package com.tencent.compose.sample

import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxHeight
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier

@Composable
internal fun FfiBenchmark() {
    Column() {
        ArkUIView(
            name = "FfiBenchmark",
            modifier = Modifier
                .fillMaxWidth()
                .fillMaxHeight()
        )
    }
}