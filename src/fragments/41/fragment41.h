#ifndef _FRAGMENT41_H_
#define _FRAGMENT41_H_

#include "global.h"
#include "src/1AB70.h"
#include "src/29BA0.h"

typedef struct unk_func_82F00838_sp30_00C {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ char unk01[0xD];
    /* 0x0E */ u16 unk_0E;
    /* 0x10 */ char unk10[0x14];
    /* 0x24 */ u8 unk_24;
    /* 0x25 */ char unk25[0xB];
    /* 0x30 */ char unk_30[11];
    /* 0x3B */ char unk_3B[11];
    /* 0x46 */ char unk46[0xA];
    /* 0x50 */ s32 force_align;
} unk_func_82F00838_sp30_00C; // size = 0x54

typedef struct unk_D_82F144D0_0CA8 {
    /* 0x000 */ s16 unk_000;
    /* 0x004 */ struct unk_D_82F144D0_0CA8* unk_004;
    /* 0x008 */ struct unk_D_82F144D0_0CA8* unk_008;
    /* 0x00C */ unk_func_82F00838_sp30_00C unk_00C[20];
} unk_D_82F144D0_0CA8; // size = 0x69C

typedef struct unk_D_82F144D0 {
    /* 0x0000 */ s16 unk_0000;
    /* 0x0002 */ s16 unk_0002;
    /* 0x0004 */ s16 unk_0004;
    /* 0x0006 */ s16 unk_0006;
    /* 0x0008 */ s16 unk_0008;
    /* 0x000A */ s16 unk_000A;
    /* 0x000C */ s16 unk_000C;
    /* 0x000E */ s16 unk_000E;
    /* 0x0010 */ s16 unk_0010;
    /* 0x0012 */ s16 unk_0012;
    /* 0x0014 */ s16 unk_0014;
    /* 0x0016 */ s16 unk_0016;
    /* 0x0018 */ s16 unk_0018;
    /* 0x001A */ s16 unk_001A;
    /* 0x001C */ s16 unk_001C;
    /* 0x001E */ s16 unk_001E;
    /* 0x0020 */ s16 unk_0020;
    /* 0x0022 */ char unk0022[0x6];
    /* 0x0028 */ u16 unk_0028[0x640];
    /* 0x0CA8 */ unk_D_82F144D0_0CA8 unk_0CA8[13];
    /* 0x6294 */ char unk6294[0x4];
} unk_D_82F144D0; // size = 0x6298

typedef struct unk_func_82F00838_sp30 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0C */ unk_func_82F00838_sp30_00C* unk_0C;
} unk_func_82F00838_sp30; // size = 0x10

typedef struct unk_D_82F14450 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ char unk_08[1];
    /* 0x09 */ char unk09[0xD];
} unk_D_82F14450; // size = 0x16

typedef struct unk_D_82F13B78 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ char* unk_04;
} unk_D_82F13B78; // size = 0x8

typedef struct unk_D_82F20A10 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 unk_10;
    /* 0x14 */ unk_func_80026268_arg0* unk_14;
    /* 0x18 */ unk_D_82F144D0* unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ unk_D_86002F58_004_000_010* unk_20;
    /* 0x24 */ unk_func_8001B1FC* unk_24;
} unk_D_82F20A10; // size >= 0x28

typedef struct unk_D_82F20A40_00E {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
} unk_D_82F20A40_00E; // size = 0x8

typedef struct unk_D_82F20A40 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ unk_D_82F20A40_00E unk_06;
    /* 0x0E */ unk_D_82F20A40_00E unk_0E[3];
    /* 0x26 */ unk_D_82F20A40_00E unk_26;
    /* 0x2E */ unk_D_82F20A40_00E unk_2E;
    /* 0x36 */ unk_D_82F20A40_00E unk_36;
    /* 0x40 */ unk_D_82F20A40_00E* unk_40;
    /* 0x44 */ unk_D_82F20A40_00E* unk_44;
} unk_D_82F20A40; // size = 0x48

typedef struct unk_D_82F20A88 {
    /* 0x000 */ s16 unk_000;
    /* 0x002 */ s16 unk_002;
    /* 0x004 */ s16 unk_004;
    /* 0x006 */ s16 unk_006;
    /* 0x008 */ s16 unk_008;
    /* 0x00A */ s16 unk_00A;
    /* 0x00C */ s16 unk_00C;
    /* 0x00E */ s16 unk_00E;
    /* 0x010 */ s16 unk_010;
    /* 0x012 */ s16 unk_012;
    /* 0x014 */ s16 unk_014;
    /* 0x018 */ f32 unk_018;
    /* 0x01C */ f32 unk_01C;
    /* 0x020 */ f32 unk_020;
    /* 0x024 */ u8* unk_024;
    /* 0x028 */ unk_D_86002F58_004_000 unk_028;
} unk_D_82F20A88; // size = 0x190

typedef struct unk_D_82F210E0 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ unk_D_82F20A40_00E unk_14[2];
    /* 0x24 */ unk_D_82F20A40_00E unk_24;
    /* 0x2C */ unk_D_82F20A40_00E unk_2C;
    /* 0x34 */ unk_D_82F20A40_00E unk_34;
} unk_D_82F210E0; // size = 0x3C

typedef struct unk_D_82F21160 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
} unk_D_82F21160; // size = 0x20

typedef struct unk_D_82F21140 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ u16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ u16 unk_14;
    /* 0x16 */ u16 unk_16;
    /* 0x18 */ s16 unk_18;
} unk_D_82F21140; // size = 0x1C

typedef struct unk_D_82F211A0_010 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
} unk_D_82F211A0_010; // size = 0x6

typedef struct unk_D_82F211A0 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x00 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ unk_D_82F211A0_010 unk_10[10];
} unk_D_82F211A0; // size = 0x4C

typedef struct unk_D_82F21238 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s16 unk_16;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ s16 unk_1E;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ unk_func_80026268_arg0* unk_24;
    /* 0x28 */ unk_D_86002F58_004_000_010* unk_28;
    /* 0x2C */ unk_func_8001B1FC* unk_2C;
    /* 0x30 */ unk_D_82F20A40_00E unk_30;
} unk_D_82F21238; // size = 0x38

extern s32 D_82F14424;
extern unk_D_82F14450 D_82F14450[4];

extern char** D_82F13B70;
extern char** D_82F13B74;

char* func_82F00020(s32 arg0);
char* func_82F00058(s32 arg0);
char* func_82F00090(s32 arg0);
void func_82F000C8(s16 arg0);
void func_82F00138(void);
void func_82F00164(void);
void func_82F00284(void);
void func_82F002BC(s16 arg0, s16 arg1, s8* arg2, s32 arg3);
void func_82F0036C(void);
void func_82F00378(unk_D_82F13B78* arg0, s32 arg1);
s32 func_82F003F8(unk_D_82F13B78* arg0);
void func_82F00424(void);
s32 func_82F00524(void);
void func_82F00568(void);
void func_82F00704(void);
void func_82F00734(void);
void func_82F00838(void);
void func_82F00960(void);
void func_82F00968(void);
void func_82F00A58(void);
void func_82F00AC8(s32 arg0);
void func_82F00C14(s16 arg0);
void func_82F00C50(void);
void func_82F00CE0(void);
void func_82F00D3C(void);
void func_82F00E88(void);
void func_82F00F3C(void);
void func_82F00FD8(void);
s32 func_82F0109C(void);
void func_82F01180(void);
s32 func_82F01234(s32 arg0, s32 arg1);

s16 func_82F01390(unk_D_82F144D0* arg0, s16 arg1);
u16* func_82F014E4(u8* arg0, s16 arg1, s16 arg2);
void func_82F01530(s32 arg0, s16 arg1);
s32 func_82F018F8(void);
void func_82F01920(unk_D_82F144D0* arg0);
void func_82F01A70(unk_D_82F144D0* arg0);
void func_82F01FE4(unk_D_82F144D0* arg0);
void func_82F020B4(unk_D_82F144D0* arg0);
void func_82F02180(unk_D_82F144D0* arg0);
void func_82F022DC(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void func_82F02544(s16 arg0, s16 arg1, s16 arg2);
void func_82F028AC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, Color_RGB8* arg4, s16 arg5);
void func_82F029FC(s16 arg0, s16 arg1, s16 arg2);
void func_82F02B5C(s16 arg0, s16 arg1, s16 arg2);
void func_82F02CE8(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void func_82F02EAC(s16 arg0, s16 arg1, s16 arg2);
void func_82F02FEC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7);
void func_82F037EC(s16, s16, s16, s16, u8, u8, u8, u8);
void func_82F04010(s16 arg0, s16 arg1, u8* arg2, s16 arg3);
void func_82F040D0(unk_D_82F144D0* arg0, s16 arg1, s16 arg2, s32 arg3);
void func_82F043A4(s16 arg0, s16 arg1, s16 arg2);
void func_82F04604(unk_D_82F144D0* arg0);
void func_82F04FD4(void);
void func_82F0504C(void);
void func_82F05110(void);
u16* func_82F05198(s32);
void func_82F051B8(void);
s32 func_82F0525C(s32 arg0, unk_func_82F00838_sp30* arg1);

void func_82F05210(s16, unk_func_80026268_arg0*);
void func_82F052F0(unk_D_82F144D0* arg0, u8* arg1, s16 arg2, s16 arg3);
void func_82F053F8(unk_D_82F20A10* arg0);
void func_82F05560(unk_D_82F20A10* arg0);
void func_82F056D0(unk_D_82F20A10* arg0);
void func_82F05828(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6);
void func_82F05920(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6);
void func_82F05C50(s16 arg0, s16 arg1, s32 arg2);
void func_82F05D74(s16 arg0, s16 arg1, s16 arg2);
s32 func_82F05F20(s32 arg0);
void func_82F05F40(unk_D_82F20A10* arg0);
void func_82F06D50(void);
void func_82F06D88(void);
void func_82F06E04(void);
s32 func_82F06E38(void);

s32 func_82F06E50(s32 arg0, GraphNode* arg1);
s16 func_82F06F9C(unk_D_82F14450* arg0);
void func_82F07004(s16 arg0);
void func_82F07214(unk_D_82F20A88* arg0, s16 arg1);
void func_82F07440(unk_D_82F20A88* arg0);
void func_82F07498(unk_D_82F20A88* arg0);
void func_82F0761C(unk_D_82F20A88* arg0);
void func_82F0763C(unk_D_82F20A88* arg0);
void func_82F07728(unk_D_82F20A88* arg0);
void func_82F07784(unk_D_82F20A88* arg0);
void func_82F077E0(void);
void func_82F07958(void);
s32 func_82F07A54(s16 arg0);
s32 func_82F07A74(void);
void func_82F07A80(unk_D_82F20A40* arg0, s32 arg1);
void func_82F07DEC(unk_D_82F20A40* arg0);
void func_82F08084(unk_D_82F20A40* arg0);
void func_82F081FC(unk_D_82F20A40* arg0);
void func_82F0822C(unk_D_82F20A40* arg0);
void func_82F083B0(unk_D_82F20A40* arg0, s16 arg1, s16 arg2);
void func_82F084EC(unk_D_82F20A40* arg0);
void func_82F0856C(unk_D_82F20A40* arg0);
void func_82F0866C(unk_D_82F20A40* arg0);
void func_82F087F8(unk_D_82F20A40_00E* arg0, s16 arg1, s16 arg2);
void func_82F088F8(unk_D_82F20A40* arg0);
void func_82F08968(unk_D_82F20A40* arg0);
void func_82F08B7C(unk_D_82F20A40* arg0);
void func_82F08EB4(unk_D_82F20A40* arg0);
void func_82F0917C(unk_D_82F20A40* arg0);
void func_82F09284(unk_D_82F20A40* arg0);
void func_82F094B4(unk_D_82F20A40* arg0);
void func_82F097D8(s16 arg0, s16 arg1);
void func_82F09B70(s16 arg0);
void func_82F09C6C(void);
void func_82F09D2C(void);
void func_82F09E30(void);

s32 func_82F09EB0(unk_func_82F00838_sp30* arg0);
s32 func_82F09F44(unk_D_82F210E0* arg0);
void func_82F0A0A8(s32 arg0);
void func_82F0A23C(unk_D_82F210E0* arg0);
void func_82F0A5F8(unk_D_82F210E0* arg0);
void func_82F0A804(unk_D_82F210E0* arg0);
void func_82F0A850(unk_D_82F210E0* arg0);
void func_82F0A950(unk_D_82F210E0* arg0);
void func_82F0AA50(unk_D_82F210E0* arg0);
void func_82F0AB68(unk_D_82F210E0* arg0);
void func_82F0ACC4(unk_D_82F210E0* arg0);
void func_82F0B2A4(s16 arg0, s16 arg1, s16 arg2);
void func_82F0B3E0(unk_D_82F210E0* arg0);
void func_82F0B7B4(unk_D_82F210E0* arg0);
void func_82F0BBE8(unk_D_82F210E0* arg0);
void func_82F0BD38(unk_D_82F210E0* arg0);
void func_82F0BE7C(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void func_82F0BEF8(unk_D_82F210E0* arg0);
s32 func_82F0C16C(void);
s32 func_82F0C178(void);
s32 func_82F0C184(void);
void func_82F0C190(void);
void func_82F0C254(void);
void func_82F0C320(void);

void func_82F0C410(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s32 arg8);
void func_82F0C630(void);
void func_82F0C658(s32 arg0, s16 arg1);
void func_82F0C784(unk_D_82F211A0* arg0);
void func_82F0C7FC(unk_D_82F211A0* arg0);
void func_82F0C8EC(unk_D_82F211A0* arg0);
void func_82F0C958(unk_D_82F211A0* arg0);
void func_82F0CA7C(unk_D_82F211A0* arg0);
void func_82F0CB90(void);
void func_82F0CC3C(void);
void func_82F0D084(void);
void func_82F0D090(unk_D_82F21238* arg0, s32 arg1);
void func_82F0D160(s16 arg0);
void func_82F0D27C(unk_D_82F21238* arg0);
void func_82F0D2F4(unk_D_82F21238* arg0);
s32 func_82F0D3F4(s32 arg0);
void func_82F0D428(unk_D_82F21238* arg0);
void func_82F0D51C(unk_D_82F21238* arg0);
s32 func_82F0D64C(s16 arg0, s8* arg1);
void func_82F0D6D0(s16 arg0, unk_func_80026268_arg0* arg1);
void func_82F0D76C(unk_D_82F21238* arg0);
void func_82F0D834(unk_D_82F21238* arg0);
void func_82F0DA60(unk_D_82F21238* arg0);
void func_82F0DCF4(void);
void func_82F0DD90(s16 arg0, s16 arg1, s16 arg2);
void func_82F0E5C8(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void func_82F0E97C(unk_D_82F21238* arg0);
void func_82F0ECA4(void);
void func_82F0ECAC(unk_D_82F20A40_00E* arg0, unk_func_80026268_arg0* arg1);
void func_82F0EE58(void);
void func_82F0EF68(void);
void func_82F0EFC4(s32 arg0, s16 arg1);
void func_82F0F260(unk_D_82F21160* arg0);
void func_82F0F2AC(unk_D_82F21160* arg0);
void func_82F0F374(unk_D_82F21160* arg0);
void func_82F0F578(unk_D_82F21160* arg0);
void func_82F0F600(unk_D_82F21160* arg0);
void func_82F0F654(unk_D_82F21160* arg0);
void func_82F0F714(unk_D_82F21160* arg0);
void func_82F0F79C(unk_D_82F21160* arg0);
void func_82F0F89C(void);
void func_82F0F9E0(s16 arg0, s16 arg1, f32 arg2, s16 arg3);
void func_82F0FCC0(void);
s32 func_82F0FDCC(void);
void func_82F0FDEC(s16 arg0);
void func_82F10034(unk_D_82F21140* arg0);
void func_82F10110(unk_D_82F21140* arg0);
void func_82F101C8(unk_D_82F21140* arg0);
void func_82F10348(unk_D_82F21140* arg0);
void func_82F10400(unk_D_82F21140* arg0);
void func_82F10454(unk_D_82F21140* arg0);
void func_82F1050C(unk_D_82F21140* arg0);
void func_82F10674(unk_D_82F21140* arg0);
void func_82F10710(unk_D_82F21140* arg0);
void func_82F10744(unk_D_82F21140* arg0);
void func_82F10818(unk_D_82F21140* arg0);
void func_82F1084C(unk_D_82F21140* arg0);
void func_82F1091C(unk_D_82F21140* arg0);
void func_82F10950(unk_D_82F21140* arg0);
void func_82F10A24(unk_D_82F21140* arg0);
void func_82F10BB4(s16 arg0, s16 arg1, f32 arg2);
void func_82F10ED0(s16 arg0, s16 arg1, f32 arg2, s16 arg3, s16 arg4, s16 arg5);
void func_82F11264(s16 arg0, s16 arg1, f32 arg2, s16 arg3, s16 arg4, s16 arg5);
void func_82F115F8(s16 arg0, s16 arg1, f32 arg2, s16 arg3, s16 arg4, s16 arg5);
void func_82F1198C(s16 arg0, s16 arg1, f32 arg2, s16 arg3, s16 arg4, s16 arg5);
void func_82F11D68(s16 arg0, s16 arg1, f32 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6);
void func_82F1228C(s16 arg0, s16 arg1, f32 arg2, s16 arg3, s16 arg4, s16 arg5);
void func_82F12614(void);
void func_82F12DE4(s16 arg0, s16 arg1, f32 arg2, s16 arg3, s16 arg4, s16 arg5);
void func_82F13278(void);
void func_82F132D0(void);
void func_82F13414(void);
s32 func_82F13964(s16 arg0);
void func_82F13B4C(s16 arg0);
s16 func_82F13B64(void);

#endif // _FRAGMENT41_H_
