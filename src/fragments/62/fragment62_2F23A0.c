#include "fragment62.h"
#include "src/17300.h"
#include "src/18140.h"
#include "src/1C720.h"
#include "src/2E110.h"
#include "src/F420.h"

s32 func_84307AE0(u8 arg0, u8* arg1, s32 arg2) {
    while (arg2--) {
        if (arg0 == *arg1) {
            return 1;
        }
        arg1++;
    }

    return 0;
}

unk_func_80026268_arg0* func_84307B28(unk_D_84390010* arg0) {
    unk_func_80026268_arg0* ptr = &arg0->unk_720->unk_08[arg0->unk_654.unk_2C]->unk_01C[arg0->unk_654.unk_08];

    return ptr;
}

s32 func_84307B60(unk_D_84390010* arg0) {
    unk_func_80026268_arg0* temp_v0 = func_84307B28(arg0);

    if ((arg0->unk_000.unk_01A == 0x19) && (temp_v0->unk_52 & 0x80)) {
        return 1;
    }
    return 0;
}

f32 func_84307BAC(unk_D_84390010* arg0) {
    return D_84390028[func_84307F00(arg0)].unk_08;
}

f32 func_84307BD8(unk_D_84390010* arg0) {
    return D_84390028[func_84307F00(arg0)].unk_00;
}

f32 func_84307C04(unk_D_84390010* arg0) {
    return D_84390028[func_84307F00(arg0)].unk_04;
}

f32 func_84307C30(unk_D_84390010* arg0) {
    return D_84390028[func_84307F00(arg0)].unk_0C;
}

void func_84307C5C(unk_D_84390010* arg0) {
    if (func_84307F00(arg0) == 0) {
        if (arg0->unk_000.unk_01A == 0x82) {
            func_8000E88C(&arg0->unk_000.unk_024, -225.0f, func_84307BAC(arg0), 0.0f);
        } else if ((arg0->unk_000.unk_01A == 3) || (arg0->unk_000.unk_01A == 0x83)) {
            func_8000E88C(&arg0->unk_000.unk_024, -175.0f, func_84307BAC(arg0), 0.0f);
        } else if (arg0->unk_000.unk_01A == 0x5F) {
            func_8000E88C(&arg0->unk_000.unk_024, -225.0f, func_84307BAC(arg0), 7.5000005f);
        } else {
            func_8000E88C(&arg0->unk_000.unk_024, -150.0f, func_84307BAC(arg0), 0.0f);
        }
    } else if ((arg0->unk_000.unk_01A == 0x82) || (arg0->unk_000.unk_01A == 0x5F)) {
        func_8000E88C(&arg0->unk_000.unk_024, 225.0f, func_84307BAC(arg0), 0.0f);
    } else if ((arg0->unk_000.unk_01A == 3) || (arg0->unk_000.unk_01A == 0x83)) {
        func_8000E88C(&arg0->unk_000.unk_024, 175.0f, func_84307BAC(arg0), 0.0f);
    } else {
        func_8000E88C(&arg0->unk_000.unk_024, 150.0f, func_84307BAC(arg0), 0.0f);
    }
}

f32 func_84307DE0(unk_D_84390010* arg0) {
    if (func_84307F00(arg0) == 0) {
        if ((arg0->unk_000.unk_01A == 0x82) || (arg0->unk_000.unk_01A == 0x5F)) {
            return -200.0f;
        }

        if ((arg0->unk_000.unk_01A == 3) || (arg0->unk_000.unk_01A == 0x83)) {
            return -175.0f;
        }
        return -150.0f;
    }

    if ((arg0->unk_000.unk_01A == 0x82) || (arg0->unk_000.unk_01A == 0x5F)) {
        return 200.0f;
    }

    if ((arg0->unk_000.unk_01A == 3) || (arg0->unk_000.unk_01A == 0x83)) {
        return 175.0f;
    }

    return 150.0f;
}

void func_84307EAC(unk_D_84390010* arg0, f32 arg1) {
    arg0->unk_000.unk_030.x = arg1;
    arg0->unk_000.unk_030.y = arg1;
    arg0->unk_000.unk_030.z = arg1;
}

s32 func_84307EC4(unk_D_84390010* arg0) {
    return arg0->unk_720->unk_08[arg0->unk_654.unk_2B]->unk_002;
}

s32 func_84307EE0(unk_D_84390010* arg0) {
    s32 idx = arg0->unk_654.unk_2B == 0;

    return arg0->unk_720->unk_08[idx]->unk_002;
}

s32 func_84307F00(unk_D_84390010* arg0) {
    if (arg0 == D_84390018) {
        return 0;
    }
    return 1;
}

u8 func_84307F24(unk_D_84390010* arg0) {
    UNUSED s32 pad;
    UNUSED s16 pad2;
    s16 sp18 = arg0->unk_654.unk_38.unk_5A - 1;
    unk_D_8438E7B0_A50* ptr = &D_84384570[func_84307F00(arg0)]->unk_000[sp18];

    return ptr->unk_02;
}

u8 func_84307F68(unk_D_84390010* arg0) {
    UNUSED s32 pad;
    UNUSED s16 pad2;
    s16 sp18 = arg0->unk_654.unk_38.unk_5A - 1;
    unk_D_8438E7B0_A50* ptr = &D_84384570[func_84307F00(arg0)]->unk_000[sp18];

    return ptr->unk_03;
}

s16 func_84307FAC(unk_D_84390010* arg0) {
    unk_D_8438E7B0_A50* ptr = &D_84384570[func_84307F00(arg0)]->unk_A80;

    return ptr->unk_02;
}

s32 func_84307FE0(unk_D_84390010* arg0) {
    unk_D_8438E7B0_A50* ptr = &D_84384570[func_84307F00(arg0)]->unk_A80;

    return ptr->unk_03;
}

f32 func_84308014(unk_D_84390010* arg0) {
    return ((func_84307C04(arg0) * 2) / 50.0f) * arg0->unk_000.unk_030.y;
}

f32 func_84308058(unk_D_84390010* arg0) {
    return (func_84307C04(arg0) * 2) / 50.0f;
}

s16 func_8430808C(unk_D_84390010* arg0) {
    return arg0->unk_654.unk_38.unk_5A;
}

void func_84308094(unk_D_84390010* arg0, Vec3f* arg1) {
    arg1->x = ((func_84307BD8(arg0) * 2) / 50.0f) * arg0->unk_000.unk_030.x;
    arg1->y = ((func_84307C04(arg0) * 2) / 50.0f) * arg0->unk_000.unk_030.y;
    arg1->z = ((func_84307BD8(arg0) * 2) / 50.0f) * arg0->unk_000.unk_030.x;
}

void func_84308148(unk_D_84390010* arg0, Vec3s* arg1) {
    arg1->x = arg0->unk_000.unk_01E.x;
    arg1->y = arg0->unk_000.unk_01E.y;
    arg1->z = arg0->unk_000.unk_01E.z;
}

u16 func_84308164(unk_D_84390010* arg0) {
    unk_func_80026268_arg0* ptr = &arg0->unk_724->unk_01C[arg0->unk_654.unk_08];

    return ptr->unk_02;
}

s16 func_84308190(unk_D_84390010* arg0) {
    return arg0->unk_4B0 << 0xE;
}

s16 func_843081A4(s32 arg0) {
    return D_84390010[arg0]->unk_000.unk_01A;
}

s16 func_843081BC(unk_D_84390010* arg0) {
    return arg0->unk_000.unk_01A;
}

u8 func_843081C4(unk_D_84390010* arg0) {
    s32 ret = arg0->unk_000.unk_000.unk_01 & 1;
    return ret;
}

void func_843081D4(unk_D_84390010* arg0, Vec3f* arg1) {
    arg1->x = arg0->unk_000.unk_024.x;
    arg1->y = arg0->unk_000.unk_024.y;
    arg1->z = arg0->unk_000.unk_024.z;
}

void func_843081F0(unk_D_84390010* arg0, Vec3f* arg1) {
    f32 var_fs0 = 0.0f;

    if (func_84307AE0(arg0->unk_000.unk_01A, &D_843845F0, 1) != 0) {
        var_fs0 = func_84308548(arg0) / 1.5f;
    } else if (func_84307AE0(arg0->unk_000.unk_01A, &D_843845F4, 1) != 0) {
        var_fs0 = func_84308548(arg0) * 0.5f;
    } else if ((func_84307AE0(arg0->unk_000.unk_01A, &D_843845F8, 1) != 0) && (arg0->unk_654.unk_34 & 0x200)) {
        var_fs0 = 2.0f * func_84308548(arg0);
    } else if ((func_84307AE0(arg0->unk_000.unk_01A, D_843845FC, 2) != 0) && (arg0->unk_654.unk_34 & 0x200)) {
        var_fs0 = func_84308548(arg0) * 1.5f;
    }

    if (func_84307BAC(arg0) != 0.0f) {
        arg1->x = arg0->unk_000.unk_024.x;
        arg1->y = arg0->unk_000.unk_024.y + var_fs0;
        arg1->z = arg0->unk_000.unk_024.z;
    } else {
        arg1->x = arg0->unk_000.unk_024.x;
        arg1->y = func_84308548(arg0) + arg0->unk_000.unk_024.y + var_fs0;
        arg1->z = arg0->unk_000.unk_024.z;
    }

    if (arg1->y < 0.0f) {
        arg1->y = func_84308548(arg0);
    }
}

void func_843083A0(unk_D_84390010* arg0, Vec3f* arg1) {
    if (func_84307F00(arg0) == 0) {
        if (arg0->unk_000.unk_01A == 0x82) {
            func_8000E88C(arg1, -225.0f, func_84307BAC(arg0), 0.0f);
        } else if ((arg0->unk_000.unk_01A == 3) || (arg0->unk_000.unk_01A == 0x83)) {
            func_8000E88C(arg1, -175.0f, func_84307BAC(arg0), 0.0f);
        } else if (arg0->unk_000.unk_01A == 0x5F) {
            func_8000E88C(arg1, -225.0f, func_84307BAC(arg0), 7.5000005f);
        } else {
            func_8000E88C(arg1, -150.0f, func_84307BAC(arg0), 0.0f);
        }
    } else if ((arg0->unk_000.unk_01A == 0x82) || (arg0->unk_000.unk_01A == 0x5F)) {
        func_8000E88C(arg1, 225.0f, func_84307BAC(arg0), 0.0f);
    } else if ((arg0->unk_000.unk_01A == 3) || (arg0->unk_000.unk_01A == 0x83)) {
        func_8000E88C(arg1, 175.0f, func_84307BAC(arg0), 0.0f);
    } else {
        func_8000E88C(arg1, 150.0f, func_84307BAC(arg0), 0.0f);
    }
}

void func_84308520(unk_D_84390010* arg0, Vec3f* arg1) {
    arg1->x = arg0->unk_4EC.unk_024.x;
    arg1->y = arg0->unk_4EC.unk_024.y + 2.5f;
    arg1->z = arg0->unk_4EC.unk_024.z;
}

f32 func_84308548(unk_D_84390010* arg0) {
    if (arg0->unk_4B4 == 0x10) {
        return func_84307C04(arg0);
    }
    return func_84307C04(arg0) * arg0->unk_000.unk_030.y;
}

f32 func_84308598(unk_D_84390010* arg0) {
    return func_84307BD8(arg0) * arg0->unk_000.unk_030.y;
}

unk_D_86002F58_004_000_004* func_843085C4(unk_D_84390010* arg0, s32 arg1) {
    return arg0->unk_720->unk_14->unk_00[2]->unk_00[arg1];
}

s32 func_843085E0(unk_D_84390010* arg0, UNUSED s32 arg1) {
    return arg0->unk_720->unk_02;
}

void func_843085F0(unk_D_84390010* arg0) {
    func_8002D7C0(NULL, 0, D_843900B8, arg0->unk_654.unk_38.unk_5A - 1);
}

u8* func_8430862C(unk_D_84390010* arg0) {
    return arg0->unk_724->unk_01C[arg0->unk_654.unk_08].unk_30;
}

void func_84308654(unk_D_84390010* arg0, s32 arg1, s32 arg2) {
    arg0->unk_4B4 = arg1;
    arg0->unk_4B8 = arg2;
}

void func_84308660(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    s32 idx;
    unk_D_8438E7B0_A50* sp30;
    unk_D_8438E7B0_A50* sp2C;
    unk_D_8438E7B0_A50* sp28;
    unk_D_84390010_654* sp20 = &arg0->unk_654;

    idx = func_84307F00(arg0);
    sp30 = &D_84384570[idx]->unk_A50;
    idx = func_84307F00(arg0);
    sp2C = &D_84384570[idx]->unk_B00;
    idx = func_84307F00(arg0);
    sp28 = &D_84384570[idx]->unk_AF0;

    if (!(sp20->unk_34 & 0x4002)) {
        if ((func_84301FF0(arg0) == 0) && (arg1->unk_000.unk_040.unk_00 != -1) &&
            (func_80017514(&arg1->unk_000) == 1)) {
            if (sp20->unk_34 & 0x200) {
                func_8001BD04(&arg1->unk_000, sp2C->unk_00);
            } else if ((sp20->unk_34 & 1) && (func_84307AE0(arg1->unk_000.unk_01A, D_84384590, 8) != 0)) {
                func_8001BD04(&arg1->unk_000, sp28->unk_00);
            } else {
                if (arg1->unk_000.unk_01A == 0x84) {
                    idx = func_8430C414(5);
                    func_8001BD04(&arg1->unk_000, idx + 0xE);
                } else {
                    func_8001BD04(&arg1->unk_000, sp30->unk_00);
                }

                if (!(sp20->unk_34 & 1)) {
                    func_84305A74(arg0, 0xA5, 1);
                }
            }

            func_80017464(&arg1->unk_000, 0);
        }
    }
}

void func_843087F8(unk_D_84390010* arg0) {
    s32 idx;
    unk_D_84390010_654* sp24;
    unk_D_8438E7B0_A50* sp34;
    unk_D_8438E7B0_A50* sp30;
    unk_D_8438E7B0_A50* sp2C;

    sp24 = &arg0->unk_654;
    idx = func_84307F00(arg0);
    sp34 = &D_84384570[idx]->unk_A50;
    idx = func_84307F00(arg0);
    sp30 = &D_84384570[idx]->unk_B00;
    idx = func_84307F00(arg0);
    sp2C = &D_84384570[idx]->unk_AF0;

    if (!(sp24->unk_34 & 0x4002) && (func_84301FF0(arg0) == 0) && (arg0->unk_000.unk_040.unk_00 != -1)) {
        func_80017464(&arg0->unk_000, 0);
        if (sp24->unk_34 & 0x200) {
            func_8001BD04(&arg0->unk_000, sp30->unk_00);
        } else if ((sp24->unk_34 & 1) && (func_84307AE0(arg0->unk_000.unk_01A, D_84384590, 8) != 0)) {
            func_8001BD04(&arg0->unk_000, sp2C->unk_00);
        } else {
            if (arg0->unk_000.unk_01A == 0x84) {
                func_8001BD04(&arg0->unk_000, func_8430C414(5) + 0xE);
            } else {
                func_8001BD04(&arg0->unk_000, sp34->unk_00);
            }

            if (!(sp24->unk_34 & 1)) {
                func_84305A74(arg0, 0xA5, 1);
            }
        }
    }
}

void func_8430897C(unk_D_84390010* arg0) {
    unk_D_8438E7B0_A50* sp1C = &D_84384570[func_84307F00(arg0)]->unk_A80;

    if (arg0->unk_000.unk_040.unk_00 != -1) {
        func_80017464(&arg0->unk_000, 0);
        func_8001BD04(&arg0->unk_000, sp1C->unk_00);
    }
}

void func_843089DC(unk_D_84390010* arg0, s32 arg1) {
    arg0->unk_724 = arg0->unk_720->unk_08[arg1];
}

void func_843089F4(unk_D_84390010* arg0, s32 arg1) {
    arg0->unk_654.unk_2B = arg1;
}

void func_843089FC(unk_D_84390010* arg0, Controller* arg1) {
    arg0->unk_654.unk_C8 = arg1;
}

void func_84308A04(unk_D_84390010* arg0, s32 arg1) {
    unk_D_84390010_654* temp_v0 = &arg0->unk_654;

    func_843089DC(arg0, arg1);
    func_843089F4(arg0, arg1);
    temp_v0->unk_08 = temp_v0->unk_18;
    arg0->unk_728.unk_16C = temp_v0->unk_2B;
}

s32 func_84308A4C(unk_D_84390010* arg0) {
    s32 i;
    unk_D_84390010_654* temp_s0;
    unk_func_80026268_arg0* ptr;

    temp_s0 = &arg0->unk_654;

    for (i = 0; i < func_84307EC4(arg0); i++) {
        ptr = &arg0->unk_724->unk_01C[i];
        if ((ptr->unk_05 & 0x20) && (arg0->unk_654.unk_38.unk_16[temp_s0->unk_08 + temp_s0->unk_2B * 3] == 0)) {
            return 1;
        }
    }

    if (arg0->unk_720->unk_01 == 2) {
        for (i = 0; i < func_84307EE0(arg0); i++) {
            ptr = &arg0->unk_720->unk_08[temp_s0->unk_2B == 0]->unk_01C[i];
            if ((ptr->unk_05 & 0x20) &&
                (arg0->unk_654.unk_38.unk_16[temp_s0->unk_08 + (temp_s0->unk_2B == 0) * 3] == 0)) {
                return 1;
            }
        }
    }

    return 0;
}

s32 func_84308BD0(unk_D_84390010* arg0) {
    s32 i;
    unk_D_84390010_654* temp_s0;
    unk_func_80026268_arg0* ptr;

    temp_s0 = &arg0->unk_654;

    for (i = 0; i < func_84307EC4(arg0); i++) {
        ptr = &arg0->unk_724->unk_01C[i];
        if ((ptr->unk_05 & 7) && (arg0->unk_654.unk_38.unk_16[temp_s0->unk_08 + temp_s0->unk_2B * 3] == 0)) {
            return 1;
        }
    }

    if (arg0->unk_720->unk_01 == 2) {
        for (i = 0; i < func_84307EE0(arg0); i++) {
            ptr = &arg0->unk_720->unk_08[temp_s0->unk_2B == 0]->unk_01C[i];
            if ((ptr->unk_05 & 7) && (arg0->unk_654.unk_38.unk_16[temp_s0->unk_08 + (temp_s0->unk_2B == 0) * 3] == 0)) {
                return 1;
            }
        }
    }
    return 0;
}

s32 func_84308D54(unk_D_84390010* arg0) {
    if (arg0->unk_720->unk_01 != 2) {
        return arg0->unk_720->unk_08[0]->unk_002;
    }
    return arg0->unk_720->unk_08[1]->unk_002 + arg0->unk_720->unk_08[0]->unk_002;
}

u8 func_84308D90(unk_D_84390010* arg0) {
    return arg0->unk_000.unk_000.unk_02;
}

s32 func_84308D98(unk_D_84390010* arg0) {
    return arg0->unk_720->unk_08[arg0->unk_728.unk_16C]->unk_001 + 1;
}

void func_84308DB8(unk_D_84390010* arg0, unk_D_84390010* arg1, s32 arg2, s32 arg3) {
    UNUSED s32 pad;
    unk_D_86002F58_004_000_004* sp20 = func_843085C4(arg0, 0);

    func_84307F00(arg0);
    func_8001BCF0(&arg1->unk_000);

    if (arg0 == D_84390010[0]) {
        arg1->unk_000.unk_0A6 = 0;
    } else {
        arg1->unk_000.unk_0A6 = 1;
    }

    func_8001BC34(&arg1->unk_000, 0, arg2, sp20);
    func_84302658(arg0, arg3);
    func_80017464(&arg1->unk_000, 0);
    func_8001BD04(&arg1->unk_000, 0);

    if ((arg1->unk_000.unk_01A == 0x32) || (arg1->unk_000.unk_01A == 0x33)) {
        arg1->unk_000.unk_000.unk_02 &= 0xFFBF;
    } else {
        arg1->unk_000.unk_000.unk_02 |= 0x40;
    }

    if (!(arg0->unk_654.unk_34 & 0x200)) {
        if (arg0 == D_84390010[0]) {
            func_84307C5C(arg0);
            arg1->unk_000.unk_01E.y = 0x4000;
        } else {
            func_84307C5C(arg0);
            arg1->unk_000.unk_01E.y = -0x4000;
        }
    }
}

void func_84308ED4(unk_D_84390010* arg0, unk_D_84390010_728* arg1, s16 arg2) {
    unk_D_86002F58_004_000_004* sp24;

    sp24 = func_843085C4(arg0, 0);
    func_8001BCF0(&arg1->unk_000);

    if (arg0 == D_84390010[0]) {
        arg1->unk_000.unk_0A6 = 0xFF;
    } else {
        arg1->unk_000.unk_0A6 = 0xFF;
    }

    if (arg0 == D_84390010[0]) {
        func_8001BC34(&arg1->unk_000, 1, arg2, sp24);
    } else {
        func_8001BC34(&arg1->unk_000, 2, arg2, sp24);
    }

    func_80017464(&arg1->unk_000, 0);
    func_8001BD04(&arg1->unk_000, 0);
    arg1->unk_000.unk_000.unk_02 &= ~0x40;
}

void func_84308F94(unk_D_84390010* arg0, s16 arg1) {
    s32 i;
    unk_D_86002F58_004_000_004* sp58;
    unk_D_84390010_168* var_s0;

    sp58 = func_843085C4(arg0, 0);

    for (i = 0; i < 2; i++) {
        var_s0 = &arg0->unk_168[i];

        func_8001BCF0(&var_s0->unk_000);
        if (arg0 == D_84390010[0]) {
            var_s0->unk_000.unk_0A6 = 0xFF;
        } else {
            var_s0->unk_000.unk_0A6 = 0xFF;
        }

        func_8001BC34(&var_s0->unk_000, 0, arg1, sp58);
        func_80017464(&var_s0->unk_000, 0);
        func_8001BD04(&var_s0->unk_000, 0);

        var_s0->unk_000.unk_000.unk_02 &= ~0x40;

        if (arg0 == D_84390010[0]) {
            func_8000E88C(&var_s0->unk_000.unk_024, -150.0f, 0.0f, 0.0f);
            var_s0->unk_000.unk_01E.y = 0x4000;
        } else {
            func_8000E88C(&var_s0->unk_000.unk_024, 150.0f, 0.0f, 0.0f);
            var_s0->unk_000.unk_01E.y = -0x4000;
        }

        var_s0->unk_000.unk_000.unk_01 &= ~1;
    }
}

void func_84309110(unk_D_84390010* arg0) {
    if (arg0->unk_654.unk_34 & 1) {
        func_843059C0(arg0, 0xAF, 2);
    } else {
        arg0->unk_654.unk_36 = 0;
        func_80017804(&arg0->unk_000, 0);
        func_8001BD9C(&arg0->unk_000, -1);
    }
}

void func_84309168(unk_D_84390010* arg0) {
    unk_D_84390010_654* ptr = &arg0->unk_654;
    UNUSED s32 pad[3];
    s16 sp26;

    func_843085C4(arg0, 0);
    sp26 = func_843085E0(arg0, 0);
    func_84308DB8(arg0, arg0, sp26, 0);
    func_84308ED4(arg0, &arg0->unk_728, sp26);
    func_84308F94(arg0, sp26);
    func_84309110(arg0);
    ptr->unk_34 &= 0x1800;
    func_8000E88C(&arg0->unk_000.unk_030, 1.0f, 1.0f, 1.0f);
}

void func_8430920C(unk_D_84390010* arg0) {
    unk_D_84390010_654* ptr = &arg0->unk_654;
    UNUSED s32 pad[3];
    s16 sp26;

    func_843085C4(arg0, 0);
    sp26 = func_843085E0(arg0, 0);
    func_84308DB8(arg0, arg0, sp26, 1);
    func_84308ED4(arg0, &arg0->unk_728, sp26);
    func_84308F94(arg0, sp26);
    func_84309110(arg0);
    ptr->unk_2D = 0;
    ptr->unk_34 &= 0x1800;
    func_8000E88C(&arg0->unk_000.unk_030, 1.0f, 1.0f, 1.0f);
}

void func_843092B4(unk_D_84390010* arg0) {
    func_8001BE34(&arg0->unk_000, 0xFF, 0xFF, 0xFF, arg0->unk_654.unk_2E = 0xFF);
    arg0->unk_654.unk_BC = arg0->unk_000.unk_01A;
    func_84308DB8(arg0, arg0, 0x98, 0);
    func_84308F94(arg0, 0x98);
    func_84309110(arg0);
}

void func_84309328(unk_D_84390010* arg0) {
    func_84308DB8(arg0, arg0, 0x98, 0);
    func_84308F94(arg0, 0x98);
    func_84309110(arg0);
}

void func_84309368(unk_D_84390010* arg0) {
    UNUSED s32 pad[3];
    unk_D_84390010_654* ptr = &arg0->unk_654;
    s16 sp2E = func_843085E0(arg0, 0);

    ptr->unk_2E = 0xFF;
    func_8001BE34(&arg0->unk_000, 0xFF, 0xFF, 0xFF, ptr->unk_2E);
    func_84308DB8(arg0, arg0, sp2E, 0);
    func_84308F94(arg0, sp2E);
    func_84309110(arg0);
}
