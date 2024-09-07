#ifndef _29BA0_H_
#define _29BA0_H_

#include "global.h"

typedef struct unk_D_800AE540_0004 {
    /* 0x000 */ char unk000[0x21C];
} unk_D_800AE540_0004; // size = 0x21C

typedef struct unk_D_800AE520 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 fragment_id;
    /* 0x04 */ u8* rom_start;
    /* 0x08 */ u8* rom_end;
    /* 0x0C */ s32 arg0;
    /* 0x10 */ s32 arg1;
    /* 0x14 */ s32 pad14[3];
} unk_D_800AE520; // size >= 0x14

typedef struct unk_D_800AE540 {
    /* 0x0000 */ s8 unk_0000;
    /* 0x0001 */ s8 unk_0001;
    /* 0x0002 */ s8 unk_0002;
    /* 0x0003 */ s8 unk_0003;
    /* 0x0004 */ unk_D_800AE540_0004 unk_0004[1];
    /* 0x0220 */ char unk0220[0xFD2];
    /* 0x11F2 */ u8 unk_11F2;
    /* 0x11F3 */ char unk11F3[0x2];
    /* 0x11F5 */ u8 unk_11F5;
    /* 0x11F6 */ u16 unk_11F6;
    /* 0x11F8 */ char pad11F8[0x8];
} unk_D_800AE540; // size = 0x1200

extern s32 gCurrentGameState;
extern unk_D_800AE520 D_800AE520;
extern unk_D_800AE540 D_800AE540;

s32 Game_DoCopyProtection(s32 state);
s32 func_80029008(s32 arg0, u8* romStart, u8* romEnd, u32 arg3, u32 arg4);
void func_80029048(s32 arg0, u8* arg1, u8* arg2, s32 arg3, s32 arg4);
unk_D_800AE540_0004* func_80029074(void);
s16 func_80029080(void);
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
void Game_Thread(UNUSED void *arg);

#endif // _29BA0_H_
