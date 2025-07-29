/*
 * Tencent is pleased to support the open source community by making ovCompose available.
 * Copyright (C) 2025 THL A29 Limited, a Tencent company. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "libkn_api.h"
#include "napi/native_api.h"
#include <rawfile/raw_file_manager.h>
#include <hilog/log.h>
#include "manager.h"

namespace NativeXComponentSample {

void callKotlinMethodTest() {
    OH_LOG_INFO(LOG_APP, "KN: callKotlinMethodTest: start");
    int num = kotlin_function(10);
    OH_LOG_INFO(LOG_APP, "KN: callKotlinMethodTest: end num=%{public}d", num);
}

void print_result(int x) {
    OH_LOG_INFO(LOG_APP, "KN: print_result: num=%{public}d", x);
}

void callKotlinCallbackTest() {
    kotlin_callback(21, (void *)print_result); // 输出: "Result: 42"
}

static napi_value Add(napi_env env, napi_callback_info info)
{
    size_t argc = 2;
    napi_value args[2] = {nullptr};

    napi_get_cb_info(env, info, &argc, args , nullptr, nullptr);

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

    callKotlinMethodTest();
    callKotlinCallbackTest();

    napi_value result;
    napi_create_int32(env, 0, &result);
    return result;
}

EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports) {
    androidx_compose_ui_arkui_init(env, exports);
    napi_property_descriptor desc[] = {
        {"add", nullptr, Add, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"initResourceManager", nullptr, InitResourceManager, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"MainArkUIViewController", nullptr, MainArkUIViewController, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"getContext", nullptr, Manager::GetContext, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"createNativeNode", nullptr, Manager::CreateNativeNode, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"updateNativeNode", nullptr, Manager::UpdateNativeNode, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"createNativeNodeStackView", nullptr, Manager::CreateNativeNodeStackView, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"createNativeNodeTextView", nullptr, Manager::CreateNativeNodeTextView, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"createNativeNodeImageView", nullptr, Manager::CreateNativeNodeImageView, nullptr, nullptr, nullptr, napi_default, nullptr},
    };
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
EXTERN_C_END

static napi_module demoModule = {
    .nm_version = 1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = Init,
    .nm_modname = "entry",
    .nm_priv = ((void*)0),
    .reserved = { 0 },
};

extern "C" __attribute__((constructor)) void RegisterEntryModule(void)
{
    napi_module_register(&demoModule);
}
}
