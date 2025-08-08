package com.tencent.compose.sample

import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.wrapContentWidth
import androidx.compose.foundation.text.KeyboardOptions
import androidx.compose.material.Button
import androidx.compose.material.OutlinedTextField
import androidx.compose.material.Scaffold
import androidx.compose.material.Text
import androidx.compose.material.TextButton
import androidx.compose.material.TopAppBar
import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.text.input.KeyboardType
import androidx.compose.ui.unit.dp


@Composable
internal fun NestedLayerEntry() {
    var depth by remember { mutableStateOf<Int?>(null) }

    if (depth == null) {
        NestedLayerInputScreen { enteredDepth ->
            depth = enteredDepth
        }
    } else {
        NestedLayerScreen(
            depth = depth!!,
            onBack = { depth = null }
        )
    }
}

@Composable
internal fun NestedLayerInputScreen(onGenerate: (Int) -> Unit) {
    var text by remember { mutableStateOf("") }
    var error by remember { mutableStateOf<String?>(null) }

    Scaffold(
        topBar = { TopAppBar(title = { Text("嵌套层数") }) }
    ) { padding ->
        Column(
            modifier = Modifier
                .padding(padding)
                .padding(16.dp)
        ) {
            OutlinedTextField(
                value = text,
                onValueChange = { text = it; error = null },
                label = { Text("嵌套层数") },
                isError = error != null,
                keyboardOptions = KeyboardOptions(keyboardType = KeyboardType.Number),
                singleLine = true
            )
            Spacer(Modifier.height(20.dp))
            Button(onClick = {
                val depth = text.toIntOrNull()
                if (depth == null || depth < 0 || depth > 5000) {
                    error = "input layer number"
                } else {
                    onGenerate(depth)
                }
            }) {
                Text("生成 layers")
            }
        }
    }
}


@Composable
internal fun NestedLayerScreen(depth: Int, onBack: () -> Unit) {
    var currentLayer: @Composable () -> Unit = { Text("Inner Text") }

    repeat(depth) {
        val prev = currentLayer
        currentLayer = { Row (modifier = Modifier.wrapContentWidth()) { prev() } }
    }

    Scaffold(
        topBar = {
            TopAppBar(
                title = { Text("嵌套层数：$depth") },
                navigationIcon = {
                    TextButton(onClick = onBack) { Text("Back") }
                }
            )
        }
    ) { padding ->
        Box(
            modifier = Modifier
                .padding(padding)
                .padding(12.dp),
            contentAlignment = Alignment.TopStart
        ) {
            currentLayer()
        }
    }
}
