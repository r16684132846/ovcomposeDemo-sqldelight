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

import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.size
import androidx.compose.material.Button
import androidx.compose.material.Text
import androidx.compose.material.TextField
import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.unit.dp
import com.multiplatform.webview.web.LoadingState
import com.multiplatform.webview.web.WebViewNavigator
import com.multiplatform.webview.web.rememberWebViewNavigator
import com.multiplatform.webview.web.rememberWebViewState
import androidx.compose.ui.napi.js

@Composable
internal fun WebViewExample() {
    var url by remember { mutableStateOf("https://www.baidu.com") }
    val state = rememberWebViewState(url = url)
    val navigator = rememberWebViewNavigator()

    val userAgent =
        "Mozilla/5.0 (OpenHarmony) AppleWebKit/537.36 (KHTML, like Gecko) Version/9.0 Mobile"

    // 使用一个状态变量来记录是否加载失败
    val webViewError by remember { mutableStateOf<String?>(null) }

    Column(
        modifier = Modifier.fillMaxSize()
    ) {
        TextField(
            value = url,
            onValueChange = { url = it },
            modifier = Modifier
                .fillMaxWidth()
                .padding(8.dp),
            label = { Text("URL") }
        )

        Button(
            onClick = { navigator.loadUrl(url) },
            modifier = Modifier
                .fillMaxWidth()
                .padding(8.dp)
        ) {
            Text("加载")
        }

        WebViewNavigationControls(navigator, state)

        Box(
            modifier = Modifier
                .background(Color.Red)
                .size(500.dp, 500.dp)
        ) {
            // 将 ArkUIView 的创建放在一个独立的可组合函数中
            if (webViewError == null) {
                ArkUIView(
                    name = "webview",
                    modifier = Modifier.fillMaxSize(),
                    parameter = js {
                        "url"(url)
                        "userAgent"(userAgent)
                        "databaseEnabled"(true)
                        "domStorageEnabled"(true)
                        "cacheMode"("default")
                        "javaScriptEnabled"(true)
                    },
                )
            } else {
                Text("WebView加载失败: $webViewError")
            }
        }
    }
}


@Composable
private fun WebViewNavigationControls(
    navigator: WebViewNavigator,
    state: com.multiplatform.webview.web.WebViewState
) {
    // 显示页面加载状态
    Text(
        text = when (state.loadingState) {
            is com.multiplatform.webview.web.LoadingState.Initializing -> "初始化中..."
            is com.multiplatform.webview.web.LoadingState.Loading -> "加载中... ${(state.loadingState as LoadingState.Loading).progress}%"
            is com.multiplatform.webview.web.LoadingState.Finished -> "加载完成"
        },
        modifier = Modifier.padding(8.dp)
    )

    // 导航控制按钮
    androidx.compose.foundation.layout.Row(
        modifier = Modifier
            .fillMaxWidth()
            .padding(8.dp)
    ) {
        Button(
            onClick = { navigator.navigateBack() },
            enabled = navigator.canGoBack,
            modifier = Modifier.weight(1f).padding(4.dp)
        ) {
            Text("后退")
        }

        Button(
            onClick = { navigator.navigateForward() },
            enabled = navigator.canGoForward,
            modifier = Modifier.weight(1f).padding(4.dp)
        ) {
            Text("前进")
        }

        Button(
            onClick = { navigator.reload() },
            modifier = Modifier.weight(1f).padding(4.dp)
        ) {
            Text("刷新")
        }

        Button(
            onClick = { navigator.loadUrl("https://www.baidu.com") },
            modifier = Modifier.weight(1f).padding(4.dp)
        ) {
            Text("首页")
        }
    }
}
