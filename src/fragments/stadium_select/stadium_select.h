#ifndef _FRAGMENT59_H_
#define _FRAGMENT59_H_

#include "global.h"
#include "src/gfx_rect.h"
#include "src/geo_node.h"

void func_84100020(s16 arg0, s16 arg1, s16 arg2);
void StadiumSelect_UpdateSparkles(s16 arg0);
void StadiumSelect_InitSparkleFlags(void);
void StadiumSelect_DrawIconFrame(DepthBuffer* arg0, s16 arg1, s16 arg2);
void StadiumSelect_DrawBlurbBackdrop(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7);
void StadiumSelect_DrawSelectionCorners(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7);
s32 StadiumSelect_IconGeoPostCallback(s32 arg0, unk_func_80011B94* arg1);
void StadiumSelect_DrawCupInfoPanel(s16 arg0);
void StadiumSelect_RenderFrame(s32 arg0, s32 arg1, f32 arg2);
DepthBuffer* StadiumSelect_BuildDivisionCupIcon(u8* arg0, s16 arg1);
DepthBuffer* StadiumSelect_BuildSimpleCupIcon(u8* arg0, s16 arg1);
void StadiumSelect_BuildCupIconGrid(void);
s16 StadiumSelect_HandleInput(void);
void StadiumSelect_Loop(void);
void StadiumSelect_InitGeoLayouts(void);
s32 StadiumSelect_ConfirmSelection(void);
s32 StadiumSelect_Main(s32 arg0, s32 arg1);

#endif // _FRAGMENT59_H_
