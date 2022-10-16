#include <ultra64.h>
#include "PR/os_internal.h"

extern u32 __osGlobalIntMask;

void __osResetGlobalIntMask(OSHWIntr mask) {
    register u32 saveMask = __osDisableInt();

    __osGlobalIntMask &= ~(mask & ~OS_IM_RCP);

    __osRestoreInt(saveMask);
}
