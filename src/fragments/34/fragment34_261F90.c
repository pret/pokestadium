#include "fragment34.h"
#include "include/libc/math.h"
#include "src/F420.h"
#include "src/math_util.h"

MtxF* D_8140E620;
s32 D_8140E624;
s32 D_8140E624;
unk_D_8140E634 D_8140E628;
u32 D_8140E6B8;
s32 D_8140E6BC;
s32 D_8140E6C0;
s32 D_8140E6C4;
s32 D_8140E6C8;
s32 D_8140E6CC;
u32 D_8140E6D0;
s32 D_8140E6D4;
u32 D_8140E6D8;
u32 D_8140E6DC;
u32 D_8140E6E0;
u32 D_8140E6E4;
u32 D_8140E6E8;
u32 D_8140E6EC;
u32 D_8140E6F0;
s32 D_8140E6F4;
s32 D_8140E6F8;
s32 D_8140E6FC;
s32 D_8140E700;
s32 D_8140E704;
s32 D_8140E708;
s32 D_8140E70C;
s32 D_8140E710;
s32 pad_D_8140E714[2];
unk_D_8140E720* D_8140E720;
s32 pad_D_8140E724;
unk_D_8140E728* D_8140E728;
s32 D_8140E72C;
s32 D_8140E734;

void func_81400020(s32* arg0, s32 arg1) {
    *arg0 |= arg1;
}

void func_81400030(s32* arg0, s32 arg1) {
    *arg0 &= ~arg1;
}

void func_81400044(s32* arg0, s32 arg1) {
    *arg0 ^= arg1;
}

s32 func_81400054(s32* arg0, s32 arg1) {
    s32 var_v1 = 0;

    if (*arg0 & arg1) {
        var_v1 = 1;
    }
    return var_v1;
}

s32 func_81400074(s32* arg0, s32 arg1) {
    s32 var_v1 = 0;

    if (!(*arg0 & arg1)) {
        var_v1 = 1;
    }
    return var_v1;
}

s32 func_81400094(f32* arg0, f32 arg1, f32 arg2) {
    s32 var_v1 = 0;

    if (*arg0 < arg1) {
        *arg0 += arg2;
        if (arg1 <= *arg0) {
            *arg0 = arg1;
            var_v1 = 1;
        }
    }
    return var_v1;
}

s32 func_814000E0(f32* arg0, f32 arg1, f32 arg2) {
    s32 var_v1 = 0;

    if (arg1 < *arg0) {
        *arg0 -= arg2;
        if (*arg0 <= arg1) {
            *arg0 = arg1;
            var_v1 = 1;
        }
    }
    return var_v1;
}

s32 func_8140012C(s32* arg0, s32 arg1, s32 arg2) {
    s32 var_v1 = 0;

    if (*arg0 < arg1) {
        *arg0 += arg2;
        if (*arg0 >= arg1) {
            *arg0 = arg1;
            var_v1 = 1;
        }
    }
    return var_v1;
}

s32 func_8140015C(s32* arg0, s32 arg1, s32 arg2) {
    s32 var_v1 = 0;

    if (arg1 < *arg0) {
        *arg0 -= arg2;
        if (arg1 >= *arg0) {
            *arg0 = arg1;
            var_v1 = 1;
        }
    }
    return var_v1;
}

s32 func_8140018C(s16* arg0, s16 arg1, s16 arg2) {
    s32 var_v1 = 0;

    if (*arg0 < arg1) {
        *arg0 += arg2;
        if (*arg0 >= arg1) {
            *arg0 = arg1;
            var_v1 = 1;
        }
    }
    return var_v1;
}

s32 func_814001DC(u16* arg0, u16 arg1, u16 arg2) {
    s32 var_v1 = 0;

    if (*arg0 < arg1) {
        *arg0 += arg2;
        if (*arg0 >= arg1) {
            *arg0 = arg1;
            var_v1 = 1;
        }
    }
    return var_v1;
}

s32 func_81400220(s16* arg0, s16 arg1, s16 arg2) {
    s32 var_v1 = 0;

    if (arg1 < *arg0) {
        *arg0 -= arg2;
        if (arg1 >= *arg0) {
            *arg0 = arg1;
            var_v1 = 1;
        }
    }
    return var_v1;
}

s32 func_81400270(u16* arg0, s32 arg1, s32 arg2) {
    s32 var_v1 = 0;
    s32 temp_v0 = *arg0;

    if (arg1 < temp_v0) {
        temp_v0 -= arg2;
        if (arg1 >= temp_v0) {
            temp_v0 = arg1;
            var_v1 = 1;
        }
        *arg0 = temp_v0;
    }
    return var_v1;
}

s32 func_814002A4(f32* arg0, f32 arg1, f32* arg2) {
    s32 var_v1 = 0;

    if (*arg0 < arg1) {
        *arg0 += *arg2;
        if (arg1 <= *arg0) {
            *arg0 = arg1;
            var_v1 = 1;
        }
    }
    return var_v1;
}

s32 func_814002F0(f32* arg0, f32 arg1, f32* arg2) {
    s32 var_v1 = 0;

    if (arg1 < *arg0) {
        *arg0 -= *arg2;
        if (*arg0 <= arg1) {
            *arg0 = arg1;
            var_v1 = 1;
        }
    }
    return var_v1;
}

s32 func_8140033C(s32* arg0, s32 arg1, s32* arg2) {
    s32 var_v1 = 0;

    if (*arg0 < arg1) {
        *arg0 += *arg2;
        if (*arg0 >= arg1) {
            *arg0 = arg1;
            var_v1 = 1;
        }
    }
    return var_v1;
}

s32 func_81400374(s32* arg0, s32 arg1, s32* arg2) {
    s32 var_v1 = 0;

    if (arg1 < *arg0) {
        *arg0 -= *arg2;
        if (arg1 >= *arg0) {
            *arg0 = arg1;
            var_v1 = 1;
        }
    }
    return var_v1;
}

s32 func_814003AC(s16* arg0, s16 arg1, s16* arg2) {
    s32 var_v1 = 0;

    if (*arg0 < arg1) {
        *arg0 += *arg2;
        if (*arg0 >= arg1) {
            *arg0 = arg1;
            var_v1 = 1;
        }
    }
    return var_v1;
}

s32 func_814003F4(s16* arg0, s16 arg1, s16* arg2) {
    s32 var_v1 = 0;

    if (arg1 < *arg0) {
        *arg0 -= *arg2;
        if (arg1 >= *arg0) {
            *arg0 = arg1;
            var_v1 = 1;
        }
    }
    return var_v1;
}

s32 func_8140043C(s8* arg0, s8 arg1, s8 arg2) {
    s32 var_v1 = 0;
    s32 var_a3 = *arg0;

    if (var_a3 < arg1) {
        if (arg2 >= 0) {
            var_a3 += arg2;
        } else {
            var_a3 -= arg2;
        }

        if (var_a3 >= arg1) {
            var_a3 = arg1;
            var_v1 = 1;
        }
    } else if (arg1 < var_a3) {
        if (arg2 >= 0) {
            var_a3 -= arg2;
        } else {
            var_a3 += arg2;
        }

        if (arg1 >= var_a3) {
            var_a3 = arg1;
            var_v1 = 1;
        }
    } else {
        var_v1 = 1;
    }

    *arg0 = var_a3;
    return var_v1;
}

s32 func_814004D8(u8* arg0, u8 arg1, u8 arg2) {
    s32 var_v1 = 0;
    s32 var_a3 = *arg0;

    if (var_a3 < arg1) {
        var_a3 += arg2;
        if (var_a3 >= arg1) {
            var_a3 = arg1;
            var_v1 = 1;
        }
    } else if (arg1 < var_a3) {
        var_a3 -= arg2;
        if (arg1 >= var_a3) {
            var_a3 = arg1;
            var_v1 = 1;
        }
    } else {
        var_v1 = 1;
    }

    *arg0 = var_a3;
    return var_v1;
}

s32 func_81400550(s16* arg0, s16 arg1, s16 arg2) {
    s32 var_v1 = 0;
    s32 var_a3 = *arg0;

    if (var_a3 < arg1) {
        if (arg2 >= 0) {
            var_a3 += arg2;
        } else {
            var_a3 -= arg2;
        }

        if (var_a3 >= arg1) {
            var_a3 = arg1;
            var_v1 = 1;
        }
    } else if (arg1 < var_a3) {
        if (arg2 >= 0) {
            var_a3 -= arg2;
        } else {
            var_a3 += arg2;
        }

        if (arg1 >= var_a3) {
            var_a3 = arg1;
            var_v1 = 1;
        }
    } else {
        var_v1 = 1;
    }

    *arg0 = var_a3;
    return var_v1;
}

s32 func_814005EC(s16* arg0, s16 arg1, s16 arg2) {
    s32 a0 = *(u16*)arg0;
    s32 var_v1 = 0;
    s32 var_a1 = (u16)arg1;

    if ((u16)arg1 == a0) {
        var_a1 = (u16)arg1;
        var_v1 = 1;
    } else {
        var_a1 = (u16)arg1 - a0;
        if (var_a1 < -0x8000) {
            var_a1 = arg2 + a0;
            if (((u16)arg1 - var_a1) <= -65536) {
                var_a1 = (u16)arg1;
                var_v1 = 1;
            }
        } else if (var_a1 < 0) {
            var_a1 = a0 - arg2;
            if (((u16)arg1 - var_a1) >= 0) {
                var_a1 = (u16)arg1;
                var_v1 = 1;
            }
        } else if (var_a1 < 0x8000) {
            var_a1 = arg2 + a0;
            if (((u16)arg1 - var_a1) <= 0) {
                var_a1 = (u16)arg1;
                var_v1 = 1;
            }
        } else {
            var_a1 = a0 - arg2;
            if (((u16)arg1 - var_a1) >= 0x10000) {
                var_a1 = (u16)arg1;
                var_v1 = 1;
            }
        }
    }

    *arg0 = var_a1;
    return var_v1;
}

s32 func_814006CC(s32* arg0, s32 arg1, s32 arg2) {
    s32 temp_v0 = *arg0;
    s32 var_v1 = 0;

    if (temp_v0 < arg1) {
        if (arg2 >= 0) {
            *arg0 = temp_v0 + arg2;
        } else {
            *arg0 = temp_v0 - arg2;
        }

        if (*arg0 >= arg1) {
            *arg0 = arg1;
            var_v1 = 1;
        }
    } else if (arg1 < temp_v0) {
        if (arg2 >= 0) {
            *arg0 = temp_v0 - arg2;
        } else {
            *arg0 = temp_v0 + arg2;
        }

        if (arg1 >= *arg0) {
            *arg0 = arg1;
            var_v1 = 1;
        }
    } else {
        var_v1 = 1;
    }

    return var_v1;
}

s32 func_81400760(f32* arg0, f32 arg1, f32 arg2) {
    s32 var_v1 = 0;

    if (*arg0 < arg1) {
        if (arg2 >= 0.0f) {
            *arg0 += arg2;
        } else {
            *arg0 -= arg2;
        }

        if (arg1 <= *arg0) {
            *arg0 = arg1;
            var_v1 = 1;
        }
    } else if (arg1 < *arg0) {
        if (arg2 >= 0.0f) {
            *arg0 -= arg2;
        } else {
            *arg0 += arg2;
        }

        if (*arg0 <= arg1) {
            *arg0 = arg1;
            var_v1 = 1;
        }
    } else {
        var_v1 = 1;
    }

    return var_v1;
}

void func_8140082C(f32* arg0, f32 arg1, f32 arg2, f32* arg3) {
    *arg0 += *arg3;

    if (*arg3 >= 0.0f) {
        if (arg2 <= *arg0) {
            *arg0 = arg2;
            *arg3 = -*arg3;
        }
    } else if (*arg0 <= arg1) {
        *arg0 = arg1;
        *arg3 = -*arg3;
    }
}

void func_814008B0(s16* arg0, s16 arg1, s16 arg2, s16* arg3) {
    *arg0 += *arg3;
    if (*arg3 >= 0) {
        if (*arg0 >= arg2) {
            *arg0 = arg2;
            *arg3 = -*arg3;
        }
    } else if (arg1 >= *arg0) {
        *arg0 = arg1;
        *arg3 = -*arg3;
    }
}

void func_81400930(Vec3f* arg0, Vec3f* arg1) {
    arg0->x = arg1->x;
    arg0->y = arg1->y;
    arg0->z = arg1->z;
}

void func_8140094C(Vec3s* arg0, Vec3s* arg1) {
    arg0->x = arg1->x;
    arg0->y = arg1->y;
    arg0->z = arg1->z;
}

void func_81400968(Vec3f* arg0, Vec3f* arg1) {
    arg0->x += arg1->x;
    arg0->y += arg1->y;
    arg0->z += arg1->z;
}

void func_8140099C(Vec3s* arg0, Vec3s* arg1) {
    arg0->x += arg1->x;
    arg0->y += arg1->y;
    arg0->z += arg1->z;
}

f32 func_814009D0(Vec3f arg0, Vec3f arg1) {
    return (arg0.x * arg1.x) + (arg0.y * arg1.y) + (arg0.z * arg1.z);
}

s32 func_81400A10(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    s32 var_v1 = 0;

    if ((SQ(arg2 - arg0) + SQ(arg3 - arg1)) <= SQ(arg4)) {
        var_v1 = 1;
    }
    return var_v1;
}

void func_81400A60(void) {
    D_8140E710++;
}

u32 func_81400A78(s32 arg0) {
    u32 temp_a0 = guRandom() + D_8140E710;
    u32 var_v1;

    if (arg0 == 0) {
        var_v1 = 0;
    } else {
        var_v1 = (temp_a0 / 10) % arg0;
    }
    return var_v1;
}

s32 func_81400ADC(s32 arg0, s32 arg1) {
    return func_81400A78(arg0) + arg1;
}

s32 func_81400B00(s32 arg0) {
    return func_81400A78(arg0 * 2) - arg0;
}

s32 func_81400B28(s32 arg0, s32 arg1) {
    return func_81400B00(arg0) + arg1;
}

s32 func_81400B4C(s32 arg0, s32 arg1) {
    s32 temp_v0 = func_81400B00(arg0);

    if (temp_v0 >= 0) {
        temp_v0 += arg1;
    } else {
        temp_v0 -= arg1;
    }
    return temp_v0;
}

void func_81400B84(UNUSED s32 arg0) {
}

void func_81400B8C(Vec3f arg0) {
    MathUtil_Atan2s(arg0.y, arg0.z);
}

void func_81400BBC(Vec3f arg0) {
    MathUtil_Atan2s(arg0.z, arg0.x);
}

void func_81400BEC(Vec3f arg0) {
    MathUtil_Atan2s(arg0.x, arg0.y);
}

void func_81400C1C(Vec3s* arg0, Vec3f arg1) {
    arg0->x = MathUtil_Atan2s(arg1.y, arg1.z);
    arg0->y = MathUtil_Atan2s(arg1.z, arg1.x);
    arg0->z = MathUtil_Atan2s(arg1.x, arg1.y);
}

f32 func_81400C80(f32 arg0, f32 arg1, s16 arg2) {
    return (COSS(arg2) * arg0) - (SINS(arg2) * arg1);
}

f32 func_81400CC0(f32 arg0, f32 arg1, s16 arg2) {
    return (SINS(arg2) * arg0) + (COSS(arg2) * arg1);
}

Vec3f* func_81400D00(Vec3f* arg0, Vec3f arg1, Vec3s arg2) {
    f32 temp_fv0 = SINS(arg2.y);
    f32 temp_fv1 = COSS(arg2.y);

    arg0->x = (arg1.x * temp_fv1) + (arg1.z * temp_fv0);
    arg0->y = arg1.y;
    arg0->z = (-arg1.x * temp_fv0) + (arg1.z * temp_fv1);

    return arg0;
}

Vec3f* func_81400D6C(Vec3f* arg0, f32 arg1, s16 arg2) {
    f32 temp_fv0 = SINS(arg2);
    f32 temp_fv1 = COSS(arg2);

    arg0->x = arg1 * temp_fv0;
    arg0->y = 0.0f;
    arg0->z = arg1 * temp_fv1;

    return arg0;
}

Vec3f* func_81400DC0(Vec3f* arg0, Vec3f arg1, Vec3s arg4) {
    f32 x = arg1.x;
    f32 y = arg1.y;
    f32 z = arg1.z;
    f32 temp_fv0 = SINS(arg4.x);
    f32 temp_fv1 = COSS(arg4.x);
    f32 temp_ft4 = SINS(arg4.y);
    f32 temp_ft5 = COSS(arg4.y);

    arg0->x = (x * temp_ft5) + (z * temp_ft4);
    arg0->y = ((x * temp_fv0 * temp_ft4) + (y * temp_fv1)) - (z * temp_fv0 * temp_ft5);
    arg0->z = (-x * temp_fv1 * temp_ft4) + (y * temp_fv0) + (z * temp_fv1 * temp_ft5);

    return arg0;
}

f32 func_81400E8C(Vec3f arg0, Vec3f arg1) {
    return sqrtf(SQ(arg1.x - arg0.x) + SQ(arg1.y - arg0.y) + SQ(arg1.z - arg0.z));
}

f32 func_81400EF0(Vec3f arg0, Vec3f arg1) {
    return sqrtf(SQ(arg1.x - arg0.x) + SQ(arg1.z - arg0.z));
}

Vec3f* func_81400F44(Vec3f* arg0, Vec3f arg1, Vec3f arg2) {
    arg0->x = arg2.x - arg1.x;
    arg0->y = arg2.y - arg1.y;
    arg0->z = arg2.z - arg1.z;

    func_8000EAF4(arg0);

    return arg0;
}

s32 func_81400FA4(Vec3f arg0, Vec3f arg1, f32 arg2) {
    return func_81400E8C(arg0, arg1) / arg2;
}

s32 func_81401020(Vec3f* arg0, Vec3f arg1, Vec3f arg2, f32 arg3) {
    f32 temp_fv1;

    arg0->x = arg2.x - arg1.x;
    arg0->y = arg2.y - arg1.y;
    arg0->z = arg2.z - arg1.z;

    temp_fv1 = arg3 / sqrtf(SQ(arg0->x) + SQ(arg0->y) + SQ(arg0->z));

    arg0->x = arg0->x * temp_fv1;
    arg0->y = arg0->y * temp_fv1;
    arg0->z = arg0->z * temp_fv1;

    return 1.0f / temp_fv1;
}

Vec3f* func_814010D8(Vec3f* arg0, f32 arg1) {
    Vec3f sp2C;
    Vec3s sp24;

    sp2C.x = 0.0f;
    sp2C.y = 0.0f;
    sp2C.z = arg1;

    sp24.x = func_81400A78(0x10000);
    sp24.y = func_81400A78(0x10000);

    func_81400DC0(arg0, sp2C, sp24);
    return arg0;
}

Vec3f* func_81401168(Vec3f* arg0, f32 arg1) {
    arg0->x *= arg1;
    arg0->y *= arg1;
    arg0->z *= arg1;

    return arg0;
}

s16 func_8140119C(Vec3f arg0, Vec3f arg1) {
    return MathUtil_Atan2s(arg1.y - arg0.y, arg1.z - arg0.z);
}

s16 func_814011E0(Vec3f arg0, Vec3f arg1) {
    return MathUtil_Atan2s(arg1.z - arg0.z, arg1.x - arg0.x);
}

s16 func_81401224(Vec3f arg0, Vec3f arg1) {
    return MathUtil_Atan2s(arg1.x - arg0.x, arg1.y - arg0.y);
}

s16 func_81401268(s16 arg0, s16 arg1) {
    s16 temp_v0 = arg1 - arg0;

    if ((arg0 >> 8) != (arg1 >> 8)) {
        if (temp_v0 < 0x400) {
            arg0 += 0x80;
        } else if (temp_v0 < 0x800) {
            arg0 += 0x200;
        } else if (temp_v0 < 0x4000) {
            arg0 += 0x400;
        } else if (temp_v0 < 0x8000) {
            arg0 += 0x700;
        } else if (temp_v0 < 0xC000) {
            arg0 -= 0x700;
        } else if (temp_v0 < 0xF800) {
            arg0 -= 0x400;
        } else if (temp_v0 < 0xFC00) {
            arg0 -= 0x200;
        } else {
            arg0 -= 0x80;
        }
    } else {
        arg0 = arg1;
    }

    return arg0;
}

void func_8140138C(void) {
}

void func_81401394(MtxF* arg0) {
    if (D_8140E624 < 0x16C) {
        func_80010090((MtxF*)((u32)D_8140E620 + (D_8140E624 * sizeof(MtxF))), arg0);

        gSPMatrix(gDisplayListHead++, ((u32)D_8140E620 + (D_8140E624 * sizeof(MtxF))) & 0x1FFFFFFF,
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        D_8140E624++;
    }
}

void func_81401430(MtxF* arg0, s16 arg1, s16 arg2, s16 arg3, f32 arg4) {
    f32 temp_fv0 = SINS(arg3) * arg4;
    f32 temp_fv1 = COSS(arg3) * arg4;

    arg0->mf[0][0] = temp_fv1;
    arg0->mf[0][1] = -temp_fv0;
    arg0->mf[0][2] = 0.0f;
    arg0->mf[0][3] = 0.0f;

    arg0->mf[1][0] = temp_fv0;
    arg0->mf[1][1] = temp_fv1;
    arg0->mf[1][2] = 0.0f;
    arg0->mf[1][3] = 0.0f;

    arg0->mf[2][0] = 0.0f;
    arg0->mf[2][1] = 0.0f;
    arg0->mf[2][2] = 1.0f;
    arg0->mf[2][3] = 0.0f;

    arg0->mf[3][0] = arg1;
    arg0->mf[3][1] = arg2;
    arg0->mf[3][2] = 0.0f;
    arg0->mf[3][3] = 1.0f;
}

void func_814014E8(MtxF* arg0, s16 arg1, s16 arg2, s16 arg3, f32 arg4) {
    f32 temp_fv0 = SINS(arg3);
    f32 temp_fv1 = COSS(arg3);

    arg0->mf[0][0] = temp_fv1;
    arg0->mf[0][1] = -temp_fv0;
    arg0->mf[0][2] = 0.0f;
    arg0->mf[0][3] = 0.0f;

    arg0->mf[1][0] = temp_fv0 * arg4;
    arg0->mf[1][1] = temp_fv1 * arg4;
    arg0->mf[1][2] = 0.0f;
    arg0->mf[1][3] = 0.0f;

    arg0->mf[2][0] = 0.0f;
    arg0->mf[2][1] = 0.0f;
    arg0->mf[2][2] = 1.0f;
    arg0->mf[2][3] = 0.0f;

    arg0->mf[3][0] = arg1;
    arg0->mf[3][1] = arg2;
    arg0->mf[3][2] = 0.0f;
    arg0->mf[3][3] = 1.0f;
}

void func_814015A0(s16 arg0, s16 arg1, s16 arg2, f32 arg3) {
    MtxF sp20;

    func_81401430(&sp20, arg0, arg1, arg2 + 0x8000, arg3);
    func_81401394(&sp20);
}

void func_814015F8(s16 arg0, s16 arg1, s16 arg2, f32 arg3) {
    MtxF sp20;

    func_814014E8(&sp20, arg0, arg1, arg2 + 0x8000, arg3);
    func_81401394(&sp20);
}

void func_81401650(MtxF* arg0, Vec3f arg1, Vec3s arg2, f32 arg3) {
    f32 temp_fa1;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_ft4;
    f32 temp_fv0;
    f32 temp_fv1;

    temp_ft4 = SINS(arg2.x);
    temp_fv0 = COSS(arg2.x);

    temp_fv1 = SINS(arg2.y);
    temp_fa1 = COSS(arg2.y);

    temp_fs0 = SINS(arg2.z);
    temp_fs1 = COSS(arg2.z);

    arg0->mf[0][0] = ((temp_fa1 * temp_fs1) + (temp_ft4 * temp_fv1 * temp_fs0)) * arg3;
    arg0->mf[0][1] = temp_fv0 * temp_fs0 * arg3;
    arg0->mf[0][2] = ((-temp_fv1 * temp_fs1) + (temp_ft4 * temp_fa1 * temp_fs0)) * arg3;
    arg0->mf[0][3] = 0.0f;

    arg0->mf[1][0] = ((-temp_fa1 * temp_fs0) + (temp_ft4 * temp_fv1 * temp_fs1)) * arg3;
    arg0->mf[1][1] = temp_fv0 * temp_fs1 * arg3;
    arg0->mf[1][2] = ((temp_fv1 * temp_fs0) + (temp_ft4 * temp_fa1 * temp_fs1)) * arg3;
    arg0->mf[1][3] = 0.0f;

    arg0->mf[2][0] = temp_fv0 * temp_fv1 * arg3;
    arg0->mf[2][1] = -temp_ft4 * arg3;
    arg0->mf[2][2] = temp_fv0 * temp_fa1 * arg3;
    arg0->mf[2][3] = 0.0f;

    arg0->mf[3][0] = arg1.x;
    arg0->mf[3][1] = arg1.y;
    arg0->mf[3][2] = arg1.z;
    arg0->mf[3][3] = 1.0f;
}

void func_814017E0(MtxF* arg0, Vec3f arg1, Vec3s arg2, f32 arg3) {
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_fs0;
    f32 temp_ft5;
    f32 temp_fv0;
    f32 temp_fv1;

    temp_fa1 = SINS(arg2.x);
    temp_fv0 = COSS(arg2.x);

    temp_fv1 = SINS(arg2.y);
    temp_fa0 = COSS(arg2.y);

    temp_ft5 = SINS(arg2.z);
    temp_fs0 = COSS(arg2.z);

    arg0->mf[0][0] = (temp_fa0 * temp_fs0) + (temp_fa1 * temp_fv1 * temp_ft5);
    arg0->mf[0][1] = temp_fv0 * temp_ft5;
    arg0->mf[0][2] = (-temp_fv1 * temp_fs0) + (temp_fa1 * temp_fa0 * temp_ft5);
    arg0->mf[0][3] = 0.0f;

    arg0->mf[1][0] = ((-temp_fa0 * temp_ft5) + (temp_fa1 * temp_fv1 * temp_fs0)) * arg3;
    arg0->mf[1][1] = temp_fv0 * temp_fs0 * arg3;
    arg0->mf[1][2] = ((temp_fv1 * temp_ft5) + (temp_fa1 * temp_fa0 * temp_fs0)) * arg3;
    arg0->mf[1][3] = 0.0f;

    arg0->mf[2][0] = temp_fv0 * temp_fv1;
    arg0->mf[2][1] = -temp_fa1;
    arg0->mf[2][2] = temp_fv0 * temp_fa0;
    arg0->mf[2][3] = 0.0f;

    arg0->mf[3][0] = arg1.x;
    arg0->mf[3][1] = arg1.y;
    arg0->mf[3][2] = arg1.z;
    arg0->mf[3][3] = 1.0f;
}

void func_81401940(MtxF* arg0, Vec3f arg1, Vec3s arg2, f32 arg3, f32 arg4) {
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_fs0;
    f32 temp_ft5;
    f32 temp_fv0;
    f32 temp_fv1;

    temp_fa1 = SINS(arg2.x);
    temp_fv0 = COSS(arg2.x);

    temp_fv1 = SINS(arg2.y);
    temp_fa0 = COSS(arg2.y);

    temp_ft5 = SINS(arg2.z);
    temp_fs0 = COSS(arg2.z);

    arg0->mf[0][0] = ((temp_fa0 * temp_fs0) + (temp_fa1 * temp_fv1 * temp_ft5)) * arg3;
    arg0->mf[0][1] = temp_fv0 * temp_ft5 * arg3;
    arg0->mf[0][2] = ((-temp_fv1 * temp_fs0) + (temp_fa1 * temp_fa0 * temp_ft5)) * arg3;
    arg0->mf[0][3] = 0.0f;

    arg0->mf[1][0] = ((-temp_fa0 * temp_ft5) + (temp_fa1 * temp_fv1 * temp_fs0)) * arg4;
    arg0->mf[1][1] = temp_fv0 * temp_fs0 * arg4;
    arg0->mf[1][2] = ((temp_fv1 * temp_ft5) + (temp_fa1 * temp_fa0 * temp_fs0)) * arg4;
    arg0->mf[1][3] = 0.0f;

    arg0->mf[2][0] = temp_fv0 * temp_fv1;
    arg0->mf[2][1] = -temp_fa1;
    arg0->mf[2][2] = temp_fv0 * temp_fa0;
    arg0->mf[2][3] = 0.0f;

    arg0->mf[3][0] = arg1.x;
    arg0->mf[3][1] = arg1.y;
    arg0->mf[3][2] = arg1.z;
    arg0->mf[3][3] = 1.0f;
}

void func_81401ABC(MtxF* arg0, MtxF* arg1, Vec3f arg2, f32 arg3) {
    arg0->mf[0][0] = arg1->mf[0][0] * arg3;
    arg0->mf[0][1] = arg1->mf[1][0] * arg3;
    arg0->mf[0][2] = arg1->mf[2][0] * arg3;
    arg0->mf[0][3] = 0.0f;

    arg0->mf[1][0] = arg1->mf[0][1] * arg3;
    arg0->mf[1][1] = arg1->mf[1][1] * arg3;
    arg0->mf[1][2] = arg1->mf[2][1] * arg3;
    arg0->mf[1][3] = 0.0f;

    arg0->mf[2][0] = arg1->mf[0][2] * arg3;
    arg0->mf[2][1] = arg1->mf[1][2] * arg3;
    arg0->mf[2][2] = arg1->mf[2][2] * arg3;
    arg0->mf[2][3] = 0.0f;

    arg0->mf[3][0] = arg2.x;
    arg0->mf[3][1] = arg2.y;
    arg0->mf[3][2] = arg2.z;
    arg0->mf[3][3] = 1.0f;
}

void func_81401B6C(MtxF* arg0, MtxF* arg1, Vec3f arg2, f32 arg3) {
    arg0->mf[0][0] = arg1->mf[0][0];
    arg0->mf[0][1] = arg1->mf[1][0];
    arg0->mf[0][2] = arg1->mf[2][0];
    arg0->mf[0][3] = 0.0f;

    arg0->mf[1][0] = arg1->mf[0][1] * arg3;
    arg0->mf[1][1] = arg1->mf[1][1] * arg3;
    arg0->mf[1][2] = arg1->mf[2][1] * arg3;
    arg0->mf[1][3] = 0.0f;

    arg0->mf[2][0] = arg1->mf[0][2];
    arg0->mf[2][1] = arg1->mf[1][2];
    arg0->mf[2][2] = arg1->mf[2][2];
    arg0->mf[2][3] = 0.0f;

    arg0->mf[3][0] = arg2.x;
    arg0->mf[3][1] = arg2.y;
    arg0->mf[3][2] = arg2.z;
    arg0->mf[3][3] = 1.0f;
}

void func_81401C04(MtxF* arg0, MtxF* arg1, Vec3f arg2, f32 arg3, s16 arg4) {
    f32 temp_fv0 = SINS(arg4);
    f32 temp_fv1 = COSS(arg4);

    arg0->mf[0][0] = ((arg1->mf[0][0] * temp_fv1) + (arg1->mf[0][1] * temp_fv0)) * arg3;
    arg0->mf[0][1] = ((arg1->mf[1][0] * temp_fv1) + (arg1->mf[1][1] * temp_fv0)) * arg3;
    arg0->mf[0][2] = ((arg1->mf[2][0] * temp_fv1) + (arg1->mf[2][1] * temp_fv0)) * arg3;
    arg0->mf[0][3] = 0.0f;

    arg0->mf[1][0] = ((arg1->mf[0][0] * -temp_fv0) + (arg1->mf[0][1] * temp_fv1)) * arg3;
    arg0->mf[1][1] = ((arg1->mf[1][0] * -temp_fv0) + (arg1->mf[1][1] * temp_fv1)) * arg3;
    arg0->mf[1][2] = ((arg1->mf[2][0] * -temp_fv0) + (arg1->mf[2][1] * temp_fv1)) * arg3;
    arg0->mf[1][3] = 0.0f;

    arg0->mf[2][0] = arg1->mf[0][2] * arg3;
    arg0->mf[2][1] = arg1->mf[1][2] * arg3;
    arg0->mf[2][2] = arg1->mf[2][2] * arg3;
    arg0->mf[2][3] = 0.0f;

    arg0->mf[3][0] = arg2.x;
    arg0->mf[3][1] = arg2.y;
    arg0->mf[3][2] = arg2.z;
    arg0->mf[3][3] = 1.0f;
}

void func_81401D50(MtxF* arg0, MtxF* arg1, Vec3f arg2, f32 arg3, s16 arg4) {
    f32 temp_fv0 = SINS(arg4);
    f32 temp_fv1 = COSS(arg4);

    arg0->mf[0][0] = (arg1->mf[0][0] * temp_fv1) + (arg1->mf[0][1] * temp_fv0);
    arg0->mf[0][1] = (arg1->mf[1][0] * temp_fv1) + (arg1->mf[1][1] * temp_fv0);
    arg0->mf[0][2] = (arg1->mf[2][0] * temp_fv1) + (arg1->mf[2][1] * temp_fv0);
    arg0->mf[0][3] = 0.0f;

    arg0->mf[1][0] = ((arg1->mf[0][0] * -temp_fv0) + (arg1->mf[0][1] * temp_fv1)) * arg3;
    arg0->mf[1][1] = ((arg1->mf[1][0] * -temp_fv0) + (arg1->mf[1][1] * temp_fv1)) * arg3;
    arg0->mf[1][2] = ((arg1->mf[2][0] * -temp_fv0) + (arg1->mf[2][1] * temp_fv1)) * arg3;
    arg0->mf[1][3] = 0.0f;

    arg0->mf[2][0] = arg1->mf[0][2];
    arg0->mf[2][1] = arg1->mf[1][2];
    arg0->mf[2][2] = arg1->mf[2][2];
    arg0->mf[2][3] = 0.0f;

    arg0->mf[3][0] = arg2.x;
    arg0->mf[3][1] = arg2.y;
    arg0->mf[3][2] = arg2.z;
    arg0->mf[3][3] = 1.0f;
}

void func_81401E84(MtxF* arg0, Vec3f arg1, Vec3f arg2, s16 arg3, f32 arg4) {
    Vec3f sp3C;
    Vec3f sp30;
    Vec3f sp24;

    func_8000E88C(&sp3C, SINS(arg3), 0.0f, COSS(arg3));
    func_8000EAF4(&arg1);
    func_8000EA84(&sp30, &arg1, &sp3C);
    func_8000EAF4(&sp30);
    func_8000EA84(&sp24, &sp30, &arg1);
    func_8000EAF4(&sp24);

    arg0->mf[0][0] = sp30.x * arg4;
    arg0->mf[0][1] = sp30.y * arg4;
    arg0->mf[0][2] = sp30.z * arg4;
    arg0->mf[3][0] = arg2.x;

    arg0->mf[1][0] = arg1.x * arg4;
    arg0->mf[1][1] = arg1.y * arg4;
    arg0->mf[1][2] = arg1.z * arg4;
    arg0->mf[3][1] = arg2.y;

    arg0->mf[2][0] = sp24.x * arg4;
    arg0->mf[2][1] = sp24.y * arg4;
    arg0->mf[2][2] = sp24.z * arg4;
    arg0->mf[3][2] = arg2.z;

    arg0->mf[0][3] = 0.0f;
    arg0->mf[1][3] = 0.0f;
    arg0->mf[2][3] = 0.0f;
    arg0->mf[3][3] = 1.0f;
}

void func_81401FC0(Vec3f arg0, Vec3s arg1, f32 arg2) {
    MtxF sp28;

    func_81401650(&sp28, arg0, arg1, arg2);
    func_81401394(&sp28);
}

void func_8140203C(Vec3f arg0, Vec3s arg1, f32 arg2) {
    MtxF sp28;

    func_814017E0(&sp28, arg0, arg1, arg2);
    func_81401394(&sp28);
}

void func_814020B8(Vec3f arg0, Vec3s arg1, f32 arg2, f32 arg3) {
    MtxF sp28;

    func_81401940(&sp28, arg0, arg1, arg2, arg3);
    func_81401394(&sp28);
}

void func_8140213C(arg1_func_8140213C* arg0, Vec3f arg1, f32 arg4) {
    MtxF sp20;

    func_81401ABC(&sp20, &arg0->unk_64, arg1, arg4);
    func_81401394(&sp20);
}

void func_814021A4(arg1_func_8140213C* arg0, Vec3f arg1, f32 arg4, s16 arg5) {
    MtxF sp28;

    func_81401C04(&sp28, &arg0->unk_64, arg1, arg4, arg5);
    func_81401394(&sp28);
}

void func_81402214(arg1_func_8140213C* arg0, Vec3f arg1, f32 arg4) {
    MtxF sp20;

    func_81401B6C(&sp20, &arg0->unk_64, arg1, arg4);
    func_81401394(&sp20);
}

void func_8140227C(arg1_func_8140213C* arg0, Vec3f arg1, f32 arg4, s16 arg5) {
    MtxF sp28;

    func_81401D50(&sp28, &arg0->unk_64, arg1, arg4, arg5);
    func_81401394(&sp28);
}

void func_814022EC(Vec3f arg0, Vec3s arg3, f32 arg5) {
    MtxF sp30;
    Vec3s sp28;

    sp28.x = arg3.x + 0x8000;
    sp28.y = arg3.y + 0x8000;
    sp28.z = arg3.z;

    func_81401650(&sp30, arg0, sp28, arg5);
    func_81401394(&sp30);
}

void func_8140238C(Vec3f arg0, Vec3f arg3, f32 arg6) {
    MtxF sp30;

    func_81401E84(&sp30, arg3, arg0, 0, arg6);
    func_81401394(&sp30);
}
