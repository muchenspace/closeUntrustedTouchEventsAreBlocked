#include "thread"
#include "dobby.h"
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
    void *sym_input = DobbySymbolResolver("system/lib/libinputflinger.so", "_ZNK7android15inputdispatcher15InputDispatcher20isTouchTrustedLockedERKNS1_18TouchOcclusionInfoE");
    if (NULL != sym_input)
    {
        LOGI("_ZNK7android15inputdispatcher15InputDispatcher20isTouchTrustedLockedERKNS1_18TouchOcclusionInfoE:%llx", (unsigned long long)sym_input);
        DobbyHook(sym_input, (void *)new_input, (void **)&oldfunc);
    }
}

__unused __attribute__((constructor)) void constructor_main()
{

    hook_input();
}