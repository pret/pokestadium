#ifndef _46680_H_
#define _46680_H_

#include "global.h"

typedef struct unk_D_800FCED8_0000 {
    /* 0x000 */ char unk000[0x166];
    /* 0x166 */ s16 unk_166;
    /* 0x168 */ char unk168[0x28];
} unk_D_800FCED8_0000; // size = 0x190

typedef struct unk_D_800FCED8_0198 {
    /* 0x000 */ char unk_0000[0x1400];
} unk_D_800FCED8_0198; // size = 0x1400

typedef struct unk_D_800FCED8_01598 {
    /* 0x00 */ char unk00[0x4];
    /* 0x04 */ u32 unk_04;
} unk_D_800FCED8_01598; // size = 0x8

typedef void (*unk_D_800FCED8_190)(s32, unk_D_800FCED8_01598*, s32, OSMesgQueue*);

typedef struct unk_D_800FCED8 {
    /* 0x0000 */ unk_D_800FCED8_0000 unk_0000;
    /* 0x0190 */ unk_D_800FCED8_190 unk_0190;
    /* 0x0194 */ s32 unk_0194;
    /* 0x0198 */ unk_D_800FCED8_0198 unk_0198;
    /* 0x1598 */ unk_D_800FCED8_01598 unk_1598[1];
    /* 0x15A0 */ u32 unk_15A0;
    /* 0x15A4 */ char unk_15A4[0xFF4];
    /* 0x2598 */ u16 unk_2598;
    /* 0x259A */ u16 unk_259A;
    /* 0x259C */ u32 unk_259C;
    /* 0x25A0 */ OSMesgQueue unk_25A0;
    /* 0x25B8 */ OSMesg unk_25B8;
    /* 0x25BC */ u32 unk_25BC;
    /* 0x25C0 */ u32 unk_25C0;
    /* 0x25C4 */ u32 unk_25C4;
    /* 0x25C8 */ s32 unk_25C8;
    /* 0x25CC */ u32 unk_25CC;
    /* 0x25D0 */ s8 unk_25D0;
    /* 0x25D1 */ s8 unk_25D1;
    /* 0x25D2 */ s8 unk_25D2;
    /* 0x25D3 */ char unk25D3[0x5];
} unk_D_800FCED8; // size = 0x25D8

s32 func_80045FF0(unk_D_800FCED8*, void*);

#endif // _46680_H_
