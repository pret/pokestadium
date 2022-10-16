#include "piint.h"

s32 osEPiRawWriteIo(OSPiHandle*, u32, u32);

s32 osEPiWriteIo(OSPiHandle* pihandle, u32 devAddr, u32 data) {
    register s32 ret;

    __osPiGetAccess();
    ret = osEPiRawWriteIo(pihandle, devAddr, data);
    __osPiRelAccess();

    return ret;
}
