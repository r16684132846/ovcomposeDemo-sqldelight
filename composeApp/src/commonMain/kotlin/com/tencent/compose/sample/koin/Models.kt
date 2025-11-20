package com.tencent.compose.sample.koin

data class User(val id: Int, val name: String, val email: String)
data class AppState(var count: Int, var message: String)