#ifndef _6BC0_H_
#define _6BC0_H_

#include "global.h"

// image size in bits
typedef enum IMAGE_SIZE_BITS {
	IMAGE_SIZE_BITS_4b,
	IMAGE_SIZE_BITS_8b,
	IMAGE_SIZE_BITS_16b,
	IMAGE_SIZE_BITS_32b,
} IMAGE_SIZE_BITS;

typedef struct unk_D_80068BB0 {
	/* 0x00 */ u16 fmt;
	/* 0x02 */ u16 size;
	/* 0x04 */ u16 width;
	/* 0x06 */ u16 height;
	/* 0x08 */ u8* img_p;
	/* 0x0C */ struct unk_D_80068BB0* depth_p;
} unk_D_80068BB0; // size = 0x10

unk_D_800A7440* func_80005FC0(unk_D_800A7440* arg0, s16 x1, s16 y1, s16 x2, s16 y2);
s32 func_80006030(unk_D_800A7440* arg0);
void func_800060E0(Gfx** gfx_p, s16 x, s16 y, s16 width, s16 height);
void func_80006200(Gfx** gfx_p);
void func_800062E4(unk_D_80068BB0* arg0, s32 fmt, s32 size, s32 width, s32 height, u32 img_p);
unk_D_80068BB0* func_80006314(s32 fmt, s32 size, s32 width, s32 height, s32 side);
void func_80006414(unk_D_80068BB0* img, unk_D_80068BB0* depth);
void func_80006450(void);
unk_D_80068BB0* func_8000648C(void);
void func_80006498(Gfx** gfx_p, unk_D_80068BB0* arg1);
void func_800065B4(Gfx** gfx_p, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u16 fill_colour);
void func_800067E4(Gfx** gfx_p, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_8000699C(Gfx** gfx_p, u16 fill_colour);


#endif // _6BC0_H_
