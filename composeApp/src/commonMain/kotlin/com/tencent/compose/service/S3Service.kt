package com.tencent.compose.service

import kotlinx.datetime.Instant

/**
 * S3对象接口
 */
data class FileItem(
    val key: String,
    val lastModified: Instant,
    val eTag: String,
    val size: Long,
    val storageClass: String
)

/**
 * 文件信息接口
 */
data class FileInfo(
    val name: String,
    val size: Long,
    val lastModified: Instant,
    val contentType: String
)

/**
 * 上传文件
 * @param fileName 文件名
 * @param fileContent 文件内容
 * @return 是否上传成功
 */
expect suspend fun uploadFile(fileName: String, fileContent: ByteArray): Boolean

/**
 * 下载文件
 * @param fileName 文件名
 * @return 文件内容
 */
expect suspend fun downloadFile(fileName: String): ByteArray?

/**
 * 列出文件
 * @param prefix 文件前缀
 * @return 文件列表
 */
expect suspend fun listFiles(prefix: String): List<FileItem>?

/**
 * 获取文件信息
 * @param fileName 文件名
 * @return 文件信息
 */
expect suspend fun getFileInfo(fileName: String): FileInfo?

/**
 * 检查文件是否存在
 * @param fileName 文件名
 * @return 是否存在
 */
expect suspend fun isFileExists(fileName: String): Boolean

/**
 * 删除文件
 * @param fileName 文件名
 * @return 是否删除成功
 */
expect suspend fun deleteFile(fileName: String): Boolean

/**
 * 复制文件
 * @param sourceFileName 源文件名
 * @param targetFileName 目标文件名
 * @return 是否复制成功
 */
expect suspend fun copyFile(sourceFileName: String, targetFileName: String): Boolean

/**
 * 删除文件夹
 * @param folderPath 文件夹路径
 * @return 是否删除成功
 */
expect suspend fun deleteFolder(folderPath: String): Boolean
