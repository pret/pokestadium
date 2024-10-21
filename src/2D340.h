#ifndef _3D340_H_
#define _3D340_H_

#include "global.h"
#include "src/1C720.h"
#include "src/1AB70.h"

typedef struct unk_func_88205880_00D0 {
    /* 0x000 */ unk_func_80026268_arg0 unk_000[20];
    /* 0x690 */ s32 unk_690;
    /* 0x694 */ s32 unk_694;
    /* 0x698 */ s32 unk_698;
    /* 0x69C */ u32 unk_69C;
} unk_func_88205880_00D0; // size = 0x6A0

typedef struct unk_func_88200FA0_030_038 {
    /* 0x00 */ unk_func_88205880_00D0** unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
} unk_func_88200FA0_030_038; // size = 0xC

typedef struct unk_func_88201DA0_034 {
    /* 0x0000 */ s32 unk_000;
    /* 0x0004 */ char unk004[0x4];
    /* 0x0008 */ unk_func_88201DA0_034_008 unk_008;
    /* 0x000C */ char unk00C[0xC7C];
} unk_func_88201DA0_034; // size = 0xC88

typedef struct unk_func_88201DA0_038 {
    /* 0x00 */ unk_func_88201DA0_034* unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
} unk_func_88201DA0_038; // size = 0x10

typedef struct unk_func_88205880_A030 {
    /* 0x00 */ unk_func_88205880_00D0** unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
} unk_func_88205880_A030; // size = 0xC

typedef struct unk_func_8820BE14_06C_000 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ unk_func_88200FA0_030_038 unk_04;
} unk_func_8820BE14_06C_000; // size = 0x10

typedef struct unk_func_8820BE14_06C {
    /* 0x00 */ unk_func_8820BE14_06C_000* unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
} unk_func_8820BE14_06C; // size = 0x10

void func_8002C740(s8*, unk_func_88201DA0_034*, s32, s32, s32);
void func_8002C758(unk_func_8820BE14_06C*, s32, s32, MemoryPool*);
void func_8002C88C(unk_func_8820BE14_06C*, u8*, s32);
void func_8002C990(unk_func_8820BE14_06C*, s32);
void func_8002CBC0(unk_func_88200FA0_030_038*, s32, MemoryPool*);
void func_8002CBB0(unk_func_88205880_A030*, void*, s32, s32);
void func_8002CC2C(unk_func_88200FA0_030_038*, char*, s32);
void func_8002D3F0(f32*);
Color_RGBA8 func_8002D444(Color_RGBA8, f32);

#endif // _3D340_H_
