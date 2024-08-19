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
#include "math.h"

typedef struct unk_D_86002F58_004_00C_028 {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char pad6[6];
    /* 0x0C */ s32* unk_0C;
    /* 0x10 */ s32* unk_10;
} unk_D_86002F58_004_00C_028; // size >= 0x14

typedef unk_D_86002F58_004_00C_028* (*unk_D_86002F58_004_00C_028_func)(s32, s32);

typedef struct unk_D_86002F58_004_00C {
    /* 0x00 */ char unk_00[0x28];
    /* 0x28 */ unk_D_86002F58_004_00C_028_func unk_28;
} unk_D_86002F58_004_00C; // size >= 0x2C

typedef struct unk_D_86002F58_004_010 {
	/* 0x00 */ u8 unk_00;
	/* 0x01 */ char unk_01[0x23];
	/* 0x24 */ s32 unk_24;
	/* 0x28 */ s32 unk_28;
} unk_D_86002F58_004_010; // size >= 0x2C

typedef struct unk_func_8001BCF0 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x04 */ unk_D_86002F58_004_00C* unk_04;
    /* 0x08 */ unk_D_86002F58_004_010* unk_08;
} unk_func_8001BCF0; // size >= 0x0C

typedef struct unk_D_86002F58_004 {
    /* 0x000 */ u8 unk_000;
    /* 0x001 */ u8 unk_001;
    /* 0x002 */ u8 unk_002;
    /* 0x004 */ unk_func_8001BCF0 unk_004;
    /* 0x010 */ char unk010[0x8];
    /* 0x018 */ s16 unk_018;
    /* 0x01A */ s16 unk_01A;
    /* 0x01C */ u8 unk_01C;
    /* 0x01D */ u8 unk_01D;
    /* 0x01E */ char unk01E[0x2];
    /* 0x020 */ s16 unk_020;
    /* 0x024 */ f32 unk_024;
    /* 0x028 */ f32 unk_028;
    /* 0x02C */ f32 unk_02C;
    /* 0x030 */ f32 unk_030;
    /* 0x034 */ f32 unk_034;
    /* 0x038 */ f32 unk_038;
    /* 0x03C */ s32 unk_03C;
    /* 0x040 */ s16 unk_040;
    /* 0x044 */ s32 unk_044;
    /* 0x048 */ s32 unk_048;
    /* 0x04C */ u32 unk_04C;
    /* 0x050 */ char pad50[4];
    /* 0x054 */ s16 unk_054;
    /* 0x058 */ s32 unk_058;
    /* 0x05C */ char pad5C[4];
    /* 0x060 */ s32 unk_060;
    /* 0x064 */ char pad64[0x3C];
    /* 0x0A0 */ s32 unk_0A0;
    /* 0x0A4 */ char padA4[2];
    /* 0x0A6 */ s8 unk_0A6;
    /* 0x0A7 */ char padA7[5];
    /* 0x0AC */ f32 unk_0AC;
    /* 0x0B0 */ f32 unk_0B0;
    /* 0x0B4 */ char padB4[0xB4];
} unk_D_86002F58_004; // size = 0x168

// possibly unk_D_86002F58_004
typedef struct unk_D_86002F34_00C {
    /* 0x00 */ char pad0[0x2C];
    /* 0x2C */ f32 unk_02C;
    /* 0x30 */ char pad30[4];
    /* 0x34 */ f32 unk_034;
    /* 0x38 */ f32 unk_038;
    /* 0x3C */ char pad3C[0x28];
    /* 0x64 */ Vec3f unk_064;
    /* 0x70 */ char pad70[0x38];
    /* 0xA8 */ f32 unk_0A8;
    /* 0xAC */ f32 unk_0AC;
    /* 0xB0 */ f32 unk_0B0;
    /* 0xB4 */ f32 unk_0B4;
    /* 0xB8 */ f32 unk_0B8;
    /* 0xBC */ f32 unk_0BC;
} unk_D_86002F34_00C; // size >= 0xC0

typedef struct unk_D_86002F34 {
    /* 0x00 */ char pad00[0xC];
    /* 0x0C */ unk_D_86002F34_00C* unk_0C;
} unk_D_86002F34; // size >= 0x10

typedef struct unk_D_86002F30 {
    /* 0x00 */ char unk_00[0x8];
    /* 0x08 */ unk_func_8001BCF0** unk_08;
} unk_D_86002F30; // size >= 0xC


#endif
