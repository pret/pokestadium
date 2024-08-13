#ifndef _1C720_H_
#define _1C720_H_

#include "global.h"
#include "19840.h"

typedef struct unk_func_8001C014 {
	/* 0x00 */ char unk_00[0x2];
	/* 0x02 */ u16 unk_02;
	/* 0x04 */ s8 unk_04[0x10];
	/* 0x14 */ s8 unk_14[0x10];
} unk_func_8001C014; // size >= 0x24

typedef struct unk_func_8001BEE8 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ char unk01[0xD];
    /* 0x0E */ u16 unk_0E;
    /* 0x10 */ char unk10[0x20];
    /* 0x30 */ char unk_30[0xB];
    /* 0x3B */ char unk_3B[0xB];
    /* 0x48 */ char unk46[0xC];
    /* 0x52 */ u8 unk_52;
} unk_func_8001BEE8; // size >= 0x54

typedef struct unk_func_8001C07C_arg0 {
    /* 0x00 */ u8 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ unk_func_8001BEE8* unk_04;
    /* 0x08 */ char unk_08[0x8];
    /* 0x10 */ unk_D_86002F58_004_010* unk_10;
    /* 0x14 */ s32 unk_14;
} unk_func_8001C07C_arg0; // size >= 0x18

void func_8001BB20(void);
void func_8001BB58(unk_D_86002F58_004* arg0);
void func_8001BBC8(unk_D_86002F58_004* arg0);
void func_8001BC34(unk_D_86002F58_004* arg0, s16 arg1, s16 arg2, unk_D_86002F58_004* arg3);
void func_8001BCF0(unk_D_86002F58_004* arg0);
s32 func_8001BD04(unk_D_86002F58_004* arg0, s32 arg1);
s32 func_8001BD9C(unk_D_86002F58_004* arg0, s32 arg1);
void func_8001BE34(unk_D_86002F58_004* arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4);
void func_8001BE78(unk_D_86002F58_004* arg0, u8 arg1);
void func_8001BE84(unk_D_86002F58_004* arg0, u8 arg1);
unk_D_86002F58_004_00C_028* func_8001BE90(unk_D_86002F58_004* arg0, s32 arg1);
void func_8001BEE8(s32* arg0, unk_func_8001BEE8* arg1);
void func_8001C014(s32* arg0, unk_func_8001C014* arg1, u16 arg2);
void func_8001C07C(unk_func_8001C07C_arg0* arg0);
void func_8001C198(unk_func_8001C248* arg0);
void func_8001C1E8(unk_func_8001C248* arg0);
void func_8001C248(unk_func_8001C248* arg0);
void func_8001C2D8(unk_func_8001C248* arg0);

#endif // _1C720_H_
