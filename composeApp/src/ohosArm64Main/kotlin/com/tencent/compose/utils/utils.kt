@file:OptIn(ExperimentalForeignApi::class)

package com.tencent.compose.utils

import androidx.compose.ui.napi.JsEnv
import androidx.compose.ui.napi.asString
import kotlinx.cinterop.ExperimentalForeignApi
import kotlinx.cinterop.NativePtr
import kotlinx.cinterop.interpretCPointer
import platform.ohos.napi_value

@OptIn(ExperimentalForeignApi::class)
fun napi_value.asString(): String? {
    return napi_get_kotlin_string_utf16(JsEnv.env().rawValue, this.rawValue)
}

fun napi_value.asStringUtf8(): String? {
    return JsEnv.getValueStringUtf8(this)
}

fun createString(value: String): napi_value? {
    val nativePtr: NativePtr = JsEnv.env().rawValue
    val result: napi_value? = interpretCPointer(value.getNapiValue(nativePtr))
    return result
}
