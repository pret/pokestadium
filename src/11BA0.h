#ifndef _11BA0_H_
#define _11BA0_H_

#include "global.h"
#include "src/memory.h"

typedef struct unk_func_80011B94 {
    /* 0x00 */ unk_D_86002F58_004_000_000 unk_00;
    /* 0x18 */ Gfx* unk_18;
} unk_func_80011B94; // size = 0x1C

unk_D_86002F58_004_000_000* func_8001103C(MainPoolState*, void*);
unk_D_86002F58_004_000* func_80011938(MainPoolState* arg0, unk_D_86002F58_004_000* arg1, s16 arg2, Vec3f* arg3, Vec3s* arg4, Vec3f* arg5);
unk_func_80011B94* func_80011B94(MainPoolState*, void*, s32, Gfx*);
void func_80012094(unk_D_86002F58_004_000_000*, unk_D_86002F58_004_000_000*);


#endif // _11BA0_H_
