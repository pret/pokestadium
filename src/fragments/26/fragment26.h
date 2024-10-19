#ifndef _FRAGMENT26_H_
#define _FRAGMENT26_H_

#include "global.h"
#include "src/memory.h"
#include "src/controller.h"

struct unk_func_88001300;
struct unk_func_88001300_000;
struct unk_func_88001300_03C;

typedef s32 (*unk_func_88001300_018)(struct unk_func_88001300_000*, s32, s32);
typedef s32 (*unk_func_88001300_01C)(struct unk_func_88001300_000*);
typedef s32 (*unk_func_88001300_020)(struct unk_func_88001300*, Controller*);
typedef void (*unk_func_88001300_024)(struct unk_func_88001300*, s32);

typedef struct unk_func_88001300_000_000 {
    /* 0x00 */ char unk00[0x4];
    /* 0x04 */ struct unk_func_88001300* unk_04;
    /* 0x08 */ struct unk_func_88001300* unk_08;
} unk_func_88001300_000_000; // size >= 0xC

typedef struct unk_func_88001300_000 {
    /* 0x00 */ unk_func_88001300_000_000 unk_00;
    /* 0x0C */ char unk0C[0x4];
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s16 unk_16;
    /* 0x18 */ unk_func_88001300_018 unk_18;
    /* 0x1C */ unk_func_88001300_01C unk_1C;
    /* 0x20 */ unk_func_88001300_020 unk_20;
    /* 0x24 */ unk_func_88001300_024 unk_24;
    /* 0x28 */ u16 unk_28;
    /* 0x2A */ u16 unk_2A;
} unk_func_88001300_000; // size = 0x2C

typedef struct unk_func_88001300_02C {
    /* 0x00 */ unk_func_88001300_000_000 unk_00;
    /* 0x0C */ char unk0C[0x20];
    /* 0x2C */ s32 unk_2C;
} unk_func_88001300_02C; // size = 0x30

typedef struct unk_func_88001300_030 {
    /* 0x00 */ unk_func_88001300_000_000 unk_00;
    /* 0x0C */ char unk0C[0x20];
    /* 0x2C */ Color_RGBA8_u32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ char unk38[0x4];
} unk_func_88001300_030; // size = 0x3C

typedef struct unk_func_88001300_034 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ char unk2C[0x4];
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ char unk34[0xC];
    /* 0x40 */ s32 unk_40;
} unk_func_88001300_034; // size = 0x44

typedef struct unk_func_88001300_038 {
    /* 0x00 */ char unk00[0x28];
    /* 0x28 */ u16 unk_28;
    /* 0x2A */ char unk2A[0xA];
} unk_func_88001300_038; // size = 0x34

typedef struct unk_func_88001300_03C_00C {
    /* 0x00 */ char unk00[0x10];
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s16 unk_16;
    /* 0x18 */ char unk18[0x14];
} unk_func_88001300_03C_00C; // size = 0x2C

typedef struct unk_func_88001300_03C_01C {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ Color_RGBA8_u32 unk_2C;
    /* 0x30 */ s32 unk_30;
} unk_func_88001300_03C_01C; // size = 0x34

typedef s32 (*unk_func_88001300_03C_010)(struct unk_func_88001300_03C*, Controller*);
typedef void (*unk_func_88001300_03C_014)(struct unk_func_88001300_03C*, s32);

typedef struct unk_func_88001300_03C {
    /* 0x00 */ char unk00[0xC];
    /* 0x00 */ unk_func_88001300_03C_00C* unk_0C;
    /* 0x10 */ unk_func_88001300_03C_010 unk_10;
    /* 0x14 */ unk_func_88001300_03C_014 unk_14;
    /* 0x18 */ unk_func_88001300_000** unk_18;
    /* 0x1C */ unk_func_88001300_03C_01C* unk_1C;
    /* 0x20 */ char unk20[0x4];
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ char unk28[0x4];
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ char unk30[0x10];
} unk_func_88001300_03C; // size = 0x40

typedef struct unk_func_88001300 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ unk_func_88001300_02C* unk_2C;
    /* 0x30 */ unk_func_88001300_030* unk_30;
    /* 0x34 */ unk_func_88001300_034* unk_34;
    /* 0x38 */ unk_func_88001300_038* unk_38;
    /* 0x3C */ unk_func_88001300_03C* unk_3C;
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ char unk44[0xC];
    /* 0x50 */ s32 unk_50;
    /* 0x54 */ s32 unk_54;
} unk_func_88001300; // size = 0x58

typedef struct unk_func_88500E34 {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ u8* unk_2C;
} unk_func_88500E34; // size = 0x30

typedef struct unk_func_88509A2C {
    /* 0x00 */ unk_func_88001300_000 unk_00;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ char* unk_3C;
    /* 0x40 */ char unk_40[12];
} unk_func_88509A2C; // size = 0x4C

typedef struct unk_func_88500020 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ u8* unk_0C;
} unk_func_88500020; // size = 0x10

typedef void (*func88500020)(unk_func_88500020*, s32, s32);
typedef void (*func8850068C)(unk_func_88001300_000_000*, unk_func_88001300_000_000*);
typedef void (*func885007CC)(unk_func_88001300_000*, s32);
typedef void (*func88500828)(unk_func_88001300*, s32, s32);
typedef void (*func885008C4)(unk_func_88001300*);
typedef void (*func8850093C)(s32, s32);
typedef void (*func88500E34)(unk_func_88500E34*, s32, s32, s32, s32, u8*);
typedef void (*func88502274)(unk_func_88001300_038*, s32, s32, s32, s32);
typedef void (*func88503118)(unk_func_88001300_02C*, s32, s32, s32, s32);
typedef void (*func88504570)(unk_func_88001300_03C_01C*, s32, s32, s32, s32, Color_RGBA8);
typedef void (*func885054D8)(unk_func_88001300_030*, s32, s32, s32, s32, Color_RGBA8);
typedef void (*func88505E2C)(unk_func_88001300_034*, s32, s32, s32, s32, s32, Color_RGBA8, unk_D_800AC870*);
typedef void (*func88506074)(unk_func_88001300_034*, char*);
typedef void (*func88509A2C)(unk_func_88509A2C*, s32, s32, s32, char*);
typedef void (*func8850BC94)(s32);
typedef void (*func8850C284)(unk_func_88001300_03C*, s32, s32, MemoryPool*);
typedef void (*func8850CB48)(unk_func_88001300_03C*, s32);

void func_88500020(unk_func_88500020*, s32, s32);
void func_8850068C(unk_func_88001300_000_000*, unk_func_88001300_000_000*);
void func_885007CC(unk_func_88001300_000*, s32);
void func_88500828(unk_func_88001300*, s32, s32);
void func_885008C4(unk_func_88001300*);
void func_8850093C(s32, s32);
void func_88500E34(unk_func_88500E34*, s32, s32, s32, s32, u8*);
void func_88502274(unk_func_88001300_038*, s32, s32, s32, s32);
void func_88503118(unk_func_88001300_02C*, s32, s32, s32, s32);
void func_88504570(unk_func_88001300_03C_01C*, s32, s32, s32, s32, Color_RGBA8);
void func_885054D8(unk_func_88001300_030*, s32, s32, s32, s32, Color_RGBA8);
void func_88505E2C(unk_func_88001300_034*, s32, s32, s32, s32, s32, Color_RGBA8, unk_D_800AC870*);
void func_88506074(unk_func_88001300_034* arg0, char* arg1);
void func_88509A2C(unk_func_88509A2C*, s32, s32, s32, char*);
void func_8850BC94(s32);
void func_8850C284(unk_func_88001300_03C*, s32, s32, MemoryPool*);
void func_8850CB48(unk_func_88001300_03C*, s32, s32);


#endif // _FRAGMENT26_H_
