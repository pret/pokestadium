#ifndef _45720_H_
#define _45720_H_

#include "global.h"
#include "src/46680.h"

typedef struct unk_D_800FCF28 {
    /* 0x000 */ s16 unk_000[0x8A0];
} unk_D_800FCF28; // size = 0x1140

extern unk_D_800FCF28* D_800FCF28[2];
extern u32 D_800FCF30[2];

void func_80044B20(ALHeap*, u32, u32);
void func_80044CBC(u32, u32, u32, u32);
void func_80044D78(u32, u32);
s32 func_80044E54(s32);
void func_80044E80(s32);
void func_80044EA4(void);
void func_800455DC(u32 arg0, u32 arg1, u32 arg2, OSMesgQueue* arg3);
void func_800456D0(unk_D_800FCED8*, s32, s32);
void func_80045780(unk_D_800FCED8*);
u32 func_800459E0(unk_D_800FCED8*, u32);
void func_80045A48(unk_D_800FCED8*);
void func_80045A68(unk_D_800FCED8*);

#endif // _45720_H_
