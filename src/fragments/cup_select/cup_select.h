#ifndef _FRAGMENT60_H_
#define _FRAGMENT60_H_

#include "global.h"
#include "src/geo_node.h"

void CupSelect_PollController(void);
void func_82E00050(void);
void CupSelect_DrawSelectionCorners(s16 left, s16 bottom, s16 right, s16 top, u8 r, u8 g, u8 b, u8 alpha);
s32 CupSelect_IconGeoPostCallback(s32 arg0, UNUSED unk_func_80011B94* arg1);
s32 CupSelect_DividerGeoPostCallback(s32 arg0, UNUSED unk_func_80011B94* arg1);
void CupSelect_RenderFrame(s32 mode, s32 counter);
void CupSelect_BuildDivisionList(void);
s32 CupSelect_HandleInput(void);
s32 CupSelect_Loop(void);
void CupSelect_InitGeoLayouts(void);
s32 CupSelect_Main(UNUSED s32 arg0, UNUSED s32 arg1);

#endif // _FRAGMENT60_H_
