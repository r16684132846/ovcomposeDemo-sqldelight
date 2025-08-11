
#include "container.h"
#include "test_0725.h"
#include "hilog/log.h"
#include "HiTraceSystraceSection.h"
#include <string>

#define LOG_TAG "MY_TAG"   // 全局tag宏，标识模块日志tag

int testNum(int num) {
    return num + 1;
}

void OH_LOG(const char *msg) {
    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "native_register", "dzy %{public}s",msg);
}

void print_string(char* msg) {
    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "xxx", "KN: print_string: num=%{public}s", msg);
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

void native_register(void* kotlin_obj, register_callback_holder callback, bool holdRef) {
    if (holdRef == true) {
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "native_register", "dzy C: register Kotlin callback...");
        g_kotlin_obj = kotlin_obj;
        g_callback = callback;
    }
}

void native_trigger() {
    if (g_callback && g_kotlin_obj) {
        counter = counter + 1;
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "native_register", "dzy C: Triggering Kotlin callback...");
        g_callback(counter, g_kotlin_obj);
    }
}
typedef struct {
    char id[64];
    void* stable_ref;
    void (*callback)(void*);
    bool is_active;
} SimpleCallbackEntry;

#define MAX_CALLBACKS 100
static SimpleCallbackEntry g_callbacks[MAX_CALLBACKS];
static int g_callback_count = 0;

static SimpleCallbackEntry* find_simple_callback_by_id(const char* id) {
    for (int i = 0; i < g_callback_count; i++) {
        if (g_callbacks[i].is_active && strcmp(g_callbacks[i].id, id) == 0) {
            return &g_callbacks[i];
        }
    }
    return nullptr;
}

void native_register_simple_callback(const char* id, void* stable_ref, void (*callback)(void*)) {
    if (g_callback_count < MAX_CALLBACKS) {
        SimpleCallbackEntry* entry = &g_callbacks[g_callback_count];
        strncpy(entry->id, id, sizeof(entry->id) - 1);
        entry->id[sizeof(entry->id) - 1] = '\0';
        entry->stable_ref = stable_ref;
        entry->callback = callback;
        entry->is_active = true;
        g_callback_count++;

        std::string msg1 = "[C] 注册简化回调: " + std::string(id) +
                           ", StableRef: " + std::to_string(reinterpret_cast<uintptr_t>(stable_ref));
        OH_LOG(msg1.c_str());

        std::string msg2 = "[C] 当前活跃回调数量: " + std::to_string(g_callback_count);
        OH_LOG(msg2.c_str());
    }
}

void native_trigger_simple_callback(const char* id) {
    SimpleCallbackEntry* entry = find_simple_callback_by_id(id);
    if (entry && entry->callback && entry->stable_ref) {
        std::string msg = "[C] 触发简化回调: " + std::string(id);
        OH_LOG(msg.c_str());

        entry->callback(entry->stable_ref);
    } else {
        std::string msg = "[C] 未找到回调: " + std::string(id);
        OH_LOG(msg.c_str());
    }
}

void native_cleanup_simple_callback(const char* id) {
    SimpleCallbackEntry* entry = find_simple_callback_by_id(id);
    if (entry) {
        std::string msg = "[C] 清理简化回调: " + std::string(id);
        OH_LOG(msg.c_str());

        entry->stable_ref = nullptr;
        entry->callback = nullptr;
        entry->is_active = false;
        memset(entry->id, 0, sizeof(entry->id));
    }
}

void native_cleanup_all_simple_callbacks() {

    std::string msg = "[C] 清理前有 " + std::to_string(g_callback_count) + " 个活跃回调";
    OH_LOG(msg.c_str());

    for (int i = 0; i < g_callback_count; i++) {
        SimpleCallbackEntry* entry = &g_callbacks[i];
        if (entry->is_active) {
            std::string clearMsg = "[C] 清理回调: " + std::string(entry->id);
            OH_LOG(clearMsg.c_str());
        }

        entry->stable_ref = nullptr;
        entry->callback = nullptr;
        entry->is_active = false;
        memset(entry->id, 0, sizeof(entry->id));
    }

    g_callback_count = 0;
}

int native_get_simple_callback_count() {
    int count = 0;
    for (int i = 0; i < g_callback_count; i++) {
        if (g_callbacks[i].is_active) {
            count++;
        }
    }
    return count;
}

void native_print_simple_callback_status() {

    std::string msg = "[C] 活跃回调数量: " + std::to_string(native_get_simple_callback_count());
    OH_LOG(msg.c_str());

    for (int i = 0; i < g_callback_count; i++) {
        if (g_callbacks[i].is_active) {
            std::string entryMsg = "[C] - ID: " + std::string(g_callbacks[i].id) +
                                   ", StableRef: " + std::to_string(reinterpret_cast<uintptr_t>(g_callbacks[i].stable_ref));
            OH_LOG(entryMsg.c_str());
        }
    }

}