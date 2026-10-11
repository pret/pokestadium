#ifndef _STAGE_LOADER_H_
#define _STAGE_LOADER_H_

#include "global.h"
#include "src/gfx_rect.h"

typedef struct unk_D_800A7450 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 zoom;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ Gfx* unk_04;
    /* 0x08 */ Gfx* unk_08;
    /* 0x0C */ void* unk_0C;
    /* 0x10 */ char unk10[0x4];
} unk_D_800A7450; // size >= 0x14

typedef struct unk_func_80007444 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s8 zoom;
    /* 0x0D */ s8 unk_0D;
    /* 0x0E */ s8 unk_0E;
    /* 0x0F */ s8 unk_0F;
    /* 0x10 */ s8 unk_10;
    /* 0x11 */ u8 fade_mode;
    /* 0x12 */ u8 unk_12;
    /* 0x13 */ u8 unk_13;
    /* 0x14 */ u16 clear_color;
    /* 0x16 */ s8 unk_16;
    /* 0x17 */ u8 pad17;
    /* 0x18 */ unk_D_80068BB0* unk_18[3];
} unk_func_80007444; // size = 0x24

void StageFade_Update(void);
s32 StageFade_Start(s32 arg0);
s32 StageFade_StartFromOpaque(s32 arg0);
s32 StageFade_StartFromTransparent(s32 arg0);
void StageFade_SetMode(s32 fade_mode);
void Profiler_SetDisplayModes(u32 arg0, u32 arg1);
void Gfx_SetDefaultRenderState(void);
void Gfx_SetDefaultGeometryState(void);
void StageLoader_ResetGraphicsState(void);
void StageLoader_SetupFrame(void);
void StageLoader_SwapDisplayListAndReset(void);
void StageLoader_BeginFrame(void);
void StageLoader_FillFrame(void);
unk_func_80007444* StageContext_Allocate(s8 zoom, s8 arg1, s8 arg2, s8 arg3, s8 arg4, s32 arg5);
unk_func_80007444* StageContext_GetCurrent(void);
s32 StageContext_GetFadeMode(void);
void StageContext_SaveAndSwitch(unk_func_80007444* arg0);
void StageContext_Activate(unk_func_80007444* arg0);
void StageContext_Deactivate(void);
void StageLoader_WaitForRetrace(void);
void StageLoader_UpdateSegments(void);
s32 BgStage_AdvanceFrame(void);
void StageLoader_RunFrames(s32 timer);
s32 BgStage_RunUntilCondition(u32 timer, s32 (*f)(u8));
s32 BgStage_WaitForCondition(s32 (*arg0)(u8), s32 arg1, s32 arg2);
void StageContext_SetClearColor(u16 color);
void BgStage_DrawFrame(void);
unk_D_80068BB0* StageContext_GetCurrentImage(void);
s32 StageContext_IsHighResolution(void);
void TextRenderer_SetupGlyphState(void);
void TextRenderer_RestoreState(void);
void TextRenderer_DrawGlyphSmall(s16 arg0, s16 arg1, s16 arg2);
void TextRenderer_DrawGlyphLarge(s16 arg0, s16 arg1, s16 arg2);
void TextRenderer_DrawString(s16 arg0, s16 arg1, s8* arg2, s32 arg3);
void TextRenderer_FlushQueuedStrings(Gfx** arg0, s32 arg1);
void TextRenderer_ClearQueuedStrings(void);
char* TextRenderer_FormatCopy(char* buffer, const char* data, size_t size);
s32 HAL_Printf(s16 x, s16 y, const char* fmt, ...);
s32 TextRenderer_QueuePersistentString(s16 x, s16 y, const char* fmt, ...);


#endif // _STAGE_LOADER_H_
