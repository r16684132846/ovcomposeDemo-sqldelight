package com.tencent.compose.sqldelight

import app.cash.sqldelight.ColumnAdapter
import kotlinx.datetime.Instant
import kotlinx.datetime.LocalDate
import kotlinx.datetime.TimeZone
import kotlinx.datetime.UtcOffset
import kotlinx.datetime.atTime
import kotlinx.datetime.toInstant
import kotlinx.datetime.toLocalDateTime


class DateAdapter() : ColumnAdapter<LocalDate, Long> {
    override fun decode(databaseValue: Long): LocalDate {
        return Instant.fromEpochMilliseconds(databaseValue).toLocalDateTime(TimeZone.UTC).date
    }

    override fun encode(value: LocalDate): Long {
        val instant = value.atTime(0,0,0).toInstant(TimeZone.UTC)
        return instant.toEpochMilliseconds()
    }
}