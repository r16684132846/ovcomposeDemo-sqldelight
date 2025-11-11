package com.tencent.compose.sample

import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
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
import androidx.compose.ui.napi.asString
import androidx.compose.ui.unit.dp
import androidx.compose.ui.napi.js
import kotlinx.cinterop.ExperimentalForeignApi

@OptIn(ExperimentalForeignApi::class)
@Composable
internal fun WebViewExample() {
    var url by remember { mutableStateOf("https://www.baidu.com/") }
    var canGoBack by remember { mutableStateOf(false) }
    var canGoForward by remember { mutableStateOf(false) }

    // 记录首页URL
    val homeUrl by remember { mutableStateOf(url) }

    // 导航命令状态
    var navigationCommand by remember { mutableStateOf("") }
    var navigationCommandId by remember { mutableStateOf(0) }

    val userAgent =
        "Mozilla/5.0 (OpenHarmony) AppleWebKit/537.36 (KHTML, like Gecko) Version/9.0 Mobile"

    // 是否加载失败
    val webViewError by remember { mutableStateOf<String?>(null) }

    Column(
        modifier = Modifier.fillMaxSize()
    ) {
        TextField(
            value = url,
            onValueChange = {
                url = it
                println("URL输入变更，同步到鸿蒙端: $url")
            },
            modifier = Modifier
                .fillMaxWidth()
                .padding(8.dp),
            label = { Text("URL") }
        )

        Button(
            onClick = {
                navigationCommand = "loadUrl"
                navigationCommandId++
                println("kn numId--加载 url更新 : $navigationCommandId , $url")
            },
            modifier = Modifier
                .fillMaxWidth()
                .padding(8.dp)
        ) {
            Text("加载")
        }

        // 导航控制按钮
        Row(
            modifier = Modifier
                .fillMaxWidth()
                .padding(8.dp)
        ) {
            Button(
                onClick = {
                    navigationCommand = "back"
                    navigationCommandId++
                    println("kn numId--后退 url后退 : $navigationCommandId ,$navigationCommand,$url")
                },
//                enabled = canGoBack,
                modifier = Modifier.weight(1f).padding(4.dp)
            ) {
                Text("后退")
            }

            Button(
                onClick = {
                    navigationCommand = "forward"
                    navigationCommandId++
                    println("kn numId--前进 url前进 : $navigationCommandId ,$navigationCommand,$url")
                },
//                enabled = canGoForward,
                modifier = Modifier.weight(1f).padding(4.dp)
            ) {
                Text("前进")
            }

            Button(
                onClick = {
                    navigationCommand = "reload"
                    navigationCommandId++
                    println("kn numId--刷新 url刷新 : $navigationCommandId ,$navigationCommand ,$url")
                },
                modifier = Modifier.weight(1f).padding(4.dp)
            ) {
                Text("刷新")
            }

            Button(
                onClick = {
                    url = homeUrl
                    navigationCommand = "home"
                    navigationCommandId++
                    println("kn numId--加载 url更新 : $navigationCommandId , $url")
                },
                modifier = Modifier.weight(1f).padding(4.dp)
            ) {
                Text("首页")
            }
        }

        Box(
            modifier = Modifier
                .background(Color.Red)
                .size(500.dp, 500.dp)
        ) {
            if (webViewError == null) {
                ArkUIView(
                    name = "webview",
                    modifier = Modifier.fillMaxSize(),
                    parameter = js {
                        "url"(url)
                        println("kotlin传递给鸿蒙url : $url")
                        "userAgent"(userAgent)
                        "databaseEnabled"(true)
                        "domStorageEnabled"(true)
                        "cacheMode"("default")
                        "javaScriptEnabled"(true)
                        "navigationCommand"(navigationCommand)
                        "navigationCommandId"(navigationCommandId)
                        println("kotlin传递给鸿蒙navigationCommand和ID : $navigationCommand, $navigationCommandId")
                    },
                    update = { jsObject ->
                        val newUrl = jsObject["currentUrl"]?.asString()
                        if (!newUrl.isNullOrEmpty()) {
                            url = newUrl
                            println("鸿蒙返回url :  $url")
                        }
                        // 更新导航按钮状态
                        val backState = jsObject["canGoBack"]?.asString()
                        if (backState != null) {
                            canGoBack = backState.toBoolean()
                        }

                        val forwardState = jsObject["canGoForward"]?.asString()
                        if (forwardState != null) {
                            canGoForward = forwardState.toBoolean()
                        }
                    }
                )
            } else {
                Text("WebView加载失败: $webViewError")
            }
        }
    }
}


