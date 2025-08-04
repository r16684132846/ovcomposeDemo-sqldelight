
#include "container.h"
#include "test_0725.h"
#include "hilog/log.h"
#include "HiTraceSystraceSection.h"

#define LOG_TAG "MY_TAG"   // 全局tag宏，标识模块日志tag

int testNum(int num) {
    return num + 1;
}

void print_string(char* msg) {
    OH_LOG_INFO(LOG_APP, "KN: print_string: num=%{public}s", msg);
}

void print_const_string(const char* msg) {
    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "printString", "lww str:%{public}s", msg);
    HiTraceSystraceSection s("#Compose::printString::KeyToCPPFast");
}

static HiTraceSystraceSection* g_trace = nullptr;

void trace_tag_begin() {
//    HiTraceSystraceSection s("trace_tag_begin");
    if (!g_trace) {
        g_trace = new HiTraceSystraceSection("trace_tag_compose_block");
    }
}


void trace_tag_cnt(int num) {
    std::string tag = std::string("trace_tag_") + std::to_string(num);
    const char * tag_char = tag.c_str();
    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "trace_tag_cnt", "%{public}",tag_char);
    HiTraceSystraceSection s(tag_char);
}

void trace_tag_end() {
//    HiTraceSystraceSection s("trace_tag_end");
    delete g_trace;
    g_trace = nullptr;
}


    

static void* g_kotlin_obj = NULL;
static register_callback_holder g_callback = NULL;
static int counter = 0;

void native_register(void* kotlin_obj, register_callback_holder callback) {
    g_kotlin_obj = kotlin_obj;
    g_callback = callback;
}

void native_trigger() {
    if (g_callback && g_kotlin_obj) {
        counter = counter + 1;
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "native_register", "dzy C: Triggering Kotlin callback...");
        g_callback(counter, g_kotlin_obj);
    }
}


