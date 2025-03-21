#include "18140.h"
#include "src/util.h"

static unk_D_800ABD00 D_800ABD00[2];
static s32 D_800ABD20;

s32 func_80017540(s32 arg0, unk_func_80017540_arg1* arg1, s32 arg2) {
    unk_func_80017540_arg1* temp_v0 = &arg1[arg2];
    s32 ret;

    if (arg0 < temp_v0->unk_00) {
        ret = arg0 + temp_v0->unk_02;
    } else {
        ret = (temp_v0->unk_02 + temp_v0->unk_00) - 1;
    }
    return ret;
}

s16 func_80017578(unk_D_86002F58_004_000_054* arg0, u16 arg1) {
    s16 var_v1;
    unk_D_86002F58_004_000_054_004* temp_v0;

    var_v1 = arg0->unk_08;
    temp_v0 = arg0->unk_04;

    if (arg0->unk_0A != arg1) {
        var_v1 += 1;
        if (var_v1 >= temp_v0->unk_0A) {
            if (temp_v0->unk_00 & 2) {
                var_v1 = temp_v0->unk_0A - 1;
            } else {
                var_v1 = temp_v0->unk_06;
            }
        }
    }
    return var_v1;
}

void func_800175D8(void) {
    D_800ABD20 = -1;
}

void func_800175E8(unk_D_86002F58_004_000_054* arg0, u16 arg1, s32 arg2) {
    unk_D_86002F58_004_000_054_004* sp24;
    unk_D_800ABD00* temp_s0;

    sp24 = arg0->unk_04;
    D_800ABD20++;
    if (D_800ABD20 < 2) {
        temp_s0 = &D_800ABD00[D_800ABD20];
        if (arg0->unk_04 != NULL) {
            if (arg2 != 0) {
                arg0->unk_08 = func_80017578(arg0, arg1);
            }
            arg0->unk_0A = arg1;
            temp_s0->unk_00 = 1;
            temp_s0->unk_02 = arg0->unk_08;
            temp_s0->unk_04 = sp24;
            temp_s0->unk_08 = Util_ConvertAddrToVirtAddr(sp24->unk_0C);
            temp_s0->unk_0C = Util_ConvertAddrToVirtAddr(sp24->unk_10);
            if (temp_s0->unk_02 < 0) {
                temp_s0->unk_02 = 0;
            }
        } else {
            temp_s0->unk_00 = 0;
        }
    }
}

void func_800176BC(void) {
    if (D_800ABD20 >= 0) {
        D_800ABD20--;
    }
}

void func_800176DC(unk_D_86002F34_alt11_018** arg0, unk_D_86002F34_alt11_018* arg1, s32 arg2) {
    unk_D_800ABD00* sp1C;

    if ((D_800ABD20 >= 0) && (D_800ABD20 < 2)) {
        sp1C = &D_800ABD00[D_800ABD20];
        if ((sp1C->unk_00 == 1) && (arg2 >= 0) && (arg2 < sp1C->unk_04->unk_08)) {
            *arg0 = &arg1[((u8*)sp1C->unk_0C)[func_80017540(sp1C->unk_02, sp1C->unk_08, arg2)]];
        }
    }
}

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
