#include "kn_wrapper.h"

#include <cstdint>
#include <future>
#include <napi/native_api.h>


// 观察 Promise 解析值（napi_value），用于数组等复杂类型
struct ObservePromiseJsValueCtx {
    kn_jsvalue_callback cb;
    void *user_data;
};

static napi_value kn_promise_on_fulfilled_async_value(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    void *data = nullptr;
    napi_get_cb_info(env, info, &argc, args, nullptr, &data);
    auto *ctx = reinterpret_cast<ObservePromiseJsValueCtx *>(data);

    if (ctx && ctx->cb) {
        // 将解析出的值（可能是数组）直接传递给回调
        ctx->cb(args[0], ctx->user_data);
    }
    delete ctx;

    napi_value undefined;
    napi_get_undefined(env, &undefined);
    return undefined;
}

static napi_value kn_promise_on_rejected_async_value(napi_env env, napi_callback_info info) {
    void *data = nullptr;
    napi_get_cb_info(env, info, nullptr, nullptr, nullptr, &data);
    auto *ctx = reinterpret_cast<ObservePromiseJsValueCtx *>(data);

    if (ctx && ctx->cb) {
        // 拒绝时传递空值，Kotlin 侧自行转为空列表
        ctx->cb(nullptr, ctx->user_data);
    }
    delete ctx;

    napi_value undefined;
    napi_get_undefined(env, &undefined);
    return undefined;
}

void kn_observe_promise_jsvalue(napi_env env, napi_value promise, kn_jsvalue_callback cb,
                                void *user_data) {
    bool isPromise = false;
    if (napi_is_promise(env, promise, &isPromise) == napi_ok && !isPromise) {
        // 非 Promise，直接回调传递该值
        if (cb) {
            cb(promise, user_data);
        }
        return;
    }

    auto *ctx = new ObservePromiseJsValueCtx{.cb = cb, .user_data = user_data};

    napi_value onFulfilledFn;
    napi_create_function(env, "onFulfilledValueAsync", NAPI_AUTO_LENGTH,
                         kn_promise_on_fulfilled_async_value, ctx,
                         &onFulfilledFn);

    napi_value onRejectedFn;
    napi_create_function(env, "onRejectedValueAsync", NAPI_AUTO_LENGTH,
                         kn_promise_on_rejected_async_value, ctx,
                         &onRejectedFn);

    napi_value thenFunc;
    napi_get_named_property(env, promise, "then", &thenFunc);

    napi_value argv[2] = {onFulfilledFn, onRejectedFn};
    napi_value out;
    napi_call_function(env, promise, thenFunc, 2, argv, &out);
}

extern "C" uint8_t *kn_get_arraybuffer_value(napi_env env, napi_value value) {
    void *data = nullptr;
    size_t length = 0;
    napi_status st = napi_get_arraybuffer_info(env, value, &data, &length);
    if (st != napi_ok) {
        return nullptr;
    }
    return static_cast<uint8_t *>(data);
}

extern "C" size_t kn_get_arraybuffer_length(napi_env env, napi_value value) {
    void *data = nullptr;
    size_t length = 0;
    napi_status st = napi_get_arraybuffer_info(env, value, &data, &length);
    if (st != napi_ok) {
        return 0;
    }
    return length;
}
