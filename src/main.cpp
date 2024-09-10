#include "thread"
#include "dobby.h"
#include "util.h"
#include <android/log.h>

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "muchen", __VA_ARGS__))


void* oldfunc{nullptr};


static bool new_input(void* t1)
{
    if (nullptr == oldfunc)
    {
        LOGI("failed to get original input");
    }
    LOGI("new_input");
    return true;
}

static void hook_input()
{
    void *sym_input = DobbySymbolResolver(util::getSoPath("libinputflinger.so").c_str(), "_ZNK7android15inputdispatcher15InputDispatcher20isTouchTrustedLockedERKNS1_18TouchOcclusionInfoE");
    LOGI("muchen");
    LOGI("路径:%s",util::getSoPath("libinputflinger.so").c_str());
    if (NULL != sym_input)
    {
        LOGI("_ZNK7android15inputdispatcher15InputDispatcher20isTouchTrustedLockedERKNS1_18TouchOcclusionInfoE:%llx", (unsigned long long)sym_input);
        int code = DobbyHook(sym_input, (void *)new_input, (void **)&oldfunc);
        LOGI("code: %d",code);
    }
}

__unused __attribute__((constructor)) void constructor_main()
{
    hook_input();
}