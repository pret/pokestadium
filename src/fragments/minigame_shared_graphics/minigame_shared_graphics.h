#ifndef _FRAGMENT4_H_
#define _FRAGMENT4_H_

#include "global.h"

extern u32 D_87A01110[];
extern u32 D_87A01178[];
extern u32 D_87A01180[];
extern u32 D_87A01190[];
extern u32 D_87A011A4[];

void MiniCam_SetActive(CameraNode*);
Gfx* MiniCam_ApplyProjection(Gfx*);
Gfx* MiniGfx_DrawTexturedQuad(Gfx*, Mtx*, f32, f32, f32, f32, void*, s32, s32);
void func_87A00DB8(s32);
s32 MiniSound_DispatchCommand(s32, s32, s32);

#endif // _FRAGMENT4_H_
