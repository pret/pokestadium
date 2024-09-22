#ifndef _F420_H_
#define _F420_H_

#include "global.h"

typedef union arg1_func_80010CA8 {
    struct {
        /* 0x00 */ s16 unk_00;
        /* 0x02 */ s8 unk_02;
        /* 0x03 */ s8 unk_03;
    };
    u32 raw;
} arg1_func_80010CA8; // size = 0x4

extern Vec3f D_8006F050;
extern Vec3s D_8006F05C;
extern Vec3f D_8006F064;
extern u16 D_8006F070[];

Color_RGBA8_u32* func_8000E820(Color_RGBA8_u32* arg0, u8 r, u8 g, u8 b);
Color_RGBA8_u32* func_8000E840(Color_RGBA8_u32* arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4);
Vec3f* func_8000E868(Vec3f* arg0, f32 arg1, f32 arg2, f32 arg3);
Vec3f* func_8000E88C(Vec3f* arg0, f32 arg1, f32 arg2, f32 arg3);
Vec3f* func_8000E8B0(Vec3f* arg0, Vec3f* arg1);
Vec3f* func_8000E8E8(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2);
Vec3f* func_8000E920(Vec3f* arg0, Vec3f* arg1);
Vec3f* func_8000E958(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2);
Vec3f* func_8000E990(Vec3f* arg0, Vec3s* arg1);
Vec3f* func_8000E9D4(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3);
Vec3f* func_8000EA84(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2);
Vec3f* func_8000EAF4(Vec3f* arg0);
Vec3s* func_8000EB70(Vec3s* arg0, s16 arg1, s16 arg2, s16 arg3);
Vec3s* func_8000EBA8(Vec3s* arg0, Vec3s* arg1);
Vec3s* func_8000EBE0(Vec3s* arg0, Vec3s* arg1, Vec3s* arg2);
Vec3s* func_8000EC18(Vec3s* arg0, Vec3s* arg1);
Vec3s* func_8000EC50(Vec3s* arg0, Vec3s* arg1, Vec3s* arg2);
Vec3s* func_8000EC88(Vec3s* arg0, Vec3f* arg1);
void func_8000ED4C(MtxF* dest, MtxF* src);
void func_8000ED98(MtxF* arg0);
void func_8000EDD8(MtxF* arg0, Vec3f* arg1);
void func_8000EE1C(MtxF* mtx, Vec3f* from, Vec3f* to, u16 roll);
void func_8000F174(MtxF* dest, Vec3s* translate, Vec3s* rotate);
void func_8000F2C4(MtxF* arg0, Vec3f* arg1, Vec3s* arg2);
void func_8000F3FC(MtxF* arg0, Vec3f* arg1, Vec3s* arg2);
void func_8000F5A8(MtxF* dest, Vec3f* b, Vec3s* c, Vec3f* arg3);
void func_8000F730(MtxF* dest, Vec3f* b, Vec3s* c, Vec3f* arg3);
void func_8000F88C(MtxF* arg0, MtxF* arg1, MtxF* arg2, Vec3f* arg3, f32 arg4);
void func_8000FA94(MtxF* dest, Vec3f* upDir, Vec3f* pos, s16 yaw);
void func_8000FBB0(MtxF* arg0, MtxF* arg1, MtxF* arg2);
void func_8000FDE4(MtxF* dest, MtxF* mtx, Vec3f* s);
void func_8000FF04(MtxF* arg0, Vec3f* arg1);
void func_8000FFB8(MtxF* arg0, Vec3s* arg1);
void func_80010090(MtxF* dest, MtxF* src);
void func_80010228(MtxF* arg0, Vec3f* arg1, Vec3s* arg2, Vec3f* arg3, MtxF* arg4, MtxF* arg5);
void func_800102A4(Vec3f* arg0, Vec3f* arg1, f32* arg2, s16* arg3, s16* arg4);
void func_80010354(Vec3f* from, Vec3f* to, f32 dist, s16 pitch, s16 yaw);
s16 func_800103F0(s16 current, s16 target, s16 inc);
s32 func_8001046C(s32 current, s32 target, s32 inc, s32 dec);
f32 func_800104AC(f32 current, f32 target, f32 inc, f32 dec);
s16 func_80010500(s16* arg0, s32 arg1, s32 arg2);
void func_80010570(f32 arg0, f32 arg1, f32 arg2, Vec3f* arg3);
void func_80010720(Color_RGBA8_u32 arg0, Vec3f* arg1);
void func_80010780(u16 arg0, Vec3f* arg1);
f32 func_800107F0(f32 arg0, f32 arg1, f32 arg2);
void func_80010930(f32* arg0, f32* arg1, f32* arg2, Vec3f* arg3);
u16 func_80010B20(Vec3f* arg0);
Color_RGBA8_u32* func_80010BD4(Color_RGBA8_u32* arg0, Vec3f* arg1, s32 arg2);
u16 func_80010CA8(u16 arg0, arg1_func_80010CA8 arg1);
u32 func_80010E20(u32 arg0, arg1_func_80010CA8 arg1);

#endif // _F420_H_
