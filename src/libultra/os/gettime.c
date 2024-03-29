#include <ultra64.h>

extern u32 __osBaseCounter;
extern OSTime __osCurrentTime;

OSTime osGetTime(void) {
    u32 count;
    u32 base;
    u64 t;
    register u32 prevInt = __osDisableInt();

    count = osGetCount();
    base = count - __osBaseCounter;
    t = __osCurrentTime;
    __osRestoreInt(prevInt);

    return base + t;
}
