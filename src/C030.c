#include "global.h"
#include "controller.h"

extern s32 D_800697E0;
extern u8 D_800A82B0[32];

extern OSMesgQueue gSIEventMesgQueue;

s32 __osContRamWrite(OSMesgQueue* mq, int channel, u16 address, u8* buffer, int force);
s32 __osContRamRead(OSMesgQueue* mq, int channel, u16 address, u8* buffer);

extern s32 osPfsIsPlug(OSMesgQueue*, u8*);

extern u8 D_800A82CF;

// some kind of cycle count sleep function. just like the one in crash_screen.c
void func_8000B430(long ms) {
    unsigned long start = (osGetCount());
    unsigned long target = (s32)((ms * 1000LL) * 3000 / 64ULL + start);

    while (osGetCount() < target) {
        ;
    }
}

// Is this a Sticker Station?
s32 func_8000B4C4(void) {
    s32 i;
    s32 ret;
    u8 sp2F; // sp2F

    if (D_800697E0 == 0) {
        u8* buffer;
        osPfsIsPlug(&gSIEventMesgQueue, &sp2F);
        // is controller 4 plugged in? (why?)
        if (sp2F & 8) {
            Cont_BlockEepromQueue();
            for (buffer = D_800A82B0, i = 0; i < 32; i++) {
                buffer[i] = 0xFE;
            }
            if ((__osContRamWrite(&gSIEventMesgQueue, 3, 0x400, buffer, 0) == 2) &&
                (__osContRamWrite(&gSIEventMesgQueue, 3, 0x400, buffer, 0) != 0)) {
                Cont_NoBlockEepromQueue();
                return 0;
            }
            if ((__osContRamRead(&gSIEventMesgQueue, 3, 0x400, buffer) == 0) && (D_800A82CF == 0xFE)) {
                Cont_NoBlockEepromQueue();
                return 0;
            }
            for (buffer = D_800A82B0, i = 0; i < 32; i += 4) {
                buffer[i + 0] = 0x85;
                buffer[i + 1] = 0x85;
                buffer[i + 2] = 0x85;
                buffer[i + 3] = 0x85;
            }
            if ((__osContRamWrite(&gSIEventMesgQueue, 3, 0x400, buffer, 0) == 2) &&
                (__osContRamWrite(&gSIEventMesgQueue, 3, 0x400, buffer, 0) != 0)) {
                Cont_NoBlockEepromQueue();
                return 0;
            }
            if ((__osContRamRead(&gSIEventMesgQueue, 3, 0x400, buffer) == 0) && (D_800A82CF == 0x85)) {
                Cont_NoBlockEepromQueue();
                D_800697E0 = 1;
                return 1;
            }
            Cont_NoBlockEepromQueue();
        }
        return 0;
    }
    return 1;
}

u8 func_8000B6B4(void) {
    Cont_BlockEepromQueue();
    __osContRamRead(&gSIEventMesgQueue, 3, 0x600, D_800A82B0);
    Cont_NoBlockEepromQueue();
    return D_800A82CF;
}

void func_8000B6FC(u8 arg0) {
    u8* buffer = D_800A82B0;
    Cont_BlockEepromQueue();
    __osContRamRead(&gSIEventMesgQueue, 3, 0x600, buffer);
    if (D_800A82CF == 8) {
        do {
            func_8000B430(0x14);
            __osContRamRead(&gSIEventMesgQueue, 3, 0x600, buffer);
        } while (buffer[0x1F] == 8);
    }
    D_800A82CF = arg0;
    __osContRamWrite(&gSIEventMesgQueue, 3, 0x600, buffer, 1);
    Cont_NoBlockEepromQueue();
}
