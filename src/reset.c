#include <ultra64.h>
#include "reset.h"

// this file handles the soft reset effect.

struct UnkStruct800A62E0 {
    char filler0[0xA38];
    s16 unkA38;
};

struct UnkStruct800A6D20 {
    OSThread thread;
    char filler1B0[0x5E0 - 0x1B0];
    u32 unk5E0;
};

extern struct UnkStruct800A62E0 D_800A62E0;
extern struct UnkStruct800A6D20 D_800A6D20;

struct UnkStruct4 {
    s32 unk0;
    u16 unk4;
    u16 unk6;
    s32 unk8;
};

extern u32 gSoftResetLineNum;
extern s32 gSoftResetRed;
extern s32 gSoftResetGreen;
extern s32 gSoftResetBlue;

/**
 * Perform the horizontal framebuffer wipe across 15 different lines for a
 * screen with 320x240 resolution.
 */
void SoftReset_ClearLines320(u16* buf) {
    int i, j;

    if (gSoftResetLineNum <= 15) {
        // where is the framebuffer starting, based on the line number of the effect?
        u16* ptr = buf + gSoftResetLineNum * 320;

        // iterate over and clear the 15 lines of the next frame during the effect.
        for (j = 0; j < 15; j++) {
            for (i = 0; i < 320; i++) {
                *ptr++ = 1;
            }
            ptr += (320 * 15); // move the framebuffer pointer to the next line to clear
                               // (down 15 lines).
        }
        osWritebackDCacheAll();
    }
}

/**
 * Perform the horizontal framebuffer wipe across 15 different lines for a
 * screen with 640x480 resolution.
 */
void SoftReset_ClearLines640(u16* buf) {
    int i, j;

    if (gSoftResetLineNum <= 15) {
        // where is the framebuffer starting, based on the line number of the effect?
        u16* ptr = buf + gSoftResetLineNum * (640 * 2);

        // iterate over and clear the 15 lines of the next frame during the effect.
        for (j = 0; j < 15; j++) {
            for (i = 0; i < (640 * 2); i++) {
                *ptr++ = 1;
            }
            ptr += ((640 * 2) * 15); // move the framebuffer pointer to the next line to clear
                                     // (down 15 lines).
        }
        osWritebackDCacheAll();
    }
}

// not enough information to name this function. seems to get some unknown
// color from dp_intro.c and then only writes a single line to the framebuffer???
void func_8000559C(void) {
    if (gSoftResetLineNum <= 15) {
        if (gSoftResetLineNum == 0) {
            u16 color = func_80001B2C();
            // decoding a 5551 value back to the raw R/G/B values.
            gSoftResetRed = (color >> 11) & 31;  // masked red?
            gSoftResetGreen = (color >> 6) & 31; // masked green?
            gSoftResetBlue = (color >> 1) & 31;  // masked blue?
        }
        // this function is supposed to only take 1 argument. huh?
        // this function packs 3 values into a RGBA5551 format.
        func_80001AD4(((((u32)(gSoftResetRed * (15 - gSoftResetLineNum)) >> 4) << 11) |
                       (((u32)(gSoftResetGreen * (15 - gSoftResetLineNum)) >> 4) << 6) |
                       (((u32)(gSoftResetBlue * (15 - gSoftResetLineNum)) >> 4) << 1) | 1) &
                          0xFFFF,
                      gSoftResetLineNum);
    }
}

/**
 * Thread function for the soft reset function. This will run and stop until
 * it gets a soft reset, and then proceed to handle the soft reset framebuffer
 * effect.
 */
void SoftReset_Thread(void* unused) {
    __osSetFpcCsr(0x01000C01);
    func_80005328(&D_800A6D20.thread);

    // thread loop
    while (1) {
        func_80004CF4(&D_800A6D20.thread); // hangs here until gets a soft reset.
        if (D_800A62E0.unkA38 == 0) {
            continue;
        }
        if ((u32)D_800A6D20.unk5E0 < 0x10U) {
            struct UnkStruct4* temp_v0 = func_80001C58();
            if (temp_v0 != NULL) {
                if (temp_v0->unk4 == 320) {
                    SoftReset_ClearLines320(temp_v0->unk8);
                } else {
                    SoftReset_ClearLines640(temp_v0->unk8);
                }
            } else if (func_80001B40() != 0) {
                func_8000559C();
            } else {
                SoftReset_ClearLines320(osViGetCurrentFramebuffer());
            }
            D_800A6D20.unk5E0++;
            continue;
        }
        if (D_800A6D20.unk5E0 != 0x10) {
            continue;
        }
        osViBlack(1U);
        osViSetYScale(1.0f);
        D_800A6D20.unk5E0++;
    }
}

/**
 * Create the soft reset effect thread.
 */
void SoftReset_CreateThread(void) {
    func_80004CC0(&D_800A6D20.thread, 2, 1);
    D_800A6D20.unk5E0 = 0;
    osCreateThread(&D_800A6D20.thread, THREAD_ID_RESET, SoftReset_Thread, NULL, &gSoftResetLineNum, THREAD_PRI_RESET);
    osStartThread(&D_800A6D20.thread);
}
