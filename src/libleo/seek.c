#include <ultra64.h>
#include "libleo/internal.h"

s32 LeoSeek(LEOCmd* cmdBlock, u32 lba, OSMesgQueue* mq) {
    if (!__leoActive) {
        return -1;
    }
    cmdBlock->header.command = LEO_COMMAND_SEEK;
    cmdBlock->header.reserve1 = 0;
    cmdBlock->header.control = 0;
    cmdBlock->header.reserve3 = 0;
    cmdBlock->data.readwrite.lba = lba;
    if (mq != NULL) {
        cmdBlock->header.control |= LEO_CONTROL_POST;
        cmdBlock->header.post = mq;
    }
    leoCommand(cmdBlock);
    return 0;
}
