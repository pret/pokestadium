#ifndef _COMMON_H
#define _COMMON_H

#include <ultra64.h>

typedef unsigned int uintptr_t;

#include "macros.h"

#include "attributes.h"
#include "functions.h"
#include "variables.h"
#include "sections.h"
#include "gfx.h"
#include "color.h"

typedef struct unk_D_86002F58_004 {
    /* 0x000 */ char pad0[0xC];
    /* 0x00C */ s32 unk_00C;
    /* 0x010 */ s8 unk_010[0x10];
    /* 0x020 */ s16 unk_020;
    /* 0x024 */ f32 unk_024;
    /* 0x028 */ f32 unk_028;
    /* 0x02C */ f32 unk_02C;
    /* 0x030 */ f32 unk_030;
    /* 0x034 */ f32 unk_034;
    /* 0x038 */ f32 unk_038;
    /* 0x03C */ char pad3C[0xC];
    /* 0x048 */ s32 unk_048;
    /* 0x04C */ u32 unk_04C;
    /* 0x050 */ char pad50[0x56];
    /* 0x0A6 */ s8 unk_0A6;
    /* 0x0A7 */ char padA7[5];
    /* 0x0AC */ f32 unk_0AC;
    /* 0x0B0 */ f32 unk_0B0;
    /* 0x0B4 */ char padB4[0xB4];
    /* 0x168 */ s16 unk_168;
    /* 0x16A */ u16 unk_16A;
    /* 0x16C */ s16 unk_16C;
    /* 0x16E */ char pad16E[2];
} unk_D_86002F58_004; // size = 0x170

// possibly unk_D_86002F58_004
typedef struct unk_D_86002F34_00C {
    /* 0x00 */ char pad00[0x2C];
    /* 0x2C */ f32 unk_02C;
    /* 0x30 */ char pad30[0x4];
    /* 0x34 */ f32 unk_034;
    /* 0x38 */ f32 unk_038;
    /* 0x3C */ char pad3C[0x6C];
    /* 0xA8 */ f32 unk_0A8;
    /* 0xAC */ char padAC[0x8];
    /* 0xB4 */ f32 unk_0B4;
    /* 0xB8 */ f32 unk_0B8;
    /* 0xBC */ f32 unk_0BC;
} unk_D_86002F34_00C; // size >= 0xC0

typedef struct unk_D_86002F34 {
    /* 0x00 */ char pad00[0xC];
    /* 0x0C */ unk_D_86002F34_00C* unk_0C;
} unk_D_86002F34; // size >= 0x10



#endif
