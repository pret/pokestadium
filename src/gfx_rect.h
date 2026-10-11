#ifndef _6BC0_H_
#define _6BC0_H_

#include "global.h"

// image size in bits
typedef enum IMAGE_SIZE_BITS {
	IMAGE_SIZE_BITS_4b  = 0,
	IMAGE_SIZE_BITS_8b  = 1,
	IMAGE_SIZE_BITS_16b = 2,
	IMAGE_SIZE_BITS_32b = 3,
} IMAGE_SIZE_BITS;

typedef enum IMAGE_FMT {
	IMAGE_FMT_RGBA = 0,
	IMAGE_FMT_YUV  = 1,
	IMAGE_FMT_CI   = 2,
	IMAGE_FMT_IA   = 3,
	IMAGE_FMT_I    = 4,
} IMAGE_FMT;

typedef struct unk_D_80068BB0 {
	/* 0x00 */ u16 fmt;
	/* 0x02 */ u16 size;
	/* 0x04 */ u16 width;
	/* 0x06 */ u16 height;
	/* 0x08 */ u8* img_p;
	/* 0x0C */ struct unk_D_80068BB0* depth_p;
} unk_D_80068BB0; // size = 0x10

unk_D_800A7440* GfxRect_SetBounds(unk_D_800A7440* arg0, s16 x1, s16 y1, s16 x2, s16 y2);
s32 GfxRect_ClipToScissor(unk_D_800A7440* rectangle);
void Gfx_SetScissorRect(Gfx** gfx_p, s16 x, s16 y, s16 width, s16 height);
void Gfx_ApplyScissorRect(Gfx** gfx_p);
void GfxImage_Initialize(unk_D_80068BB0* arg0, s32 fmt, s32 size, s32 width, s32 height, u32 img_p);
unk_D_80068BB0* GfxImage_Allocate(s32 fmt, s32 size, s32 width, s32 height, s32 side);
void GfxImage_AttachDepthBuffer(unk_D_80068BB0* img, unk_D_80068BB0* depth);
void GfxImage_ResetCurrent(void);
unk_D_80068BB0* GfxImage_GetCurrent(void);
void GfxImage_SetRenderTarget(Gfx** gfx_p, unk_D_80068BB0* arg1);
void GfxImage_FillRectangle(Gfx** gfx_p, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u16 fill_colour);
void GfxImage_ClearDepthRectangle(Gfx** gfx_p, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void GfxImage_FillCurrent(Gfx** gfx_p, u16 fill_colour);


#endif // _6BC0_H_
