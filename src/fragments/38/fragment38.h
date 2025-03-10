#ifndef _FRAGMENT38_H_
#define _FRAGMENT38_H_

#include "global.h"
#include "src/29BA0.h"

typedef struct unk_D_82305A28 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
} unk_D_82305A28; // size = 0x8

typedef struct unk_D_82305A50 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ u8* unk_0C;
    /* 0x10 */ char* unk_10;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s16 unk_16;
    /* 0x18 */ s16 unk_18;
} unk_D_82305A50; // size = 0x1C

typedef struct unk_D_82305A30 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
} unk_D_82305A30; // size = 0x8

typedef struct unk_D_82305A40 {
    /* 0x00 */ u8 unk_00;
    /* 0x00 */ u8 unk_01;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
} unk_D_82305A40; // size = 0x10

typedef struct unk_D_82305AF8 {
    /* 0x0000 */ u8 unk_0000;
    /* 0x0001 */ u8 unk_0001;
    /* 0x0002 */ u8 unk_0002;
    /* 0x0003 */ u8 unk_0003;
    /* 0x0004 */ s16 unk_0004;
    /* 0x0006 */ s16 unk_0006;
    /* 0x0008 */ s16 unk_0008;
    /* 0x000A */ s16 unk_000A;
    /* 0x000C */ s16 unk_000C;
    /* 0x000E */ s16 unk_000E;
    /* 0x0010 */ s16 unk_0010;
    /* 0x0012 */ u16 unk_0012;
    /* 0x0014 */ char unk_0014[4];
    /* 0x0018 */ char unk0018[0x8];
    /* 0x0020 */ unk_func_80026268_arg0 unk_0020[6];
    /* 0x0218 */ u8 unk_0218[6][0xC80];
} unk_D_82305AF8; // size = 0x4D18

typedef struct unk_D_8230F528 {
    /* 0x00 */ u8 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ char* unk_08;
} unk_D_8230F528; // size = 0x0C

typedef struct unk_D_82305920 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
} unk_D_82305920; // size = 0xA

typedef struct unk_D_82305978 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
} unk_D_82305978; // size = 0x8

u8 func_82302BB4(unk_D_82305AF8* arg0, s16 arg1);

#endif // _FRAGMENT38_H_
