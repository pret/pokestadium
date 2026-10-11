#ifndef _FRAGMENT66_H_
#define _FRAGMENT66_H_

#include "global.h"
#include "src/game_state.h"

typedef struct unk_D_832025C8 {
    /* 0x000 */ s32 unk_00;
    /* 0x004 */ char unk04[0x1FC];
} unk_D_832025C8; // size = 0x200

typedef struct unk_D_832027C8 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x04 */ BattleMon unk_04;
} unk_D_832027C8; // size = 0x58

s32 PikachuReward_PositionSurfingPikachuModel(s32 arg0, DisplayObject* arg1);
s32 PikachuReward_CheckNoSpecialMove(BattleMon* arg0);
s32 PikachuReward_CheckEligibleForSurf(BattleMon* arg0, s16 arg1, s16 arg2, s16 arg3);
s32 PikachuReward_SearchDeckForPikachu(s16 arg0, s16 arg1, s16 arg2);
s32 PikachuReward_FindPikachuOnCart(void);
s32 PikachuReward_CountKnownMoves(void);
void PikachuReward_UpdateLeadPikachuAnimation(void);
void PikachuReward_UpdateFollowerVisibility(void);
s32 PikachuReward_RenderFrame(u8 arg0);
void PikachuReward_DrawBlinkingStarIcon(s16 arg0, s16 arg1);
void PikachuReward_DrawTextBoxPanel(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void PikachuReward_DrawSelectionCursor(s16 arg0, s16 arg1);
void PikachuReward_ShowTextForFrames(char* arg0, s32 arg1);
void PikachuReward_ShowTextWaitForA(char* arg0, s32 arg1);
void PikachuReward_ScrollTextIn(s8* arg0);
s32 PikachuReward_ConfirmYesNoPrompt(char* arg0);
s32 PikachuReward_SelectMoveToForget(char* arg0);
void PikachuReward_ShowDeclinedEnding(void);
void PikachuReward_ShowSuccessEnding(void);
void PikachuReward_PlayIntroCamera(void);
s32 PikachuReward_ShowIntroAndConfirm(void);
s32 PikachuReward_ResolveMoveSlot(void);
void PikachuReward_ShowSaveStatusScreen(s32 arg0);
void PikachuReward_SaveToCartridge(void);
void PikachuReward_TeachSurfToPikachu(s32 arg0);
void PikachuReward_RunSequence(void);
void PikachuReward_SetupFollowerModel(DisplayObject* arg0, s16 arg1, s16 arg2, s16 arg3);
void PikachuReward_SetupScene(void);
s32 Stadium_BonusPikachuReward(UNUSED s32 arg0, UNUSED s32 arg1);

#endif // _FRAGMENT66_H_
