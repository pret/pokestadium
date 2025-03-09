#ifndef _FRAGMENT43_H_
#define _FRAGMENT43_H_

#include "global.h"
#include "30640.h"

typedef struct unk_D_83402E4C {
    /* 0x00 */ s16 unk_00;
    /* 0x00 */ s16 unk_02;
    /* 0x00 */ s16 unk_04;
    /* 0x00 */ s16 unk_06;
    /* 0x00 */ s8 unk_08;
    /* 0x00 */ s8 unk_09;
    /* 0x00 */ s16 unk_0A;
    /* 0x00 */ s16* unk_0C;
} unk_D_83402E4C; // size = 0x10

extern unk_D_83402EE0 D_83402EE0[24];
extern s32 D_83403C00[24];
extern unk_D_83403C60 D_83403C60[36];
extern unk_D_83403C60 D_834063C0[21];
extern unk_D_83403C60* D_83407ABC;
extern unk_D_83403C60* D_83407AC0;
extern unk_D_83407AC8 D_83407AC8;
extern s32 D_83407AE4;
extern s32 D_83407AE8;
extern s32 D_83407AEC;
extern unk_D_83407B00 D_83407AF8;
extern unk_D_83407B00 D_83407B00;
extern unk_D_83407B00 D_83407B08;
extern unk_D_83407B00 D_83407B10;
extern unk_D_83407B00 D_83407B18;
extern unk_D_83407B00 D_83407B20;
extern unk_D_83407B00 D_83407B28;
extern unk_D_83407B00 D_83407B30;
extern unk_D_83407B38 D_83407B38;

extern s32 D_83402E20;
extern s32 D_83402E24;
extern s32 D_83402E28;

void func_83400020(void);
s32 func_834002C4(unk_D_83406EB0* arg0);
s32 func_834002E4(unk_D_83406EB0* arg0);
s32 func_83400304(unk_D_83403C60* arg0, unk_D_83403C60* arg1, s32 arg2);
s32 func_83400334(void);
s32 func_83400410(s32 arg0, s32 arg1);
void func_8340051C(void);
void func_83400524(void);
void func_83400570(unk_D_83403C60* arg0);
void func_83400590(unk_D_83403C60* arg0, unk_D_83403C60* arg1);
s32 func_83400660(unk_D_83403C60* arg0, unk_D_83403C60* arg1);
void func_83400694(unk_D_83403C60* arg0);
unk_D_83403C60* func_834006A0(s32 arg0);
void func_834006BC(unk_D_83407B00* arg0);
s32 func_834006CC(s8* arg0);
s32 func_83400704(unk_D_83403C60* arg0, s32 arg1, s32 arg2);
s32 func_834007B4(unk_D_83403C60* arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_83400870(unk_D_83403C60* arg0, s32 arg1);
void func_834008DC(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_83400928(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7);
void func_83401110(s32 arg0, s32 arg1, s32 arg2, Color_RGBA8* arg3, Color_RGBA8* arg4);
void func_8340144C(u16* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
void func_834016C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_83401728(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_83401818(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_834018C0(u16* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void func_83401B48(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_83401D0C(s32 arg0, s32 arg1, s32 arg2);
void func_83401D68(unk_D_83407B38* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, unk_D_86002F58_004_000_010* arg5,
    BinArchive* arg6, unk_D_83403C60* arg7, s32 arg8, s32 arg9);
void func_83401FD0(unk_D_83407B38* arg0);
void func_834020D8(void);
s32 func_83402124(unk_D_83407B38* arg0, s32 arg1);
void func_834021C8(unk_D_83407B00* arg0);
void func_834021D8(unk_D_83407B38* arg0, unk_D_83407B00* arg1);
void func_834021EC(unk_D_83407B38* arg0, unk_D_83407B00* arg1);
void func_83402210(unk_D_83407B38* arg0, s32* arg1, s32* arg2, s32 arg3);
s32 func_83402280(unk_D_83407B38* arg0, s32 arg1, s32 arg2);
void func_83402298(unk_D_83407B38* arg0, unk_D_86002F58_004_000_010* arg1, BinArchive* arg2);

void func_83402340(void);
char* func_83402374(s32 arg0);
char* func_834023A4(char* arg0, s32 arg1, s32 arg2);
char* func_834023CC(s32 arg0);
char* func_834023FC(char* arg0, s32 arg1, u32 arg2);

void func_83402430(unk_D_83402E4C* arg0, s16 arg1);
void func_834024C4(unk_D_83402E4C* arg0);
void func_834026A4(unk_D_83402E4C* arg0);
void func_83402834(unk_D_83402E4C* arg0);
void func_834028C4(void);
void func_834028D0(UNUSED s32 arg0);
void func_83402A38(void);
void func_83402BF4(void);
void func_83402C34(void);
s32 func_83402C6C(void);
s32 func_83402CE4(s16 arg0, Controller* arg1);
s32 func_83402D74(s16 arg0);
s16 func_83402DC8(s16 arg0);

#endif // _FRAGMENT43_H_
