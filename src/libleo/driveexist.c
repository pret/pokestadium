#include <ultra64.h>
#include "libleo/internal.h"

void __osPiRelAccess(void);
void __osPiGetAccess(void);

#define CONNECTED 0x2129FFF8
#define DDROM_ADDRESS_CHECK 0x06001010

// https://github.com/LuigiBlood/64dd/wiki/64DD-IPL
u32 LeoDriveExist(void) {
    register u32 ddromStatus;
    register s32 status;
    register u32 lastLatency;
    register u32 lastPageSize;
    register u32 lastRelDuration;
    register u32 lastPulse;

    __osPiGetAccess();

    while ((status = HW_REG(PI_STATUS_REG, u32)) & (PI_STATUS_DMA_BUSY | PI_STATUS_IO_BUSY)) {}

    lastLatency = HW_REG(PI_BSD_DOM1_LAT_REG, u32);
    lastPageSize = HW_REG(PI_BSD_DOM1_PGS_REG, u32);
    lastRelDuration = HW_REG(PI_BSD_DOM1_RLS_REG, u32);
    lastPulse = HW_REG(PI_BSD_DOM1_PWD_REG, u32);

    HW_REG(PI_BSD_DOM1_LAT_REG, u32) = 0xFF;
    HW_REG(PI_BSD_DOM1_PGS_REG, u32) = 0;
    HW_REG(PI_BSD_DOM1_RLS_REG, u32) = 3;
    HW_REG(PI_BSD_DOM1_PWD_REG, u32) = 0xFF;

    ddromStatus = HW_REG(DDROM_ADDRESS_CHECK, u32);

    HW_REG(PI_BSD_DOM1_LAT_REG, u32) = lastLatency;
    HW_REG(PI_BSD_DOM1_PGS_REG, u32) = lastPageSize;
    HW_REG(PI_BSD_DOM1_RLS_REG, u32) = lastRelDuration;
    HW_REG(PI_BSD_DOM1_PWD_REG, u32) = lastPulse;

    __osPiRelAccess();
    if (ddromStatus == CONNECTED) {
        return 1;
    }
    return 0;
}
