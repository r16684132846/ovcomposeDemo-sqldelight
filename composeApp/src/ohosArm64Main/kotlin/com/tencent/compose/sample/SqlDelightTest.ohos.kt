package com.tencent.compose.sample

import app.cash.sqldelight.db.SqlDriver
import app.cash.sqldelight.driver.native.NativeSqliteDriver
import com.tencent.compose.db.MyDatabase

//提供平台特定的驱动创建方法
actual fun createTestDriver(): SqlDriver {
    return try {
        // 尝试使用新的配置方式
        DatabaseConfig().createDriver("test.db")
    } catch (e: Exception) {
        println("使用自定义配置创建数据库失败，回退到默认方式: ${e.message}")
        try {
            // 回退到简单方式
            NativeSqliteDriver(MyDatabase.Schema, "test.db")
        } catch (fallbackException: Exception) {
            throw RuntimeException("无法创建数据库驱动: ${fallbackException.message}")
        }
    }
}
