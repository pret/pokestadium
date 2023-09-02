#include <ultra64.h>
#include "libleo/internal.h"

s32 LeoTestUnitReady(u8* status) {
    volatile LEOCmdTestUnitReady cmdBlock;

    if (!__leoActive) {
        return -1;
    }
    if (HW_REG(PI_STATUS_REG, u32) & 1) {
        return LEO_STATUS_BUSY;
    }
    cmdBlock.header.command = 3;
    cmdBlock.header.reserve1 = 0;
    cmdBlock.header.control = 0;
    cmdBlock.header.reserve3 = 0;
    leoCommand((void*)&cmdBlock);

    while (cmdBlock.header.status == LEO_STATUS_BUSY) {}

    *status = cmdBlock.test;
    return cmdBlock.header.sense;
}
