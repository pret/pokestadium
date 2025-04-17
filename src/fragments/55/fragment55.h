#ifndef _FRAGMENT55_H_
#define _FRAGMENT55_H_

#include "global.h"
#include "src/29BA0.h"

typedef struct unk_D_83003CE0 {
    /* 0x00 */ char* unk_00[29];
    /* 0x74 */ char* unk_74;
    /* 0x78 */ char* unk_78;
    /* 0x7C */ char* unk_7C;
    /* 0x80 */ char* unk_80;
    /* 0x84 */ char* unk_84;
    /* 0x88 */ char* unk_88;
    /* 0x8C */ char* unk_8C;
    /* 0x90 */ char* unk_90;
    /* 0x94 */ char* unk_94;
    /* 0x98 */ char* unk_98;
    /* 0x9C */ char unk9C[0x64];
} unk_D_83003CE0; // size = 0x100

typedef struct unk_D_83079E70_014_000 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
} unk_D_83079E70_014_000; // size = 0x4

typedef struct unk_D_83079E70_000 {
    /* 0x00 */ unk_D_83079E70_014_000 unk_00[6];
    /* 0x18 */ struct unk_D_83079E70_000* unk_18;
    /* 0x1C */ struct unk_D_83079E70_000* unk_1C;
} unk_D_83079E70_000; // size = 0x20

typedef struct unk_D_83079E70 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x10 */ unk_D_83079E70_000* unk_10;
    /* 0x14 */ unk_D_83079E70_000 unk_14[6];
} unk_D_83079E70; // size = 0xD4

extern unk_D_83003CE0 D_83003CE0;
extern unk_D_83003CE0 D_83003DE0;

extern char** D_830039C0;

char* func_83000020(s32 arg0);
void func_83000058(void);
void func_83000130(void);
s16* func_83000160(unk_D_800AE540* arg0);
char* func_830003A4(s8 arg0);
char* func_83000418(s8 arg0);
s32 func_830004BC(s16* arg0);
void func_83000508(void);
void func_8300059C(void);
void func_83000710(void);
void func_83000750(void);
s32 func_830007C4(void);
void func_830007F4(void);
void func_83000A30(void);
void func_83000F10(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void func_83001178(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6);
void func_830014B0(s16 arg0, s16 arg1);
void func_830015EC(s16 arg0, s16 arg1);
void func_830017C0(void);
void func_83001A9C(void);
void func_83001B64(void);
void func_83001C4C(void);
void func_83001CF8(void);
s32 func_83002030(void);
void func_830020D0(void);
s32 func_83002120(UNUSED s32 arg0, UNUSED s32 arg1);

s32 func_83002270(s8* arg0);
void func_830022B0(void);
void func_83002324(void);
void func_83002370(void);
void func_830023B8(void);
void func_830023CC(void);
void func_8300243C(void);
void func_830025F8(s16 arg0);
s32 func_8300269C(void);
s32 func_830026C0(void);

s32 func_830026D0(s16 arg0, s16 arg1);
s16 func_830027C8(s16 arg0);
s32 func_83002848(unk_D_83079E70_000* arg0, s16 arg1, s16 arg2);
unk_D_83079E70_000* func_83002950(unk_D_83079E70_000* arg0, s32 arg1);
s32 func_83002974(unk_D_83079E70* arg0);
s32 func_83002A0C(unk_D_83079E70* arg0);
void func_83002AB4(unk_D_83079E70* arg0);
void func_83002B1C(unk_D_83079E70* arg0);
void func_83002BA4(unk_D_83079E70* arg0);
void func_83002C30(unk_D_83079E70* arg0);
void func_83002C74(s16 arg0, s16 arg1, unk_D_83079E70* arg2);
void func_83002F9C(s16 arg0, s16 arg1);
void func_83003054(s16 arg0, s16 arg1, unk_D_83079E70_000* arg2);
void func_830032D8(s32 arg0);
void func_830033F0(void);
void func_83003484(void);
void func_830038DC(void);
s32 func_83003988(void);
s32 func_830039AC(void);


#endif // _FRAGMENT55_H_
