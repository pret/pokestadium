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

void GymLeaderCastleClear_UpdateSweepObject(DisplayObject* arg0);
s32 GymLeaderCastleClear_GeoBannerCallback(s32 arg0, UNUSED GraphNode* arg1);
void GymLeaderCastleClear_UpdateColorKeyframe(unk_D_83101F00* arg0);
s32 GymLeaderCastleClear_GeoSpriteCallback(s32 arg0, GraphNode* arg1);
void GymLeaderCastleClear_InitCircleWipe(void);
void GymLeaderCastleClear_UpdateCircleWipe(void);
void GymLeaderCastleClear_DrawCircleWipe(void);
void GymLeaderCastleClear_StartCircleWipe(s16 start);
void GymLeaderCastleClear_InitBackgroundFade(void);
void GymLeaderCastleClear_UpdateBackgroundFade(void);
void GymLeaderCastleClear_DrawFadedBackground(u8* texture, s16 alpha);
void GymLeaderCastleClear_DrawBackground(void);
void GymLeaderCastleClear_StartBackgroundFade(s16 mode);
void GymLeaderCastleClear_ReadInputs(void);
void GymLeaderCastleClear_InitObjectAnimation(unk_D_83101F00* arg0, s16 arg1);
void GymLeaderCastleClear_DrawScissoredRectangle(s16 x1, s16 y1, s16 width, s16 height, s16 texture_start_x,
                                                 s16 texture_start_y, s16 texture_spread_x, s16 texture_spread_y);
void GymLeaderCastleClear_DrawTrackingIcon(void);
void GymLeaderCastleClear_InitState(void);
void GymLeaderCastleClear_Draw(void);
s32 GymLeaderCastleClear_AdvanceState(void);
void GymLeaderCastleClear_RunLoop(void);
void GymLeaderCastleClear_InitGraphics(void);
s32 GymLeaderCastleClear_Main(UNUSED s32 arg0, UNUSED s32 arg1);

#endif // _FRAGMENT40_H_
