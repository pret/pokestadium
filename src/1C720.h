#ifndef _1C720_H_
#define _1C720_H_

#include "global.h"
#include "src/29BA0.h"

typedef struct unk_func_8001C014 {
	/* 0x00 */ char unk_00[0x2];
	/* 0x02 */ u16 unk_02;
	/* 0x04 */ s8 unk_04[0x10];
	/* 0x14 */ s8 unk_14[0x10];
} unk_func_8001C014; // size >= 0x24

typedef struct unk_func_8001C248 {
    /* 0x000 */ unk_D_86002F58_004_000_000 unk_000;
    /* 0x018 */ s16 unk_018;
    /* 0x01A */ s16 unk_01A;
    /* 0x01C */ u8 unk_01C;
    /* 0x01D */ u8 unk_01D;
    /* 0x01E */ char unk01E[0x2];
    /* 0x020 */ s32 unk_020;
    /* 0x024 */ s32* unk_024;
} unk_func_8001C248; // size >= 0x28

void func_8001BB20(void);
void func_8001BB58(unk_D_86002F58_004_000* arg0);
void func_8001BBC8(unk_D_86002F58_004_000* arg0);
void func_8001BC34(unk_D_86002F58_004_000* arg0, s16 arg1, s16 arg2, unk_D_86002F58_004_000_004* arg3);
void func_8001BCF0(unk_D_86002F58_004_000* arg0);
s32 func_8001BD04(unk_D_86002F58_004_000* arg0, s32 arg1);
s32 func_8001BD9C(unk_D_86002F58_004_000* arg0, s32 arg1);
void func_8001BE34(unk_D_86002F58_004_000* arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4);
void func_8001BE78(unk_D_86002F58_004_000* arg0, u8 arg1);
void func_8001BE84(unk_D_86002F58_004_000* arg0, u8 arg1);
unk_D_86002F58_004_000_00C_028* func_8001BE90(unk_D_86002F58_004_000* arg0, s32 arg1);
arg1_func_80010CA8* func_8001BEE8(arg1_func_80010CA8* arg0, unk_func_80026268_arg0* arg1);
void func_8001C014(arg1_func_80010CA8* arg0, unk_func_8001C014* arg1, u16 arg2);
void func_8001C07C(unk_D_800AE540_1194* arg0);
void func_8001C198(unk_func_8001C248* arg0);
void func_8001C1E8(unk_func_8001C248* arg0);
void func_8001C248(unk_func_8001C248* arg0);
void func_8001C2D8(unk_func_8001C248* arg0);

#endif // _1C720_H_
