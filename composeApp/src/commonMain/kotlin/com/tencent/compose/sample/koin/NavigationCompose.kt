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

package com.tencent.compose.sample.mainpage.sectionItem

import androidx.compose.animation.slideInHorizontally
import androidx.compose.animation.slideOutHorizontally
import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.size
import androidx.compose.foundation.text.BasicText
import androidx.compose.material.Button
import androidx.compose.material.ButtonDefaults
import androidx.compose.material.Card
import androidx.compose.material.MaterialTheme
import androidx.compose.material.Scaffold
import androidx.compose.material.Surface
import androidx.compose.material.Text
import androidx.compose.material.TopAppBar
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.platform.testTag
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import androidx.navigation.NavController
import androidx.navigation.NavHostController
import androidx.navigation.compose.NavHost
import androidx.navigation.compose.composable
import androidx.navigation.compose.rememberNavController
import org.jetbrains.compose.ui.tooling.preview.Preview
import androidx.compose.runtime.CompositionLocalProvider
import androidx.compose.runtime.remember
import androidx.compose.runtime.staticCompositionLocalOf
import androidx.lifecycle.LifecycleOwner
import androidx.lifecycle.ViewModelStoreOwner
import androidx.lifecycle.ViewModelStore
import androidx.lifecycle.compose.LocalLifecycleOwner
import androidx.lifecycle.viewmodel.compose.LocalViewModelStoreOwner

sealed class NavigationScreen(val route: String) {
    object Main : NavigationScreen("main")
    object Profile : NavigationScreen("profile")
    object Settings : NavigationScreen("settings")
    object Details : NavigationScreen("details")
}

class DefaultLifecycleOwner : LifecycleOwner, ViewModelStoreOwner {
    override val lifecycle = androidx.lifecycle.LifecycleRegistry(this)
    override val viewModelStore = androidx.lifecycle.ViewModelStore()

    // 初始化生命周期（标记为已创建）
    init {
        lifecycle.currentState = androidx.lifecycle.Lifecycle.State.CREATED
    }
}
@Preview
@Composable
internal fun NavigationComposeTest() {
    val navController = rememberNavController()
    Scaffold(
        topBar = {
            TopAppBar(
                title = { Text("ovCompose Navigation Demo") },
                backgroundColor = MaterialTheme.colors.primary,
                contentColor = Color.White
            )
        }
    ) { innerPadding ->
        Surface(
            modifier = Modifier
                .padding(innerPadding)
                .fillMaxSize(),
            color = MaterialTheme.colors.background
        ) {
            NavigationHost(navController = navController)
        }
    }
}

@Composable
private fun NavigationHost(navController: NavHostController) {
    // 创建默认生命周期所有者
    val defaultLifecycleOwner = remember { DefaultLifecycleOwner() }

    // 手动注入 LocalLifecycleOwner
    CompositionLocalProvider(
        LocalLifecycleOwner provides defaultLifecycleOwner,
        LocalViewModelStoreOwner provides defaultLifecycleOwner
    ) {
        NavHost(
            navController = navController,
            startDestination = NavigationScreen.Main.route,
            modifier = Modifier.testTag("navigationHost")
        ) {
            composable(NavigationScreen.Main.route) {
                MainScreen(navController)
            }
            composable(NavigationScreen.Profile.route) {
                ProfileScreen(navController)
            }
            composable(NavigationScreen.Settings.route) {
                SettingsScreen(navController)
            }
            composable(NavigationScreen.Details.route) {
                DetailsScreen(navController)
            }
        }
    }
}

@Composable
private fun MainScreen(navController: NavController) {
    Column(
        modifier = Modifier
            .padding(16.dp)
            .fillMaxSize(),
        verticalArrangement = Arrangement.Center,
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        Text(
            text = "主页面",
            fontSize = 24.sp,
            fontWeight = FontWeight.Bold,
            modifier = Modifier.padding(bottom = 32.dp)
        )

        NavigationButton(
            text = "前往个人资料",
            onClick = {
                try {
                    navController.navigate(NavigationScreen.Profile.route)
                } catch (e: Exception) {
                    // 抛出更详细的错误信息
                    throw RuntimeException("导航到个人资料失败: ${e.message}", e)
                }
            },
            modifier = Modifier.testTag("profileButton")
        )

        Spacer(modifier = Modifier.height(16.dp))

        NavigationButton(
            text = "前往设置",
            onClick = {
                try {
                    navController.navigate(NavigationScreen.Settings.route)
                } catch (e: Exception) {
                    throw RuntimeException("导航到设置失败: ${e.message}", e)
                }
            },
            modifier = Modifier.testTag("settingsButton")
        )

        Spacer(modifier = Modifier.height(16.dp))

        NavigationButton(
            text = "查看详情",
            onClick = {
                try {
                    navController.navigate(NavigationScreen.Details.route)
                } catch (e: Exception) {
                    throw RuntimeException("导航到详情失败: ${e.message}", e)
                }
            },
            modifier = Modifier.testTag("detailsButton")
        )
    }
}

@Composable
private fun ProfileScreen(navController: NavController) {
    Column(
        modifier = Modifier
            .padding(16.dp)
            .fillMaxSize(),
        verticalArrangement = Arrangement.Center,
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        Card(
            modifier = Modifier
                .fillMaxWidth()
                .padding(16.dp),
            elevation = 8.dp,
            backgroundColor = MaterialTheme.colors.surface
        ) {
            Column(
                modifier = Modifier.padding(16.dp),
                horizontalAlignment = Alignment.CenterHorizontally
            ) {
                Text(
                    text = "个人资料",
                    fontSize = 20.sp,
                    fontWeight = FontWeight.Bold,
                    modifier = Modifier.padding(bottom = 16.dp)
                )
                Text("姓名: 示例用户")
                Text("邮箱: user@example.com")
                Text("部门: 技术研发部")
            }
        }

        Spacer(modifier = Modifier.height(32.dp))

        NavigationButton(
            text = "返回主页",
            onClick = { navController.popBackStack() },
            modifier = Modifier.testTag("backToMainButton")
        )
    }
}

@Composable
private fun SettingsScreen(navController: NavController) {
    Column(
        modifier = Modifier
            .padding(16.dp)
            .fillMaxSize(),
        verticalArrangement = Arrangement.Center,
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        Text(
            text = "设置页面",
            fontSize = 24.sp,
            fontWeight = FontWeight.Bold,
            modifier = Modifier.padding(bottom = 32.dp)
        )

        Card(
            modifier = Modifier
                .fillMaxWidth()
                .padding(8.dp),
            elevation = 4.dp
        ) {
            Column(modifier = Modifier.padding(16.dp)) {
                Text("通知设置", fontWeight = FontWeight.Medium)
                Text("语言设置", fontWeight = FontWeight.Medium)
                Text("隐私设置", fontWeight = FontWeight.Medium)
            }
        }

        Spacer(modifier = Modifier.height(32.dp))

        Row(
            horizontalArrangement = Arrangement.spacedBy(16.dp)
        ) {
            NavigationButton(
                text = "返回",
                onClick = { navController.popBackStack() },
                modifier = Modifier.testTag("backFromSettingsButton")
            )

            NavigationButton(
                text = "去详情",
                onClick = { navController.navigate(NavigationScreen.Details.route) },
                backgroundColor = Color(0.4f, 0.3137255f, 0.6431373f, 1.0f),
                modifier = Modifier.testTag("toDetailsFromSettingsButton")
            )
        }
    }
}
@Composable
private fun DetailsScreen(navController: NavController) {
    Column(
        modifier = Modifier
            .padding(16.dp)
            .fillMaxSize(),
        verticalArrangement = Arrangement.Center,
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        Text(
            text = "详情页面",
            fontSize = 24.sp,
            fontWeight = FontWeight.Bold,
            modifier = Modifier.padding(bottom = 24.dp)
        )

        Card(
            modifier = Modifier
                .fillMaxWidth()
                .padding(16.dp),
            elevation = 8.dp,
            backgroundColor = Color(0.91764706f, 0.8666667f, 1.0f, 1.0f)
        ) {
            Column(
                modifier = Modifier.padding(16.dp),
                horizontalAlignment = Alignment.CenterHorizontally
            ) {
                Text(
                    "项目详情",
                    fontSize = 18.sp,
                    fontWeight = FontWeight.Bold,
                    color = Color(0.4f, 0.3137255f, 0.6431373f, 1.0f)
                )
                Text("版本: 1.0.0")
                Text("构建时间: 2024-12-01")
            }
        }

        Spacer(modifier = Modifier.height(32.dp))

        NavigationButton(
            text = "返回主页",
            onClick = {
                navController.popBackStack(NavigationScreen.Main.route, inclusive = false)
            },
            backgroundColor = Color(0.4f, 0.3137255f, 0.6431373f, 1.0f),
            modifier = Modifier.testTag("backToHomeFromDetailsButton")
        )
    }
}

@Composable
private fun NavigationButton(
    text: String,
    onClick: () -> Unit,
    backgroundColor: Color = MaterialTheme.colors.primary,
    modifier: Modifier = Modifier
) {
    Button(
        onClick = onClick,
        modifier = modifier
            .fillMaxWidth()
            .height(56.dp),
        colors = ButtonDefaults.buttonColors(
            backgroundColor = backgroundColor
        )
    ) {
        Text(
            text = text,
            fontSize = 16.sp,
            color = Color.White
        )
    }
}

@Preview
@Composable
internal fun NavigationPreview() {
    MaterialTheme {
        NavigationComposeTest()
    }
}

private const val FIRST = "first"
private const val SECOND = "second"
private const val THIRD = "third"

private val Blue = Color(0xFF2196F3)
private val Green = Color(0xFF4CAF50)