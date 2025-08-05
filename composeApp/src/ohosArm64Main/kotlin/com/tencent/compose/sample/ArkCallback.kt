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
import kotlin.native.runtime.GC
import kotlin.native.ref.WeakReference
import kotlin.native.runtime.NativeRuntimeApi
import kotlin.time.TimeSource

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

object RefManager {
    @OptIn(ExperimentalForeignApi::class)
    private val refs = mutableListOf<StableRef<CallbackHolder>>()

    @OptIn(ExperimentalForeignApi::class)
    fun register(ref: StableRef<CallbackHolder>) {
        refs += ref
    }

    @OptIn(ExperimentalForeignApi::class)
    fun disposeAll() {
        refs.forEach {
            it.dispose()
        }
        refs.clear()
        LogBuffer.log("dzy 所有未释放 StableRef 已 dispose()")
    }
}

@OptIn(NativeRuntimeApi::class)
fun forceGC() {
    LogBuffer.log("dzy 手动触发 GC ...")
    GC.collect()
}

@OptIn(ExperimentalForeignApi::class)
@Composable
internal fun CallbackLeakTestScreen() {
    val triggered = remember { mutableStateOf(false) }
    var holdInC by remember { mutableStateOf(true) }
    var disposeAfterRegister by remember { mutableStateOf(false) }

    Column(Modifier
        .padding(16.dp)
        .fillMaxSize()) {
        Column {
            Button(onClick = {
                LogBuffer.log("dzy Click: 创建并注册 CallbackHolder...")

                val holder = CallbackHolder("Holder-${TimeSource.Monotonic.markNow()}")
                val ref = StableRef.create(holder)

                val cb = staticCFunction { x: Int, ptr: COpaquePointer? ->
                    val obj = ptr!!.asStableRef<CallbackHolder>().get()
                    obj.onResult(x)
                }

                native_register(ref.asCPointer(), cb, holdInC)
//                native_trigger()

                if (disposeAfterRegister) {
                    ref.dispose()
                    LogBuffer.log("dzy StableRef disposed")
                } else {
                    RefManager.register(ref)
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

            // ✅ 新增：手动释放所有未 dispose 的引用
            Button(onClick = {
                RefManager.disposeAll()
            }) {
                Text("释放所有未释放的引用")
            }
        }

        Row(verticalAlignment = Alignment.CenterVertically) {
            Checkbox(
                checked = disposeAfterRegister,
                onCheckedChange = { disposeAfterRegister = it }
            )
            Text("创建后立即 dispose()（避免引用环）")
        }

        Row(verticalAlignment = Alignment.CenterVertically) {
            Checkbox(
                checked = holdInC,
                onCheckedChange = { holdInC = it }
            )
            Text("C 侧是否持有 Kotlin 对象")
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
        @OptIn(kotlin.experimental.ExperimentalNativeApi::class)
        LogBuffer.log("dzy 创建 Holder: $name, 当前数量: ${LeakTracker.holders.size}")
    }

    fun onResult(x: Int) {
        LogBuffer.log("dzy [$name] called with $x")
    }

    protected fun finalize() {
        LogBuffer.log("dzy CallbackHolder [$name] finalized, 已被 GC 回收")
    }
}
