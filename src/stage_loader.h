#ifndef _STAGE_LOADER_H_
#define _STAGE_LOADER_H_

#include "global.h"

typedef struct unk_D_800A7450 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ Gfx* unk_04;
    /* 0x08 */ Gfx* unk_08;
    /* 0x0C */ void* unk_0C;
    /* 0x10 */ char unk10[0x4];
} unk_D_800A7450; // size >= 0x14

typedef struct unk_func_80007444_018 {
    /* 0x00 */ char unk00[0x4];
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ char unk0C[0x4];
} unk_func_80007444_018; // size = 0x10

typedef struct unk_func_80007444 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s8 unk_0C;
    /* 0x0D */ s8 unk_0D;
    /* 0x0E */ s8 unk_0E;
    /* 0x0F */ s8 unk_0F;
    /* 0x10 */ s8 unk_10;
    /* 0x11 */ u8 unk_11;
    /* 0x12 */ u8 unk_12;
    /* 0x13 */ u8 unk_13;
    /* 0x14 */ u16 unk_14;
    /* 0x16 */ s8 unk_16;
    /* 0x18 */ unk_func_80007444_018* unk_18[3];
} unk_func_80007444; // size = 0x24

void func_800069F0(void);
s32 func_80006C04(s32 arg0);
s32 func_80006C6C(s32 arg0);
s32 func_80006CB4(s32 arg0);
void func_80006CF8(s32 arg0);
void func_80006D28(u32 arg0, u32 arg1);
void func_80006D50(void);
void func_80006F34(void);
void func_80006F98(void);
void func_80006FE8(void);
void func_80007234(void);
void func_8000725C(void);
void func_80007304(void);
unk_func_80007444* func_80007444(s8 arg0, s8 arg1, s8 arg2, s8 arg3, s8 arg4, s32 arg5);
unk_func_80007444* func_800075F8(void);
s32 func_80007604(void);
void func_80007614(unk_func_80007444* arg0);
void func_80007678(unk_func_80007444* arg0);
void func_800076C0(void);
void func_8000771C(void);
void func_80007754(void);
s32 func_80007778(void);
void func_800077B4(s32 arg0);
s32 func_80007820(u32 arg0, s32 (*arg1)(u8));
s32 func_800078D4(s32 (*arg0)(u8), s32 arg1, s32 arg2);
void func_80007990(u16 arg0);
void func_800079C4(void);
unk_func_80007444_018* func_80007A2C(void);
s32 func_80007A58(void);
void func_80007A80(void);
void func_80007C3C(void);
void func_80007CD8(s16 arg0, s16 arg1, s16 arg2);
void func_80007DE4(s16 arg0, s16 arg1, s16 arg2);
void func_80007EF0(s16 arg0, s16 arg1, s8* arg2, s32 arg3);
void func_80007FC4(Gfx** arg0, s32 arg1);
void func_800080E0(void);
char* func_80008130(char* buffer, const char* data, size_t size);
s32 HAL_Printf(s16 x, s16 y, const char* fmt, ...);
s32 func_800081F8(s16 x, s16 y, const char* fmt, ...);


#endif // _STAGE_LOADER_H_
