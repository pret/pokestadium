#include "fragment62.h"
#include "src/math_util.h"

void func_8430C070(Vec3f* arg0, Vec3f* arg1, f32* arg2, s16* arg3, s16* arg4) {
    f32 sp2C = arg1->x - arg0->x;
    f32 sp28 = arg1->y - arg0->y;
    f32 sp24 = arg1->z - arg0->z;

    *arg2 = sqrtf(SQ(sp2C) + SQ(sp28) + SQ(sp24));
    *arg3 = MathUtil_Atan2s(sqrtf(SQ(sp2C) + SQ(sp24)), sp28);
    *arg4 = MathUtil_Atan2s(sp24, sp2C);
}

Vec3f* func_8430C120(Vec3f* arg0) {
    arg0->x = 0.0f;
    arg0->y = 0.0f;
    arg0->z = 0.0f;
    return arg0;
}

Vec3f* func_8430C138(Vec3f* arg0, Vec3f* arg1, f32 arg2, s16 arg3) {
    arg0->x = (SINS(arg3) * arg2) + arg1->x;
    arg0->y = arg1->y;
    arg0->z = (COSS(arg3) * arg2) + arg1->z;
    return arg0;
}

void func_8430C19C(Vec3f* arg0, f32 arg1, s16 arg2) {
    arg0->x = COSS(arg2) * arg1;
    arg0->z = SINS(arg2) * arg1;
}

Vec3f* func_8430C1E4(Vec3f* arg0, Vec3f* arg1) {
    arg0->x = arg1->x;
    arg0->y = arg1->y;
    arg0->z = arg1->z;
    return arg0;
}

Vec3s* func_8430C204(Vec3s* arg0, Vec3s* arg1) {
    arg0->x = arg1->x;
    arg0->y = arg1->y;
    arg0->z = arg1->z;
    return arg0;
}

Vec3f* func_8430C224(Vec3f* arg0, f32 arg1, f32 arg2, f32 arg3) {
    arg0->x = arg0->x * arg1;
    arg0->y = arg0->y * arg2;
    arg0->z = arg0->z * arg3;
    return arg0;
}

s16 func_8430C260(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    return MathUtil_Atan2s(arg2 - arg0, arg3 - arg1);
}

f32 func_8430C2A4(Vec3f arg0, Vec3f arg1) {
    return sqrtf(SQ(arg1.x - arg0.x) + SQ(arg1.y - arg0.y) + SQ(arg1.z - arg0.z));
}

f32 func_8430C308(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    static f32 D_843900D0;
    static f32 D_843900D4;

    D_843900D0 = SQ(arg0 - arg2);
    D_843900D4 = SQ(arg1 - arg3);

    if (D_843900D0 + D_843900D4 == 0.0f) {
        return 0.0f;
    }

    return sqrtf(D_843900D0 + D_843900D4);
}

s32 func_8430C384(f32 arg0) {
    s32 temp_v1;
    s32 var_v1;

    temp_v1 = osGetCount() & 0xFF;
    while (temp_v1-- > 0) {
        MathUtil_Random_ZeroOne();
    }

    var_v1 = MathUtil_Random_ZeroOne() * arg0;
    if (arg0 <= var_v1) {
        var_v1 = (s32)arg0 - 1;
    }
    return var_v1;
}

u16 func_8430C414(s32 arg0) {
    f32 tmp = (u32)MathUtil_Random16();

    return (tmp / 65535.0) * arg0;
}

s32 func_8430C4F8(s16* arg0, s16 arg1, s16 arg2) {
    s16 temp_v0 = arg1 - *arg0;

    if (arg2 < 0) {
        arg2 *= -1;
    }

    if (temp_v0 > 0) {
        temp_v0 -= arg2;
        if (temp_v0 >= 0) {
            *arg0 = arg1 - temp_v0;
        } else {
            *arg0 = arg1;
        }
    } else {
        temp_v0 += arg2;
        if (temp_v0 <= 0) {
            *arg0 = arg1 - temp_v0;
        } else {
            *arg0 = arg1;
        }
    }

    if (arg1 == *arg0) {
        return 0;
    }

    return 1;
}

s32 func_8430C59C(s16* arg0, s16 arg1, f32 arg2) {
    f32 var_fv0;
    s16 temp_v0;

    temp_v0 = arg1 - *arg0;
    if (arg2 < 0.0f) {
        arg2 = -1.0f * arg2;
    }

    var_fv0 = temp_v0 * arg2;

    if (temp_v0 > 0) {
        if ((s16)var_fv0 >= 0x444) {
            var_fv0 = 1092.0f;
        }

        if ((s16)var_fv0 < 0x29) {
            var_fv0 = 40.0f;
        }

        temp_v0 -= (s16)var_fv0;
        if (temp_v0 >= 0) {
            *arg0 = arg1 - temp_v0;
        } else {
            *arg0 = arg1;
        }
    } else {
        if ((s16)var_fv0 < -0x443) {
            var_fv0 = -1092.0f;
        }

        if ((s16)var_fv0 >= -0x28) {
            var_fv0 = -40.0f;
        }

        temp_v0 -= (s16)var_fv0;
        if (temp_v0 <= 0) {
            *arg0 = arg1 - temp_v0;
        } else {
            *arg0 = arg1;
        }
    }

    if (arg1 == *arg0) {
        return 0;
    }
    return 1;
}

void func_8430C718(f32* arg0, f32 arg1, f32 arg2) {
    *arg0 = *arg0 + ((arg1 - *arg0) * arg2);
    if ((*arg0 < 0.001) && (*arg0 > -0.001)) {
        *arg0 = 0.0f;
    }
}

void func_8430C780(s16* arg0, s16 arg1, s16 arg2) {
    *arg0 = *arg0 + ((arg1 - *arg0) * arg2);
}

void func_8430C7B4(u16* arg0, u16 arg1, s16 arg2) {
    *arg0 = *arg0 + ((arg1 - *arg0) * arg2);
}

void func_8430C7E4(f32* arg0, f32 arg1) {
    static f32 D_843900D8;
    static f32 D_843900DC;
    static f32 D_843900E0;

    D_843900E0 = 1.0f - arg1;
    D_843900DC = SQ(arg1);
    D_843900D8 = D_843900DC * arg1;

    arg0[0] = (SQ(D_843900E0) * D_843900E0) / 6.0f;
    arg0[1] = ((0.5f * D_843900D8) - D_843900DC) + 0.6666667f;
    arg0[2] = (-0.5f * D_843900D8) + (0.5f * D_843900DC) + (0.5f * arg1) + 0.16666667f;
    arg0[3] = D_843900D8 / 6.0;
}

void func_8430C8A0(f32* arg0, f32 arg1) {
    static f32 D_843900E4;
    static f32 D_843900E8;
    static f32 D_843900EC;

    D_843900EC = 1.0 - arg1;
    D_843900E8 = SQ(arg1);
    D_843900E4 = D_843900E8 * arg1;

    arg0[0] = SQ(D_843900EC) * D_843900EC;
    arg0[1] = (((21.0f * D_843900E4) / 12.0f) - (9.0f * D_843900E8 * 0.5f)) + (3.0f * arg1);
    arg0[2] = ((-11.0f * D_843900E4) / 12.0f) + (3.0f * D_843900E8 * 0.5f);
    arg0[3] = D_843900E4 / 6.0f;
}

void func_8430C97C(f32* arg0, f32 arg1) {
    static f32 D_843900F0;
    static f32 D_843900F4;
    static f32 D_843900F8;

    D_843900F8 = 1.0f - arg1;
    D_843900F4 = SQ(arg1);
    D_843900F0 = D_843900F4 * arg1;

    arg0[0] = SQ(D_843900F8) * D_843900F8 * 0.25f;
    arg0[1] = ((0.5833333f * D_843900F0) - (1.25f * D_843900F4)) + (arg1 * 0.25f) + 0.5833333f;
    arg0[2] = (-0.5f * D_843900F0) + (0.5f * D_843900F4) + (0.5f * arg1) + 0.16666667f;
    arg0[3] = D_843900F0 / 6.0f;
}

void func_8430CA4C(f32* arg0, f32 arg1) {
    static f32 D_843900FC;
    static f32 D_84390100;
    static f32 D_84390104;
    static f32 D_84390108;

    D_84390100 = 1.0f - arg1;
    D_84390104 = SQ(D_84390100);
    D_84390108 = D_84390104 * D_84390100;
    D_843900FC = CB(arg1);

    arg0[0] = D_84390108 / 6.0f;
    arg0[1] = (-0.5f * D_84390108) + (0.5f * D_84390104) + (0.5f * D_84390100) + 0.16666667f;
    arg0[2] = (((7.0f * D_84390108) / 12.0f) - (5.0f * D_84390104 * 0.25f)) + (D_84390100 * 0.25f) + 0.5833333f;
    arg0[3] = D_843900FC * 0.25f;
}

void func_8430CB3C(f32* arg0, f32 arg1) {
    static f32 D_8439010C;
    static f32 D_84390110;
    static f32 D_84390114;
    static f32 D_84390118;

    D_84390110 = 1.0f - arg1;
    D_84390114 = SQ(D_84390110);
    D_84390118 = D_84390114 * D_84390110;
    D_8439010C = CB(arg1);

    arg0[0] = D_84390118 / 6.0f;
    arg0[1] = ((-11.0f * D_84390118) / 12.0f) + (3.0f * D_84390114 * 0.5f);
    arg0[2] = (((21.0f * D_84390118) / 12.0f) - (9.0f * D_84390114 * 0.5f)) + (3.0f * D_84390110);
    arg0[3] = D_8439010C;
}
