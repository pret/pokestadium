#ifndef _20470_H_
#define _20470_H_

#include "global.h"

extern Gfx D_8006F470[];
extern Gfx D_8006F498[];
extern Gfx D_8006F4C0[];
extern Gfx D_8006F4E0[];
extern Gfx D_8006F518[];
extern Gfx D_8006F558[];
extern Gfx D_8006F5A0[];
extern Gfx D_8006F608[];
extern Gfx D_8006F630[];
extern Gfx D_8006F710[];
extern Gfx D_8006F750[];
extern Gfx D_8006F768[];
extern Gfx D_8006F798[];

void Ui_DrawTexturedRect8x8(s32 x1, s32 y1, s32 width, s32 height, u8* texture);
void Ui_DrawBorderStyleA(s32 x1, s32 y1, s32 width, s32 height);
void Ui_DrawBorderStyleB(s32 x1, s32 y1, s32 width, s32 height);
void Ui_DrawBorderStyleC(s32 x1, s32 y1, s32 width, s32 height);
void Ui_FillInsetRectangleA(s32 x1, s32 y1, s32 width, s32 height, u16 color);
void Ui_FillInsetRectangleB(s32 x1, s32 y1, s32 width, s32 height, u16 color);
void Ui_DrawGradientRectangle(s32 x1, s32 y1, s32 width, s32 height, Color_RGB8* top_color,
                              Color_RGB8* bottom_color);
void Ui_DrawBorderedPanel(s32 x1, s32 y1, s32 width, s32 height, u16 color);
void Ui_DrawGradientPanel(s32 x1, s32 y1, s32 width, s32 height, Color_RGB8* top_color, Color_RGB8* bottom_color);
void Ui_DrawBorderedPanelStyleB(s32 x1, s32 y1, s32 width, s32 height, u16 color);
void Ui_DrawBorderedPanelNoFill(s32 x1, s32 y1, s32 width, s32 height);
void Ui_DrawTextureMarker(s32 x, s32 y);
void Ui_DrawAnimatedTextureMarker(s16 x, s16 y);
void Ui_Draw20x20Icon(s32 arg0, s32 arg1, s32 arg2);
void BattleHud_DrawHpBarTexture(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void BattleHud_DrawHpBar16x5(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void Text_LoadNameTable(void);

#endif // _20470_H_
