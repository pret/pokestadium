#ifndef _2E460_H_
#define _2E460_H_

#include "global.h"
#include "29BA0.h"

typedef struct unk_func_8002D860 {
    /* 0x00 */ char unk00[0x8];
    /* 0x08 */ s32 unk_08;
} unk_func_8002D860; // size >= 0xC

typedef struct ret_func_8002ED08 {
    /* 0x00 */ u8 unk_00[12];
} ret_func_8002ED08; // size = 0xC

typedef struct unk_func_8820E99C_030_030 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
} unk_func_8820E99C_030_030; // size = 0x14

typedef struct unk_func_8830867C_044_038_030 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
} unk_func_8830867C_044_038_030; // size = 0x14

void func_8002D860(unk_func_8002D860*, s32);
void func_8002D8C8(unk_func_88500020*, s32, s32);
s32 func_8002DF68(unk_func_8830867C_044_038_030*, s32);
s32 func_8002EC08(s32);
s32 func_8002ECDC(unk_func_80026268_arg0*);
s32 func_8002E0F4(unk_func_8820E99C_030_030*);
void func_8002E5A0(s32, s32, s32, s32);
void func_8002E8E4(s32, s32, s32, s32);
unk_D_80072B00* func_8002ED40(s32);
s32 func_8002EE1C(s32, s32, s32);
void func_8002EE78(void);
void func_8002EEA8(OSMesg);
ret_func_8002ED08* func_8002ED08(s32);
s32 func_8002ED78(unk_func_80026268_arg0*, s32);
s32 func_8002EDEC(s32);
void func_8002EEEC(void);
void func_8002EF18(s32*);
void func_8002EF44(void);
s32 func_8002F1C0(u8);
s32 func_8002F264(s32);

#endif // _2E460_H_
