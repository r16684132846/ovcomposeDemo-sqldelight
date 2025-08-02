package com.tencent.compose.sample

import androidx.compose.foundation.Image
import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.size
import androidx.compose.foundation.rememberScrollState
import androidx.compose.foundation.shape.CircleShape
import androidx.compose.foundation.verticalScroll
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.graphics.RectangleShape
import androidx.compose.ui.graphics.graphicsLayer
import androidx.compose.ui.graphics.painter.Painter
import androidx.compose.ui.layout.ContentScale
import androidx.compose.ui.unit.dp
import com.tencent.compose.sample.rememberLocalImage
import composesample.composeapp.generated.resources.Res
import composesample.composeapp.generated.resources.image_cat
import org.jetbrains.compose.resources.ExperimentalResourceApi
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.border
import androidx.compose.runtime.LaunchedEffect
import androidx.compose.runtime.SideEffect
import platform.test725.trace_tag_begin
import platform.test725.trace_tag_end
import platform.test725.trace_tag_cnt
import kotlinx.cinterop.ExperimentalForeignApi
import kotlinx.cinterop.cstr


@OptIn(ExperimentalForeignApi::class)
@Composable
internal fun ComposeView1500Page() {

    LaunchedEffect(Unit) {
        trace_tag_begin()
    }

    SideEffect {
        trace_tag_end()
    }


    Column(
        modifier = Modifier
            .verticalScroll(rememberScrollState()) // 启用垂直滚动
            .fillMaxWidth(),
        horizontalAlignment = Alignment.CenterHorizontally // 水平居中所有子项
    ) {
//        trace_tag_begin()
        // 创建1500个Box
        repeat(1500) { index ->
            Box(
                modifier = Modifier
                    .size(300.dp, 100.dp) // 设置宽高均为300dp
                    .border(
                        width = 2.dp, // 边框宽度
                        color = Color.Red, // 边框颜色为红色
                    )
            ) {
                Text(
                    text = "Item #$index",
                )
            }
        }
//        trace_tag_end()
    }
}
