package com.tencent.compose

import androidx.compose.ui.napi.JsEnv
import androidx.compose.ui.napi.JsEnv.env
import androidx.compose.ui.napi.asJsArray
import androidx.compose.ui.napi.asString
import androidx.compose.ui.napi.nApiValue
import kotlinx.cinterop.COpaquePointer
import platform.ohos.napi_delete_reference
import platform.ohos.napi_env
import platform.ohos.napi_value
import kotlinx.cinterop.CFunction
import kotlinx.cinterop.CPointer
import kotlinx.cinterop.ExperimentalForeignApi
import kotlinx.cinterop.StableRef
import kotlinx.cinterop.asStableRef
import kotlinx.cinterop.staticCFunction
import platform.napiwrapper.kn_jsvalue_callback
import platform.napiwrapper.kn_observe_promise_jsvalue

object TsEnv {
    // 异步观察 Promise 解析值（数组）并转换为 List<String>
    @OptIn(ExperimentalForeignApi::class)
    fun observePromiseArrayString(
        promise: napi_value?,
        callback: (List<String>) -> Unit
    ) {
        promise ?: return
        val ref = StableRef.create(callback)
        val handler: kn_jsvalue_callback? =
            staticCFunction { value: napi_value?, data: COpaquePointer? ->
                val cbRef = data?.asStableRef<(List<String>) -> Unit>()
                val list = mutableListOf<String>()
                val global = JsEnv.getGlobal()
                // 通过 length+索引的方式枚举，避免 JsArray 迭代器可能的 off-by-one 问题
                val lengthName = JsEnv.createStringUtf8("length")
                val lenVal = if (value != null) JsEnv.getProperty(value, lengthName) else null
                val lenStrVal = if (lenVal != null) {
                    val stringName = JsEnv.createStringUtf8("String")
                    val stringFn = JsEnv.getProperty(global, stringName)
                    JsEnv.callFunction(global, stringFn, lenVal)
                } else null
                val len = lenStrVal?.asString()?.toString()?.toIntOrNull() ?: 0
                val stringName = JsEnv.createStringUtf8("String")
                val stringFn = JsEnv.getProperty(global, stringName)
                for (i in 0 until len) {
                    val idxName = JsEnv.createStringUtf8(i.toString())
                    val itemVal = JsEnv.getProperty(value, idxName)
                    var str = itemVal?.asString()?.toString()
                    if (str == null) {
                        val coerced = JsEnv.callFunction(global, stringFn, itemVal)
                        str = coerced?.asString()?.toString()
                    }
                    if (str != null) list.add(str)
                }
                /*  使用asJsArray()会出现丢失数组最后一个元素的bug
                    val arr = value?.asJsArray()
                    if (arr != null) {
                        for ((idx, item) in arr.withIndex()) {
                            var str = item.asString()?.toString()
                            if (str == null) {
                                val stringName = JsEnv.createStringUtf8("String")
                                val stringFn = JsEnv.getProperty(global, stringName)
                                val coerced = JsEnv.callFunction(global, stringFn, item)
                                str = coerced?.asString()?.toString()
                            }
                            if (str != null) list.add(str)
                        }
                    }
                }*/
                cbRef?.get()?.invoke(list)
                cbRef?.dispose()
            }
        kn_observe_promise_jsvalue(env(), promise, handler, ref.asCPointer())
    }
}