#ifndef _FRAGMENT65_H_
#define _FRAGMENT65_H_

#include "global.h"

typedef struct Glc_Trainer {
    /* 0x00 */ u8 loaded;
    /* 0x02 */ s16 portrait_x;
    /* 0x04 */ s32 portrait;
    /* 0x08 */ char* name;
} Glc_Trainer; // size = 0xC

typedef struct CastleMapNode {
    /* 0x00 */ u8 index;
    /* 0x01 */ u8 node_state;
    /* 0x02 */ s16 label_x;
    /* 0x04 */ s16 label_y;
    /* 0x06 */ s16 cursor_x;
    /* 0x08 */ s16 cursor_y;
    /* 0x0A */ s16 marker_x;
    /* 0x0C */ s16 marker_y;
    /* 0x0E */ s16 marker_width;
    /* 0x10 */ s16 marker_height;
    /* 0x12 */ s16 pulsing;
    /* 0x14 */ s8 up_neighbour;
    /* 0x15 */ s8 down_neighbour;
    /* 0x16 */ s8 left_neighbour;
    /* 0x17 */ s8 right_neighbour;
    /* 0x18 */ Color_RGBA8 color;
    /* 0x1C */ u8* texture;
    /* 0x20 */ s16 boss_title;
    /* 0x22 */ s16 file_number;
    /* 0x24 */ u8* info_panel_texture;
} CastleMapNode; // size = 0x28

void Glc_DrawBackgroundCrossFade(u8* fade_in_texture, u8* fade_out_texture, u8 alpha);
void Glc_DrawScaledTextureRgba(s16 x_start, s16 y_start, s16 draw_width, s16 height, s16 load_width, u8* texture, f32 scale);
void func_84A00630(void);
void Glc_DrawScaledTextureIa8(s16 x_start, s16 y_start, s16 width, s16 height, u8* texture, f32 scale);
void Glc_DrawRoomDescription(void);
void Glc_DrawTrainerIntroPanels(void);
void Glc_DrawMapBorder(void);
void Glc_DrawRoomMarkers(void);
void Glc_DrawRoomLabels(void);
void Glc_DrawGymLeaderInfoPanel(CastleMapNode* node, u8 alpha1, u8 alpha2);
void Glc_DrawEliteFourRoomInfoPanel(CastleMapNode* node, u8 alpha1, u8 alpha2);
void Glc_UpdateRoomInfoPanelFade(void);
void Glc_UpdateMapCursor(void);
void Glc_Draw(void);
s32 func_84A02074(void);
s32 Glc_SelectRoom(void);
void Glc_LoadTrainerPanels(void);
void Glc_ClearTrainerPanels(void);
void Glc_SlideTrainerPanels(s16 panels_start, s16 panels_end, s16 timer, s16 x_delta);
s32 Glc_ShowIntro(void);
s32 Glc_AdvanceRoom(void);
s16 Glc_RunMenu(s16 action);
s16 Glc_InitMenu(s16 arg0);
s32 GymLeaderCastle_Main(s32 arg0, UNUSED s32 arg1);

#endif // _FRAGMENT65_H_
