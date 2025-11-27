package com.tencent.compose.sample

import androidx.compose.foundation.border
import androidx.compose.foundation.layout.*
import androidx.compose.foundation.rememberScrollState
import androidx.compose.foundation.verticalScroll
import androidx.compose.material.Text
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp

@Composable
internal fun ComposeView1500Text() {
//    val startTime = remember { getTimeMillis() }
//
//    // 等待首帧绘制完毕后输出耗时
//    LaunchedEffect(Unit) {
//        val duration = getTimeMillis() - startTime
//        println("dzy Compose 页面构建 + 渲染耗时：${duration}ms")
//    }

    Column(
        modifier = Modifier
            .verticalScroll(rememberScrollState())
            .fillMaxWidth(),
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        repeat(1500) { index ->
            Text(
                text = "Item #$index",
                fontSize = 16.sp,
                modifier = Modifier
                    .width(300.dp)
                    .height(50.dp)
                    .border(1.dp, Color.Gray)
                    .padding(10.dp)
            )
        }
    }
}
