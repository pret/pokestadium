#ifndef _FRAGMENT33_H_
#define _FRAGMENT33_H_

#include "global.h"

typedef struct unk_D_81304008 {
    /* 0x000 */ s16 unk_000;
    /* 0x002 */ s16 unk_002;
    /* 0x004 */ s16 unk_004;
    /* 0x006 */ char unk006[0x2];
    /* 0x008 */ s16 unk_008;
    /* 0x00A */ s16 unk_00A;
    /* 0x00C */ s16 unk_00C;
    /* 0x00E */ s16 unk_00E;
    /* 0x010 */ s16 unk_010;
    /* 0x014 */ f32 unk_014;
    /* 0x018 */ f32 unk_018;
    /* 0x01C */ u8* unk_01C;
    /* 0x020 */ f32 unk_020;
    /* 0x020 */ f32 unk_024;
    /* 0x020 */ unk_D_86002F58_004_000 unk_028;
} unk_D_81304008; // size = 0x190

typedef struct unk_D_81303FA8 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ char unk05[0x1];
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ char unk_08[1];
    /* 0x09 */ char unk09[0xD];
} unk_D_81303FA8; // size = 0x16

s32 func_81300020(s32 arg0, GraphNode* arg1);
s32 func_813001C0(void);
void func_813001EC(void);
s32 func_81300254(s32 arg0);
s32 func_81300314(s32 arg0);
void func_813003B4(s32 arg0, s32 arg1, s32 arg2);
void func_81300870(u8* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, f32 arg5);
void func_81300DA4(void);
void func_81300DF8(u8* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, f32 arg5, s16 arg6);
void func_81301668(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7);
void func_81301E8C(void);
void func_8130222C(void);
void func_8130237C(void);
void func_81302498(void);
void func_813024C8(s32 arg0);
void func_81302548(void);
void func_81302630(void);
void func_81302798(void);
s32 func_81302A70(s32 arg0);
void func_81302C20(void);
void func_81302DD8(void);
s32 func_81302E58(s32 arg0, s32 arg1);
void func_8130306C(u8* arg0);
void func_8130337C(void);

#endif // _FRAGMENT33_H_
