package com.tencent.compose.sample.koin

// 服务接口
interface ValidationService {
    fun validateEmail(email: String): Boolean
    fun validateName(name: String): Boolean
}

// 服务实现
class ValidationServiceImpl : ValidationService {
    override fun validateEmail(email: String): Boolean {
        return email.contains("@") && email.length > 5
    }

    override fun validateName(name: String): Boolean {
        return name.isNotBlank() && name.length >= 2
    }
}