#ifndef GLOBAL_TEST_0725_H
#define GLOBAL_TEST_0725_H

#include <stdbool.h>
#ifdef __cplusplus
extern "C" {
#endif

int testNum(int num);
void print_string(char* msg);
void print_const_string(const char* msg);
void trace_tag_begin();
void trace_tag_end();
void trace_tag_cnt(int num);

typedef void (*register_callback_holder)(int, void*);
void native_register(void* kotlin_obj, register_callback_holder callback, bool holdRef);
void native_trigger(void);
void native_register_plain_holder(void* ptr, bool holdRef);

void native_register_simple_callback(const char* id, void* stable_ref, void (*callback)(void*));
void native_trigger_simple_callback(const char* id);
void native_cleanup_simple_callback(const char* id);
void native_cleanup_all_simple_callbacks();
int native_get_simple_callback_count();
void native_print_simple_callback_status();

#ifdef __cplusplus
};
#endif

/** @} */
#endif // GLOBAL_TEST_0725_H
