#ifndef _6A40_H_
#define _6A40_H_

#include "global.h"

void Gfx_InitDisplayListBuffers(u32 arg0, s32 arg1);
void Gfx_FreeDisplayListBuffers(void);
void Gfx_SwapDisplayListBuffer(void);
void Gfx_GetDisplayListRange(Gfx** arg0, Gfx** arg1);
void* Gfx_AllocDisplayList(s32 size);
s32 Gfx_GetDisplayListRemaining(void);

#endif // _6A40_H_
