#include <ultra64.h>
#include "ultra64/internal.h"

extern __OSEventState __osEventStateTab[OS_NUM_EVENTS];

extern u32 __osPreNMI;
extern u32 __osShutdown;

void osSetEventMesg(OSEvent e, OSMesgQueue* mq, OSMesg msg) {
    register u32 prevInt = __osDisableInt();
    __OSEventState* msgs = &__osEventStateTab[e];

    msgs->queue = mq;
    msgs->msg = msg;

    if (e == OS_EVENT_PRENMI) {
        if (__osShutdown && !__osPreNMI) {
            osSendMesg(mq, msg, OS_MESG_NOBLOCK);
        }
        __osPreNMI = true;
    }
    __osRestoreInt(prevInt);
}
