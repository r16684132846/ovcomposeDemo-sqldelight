package com.tencent.compose.sample.koin

// 仓储接口
interface UserRepository {
    fun getAllUsers(): List<User>
    fun getUserById(id: Int): User?
    fun addUser(user: User)
    fun getUserCount(): Int
    fun setCurrentUserID(id: Int)
    fun getCurrentUser(): User?
}

// 仓储实现
class UserRepositoryImpl : UserRepository {
    private val users = mutableListOf<User>()
    private var currentUserID: Int = 0

    init {
        // 初始化一些测试数据
        users.addAll(listOf(
            User(1, "Alice", "alice@example.com"),
            User(2, "Bob", "bob@example.com")
        ))
    }

    override fun getAllUsers(): List<User> = users.toList()

    override fun getUserById(id: Int): User? = users.find { it.id == id }

    override fun addUser(user: User) {
        users.add(user)
    }

    override fun getUserCount(): Int = users.size

    override fun setCurrentUserID(id: Int) {
        currentUserID = id
    }

    override fun getCurrentUser(): User? {
        return getUserById(currentUserID)
    }
}