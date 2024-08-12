#include "global.h"
#include "libleo/internal.h"

s32 LeoReadRTC(LEOCmd* cmdBlock, OSMesgQueue* mq) {
    if (!__leoActive) {
        return -1;
    }
    cmdBlock->header.command = LEO_COMMAND_READ_TIMER;
    cmdBlock->header.reserve1 = 0;
    cmdBlock->header.control = 0;
    cmdBlock->header.reserve3 = 0;
    if (mq != NULL) {
        cmdBlock->header.control |= LEO_CONTROL_POST;
        cmdBlock->header.post = mq;
    }
    leoCommand(cmdBlock);
    return 0;
}
