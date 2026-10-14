#ifndef _FRAGMENT23_H_
#define _FRAGMENT23_H_

#include "global.h"
#include "src/fragments/widget_tree/widget_tree.h"
#include "src/fragments/lab_ui_support/lab_ui_support.h"
#include "src/table_view.h"
#include "src/gb_data.h"
#include "src/gb_save.h"

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
    /* 0x00 */ WidgetNode unk_00;
    /* 0x2C */ WidgetAnimatedPanel* unk_2C;
    /* 0x30 */ unk_func_88200FA0_030_030* unk_30;
    /* 0x34 */ unk_func_88503298* unk_34;
    /* 0x38 */ unk_func_88200FA0_030_038 unk_38;
} unk_func_88200FA0_030; // size = 0x44

typedef struct unk_func_88200FA0 {
    /* 0x00 */ WidgetNode unk_00;
    /* 0x2C */ unk_func_885088F4* unk_2C;
    /* 0x30 */ unk_func_88200FA0_030* unk_30;
} unk_func_88200FA0; // size = 0x34

typedef struct unk_func_88205880 {
    /* 0x0000 */ WidgetNode unk_0000;
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
    /* 0x00 */ WidgetNode unk_00;
    /* 0x2C */ unk_func_8850143C* unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 unk_38;
} unk_func_88208C5C; // size = 0x3C

typedef struct unk_func_882079D8 {
    /* 0x00 */ WidgetNode unk_00;
    /* 0x2C */ unk_func_88205880_00D0* unk_2C;
} unk_func_882079D8; // size = 0x30

typedef struct unk_func_8820BE14_030 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ MemoryPool* unk_04;
    /* 0x08 */ WidgetLinkHeader* unk_08;
    /* 0x0C */ unk_func_88205880_00D0* unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ WidgetNode* unk_14;
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
    /* 0x74 */ WidgetUpdateCallback unk_74;
    /* 0x78 */ WidgetDrawCallback unk_78;
    /* 0x7C */ WidgetInputCallback unk_7C;
    /* 0x80 */ WidgetDrawCallback unk_80;
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
    /* 0x28 */ WidgetGridMenu* unk_28;
    /* 0x28 */ unk_func_8820B12C_02C* unk_2C;
} unk_func_8820B12C; // size = 0x30

typedef struct unk_func_8820BE14_02C_070 {
    /* 0x0000 */ WidgetNode unk_0000;
    /* 0x002C */ unk_func_88205880_00D0* unk_002C;
    /* 0x0030 */ s16 unk_0030;
    /* 0x0032 */ char unk0032[0x7];
    /* 0x0039 */ u8 unk_0039[2][0xC80];
} unk_func_8820BE14_02C_070; // size = 0x193C

typedef struct unk_func_8820BE14_02C_078_034 {
    /* 0x00 */ WidgetNode unk_00;
    /* 0x2C */ WidgetAnimatedPanel* unk_2C;
    /* 0x30 */ unk_func_88200FA0_030_030* unk_30;
} unk_func_8820BE14_02C_078_034; // size = 0x34

typedef struct unk_func_8820BE14_02C_078 {
    /* 0x00 */ WidgetNode unk_00;
    /* 0x2C */ WidgetAnimatedPanel* unk_2C;
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
    /* 0x00 */ WidgetNode unk_00;
    /* 0x2C */ WidgetAnimatedPanel* unk_2C;
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
    /* 0x00 */ WidgetNode unk_00;
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
    /* 0x00 */ WidgetNode unk_00;
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
    /* 0x00 */ WidgetNode unk_00;
    /* 0x2C */ s32 unk_2C;
} unk_func_8821421C_02C_06C_02C_068; // size = 0x30

typedef struct unk_func_8820E99C_030 {
    /* 0x00 */ WidgetNode unk_00;
    /* 0x2C */ WidgetAnimatedPanel* unk_2C;
    /* 0x30 */ unk_func_8820E99C_030_030 unk_30;
    /* 0x44 */ unk_func_8820E99C_030_044* unk_44;
} unk_func_8820E99C_030; // size = 0x48

typedef struct unk_func_8820E99C {
    /* 0x00 */ WidgetNode unk_00;
    /* 0x2C */ WidgetAnimatedPanel* unk_2C;
    /* 0x30 */ unk_func_8820E99C_030* unk_30;
    /* 0x34 */ s32 unk_34;
} unk_func_8820E99C; // size = 0x38

typedef struct unk_func_8821421C_034 {
    /* 0x00 */ WidgetNode unk_00;
    /* 0x2C */ WidgetAnimatedPanel* unk_2C;
    /* 0x30 */ WidgetGridMenu* unk_30;
    /* 0x34 */ unk_func_8850878C* unk_34;
} unk_func_8821421C_034; // size = 0x38

typedef struct unk_func_8821421C_038_02C {
    /* 0x00 */ WidgetNode unk_00;
    /* 0x2C */ unk_func_8850143C* unk_2C;
    /* 0x30 */ unk_func_8821421C_038_050* unk_30;
} unk_func_8821421C_038_02C; // size = 0x34

typedef struct spE8_func_882121E0 {
    /* 0x00 */ char* unk_00[3];
} spE8_func_882121E0; // size >= 0xC

typedef struct unk_func_8821421C_02C_030 {
    /* 0x00 */ WidgetNode unk_00;
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
    /* 0x00 */ WidgetNode unk_00;
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
    /* 0x28 */ WidgetGridMenu* unk_28;
    /* 0x2C */ unk_func_8821421C_02C_06C_02C* unk_2C;
} unk_func_8821421C_02C_06C; // size = 0x30

typedef struct unk_func_8821421C_02C_070 {
    /* 0x00 */ WidgetNode unk_00;
    /* 0x2C */ WidgetAnimatedPanel* unk_2C;
    /* 0x30 */ unk_func_88200FA0_030_030* unk_30;
    /* 0x34 */ unk_func_88205880_A030 unk_34;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ s32 unk_48;
} unk_func_8821421C_02C_070; // size = 0x4C

typedef struct unk_func_8821421C_02C {
    /* 0x00 */ WidgetNode unk_00;
    /* 0x2C */ WidgetAnimatedPanel* unk_2C;
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
    /* 0x28 */ WidgetGridMenu* unk_28;
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
    /* 0x00 */ WidgetNode unk_00;
    /* 0x2C */ unk_func_8821421C_038_02C* unk_2C;
    /* 0x30 */ unk_func_8820BE14_02C_038* unk_30;
    /* 0x34 */ unk_func_8821421C_038_034* unk_34;
    /* 0x38 */ unk_func_88500994* unk_38;
    /* 0x3C */ unk_func_88500994* unk_3C;
    /* 0x40 */ unk_func_8850878C* unk_40;
    /* 0x44 */ WidgetAnimatedPanel* unk_44;
    /* 0x48 */ unk_func_8821421C_034* unk_48;
    /* 0x4C */ unk_func_8821421C_038_04C* unk_4C;
    /* 0x50 */ unk_func_8821421C_038_050* unk_50[1];
    /* 0x54 */ char unk54[0xC];
    /* 0x60 */ s32 unk_60;
    /* 0x64 */ unk_func_8820BE14_06C unk_64;
    /* 0x74 */ char unk74[0x4];
} unk_func_8821421C_038; // size = 0x78

typedef struct unk_func_8821421C {
    /* 0x00 */ WidgetNode unk_00;
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

FontContext* LabPC_Enter(void);
void LabPC_Exit(void);
s32 LabPC_ExitToLabMain(UNUSED s32 arg0, UNUSED s32 arg1);
s32 LabPC_Dispatch(s32 arg0, s32 arg1);

void LabPC_BuildMenuTitleLabel(unk_func_88503298* arg0, s32 arg1, s32 arg2, MemoryPool* arg3);
void LabPC_MenuTitleLabel_SetText(unk_func_88503298* arg0, s8* arg1);
void LabPC_BuildMenuGridWidget(unk_func_88200FA0_030* arg0, s32 arg1, s32 arg2, WidgetNode* arg3, MemoryPool* arg4);
void LabPC_MenuGridWidget_RefreshTitle(unk_func_88200FA0_030* arg0, s32 arg1);
void LabPC_DrawMenuGridCell(s32 arg0, s32 arg1, char* arg2, s32 arg3);
s32 LabPC_MenuGridWidget_HandleInput(unk_func_88200FA0_030* arg0, Controller* arg1);
void LabPC_MenuGridWidget_Open(unk_func_88200FA0_030* arg0);
void LabPC_MenuGridWidget_Close(unk_func_88200FA0_030* arg0);
s32 LabPC_MenuHandleInput(unk_func_88200FA0_030* arg0, Controller* arg1);
void LabPC_BuildMenuWidget(unk_func_88200FA0* arg0, s32 arg1, s32 arg2, s32 arg3, MemoryPool* arg4);
s32 LabPC_RunWidgetLoop(unk_func_88200FA0* arg0);
void LabPC_MenuThreadEntry(unk_func_88200FA0* arg0);
s32 LabPC_ShowMenu(s32 arg0, UNUSED s32 arg1);

void LabPC_MarkBoxSeen(unk_func_88205880_00D0* arg0);
void LabPC_WriteBoxEntries(s32 arg0, s32 arg1, s32 arg2, unk_func_88205880_00D0* arg3);
s32 LabPC_ReadBoxEntries(s32 arg0, s32 arg1, s32 arg2, unk_func_88205880_00D0* arg3, s32 arg4);
void LabPC_LoadAllBoxes(unk_func_88205880_00D0* arg0, s32 arg1, s32 arg2, s32 arg3);
s32 LabPC_NoEmptyBoxAvailable(unk_func_88205880_A030* arg0);
s32 LabPC_AllBoxesEmpty(unk_func_88205880_A030* arg0);
void LabPC_CheckBox_SetTitle(unk_func_88201DA0* arg0, u32 arg1, u32 arg2);
void LabPC_CheckBox_ShowBox(unk_func_88201DA0* arg0, unk_func_88205880_00D0* arg1, u32 arg2);
void LabPC_CheckBox_SetSelectedIndex(unk_func_88203ED8* arg0, s32 arg1);
s32 LabPC_CheckBox_HandleInput(unk_func_88201DA0* arg0, Controller* arg1);
void LabPC_CheckBox_ModalLoop(unk_func_88201DA0* arg0, Controller* arg1);
void LabPC_DrawBoxCount(unk_func_88205880_00D0* arg0, s32 arg1, s32 arg2);
void LabPC_BuildBoxCountLabel(unk_func_8820253C* arg0, s32 arg1, s32 arg2, unk_func_88205880_00D0* arg3);
void LabPC_BoxCountLabel_SetBox(unk_func_8820253C* arg0, unk_func_88205880_00D0* arg1);
s32 LabPC_BoxCountLabel_Draw(unk_func_8820253C* arg0, s32 arg1, s32 arg2);
void LabPC_BuildBoxPairSelector(unk_func_882025E0_1A9780* arg0, unk_func_88200FA0_030_030* arg1, unk_func_88200FA0_030_030* arg2, unk_func_88203ED8* arg3, MemoryPool* arg4);
void LabPC_BoxPairSelector_SetFlags(unk_func_882025E0_1A9780* arg0, s32 arg1);
void LabPC_BoxPairSelector_Refresh(unk_func_882025E0_1A9780* arg0);
void LabPC_BoxPairSelector_SetActiveSide(unk_func_882025E0_1A9780* arg0, s32 arg1);
void LabPC_BoxPairSelector_GetSelectedBoxes(unk_func_882025E0_1A9780* arg0, unk_func_88205880_00D0** arg1, unk_func_88205880_00D0** arg2);
void LabPC_BoxPairSelector_GetSelectedBoxIds(unk_func_882025E0_1A9780* arg0, WidgetPoint* arg1, WidgetPoint* arg2);
void LabPC_DisableEmptyBoxes(unk_func_88200FA0_030_030* arg0);
void LabPC_DisableNonEmptyBoxes(unk_func_88200FA0_030_030* arg0);
void LabPC_BoxPairSelector_RefreshDisabledBoxes(unk_func_882025E0_1A9780* arg0);
void LabPC_BoxPairSelector_SetStage(unk_func_882025E0_1A9780* arg0, s32 arg1);
void LabPC_BoxPairSelector_SetMode(unk_func_882025E0_1A9780* arg0, s32 arg1);
void LabPC_BoxPairSelector_Reset(unk_func_882025E0_1A9780* arg0);
void LabPC_BoxPairSelector_SwapSides(unk_func_882025E0_1A9780* arg0);
s32 LabPC_BoxPairSelector_IsInitialStage(unk_func_882025E0_1A9780* arg0);
void LabPC_BoxPairSelector_ReorderSwap(unk_func_882025E0_1A9780* arg0);
void LabPC_BoxPairSelector_ExchangeSwap(unk_func_882025E0_1A9780* arg0);
s32 LabPC_BoxPairSelector_HandleInput(unk_func_882025E0_1A9780* arg0, Controller* arg1);
void LabPC_BuildBoxLabelTab(unk_func_8820399C* arg0, s32 arg1, unk_func_8850143C* arg2);
s32 LabPC_DrawBoxLabelTab(unk_func_8820399C* arg0, s32 arg1, s32 arg2);
s32 LabPC_BoxMenu_OnShow(unk_func_88203ED8* arg0);
void LabPC_BoxMenu_SetVisible(unk_func_88203ED8* arg0, s32 arg1);
s32 LabPC_BoxMenu_HandleInput(unk_func_88203ED8* arg0, Controller* arg1);
void LabPC_BoxMenu_ClearButtonHighlights(unk_func_88203ED8* arg0);
void LabPC_BoxMenu_RefreshBoxLabels(unk_func_88203ED8* arg0);
void LabPC_BoxMenu_InitFocusNode(unk_func_88203ED8_064* arg0, unk_func_88203ED8* arg1);
u32 LabPC_BoxHasUnsavedChanges(unk_func_88205880_00D0* arg0, s32 arg1, s32 arg2, s32 arg3);
s32 LabPC_GetDirtyBoxMask(unk_func_88203ED8* arg0);
void LabPC_SaveModifiedBoxes(unk_func_88203ED8* arg0, s32 arg1);
s32 LabPC_ConfirmSaveAndExit(unk_func_88203ED8* arg0, Controller* arg1);
s32 func_882052F4(unk_func_88203ED8_064* arg0, Controller* arg1);
void LabPC_BoxMenu_ModalLoop(unk_func_88203ED8* arg0, Controller* arg1);
s32 LabPC_BoxScreen_HandleInput(unk_func_88205880* arg0, Controller* arg1);
void LabPC_BoxScreen_DrawLoop(unk_func_88205880* arg0);
void LabPC_BoxScreen_InputThread(unk_func_88205880* arg0);

void func_88206110(BattleMon* arg0);
s32 LabPC_ReadDeckEntries(unk_func_882062E4* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 LabPC_BoxNumberSelectorInput(unk_func_8820BE14_02C_078_034* arg0, Controller* arg1);
s32 LabPC_RunBoxNumberSelectorModal(WidgetTextList* arg0, Controller* arg1);
s32 LabPC_MeasureBoxNumberWidth(void);
void LabPC_InitBoxNumberSelector(unk_func_8820BE14_02C_078_034* arg0, s32 arg1, s32 arg2, MemoryPool* arg3);
s32 LabPC_MeasureBoxTypeLabelWidth(void);
u32 LabPC_BoxTypeSelector_GetSlotSelection(unk_func_8820BE14_02C_078* arg0);
void LabPC_BoxTypeSelector_SetSlotASelection(unk_func_8820BE14_02C_078* arg0, u32 arg1);
void LabPC_BoxTypeSelector_SetSlotBSelection(unk_func_8820BE14_02C_078* arg0, u32 arg1);
s32 LabPC_BoxTypeSelectorInput(unk_func_8820BE14_02C_078* arg0, Controller* arg1);
s32 LabPC_RunBoxTypeSelectorModal(unk_func_8820BE14_02C_078* arg0, Controller* arg1);
void LabPC_DrawMonNameLevel(unk_func_88205880_00D0* arg0, s32 arg1, s32 arg2, s32 arg3);
void LabPC_InitMonNameLevelWidget(unk_func_882079D8* arg0, s32 arg1, s32 arg2, s32 arg3, unk_func_88205880_00D0* arg4);
void LabPC_MonNameLevelWidget_SetMon(unk_func_882079D8* arg0, unk_func_88205880_00D0* arg1);
s32 LabPC_MonNameLevelWidget_Draw(unk_func_882079D8* arg0, s32 arg1, s32 arg2);
void LabPC_SwapMenu_NotifyModeChanged(unk_func_8820B12C_02C* arg0, s32 arg1);
void LabPC_SwapMenu_SetSelectMode(unk_func_8820B12C_02C* arg0, s32 arg1);
void LabPC_SwapMenu_RefreshHighlight(unk_func_8820B12C_02C* arg0);
void LabPC_SwapMenu_SetActiveSide(unk_func_8820B12C_02C* arg0, s32 arg1);
void LabPC_SwapMenu_SetState(unk_func_8820B12C_02C* arg0, s32 arg1);
void LabPC_SwapMenu_SwapSides(unk_func_8820B12C_02C* arg0);
void LabPC_SwapMenu_GetSelectedMons(unk_func_8820B12C_02C* arg0, unk_func_88205880_00D0** arg1, unk_func_88205880_00D0** arg2);
void LabPC_SwapMenu_GetSelectedPositions(unk_func_8820B12C_02C* arg0, WidgetPoint* arg1, WidgetPoint* arg2);
void LabPC_SwapMenu_SetPhase(unk_func_8820B12C_02C* arg0, s32 arg1);
void LabPC_SwapMenu_Reset(unk_func_8820B12C_02C* arg0);
s32 LabPC_SwapMenu_IsIdle(unk_func_8820B12C_02C* arg0);
void LabPC_MoveMonToSlot(unk_func_8820B12C_02C_020* arg0, unk_func_8820B12C_02C_020* arg1);
void LabPC_SwapMonsInBox(unk_func_8820B12C_02C_020* arg0, s32 arg1, s32 arg2);
void LabPC_ExchangeMonsBetweenBoxes(unk_func_8820B12C_02C_020* arg0, unk_func_8820B12C_02C_020* arg1);
void LabPC_RemoveMonFromBox(unk_func_8820B12C_02C_020* arg0);
void LabPC_PerformMove(unk_func_8820B12C_02C* arg0, Controller* arg1);
void LabPC_PerformExchange(unk_func_8820B12C_02C* arg0, Controller* arg1, s32 arg2);
void LabPC_PerformReleaseOrReceive(unk_func_8820B12C_02C* arg0);
s32 LabPC_SwapMenuInput(unk_func_8820B12C_02C* arg0, Controller* arg1);
unk_func_88205880_00D0* LabPC_GetHighlightedMon(unk_func_8820B12C_02C* arg0);
void LabPC_InitBoxLocationWidget(unk_func_88208C5C* arg0, unk_func_8850143C* arg1);
s32 LabPC_DrawBoxLocationLabel(unk_func_88208C5C* arg0, s32 arg1, s32 arg2);
u32 LabPC_BoxLocationWidget_GetSelection(unk_func_88208C5C* arg0);
void LabPC_BoxLocationWidget_SetSelection(unk_func_88208C5C* arg0, u32 arg1);
void LabPC_InitPokemonInfoCard(unk_func_8820BE14_02C_070* arg0, s32 arg1, s32 arg2);
void LabPC_DrawMoveName(s32 arg0, s32 arg1, ret_func_8002ED08* arg2, s32 arg3);
s32 LabPC_DrawPokemonInfoCard(unk_func_8820BE14_02C_070* arg0, s32 arg1, s32 arg2);
void LabPC_InfoCard_SetMon(unk_func_8820BE14_02C_070* arg0, unk_func_88205880_00D0* arg1);
s32 LabPC_FindDirtyDeck(unk_func_8820BE14_06C* arg0);
s32 LabPC_SwapScreen_UpdatePageSelection(unk_func_8820BE14_02C* arg0);
s32 LabPC_HandleInput(unk_func_8820BE14_02C* arg0, Controller* arg1);
s32 LabPC_RunSwapScreenModal(unk_func_8820BE14_02C* arg0, Controller* arg1);
void LabPC_SwapScreen_SetMenuState(unk_func_8820BE14_02C* arg0, s32 arg1);
void LabPC_ReleaseSwapWidgets(unk_func_8820B12C_02C* arg0);
void LabPC_InitSwapController(unk_func_8820B12C* arg0, unk_func_8820BE14_02C* arg1);
s32 LabPC_DeckHasChanged(unk_func_8820BE14_06C_000* arg0, s32 arg1, s32 arg2, s32 arg3);
s32 LabPC_CheckDirtyDecks(unk_func_8820BE14_02C* arg0);
s32 LabPC_IsPrizeDeckEmpty(unk_func_8820BE14_02C* arg0);
void LabPC_WriteDeckBack(s32 arg0, s32 arg1, s32 arg2, unk_func_88200FA0_030_038* arg3);
void LabPC_MarkSeenOwned(unk_func_88200FA0_030_038* arg0, s32 arg1);
void LabPC_CommitChanges(unk_func_8820BE14_02C* arg0, s32 arg1);
s32 LabPC_RunConfirmSaveFlow(unk_func_8820BE14_02C* arg0, Controller* arg1);
s32 LabPC_SwapControllerInput(unk_func_8820B12C* arg0, Controller* arg1);
void LabPC_RunSwapScreenLoop(unk_func_8820BE14* arg0);
void LabPC_PokemonSessionThread(unk_func_8820BE14* arg0);
void LabPC_PrizePokemonThread(unk_func_8820BE14* arg0);
void LabPC_ShowPokemon(FontContext* arg0, s32 arg1);

void LabItem_ReadDeckEntries(s32 arg0, s32 arg1, s32 arg2, unk_func_8820BE14_06C* arg3);
void LabItem_WriteDeckBack(s32 arg0, s32 arg1, s32 arg2, unk_func_8820BE14_06C* arg3, s32 arg4, char* arg5, s32 arg6);
void LabItem_LoadGamePakBoxSlots(unk_func_8821421C_07C* arg0);
s32 LabItem_FindOrAllocateGamePakBoxSlot(unk_func_8821421C_07C* arg0, s32 arg1, char* arg2);
void LabItem_InitBoxLocationWidget(unk_func_8821421C_02C_030* arg0, unk_func_8850143C* arg1, spE8_func_882121E0* arg2);
s32 LabItem_DrawBoxLocationLabel(unk_func_8821421C_02C_030* arg0, s32 arg1, s32 arg2);
s32 LabItem_BoxLocationWidget_GetSelection(unk_func_8821421C_02C_030* arg0);
void LabItem_BoxLocationWidget_SetSelection(unk_func_8821421C_02C_030* arg0, s32 arg1);
void LabItem_InitConfirmDialog(unk_func_8821421C_034* arg0, s32 arg1, s32 arg2, MemoryPool* arg3);
s32 LabItem_ConfirmDialog_HandleInput(unk_func_8821421C_034* arg0, Controller* arg1);
void LabItem_ConfirmDialog_SetSelectedIndex(unk_func_8821421C_034* arg0, s32 arg1);
void LabItem_SetConfirmDialogText(unk_func_8821421C_034* arg0, char* arg1);
s32 LabItem_RunConfirmDialog(unk_func_8821421C_034* arg0, Controller* arg1);
s32 LabItem_MeasureMenuWidth(spE8_func_882121E0* arg0, s32 arg1);
void LabItem_DrawMenuCell(s32 arg0, s32 arg1, s8* arg2, s32 arg3, s32 arg4, unk_func_88200FA0_030_030* arg5);
s32 LabItem_DropdownMenu_HandleInput(unk_func_8821421C_02C_070* arg0, Controller* arg1);
void LabItem_DropdownMenu_SetSelectedIndex(unk_func_8821421C_02C_070* arg0, s32 arg1);
s32 LabItem_DropdownMenu_GetSelectedIndex(unk_func_8821421C_02C_070* arg0);
void LabItem_DropdownMenu_SetSelection(unk_func_8821421C_02C_070* arg0, s32 arg1);
void LabItem_DropdownMenu_Open(unk_func_8821421C_02C_070* arg0);
void LabItem_DropdownMenu_Close(unk_func_8821421C_02C_070* arg0);
s32 LabItem_RunDropdownMenuModal(unk_func_8821421C_02C_070* arg0, Controller* arg1);
void LabItem_DropdownMenu_SetDisabledIndex(unk_func_8821421C_02C_070* arg0, s32 arg1);
s32 LabItem_DrawItemRow(u8* arg0, s32 arg1, s32 arg2, s32 arg3);
void LabItem_DrawItemGridCell(s32 arg0, s32 arg1, u8* arg2, s32 arg3, s32 arg4, unk_func_8820BE14_02C_038* arg5);
void LabItem_InitItemRowWidget(unk_func_8821421C_02C_06C_02C_060* arg0, s32 arg1, s32 arg2, s32 arg3);
void LabItem_ItemRowWidget_SetItem(unk_func_8821421C_02C_06C_02C_060* arg0, unk_func_8821421C_02C_06C_02C_060_02C_000 arg1);
s32 LabItem_ItemRowWidget_Draw(unk_func_8821421C_02C_06C_02C_060* arg0, s32 arg1, s32 arg2);
void LabItem_QuantitySpinner_Init(unk_func_8820E99C_030* arg0, s32 arg1);
void LabItem_InitQuantitySpinnerDigits(unk_func_8820E99C_030* arg0, s32 arg1, s32 arg2, MemoryPool* arg3);
void LabItem_QuantitySpinnerDigits_SetSelected(unk_func_8820E99C_030* arg0, s32 arg1);
s32 LabItem_QuantitySpinnerDigits_PositionArrow(unk_func_8820E99C_030* arg0);
s32 LabItem_DrawQuantitySpinnerDigits(unk_func_8820E99C_030* arg0, s32 arg1, s32 arg2);
s32 LabItem_QuantitySpinnerInput(unk_func_8820E99C_030* arg0, Controller* arg1);
void LabItem_QuantitySpinner_SetMax(unk_func_8820E99C* arg0, s32 arg1, s32 arg2);
void LabItem_InitQuantitySpinner(unk_func_8820E99C* arg0, s32 arg1, s32 arg2, MemoryPool* arg3);
void LabItem_QuantitySpinner_SetSelected(unk_func_8820E99C* arg0, s32 arg1);
s32 LabItem_QuantitySpinner_HandleInput(unk_func_8820E99C* arg0, Controller* arg1);
void LabItem_QuantitySpinner_Open(unk_func_8820E99C* arg0);
void LabItem_QuantitySpinner_Close(unk_func_8820E99C* arg0);
void LabItem_InitGamePakLabelWidget(unk_func_8821421C_038_02C* arg0, unk_func_8850143C* arg1);
s32 LabItem_DrawGamePakLabel(unk_func_8821421C_038_02C* arg0, s32 arg1, s32 arg2);
void LabItem_GamePakLabelWidget_SetSlot(unk_func_8821421C_038_02C* arg0, unk_func_8821421C_038_050* arg1);
void LabItem_DrawGamePakInfoCard(s32 arg0, s32 arg1, unk_func_8820EFD8* arg2, s32 arg3, s32 arg4, unk_func_8821421C_038_034* arg5);
void LabItem_BindBoxScreenSlot(unk_func_8821421C_038* arg0, unk_func_8821421C_07C* arg1);
s32 LabItem_BoxScreen_UpdatePageSelection(unk_func_8821421C_038* arg0);
s32 LabItem_BoxScreen_HandleInput(unk_func_8821421C_038* arg0, Controller* arg1);
void LabItem_BoxScreen_SetMenuState(unk_func_8821421C_038* arg0, s32 arg1);
void LabItem_LoadBoxScreenSlotItems(unk_func_8821421C_038* arg0, s32 arg1);
s32 LabItem_RunBoxScreenModal(unk_func_8821421C_038* arg0, Controller* arg1);
void LabItem_InitBoxScreenMenu(unk_func_8821421C_038_04C* arg0, unk_func_8821421C_038* arg1);
s32 func_88210380(unk_func_8821421C_038_04C* arg0, Controller* arg1);
void LabItem_OperationController_SetSelectMode(unk_func_8821421C_02C_06C_02C* arg0, s32 arg1);
void LabItem_OperationController_RefreshHighlight(unk_func_8821421C_02C_06C_02C* arg0);
void LabItem_OperationController_SetActiveSide(unk_func_8821421C_02C_06C_02C* arg0, s32 arg1);
void LabItem_OperationController_SwapSides(unk_func_8821421C_02C_06C_02C* arg0);
void LabItem_OpenQuantitySpinnerForSelection(unk_func_8821421C_02C_06C_02C* arg0, s32 arg1);
void LabItem_SetOperationState(unk_func_8821421C_02C_06C_02C* arg0, s32 arg1);
void LabItem_SetOperationMode(unk_func_8821421C_02C_06C_02C* arg0, s32 arg1);
void LabItem_ResetOperation(unk_func_8821421C_02C_06C_02C* arg0);
s32 LabItem_IsOperationIdle(unk_func_8821421C_02C_06C_02C* arg0);
void func_88210DA8(void);
s32 LabItem_ComputeRemainingCapacity(s32 arg0, unk_func_8820BE14_06C* arg1);
s32 LabItem_ComputeMaxTransferQuantity(s32 arg0, unk_func_8820BE14_06C* arg1);
void LabItem_InsertGridEntry(unk_func_8820BE14_02C_038* arg0, u8* arg1);
void LabItem_RemoveGridEntryAt(unk_func_8820BE14_02C_038* arg0, s32 arg1);
void LabItem_RemoveSelectedGridEntry(unk_func_8820BE14_02C_038* arg0);
void func_88210F74(unk_func_8820BE14_02C_038* arg0, s32 arg1, s32 arg2);
void LabItem_SubtractSelectedItemQuantity(unk_func_8820BE14_02C_038* arg0, s32 arg1);
void LabItem_MoveSelectedItem(unk_func_8820BE14_02C_038* arg0, unk_func_8820BE14_02C_038* arg1, unk_func_8820E99C* arg2);
s32 LabItem_CombineStackQuantities(unk_func_8821421C_02C_06C_02C_060_02C_000* arg0, unk_func_8821421C_02C_06C_02C_060_02C_000* arg1);
void func_882111F8(unk_func_8820BE14_02C_038* arg0, s32 arg1, s32 arg2);
void LabItem_SwapEntries(unk_func_8820BE14_02C_038* arg0, unk_func_8820BE14_02C_038* arg1);
void LabItem_CommitMove(unk_func_8821421C_02C_06C_02C* arg0, Controller* arg1);
void LabItem_CommitReorder(unk_func_8821421C_02C_06C_02C* arg0, Controller* arg1);
void LabItem_CommitExchange(unk_func_8821421C_02C_06C_02C* arg0, Controller* arg1);
s32 LabItem_OperationInputHandler(unk_func_8821421C_02C_06C_02C* arg0, Controller* arg1);
u8* LabItem_GetHighlightedEntry(unk_func_8821421C_02C_06C_02C* arg0);
s32 LabItem_RefreshDescriptionPanel(unk_func_8821421C_02C* arg0);
s32 LabPC_ItemMenu_HandleInput(unk_func_8821421C_02C* arg0, Controller* arg1);
s32 LabPC_ItemMenu_ModalLoop(unk_func_8821421C_02C* arg0, Controller* arg1);
void LabItem_SetMenuState(unk_func_8821421C_02C* arg0, s32 arg1);
void LabItem_ToggleAllTabFlips(unk_func_8821421C_02C* arg0);
void LabItem_InitMenuController(unk_func_8821421C_02C_06C* arg0, unk_func_8821421C_02C* arg1);
s32 LabItem_DeckHasChanged(unk_func_8821421C_03C* arg0, s32 arg1, s32 arg2, s32 arg3);
s32 LabItem_CheckDirtyDecks(unk_func_8821421C_02C* arg0);
void LabItem_CommitChanges(unk_func_8821421C_02C* arg0, s32 arg1);
s32 LabItem_RunConfirmSaveFlow(unk_func_8821421C_02C* arg0, Controller* arg1);
s32 LabItem_BoxPairMenu_HandleInput(unk_func_8821421C_02C_06C* arg0, Controller* arg1);
void LabPC_BuildItemScreenWidget(unk_func_8821421C* arg0, s32 arg1, s32 arg2, MemoryPool* arg3, s32 arg4, char** arg5);
void LabPC_ItemScreen_DrawLoop(unk_func_8821421C* arg0);
void LabPC_ItemScreen_InputThread(unk_func_8821421C* arg0);
void LabPC_ShowItems(FontContext* arg0);

void LabPC_InitTabWidget(unk_func_882149A0* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, Color_RGBA8 arg7, Color_RGBA8 arg8, Color_RGBA8 arg9);
s32 LabPC_DrawTabWidget(unk_func_882149A0* arg0, s32 arg1, s32 arg2);
void LabPC_TabWidget_ToggleFlip(unk_func_882149A0* arg0);
void LabPC_InitScrollableBoxGrid(unk_func_8820BE14_02C_038* arg0, s32 arg1, s32 arg2, s32 arg3, void (*arg4)(), s32 arg5, s32 arg6, MemoryPool* arg7);
void LabPC_SetGridBorderActive(unk_func_88200FA0_030_030* arg0, s32 arg1);
void LabPC_BoxGrid_BindMessagePanel(unk_func_8820BE14_02C_038* arg0, unk_func_88507D4C* arg1);
s32 LabPC_ScrollableGrid_UpdateScroll(unk_func_8820BE14_02C_038* arg0);
s32 LabPC_ScrollableGrid_DrawCells(unk_func_8820BE14_02C_038* arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_88216000(unk_func_8820BE14_02C_038* arg0, s32 arg1, s32 arg2);
s32 func_882169D4(unk_func_8820BE14_02C_038* arg0, Controller* arg1);
void LabPC_ScrollableGrid_SetSwapMode(unk_func_8820BE14_02C_038* arg0, s32 arg1);
void LabPC_BindGridDeckData(unk_func_8820BE14_02C_038* arg0, unk_func_8820BE14_06C_000* arg1, u32 arg2);
void LabPC_BindGridStridedData(unk_func_8820BE14_02C_038*, s32*, s32);
void LabPC_InitPageCounterWidget(unk_func_882170A8* arg0, s32 arg1, s32 arg2, unk_func_8820BE14_02C_038* arg3, s32 arg4);
void LabPC_DrawPageCounterDigits(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 LabPC_PageCounterWidget_Draw(unk_func_882170A8* arg0, s32 arg1, s32 arg2);
void LabPC_InitFlyingIconWidget(unk_func_882173EC* arg0, s32 arg1, s32 arg2);
s32 LabPC_FlyingIconWidget_Update(unk_func_882173EC* arg0);
void LabPC_FlyingIconWidget_Start(unk_func_882173EC* arg0, WidgetPoint arg1, WidgetPoint arg2);
void LabPC_InitSlideIconWidget(unk_func_8821421C_02C_06C_02C_068* arg0, s32 arg1, s32 arg2);
s32 LabPC_SlideIconWidget_Update(unk_func_8821421C_02C_06C_02C_068* arg0);
void LabPC_SlideIconWidget_Start(unk_func_8821421C_02C_06C_02C_068* arg0, WidgetPoint arg1);
void LabPC_InitModeToggleIcon(unk_func_88217740* arg0, s32 arg1, s32 arg2);
s32 LabPC_ModeToggleIcon_Draw(unk_func_88217740* arg0, s32 arg1, s32 arg2);
void LabPC_ModeToggleIcon_SetMode(unk_func_88217740* arg0, s32 arg1);
void LabPC_ModeToggleIcon_SetPressed(unk_func_88217740* arg0);
void LabPC_ModeToggleIcon_ClearPressed(unk_func_88217740* arg0);
void LabPC_ModeToggleIcon_ToggleMode(unk_func_88217740* arg0);


#endif // _FRAGMENT23_H_
