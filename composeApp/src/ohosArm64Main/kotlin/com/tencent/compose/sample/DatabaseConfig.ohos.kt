package com.tencent.compose.sample

import app.cash.sqldelight.db.SqlDriver
import app.cash.sqldelight.driver.native.NativeSqliteDriver
import app.cash.sqldelight.driver.native.wrapConnection
import co.touchlab.sqliter.DatabaseConfiguration
import com.tencent.compose.db.MyDatabase
import platform.posix.S_IRWXU
import platform.posix.mkdir
import platform.posix.S_IRWXG
import platform.posix.S_IRWXO

//HarmonyOS 特定的数据库配置
class DatabaseConfig {
    fun createDriver(databaseName: String = "app_database.db"): SqlDriver {
        // HarmonyOS 特定的数据库路径
        val databasePath = "/data/app/el2/100/database/com.tencent.compose/"

        // 确保目录存在
        mkdir(databasePath, (S_IRWXU.toUInt() or S_IRWXG.toUInt() or S_IRWXO.toUInt()))

        val config = DatabaseConfiguration(
            name = databaseName,
            version = MyDatabase.Schema.version.toInt(),
            create = { connection ->
                wrapConnection(connection) { MyDatabase.Schema.create(it) }
            },
            upgrade = { connection, oldVersion, newVersion ->
                wrapConnection(connection) {
                    MyDatabase.Schema.migrate(it, oldVersion.toLong(), newVersion.toLong())
                }
            },
            extendedConfig = DatabaseConfiguration.Extended(
                basePath = databasePath
            )
        )

        return NativeSqliteDriver(config)
    }
}
