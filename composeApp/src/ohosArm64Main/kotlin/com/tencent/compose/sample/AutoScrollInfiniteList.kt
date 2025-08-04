package com.tencent.compose.sample

import androidx.compose.foundation.border
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.rememberLazyListState
import androidx.compose.foundation.rememberScrollState
import androidx.compose.foundation.verticalScroll
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.LaunchedEffect
import androidx.compose.runtime.mutableStateListOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.rememberCoroutineScope
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.unit.dp
import kotlinx.coroutines.delay


@Composable
fun AutoScrollingInfiniteList() {
    val items = remember { mutableStateListOf<Int>() }
    val coroutineScope = rememberCoroutineScope()
    val listState = rememberLazyListState()

    // 初始填充大量数据
    LaunchedEffect(Unit) {
        repeat(1000000) { items += it }
    }

    LaunchedEffect(Unit) {
        while (true) {
            delay(16)
            val nextIndex = (listState.firstVisibleItemIndex + 1).coerceAtMost(items.lastIndex)
            listState.scrollToItem(nextIndex)
        }
    }

    LazyColumn(
        state = listState,
        modifier = Modifier.fillMaxSize()
    ) {
        items(items.size) { index ->
            Box(
                modifier = Modifier
                    .fillMaxWidth()
                    .height(80.dp)
                    .padding(4.dp)
                    .border(1.dp, Color.DarkGray)
            ) {
                Text("Item $index", modifier = Modifier.align(Alignment.Center))
            }
        }
    }
}
