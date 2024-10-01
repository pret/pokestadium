#ifndef _FRAGMENT14_H_
#define _FRAGMENT14_H_

#include "global.h"
#include "src/controller.h"

typedef struct unk_D_868084D8_038 {
    /* 0x000 */ s16 unk_000;
    /* 0x002 */ s16 unk_002;
    /* 0x004 */ char unk004[0x2];
    /* 0x006 */ s16 unk_006;
    /* 0x008 */ struct unk_D_868084D8_038* unk_008;
    /* 0x00C */ Vec3f unk_00C;
    /* 0x018 */ char unk018[0x1B8];
    /* 0x1D0 */ Vec3f unk_1D0;
} unk_D_868084D8_038; // size >= 0x1DC

typedef struct unk_D_868084D8_040 {
    /* 0x00 */char unk00[0x1];
    /* 0x01 */u8 unk_01;
    /* 0x02 */char unk02[0x1];
    /* 0x03 */u8 unk_03;
} unk_D_868084D8_040; // size >= 0x2

typedef struct unk_D_868084D8 {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ Color_RGBA8_u32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ Vec3f unk_14;
    /* 0x20 */ Vec3f unk_20;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ unk_D_868084D8_038* unk_38;
    /* 0x3C */ Gfx* unk_3C;
    /* 0x40 */ unk_D_86002F34_alt9* unk_40;
} unk_D_868084D8; // size = 0x44

typedef struct unk_D_86807558_040 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ s16 unk_18;
} unk_D_86807558_040; // size >= 0x1C

typedef struct unk_D_86807558_098 {
    /* 0x00 */ Vec3f unk_00;
    /* 0x0C */ Vec3f unk_0C;
    /* 0x18 */ Vec3f unk_18;
} unk_D_86807558_098; // size = 0x24

typedef struct unk_D_86807558 {
    /* 0x000 */ s16 unk_000;
    /* 0x002 */ u16 unk_002;
    /* 0x004 */ s16 unk_004;
    /* 0x004 */ s16 unk_006;
    /* 0x008 */ s32 unk_008;
    /* 0x00C */ s16 unk_00C;
    /* 0x010 */ unk_D_868084D8* unk_010;
    /* 0x014 */ s16 unk_014;
    /* 0x016 */ u16 unk_016;
    /* 0x018 */ s32 unk_018;
    /* 0x01C */ s32 unk_01C;
    /* 0x020 */ s32 unk_020;
    /* 0x024 */ s32 unk_024;
    /* 0x028 */ s16 unk_028;
    /* 0x02A */ s16 unk_02A;
    /* 0x02C */ s16 unk_02C[9];
    /* 0x03E */ s16 unk_03E;
    /* 0x040 */ unk_D_86807558_040 unk_040;
    /* 0x05C */ s32 unk_05C;
    /* 0x060 */ s32 unk_060;
    /* 0x064 */ Controller* unk_064;
    /* 0x068 */ Vec3f unk_068;
    /* 0x074 */ Vec3f unk_074;
    /* 0x080 */ Vec3f unk_080;
    /* 0x08C */ Vec3f unk_08C;
    /* 0x098 */ unk_D_86807558_098 unk_098;
    /* 0x0BC */ s16 unk_0BC;
    /* 0x0BE */ s16 unk_0BE;
    /* 0x0C0 */ s32 unk_0C0;
    /* 0x0C4 */ s32 unk_0C4;
    /* 0x0C8 */ f32 unk_0C8;
    /* 0x0CC */ s16 unk_0CC;
    /* 0x0D0 */ Color_RGBA8_u32 unk_0D0;
    /* 0x0D4 */ s16 unk_0D4;
    /* 0x0D8 */ f32 unk_0D8;
    /* 0x0DC */ unk_D_868084D8* unk_0DC;
    /* 0x0E0 */ s16 unk_0E0;
    /* 0x0E2 */ s16 unk_0E2;
    /* 0x0E4 */ unk_D_86002F58_004_000 unk_0E4;
    /* 0x24C */ unk_D_86002F58_004_000 unk_24C;
    /* 0x3B4 */ u32* unk_3B4;
} unk_D_86807558; // size = 0x3B8

typedef struct unk_D_86808498 {
    /* 0x00 */ Vec3f unk_00;
    /* 0x0C */ Vec3f unk_0C;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ Vec3f unk_20;
    /* 0x2C */ Vec3f unk_2C;
} unk_D_86808498; // size >= 0x38

typedef struct unk_D_86808808_018 {
    /* 0x000 */ unk_D_86002F58_004_000_000 unk_000;
    /* 0x018 */ char unk018[0xC];
    /* 0x024 */ Vec3f unk_024;
    /* 0x030 */ Vec3f unk_030;
} unk_D_86808808_018; // size >= 0x3C

typedef struct unk_D_86808808 {
    /* 0x000 */ s16 unk_000;
    /* 0x002 */ s16 unk_002;
    /* 0x004 */ u16 unk_004;
    /* 0x006 */ s16 unk_006;
    /* 0x008 */ s32 unk_008;
    /* 0x00C */ Vec3f unk_00C;
    /* 0x018 */ unk_D_86808808_018 unk_018;
    /* 0x054 */ char unk054[0x12C];
} unk_D_86808808; // size = 0x180

typedef struct unk_D_86807180 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ u8* unk_04;
    /* 0x08 */ u8* unk_08;
    /* 0x10 */ char* unk_0C;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s16 unk_18;
} unk_D_86807180; // size = 0x1C

extern s32 D_86807160[];
extern unk_D_86807180 D_86807180[];

extern unk_D_86002F34* D_86807500;
extern s32 D_86807510;
extern unk_D_86807558 D_86807558[4];

extern unk_D_868084D8 D_868084D8[12];

void func_86800020(s32 arg0);
void func_86800070(void);
Gfx* func_868001A8(Gfx* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_868004F4(void);
void func_868005A8(Color_RGB8* arg0, Color_RGB8* arg1, s32 arg2, s32 arg3, s32 arg4);
void func_8680091C(s32 arg0, s16 arg1, s16 arg2, f32 arg3);
void func_86800B38(void);
void func_86801644(void);
void func_86801700(void);
s32 func_86801840(void);
s32 func_86801884(void);
void func_86801CA8(void);
void func_86801D48(void);
void func_86801E2C(s32 arg0, UNUSED s32 arg1);


void func_86805108(u16, s32);
s32 func_868055D4(void);
void func_86805858(s32);
void func_86805974(void);
void func_86805BD4(void);
void func_86805CB4(void);

f32 func_86805E94(unk_D_868084D8*, Vec3f*, Vec3f*);
void func_86806868(unk_D_868084D8*, s32, unk_D_86807558*);
s32 func_86806930(unk_D_868084D8*);
s16 func_86806950(s32);
void func_86806964(s32);
void func_86806A50(void);
void func_86806BF0(void);

#endif // _FRAGMENT14_H_
