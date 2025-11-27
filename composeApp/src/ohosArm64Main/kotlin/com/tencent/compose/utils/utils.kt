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
//    return napi_get_kotlin_string_utf16(JsEnv.env().rawValue, this.rawValue)
    //TODO bug need to be fixed
    return ""
}

fun napi_value.asStringUtf8(): String? {
    return JsEnv.getValueStringUtf8(this)
}

fun createString(value: String): napi_value? {
    val nativePtr: NativePtr = JsEnv.env().rawValue
//    val result: napi_value? = interpretCPointer(value.getNapiValue(nativePtr))
    //TODO bug need to be fixed
//    val str1 = result.asString()
//    val str2 = result?.asStringUtf8()
//    println("kn: result.asString     length=${str1?.length}, result=${str1}, charArray=${toPrintChar(str1)}")
//    println("kn: result.asStringUtf8 length=${str2?.length}, result=${str2}, charArray=${toPrintChar(str2)}")
    return null
}

fun toPrintChar(asString: String?): List<String>? {
    return asString?.split("")?.map { item -> "(${item.length},${item})" }
}
