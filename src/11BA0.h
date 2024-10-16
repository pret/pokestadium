#ifndef _11BA0_H_
#define _11BA0_H_

#include "global.h"
#include "src/memory.h"

typedef struct unk_func_80011B94 {
    /* 0x00 */ unk_D_86002F58_004_000_000 unk_00;
    /* 0x18 */ Gfx* unk_18;
} unk_func_80011B94; // size = 0x1C

typedef struct unk_D_8690A610_018 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ Color_RGBA8_u32 unk_04;
} unk_D_8690A610_018; // size = 0x8

typedef struct unk_D_8690A610 {
    /* 0x00 */ unk_D_86002F58_004_000_000 unk_00;
    /* 0x18 */ unk_D_8690A610_018 unk_18;
} unk_D_8690A610; // size = 0x20

void func_80010FA0(struct GraphNode* arg0, u8 arg1);
void func_80010FDC(struct GraphNode* arg0, func_D_86002F34_000_010 arg1, unk_D_86002F34_000_014* arg2);
struct GraphNode* func_8001103C(MainPoolState* arg0, struct GraphNode* arg1);
unk_D_86002F34_alt2* func_80011088(MainPoolState* arg0, unk_D_86002F34_alt2* arg1, struct GraphNode* arg2);
unk_D_86002F34_00C* func_800110E0(MemoryBlock* arg0, unk_D_86002F34_00C* arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5);
unk_D_86002F34_alt13* func_800111A4(MemoryBlock* arg0, unk_D_86002F34_alt13* arg1, s16 arg2);
unk_D_86002F34_alt1* func_800111FC(MemoryBlock* arg0, unk_D_86002F34_alt1* arg1, s16 arg2);
unk_D_86002F34_alt14* func_80011258(MainPoolState* arg0, unk_D_86002F34_alt14* arg1, s16 arg2);
unk_D_86002F34_alt15* func_800112BC(MainPoolState* arg0, unk_D_86002F34_alt15* arg1, s16 arg2);
unk_D_86002F34_alt16* func_80011320(MainPoolState* arg0, unk_D_86002F34_alt16* arg1, u8 arg2, u8 arg3, u8 arg4);
unk_D_86002F34_alt17* func_800113AC(MainPoolState* arg0, unk_D_86002F34_alt17* arg1);
unk_D_8690A610* func_800113F8(s32 arg0, unk_D_8690A610* arg1, s16 arg2, s16 arg3, u8 r, u8 g, u8 b, u8 a);
unk_D_86002F34_alt18* func_80011484(MainPoolState* arg0, unk_D_86002F34_alt18* arg1, s16 arg2, s16 arg3, u8 r, u8 g, u8 b, u8 a);
unk_D_86002F34_alt19* func_80011504(MainPoolState* arg0, unk_D_86002F34_alt19* arg1, u8 r, u8 g, u8 b);
unk_D_86002F34* func_8001156C(MainPoolState* arg0, unk_D_86002F34* arg1, s32 arg2, 
                              unk_D_86002F34_018* arg3, s32 arg4, unk_D_86002F34_01C* arg5, 
                              s32 arg6, Vtx* arg7);
unk_D_86002F34_alt12* func_800115F0(MainPoolState* arg0, unk_D_86002F34_alt12* arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5);
unk_D_86002F34_alt20* func_80011660(MainPoolState* arg0, unk_D_86002F34_alt20* arg1, s16 arg2, s16 arg3);
unk_D_86002F34_alt21* func_800116C0(MainPoolState* arg0, unk_D_86002F34_alt21* arg1, s16 arg2, s16 arg3);
unk_D_86002F34_alt5* func_80011720(MainPoolState* arg0, unk_D_86002F34_alt5* arg1, Vec3f* arg2, Vec3s* arg3);
unk_D_86002F34_alt22* func_800117A8(MainPoolState* arg0, unk_D_86002F34_alt22* arg1, Vec3f* arg2);
unk_D_86002F34_alt6* func_80011814(MainPoolState* arg0, unk_D_86002F34_alt6* arg1, s16 arg2, s16 arg3, s16 arg4, Vec3s* arg5, Vec3s* arg6, Vec3f* arg7);
unk_D_86002F34_alt7* func_800118D0(MainPoolState* arg0, unk_D_86002F34_alt7* arg1, s32 arg2, Gfx* arg3, s16 arg4);
unk_D_86002F58_004_000* func_80011938(MainPoolState* arg0, unk_D_86002F58_004_000* arg1, s16 arg2, Vec3f* arg3,
                                      Vec3s* arg4, Vec3f* arg5);
unk_D_86002F34_alt8* func_80011A3C(MainPoolState* arg0, unk_D_86002F34_alt8* arg1, s32 arg2, Gfx* arg3, MtxF* arg4);
unk_D_86002F34_alt8* func_80011ABC(MainPoolState* arg0, unk_D_86002F34_alt8* arg1, s32 arg2, Gfx* arg3, Vec3f* arg4, Vec3s* arg5);
unk_D_86002F34_alt9* func_80011B10(MainPoolState* arg0, unk_D_86002F34_alt9* arg1, s32 arg2, Gfx* arg3, Vec3f* arg4, f32 arg5);
unk_func_80011B94* func_80011B94(MainPoolState* arg0, unk_func_80011B94* arg1, s32 arg2, Gfx* arg3);
unk_D_86002F34_alt10* func_80011BF4(MainPoolState* arg0, unk_D_86002F34_alt10* arg1, s16 arg2, s16 arg3, Gfx* arg4, s16 arg5, s16 arg6, u8 r, u8 g, u8 b, u8 a);
unk_D_86002F34_alt23* func_80011C98(MainPoolState* arg0, unk_D_86002F34_alt23* arg1, s16 arg2);
unk_D_86002F34_alt24* func_80011CF0(MainPoolState* arg0, unk_D_86002F34_alt24* arg1, s32 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s32 arg9, 
                                    u8 r, u8 g, u8 b, u8 a);
void func_80011DAC(unk_D_86002F34_00C* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void func_80011E68(unk_D_86002F34_00C* arg0, f32 arg1, f32 arg2, f32 arg3);
void func_80011EB4(unk_D_86002F34_00C* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, s32 arg7);
void func_80011FC8(unk_D_86002F34_00C* arg0, s16 arg1, s16 arg2, u8 arg3, u8 arg4, u8 arg5);
void func_80012094(struct GraphNode* arg0, struct GraphNode* arg1);
#endif // _11BA0_H_
