package com.tencent.compose.sample

import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.padding
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.ui.Modifier
import androidx.compose.ui.unit.dp
import kotlinx.cinterop.*
import kotlin.experimental.ExperimentalNativeApi
import platform.test725.native_register
import platform.test725.native_trigger


@OptIn(ExperimentalForeignApi::class)
@Composable
internal fun CallbackInteropButton() {
    val triggered = remember { mutableStateOf(false) }

    Column(Modifier.padding(16.dp)) {
        androidx.compose.material.Button(onClick = {
            println("dzy CallbackInteropButton in ...")

            val holder = CallbackHolder("Circular Reference Triggered")
            val ref = StableRef.create(holder)

            val cb = staticCFunction { x: Int, ptr: COpaquePointer? ->
                val obj = ptr!!.asStableRef<CallbackHolder>().get()
                obj.onResult(x)
            }

            native_register(ref.asCPointer(), cb)

            println("dzy Triggering native callback from Compose button...")
            native_trigger()

            // ref.dispose()  // 打破闭环
            triggered.value = true
        }) {
            Text("执行 Kotlin ↔ C 环状引用测试")
        }

        if (triggered.value) {
            println("dzy 已触发 callback，可观察控制台输出")
        }
    }
}


@OptIn(ExperimentalForeignApi::class)
class CallbackHolder(val name: String) {
    fun onResult(x: Int) {
        println("dzy [$name] Kotlin CallbackHolder.onResult called with $x")
        native_trigger()
    }
}
