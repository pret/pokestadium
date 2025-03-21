#ifndef _FRAGMENT26_H_
#define _FRAGMENT26_H_

#include "global.h"
#include "src/memory.h"
#include "src/memmap.h"
#include "src/controller.h"
#include "src/29BA0.h"
#include "src/1AB70.h"
#include "src/2D340.h"
#include "src/fragments/25/fragment25.h"

struct unk_func_88001300;
struct unk_func_88001300_000;
struct unk_func_88001300_000_000;
struct unk_func_88001300_03C;
struct unk_func_88203ED8;
struct unk_func_88203ED8_064;
struct unk_func_882025E0;
struct unk_func_8850CD44;
struct unk_func_8830867C_02C_048_000;
struct unk_func_8850BD40;
struct unk_func_88200FA0_030_030;

typedef s32 (*unk_func_88001300_018)(struct unk_func_88001300_000*, s32, s32);
typedef s32 (*unk_func_88001300_01C)(struct unk_func_88001300_000*);
typedef s32 (*unk_func_88001300_020)(struct unk_func_88001300_000*, Controller*);
typedef void (*unk_func_88001300_024)(struct unk_func_88001300_000*, s32);
typedef void (*unk_func_88001300_000_000_0C)(struct unk_func_88001300_000_000*, MemoryPool*);

typedef struct unk_func_88001300_000_000 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ struct unk_func_88001300_000_000* unk_04;
    /* 0x08 */ struct unk_func_88001300_000_000* unk_08;
    /* 0x0C */ unk_func_88001300_000_000_0C unk_0C;
} unk_func_88001300_000_000; // size = 0x10

typedef struct unk_func_88001300_000_010 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
} unk_func_88001300_000_010; // size = 0x4

typedef struct unk_func_88001300_000 {
    /* 0x00 */ unk_func_88001300_000_000 unk_00;
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
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ Color_RGBA8 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ char unk38[0x4];
} unk_func_88001300_030; // size = 0x3C

typedef struct unk_func_88001300_038 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
} unk_func_88001300_038; // size = 0x34

typedef struct unk_func_88001300_034 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_88001300_038* unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ u8 unk_34;
    /* 0x35 */ s8 unk_35;
    /* 0x36 */ u8 unk_36;
    /* 0x38 */ Color_RGBA8 unk_38;
    /* 0x3C */ unk_D_800AC870* unk_3C;
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
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s16 unk_34;
    /* 0x36 */ s16 unk_36;
    /* 0x38 */ s16 unk_38;
    /* 0x3A */ s16 unk_3A;
    /* 0x3C */ s16 unk_3C;
    /* 0x3E */ s16 unk_3E;
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
    /* 0x40 */ s8 unk_40[12];
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

typedef struct unk_func_88509F0C {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ char* unk_2C;
} unk_func_88509F0C; // size = 0x30

typedef struct unk_func_88509E34 {
    /* 0x00 */ unk_func_88509F0C unk_00;
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

typedef void (*unk_func_88200FA0_030_030_040)(s32, s32, char*, s32, s32, struct unk_func_88200FA0_030_030*);

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

// Copy of above with unk_2C changed just for fragment24_1CEA00
typedef struct unk_func_88200FA0_030_030_1CEA00 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_8830867C_02C_0CC* unk_2C;
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
} unk_func_88200FA0_030_030_1CEA00; // size = 0x54

typedef struct unk_func_8850182C {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ Color_RGBA8 unk_2C;
} unk_func_8850182C; // size = 0x30

typedef struct unk_func_889000C4_02C {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
} unk_func_889000C4_02C; // size = 0x34

typedef struct unk_func_889000C4_044_02C {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ char unk30[0x4];
} unk_func_889000C4_044_02C; // size = 0x34

typedef struct unk_func_88500994 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
} unk_func_88500994; // size = 0x34

typedef struct unk_func_889000C4_044 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_889000C4_044_02C* unk_2C;
    /* 0x30 */ unk_func_88500994* unk_30;
    /* 0x34 */ unk_func_8850878C* unk_34;
    /* 0x38 */ unk_func_8850878C* unk_38;
} unk_func_889000C4_044; // size = 0x3C

typedef struct unk_func_889000C4 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_889000C4_02C* unk_2C;
    /* 0x30 */ unk_func_88200FA0_030_030* unk_30;
    /* 0x34 */ unk_func_88200FA0_030_038 unk_34;
    /* 0x40 */ unk_func_88500994* unk_40;
    /* 0x44 */ unk_func_889000C4_044* unk_44;
} unk_func_889000C4; // size = 0x48

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
    /* 0x2C */ unk_func_88001300_038* unk_2C;
    /* 0x30 */ unk_func_885012A4* unk_30;
    /* 0x34 */ unk_func_8850878C* unk_34;
    /* 0x38 */ unk_D_800AC870* unk_38;
} unk_func_88509F48; // size = 0x3C

typedef s32 (*unk_func_8850CD44_010)(struct unk_func_8850CD44* arg0, Controller* arg1);
typedef void (*unk_func_8850CD44_014)(struct unk_func_8850CD44* arg0, s32 arg1);

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

typedef struct unk_func_882025E0_000 {
    /* 0x00 */ unk_func_88001300_000_000 unk_00;
    /* 0x10 */ unk_func_882025E0_010 unk_10;
    /* 0x14 */ unk_func_882025E0_014 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ struct unk_func_88203ED8* unk_20;
} unk_func_882025E0_000; // size = 0x24

typedef struct unk_func_882025E0 {
    /* 0x00 */ unk_func_882025E0_000 unk_00;
    /* 0x24 */ unk_func_88200FA0_030_030* unk_24[2]; // unk_func_882025E0_024
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ unk_func_882025E0_03C unk_3C[5];
} unk_func_882025E0; // size = 0x78

typedef struct unk_func_882025E0_1A9780 {
    /* 0x00 */ unk_func_882025E0_000 unk_00;
    /* 0x24 */ unk_func_88200FA0_030_030_1AE680* unk_24[2];
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ unk_func_882025E0_03C unk_3C[5];
} unk_func_882025E0_1A9780; // size = 0x78

typedef struct unk_func_88205880_0098_008_040_02C {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ s32 unk_2C;
} unk_func_88205880_0098_008_040_02C; // size = 0x30

typedef struct unk_func_88205880_0098_008_040_03C {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ s32 unk_2C;
} unk_func_88205880_0098_008_040_03C; // size = 0x30

typedef struct unk_func_88205880_0098_008_040_05C {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
} unk_func_88205880_0098_008_040_05C; // size = 0x34

typedef struct unk_func_88205880_0098_008_040_06C {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ unk_func_88001300_000_010 unk_30;
    /* 0x34 */ unk_func_88001300_000_010 unk_34;
} unk_func_88205880_0098_008_040_06C; // size = 0x38

typedef struct unk_func_88205880_0098_008_040 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_88205880_0098_008_040_02C* unk_2C[4];
    /* 0x3C */ unk_func_88205880_0098_008_040_03C* unk_3C[4];
    /* 0x4C */ unk_func_88205880_0098_008_040_06C* unk_4C[4];
    /* 0x5C */ unk_func_88205880_0098_008_040_05C* unk_5C[4];
    /* 0x6C */ unk_func_88205880_0098_008_040_06C* unk_6C[4];
    /* 0x7C */ unk_func_885012A4* unk_7C[4];
} unk_func_88205880_0098_008_040; // size = 0x8C

typedef struct unk_func_88205880_0098_008_044 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_80026268_arg0* unk_2C;
} unk_func_88205880_0098_008_044; // size = 0x30

typedef struct unk_func_88205880_0098_008_048 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_80026268_arg0* unk_2C;
} unk_func_88205880_0098_008_048; // size = 0x30

typedef struct unk_func_88205880_0098_008_04C {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_80026268_arg0* unk_2C;
} unk_func_88205880_0098_008_04C; // size = 0x30

typedef struct unk_func_88205880_0098_008_050 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ unk_func_80026268_arg0* unk_30;
    /* 0x34 */ unk_func_8001B1FC* unk_34;
} unk_func_88205880_0098_008_050; // size = 0x38

typedef struct unk_func_88205880_0098_008_054 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_80026268_arg0* unk_2C;
} unk_func_88205880_0098_008_054; // size = 0x30

typedef struct unk_func_88205880_0098_008_058 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ s32 unk_2C;
} unk_func_88205880_0098_008_058; // size = 0x30

typedef struct unk_func_88205880_0098_008_070 {
    /* 0x00 */ unk_func_88001300_03C unk_00;
    /* 0x40 */ s32 unk_40;
} unk_func_88205880_0098_008_070; // size = 0x44

typedef struct unk_func_88205880_0098_008 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_88001300_038* unk_2C;
    /* 0x30 */ unk_func_88001300_02C* unk_30;
    /* 0x34 */ unk_func_88001300_02C* unk_34;
    /* 0x38 */ unk_func_88001300_02C* unk_38;
    /* 0x3C */ unk_func_88001300_02C* unk_3C;
    /* 0x40 */ unk_func_88205880_0098_008_040* unk_40;
    /* 0x44 */ unk_func_88205880_0098_008_044* unk_44;
    /* 0x48 */ unk_func_88205880_0098_008_048* unk_48;
    /* 0x4C */ unk_func_88205880_0098_008_04C* unk_4C;
    /* 0x50 */ unk_func_88205880_0098_008_050* unk_50;
    /* 0x54 */ unk_func_88205880_0098_008_054* unk_54;
    /* 0x58 */ unk_func_88205880_0098_008_058* unk_58;
    /* 0x5C */ unk_func_88500994* unk_5C;
    /* 0x60 */ unk_func_88500994* unk_60;
    /* 0x64 */ unk_func_88500994* unk_64;
    /* 0x68 */ unk_func_8850182C* unk_68;
    /* 0x6C */ unk_func_88001300_03C* unk_6C;
    /* 0x70 */ unk_func_88205880_0098_008_070* unk_70;
    /* 0x74 */ unk_func_8850CD44* unk_74;
    /* 0x78 */ unk_func_80026268_arg0* unk_78;
    /* 0x7C */ s32 unk_7C;
    /* 0x80 */ s32 unk_80;
    /* 0x84 */ s32 unk_84;
    /* 0x88 */ s32 unk_88;
    /* 0x8C */ s32 unk_8C;
} unk_func_88205880_0098_008; // size = 0x90

typedef struct unk_func_88205880_0098 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ MemoryPool* unk_04;
    /* 0x08 */ unk_func_88205880_0098_008* unk_08;
    /* 0x0C */ unk_func_80026268_arg0* unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ unk_func_88001300_000* unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ char** unk_1C;
    /* 0x20 */ char** unk_20;
    /* 0x24 */ char** unk_24;
    /* 0x28 */ char** unk_28;
    /* 0x2C */ char** unk_2C;
    /* 0x30 */ char** unk_30;
    /* 0x34 */ char** unk_34;
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

typedef s32 (*unk_func_8830867C_02C_048_000_010)(struct unk_func_8830867C_02C_048_000*, Controller*);
typedef void (*unk_func_8830867C_02C_048_000_014)(struct unk_func_8830867C_02C_048_000*, s32);

typedef struct unk_func_8830867C_02C_048_000 {
    /* 0x00 */ unk_func_88001300_000_000 unk_00;
    /* 0x10 */ unk_func_8830867C_02C_048_000_010 unk_10;
    /* 0x14 */ unk_func_8830867C_02C_048_000_014 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
} unk_func_8830867C_02C_048_000; // size = 0x24

typedef struct unk_func_88203ED8_064 {
    /* 0x00 */ unk_func_8830867C_02C_048_000 unk_00;
    /* 0x24 */ struct unk_func_88203ED8* unk_24;
} unk_func_88203ED8_064; // size = 0x28

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

typedef struct unk_func_8821421C_038_034 {
    /* 0x00 */ unk_func_88200FA0_030_030 unk_00;
    /* 0x54 */ u16 unk_54;
    /* 0x56 */ u16 unk_56;
    /* 0x58 */ s32 unk_58;
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ s32 unk_60;
    /* 0x64 */ s32 unk_64;
    /* 0x68 */ s32 unk_68;
    /* 0x6C */ s32 unk_6C;
} unk_func_8821421C_038_034; // size = 0x70

typedef s32 (*unk_func_8850BD40_010)(struct unk_func_8850BD40*);
typedef void (*unk_func_8850BD40_014)(struct unk_func_8850BD40*);

typedef struct unk_func_8850BD40 {
    /* 0x00 */ unk_func_88001300_000_000 unk_00;
    /* 0x10 */ unk_func_8850BD40_010 unk_10;
    /* 0x14 */ unk_func_8850BD40_014 unk_14;
    /* 0x18 */ char unk18[0x4];
    /* 0x1C */ unk_func_8821421C_038_034* unk_1C;
} unk_func_8850BD40; // size = 0x20

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

struct unk_func_8830867C_02C;

typedef struct unk_func_8830867C_02C_034 {
    /* 0x00 */ unk_func_88200FA0_030_030_1CEA00 unk_00;
    /* 0x54 */ s16 unk_54;
    /* 0x58 */ s32 unk_58;
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ char unk60[0xC];
    /* 0x6C */ s32 unk_6C;
    /* 0x70 */ struct unk_func_8830867C_02C* unk_70;
} unk_func_8830867C_02C_034; // size = 0x74

typedef struct unk_func_8830867C_02C_048 {
    /* 0x00 */ unk_func_8830867C_02C_048_000 unk_00;
    /* 0x24 */ struct unk_func_8830867C_02C* unk_24;
} unk_func_8830867C_02C_048; // size = 0x28

typedef struct unk_func_8830867C_034_038 {
    /* 0x00 */ unk_func_8830867C_02C_048_000 unk_00;
    /* 0x24 */ struct unk_func_8830867C_034* unk_24;
} unk_func_8830867C_034_038; // size = 0x28

typedef struct unk_func_8830867C_044_040 {
    /* 0x00 */ unk_func_8830867C_02C_048_000 unk_00;
    /* 0x24 */ struct unk_func_8830867C_044* unk_24;
} unk_func_8830867C_044_040; // size = 0x28

typedef struct unk_func_8830867C_03C_058 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ unk_D_88400138* unk_04;
} unk_func_8830867C_03C_058; // size = 0x8

typedef struct unk_func_8830867C_03C_0D0 {
    /* 0x00 */ unk_func_8830867C_03C_058** unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
} unk_func_8830867C_03C_0D0; // size = 0x10

typedef struct unk_func_8830867C_03C_04C {
    /* 0x00 */ unk_func_8830867C_02C_048_000 unk_00;
    /* 0x24 */ struct unk_func_8830867C_03C* unk_24;
} unk_func_8830867C_03C_04C; // size = 0x28

typedef struct unk_func_8830867C_040_05C {
    /* 0x00 */ unk_func_8830867C_02C_048_000 unk_00;
    /* 0x24 */ struct unk_func_8830867C_040* unk_24;
} unk_func_8830867C_040_05C; // size = 0x28

typedef struct unk_func_8830867C_04C_080 {
    /* 0x00 */ unk_func_8830867C_02C_048_000 unk_00;
    /* 0x24 */ struct unk_func_8830867C_04C* unk_24;
} unk_func_8830867C_04C_080; // size = 0x28

typedef struct unk_func_8830867C_048_048 {
    /* 0x00 */ unk_func_8830867C_02C_048_000 unk_00;
    /* 0x24 */ struct unk_func_8830867C_048* unk_24;
} unk_func_8830867C_048_048; // size = 0x28

typedef void (*func88500020)(unk_func_88500020*, s32, s32);
typedef void (*func88500338)(unk_func_88500020* arg0, s32 arg1, s32 arg2, s32 arg3);
typedef void (*func88500668)(unk_func_882025E0*, s32);
typedef void (*func8850068C)(unk_func_88001300_000_000*, unk_func_88001300_000_000*);
typedef void (*func885007CC)(unk_func_88001300_000*, s32);
typedef void (*func88500828)(unk_func_88001300_000*, s32, s32);
typedef void (*func885008C4)(unk_func_88001300_000*);
typedef void (*func8850093C)(s32, s32);
typedef void (*func88500994)(unk_func_88500994*, s32, s32);
typedef void (*func88500A3C)(unk_func_88500994*, unk_func_88001300_000*);
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
typedef void (*func88503BAC)(unk_func_88001300_03C_01C*, s32, s32, s32, s32, Color_RGBA8);
typedef void (*func88504570)(unk_func_88001300_03C_01C*, s32, s32, s32, s32, Color_RGBA8);
typedef void (*func88504F98)(unk_func_8820E99C_030_044*, s32, s32, s32, s32);
typedef void (*func885054D8)(unk_func_88001300_030*, s32, s32, s32, s32, Color_RGBA8);
typedef void (*func88505E2C)(unk_func_88001300_034*, s32, s32, s32, s32, s32, Color_RGBA8, unk_D_800AC870*);
typedef void (*func88506074)(unk_func_88001300_034*, char*);
typedef void (*func885060BC)(unk_func_88200FA0_030_030*, s32, s32, unk_func_88200FA0_030_030_040, s32, s32, s32, s32, MemoryPool*);
typedef void (*func88506238)(unk_func_88200FA0_030_030*, s32, MemoryPool*);
typedef void (*func8850628C)(unk_func_88200FA0_030_030*);
typedef void (*func8850633C)(unk_func_88200FA0_030_030_1CEA00*, unk_func_8830867C_02C_0CC*);
typedef void (*func88506384)(unk_func_88200FA0_030_030*, unk_func_88200FA0_030_038*, MemoryPool*);
typedef void (*func885063B8)(unk_func_88200FA0_030_030*, unk_func_88201DA0_038*);
typedef void (*func88506404)(unk_func_88200FA0_030_030*, u8*, MemoryPool*);
typedef void (*func88506BFC)(unk_func_88200FA0_030_030*, s32);
typedef void (*func88506CE4)(unk_func_88200FA0_030_030*);
typedef void (*func88506DCC)(unk_func_8821421C_038_034*, s32, s32, void (*)(), s32, s32, s32, MemoryPool*);
typedef void (*func88506EE4)(unk_func_8820BE14_02C_038*, unk_func_88200FA0_030_038*);
typedef void (*func88506F1C)(unk_func_8830867C_02C_034*, unk_func_88200FA0_030_038*, MemoryPool*);
typedef void (*func88506F50)(unk_func_8821421C_038_034*, unk_func_8821421C_038_050**);
typedef void (*func88506F8C)(unk_func_8821421C_038_034*, unk_func_8830867C_03C_0D0*, MemoryPool*);
typedef void (*func88506FC0)(unk_func_8820BE14_02C_038*);
typedef void (*func88506FE0)(unk_func_8820BE14_02C_038*);
typedef void (*func88507AE4)(unk_func_8820BE14_02C_038*, s32);
typedef void (*func88507B80)(unk_func_8820BE14_02C_038*, s32);
typedef void (*func88507C0C)(unk_func_8830867C_02C_034*, s32, s32);
typedef void (*func88507CC4)(unk_func_8820BE14_02C_038*, unk_func_88205880_00D0*);
typedef void (*func88507CEC)(unk_func_8820BE14_02C_038*);
typedef void (*func88507D4C)(unk_func_88507D4C*, s32, s32, s32, s32, unk_func_8820BE14_02C_038*);
typedef void (*func8850878C)(unk_func_8850878C*, s32, s32, char*, s32);
typedef void (*func885088F4)(unk_func_885088F4*, s32, s32, s32);
typedef void (*func88509A2C)(unk_func_88509A2C*, s32, s32, s32, char*);
typedef void (*func88509E34)(unk_func_88509F0C*, s32, s32, char*);
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
typedef void (*func8850CBA8)(unk_func_8830867C_02C_048*);
typedef void (*func8850CC74)(unk_func_88001300_000*, unk_func_88001300_000*);
typedef void (*func8850CD24)(unk_func_8830867C_02C_048*, s32);
typedef void (*func8850CD44)(unk_func_8850CD44*, s32, MemoryPool*);
typedef void (*func8850CF00)(unk_func_8850CD44*, Controller*);

void func_88500020(unk_func_88500020*, s32, s32);
void func_88500338(unk_func_88500020* arg0, s32 arg1, s32 arg2, s32 arg3);
void func_88500668(unk_func_88001300_000_000*, s32);
void func_8850068C(unk_func_88001300_000_000*, unk_func_88001300_000_000*);
void func_885007CC(unk_func_88001300_000*, s32);
void func_88500828(unk_func_88001300_000*, s32, s32);
void func_885008C4(unk_func_88001300_000*);
void func_8850093C(unk_func_88001300_000*, s32);
void func_88500994(unk_func_88500994*, s32, s32);
s32 func_885009E8(unk_func_88500994*, s32, s32);
void func_88500A3C(unk_func_88500994*, unk_func_88001300_000*);
void func_88500A6C(unk_func_88500994*, s32);
void func_88500E34(unk_func_88500E34*, s32, s32, s32, s32, u8*);
s32 func_88500E9C(unk_func_88500E34*, s32, s32);
void func_88500EE4(unk_func_88500EE4*, s32, s32, s32, s32, u8*, Color_RGBA8, Color_RGBA8);
s32 func_88500F6C(unk_func_88500EE4*, s32, s32);
void func_885012A4(unk_func_885012A4*, s32, s32, s32, s32, Color_RGBA8);
s32 func_88501314(unk_func_885012A4*, s32, s32);
void func_8850143C(unk_func_8850143C*, s32, s32, s32, s32, Color_RGBA8, Color_RGBA8);
s32 func_885014BC(unk_func_8850143C*, s32, s32);
void func_8850182C(unk_func_8850182C*, s32, s32, s32, s32, Color_RGBA8);
s32 func_8850189C(unk_func_8850182C*, s32, s32);
void func_88502274(unk_func_88001300_038*, s32, s32, s32, s32);
s32 func_8850230C(unk_func_88001300_038*);
s32 func_885023F4(unk_func_88001300_038*, s32, s32);
s32 func_88502C24(unk_func_88001300_038*, Controller*);
void func_88502C98(unk_func_88001300_038*);
s32 func_88502D60(unk_func_88001300_000*, s32, s32);
void func_88503118(unk_func_88001300_02C*, s32, s32, s32, s32);
s32 func_8850318C(unk_func_88001300_02C*, s32, s32);
s32 func_885031B8(unk_func_88001300_02C*);
void func_885031E8(unk_func_88001300_000*, s32, s32, s32, s32);
s32 func_88503254(unk_func_88001300_000*);
s32 func_88503268(unk_func_88001300_000*, s32, s32);
void func_88503298(unk_func_88503298*, unk_func_88001300_038*, unk_func_88001300_000*);
s32 func_885032E4(unk_func_88503298*);
void func_88503340(unk_func_88001300_03C_01C*, s32, s32, s32, s32, Color_RGBA8);
s32 func_885033CC(unk_func_88001300_03C_01C*);
s32 func_885033E8(unk_func_88001300_03C_01C*, s32, s32);
void func_88503BA0(unk_func_88001300_03C_01C*, s32);
void func_88503BAC(unk_func_88001300_03C_01C*, s32, s32, s32, s32, Color_RGBA8);
s32 func_88503C38(unk_func_88001300_03C_01C*);
s32 func_88503C54(unk_func_88001300_03C_01C*, s32, s32);
void func_88504564(unk_func_88001300_03C_01C*, s32);
void func_88504570(unk_func_88001300_03C_01C*, s32, s32, s32, s32, Color_RGBA8);
s32 func_885045FC(unk_func_88001300_03C_01C*);
s32 func_88504618(unk_func_88001300_03C_01C*, s32, s32);
void func_88504F8C(unk_func_88001300_03C_01C*, s32);
void func_88504F98(unk_func_8820E99C_030_044*, s32, s32, s32, s32);
s32 func_88505014(unk_func_8820E99C_030_044*);
s32 func_88505030(unk_func_8820E99C_030_044*, s32, s32);
void func_885054CC(unk_func_8820E99C_030_044*, s32);
void func_885054D8(unk_func_88001300_030*, s32, s32, s32, s32, Color_RGBA8);
s32 func_8850555C(unk_func_88001300_030*);
s32 func_8850562C(unk_func_88001300_030*, s32, s32);
void func_88505E2C(unk_func_88001300_034*, s32, s32, s32, s32, s32, Color_RGBA8, unk_D_800AC870*);
s32 func_88505EC0(unk_func_88001300_034*);
s32 func_88505EF4(unk_func_88001300_034*, s32, s32);
void func_88506074(unk_func_88001300_034* arg0, u8* arg1);
void func_885060BC(unk_func_88200FA0_030_030*, s32, s32, unk_func_88200FA0_030_030_040, s32, s32, s32, s32, MemoryPool*);
void func_88506238(unk_func_88200FA0_030_030*, s32, MemoryPool*);
void func_8850628C(unk_func_88200FA0_030_030*);
void func_885062D4(unk_func_88200FA0_030_030*, s32);
void func_8850633C(unk_func_88200FA0_030_030_1CEA00*, unk_func_8830867C_02C_0CC*);
void func_88506384(unk_func_88200FA0_030_030*, unk_func_88200FA0_030_038*, MemoryPool*);
void func_885063B8(unk_func_88200FA0_030_030*, unk_func_88201DA0_038*);
void func_88506404(unk_func_88200FA0_030_030*, unk_func_8820BE14_06C*, MemoryPool*);
s32 func_88506438(unk_func_88200FA0_030_030*, s32, s32);
s32 func_885065E0(unk_func_88200FA0_030_030*, Controller*);
void func_88506BFC(unk_func_88200FA0_030_030*, s32);
s32 func_88506CE4(unk_func_88200FA0_030_030*);
void func_88506DCC(unk_func_8821421C_038_034*, s32, s32, unk_func_88200FA0_030_030_040, s32, s32, s32, MemoryPool*);
void func_88506EE4(unk_func_8820BE14_02C_038*, unk_func_88200FA0_030_038*);
void func_88506F1C(unk_func_8830867C_02C_034*, unk_func_88200FA0_030_038*, MemoryPool*);
void func_88506F50(unk_func_8821421C_038_034*, unk_func_8821421C_038_050**);
void func_88506F8C(unk_func_8821421C_038_034*, unk_func_8830867C_03C_0D0*, MemoryPool*);
void func_88506FC0(unk_func_8820BE14_02C_038*);
void func_88506FE0(unk_func_8820BE14_02C_038*);
s32 func_88507018(unk_func_8821421C_038_034*);
s32 func_8850734C(unk_func_8821421C_038_034*, s32, s32);
s32 func_885075BC(unk_func_8821421C_038_034*, Controller*);
void func_88507AE4(unk_func_8820BE14_02C_038*, s32);
void func_88507B80(unk_func_8820BE14_02C_038*, s32);
void func_88507C0C(unk_func_8830867C_02C_034*, s32, s32);
void func_88507CC4(unk_func_8820BE14_02C_038*, unk_func_88205880_00D0*);
void func_88507CEC(unk_func_8820BE14_02C_038*);
void func_88507D4C(unk_func_88507D4C*, s32, s32, s32, s32, unk_func_8820BE14_02C_038*);
s32 func_88507DBC(unk_func_88507D4C*, s32, s32);
void func_8850878C(unk_func_8850878C*, s32, s32, char*, s32);
s32 func_8850882C(unk_func_8850878C*, s32, s32);
void func_885088F4(unk_func_885088F4*, s32, s32, s32);
s32 func_8850897C(unk_func_885088F4*);
s32 func_88508AA8(unk_func_885088F4*, s32, s32);
void func_88509A2C(unk_func_88509A2C*, s32, s32, s32, char*);
s32 func_88509AF0(unk_func_88509A2C*, s32, s32);
void func_88509E34(unk_func_88509E34*, s32, s32, char*);
s32 func_88509E8C(unk_func_88509F0C*, s32, s32);
void func_88509F48(unk_func_88509F48*, s32, s32, s32, s32, MemoryPool*, unk_D_800AC870*);
void func_8850A10C(unk_func_88509F48*, unk_func_8850878C*, s32, s32);
s32 func_8850A29C(unk_func_88509F48*, Controller*);
void func_8850A3CC(unk_func_88509F48*, Controller*);
void func_8850A3EC(unk_func_88509F48*, Controller*);
void func_8850A40C(unk_func_88001300_000*, s32, s32, s32, s32);
s32 func_8850A480(unk_func_88001300_000*, s32, s32);
void func_8850AB48(unk_func_88001300_000*, s32, s32, s32, s32);
s32 func_8850ABBC(unk_func_88001300_000*, s32, s32);
void func_8850B254(unk_func_8850B254*, s32, s32, s32, s32, Color_RGBA8, Color_RGBA8);
s32 func_8850B2D4(unk_func_8850B254*, s32, s32);
void func_8850BC94(s32);
void func_8850BD40(unk_func_8850BD40*, unk_func_8821421C_038_034*);
s32 func_8850BD8C(unk_func_8850BD40* arg0, Controller* arg1);
void func_8850BDC8(unk_func_8850BD40* arg0, s32 arg1);
void func_8850BDF0(unk_func_8830867C_02C_048_000* arg0);
s32 func_8850BE3C(unk_func_8830867C_02C_048_000*, Controller*);
void func_8850BF60(unk_func_8830867C_02C_048_000*, s32);
void func_8850BF80(unk_func_8830867C_02C_048_000*, unk_func_88001300_000_000*);
void func_8850BFB0(unk_func_8830867C_02C_048_000*);
void func_8850C064(unk_func_8830867C_02C_048_000*, s32);
s32 func_8850C0D0(unk_func_8830867C_02C_048_000* arg0, Controller* arg1);
void func_8850C1B8(unk_func_8830867C_02C_048_000* arg0, s32 arg1);
void func_8850C208(unk_func_8830867C_02C_048_000*);
void func_8850C284(unk_func_88001300_03C*, s32, s32, MemoryPool*);
s32 func_8850C3B8(unk_func_88001300_03C*, Controller*);
void func_8850C904(unk_func_88001300_03C*, s32);
void func_8850C924(unk_func_88001300_03C*);
void func_8850CAB4(unk_func_88001300_03C*);
void func_8850CB48(unk_func_88001300_03C*, s32);
void func_8850CBA8(unk_func_8830867C_02C_048_000*);
s32 func_8850CBF4(unk_func_8830867C_02C_048_000*, Controller*);
void func_8850CC54(unk_func_8830867C_02C_048_000*, s32);
void func_8850CCA4(unk_func_8830867C_02C_048_000* arg0);
void func_8850CC74(unk_func_8830867C_02C_048_000*, unk_func_88001300_000*);
void func_8850CD24(unk_func_8830867C_02C_048*, s32);
void func_8850CD44(unk_func_8850CD44*, s32, MemoryPool*);
s32 func_8850CE30(unk_func_8850CD44* arg0, Controller* arg1);
void func_8850CE80(unk_func_8850CD44* arg0, s32 arg1);
void func_8850CF00(unk_func_8850CD44*, Controller* arg1);

#endif // _FRAGMENT26_H_
