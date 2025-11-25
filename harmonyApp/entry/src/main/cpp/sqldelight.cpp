#include "libkn_api.h"
#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <hilog/log.h>
#include <libgen.h>
#include <string>
#include <sys/stat.h>


// 统一定义
#undef LOG_DOMAIN
#undef LOG_TAG
#define LOG_DOMAIN 0xD002D12
#define LOG_TAG "PDFIUM_NATIVE"

// 正确的日志宏
#define LOGI(fmt, ...) ((void)OH_LOG_Print(LOG_APP, LOG_INFO, LOG_DOMAIN, LOG_TAG, fmt, ##__VA_ARGS__))
#define LOGE(fmt, ...) ((void)OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_DOMAIN, LOG_TAG, fmt, ##__VA_ARGS__))

// 定义全局数据库路径变量
std::string g_dbPath = "";

// 创建目录的辅助函数
int createDirectories(const char *path) {
    char *temp = strdup(path);
    char *dir = dirname(temp);

    struct stat st;
    if (stat(dir, &st) == 0) {
        if (S_ISDIR(st.st_mode)) {
            free(temp);
            return 0; // 目录已存在
        } else {
            free(temp);
            return -1; // 存在同名非目录文件
        }
    }

    // 递归创建父目录
    char *parent = strdup(dir);
    char *parentDir = dirname(parent);
    if (strcmp(parentDir, ".") != 0 && strcmp(parentDir, "/") != 0 && strcmp(parentDir, dir) != 0) {
        createDirectories(parentDir);
    }

    // 确保父目录存在后再创建当前目录
    if (stat(parentDir, &st) == -1) {
        mkdir(parentDir, 0755);
    }

    int result = mkdir(dir, 0755);
    if (result != 0 && errno != EEXIST) {
        LOGE("Failed to create directory %s: %s", dir, strerror(errno));
    }

    free(parent);
    free(temp);
    return result;
}

extern "C" {
libkn_kref_app_cash_sqldelight_db_SqlDriver createTestDriver() {
    // 使用从HarmonyOS传入的正确数据库路径
    std::string dbPath =
            g_dbPath.empty() ? "/data/storage/el2/base/haps/entry/files/database/my_database.db"
                             : g_dbPath;
    LOGI("数据库Database path: %s", dbPath.c_str());

    // 确保数据库目录存在
    if (createDirectories(dbPath.c_str()) != 0) {
        LOGE("Failed to create database directory for path: %s", dbPath.c_str());
    }

    // 检查数据库文件是否存在
    struct stat st;
    if (stat(dbPath.c_str(), &st) == 0) {
        if (S_ISREG(st.st_mode)) {
            LOGI("Database file already exists and is a regular file");
        } else {
            LOGE("Database path exists but is not a regular file");
        }
    } else {
        LOGI("Database file does not exist yet");
    }

    // 创建 SQLite 驱动
    auto kt = libkn_symbols();
    if (kt == nullptr) {
        LOGE("Failed to load Kotlin symbols");
        // 返回空的驱动或者抛出异常
    }

    // 获取数据库 Schema
    auto schema = kt->kotlin.root.com.tencent.compose.db.MyDatabase.Companion.get_Schema(
            kt->kotlin.root.com.tencent.compose.db.MyDatabase.Companion._instance());
    LOGI("获取数据库Schema成功...");
    // 调用Kotlin中定义的createTestDriver函数
    auto driver = kt->kotlin.root.com.tencent.compose.sample.createTestDriver();
    LOGI("创建数据库驱动成功...");
    return driver;
}

// 添加设置数据库路径
void setDatabasePath(const char *path) {
    if (path != nullptr) {
        g_dbPath = std::string(path);
        LOGI("设置数据库路径成功: %s", path);

        // 确保路径目录存在
        createDirectories(path);
    } else {
        LOGI("尝试设置空的数据库路径");
    }
}

// 添加获取数据库路径
const char *getDatabasePath() {
    LOGI("获取数据库路径成功: %s", g_dbPath.c_str());
    return g_dbPath.c_str(); // 返回数据库路径
}
}
