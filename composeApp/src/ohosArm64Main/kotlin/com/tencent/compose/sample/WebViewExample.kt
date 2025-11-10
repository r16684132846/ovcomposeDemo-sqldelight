package com.tencent.compose.sample

import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.height
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
import com.multiplatform.webview.web.LoadingState
import com.multiplatform.webview.web.rememberWebViewNavigator
import com.multiplatform.webview.web.rememberWebViewState
import androidx.compose.ui.napi.js
import kotlinx.cinterop.ExperimentalForeignApi

@OptIn(ExperimentalForeignApi::class)
@Composable
internal fun WebViewExample() {
    var url by remember { mutableStateOf("https://www.baidu.com") }
    val state = rememberWebViewState(url = url)
    val navigator = rememberWebViewNavigator()

    // 记录首页URL（用户首次访问的页面）
    val homeUrl by remember { mutableStateOf(url) }

    // 导航命令状态（关键修改：确保状态可观察且递增）
    var navigationCommand by remember { mutableStateOf("") }
    var navigationCommandId by remember { mutableStateOf(0) } // 初始ID为0

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
                .height(60.dp)
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

        // 显示页面加载状态
//        Text(
//            text = when (state.loadingState) {
//                is LoadingState.Initializing -> "初始化中..."
//                is LoadingState.Loading -> "加载中... ${(state.loadingState as LoadingState.Loading).progress}%"
//                is LoadingState.Finished -> "加载完成"
//            },
//            modifier = Modifier.padding(8.dp)
//        )

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
                enabled = navigator.canGoBack,
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
                enabled = navigator.canGoForward,
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
                    // 返回到首页URL（用户首次访问的页面）
                    url = homeUrl
//                    navigator.loadUrl(homeUrl)
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
                    },
                    update = { jsObject ->
                        val newUrl = jsObject["currentUrl"]?.asString()?.toString()
                        if (!newUrl.isNullOrEmpty()) {
                            url = newUrl
                            println("鸿蒙返回url :  $url")
                        }
                    }
                )
            } else {
                Text("WebView加载失败: $webViewError")
            }
        }
    }
}


