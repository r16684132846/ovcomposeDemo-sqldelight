#include "libkn_api.h"
#include "napi/native_api.h"
#include <cstdlib>
#include <rawfile/raw_file_manager.h>
#include <string>
#include <hilog/log.h>

// 添加日志定义
#undef LOG_DOMAIN
#undef LOG_TAG
#define LOG_DOMAIN 0xD002D12
#define LOG_TAG "NATIVE_ENTRY"

#define LOGI(fmt, ...) ((void)OH_LOG_Print(LOG_APP, LOG_INFO, LOG_DOMAIN, LOG_TAG, fmt, ##__VA_ARGS__))
#define LOGE(fmt, ...) ((void)OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_DOMAIN, LOG_TAG, fmt, ##__VA_ARGS__))

// 声明Native层的函数
extern "C" void setDatabasePath(const char *path);
extern "C" const char *getDatabasePath();

static napi_value Add(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2] = {nullptr};

    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    napi_valuetype valuetype0;
    napi_typeof(env, args[0], &valuetype0);

    napi_valuetype valuetype1;
    napi_typeof(env, args[1], &valuetype1);

    double value0;
    napi_get_value_double(env, args[0], &value0);

    double value1;
    napi_get_value_double(env, args[1], &value1);

    napi_value sum;
    napi_create_double(env, value0 + value1, &sum);

    return sum;
}

// 实现NAPI绑定函数
static napi_value SetDatabasePath(napi_env env, napi_callback_info info) {
    LOGI("SetDatabasePath function called");
    
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    if (argc < 1) {
        LOGE("Wrong number of arguments");
        napi_throw_error(env, nullptr, "Wrong number of arguments");
        return nullptr;
    }

    // 检查参数是否为字符串
    napi_valuetype valueType;
    napi_typeof(env, args[0], &valueType);
    if (valueType != napi_string) {
        LOGE("Argument must be a string");
        napi_throw_error(env, nullptr, "Argument must be a string");
        return nullptr;
    }

    // 获取字符串参数
    size_t strLen;
    napi_status status = napi_get_value_string_utf8(env, args[0], nullptr, 0, &strLen);
    if (status != napi_ok) {
        LOGE("Failed to get string length");
        napi_throw_error(env, nullptr, "Failed to get string length");
        return nullptr;
    }

    char *buffer = (char *)malloc(strLen + 1);
    if (buffer == nullptr) {
        LOGE("Memory allocation failed");
        napi_throw_error(env, nullptr, "Memory allocation failed");
        return nullptr;
    }

    status = napi_get_value_string_utf8(env, args[0], buffer, strLen + 1, &strLen);
    if (status != napi_ok) {
        free(buffer);
        LOGE("Failed to get string value");
        napi_throw_error(env, nullptr, "Failed to get string value");
        return nullptr;
    }

    buffer[strLen] = '\0';
    LOGI("Received path: %{public}s", buffer);

    // 调用Native函数
    setDatabasePath(buffer);

    free(buffer);

    // 返回undefined
    napi_value result;
    napi_get_undefined(env, &result);
    return result;
}

// 实现获取数据库路径的NAPI绑定函数
static napi_value GetDatabasePath(napi_env env, napi_callback_info info) {
    LOGI("GetDatabasePath function called");
    
    // 调用Native函数获取路径
    const char *path = getDatabasePath();
    LOGI("Returning path: %{public}s", path);

    // 创建并返回JavaScript字符串
    napi_value result;
    napi_create_string_utf8(env, path, NAPI_AUTO_LENGTH, &result);
    return result;
}

static napi_value MainArkUIViewController(napi_env env, napi_callback_info info) {
    return reinterpret_cast<napi_value>(MainArkUIViewController(env));
}

static napi_value InitResourceManager(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    auto manager = OH_ResourceManager_InitNativeResourceManager(env, args[0]);
    auto kt = libkn_symbols();
    kt->kotlin.root.com.tencent.compose.initResourceManager(manager);

    napi_value result;
    napi_create_int32(env, 0, &result);
    return result;
}

static napi_value NAPI_Global_MainArkUIViewController(napi_env env, napi_callback_info info) { return nullptr; }

EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports) {
    LOGI("Initializing native module");
    
    androidx_compose_ui_arkui_init(env, exports);
    
    napi_property_descriptor desc[] = {
        {"add", nullptr, Add, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"initResourceManager", nullptr, InitResourceManager, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"MainArkUIViewController", nullptr, MainArkUIViewController, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"MainArkUIViewController", nullptr, NAPI_Global_MainArkUIViewController, nullptr, nullptr, nullptr,
         napi_default, nullptr},
        // 添加数据库路径相关函数的绑定
        {"setDatabasePath", nullptr, SetDatabasePath, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"getDatabasePath", nullptr, GetDatabasePath, nullptr, nullptr, nullptr, napi_default, nullptr},
    };
    
    napi_status status = napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    if (status != napi_ok) {
        LOGE("Failed to define properties");
    } else {
        LOGI("Properties defined successfully");
    }
    
    LOGI("Native module initialization completed");
    return exports;
}
EXTERN_C_END

static napi_module demoModule = {
    .nm_version = 1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = Init,
    .nm_modname = "libentry",
    .nm_priv = ((void *)0),
    .reserved = {0},
};

extern "C" __attribute__((constructor)) void RegisterEntryModule(void) { 
    LOGI("Registering entry module");
    napi_module_register(&demoModule); 
}
