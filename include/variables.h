#ifndef _VARIABLES_H_
#define _VARIABLES_H_

#include "ultra64.h"

// thread pris
#define THREAD_PRI_IDLE_INIT 100
#define THREAD_PRI_RESET 30

// thread IDs
#define THREAD_ID_IDLE 1
#define THREAD_ID_RESET 21

#define POOL_END_4MB 0x80400000
#define POOL_END_6MB 0x80600000

/*
 * Dynamic heap with an indetermate amount of space. This pool can either end at 4MB or
 * 6MB depending on osMemSize, which is really strange as it should be using the whole
 * 8MB of the expansion pak.
 */
extern u8 gPool[1];

extern Gfx* gDisplayListHead;

extern u32 D_1000000;
extern u32 D_3000000;
extern u32 D_5000000;
extern u32 D_6000000;
extern u32 D_800AC840;
extern u32 D_8D000000;

typedef struct unk_D_80068BA0 {
    /* 0x00 */ char pad00[6];
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ u16 unk_08;
} unk_D_80068BA0; // size >= 0xC

extern unk_D_80068BA0* D_80068BA0[4];
extern Gfx D_8006F518[];
extern Gfx D_8006F630[];

typedef struct unk_D_800A7450 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ void* unk_0C;
} unk_D_800A7450; // size >= 0x10
extern unk_D_800A7450 D_800A7450;

extern Mtx D_800A7468;
extern s32 gShowCPUProfiler;
extern s32 gShowMEMProfiler;


typedef struct unk_func_80007444 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s8 unk_0C;
    /* 0x0D */ s8 unk_0D;
    /* 0x0E */ s8 unk_0E;
    /* 0x0F */ s8 unk_0F;
    /* 0x10 */ s8 unk_10;
    /* 0x11 */ u8 unk_11;
    /* 0x12 */ u8 unk_12;
    /* 0x13 */ u8 unk_13;
    /* 0x14 */ u16 unk_14;
    /* 0x16 */ s8 unk_16;
    /* 0x18 */ void* unk_18[3];
} unk_func_80007444; // size = 0x24
extern unk_func_80007444* D_800A7464;

extern Gfx* D_800A74B0;

typedef struct unk_D_800A7440 {
	/* 0x00 */ s16 x1;
	/* 0x02 */ s16 y1;
	/* 0x04 */ s16 x2;
	/* 0x06 */ s16 y2;
} unk_D_800A7440; // size >= 0x8
extern unk_D_800A7440 D_800A7440;

#endif
