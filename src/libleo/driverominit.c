#include <ultra64.h>
#include "libleo/internal.h"

void __osPiRelAccess(void);
void __osPiGetAccess(void);

OSPiHandle __DriveRomHandle;

OSPiHandle* osDriveRomInit(void) {
    register s32 status;
    register s32 saveMask;
    register u32 value;
    static s32 first = 1; // D_80079580
    u32 latency, pageSize, release, pulse;

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

    //Keep the previous PI settings as we go to into the safest settings to read the PI info from DDROM.
    latency = HW_REG(PI_BSD_DOM1_LAT_REG, u32);
    pageSize = HW_REG(PI_BSD_DOM1_PGS_REG, u32);
    release = HW_REG(PI_BSD_DOM1_RLS_REG, u32);
    pulse = HW_REG(PI_BSD_DOM1_PWD_REG, u32);

    //Set the safest PI settings
    HW_REG(PI_BSD_DOM1_LAT_REG, u32) = 0xff;
    HW_REG(PI_BSD_DOM1_PGS_REG, u32) = 0;
    HW_REG(PI_BSD_DOM1_RLS_REG, u32) = 3;
    HW_REG(PI_BSD_DOM1_PWD_REG, u32) = 0xff;

    //Read the PI settings from DDROM and put it in __DriveRomHandle
    value = HW_REG(__DriveRomHandle.baseAddress, u32);
    __DriveRomHandle.latency = value & 0xFF;
    __DriveRomHandle.pageSize = (value >> 0x10) & 0xF;
    __DriveRomHandle.relDuration = (value >> 0x14) & 0xF;
    __DriveRomHandle.pulse = (value >> 8) & 0xFF;

    //Put back the previous PI settings
    HW_REG(PI_BSD_DOM1_LAT_REG, u32) = latency;
    HW_REG(PI_BSD_DOM1_PGS_REG, u32) = pageSize;
    HW_REG(PI_BSD_DOM1_RLS_REG, u32) = release;
    HW_REG(PI_BSD_DOM1_PWD_REG, u32) = pulse;
    

    saveMask = __osDisableInt();
    __DriveRomHandle.next = __osPiTable;
    __osPiTable = &__DriveRomHandle;
    __osRestoreInt(saveMask);
    __osPiRelAccess();
    
    return &__DriveRomHandle;
}
