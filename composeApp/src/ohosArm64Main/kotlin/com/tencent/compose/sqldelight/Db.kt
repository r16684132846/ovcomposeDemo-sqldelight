package com.tencent.compose.sqldelight

import app.cash.sqldelight.db.SqlDriver
import app.cash.sqldelight.driver.native.NativeSqliteDriver
import platform.posix.setenv
import kotlin.concurrent.AtomicReference
import kotlin.native.concurrent.freeze

actual fun getDbInstance(): AppDatabase {
    return Db.instance
}

object Db {
    private val driverRef = AtomicReference<SqlDriver?>(null)
    private val dbRef = AtomicReference<AppDatabase?>(null)

    internal fun dbSetup(driver: SqlDriver) {
        val db = createQueryWrapper(driver)
        driverRef.value = driver.freeze()
        dbRef.value = db.freeze()
    }

    internal fun dbClear() {
        driverRef.value!!.close()
        dbRef.value = null
        driverRef.value = null
    }

    // Called from Swift
    @Suppress("unused")
    fun defaultDriver() {
        println("fwd:------->:set env")
        val ret = setenv("HOME","/data/storage/el2/base/cache/",1)
        println("fwd:------->:init sql driver $ret")
        Db.dbSetup(NativeSqliteDriver(Schema, "app.db"))
    }

    val instance: AppDatabase
        get() = dbRef.value!!
}