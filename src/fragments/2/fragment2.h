#ifndef _FRAGMENT2_H_
#define _FRAGMENT2_H_

#include "global.h"

typedef struct unk_func_87801684 {
    /* 0x00 */ u32* unk_00;
    /* 0x04 */ s16 unk_04;
} unk_func_87801684; // size = 0x8

extern char** D_87806330;
extern s16 D_87806338;
extern u32* D_8780633C[];
extern u32* D_8780634C[];

extern u16 D_8780FA28;
extern s16 D_8780FA2A;
extern s16 D_8780FA2C;
extern s16 D_8780FA30[4];
extern s16 D_8780FA38;
extern s16 D_8780FA3A;
extern s16 D_8780FA40[4];
extern s16 D_8780FA48;
extern s16 D_8780FA68[4];
extern u32* D_8780FA70;
extern u16 D_8780FC92;
extern u16 D_8780FC94;
extern u16 D_8780FC96;
extern u16 D_8780FC98;


void func_87800020(void);
void func_8780005C(void);
void func_878001D0(void);
u32 func_878001E8(u32 arg0);
void func_8780024C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_878009BC(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_878010C8(s16 arg0);
void func_8780118C(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void func_87801290(s32* arg0, s32* arg1, char* arg2, char* arg3, s32 arg4);
s32 func_878013D4(UNUSED unk_D_800AC870* arg0, char* arg1);
void func_87801400(s32 arg0, s16 arg1, s16 arg2, f32 arg3, f32 arg4);
void func_87801644(s32 arg0, s16 arg1, s16 arg2, f32 arg3);
void func_87801684(s16 arg0, s16 arg1, unk_func_87801684* arg2);
void func_87801754(s16 arg0, s16 arg1, unk_func_87801684* arg2);
void func_87801824(s16 arg0, s16 arg1, unk_func_87801684* arg2);
void func_878018F4(s16 arg0, s16 arg1, unk_func_87801684* arg2);
void func_87801AC0(s16 arg0, s16 arg1, unk_func_87801684* arg2);
void func_87801C8C(s16 arg0, s16 arg1, unk_func_87801684* arg2);
void func_87801D5C(s16 arg0, s16 arg1, s16 arg2, unk_func_87801684* arg3);
void func_87801F48(s16 arg0, s16 arg1, s16 arg2);
void func_878021B4(s16 arg0, s16 arg1);

void func_87802360(s16 arg0, s16 arg1, f32* arg2, f32* arg3);
void func_87802528(void);
void func_878025D0(void);
void func_8780295C(s16 arg0);
s32 func_87802974(void);

void func_878029C0(void);
void func_87802E1C(void);
void func_87802E58(void);
void func_87802EB8(s16 arg0);
void func_87802F00(s32 arg0);
void func_87802F4C(void);
s32 func_87802FA0(void);
void func_8780304C(void);
s32 func_87803118(void);
void func_87803200(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8* arg4, u8* arg5);
void func_87803280(Mtx* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 argA);
void func_87803368(s16 arg0);
void func_878038B8(s32 arg0, u32* arg1, u8 arg2, u8 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, f32 arg8, f32 arg9, f32 argA, f32 argB, f32 argC, f32 argD, f32 argE);
void func_87803EAC(u32* arg0, u16 arg1, UNUSED u16 arg2, u16 arg3, u16 arg4, u8 arg5, u8 arg6);
void func_87804320(u8 arg0, s8 arg1, s8 arg2, s8 arg3, s8 arg4);
void func_87804AD0(s16 arg0);
s32 func_87804FD4(void);

#endif // _FRAGMENT2_H_
