package com.tencent.compose.sample

import androidx.compose.foundation.layout.*
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.material.*
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.unit.dp
import kotlinx.cinterop.*
import platform.test725.native_register
import platform.test725.native_trigger
import kotlin.experimental.ExperimentalNativeApi
import kotlin.native.internal.GC
import kotlin.native.ref.WeakReference
import kotlin.system.getTimeMillis

object LogBuffer {
    val logs = mutableStateListOf<String>()

    fun log(msg: String) {
        println(msg)
        logs += msg
    }

    fun clear() {
        logs.clear()
    }
}

object LeakTracker {
    @OptIn(ExperimentalNativeApi::class)
    val holders = mutableListOf<WeakReference<CallbackHolder>>()

    @OptIn(ExperimentalNativeApi::class)
    fun collectStatus(): List<Unit> {
        return holders.mapIndexed { index, ref ->
            val obj = ref.get()
            if (obj != null) {
                LogBuffer.log("dzy $index -> ${obj.name} ✅ 活跃")
            } else {
                LogBuffer.log("dzy $index -> 已被 GC 回收")
            }
        }
    }
}

fun forceGC() {
    LogBuffer.log("dzy 手动触发 GC ...")
    GC.collect()
}

@OptIn(ExperimentalForeignApi::class)
@Composable
fun CallbackLeakTestScreen() {
    val triggered = remember { mutableStateOf(false) }
    var disposeAfterRegister by remember { mutableStateOf(false) }

    Column(Modifier
        .padding(16.dp)
        .fillMaxSize()) {
        Column {
            Button(onClick = {
                LogBuffer.log("dzy Click: 创建并注册 CallbackHolder...")

                val holder = CallbackHolder("Holder-${getTimeMillis()}")
                val ref = StableRef.create(holder)

                val cb = staticCFunction { x: Int, ptr: COpaquePointer? ->
                    val obj = ptr!!.asStableRef<CallbackHolder>().get()
                    obj.onResult(x)
                }

                native_register(ref.asCPointer(), cb)
//                native_trigger()

                if (disposeAfterRegister) {
                    ref.dispose()
                    LogBuffer.log("dzy StableRef disposed")
                }

                triggered.value = true
            }) {
                Text("创建 CallbackHolder")
            }

            Button(onClick = {
                LeakTracker.collectStatus()
            }) {
                Text("查看状态")
            }

            Button(onClick = {
                forceGC()
            }) {
                Text("GC")
            }

            Button(onClick = {
                LogBuffer.clear()
            }) {
                Text("清空日志")
            }
        }

        Row(verticalAlignment = Alignment.CenterVertically) {
            Checkbox(
                checked = disposeAfterRegister,
                onCheckedChange = { disposeAfterRegister = it }
            )
            Text("创建后立即 dispose()（避免引用环）")
        }

        Spacer(Modifier.height(8.dp))

        LazyColumn(
            modifier = Modifier
                .fillMaxWidth()
                .weight(1f),
            verticalArrangement = Arrangement.spacedBy(4.dp)
        ) {
            items(LogBuffer.logs) { log ->
                Text(log)
            }
        }
    }
}

@OptIn(ExperimentalForeignApi::class)
class CallbackHolder(val name: String) {

    init {
        @OptIn(ExperimentalNativeApi::class)
        LeakTracker.holders += WeakReference(this)
        @OptIn(kotlin. experimental. ExperimentalNativeApi::class)
        LogBuffer.log("dzy 创建 Holder: $name, 当前数量: ${LeakTracker.holders.size}")
    }

    fun onResult(x: Int) {
        LogBuffer.log("dzy [$name] called with $x")
    }

    protected fun finalize() {
        LogBuffer.log("dzy CallbackHolder [$name] finalized, 已被 GC 回收")
    }
}
