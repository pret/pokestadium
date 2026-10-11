#ifndef _FRAGMENT40_H_
#define _FRAGMENT40_H_

#include "global.h"
#include "src/geo_layout.h"

typedef struct unk_D_83101F00 {
    /* 0x000 */ DisplayObject unk_000;
    /* 0x168 */ s16 unk_168;
    /* 0x16A */ s16 unk_16A;
    /* 0x16C */ s16 unk_16C;
    /* 0x16E */ s16 unk_16E;
    /* 0x170 */ s16 unk_170;
    /* 0x172 */ s16 unk_172;
    /* 0x174 */ s16 unk_174;
    /* 0x176 */ s16 unk_176;
    /* 0x178 */ s16 unk_178;
    /* 0x17A */ s16 unk_17A;
    /* 0x17C */ s16 unk_17C;
    /* 0x180 */ f32 unk_180;
    /* 0x184 */ f32 unk_184;
} unk_D_83101F00; // size = 0x188

void Glc_UpdateSweepObject(DisplayObject* arg0);
s32 Glc_GeoBannerCallback(s32 arg0, UNUSED GraphNode* arg1);
void Glc_UpdateColorKeyframe(unk_D_83101F00* arg0);
s32 Glc_GeoSpriteCallback(s32 arg0, GraphNode* arg1);
void Glc_InitCircleWipe(void);
void Glc_UpdateCircleWipe(void);
void Glc_DrawCircleWipe(void);
void Glc_StartCircleWipe(s16 start);
void Glc_InitBackgroundFade(void);
void Glc_UpdateBackgroundFade(void);
void Glc_DrawFadedBackground(u8* texture, s16 alpha);
void Glc_DrawBackground(void);
void Glc_StartBackgroundFade(s16 mode);
void Glc_ReadInputs(void);
void Glc_InitObjectAnimation(unk_D_83101F00* arg0, s16 arg1);
void Glc_DrawScisRectangle(s16 x1, s16 y1, s16 width, s16 height, s16 texture_start_x, s16 texture_start_y, s16 texture_spread_x, s16 texture_spread_y);
void Glc_DrawTrackingIcon(void);
void Glc_ClearInitState(void);
void Glc_ClearDraw(void);
s32 Glc_ClearAdvanceState(void);
void Glc_ClearRunLoop(void);
void Glc_ClearInitGraphics(void);
s32 GymLeaderCastleClear_Main(UNUSED s32 arg0, UNUSED s32 arg1);

#endif // _FRAGMENT40_H_
