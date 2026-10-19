#ifndef _FRAGMENT25_H_
#define _FRAGMENT25_H_

#include "global.h"
#include "game_state.h"

typedef struct unk_D_88400100 {
#if defined(VERSION_JP)
    /* 0x00 */ char* unk_00; // Status name.
#else
    /* 0x00 */ s32 unk_00;
#endif
    /* 0x04 */ Color_RGBA8 unk_04;
} unk_D_88400100; // size = 0x8

typedef struct unk_D_88400138 {
#if defined(VERSION_JP)
    /* 0x00 */ char* unk_00; // Move type name.
#else
    /* 0x00 */ s32 unk_00;
#endif
    /* 0x04 */ Color_RGBA8 unk_04;
    /* 0x08 */ Color_RGBA8 unk_08;
} unk_D_88400138; // size = 0xC

typedef unk_D_88400100* (*func8840007C)(BattleMon*);
typedef unk_D_88400138* (*func884000C4)(s32);

unk_D_88400100* LabPC_GetMonStatusIcon(BattleMon*);
unk_D_88400138* LabPC_GetTypeColor(s32);

#endif // _FRAGMENT25_H_
