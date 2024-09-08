#ifndef _26820_H_
#define _26820_H_

#include "global.h"

typedef struct unk_func_8002A728 {
    /* 0x00 */ s16 unk_00;
    /* 0x04 */ u32* unk_04;
} unk_func_8002A728; // size = 0x8

typedef struct unk_func_80027F24 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ unk_func_8002A728* unk_04;
} unk_func_80027F24; // size = 0x8

void func_80026684(s32, s32);
void func_80027F24(unk_func_80027F24*);
void func_80027F40(unk_func_80027F24*);
void func_80028070(u16*);
void func_800280D4(s32);
void func_800284B4(s32);
void func_80028AFC(s32);

#endif // _26820_H_
