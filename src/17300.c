#include "17300.h"
#include "src/util.h"
#include "src/F420.h"
#include "src/18140.h"

static unk_D_800ABCC0 D_800ABCC0[2];
static s32 D_800ABCF0;

f32 func_80016700(unk_D_800ABCC0* arg0, s32 arg1) {
    f32 ret;
    s32 var_a2;
    unk_D_800ABCC0_008* temp_v0 = &arg0->unk_08[arg1];

    if (temp_v0->unk_00 == 1) {
        ret = temp_v0->unk_04 / 1000.0f;
    } else {
        if (arg0->unk_02 < temp_v0->unk_00) {
            var_a2 = temp_v0->unk_04 + arg0->unk_02;
        } else {
            var_a2 = (temp_v0->unk_04 + temp_v0->unk_00) - 1;
        }

        ret = arg0->unk_0C[var_a2] / 1000.0f;
    }

    return ret;
}

s16 func_800167B4(unk_D_800ABCC0* arg0, s32 arg1) {
    s32 var_a1;
    s16 var_v1;
    unk_D_800ABCC0_008* temp_v0 = &arg0->unk_08[arg1];

    if (temp_v0->unk_01 == 1) {
        var_v1 = temp_v0->unk_06 * 0x10;
    } else {
        if (arg0->unk_02 < temp_v0->unk_01) {
            var_a1 = temp_v0->unk_06 + arg0->unk_02;
        } else {
            var_a1 = (temp_v0->unk_06 + temp_v0->unk_01) - 1;
        }
        var_v1 = func_80010500(arg0->unk_10, var_a1, 0xC) * 0x10;
    }
    return var_v1;
}

f32 func_80016848(unk_D_800ABCC0* arg0, s32 arg1) {
    f32 var_fv1;
    s16 var_a2;
    s32 var_a1;
    unk_D_800ABCC0_008* temp_v0 = &arg0->unk_08[arg1];

    if (temp_v0->unk_02 == 1) {
        if (arg0->unk_01 & 4) {
            var_fv1 = (s16)temp_v0->unk_08;
        } else {
            var_a2 = temp_v0->unk_08 * 0x10;
            var_fv1 = var_a2 >> 4;
        }
    } else {
        if (arg0->unk_02 < temp_v0->unk_02) {
            var_a1 = temp_v0->unk_08 + arg0->unk_02;
        } else {
            var_a1 = (temp_v0->unk_08 + temp_v0->unk_02) - 1;
        }

        if (arg0->unk_01 & 4) {
            var_fv1 = func_80010500(arg0->unk_14, var_a1, 0x10);
        } else {
            var_fv1 = func_80010500(arg0->unk_14, var_a1, 0xC);
        }
    }

    return var_fv1;
}

#ifdef NON_MATCHING
f32 func_80016934(Vec3s* arg0, s16 arg1, s16 arg2) {
    s32 i;
    f32 sp4;
    Vec3s* temp_a1;
    Vec3s* temp_v0;
    Vec3s* var_a1;
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_ft3;
    f32 temp_ft4;
    f32 temp_ft5;
    f32 temp_fv0;
    f32 var_fv1;
    s16 temp_v1_2;
    s32 temp_v1;
    s32 var_v0;

    if (arg0->x >= arg2) {
        var_fv1 = arg0->y;
    } else {
        if (arg2 >= arg0[arg1 - 1].x) {
            var_fv1 = arg0[arg1 - 1].y;
        } else {
            for (i = 0; i < arg1 - 2; i++) {
                if (arg2 < arg0[i + 1].x) {
                    break;
                }
            }

            temp_fv0 = (arg2 - arg0[i].x) / 30.0f;
            temp_fa0 = 30.0f / (arg0[i + 1].x - arg0[i].x);
            temp_ft4 = CB(temp_fv0) * SQ(temp_fa0);
            temp_ft5 = 2.0f * SQ(temp_fv0);
            temp_ft3 = 3.0f * SQ(temp_fv0) * SQ(temp_fa0);

            var_fv1 = (arg0[i + 1].z * (temp_ft4 - (SQ(temp_fv0) * temp_fa0))) +
                      ((arg0[i].y * (((temp_ft5 * temp_fv0 * CB(temp_fa0)) - temp_ft3) + 1.0f)) +
                       (arg0[i + 1].y * ((-2.0f * CB(temp_fv0) * CB(temp_fa0)) + temp_ft3)) +
                       (arg0[i].z * ((temp_ft4 - (temp_ft5 * temp_fa0)) + temp_fv0)));
        }
    }
    return var_fv1;
}
#else
f32 func_80016934(Vec3s* arg0, s16 arg1, s16 arg2);
#pragma GLOBAL_ASM("asm/us/nonmatchings/17300/func_80016934.s")
#endif

#pragma GLOBAL_ASM("asm/us/nonmatchings/17300/func_80016B30.s")

f32 func_80016B30(Vec3s*, s16, s16);

f32 func_80016D20(unk_D_800ABCC0* arg0, s32 arg1) {
    f32 var_fv1;
    unk_D_800ABCC0_008* temp_v0 = &arg0->unk_08[arg1];
    s16* tmp;

    if (temp_v0->unk_00 < 2) {
        var_fv1 = (s16)temp_v0->unk_04 / 100.0f;
    } else {
        tmp = &arg0->unk_0C[temp_v0->unk_04];
        if (temp_v0->unk_03 & 4) {
            var_fv1 = func_80016B30(tmp, temp_v0->unk_00, arg0->unk_02) / 100.0f;
        } else {
            var_fv1 = func_80016934(tmp, temp_v0->unk_00, arg0->unk_02) / 100.0f;
        }
    }
    return var_fv1;
}

s16 func_80016DE0(unk_D_800ABCC0* arg0, s32 arg1) {
    f32 var_fv1;
    s16* temp_a0;
    unk_D_800ABCC0_008* temp_v0 = &arg0->unk_08[arg1];

    if (temp_v0->unk_01 < 2) {
        var_fv1 = (s16)temp_v0->unk_06 / 10.0f;
    } else {
        temp_a0 = &arg0->unk_10[temp_v0->unk_06];
        if (temp_v0->unk_03 & 2) {
            var_fv1 = func_80016B30(temp_a0, temp_v0->unk_01, arg0->unk_02) / 10.0f;
        } else {
            var_fv1 = func_80016934(temp_a0, temp_v0->unk_01, arg0->unk_02) / 10.0f;
        }
    }

    while (var_fv1 < 0.0f) {
        var_fv1 += 360.0f;
    }

    while (var_fv1 >= 360.0f) {
        var_fv1 -= 360.0f;
    }

    return (var_fv1 / 360.0f) * 65536.0f;
}

f32 func_80016F20(unk_D_800ABCC0* arg0, s32 arg1) {
    Vec3s* temp_a0;
    f32 var_fv0;
    f32 var_fv1;
    unk_D_800ABCC0_008* temp_v0 = &arg0->unk_08[arg1];

    if (temp_v0->unk_02 < 2) {
        var_fv1 = (s16)temp_v0->unk_08;
    } else {
        temp_a0 = &arg0->unk_14[temp_v0->unk_08];
        if (temp_v0->unk_03 & 1) {
            var_fv0 = func_80016B30(temp_a0, temp_v0->unk_02, arg0->unk_02);
        } else {
            var_fv0 = func_80016934(temp_a0, temp_v0->unk_02, arg0->unk_02);
        }
        var_fv1 = var_fv0;
    }
    return var_fv1;
}

typedef union arg1_func_80010CA8_test {
    struct {
        s16 unk_00;
        s16 unk_02;
    };
    s32 raw;
} arg1_func_80010CA8_test; // size = 0x4

typedef struct unk_D_86002F58_004_000_040_test {
    /* 0x00 */ s16 unk_00;
    /* 0x04 */ unk_D_86002F58_004_000_040_004* unk_04;
    /* 0x08 */ arg1_func_80010CA8_test unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ char unk10[0x2];
    /* 0x12 */ u16 unk_12;
} unk_D_86002F58_004_000_040_test; // size >= 0x14

#ifdef NON_MATCHING
s32 func_80016FBC(unk_D_86002F58_004_000_040_test* arg0, u16 arg1) {
    arg1_func_80010CA8_test spC;
    arg1_func_80010CA8_test* ptr;
    unk_D_86002F58_004_000_040_004* temp_v0;

    spC = arg0->unk_08;
    temp_v0 = arg0->unk_04;

    if (arg1 != arg0->unk_12) {
        spC.raw += arg0->unk_0C;
        if (arg0->unk_0C >= 0) {
            ptr = &spC;
            if (ptr->unk_00 >= temp_v0->unk_0A) {
                if (temp_v0->unk_00 & 2) {
                    ptr->unk_00 = temp_v0->unk_0A - 1;
                } else {
                    ptr->unk_00 = temp_v0->unk_06;
                }
            }
        } else {
            ptr = &spC;
            if (ptr->unk_00 < temp_v0->unk_06) {
                if (temp_v0->unk_00 & 2) {
                    ptr->unk_00 = temp_v0->unk_06;
                } else {
                    ptr->unk_00 = temp_v0->unk_0A - 1;
                }
            }
        }
    }

    return spC.raw;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/17300/func_80016FBC.s")
#endif

void func_80017080(void) {
    D_800ABCF0 = -1;
}

void func_80017090(unk_D_86002F58_004_000_040* arg0, u16 arg1, s32 arg2) {
    unk_D_86002F58_004_000_040_004* temp_s1;
    unk_D_800ABCC0* temp_s0;

    temp_s1 = arg0->unk_04;

    D_800ABCF0++;
    if (D_800ABCF0 < 2) {
        temp_s0 = &D_800ABCC0[D_800ABCF0];
        if (arg0->unk_04 != NULL) {
            if (arg2 != 0) {
                arg0->unk_08 = func_80016FBC(arg0, arg1);
            }

            arg0->unk_12 = arg1;

            temp_s0->unk_00 = 1;
            temp_s0->unk_01 = arg0->unk_04->unk_00;
            temp_s0->unk_02 = arg0->unk_08 >> 0x10;
            temp_s0->unk_04 = temp_s1;
            temp_s0->unk_08 = Util_ConvertAddrToVirtAddr(temp_s1->unk_0C);
            temp_s0->unk_0C = Util_ConvertAddrToVirtAddr(temp_s1->unk_10);
            temp_s0->unk_10 = Util_ConvertAddrToVirtAddr(temp_s1->unk_14);
            temp_s0->unk_14 = Util_ConvertAddrToVirtAddr(temp_s1->unk_18);

            if (temp_s0->unk_02 < 0) {
                temp_s0->unk_02 = 0;
            }
        } else {
            temp_s0->unk_00 = 0;
        }
    }
}

void func_80017188(void) {
    if (D_800ABCF0 >= 0) {
        D_800ABCF0--;
    }
}

void func_800171A8(Vec3f* arg0, Vec3s* arg1, Vec3f* arg2, s32 arg3) {
    if ((D_800ABCF0 >= 0) && (D_800ABCF0 < 2)) {
        unk_D_800ABCC0* temp_s0 = &D_800ABCC0[D_800ABCF0];

        if ((temp_s0->unk_00 == 1) && (arg3 >= 0) && (arg3 + 2 < temp_s0->unk_04->unk_08)) {
            if (temp_s0->unk_01 & 8) {
                arg0->x = func_80016F20(temp_s0, arg3 + 0);
                arg0->y = func_80016F20(temp_s0, arg3 + 1);
                arg0->z = func_80016F20(temp_s0, arg3 + 2);

                arg1->x = func_80016DE0(temp_s0, arg3 + 0);
                arg1->y = func_80016DE0(temp_s0, arg3 + 1);
                arg1->z = func_80016DE0(temp_s0, arg3 + 2);

                arg2->x = func_80016D20(temp_s0, arg3 + 0);
                arg2->y = func_80016D20(temp_s0, arg3 + 1);
                arg2->z = func_80016D20(temp_s0, arg3 + 2);
            } else {
                arg0->x = func_80016848(temp_s0, arg3 + 0);
                arg0->y = func_80016848(temp_s0, arg3 + 1);
                arg0->z = func_80016848(temp_s0, arg3 + 2);

                arg1->x = func_800167B4(temp_s0, arg3 + 0);
                arg1->y = func_800167B4(temp_s0, arg3 + 1);
                arg1->z = func_800167B4(temp_s0, arg3 + 2);

                arg2->x = func_80016700(temp_s0, arg3 + 0);
                arg2->y = func_80016700(temp_s0, arg3 + 1);
                arg2->z = func_80016700(temp_s0, arg3 + 2);
            }
        }
    }
}

void func_800173CC(unk_D_86002F58_004_000* arg0) {
    arg0->unk_040.unk_00 = -1;
    arg0->unk_040.unk_04 = NULL;
}

s32 func_800173DC(unk_D_86002F58_004_000* arg0, s16 arg1, void* arg2, s32 arg3) {
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

s32 func_80017454(unk_D_86002F58_004_000* arg0, s32 arg1) {
    arg0->unk_040.unk_0C = arg1;
    return arg0->unk_040.unk_08 >> 0x10;
}

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

s32 func_800174E4(unk_D_86002F58_004_000* arg0) {
    return func_80017484(arg0, arg0->unk_040.unk_04->unk_0A - 1);
}

s32 func_80017514(unk_D_86002F58_004_000* arg0) {
    return arg0->unk_040.unk_08 >= ((arg0->unk_040.unk_04->unk_0A - 1) << 0x10);
}
