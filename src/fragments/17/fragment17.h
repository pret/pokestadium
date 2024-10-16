#ifndef _FRAGMENT17_H_
#define _FRAGMENT17_H_

#include "global.h"

typedef struct unk_D_86B0E5D4_04 {
    /* 0x00 */ Vec3f unk_00;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ char unk10[0x2];
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ s16 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ s16 unk_20;
    /* 0x22 */ s16 unk_22;
    /* 0x24 */ char unk24[0x2];
    /* 0x26 */ s16 unk_26;
    /* 0x28 */ s16 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ char unk40[0x4];
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ s32 unk_48;
    /* 0x4C */ s32 unk_4C;
    /* 0x50 */ s32 unk_50;
    /* 0x54 */ char unk54[0x14];
    /* 0x68 */ f32 unk_68;
    /* 0x6C */ f32 unk_6C;
    /* 0x70 */ f32 unk_70;
    /* 0x74 */ f32 unk_74;
} unk_D_86B0E5D4_04; // size >= 0x78

typedef struct unk_D_86B0E5D4 {
    /* 0x00 */ unk_D_86002F34_00C* unk_00;
    /* 0x04 */ unk_D_86B0E5D4_04 unk_04;
} unk_D_86B0E5D4; // size = 0x7C

typedef struct unk_D_86B0C160 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s16 unk_16;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ s16 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
} unk_D_86B0C160; // size = 0x34

typedef struct unk_D_86B0E5F0 {
    /* 0x000 */ unk_D_86002F30* unk_000;
    /* 0x004 */ unk_D_86002F58_004_000 unk_004;
    /* 0x16C */ s32 unk_16C;
} unk_D_86B0E5F0; // size = 0x170

typedef struct unk_D_86B0C4C8 {
    /* 0x00 */ Vec3f unk_00;
    /* 0x0C */ u8 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ u16 unk_10;
    /* 0x12 */ char unk12[0x2];
} unk_D_86B0C4C8; // size = 0x14

typedef struct unk_D_86B0DAE0_000 {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ u16 unk_08;
    /* 0x0A */ u16 unk_0A;
    /* 0x0C */ u16 unk_0C;
    /* 0x0E */ u16 unk_0E;
    /* 0x10 */ u16 unk_10;
    /* 0x12 */ u16 unk_12;
    /* 0x14 */ u16 unk_14;
    /* 0x16 */ u16 unk_16;
} unk_D_86B0DAE0_000; // size = 0x18

typedef struct unk_D_86B0DAE0 {
    /* 0x00 */ unk_D_86B0DAE0_000 unk_00;
    /* 0x18 */ unk_D_86B0DAE0_000 unk_18;
} unk_D_86B0DAE0; // size = 0x30

typedef struct unk_D_86B0FA78 {
    /* 0x000 */ unk_D_86002F30* unk_000;
    /* 0x004 */ unk_D_86002F58_004_000 unk_004;
    /* 0x16C */ s32 unk_16C;
    /* 0x170 */ s32 unk_170;
    /* 0x174 */ s32 unk_174;
    /* 0x178 */ s32 unk_178;
    /* 0x17C */ s32 unk_17C;
    /* 0x180 */ s16 unk_180;
} unk_D_86B0FA78; // size = 0x184

typedef struct unk_D_86B0FA50 {
    /* 0x00 */ char unk00[0x80];
    /* 0x80 */ s32 unk_80;
    /* 0x84 */ s32 unk_84;
    /* 0x88 */ s32 unk_88;
    /* 0x8C */ s32 unk_8C;
    /* 0x90 */ s32 unk_90;
    /* 0x94 */ char unk94[0x4];
    /* 0x98 */ f32 unk_98;
    /* 0x9C */ s16 unk_9C;
    /* 0x9E */ s16 unk_9E;
    /* 0xA0 */ s16 unk_A0;
    /* 0xA4 */ f32 unk_A4;
    /* 0xA8 */ f32 unk_A8;
    /* 0xAC */ f32 unk_AC;
    /* 0xB0 */ unk_D_86B0DAE0_000 unk_B0;
} unk_D_86B0FA50; // size = 0xC8

typedef struct unk_D_86B0FA7C {
    /* 0x00 */ unk_D_86002F34_00C* unk_00;
    /* 0x04 */ Vec3f unk_04;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ char unk14[0x2];
    /* 0x16 */ s16 unk_16;
    /* 0x18 */ s16 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ s16 unk_24;
    /* 0x26 */ s16 unk_26;
    /* 0x28 */ char unk28[0x2];
    /* 0x2A */ s16 unk_2A;
    /* 0x2C */ s16 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ char unk48[0x34];
} unk_D_86B0FA7C; // size = 0x7C

typedef struct unk_D_86B0C264 {
    /* 0x00 */ Vec3f unk_00;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ u16 unk_10;
    /* 0x10 */ u16 unk_12;
    /* 0x14 */ u16 unk_14;
    /* 0x14 */ u16 unk_16;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
} unk_D_86B0C264; // size = 0x1C

extern unk_D_86B0C160 D_86B0E040[];
extern s32 D_86B0E5DC;
extern char** D_86B0E5E0;
extern unk_D_86B0FA78* D_86B0FA78;
extern unk_D_86B0FA7C* D_86B0FA7C;
extern unk_70D3A0 D_86B10660;

s32 func_86B00020(UNUSED s32 arg0, UNUSED s32 arg1);

s32 func_86B000D0(s32 arg0, GraphNode* arg1);
s32 func_86B00158(s32 arg0, GraphNode* arg1);
s32 func_86B00188(s32 arg0, GraphNode* arg1);
s32 func_86B001B8(s32 arg0, GraphNode* arg1);
void func_86B001D8(void);
void func_86B001FC(unk_D_86B0E5F0* arg0);
void func_86B00258(void);
void func_86B0027C(unk_D_86B0E5F0* arg0, unk_D_86B0C4C8* arg1);
void func_86B0032C(unk_D_86B0E5F0* arg0, unk_D_86B0C4C8* arg1);
void func_86B00348(s32 arg0);
void func_86B003CC(s32 arg0);
void func_86B00470(s32 arg0);
void func_86B0054C(s32 arg0);
void func_86B00680(void);
void func_86B00688(void);
void func_86B00794(void);
void func_86B007EC(void);
s32 func_86B00848(s32 arg0);
void func_86B008C4(void);
void func_86B00904(void);
void func_86B00944(s32 arg0);
void func_86B00AE4(void);
void func_86B00B14(void);
s32 func_86B00C34(void);
void func_86B01004(void);
void func_86B0100C(void);
void func_86B0107C(void);
void func_86B010FC(void);
void func_86B0111C(void);
s32 func_86B01190(void);

u16 func_86B01320(s32);
Vec3f* func_86B01404(Vec3f*, Vec3f*);
void func_86B0145C(f32*, f32, f32);

u16 func_86B01670(unk_D_86002F34_00C* arg0, unk_D_86002F58_004_000* arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5);
void func_86B01898(unk_D_86B0E5D4_04* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void func_86B018D4(unk_D_86B0E5D4_04* arg0, f32 arg1, f32 arg2);
void func_86B018E8(unk_D_86B0E5D4_04* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void func_86B01924(unk_D_86B0E5D4_04* arg0, f32 arg1, f32 arg2);
void func_86B01938(unk_D_86B0E5D4_04* arg0, f32 arg1, f32 arg2);
void func_86B0194C(unk_D_86B0C160* arg0, unk_D_86B0E5D4* arg1);
void func_86B01A40(unk_D_86B0E5D4_04* arg0, unk_D_86B0E5D4* arg1);
s32 func_86B01AAC(unk_D_86B0E5D4_04* arg0, unk_D_86B0E5D4* arg1);

void func_86B01C00(u8*);
void func_86B01D8C(u8*, s32, s32, s32, s32, u8, u8);
void func_86B02348(void);

s32 func_86B024D0(s32 arg0, GraphNode* arg1);
s32 func_86B02538(s32 arg0, GraphNode* arg1);
void func_86B025A4(void);
void func_86B026C0(void);
void func_86B028F8(void);
void func_86B02908(void);
void func_86B02928(void);
void func_86B0299C(void);
void func_86B02A78(void);
s32 func_86B02B50(void);
void func_86B02C9C(s16 arg0, s16 arg1);
void func_86B02ED0(s16 arg0, s16 arg1);
void func_86B02F34(void);
void func_86B02F8C(void);
void func_86B03048(void);
void func_86B034AC(void);
void func_86B03B9C(void);
s32 func_86B03DF4(void);
Gfx* func_86B040C0(void);
s32 func_86B04200(void);
s32 func_86B042B4(void);
s32 func_86B0434C(void);
void func_86B044A0(void);
void func_86B044B0(void);
void func_86B04500(void);
void func_86B04740(void);
void func_86B04794(void);
void func_86B04880(void);
void func_86B048D8(void);
void func_86B04914(void);
s32 func_86B04944(void);
void func_86B04C9C(void);
void func_86B04CF4(UNUSED s32 arg0);
void func_86B04D48(void);
void func_86B04D98(void);
void func_86B04DF0(void);
void func_86B04EBC(void);
s32 func_86B04FB0(void);

void func_86B05170(u8* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 width, u8 height, u8 uls, u8 ult, u8 lrs, u8 lrt, u8 argB, u8 argC, unk_D_86B0DAE0* argD, s32 argE);
void func_86B05944(s32, s32, s32, s32, s32);

s32 func_86B05CB0(s32 arg0, GraphNode* arg1);
s32 func_86B05D18(s32 arg0, GraphNode* arg1);
s32 func_86B05D84(s32 arg0, GraphNode* arg1);
void func_86B05DA0(u8 arg0, u8 arg1, u8 arg2);
void func_86B05E18(void);
void func_86B05EE8(void);
void func_86B06008(void);
void func_86B06050(void);
void func_86B06100(void);
void func_86B061E8(void);
s32 func_86B0630C(unk_D_86002F58_004_000* arg0, s16 arg1, s16 arg2);
s32 func_86B06394(unk_D_86002F58_004_000* arg0, s16 arg1, s16 arg2);
s32 func_86B06440(void);
void func_86B065C4(void);
void func_86B06960(void);
void func_86B069D8(void);
void func_86B06AB4(unk_D_86B0FA50* arg0, u8* arg1, f32 arg2, s16 arg3, s16 arg4, s16 arg5);
void func_86B06B38(void);
void func_86B06E34(void);
void func_86B06E80(void);
void func_86B06EC8(void);
void func_86B06F18(void);
void func_86B06F60(void);
void func_86B06F74(void);
void func_86B06FCC(void);
s32 func_86B06FFC(void);
s32 func_86B07450(unk_D_86B0FA50* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
void func_86B075EC(void);
void func_86B07DF4(void);
void func_86B07EA0(void);
void func_86B07F14(void);
void func_86B07FA4(void);
void func_86B08034(void);
void func_86B0819C(void);
s32 func_86B08644(void);

s16 func_86B08780(void);
s32 func_86B087A0(u8 arg0, u8* arg1, s32 arg2);
void func_86B087E8(unk_D_86B0FA78* arg0, Vec3f* arg1);
void func_86B088E4(void);
f32 func_86B089B0(f32 arg0, f32 arg1);
void func_86B089E0(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void func_86B08A3C(f32 arg0, f32 arg1);
void func_86B08A58(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void func_86B08AB4(f32 arg0, f32 arg1);
void func_86B08AD0(f32 arg0, f32 arg1);
void func_86B08AEC(unk_D_86B0C160* arg0, unk_D_86002F34_00C* arg1);
s32 func_86B08C44(unk_D_86002F34_00C* arg0);

void func_86B08E50(s32 arg0, s32 arg1);
s32 func_86B08EA8(void);
void func_86B08EB4(void);
Gfx* func_86B08F48(Gfx* gfx, u32 arg1);
void func_86B095C4(void);
void func_86B0961C(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7);
void func_86B097B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8* arg4, UNUSED s32 arg5);
void func_86B09928(u8* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, unk_D_86B0DAE0_000* arg5);
void func_86B09AD8(u8* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);

void func_86B0A0B0(void);
void func_86B0A0B8(void);
void func_86B0A15C(void);
void func_86B0A18C(u8* arg0);
void func_86B0A30C(void);
s32 func_86B0A37C(void);
void func_86B0A414(void);
void func_86B0A47C(void);
s32 func_86B0A554(void);

void func_86B0A750(void);
void func_86B0A7F8(void);
void func_86B0A81C(void);
void func_86B0A824(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7);
void func_86B0B024(void);
void func_86B0B034(void);
s32 func_86B0B040(void);
void func_86B0B0B4(void);
void func_86B0B12C(void);
void func_86B0B184(void);
void func_86B0B498(void);
void func_86B0B4C8(void);
void func_86B0B4D0(u8* arg0);
void func_86B0B650(void);
s32 func_86B0B6C0(void);
void func_86B0B810(void);
void func_86B0B8DC(void);
s32 func_86B0BA18(void);

#endif // _FRAGMENT17_H_
