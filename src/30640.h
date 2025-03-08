#ifndef _30640_H_
#define _30640_H_

#include "global.h"
#include "1C720.h"
#include "src/6BC0.h"

typedef struct unk_D_83407AC8 {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ s8 unk_03[11];
    /* 0x0E */ s8 unk_0E[11];
} unk_D_83407AC8; // size >= 0x1A

typedef struct unk_D_83402EE0_070 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03[11];
    /* 0x0E */ u8 unk_0E[11];
    /* 0x19 */ char unk19[0x1];
} unk_D_83402EE0_070; // size = 0x1A

typedef struct unk_D_83402EE0_00A {
    /* 0x00 */ u8 unk_00[7];
} unk_D_83402EE0_00A; // size = 0x7

typedef struct unk_D_83402EE0 {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ u8 unk_09;
    /* 0x0A */ unk_D_83402EE0_00A unk_0A[10];
    /* 0x50 */ Vec3f unk_50;
    /* 0x5C */ Vec3f unk_5C;
    /* 0x68 */ u32 unk_68;
    /* 0x6C */ u8 unk_6C;
    /* 0x6D */ char unk6D[3];
    /* 0x70 */ unk_D_83402EE0_070 unk_70;
} unk_D_83402EE0; // size = 0x8C

typedef struct unk_D_83403C60 {
    /* 0x00 */ unk_func_80026268_arg0 unk_00;
    /* 0x54 */ char unk54[0x38];
} unk_D_83403C60; // size = 0x8C

typedef struct unk_D_83406EB0 {
    /* 0x00 */ char unk00[0x6C];
    /* 0x6C */ u8 unk_6C;
    /* 0x6D */ char unk6D[0x1F];
} unk_D_83406EB0; // size = 0x8C

typedef struct unk_D_83407B00 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
} unk_D_83407B00; // size = 0x8

typedef struct unk_func_80031270 {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ unk_D_80068BB0* unk_08;
    /* 0x0C */ unk_D_80068BB0* unk_0C;
    /* 0x10 */ unk_D_86002F58_004_000_010* unk_10;
    /* 0x14 */ BinArchive* unk_14;
    /* 0x18 */ unk_D_83403C60* unk_18;
    /* 0x1C */ GraphNode* unk_1C;
    /* 0x20 */ char unk20[0x14];
    /* 0x32 */ s32 unk_34;
} unk_func_80031270; // size = 0x38

typedef struct unk_D_83407B38_0B0_008 {
    /* 0x00 */ s32 unk_00;
    /* 0x00 */ s32 unk_08;
} unk_D_83407B38_0B0_008; // size >= 0xC

typedef struct unk_D_83407B38_0B0 {
    /* 0x00 */ s32 unk_00;
    /* 0x00 */ s32 unk_08;
} unk_D_83407B38_0B0; // size >= 0xC

typedef struct unk_D_83407B38 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ unk_func_80031270* unk_20[36];
    /* 0xB0 */ unk_func_80031270* unk_B0;
} unk_D_83407B38; // size = 0xB4

extern unk_D_83407B00 D_83407B30;

void func_8002FA40(void);
void func_8002FF00(void);
void func_8002FF20(void);
void func_8003107C(unk_D_83402EE0_070*, unk_func_80026268_arg0*);
void func_80031140(unk_func_80026268_arg0*, unk_D_83407AC8*);
unk_func_80031270* func_80031270(s16, s16, unk_D_80068BB0*, unk_D_80068BB0*, unk_D_86002F58_004_000_010*, BinArchive*, unk_D_83403C60*);
void func_80031660(unk_func_80031270*);
s32 func_800317D8(unk_func_80031270*);
s32 func_8003181C(unk_func_80031270**, s32);
u16* func_800318AC(void);
void func_800318B8(void);
s32 func_800318C4(unk_D_83403C60*);
f32 func_80031A6C(f32);
void func_80031EF4(MtxF*, MtxF*);
void func_80032034(MtxF* arg0, Vec3f* arg1);

#endif // _30640_H_
