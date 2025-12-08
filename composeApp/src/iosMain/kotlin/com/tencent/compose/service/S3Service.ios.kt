package com.tencent.compose.service

/**
 * 上传文件
 * @param fileName 文件名
 * @param fileContent 文件内容
 * @return 是否上传成功
 */
actual suspend fun uploadFile(fileName: String, fileContent: ByteArray): Boolean {
    TODO("Not yet implemented")
}

/**
 * 下载文件
 * @param fileName 文件名
 * @return 文件内容
 */
actual suspend fun downloadFile(fileName: String): ByteArray? {
    TODO("Not yet implemented")
}

/**
 * 列出文件
 * @param prefix 文件前缀
 * @return 文件列表
 */
actual suspend fun listFiles(prefix: String): List<FileItem>? {
    TODO("Not yet implemented")
}

/**
 * 获取文件信息
 * @param fileName 文件名
 * @return 文件信息
 */
actual suspend fun getFileInfo(fileName: String): FileInfo? {
    TODO("Not yet implemented")
}

/**
 * 检查文件是否存在
 * @param fileName 文件名
 * @return 是否存在
 */
actual suspend fun isFileExists(fileName: String): Boolean {
    TODO("Not yet implemented")
}

/**
 * 删除文件
 * @param fileName 文件名
 * @return 是否删除成功
 */
actual suspend fun deleteFile(fileName: String): Boolean {
    TODO("Not yet implemented")
}

/**
 * 复制文件
 * @param sourceFileName 源文件名
 * @param targetFileName 目标文件名
 * @return 是否复制成功
 */
actual suspend fun copyFile(sourceFileName: String, targetFileName: String): Boolean {
    TODO("Not yet implemented")
}

/**
 * 删除文件夹
 * @param folderPath 文件夹路径
 * @return 是否删除成功
 */
actual suspend fun deleteFolder(folderPath: String): Boolean {
    TODO("Not yet implemented")
}