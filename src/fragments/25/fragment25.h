#ifndef _FRAGMENT25_H_
#define _FRAGMENT25_H_

#include "global.h"
#include "29BA0.h"

typedef struct unk_D_88400100 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Color_RGBA8 unk_04;
} unk_D_88400100; // size = 0x8

typedef struct unk_D_88400138 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Color_RGBA8 unk_04;
    /* 0x08 */ Color_RGBA8 unk_08;
} unk_D_88400138; // size = 0xC

typedef unk_D_88400100* (*func8840007C)(unk_func_80026268_arg0*);
typedef unk_D_88400138* (*func884000C4)(s32);

unk_D_88400100* func_8840007C(unk_func_80026268_arg0*);
unk_D_88400138* func_884000C4(s32);

#endif // _FRAGMENT25_H_
