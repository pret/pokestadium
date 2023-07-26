#include <ultra64.h>
#include "libleo/internal.h"

void __osPiRelAccess(void);
void __osPiGetAccess(void);

extern OSPiHandle* __osCurrentHandle[];
extern OSPiHandle __DriveRomHandle;

#ifdef NON_MATCHING
// https://decomp.me/scratch/uNZ73
OSPiHandle* osDriveRomInit(void) {
 register s32 saveMask;
 register u32 value;
 register s32 status;
 static s32 first = 1; // D_80079580

  __osPiGetAccess();
  if (!first) {
    __osPiRelAccess();
      return &__DriveRomHandle;
  }
    first = 0;
    __DriveRomHandle.type = DEVICE_TYPE_BULK;
    __DriveRomHandle.baseAddress = PHYS_TO_K1(PI_DOM1_ADDR1);
    __DriveRomHandle.domain = PI_DOMAIN1;
    __DriveRomHandle.speed = 0;
    bzero(&__DriveRomHandle.transferInfo, sizeof(__OSTranxInfo));

     while (status = HW_REG(PI_STATUS_REG, u32), status & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    HW_REG(PI_BSD_DOM1_LAT_REG, u32) = 0xff;
    HW_REG(PI_BSD_DOM1_PGS_REG, u32) = 0;
    HW_REG(PI_BSD_DOM1_RLS_REG, u32) = 3;
    HW_REG(PI_BSD_DOM1_PWD_REG, u32) = 0xff;

    value = HW_REG(__DriveRomHandle.baseAddress, u32);
    __DriveRomHandle.latency = value & 0xFF;
    __DriveRomHandle.pulse = (value >> 8) & 0xFF;
    __DriveRomHandle.pageSize = (value >> 0x10) & 0xF;
    __DriveRomHandle.relDuration = (value >> 0x14) & 0xF;
    
    HW_REG(PI_BSD_DOM1_LAT_REG, u32) =  (u8)value;
    HW_REG(PI_BSD_DOM1_PGS_REG, u32) = __DriveRomHandle.pageSize;
    HW_REG(PI_BSD_DOM1_RLS_REG, u32) = __DriveRomHandle.relDuration;
    HW_REG(PI_BSD_DOM1_PWD_REG, u32) = __DriveRomHandle.pulse;

    saveMask = __osDisableInt();
    __DriveRomHandle.next = __osPiTable;
    __osPiTable = &__DriveRomHandle;
    __osRestoreInt(saveMask);
    __osPiRelAccess();
  return &__DriveRomHandle;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libleo/driverominit/osDriveRomInit.s")
#endif
