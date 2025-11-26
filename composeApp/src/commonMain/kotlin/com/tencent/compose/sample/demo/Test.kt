package com.tencent.compose.sample.demo

import com.tencent.compose.sqldelight.getDbInstance
import org.kotlincrypto.hash.sha1.SHA1

fun hashTest(): String {
    // 创建SHA1实例
    val sha1 = SHA1()

    // 测试数据
    val testData = "Hello, World!"
    // testData.  // 删除这行
    val testDataBytes = testData.encodeToByteArray()

    // 使用KotlinCrypto SHA1计算哈希
    val hashResult = sha1.digest(testDataBytes)

    // 转换为十六进制字符串以便显示
    val hexResult = hashResult.joinToString("")

    println("原始数据: $testData")
    println("SHA-1 哈希值: $hexResult")
    return hexResult
}


fun sqlTest(): String {
    val db = getDbInstance()
    val teams = db.teamQueries.selectAll().executeAsList()
    val players = db.playerQueries.selectAll().executeAsList()
    println("team count: ${teams.size}")
    println("player count: ${players.size}")
    return "Team count: ${teams.size}    Player count: ${players.size}"
}