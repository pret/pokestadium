#ifndef _26820_H_
#define _26820_H_

#include "global.h"
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

void func_80026684(s32, s32);
void func_8002707C(s32 arg0, s32 arg1);
void func_80027F24(unk_func_8002A728*);
void func_80027F40(unk_func_8002A728*);
void func_80027FA0(unk_func_80027FA0*, s16);
void func_80028070(u16*);
void func_800280D4(u8);
void func_80028128(s32);
s32 func_8002816C(void);
void func_8002817C(u8, u8);
void func_800281D4(unk_func_800281D4*, unk_func_80026268_arg0*, u8);
s32 func_80028320(unk_func_800281D4*, unk_func_80026268_arg0*);
s32 func_800284B4(s16);
s32 func_80028AFC(s16);

#endif // _26820_H_
