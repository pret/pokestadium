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

extern Gfx D_8140DAE0[];
extern Gfx D_8140DB30[];

extern MtxF* D_8140E620;
extern s32 D_8140E624;
extern Vec3f D_8140E628;

extern unk_D_8140E720* D_8140E720;
extern unk_D_8140E728* D_8140E728;
extern s32 D_8140E72C;
extern s32 D_8140E734;

void func_81400930(Vec3f*, Vec3f*);
void func_8140094C(Vec3s*, Vec3s*);
u32 func_81400A78(s32);
s32 func_81400B00(s32);

void func_81406204(Gfx*, s32, s32, s32, s32);
void func_81406288(Gfx*, s32, s32, s32, s32);
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
