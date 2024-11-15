#ifndef _26820_H_
#define _26820_H_

#include "global.h"
#include "22630.h"
#include "29BA0.h"

typedef struct unk_func_8002A728 {
    /* 0x00 */ s16 unk_00;
    /* 0x04 */ struct unk_func_8002A728* unk_04;
} unk_func_8002A728; // size = 0x8

typedef struct unk_func_80027FA0 {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ char unk02[0x2];
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ char unk05[0x2];
    /* 0x07 */ u8 unk_07;
} unk_func_80027FA0; // size = 0x8

typedef struct unk_func_800281D4 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05[2][4];
    /* 0x0D */ u8 unk_0D;
    /* 0x0E */ u16 unk_0E;
    /* 0x10 */ char unk_10[16];
} unk_func_800281D4; // size >= 0x20

void func_80025C20(UNUSED MainPoolBlock* arg0, u32 arg1);
u16 func_80025C80(u8* arg0, s32 arg1);
s32 func_80025CBC(u8* arg0, s32 arg1);
void func_80025D30(u8* arg0, s32 arg1, s32 arg2);
void func_80025DA0(u8* arg0, u8* arg1, s32 arg2, s32 arg3);
void func_80025DE4(u8* arg0, s32 arg1, s32 arg2);
void func_80025E44(u8* arg0, s32 arg1, s32 arg2);
void func_80025EA0(u8* arg0, s32 arg1, s32 arg2);
void func_80025EF8(u8* arg0, s32 arg1, s32 arg2);
void func_80025F50(s32 arg0, s32 arg1);
void func_80026268(unk_func_80026268_arg0* arg0, unk_D_800AE4E8_004_1_000_010* arg1);
void func_800262DC(unk_func_80026268_arg0* arg0, unk_D_800AE4E8_004_1_000_010* arg1);
s32 func_80026338(s32 arg0, s32 arg1, s16 arg2);
void func_800264DC(s32 arg0, s32 arg1, s16 arg2);
void func_8002667C(void);
void func_80026684(s32 arg0, s32 arg1);
void func_8002685C(s32 arg0, s32 arg1);
void func_80026A34(s32 arg0, s32 arg1);
void func_80026C0C(s32 arg0, s32 arg1);
void func_8002707C(s32 arg0, s32 arg1);
s32 func_800270AC(s32 arg0);
s32 func_80027108(s32 arg0);
s32 func_80027164(s32, s32);
s32 func_80027184(s32, s32);
void func_800272BC(s32, s32, char*);
s16 func_800275E0(s32 arg0, s32 arg1);
s32 func_8002797C(s32 arg0, s32 arg1, s32 arg2, void* arg3);
s32 func_80027C24(s32 arg0, s32 arg1, s32 arg2, void* arg3);
void func_80027F24(unk_func_8002A728* arg0);
void func_80027F40(unk_func_8002A728* arg0);
void func_80027FA0(unk_func_80027FA0* arg0, s16 arg1);
void func_80028070(u16* arg0);
void func_800280D4(u8 arg0);
s32 func_8002816C(void);
void func_8002817C(u8, u8);
s32 func_800284B4(s16 arg0);
s32 func_8002873C(s16 arg0, u32 arg1);
void func_80028840(void);
void func_800288F4(void);
void func_800289AC(void);
void func_80028A74(void);
s32 func_80028AFC(s16 arg0);

#endif // _26820_H_
