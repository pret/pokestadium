#ifndef _E890_H_
#define _E890_H_

#include "global.h"

typedef struct unk_D_800AA680 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ void* unk_08;
    /* 0x0C */ s32 unk_0C;
} unk_D_800AA680; // size = 0x10

typedef struct unk_D_800AA690 {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ u16 unk_06;
} unk_D_800AA690; // size = 0x8

extern unk_D_800AA680 D_800AA680;

s32 func_8000DC90(void);
s32 func_8000DD68(unk_D_800AA680* arg0);
s32 func_8000DDB0(void);
s32 func_8000DDE4(void);
s32 func_8000DE18(unk_D_800AA680* arg0);
s32 func_8000DE70(void);
s32 func_8000DED0(void);
s32 func_8000E0EC(void);
s32 func_8000E21C(unk_D_800AA680* arg0);
s32 func_8000E3B4(void);
s32 func_8000E51C(void);
void func_8000E5B4(void);
s32 func_8000E5BC(unk_D_800AA680* arg0);
s32 func_8000E6EC(void);
void func_8000E760(void);
void func_8000E7E4(void);

#endif // _E890_H_
