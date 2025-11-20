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

package com.tencent.compose

import androidx.compose.runtime.CompositionLocalProvider
import androidx.compose.ui.platform.LocalLifecycleOwner
import androidx.compose.ui.window.ComposeArkUIViewController
import androidx.lifecycle.Lifecycle
import androidx.lifecycle.LifecycleOwner
import androidx.lifecycle.LifecycleRegistry
import androidx.lifecycle.ViewModelStore
import androidx.lifecycle.ViewModelStoreOwner
import androidx.lifecycle.viewmodel.compose.LocalViewModelStoreOwner
import com.tencent.compose.sample.NativeResourceManager
import com.tencent.compose.sample.koin.appModule
import com.tencent.compose.sample.mainpage.MainPage
import com.tencent.compose.sample.nativeResourceManager
import kotlinx.cinterop.ExperimentalForeignApi
import kotlinx.coroutines.initMainHandler
import org.koin.core.context.startKoin
import platform.ohos.napi_env
import platform.ohos.napi_value
import kotlin.experimental.ExperimentalNativeApi

@OptIn(ExperimentalNativeApi::class, ExperimentalForeignApi::class)
@CName("MainArkUIViewController")
fun MainArkUIViewController(env: napi_env): napi_value {
    initMainHandler(env)
    startKoin {
        modules(appModule)
    }
    return ComposeArkUIViewController(env) {
        val lifecycleOwner = object : LifecycleOwner {
            private val registry = LifecycleRegistry(this)
            override val lifecycle: Lifecycle
                get() = registry
        }
        val viewModelStoreOwner = object : ViewModelStoreOwner {
            override val viewModelStore: ViewModelStore = ViewModelStore()
        }
        CompositionLocalProvider(
            LocalLifecycleOwner provides lifecycleOwner,
            LocalViewModelStoreOwner provides viewModelStoreOwner
        ){
            MainPage()
        }
    }
}

@OptIn(ExperimentalForeignApi::class)
fun initResourceManager(resourceManager: NativeResourceManager) {
    nativeResourceManager = resourceManager
}

