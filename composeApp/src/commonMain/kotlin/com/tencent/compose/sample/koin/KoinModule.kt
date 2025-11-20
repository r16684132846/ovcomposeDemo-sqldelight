package com.tencent.compose.sample.koin
import org.koin.core.module.dsl.bind
import org.koin.core.module.dsl.singleOf
import org.koin.core.module.dsl.viewModelOf
import org.koin.dsl.module
import org.koin.mp.KoinPlatformTools

// 使用 Koin 4.x 的 DSL 定义模块
val appModule = module {
    // singleOf 是 Koin 4.x 中推荐的方式之一 (实验性，但更简洁)
    singleOf(::UserRepositoryImpl) { bind<UserRepository>() }
    singleOf(::ValidationServiceImpl) { bind<ValidationService>() }

    viewModelOf(::UserViewModel)

}

// Koin 验证器
class KoinValidator {
    fun validateKoinSetup(): List<String> {
        val results = mutableListOf<String>()
        try {
            val koin = KoinPlatformTools.defaultContext().get()
            results.add("✅ Koin 实例创建成功 (v4.0.4)")

            val repository = koin.get<UserRepository>()
            results.add("✅ UserRepository 解析成功: ${repository::class.simpleName}")

            val service = koin.get<ValidationService>()
            results.add("✅ ValidationService 解析成功: ${service::class.simpleName}")

            val viewModel = koin.get<UserViewModel>()
            results.add("✅ UserViewModel 解析成功: ${viewModel::class.simpleName}")

            val initialCount = viewModel.getUserCount()
            results.add("✅ 依赖注入工作正常，初始用户数: $initialCount")

            val repository2 = koin.get<UserRepository>()
            val isSingleton = repository === repository2
            results.add("✅ 单例验证: $isSingleton")

        } catch (e: Exception) {
            results.add("❌ Koin 验证失败: ${e.message}")
        }
        return results
    }

    // testDependencyInjection 方法内容与之前相同
    fun testDependencyInjection(): List<String> {
        val results = mutableListOf<String>()
        try {
            val koin = KoinPlatformTools.defaultContext().get()
            val viewModel = koin.get<UserViewModel>()

            val testResult1 = viewModel.addUser("Test User", "test@example.com")
            results.add("✅ 添加用户测试: $testResult1")

            val testResult2 = viewModel.addUser("A", "invalid-email")
            results.add("✅ 验证失败测试: ${testResult2.contains("Invalid")}")

            val finalCount = viewModel.getUserCount()
            results.add("✅ 最终用户计数: $finalCount")

        } catch (e: Exception) {
            results.add("❌ 依赖注入测试失败: ${e.message}")
        }
        return results
    }
}