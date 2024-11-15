#ifndef _FRAGMENT26_H_
#define _FRAGMENT26_H_

#include "global.h"
#include "src/memory.h"
#include "src/memmap.h"
#include "src/controller.h"
#include "src/29BA0.h"
#include "src/1AB70.h"
#include "src/2D340.h"

struct unk_func_88001300;
struct unk_func_88001300_000;
struct unk_func_88001300_03C;
struct unk_func_88203ED8;
struct unk_func_88203ED8_064;
struct unk_func_882025E0;

typedef s32 (*unk_func_88001300_018)(struct unk_func_88001300_000*, s32, s32);
typedef s32 (*unk_func_88001300_01C)(struct unk_func_88001300_000*);
typedef s32 (*unk_func_88001300_020)(struct unk_func_88001300*, Controller*);
typedef void (*unk_func_88001300_024)(struct unk_func_88001300_000*, s32);

typedef struct unk_func_88001300_000_000 {
    /* 0x00 */ char unk00[0x4];
    /* 0x04 */ struct unk_func_88001300_000_000* unk_04;
    /* 0x08 */ struct unk_func_88001300_000_000* unk_08;
} unk_func_88001300_000_000; // size >= 0xC

typedef struct unk_func_88001300_000_010 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
} unk_func_88001300_000_010; // size = 0x4

typedef struct unk_func_88001300_000 {
    /* 0x00 */ unk_func_88001300_000_000 unk_00;
    /* 0x0C */ char unk0C[0x4];
    /* 0x10 */ unk_func_88001300_000_010 unk_10;
    /* 0x14 */ unk_func_88001300_000_010 unk_14;
    /* 0x18 */ unk_func_88001300_018 unk_18;
    /* 0x1C */ unk_func_88001300_01C unk_1C;
    /* 0x20 */ unk_func_88001300_020 unk_20;
    /* 0x24 */ unk_func_88001300_024 unk_24;
    /* 0x28 */ u16 unk_28;
    /* 0x2A */ u16 unk_2A;
} unk_func_88001300_000; // size = 0x2C

typedef struct unk_func_88001300_02C {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ s32 unk_2C;
} unk_func_88001300_02C; // size = 0x30

typedef struct unk_func_88001300_030 {
    /* 0x00 */ unk_func_88001300_000_000 unk_00;
    /* 0x0C */ char unk0C[0x20];
    /* 0x2C */ Color_RGBA8_u32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ char unk38[0x4];
} unk_func_88001300_030; // size = 0x3C

typedef struct unk_func_88001300_038 {
    /* 0x00 */ u8* unk_00[1];
    /* 0x04 */ char unk04[0x8];
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ char unk10[0x4];
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s16 unk_16;
    /* 0x18 */ char unk18[0x10];
    /* 0x28 */ u16 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
} unk_func_88001300_038; // size = 0x34

typedef struct unk_func_88001300_034 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_88001300_038* unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ char unk34[0xC];
    /* 0x40 */ s32 unk_40;
} unk_func_88001300_034; // size = 0x44

typedef struct unk_func_88001300_03C_00C {
    /* 0x00 */ char unk00[0x10];
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s16 unk_16;
    /* 0x18 */ char unk18[0x14];
} unk_func_88001300_03C_00C; // size = 0x2C

typedef struct unk_func_88001300_03C_01C {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ Color_RGBA8 unk_2C;
    /* 0x30 */ s32 unk_30;
} unk_func_88001300_03C_01C; // size = 0x34

typedef s32 (*unk_func_88001300_03C_010)(struct unk_func_88001300_03C*, Controller*);
typedef void (*unk_func_88001300_03C_014)(struct unk_func_88001300_03C*, s32);

typedef struct unk_func_88001300_03C {
    /* 0x00 */ char unk00[0xC];
    /* 0x00 */ unk_func_88001300_03C_00C* unk_0C;
    /* 0x10 */ unk_func_88001300_03C_010 unk_10;
    /* 0x14 */ unk_func_88001300_03C_014 unk_14;
    /* 0x18 */ unk_func_88001300_000** unk_18;
    /* 0x1C */ unk_func_88001300_03C_01C* unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ char unk28[0x4];
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ char unk30[0x10];
} unk_func_88001300_03C; // size = 0x40

typedef struct unk_func_88001300 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_88001300_02C* unk_2C;
    /* 0x30 */ unk_func_88001300_030* unk_30;
    /* 0x34 */ unk_func_88001300_034* unk_34;
    /* 0x38 */ unk_func_88001300_038* unk_38;
    /* 0x3C */ unk_func_88001300_03C* unk_3C;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ char unk44[0xC];
    /* 0x50 */ s32 unk_50;
    /* 0x54 */ s32 unk_54;
} unk_func_88001300; // size = 0x58

typedef struct unk_func_88500E34 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ u8* unk_2C;
} unk_func_88500E34; // size = 0x30

typedef struct unk_func_88509A2C {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ char* unk_3C;
    /* 0x40 */ char unk_40[12];
} unk_func_88509A2C; // size = 0x4C

typedef struct unk_func_88500EE4 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ u8* unk_2C;
    /* 0x30 */ Color_RGBA8 unk_30;
    /* 0x34 */ Color_RGBA8 unk_34;
} unk_func_88500EE4; // size = 0x38

typedef struct unk_func_885088F4 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 unk_38;
} unk_func_885088F4; // size = 0x3C

typedef struct unk_func_88509E34 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ char* unk_2C;
    /* 0x30 */ char unk30[0x4];
} unk_func_88509E34; // size = 0x34

typedef struct unk_func_8850B254 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ Color_RGBA8 unk_2C;
    /* 0x30 */ Color_RGBA8 unk_30;
} unk_func_8850B254; // size = 0x34

typedef struct unk_func_8850878C {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ Color_RGBA8 unk_30;
    /* 0x34 */ Color_RGBA8 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ char* unk_40;
    /* 0x44 */ s32 unk_44;
} unk_func_8850878C; // size = 0x48

typedef struct unk_func_885012A4 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ Color_RGBA8 unk_2C;
} unk_func_885012A4; // size = 0x30

typedef struct unk_func_88503298 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_88001300_038* unk_2C;
    /* 0x30 */ unk_func_8850878C* unk_30;
} unk_func_88503298; // size = 0x34

typedef void (*unk_func_88200FA0_030_030_040)();

typedef struct unk_func_88200FA0_030_030 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_8820BE14_06C* unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ u16* unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s16 unk_3C;
    /* 0x3E */ s16 unk_3E;
    /* 0x40 */ unk_func_88200FA0_030_030_040 unk_40;
    /* 0x44 */ unk_func_88001300_03C_01C* unk_44;
    /* 0x48 */ s16 unk_48;
    /* 0x4A */ s16 unk_4A;
    /* 0x4C */ s16 unk_4C;
    /* 0x4E */ s16 unk_4E;
    /* 0x50 */ s16 unk_50;
    /* 0x52 */ s16 unk_52;
} unk_func_88200FA0_030_030; // size = 0x54

// Copy of above with unk_2C changed just for fragment23_1AE680
typedef struct unk_func_88200FA0_030_030_1AE680 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_88205880_A030* unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ u16* unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s16 unk_3C;
    /* 0x3E */ s16 unk_3E;
    /* 0x40 */ unk_func_88200FA0_030_030_040 unk_40;
    /* 0x44 */ unk_func_88001300_03C_01C* unk_44;
    /* 0x48 */ s16 unk_48;
    /* 0x4A */ s16 unk_4A;
    /* 0x4C */ s16 unk_4C;
    /* 0x4E */ s16 unk_4E;
    /* 0x50 */ s16 unk_50;
    /* 0x52 */ s16 unk_52;
} unk_func_88200FA0_030_030_1AE680; // size = 0x54

typedef struct unk_func_8850182C {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ Color_RGBA8 unk_2C;
} unk_func_8850182C; // size = 0x30

typedef struct unk_func_889000C4 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ void* unk_2C;
    /* 0x30 */ void* unk_30;
    /* 0x34 */ unk_func_88200FA0_030_038 unk_34;
    /* 0x40 */ void* unk_40;
    /* 0x44 */ s32 unk_44;
} unk_func_889000C4; // size = 0x48

typedef struct unk_func_88500994 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
} unk_func_88500994; // size = 0x34

typedef struct unk_func_8850143C {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ Color_RGBA8 unk_2C;
    /* 0x30 */ Color_RGBA8 unk_30;
} unk_func_8850143C; // size = 0x34

typedef struct unk_func_8820399C {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ unk_func_8850143C* unk_30;
} unk_func_8820399C; // size = 0x34

typedef struct unk_func_88509F48 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ void* unk_2C;
    /* 0x30 */ void* unk_30;
    /* 0x34 */ void* unk_34;
    /* 0x38 */ s32 unk_38;
} unk_func_88509F48; // size = 0x3C

typedef void (*unk_func_8850CD44_010)();
typedef void (*unk_func_8850CD44_014)();

typedef struct unk_func_882173EC {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ unk_func_88001300_000_010 unk_30;
    /* 0x34 */ unk_func_88001300_000_010 unk_34;
} unk_func_882173EC; // size = 0x38

typedef struct unk_func_8850CD44 {
    /* 0x00 */ char unk00[0x10];
    /* 0x10 */ unk_func_8850CD44_010 unk_10;
    /* 0x14 */ unk_func_8850CD44_014 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ unk_func_882173EC** unk_1C;
    /* 0x20 */ s32 unk_20;
} unk_func_8850CD44; // size = 0x24

typedef struct unk_func_882025E0_03C {
    /* 0x00 */ unk_func_8850878C* unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
} unk_func_882025E0_03C; // size = 0xC

typedef s32 (*unk_func_882025E0_010)(struct unk_func_882025E0* arg0, Controller* arg1);
typedef void (*unk_func_882025E0_014)(struct unk_func_882025E0* arg0, s32 arg1);

typedef struct unk_func_882025E0_024_02C {
    /* 0x00 */ unk_func_88205880_00D0* unk_00[2];
    /* 0x08 */ s32 unk_08;
} unk_func_882025E0_024_02C; // size >= 0xC

typedef struct unk_func_882025E0_024_02C_wrap {
    /* 0x00 */ unk_func_882025E0_024_02C* unk_00;
} unk_func_882025E0_024_02C_wrap; // size >= 0xC

typedef struct unk_func_882025E0_024 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_882025E0_024_02C_wrap* unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ u16* unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s16 unk_3C;
    /* 0x3E */ s16 unk_3E;
    /* 0x40 */ unk_func_88200FA0_030_030_040 unk_40;
    /* 0x44 */ unk_func_88001300_03C_01C* unk_44;
    /* 0x48 */ s16 unk_48;
    /* 0x4A */ s16 unk_4A;
    /* 0x4C */ s16 unk_4C;
    /* 0x4E */ s16 unk_4E;
    /* 0x50 */ s16 unk_50;
    /* 0x52 */ s16 unk_52;
} unk_func_882025E0_024; // size >= 0x54

typedef struct unk_func_882025E0 {
    /* 0x00 */ char unk00[0x10];
    /* 0x10 */ unk_func_882025E0_010 unk_10;
    /* 0x14 */ unk_func_882025E0_014 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ struct unk_func_88203ED8* unk_20;
    /* 0x24 */ unk_func_88200FA0_030_030* unk_24[2]; // unk_func_882025E0_024
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ unk_func_882025E0_03C unk_3C[5];
} unk_func_882025E0; // size = 0x78

// copy of the above for _1A9780
typedef struct unk_func_882025E0_1A9780 {
    /* 0x00 */ char unk00[0x10];
    /* 0x10 */ unk_func_882025E0_010 unk_10;
    /* 0x14 */ unk_func_882025E0_014 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ struct unk_func_88203ED8* unk_20;
    /* 0x24 */ unk_func_88200FA0_030_030_1AE680* unk_24[2];
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ unk_func_882025E0_03C unk_3C[5];
} unk_func_882025E0_1A9780; // size = 0x78


typedef s32 (*unk_func_88203ED8_064_010)(struct unk_func_88203ED8_064*, Controller*);
typedef void (*unk_func_88203ED8_064_014)(struct unk_func_88203ED8_064*);

typedef struct unk_func_88203ED8_064 {
    /* 0x00 */ char unk00[0x4];
    /* 0x04 */ struct unk_func_88203ED8_064* unk_04;
    /* 0x08 */ struct unk_func_88203ED8_064* unk_08;
    /* 0x0C */ char unk0C[0x4];
    /* 0x10 */ unk_func_88203ED8_064_010 unk_10;
    /* 0x14 */ unk_func_88203ED8_064_014 unk_14;
    /* 0x18 */ char unk18[0x4];
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ struct unk_func_88203ED8* unk_24;
} unk_func_88203ED8_064; // size = 0x28

typedef struct unk_func_88205880_0098_008 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ char unk2C[0x64];
} unk_func_88205880_0098_008; // size = 0x90

typedef struct unk_func_88205880_0098 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ MemoryPool* unk_04;
    /* 0x08 */ unk_func_88205880_0098_008* unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ char* unk_14;
    /* 0x18 */ char* unk_18;
    /* 0x1C */ char* unk_1C;
    /* 0x20 */ char* unk_20;
    /* 0x24 */ char* unk_24;
    /* 0x28 */ char* unk_28;
    /* 0x2C */ char* unk_2C;
    /* 0x30 */ char* unk_30;
    /* 0x34 */ char* unk_34;
} unk_func_88205880_0098; // size = 0x38

typedef struct unk_func_88201DA0 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_88001300_038* unk_2C;
    /* 0x30 */ unk_func_88200FA0_030_030* unk_30;
    /* 0x34 */ unk_func_88201DA0_034* unk_34;
    /* 0x38 */ unk_func_88201DA0_038 unk_38;
    /* 0x48 */ FragmentEntry unk_48;
    /* 0x4C */ unk_func_88205880_0098* unk_4C;
    /* 0x50 */ unk_func_8850878C* unk_50;
    /* 0x54 */ char* unk_54;
    /* 0x58 */ unk_func_8850182C* unk_58;
    /* 0x5C */ unk_func_88205880_00D0* unk_5C;
    /* 0x60 */ u32 unk_60;
} unk_func_88201DA0; // size = 0x64

typedef struct unk_func_8820253C {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_88205880_00D0* unk_2C;
} unk_func_8820253C; // size = 0x30

typedef struct unk_func_88217740 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
} unk_func_88217740; // size = 0x34

typedef struct unk_func_882149A0 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ u8* unk_2C;
    /* 0x30 */ s16 unk_30;
    /* 0x32 */ Color_RGBA8 unk_32;
    /* 0x36 */ Color_RGBA8 unk_36;
    /* 0x3A */ Color_RGBA8 unk_3A;
    /* 0x40 */ s32 unk_40;
} unk_func_882149A0; // size = 0x44

typedef struct unk_func_88203ED8 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_88001300_038* unk_2C;
    /* 0x2C */ unk_func_8820399C* unk_30;
    /* 0x2C */ unk_func_8820399C* unk_34;
    /* 0x2C */ unk_func_88200FA0_030_030* unk_38;
    /* 0x2C */ unk_func_88200FA0_030_030* unk_3C;
    /* 0x2C */ unk_func_88217740* unk_40;
    /* 0x44 */ unk_func_882149A0* unk_44[5];
    /* 0x58 */ unk_func_88500994* unk_58;
    /* 0x5C */ unk_func_88201DA0* unk_5C;
    /* 0x60 */ unk_func_88509F48* unk_60;
    /* 0x64 */ unk_func_88203ED8_064* unk_64;
    /* 0x68 */ unk_func_88001300_03C* unk_68;
    /* 0x6C */ unk_func_882025E0* unk_6C;
    /* 0x70 */ unk_func_8850CD44* unk_70;
    /* 0x74 */ unk_func_882173EC* unk_74[2];
    /* 0x7C */ unk_func_8820253C* unk_7C[2];
    /* 0x84 */ unk_func_889000C4* unk_84;
} unk_func_88203ED8; // size = 0x88

typedef struct unk_func_8820BE14_02C_038_084 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
} unk_func_8820BE14_02C_038_084; // size >= 0x18

typedef struct unk_func_8820BE14_02C_038 {
    /* 0x00 */ unk_func_88200FA0_030_030 unk_00; // unk_func_882025E0_024
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
} unk_func_8820BE14_02C_038; // size = 0x90

typedef struct unk_func_88507D4C {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_8820BE14_02C_038* unk_2C;
    /* 0x30 */ s32 unk_30;
} unk_func_88507D4C; // size = 0x34

typedef struct unk_func_8850BD40 {
    /* 0x00 */ unk_func_88001300_000_000 unk_00;
    /* 0x0C */ char unk0C[0x14];
} unk_func_8850BD40; // size = 0x20

typedef struct unk_func_8821421C_038_034 {
    /* 0x00 */ unk_func_88200FA0_030_030 unk_00;
    /* 0x54 */ char unk54[0x1C];
} unk_func_8821421C_038_034; // size = 0x70

typedef struct unk_func_8821421C_038_050 {
    /* 0x00 */ char unk00[0x8];
    /* 0x08 */ char unk_08[4];
    /* 0x0C */ char unk0C[0x8];
} unk_func_8821421C_038_050; // size = 0x14

typedef struct unk_func_8820E99C_030_044 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ char unk2C[0x4];
    /* 0x30 */ s32 unk_30;
} unk_func_8820E99C_030_044; // size = 0x34

typedef void (*func88500020)(unk_func_88500020*, s32, s32);
typedef void (*func88500668)(unk_func_882025E0*, s32);
typedef void (*func8850068C)(unk_func_88001300_000_000*, unk_func_88001300_000_000*);
typedef void (*func885007CC)(unk_func_88001300_000*, s32);
typedef void (*func88500828)(unk_func_88001300*, s32, s32);
typedef void (*func885008C4)(unk_func_88001300*);
typedef void (*func8850093C)(s32, s32);
typedef void (*func88500994)(unk_func_88500994*, s32, s32);
typedef void (*func88500A3C)(unk_func_88500994*, unk_func_8850878C*);
typedef void (*func88500A6C)(unk_func_88500994*, s32);
typedef void (*func88500E34)(unk_func_88500E34*, s32, s32, s32, s32, u8*);
typedef void (*func88500EE4)(unk_func_88500EE4*, s32, s32, s32, s32, u8*, Color_RGBA8, Color_RGBA8);
typedef void (*func885012A4)(unk_func_885012A4*, s32, s32, s32, s32, Color_RGBA8);
typedef void (*func8850143C)(unk_func_8850143C*, s32, s32, s32, s32, Color_RGBA8, Color_RGBA8);
typedef void (*func8850182C)(unk_func_8850182C*, s32, s32, s32, s32, Color_RGBA8);
typedef void (*func88502274)(unk_func_88001300_038*, s32, s32, s32, s32);
typedef void (*func88502C98)(unk_func_88001300_038*);
typedef void (*func88503118)(unk_func_88001300_02C*, s32, s32, s32, s32);
typedef void (*func885031E8)(unk_func_88001300_000*, s32, s32, s32, s32);
typedef void (*func88503298)(unk_func_88503298*, unk_func_88001300_038*, unk_func_88001300_000*);
typedef void (*func88503340)(unk_func_88001300_03C_01C*, s32, s32, s32, s32, Color_RGBA8);
typedef void (*func88504570)(unk_func_88001300_03C_01C*, s32, s32, s32, s32, Color_RGBA8);
typedef void (*func88504F98)(unk_func_8820E99C_030_044*, s32, s32, s32, s32);
typedef void (*func885054D8)(unk_func_88001300_030*, s32, s32, s32, s32, Color_RGBA8);
typedef void (*func88505E2C)(unk_func_88001300_034*, s32, s32, s32, s32, s32, Color_RGBA8, unk_D_800AC870*);
typedef void (*func88506074)(unk_func_88001300_034*, char*);
typedef void (*func885060BC)(unk_func_88200FA0_030_030*, s32, s32, unk_func_88200FA0_030_030_040, s32, s32, s32, s32, MemoryPool*);
typedef void (*func88506238)(unk_func_88200FA0_030_030*, s32, MemoryPool*);
typedef void (*func8850628C)(unk_func_88200FA0_030_030*);
typedef void (*func88506384)(unk_func_88200FA0_030_030*, unk_func_88200FA0_030_038*, MemoryPool*);
typedef void (*func885063B8)(unk_func_88200FA0_030_030*, unk_func_88201DA0_038*);
typedef void (*func88506404)(unk_func_88200FA0_030_030*, u8*, MemoryPool*);
typedef void (*func88506BFC)(unk_func_88200FA0_030_030*, s32);
typedef void (*func88506CE4)(unk_func_88200FA0_030_030*);
typedef void (*func88506DCC)(unk_func_8821421C_038_034*, s32, s32, void (*)(), s32, s32, s32, MemoryPool*);
typedef void (*func88506EE4)(unk_func_8820BE14_02C_038*, unk_func_88200FA0_030_038*);
typedef void (*func88506F50)(unk_func_8821421C_038_034*, unk_func_8821421C_038_050**);
typedef void (*func88506FC0)(unk_func_8820BE14_02C_038*);
typedef void (*func88506FE0)(unk_func_8820BE14_02C_038*);
typedef void (*func88507AE4)(unk_func_8820BE14_02C_038*, s32);
typedef void (*func88507B80)(unk_func_8820BE14_02C_038*, s32);
typedef void (*func88507CC4)(unk_func_8820BE14_02C_038*, unk_func_88205880_00D0*);
typedef void (*func88507CEC)(unk_func_8820BE14_02C_038*);
typedef void (*func88507D4C)(unk_func_88507D4C*, s32, s32, s32, s32, unk_func_8820BE14_02C_038*);
typedef void (*func8850878C)(unk_func_8850878C*, s32, s32, char*, s32);
typedef void (*func885088F4)(unk_func_885088F4*, s32, s32, s32);
typedef void (*func88509A2C)(unk_func_88509A2C*, s32, s32, s32, char*);
typedef void (*func88509E34)(unk_func_88509E34*, s32, s32, char*);
typedef void (*func88509F48)(unk_func_88509F48*, s32, s32, s32, s32, MemoryPool*, s32);
typedef void (*func8850A10C)(unk_func_88509F48*, unk_func_8850878C*, s32, s32);
typedef void (*func8850A3CC)(unk_func_88509F48*, Controller*);
typedef void (*func8850A3EC)(unk_func_88509F48*, Controller*);
typedef void (*func8850A40C)(unk_func_88001300_000*, s32, s32, s32, s32);
typedef void (*func8850AB48)(unk_func_88001300_000*, s32, s32, s32, s32);
typedef void (*func8850B254)(unk_func_8850B254*, s32, s32, s32, s32, Color_RGBA8, Color_RGBA8);
typedef void (*func8850BC94)(s32);
typedef void (*func8850BD40)(unk_func_8850BD40*, unk_func_8821421C_038_034*);
typedef void (*func8850BDF0)(unk_func_88203ED8_064* arg0);
typedef void (*func8850BF60)(unk_func_88001300_000*, s32);
typedef void (*func8850BF80)(unk_func_88001300_000*, unk_func_88001300_000*);
typedef void (*func8850BFB0)(unk_func_88203ED8_064*);
typedef void (*func8850C064)(unk_func_88203ED8_064*, s32);
typedef void (*func8850C284)(unk_func_88001300_03C*, s32, s32, MemoryPool*);
typedef void (*func8850CAB4)(unk_func_88001300_03C*);
typedef void (*func8850CB48)(unk_func_88001300_03C*, s32);
typedef void (*func8850CC74)(unk_func_88001300_000*, unk_func_88001300_000*);
typedef void (*func8850CD44)(unk_func_8850CD44*, s32, MemoryPool*);
typedef void (*func8850CF00)(unk_func_8850CD44*, s32);


void func_88500020(unk_func_88500020*, s32, s32);
void func_88500668(unk_func_882025E0*, s32);
void func_8850068C(unk_func_88001300_000_000*, unk_func_88001300_000_000*);
void func_885007CC(unk_func_88001300_000*, s32);
void func_88500828(unk_func_88001300_000*, s32, s32);
void func_885008C4(unk_func_88001300_000*);
void func_8850093C(s32, s32);
void func_88500994(unk_func_88500994*, s32, s32);
void func_88500A3C(unk_func_88500994*, unk_func_8850878C*);
void func_88500A6C(unk_func_88500994*, s32);
void func_88500E34(unk_func_88500E34*, s32, s32, s32, s32, u8*);
void func_88500EE4(unk_func_88500EE4*, s32, s32, s32, s32, u8*, Color_RGBA8, Color_RGBA8);
void func_885012A4(unk_func_885012A4*, s32, s32, s32, s32, Color_RGBA8);
void func_8850143C(unk_func_8850143C*, s32, s32, s32, s32, Color_RGBA8, Color_RGBA8);
void func_8850182C(unk_func_8850182C*, s32, s32, s32, s32, Color_RGBA8);
void func_88502274(unk_func_88001300_038*, s32, s32, s32, s32);
void func_88502C98(unk_func_88001300_038*);
void func_88503118(unk_func_88001300_02C*, s32, s32, s32, s32);
void func_885031E8(unk_func_88001300_000*, s32, s32, s32, s32);
void func_88503298(unk_func_88503298*, unk_func_88001300_038*, unk_func_88001300_000*);
void func_88503340(unk_func_88001300_03C_01C*, s32, s32, s32, s32, Color_RGBA8);
void func_88504570(unk_func_88001300_03C_01C*, s32, s32, s32, s32, Color_RGBA8);
void func_88504F98(unk_func_8820E99C_030_044*, s32, s32, s32, s32);
void func_885054D8(unk_func_88001300_030*, s32, s32, s32, s32, Color_RGBA8);
void func_88505E2C(unk_func_88001300_034*, s32, s32, s32, s32, s32, Color_RGBA8, unk_D_800AC870*);
void func_88506074(unk_func_88001300_034* arg0, char* arg1);
void func_885060BC(unk_func_88200FA0_030_030*, s32, s32, unk_func_88200FA0_030_030_040, s32, s32, s32, s32, MemoryPool*);
void func_88506238(unk_func_88200FA0_030_030*, s32, MemoryPool*);
void func_8850628C(unk_func_88200FA0_030_030*);
void func_88506384(unk_func_88200FA0_030_030*, unk_func_88200FA0_030_038*, MemoryPool*);
void func_885063B8(unk_func_88200FA0_030_030*, unk_func_88201DA0_038*);
void func_88506404(unk_func_88200FA0_030_030*, u8*, MemoryPool*);
void func_88506BFC(unk_func_88200FA0_030_030*, s32);
void func_88506CE4(unk_func_88200FA0_030_030*);
void func_88506DCC(unk_func_8821421C_038_034*, s32, s32, void (*)(), s32, s32, s32, MemoryPool*);
void func_88506EE4(unk_func_8820BE14_02C_038*, unk_func_88200FA0_030_038*);
void func_88506F50(unk_func_8821421C_038_034*, unk_func_8821421C_038_050**);
void func_88506FC0(unk_func_8820BE14_02C_038*);
void func_88506FE0(unk_func_8820BE14_02C_038*);
void func_88507AE4(unk_func_8820BE14_02C_038*, s32);
void func_88507B80(unk_func_8820BE14_02C_038*, s32);
void func_88507CC4(unk_func_8820BE14_02C_038*, unk_func_88205880_00D0*);
void func_88507CEC(unk_func_8820BE14_02C_038*);
void func_88507D4C(unk_func_88507D4C*, s32, s32, s32, s32, unk_func_8820BE14_02C_038*);
void func_8850878C(unk_func_8850878C*, s32, s32, char*, s32);
void func_885088F4(unk_func_885088F4*, s32, s32, s32);
void func_88509A2C(unk_func_88509A2C*, s32, s32, s32, char*);
void func_88509E34(unk_func_88509E34*, s32, s32, char*);
void func_88509F48(unk_func_88509F48*, s32, s32, s32, s32, MemoryPool*, s32);
void func_8850A10C(unk_func_88509F48*, unk_func_8850878C*, s32, s32);
void func_8850A3CC(unk_func_88509F48*, Controller*);
void func_8850A3EC(unk_func_88509F48*, Controller*);
void func_8850A40C(unk_func_88001300_000*, s32, s32, s32, s32);
void func_8850AB48(unk_func_88001300_000*, s32, s32, s32, s32);
void func_8850B254(unk_func_8850B254*, s32, s32, s32, s32, Color_RGBA8, Color_RGBA8);
void func_8850BC94(s32);
void func_8850BD40(unk_func_8850BD40*, unk_func_8821421C_038_034*);
void func_8850BDF0(unk_func_88203ED8_064* arg0);
void func_8850BF60(unk_func_88001300_000*, s32);
void func_8850BF80(unk_func_88001300_000*, unk_func_88001300_000_000*);
void func_8850BFB0(unk_func_88203ED8_064*);
void func_8850C064(unk_func_88203ED8_064*, s32);
void func_8850C284(unk_func_88001300_03C*, s32, s32, MemoryPool*);
void func_8850CAB4(unk_func_88001300_03C*);
void func_8850CB48(unk_func_88001300_03C*, s32, s32);
void func_8850CC74(unk_func_88001300_000*, unk_func_88001300_000*);
void func_8850CD44(unk_func_8850CD44*, s32, MemoryPool*);
void func_8850CF00(unk_func_8850CD44*, s32);

#endif // _FRAGMENT26_H_
