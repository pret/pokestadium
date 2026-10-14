#ifndef _FRAGMENT37_H_
#define _FRAGMENT37_H_

#include "global.h"

s32 AreaSelect_CheckCartRemoved(s32 arg0);
void AreaSelect_DrawCrossfadeBackground(u8* fade_out_texture, u8* fade_in_texture, u8 alpha);
Vtx* AreaSelect_BuildGlowQuadVerts(void);
void AreaSelect_DrawCursorGlow(void);
void AreaSelect_AdvanceMagnemiteTrail(void);
void AreaSelect_InitMagnemiteTrail(s32 arg0);
Vtx* AreaSelect_BuildMagnemiteQuadVerts(s16 x, s16 y, s16 offset, Color_RGBA8 color);
void AreaSelect_DrawMagnemiteQuad(s16 x, s16 y, s16 offset, u8* sprite, Color_RGBA8 color);
void AreaSelect_DrawMagnemiteTrail(u8* sprite);
void AreaSelect_UpdateMagnemites(void);
void AreaSelect_DrawNameBanner(s16 x, s16 y, s16 alpha, s16 area);
void func_822014C0(void);
void AreaSelect_DrawNameBannerCrossfade(s16 area, s16 x, s16 y);
void AreaSelect_DrawPulsingMarker(s16 x, s16 y);
void AreaSelect_DrawGlowCircle(s16 x, s16 y, s16 diameter);
void AreaSelect_DrawInfoPanel(s16 x, s16 y, s16 width, s16 height, u8 r, u8 g, u8 b, u8 alpha);
void AreaSelect_DrawAreaInfoBox(s32 draw_text);
void AreaSelect_PollInput(void);
s32 AreaSelect_HandleInput(void);
s16 AreaSelect_CursorMoveAnim(void);
s32 AreaSelect_ConfirmSelection(void);
s32 AreaSelect_FadeToBattle(void);
s32 AreaSelect_MusicFadeWait(void);
s32 AreaSelect_WaitFragmentUnload(void);
void AreaSelect_SetupOrthoProjection(void);
void AreaSelect_Draw(s16 arg0);
s32 AreaSelect_FadeInFromBattle(void);
void AreaSelect_Intro(void);
void AreaSelect_Loop(void);
void AreaSelect_LoadBackgroundArt(void);
s32 AreaSelect_Main(UNUSED s32 arg0, UNUSED s32 arg1);

#endif // _FRAGMENT37_H_
