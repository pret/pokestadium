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

#endif
