@file:OptIn(ExperimentalNativeApi::class)

package com.tencent.compose

import kotlinx.cinterop.CFunction
import kotlinx.cinterop.CPointer
import kotlinx.cinterop.ExperimentalForeignApi
import kotlinx.cinterop.StableRef
import kotlinx.cinterop.invoke
import kotlin.experimental.ExperimentalNativeApi

@CName("kotlin_function")
fun kotlinFunction(input: Int): Int {
    return input * 2
}

@OptIn(ExperimentalForeignApi::class)
@CName("kotlin_callback")
fun callback(data: Int, handler: CPointer<CFunction<(Int) -> Unit>>) {
    handler.invoke(data * 2)
}
