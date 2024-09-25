#ifndef _12D80_H_
#define _12D80_H_

#include "global.h"

typedef struct unk_D_800AB970 {
    /* 0x000 */ Vec3f unk_000[1];
    /* 0x00C */ char unk00C[0x174];
    /* 0x180 */ s32 unk_180;
    /* 0x184 */ char unk184[0xC];
} unk_D_800AB970; // size = 0x190?

typedef struct unk_D_800ABB00 {
    /* 0x00 */ void* unk_00;
    /* 0x04 */ void* unk_04;
    /* 0x08 */ char unk08[0x8];
} unk_D_800ABB00; // size >= 0x10?

typedef struct unk_D_800ABB28 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Gfx* unk_04;
    /* 0x08 */ Gfx* unk_08;
    /* 0x0C */ MtxF* unk_0C;
    /* 0x10 */ Color_RGBA8_u32 unk_10;
    /* 0x14 */ Color_RGBA8_u32 unk_14;
    /* 0x18 */ unk_D_86002F34_alt11_018* unk_18;
    /* 0x1C */ struct unk_D_800ABB28* unk_1C;
    /* 0x20 */ Gfx* unk_20;
    /* 0x24 */ u8 unk_24;
    /* 0x24 */ u8 unk_25;
    /* 0x24 */ u8 unk_26;
    /* 0x24 */ u8 unk_27;
} unk_D_800ABB28; // size = 0x28

typedef struct unk_D_800ABB10 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ Color_RGBA8_u32 unk_04;
    /* 0x08 */ Color_RGBA8_u32 unk_08;
    /* 0x0C */ unk_D_86002F34_alt11_018* unk_0C;
    /* 0x10 */ unk_D_800ABB28* unk_10;
    /* 0x14 */ Gfx* unk_14;
} unk_D_800ABB10; // size = 0x18?

extern s32 D_8006F080;
extern u16 D_8006F084;
extern unk_D_86002F34_00C* D_8006F088;
extern unk_D_86002F34_alt1* D_8006F08C;
extern unk_D_86002F34_alt1* D_8006F090;
extern unk_D_86002F34_00C* D_8006F094;
extern unk_D_86002F34_alt1* D_8006F098;
extern unk_D_86002F58_004_000* D_8006F09C;
extern unk_D_86002F34_alt11* D_8006F0A0;

void func_80012180(void);
void func_800121C8(void);
void func_80012230(MtxF* arg0);
void func_800122B4(MtxF* arg0);
void func_80012344(Vec3f* arg0);
MtxF* func_800123D4(s32 arg0);
MtxF* func_80012400(s32 arg0);
void func_80012428(void);
void func_80012458(Vec3f* arg0);
Vtx* func_800124D4(unk_D_86002F34_00C_0CC* arg0, unk_D_86002F34_00C_040* arg1);
void func_80012768(unk_D_86002F34_00C_0CC* arg0, unk_D_86002F34_00C_040* arg1);
void func_80012870(Vtx* arg0, unk_D_86002F34_00C_0CC* arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7);
Vtx* func_80012960(unk_D_86002F34_00C_0CC* arg0);
void func_80012D88(unk_D_86002F34_00C_0CC* arg0, UNUSED unk_D_86002F34_00C_040* arg1);
void func_800131B4(unk_D_86002F34_00C_0CC* arg0, unk_D_86002F34_00C_040* arg1);
void func_80013330(unk_D_86002F34_000* arg0);
void func_800133D8(unk_D_86002F34_000* arg0);
void func_80013464(unk_D_86002F34_000* arg0);
void func_80013764(unk_D_86002F34_000* arg0);
void func_8001378C(unk_D_86002F34_000* arg0);
void func_800138F0(unk_D_86002F34_000* arg0);
void func_8001395C(unk_D_86002F34_000* arg0);
void func_800139E8(unk_D_86002F34_000* arg0);
void func_80013AF8(unk_D_86002F34_000* arg0);
void func_80013B8C(UNUSED unk_D_86002F34_000* arg0);
void func_80013C14(UNUSED unk_D_86002F34_000* arg0);
void func_80013C1C(unk_D_86002F34_000* arg0);
void func_80013D34(unk_D_86002F34_000* arg0);
void func_80013F7C(UNUSED unk_D_86002F34_000* arg0);
void func_80013F84(unk_D_86002F34_000* arg0);
void func_80014124(unk_D_86002F34_000* arg0);
void func_80014214(unk_D_86002F34_000* arg0);
void func_800142BC(unk_D_86002F34_000* arg0);
void func_80014334(unk_D_86002F34_000* arg0);
void func_80014384(unk_D_86002F34_000* arg0);
void func_800143C0(unk_D_86002F34_000* arg0);
void func_80014624(unk_D_86002F34_000* arg0);
void func_80014690(unk_D_86002F34_000* arg0);
void func_800148D8(unk_D_86002F34_000* arg0);
void func_80014980(unk_D_86002F34_000* arg0);
void func_80014A60(unk_D_86002F34_000* arg0);
void func_80014AEC(unk_D_86002F34_000* arg0);
void func_80014CB8(s32 arg0);
void func_80014D24(unk_D_86002F34_000* arg0);
void func_80014D50(unk_D_86002F34_000* arg0);
void func_80014D70(unk_D_86002F34_000* arg0);
void func_80015094(unk_D_86002F34_000* arg0);
void func_80015220(unk_D_86002F34_000* arg0, s32 arg1);
void func_8001533C(s32 arg0);
void func_80015348(void);
s32 func_80015360(void);
Vec3f* func_80015390(unk_D_86002F58_004_000* arg0, s16 arg1, Vec3f* arg2);
void func_80015400(Gfx* arg0, u8* arg1);
void func_8001550C(void);
void func_8001554C(void);
void func_80015684(void);
void func_8001587C(unk_D_800ABB10* arg0);
void func_80015948(UNUSED unk_D_800ABB10* arg0);
void func_80015984(unk_D_800ABB10* arg0);
void func_80015A44(unk_D_800ABB10* arg0);
void func_80015AC4(UNUSED unk_D_800ABB10* arg0);
void func_80015B20(unk_D_800ABB10* arg0);
void func_80015DD8(UNUSED unk_D_800ABB10* arg0);
void func_80015F64(s16 arg0);
void func_80016010(s16 arg0);
s16 func_80016060(s16 arg0);
void func_800160E0(s16 arg0, MtxF* arg1);
void func_80016274(Gfx* arg0, s32 arg1);
void func_80016344(Color_RGBA8_u32 arg0, u8 arg1, u32 arg2);
void func_80016364(s32 arg0, Color_RGBA8_u32 arg1, unk_D_86002F34_alt11_018* arg2, unk_D_86002F34_alt11_018* arg3, s32 arg4);
void func_8001638C(s32 arg0, s32 arg1);
void func_8001660C(void);

#endif // _12D80_H_
