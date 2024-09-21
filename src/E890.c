#include "E890.h"
#include <PR/leo.h>

extern char D_8006F000[];
extern char D_8006F004[];

s32 func_8000DC90(void) {
    if (osMemSize < 0x800000) {
        return 2;
    }

    if (bcmp(&D_800818E0[0x18], D_8006F004, 2) != 0) {
        return 1;
    }

    if (bcmp(&D_800818E0[1], D_8006F000, 3) != 0) {
        return 1;
    }

    if (D_800818E0[0] < 'E') {
        return 1;
    }

    if (D_800818E0[0] > 'Z') {
        return 1;
    }

    if (D_800818E0[5] != 1) {
        return 1;
    }

    _bcopy(&D_800818E0, &leoBootID, 0x20);
    return 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/E890/func_8000DD68.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/E890/func_8000DDB0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/E890/func_8000DDE4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/E890/func_8000DE18.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/E890/func_8000DE70.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/E890/func_8000DED0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/E890/func_8000E0EC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/E890/func_8000E21C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/E890/func_8000E3B4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/E890/func_8000E51C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/E890/func_8000E5BC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/E890/func_8000E6EC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/E890/func_8000E760.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/E890/func_8000E7E4.s")
