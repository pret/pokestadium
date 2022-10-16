#include "PR/os_internal.h"

extern u32 __osGlobalIntMask;

void __osSetGlobalIntMask(OSHWIntr mask) {
    register u32 saveMask = __osDisableInt();

    __osGlobalIntMask |= mask;
    
    __osRestoreInt(saveMask);
}
