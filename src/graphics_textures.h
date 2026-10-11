#ifndef _1CF30_H_
#define _1CF30_H_

#include "global.h"

extern FontContext* font_context;

void Gfx_DrawTexturedRectClipped(s16 x1, s16 y1, s16 width, s16 height, s16 texture_start_x, s16 texture_start_y, s16 texture_step_x, s16 texture_step_y, s32 texture_spread_x_mode);
void Gfx_DrawTexturedRect(s32 x1, s32 y1, s32 width, s32 height, s32 texture_step_x, s32 texture_step_y, s32 texture_step_x_mode);
void Gfx_FillRectRgb(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6);
void Gfx_FillRectRgba(s16 x1, s16 y1, s16 width, s16 height, u8 r, u8 g, u8 b, u8 alpha);
void Gfx_DrawTextureRgba16(s16 x1, s16 y1, s16 draw_width, s16 height, u8* texture, s16 load_width, s32 texture_spread_x_mode);
void Gfx_DrawTextureRgba32(s16 x1, s16 y1, s16 draw_width, s16 height, u8* texture, s16 load_width, s32 texture_spread_x_mode);
void Gfx_DrawTextureIa8(s16 x1, s16 y1, s16 draw_width, s16 height, u8* texture, s16 load_width, s32 texture_spread_x_mode);
void Gfx_DrawTextureIa16(s16 x1, s16 y1, s16 draw_width, s16 height, u8* texture, s16 load_width, s32 texture_spread_x_mode);
void Gfx_DrawTextureI4(s16 x1, s16 y1, s16 draw_width, s16 height, u8* texture, s16 load_width, s32 texture_spread_x_mode);
void Gfx_DrawTextureI8(s16 x1, s16 y1, s16 draw_width, s16 height, u8* texture, s16 load_width, s32 texture_spread_x_mode);
void Gfx_DrawTextureI16(s16 x1, s16 y1, s16 draw_width, s16 height, u8* texture, s16 load_width, s32 texture_spread_x_mode);
void Gfx_DrawTextureRgba16Ia8(s16 x1, s16 y1, s16 draw_width, s16 height, u8* texture, u8* texture_multi, s16 load_width, s32 texture_x_spread_mode);
void Gfx_DrawTiledRgba16Image(u8* image);
void Gfx_DrawRgba16ImageRegion(u32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void Gfx_DrawTiledImageMesh(s16 arg0, s16 arg1, s16 arg2, f32 arg3, Vtx* arg4, u32 arg5);
Vtx* func_8001E490(void);
void Gfx_SetVertexAttributes(Vtx* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9);
void Gfx_SetViewportDimensions(Vp* arg0, s16 arg1, s16 arg2);
u8 Font_MapGlyphCode(u16 arg0);
u8 Font_GetGlyphAdvance(FontSet* arg0, u16 arg1);
void Font_ResetContext(UNUSED s32 arg0, UNUSED s32 arg1);
void Font_FreeSetAsset(UNUSED s32 arg0, s32 arg1);
s32 Font_GetSetIndexFromMask(s32 mask);
void Font_LoadSet(s32 arg0, s32 arg1, s32 arg2);
FontContext* Font_Init(s32 load_size, s32 side);
void Font_Free(void);
void Font_LoadSizes(s32 arg0);
void Font_UnloadSizes(s32 arg0);
void Font_SetActive(s32 mask, s32 arg1);
s32 Font_GetSetInfo(s32 arg0, FontSet* arg1);
s16 Font_DrawChar(s16 arg0, s16 arg1, s16 arg2);
char* String_CopyBytesAndAdvance(char* buffer, const char* data, u32 size);
void Font_Printf(s32 x, s32 y, const char* fmt, ...);
void Font_DrawCharAt(s32 arg0, s32 arg1, s32 arg2);
void Gfx_SetEnvColor(s32 r, s32 g, s32 b, s32 a);
void Gfx_SetPrimColor(s32 r, s32 g, s32 b, s32 a);
void Font_SetLineHeight(s32 line_height);
void Font_DisableLineBreak(void);
void Font_EnableLineBreak(void);
void Font_BeginTranslucentTextRendering(void);
void Font_EndTexturedTextRendering(void);
void Font_EnableTwoCycleTexturing(void);
void Font_DisableTwoCycleTexturing(void);
void Gfx_FillRectWithDisplayState(s32 x1, s32 y1, s32 width, s32 length, s32 r, s32 g, s32 b, s32 alpha);
s32 Font_MeasureTextExtent(s32 x, s32 y, const char* fmt, ...);
u8 Font_GetCharWidth(s32 arg0, s32 arg1);

#endif // _1CF30_H_
