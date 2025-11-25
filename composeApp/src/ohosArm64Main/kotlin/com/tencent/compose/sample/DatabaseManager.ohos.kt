package com.tencent.compose.sample

import app.cash.sqldelight.db.SqlDriver
import com.tencent.compose.db.MyDatabase

//提供数据库管理功能
object DatabaseManager {
    private var database: MyDatabase? = null
    private var driver: SqlDriver? = null

    fun initialize(): Boolean {
        return try {
            if (database == null) {
                val dbDriver = DatabaseConfig().createDriver()
                driver = dbDriver
                database = MyDatabase(dbDriver)
            }
            true
        } catch (e: Exception) {
            println("数据库初始化失败: ${e.message}")
            e.printStackTrace()
            false
        }
    }

    fun getDatabase(): MyDatabase {
        return database ?: throw IllegalStateException("Database not initialized")
    }

    fun close() {
        try {
            driver?.close()
        } catch (e: Exception) {
            println("关闭数据库时出错: ${e.message}")
        } finally {
            database = null
            driver = null
        }
    }
}
