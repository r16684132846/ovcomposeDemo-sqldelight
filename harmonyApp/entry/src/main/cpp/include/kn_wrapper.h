#ifndef KN_WRAPPER_H
#define KN_WRAPPER_H

#include <napi/native_api.h>
#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
extern "C" {
#endif

// 异步观察 Promise 解析值并通过回调返回 napi_value（例如数组）
typedef void (*kn_jsvalue_callback)(napi_value value, void *user_data);

void kn_observe_promise_jsvalue(napi_env env, napi_value promise, kn_jsvalue_callback cb,
                                void *user_data);

// 返回 ArrayBuffer 的原始字节指针（uint8_t*）
uint8_t *kn_get_arraybuffer_value(napi_env env, napi_value value);

// 返回 ArrayBuffer 的实际长度（size_t）
size_t kn_get_arraybuffer_length(napi_env env, napi_value value);


// 将 Kotlin ByteArray 转换为 JavaScript ArrayBuffer
napi_value kn_create_arraybuffer_from_bytes(napi_env env, const uint8_t *data, size_t length);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
};
#endif

/** @} */
#endif