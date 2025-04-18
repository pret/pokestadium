#ifndef _FRAGMENT57_H_
#define _FRAGMENT57_H_

#include "global.h"
#include "src/6BC0.h"
#include "src/11BA0.h"
#include "src/26820.h"

typedef struct unk_D_82D0AB38 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ char unk_08[1];
    /* 0x09 */ char unk09[0xD];
} unk_D_82D0AB38; // size = 0x16

typedef struct unk_D_82D0ABD0 {
    /* 0x00 */ u8 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ char unk0C[0x4];
} unk_D_82D0ABD0; // size = 0x10

typedef struct unk_D_82D09F1C {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s8 unk_08;
    /* 0x09 */ s8 unk_09;
    /* 0x0A */ s8 unk_0A;
    /* 0x0B */ s8 unk_0B;
} unk_D_82D09F1C; // size = 0xC

s32 func_82D00020(s32 arg0);
void func_82D00088(void);
void func_82D002C4(unk_D_80068BB0* arg0, s16 arg1, s16 arg2);
void func_82D0053C(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7);
void func_82D00D3C(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7);
void func_82D0153C(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7);
s32 func_82D01758(s32 arg0, unk_func_80011B94* arg1);
s32 func_82D0180C(s32 arg0, unk_func_80011B94* arg1);
s32 func_82D018AC(s32 arg0, unk_func_80011B94* arg1);
void func_82D0194C(s32 arg0);
void func_82D01AB4(s16 arg0);
void func_82D021B4(s32 arg0);
void func_82D022E8(u8 arg0);
void func_82D02454(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8* arg4);
void func_82D02870(s32 arg0);
void func_82D029E0(void);
void func_82D02D94(void);
void func_82D02ED0(s32 arg0, s16 arg1);
void func_82D02FB8(void);
void func_82D03120(void);
s32 func_82D03174(void);
void func_82D03340(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7);
void func_82D03B40(s16 arg0, s16 arg1, s16 arg2, s16 arg3, char* arg4);
void func_82D03BCC(s16 arg0, s16 arg1);
void func_82D03DC0(s16 arg0, s16 arg1, unk_func_800281D4* arg2, s32 arg3);
void func_82D043CC(s16 arg0, s16 arg1, unk_func_800281D4* arg2, s16 arg3, s16 arg4);
s32 func_82D0442C(unk_func_800281D4* arg0);
s16 func_82D04590(unk_func_800281D4* arg0);
void func_82D04904(unk_D_82D0ABD0* arg0);
s32 func_82D04C20(unk_D_82D0ABD0* arg0);
void func_82D04CF4(unk_D_82D0ABD0* arg0, s16 arg1, s16 arg2);
void func_82D04D24(unk_D_82D0ABD0* arg0, s16 arg1, s16 arg2);
s32 func_82D04D50(s32 arg0, UNUSED unk_func_80011B94* a1);
s32 func_82D04EB8(void);
void func_82D04FA0(s32 arg0, s32 arg1);
void func_82D05258(s32 arg0, s32 arg1);
void func_82D053F4(s32 arg0, s32 arg1);
unk_D_80068BB0* func_82D0580C(s32 arg0);
unk_D_80068BB0* func_82D05A5C(void);
unk_D_80068BB0* func_82D05BE0(void);
unk_D_80068BB0* func_82D05D64(void);
unk_D_80068BB0* func_82D05EE8(s8* arg0, u8 arg1, u8 arg2, u8 arg3);
void func_82D06014(void);
void func_82D06388(void);
s32 func_82D063E4(void);
s32 func_82D0670C(void);
s16 func_82D067A0(void);
void func_82D06AB0(void);
void func_82D06B98(void);
s32 func_82D06D0C(s32 arg0, s32 arg1);

#endif // _FRAGMENT57_H_
