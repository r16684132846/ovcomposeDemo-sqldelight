package com.tencent.compose.service


import androidx.compose.ui.napi.JsEnv
import androidx.compose.ui.napi.asBoolean
import kotlinx.cinterop.COpaquePointer
import kotlinx.cinterop.ExperimentalForeignApi
import kotlinx.cinterop.StableRef
import kotlinx.cinterop.asStableRef
import kotlinx.cinterop.staticCFunction
import kotlinx.coroutines.CompletableDeferred
import platform.napiwrapper.kn_jsvalue_callback
import platform.napiwrapper.kn_observe_promise_jsvalue
import platform.ohos.napi_value

/**
 * 上传文件
 * @param fileName 文件名
 * @param fileContent 文件内容
 * @return 是否上传成功
 */
@OptIn(ExperimentalForeignApi::class)
actual suspend fun uploadFile(fileName: String, fileContent: ByteArray): Boolean {
//    val global = JsEnv.getGlobal()
//    val funcName = JsEnv.createStringUtf8("uploadFile")
//    val func = JsEnv.getProperty(global, funcName)
//    val paramFileName = JsEnv.createStringUtf8(fileName)
//    val paramFileContent = JsEnv.crea(fleContent)
//    val promise = JsEnv.callFunction(global, func, paramFileName, paramFileContent)
//
//    val deferred = CompletableDeferred<Boolean>()
//    val ref = StableRef.create(deferred)
//    val handler: kn_jsvalue_callback? =
//        staticCFunction { value: napi_value?, data: COpaquePointer? ->
//            val defRef = data?.asStableRef<CompletableDeferred<Boolean>>()
//            val result = value?.asBoolean() ?: false
//            defRef?.get()?.complete(result)
//            defRef?.dispose()
//        }
//    kn_observe_promise_jsvalue(JsEnv.env(), promise, handler, ref.asCPointer())
//    return deferred.await()
    TODO("Not yet implemented")
}

/**
 * 下载文件
 * @param fileName 文件名
 * @return 文件内容
 */
actual suspend fun downloadFile(fileName: String): ByteArray? {
    TODO("Not yet implemented")
}

/**
 * 列出文件
 * @param prefix 文件前缀
 * @return 文件列表
 */
actual suspend fun listFiles(prefix: String): List<FileItem>? {
    TODO("Not yet implemented")
}

/**
 * 获取文件信息
 * @param fileName 文件名
 * @return 文件信息
 */
actual suspend fun getFileInfo(fileName: String): FileInfo? {
    TODO("Not yet implemented")
}


/**
 * 检查文件是否存在
 * @param fileName 文件名
 * @return 是否存在
 */
@OptIn(ExperimentalForeignApi::class)
actual suspend fun isFileExists(fileName: String): Boolean {
    val global = JsEnv.getGlobal()
    val funcName = JsEnv.createStringUtf8("isFileExists")
    val func = JsEnv.getProperty(global, funcName)
    val param = JsEnv.createStringUtf8(fileName)
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
 * @param fileName 文件名
 * @return 是否删除成功
 */
@OptIn(ExperimentalForeignApi::class)
actual suspend fun deleteFile(fileName: String): Boolean {
    val global = JsEnv.getGlobal()
    val funcName = JsEnv.createStringUtf8("deleteFile")
    val func = JsEnv.getProperty(global, funcName)
    val param = JsEnv.createStringUtf8(fileName)
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
 * @param sourceFileName 源文件名
 * @param targetFileName 目标文件名
 * @return 是否复制成功
 */
@OptIn(ExperimentalForeignApi::class)
actual suspend fun copyFile(sourceFileName: String, targetFileName: String): Boolean {
    val global = JsEnv.getGlobal()
    val funcName = JsEnv.createStringUtf8("copyFile")
    val func = JsEnv.getProperty(global, funcName)
    val paramSource = JsEnv.createStringUtf8(sourceFileName)
    val paramTarget = JsEnv.createStringUtf8(targetFileName)
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
    val global = JsEnv.getGlobal()
    val funcName = JsEnv.createStringUtf8("deleteFolder")
    val func = JsEnv.getProperty(global, funcName)
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
