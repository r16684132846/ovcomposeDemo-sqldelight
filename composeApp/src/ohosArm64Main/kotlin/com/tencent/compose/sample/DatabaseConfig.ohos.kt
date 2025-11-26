package com.tencent.compose.sample

import app.cash.sqldelight.db.AfterVersion
import app.cash.sqldelight.db.QueryResult
import app.cash.sqldelight.db.SqlDriver
import app.cash.sqldelight.db.SqlSchema
import app.cash.sqldelight.driver.native.NativeSqliteDriver
import app.cash.sqldelight.driver.native.wrapConnection
import co.touchlab.sqliter.DatabaseConfiguration
import kotlinx.cinterop.ExperimentalForeignApi
import platform.posix.getenv
import platform.posix.setenv

// 数据库配置类
class DatabaseConfig {
    @OptIn(ExperimentalForeignApi::class)
    fun createDriver(databaseName: String = "myDatabase.db"): SqlDriver {
        setenv("HOME", "/data/app/el2/100/database/com.tencent.compose/", 1)
        val config = DatabaseConfiguration(
            name = databaseName,
            version = DatabaseSchema.version.toInt(),
            create = { connection ->
                wrapConnection(connection) { DatabaseSchema.create(it) }
            },
            upgrade = { connection, oldVersion, newVersion ->
                wrapConnection(connection) {
                    DatabaseSchema.migrate(it, oldVersion.toLong(), newVersion.toLong())
                }
            },
            extendedConfig = DatabaseConfiguration.Extended(
                basePath = getenv("HOME")?.toString(),
            )
        )

        return NativeSqliteDriver(config)
    }
}

object DatabaseSchema : SqlSchema<QueryResult.Value<Unit>> {
    override val version: Long = 1

    override fun create(driver: SqlDriver): QueryResult.Value<Unit> {
        val result = driver.execute(
            identifier = null,
            sql = """
                CREATE TABLE IF NOT EXISTS Person (
                    id INTEGER NOT NULL PRIMARY KEY,
                    name TEXT NOT NULL,
                    age INTEGER NOT NULL
                )
            """.trimIndent(),
            parameters = 0
        )
        println("setupDatabase: $result")
        return QueryResult.Unit
    }

    override fun migrate(
        driver: SqlDriver,
        oldVersion: Long,
        newVersion: Long,
        vararg callbacks: AfterVersion
    ): QueryResult.Value<Unit> {
        // 处理从版本1到版本2的迁移
        when (oldVersion) {
            1L -> {
                // 添加新的字段或修改表结构
                driver.execute(
                    identifier = null,
                    sql = """
                        ALTER TABLE Person ADD COLUMN created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
                    """.trimIndent(),
                    parameters = 0
                )
            }

            else -> throw IllegalArgumentException("Migration from version $oldVersion is not supported")
        }
        return QueryResult.Unit
    }
}
