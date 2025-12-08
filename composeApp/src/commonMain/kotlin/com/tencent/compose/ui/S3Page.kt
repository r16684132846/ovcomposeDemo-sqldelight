package com.tencent.compose.ui

import androidx.compose.foundation.layout.*
import androidx.compose.material.Button
import androidx.compose.material.MaterialTheme
import androidx.compose.material.Text
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.unit.dp
import com.tencent.compose.service.*
import kotlinx.coroutines.launch

@Composable
fun S3Page() {
    var message by remember { mutableStateOf("S3 功能演示") }
    var fileInfo by remember { mutableStateOf("") }
    var fileList by remember { mutableStateOf(emptyList<String>()) }
    val coroutineScope = rememberCoroutineScope()

    Column(
        modifier = Modifier
            .fillMaxSize()
            .padding(20.dp),
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        Text(
            text = message,
            fontSize = MaterialTheme.typography.h6.fontSize,
            fontWeight = MaterialTheme.typography.h6.fontWeight,
            modifier = Modifier.padding(bottom = 20.dp)
        )

        // 添加测试按钮
        Button(
            onClick = {
                coroutineScope.launch {
                    testUpload() { result -> message = result }
                }
            },
            modifier = Modifier
                .fillMaxWidth(0.8f)
                .padding(bottom = 10.dp)
        ) {
            Text("上传测试文件")
        }

        Button(
            onClick = {
                coroutineScope.launch {
                    testDownload() { result, info ->
                        message = result
                        fileInfo = info ?: ""
                    }
                }
            },
            modifier = Modifier
                .fillMaxWidth(0.8f)
                .padding(bottom = 10.dp)
        ) {
            Text("下载测试文件")
        }

        Button(
            onClick = {
                coroutineScope.launch {
                    listFiles("") { result, list ->
                        message = result
                        fileList = list ?: emptyList()
                    }
                }
            },
            modifier = Modifier
                .fillMaxWidth(0.8f)
                .padding(bottom = 10.dp)
        ) {
            Text("列出文件")
        }

        Button(
            onClick = {
                coroutineScope.launch {
                    getFileInfo("test.txt") { result, info ->
                        message = result
                        fileInfo = info ?: ""
                    }
                }
            },
            modifier = Modifier
                .fillMaxWidth(0.8f)
                .padding(bottom = 10.dp)
        ) {
            Text("获取文件信息")
        }

        Button(
            onClick = {
                coroutineScope.launch {
                    checkFileExists("test.txt") { result -> message = result }
                }
            },
            modifier = Modifier
                .fillMaxWidth(0.8f)
                .padding(bottom = 10.dp)
        ) {
            Text("检查文件是否存在")
        }

        Button(
            onClick = {
                coroutineScope.launch {
                    deleteFile("test.txt") { result -> message = result }
                }
            },
            modifier = Modifier
                .fillMaxWidth(0.8f)
                .padding(bottom = 10.dp)
        ) {
            Text("删除文件")
        }

        Button(
            onClick = {
                coroutineScope.launch {
                    copyFile("test.txt", "test_copy.txt") { result -> message = result }
                }
            },
            modifier = Modifier
                .fillMaxWidth(0.8f)
                .padding(bottom = 10.dp)
        ) {
            Text("复制文件")
        }

        Button(
            onClick = {
                coroutineScope.launch {
                    deleteFolder("test_folder") { result -> message = result }
                }
            },
            modifier = Modifier
                .fillMaxWidth(0.8f)
                .padding(bottom = 10.dp)
        ) {
            Text("删除文件夹")
        }

        // 显示文件信息
        Text(
            text = fileInfo,
            fontSize = MaterialTheme.typography.body1.fontSize,
            modifier = Modifier
                .padding(top = 20.dp, bottom = 20.dp)
                .align(Alignment.Start)
        )

        // 显示文件列表
        if (fileList.isNotEmpty()) {
            Column(
                modifier = Modifier
                    .fillMaxWidth()
                    .padding(top = 20.dp)
            ) {
                Text(
                    text = "文件列表:",
                    fontSize = MaterialTheme.typography.h5.fontSize,
                    modifier = Modifier.padding(bottom = 10.dp)
                )

                fileList.forEach { item ->
                    Text(
                        text = item,
                        fontSize = MaterialTheme.typography.body1.fontSize,
                        modifier = Modifier
                            .padding(bottom = 5.dp)
                            .align(Alignment.Start)
                    )
                }
            }
        }
    }
}

// 测试上传文件
private suspend fun testUpload(onUpdateMessage: (String) -> Unit) {
    try {
        val content = "这是一个测试文件的内容"
        val fileContent = content.encodeToByteArray()

        val success = uploadFile("test.txt", fileContent)
        if (success) {
            onUpdateMessage("文件上传成功")
        } else {
            onUpdateMessage("文件上传失败")
        }
    } catch (e: Exception) {
        onUpdateMessage("上传过程中出现错误: ${e.message}")
    }
}

// 测试下载文件
private suspend fun testDownload(onUpdateResult: (String, String?) -> Unit) {
    try {
        val data = downloadFile("test.txt")
        if (data != null) {
            val content = data.decodeToString()
            onUpdateResult("文件下载成功", "文件内容: $content")
        } else {
            onUpdateResult("文件下载失败", null)
        }
    } catch (e: Exception) {
        onUpdateResult("下载过程中出现错误: ${e.message}", null)
    }
}

// 列出文件
private suspend fun listFiles(
    prefix: String,
    onUpdateResult: (String, List<String>?) -> Unit
) {
    try {
        val files = listFiles(prefix)
        if (files != null) {
            val fileListText = files.map {
                "文件名: ${it.key}, 大小: ${it.size} 字节, 修改时间: ${it.lastModified}"
            }
            onUpdateResult("找到 ${files.size} 个文件", fileListText)
        } else {
            onUpdateResult("获取文件列表失败", null)
        }
    } catch (e: Exception) {
        onUpdateResult("获取文件列表时出现错误: ${e.message}", null)
    }
}

// 获取文件信息
private suspend fun getFileInfo(fileName: String, onUpdateResult: (String, String?) -> Unit) {
    try {
        val info = getFileInfo(fileName)
        if (info != null) {
            val infoText =
                "文件名: ${info.name}\n大小: ${info.size} 字节\n修改时间: ${info.lastModified}\n类型: ${info.contentType}"
            onUpdateResult("获取文件信息成功", infoText)
        } else {
            onUpdateResult("获取文件信息失败", null)
        }
    } catch (e: Exception) {
        onUpdateResult("获取文件信息时出现错误: ${e.message}", null)
    }
}

// 检查文件是否存在
private suspend fun checkFileExists(fileName: String, onUpdateMessage: (String) -> Unit) {
    try {
        val exists = isFileExists(fileName)
        if (exists) {
            onUpdateMessage("文件存在")
        } else {
            onUpdateMessage("文件不存在")
        }
    } catch (e: Exception) {
        onUpdateMessage("检查文件存在性时出现错误: ${e.message}")
    }
}

// 删除文件
private suspend fun deleteFile(fileName: String, onUpdateMessage: (String) -> Unit) {
    try {
        val success = deleteFile(fileName)
        if (success) {
            onUpdateMessage("文件删除成功")
        } else {
            onUpdateMessage("文件删除失败")
        }
    } catch (e: Exception) {
        onUpdateMessage("删除文件时出现错误: ${e.message}")
    }
}

// 复制文件
private suspend fun copyFile(
    sourceFileName: String,
    targetFileName: String,
    onUpdateMessage: (String) -> Unit
) {
    try {
        val success = copyFile(sourceFileName, targetFileName)
        if (success) {
            onUpdateMessage("文件复制成功")
        } else {
            onUpdateMessage("文件复制失败")
        }
    } catch (e: Exception) {
        onUpdateMessage("复制文件时出现错误: ${e.message}")
    }
}

// 删除文件夹
private suspend fun deleteFolder(folderPath: String, onUpdateMessage: (String) -> Unit) {
    try {
        val success = deleteFolder(folderPath)
        if (success) {
            onUpdateMessage("文件夹删除成功")
        } else {
            onUpdateMessage("文件夹删除失败")
        }
    } catch (e: Exception) {
        onUpdateMessage("删除文件夹时出现错误: ${e.message}")
    }
}
