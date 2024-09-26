#ifndef _FRAGMENT34_H_
#define _FRAGMENT34_H_

#include "global.h"

typedef void (*func_unk_D_8140E720_008)(struct unk_D_8140E720*);

typedef struct unk_D_8140E728_01C_004 {
    /* 0x00 */ u8 unk_00;
} unk_D_8140E728_01C_004; 

typedef struct unk_D_8140E728_01C {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ unk_D_8140E728_01C_004* unk_04;
} unk_D_8140E728_01C; // size >= 0x8

typedef struct unk_D_8140E728 {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ Vec3f unk_04;
    /* 0x10 */ Vec3s unk_10;
    /* 0x18 */ func_unk_D_8140E720_008 unk_18;
    /* 0x1C */ unk_D_8140E728_01C* unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ u16 unk_24;
    /* 0x26 */ s16 unk_26;
    /* 0x28 */ s16 unk_28;
    /* 0x2A */ s8 unk_2A;
    /* 0x2B */ s8 unk_2B;
    /* 0x2C */ u8 unk_2C;
    /* 0x2D */ u8 unk_2D;
    /* 0x2E */ u8 unk_2E;
    /* 0x2F */ u8 unk_2F;
} unk_D_8140E728; // size = 0x30

typedef struct unk_D_8140E720 {
    /* 0x00 */ struct unk_D_8140E720* next;
    /* 0x04 */ char unk04[0x4];
    /* 0x08 */ func_unk_D_8140E720_008 unk_08;
    /* 0x0C */ unk_D_8140E728_01C* unk_0C;
    /* 0x10 */ char unk10[0x8];
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ char unk1C[0xC];
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ char unk2C[0x4];
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ char unk34[0x20];
    /* 0x54 */ f32 unk_54;
    /* 0x58 */ char unk58[0x10];
    /* 0x68 */ Vec3f unk_68;
    /* 0x74 */ char unk74[0x20];
    /* 0x94 */ Vec3s unk_94;
    /* 0x9A */ char unk9A[0x10];
    /* 0xAA */ s16 unk_AA;
    /* 0xAC */ s16 unk_AC;
    /* 0xAE */ char unkAE[0x4];
    /* 0xB2 */ s16 unk_B2;
    /* 0xB4 */ char unkB4[0x19];
    /* 0xCD */ u8 unk_CD;
    /* 0xCE */ u8 unk_CE;
    /* 0xCF */ u8 unk_CF;
    /* 0xD0 */ s8 unk_D0;
} unk_D_8140E720; // size = 0xD4

typedef struct arg1_func_8140213C {
    /* 0x00 */ char unk00[0x64];
    /* 0x64 */ MtxF unk_64;
} arg1_func_8140213C; // size >= 0xA4

typedef struct arg1_func_87903D64_014 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ unk_D_86002F34_000_014_004* unk_04;
    /* 0x08 */ unk_D_86002F34_000_014_004* unk_08;
    /* 0x0C */ unk_D_86002F34_000_014_004* unk_0C;
    /* 0x10 */ unk_D_86002F34_000_014_010* unk_10;
    /* 0x14 */ unk_D_86002F34_000_014_010* unk_14;
    /* 0x18 */ unk_D_86002F34_000_014_010* unk_18;
} arg1_func_87903D64_014;

// Possibly unk_D_86002F34_alt7, unk_D_86002F34_alt8,
// unk_D_86002F34_alt9 or unk_D_86002F34_alt2
typedef struct arg1_func_87903D64 {
    /* 0x00 */ char unk00[0x14];
    /* 0x00 */ arg1_func_87903D64_014* unk_14;
    /* 0x18 */ Gfx* unk_18;
} arg1_func_87903D64; // size >= 0x1C

typedef struct arg1_func_81407874_014_000_014_000_000 {
    /* 0x00 */ Color_RGBA8 color;
    /* 0x04 */ u8 l;
} arg1_func_81407874_014_000_014_000_000; // size = 0x5

typedef struct arg1_func_81407874_014_000_018_000_000 {
    /* 0x00 */ Color_RGBA8 color;
} arg1_func_81407874_014_000_018_000_000; // size = 0x4

typedef union arg1_func_81407874_014_000_014_000 {
    arg1_func_81407874_014_000_014_000_000* ptr5;
    arg1_func_81407874_014_000_018_000_000* ptr4;
    Color_RGBA8_u32 color;
    u8** texture;
} arg1_func_81407874_014_000_014_000; // size = 0x4

typedef struct arg1_func_81407874_014_000_014 {
    /* 0x00 */ arg1_func_81407874_014_000_014_000 unk_00;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
} arg1_func_81407874_014_000_014; // size >= 0x08

typedef struct arg1_func_81407874_014_000_01C {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u16 unk_02;
} arg1_func_81407874_014_000_01C; // size >= 0x04

typedef struct arg1_func_81407874_014_000 {
    /* 0x00 */ struct arg1_func_81407874_014_000* unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ char unk08[0x8];
    /* 0x10 */ arg1_func_81407874_014_000_010* unk_10;
    /* 0x14 */ arg1_func_81407874_014_000_014* unk_14;
    /* 0x18 */ arg1_func_81407874_014_000_014* unk_18;
    /* 0x1C */ arg1_func_81407874_014_000_01C* unk_1C;
} arg1_func_81407874_014_000; // size >= 0x20

typedef struct arg1_func_81407874_014_004_008 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
} arg1_func_81407874_014_004_008; // size >= 0xA

typedef struct arg1_func_81407874_014_004_004 {
    /* 0x00 */ s16 fmt;
    /* 0x02 */ s16 size;
    /* 0x04 */ s16 width;
    /* 0x06 */ s16 height;
    /* 0x08 */ s16 cms;
    /* 0x0A */ s16 cmt;
    /* 0x0C */ s16 masks;
    /* 0x0E */ s16 maskt;
    /* 0x10 */ s16 shfits;
    /* 0x12 */ s16 shiftt;
} arg1_func_81407874_014_004_004; // size >= 0x14

typedef struct arg1_func_81407874_014_004 {
    /* 0x00 */ arg1_func_81407874_014_000* unk_00;
    /* 0x04 */ arg1_func_81407874_014_004_004* unk_04;
    /* 0x08 */ arg1_func_81407874_014_004_008* unk_08;
    /* 0x0C */ arg1_func_81407874_014_000_014* unk_0C;
} arg1_func_81407874_014_004; // size >= 0x4

typedef struct arg1_func_81407874_014 {
    /* 0x00 */ arg1_func_81407874_014_000* unk_00;
    /* 0x04 */ arg1_func_81407874_014_004* unk_04;
} arg1_func_81407874_014; // size >= 0x8

typedef struct arg1_func_81407874 {
    /* 0x00 */ char unk00[0x14];
    /* 0x00 */ arg1_func_81407874_014* unk_14;
} arg1_func_81407874; // size >= 0x18

extern Gfx D_8140DAE0[];
extern Gfx D_8140DB30[];
extern Gfx D_8140DBA8[];
extern Gfx D_8140DC00[];
extern Gfx D_8140DC58[];
extern Gfx D_8140DC78[];
extern Gfx D_8140DC98[];
extern Gfx D_8140DCB8[];
extern Gfx D_8140DCD8[];
extern Gfx D_8140DCF8[];
extern Gfx D_8140DD18[];
extern Gfx D_8140DD38[];
extern Gfx D_8140DD58[];
extern Gfx D_8140DD78[];
extern Gfx D_8140DDD8[];
extern Gfx D_8140DDF8[];
extern Vtx D_8140DE78[];
extern Vtx D_8140DEF8[];
extern Vtx D_8140DF78[];
extern Vtx D_8140DFA8[];
extern Vtx D_8140DFD8[];
extern Vtx D_8140E018[];
extern Vtx D_8140E058[];
extern Vtx D_8140E098[];
extern Vtx D_8140E0D8[];
extern Vtx D_8140E108[];
extern Vtx D_8140E148[];
extern Vtx D_8140E178[];
extern Vtx D_8140E1B8[];
extern Vtx D_8140E1F8[];
extern Vtx D_8140E238[];
extern Vtx D_8140E2B8[];
extern Vtx D_8140E378[];
extern Vtx D_8140E3B8[];
extern Gfx D_8140E418[];
extern Gfx D_8140E430[];
extern Gfx D_8140E448[];

extern MtxF* D_8140E620;
extern s32 D_8140E624;
extern Vec3f D_8140E628;

extern unk_D_8140E720* D_8140E720;
extern unk_D_8140E728* D_8140E728;
extern s32 D_8140E72C;
extern s32 D_8140E734;

void func_81400020(s32* arg0, s32 arg1);
void func_81400030(s32* arg0, s32 arg1);
void func_81400044(s32* arg0, s32 arg1);
s32 func_81400054(s32* arg0, s32 arg1);
s32 func_81400074(s32* arg0, s32 arg1);
s32 func_81400094(f32* arg0, f32 arg1, f32 arg2);
s32 func_814000E0(f32* arg0, f32 arg1, f32 arg2);
s32 func_8140012C(s32* arg0, s32 arg1, s32 arg2);
s32 func_8140015C(s32* arg0, s32 arg1, s32 arg2);
s32 func_8140018C(s16* arg0, s16 arg1, s16 arg2);
s32 func_814001DC(u16* arg0, u16 arg1, u16 arg2);
s32 func_81400220(s16* arg0, s16 arg1, s16 arg2);
s32 func_81400270(u16* arg0, s32 arg1, s32 arg2);
s32 func_814002A4(f32* arg0, f32 arg1, f32* arg2);
s32 func_814002F0(f32* arg0, f32 arg1, f32* arg2);
s32 func_8140033C(s32* arg0, s32 arg1, s32* arg2);
s32 func_81400374(s32* arg0, s32 arg1, s32* arg2);
s32 func_814003AC(s16* arg0, s16 arg1, s16* arg2);
s32 func_814003F4(s16* arg0, s16 arg1, s16* arg2);
s32 func_8140043C(s8* arg0, s8 arg1, s8 arg2);
s32 func_814004D8(u8* arg0, u8 arg1, u8 arg2);
s32 func_81400550(s16* arg0, s16 arg1, s16 arg2);
s32 func_814005EC(u16* arg0, s16 arg1, s16 arg2);
s32 func_814006CC(s32* arg0, s32 arg1, s32 arg2);
s32 func_81400760(f32* arg0, f32 arg1, f32 arg2);
void func_8140082C(f32* arg0, f32 arg1, f32 arg2, f32* arg3);
void func_814008B0(s16* arg0, s16 arg1, s16 arg2, s16* arg3);
void func_81400930(Vec3f* arg0, Vec3f* arg1);
void func_8140094C(Vec3s* arg0, Vec3s* arg1);
void func_81400968(Vec3f* arg0, Vec3f* arg1);
void func_8140099C(Vec3s* arg0, Vec3s* arg1);
f32 func_814009D0(Vec3f arg0, Vec3f arg1);
s32 func_81400A10(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
void func_81400A60(void);
u32 func_81400A78(s32 arg0);
s32 func_81400ADC(s32 arg0, s32 arg1);
s32 func_81400B00(s32 arg0);
s32 func_81400B28(s32 arg0, s32 arg1);
s32 func_81400B4C(s32 arg0, s32 arg1);
void func_81400B84(UNUSED s32 arg0);
void func_81400B8C(Vec3f arg0);
void func_81400BBC(Vec3f arg0);
void func_81400BEC(Vec3f arg0);
void func_81400C1C(Vec3s* arg0, Vec3f arg1);
f32 func_81400C80(f32 arg0, f32 arg1, s16 arg2);
f32 func_81400CC0(f32 arg0, f32 arg1, s16 arg2);
Vec3f* func_81400D00(Vec3f* arg0, Vec3f arg1, u16 arg4);
Vec3f* func_81400D6C(Vec3f* arg0, f32 arg1, s16 arg2);
Vec3f* func_81400DC0(Vec3f* arg0, Vec3f arg1, Vec3s arg4);
f32 func_81400E8C(Vec3f arg0, Vec3f arg1);
f32 func_81400EF0(Vec3f arg0, Vec3f arg1);
Vec3f* func_81400F44(Vec3f* arg0, Vec3f arg1, Vec3f arg2);
s32 func_81400FA4(Vec3f arg0, Vec3f arg1, f32 arg2);
s32 func_81401020(Vec3f* arg0, Vec3f arg1, Vec3f arg2, f32 arg3);
Vec3f* func_814010D8(Vec3f* arg0, f32 arg1);
Vec3f* func_81401168(Vec3f* arg0, f32 arg1);
s16 func_8140119C(Vec3f arg0, Vec3f arg1);
s16 func_814011E0(Vec3f arg0, Vec3f arg1);
s16 func_81401224(Vec3f arg0, Vec3f arg1);
s16 func_81401268(s16 arg0, s16 arg1);
void func_8140138C(void);
void func_81401394(MtxF* arg0);
void func_81401430(MtxF* arg0, s16 arg1, s16 arg2, s16 arg3, f32 arg4);
void func_814014E8(MtxF* arg0, s16 arg1, s16 arg2, s16 arg3, f32 arg4);
void func_814015A0(s16 arg0, s16 arg1, s16 arg2, f32 arg3);
void func_814015F8(s16 arg0, s16 arg1, s16 arg2, f32 arg3);
void func_81401650(MtxF* arg0, Vec3f arg1, Vec3s arg2, f32 arg3);
void func_814017E0(MtxF* arg0, Vec3f arg1, Vec3s arg2, f32 arg3);
void func_81401940(MtxF* arg0, Vec3f arg1, Vec3s arg2, f32 arg3, f32 arg4);
void func_81401ABC(MtxF* arg0, MtxF* arg1, Vec3f arg2, f32 arg3);
void func_81401B6C(MtxF* arg0, MtxF* arg1, Vec3f arg2, f32 arg3);
void func_81401C04(MtxF* arg0, MtxF* arg1, Vec3f arg2, f32 arg3, s16 arg4);
void func_81401D50(MtxF* arg0, MtxF* arg1, Vec3f arg2, f32 arg3, s16 arg4);
void func_81401E84(MtxF* arg0, Vec3f arg1, Vec3f arg2, s16 arg3, f32 arg4);
void func_81401FC0(Vec3f arg0, Vec3s arg1, f32 arg2);
void func_8140203C(Vec3f arg0, Vec3s arg1, f32 arg2);
void func_814020B8(Vec3f arg0, Vec3s arg1, f32 arg2, f32 arg3);
void func_8140213C(arg1_func_8140213C* arg0, Vec3f arg1, f32 arg4);
void func_814021A4(arg1_func_8140213C* arg0, Vec3f arg1, f32 arg4, s16 arg5);
void func_81402214(arg1_func_8140213C* arg0, Vec3f arg1, f32 arg4);
void func_8140227C(arg1_func_8140213C* arg0, Vec3f arg1, f32 arg4, s16 arg5);
void func_814022EC(Vec3f arg0, Vec3s arg3, f32 arg5);
void func_8140238C(Vec3f arg0, Vec3f arg3, f32 arg6);


void func_81402410(void);
void func_81402434(void);
s32 func_81402494(s32 size);
void func_814024C0(void);
void func_814024C8(void);
void func_814024D0(void);
void func_814024D8(void);
void func_814024E0(void);
void func_814024E8(void);
void func_814024F0(void);
void func_814024F8(void);
void func_81402500(u8* texture, s32 fmt, s32 width, s32 height, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt);
void func_81402784(u8* texture, s32 fmt, s32 width, s32 height, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt);
void func_8140297C(u8* texture, s32 fmt, s32 width, s32 height, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt);
void func_81402C1C(u8* texture, s32 fmt, s32 width, s32 height, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt);
void func_81402E14(u8* texture, s32 fmt, s32 width, s32 height, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt);
void func_814030C0(u8* texture, s32 fmt, s32 width, s32 height, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt);
void func_814032B4(u8* texture, s32 fmt, s32 width, s32 height, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt);
void func_8140353C(u8* texture, s32 fmt, s32 width, s32 height, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt);
void func_81403A20(u8* texture, s32 width, s32 height);
void func_81403A6C(u8* texture, s32 width, s32 height);
void func_81403AB8(u8* texture, s32 width, s32 height);
void func_81403B04(u8* texture1, u8* texture2, s32 width, s32 height);
void func_81403D20(u8* texture, s32 width, s32 height);
void func_81403D80(u8* texture, s32 width, s32 height);
void func_81403DE0(u8* texture, s32 width, s32 height);
void func_81403E50(u8* texture, s32 width, s32 height, s32 masks);
void func_81403EA8(u8* texture, s32 width, s32 height);
void func_81403EF4(u8* texture, s32 width, s32 height);
void func_81403F40(u8* texture, s32 width, s32 height);
void func_81403F8C(u8* texture, s32 width, s32 height);
void func_81403FD8(u8* texture, s32 width, s32 height);
void func_81404024(u8* texture, s32 width, s32 height);
void func_81404094(u8* texture, s32 width, s32 height);
void func_814040E0(u8* texture, s32 width, s32 height);
void func_81404150(u8* texture, s32 width, s32 height);
void func_8140419C(u8* texture, s32 width, s32 height);
void func_814041BC(u8* texture, s32 width, s32 height);
void func_814041DC(u8* texture, s32 width, s32 height);
void func_81404228(u8* texture, s32 width, s32 height);
void func_81404274(u8* texture, s32 width, s32 height);
void func_814042C0(u8* texture, s32 width, s32 height);
void func_8140430C(u8* texture, s32 width, s32 height);
void func_8140437C(u8* texture, s32 width, s32 height);
void func_8140439C(u8* texture, s32 width, s32 height);
void func_814043BC(u8* texture, s32 width, s32 height);
void func_8140441C(u8* texture, s32 width, s32 height);
void func_81404484(u8* texture, s32 width, s32 height);
void func_814044FC(u8* texture, s32 width, s32 height, s32 shifts, s32 shiftt);
void func_81404580(u8* texture, s32 width, s32 height);
void func_814045CC(u8* texture, s32 width, s32 height, s32 masks);
void func_81404624(u8* texture, s32 width, s32 height);
void func_81404670(u8* texture1, u8* texture2, s32 width, s32 height);
void func_81404A6C(Vtx* arg0);
void func_81404AB4(void);
void func_81404ABC(Vec3f arg0, Vec3s arg1, f32 arg2, Vtx* arg3);
void func_81404B78(Vec3f arg0, Vec3s arg1, f32 arg3, Vtx* arg4);
void func_81404C34(Vec3f arg0, Vec3s arg1, f32 arg2, f32 arg3, Vtx* arg4);
void func_81404CF8(Vec3f arg0, Vec3s arg1, f32 arg2, Vtx* arg3);
void func_81404DB4(arg1_func_8140213C* arg0, Vec3f arg1, f32 arg2, Vtx* arg3);
void func_81404E4C(arg1_func_8140213C* arg0, Vec3f arg1, f32 arg2, Vtx* arg3, s16 arg4);
void func_81404EEC(arg1_func_8140213C* arg0, Vec3f arg1, f32 arg2, Vtx* arg3);
void func_81404F84(arg1_func_8140213C* arg0, Vec3f arg1, f32 arg2, Vtx* arg3, s16 arg4);
void func_81405024(arg1_func_8140213C* arg0, Vec3f arg1, f32 arg2, Vtx* arg3);
void func_814050BC(arg1_func_8140213C* arg0, Vec3f arg1, f32 arg2, Vtx* arg3, s16 arg4);
void func_8140515C(u8* texture, Vtx* vtx, s32 arg2, s32 arg3, s32 width, s32 height);
void func_81405308(u8* texture, Vtx* vtx, s32 arg2, s32 arg3, s32 width, s32 height);
void func_814054B4(u8* texture, Vtx* vtx, s32 arg2, s32 arg3, s32 width, s32 height);
void func_81405660(u8* texture, Vtx* vtx, s32 arg2, s32 arg3, s32 width, s32 height);
void func_81405814(u8* texture, Vtx* vtx, s32 arg2, s32 arg3, s32 width, s32 height);
void func_814059C8(u8 r, u8 g, u8 b, u8 a);
void func_81405A20(u8 r, u8 g, u8 b, u8 a);
void func_81405A90(u8 r, u8 g, u8 b, u8 a);
void func_81405B00(u8 r, u8 g, u8 b, u8 a);
void func_81405B70(u8 r, u8 g, u8 b, u8 a);
void func_81405C04(u8 a);
void func_81405C70(u8 prim_r, u8 prim_g, u8 prim_b, u8 env_r, u8 env_g, u8 env_b, u8 prim_a);
void func_81405D38(u8 prim_r, u8 prim_g, u8 prim_b, u8 env_r, u8 env_g, u8 env_b, u8 prim_a);
void func_81405E04(u8 prim_r, u8 prim_g, u8 prim_b, u8 prim_a, u8 env_r, u8 env_g, u8 env_b, u8 env_a);
void func_81405ED8(u8 l, u8 prim_r, u8 prim_g, u8 prim_b, u8 prim_a, u8 env_r, u8 env_g, u8 env_b);
void func_81405FAC(u8 l, u8 prim_r, u8 prim_g, u8 prim_b, u8 prim_a, u8 env_r, u8 env_g, u8 env_b);
u32 func_81406080(s32 arg0);
void func_814060D4(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_81406168(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_81406204(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_81406288(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_81406314(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_81406388(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_81406404(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
void func_814064B0(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
void func_8140679C(Gfx* gfx, u8* texture, s32 width, s32 height);
Gfx* func_814067F0(Gfx* arg0, u8* texture, arg1_func_81407874_014_004* arg2, s32 tmem, s32 rtile);
Gfx* func_814072B0(Gfx* arg0, arg1_func_81407874_014_004* arg1, s32 tmem, s32 rtile);
Gfx* func_81407410(Gfx* arg0, arg1_func_81407874_014* arg1);
Gfx* func_8140743C(Gfx* arg0, arg1_func_81407874_014* arg1);
void func_81407484(Gfx* arg0, arg1_func_81407874_014_000_010* arg1);
Gfx* func_81407590(Gfx* arg0, arg1_func_81407874_014* arg1);
void func_81407874(s32 arg0, arg1_func_87903D64* arg1);


void func_81407B04(unk_D_8140E720*);
unk_D_8140E720* func_81407B3C(void);
unk_D_8140E720* func_81407B5C(s32);
void func_81408150(unk_D_8140E720*);
void func_81408158(unk_D_8140E720*);
s32 func_81408180(unk_D_8140E720*);
s32 func_8140819C(unk_D_8140E720*);
void func_814081BC(unk_D_8140E720*);
void func_81408328(unk_D_8140E720*);
void func_81408348(unk_D_8140E720*);
s32 func_81408368(unk_D_8140E720*);
void func_814084D8(unk_D_8140E720*, s32, s32, s32, s32, s32);
void func_81408AF0(unk_D_8140E720*);
void func_81408E18(unk_D_8140E720*, f32, f32, f32);
void func_8140935C(unk_D_8140E720*, s32, s32);
void func_81409404(unk_D_8140E720*, s32, s32);
void func_81409514(unk_D_8140E720*, s32, s32);
void func_8140959C(unk_D_8140E720*, s32, s32, s32);
void func_81409BDC(unk_D_8140E720*);
void func_81409C6C(unk_D_8140E720*);
void func_81409CBC(unk_D_8140E720*);
void func_81409FD8(unk_D_8140E720*);
void func_8140A24C(unk_D_8140E720*, Vec3s);
void func_8140A4F0(unk_D_8140E720*, Vec3s);
void func_8140A594(unk_D_8140E720*, s16);
void func_8140AD8C(unk_D_8140E720*, f32);
void func_8140ADA4(unk_D_8140E720*, f32);
void func_8140ADBC(unk_D_8140E720*, f32, f32);
void func_8140AF24(unk_D_8140E720*, f32);
void func_8140B0A4(unk_D_8140E720*, f32, f32);
void func_8140B180(unk_D_8140E720*, f32, f32);
void func_8140B2B4(unk_D_8140E720*);
void func_8140B938(unk_D_8140E720*, f32);
void func_8140B95C(unk_D_8140E720*, f32);
void func_8140B974(unk_D_8140E720*, f32);
void func_8140B98C(unk_D_8140E720*, f32, f32);
s32 func_8140BA48(unk_D_8140E720*);
void func_8140BAC8(unk_D_8140E720*, s32, s32, s32);
void func_8140BB74(unk_D_8140E720*, s32, s32, s32);
s32 func_8140BDAC(unk_D_8140E720*);
s32 func_8140BDD0(unk_D_8140E720*);
void func_8140BC20(unk_D_8140E720*, s32);
void func_8140BCA8(unk_D_8140E720*, s32);
s16 func_8140C038(unk_D_8140E720*);
void func_8140C040(unk_D_8140E720*);
void func_8140C204(unk_D_86002F34_00C*, Gfx**);


void func_8140C5D0(void);
void func_8140D5A0(unk_D_8140E720*, s32);

#endif // _FRAGMENT34_H_
