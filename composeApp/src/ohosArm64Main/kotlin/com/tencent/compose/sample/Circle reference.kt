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
import platform.test725.native_register_simple_callback
import platform.test725.native_trigger_simple_callback
import platform.test725.native_cleanup_simple_callback
import platform.test725.native_cleanup_all_simple_callbacks
import kotlin.experimental.ExperimentalNativeApi
import kotlin.native.internal.GC
import kotlin.native.ref.WeakReference
import kotlin.system.getTimeMillis

object MemoryLogger {
    val logs = mutableStateListOf<String>()

    fun log(msg: String) {
        println(msg)
        logs += "[${getTimeMillis() % 100000}] $msg"
    }

    fun clear() {
        logs.clear()
    }
}

// 全局存储，模拟环状引用
object CallbackRegistry {
    // 这个Map会持有对象引用，阻止GC
    private val activeCallbacks = mutableMapOf<String, LeakyCallbackHolder>()

    fun register(id: String, holder: LeakyCallbackHolder) {
        activeCallbacks[id] = holder
        MemoryLogger.log("dzy 注册到全局Registry: $id (当前数量: ${activeCallbacks.size})")
    }

    fun getCallback(id: String): LeakyCallbackHolder? {
        return activeCallbacks[id]
    }

    fun remove(id: String) {
        activeCallbacks.remove(id)
        MemoryLogger.log("dzy 从Registry移除: $id (剩余: ${activeCallbacks.size})")
    }

    fun clear() {
        val count = activeCallbacks.size
        activeCallbacks.clear()
        MemoryLogger.log("dzy 清空Registry，释放了 $count 个引用")
    }

    fun getActiveCount(): Int = activeCallbacks.size
}

// 对象追踪器
object ObjectTracker {
    @OptIn(ExperimentalNativeApi::class)
    private val trackedObjects = mutableListOf<WeakReference<LeakyCallbackHolder>>()

    @OptIn(ExperimentalNativeApi::class)
    fun track(obj: LeakyCallbackHolder) {
        trackedObjects += WeakReference(obj)
        MemoryLogger.log("dzy 开始追踪对象: ${obj.id}")
    }

    @OptIn(ExperimentalNativeApi::class)
    fun checkStatus() {
        var aliveCount = 0
        var gcCount = 0

        MemoryLogger.log("dzy 检查所有追踪的对象状态...")

        trackedObjects.forEachIndexed { index, ref ->
            val obj = ref.get()
            if (obj != null) {
                aliveCount++
                MemoryLogger.log("dzy 对象 ${obj.id} 仍然存活")
            } else {
                gcCount++
                MemoryLogger.log("dzy 对象已被GC回收")
            }
        }

        MemoryLogger.log("dzy 统计结果: 存活 $aliveCount 个, 已回收 $gcCount 个")
        MemoryLogger.log("dzy Registry中还有 ${CallbackRegistry.getActiveCount()} 个引用")

        if (aliveCount > 0 && CallbackRegistry.getActiveCount() > 0) {
            MemoryLogger.log("dzy 检测到可能的内存泄漏！对象无法被GC")
        }
    }

    @OptIn(ExperimentalNativeApi::class)
    fun reset() {
        trackedObjects.clear()
    }
}

// 会产生环状引用的回调持有者
@OptIn(ExperimentalForeignApi::class)
class LeakyCallbackHolder(val id: String) {
    private var stableRef: StableRef<LeakyCallbackHolder>? = null
    private var isRegistered = false

    init {
        ObjectTracker.track(this)
        MemoryLogger.log("dzy 创建 LeakyCallbackHolder: $id")
    }

    fun registerToC(createCircularRef: Boolean = true) {
        if (!isRegistered) {
            stableRef = StableRef.create(this)

            val callback:CPointer<CFunction<(COpaquePointer?) -> Unit>> = staticCFunction { ptr: COpaquePointer? ->
                try {
                    ptr?.asStableRef<LeakyCallbackHolder>()?.get()?.let { obj ->
                        obj.handleCallback("dzy 来自C层的数据")

                        // 关键：同时通过Registry也能获取到同一个对象
                        // 这证明了环状引用的存在
                        val registryObj = CallbackRegistry.getCallback(obj.id)
                        if (registryObj === obj) {
                            MemoryLogger.log("dzy 确认环状引用：Registry和StableRef指向同一对象")
                        }
                    }
                } catch (e: Exception) {
                    MemoryLogger.log("dzy 回调执行出错: ${e.message}")
                }
            }

            // 注册到C层 - 使用简化的接口
            native_register_simple_callback(id, stableRef!!.asCPointer(), callback)

            if (createCircularRef) {
                // 关键步骤：将自己注册到全局Registry
                // 这创建了环状引用：
                // 1. 这个对象持有StableRef
                // 2. C层通过StableRef持有这个对象
                // 3. 全局Registry也持有这个对象
                // 4. 即使C层释放了StableRef，Registry仍然持有引用阻止GC
                CallbackRegistry.register(id, this)
                MemoryLogger.log("dzy 创建环状引用: $id")
            }

            isRegistered = true
        }
    }

    fun handleCallback(data: String) {
        MemoryLogger.log("dzy [$id] 收到回调: $data")
    }

    fun dispose() {
        if (isRegistered) {
            // 1. 清理C层注册
            native_cleanup_simple_callback(id)

            // 2. 释放StableRef
            stableRef?.dispose()
            stableRef = null

            // 3. 从Registry移除（解除环状引用）
            CallbackRegistry.remove(id)

            isRegistered = false
            MemoryLogger.log("dzy 正确清理对象: $id")
        }
    }

    // 只清理C层和StableRef，但不清理Registry引用（保持环状引用）
    fun partialDispose() {
        if (isRegistered) {
            native_cleanup_simple_callback(id)
            stableRef?.dispose()
            stableRef = null
            isRegistered = false
            MemoryLogger.log("dzy 部分清理对象: $id (Registry引用仍存在)")
        }
    }

    fun cleanupOnlyRegistry() {
        CallbackRegistry.remove(id)
        stableRef?.dispose()
        stableRef = null
        MemoryLogger.log("dzy 部分清理对象 Registry引用 和 stableRef: $id")
    }

    protected fun finalize() {
        MemoryLogger.log("dzy 对象 $id 被GC回收（finalize调用）")
    }
}

@Composable
fun CircularReferenceDemo() {
    var objectCounter by remember { mutableStateOf(0) }
    var createCircularRef by remember { mutableStateOf(true) }
    var usePartialDispose by remember { mutableStateOf(false) }

    // 存储创建的对象，用于手动清理测试
    val createdObjects = remember { mutableListOf<LeakyCallbackHolder>() }

    Column(
        modifier = Modifier
            .padding(16.dp)
            .fillMaxSize()
    ) {
        Text(
            text = "KMP 环状引用演示",
            style = MaterialTheme.typography.h6
        )

        Spacer(modifier = Modifier.height(8.dp))

        Column {
            Row(verticalAlignment = Alignment.CenterVertically) {
                Checkbox(
                    checked = createCircularRef,
                    onCheckedChange = { createCircularRef = it }
                )
                Text("创建环状引用（Registry持有对象）")
            }

            Row(verticalAlignment = Alignment.CenterVertically) {
                Checkbox(
                    checked = usePartialDispose,
                    onCheckedChange = { usePartialDispose = it }
                )
                Text("使用部分清理（保持环状引用）")
            }
        }

        Spacer(modifier = Modifier.height(16.dp))

        // 第一行按钮
        Row(
            horizontalArrangement = Arrangement.spacedBy(8.dp)
        ) {
            Button(
                onClick = {
                    objectCounter++
                    val obj = LeakyCallbackHolder("Holder-$objectCounter")
                    obj.registerToC(createCircularRef)
                    createdObjects.add(obj)

                    if (createCircularRef) {
                        MemoryLogger.log("dzy 创建了可能泄漏的对象（有环状引用）")
                    } else {
                        MemoryLogger.log("dzy 创建了正常的对象（无环状引用）")
                    }
                }
            ) {
                Text("创建对象")
            }

            Button(
                onClick = {
                    if (createdObjects.isNotEmpty()) {
                        val obj = createdObjects.removeLastOrNull()
                        obj?.let {
                            if (usePartialDispose) {
                                it.partialDispose() // 保持环状引用
                            }
                            else {
                                it.dispose() // 完全清理
                            }
                        }
                    }
                }
            ) {
                Text("清理最后对象")
            }
        }

        // 第二行按钮
        Row(
            horizontalArrangement = Arrangement.spacedBy(8.dp)
        ) {
            Button(
                onClick = {
                    val id = "Holder-$objectCounter"
                    @OptIn(kotlinx.cinterop.ExperimentalForeignApi::class)
                    native_trigger_simple_callback(id)
                    MemoryLogger.log("🚀 触发回调: $id")
                }
            ) {
                Text("触发回调")
            }

            Button(
                onClick = {
                    MemoryLogger.log("dzy 开始强制GC...")
                    GC.collect()
                    MemoryLogger.log("dzy GC完成")
                }
            ) {
                Text("强制GC")
            }
        }

        // 第三行按钮
        Row(
            horizontalArrangement = Arrangement.spacedBy(8.dp)
        ) {
            Button(
                onClick = {
                    ObjectTracker.checkStatus()
                }
            ) {
                Text("检查内存")
            }

            Button(
                onClick = {
                    // 清理所有Registry引用，解除环状引用
                    CallbackRegistry.clear()
                    @OptIn(kotlinx.cinterop.ExperimentalForeignApi::class)
                    native_cleanup_all_simple_callbacks()
                }
            ) {
                Text("解除环状引用")
            }
        }

        // 第四行按钮
        Row(
            horizontalArrangement = Arrangement.spacedBy(8.dp)
        ) {
            Button(
                onClick = {
                    createdObjects.clear()
                    ObjectTracker.reset()
                    CallbackRegistry.clear()
                    MemoryLogger.clear()
                }
            ) {
                Text("重置所有")
            }
        }

        Spacer(modifier = Modifier.height(16.dp))

        // 说明卡片
        Card(
            modifier = Modifier.fillMaxWidth(),
            backgroundColor = MaterialTheme.colors.surface
        ) {
            Column(modifier = Modifier.padding(8.dp)) {
                Text(
                    text = "观察步骤:",
                    style = MaterialTheme.typography.subtitle2
                )
                Text(
                    text = "1️⃣ 勾选'创建环状引用'，创建几个对象\n" +
                            "2️⃣ 点击'强制GC'，然后'检查内存'\n" +
                            "3️⃣ 观察对象无法被GC回收（Registry持有引用）\n" +
                            "4️⃣ 点击'解除环状引用'，再次GC\n" +
                            "5️⃣ 观察对象现在可以被GC回收了\n\n" +
                            "🔴 环状引用路径:\n" +
                            "Kotlin对象 → StableRef → C层 → 回调 → Registry → Kotlin对象",
                    style = MaterialTheme.typography.caption
                )
            }
        }

        Spacer(modifier = Modifier.height(8.dp))

        // 日志显示
        LazyColumn(
            modifier = Modifier
                .fillMaxWidth()
                .weight(1f),
            verticalArrangement = Arrangement.spacedBy(2.dp)
        ) {
            items(MemoryLogger.logs) { log ->
                Text(
                    text = log,
                    style = MaterialTheme.typography.caption
                )
            }
        }
    }
}