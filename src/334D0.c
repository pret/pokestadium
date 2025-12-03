#include "334D0.h"
#include "src/12D80.h"
#include "src/30640.h"
#include "src/32D10.h"
#include "src/6A40.h"
#include "src/F420.h"

typedef struct unk_D_800AFFC8 {
    /* 0x000 */ s16 unk_000;
    /* 0x002 */ char unk002[0x7CE];
} unk_D_800AFFC8; // size = 0x7D0

extern unk_D_800AFFC8 D_800AFFC8[2][3];

#pragma GLOBAL_ASM("asm/us/nonmatchings/334D0/func_800328D0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/334D0/func_800328D8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/334D0/func_800328E4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/334D0/func_80032940.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/334D0/func_80032990.s")

void func_80032A34(s32 arg0) {
    s32 i;
    unk_D_800AFFC8* var_v1 = &D_800AFFC8[arg0];

    for (i = 0; i < 3; i++) {
        var_v1[i].unk_000 = 0;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/334D0/func_80032A7C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/334D0/func_80032BD4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/334D0/func_80032D28.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/334D0/func_80032E00.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/334D0/func_80032F94.s")
