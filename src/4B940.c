#include "4B940.h"

static OSMesgQueue D_800FF990;
static OSPiHandle* D_800FF9A8;
static OSMesg D_800FF9AC;

void func_8004AD40(s32 arg0) {
    switch (arg0) {
        case 1:
            D_800FF9A8 = osDriveRomInit();
            break;

        case 2:
        default:
            D_800FF9A8 = osCartRomInit();
            break;
    }

    osCreateMesgQueue(&D_800FF990, &D_800FF9AC, 1);
}

void func_8004ADB0(u32 dev_addr, u32 dram_addr, u32 size) {
    OSIoMesg msg;
    u32 dev = dev_addr;
    u32 dram = dram_addr;
    s32 var_s0;

    while (size != 0) {
        if (size > 0x4000) {
            var_s0 = 0x4000;
        } else {
            var_s0 = size;
        }

        msg.hdr.pri = 0;
        msg.hdr.retQueue = &D_800FF990;
        msg.dramAddr = dram;
        msg.devAddr = dev;
        msg.size = var_s0;

        osInvalDCache(msg.dramAddr, var_s0);
        osEPiStartDma(D_800FF9A8, &msg, 0);
        osRecvMesg(&D_800FF990, NULL, 1);

        dev += var_s0;
        dram += var_s0;
        size -= var_s0;
    }
}
