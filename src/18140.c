#include "18140.h"
#include "src/util.h"

#pragma GLOBAL_ASM("asm/us/nonmatchings/18140/func_80017540.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18140/func_80017578.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18140/func_800175D8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18140/func_800175E8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18140/func_800176BC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/18140/func_800176DC.s")

void func_80017788(unk_D_86002F58_004_000* arg0) {
    arg0->unk_054.unk_00 = -1;
    arg0->unk_054.unk_04 = 0;
}

s16 func_80017798(unk_D_86002F58_004_000* arg0, s16 arg1, s32 arg2) {
    unk_D_86002F58_004_000_054_004* temp_v0 = Util_ConvertAddrToVirtAddr(arg2);
    unk_D_86002F58_004_000_054* ptr = &arg0->unk_054;

    if ((temp_v0 != ptr->unk_04) || (arg1 != ptr->unk_00)) {
        ptr->unk_00 = arg1;
        ptr->unk_04 = temp_v0;
        ptr->unk_08 = temp_v0->unk_04 - 1;
    }

    return ptr->unk_08;
}

void func_80017804(unk_D_86002F58_004_000* arg0, s16 arg1) {
    arg0->unk_054.unk_08 = arg1 - 1;
}

s32 func_8001781C(unk_D_86002F58_004_000* arg0, s16 arg1) {
    return (arg0->unk_054.unk_08 + 1) == arg1;
}

s32 func_8001783C(unk_D_86002F58_004_000* arg0) {
    return (arg0->unk_054.unk_08 + 2) == arg0->unk_054.unk_04->unk_0A;
}

s32 func_80017858(unk_D_86002F58_004_000* arg0) {
    return (arg0->unk_054.unk_08 + 1) == arg0->unk_054.unk_04->unk_0A;
}
