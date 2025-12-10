package com.tencent.compose.ui

import androidx.compose.foundation.layout.*
import androidx.compose.foundation.rememberScrollState
import androidx.compose.foundation.verticalScroll
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
            .padding(20.dp)
            .verticalScroll(rememberScrollState()),
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        Text(
            text = message,
            fontSize = MaterialTheme.typography.h6.fontSize,
            fontWeight = MaterialTheme.typography.h6.fontWeight,
            modifier = Modifier.padding(bottom = 10.dp)
        )

        // 添加测试按钮
        Button(
            onClick = {
                println("点击上传测试文件按钮")
                coroutineScope.launch {
                    testUpload() { result ->
                        println("上传结果: $result")
                        message = result
                    }
                }
            },
            modifier = Modifier
                .fillMaxWidth(0.8f)
                .padding(bottom = 5.dp)
        ) {
            Text("上传测试文件")
        }

        Button(
            onClick = {
                println("点击下载测试文件按钮")
                coroutineScope.launch {
                    testDownload() { result, info ->
                        println("下载结果: $result")
                        message = result
                        fileInfo = info ?: ""
                    }
                }
            },
            modifier = Modifier
                .fillMaxWidth(0.8f)
                .padding(bottom = 5.dp)
        ) {
            Text("下载测试文件")
        }

        Button(
            onClick = {
                println("点击列出文件按钮")
                coroutineScope.launch {
                    listObjects("") { result, list ->
                        println("列出文件结果: $result")
                        message = result
                        fileList = list ?: emptyList()
                    }
                }
            },
            modifier = Modifier
                .fillMaxWidth(0.8f)
                .padding(bottom = 5.dp)
        ) {
            Text("列出文件")
        }

        Button(
            onClick = {
                println("点击获取文件信息按钮")
                coroutineScope.launch {
                    getFileInfo("test.txt") { result, info ->
                        println("获取文件信息结果: $result")
                        message = result
                        fileInfo = info ?: ""
                    }
                }
            },
            modifier = Modifier
                .fillMaxWidth(0.8f)
                .padding(bottom = 5.dp)
        ) {
            Text("获取文件信息")
        }

        Button(
            onClick = {
                println("点击检查文件是否存在按钮")
                coroutineScope.launch {
                    checkFileExists("test.txt") { result ->
                        println("检查文件存在性结果: $result")
                        message = result
                    }
                }
            },
            modifier = Modifier
                .fillMaxWidth(0.8f)
                .padding(bottom = 5.dp)
        ) {
            Text("检查文件是否存在")
        }

        Button(
            onClick = {
                println("点击删除文件按钮")
                coroutineScope.launch {
                    deleteFile("test.txt") { result ->
                        println("删除文件结果: $result")
                        message = result
                    }
                }
            },
            modifier = Modifier
                .fillMaxWidth(0.8f)
                .padding(bottom = 5.dp)
        ) {
            Text("删除文件")
        }

        Button(
            onClick = {
                println("点击复制文件按钮")
                coroutineScope.launch {
                    copy("test.txt", "test_copy.txt") { result ->
                        println("复制文件结果: $result")
                        message = result
                    }
                }
            },
            modifier = Modifier
                .fillMaxWidth(0.8f)
                .padding(bottom = 5.dp)
        ) {
            Text("复制文件")
        }

        Button(
            onClick = {
                println("点击删除文件夹按钮")
                coroutineScope.launch {
                    deleteFolder("test_folder") { result ->
                        println("删除文件夹结果: $result")
                        message = result
                    }
                }
            },
            modifier = Modifier
                .fillMaxWidth(0.8f)
                .padding(bottom = 5.dp)
        ) {
            Text("删除文件夹")
        }

        // 显示文件信息
        Text(
            text = fileInfo,
            fontSize = MaterialTheme.typography.body1.fontSize,
            modifier = Modifier
                .padding(top = 10.dp, bottom = 10.dp)
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
        println("开始上传文件")
        val content = "这是一个测试文件的内容"
        val fileContent = content.encodeToByteArray()

        val success = uploadFile("test.txt", fileContent)
        if (success) {
            println("文件上传成功")
            onUpdateMessage("文件上传成功")
        } else {
            println("文件上传失败")
            onUpdateMessage("文件上传失败")
        }
    } catch (e: Exception) {
        println("上传过程中出现错误: ${e.message}")
        onUpdateMessage("上传过程中出现错误: ${e.message}")
    }
}

// 测试下载文件
private suspend fun testDownload(onUpdateResult: (String, String?) -> Unit) {
    try {
        println("开始下载文件")
        val data = downloadFile("test.txt")
        if (data != null) {
            val content = data.decodeToString()
            println("文件下载成功，内容长度: ${data.size}")
            onUpdateResult("文件下载成功", "文件内容: $content")
        } else {
            println("文件下载失败，返回数据为空")
            onUpdateResult("文件下载失败", null)
        }
    } catch (e: Exception) {
        println("下载过程中出现错误: ${e.message}")
        onUpdateResult("下载过程中出现错误: ${e.message}", null)
    }
}

// 列出文件
private suspend fun listObjects(
    prefix: String,
    onUpdateResult: (String, List<String>?) -> Unit
) {
    try {
        println("开始列出文件，前缀: '$prefix'")
        val files = listObjects(prefix)
        if (files != null) {
            println("获取到 ${files.size} 个文件")
            val fileListText = files.map {
                "文件名: ${it.key}, 大小: ${it.size} 字节, 修改时间: ${it.lastModified}"
            }
            onUpdateResult("找到 ${files.size} 个文件", fileListText)
        } else {
            println("获取文件列表失败，返回为空")
            onUpdateResult("获取文件列表失败", null)
        }
    } catch (e: Exception) {
        println("获取文件列表时出现错误: ${e.message}")
        onUpdateResult("获取文件列表时出现错误: ${e.message}", null)
    }
}

// 获取文件信息
private suspend fun getFileInfo(fileName: String, onUpdateResult: (String, String?) -> Unit) {
    try {
        println("开始获取文件信息: $fileName")
        val info = getFileInfo(fileName)
        if (info != null) {
            val infoText =
                "文件名: ${info.name}\n大小: ${info.size} 字节\n修改时间: ${info.lastModified}\n类型: ${info.contentType}"
            println("获取文件信息成功: $infoText")
            onUpdateResult("获取文件信息成功", infoText)
        } else {
            println("获取文件信息失败，返回为空")
            onUpdateResult("获取文件信息失败", null)
        }
    } catch (e: Exception) {
        println("获取文件信息时出现错误: ${e.message}")
        onUpdateResult("获取文件信息时出现错误: ${e.message}", null)
    }
}

// 检查文件是否存在
private suspend fun checkFileExists(fileName: String, onUpdateMessage: (String) -> Unit) {
    try {
        println("开始检查文件是否存在: $fileName")
        val exists = existsFile(fileName)
        if (exists) {
            println("文件存在: $fileName")
            onUpdateMessage("文件存在")
        } else {
            println("文件不存在: $fileName")
            onUpdateMessage("文件不存在")
        }
    } catch (e: Exception) {
        println("检查文件存在性时出现错误: ${e.message}")
        onUpdateMessage("检查文件存在性时出现错误: ${e.message}")
    }
}

// 删除文件
private suspend fun deleteFile(fileName: String, onUpdateMessage: (String) -> Unit) {
    try {
        println("开始删除文件: $fileName")
        val success = deleteFile(fileName)
        if (success) {
            println("文件删除成功: $fileName")
            onUpdateMessage("文件删除成功")
        } else {
            println("文件删除失败: $fileName")
            onUpdateMessage("文件删除失败")
        }
    } catch (e: Exception) {
        println("删除文件时出现错误: ${e.message}")
        onUpdateMessage("删除文件时出现错误: ${e.message}")
    }
}

// 复制文件
private suspend fun copy(
    relativePath: String,
    toPath: String,
    onUpdateMessage: (String) -> Unit
) {
    try {
        println("开始复制文件: $relativePath -> $toPath")
        val success = copy(relativePath, toPath)
        if (success) {
            println("文件复制成功: $relativePath -> $toPath")
            onUpdateMessage("文件复制成功")
        } else {
            println("文件复制失败: $relativePath -> $toPath")
            onUpdateMessage("文件复制失败")
        }
    } catch (e: Exception) {
        println("复制文件时出现错误: ${e.message}")
        onUpdateMessage("复制文件时出现错误: ${e.message}")
    }
}

// 删除文件夹
private suspend fun deleteFolder(folderPath: String, onUpdateMessage: (String) -> Unit) {
    try {
        println("开始删除文件夹: $folderPath")
        val success = deleteFolder(folderPath)
        if (success) {
            println("文件夹删除成功: $folderPath")
            onUpdateMessage("文件夹删除成功")
        } else {
            println("文件夹删除失败: $folderPath")
            onUpdateMessage("文件夹删除失败")
        }
    } catch (e: Exception) {
        println("删除文件夹时出现错误: ${e.message}")
        onUpdateMessage("删除文件夹时出现错误: ${e.message}")
    }
}
