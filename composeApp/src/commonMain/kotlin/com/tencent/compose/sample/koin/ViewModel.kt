package com.tencent.compose.sample.koin

import androidx.lifecycle.ViewModel

class UserViewModel(
    private val userRepository: UserRepository,
    private val validationService: ValidationService
): ViewModel() {
    private var _state = AppState(0,"")
    val state: AppState get() = _state

    fun getAllUsers(): List<User> {
        return userRepository.getAllUsers()
    }

    fun addUser(name: String, email: String): String {
        return if (!validationService.validateName(name)) {
            "Invalid name: must be at least 2 characters"
        } else if (!validationService.validateEmail(email)) {
            "Invalid email format"
        } else {
            val newUser = User(
                id = userRepository.getUserCount() + 1,
                name = name,
                email = email
            )
            userRepository.addUser(newUser)
            _state = _state.copy(
                count = userRepository.getUserCount(),
                message = "User '$name' added successfully!"
            )
            "SUCCESS"
        }
    }

    fun getUserCount(): Int {
        return userRepository.getUserCount()
    }

    fun setCurrentUserID(count: Int) {
        userRepository.setCurrentUserID(count)
    }

    fun getCurrentUser(): User? {
        return userRepository.getCurrentUser()
    }
}
