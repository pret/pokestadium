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
	/* 0x10 */ char unk_10[0x40];
} unk_D_80068BB0; // size = 0x50

void func_800060E0(Gfx**, s16, s16, s16, s16);
unk_D_80068BB0* func_80006314(s32 fmt, s32 size, s32 width, s32 height, s32 side);
void func_80006414(unk_D_80068BB0*, unk_D_80068BB0*);
void func_80006450(void);
void func_80006498(Gfx**, unk_D_80068BB0*);
void func_800067E4(Gfx**, s32, s32, s32, s32);
void func_8000699C(Gfx**, u16);


#endif // _6BC0_H_
