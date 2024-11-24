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

typedef struct unk_func_8820BE14_06C_000_alt {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ unk_func_88200FA0_030_038 unk_04;
    /* 0x10 */ unk_func_88205880_A030 unk_10;
} unk_func_8820BE14_06C_000_alt; // size = 0x1C

typedef struct unk_func_8820BE14_06C {
    /* 0x00 */ unk_func_8820BE14_06C_000* unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
} unk_func_8820BE14_06C; // size = 0x10

typedef struct unk_func_8830867C_02C_0CC_000_000_000 {
    /* 0x00 */ char unk00[0x8];
    /* 0x08 */ s32 unk_08;
} unk_func_8830867C_02C_0CC_000_000_000; // size >= 0xC

typedef struct unk_func_8830867C_02C_0CC_000_000_010_000_000 {
    /* 0x00 */ struct unk_func_8830867C_02C_0CC_000_000* unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ unk_func_80026268_arg0 unk_08;
} unk_func_8830867C_02C_0CC_000_000_010_000_000; // size >= 0x5C

typedef struct unk_func_8830867C_02C_0CC_000_000_010_000 {
    /* 0x00 */ unk_func_8830867C_02C_0CC_000_000_010_000_000* unk_00;
} unk_func_8830867C_02C_0CC_000_000_010_000; // size >= 0x4

typedef struct unk_func_8830867C_02C_0CC_000_000_010 {
    /* 0x00 */ unk_func_8830867C_02C_0CC_000_000_010_000* unk_00;
    /* 0x04 */ char unk04[0x4];
    /* 0x08 */ s32 unk_08;
} unk_func_8830867C_02C_0CC_000_000_010; // size = 0xC

typedef struct unk_func_8830867C_02C_0CC_000_000 {
    /* 0x00 */ unk_func_8830867C_02C_0CC_000_000_000* unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ unk_func_8830867C_02C_0CC_000_000_010 unk_10;
} unk_func_8830867C_02C_0CC_000_000; // size = 0x1C

typedef struct unk_func_8830867C_02C_0CC_000_008 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ char unk01[0x1];
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ char unk04[0x5];
    /* 0x09 */ u8 unk_09[4];
    /* 0x0D */ char unk0D[0x3];
    /* 0x10 */ u8 unk_10;
    /* 0x11 */ u8 unk_11;
    /* 0x12 */ char unk12[0x2];
    /* 0x14 */ u16 unk_14;
    /* 0x16 */ u16 unk_16;
    /* 0x18 */ u16 unk_18;
    /* 0x1A */ u16 unk_1A;
    /* 0x1C */ u16 unk_1C;
    /* 0x1E */ u16 unk_1E;
    /* 0x20 */ u8 unk_20[4];
    /* 0x24 */ u8 unk_24;
    /* 0x26 */ u16 unk_26;
    /* 0x28 */ u16 unk_28;
    /* 0x2A */ u16 unk_2A;
    /* 0x2C */ u16 unk_2C;
    /* 0x2E */ u16 unk_2E;
} unk_func_8830867C_02C_0CC_000_008; // size = 0x30

typedef struct unk_func_8830867C_02C_0CC_000 {
    /* 0x00 */ unk_func_8830867C_02C_0CC_000_000* unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ unk_func_8830867C_02C_0CC_000_008 unk_08;
    /* 0x38 */ char unk_38[4];
    /* 0x3C */ char unk3C[0x20];
} unk_func_8830867C_02C_0CC_000; // size = 0x5C

typedef struct unk_func_8830867C_02C_0CC {
    /* 0x00 */ unk_func_8830867C_02C_0CC_000** unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
} unk_func_8830867C_02C_0CC; // size = 0xC

typedef struct unk_func_8830867C_04C_030_02C_000_000_00C {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ char unk04[0x4];
    /* 0x08 */ s32 unk_08;
} unk_func_8830867C_04C_030_02C_000_000_00C; // size >= 0xC

typedef void (*func_func_8002D1AC)();
typedef s32 (*unk_D_8831A1F8)(s32, s32);

void func_8002C740(unk_func_88201DA0_038*, unk_func_88201DA0_034*, s32, s32, s32);
void func_8002C758(unk_func_8820BE14_06C*, s32, s32, MemoryPool*);
void func_8002C88C(unk_func_8820BE14_06C*, u8*, s32);
void func_8002C990(unk_func_8820BE14_06C*, s32);
s32 func_8002CB58(unk_func_8830867C_04C_030_02C_000_000_00C*, s32);
void func_8002CBC0(unk_func_88200FA0_030_038*, s32, MemoryPool*);
void func_8002CBB0(unk_func_88205880_A030*, void*, s32, s32);
void func_8002CC2C(unk_func_88200FA0_030_038*, char*, s32);
void func_8002CC80(unk_func_8830867C_02C_0CC*, s32);
void func_8002D180(unk_func_8830867C_02C_0CC*, unk_D_8831A1F8);
void func_8002D1AC(unk_func_8830867C_02C_0CC*, unk_func_8830867C_02C_0CC*, func_func_8002D1AC, s32*);
s32 func_8002D348(u8*, u8*);
void func_8002D3F0(f32*);
Color_RGBA8 func_8002D444(Color_RGBA8, f32);

#endif // _3D340_H_
