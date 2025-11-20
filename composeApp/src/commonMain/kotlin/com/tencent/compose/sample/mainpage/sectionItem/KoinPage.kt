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

import androidx.compose.foundation.clickable
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxHeight
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.heightIn
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.material.Button
import androidx.compose.material.OutlinedTextField
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.getValue
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import com.tencent.compose.sample.koin.KoinValidator
import com.tencent.compose.sample.koin.UserViewModel
import org.koin.compose.koinInject
import org.koin.compose.viewmodel.koinViewModel

@Composable
internal fun KoinPage() {
    val koinValidator = KoinValidator()
    val textContent = "koin 功能验证"
    var koinConfigResult by mutableStateOf( "")
    var koinInjectResult by mutableStateOf( "")
    LazyColumn(modifier = Modifier.fillMaxSize().fillMaxHeight()) {
        item {
            Text(text = textContent)
            Text(
                text = "Koin 配置验证",
                color = Color.Red,
                fontSize = 16.sp,
                modifier = Modifier.clickable {
                    koinConfigResult = koinValidator.validateKoinSetup().joinToString("\n")
                }
            )
            Text(text = koinConfigResult)
            Spacer(modifier = Modifier.fillMaxWidth().height(10.dp))
        }
        item {
            Text(text = textContent)
            Text(
                text = "Koin 依赖注入验证",
                color = Color.Red,
                fontSize = 16.sp,
                modifier = Modifier.clickable {
                    koinInjectResult = koinValidator.testDependencyInjection().joinToString("\n")
                }
            )
            Text(text = koinInjectResult)
            Spacer(modifier = Modifier.fillMaxWidth().height(10.dp))
        }
        item {
            Text(text = "koin 实时功能验证")
            LiveDemo()
        }
    }
}

@Composable
fun LiveDemo() {
    // 使用 koinInject() 获取 ViewModel (Koin 4.x Compose 集成)
    val viewModel: UserViewModel = koinInject()
    var userName by remember { mutableStateOf("") }
    var userEmail by remember { mutableStateOf("") }

    Column(
        modifier = Modifier.fillMaxWidth(),
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        Text("当前用户数: ${viewModel.getUserCount()}")

        if (viewModel.state.message.isNotBlank()) {
            Text(
                text = viewModel.state.message,
                modifier = Modifier.padding(4.dp)
            )
        }

        Spacer(modifier = Modifier.height(8.dp))

        OutlinedTextField(
            value = userName,
            onValueChange = { userName = it },
            label = { Text("用户名") },
            modifier = Modifier.fillMaxWidth()
        )

        Spacer(modifier = Modifier.height(8.dp))

        OutlinedTextField(
            value = userEmail,
            onValueChange = { userEmail = it },
            label = { Text("邮箱") },
            modifier = Modifier.fillMaxWidth()
        )

        Spacer(modifier = Modifier.height(8.dp))

        Button(
            onClick = {
                val result = viewModel.addUser(userName, userEmail)
                if (result == "SUCCESS") {
                    userName = ""
                    userEmail = ""
                }
            }
        ) {
            Text("添加用户")
        }

        Spacer(modifier = Modifier.height(8.dp))

        val users = viewModel.getAllUsers()
        if (users.isNotEmpty()) {
            Text("用户列表:", fontWeight = FontWeight.Bold)
            LazyColumn(
                modifier = Modifier.heightIn(max = 150.dp)
            ) {
                items(users) { user ->
                    Text(
                        text = "${user.id}. ${user.name} - ${user.email}",
                        modifier = Modifier.padding(2.dp)
                    )
                }
            }
        }
    }
}

