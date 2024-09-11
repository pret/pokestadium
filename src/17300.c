#include "17300.h"
#include "src/util.h"

#pragma GLOBAL_ASM("asm/us/nonmatchings/17300/func_80016700.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/17300/func_800167B4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/17300/func_80016848.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/17300/func_80016934.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/17300/func_80016B30.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/17300/func_80016D20.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/17300/func_80016DE0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/17300/func_80016F20.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/17300/func_80016FBC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/17300/func_80017080.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/17300/func_80017090.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/17300/func_80017188.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/17300/func_800171A8.s")

void func_800173CC(unk_D_86002F58_004_000* arg0) {
    arg0->unk_040.unk_00 = -1;
    arg0->unk_040.unk_04 = NULL;
}

s32 func_800173DC(unk_D_86002F58_004_000* arg0, s16 arg1, s32 arg2, s32 arg3) {
    unk_D_86002F58_004_000_040_004* temp_v0 = Util_ConvertAddrToVirtAddr(arg2);
    unk_D_86002F58_004_000_040* ptr = &arg0->unk_040;

    if ((temp_v0 != ptr->unk_04) || (arg1 != ptr->unk_00)) {
        ptr->unk_00 = arg1;
        ptr->unk_04 = temp_v0;
        ptr->unk_08 = (temp_v0->unk_04 << 0x10) - arg3;
    }

    ptr->unk_0C = arg3;
    return ptr->unk_08 >> 0x10;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/17300/func_80017454.s")

void func_80017464(unk_D_86002F58_004_000* arg0, s16 arg1) {
    arg0->unk_040.unk_08 = (arg1 << 0x10) - arg0->unk_040.unk_0C;
}

s32 func_80017484(unk_D_86002F58_004_000* arg0, s16 arg1) {
    unk_D_86002F58_004_000_040* ptr = &arg0->unk_040;
    s32 temp_v0 = ptr->unk_08 + ptr->unk_0C;
    s32 arg = arg1 << 0x10;
    s32 var_a2;
    s32 v = ptr->unk_0C;

    if (v >= 0) {
        var_a2 = ptr->unk_08 < arg;
        if (var_a2 != 0) {
            var_a2 = temp_v0 >= arg;
        }
    } else {
        var_a2 = (arg < ptr->unk_08);
        if (var_a2 != 0) {
            var_a2 = arg >= temp_v0;
        }
    }

    return var_a2;
}

void func_800174E4(unk_D_86002F58_004_000* arg0) {
    func_80017484(arg0, arg0->unk_040.unk_04->unk_0A - 1);
}

s32 func_80017514(unk_D_86002F58_004_000* arg0) {
    return arg0->unk_040.unk_08 >= ((arg0->unk_040.unk_04->unk_0A - 1) << 0x10);
}
