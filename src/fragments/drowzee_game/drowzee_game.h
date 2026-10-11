#ifndef _FRAGMENT10_H_
#define _FRAGMENT10_H_

#include "global.h"
#include "src/geo_node.h"
#include "src/fragments/minigame_shared_library/minigame_shared_library.h"

typedef struct unk_D_86404778 {
    /* 0x000 */ s32 unk_000;
    /* 0x004 */ s32 unk_004;
    /* 0x008 */ s16 unk_008;
    /* 0x00A */ s16 unk_00A;
    /* 0x00C */ u8 unk_00C;
    /* 0x00E */ s16 unk_00E;
    /* 0x010 */ s16 unk_010;
    /* 0x012 */ s16 unk_012;
    /* 0x014 */ u8 unk_014;
    /* 0x015 */ u8 unk_015;
    /* 0x016 */ char unk016[0x2];
    /* 0x018 */ s32 unk_018;
    /* 0x01C */ u8 unk_01C;
    /* 0x020 */ s32 unk_020;
    /* 0x024 */ u8 unk_024;
    /* 0x028 */ DisplayObject unk_028;
    /* 0x190 */ unk_D_86002F34_alt9* unk_190;
    /* 0x194 */ u16 unk_194[14][8];
    /* 0x274 */ u8 unk_274;
} unk_D_86404778; // size = 0x278

typedef struct unk_D_86405158 {
    /* 0x000 */ u8 unk_000;
    /* 0x001 */ u8 unk_001;
    /* 0x004 */ DisplayObject unk_004;
    /* 0x16C */ u8 unk_16C;
    /* 0x16D */ u8 unk_16D;
} unk_D_86405158; // size = 0x170

extern u8 D_86402848;
extern u16 D_864029F0[4][14][8];
extern Gfx D_86403FA0[];
extern Gfx D_86403BB0[];
extern Gfx D_86403F30[];

void DrowzeeGame_UpdatePlayerTimingWindows(void);
u16 DrowzeeGame_IsWindowMatch(u8 arg0);
void DrowzeeGame_SetPlayerState(unk_D_86404778* arg0, s32 arg1, u8 arg2, s32 arg3, u8 arg4);
void DrowzeeGame_InitPlayerSlots(void);
void DrowzeeGame_LoopDrowzeeIdleAnim(void);
void DrowzeeGame_AdvanceBreathPhase(unk_D_86405158* arg0);
void DrowzeeGame_UpdatePlayerAnimations(void);
void DrowzeeGame_ProcessElimination(u8 arg0);
void DrowzeeGame_DrawPlayerOverlay(UNUSED s32 arg0);
void DrowzeeGame_UpdateRoundTick(s32 arg0);
void DrowzeeGame_JudgePlayerTiming(void);
void DrowzeeGame_DrawTutorialScreen(s32 arg0);
void DrowzeeGame_DrawFrame(s32 arg0);
void DrowzeeGame_WaitForStart(void);
void DrowzeeGame_MainLoop(void);
void DrowzeeGame_ShowResultText(void);
void DrowzeeGame_InitCamera(void);
void DrowzeeGame_InitPlayerOverlays(void);
void DrowzeeGame_LoadAssets(void);
void DrowzeeGame_Main(UNUSED s32 arg0, UNUSED s32 arg1);

s8 DrowzeeGame_ComputeAITimingBias(u8 arg0, s32 arg1);

#endif // _FRAGMENT10_H_
