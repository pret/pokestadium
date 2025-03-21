#include "D470.h"
#include "PR/os_internal_flash.h"

static u32 D_800A82E0[4];      // __osFlashID
static OSIoMesg D_800A82F0;    // __osFlashMsg
static OSMesgQueue D_800A8308; // __osFlashMessageQ
static OSPiHandle D_800A8320;  // __osFlashHandler
static OSMesg D_800A8394[1];   // __osFlashMsgBuf
static s32 D_800A8398;         // __osFlashVersion

// osFlashReInit
OSPiHandle* func_8000C870(u8 latency, u8 pulse, u8 page_size, u8 rel_duration, u32 start) {
    D_800A8320.baseAddress = PHYS_TO_K1(start);
    D_800A8320.type++;
    D_800A8320.latency = latency;
    D_800A8320.pulse = pulse;
    D_800A8320.pageSize = page_size;
    D_800A8320.relDuration = rel_duration;
    D_800A8320.domain = PI_DOMAIN2;

    return &D_800A8320;
}

// osFlashInit
OSPiHandle* func_8000C8F8(void) {
    u32 flash_type;
    u32 flash_maker;

    osCreateMesgQueue(&D_800A8308, D_800A8394, ARRAY_COUNT(D_800A8394));
    if (D_800A8320.baseAddress == PHYS_TO_K1(FLASH_START_ADDR)) {
        return &D_800A8320;
    }

    D_800A8320.type = DEVICE_TYPE_FLASH;
    D_800A8320.baseAddress = PHYS_TO_K1(FLASH_START_ADDR);
    D_800A8320.latency = FLASH_LATENCY;
    D_800A8320.pulse = FLASH_PULSE;
    D_800A8320.pageSize = FLASH_PAGE_SIZE;
    D_800A8320.relDuration = FLASH_REL_DURATION;
    D_800A8320.domain = PI_DOMAIN2;
    D_800A8320.speed = 0;

    bzero(&D_800A8320.transferInfo, sizeof(__OSTranxInfo));

    osEPiLinkHandle(&D_800A8320);
    func_8000CB18(&flash_type, &flash_maker);

    if ((flash_maker == FLASH_VERSION_MX_C) || (flash_maker == FLASH_VERSION_MX_A) ||
        (flash_maker == FLASH_VERSION_MX_PROTO_A)) {
        D_800A8398 = 0x40;
    } else {
        D_800A8398 = 0x80;
    }

    return &D_800A8320;
}

// osFlashReadStatus
void func_8000CA4C(u8* flash_status) {
    u32 status;

    osEPiWriteIo(&D_800A8320, D_800A8320.baseAddress | FLASH_CMD_REG, FLASH_CMD_STATUS);
    osEPiReadIo(&D_800A8320, D_800A8320.baseAddress, &status);

    osEPiWriteIo(&D_800A8320, D_800A8320.baseAddress | FLASH_CMD_REG, FLASH_CMD_STATUS);
    osEPiReadIo(&D_800A8320, D_800A8320.baseAddress, &status);

    *flash_status = status & 0xFF;
    return;
}

// osFlashReadId
void func_8000CB18(u32* flash_type, u32* flash_maker) {
    u8 status;

    func_8000CA4C(&status);
    osEPiWriteIo(&D_800A8320, D_800A8320.baseAddress | FLASH_CMD_REG, FLASH_CMD_ID);

    D_800A82F0.hdr.pri = OS_MESG_PRI_NORMAL;
    D_800A82F0.hdr.retQueue = &D_800A8308;
    D_800A82F0.dramAddr = D_800A82E0;
    D_800A82F0.devAddr = 0;
    D_800A82F0.size = 2 * sizeof(u32);

    osWritebackDCache(&D_800A82E0, sizeof(__osFlashID));
    osEPiStartDma(&D_800A8320, &D_800A82F0, 0);
    osRecvMesg(&D_800A8308, NULL, 1);

    *flash_type = D_800A82E0[0];
    *flash_maker = D_800A82E0[1];
    return;
}

// osFlashClearStatus
void func_8000CC30(void) {
    osEPiWriteIo(&D_800A8320, D_800A8320.baseAddress | FLASH_CMD_REG, FLASH_CMD_STATUS);
    osEPiWriteIo(&D_800A8320, D_800A8320.baseAddress, 0);
    return;
}

// osFlashAllErase without the timer ?
s32 func_8000CC9C(void) {
    u32 status;

    osEPiWriteIo(&D_800A8320, D_800A8320.baseAddress | FLASH_CMD_REG, FLASH_CMD_CHIP_ERASE);
    osEPiWriteIo(&D_800A8320, D_800A8320.baseAddress | FLASH_CMD_REG, FLASH_CMD_EXECUTE_ERASE);

    do {
        osEPiReadIo(&D_800A8320, D_800A8320.baseAddress, &status);
    } while ((status & FLASH_STATUS_ERASE_BUSY) == FLASH_STATUS_ERASE_BUSY);

    osEPiReadIo(&D_800A8320, D_800A8320.baseAddress, &status);
    func_8000CC30();

    if (((status & 0xFF) == 8) || ((status & 0xFF) == 0x48) || ((status & 8) == 8)) {
        return FLASH_STATUS_ERASE_OK;
    } else {
        return FLASH_STATUS_ERASE_ERROR;
    }
}

// osFlashAllErase without the timer and an arg
s32 func_8000CDB8(s32 arg0) {
    u32 status;

    osEPiWriteIo(&D_800A8320, D_800A8320.baseAddress | FLASH_CMD_REG, arg0 | FLASH_CMD_SECTOR_ERASE);
    osEPiWriteIo(&D_800A8320, D_800A8320.baseAddress | FLASH_CMD_REG, FLASH_CMD_EXECUTE_ERASE);

    do {
        osEPiReadIo(&D_800A8320, D_800A8320.baseAddress, &status);
    } while ((status & FLASH_STATUS_ERASE_BUSY) == FLASH_STATUS_ERASE_BUSY);

    osEPiReadIo(&D_800A8320, D_800A8320.baseAddress, &status);
    func_8000CC30();

    if ((((status & 0xFF) == 8) || ((status & 0xFF) == 0x48)) || ((status & 8) == 8)) {
        return FLASH_STATUS_ERASE_OK;
    } else {
        return FLASH_STATUS_ERASE_ERROR;
    }
}

// osFlashWriteBuffer
s32 func_8000CEE4(OSIoMesg* mb, s32 priority, void* dramAddr, OSMesgQueue* mq) {
    s32 sp1C;

    osEPiWriteIo(&D_800A8320, D_800A8320.baseAddress | FLASH_CMD_REG, FLASH_CMD_PAGE_PROGRAM);

    mb->hdr.pri = priority;
    mb->hdr.retQueue = mq;
    mb->dramAddr = dramAddr;
    mb->devAddr = 0;
    mb->size = FLASH_BLOCK_SIZE;

    sp1C = osEPiStartDma(&D_800A8320, mb, OS_WRITE);
    return sp1C;
}

// Similar to osFlashAllErase without the timer, an arg, and different status bits
s32 func_8000CFB0(s32 arg0) {
    u32 status;

    osEPiWriteIo(&D_800A8320, D_800A8320.baseAddress | FLASH_CMD_REG, arg0 | FLASH_CMD_PROGRAM_PAGE);

    do {
        osEPiReadIo(&D_800A8320, D_800A8320.baseAddress, &status);
    } while ((status & 1) == 1);

    osEPiReadIo(&D_800A8320, D_800A8320.baseAddress, &status);
    func_8000CC30();

    if (((status & 0xFF) == 4) || ((status & 0xFF) == 0x44) || ((status & 4) == 4)) {
        return FLASH_STATUS_ERASE_OK;
    } else {
        return FLASH_STATUS_ERASE_ERROR;
    }
}

// osFlashReadArray but without handling pages individually
s32 func_8000D0B4(OSIoMesg* mb, s32 priority, s32 devAddr, void* dramAddr, s32 n_pages, OSMesgQueue* mq) {
    s32 sp1C;
    u32 sp18;

    osEPiWriteIo(&D_800A8320, D_800A8320.baseAddress | FLASH_CMD_REG, FLASH_CMD_READ_ARRAY);
    osEPiReadIo(&D_800A8320, D_800A8320.baseAddress, &sp18);

    mb->hdr.pri = priority;
    mb->hdr.retQueue = mq;
    mb->dramAddr = dramAddr;
    mb->devAddr = devAddr * D_800A8398;
    mb->size = n_pages * FLASH_BLOCK_SIZE;

    sp1C = osEPiStartDma(&D_800A8320, mb, OS_READ);
    return sp1C;
}
