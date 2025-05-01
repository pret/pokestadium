#ifndef _FRAGMENT66_H_
#define _FRAGMENT66_H_

#include "global.h"
#include "src/29BA0.h"

typedef struct unk_D_832025C8 {
    /* 0x000 */ s32 unk_00;
    /* 0x004 */ char unk04[0x1FC];
} unk_D_832025C8; // size = 0x200

typedef struct unk_D_832027C8 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x04 */ unk_func_80026268_arg0 unk_04;
} unk_D_832027C8; // size = 0x58

s32 func_83200020(s32 arg0, unk_D_86002F58_004_000* arg1);
s32 func_83200064(unk_func_80026268_arg0* arg0);
s32 func_832000A0(unk_func_80026268_arg0* arg0, s16 arg1, s16 arg2, s16 arg3);
s32 func_83200148(s16 arg0, s16 arg1, s16 arg2);
s32 func_8320029C(void);
s32 func_8320037C(void);
void func_832003AC(void);
void func_83200468(void);
s32 func_8320058C(u8 arg0);
void func_832005E4(s16 arg0, s16 arg1);
void func_83200684(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void func_83200700(s16 arg0, s16 arg1);
void func_832007A4(char* arg0, s32 arg1);
void func_8320084C(char* arg0, s32 arg1);
void func_83200934(s8* arg0);
s32 func_83200ADC(char* arg0);
s32 func_83200CD8(char* arg0);
void func_83200FF8(void);
void func_832010BC(void);
void func_8320118C(void);
s32 func_8320126C(void);
s32 func_83201450(void);
void func_832016F4(s32 arg0);
void func_832018DC(void);
void func_83201A18(s32 arg0);
void func_83201B60(void);
void func_83201BD8(unk_D_86002F58_004_000* arg0, s16 arg1, s16 arg2, s16 arg3);
void func_83201C8C(void);
s32 func_83201DD4(UNUSED s32 arg0, UNUSED s32 arg1);

#endif // _FRAGMENT66_H_
