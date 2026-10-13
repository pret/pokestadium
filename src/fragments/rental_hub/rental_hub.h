#ifndef _FRAGMENT54_H_
#define _FRAGMENT54_H_

#include "global.h"
#include "src/save_data.h"

void RentalHub_DrawHeaderIcon(s16 x, s16 y);
void RentalHub_DrawHeaderBar(s16 x, s16 y, s16 clip_width, Color_RGBA8* fill_color, Color_RGBA8* border_color);
void RentalHub_DrawHeader(void);
void RentalHub_DrawSelectionCursor(s16 x, s16 y, s16 width, s16 height);
void RentalHub_DrawMenuItemBorder(s16 x, s16 y, s16 width, s16 height);
void RentalHub_DrawMenuItemBox(s16 x, s16 y, s16 height, char* text);
void RentalHub_DrawMenuItems(s16 height);
s32 RentalHub_HandleInput(void);
void RentalHub_Draw(s16 height);
void RentalHub_FadeInWait(void);
void RentalHub_FadeOutWait(void);
s16 RentalHub_MenuLoop(void);
void RentalHub_LoadBackgroundImage(ModeSettings* arg0);
s32 RentalHub_MenuMain(void);
s32 RentalHub_LoadRentalPicker(void);
s32 RentalHub_LoadRentalRules(void);
s32 RentalHub_Main(UNUSED s32 arg0, UNUSED s32 arg1);

#endif // _FRAGMENT54_H_
