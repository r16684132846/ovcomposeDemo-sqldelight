package com.tencent.compose.service

import androidx.compose.ui.napi.JsEnv
import androidx.compose.ui.napi.asBoolean
import androidx.compose.ui.napi.asString
import kotlinx.cinterop.COpaquePointer
import kotlinx.cinterop.ExperimentalForeignApi
import kotlinx.cinterop.StableRef
import kotlinx.cinterop.addressOf
import kotlinx.cinterop.asStableRef
import kotlinx.cinterop.staticCFunction
import kotlinx.coroutines.CompletableDeferred
import platform.napiwrapper.kn_create_arraybuffer_from_bytes
import platform.napiwrapper.kn_jsvalue_callback
import platform.napiwrapper.kn_observe_promise_jsvalue
import platform.ohos.napi_value
import kotlinx.cinterop.reinterpret
import kotlinx.cinterop.usePinned
import kotlinx.cinterop.*
import kotlinx.coroutines.suspendCancellableCoroutine
import kotlinx.datetime.Instant
import platform.napiwrapper.kn_get_arraybuffer_length
import platform.napiwrapper.kn_get_arraybuffer_value
import kotlin.coroutines.resume

// 工具函数，用于获取全局对象和相关方法
@OptIn(ExperimentalForeignApi::class)
private fun getJsGlobalAndFunction(funcName: String): Pair<napi_value?, napi_value?> {
    val global = JsEnv.getGlobal()
    val jsFuncName = JsEnv.createStringUtf8(funcName)
    val func = JsEnv.getProperty(global, jsFuncName)
    return Pair(global, func)
}

// 工具函数，用于安全获取对象属性字符串
@OptIn(ExperimentalForeignApi::class)
private fun getPropAsString(g: napi_value, obj: napi_value?, propName: String): String? {
    if (obj == null) return null
    val key = JsEnv.createStringUtf8(propName)
    val propVal = JsEnv.getProperty(obj, key)
    return propVal?.asString()
}

// 工具函数，用于安全获取对象属性数值
@OptIn(ExperimentalForeignApi::class)
private fun getPropAsNumber(g: napi_value, obj: napi_value?, propName: String): Double? {
    if (obj == null) return null
    val key = JsEnv.createStringUtf8(propName)
    val propVal = JsEnv.getProperty(obj, key)
    // 尝试转为 number：先用 JS Number() 包装再 toString，再 parse
    val numStr = JsEnv.callFunction(
        g,
        JsEnv.getProperty(g, JsEnv.createStringUtf8("Number")),
        propVal
    )
        ?.asString()
    return numStr?.toDoubleOrNull()
}


/**
 * 上传文件
 * @param relativePath 文件名
 * @param fileContent 文件内容
 * @return 是否上传成功
 */
@OptIn(ExperimentalForeignApi::class)
actual suspend fun uploadFile(relativePath: String, fileContent: ByteArray): Boolean {
    val (global, func) = getJsGlobalAndFunction("uploadFile")
    val paramRelativePath = JsEnv.createStringUtf8(relativePath)
    val paramFileContent = fileContent.usePinned { pinned ->
        kn_create_arraybuffer_from_bytes(
            JsEnv.env(),
            pinned.addressOf(0).reinterpret(), // Byte* → UByte*
            fileContent.size.toULong()
        )
    }
    val promise = JsEnv.callFunction(global, func, paramRelativePath, paramFileContent)

    val deferred = CompletableDeferred<Boolean>()
    val ref = StableRef.create(deferred)
    val handler: kn_jsvalue_callback? =
        staticCFunction { value: napi_value?, data: COpaquePointer? ->
            val defRef = data?.asStableRef<CompletableDeferred<Boolean>>()
            val result = value?.asBoolean() ?: false
            defRef?.get()?.complete(result)
            defRef?.dispose()
        }
    kn_observe_promise_jsvalue(JsEnv.env(), promise, handler, ref.asCPointer())
    return deferred.await()
}

/**
 * 下载文件
 * @param relativePath 文件名
 * @return 文件内容
 */
@OptIn(ExperimentalForeignApi::class)
actual suspend fun downloadFile(relativePath: String): ByteArray? {
    return suspendCancellableCoroutine { continuation ->
        // 1. 调用 JS 函数
        val (global, func) = getJsGlobalAndFunction("downloadFile")
        val param = JsEnv.createStringUtf8(relativePath)
        val promise = JsEnv.callFunction(global, func, param)

        // 2. 创建 StableRef 传递 continuation 回调
        val callbackRef = StableRef.create<(ByteArray?) -> Unit> { result ->
            if (continuation.isActive) {
                continuation.resume(result)
            }
        }

        // 3. 定义 C 回调
        val handler: kn_jsvalue_callback? =
            staticCFunction { value: napi_value?, data: COpaquePointer? ->
                val cb = data?.asStableRef<(ByteArray?) -> Unit>()?.get()

                var result: ByteArray? = null

                if (value != null) {
                    try {
                        val env = JsEnv.env()
                        val dataPtr = kn_get_arraybuffer_value(env, value)
                        val dataLength = kn_get_arraybuffer_length(env, value)

                        if (dataPtr != null && dataLength > 0u) {
                            // 安全地从 C 指针构造 ByteArray
                            result = ByteArray(dataLength.toInt()) { index ->
                                dataPtr[index].toByte()
                            }
                        }
                    } catch (_: Throwable) {
                        // 读取失败，result 保持 null
                    }
                }

                cb?.invoke(result)
                data?.asStableRef<(ByteArray?) -> Unit>()?.dispose()
            }

        // 4. 监听 Promise
        kn_observe_promise_jsvalue(JsEnv.env(), promise, handler, callbackRef.asCPointer())
    }
}

/**
 * 列出文件
 * @param prefix 文件前缀
 * @return 文件列表
 */
@OptIn(ExperimentalForeignApi::class)
actual suspend fun listObjects(prefix: String): List<FileItem>? {
    return suspendCancellableCoroutine { continuation ->
        // 1. 调用 ArkTS: listFiles(prefix) -> Promise<S3Object[] | null>
        val (g, fn) = getJsGlobalAndFunction("listObjects")
        val arg = JsEnv.createStringUtf8(prefix)
        val promise = JsEnv.callFunction(g, fn, arg)

        // 2. 创建回调引用（用于从 C 回调传回 Kotlin）
        val callbackRef = StableRef.create<(List<FileItem>?) -> Unit> { result ->
            if (continuation.isActive) {
                continuation.resume(result)
            }
        }

        // 3. 定义 C 回调：处理 Promise resolve 的值（JS 数组）
        val handler: kn_jsvalue_callback? =
            staticCFunction { value: napi_value?, data: COpaquePointer? ->
                val cb = data?.asStableRef<(List<FileItem>?) -> Unit>()?.get()

                var result: List<FileItem>? = null

                if (value != null) {
                    try {
                        // 获取全局对象（在回调内部重新获取）
                        val global = JsEnv.getGlobal()

                        // 检查是否为 null/undefined
                        val stringFn = JsEnv.getProperty(global, JsEnv.createStringUtf8("String"))
                        val typeStr = JsEnv.callFunction(global, stringFn, value)?.asString()
                        if (typeStr == "null" || typeStr == "undefined") {
                            cb?.invoke(null)
                            data?.asStableRef<(List<FileItem>?) -> Unit>()?.dispose()
                            return@staticCFunction
                        }

                        // 判断是否为数组
                        val arrayConstructor =
                            JsEnv.getProperty(global, JsEnv.createStringUtf8("Array"))
                        val isArrayFn =
                            JsEnv.getProperty(arrayConstructor, JsEnv.createStringUtf8("isArray"))
                        val isArrayVal = JsEnv.callFunction(global, isArrayFn, value)
                        val isArray =
                            JsEnv.callFunction(global, stringFn, isArrayVal)?.asString() == "true"

                        if (!isArray) {
                            cb?.invoke(null)
                            data?.asStableRef<(List<FileItem>?) -> Unit>()?.dispose()
                            return@staticCFunction
                        }

                        // 获取数组长度
                        val lengthKey = JsEnv.createStringUtf8("length")
                        val lengthVal = JsEnv.getProperty(value, lengthKey)
                        val lengthStr =
                            JsEnv.callFunction(global, stringFn, lengthVal)?.asString()
                        val length = lengthStr?.toIntOrNull() ?: 0

                        if (length <= 0) {
                            cb?.invoke(emptyList())
                            data?.asStableRef<(List<FileItem>?) -> Unit>()?.dispose()
                            return@staticCFunction
                        }

                        val items = mutableListOf<FileItem>()

                        // 遍历数组
                        for (i in 0 until length) {
                            val indexStr = JsEnv.createStringUtf8(i.toString())
                            val itemObj = JsEnv.getProperty(value, indexStr) ?: continue

                            // 解析 S3Object 字段（注意大小写：Key, LastModified, ETag, Size, StorageClass）
                            val key =
                                global?.let { getPropAsString(it, itemObj, "Key") } ?: continue
                            val eTag = getPropAsString(global, itemObj, "ETag") ?: ""
                            val storageClass =
                                getPropAsString(global, itemObj, "StorageClass") ?: ""
                            val size = getPropAsNumber(global, itemObj, "Size")?.toLong() ?: 0L

                            // 解析 LastModified: Date → Instant
                            val dateObj =
                                JsEnv.getProperty(itemObj, JsEnv.createStringUtf8("LastModified"))
                            val timeMillis = if (dateObj != null) {
                                val valueOfKey = JsEnv.createStringUtf8("valueOf")
                                val valueOfFn = JsEnv.getProperty(dateObj, valueOfKey)
                                if (valueOfFn != null) {
                                    val tsVal = JsEnv.callFunction(dateObj, valueOfFn)
                                    val tsStr = JsEnv.callFunction(
                                        global,
                                        JsEnv.getProperty(global, JsEnv.createStringUtf8("Number")),
                                        tsVal
                                    )
                                        ?.asString()
                                    tsStr?.toLongOrNull() ?: 0L
                                } else {
                                    0L
                                }
                            } else {
                                0L
                            }

                            val lastModified = Instant.fromEpochMilliseconds(timeMillis)

                            items.add(
                                FileItem(
                                    key = key,
                                    lastModified = lastModified,
                                    eTag = eTag,
                                    size = size,
                                    storageClass = storageClass
                                )
                            )
                        }

                        result = items
                    } catch (e: Throwable) {
                        // 解析失败，result 保持 null
                        e.printStackTrace()
                    }
                }

                cb?.invoke(result)
                data?.asStableRef<(List<FileItem>?) -> Unit>()?.dispose()
            }

        // 4. 监听 Promise
        kn_observe_promise_jsvalue(JsEnv.env(), promise, handler, callbackRef.asCPointer())
    }
}

/**
 * 获取文件信息
 * @param relativePath 文件名
 * @return 文件信息
 */
@OptIn(ExperimentalForeignApi::class)
actual suspend fun getFileInfo(relativePath: String): FileInfo? {
    return suspendCancellableCoroutine { continuation ->
        // 1. 调用 ArkTS 的 getFileInfo(relativePath) -> Promise<FileInfo | null>
        val (g, fn) = getJsGlobalAndFunction("getFileInfo")
        val arg = JsEnv.createStringUtf8(relativePath)
        val promise = JsEnv.callFunction(g, fn, arg)

        // 2. 定义回调：从 JS 的 napi_value 解析为 Kotlin FileInfo?
        val callbackRef = StableRef.create<(FileInfo?) -> Unit> { result ->
            if (continuation.isActive) {
                continuation.resume(result)
            }
        }

        // 3. C 回调函数：由 N-API 在 Promise resolve 时调用
        val handler: kn_jsvalue_callback? =
            staticCFunction { value: napi_value?, data: COpaquePointer? ->
                val cb = data?.asStableRef<(FileInfo?) -> Unit>()?.get()

                var fileInfo: FileInfo? = null
                if (value != null) {
                    try {
                        // 获取全局对象（在回调内部重新获取）
                        val global = JsEnv.getGlobal()

                        // 检查是否为 null/undefined
                        val stringFn = JsEnv.getProperty(global, JsEnv.createStringUtf8("String"))
                        val typeStr = JsEnv.callFunction(global, stringFn, value)?.asString()
                        if (typeStr != "null" && typeStr != "undefined") {
                            val name = global?.let { getPropAsString(it, value, "name") }
                                ?: return@staticCFunction cb?.invoke(null)!!
                            val size = getPropAsNumber(global, value, "size")?.toLong() ?: 0L
                            val contentType = getPropAsString(global, value, "contentType") ?: ""

                            // lastModified 是 JS Date 对象，其 .valueOf() 返回毫秒时间戳
                            val dateKey = JsEnv.createStringUtf8("lastModified")
                            val dateObj = JsEnv.getProperty(value, dateKey)
                            val timeMillis = if (dateObj != null) {
                                // 调用 dateObj.valueOf() → number
                                val valueOfKey = JsEnv.createStringUtf8("valueOf")
                                val valueOfFn = JsEnv.getProperty(dateObj, valueOfKey)
                                if (valueOfFn != null) {
                                    val tsVal = JsEnv.callFunction(dateObj, valueOfFn)
                                    val tsStr = JsEnv.callFunction(
                                        global,
                                        JsEnv.getProperty(global, JsEnv.createStringUtf8("Number")),
                                        tsVal
                                    )
                                        ?.asString()
                                    tsStr?.toLongOrNull()
                                } else {
                                    null
                                }
                            } else {
                                null
                            } ?: 0L

                            val lastModified = Instant.fromEpochMilliseconds(timeMillis)

                            fileInfo = FileInfo(
                                name = name,
                                size = size,
                                lastModified = lastModified,
                                contentType = contentType
                            )
                        }
                    } catch (e: Throwable) {
                        // 解析失败，返回 null
                    }
                }
                cb?.invoke(fileInfo)
                data?.asStableRef<(FileInfo?) -> Unit>()?.dispose()
            }
        // 4. 监听 Promise
        kn_observe_promise_jsvalue(JsEnv.env(), promise, handler, callbackRef.asCPointer())
    }
}


/**
 * 检查文件是否存在
 * @param relativePath 文件名
 * @return 是否存在
 */
@OptIn(ExperimentalForeignApi::class)
actual suspend fun existsFile(relativePath: String): Boolean {
    val (global, func) = getJsGlobalAndFunction("existsFile")
    val param = JsEnv.createStringUtf8(relativePath)
    val promise = JsEnv.callFunction(global, func, param)

    val deferred = CompletableDeferred<Boolean>()
    val ref = StableRef.create(deferred)
    val handler: kn_jsvalue_callback? =
        staticCFunction { value: napi_value?, data: COpaquePointer? ->
            val defRef = data?.asStableRef<CompletableDeferred<Boolean>>()
            val result = value?.asBoolean() ?: false
            defRef?.get()?.complete(result)
            defRef?.dispose()
        }
    kn_observe_promise_jsvalue(JsEnv.env(), promise, handler, ref.asCPointer())
    return deferred.await()
}

/**
 * 删除文件
 * @param relativePath 文件名
 * @return 是否删除成功
 */
@OptIn(ExperimentalForeignApi::class)
actual suspend fun deleteFile(relativePath: String): Boolean {
    val (global, func) = getJsGlobalAndFunction("deleteFile")
    val param = JsEnv.createStringUtf8(relativePath)
    val promise = JsEnv.callFunction(global, func, param)

    val deferred = CompletableDeferred<Boolean>()
    val ref = StableRef.create(deferred)
    val handler: kn_jsvalue_callback? =
        staticCFunction { value: napi_value?, data: COpaquePointer? ->
            val defRef = data?.asStableRef<CompletableDeferred<Boolean>>()
            val result = value?.asBoolean() ?: false
            defRef?.get()?.complete(result)
            defRef?.dispose()
        }
    kn_observe_promise_jsvalue(JsEnv.env(), promise, handler, ref.asCPointer())
    return deferred.await()
}

/**
 * 复制文件
 * @param relativePath 源文件名
 * @param toPath 目标文件名
 * @return 是否复制成功
 */
@OptIn(ExperimentalForeignApi::class)
actual suspend fun copy(relativePath: String, toPath: String): Boolean {
    val (global, func) = getJsGlobalAndFunction("copy")
    val paramSource = JsEnv.createStringUtf8(relativePath)
    val paramTarget = JsEnv.createStringUtf8(toPath)
    val promise = JsEnv.callFunction(global, func, paramSource, paramTarget)

    val deferred = CompletableDeferred<Boolean>()
    val ref = StableRef.create(deferred)
    val handler: kn_jsvalue_callback? =
        staticCFunction { value: napi_value?, data: COpaquePointer? ->
            val defRef = data?.asStableRef<CompletableDeferred<Boolean>>()
            val result = value?.asBoolean() ?: false
            defRef?.get()?.complete(result)
            defRef?.dispose()
        }
    kn_observe_promise_jsvalue(JsEnv.env(), promise, handler, ref.asCPointer())
    return deferred.await()
}

/**
 * 删除文件夹
 * @param folderPath 文件夹路径
 * @return 是否删除成功
 */
@OptIn(ExperimentalForeignApi::class)
actual suspend fun deleteFolder(folderPath: String): Boolean {
    val (global, func) = getJsGlobalAndFunction("deleteFolder")
    val param = JsEnv.createStringUtf8(folderPath)
    val promise = JsEnv.callFunction(global, func, param)

    val deferred = CompletableDeferred<Boolean>()
    val ref = StableRef.create(deferred)
    val handler: kn_jsvalue_callback? =
        staticCFunction { value: napi_value?, data: COpaquePointer? ->
            val defRef = data?.asStableRef<CompletableDeferred<Boolean>>()
            val result = value?.asBoolean() ?: false
            defRef?.get()?.complete(result)
            defRef?.dispose()
        }
    kn_observe_promise_jsvalue(JsEnv.env(), promise, handler, ref.asCPointer())
    return deferred.await()
}
