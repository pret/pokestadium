#include "435D0.h"

extern u8 D_800FCD48[8];
extern s8 D_800FCEB4;
extern s32 D_800FCEC8;
extern u8 D_800FCECC;
extern u8 D_800FCECD;

void func_800429D0(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if (D_800FCD48[i] != 0) {
            func_80042B8C(i);
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_80042A2C.s")

s32 func_80042AB0(u16 arg0) {
    s32 a;
    s32 offset;

    if (func_800449F8() != 0) {
        return 0;
    }

    func_80044A50(D_800FC6D4);

    if (D_800FC6D4->num_entries < arg0) {
        return 0;
    }

    offset = D_800FC6D4->offset;
    func_8004473C();

    arg0--;

    a = D_800FC6D4->entries[arg0].unk_00;
    D_800FCEB4 = a;
    D_800FCECC = D_800FC6D4->entries[arg0].unk_02;
    D_800FCECD = D_800FC6D4->entries[arg0].unk_03;
    D_800FCEC8 = offset + (a * 0x18);

    func_80044568(a);

    return 1;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_80042B8C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_80042D90.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_80042F20.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_800430AC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_80043134.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_800431DC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_800431FC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_8004327C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_80043330.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_80043364.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_8004340C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_80043434.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_80043488.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_800434E0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_80043514.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_80043534.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_800435CC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_800435E8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_80043708.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_800437A0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_80043838.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_80043A10.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_80043B28.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_80043C08.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_80043C74.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_80043DB0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_80043DF8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_80043E70.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_80043EC0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_80043F04.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_80044058.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_80044108.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_80044180.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_800441A4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_800441F0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_80044278.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_80044568.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_8004473C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_800448B4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_800449F8.s")

#ifdef NON_MATCHING
void func_80044A50(unk_D_800FC6D4* arg0) {
    u32 i;
    u32 end;
    testme* ptr;
    u32 a0 = arg0;

    if (arg0->flags != 0) {
        return;
    }

    end = arg0->unk_04 * 3;
    ptr = arg0->offset + a0;
    arg0->offset = ptr;

    for (i = 0; i < end; i++) {
        ptr[i].unk_00 += a0;
    }

    arg0->flags = 1;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/435D0/func_80044A50.s")
#endif
