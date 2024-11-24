#ifndef _FRAGMENT24_H_
#define _FRAGMENT24_H_

#include "global.h"
#include "src/fragments/25/fragment25.h"
#include "src/fragments/26/fragment26.h"
#include "src/fragments/29/fragment29.h"
#include "src/2E460.h"

typedef struct unk_func_8830867C_02C_04C_018 {
    /* 0x00 */ char unk00[0x8];
    /* 0x08 */ unk_func_88001300_000* unk_08;
    /* 0x0C */ unk_func_88001300_000* unk_0C;
    /* 0x10 */ unk_func_88001300_000* unk_10;
    /* 0x14 */ unk_func_88001300_000* unk_14;
    /* 0x18 */ unk_func_88001300_000* unk_18;
    /* 0x1C */ unk_func_88001300_000* unk_1C;
} unk_func_8830867C_02C_04C_018; // size >= 0x20

typedef struct unk_func_8830867C_02C_04C {
    /* 0x00 */ char unk00[0xC];
    /* 0x00 */ unk_func_88001300_03C_00C* unk_0C;
    /* 0x10 */ unk_func_88001300_03C_010 unk_10;
    /* 0x14 */ unk_func_88001300_03C_014 unk_14;
    /* 0x18 */ unk_func_8830867C_02C_04C_018* unk_18;
    /* 0x1C */ unk_func_88001300_03C_01C* unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ char unk30[0x8];
    /* 0x38 */ s16 unk_38;
    /* 0x3A */ s16 unk_3A;
    /* 0x3C */ s16 unk_3C;
    /* 0x3E */ s16 unk_3E;
} unk_func_8830867C_02C_04C; // size = 0x40

typedef struct unk_func_8830867C_02C_050 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ struct unk_func_8830867C_02C* unk_2C;
} unk_func_8830867C_02C_050; // size = 0x30

typedef struct unk_func_8830867C_02C_0B4_030 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ char unk2C[0xC];
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ char unk3C[0x18];
} unk_func_8830867C_02C_0B4_030; // size = 0x54

typedef struct unk_func_8830867C_02C_0B4 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_88001300_038* unk_2C;
    /* 0x30 */ unk_func_8830867C_02C_0B4_030* unk_30;
    /* 0x34 */ unk_func_88200FA0_030_038 unk_34;
} unk_func_8830867C_02C_0B4; // size = 0x40

typedef struct unk_func_8830867C_02C_0C0 {
    /* 0x00 */ unk_func_882173EC unk_00;
    /* 0x38 */ s32 unk_38;
} unk_func_8830867C_02C_0C0; // size = 0x3C

typedef struct unk_func_8830867C_034_03C_038_02C_000 {
    /* 0x00 */ char unk00[0x8];
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ char unk0C[0x10];
} unk_func_8830867C_034_03C_038_02C_000; // size = 0x1C

typedef struct unk_func_8830867C_034_03C_038_02C {
    /* 0x00 */ unk_func_8830867C_034_03C_038_02C_000* unk_00;
    /* 0x04 */ char unk04[0x4];
    /* 0x08 */ s32 unk_08;
} unk_func_8830867C_034_03C_038_02C; // size >= 0xC

// Seems to be >= 0x58 in other places?
typedef struct unk_func_8830867C_02C_144_000 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ char unk08[0x4];
    /* 0x0C */ unk_func_8830867C_02C_0CC_000_000* unk_0C;
    /* 0x10 */ char unk10[0x4];
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ char unk18[0x8];
} unk_func_8830867C_02C_144_000; // size = 0x20

typedef struct unk_func_8830867C_02C_144_000_alt {
    /* 0x00 */ char unk00[0x2C];
    /* 0x2C */ unk_func_8830867C_034_03C_038_02C unk_2C;
    /* 0x38 */ char unk_38[0x14];
    /* 0x4C */ unk_func_8830867C_034_03C_038_02C unk_4C;
} unk_func_8830867C_02C_144_000_alt; // size >= 0x58

typedef struct unk_func_8830867C_02C_144 {
    /* 0x00 */ unk_func_8830867C_02C_144_000* unk_00;
    /* 0x04 */ char unk04[0x4];
    /* 0x08 */ s32 unk_08;
} unk_func_8830867C_02C_144; // size >= 0xC

typedef struct unk_func_8830867C_02C_154 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ u8* unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ char unk18[0x4];
} unk_func_8830867C_02C_154; // size = 0x1C

typedef struct unk_func_8830867C_02C_1A8 {
    /* 0x00 */ u8* unk_00;
    /* 0x04 */ unk_func_8830867C_02C_154* unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
} unk_func_8830867C_02C_1A8; // size = 0x10

typedef struct unk_func_8830867C_030_03C_034 {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ char unk04[0x2];
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ char unk08[0x2];
    /* 0x0A */ u16 unk_0A;
} unk_func_8830867C_030_03C_034; // size >= 0xC

typedef struct unk_func_8830867C_030 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_88001300_038* unk_2C;
    /* 0x30 */ unk_func_88001300_000_010 unk_30;
    /* 0x34 */ unk_func_88001300_000_010 unk_34;
    /* 0x38 */ unk_func_885012A4* unk_38;
    /* 0x3C */ unk_func_88200FA0_030_030_1CEA00* unk_3C;
    /* 0x40 */ unk_func_8830867C_02C_0CC unk_40;
    /* 0x4C */ s32 unk_4C;
    /* 0x50 */ s32 unk_50;
} unk_func_8830867C_030; // size = 0x54

typedef struct unk_func_8830867C_034_034 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ char unk2C[0x4];
    /* 0x30 */ s32 unk_30;
} unk_func_8830867C_034_034; // size = 0x34

typedef struct unk_func_8830867C_034_03C_038 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_8830867C_034_03C_038_02C* unk_2C;
    /* 0x30 */ char unk30[0x4];
    /* 0x34 */ u16* unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ char unk3C[0x8];
    /* 0x44 */ unk_func_88001300_000* unk_44;
    /* 0x48 */ char unk48[0xC];
} unk_func_8830867C_034_03C_038; // size = 0x54

typedef struct unk_func_8830867C_034_03C {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_88001300_038* unk_2C;
    /* 0x30 */ unk_func_88500994* unk_30;
    /* 0x34 */ unk_func_88500994* unk_34;
    /* 0x38 */ unk_func_8830867C_034_03C_038* unk_38[2];
    /* 0x40 */ char unk40[0x4];
} unk_func_8830867C_034_03C; // size = 0x44

typedef struct unk_func_8830867C_034 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_88001300_038* unk_2C;
    /* 0x30 */ unk_func_88200FA0_030_030_1CEA00* unk_30;
    /* 0x34 */ unk_func_8830867C_034_034* unk_34;
    /* 0x38 */ unk_func_8830867C_034_038* unk_38;
    /* 0x3C */ unk_func_8830867C_034_03C* unk_3C;
    /* 0x40 */ unk_func_8850878C* unk_40;
} unk_func_8830867C_034; // size = 0x44

typedef struct unk_func_8830867C_038_034 {
    /* 0x00 */ char** unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
} unk_func_8830867C_038_034; // size = 0xC

typedef struct unk_func_8830867C_038 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_88001300_038* unk_2C;
    /* 0x30 */ unk_func_88200FA0_030_030_1CEA00* unk_30;
    /* 0x34 */ unk_func_8830867C_038_034 unk_34;
    /* 0x40 */ unk_func_88001300_038* unk_40;
} unk_func_8830867C_038; // size = 0x44

typedef struct unk_func_8830867C_03C_030 {
    /* 0x00 */ unk_func_8850878C* unk_00;
    /* 0x00 */ s32 unk_04;
} unk_func_8830867C_03C_030; // size = 0x8

typedef struct unk_func_8830867C_03C {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_88001300_038* unk_2C;
    /* 0x30 */ unk_func_8830867C_03C_030 unk_30[2];
    /* 0x40 */ unk_func_8850878C* unk_40;
    /* 0x44 */ unk_func_8850878C* unk_44;
    /* 0x48 */ unk_func_88001300_000* unk_48;
    /* 0x4C */ unk_func_8830867C_03C_04C* unk_4C;
    /* 0x50 */ unk_func_88001300_03C* unk_50;
    /* 0x54 */ unk_func_8821421C_038_034* unk_54;
    /* 0x58 */ unk_func_8830867C_03C_058 unk_58[15];
    /* 0xD0 */ unk_func_8830867C_03C_0D0 unk_D0;
    /* 0xE0 */ u16 unk_E0;
} unk_func_8830867C_03C; // size = 0xE4

typedef struct unk_func_8830867C_040_030 {
    /* 0x00 */ unk_func_8850878C* unk_00;
    /* 0x04 */ u8* unk_04;
} unk_func_8830867C_040_030; // size = 0x8

typedef struct unk_func_8830867C_040 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_88001300_038* unk_2C;
    /* 0x30 */ unk_func_8830867C_040_030 unk_30[4];
    /* 0x50 */ unk_func_8850878C* unk_50;
    /* 0x54 */ unk_func_8850878C* unk_54;
    /* 0x58 */ unk_func_88001300_000* unk_58;
    /* 0x5C */ unk_func_8830867C_040_05C* unk_5C;
    /* 0x60 */ unk_func_88001300_03C* unk_60;
    /* 0x64 */ unk_func_8821421C_038_034* unk_64;
    /* 0x68 */ unk_func_88205880_A030 unk_68;
    /* 0x74 */ u16 unk_74;
} unk_func_8830867C_040; // size = 0x78

typedef struct unk_func_8830867C_044_038 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ char unk2C[0x4];
    /* 0x30 */ unk_func_8830867C_044_038_030 unk_30;
    /* 0x44 */ unk_func_8820E99C_030_044* unk_44;
} unk_func_8830867C_044_038; // size = 0x48

typedef struct unk_func_8830867C_044 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_88001300_038* unk_2C;
    /* 0x30 */ unk_func_8850878C* unk_30;
    /* 0x34 */ unk_func_88001300_000* unk_34;
    /* 0x38 */ unk_func_8830867C_044_038* unk_38;
    /* 0x3C */ unk_func_8830867C_044_038* unk_3C;
    /* 0x40 */ unk_func_8830867C_044_040* unk_40;
    /* 0x44 */ unk_func_88001300_03C* unk_44;
} unk_func_8830867C_044; // size = 0x48

typedef struct unk_func_8830867C_048_04C {
    /* 0x00 */ char unk00[0x1C];
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ char unk20[0x4];
} unk_func_8830867C_048_04C; // size = 0x24

typedef struct unk_func_8830867C_048 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_88001300_038* unk_2C;
    /* 0x30 */ unk_func_88001300_038* unk_30;
    /* 0x34 */ unk_func_88200FA0_030_030_1CEA00* unk_34;
    /* 0x38 */ unk_func_88200FA0_030_030_1CEA00* unk_38[2];
    /* 0x40 */ unk_func_88500994* unk_40;
    /* 0x44 */ unk_func_88500994* unk_44;
    /* 0x48 */ unk_func_8830867C_048_048* unk_48;
    /* 0x4C */ unk_func_8830867C_048_04C* unk_4C;
    /* 0x50 */ char unk_50[0x80];
} unk_func_8830867C_048; // size = 0xD0

typedef struct unk_func_8830867C_04C_030_02C_000_000 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ char unk02[0x6];
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ unk_func_8830867C_04C_030_02C_000_000_00C unk_0C;
} unk_func_8830867C_04C_030_02C_000_000; // size >= 0x18

typedef struct unk_func_8830867C_04C_030_02C_000 {
    /* 0x00 */ unk_func_8830867C_04C_030_02C_000_000* unk_00[1];
} unk_func_8830867C_04C_030_02C_000; // size >= 0x8

typedef struct unk_func_8830867C_04C_030_02C {
    /* 0x00 */ unk_func_8830867C_04C_030_02C_000* unk_00;
    /* 0x04 */ char unk04[0x4];
    /* 0x08 */ s32 unk_08;
} unk_func_8830867C_04C_030_02C; // size >= 0xC

typedef struct unk_func_8830867C_04C_030 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_8830867C_04C_030_02C* unk_2C;
    /* 0x30 */ char unk30[0x4];
    /* 0x34 */ u16* unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ char unk3C[0x2];
    /* 0x3E */ s16 unk_3E;
    /* 0x40 */ char unk40[0x18];
    /* 0x58 */ s32 unk_58;
    /* 0x5C */ char unk5C[0x14];
} unk_func_8830867C_04C_030; // size = 0x70

typedef void (*unk_func_8830867C_04C_078_030_040)();

typedef struct unk_func_8830867C_04C_078_030 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ void* unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ u16* unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s16 unk_3C;
    /* 0x3E */ s16 unk_3E;
    /* 0x40 */ unk_func_8830867C_04C_078_030_040 unk_40;
    /* 0x44 */ unk_func_88001300_03C_01C* unk_44;
    /* 0x48 */ s16 unk_48;
    /* 0x4A */ s16 unk_4A;
    /* 0x4C */ s16 unk_4C;
    /* 0x4E */ s16 unk_4E;
    /* 0x50 */ s16 unk_50;
    /* 0x52 */ s16 unk_52;
} unk_func_8830867C_04C_078_030; // size = 0x54

typedef struct unk_func_8830867C_04C_078_044 {
    /* 0x00 */ unk_func_88201DA0_034* unk_00;
    /* 0x04 */ s32 unk_04;
} unk_func_8830867C_04C_078_044; // size = 0x8

typedef struct unk_func_8830867C_04C_078 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_88001300_038* unk_2C;
    /* 0x30 */ unk_func_8830867C_04C_078_030* unk_30;
    /* 0x34 */ unk_func_88201DA0_038 unk_34;
    /* 0x44 */ unk_func_8830867C_04C_078_044 unk_44[1];
    /* 0x4C */ char unk4C[0x18];
} unk_func_8830867C_04C_078; // size = 0x64

typedef struct unk_func_8830867C_04C_02C {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
} unk_func_8830867C_04C_02C; // size = 0x34

typedef struct unk_func_8830867C_04C {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_8830867C_04C_02C* unk_2C;
    /* 0x30 */ unk_func_8830867C_04C_030* unk_30;
    /* 0x34 */ unk_func_88500994* unk_34;
    /* 0x38 */ char unk_38[4];
    /* 0x3C */ char unk3C[0x3C];
    /* 0x78 */ unk_func_8830867C_04C_078* unk_78;
    /* 0x7C */ unk_func_8830867C_030* unk_7C;
    /* 0x80 */ unk_func_8830867C_04C_080* unk_80;
    /* 0x84 */ s32 unk_84;
    /* 0x88 */ unk_func_80026268_arg0* unk_88; // maybe unk_func_8830867C_02C_0CC_000_008
    /* 0x8C */ s32 unk_8C;
    /* 0x90 */ unk_func_88503298* unk_90;
} unk_func_8830867C_04C; // size = 0x94

typedef struct unk_func_8830867C_02C_C54_014 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ u8 unk_04[2];
} unk_func_8830867C_02C_C54_014; // size >= 0x8

typedef struct unk_func_8830867C_02C_C54_01C {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ u8 unk_04[2];
} unk_func_8830867C_02C_C54_01C; // size >= 0x8

typedef struct unk_func_8830867C_02C_C54_024 {
    /* 0x00 */ u8 unk_00[4];
    /* 0x04 */ s32 unk_04;
} unk_func_8830867C_02C_C54_024; // size >= 0x8

typedef struct unk_func_8830867C_02C_C54 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ u8 unk_09;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ unk_func_8830867C_02C_C54_014 unk_14;
    /* 0x1C */ unk_func_8830867C_02C_C54_01C unk_1C;
    /* 0x24 */ unk_func_8830867C_02C_C54_024 unk_24;
    /* 0x2C */ u8 unk_2C;
} unk_func_8830867C_02C_C54; // size = 0x30

typedef struct unk_func_8830867C_054 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ MemoryPool* unk_04;
    /* 0x08 */ unk_func_88001300_000* unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
} unk_func_8830867C_054; // size >= 0x14

typedef struct unk_func_8830867C_02C_0E4 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ unk_func_8820BE14_06C unk_0C;
    /* 0x1C */ s32 unk_1C;
} unk_func_8830867C_02C_0E4; // size = 0x20

typedef struct unk_func_8830867C_02C_0DC {
    /* 0x00 */ s32* unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ char unk0C[0xC];
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ char unk1C[0xC];
    /* 0x28 */ s32 unk_28;
} unk_func_8830867C_02C_0DC; // size >= 0x2C

typedef struct unk_func_8830867C_02C {
    /* 0x000 */ unk_func_88001300_000 unk_000;
    /* 0x02C */ unk_func_88001300_038* unk_02C;
    /* 0x030 */ unk_func_8850B254* unk_030;
    /* 0x034 */ unk_func_8830867C_02C_034* unk_034;
    /* 0x038 */ unk_func_88500994* unk_038;
    /* 0x03C */ unk_func_88200FA0_030_038 unk_03C;
    /* 0x048 */ unk_func_8830867C_02C_048* unk_048;
    /* 0x04C */ unk_func_8830867C_02C_04C* unk_04C;
    /* 0x050 */ unk_func_8830867C_02C_050* unk_050;
    /* 0x054 */ unk_func_88001300_000* unk_054;
    /* 0x058 */ unk_func_88001300_000* unk_058;
    /* 0x05C */ unk_func_88001300_000* unk_05C;
    /* 0x060 */ unk_func_88001300_000* unk_060;
    /* 0x064 */ unk_func_88001300_000* unk_064;
    /* 0x068 */ unk_func_88001300_000* unk_068;
    /* 0x06C */ unk_func_88001300_000* unk_06C;
    /* 0x070 */ unk_func_88001300_000* unk_070;
    /* 0x074 */ unk_func_88001300_000* unk_074;
    /* 0x078 */ unk_func_88001300_000* unk_078;
    /* 0x07C */ unk_func_88001300_000* unk_07C;
    /* 0x080 */ unk_func_88001300_000* unk_080;
    /* 0x084 */ unk_func_88001300_000* unk_084;
    /* 0x088 */ unk_func_88001300_000* unk_088;
    /* 0x08C */ unk_func_8830867C_030* unk_08C;
    /* 0x090 */ unk_func_88509F48* unk_090;
    /* 0x094 */ unk_func_8830867C_034* unk_094;
    /* 0x098 */ unk_func_8830867C_038* unk_098;
    /* 0x09C */ unk_func_8830867C_03C* unk_09C;
    /* 0x0A0 */ unk_func_8830867C_040* unk_0A0;
    /* 0x0A4 */ unk_func_8830867C_044* unk_0A4;
    /* 0x0A8 */ unk_func_8830867C_048* unk_0A8;
    /* 0x0AC */ unk_func_8830867C_04C* unk_0AC;
    /* 0x0B0 */ unk_func_889000C4* unk_0B0;
    /* 0x0B4 */ unk_func_8830867C_02C_0B4* unk_0B4;
    /* 0x0B8 */ unk_func_8850CD44* unk_0B8;
    /* 0x0BC */ unk_func_882173EC* unk_0BC;
    /* 0x0C0 */ unk_func_8830867C_02C_0C0* unk_0C0;
    /* 0x0C4 */ unk_func_882173EC* unk_0C4;
    /* 0x0C8 */ unk_func_882173EC* unk_0C8;
    /* 0x0CC */ unk_func_88200FA0_030_038 unk_0CC;
    /* 0x0D8 */ s32 unk_0D8;
    /* 0x0DC */ unk_func_8830867C_02C_0DC* unk_0DC;
    /* 0x0E0 */ s32 unk_0E0;
    /* 0x0E4 */ unk_func_8830867C_02C_0E4 unk_0E4[3];
    /* 0x144 */ unk_func_8830867C_02C_144 unk_144;
    /* 0x150 */ char unk150[0x4];
    /* 0x154 */ unk_func_8830867C_02C_154 unk_154[3];
    /* 0x1A8 */ unk_func_8830867C_02C_1A8 unk_1A8[3];
    /* 0x1D8 */ char unk1D8[0xA70];
    /* 0xC48 */ unk_func_88200FA0_030_038 unk_C48;
    /* 0xC54 */ unk_func_8830867C_02C_C54 unk_C54;
    /* 0xC84 */ unk_func_8830867C_02C_C54 unk_C84;
    /* 0xCB4 */ s32 unk_CB4;
    /* 0xCB8 */ s32 unk_CB8;
    /* 0xCBC */ s32 unk_CBC;
    /* 0xCC0 */ s32 unk_CC0;
    /* 0xCC4 */ s32 unk_CC4;
    /* 0xCC8 */ s32 unk_CC8;
    /* 0xCCC */ unk_func_8850878C* unk_CCC;
    /* 0xCD0 */ s32 unk_CD0;
    /* 0xCD4 */ s32* unk_CD4;
    /* 0xCD8 */ FragmentEntry unk_CD8;
    /* 0xCDC */ unk_func_8830867C_054* unk_CDC;
} unk_func_8830867C_02C; // size = 0xCE0

typedef struct unk_func_8830867C {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_8830867C_02C* unk_2C;
    /* 0x30 */ unk_func_8830867C_030* unk_30;
    /* 0x34 */ unk_func_8830867C_034* unk_34;
    /* 0x38 */ unk_func_8830867C_038* unk_38;
    /* 0x3C */ unk_func_8830867C_03C* unk_3C;
    /* 0x40 */ unk_func_8830867C_040* unk_40;
    /* 0x44 */ unk_func_8830867C_044* unk_44;
    /* 0x48 */ unk_func_8830867C_048* unk_48;
    /* 0x4C */ unk_func_8830867C_04C* unk_4C;
    /* 0x50 */ unk_func_889000C4* unk_50;
    /* 0x54 */ unk_func_8830867C_054 unk_54;
    /* 0x68 */ unk_func_88001300_000* unk_68;
    /* 0x6C */ s32 unk_6C;
    /* 0x70 */ char** unk_70;
    /* 0x74 */ char** unk_74;
    /* 0x78 */ char** unk_78;
    /* 0x7C */ char** unk_7C;
    /* 0x80 */ char** unk_80;
    /* 0x84 */ char** unk_84;
    /* 0x88 */ char** unk_88;
} unk_func_8830867C; // size = 0x8C

typedef struct unk_func_88302D98 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_8830867C_02C* unk_2C;
} unk_func_88302D98; // size = 0x30

typedef struct unk_func_88304850_arg2 {
    /* 0x00 */ s32* unk_00;
    /* 0x04 */ char unk04[4];
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ char unk09[0xD];
    /* 0x16 */ s16 unk_16;
    /* 0x18 */ char unk18[0x14];
    /* 0x2C */ u8 unk_2C;
    /* 0x2E */ s16 unk_2E;
    /* 0x30 */ s16 unk_30;
    /* 0x32 */ s16 unk_32;
    /* 0x34 */ s16 unk_34;
    /* 0x36 */ s16 unk_36;
    /* 0x38 */ char unk_38[4];
    /* 0x3C */ char unk3C[0x4];
    /* 0x40 */ char unk_40[3];
    /* 0x43 */ char unk_43[1];
} unk_func_88304850_arg2; // size >= 0x44

typedef struct unk_func_88309C38_arg2_004 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Color_RGBA8 unk_04;
} unk_func_88309C38_arg2_004; // size >= 0x8

typedef struct unk_func_88309C38_arg2_00C {
    /* 0x00 */ char unk00[0x14];
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
} unk_func_88309C38_arg2_00C; // size >= 0x1C

typedef struct unk_func_88309C38_arg2 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x04 */ unk_func_88309C38_arg2_004* unk_04;
    /* 0x08 */ char unk08[0x4];
    /* 0x0C */ unk_func_88309C38_arg2_00C* unk_0C;
    /* 0x10 */ char unk10[0x4];
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
} unk_func_88309C38_arg2; // size >= 0x1C

typedef struct unk_func_88309160_arg2 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ char unk08[0x4];
    /* 0x0C */ unk_func_88309C38_arg2_00C* unk_0C;
    /* 0x10 */ char unk10[0x4];
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
} unk_func_88309160_arg2; // size >= 0x1C

typedef struct unk_func_88310CA4_arg2 {
    /* 0x00 */ u8* unk_00;
    /* 0x04 */ u8* unk_04;
    /* 0x08 */ char unk08[0x4];
    /* 0x0C */ unk_func_88309C38_arg2_00C* unk_0C;
    /* 0x10 */ char unk10[0x4];
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
} unk_func_88310CA4_arg2; // size >= 0x1C

typedef struct unk_func_88310B70 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_8830867C_04C_030* unk_2C;
    /* 0x30 */ unk_func_8850878C* unk_30;
} unk_func_88310B70; // size = 0x34

typedef struct unk_func_88313894_020 {
    /* 0x00 */ char unk00[0xC];
    /* 0x0C */ unk_func_8830867C_02C_0CC_000_000* unk_0C;
    /* 0x10 */ char unk10[0x4];
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ char unk18[0x4];
    /* 0x1C */ s32 unk_1C;
} unk_func_88313894_020; // size = 0x20

typedef struct unk_func_88316128 {
    /* 0x00 */ char unk00[0x8];
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ char unk09[0xD];
    /* 0x16 */ u16 unk_16;
    /* 0x18 */ char unk18[0x14];
    /* 0x2C */ u8 unk_2C;
    /* 0x2E */ u16 unk_2E;
    /* 0x30 */ u16 unk_30;
    /* 0x32 */ u16 unk_32;
    /* 0x34 */ u16 unk_34;
    /* 0x36 */ u16 unk_36;
    /* 0x38 */ u8 unk_38;
    /* 0x39 */ char unk39[0xA];
    /* 0x43 */ u8 unk_43;
} unk_func_88316128; // size >= 0x44

extern char** D_8831A4C0;
extern char** D_8831A4C4;
extern char** D_8831A4C8;
extern char** D_8831A4CC;
extern char** D_8831A4D0;
extern char** D_8831A4D4;
extern char** D_8831A4D8;
extern Color_RGBA8 D_8831727C;
extern Color_RGBA8 D_88317280;
extern Color_RGBA8 D_88317284;
extern u32 D_883176D8[];
extern u32 D_88317920[];
extern u32 D_88317F28[];
extern u32 D_88318530[];
extern u32 D_883186E8[];
extern u32 D_88318898[];
extern u32 D_883198A0[];
extern unk_D_8831A1F8 D_8831A1F8[];

void func_88300020(unk_func_88001300_000* arg0, s32 arg1, s32 arg2);
s32 func_88300090(unk_func_88001300_000* arg0, s32 arg1, s32 arg2);
void func_883003E4(unk_func_88001300_000* arg0, s32 arg1, s32 arg2);
s32 func_88300454(unk_func_88001300_000* arg0, s32 arg1, s32 arg2);
void func_88300640(unk_func_88001300_000* arg0, s32 arg1, s32 arg2);
s32 func_883006B0(unk_func_88001300_000* arg0, s32 arg1, s32 arg2);
void func_8830089C(unk_func_88001300_000* arg0, s32 arg1, s32 arg2);
s32 func_8830090C(unk_func_88001300_000* arg0, s32 arg1, s32 arg2);
void func_88300AF8(unk_func_88001300_000* arg0, s32 arg1, s32 arg2);
s32 func_88300B68(unk_func_88001300_000* arg0, s32 arg1, s32 arg2);
void func_88300D54(unk_func_88001300_000* arg0, s32 arg1, s32 arg2);
s32 func_88300DC4(unk_func_88001300_000* arg0, s32 arg1, s32 arg2);
void func_88300FB0(unk_func_88001300_000* arg0, s32 arg1, s32 arg2);
s32 func_88301020(unk_func_88001300_000* arg0, s32 arg1, s32 arg2);
void func_8830133C(unk_func_88001300_000* arg0, s32 arg1, s32 arg2);
s32 func_883013AC(unk_func_88001300_000* arg0, s32 arg1, s32 arg2);
void func_883018D8(unk_func_88001300_000* arg0, s32 arg1, s32 arg2);
s32 func_88301948(unk_func_88001300_000* arg0, s32 arg1, s32 arg2);
void func_88301B34(unk_func_88001300_000* arg0, s32 arg1, s32 arg2);
s32 func_88301BA4(unk_func_88001300_000* arg0, s32 arg1, s32 arg2);
void func_88301D90(unk_func_88001300_000* arg0, s32 arg1, s32 arg2);
s32 func_88301E00(unk_func_88001300_000* arg0, s32 arg1, s32 arg2);
void func_88301FB8(unk_func_88001300_000* arg0, s32 arg1, s32 arg2);
s32 func_88302028(unk_func_88001300_000* arg0, s32 arg1, s32 arg2);
void func_88302214(unk_func_88001300_000* arg0, s32 arg1, s32 arg2);
s32 func_88302284(unk_func_88001300_000* arg0, s32 arg1, s32 arg2);
void func_88302470(unk_func_88001300_000* arg0, s32 arg1, s32 arg2);
s32 func_883024E0(unk_func_88001300_000* arg0, s32 arg1, s32 arg2);
s32 func_88302748(unk_func_8830867C_02C_050* arg0, s32 arg1, s32 arg2);
void func_8830290C(unk_func_88001300_000* arg0, s32 arg1, s32 arg2);
s32 func_88302968(unk_func_88001300_000* arg0, s32 arg1, s32 arg2);
void func_88302BB4(unk_func_8830867C_02C* arg0, MemoryPool* arg1);
void func_88302C18(unk_func_8830867C_02C* arg0);
void func_88302C7C(unk_func_8830867C_02C* arg0, MemoryPool* arg1);
void func_88302D98(unk_func_88302D98* arg0, s32 arg1, s32 arg2, unk_func_8830867C_02C* arg3);
s32 func_88302E04(unk_func_88302D98* arg0, s32 arg1, s32 arg2);
void func_88303520(unk_func_8830867C_02C* arg0);
void func_88304350(s32 arg0, s32 arg1, s32 arg2, u8* arg3, s32 arg4);
void func_88304490(s32 arg0, s32 arg1, s32 arg2, u8* arg3, s32 arg4);
void func_883045C0(s32 arg0, s32 arg1, s32 arg2, unk_func_88304850_arg2* arg3);
void func_88304608(s32 arg0, s32 arg1, s8* arg2, s32 arg3);
void func_88304680(s32 arg0, s32 arg1, char* arg2, s32 arg3);
void func_88304718(s32 arg0, s32 arg1, char* arg2, s32 arg3, u8* arg4);
s32 func_883047CC(unk_func_8830867C_02C* arg0, unk_func_88304850_arg2* arg1);
void func_88304850(s32 arg0, s32 arg1, unk_func_88304850_arg2* arg2, s32 arg3, s32 arg4,
                   unk_func_8830867C_02C_034* arg5);
void func_883050CC(unk_func_8830867C_02C* arg0);
void func_88305168(unk_func_8830867C_02C* arg0);
void func_883051B0(unk_func_8830867C_02C* arg0);
void func_883051F8(unk_func_8830867C_02C* arg0);
s32 func_88305220(unk_func_8830867C_02C* arg0, s32 arg1);
void func_88305230(unk_func_8830867C_02C* arg0, s32 arg1);
void func_88305240(unk_func_8830867C_02C* arg0, s32 arg1);
s32 func_88305254(unk_func_8830867C_02C* arg0, s32 arg1);
void func_88305268(unk_func_8830867C_02C* arg0, s32 arg1);
void func_88305270(unk_func_8830867C_02C* arg0);
s32 func_88305458(unk_func_8830867C_02C* arg0);
s32 func_883054DC(unk_func_8830867C_02C_0CC* arg0, unk_func_8830867C_02C_0CC_000* arg1);
void func_88305520(unk_func_8830867C_02C* arg0, unk_func_8830867C_02C_0CC_000* arg1, Controller* arg2);
void func_883057F4(unk_func_8830867C_02C_0CC_000_000* arg0);
void func_88305830(unk_func_8830867C_02C* arg0, unk_func_8830867C_02C_0CC_000* arg1, s32 arg2, s32 arg3);
void func_88305C7C(unk_func_8830867C_02C_0CC_000_008* arg0, s32 arg1);
void func_88305CDC(unk_func_8830867C_02C_0CC_000* arg0, unk_func_8830867C_04C_030_02C_000* arg1, s32 arg2);
void func_88305D7C(unk_func_8830867C_02C* arg0, s32 arg1);
s32 func_88305DA8(unk_func_8830867C_02C* arg0, Controller* arg1);
void func_88305DF4(unk_func_8830867C_02C* arg0, Controller* arg1);
void func_88305F28(unk_func_8830867C_02C* arg0);
s32 func_88306544(unk_func_8830867C_02C* arg0, Controller* arg1);
s32 func_8830681C(unk_func_8830867C_02C* arg0, Controller* arg1);
s32 func_88306C70(unk_func_8830867C_02C* arg0, unk_func_88001300_000* arg1, s32 arg2, Controller* arg3);
u32 func_88306F90(unk_func_8830867C_02C* arg0);
void func_88306FE4(void);
void func_88306FEC(unk_func_8830867C_02C_048* arg0, unk_func_8830867C_02C* arg1);
void func_88307038(unk_func_8830867C_02C* arg0, s32 arg1);
void func_88307110(unk_func_8830867C_02C* arg0);
s32 func_88307250(unk_func_8830867C_02C* arg0);
s32 func_88307264(unk_func_8830867C_02C* arg0, Controller* arg1, s32 arg2);
void func_883073E8(unk_func_8830867C_02C* arg0, s32 arg1);
void func_88307478(unk_func_8830867C_02C_048* arg0);
void func_883074D4(unk_func_8830867C_02C_048* arg0, Controller* arg1);
s32 func_8830757C(unk_func_8830867C_02C_048* arg0, Controller* arg1);
s32 func_88307628(unk_func_8830867C_02C_048* arg0, Controller* arg1);
s32 func_8830772C(unk_func_8830867C_02C_048* arg0, Controller* arg1, s32 arg2);
s32 func_88307C2C(unk_func_8830867C_02C_048* arg0, Controller* arg1, s32 arg2);
s32 func_8830858C(unk_func_8830867C_02C_048* arg0, Controller* arg1);
void func_88308D60(unk_func_8830867C* arg0);
void func_88308DFC(unk_func_8830867C* arg0);
s32 func_88308E84(UNUSED s32 arg0, UNUSED s32 arg1);

void func_883092C8(unk_func_8830867C_04C_078* arg0, s32 arg1, s32 arg2, MemoryPool* arg3);
void func_883094CC(unk_func_8830867C_04C_078* arg0, unk_func_80026268_arg0* arg1);
void func_88309614(unk_func_8830867C_04C_078* arg0);
void func_883096BC(unk_func_8830867C_04C_078* arg0);
s32 func_88309728(unk_func_8830867C_04C_078* arg0, Controller* arg1);
void func_88309774(unk_func_8830867C_04C_078* arg0);
void func_883097D4(unk_func_8830867C_04C_078* arg0);
void func_883097E4(void);
s32 func_883097EC(unk_func_8830867C_034_03C_038_02C_000* arg0);
void func_88309808(void);
void func_88309810(unk_func_8830867C_034_03C* arg0);
void func_883098D0(unk_func_8830867C_034_03C* arg0, s32 arg1);
void func_88309960(unk_func_8830867C_034_03C* arg0);
void func_883099D8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_88309DC8(void);
void func_88309E28(unk_func_8830867C_034_03C* arg0, s32 arg1, s32 arg2, s32 arg3, MemoryPool* arg4);
s32 func_8830A474(unk_func_8830867C_034_03C* arg0, Controller* arg1);
void func_8830A520(unk_func_8830867C_034_03C* arg0, s32 arg1);
void func_8830A578(unk_func_8830867C_034_034* arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_8830A5E4(unk_func_8830867C_034_034* arg0, s32 arg1, s32 arg2);
s32 func_8830A840(unk_func_8830867C_02C_144_000* arg0);
void func_8830A88C(unk_func_8830867C_034* arg0, unk_func_8830867C_034_03C* arg1);
void func_8830A928(unk_func_8830867C_034* arg0);
void func_8830A9D8(unk_func_8830867C_034* arg0);
void func_8830AAA4(unk_func_8830867C_034* arg0, s32 arg1);
s32 func_8830AC0C(void);
void func_8830ACA0(unk_func_8830867C_034* arg0, s32 arg1, s32 arg2, unk_func_88001300_000* arg3, MemoryPool* arg4);
void func_8830B2EC(unk_func_8830867C_034* arg0, unk_func_8830867C_02C_144* arg1);
void func_8830B354(unk_func_8830867C_034* arg0, s32 arg1);
s32 func_8830B380(unk_func_8830867C_034* arg0, Controller* arg1);
void func_8830B404(unk_func_8830867C_034_038* arg0, unk_func_8830867C_034* arg1);
s32 func_8830B450(unk_func_8830867C_034_038* arg0, Controller* arg1);
void func_8830B8A0(unk_func_8830867C_034* arg0);
void func_8830B938(unk_func_8830867C_034* arg0);
s32 func_8830B954(unk_func_8830867C_034* arg0, Controller* arg1);
void func_8830BA1C(s32 arg0, s32 arg1, char* arg2, s32 arg3, s32 arg4);
void func_8830BAC4(unk_func_8830867C_030* arg0, unk_func_88001300_000* arg1, MemoryPool* arg2);
void func_8830BCE8(unk_func_8830867C_030* arg0, char** arg1, s32 arg2);
void func_8830BE3C(unk_func_8830867C_030* arg0);
void func_8830BF30(unk_func_8830867C_030* arg0, s32 arg1);
s32 func_8830BF5C(unk_func_8830867C_030* arg0, Controller* arg1);
void func_8830BFE0(unk_func_8830867C_030* arg0, s32 arg1);
void func_8830C048(unk_func_8830867C_030* arg0);
u32 func_8830C058(unk_func_8830867C_030* arg0, Controller* arg1, s32 arg2);
void func_8830C150(s32 arg0, s32 arg1, char* arg2, s32 arg3, s32 arg4);
void func_8830C218(unk_func_8830867C_038* arg0, s32 arg1, s32 arg2, unk_func_88001300_000* arg3, MemoryPool* arg4);
void func_8830CD4C(unk_func_8830867C_038* arg0, s32 arg1);
s32 func_8830CE00(unk_func_8830867C_038* arg0, Controller* arg1);
s32 func_8830CE84(unk_func_8830867C_038* arg0, Controller* arg1);
void func_8830CF88(unk_func_8830867C_044_038* arg0);
void func_8830CFBC(unk_func_8830867C_044_038* arg0, s32 arg1, s32 arg2, MemoryPool* arg3);
void func_8830D0B4(unk_func_8830867C_044_038* arg0, s32 arg1);
s32 func_8830D11C(unk_func_8830867C_044_038* arg0, s32 arg1, s32 arg2);
s32 func_8830D268(unk_func_8830867C_044_038* arg0, Controller* arg1);
void func_8830D2F8(unk_func_8830867C_044* arg0, s32 arg1, s32 arg2, unk_func_88001300_000* arg3, MemoryPool* arg4);
void func_8830DAB8(unk_func_8830867C_044* arg0, s32 arg1, s32 arg2, s32 arg3);
void func_8830DBE0(unk_func_8830867C_044* arg0, s32 arg1);
s32 func_8830DC0C(unk_func_8830867C_044* arg0, Controller* arg1);
s32 func_8830DC58(unk_func_8830867C_044* arg0, Controller* arg1);
void func_8830DD8C(unk_func_8830867C_044_040* arg0, unk_func_8830867C_044* arg1);
s32 func_8830DDD8(unk_func_8830867C_044_040* arg0, Controller* arg1);
void func_8830E4A4(unk_func_8830867C_03C* arg0, unk_func_8850878C* arg1, char* arg2);
void func_8830E504(unk_func_8830867C_03C* arg0, s32 arg1, s32 arg2, unk_func_88001300_000* arg3, MemoryPool* arg4);
void func_8830EE58(unk_func_8830867C_03C* arg0, unk_func_8830867C_02C_C54_01C* arg1);
void func_8830F05C(unk_func_8830867C_03C* arg0, unk_func_8830867C_02C_C54_01C* arg1);
void func_8830F09C(unk_func_8830867C_03C* arg0, s32 arg1);
s32 func_8830F0C8(unk_func_8830867C_03C* arg0, Controller* arg1);
s32 func_8830F114(unk_func_8830867C_03C* arg0, Controller* arg1);
void func_8830F254(unk_func_8830867C_03C_04C* arg0, unk_func_8830867C_03C* arg1);
s32 func_8830F2A0(unk_func_8830867C_03C_04C* arg0, Controller* arg1);
void func_8830FA10(void);
void func_8830FA18(void);
void func_8830FA20(unk_func_8830867C_040* arg0, unk_func_8850878C* arg1, char* arg2);
void func_8830FA80(unk_func_8830867C_040* arg0, s32 arg1, s32 arg2, unk_func_88001300_000* arg3, MemoryPool* arg4);
void func_883103CC(unk_func_8830867C_040* arg0, unk_func_8830867C_02C_C54_024* arg1);
void func_883105D4(unk_func_8830867C_040* arg0, unk_func_8830867C_02C_C54_024* arg1);
void func_88310650(unk_func_8830867C_040* arg0, s32 arg1);
s32 func_8831067C(unk_func_8830867C_040* arg0, Controller* arg1);
s32 func_883106C8(unk_func_8830867C_040* arg0, Controller* arg1);
void func_88310808(unk_func_8830867C_040_05C* arg0, unk_func_8830867C_040* arg1);
s32 func_88310854(unk_func_8830867C_040_05C* arg0, Controller* arg1);
void func_88310B70(unk_func_88310B70* arg0, s32 arg1, s32 arg2, unk_func_8830867C_04C_030* arg3, MemoryPool* arg4);
s32 func_88310C38(unk_func_88310B70* arg0);
void func_883112B0(unk_func_8830867C_04C* arg0, s32 arg1, s32 arg2, unk_func_88001300_000* arg3, MemoryPool* arg4);
s32 func_88311C64(s32 arg0, s32 arg1);
s32 func_88311D6C(s32 arg0, unk_func_8830867C_02C_0CC_000_008* arg1);
s32 func_88311E28(unk_func_8830867C_02C_0CC_000_008* arg0);
s32 func_88311EB4(s32 arg0, unk_func_8830867C_02C_0CC_000_008* arg1);
void func_88311F70(unk_func_8830867C_04C* arg0, unk_func_88200FA0_030_038* arg1);
void func_88312018(unk_func_8830867C_04C* arg0, unk_func_80026268_arg0* arg1);
void func_88312020(unk_func_8830867C_04C* arg0);
void func_88312108(unk_func_8830867C_04C* arg0);
void func_88312188(unk_func_8830867C_04C* arg0, s32 arg1);
void func_883121F0(unk_func_8830867C_04C* arg0, s32 arg1);
s32 func_8831221C(unk_func_8830867C_04C* arg0, s32* arg1);
void func_88312298(unk_func_8830867C_04C_080* arg0, unk_func_8830867C_04C* arg1);
s32 func_883122E4(unk_func_8830867C_04C_080* arg0);
s32 func_8831239C(unk_func_8830867C_04C_080* arg0);
void func_8831247C(unk_func_8830867C_04C_080* arg0);
s32 func_883125B4(unk_func_8830867C_04C_080* arg0, Controller* arg1);
s32 func_8831286C(unk_func_8830867C_04C* arg0, Controller* arg1);
void func_883128B8(unk_func_8830867C_04C* arg0);
void func_883128FC(unk_func_8830867C_04C* arg0);
s32 func_88312998(unk_func_8830867C_04C* arg0, Controller* arg1);
void func_88312B10(s32 arg0, s32 arg1, unk_func_88309160_arg2* arg2, s32 arg3, s32 arg4, unk_func_88200FA0_030_030_1CEA00* arg5);
void func_88312C7C(s32 arg0, s32 arg1, unk_func_88309160_arg2* arg2, s32 arg3, s32 arg4, unk_func_88200FA0_030_030_1CEA00* arg5);
void func_88312D7C(unk_func_8830867C_048* arg0, s32 arg1, s32 arg2, unk_func_88001300_000* arg3, MemoryPool* arg4);
void func_88313740(unk_func_8830867C_048* arg0, unk_func_8830867C_02C_144* arg1);
void func_883137C4(unk_func_88200FA0_030_030_1CEA00* arg0, unk_func_8830867C_02C_0CC_000* arg1, unk_func_88313894_020* arg2);
void func_88313894(unk_func_8830867C_048* arg0, unk_func_8830867C_02C_0CC_000* arg1);
void func_88313950(char* arg0, s32 arg1, s32 arg2);
void func_883139E8(unk_func_8830867C_048* arg0, s32 arg1, s32 arg2);
void func_88313A34(unk_func_8830867C_048* arg0);
void func_88313A94(unk_func_8830867C_048* arg0);
void func_88313B4C(unk_func_8830867C_048* arg0);
void func_88313B64(unk_func_8830867C_048* arg0, s32 arg1);
s32 func_88313B90(unk_func_8830867C_048* arg0, Controller* arg1);
void func_88313C24(unk_func_8830867C_048_048* arg0, unk_func_8830867C_048* arg1);
s32 func_88313C70(unk_func_8830867C_048_048* arg0, Controller* arg1);
s32 func_88313E50(unk_func_8830867C_048* arg0, Controller* arg1);
void func_88313F24(s32 arg0, s32 arg1, s8* arg2, s32 arg3);
void func_88313FA0(unk_func_8830867C_02C_0B4* arg0, s32 arg1, s32 arg2, MemoryPool* arg3);
s32 func_883142F4(unk_func_8830867C_02C_0B4* arg0, Controller* arg1);
s32 func_88314340(unk_func_8830867C_02C_0B4* arg0, Controller* arg1);
void func_88314484(unk_func_882173EC* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_88314518(unk_func_882173EC* arg0);
s32 func_88314574(unk_func_882173EC* arg0, s32 arg1, s32 arg2);
void func_88314920(unk_func_882173EC* arg0, s32 arg1, s32 arg2, unk_func_88001300_000_010 arg3);
void func_88314950(unk_func_8830867C_02C_0C0* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_883149E4(unk_func_8830867C_02C_0C0* arg0);
s32 func_88314A38(unk_func_8830867C_02C_0C0* arg0, s32 arg1, s32 arg2);
void func_883151B8(unk_func_8830867C_02C_0C0* arg0, s32 arg1, s32 arg2, s32 arg3, unk_func_88001300_000_010 arg4);
void func_883151E8(unk_func_882173EC* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_8831527C(unk_func_882173EC* arg0);
s32 func_883152D0(unk_func_882173EC* arg0, s32 arg1, s32 arg2);
void func_883156B8(unk_func_882173EC* arg0, char* arg1, char* arg2, unk_func_88001300_000_010 arg3);
void func_883156E8(unk_func_882173EC* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_8831577C(unk_func_882173EC* arg0);
void func_883157D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
s32 func_88315A6C(unk_func_882173EC* arg0, s32 arg1, s32 arg2);
void func_88315C98(unk_func_882173EC* arg0, s32 arg1, s32 arg2, unk_func_88001300_000_010 arg3);

s32 func_88315CD0(unk_func_88316128*, unk_func_88316128*);
s32 func_88315D48(unk_func_88316128*, unk_func_88316128*);
s32 func_88315D8C(unk_func_88316128*, unk_func_88316128*);
s32 func_88315DD0(unk_func_88316128*, unk_func_88316128*);
s32 func_88315E14(unk_func_88316128*, unk_func_88316128*);
s32 func_88315E58(unk_func_88316128*, unk_func_88316128*);
s32 func_88315E9C(unk_func_88316128*, unk_func_88316128*);
s32 func_88315EE0(unk_func_88316128*, unk_func_88316128*);
s32 func_88315F24(unk_func_88316128*, unk_func_88316128*);
s32 func_88315F68(unk_func_88316128*, unk_func_88316128*);
s32 func_88315FAC(unk_func_88316128*, unk_func_88316128*);
s32 func_88315FF0(unk_func_88316128*, unk_func_88316128*);
s32 func_88316034(unk_func_88316128*, unk_func_88316128*);
s32 func_88316078(unk_func_88316128*, unk_func_88316128*);
s32 func_883160BC(unk_func_8830867C_02C_0CC*, unk_func_8830867C_02C_0CC*);
s32 func_883160DC(unk_func_88316128* arg0, unk_func_88316128* arg1);
s32 func_88316128(unk_func_88316128*, unk_func_88316128*);
s32 func_88316174(unk_func_8830867C_02C_0CC*, unk_func_8830867C_02C_0CC*);
s32 func_883161D0(unk_func_8830867C_02C_0CC*, unk_func_8830867C_02C_0CC*);
int func_88316214(unk_func_8830867C_02C_0CC* arg0, u8* arg1);
s32 func_88316240(unk_func_8830867C_02C_0CC* arg0, unk_func_8830867C_02C_C54_01C* arg1);
s32 func_88316304(unk_func_8830867C_02C_0CC* arg0, unk_func_8830867C_02C_C54_024* arg1);
s32 func_883163A4(unk_func_8830867C_02C_0CC* arg0, s32* arg1);
s32 func_883163B8(unk_func_8830867C_02C_0CC* arg0, unk_func_8830867C_02C_C54_014* arg1);
s32 func_88316480(unk_func_88316128* arg0, u8* arg1);
void func_883164C0(unk_func_8830867C_02C_0E4*, s32, s32, MemoryPool*);
void func_883166A0(unk_func_8830867C_02C_144*);
void func_883167CC(unk_func_88200FA0_030_038*, unk_func_8830867C_02C_144*);
s32 func_883168B4(unk_func_8830867C_02C_144*);
void func_88316A58(unk_func_8830867C_02C_144*, s32);
void func_88316BEC(unk_func_8830867C_02C_154*, MemoryPool* arg1);
void func_88316D5C(unk_func_8830867C_02C_154*);
void func_88316DB8(unk_func_8830867C_02C_154*);
void func_88316F98(unk_func_88200FA0_030_038*, unk_func_8830867C_02C_1A8*, unk_func_8830867C_02C_154*, s32, s32);
void func_88317144(unk_func_8830867C_04C_030_02C_000*);


#endif // _FRAGMENT24_H_
