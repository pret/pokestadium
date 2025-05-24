#ifndef _29BA0_H_
#define _29BA0_H_

#include "global.h"
#include "3FB0.h"
#include "src/controller.h"
#include "PR/leo.h"

typedef struct unk_D_800AE520 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 fragment_id;
    /* 0x04 */ u8* rom_start;
    /* 0x08 */ u8* rom_end;
    /* 0x0C */ s32 arg0;
    /* 0x10 */ s32 arg1;
} unk_D_800AE520; // size >= 0x14

typedef struct unk_func_80026268_arg0_000 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
} unk_func_80026268_arg0_000; // size = 0x2

typedef struct unk_func_80026268_arg0 {
    /* 0x00 */ unk_func_80026268_arg0_000 unk_00;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ u8 unk_06;
    /* 0x07 */ u8 unk_07;
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ u8 unk_09[4];
    /* 0x0E */ u16 unk_0E;
    /* 0x10 */ u32 unk_10;
    /* 0x14 */ u16 unk_14;
    /* 0x16 */ u16 unk_16;
    /* 0x18 */ u16 unk_18;
    /* 0x1A */ u16 unk_1A;
    /* 0x1C */ u16 unk_1C;
    /* 0x1E */ u16 unk_1E;
    /* 0x20 */ u8 unk_20[4];
    /* 0x24 */ u8 unk_24;
    /* 0x25 */ u8 unk_25;
    /* 0x26 */ u16 unk_26;
    /* 0x28 */ u16 unk_28;
    /* 0x2A */ u16 unk_2A;
    /* 0x2C */ u16 unk_2C;
    /* 0x2E */ u16 unk_2E;
    /* 0x30 */ u8 unk_30[11];
    /* 0x3B */ u8 unk_3B[11];
    /* 0x46 */ u8 unk_46[11];
    /* 0x51 */ char unk51[0x1];
    /* 0x52 */ u8 unk_52;
    /* 0x52 */ u8 unk_53;
} unk_func_80026268_arg0; // size = 0x54

typedef struct unk_D_800AE540_0874 {
    /* 0x000 */ u16 unk_000;
    /* 0x002 */ u8 unk_002;
    /* 0x003 */ u8 unk_003;
    /* 0x004 */ char unk004[0x10];
    /* 0x014 */ char unk_014[4];
    /* 0x018 */ char unk018[0x10];
    /* 0x028 */ unk_func_80026268_arg0 unk_028[1];
    /* 0x07C */ char unk07C[0x1A4];
    /* 0x220 */ char unk_220[0x4];
    /* 0x224 */ char unk224[0x24];
} unk_D_800AE540_0874; // size = 0x248

typedef struct unk_D_800AE540_0004 {
    /* 0x000 */ u8 unk_000;
    /* 0x001 */ u8 unk_001;
    /* 0x002 */ u8 unk_002;
    /* 0x004 */ Controller* controller;
    /* 0x008 */ char unk_008[4];
    /* 0x00C */ char unk00C[0xC];
    /* 0x018 */ s32 unk_018;
    /* 0x01C */ unk_func_80026268_arg0 unk_01C[6];
    /* 0x214 */ unk_D_800AE540_0874* unk_214;
    /* 0x218 */ char unk218[0x4];
} unk_D_800AE540_0004; // size = 0x21C

typedef struct unk_D_800AE540_1194 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ unk_D_800AE540_0004* unk_04;
    /* 0x04 */ unk_D_800AE540_0004* unk_08[2];
    /* 0x04 */ s32 unk_10;
    /* 0x04 */ unk_D_86002F58_004_000_004* unk_14;
    /* 0x04 */ unk_D_86002F58_004_000_004* unk_18;
    /* 0x1C */ u8 unk_1C;
    /* 0x1D */ u8 unk_1D;
    /* 0x1E */ u8 unk_1E;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ char unk24[0x4];
} unk_D_800AE540_1194; // size = 0x28

typedef struct unk_D_800AE540 {
    /* 0x0000 */ s8 unk_0000;
    /* 0x0001 */ s8 unk_0001;
    /* 0x0002 */ s8 unk_0002;
    /* 0x0003 */ s8 unk_0003;
    /* 0x0004 */ unk_D_800AE540_0004 unk_0004[4];
    /* 0x0874 */ unk_D_800AE540_0874 unk_0874[4];
    /* 0x1194 */ unk_D_800AE540_1194 unk_1194[2];
    /* 0x11E4 */ u8 unk_11E4[2][4];
    /* 0x11EC */ u8 unk_11EC;
    /* 0x11EC */ u8 unk_11ED;
    /* 0x11EC */ u8 unk_11EE;
    /* 0x11EC */ u8 unk_11EF;
    /* 0x11F0 */ u8 unk_11F0;
    /* 0x11F1 */ char unk11F1[0x1];
    /* 0x11F2 */ u8 unk_11F2;
    /* 0x11F3 */ u8 unk_11F3;
    /* 0x11F4 */ u8 unk_11F4;
    /* 0x11F5 */ u8 unk_11F5;
    /* 0x11F6 */ u16 unk_11F6;
} unk_D_800AE540; // size = 0x11F8

extern s32 gCurrentGameState;
extern unk_D_800AE520 D_800AE520;
extern unk_D_800AE540 D_800AE540;
extern BinArchive* D_800AF738;

s32 Game_DoCopyProtection(s32 state);
s32 func_80029008(s32 arg0, u8* romStart, u8* romEnd, u32 arg3, u32 arg4);
void func_80029048(s32 arg0, u8* arg1, u8* arg2, s32 arg3, s32 arg4);
unk_D_800AE540_0004* func_80029074(void);
s32 func_80029080(void);
void func_8002908C(s32 arg0);
void func_800290B4(void);
s32 func_800290E4(s16 arg0);
void func_800291E0(void);
void func_80029310(void);
void func_800293CC(void);
void func_800296AC(void);
void func_800296E0(void);
void func_80029828(void);
void func_80029884(void);
void func_800298D4(void);
void func_80029924(void);
s16 func_80029984(s16 arg0);
void func_80029BC0(void);
s32 func_80029E78(s16 arg0);
void func_8002A06C(void);
s16 func_8002A260(s16 arg0);
void func_8002A400(void);
void func_8002A670(void);
void func_8002A698(void);
void func_8002A6C0(void);
void func_8002A728(void);
s16 func_8002A8A0(s16 arg0, s16 arg1);
void func_8002AAA8(void);
void func_8002ADE8(s32 arg0);
void func_8002AF38(void);
void func_8002B07C(void);
void func_8002B180(void);
void func_8002B244(void);
void func_8002B24C(void);
void func_8002B274(s32 arg0, s32 arg1);
void func_8002B310(void);
void Game_Thread(UNUSED LEODiskID* arg);

#endif // _29BA0_H_
