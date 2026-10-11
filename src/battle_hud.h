#ifndef _32D10_H_
#define _32D10_H_

#include "global.h"

extern u8 D_800AF770[8];
extern s16 D_800AF778[4];
extern s16 D_800AF780[4];
extern s16 D_800AF788[4];
extern s16 D_800AF790[4];
extern s16 D_800AF798[4];
extern s16 D_800AF7A0[4];
extern s16 D_800AF7AE;
extern s16 D_800AF7B0[2];

void BattleHud_SetDigitRotationTargets(u8 arg0, s16 arg1);
void BattleHud_ApproachDigitRotations(u8 arg0, s16 arg1);
void ModelAnim_UpdateFrameChangeState(void);
s32 func_800325AC(void);
u8 ModelRenderer_GetActiveMode(void);
s16 ModelRenderer_GetObjectType(void);
void ModelAnim_StartDisplayObjectAnimation(DisplayObject* arg0);
void ModelAnim_UpdateDisplayObjectAnimation(u32 arg0, u32 arg1);
void ModelAnim_FinalizeDisplayObjectAnimation(u32 arg0, u32 arg1);
void Gfx_SetCombineMode(Gfx*, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

#endif // _32D10_H_
