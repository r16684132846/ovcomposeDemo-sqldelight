package com.tencent.compose.sample.koin

import org.koin.core.annotation.Factory
import org.koin.core.annotation.Module
import org.koin.core.annotation.Single


data class Cat(val id: String, val name: String)

interface CatRepository {
    fun getCats(): List<Cat>
}

@Single
class CatRepositoryImpl : CatRepository {
    override fun getCats(): List<Cat> = listOf(
        Cat("1", "John"),
        Cat("2", "Jane")
    )
}

@Single
class UserUseCase(
    private val catRepository: CatRepository
) {
    fun getAllUsers() = catRepository.getCats()
}

data class CatSession(val catId: String)

@Factory
class UserSessionFactory {
    fun createSession(catId: String): CatSession = CatSession(catId)
}

@Module
class CatModule