#ifndef _FRAGMENT23_H_
#define _FRAGMENT23_H_

#include "global.h"
#include "src/fragments/26/fragment26.h"
#include "src/fragments/29/fragment29.h"
#include "src/2D340.h"
#include "src/22630.h"
#include "src/2E460.h"

struct unk_func_8821421C_038_04C_000;
struct unk_func_8820B12C_02C;
struct unk_func_8821421C_034;
struct unk_func_8821421C_038;
struct unk_func_8821421C_03C;
struct unk_func_8821421C_07C;
struct unk_func_8820E99C;
struct unk_func_8821421C_02C;

typedef struct unk_func_8820EFD8 {
    /* 0x00 */ char unk00[0x4];
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ char* unk_08;
} unk_func_8820EFD8; // size >= 0xC

typedef struct unk_func_88200FA0_030 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_88001300_038* unk_2C;
    /* 0x30 */ unk_func_88200FA0_030_030* unk_30;
    /* 0x34 */ unk_func_88503298* unk_34;
    /* 0x38 */ unk_func_88200FA0_030_038 unk_38;
} unk_func_88200FA0_030; // size = 0x44

typedef struct unk_func_88200FA0 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_885088F4* unk_2C;
    /* 0x30 */ unk_func_88200FA0_030* unk_30;
} unk_func_88200FA0; // size = 0x34

typedef struct unk_func_88205880 {
    /* 0x0000 */ unk_func_88001300_000 unk_0000;
    /* 0x002C */ unk_func_88203ED8* unk_002C;
    /* 0x0030 */ char unk0030[0x64];
    /* 0x0094 */ unk_func_88201DA0* unk_0094;
    /* 0x0098 */ unk_func_88205880_0098 unk_0098;
    /* 0x00D0 */ unk_func_88205880_00D0 unk_00D0[12];
    /* 0x5050 */ unk_func_88205880_00D0 unk_5050[12];
    /* 0x9FD0 */ unk_func_88205880_00D0* unk_9FD0[12];
    /* 0xA000 */ unk_func_88205880_00D0* unk_A000[12];
    /* 0xA030 */ unk_func_88205880_A030 unk_A030[2];
} unk_func_88205880; // size = 0xA048

typedef struct unk_func_882062E4 {
    /* 0x0000 */ char unk_00[0x54];
} unk_func_882062E4; // size = 0x54

typedef struct unk_func_88208C5C {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_8850143C* unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 unk_38;
} unk_func_88208C5C; // size = 0x3C

typedef struct unk_func_882079D8 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_88205880_00D0* unk_2C;
} unk_func_882079D8; // size = 0x30

typedef struct unk_func_8820BE14_030 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ MemoryPool* unk_04;
    /* 0x08 */ unk_func_88001300_000_000* unk_08;
    /* 0x0C */ unk_func_88205880_00D0* unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ unk_func_88001300_000* unk_14;
    /* 0x18 */ s32 unk_18;
} unk_func_8820BE14_030; // size >= 0x1C

typedef struct unk_func_8820B12C_02C_020 {
    /* 0x00 */ unk_func_88200FA0_030_030_1AE680 unk_00; // unk_func_882025E0_024
    /* 0x54 */ u16 unk_54;
    /* 0x56 */ u16 unk_56;
    /* 0x58 */ s32 unk_58;
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ s32 unk_60;
    /* 0x64 */ s32 unk_64;
    /* 0x68 */ s32 unk_68;
    /* 0x6C */ s32 unk_6C;
    /* 0x70 */ s32 unk_70;
    /* 0x74 */ unk_func_88001300_01C unk_74;
    /* 0x78 */ unk_func_88001300_018 unk_78;
    /* 0x7C */ unk_func_88001300_020 unk_7C;
    /* 0x80 */ unk_func_88001300_018 unk_80;
    /* 0x84 */ unk_func_8820BE14_02C_038_084* unk_84;
    /* 0x88 */ s32* unk_88;
    /* 0x8C */ u32 unk_8C;
} unk_func_8820B12C_02C_020; // size = 0x90

typedef s32 (*unk_func_8820B12C_02C_010)(struct unk_func_8820B12C_02C* arg0, Controller* arg1);
typedef void (*unk_func_8820B12C_02C_014)(struct unk_func_8820B12C_02C* arg0, s32 arg1);

typedef struct unk_func_8820B12C_02C {
    /* 0x00 */ char unk00[0x4];
    /* 0x04 */ struct unk_func_8820B12C_02C* unk_04;
    /* 0x08 */ struct unk_func_8820B12C_02C* unk_08;
    /* 0x0C */ char unk0C[0x4];
    /* 0x10 */ unk_func_8820B12C_02C_010 unk_10;
    /* 0x14 */ unk_func_8820B12C_02C_014 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ unk_func_8820B12C_02C_020* unk_20[2];
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ unk_func_88217740* unk_38;
    /* 0x3C */ unk_func_88509F48* unk_3C;
    /* 0x40 */ unk_func_8850CD44* unk_40;
    /* 0x44 */ FragmentEntry unk_44;
    /* 0x48 */ unk_func_8820BE14_030* unk_48;
    /* 0x4C */ unk_func_882173EC* unk_4C[2];
    /* 0x54 */ unk_func_882079D8* unk_54[2];
    /* 0x5C */ unk_func_8850878C* unk_5C[6];
    /* 0x74 */ s32 unk_74;
} unk_func_8820B12C_02C; // size = 0x78

typedef struct unk_func_8820B12C_000 {
    /* 0x00 */ char unk00[0x4];
    /* 0x04 */ struct unk_func_8820B12C_000* unk_04;
    /* 0x08 */ struct unk_func_8820B12C_000* unk_08;
    /* 0x0C */ char unk0C[0x4];
    /* 0x10 */ unk_func_8820B12C_02C_010 unk_10;
    /* 0x14 */ unk_func_8820B12C_02C_014 unk_14;
    /* 0x18 */ char unk18[0x4];
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ struct unk_func_8820BE14_02C* unk_24;
} unk_func_8820B12C_000; // size = 0x28

typedef struct unk_func_8820B12C {
    /* 0x00 */ unk_func_8820B12C_000 unk_00;
    /* 0x28 */ unk_func_88001300_03C* unk_28;
    /* 0x28 */ unk_func_8820B12C_02C* unk_2C;
} unk_func_8820B12C; // size = 0x30

typedef struct unk_func_8820BE14_02C_070 {
    /* 0x0000 */ unk_func_88001300_000 unk_0000;
    /* 0x002C */ unk_func_88205880_00D0* unk_002C;
    /* 0x0030 */ s16 unk_0030;
    /* 0x0032 */ char unk0032[0x7];
    /* 0x0039 */ u8 unk_0039[2][0xC80];
} unk_func_8820BE14_02C_070; // size = 0x193C

typedef struct unk_func_8820BE14_02C_078_034 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_88001300_038* unk_2C;
    /* 0x30 */ unk_func_88200FA0_030_030* unk_30;
} unk_func_8820BE14_02C_078_034; // size = 0x34

typedef struct unk_func_8820BE14_02C_078 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_88001300_038* unk_2C;
    /* 0x30 */ unk_func_88200FA0_030_030* unk_30;
    /* 0x34 */ unk_func_8820BE14_02C_078_034* unk_34;
    /* 0x38 */ unk_func_8820BE14_06C unk_38;
    /* 0x48 */ s32 unk_48;
    /* 0x4C */ s32 unk_4C;
    /* 0x50 */ s32 unk_50;
    /* 0x54 */ s32 unk_54;
    /* 0x58 */ s32 unk_58;
    /* 0x5C */ s32 unk_5C;
} unk_func_8820BE14_02C_078; // size = 0x60

typedef struct unk_func_8820BE14_02C {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_88001300_038* unk_2C;
    /* 0x30 */ unk_func_88208C5C* unk_30[2];
    /* 0x38 */ unk_func_8820BE14_02C_038* unk_38[2];
    /* 0x40 */ unk_func_88217740* unk_40;
    /* 0x44 */ unk_func_882149A0* unk_44[8];
    /* 0x64 */ unk_func_88500994* unk_64;
    /* 0x68 */ unk_func_88500994* unk_68;
    /* 0x6C */ unk_func_88500994* unk_6C;
    /* 0x70 */ unk_func_8820BE14_02C_070* unk_70;
    /* 0x74 */ unk_func_8820B12C* unk_74;
    /* 0x78 */ unk_func_8820BE14_02C_078* unk_78[2];
    /* 0x80 */ unk_func_88509F48* unk_80;
    /* 0x84 */ unk_func_889000C4* unk_84;
    /* 0x88 */ unk_func_8850878C* unk_88;
    /* 0x8C */ unk_func_8820BE14_06C* unk_8C;
    /* 0x90 */ char unk90[0x10];
} unk_func_8820BE14_02C; // size = 0xA0

typedef struct unk_func_8820BE14 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_8820BE14_02C* unk_2C;
    /* 0x30 */ unk_func_8820BE14_030 unk_30;
    /* 0x4C */ char** unk_4C;
    /* 0x50 */ char** unk_50;
    /* 0x54 */ char** unk_54;
    /* 0x58 */ char** unk_58;
    /* 0x5C */ char** unk_5C;
    /* 0x60 */ char** unk_60;
    /* 0x64 */ char** unk_64;
    /* 0x68 */ unk_func_88509F48* unk_68;
    /* 0x6C */ unk_func_8820BE14_06C unk_6C;
    /* 0x7C */ unk_func_8820BE14_06C unk_7C;
    /* 0x8C */ unk_func_8820BE14_06C unk_8C;
} unk_func_8820BE14; // size = 0x9C

typedef struct unk_func_882170A8 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_8820BE14_02C_038* unk_2C;
    /* 0x30 */ s32 unk_30;
} unk_func_882170A8; // size = 0x34

typedef struct unk_D_88217C6C {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ u8* unk_08;
    /* 0x0C */ s16 unk_0C;
    /* 0x10 */ Color_RGBA8* unk_10;
    /* 0x14 */ s32 unk_14;
} unk_D_88217C6C; // size = 0x18

typedef struct unk_func_8821421C_02C_06C_02C_068 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ s32 unk_2C;
} unk_func_8821421C_02C_06C_02C_068; // size = 0x30

typedef struct unk_func_8820E99C_030 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_88001300_038* unk_2C;
    /* 0x30 */ unk_func_8820E99C_030_030 unk_30;
    /* 0x44 */ unk_func_8820E99C_030_044* unk_44;
} unk_func_8820E99C_030; // size = 0x48

typedef struct unk_func_8820E99C {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_88001300_038* unk_2C;
    /* 0x30 */ unk_func_8820E99C_030* unk_30;
    /* 0x34 */ s32 unk_34;
} unk_func_8820E99C; // size = 0x38

typedef struct unk_func_8821421C_034 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_88001300_038* unk_2C;
    /* 0x30 */ unk_func_88001300_03C* unk_30;
    /* 0x34 */ unk_func_8850878C* unk_34;
} unk_func_8821421C_034; // size = 0x38

typedef struct unk_func_8821421C_038_02C {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_8850143C* unk_2C;
    /* 0x30 */ unk_func_8821421C_038_050* unk_30;
} unk_func_8821421C_038_02C; // size = 0x34

typedef struct spE8_func_882121E0 {
    /* 0x00 */ char* unk_00[3];
} spE8_func_882121E0; // size >= 0xC

typedef struct unk_func_8821421C_02C_030 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_8850143C* unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ spE8_func_882121E0* unk_38;
} unk_func_8821421C_02C_030; // size = 0x3C

typedef struct unk_func_8821421C_02C_06C_02C_060_02C_000 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
} unk_func_8821421C_02C_06C_02C_060_02C_000; // size = 0x2

typedef struct unk_func_8821421C_02C_06C_02C_060_02C {
    /* 0x00 */ unk_func_8821421C_02C_06C_02C_060_02C_000 unk_00;
    /* 0x02 */ unk_func_8821421C_02C_06C_02C_060_02C_000 unk_02;
} unk_func_8821421C_02C_06C_02C_060_02C; // size >= 0x4

typedef struct unk_func_8821421C_02C_06C_02C_060 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_8821421C_02C_06C_02C_060_02C unk_2C;
} unk_func_8821421C_02C_06C_02C_060; // size = 0x30

typedef struct unk_func_8821421C_02C_06C_02C {
    /* 0x00 */ char unk00[0x10];
    /* 0x10 */ unk_func_882025E0_010 unk_10;
    /* 0x14 */ unk_func_882025E0_014 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ unk_func_8820BE14_02C_038* unk_20[2];
    /* 0x28 */ struct unk_func_8820E99C* unk_28;
    /* 0x2C */ unk_func_8820BE14_02C_038* unk_2C[2];
    /* 0x34 */ struct unk_func_8820E99C* unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ unk_func_88217740* unk_48;
    /* 0x4C */ unk_func_88509F48* unk_4C;
    /* 0x50 */ unk_func_8850CD44* unk_50;
    /* 0x54 */ char unk54[0x4];
    /* 0x58 */ unk_func_882173EC* unk_58[2];
    /* 0x60 */ unk_func_8821421C_02C_06C_02C_060* unk_60[2];
    /* 0x68 */ unk_func_8821421C_02C_06C_02C_068* unk_68[2];
    /* 0x70 */ unk_func_8821421C_02C_06C_02C_060* unk_70[2];
    /* 0x78 */ unk_func_882025E0_03C unk_78[5];
} unk_func_8821421C_02C_06C_02C; // size = 0xB4

typedef struct unk_func_8821421C_02C_06C_000 {
    /* 0x00 */ char unk00[0x4];
    /* 0x04 */ struct unk_func_88203ED8_064* unk_04;
    /* 0x08 */ struct unk_func_88203ED8_064* unk_08;
    /* 0x0C */ char unk0C[0x4];
    /* 0x10 */ unk_func_8820B12C_02C_010 unk_10;
    /* 0x14 */ unk_func_8820B12C_02C_014 unk_14;
    /* 0x18 */ char unk18[0x4];
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ struct unk_func_8821421C_02C* unk_24;
} unk_func_8821421C_02C_06C_000; // size = 0x28

typedef struct unk_func_8821421C_02C_06C {
    /* 0x00 */ unk_func_8821421C_02C_06C_000 unk_00;
    /* 0x28 */ unk_func_88001300_03C* unk_28;
    /* 0x2C */ unk_func_8821421C_02C_06C_02C* unk_2C;
} unk_func_8821421C_02C_06C; // size = 0x30

typedef struct unk_func_8821421C_02C_070 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_88001300_038* unk_2C;
    /* 0x30 */ unk_func_88200FA0_030_030* unk_30;
    /* 0x34 */ unk_func_88205880_A030 unk_34;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ s32 unk_48;
} unk_func_8821421C_02C_070; // size = 0x4C

typedef struct unk_func_8821421C_02C {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_88001300_038* unk_2C;
    /* 0x30 */ unk_func_8821421C_02C_030* unk_30[2];
    /* 0x38 */ unk_func_8820BE14_02C_038* unk_38[2];
    /* 0x40 */ unk_func_88217740* unk_40;
    /* 0x44 */ unk_func_882149A0* unk_44[6];
    /* 0x5C */ unk_func_88500994* unk_5C;
    /* 0x60 */ unk_func_88500994* unk_60;
    /* 0x64 */ unk_func_88500994* unk_64;
    /* 0x68 */ unk_func_8850878C* unk_68;
    /* 0x6C */ unk_func_8821421C_02C_06C* unk_6C;
    /* 0x70 */ unk_func_8821421C_02C_070* unk_70[2];
    /* 0x78 */ struct unk_func_8821421C_03C* unk_78;
    /* 0x78 */ struct unk_func_8821421C_03C* unk_7C;
    /* 0x80 */ s32 unk_80;
    /* 0x84 */ struct unk_func_8821421C_038* unk_84;
    /* 0x88 */ struct unk_func_8821421C_034* unk_88;
    /* 0x8C */ unk_func_88509F48* unk_8C;
    /* 0x90 */ struct unk_func_8821421C_07C* unk_90;
    /* 0x94 */ unk_func_882025E0_03C unk_94[1];
    /* 0xA0 */ unk_func_889000C4* unk_A0;
} unk_func_8821421C_02C; // size = 0xA4

typedef void (*unk_func_8821421C_038_04C_000_014)(struct unk_func_8821421C_038_04C_000*, Controller*);

typedef struct unk_func_8821421C_038_04C_000 {
    /* 0x00 */ char unk00[0x4];
    /* 0x04 */ struct unk_func_88203ED8_064* unk_04;
    /* 0x08 */ struct unk_func_88203ED8_064* unk_08;
    /* 0x0C */ char unk0C[0x4];
    /* 0x10 */ unk_func_8820B12C_02C_010 unk_10;
    /* 0x14 */ unk_func_8821421C_038_04C_000_014 unk_14;
    /* 0x18 */ char unk18[0x4];
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ struct unk_func_8821421C_038* unk_24;
} unk_func_8821421C_038_04C_000; // size = 0x28

typedef struct unk_func_8821421C_038_04C {
    /* 0x00 */ unk_func_8821421C_038_04C_000 unk_00;
    /* 0x28 */ unk_func_88001300_03C* unk_28;
} unk_func_8821421C_038_04C; // size = 0x2C

typedef struct unk_func_8821421C_03C {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ unk_func_8820BE14_06C unk_04;
} unk_func_8821421C_03C; // size = 0x14

typedef struct unk_func_8821421C_07C {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ char unk_08[4]; // unk size
    /* 0x0C */ char unk0C[0x8];
} unk_func_8821421C_07C; // size = 0x14

typedef struct unk_func_8821421C_038 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_8821421C_038_02C* unk_2C;
    /* 0x30 */ unk_func_8820BE14_02C_038* unk_30;
    /* 0x34 */ unk_func_8821421C_038_034* unk_34;
    /* 0x38 */ unk_func_88500994* unk_38;
    /* 0x3C */ unk_func_88500994* unk_3C;
    /* 0x40 */ unk_func_8850878C* unk_40;
    /* 0x44 */ unk_func_88001300_038* unk_44;
    /* 0x48 */ unk_func_8821421C_034* unk_48;
    /* 0x4C */ unk_func_8821421C_038_04C* unk_4C;
    /* 0x50 */ unk_func_8821421C_038_050* unk_50[1];
    /* 0x54 */ char unk54[0xC];
    /* 0x60 */ s32 unk_60;
    /* 0x64 */ unk_func_8820BE14_06C unk_64;
    /* 0x74 */ char unk74[0x4];
} unk_func_8821421C_038; // size = 0x78

typedef struct unk_func_8821421C {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_8821421C_02C* unk_2C;
    /* 0x34 */ unk_func_88509F48* unk_30;
    /* 0x34 */ unk_func_8821421C_034* unk_34;
    /* 0x38 */ unk_func_8821421C_038* unk_38;
    /* 0x3C */ unk_func_8821421C_03C unk_3C[3];
    /* 0x78 */ s32 unk_78;
    /* 0x7C */ unk_func_8821421C_07C unk_7C[4];
} unk_func_8821421C; // size = 0xCC

extern Color_RGBA8 D_882181B0[2];
extern Color_RGBA8 D_882181B8[2];
extern Color_RGBA8 D_882181C0[2];
extern Color_RGBA8 D_882181C8[2];
extern Color_RGBA8 D_882181D0[2];
extern Color_RGBA8 D_882181D8[2];
extern Color_RGBA8 D_882181E0[2];
extern Color_RGBA8 D_882181E8[2];
extern Color_RGBA8 D_882181F0[2];
extern Color_RGBA8 D_882181F8[2];
extern Color_RGBA8 D_88218200[2];
extern Color_RGBA8 D_88218208[2];
extern Color_RGBA8 D_88218210[2];
extern Color_RGBA8 D_88218218[2];
extern Color_RGBA8 D_88218220[2];
extern Color_RGBA8 D_88218228[2];
extern Color_RGBA8 D_88218230[2];
extern Color_RGBA8 D_88218238[2];

extern u32 D_8821E100[];
extern u32 D_88218FD0[];
extern u32 D_8821B868[];
extern u32 D_8821AAE0[];
extern u32 D_88219D58[];
extern u32 D_88218248[];
extern u32 D_8821C5F0[];
extern u32 D_8821D378[];
extern u32 D_8821EE88[];
extern u32 D_882220D8[];
extern u32 D_882225C0[];
extern u32 D_88222AA8[];
extern u32 D_88222F90[];
extern u32* D_88223470[];
extern u32 D_88223488[];
extern u32 D_88223E48[];

unk_D_800AC870* func_88200020(void);
void func_882000E4(void);
s32 func_88200110(UNUSED s32 arg0, UNUSED s32 arg1);
s32 func_88200190(s32 arg0, s32 arg1);

void func_88200290(unk_func_88503298* arg0, s32 arg1, s32 arg2, MemoryPool* arg3);
void func_882004BC(unk_func_88503298* arg0, s8* arg1);
void func_882004C8(unk_func_88200FA0_030* arg0, s32 arg1, s32 arg2, unk_func_88001300_000* arg3, MemoryPool* arg4);
void func_88200968(unk_func_88200FA0_030* arg0, s32 arg1);
void func_882009B4(s32 arg0, s32 arg1, char* arg2, s32 arg3);
s32 func_88200A30(unk_func_88200FA0_030* arg0, Controller* arg1);
void func_88200ACC(unk_func_88200FA0_030* arg0);
void func_88200AF4(unk_func_88200FA0_030* arg0);
s32 func_88200B60(unk_func_88200FA0_030* arg0, Controller* arg1);
void func_88200C44(unk_func_88200FA0* arg0, s32 arg1, s32 arg2, s32 arg3, MemoryPool* arg4);
s32 func_88200F00(unk_func_88200FA0* arg0);
void func_88200FA0(unk_func_88200FA0* arg0);
s32 func_8820104C(s32 arg0, UNUSED s32 arg1);

void func_88201210(unk_func_88205880_00D0* arg0);
void func_88201294(s32 arg0, s32 arg1, s32 arg2, unk_func_88205880_00D0* arg3);
s32 func_8820130C(s32 arg0, s32 arg1, s32 arg2, unk_func_88205880_00D0* arg3, s32 arg4);
void func_88201360(unk_func_88205880_00D0* arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_882013F8(unk_func_88205880_A030* arg0);
s32 func_88201440(unk_func_88205880_A030* arg0);
void func_88202054(unk_func_88201DA0* arg0, u32 arg1, u32 arg2);
void func_8820213C(unk_func_88201DA0* arg0, unk_func_88205880_00D0* arg1, u32 arg2);
void func_88202228(unk_func_88203ED8* arg0, s32 arg1);
s32 func_88202254(unk_func_88201DA0* arg0, Controller* arg1);
void func_88202394(unk_func_88201DA0* arg0, Controller* arg1);
void func_88202450(unk_func_88205880_00D0* arg0, s32 arg1, s32 arg2);
void func_8820253C(unk_func_8820253C* arg0, s32 arg1, s32 arg2, unk_func_88205880_00D0* arg3);
void func_882025AC(unk_func_8820253C* arg0, unk_func_88205880_00D0* arg1);
s32 func_882025B4(unk_func_8820253C* arg0, s32 arg1, s32 arg2);
void func_882025E0(unk_func_882025E0_1A9780* arg0, unk_func_88200FA0_030_030* arg1, unk_func_88200FA0_030_030* arg2, unk_func_88203ED8* arg3, MemoryPool* arg4);
void func_88202738(unk_func_882025E0_1A9780* arg0, s32 arg1);
void func_88202758(unk_func_882025E0_1A9780* arg0);
void func_882027F0(unk_func_882025E0_1A9780* arg0, s32 arg1);
void func_88202810(unk_func_882025E0_1A9780* arg0, unk_func_88205880_00D0** arg1, unk_func_88205880_00D0** arg2);
void func_882028EC(unk_func_882025E0_1A9780* arg0, unk_func_88001300_000_010* arg1, unk_func_88001300_000_010* arg2);
void func_88202A2C(unk_func_88200FA0_030_030* arg0);
void func_88202B74(unk_func_88200FA0_030_030* arg0);
void func_88202CBC(unk_func_882025E0_1A9780* arg0);
void func_88202D60(unk_func_882025E0_1A9780* arg0, s32 arg1);
void func_88202E74(unk_func_882025E0_1A9780* arg0, s32 arg1);
void func_88202E98(unk_func_882025E0_1A9780* arg0);
void func_88202EB8(unk_func_882025E0_1A9780* arg0);
s32 func_88202ED8(unk_func_882025E0_1A9780* arg0);
void func_88202EF4(unk_func_882025E0_1A9780* arg0);
void func_88202F2C(unk_func_882025E0_1A9780* arg0);
s32 func_88202F70(unk_func_882025E0_1A9780* arg0, Controller* arg1);
void func_8820399C(unk_func_8820399C* arg0, s32 arg1, unk_func_8850143C* arg2);
s32 func_88203A20(unk_func_8820399C* arg0, s32 arg1, s32 arg2);
s32 func_88204BA8(unk_func_88203ED8* arg0);
void func_88204BFC(unk_func_88203ED8* arg0, s32 arg1);
s32 func_88204C28(unk_func_88203ED8* arg0, Controller* arg1);
void func_88204C74(unk_func_88203ED8* arg0);
void func_88204CBC(unk_func_88203ED8* arg0);
void func_88204DC0(unk_func_88203ED8_064* arg0, unk_func_88203ED8* arg1);
u32 func_88204E0C(unk_func_88205880_00D0* arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_88204EE8(unk_func_88203ED8* arg0);
void func_8820508C(unk_func_88203ED8* arg0, s32 arg1);
s32 func_882051EC(unk_func_88203ED8* arg0, Controller* arg1);
s32 func_882052F4(unk_func_88203ED8_064* arg0, Controller* arg1);
void func_882057B4(unk_func_88203ED8* arg0, Controller* arg1);
s32 func_88205DD0(unk_func_88205880* arg0, Controller* arg1);
void func_88205DF8(unk_func_88205880* arg0);
void func_88205E94(unk_func_88205880* arg0);

void func_88206110(unk_func_80026268_arg0* arg0);
s32 func_882062E4(unk_func_882062E4* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_88206868(unk_func_8820BE14_02C_078_034* arg0, Controller* arg1);
s32 func_882068B4(unk_func_88001300_034* arg0, Controller* arg1);
s32 func_882069C0(void);
void func_88206A20(unk_func_8820BE14_02C_078_034* arg0, s32 arg1, s32 arg2, MemoryPool* arg3);
s32 func_88206BA0(void);
u32 func_88206E50(unk_func_8820BE14_02C_078* arg0);
void func_88206E80(unk_func_8820BE14_02C_078* arg0, u32 arg1);
void func_88206F0C(unk_func_8820BE14_02C_078* arg0, u32 arg1);
s32 func_88206F44(unk_func_8820BE14_02C_078* arg0, Controller* arg1);
s32 func_88207154(unk_func_8820BE14_02C_078* arg0, Controller* arg1);
void func_8820723C(unk_func_88205880_00D0* arg0, s32 arg1, s32 arg2, s32 arg3);
void func_882079D8(unk_func_882079D8* arg0, s32 arg1, s32 arg2, s32 arg3, unk_func_88205880_00D0* arg4);
void func_88207A54(unk_func_882079D8* arg0, unk_func_88205880_00D0* arg1);
s32 func_88207A5C(unk_func_882079D8* arg0, s32 arg1, s32 arg2);
void func_88207BFC(unk_func_8820B12C_02C* arg0, s32 arg1);
void func_88207C34(unk_func_8820B12C_02C* arg0, s32 arg1);
void func_88207C54(unk_func_8820B12C_02C* arg0);
void func_88207CEC(unk_func_8820B12C_02C* arg0, s32 arg1);
void func_88207D0C(unk_func_8820B12C_02C* arg0, s32 arg1);
void func_88207D18(unk_func_8820B12C_02C* arg0);
void func_88207D38(unk_func_8820B12C_02C* arg0, unk_func_88205880_00D0** arg1, unk_func_88205880_00D0** arg2);
void func_88207E14(unk_func_8820B12C_02C* arg0, unk_func_88001300_000_010* arg1, unk_func_88001300_000_010* arg2);
void func_88207F84(unk_func_8820B12C_02C* arg0, s32 arg1);
void func_88208124(unk_func_8820B12C_02C* arg0);
s32 func_88208160(unk_func_8820B12C_02C* arg0);
void func_8820817C(unk_func_8820B12C_02C_020* arg0, unk_func_8820B12C_02C_020* arg1);
void func_8820820C(unk_func_8820B12C_02C_020* arg0, s32 arg1, s32 arg2);
void func_88208250(unk_func_8820B12C_02C_020* arg0, unk_func_8820B12C_02C_020* arg1);
void func_882082BC(unk_func_8820B12C_02C_020* arg0);
void func_882082FC(unk_func_8820B12C_02C* arg0, Controller* arg1);
void func_882083D0(unk_func_8820B12C_02C* arg0, Controller* arg1, s32 arg2);
void func_88208508(unk_func_8820B12C_02C* arg0);
s32 func_88208600(unk_func_8820B12C_02C* arg0, Controller* arg1);
unk_func_88205880_00D0* func_88208BFC(unk_func_8820B12C_02C* arg0);
void func_88208C5C(unk_func_88208C5C* arg0, unk_func_8850143C* arg1);
s32 func_88208CE4(unk_func_88208C5C* arg0, s32 arg1, s32 arg2);
u32 func_882091E4(unk_func_88208C5C* arg0);
void func_882091F8(unk_func_88208C5C* arg0, u32 arg1);
void func_8820920C(unk_func_8820BE14_02C_070* arg0, s32 arg1, s32 arg2);
void func_8820927C(s32 arg0, s32 arg1, ret_func_8002ED08* arg2, s32 arg3);
s32 func_8820938C(unk_func_8820BE14_02C_070* arg0, s32 arg1, s32 arg2);
void func_88209A88(unk_func_8820BE14_02C_070* arg0, unk_func_88205880_00D0* arg1);
s32 func_88209AF0(unk_func_8820BE14_06C* arg0);
s32 func_8820ADEC(unk_func_8820BE14_02C* arg0);
s32 func_8820AF78(unk_func_8820BE14_02C* arg0, Controller* arg1);
s32 func_8820AFC4(unk_func_8820BE14_02C* arg0, Controller* arg1);
void func_8820B0A0(unk_func_8820BE14_02C* arg0, s32 arg1);
void func_8820B0E0(unk_func_8820B12C_02C* arg0);
void func_8820B12C(unk_func_8820B12C* arg0, unk_func_8820BE14_02C* arg1);
s32 func_8820B178(unk_func_8820BE14_06C_000* arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_8820B2A4(unk_func_8820BE14_02C* arg0);
s32 func_8820B3AC(unk_func_8820BE14_02C* arg0);
void func_8820B3C0(s32 arg0, s32 arg1, s32 arg2, unk_func_88200FA0_030_038* arg3);
void func_8820B480(unk_func_88200FA0_030_038* arg0, s32 arg1);
void func_8820B504(unk_func_8820BE14_02C* arg0, s32 arg1);
s32 func_8820B714(unk_func_8820BE14_02C* arg0, Controller* arg1);
s32 func_8820B838(unk_func_8820B12C* arg0, Controller* arg1);
void func_8820C510(unk_func_8820BE14* arg0);
void func_8820C5BC(unk_func_8820BE14* arg0);
void func_8820C63C(unk_func_8820BE14* arg0);
void func_8820C700(unk_D_800AC870* arg0, s32 arg1);

void func_8820C930(s32 arg0, s32 arg1, s32 arg2, unk_func_8820BE14_06C* arg3);
void func_8820C97C(s32 arg0, s32 arg1, s32 arg2, unk_func_8820BE14_06C* arg3, s32 arg4, char* arg5, s32 arg6);
void func_8820CA2C(unk_func_8821421C_07C* arg0);
s32 func_8820CAB4(unk_func_8821421C_07C* arg0, s32 arg1, char* arg2);
void func_8820CBA0(unk_func_8821421C_02C_030* arg0, unk_func_8850143C* arg1, spE8_func_882121E0* arg2);
s32 func_8820CC30(unk_func_8821421C_02C_030* arg0, s32 arg1, s32 arg2);
s32 func_8820D0E4(unk_func_8821421C_02C_030* arg0);
void func_8820D0EC(unk_func_8821421C_02C_030* arg0, s32 arg1);
void func_8820D0F4(unk_func_8821421C_034* arg0, s32 arg1, s32 arg2, MemoryPool* arg3);
s32 func_8820D564(unk_func_8821421C_034* arg0, Controller* arg1);
void func_8820D5E8(unk_func_8821421C_034* arg0, s32 arg1);
void func_8820D614(unk_func_8821421C_034* arg0, char* arg1);
s32 func_8820D620(unk_func_8821421C_034* arg0, Controller* arg1);
s32 func_8820D754(spE8_func_882121E0* arg0, s32 arg1);
void func_8820D7C8(s32 arg0, s32 arg1, s8* arg2, s32 arg3, s32 arg4, unk_func_88200FA0_030_030* arg5);
s32 func_8820DB98(unk_func_8821421C_02C_070* arg0, Controller* arg1);
void func_8820DBE4(unk_func_8821421C_02C_070* arg0, s32 arg1);
s32 func_8820DC10(unk_func_8821421C_02C_070* arg0);
void func_8820DC1C(unk_func_8821421C_02C_070* arg0, s32 arg1);
void func_8820DC90(unk_func_8821421C_02C_070* arg0);
void func_8820DCC4(unk_func_8821421C_02C_070* arg0);
s32 func_8820DCD4(unk_func_8821421C_02C_070* arg0, Controller* arg1);
void func_8820DDC0(unk_func_8821421C_02C_070* arg0, s32 arg1);
s32 func_8820DDE4(u8* arg0, s32 arg1, s32 arg2, s32 arg3);
void func_8820DF38(s32 arg0, s32 arg1, u8* arg2, s32 arg3, s32 arg4, unk_func_8820BE14_02C_038* arg5);
void func_8820E5BC(unk_func_8821421C_02C_06C_02C_060* arg0, s32 arg1, s32 arg2, s32 arg3);
void func_8820E638(unk_func_8821421C_02C_06C_02C_060* arg0, unk_func_8821421C_02C_06C_02C_060_02C_000 arg1);
s32 func_8820E654(unk_func_8821421C_02C_06C_02C_060* arg0, s32 arg1, s32 arg2);
void func_8820E680(unk_func_8820E99C_030* arg0, s32 arg1);
void func_8820E6A0(unk_func_8820E99C_030* arg0, s32 arg1, s32 arg2, MemoryPool* arg3);
void func_8820E7B0(unk_func_8820E99C_030* arg0, s32 arg1);
s32 func_8820E818(unk_func_8820E99C_030* arg0);
s32 func_8820E850(unk_func_8820E99C_030* arg0, s32 arg1, s32 arg2);
s32 func_8820E90C(unk_func_8820E99C_030* arg0, Controller* arg1);
void func_8820E978(unk_func_8820E99C* arg0, s32 arg1, s32 arg2);
void func_8820E99C(unk_func_8820E99C* arg0, s32 arg1, s32 arg2, MemoryPool* arg3);
void func_8820EBF0(unk_func_8820E99C* arg0, s32 arg1);
s32 func_8820EC1C(unk_func_8820E99C* arg0, Controller* arg1);
void func_8820EC68(unk_func_8820E99C* arg0);
void func_8820EC9C(unk_func_8820E99C* arg0);
void func_8820ECAC(unk_func_8821421C_038_02C* arg0, unk_func_8850143C* arg1);
s32 func_8820ED14(unk_func_8821421C_038_02C* arg0, s32 arg1, s32 arg2);
void func_8820EFD0(unk_func_8821421C_038_02C* arg0, unk_func_8821421C_038_050* arg1);
void func_8820EFD8(s32 arg0, s32 arg1, unk_func_8820EFD8* arg2, s32 arg3, s32 arg4, unk_func_8821421C_038_034* arg5);
void func_8820FFF8(unk_func_8821421C_038* arg0, unk_func_8821421C_07C* arg1);
s32 func_8821004C(unk_func_8821421C_038* arg0);
s32 func_88210168(unk_func_8821421C_038* arg0, Controller* arg1);
void func_882101B4(unk_func_8821421C_038* arg0, s32 arg1);
void func_882101E0(unk_func_8821421C_038* arg0, s32 arg1);
s32 func_88210234(unk_func_8821421C_038* arg0, Controller* arg1);
void func_88210334(unk_func_8821421C_038_04C* arg0, unk_func_8821421C_038* arg1);
s32 func_88210380(unk_func_8821421C_038_04C* arg0, Controller* arg1);
void func_882107D0(unk_func_8821421C_02C_06C_02C* arg0, s32 arg1);
void func_882107F0(unk_func_8821421C_02C_06C_02C* arg0);
void func_88210888(unk_func_8821421C_02C_06C_02C* arg0, s32 arg1);
void func_882108A8(unk_func_8821421C_02C_06C_02C* arg0);
void func_88210B38(unk_func_8821421C_02C_06C_02C* arg0, s32 arg1);
void func_88210BFC(unk_func_8821421C_02C_06C_02C* arg0, s32 arg1);
void func_88210D2C(unk_func_8821421C_02C_06C_02C* arg0, s32 arg1);
void func_88210D50(unk_func_8821421C_02C_06C_02C* arg0);
s32 func_88210D8C(unk_func_8821421C_02C_06C_02C* arg0);
void func_88210DA8(void);
s32 func_88210DB0(s32 arg0, unk_func_8820BE14_06C* arg1);
s32 func_88210DF4(s32 arg0, unk_func_8820BE14_06C* arg1);
void func_88210E70(unk_func_8820BE14_02C_038* arg0, u8* arg1);
void func_88210E98(unk_func_8820BE14_02C_038* arg0, s32 arg1);
void func_88210F00(unk_func_8820BE14_02C_038* arg0);
void func_88210F74(unk_func_8820BE14_02C_038* arg0, s32 arg1, s32 arg2);
void func_88211088(unk_func_8820BE14_02C_038* arg0, s32 arg1);
void func_882110E0(unk_func_8820BE14_02C_038* arg0, unk_func_8820BE14_02C_038* arg1, unk_func_8820E99C* arg2);
s32 func_882111C0(unk_func_8821421C_02C_06C_02C_060_02C_000* arg0, unk_func_8821421C_02C_06C_02C_060_02C_000* arg1);
void func_882111F8(unk_func_8820BE14_02C_038* arg0, s32 arg1, s32 arg2);
void func_882112E4(unk_func_8820BE14_02C_038* arg0, unk_func_8820BE14_02C_038* arg1);
void func_88211380(unk_func_8821421C_02C_06C_02C* arg0, Controller* arg1);
void func_88211508(unk_func_8821421C_02C_06C_02C* arg0, Controller* arg1);
void func_88211794(unk_func_8821421C_02C_06C_02C* arg0, Controller* arg1);
s32 func_882118CC(unk_func_8821421C_02C_06C_02C* arg0, Controller* arg1);
u8* func_88212150(unk_func_8821421C_02C_06C_02C* arg0);
s32 func_8821347C(unk_func_8821421C_02C* arg0);
s32 func_882135D4(unk_func_8821421C_02C* arg0, Controller* arg1);
s32 func_88213618(unk_func_8821421C_02C* arg0, Controller* arg1);
void func_882136F8(unk_func_8821421C_02C* arg0, s32 arg1);
void func_88213738(unk_func_8821421C_02C* arg0);
void func_88213774(unk_func_8821421C_02C_06C* arg0, unk_func_8821421C_02C* arg1);
s32 func_882137B4(unk_func_8821421C_03C* arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_882138D4(unk_func_8821421C_02C* arg0);
void func_882139C0(unk_func_8821421C_02C* arg0, s32 arg1);
s32 func_88213B90(unk_func_8821421C_02C* arg0, Controller* arg1);
s32 func_88213CA0(unk_func_8821421C_02C_06C* arg0, Controller* arg1);
void func_8821421C(unk_func_8821421C* arg0, s32 arg1, s32 arg2, MemoryPool* arg3, s32 arg4, char** arg5);
void func_88214720(unk_func_8821421C* arg0);
void func_882147BC(unk_func_8821421C* arg0);
void func_8821483C(unk_D_800AC870* arg0);

void func_882149A0(unk_func_882149A0* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, Color_RGBA8 arg7, Color_RGBA8 arg8, Color_RGBA8 arg9);
s32 func_88214A58(unk_func_882149A0* arg0, s32 arg1, s32 arg2);
void func_882158BC(unk_func_882149A0* arg0);
void func_882158CC(unk_func_8820BE14_02C_038* arg0, s32 arg1, s32 arg2, s32 arg3, void (*arg4)(), s32 arg5, s32 arg6, MemoryPool* arg7);
void func_88215974(unk_func_88200FA0_030_030* arg0, s32 arg1);
void func_882159AC(unk_func_8820BE14_02C_038* arg0, unk_func_88507D4C* arg1);
s32 func_882159BC(unk_func_8820BE14_02C_038* arg0);
s32 func_88215D18(unk_func_8820BE14_02C_038* arg0, s32 arg1, s32 arg2, s32 arg3);
void func_88216000(unk_func_8820BE14_02C_038* arg0, s32 arg1, s32 arg2);
s32 func_882169D4(unk_func_8820BE14_02C_038* arg0, Controller* arg1);
void func_88216F18(unk_func_8820BE14_02C_038* arg0, s32 arg1);
void func_88217018(unk_func_8820BE14_02C_038* arg0, unk_func_8820BE14_06C_000* arg1, u32 arg2);
void func_88217060(unk_func_8820BE14_02C_038*, s32*, s32);
void func_882170A8(unk_func_882170A8* arg0, s32 arg1, s32 arg2, unk_func_8820BE14_02C_038* arg3, s32 arg4);
void func_8821711C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 func_8821738C(unk_func_882170A8* arg0, s32 arg1, s32 arg2);
void func_882173EC(unk_func_882173EC* arg0, s32 arg1, s32 arg2);
s32 func_88217460(unk_func_882173EC* arg0);
void func_882175F4(unk_func_882173EC* arg0, unk_func_88001300_000_010 arg1, unk_func_88001300_000_010 arg2);
void func_88217650(unk_func_8821421C_02C_06C_02C_068* arg0, s32 arg1, s32 arg2);
s32 func_882176C4(unk_func_8821421C_02C_06C_02C_068* arg0);
void func_88217718(unk_func_8821421C_02C_06C_02C_068* arg0, unk_func_88001300_000_010 arg1);
void func_88217740(unk_func_88217740* arg0, s32 arg1, s32 arg2);
s32 func_882177A8(unk_func_88217740* arg0, s32 arg1, s32 arg2);
void func_88217BA0(unk_func_88217740* arg0, s32 arg1);
void func_88217BAC(unk_func_88217740* arg0);
void func_88217BB8(unk_func_88217740* arg0);
void func_88217BC0(unk_func_88217740* arg0);


#endif // _FRAGMENT23_H_
