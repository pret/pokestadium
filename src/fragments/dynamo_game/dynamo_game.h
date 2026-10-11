#ifndef _FRAGMENT11_H_
#define _FRAGMENT11_H_

#include "global.h"
#include "src/geo_node.h"

typedef struct unk_D_8650A528 {
    /* 0x000 */ s32 unk_000;
    /* 0x004 */ s32 unk_004;
    /* 0x008 */ s32 unk_008;
    /* 0x00C */ u8 unk_00C;
    /* 0x00D */ s8 unk_00D;
    /* 0x00E */ s8 unk_00E;
    /* 0x010 */ s16 unk_010;
    /* 0x010 */ s16 unk_012;
    /* 0x014 */ DisplayObject unk_014;
    /* 0x17C */ unk_D_86002F34_alt9* unk_17C;
} unk_D_8650A528; // size = 0x180

typedef struct unk_D_8650AB30_000 {
    /* 0x00 */ s8 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
} unk_D_8650AB30_000; // size = 0xC

typedef struct unk_D_8650AB30 {
    /* 0x00 */ unk_D_8650AB30_000 unk_00[12];
} unk_D_8650AB30; // size = 0x90

extern s32 D_86509250;
extern s32 D_86509254;
extern u8 D_8650AD84;
extern u8 D_8650AD85;
extern unk_D_8650A528 D_8650A528[4];
extern unk_D_8650A528* D_8650AB28;
extern unk_D_8650AB30 D_8650AB30[4];
extern unk_D_8650AB30* D_8650AD70;
extern u32 D_86506750[];
extern u32 D_86506F50[];
extern u32 D_86507750[];
extern u32 D_86507F50[];
extern u32 D_86508750[];

s8 DynamoGame_RollAIChargeBias(s32, s32);
void DynamoGame_DrawSparkEffects(s32 arg0);
void DynamoGame_InitSparkEffects(void);
void DynamoGame_PickNextCrankCue(void);
void DynamoGame_DrawCrankIcon(void);
void DynamoGame_InitCrankIconDisplay(void);

#endif // _FRAGMENT11_H_
