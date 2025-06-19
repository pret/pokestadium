#include "fragment62.h"
#include "src/12D80.h"
#include "src/F420.h"

unk_D_843901B0 D_843901B0;
f32 D_843901F0;
f32 D_843901F4;

static s32 D_84385B50 = 0;

f32 func_8431AD20(unk_D_84390010* arg0, f32 arg1, f32 arg2) {
    f32 temp_fv1 = func_84308598(arg0) * arg1;

    if (arg2 < temp_fv1) {
        return arg2;
    }
    return temp_fv1;
}

s32 func_8431AD68(s32 arg0) {
    D_84390240.unk_00->unk_10++;
    if (D_84390240.unk_00->unk_10 >= arg0) {
        D_84390240.unk_00->unk_10 = 0;
        return 1;
    }
    return 0;
}

s32 func_8431ADAC(s32 arg0) {
    D_84390240.unk_00->unk_14++;
    if (D_84390240.unk_00->unk_14 >= arg0) {
        D_84390240.unk_00->unk_14 = 0;
        return 1;
    }
    return 0;
}

s32 func_8431ADF0(s32 arg0) {
    if (D_84390240.unk_00->unk_14 >= arg0) {
        return 1;
    }
    D_84390240.unk_00->unk_14++;
    return 0;
}

s32 func_8431AE20(s32 arg0) {
    if (D_84390240.unk_00->unk_14 >= arg0) {
        return 1;
    }
    return 0;
}

void func_8431AE4C(s32 arg0) {
    D_84390240.unk_00->unk_2C = arg0;
}

void func_8431AE5C(void) {
    D_84390240.unk_00->unk_14 = 0;
}

void func_8431AE6C(void) {
    D_84390240.unk_00->unk_10 = 0;
}

void func_8431AE7C(unk_D_86002F34_00C* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s16 arg5, s16 arg6) {
    func_8000E88C(&arg0->unk_60.at, arg1, arg2, arg3);
    func_80010354(&arg0->unk_60.at, &arg0->unk_60.eye, arg4, arg5, arg6);
}

void func_8431AED8(unk_D_84390010* arg0, Vec3f* arg1) {
    UNUSED s32 pad;
    u8 sp18[] = {
        0x52, 0x73, 0x59, 0x91, 0x5F, 0x82, 0x58, 0x66, 0x0A,
    };

    if (func_84307AE0(arg0->unk_000.unk_01A, sp18, 9) != 0) {
        func_8431AF58(arg0, arg1, 9);
    } else {
        func_8431AF58(arg0, arg1, 0x64);
    }
}

void func_8431AF58(unk_D_84390010* arg0, Vec3f* arg1, s32 arg2) {
    if (func_80015390(&arg0->unk_000, arg2, arg1) == NULL) {
        func_843081F0(arg0, arg1);
        arg1->x = func_84307DE0(arg0);
        arg1->z = 0.0f;
    }
}

void func_8431AFB4(s32 arg0, s32 arg1) {
    D_84390240.unk_00->unk_1C = arg0;
    D_84390240.unk_00->unk_20 = arg1;
}

void func_8431AFD0(unk_D_86002F34_00C* arg0, f32 arg1, f32 arg2) {
    arg0->unk_24.near = arg1;
    arg0->unk_24.far = arg2;
}

void func_8431AFE4(s32 arg0, u16 arg1) {
    D_84390240.unk_00->unk_30 = arg0;
    D_84390240.unk_00->unk_2E = arg1;
}

void func_8431B004(void) {
    if (D_84390240.unk_00->unk_18 == 2) {
        if (D_84390240.unk_00->unk_44 == 1) {
            func_8431AFB4(1, 0x32);
        }

        if (D_84390240.unk_00->unk_44 == 2) {
            D_84390240.unk_00->unk_2C = D_84390240.unk_00->unk_2A;
            func_8431AFB4(2, 0);
        }
    }
}

void func_8431B078(unk_D_84390010* arg0) {
    unk_func_80026268_arg0* ptr = &arg0->unk_724->unk_01C[arg0->unk_654.unk_08];

    D_84390240.unk_00->unk_68 = ((ptr->unk_02 - arg0->unk_654.unk_38.unk_0C) / 996.0f) * 1400.0f;

    if (D_84390240.unk_00->unk_68 == 0.0f) {
        D_84390240.unk_00->unk_68 = 0.0f;
    } else if (D_84390240.unk_00->unk_68 <= 20.0f) {
        D_84390240.unk_00->unk_68 = 20.0f;
    } else if (D_84390240.unk_00->unk_68 >= 50.0f) {
        D_84390240.unk_00->unk_68 = 50.0f;
    }

    D_84390240.unk_00->unk_7A = 0;

    if (D_84390288 != 0) {
        D_84390240.unk_00->unk_68 = 25.0f;
    }
}

void func_8431B174(unk_D_86002F34_00C* arg0) {
    UNUSED s32 pad;
    f32 sp30;
    f32 temp_fv0;
    s16 sp2A;
    s16 sp28;

    func_8430C070(&arg0->unk_60.eye, &arg0->unk_60.at, &sp30, &sp28, &sp2A);
    D_84390240.unk_00->unk_7A += 0x38E0;
    func_8430C718(&D_84390240.unk_00->unk_68, 0.0f, 0.18f);

    temp_fv0 = COSS(D_84390240.unk_00->unk_7A) * D_84390240.unk_00->unk_68;

    arg0->unk_60.eye.y += temp_fv0 / 3.0f;
    arg0->unk_60.at.y += temp_fv0 / 3.0f;
    arg0->unk_60.eye.x += temp_fv0 * SINS(sp2A + 0x4000);
    arg0->unk_60.at.x += temp_fv0 * SINS(sp2A + 0x4000);
}

void func_8431B290(UNUSED unk_D_84390010* arg0) {
    D_84390240.unk_00->unk_68 = 30.0f;
    D_84390240.unk_00->unk_7A = 0;
}

s32 func_8431B2B8(s16 arg0, s16 arg1) {
    s16 temp_v1;
    s16 var_v1;

    temp_v1 = arg1 - arg0;
    var_v1 = arg1;
    if (temp_v1 > 0) {
        temp_v1 -= 0xE38;
        if (temp_v1 > 0) {
            var_v1 -= temp_v1;
        } else {
            var_v1 = arg1;
        }
    } else {
        temp_v1 += 0xE38;
        if (temp_v1 < 0) {
            var_v1 -= temp_v1;
        } else {
            var_v1 = arg1;
        }
    }

    if (var_v1 == arg1) {
        return 1;
    }
    return 0;
}

s32 func_8431B34C(unk_D_86002F34_00C* arg0, s16 arg1, s16 arg2) {
    if (arg1 > 0) {
        D_84390240.unk_00->unk_58 -= arg1;
        if ((D_84390240.unk_00->unk_58 < arg2) && ((arg2 - arg1) < D_84390240.unk_00->unk_58)) {
            D_84390240.unk_00->unk_58 = arg2;
            return 1;
        }
    } else {
        D_84390240.unk_00->unk_58 -= arg1;
        if ((arg2 < D_84390240.unk_00->unk_58) && (D_84390240.unk_00->unk_58 < (arg2 - arg1))) {
            D_84390240.unk_00->unk_58 = arg2;
            return 1;
        }
    }

    func_80010354(&arg0->unk_60.at, &arg0->unk_60.eye, D_84390240.unk_00->unk_5C, D_84390240.unk_00->unk_56,
                  D_84390240.unk_00->unk_58);
    return 0;
}

s32 func_8431B42C(UNUSED unk_D_86002F34_00C* arg0, s16 arg1, s16 arg2) {
    D_84390240.unk_00->unk_58 -= arg1;

    if (arg1 > 0) {
        if ((arg2 >= D_84390240.unk_00->unk_58) && (D_84390240.unk_00->unk_58 >= (arg2 - arg1))) {
            D_84390240.unk_00->unk_58 = arg2;
            return 1;
        }
    } else if ((D_84390240.unk_00->unk_58 >= arg2) && ((arg2 - arg1) >= D_84390240.unk_00->unk_58)) {
        D_84390240.unk_00->unk_58 = arg2;
        return 1;
    }
    return 0;
}

void func_8431B4C0(s16 arg0, s16 arg1, f32 arg2) {
    D_84390240.unk_00->unk_56 = arg0;
    D_84390240.unk_00->unk_58 = arg1;
    D_84390240.unk_00->unk_5C = arg2;
}

void func_8431B500(unk_D_86002F34_00C* arg0, s32 arg1) {
    static u8 D_84385B60 = 0x5F;
    static u16 D_84385B64 = 0x38F;

    unk_D_84390010_654* sp6C;
    UNUSED s32 pad;
    unk_D_84390010* temp_s0;
    Vec3f sp58;
    f32 sp54;
    UNUSED u16 pad2;
    UNUSED u8 pad3;
    u8 sp50;
    UNUSED u16 pad4;
    u16 sp4C;
    s32 idx = D_84390240.unk_00->unk_2C == 0;

    sp6C = &D_84390010[idx]->unk_654;
    sp50 = D_84385B60;
    sp4C = D_84385B64;
    temp_s0 = D_84390010[arg1 == 0];
    arg0->unk_24.fovy = 60.0f;

    func_8431AE5C();
    func_843081F0(temp_s0, &sp58);

    sp58.y /= 3.0f;
    if (temp_s0->unk_654.unk_34 & 0x4000) {
        sp58.y = 0.0f;
    }

    func_8431BAB4(temp_s0, arg0, sp58, 0, 0, 0.0f, 0.0f);

    if ((sp6C->unk_2D != 0x10) && !(sp6C->unk_34 & 0x4000)) {
        func_84305760(temp_s0, 1);
    }

    temp_s0 = D_84390010[arg1];
    if (temp_s0->unk_448.unk_24.unk_0C.x == 0.0f) {
        func_843081F0(temp_s0, &sp58);
    } else {
        func_8430C1E4(&sp58, &temp_s0->unk_448.unk_24.unk_0C);
        sp58.y += temp_s0->unk_000.unk_024.y - func_84307BAC(temp_s0);
    }

    sp54 = func_8431AD20(temp_s0, 3.0f, 300.0f);
    if ((func_84307AE0(temp_s0->unk_000.unk_01A, &sp50, 1) != 0) && (arg1 == 1)) {
        func_8431BB80(arg0, sp58, 0, func_84308190(temp_s0) - (temp_s0->unk_4B0 * 0x6AA4), sp54, 20.0f);
    } else if (func_84307AE0(temp_s0->unk_000.unk_01A, (u8*)&sp4C, 2) != 0) {
        func_8431BB80(arg0, sp58, 0, func_84308190(temp_s0) - (temp_s0->unk_4B0 * 0x6AA4), sp54, 20.0f);
    } else {
        func_8431BB80(arg0, sp58, 0, func_84308190(temp_s0) - (temp_s0->unk_4B0 * 0x754E), sp54, 0.0f);
    }
}

void func_8431B830(unk_D_86002F34_00C* arg0) {
    if (arg0->unk_60.eye.y <= 13.0f) {
        arg0->unk_60.eye.y = 13.0f;
    }
}

void func_8431B858(unk_D_84390010* arg0, unk_D_86002F34_00C* arg1) {
    unk_D_84390010_448* sp38 = &arg0->unk_448;
    UNUSED s32 pad[5];
    f32 sp3C = 0.0f;

    if (func_84307AE0(arg0->unk_000.unk_01A, &D_843845F0, 1) != 0) {
        sp3C = func_84308548(arg0) / 1.5f;
    } else if (func_84307AE0(arg0->unk_000.unk_01A, &D_843845F4, 1) != 0) {
        sp3C = func_84308548(arg0) * 0.5f;
    } else if ((func_84307AE0(arg0->unk_000.unk_01A, &D_843845F8, 1) != 0) && (arg0->unk_654.unk_34 & 0x200)) {
        sp3C = 2.0f * func_84308548(arg0);
    } else if ((func_84307AE0(arg0->unk_000.unk_01A, D_843845FC, 2) != 0) && (arg0->unk_654.unk_34 & 0x200)) {
        sp3C = func_84308548(arg0) * 1.5f;
    }

    func_8000E88C(&arg0->unk_448.unk_18, arg0->unk_448.unk_24.unk_00.x, arg0->unk_448.unk_24.unk_00.y,
                  arg0->unk_448.unk_24.unk_00.z);
    arg0->unk_448.unk_18.y = (arg0->unk_000.unk_024.y - func_84307BAC(arg0)) + arg0->unk_448.unk_18.y + sp3C;
    func_8430C1E4(&D_84390240.unk_00->unk_B8, &arg1->unk_60.at);
    func_8430C1E4(&D_84390240.unk_00->unk_C4, &arg1->unk_60.eye);
    func_800102A4(&D_84390240.unk_00->unk_B8, &D_84390240.unk_00->unk_C4, &D_84390240.unk_00->unk_70, &sp38->unk_44,
                  &sp38->unk_46);
    func_800102A4(&arg0->unk_448.unk_18, &arg1->unk_60.at, &sp38->unk_4C, &sp38->unk_44, &sp38->unk_46);
    D_84390240.unk_00->unk_6C = 0.0f;
    D_84390240.unk_00->unk_74 = 0.0f;
}

void func_8431BA5C(void) {
    func_8000E88C(&D_84390240.unk_00->unk_94, 0.0f, 0.0f, 0.0f);
    func_8000E88C(&D_84390240.unk_00->unk_A0, 0.0f, 0.0f, 0.0f);
}

void func_8431BAB4(unk_D_84390010* arg0, unk_D_86002F34_00C* arg1, Vec3f arg2, s16 arg3, s16 arg4, f32 arg5, f32 arg6) {
    func_80010354(&arg2, &arg1->unk_60.at, arg5, arg3, arg4);
    arg1->unk_60.at.y += arg6;
    arg1->unk_60.at.y += func_84307C30(arg0);
}

void func_8431BB24(unk_D_86002F34_00C* arg0, Vec3f arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5) {
    func_80010354(&arg1, &arg0->unk_60.at, arg4, arg2, arg3);
    arg0->unk_60.at.y += arg5;
}

void func_8431BB80(unk_D_86002F34_00C* arg0, Vec3f arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5) {
    func_80010354(&arg1, &arg0->unk_60.eye, arg4, arg2, arg3);
    arg0->unk_60.eye.y += arg5;
}

void func_8431BBDC(unk_D_86002F34_00C* arg0, s16 arg1, s16 arg2, f32 arg3, f32 arg4) {
    func_80010354(&arg0->unk_60.at, &arg0->unk_60.eye, arg3, arg1, arg2);
    arg0->unk_60.eye.y += arg4;
}

void func_8431BC38(unk_D_86002F34_00C* arg0, Vec3f arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5) {
    func_8431B4C0(arg2, arg3, arg4);
    func_80010354(&arg1, &arg0->unk_60.eye, arg4, arg2, arg3);
    arg0->unk_60.eye.y += arg5;
}

void func_8431BCA4(unk_D_86002F34_00C* arg0, s16 arg1, s16 arg2, f32 arg3, f32 arg4) {
    func_8431B4C0(arg1, arg2, arg3);
    func_80010354(&arg0->unk_60.at, &arg0->unk_60.eye, arg3, arg1, arg2);
    arg0->unk_60.eye.y += arg4;
}

void func_8431BD10(UNUSED unk_D_86002F34_00C* arg0) {
}

void func_8431BD18(f32* arg0, f32* arg1) {
    f32 tmp;

    if (*arg0 != *arg1) {
        if (*arg1 < *arg0) {
            tmp = *arg0 - *arg1;
            if (tmp <= 1e-05) {
                *arg1 = *arg0;
            }
        } else {
            tmp = *arg1 - *arg0;
            if (tmp <= 1e-05) {
                *arg0 = *arg1;
            }
        }
    }
}

void func_8431BD94(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1, UNUSED f32 arg2) {
    unk_D_84390010_448* sp2C = &arg1->unk_448;
    f32 var_fv1;
    Vec3f sp64;
    Vec3f sp58;
    Vec3f sp4C;
    Vec3f sp40;
    f32 sp3C;
    f32 temp_fv1;
    s16 sp36;
    s16 sp34;

    func_8430C1E4(&sp4C, &arg0->unk_60.at);
    func_8430C1E4(&sp40, &arg0->unk_60.at);
    func_8431AED8(arg1, &sp64);
    func_800102A4(&sp64, &arg1->unk_448.unk_18, &sp3C, &sp36, &sp34);

    switch (arg1->unk_000.unk_01A) {
        case 0x5F:
            arg0->unk_24.fovy = 50.0f;
            return;

        case 0x82:
            arg0->unk_24.fovy = 50.0f;
            if (sp3C < (func_84307BD8(arg1) * 0.5f)) {
                func_8430C1E4(&sp64, &arg1->unk_448.unk_18);
            }
            break;

        case 0x1D:
        case 0x29:
        case 0x32:
        case 0x33:
        case 0x5B:
            if (sp3C < (func_84307BD8(arg1) * 5.0f)) {
                func_8430C1E4(&sp64, &arg1->unk_448.unk_18);
            }
            break;

        case 0x12:
            if (sp3C < (func_84307BD8(arg1) * 1.5f)) {
                func_8430C1E4(&sp64, &arg1->unk_448.unk_18);
            }
            break;

        case 0x27:
        case 0x58:
        case 0x59:
        case 0x96:
            if (sp3C < func_84307BD8(arg1)) {
                func_8430C1E4(&sp64, &arg1->unk_448.unk_18);
            }
            break;

        case 0x4A:
        case 0x65:
        case 0x67:
            if (sp3C < (func_84307BD8(arg1) / 1.2f)) {
                func_8430C1E4(&sp64, &arg1->unk_448.unk_18);
            }
            break;

        case 0x7:
        case 0x11:
        case 0x16:
        case 0x4C:
        case 0x5C:
        case 0x83:
            if (sp3C < (func_84307BD8(arg1) / 3.0f)) {
                func_8430C1E4(&sp64, &arg1->unk_448.unk_18);
            }
            break;

        default:
            if (sp3C < (func_84307BD8(arg1) * 0.5f)) {
                func_8430C1E4(&sp64, &arg1->unk_448.unk_18);
            }
            break;
    }

    sp64.y = arg1->unk_448.unk_18.y;
    func_80010354(&sp64, &sp58, sp2C->unk_4C, sp2C->unk_44, sp2C->unk_46);
    sp4C.y = sp58.y;
    func_800102A4(&sp4C, &sp58, &sp3C, &sp36, &sp34);

    switch (arg1->unk_000.unk_01A) {
        case 0x58:
        case 0x59:
        case 0x87:
            var_fv1 = sp3C / (func_84307BD8(arg1) * 50.0f);
            break;

        case 0x16:
        case 0x4C:
        case 0x96:
            var_fv1 = sp3C / (func_84307BD8(arg1) * 1.5f);
            break;

        default:
            temp_fv1 = sp3C / func_84307BD8(arg1);
            if (temp_fv1 <= 0.1f) {
                var_fv1 = sp3C / (func_84307BD8(arg1) * 15.0f);
            } else if (temp_fv1 <= 0.2f) {
                var_fv1 = sp3C / (func_84307BD8(arg1) * 7.0f);
            } else if (temp_fv1 <= 0.3f) {
                var_fv1 = sp3C / (func_84307BD8(arg1) * 5.0f);
            } else if (temp_fv1 <= 0.4f) {
                var_fv1 = sp3C / (func_84307BD8(arg1) * 3.0f);
            } else if (temp_fv1 <= 0.5f) {
                var_fv1 = sp3C / (func_84307BD8(arg1) * 1.5f);
            } else {
                var_fv1 = sp3C / func_84307BD8(arg1);
            }
            break;
    }

    if (var_fv1 > 1.0f) {
        var_fv1 = 1.0f;
    }

    func_80010354(&sp4C, &arg0->unk_60.at, sp3C * var_fv1, 0, sp34);
    func_8431AED8(arg1, &sp64);
    func_80010354(&sp64, &sp58, sp2C->unk_4C, sp2C->unk_44, sp2C->unk_46);

    sp3C = sp40.y - sp58.y;
    if (sp3C < 0.0f) {
        sp3C *= -1.0f;
    }

    if (arg1->unk_4B4 == 0xD) {
        var_fv1 = 0;
    } else if ((arg1->unk_000.unk_01A == 0x58) || (arg1->unk_000.unk_01A == 0x59)) {
        temp_fv1 = sp3C / func_84307BD8(arg1);
        if (temp_fv1 <= 0.05f) {
            var_fv1 = sp3C / (func_84307BD8(arg1) * 90.0f);
        } else if (temp_fv1 <= 0.1f) {
            var_fv1 = sp3C / (func_84307BD8(arg1) * 70.0f);
        } else if (temp_fv1 <= 0.2f) {
            var_fv1 = sp3C / (func_84307BD8(arg1) * 65.0f);
        } else if (temp_fv1 <= 0.3f) {
            var_fv1 = sp3C / (func_84307BD8(arg1) * 63.0f);
        } else {
            var_fv1 = sp3C / (func_84307BD8(arg1) * 45.0f);
        }
    } else {
        temp_fv1 = sp3C / func_84307BD8(arg1);
        if (temp_fv1 <= 0.05f) {
            var_fv1 = sp3C / (func_84307BD8(arg1) * 50.0f);
        } else if (temp_fv1 <= 0.1f) {
            var_fv1 = sp3C / (func_84307BD8(arg1) * 30.0f);
        } else if (temp_fv1 <= 0.2f) {
            var_fv1 = sp3C / (func_84307BD8(arg1) * 25.0f);
        } else if (temp_fv1 <= 0.3f) {
            var_fv1 = sp3C / (func_84307BD8(arg1) * 23.0f);
        } else {
            var_fv1 = sp3C / (func_84307BD8(arg1) * 15.0f);
        }
    }

    if (var_fv1 > 1.0f) {
        var_fv1 = 1.0f;
    }

    func_8430C718(&sp40.y, sp58.y, var_fv1);
    arg0->unk_60.at.y = sp40.y;
    func_8431BD18(&arg0->unk_60.at.x, &arg0->unk_60.eye.x);
    func_8431BD18(&arg0->unk_60.at.y, &arg0->unk_60.eye.y);
    func_8431BD18(&arg0->unk_60.at.z, &arg0->unk_60.eye.z);
}

void func_8431C594(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1) {
    UNUSED s32 pad[5];
    f32 var_fv0_2;
    f32 sp44;
    s32 temp_lo;
    s16 sp3E;
    s16 sp3C;
    f32 sp38;
    s16 sp36;
    s16 sp34;
    u8 sp2C[] = { 0x2D, 0x35, 0x79, 0x2C, 0x6E };

    func_800102A4(&D_84390240.unk_00->unk_B8, &D_84390240.unk_00->unk_C4, &sp38, &sp36, &sp34);
    func_800102A4(&arg0->unk_60.at, &arg0->unk_60.eye, &sp44, &sp3E, &sp3C);

    temp_lo = sp34 / 182;
    if ((temp_lo == 0x5A) || (temp_lo == -0x5A)) {
        if (func_84307AE0(arg1->unk_000.unk_01A, sp2C, sizeof(sp2C)) != 0) {
            sp44 = sp38;
        } else {
            sp44 = func_800104AC(sp44, sp38, 30.0f, 5.0f);
        }
    } else {
        var_fv0_2 = D_84390240.unk_00->unk_70 - sp44;
        if (var_fv0_2 < 0.0f) {
            var_fv0_2 *= -1.0f;
        }

        if (sp44 < sp38) {
            sp44 = func_800104AC(sp44, D_84390240.unk_00->unk_70, var_fv0_2 * 0.4f, var_fv0_2 * 0.08f);
        }
    }
    func_80010354(&arg0->unk_60.at, &arg0->unk_60.eye, sp44, sp36, sp34);
}

void func_8431C71C(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1) {
    func_8431BD94(arg0, arg1, 50.0f);
    func_8431C594(arg0, arg1);
}

void func_8431C750(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1) {
    func_8431BD94(arg0, arg1, 90.0f);
    func_8431C594(arg0, arg1);
}

void func_8431C784(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1) {
    func_8431BD94(arg0, arg1, 50.0f);
}

void func_8431C7A4(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1) {
    unk_D_84390010_448* ptr = &arg1->unk_448;
    UNUSED s32 pad;
    Vec3f sp54;
    Vec3f sp48;
    Vec3f sp3C;
    f32 sp38;
    f32 var_fa0;
    s16 sp32;
    s16 sp30;

    func_8430C1E4(&sp3C, &arg0->unk_60.at);
    func_8431AED8(arg1, &sp54);
    func_800102A4(&sp54, &arg1->unk_448.unk_18, &sp38, &sp32, &sp30);

    if (sp38 < (func_84307BD8(arg1) * 1.1f)) {
        func_8430C1E4(&sp54, &arg1->unk_448.unk_18);
    }

    func_80010354(&sp54, &sp48, ptr->unk_4C, ptr->unk_44, ptr->unk_46);
    func_800102A4(&sp3C, &sp48, &sp38, &sp32, &sp30);

    var_fa0 = (sp38 / (func_84307BD8(arg1) * 80.0f)) * 3.0f;
    if (var_fa0 >= 1.0f) {
        var_fa0 = 1.0f;
    }

    func_80010354(&sp3C, &arg0->unk_60.at, sp38 * var_fa0, sp32, sp30);
}

s32 func_8431C8E0(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1) {
    Vec3f sp84;
    UNUSED s32 pad[3];
    Vec3f sp6C;
    Vec3f sp60;
    UNUSED s32 pad2[3];
    s16 sp52;
    s16 sp50;
    s16 sp4E;
    s16 sp4C;
    UNUSED s32 pad3[2];
    unk_D_800FCB18* temp_v1;

    temp_v1 = &D_84390010[func_84307F00(arg1) == 0]->unk_654.unk_38;

    if (arg1->unk_654.unk_34 & 0x4000) {
        return 1;
    }

    if (temp_v1->unk_5A == 0x53) {
        func_8431F500(arg1, arg0, 4);
        return 1;
    }

    func_8430C1E4(&sp6C, &arg0->unk_60.at);
    func_8430C1E4(&sp60, &arg0->unk_60.eye);

    if ((arg1->unk_000.unk_01A != 0x5F) && (arg1->unk_4B4 != 0xD)) {
        func_8431C7A4(arg0, arg1);
    }

    func_843081F0(arg1, &sp84);
    D_843901F0 = func_8431AD20(arg1, 3.5f, 300.0f);
    func_8431BB80(arg0, sp84, 0, func_84308190(arg1), D_843901F0, 0.0f);

    if (arg0->unk_60.eye.y <= 13.0f) {
        arg0->unk_60.eye.y = 13.0f;
    }

    func_8430C070(&sp84, &arg0->unk_60.eye, &D_843901F4, &sp4C, &sp50);
    func_8430C070(&sp84, &sp60, &D_843901F0, &sp4E, &sp52);
    func_8430C718(&D_843901F0, D_843901F4, 0.2f);
    func_8430C718(&D_84390240.unk_00->unk_94.z, 0.2f, 0.03f);
    func_8430C59C(&sp52, sp50, D_84390240.unk_00->unk_94.z);
    func_8430C59C(&sp4E, sp4C, D_84390240.unk_00->unk_94.z);
    func_8431BB80(arg0, sp84, sp4E, sp52, D_843901F0, 0.0f);

    if ((sp4C == sp4E) && (sp50 == sp52)) {
        return 1;
    }
    return 0;
}

void func_8431CB54(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1) {
    unk_D_84390010_448* ptr = &arg1->unk_448;
    Vec3f sp58;
    Vec3f sp4C;
    UNUSED s32 pad[3];
    Vec3f sp34;
    f32 sp30;
    UNUSED s32 pad2[1];
    s16 sp2A;
    s16 sp28;

    func_8430C1E4(&sp34, &arg0->unk_60.at);
    func_8431AED8(arg1, &sp58);
    func_80010354(&sp58, &sp4C, ptr->unk_4C, ptr->unk_44, ptr->unk_46);
    func_800102A4(&sp34, &sp4C, &sp30, &sp2A, &sp28);
    D_84390240.unk_00->unk_94.z = func_800104AC(D_84390240.unk_00->unk_94.z, 0.8f, 0.05f, 0.05f);
    func_80010354(&sp34, &arg0->unk_60.at, D_84390240.unk_00->unk_94.z * sp30, sp2A, sp28);
}

void func_8431CC38(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1) {
    unk_D_84390010_448* ptr = &arg1->unk_448;
    Vec3f sp60;
    Vec3f sp54;
    UNUSED s32 pad[3];
    Vec3f sp3C;
    UNUSED s32 pad2[3];

    func_8430C1E4(&sp3C, &arg0->unk_60.at);
    func_8431AED8(arg1, &sp60);
    func_80010354(&sp60, &sp54, ptr->unk_4C, ptr->unk_44, ptr->unk_46);
    func_8430C718(&arg0->unk_60.at.y, sp54.y, 0.1f);
    if (arg0->unk_60.at.y < -10.0f) {
        arg0->unk_60.at.y = -10.0f;
    }
    func_8430C718(&arg0->unk_60.eye.y, func_84308548(arg1) * 4.0f, 0.04f);
}

void func_8431CCFC(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1) {
    Vec3f sp74;
    Vec3f sp68;
    Vec3f sp5C;
    f32 sp58;
    s16 sp56;
    s16 sp54;
    s16 sp52;
    s16 sp50;
    s16 sp4E;
    s16 sp4C;

    func_8430C1E4(&sp68, &arg0->unk_60.at);
    func_8430C1E4(&sp5C, &arg0->unk_60.eye);
    func_843081F0(arg1, &sp74);
    D_843901F0 = func_8431AD20(arg1, 3.5f, 300.0f);
    func_8431BAB4(arg1, arg0, sp74, 0, func_84308190(arg1), 0.0f, 0.0f);
    func_8431BB80(arg0, sp74, 0, func_84308190(arg1), D_843901F0, 0.0f);
    func_8430C070(&arg0->unk_60.at, &arg0->unk_60.eye, &D_843901F4, &sp4C, &sp50);
    func_8430C070(&sp68, &sp5C, &D_843901F0, &sp4E, &sp52);
    func_8430C718(&D_843901F0, D_843901F4, 0.05f);
    func_8430C4F8(&sp52, sp50, 0x108);
    func_8430C4F8(&sp4E, sp4C, 0xB6);
    func_8430C070(&sp68, &arg0->unk_60.at, &sp58, &sp56, &sp54);
    func_80010354(&sp68, &arg0->unk_60.at, sp58 / 8, sp56, sp54);
    func_8431BBDC(arg0, sp4E, sp52, D_843901F0, 0.0f);
}

void func_8431CEF0(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1, UNUSED s32 arg2) {
    unk_D_84390010_448* ptr = &arg1->unk_448;
    Vec3f sp50;
    Vec3f sp44;
    Vec3f sp38;
    f32 sp34;
    s16 sp32;
    s16 sp30;
    UNUSED s32 pad;

    func_8431AED8(arg1, &sp50);
    func_8430C1E4(&sp38, &arg0->unk_60.at);
    func_80010354(&sp50, &sp44, ptr->unk_4C, ptr->unk_44, ptr->unk_46);
    func_8430C070(&sp38, &sp44, &sp34, &sp32, &sp30);
    func_80010354(&sp38, &arg0->unk_60.at, sp34 * 0.1f, sp32, sp30);
}

void func_8431CFA4(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1) {
    s16 sp26;
    s16 sp24;

    D_843901F0 = func_8431AD20(arg1, 8.0f, 500.0f);
    func_8430C070(&arg0->unk_60.at, &arg0->unk_60.eye, &D_843901F4, &sp26, &sp24);
    func_8430C718(&D_843901F4, D_843901F0, 0.03f);
    func_8430C4F8(&sp26, 0xE38, 0x5B);
    func_8431BBDC(arg0, sp26, sp24, D_843901F4, 0.0f);
}

s32 func_8431D048(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1) {
    Vec3f sp3C;
    Vec3f sp30;
    f32 sp2C;
    s16 sp2A;
    s16 sp28;

    func_8430C1E4(&sp3C, &arg0->unk_60.at);
    func_8430C1E4(&sp30, &arg0->unk_60.eye);
    func_8431EF54(arg0, arg1);
    func_800102A4(&sp30, &arg0->unk_60.eye, &sp2C, &sp28, &sp2A);
    func_80010354(&sp30, &arg0->unk_60.eye, sp2C / 2, sp28, sp2A);
    func_8430C1E4(&arg0->unk_60.at, &sp3C);

    if (sp2C <= 0.5f) {
        return 1;
    }
    return 0;
}

s32 func_8431D118(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1, s32 arg2, s32 arg3) {
    UNUSED s32 pad;
    Vec3f sp60;
    Vec3f sp54;
    Vec3f sp48;
    Vec3f sp3C;
    f32 sp38;
    f32 sp34;
    s16 sp32;
    s16 sp30;

    if (D_843901B0.unk_3C != 200.0f) {
        arg0->unk_24.fovy = D_843901B0.unk_3C;
    } else if (arg3 == 1) {
        func_8430C718(&arg0->unk_24.fovy, 30.0f, 0.06f);
    } else {
        arg0->unk_24.fovy = 30.0f;
    }

    func_8430C718(&D_84390240.unk_00->unk_94.z, D_843901B0.unk_34, D_843901B0.unk_38);
    func_80010354(&D_843901B0.unk_00, &sp54, D_843901B0.unk_30, D_843901B0.unk_26, D_843901B0.unk_28);
    func_8430C1E4(&sp48, &arg0->unk_60.eye);
    func_8430C070(&sp48, &sp54, &sp38, &sp32, &sp30);
    func_80010354(&sp48, &arg0->unk_60.eye, D_84390240.unk_00->unk_94.z * sp38, sp32, sp30);
    func_80010354(&D_843901B0.unk_00, &sp3C, D_843901B0.unk_2C, D_843901B0.unk_20, D_843901B0.unk_22);

    if (arg2 == 1) {
        sp3C.y += func_84307C30(arg1);
    }

    func_8430C1E4(&sp60, &arg0->unk_60.at);
    func_8430C070(&sp60, &sp3C, &sp34, &sp32, &sp30);
    func_80010354(&sp60, &arg0->unk_60.at, D_84390240.unk_00->unk_94.z * sp34, sp32, sp30);

    if ((sp38 <= 1.75f) && (sp34 <= 1.75f)) {
        return 1;
    }
    return 0;
}

s32 func_8431D318(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1) {
    Vec3f sp6C;
    Vec3f sp60;
    Vec3f sp54;
    Vec3f sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 var_fa1;
    s16 sp36;
    s16 sp34;

    if (D_843901B0.unk_3C != 200.0f) {
        arg0->unk_24.fovy = D_843901B0.unk_3C;
    } else {
        arg0->unk_24.fovy = 30.0f;
    }

    func_8430C718(&D_84390240.unk_00->unk_94.z, D_843901B0.unk_34, D_843901B0.unk_38);
    func_8431AED8(arg1, &sp6C);
    func_800102A4(&D_843901B0.unk_00, &sp6C, &sp44, &sp36, &sp34);

    var_fa1 = sp44 / (func_84307BD8(arg1) * 40.0f);
    if (var_fa1 >= 0.6f) {
        var_fa1 = 1.0f;
    }

    sp44 *= var_fa1;
    sp44 += D_843901B0.unk_30;

    func_80010354(&D_843901B0.unk_00, &sp60, sp44, D_843901B0.unk_26, D_843901B0.unk_28);
    func_8430C1E4(&sp54, &arg0->unk_60.eye);
    func_8430C070(&sp54, &sp60, &sp40, &sp36, &sp34);
    func_80010354(&sp54, &arg0->unk_60.eye, D_84390240.unk_00->unk_94.z * sp40, sp36, sp34);
    func_8431AED8(arg1, &sp6C);
    func_800102A4(&D_843901B0.unk_00, &sp6C, &sp44, &sp36, &sp34);

    var_fa1 = sp44 / (func_84307BD8(arg1) * 40.0f);
    if (var_fa1 >= 0.6f) {
        var_fa1 = 1;
    }
    sp44 *= var_fa1;
    sp44 += D_843901B0.unk_2C;

    func_80010354(&D_843901B0.unk_00, &sp48, sp44, D_843901B0.unk_20, D_843901B0.unk_22);
    sp48.y += func_84307C30(arg1);
    func_8430C1E4(&sp6C, &arg0->unk_60.at);
    func_8430C070(&sp6C, &sp48, &sp3C, &sp36, &sp34);
    func_80010354(&sp6C, &arg0->unk_60.at, D_84390240.unk_00->unk_94.z * sp3C, sp36, sp34);

    if ((sp40 <= 1.0f) && (sp3C <= 1.0f)) {
        return 1;
    }
    return 0;
}

void func_8431D5C8(UNUSED unk_D_86002F34_00C* arg0) {
    if (arg0) {}
}

void func_8431D5D0(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1, s32 arg2) {
    func_8431BB24(arg0, D_843901B0.unk_00, D_843901B0.unk_0C, D_843901B0.unk_0E, D_843901B0.unk_18, 0.0f);
    if (arg2 == 1) {
        arg0->unk_60.at.y += func_84307C30(arg1);
        func_8431BB80(arg0, arg0->unk_60.at, D_843901B0.unk_12, D_843901B0.unk_14, D_843901B0.unk_1C, 0.0f);
    } else {
        func_8431BB80(arg0, D_843901B0.unk_00, D_843901B0.unk_12, D_843901B0.unk_14, D_843901B0.unk_1C, 0.0f);
    }
}

void func_8431D704(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    D_843901B0.unk_0C = arg0;
    D_843901B0.unk_0E = arg1;
    D_843901B0.unk_20 = arg2;
    D_843901B0.unk_22 = arg3;
}

void func_8431D750(f32 arg0, f32 arg1) {
    D_843901B0.unk_18 = arg0;
    D_843901B0.unk_2C = arg1;
}

void func_8431D764(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    D_843901B0.unk_12 = arg0;
    D_843901B0.unk_14 = arg1;
    D_843901B0.unk_26 = arg2;
    D_843901B0.unk_28 = arg3;
}

void func_8431D7B0(f32 arg0, f32 arg1) {
    D_843901B0.unk_1C = arg0;
    D_843901B0.unk_30 = arg1;
}

void func_8431D7C4(f32 arg0, f32 arg1) {
    D_843901B0.unk_34 = arg0;
    D_843901B0.unk_38 = arg1;
}

void func_8431D7D8(unk_D_86B0C160* arg0, unk_D_86002F34_00C* arg1, unk_D_84390010* arg2) {
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 temp_fv1;
    UNUSED s16 pad;
    s16 sp20;

    func_8431BA5C();
    if (arg0->unk_30 != 200.0f) {
        temp_fv1 = arg0->unk_30;
        D_843901B0.unk_3C = temp_fv1;
        arg1->unk_24.fovy = temp_fv1;
    } else {
        D_843901B0.unk_3C = arg0->unk_30;
    }

    sp34 = func_8431AD20(arg2, arg0->unk_0C, 500.0f);
    sp30 = func_8431AD20(arg2, arg0->unk_20, 500.0f);
    sp2C = func_8431AD20(arg2, arg0->unk_10, 500.0f);
    sp28 = func_8431AD20(arg2, arg0->unk_24, 500.0f);
    sp20 = func_84308190(arg2);

    func_8431D704(arg0->unk_00, sp20 - (arg0->unk_02 * arg2->unk_4B0), arg0->unk_14,
                  func_84308190(arg2) - (arg0->unk_16 * arg2->unk_4B0));
    func_8431D750(sp34, sp30);
    sp20 = func_84308190(arg2);
    func_8431D764(arg0->unk_06, sp20 - (arg0->unk_08 * arg2->unk_4B0), arg0->unk_1A,
                  func_84308190(arg2) - (arg0->unk_1C * arg2->unk_4B0));
    func_8431D7B0(sp2C, sp28);
    func_8431D7C4(arg0->unk_28, arg0->unk_2C);
}

void func_8431D968(unk_D_86B0C160* arg0, unk_D_86002F34_00C* arg1) {
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 tmp;

    func_8431BA5C();

    if (arg0->unk_30 != 200.0f) {
        tmp = arg0->unk_30;
        D_843901B0.unk_3C = tmp;
        arg1->unk_24.fovy = tmp;
    } else {
        D_843901B0.unk_3C = arg0->unk_30;
    }

    sp2C = arg0->unk_0C;
    sp28 = arg0->unk_20;
    sp24 = arg0->unk_10;
    sp20 = arg0->unk_24;

    func_8431D704(arg0->unk_00, arg0->unk_02, arg0->unk_14, arg0->unk_16);
    func_8431D750(sp2C, sp28);
    func_8431D764(arg0->unk_06, arg0->unk_08, arg0->unk_1A, arg0->unk_1C);
    func_8431D7B0(sp24, sp20);
    func_8431D7C4(arg0->unk_28, arg0->unk_2C);
}

s32 func_8431DA38(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1) {
    Vec3f sp64;
    Vec3f sp58;
    Vec3f sp4C;
    Vec3f sp40;
    Vec3f sp34;
    f32 sp30;
    UNUSED s32 pad;
    s16 sp2A;
    s16 sp28;

    func_8430C718(&arg0->unk_24.fovy, 30.0f, 0.06f);
    func_8000E88C(&sp64, arg1->unk_4B0 * -150.0f, 5.0f, 0.0f);
    func_8430C718(&D_84390240.unk_00->unk_94.z, 0.2f, 0.06f);
    func_80010354(&sp64, &sp4C, 100.0f, 0, func_84308190(arg1));
    func_8430C1E4(&sp40, &arg0->unk_60.eye);
    func_8430C070(&sp40, &sp4C, &sp30, &sp2A, &sp28);
    func_80010354(&sp40, &arg0->unk_60.eye, D_84390240.unk_00->unk_94.z * sp30, sp2A, sp28);
    func_80010354(&sp64, &sp34, 0.0f, 0, func_84308190(arg1));
    func_8430C1E4(&sp58, &arg0->unk_60.at);
    func_8430C070(&sp58, &sp34, &sp30, &sp2A, &sp28);

    if (sp30 >= 1.0f) {
        func_80010354(&sp58, &arg0->unk_60.at, D_84390240.unk_00->unk_94.z * sp30, sp2A, sp28);
        return 0;
    }
    return 1;
}

s32 func_8431DBEC(UNUSED unk_D_86002F34_00C* arg0) {
    Vec3f sp2C;
    Vec3f sp20;
    f32 var_fv0;

    func_843081F0(D_84390010[0], &sp2C);
    func_843081F0(D_84390010[1], &sp20);

    var_fv0 = sp2C.y - sp20.y;
    if (sp2C.y < sp20.y) {
        var_fv0 *= -1.0f;
    }

    if (var_fv0 > 35.0f) {
        return 1;
    }
    return 0;
}

void func_8431DC78(unk_D_86002F34_00C* arg0, s32 arg1) {
    UNUSED s32 pad;
    Vec3f sp60;
    Vec3f sp54;
    Vec3f sp48;
    unk_D_84390010* sp40;

    func_8431BA5C();
    arg0->unk_24.fovy = 30.0f;

    sp40 = D_84390010[arg1];
    func_843081F0(sp40, &sp60);
    func_8431BB80(arg0, sp60, 0, sp40->unk_4B0 << 0xE, 100.0f, 0.0f);
    func_843081F0(D_84390010[arg1], &sp54);

    func_843081F0(D_84390010[arg1 == 0], &sp48);
    sp40 = D_84390010[arg1 == 0];
    func_843081F0(sp40, &sp60);

    if (sp48.y < sp54.y) {
        sp60.y = sp54.y * 1.8f;
        func_8431BAB4(sp40, arg0, sp60, 0, 0, 0, 0);
    } else {
        sp60.y = 0.0f;
        func_8431BAB4(sp40, arg0, sp60, 0, 0, 0, 0);
    }
}

s32 func_8431DE30(unk_D_86002F34_00C* arg0, s32 arg1) {
    UNUSED s32 pad;
    Vec3f sp58;
    Vec3f sp4C;
    Vec3f sp40;
    Vec3f sp34;
    f32 sp30;
    s16 sp2E;
    s16 sp2C;

    func_8430C718(&D_84390240.unk_00->unk_94.z, 0.1f, 0.05f);
    func_843081F0(D_84390010[arg1], &sp40);
    func_843081F0(D_84390010[!arg1], &sp34);

    if (sp34.y < sp40.y) {
        func_843081F0(D_84390010[!arg1], &sp4C);
    } else {
        func_843081F0(D_84390010[!arg1], &sp4C);
        sp4C.y *= 1.3f;
    }

    func_8430C1E4(&sp58, &arg0->unk_60.at);
    func_8430C070(&sp58, &sp4C, &sp30, &sp2E, &sp2C);
    func_80010354(&sp58, &arg0->unk_60.at, D_84390240.unk_00->unk_94.z * sp30, sp2E, sp2C);

    if (sp30 <= 1.0f) {
        return 1;
    }
    return 0;
}

void func_8431DF98(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1) {
    func_843081F0(arg1, &D_84390240.unk_00->unk_D0);

    D_84390240.unk_00->unk_D0.x = func_84307DE0(arg1);
    D_84390240.unk_00->unk_D0.z = 0.0f;

    if (arg1->unk_654.unk_38.unk_44.unk_00 == 0x6E) {
        D_843901F0 = func_8431AD20(arg1, 4.5f, 300.0f);
        if (D_843901F0 <= 100.0f) {
            D_843901F0 = 100.0f;
        }

        if (D_84390240.unk_00->unk_D0.y < 20.0f) {
            D_84390240.unk_00->unk_D0.y = 20.0f;
        }
    } else {
        D_843901F0 = func_8431AD20(arg1, 3.5f, 300.0f);
    }

    func_8431BAB4(arg1, arg0, D_84390240.unk_00->unk_D0, 0, func_84308190(arg1), 0.0f, 0.0f);
    func_8431BB80(arg0, D_84390240.unk_00->unk_D0, 0, func_84308190(arg1), D_843901F0, 0.0f);
}

void func_8431E118(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1) {
    f32 sp3C;

    func_843081F0(arg1, &D_84390240.unk_00->unk_D0);
    sp3C = func_8431AD20(arg1, 8.0f, 300.0f);
    func_8431BAB4(arg1, arg0, D_84390240.unk_00->unk_D0, 0, func_84308190(arg1), 0.0f, 0.0f);
    func_8431BBDC(arg0, 0, arg1->unk_4B0 << 0xE, sp3C, 0.0f);
}

void func_8431E1DC(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1, s32 arg2) {
    func_843081F0(arg1, &D_84390240.unk_00->unk_D0);
    D_843901F0 = func_8431AD20(arg1, 0.5f, 100.0f);
    D_843901F4 = func_8431AD20(arg1, 5.0f, 300.0f);
    func_8431BAB4(arg1, arg0, D_84390240.unk_00->unk_D0, 0, func_84308190(arg1), D_843901F0, 0.0f);
    func_8431BB80(arg0, D_84390240.unk_00->unk_D0, 0, func_84308190(arg1) - (arg1->unk_4B0 * 0x31C7), D_843901F4, 0.0f);

    if (arg2 == 1) {
        func_8431B858(arg1, arg0);
    } else {
        func_8431C71C(arg0, arg1);
        func_8431C71C(arg0, arg1);
    }

    func_8431C71C(arg0, arg1);
}

void func_8431E368(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1, s32 arg2) {
    func_843081F0(arg1, &D_84390240.unk_00->unk_D0);
    D_843901F0 = func_8431AD20(arg1, 0.5f, 100.0f);
    D_843901F4 = func_8431AD20(arg1, 5.0f, 300.0f);
    func_8431BAB4(arg1, arg0, D_84390240.unk_00->unk_D0, 0, func_84308190(arg1), D_843901F0, 0.0f);
    func_8431BB80(arg0, D_84390240.unk_00->unk_D0, 0x71C, func_84308190(arg1) - (arg1->unk_4B0 * 0x1555), D_843901F4,
                  0.0f);
    if (arg2 == 1) {
        func_8431B858(arg1, arg0);
    } else {
        func_8431C71C(arg0, arg1);
        func_8431C71C(arg0, arg1);
    }
    func_8431C71C(arg0, arg1);
}

void func_8431E4DC(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1, s32 arg2) {
    func_843081F0(arg1, &D_84390240.unk_00->unk_D0);
    D_843901F0 = func_8431AD20(arg1, 0.5f, 100.0f);
    D_843901F4 = func_8431AD20(arg1, 5.0f, 300.0f);
    func_8431BAB4(arg1, arg0, D_84390240.unk_00->unk_D0, 0, func_84308190(arg1), D_843901F0, 0.0f);
    func_8431BB80(arg0, D_84390240.unk_00->unk_D0, 0xE38, func_84308190(arg1), D_843901F4, 0.0f);
    if (arg2 == 1) {
        func_8431B858(arg1, arg0);
    } else {
        func_8431C71C(arg0, arg1);
        func_8431C71C(arg0, arg1);
    }
    func_8431C71C(arg0, arg1);
}

void func_8431E63C(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1, s32 arg2) {
    UNUSED s32 pad[4];
    s16 sp3E;

    func_843081F0(arg1, &D_84390240.unk_00->unk_D0);
    D_843901F0 = func_8431AD20(arg1, 0.5f, 100.0f);
    D_843901F4 = func_8431AD20(arg1, 5.0f, 300.0f);
    func_8431BAB4(arg1, arg0, D_84390240.unk_00->unk_D0, 0, func_84308190(arg1), D_843901F0, 0.0f);
    sp3E = func_84308190(arg1);
    func_8431BB80(arg0, D_84390240.unk_00->unk_D0, 0, sp3E - (arg1->unk_4B0 * 0x1555), D_843901F4,
                  -func_84308548(arg1) * 0.8);
    if (arg2 == 1) {
        func_8431B858(arg1, arg0);
    } else {
        func_8431C71C(arg0, arg1);
        func_8431C71C(arg0, arg1);
    }
    func_8431C71C(arg0, arg1);
}

void func_8431E7D0(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1, s32 arg2) {
    func_843081F0(arg1, &D_84390240.unk_00->unk_D0);
    D_843901F0 = func_8431AD20(arg1, 3.5f, 300.0f);
    func_8431BAB4(arg1, arg0, D_84390240.unk_00->unk_D0, 0, func_84308190(arg1), 0.0f, 0.0f);
    func_8431BB80(arg0, D_84390240.unk_00->unk_D0, 0, func_84308190(arg1), D_843901F0, 0.0f);
    if (arg2 == 1) {
        func_8431B858(arg1, arg0);
    } else {
        func_8431C71C(arg0, arg1);
        func_8431C71C(arg0, arg1);
    }
    func_8431C71C(arg0, arg1);
}

void func_8431E90C(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1, s32 arg2) {
    func_843081F0(arg1, &D_84390240.unk_00->unk_D0);
    D_843901F0 = func_8431AD20(arg1, 3.5f, 300.0f);
    func_8431BAB4(arg1, arg0, D_84390240.unk_00->unk_D0, 0, func_84308190(arg1), 0.0f, 0.0f);
    func_8431BB80(arg0, D_84390240.unk_00->unk_D0, 0, func_84308190(arg1), D_843901F0, 0.0f);
    if (arg2 == 1) {
        func_8431B858(arg1, arg0);
    }
}

void func_8431EA1C(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1, s32 arg2, s32 arg3) {
    func_843081F0(arg1, &D_843901B0.unk_00);
    func_8431D7D8(&D_843849C0[arg2], arg0, arg1);
    func_8431D5D0(arg0, arg1, 1);
    func_8431D5C8(arg0);
    if (arg3 == 1) {
        func_8431B858(arg1, arg0);
    }
}

void func_8431EAB8(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1) {
    func_8431BA5C();
    func_843081F0(arg1, &D_84390240.unk_00->unk_D0);
    D_843901F0 = func_8431AD20(arg1, 5.0f, 400.0f);
    func_8431BAB4(arg1, arg0, D_84390240.unk_00->unk_D0, 0, arg1->unk_4B0 << 0xE, 0.0f, 0.0f);
    func_8431BB80(arg0, D_84390240.unk_00->unk_D0, 0, arg1->unk_4B0 * 0xE38, D_843901F0, 0.0f);
    func_8431B858(arg1, arg0);
}

void func_8431EBD0(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1) {
    func_8431BA5C();
    func_843081F0(arg1, &D_84390240.unk_00->unk_D0);
    D_843901F0 = func_8431AD20(arg1, 5.0f, 400.0f);
    func_8431BAB4(arg1, arg0, D_84390240.unk_00->unk_D0, 0, arg1->unk_4B0 << 0xE, 0.0f, 0.0f);
    func_8431BB80(arg0, D_84390240.unk_00->unk_D0, 0x1555, arg1->unk_4B0 * 0xE38, D_843901F0, 0.0f);
    func_8431B858(arg1, arg0);
}

void func_8431ECEC(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1) {
    func_843081F0(arg1, &D_84390240.unk_00->unk_D0);
    D_843901F0 = func_8431AD20(arg1, 5.0f, 400.0f);
    func_8431BAB4(arg1, arg0, D_84390240.unk_00->unk_D0, 0, arg1->unk_4B0 << 0xE, 0.0f, 0.0f);
    func_8431BB80(arg0, D_84390240.unk_00->unk_D0, 0, arg1->unk_4B0 * 0xE38, D_843901F0, 2.0f * func_84308548(arg1));
    func_8431B858(arg1, arg0);
}

void func_8431EE08(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1) {
    func_843081F0(arg1, &D_84390240.unk_00->unk_D0);
    D_843901F0 = func_8431AD20(arg1, 5.0f, 400.0f);
    func_8431BAB4(arg1, arg0, D_84390240.unk_00->unk_D0, 0, arg1->unk_4B0 << 0xE, 0.0f, 0.0f);
    func_8431BB80(arg0, D_84390240.unk_00->unk_D0, 0, arg1->unk_4B0 * 0xE38, D_843901F0, -func_84308548(arg1) * 0.8f);
    if (arg0->unk_60.eye.y <= 15.0f) {
        arg0->unk_60.eye.y = 15.0f;
    }
    func_8431B858(arg1, arg0);
}

void func_8431EF54(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1) {
    func_843081F0(arg1, &D_84390240.unk_00->unk_D0);
    D_843901F0 = func_8431AD20(arg1, 3.5f, 300.0f);
    func_8431BAB4(arg1, arg0, D_84390240.unk_00->unk_D0, 0, func_84308190(arg1), 0.0f, 0.0f);
    func_8431BB80(arg0, D_84390240.unk_00->unk_D0, 0, func_84308190(arg1), D_843901F0, 0.0f);
    func_8431B858(arg1, arg0);
}

void func_8431F050(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1, s32 arg2) {
    func_843081F0(arg1, &D_84390240.unk_00->unk_D0);
    D_843901F0 = func_8431AD20(arg1, 3.5f, 300.0f);
    D_843901F4 = func_8431AD20(arg1, 0.5f, 100.0f);
    func_8431BAB4(arg1, arg0, D_84390240.unk_00->unk_D0, 0, func_84308190(arg1), D_843901F4, 0.0f);
    func_8431BB80(arg0, D_84390240.unk_00->unk_D0, 0, func_84308190(arg1) - (arg1->unk_4B0 * 0x1555), D_843901F0, 0.0f);
    if (arg2 == 1) {
        func_8431B858(arg1, arg0);
    }
}

void func_8431F194(unk_D_86002F34_00C* arg0, unk_D_84390010* arg1) {
    func_843081F0(arg1, &D_84390240.unk_00->unk_D0);
    D_843901F0 = func_8431AD20(arg1, 3.5f, 300.0f);
    func_8431BAB4(arg1, arg0, D_84390240.unk_00->unk_D0, 0, func_84308190(arg1), 0.0f, 0.0f);
    func_8431BB80(arg0, D_84390240.unk_00->unk_D0, 0, func_84308190(arg1), D_843901F0, 0.0f);
    func_8431B858(arg1, arg0);
}

void func_8431F290(unk_D_84390010* arg0, unk_D_86002F34_00C* arg1, s32 arg2, s32 arg3) {
    func_8431BA5C();
    switch (arg2) {
        case 0:
            func_8431E7D0(arg1, arg0, arg3);
            break;

        case 1:
            func_8431E90C(arg1, arg0, arg3);
            break;

        case 2:
            func_8431E1DC(arg1, arg0, arg3);
            break;

        case 3:
            func_8431E4DC(arg1, arg0, arg3);
            break;

        case 4:
            func_8431EA1C(arg1, arg0, 0, arg3);
            break;

        case 5:
            func_8431EA1C(arg1, arg0, 1, arg3);
            break;

        case 6:
            func_8431E368(arg1, arg0, arg3);
            break;

        case 7:
            func_8431E63C(arg1, arg0, arg3);
            break;

        case 8:
            func_8431EA1C(arg1, arg0, 2, arg3);
            break;

        case 9:
            func_8431EA1C(arg1, arg0, 3, arg3);
            break;

        case 10:
            func_8431EA1C(arg1, arg0, 4, arg3);
            break;

        case 11:
            func_8431EA1C(arg1, arg0, 5, arg3);
            break;

        default:
            func_8431E1DC(arg1, arg0, arg3);
            break;
    }
}

void func_8431F420(unk_D_84390010* arg0, unk_D_86002F34_00C* arg1, s32 arg2) {
    func_8431BA5C();
    switch (arg2) {
        case 0:
            func_8431E1DC(arg1, arg0, 1);
            break;
        case 1:
            func_8431E368(arg1, arg0, 1);
            break;
        case 2:
            func_8431E63C(arg1, arg0, 1);
            break;
        case 3:
            func_8431E7D0(arg1, arg0, 1);
            break;
        case 4:
            func_8431F050(arg1, arg0, 1);
            break;
        default:
            func_8431E1DC(arg1, arg0, 1);
            break;
    }
}

void func_8431F500(unk_D_84390010* arg0, unk_D_86002F34_00C* arg1, s32 arg2) {
    func_8431BA5C();
    switch (arg2) {
        case 0:
            func_8431EAB8(arg1, arg0);
            break;

        case 1:
            func_8431ECEC(arg1, arg0);
            break;

        case 2:
            func_8431EE08(arg1, arg0);
            break;

        case 3:
            func_8431EF54(arg1, arg0);
            break;

        case 4:
            func_8431EBD0(arg1, arg0);
            break;

        case 5:
            func_8431ECEC(arg1, arg0);
            break;

        case 6:
            func_8431EE08(arg1, arg0);
            break;

        case 7:
            func_8431EF54(arg1, arg0);
            break;

        default:
            func_8431EF54(arg1, arg0);
            break;
    }
}
