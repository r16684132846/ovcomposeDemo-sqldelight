#ifndef GLOBAL_TEST_0725_H
#define GLOBAL_TEST_0725_H

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

void native_register(void* kotlin_obj, register_callback_holder callback);

void native_trigger();


#ifdef __cplusplus
};
#endif

/** @} */
#endif // GLOBAL_TEST_0725_H
