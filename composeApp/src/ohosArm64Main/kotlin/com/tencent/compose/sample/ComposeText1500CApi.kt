package com.tencent.compose.sample

import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.size
import androidx.compose.foundation.rememberScrollState
import androidx.compose.foundation.verticalScroll
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.unit.dp
import org.jetbrains.compose.resources.ExperimentalResourceApi
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.border
import androidx.compose.foundation.layout.fillMaxHeight
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.width

@OptIn(ExperimentalResourceApi::class)
@Composable
internal fun ComposeText1500CApi() {
    Column(
        modifier = Modifier
            .verticalScroll(rememberScrollState()) // 启用垂直滚动
            .fillMaxWidth(),
        horizontalAlignment = Alignment.CenterHorizontally // 水平居中所有子项
    ) {
        repeat(500) { index ->
            ArkUIView(
                name = "cApiSingleText",
                modifier = Modifier
                    .width(300.dp)
                    .height(50.dp),
            )
        }
    }
}
