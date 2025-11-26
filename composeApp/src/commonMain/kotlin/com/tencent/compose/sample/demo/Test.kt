package com.tencent.compose.sample.demo

import com.tencent.compose.sqldelight.getDbInstance

fun sqlTest(): String {
    val db = getDbInstance()
    val teams = db.teamQueries.selectAll().executeAsList()
    val players = db.playerQueries.selectAll().executeAsList()
    println("team count: ${teams.size}")
    println("player count: ${players.size}")
    return "Team count: ${teams.size}    Player count: ${players.size}"
}