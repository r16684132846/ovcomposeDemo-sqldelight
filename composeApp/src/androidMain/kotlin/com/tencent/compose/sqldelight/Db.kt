package com.tencent.compose.sqldelight

import android.content.Context
import app.cash.sqldelight.driver.android.AndroidSqliteDriver
import java.util.concurrent.atomic.AtomicReference

actual fun getDbInstance(): AppDatabase {
    return Db.instance
}

object Db {
    private val driverRef = AtomicReference<AndroidSqliteDriver?>(null)
    private val dbRef = AtomicReference<AppDatabase?>(null)

    internal fun dbSetup(driver: AndroidSqliteDriver) {
        val db = createQueryWrapper(driver)
        driverRef.set(driver)
        dbRef.set(db)
    }

    internal fun dbClear() {
        driverRef.get()!!.close()
        dbRef.set(null)
        driverRef.set(null)
    }

    fun defaultDriver(context: Context) {
        Db.dbSetup(AndroidSqliteDriver(Schema, context, "app.db"))
    }

    val instance: AppDatabase
        get() = dbRef.get()!!
}


