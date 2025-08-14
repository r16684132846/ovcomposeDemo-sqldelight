package com.tencent.compose.sample

import androidx.compose.foundation.border
import androidx.compose.foundation.layout.*
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.itemsIndexed
import androidx.compose.foundation.lazy.rememberLazyListState
import androidx.compose.material.Text
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.unit.dp

@Composable
internal fun ComposeLazy1500ViewWithString() {
    val totalCount = 1500
    val items = remember { List(totalCount) { it } }

    val listState = rememberLazyListState()

    val allocSizesBytes = remember { listOf(100, 200, 500, 1000, 2_000, 5_000) }

    LaunchedEffect(listState) {
        var idx = 0
        var lastIndex = 0
        var lastOffset = 0
        var accumPx = 0

        snapshotFlow { listState.firstVisibleItemIndex to listState.firstVisibleItemScrollOffset }
            .collect { (i, off) ->
                val dy = when {
                    i == lastIndex -> off - lastOffset
                    else -> (off - lastOffset) + (i - lastIndex) * 100  // 100 近似 item 高
                }
                lastIndex = i
                lastOffset = off
                accumPx += kotlin.math.abs(dy)

                if (accumPx >= 8) {
                    accumPx = 0
                    val bytes = allocSizesBytes[idx % allocSizesBytes.size]
                    val s = createStringOfApproxBytes(bytes)
                    if (idx % 50 == 0) {
                        println("onScroll alloc -> ${bytes}B (len=${s.length})  @index=$i, off=$off")
                    }
                    idx++
                }
            }
    }

    LazyColumn(
        state = listState,
        modifier = Modifier.fillMaxWidth()
    ) {
        itemsIndexed(items) { _, item ->
            Box(
                modifier = Modifier
                    .fillMaxWidth()
                    .height(100.dp)
                    .padding(vertical = 4.dp, horizontal = 8.dp)
                    .border(2.dp, Color.Red),
                contentAlignment = Alignment.Center
            ) {
                Text("Item #$item")
            }
        }
    }
}

private fun createStringOfApproxBytes(bytes: Int): String {
    val chars = (bytes / 2).coerceAtLeast(1)
    return buildString(chars) {
        repeat(chars) { append('a') }
    }
}
