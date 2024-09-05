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

typedef struct unk_D_86002F58_004_000_00C_028 {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char pad6[6];
    /* 0x0C */ s32* unk_0C;
    /* 0x10 */ s32* unk_10;
} unk_D_86002F58_004_000_00C_028; // size >= 0x14

typedef unk_D_86002F58_004_000_00C_028* (*unk_D_86002F58_004_000_00C_028_func)(s32, s32);

typedef struct unk_D_86002F58_004_000_00C {
    /* 0x00 */ char unk_00[0x28];
    /* 0x28 */ unk_D_86002F58_004_000_00C_028_func unk_28;
} unk_D_86002F58_004_000_00C; // size >= 0x2C

typedef struct unk_D_86002F58_004_000_010 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ char unk_01[0x23];
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
} unk_D_86002F58_004_000_010; // size >= 0x2C

typedef struct unk_D_86002F58_004_000_004 {
    /* 0x00 */ struct unk_D_86002F58_004_000_004* unk_00;
    /* 0x04 */ unk_D_86002F58_004_000_00C* unk_04;
    /* 0x08 */ unk_D_86002F58_004_000_010* unk_08;
} unk_D_86002F58_004_000_004; // size >= 0x0C

typedef struct unk_D_86002F58_004_000_000 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ struct unk_D_86002F58_004_000_000* unk_04;
    /* 0x08 */ struct unk_D_86002F58_004_000_000* unk_08;
    /* 0x0C */ unk_D_86002F58_004_000_00C* unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
} unk_D_86002F58_004_000_000; // size = 0x18

typedef struct unk_D_86002F58_004_000_044 {
    /* 0x00 */ char unk00[0xA];
    /* 0x0A */ u16 unk_0A;
} unk_D_86002F58_004_000_044; // size >= 0xC

typedef struct unk_D_86002F58_004_000 {
    /* 0x000 */ unk_D_86002F58_004_000_000 unk_000;
    /* 0x018 */ s16 unk_018;
    /* 0x01A */ s16 unk_01A;
    /* 0x01C */ u8 unk_01C;
    /* 0x01D */ u8 unk_01D;
    /* 0x01E */ Vec3s unk_01E;
    /* 0x024 */ Vec3f unk_024;
    /* 0x030 */ Vec3f unk_030;
    /* 0x03C */ s32 unk_03C;
    /* 0x040 */ s16 unk_040;
    /* 0x044 */ unk_D_86002F58_004_000_044* unk_044;
    /* 0x048 */ s32 unk_048;
    /* 0x04C */ u32 unk_04C;
    /* 0x050 */ char pad050[2];
    /* 0x052 */ s16 unk_052;
    /* 0x054 */ s16 unk_054;
    /* 0x058 */ s32 unk_058;
    /* 0x05C */ s16 unk_05C;
    /* 0x05E */ s16 unk_05E;
    /* 0x060 */ s32 unk_060;
    /* 0x064 */ char pad064[0x3C];
    /* 0x0A0 */ s32 unk_0A0;
    /* 0x0A4 */ char pad0A4[2];
    /* 0x0A6 */ s8 unk_0A6;
    /* 0x0A7 */ char pad0A7[5];
    /* 0x0AC */ Vec3f unk_0AC;
    /* 0x0B8 */ char pad0B8[0x24];
    /* 0x0DC */ Vec3f unk_0DC;
    /* 0x0E0 */ char pad0E0[0x4];
    /* 0x0EC */ Vec3f unk_0EC;
    /* 0x0F8 */ char pad0F8[0x70];
} unk_D_86002F58_004_000; // size = 0x168

typedef struct unk_D_86002F34_00C {
    /* 0x00 */ char pad0[0x24];
    /* 0x24 */ MtxF* unk_024;
    /* 0x28 */ u16 unk_028;
    /* 0x2C */ f32 unk_02C;
    /* 0x30 */ char pad30[4];
    /* 0x34 */ f32 unk_034;
    /* 0x38 */ f32 unk_038;
    /* 0x3C */ char pad3C[0x24];
    /* 0x60 */ MtxF* unk_060;
    /* 0x64 */ Vec3f unk_064;
    /* 0x70 */ char pad70[0x38];
    /* 0xA8 */ Vec3f unk_0A8;
    /* 0xB4 */ Vec3f unk_0B4;
} unk_D_86002F34_00C; // size >= 0xC0

typedef struct unk_D_86002F34 {
    /* 0x00 */ char pad00[0xC];
    /* 0x0C */ unk_D_86002F34_00C* unk_0C;
} unk_D_86002F34; // size >= 0x10

// Are unk_D_86002F30 and unk_D_800AC840 the same?
typedef struct unk_D_86002F30 {
    /* 0x00 */ char unk00[0x8];
    /* 0x08 */ unk_D_86002F58_004_000_004* unk_08[4];
} unk_D_86002F30; // size = 0x18 ??

struct UnkInputStruct8000D738 {
    s32 unk0;
    s32 unk4;
};

struct UnkStruct800AA660 {
    /* 0x0000 */ OSThread thread;
    char padding1B0[0x2030];
    /* 0x21E0 */ OSMesg mesg;
    /* 0x21E4 */ OSMesgQueue queue;
    /* 0x21FC */ s32 unk21FC;
    /* 0x2200 */ s32 unk2200;
    /* 0x2204 */ struct UnkInputStruct8000D738 unk2204;
};

typedef struct unk_D_864027C0 {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ s16 unk_1C;
} unk_D_864027C0; // size = 0x20

#endif
