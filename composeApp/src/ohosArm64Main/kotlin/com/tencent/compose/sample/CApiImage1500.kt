package com.tencent.compose.sample

import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import org.jetbrains.compose.resources.ExperimentalResourceApi
import androidx.compose.foundation.layout.fillMaxHeight

@OptIn(ExperimentalResourceApi::class)
@Composable
internal fun CApiView1500Image() {
    Column(
        modifier = Modifier
//            .verticalScroll(rememberScrollState()) // 启用垂直滚动
            .fillMaxWidth(),
        horizontalAlignment = Alignment.CenterHorizontally // 水平居中所有子项
    ) {
        repeat(1) { index ->
            ArkUIView(
                name = "cApiImageView1500",
                modifier = Modifier
                    .fillMaxWidth()
                    .fillMaxHeight()
            )
        }
    }
}
