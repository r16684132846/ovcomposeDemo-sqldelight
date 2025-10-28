/*
 * Tencent is pleased to support the open source community by making ovCompose available.
 * Copyright (C) 2025 THL A29 Limited, a Tencent company. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package com.tencent.compose.sample

import io.github.aakira.napier.DebugAntilog
import io.github.aakira.napier.Napier
import kotlin.concurrent.Volatile

class NapierTest {

    companion object {
        @Volatile
        private var isInitialized = false

        private fun setupNapier() {
            if (!isInitialized) {
                // 初始化Napier日志系统
                Napier.base(DebugAntilog())
                isInitialized = true
            }
        }
    }

    fun testNapierDebug(): String {
        return try {
            setupNapier()
            Napier.d("这是一个调试级别的日志消息", tag = "NapierTest")
            "Napier DEBUG日志记录成功"
        } catch (e: Exception) {
            "Napier DEBUG日志记录失败: ${e.message}"
        }
    }

    fun testNapierInfo(): String {
        return try {
            setupNapier()
            Napier.i("这是一个信息级别的日志消息", tag = "NapierTest")
            "Napier INFO日志记录成功"
        } catch (e: Exception) {
            "Napier INFO日志记录失败: ${e.message}"
        }
    }

    fun testNapierWarning(): String {
        return try {
            setupNapier()
            Napier.w("这是一个警告级别的日志消息", tag = "NapierTest")
            "Napier WARNING日志记录成功"
        } catch (e: Exception) {
            "Napier WARNING日志记录失败: ${e.message}"
        }
    }

    fun testNapierError(): String {
        return try {
            setupNapier()
            Napier.e("这是一个错误级别的日志消息", tag = "NapierTest")
            "Napier ERROR日志记录成功"
        } catch (e: Exception) {
            "Napier ERROR日志记录失败: ${e.message}"
        }
    }

    fun testNapierWithException(): String {
        return try {
            setupNapier()
            val exception = Exception("测试异常")
            Napier.e("这是一个带异常的日志消息", throwable = exception, tag = "NapierTest")
            "Napier 异常日志记录成功"
        } catch (e: Exception) {
            "Napier 异常日志记录失败: ${e.message}"
        }
    }

    // 测试所有功能
    fun runAllTests(): String {
        val results = mutableListOf<String>()

        results.add("== NapierTest 测试结果 ==")
        results.add(testNapierDebug())
        results.add(testNapierInfo())
        results.add(testNapierWarning())
        results.add(testNapierError())
        results.add(testNapierWithException())

        return results.joinToString("\n")
    }
}
