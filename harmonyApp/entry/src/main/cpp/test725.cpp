
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