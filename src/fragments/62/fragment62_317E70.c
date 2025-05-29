#include "fragment62.h"
#include "src/12D80.h"
#include "src/1C720.h"
#include "src/F420.h"
#include "src/fragments/34/fragment34.h"
#include "src/memory.h"

void func_8432D5B0(void) {
    D_8140E724 = main_pool_alloc(sizeof(*D_8140E724) * 300, 0);
    D_8140E720 = main_pool_alloc(sizeof(*D_8140E720) * 300, 0);
    bzero(D_8140E724, sizeof(*D_8140E724) * 300);
    bzero(D_8140E720, sizeof(*D_8140E720) * 300);
    D_8140E730 = 0;
    D_8140E72C = 0;
}

#ifdef NON_MATCHING
unk_D_8140E724* func_8432D61C(void) {
    s32 i;
    s32 var_v0 = D_8140E730;
    unk_D_8140E724* var_v1 = &D_8140E724[var_v0];

    for (i = 0; i < 300; i++) {
        if (var_v1->unk_15 == 0) {
            break;
        }

        var_v0++;

        if (var_v0 >= 300) {
            var_v0 = 0;
            var_v1 = &D_8140E724[0];
        } else {
            var_v1++;
        }
    }

    if (i >= 300) {
        return -1;
    }

    var_v1->unk_15 = 1;

    D_8140E730 = var_v0 + 1;
    if (D_8140E730 >= 300) {
        D_8140E730 = 0;
    }
    return var_v1;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/62/fragment62_317E70/func_8432D61C.s")
#endif

void func_8432D6B0(unk_D_8140E724* arg0) {
    arg0->unk_0E = 0;
    arg0->unk_15 = 0;
    arg0->unk_14 = 0;
    arg0->unk_0C = arg0->unk_0E;
}

void func_8432D6C8(unk_D_8140E720* arg0, Vec3f arg1, Vec3s arg2, s32 arg3, s32 arg4) {
    while (arg0 != NULL) {
        func_81400930(&arg0->unk_68, &arg1);
        func_8140094C(&arg0->unk_94, &arg2);
        arg0->unk_08 = arg3;
        arg0->unk_0C = arg4;
        arg0->unk_10 = 0;
        arg0->unk_14 = 0;
        arg0->unk_CD = 0xFF;

        arg0 = arg0->next;
    }
}

void func_8432D76C(unk_D_8140E720* arg0, unk_D_8140E720* arg1, func_unk_D_8140E724_008 arg2, unk_D_8140E728_01C* arg3,
                   s32 arg4) {
    arg0->unk_08 = arg2;
    arg0->unk_0C = arg3;
    arg0->unk_10 = arg1->unk_10;
    arg0->unk_CF = arg1->unk_CF;
    arg0->unk_CA = arg1->unk_CA;
    arg0->unk_CC = 0x1C;
    arg0->unk_CD = 0xFF;
    arg0->unk_CE = arg1->unk_CE;
    arg0->unk_CB = arg1->unk_CB;
    arg0->unk_74 = arg1->unk_74;

    func_8140BED8(arg0, arg4);

    func_81400930(&arg0->unk_38, &arg1->unk_38);
    func_81400930(&arg0->unk_50, &arg1->unk_50);
    func_81400930(&arg0->unk_68, &arg1->unk_68);
    func_81400930(&arg0->unk_7C, &arg1->unk_7C);
    func_8140094C(&arg0->unk_94, &arg1->unk_94);
    func_8140094C(&arg0->unk_9A, &arg1->unk_9A);

    if (arg1->unk_CA == 4) {
        arg0->unk_CA = 0;
    }
}

void func_8432D844(unk_D_8140E720* arg0, func_unk_D_8140E724_008 arg1, unk_D_8140E728_01C* arg2, s16 arg3) {
    s16 i;
    unk_D_8140E720* temp_v0;

    for (i = 0; i < arg3; i++) {
        temp_v0 = func_81407B3C();
        if ((u32)temp_v0 == -1) {
            break;
        }
        func_8432D76C(temp_v0, arg0, arg1, arg2, i);
    }
}

void func_8432D8E8(unk_D_8140E720* arg0, func_unk_D_8140E724_008 arg1, unk_D_8140E728_01C* arg2, s16 arg3, s16 arg4,
                   s16 arg5) {
    s16 i;
    unk_D_8140E720* temp_v0;

    for (i = 0; i < arg3; i++) {
        temp_v0 = func_81407B3C();
        if ((u32)temp_v0 == -1) {
            break;
        }
        func_8432D76C(temp_v0, arg0, arg1, arg2, i);
        temp_v0->unk_CE = arg5;
        temp_v0->unk_CF = arg4;
    }
}

unk_D_8140E720* func_8432D9BC(s16 arg0, s16 arg1, s32 arg2, f32 arg3) {
    unk_D_8140E720* temp_v0 = func_81407B3C();

    if ((u32)temp_v0 != -1) {
        func_8000E88C(&temp_v0->unk_38, arg0, arg1, 0.0f);
        func_81408AF0(temp_v0);
        func_8000EB70(&temp_v0->unk_94, arg2, arg2, arg2);
        temp_v0->unk_1C = arg3;
        func_814082B4(temp_v0, 0x108);
    }
    return temp_v0;
}

void func_8432DA64(unk_D_8140E720* arg0) {
    if (arg0->unk_14 != NULL) {
        if (func_814082E8(arg0, 0x400) != 0) {
            func_8432CD14(arg0->unk_14);
        } else {
            func_8432CBF8(arg0->unk_14);
        }
    }
}

void func_8432DAB8(unk_D_8140E720* arg0) {
    func_8432DA64(arg0);
    arg0->unk_18 = 0;
    func_81408158(arg0);
    func_81407B04(arg0);
}

void func_8432DAEC(unk_D_8140E720* arg0) {
    Vec3f sp3C;
    Vec3f sp30;
    Vec3s sp28;

    switch (arg0->unk_CC) {
        case 0:
            func_843081D4(arg0->unk_10, &arg0->unk_68);
            break;

        case 1:
            func_843081F0(arg0->unk_10, &arg0->unk_68);
            break;

        case 27:
            func_843081F0(arg0->unk_10, &arg0->unk_68);
            arg0->unk_68.y = 0.0f;
            break;

        case 9:
            func_8432FA54(arg0->unk_10, 0x64, &arg0->unk_68);
            break;

        case 10:
            func_8432FA54(arg0->unk_10, 0x64, &arg0->unk_68);
            arg0->unk_68.y = 0.0f;
            break;

        case 11:
            func_8432FA54(arg0->unk_10, 0x64, &arg0->unk_68);
            func_84308148(arg0->unk_10, &sp28);
            func_84308094(arg0->unk_10, &sp30);
            func_81400D6C(&sp3C, sp30.x * 25.0f, sp28.y);
            func_81400968(&arg0->unk_68, &sp3C);
            break;

        case 12:
            func_8432FA54(arg0->unk_10, 0x64, &arg0->unk_68);
            func_84308148(arg0->unk_10, &sp28);
            func_84308094(arg0->unk_10, &sp30);
            func_81400D6C(&sp3C, sp30.x * 25.0f, sp28.y + 0x8000);
            func_81400968(&arg0->unk_68, &sp3C);
            break;

        case 13:
            func_8432FA54(arg0->unk_10, 0x64, &arg0->unk_68);
            func_84308094(arg0->unk_10, &sp30);
            arg0->unk_68.y += sp30.y * 25.0f;
            break;

        case 14:
            func_8432FA54(arg0->unk_10, 0x64, &arg0->unk_68);
            func_84308094(arg0->unk_10, &sp30);
            arg0->unk_68.y -= sp30.y * 25.0f;
            if (arg0->unk_68.y <= 0.0f) {
                arg0->unk_68.y = 0.0f;
            }
            break;

        case 15:
            func_8432FA54(arg0->unk_10, 0x64, &arg0->unk_68);
            func_84308148(arg0->unk_10, &sp28);
            func_84308094(arg0->unk_10, &sp30);
            func_81400D6C(&sp3C, sp30.x * 25.0f, sp28.y);
            func_81400968(&arg0->unk_68, &sp3C);
            arg0->unk_68.y = 0.0f;
            break;

        case 17:
            func_8432FA54(arg0->unk_10, arg0->unk_CD, &arg0->unk_68);
            break;

        case 19:
            func_8432FA54(arg0->unk_10, arg0->unk_CD, &arg0->unk_68);
            func_84308148(arg0->unk_10, &sp28);
            func_84308094(arg0->unk_10, &sp30);
            func_81400D6C(&sp3C, sp30.x * 25.0f, sp28.y);
            func_81400968(&arg0->unk_68, &sp3C);
            break;

        case 30:
            func_84308520(arg0->unk_10, &arg0->unk_68);
            break;
    }
}

void func_8432DE0C(unk_D_8140E720* arg0) {
    Vec3f sp3C;
    Vec3f sp30;
    Vec3s sp28;

    switch (arg0->unk_CC) {
        case 2:
            func_8432FA54(arg0->unk_10, 0x64, &arg0->unk_68);
            break;

        case 3:
            func_8432FA54(arg0->unk_10, 0x64, &arg0->unk_68);
            arg0->unk_68.y = 0.0f;
            break;

        case 4:
            func_8432FA54(arg0->unk_10, 0x64, &arg0->unk_68);
            func_84308148(arg0->unk_10, &sp28);
            func_84308094(arg0->unk_10, &sp30);
            func_81400D6C(&sp3C, sp30.x * 25.0f, sp28.y);
            func_81400968(&arg0->unk_68, &sp3C);
            break;

        case 5:
            func_8432FA54(arg0->unk_10, 0x64, &arg0->unk_68);
            func_84308148(arg0->unk_10, &sp28);
            func_84308094(arg0->unk_10, &sp30);
            func_81400D6C(&sp3C, sp30.x * 25.0f, sp28.y + 0x8000);
            func_81400968(&arg0->unk_68, &sp3C);
            break;

        case 6:
            func_8432FA54(arg0->unk_10, 0x64, &arg0->unk_68);
            func_84308094(arg0->unk_10, &sp30);
            arg0->unk_68.y += sp30.y * 25.0f;
            break;

        case 7:
            func_8432FA54(arg0->unk_10, 0x64, &arg0->unk_68);
            func_84308094(arg0->unk_10, &sp30);
            arg0->unk_68.y -= sp30.y * 25.0f;
            if (arg0->unk_68.y <= 0.0f) {
                arg0->unk_68.y = 0.0f;
            }
            break;

        case 8:
            func_8432FA54(arg0->unk_10, 0x64, &arg0->unk_68);
            func_84308148(arg0->unk_10, &sp28);
            func_84308094(arg0->unk_10, &sp30);
            func_81400D6C(&sp3C, sp30.x * 25.0f, sp28.y);
            func_81400968(&arg0->unk_68, &sp3C);
            arg0->unk_68.y = 0.0f;
            break;

        case 16:
            func_8432FA54(arg0->unk_10, arg0->unk_CD, &arg0->unk_68);
            break;

        case 18:
            func_8432FA54(arg0->unk_10, arg0->unk_CD, &arg0->unk_68);
            break;

        case 29:
            func_84308520(arg0->unk_10, &arg0->unk_68);
            break;
    }
}

void func_8432E0A4(unk_D_8140E720* arg0) {
    if ((arg0->unk_10 == NULL) || (func_814082E8(arg0, 0x108) != 0)) {
        D_8140E628.unk_00.x = 1.0f;
        D_8140E628.unk_00.y = 1.0f;
        D_8140E628.unk_00.z = 1.0f;
    } else if (func_81408308(arg0, 0x800) != 0) {
        D_8140E628.unk_00.x = func_8432FC94(arg0->unk_10);
        D_8140E628.unk_00.y = func_8432FC94(arg0->unk_10);
        D_8140E628.unk_00.z = func_8432FC94(arg0->unk_10);
    }
}

void func_8432E144(unk_D_8140E720* arg0) {
    if (func_81408180(arg0) != 0) {
        func_8432DAB8(arg0);
    } else {
        func_81408AF0(arg0);
    }
}

void func_8432E184(void) {
    s32 i;
    unk_D_8140E720* var_s0 = D_8140E720;

    for (i = 0; i < 300; i++, var_s0++) {
        if (var_s0->unk_D0 != 0) {
            func_8432DE0C(var_s0);
            func_8432E0A4(var_s0);
            var_s0->unk_08(var_s0);
            func_8432E144(var_s0);
        }
    }
}

void func_8432E200(unk_D_8140E720* arg0, unk_D_84390010* arg1, unk_D_8140E724* arg2, s16 arg3) {
    if ((u32)arg0 == -1) {
        return;
    }

    if (1) {}
    if (1) {}
    if (1) {}
    if (1) {}
    if (1) {}
    if (1) {}

    while (arg0 != NULL) {
        arg0->unk_10 = arg1;
        arg0->unk_AC = arg3++;
        arg0->unk_08 = arg2->unk_00;
        arg0->unk_0C = arg2->unk_04;
        arg0->unk_CD = arg2->unk_19;
        arg0->unk_CE = arg2->unk_1A;
        arg0->unk_AA = arg2->unk_12;
        arg0->unk_CF = arg2->unk_1B;
        arg0->unk_CA = arg2->unk_17;
        arg0->unk_CC = arg2->unk_16;
        arg0->unk_CB = arg2->unk_18;
        arg0->unk_A6 = arg2->unk_10;

        if (arg1 != NULL) {
            func_8432DAEC(arg0);
            func_84308148(arg0->unk_10, &arg0->unk_94);
        }

        if ((arg2->unk_16 & 0xFFFFu) == 0x12) {
            arg0->unk_A6 = arg2->unk_10 * arg3;
        }

        arg0 = arg0->next;
    }
}

void func_8432E30C(unk_D_8140E724* arg0, s32 arg1) {
    s16 i;
    s16 var_s2;
    unk_D_8140E728_01C* temp_a2 = arg0->unk_04;
    unk_D_8140E728_01C_004_1* temp_a3 = arg0->unk_04->unk_04.a;
    unk_D_84390010* tmp08 = arg0->unk_08;
    s16 tmp12 = arg0->unk_12;

    switch (arg1) {
        case 0:
            var_s2 = tmp12;
            break;

        case 1:
            var_s2 = arg0->unk_10 / tmp12;
            arg0->unk_10 = tmp12;
            break;
    }

    if ((temp_a2->unk_00 == 1) && (temp_a3->unk_00 == 1)) {
        func_8432E200(func_81407B5C(var_s2), tmp08, arg0, 0);
        return;
    }

    for (i = 0; i < var_s2; i++) {
        func_8432E200(func_81407B3C(), tmp08, arg0, i);
    }
}

void func_8432E434(unk_D_8140E724* arg0) {
    func_8432E30C(arg0, 0);
}

void func_8432E454(unk_D_8140E724* arg0) {
    func_8432E30C(arg0, 1);
}

void func_8432E474(unk_D_8140E724* arg0) {
    UNUSED s32 pad;
    unk_D_84390010* sp18 = arg0->unk_08;

    func_8432E200(func_81407B3C(), sp18, arg0, 0);
}

void func_8432E4B0(unk_D_8140E724* arg0) {
    switch (arg0->unk_16) {
        case 18:
            func_8432E454(arg0);
            break;

        case 22:
            func_8432E200(func_8432D9BC(0xA0, 0x78, 0, 1.0f), 0, arg0, 0);
            break;

        case 24:
            func_8432E200(func_8432D9BC(0, 0, 0, 1.0f), 0, arg0, 0);
            break;

        case 23:
            func_8432F9A8(arg0->unk_19);
            break;

        case 25:
            func_8432C768(arg0->unk_19);
            break;

        case 26:
            func_8432E474(arg0);
            break;

        default:
            func_8432E434(arg0);
            break;
    }
}

void func_8432E5A4(void) {
    s32 i;
    unk_D_8140E724* var_s0 = D_8140E724;

    for (i = 0; i < 300; i++, var_s0++) {
        if (var_s0->unk_15 != 0) {
            var_s0->unk_0E--;
            if (var_s0->unk_0E <= 0) {
                if (var_s0->unk_14 >= 0) {
                    func_8432E4B0(var_s0);
                    if (var_s0->unk_14 != 0x7F) {
                        var_s0->unk_14--;
                    }

                    if (var_s0->unk_14 <= 0) {
                        func_8432D6B0(var_s0);
                    } else {
                        var_s0->unk_0E = var_s0->unk_0C;
                    }
                } else if (var_s0->unk_14 == -1) {
                    var_s0->unk_0E = var_s0->unk_0C;
                    func_8432E4B0(var_s0);
                }
            }
        }
    }
}

void func_8432E68C(void) {
    func_8432E5A4();
    func_8432E184();
}

void func_8432E6B4(void) {
    s32 i;
    unk_D_8140E724* var_s0 = D_8140E724;
    unk_D_8140E720* var_s2 = D_8140E720;

    func_8432EB14();

    for (i = 0; i < 300; i++, var_s0++) {
        if (var_s0->unk_15 != 0) {
            if ((var_s0->unk_17 != 4) && (var_s0->unk_17 != 7)) {
                func_8432D6B0(var_s0);
            }
        }
    }

    for (i = 0; i < 300; i++, var_s2++) {
        if (var_s2->unk_D0 != 0) {
            if ((var_s2->unk_CA != 4) && (var_s2->unk_CA != 7)) {
                func_8432DAB8(var_s2);
            }
        }
    }
}

void func_8432E784(void) {
    s32 i;
    unk_D_8140E724* var_s0 = D_8140E724;
    unk_D_8140E720* var_s2 = D_8140E720;

    for (i = 0; i < 300; i++, var_s0++) {
        if ((var_s0->unk_15 != 0) && (var_s0->unk_17 != 4)) {
            func_8432D6B0(var_s0);
        }
    }

    for (i = 0; i < 300; i++, var_s2++) {
        if ((var_s2->unk_D0 != 0) && (var_s2->unk_CA != 4)) {
            func_8432DAB8(var_s2);
        }
    }

    func_8001BE34(&D_84390010[0]->unk_000, 0xFF, 0xFF, 0xFF, 0);
    func_8001BE34(&D_84390010[1]->unk_000, 0xFF, 0xFF, 0xFF, 0);
    func_8001BE78(&D_84390010[0]->unk_000, 0xFF);
    func_8001BE78(&D_84390010[1]->unk_000, 0xFF);

    D_8439037E = 0xFF;
    D_8439037C = D_8439037E;
    D_8439037A = D_8439037C;
}

s32 func_8432E8B0(void) {
    return D_84390340;
}

void func_8432E8BC(void) {
    if (D_843C4DA4 != 0) {
        D_84390340 = 1;
    } else {
        D_84390340 = 0;
    }
}

void func_8432E8EC(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if (D_84390300[i] != NULL) {
            D_84390300[i] = NULL;
            D_84390320[i] = NULL;
        }
    }

    D_84390340 = 0;
}

s32 func_8432E97C(void) {
    s32 var_v1 = 0;

    if (D_843902F8 == 0) {
        var_v1 = 1;
    }
    return var_v1;
}

void func_8432E99C(void) {
    D_843902F8 = 1;
}

void func_8432E9AC(void) {
    D_843902F8 = 0;
}

void func_8432E9B8(void) {
    func_8432E99C();
}

void func_8432E9D8(s32 arg0) {
    func_8432EB14();
    switch (arg0) {
        case 1:
            func_8432E6B4();
            if (func_8432E97C() != 0) {
                func_8432E8EC();
            }
            break;

        case 2:
            func_8432E784();
            func_8432E8EC();
            func_8432E9AC();
            func_84359380();
            break;
    }
}

void func_8432EA60(u8 arg0, unk_D_84390010* arg1) {
    s32 i;
    unk_D_8140E720* var_s0 = D_8140E720;

    for (i = 0; i < 300; i++, var_s0++) {
        if ((var_s0->unk_D0 != 0) && (var_s0->unk_CA == 4) && (var_s0->unk_CB == arg0) && (arg1 == var_s0->unk_10)) {
            func_814082B4(var_s0, 0x1000);
            func_814081BC(var_s0);
        }
    }
}

void func_8432EB14(void) {
    D_843902A8 = 0;
}

void func_8432EB20(s32 arg0) {
    D_843902A8 = arg0;
}

void func_8432EB2C(s32 arg0) {
    D_843902A8 += arg0;
}

void func_8432EB44(void) {
    func_8432EB14();
}

unk_D_8140E724* func_8432EB64(s32 arg0, s32 arg1, s8 arg2, func_unk_D_8140E724 arg3, unk_D_8140E728_01C* arg4,
                              unk_D_84390010* arg5, s16 arg6, s16 arg7, u8 arg8, u8 arg9, u8 argA, u8 argB) {
    unk_D_8140E724* sp1C = func_8432D61C();

    if ((u32)sp1C != -1) {
        sp1C->unk_0E = arg0 + D_843902A8;
        sp1C->unk_0C = arg1;
        sp1C->unk_14 = arg2;
        sp1C->unk_00 = arg3;
        sp1C->unk_04 = arg4;
        sp1C->unk_08 = arg5;
        sp1C->unk_16 = arg8;
        sp1C->unk_10 = arg6;
        sp1C->unk_12 = arg7;
        sp1C->unk_19 = arg9;
        sp1C->unk_1A = argB;
        sp1C->unk_1B = argA;
        sp1C->unk_17 = func_8432C518();
        sp1C->unk_18 = func_8432C538();
    }
    return sp1C;
}

unk_D_8140E724* func_8432EC28(s32 arg0, func_unk_D_8140E724 arg1, unk_D_8140E728_01C* arg2, s16 arg3, s16 arg4, u8 arg5,
                              u8 arg6, u8 arg7, u8 arg8) {
    return func_8432EB64(arg0, 0, 1, arg1, arg2, D_843902E8, arg3, arg4, arg5, arg6, arg7, arg8);
}

unk_D_8140E724* func_8432ECA0(s32 arg0, s32 arg1, s8 arg2, func_unk_D_8140E724 arg3, unk_D_8140E728_01C* arg4, s16 arg5,
                              s16 arg6, u8 arg7, u8 arg8, u8 arg9, u8 argA) {
    return func_8432EB64(arg0, arg1, arg2, arg3, arg4, D_843902E8, arg5, arg6, arg7, arg8, arg9, argA);
}

unk_D_8140E724* func_8432ED0C(s32 arg0, s16 arg1, u8 arg2) {
    return func_8432EB64(arg0, 0, 1, func_84331DC8, &D_8140E460, NULL, 0, arg1, 0x16, 0, arg2, 0);
}

unk_D_8140E724* func_8432ED74(s32 arg0, s16 arg1, s16 arg2, u8 arg3, u8 arg4) {
    return func_8432EB64(arg0, 0, 1, func_84332CD0, &D_843861D0[37], NULL, arg1, arg2, 0x16, arg4, arg3, 0);
}

unk_D_8140E724* func_8432EDE8(s32 arg0, s16 arg1, s16 arg2, u8 arg3) {
    return func_8432EB64(arg0, 0, 1, func_84332DB0, &D_843861D0[37], NULL, arg1, arg2, 0x16, 0xFF, arg3, 0);
}

unk_D_8140E724* func_8432EE5C(s32 arg0, s16 arg1, s16 arg2, u8 arg3, u8 arg4) {
    return func_8432EB64(arg0, 0, 1, func_84332DB0, &D_843861D0[37], NULL, arg1, arg2, 0x16, arg4, arg3, 0);
}

unk_D_8140E724* func_8432EED0(s32 arg0, s32 arg1, s8 arg2, s16 arg3, s16 arg4, u8 arg5, u8 arg6) {
    return func_8432EB64(arg0, arg1, arg2, func_84332DB0, &D_843861D0[37], NULL, arg3, arg4, 0x16, arg6, arg5, 0);
}

unk_D_8140E724* func_8432EF40(s32 arg0, s16 arg1, s16 arg2, u8 arg3) {
    return func_8432EB64(arg0, 0, 1, func_84332E6C, &D_843861D0[37], NULL, arg1, arg2, 0x16, 0xFF, arg3, 0);
}

unk_D_8140E724* func_8432EFB4(s32 arg0, s16 arg1, s16 arg2, u8 arg3, u8 arg4) {
    return func_8432EB64(arg0, 0, 1, func_84332E6C, &D_843861D0[37], NULL, arg1, arg2, 0x16, arg4, arg3, 0);
}

unk_D_8140E724* func_8432F028(s32 arg0, s32 arg1, s8 arg2, s16 arg3, s16 arg4, u8 arg5, u8 arg6) {
    return func_8432EB64(arg0, arg1, arg2, func_84332E6C, &D_843861D0[37], NULL, arg3, arg4, 0x16, arg6, arg5, 0);
}

unk_D_8140E724* func_8432F098(s32 arg0, s16 arg1, u8 arg2) {
    return func_8432EB64(arg0, 0, 1, func_84332F30, &D_843861D0[37], NULL, arg1, 0, 0x16, 0xFF, arg2, 0);
}

unk_D_8140E724* func_8432F104(s32 arg0, s16 arg1, u8 arg2, u8 arg3) {
    return func_8432EB64(arg0, 0, 1, func_84332F30, &D_843861D0[37], NULL, arg1, 0, 0x16, arg3, arg2, 0);
}

unk_D_8140E724* func_8432F174(s32 arg0, s32 arg1, s8 arg2, s16 arg3, u8 arg4, u8 arg5) {
    return func_8432EB64(arg0, arg1, arg2, func_84332F30, &D_843861D0[37], NULL, arg3, 0, 0x16, arg5, arg4, 0);
}

unk_D_8140E724* func_8432F1E0(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    return func_8432EB64(arg0, 0, 1, func_84332FD0, &D_843861D0[37], NULL, arg1, arg2, 0x16, arg4, arg3, 0);
}

unk_D_8140E724* func_8432F254(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    return func_8432EB64(arg0, 0, 1, func_843330A0, &D_843861D0[37], NULL, arg1, arg2, 0x16, arg4, arg3, 0);
}

unk_D_8140E724* func_8432F2C8(s32 arg0, u8 arg1, s16 arg2, s16 arg3, s16 arg4) {
    return func_8432EB64(arg0, 0, 1, func_84331EAC, &D_8140E460, D_843902E8, arg2, arg4, 0x1A, arg3, arg1, 0);
}

unk_D_8140E724* func_8432F344(s32 arg0, s16 arg1, u8 arg2, s16 arg3, s16 arg4, s16 arg5) {
    return func_8432EB64(arg0, 0, 1, func_84331FAC, &D_8140E460, D_843902E8, arg1, arg5, 0x1A, arg4, arg2, arg3);
}

unk_D_8140E724* func_8432F3C4(s32 arg0, s16 arg1, u8 arg2, s16 arg3, s16 arg4) {
    return func_8432EB64(arg0, 0, 1, func_843320A4, &D_8140E460, D_843902E8, arg1, arg4, 0x1A, 0, arg2, arg3);
}

unk_D_8140E724* func_8432F440(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    return func_8432EB64(arg0, 0, 1, func_843321BC, &D_8140E460, D_843902E8, arg4, arg3, 0x1A, arg2, arg1, 0);
}

unk_D_8140E724* func_8432F4BC(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    return func_8432EB64(arg0, 0, 1, func_843321BC, &D_8140E460, D_843902E8, arg4, arg3, 0x1A, arg2, arg1, 0);
}

unk_D_8140E724* func_8432F538(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5) {
    return func_8432EB64(arg0, 0, 1, func_843323BC, &D_8140E460, D_843902E8, arg4, arg3, 0x1A, arg2, arg1, arg5);
}

unk_D_8140E724* func_8432F5B8(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5) {
    return func_8432EB64(arg0, 0, 1, func_843323BC, &D_8140E460, D_843902E8, arg4, arg3, 0x1A, arg2, arg1, arg5);
}

unk_D_8140E724* func_8432F638(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5) {
    return func_8432EB64(arg0, 0, 1, func_84332604, &D_8140E460, D_843902E8, arg4, arg3, 0x1A, arg2, arg1, arg5);
}

unk_D_8140E724* func_8432F6B8(s32 arg0, s16 arg1, u8 arg2) {
    return func_8432EB64(arg0, 0, 1, func_843327B8, &D_8140E460, D_843902E8, 0, arg1, 0x1A, arg2, 0, 0);
}

unk_D_8140E724* func_8432F728(s32 arg0, s16 arg1, s16 arg2, u8 arg3) {
    return func_8432EB64(arg0, 0, 1, func_84332964, &D_8140E460, D_843902E8, arg1, arg2, 0x1A, arg3, 0, 0);
}

unk_D_8140E724* func_8432F7A0(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    return func_8432EB64(arg0, 0, 1, func_84332AFC, &D_8140E460, D_843902E8, arg1, arg3, 0x1A, arg2, 0, 0);
}

unk_D_8140E724* func_8432F818(s32 arg0) {
    return func_8432EB64(arg0, 0, 1, func_84332AFC, &D_8140E460, D_843902E8, 0xFF, 0xFF, 0x1A, 0xFF, 0, 0);
}

unk_D_8140E724* func_8432F884(s32 arg0) {
    return func_8432EB64(arg0, 0, 1, func_84332AFC, &D_8140E460, D_843902E8, 0, 0xFF, 0x1A, 0, 0, 0);
}

unk_D_8140E724* func_8432F8E8(s32 arg0, u8 arg1) {
    return func_8432EB64(arg0, 0, 1, NULL, NULL, 0, 0, 0, 0x17, arg1, 0, 0);
}

unk_D_8140E724* func_8432F93C(s32 arg0, u8 arg1) {
    return func_8432EB64(arg0, 0, 1, NULL, NULL, D_843902E8, 0, 0, 0x19, arg1, 0, 0);
}

void func_8432F998(void) {
}

void func_8432F9A0(void) {
}

void func_8432F9A8(s32 arg0) {
    D_843902F4 = arg0;
}

void func_8432F9B4(void) {
    D_843902F4 = 0;
}

s32 func_8432F9C0(void) {
    return D_843902F4;
}

s32 func_8432F9CC(s32 arg0) {
    s32 sp1C = 0;

    if (func_843081BC(D_843902E8) == arg0) {
        sp1C = 1;
    }
    return sp1C;
}

void func_8432FA0C(void) {
    func_843081BC(D_843902EC);
}

void func_8432FA30(void) {
    func_843081BC(D_843902F0);
}

void func_8432FA54(unk_D_84390010* arg0, s16 arg1, Vec3f* arg2) {
    s32 sp24 = 0;

    if (arg0 != NULL) {
        if (arg1 == 0x64) {
            if (func_80015390(&arg0->unk_000, 0xA, arg2) != NULL) {
                sp24 = 1;
            } else if (func_80015390(&arg0->unk_000, 0x64, arg2) != NULL) {
                sp24 = 2;
            }
        } else {
            if (func_80015390(&arg0->unk_000, arg1, arg2) == NULL) {
                if (func_80015390(&arg0->unk_000, 0x64, arg2) != NULL) {
                    sp24 = 3;
                }
            } else {
                sp24 = 4;
            }
        }
    }

    if (sp24 == 0) {
        arg2->x = 0.0f;
        arg2->y = 0.0f;
        arg2->z = 0.0f;
    }
}

void func_8432FB38(Vec3f* arg0) {
    func_8432FA54(D_843902E8, 0x64, arg0);
}

void func_8432FB64(Vec3f* arg0) {
    func_8432FA54(D_843902EC, 0x64, arg0);
}

void func_8432FB90(Vec3f* arg0) {
    func_8432FA54(D_843902F0, 0x64, arg0);
}

void func_8432FBBC(Vec3f* arg0) {
    if (D_843902E4 == 0xFF) {
        func_843081F0(D_843902EC, arg0);
    } else {
        func_8432FA54(D_843902EC, D_843902E2, arg0);
    }
}

void func_8432FC14(Vec3f* arg0) {
    func_8432FA54(D_843902F0, 9, arg0);
}

void func_8432FC40(unk_D_84390010* arg0, Vec3f* arg1) {
    func_84308094(arg0, arg1);
}

f32 func_8432FC60(unk_D_84390010* arg0) {
    f32 ret = D_80075E40[arg0->unk_000.unk_01A] * 0.01f;

    return ret;
}

f32 func_8432FC94(unk_D_84390010* arg0) {
    return func_8432FC60(arg0);
}

void func_8432FCB4(unk_D_84390010* arg0) {
    func_8432FC60(arg0);
}

void func_8432FCD4(void) {
    func_8432FC94(D_843902EC);
}

void func_8432FCF8(void) {
    func_8432FCB4(D_843902EC);
}

void func_8432FD1C(void) {
    func_8432FC94(D_843902F0);
}

void func_8432FD40(void) {
    func_8432FCB4(D_843902F0);
}

unk_D_86002F34_00C* func_8432FD64(void) {
    return D_8140E628.unk_0C;
}

unk_D_8140E720* func_8432FD70(Vec3f arg0, u8 arg1) {
    unk_D_8140E720* sp1C = func_81407B3C();

    if ((u32)sp1C != -1) {
        func_81400930(&sp1C->unk_68, &arg0);
        func_8433010C(sp1C, arg1);
        sp1C->unk_10 = D_843902EC;
        sp1C->unk_14 = NULL;
        sp1C->unk_CD = 0xFF;
        sp1C->unk_CC = 0x15;
        sp1C->unk_CA = 0;
    }
    return sp1C;
}

void func_8432FDF0(unk_D_8140E720* arg0, Vec3f arg1) {
    if ((u32)arg0 != -1) {
        arg0->unk_68.x = arg1.x;
        arg0->unk_68.y = arg1.y;
        arg0->unk_68.z = arg1.z;
    }
}

void func_8432FE24(unk_D_8140E720* arg0) {
    func_81408150(arg0);
}

s16 func_8432FE44(unk_D_8140E720* arg0) {
    Vec3f sp24;
    s16 ret;

    func_843081F0(D_843902F0, &sp24);
    ret = func_814011E0(arg0->unk_68, sp24) + arg0->unk_94.y;
    return ret;
}

void func_8432FEC4(unk_D_8140E720* arg0) {
    D_8439037A = arg0->prim_r;
    D_8439037C = arg0->prim_g;
    D_8439037E = arg0->prim_b;
}

void func_8432FEEC(unk_D_8140E720* arg0) {
    arg0->prim_r = D_8439037A;
    arg0->prim_g = D_8439037C;
    arg0->prim_b = D_8439037E;
}
