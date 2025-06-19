#include "fragment62.h"
#include "src/math_util.h"

void func_84337AF0(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C038(arg0);
    s16 sp24 = func_8140C058(arg0);

    func_8140B938(arg0, (func_81400A78(0xA) * 0.01f) + 0.05f);
    func_8140AF24(arg0, (func_81400A78(0x1E) * 0.1f) + 1.0f);
    func_8140A3D8(arg0, func_81400A78(0x10000));
    func_8140AD8C(arg0, 5.0f);
    func_8140ADA4(arg0, func_81400A78(0xF) + 5.0f);
    func_8140BF4C(arg0, func_81400ADC(0x1000, 0x800));
    func_8140D5A0(arg0, sp24);
    func_8140BCA8(arg0, sp26);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84337C6C(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84337AF0(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
                func_8140BCA8(arg0, 0xA);
            }
            break;

        case 3:
            if (func_8140BDAC(arg0) != 0) {
                func_814084D8(arg0, 0, 3, 1, 1, 0);
            }
            break;

        case 4:
            func_81408158(arg0);
            break;
    }

    if (func_81408368(arg0) != 0) {
        func_81409C6C(arg0);
        func_8140ADBC(arg0, arg0->unk_78, 0.5f);
        func_8140B7C8(arg0, arg0->unk_74, arg0->unk_AE);
    }
}

void func_84337D70(unk_D_8140E720* arg0, s16 arg1) {
    s16 sp2E = func_8140C038(arg0);

    func_8140BECC(arg0, 7);
    func_8140B938(arg0, 0.1f);
    func_8140A52C(arg0, func_81400B00(0xC00), func_81400B00(0x1000), 0);
    func_8140D78C(arg0);
    func_8140AD8C(arg0, (func_81400A78(6) * 0.5f) + 4.0f);
    func_8140BCA8(arg0, sp2E * 2);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84337E64(unk_D_8140E720* arg0) {
    s16 temp_a1 = func_8140C058(arg0);

    switch (arg0->unk_B2) {
        case 1:
            func_84337D70(arg0, temp_a1);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_8140BCA8(arg0, func_81400A78(0xA) + 0x19);
                func_81408328(arg0);
            }
            break;

        case 3:
            func_8140B98C(arg0, 0.15f, 0.01f);
            func_81409D0C(arg0);
            if ((func_8140BDAC(arg0) != 0) && (func_8140BC2C(arg0, 0x20, 0x20) != 0)) {
                func_814081BC(arg0);
            }
            break;

        case 4:
            func_81408158(arg0);
            break;
    }
}

void func_84337F6C(unk_D_8140E720* arg0) {
    UNUSED s32 pad[3];
    s16 sp22 = func_8140C038(arg0);

    func_8140C058(arg0);
    func_8140B938(arg0, 0.05f);
    func_8140959C(arg0, 4, 2, 2);
    func_8140A578(arg0, func_81400B28(0x200, 0xE00));
    func_8140A3C4(arg0, func_81400A78(0x1000) + 0x100);
    func_8140BFEC(arg0, -0x1800 - func_81400A78(0x1000));
    func_8140A594(arg0, func_81400B00(0x3000));
    func_8140AD8C(arg0, (func_81400A78(0xF) * 0.1f) + 1.0f);
    func_8140D78C(arg0);
    func_8140BCA8(arg0, sp22 * 2);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_843380B0(unk_D_8140E720* arg0) {
    if (arg0->unk_B8 == 1) {
        func_8140A7DC(arg0, arg0->unk_B0, arg0->unk_9A.x);
        func_81409D0C(arg0);
    }
}

void func_843380F0(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84337F6C(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408A1C(arg0);
                func_81408328(arg0);
                func_8140BCA8(arg0, func_81400A78(0xA) + 8);
            }
            break;

        case 3:
            func_8140B98C(arg0, 0.15f, 0.02f);
            if (func_8140BDAC(arg0) != 0) {
                func_814084D8(arg0, 0, 3, 1, 1, 0);
            }
            break;

        case 4:
            func_81408150(arg0);
            break;
    }

    if (func_81408368(arg0) != 0) {
        func_843380B0(arg0);
    }
}

void func_84338204(unk_D_8140E720* arg0) {
    s16 sp56 = func_8140C038(arg0);
    f32 var_fa0;
    UNUSED s32 pad[2];
    Vec3f sp3C;
    Vec3f sp30;
    s16 sp2E;

    func_8140BECC(arg0, 7);
    func_8140B938(arg0, 0.1f);
    func_8140B95C(arg0, 0.2f);
    func_8140B974(arg0, 0.02f);
    func_8432FBBC(&sp3C);
    func_8432FC14(&sp30);
    var_fa0 = sp30.x - sp3C.x;
    if (var_fa0 <= 0.0f) {
        var_fa0 = -var_fa0;
    }
    sp2E = -MathUtil_Atan2s(var_fa0, sp30.y - sp3C.y);
    func_8140A52C(arg0, sp2E + func_81400B00(0x800), func_81400B00(0x800), 0);
    func_8140959C(arg0, 4, 2, 2);
    func_8140D78C(arg0);
    func_8140AD8C(arg0, (func_81400A78(6) * 0.5f) + 5.0f);
    func_8140BCA8(arg0, sp56 * 2);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_8433837C(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84338204(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_8140BCA8(arg0, func_81400A78(0x14) + 0xF);
                func_81408328(arg0);
            }
            break;

        case 3:
            func_8140BA1C(arg0);
            func_81409D0C(arg0);
            if (func_8140BDAC(arg0) != 0) {
                func_814084D8(arg0, 0, 3, 1, 1, 0);
            }
            break;

        case 4:
            func_81408158(arg0);
            break;
    }
}

void func_84338468(unk_D_8140E720* arg0) {
    UNUSED s32 pad[2];
    f32 temp_fv0;
    Vec3f sp40;
    Vec3f sp34;
    s16 sp32;
    s16 sp30 = func_8140C038(arg0);
    s16 sp2E = func_8140C040(arg0);

    func_8140BECC(arg0, 7);
    func_8140B938(arg0, 0.1f);
    func_8432FBBC(&sp40);
    func_8432FC14(&sp34);

    temp_fv0 = sp34.x - sp40.x;
    if (temp_fv0 <= 0.0f) {
        temp_fv0 = -temp_fv0;
    }

    sp32 = MathUtil_Atan2s(temp_fv0, sp34.y - sp40.y) * -1;
    func_8140A594(arg0, func_81400B00(0x400));

    switch (sp2E) {
        case 0:
            func_8140BF4C(arg0, sp32 + 0x800);
            func_8140BFEC(arg0, 0x1800);
            break;

        case 1:
            func_8140BF4C(arg0, sp32 - 0x1000);
            func_8140BFEC(arg0, 0x1000);
            break;

        case 2:
            func_8140BF4C(arg0, sp32 + 0xC00);
            func_8140BFEC(arg0, -0x1400);
            break;

        case 3:
            func_8140BF4C(arg0, sp32 - 0xA00);
            func_8140BFEC(arg0, -0x2000);
            break;
    }

    func_8140AD8C(arg0, 5.25f);
    func_8140D78C(arg0);
    func_8140BCA8(arg0, sp30 * 2);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84338620(unk_D_8140E720* arg0) {
    switch (arg0->unk_B8) {
        case 1:
            if (func_81408A78(arg0, 2) != 0) {
                func_81408A68(arg0);
                func_8140A578(arg0, arg0->unk_AE);
            }
            break;

        case 2:
            func_8140A5B0(arg0, arg0->unk_B0);
            break;
    }

    if (arg0->unk_B8 > 0) {
        func_81409DAC(arg0);
    }
}

void func_843386B0(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84338468(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408A1C(arg0);
                func_81408328(arg0);
                func_8140BCA8(arg0, 0x1E);
            }
            break;

        case 3:
            func_8140BDD0(arg0);
            break;

        case 4:
            func_81408150(arg0);
            break;
    }

    if (func_81408368(arg0) != 0) {
        func_84338620(arg0);
    }
}

void func_84338778(unk_D_8140E720* arg0) {
    s16 sp4E = func_8140C040(arg0);
    Vec3f sp40;
    Vec3f sp34;
    s16 temp_v1;

    func_8140BECC(arg0, 7);
    func_8140B938(arg0, 0.1f);
    func_8140B95C(arg0, 0.1f);
    func_8432FBBC(&sp40);
    func_8432FC14(&sp34);

    temp_v1 = func_8140119C(sp40, sp34);

    switch (sp4E) {
        case 0:
            func_8140A578(arg0, temp_v1 + 0x2000);
            func_8140A594(arg0, -0x4000);
            break;

        case 1:
            func_8140A578(arg0, temp_v1 + 0x6000);
            func_8140A594(arg0, -0x4000);
            break;
    }

    func_8140D5A0(arg0, func_8140C058(arg0));
    func_814081BC(arg0);
}

void func_843388A8(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84338778(arg0);
            break;

        case 2:
            func_8140BC5C(arg0, 0xFF, 4);
            break;

        case 3:
            func_8140826C(arg0, 0x46);
            break;

        case 4:
            func_8140BC5C(arg0, 0, 0x10);
            break;

        case 5:
            func_81408158(arg0);
            break;
    }

    func_8140B98C(arg0, 50.0f, 0.2f);
    func_8140BA84(arg0, 1.0f, 0.1f);
}

void func_84338978(unk_D_8140E720* arg0) {
    switch (func_8140C040(arg0)) {
        case 0:
            func_8140B938(arg0, 0.5f);
            func_8140B95C(arg0, 1.2f);
            func_8140B974(arg0, 0.1f);
            break;

        case 1:
            func_8140B938(arg0, 0.3f);
            func_8140B95C(arg0, 0.8f);
            func_8140B974(arg0, 0.05f);
            break;
    }

    func_8140D5A0(arg0, 0x26);
    func_814081BC(arg0);
}

void func_84338A2C(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84338978(arg0);
            break;

        case 2:
            func_8140BA1C(arg0);
            func_814084D8(arg0, 0, 7, 1, 2, 0);
            func_8140BC2C(arg0, 0x20, 8);
            break;

        case 3:
            func_81408150(arg0);
            break;
    }
}

void func_84338AC4(unk_D_8140E720* arg0) {
    UNUSED s32 pad;

    func_8140C038(arg0);
    func_8140B938(arg0, 0.5f);
    func_8140A52C(arg0, func_81400A78(0x10000), func_81400A78(0x10000), 0);
    func_8140AD8C(arg0, 1.0f);
    func_8140D5A0(arg0, 0x27);
    func_814081BC(arg0);
}

void func_84338B44(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84338AC4(arg0);
            break;

        case 2:
            func_8140B98C(arg0, 0.3f, 0.05f);
            func_8140BC2C(arg0, 0x20, 0x10);
            func_8140ADBC(arg0, 0.5f, 0.05f);
            func_81409D0C(arg0);
            func_81408E90(arg0, -1.0f);
            func_8140826C(arg0, 0x10);
            break;

        case 3:
            func_81408150(arg0);
            break;
    }
}

void func_84338C0C(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C040(arg0);

    func_8140B938(arg0, 0.6f);

    if (sp26 == 1) {
        func_81408F38(arg0, 6.0f);
    }

    func_8140D5A0(arg0, 0x28);
    func_8140BC20(arg0, 0xC8);
    func_814081BC(arg0);
}

void func_84338C84(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84338C0C(arg0);
            break;

        case 2:
            if (func_8140BC2C(arg0, 0x80, 0x20) != 0) {
                func_814081BC(arg0);
            }
            break;

        case 3:
            func_81408158(arg0);
            break;
    }

    func_8140B98C(arg0, 0.35f, 0.05f);
}

void func_84338D28(unk_D_8140E720* arg0) {
    func_8140B938(arg0, 0.7f);
    func_8140AD8C(arg0, 12.0f);
    func_8140D5A0(arg0, 0x28);
    func_8140BC20(arg0, 0xFF);
    func_814081BC(arg0);
}

void func_84338D84(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84338D28(arg0);
            break;

        case 2:
            func_8432D8E8(arg0, func_84338C84, &D_843861D0[8], 1, 0, 0);
            func_8432D8E8(arg0, func_84338C84, &D_843861D0[8], 1, 0, 1);
            func_8432D844(arg0, func_84338B44, &D_843861D0[0xA], 4);
            func_8140826C(arg0, 0x14);
            break;

        case 3:
            func_81408158(arg0);
            break;
    }

    func_81409D0C(arg0);
}

void func_84338E6C(unk_D_8140E720* arg0) {
    UNUSED s32 pad;

    func_8140C038(arg0);
    func_8140B938(arg0, 0.2f);
    func_8140A52C(arg0, func_81400A78(0x10000), func_81400A78(0x10000), 0);
    func_8140AD8C(arg0, 0.5f);
    func_8140D5A0(arg0, 0x27);
    func_814081BC(arg0);
}

void func_84338EF0(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84338E6C(arg0);
            break;

        case 2:
            func_8140B98C(arg0, 0.1f, 0.02f);
            func_8140BC2C(arg0, 0x20, 0xC);
            func_81409D0C(arg0);
            func_81408E90(arg0, -0.5f);
            func_8140826C(arg0, 0x10);
            break;

        case 3:
            func_81408150(arg0);
            break;
    }
}

void func_84338FA4(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C040(arg0);

    func_8140B938(arg0, 0.2f);

    switch (sp26) {
        case 1:
            func_81408F38(arg0, 3.0f);
            break;

        case 2:
            func_81408F38(arg0, 6.0f);
            break;
    }

    func_8140D5A0(arg0, 0x28);
    func_8140BC20(arg0, 0xC8);
    func_814081BC(arg0);
}

void func_8433903C(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84338FA4(arg0);
            break;

        case 2:
            if (func_8140BC2C(arg0, 0x80, 0x20) != 0) {
                func_814081BC(arg0);
            }
            break;

        case 3:
            func_81408158(arg0);
            break;
    }

    func_8140B98C(arg0, 0.1f, 0.02f);
}

void func_843390E0(unk_D_8140E720* arg0) {
    func_8140B938(arg0, 0.2f);
    func_8140AD8C(arg0, 10.0f);
    func_8140D5A0(arg0, 0x28);
    func_8140BC20(arg0, 0xFF);
    func_814081BC(arg0);
}

void func_8433913C(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_843390E0(arg0);
            break;

        case 2:
            func_8432D8E8(arg0, func_8433903C, &D_843861D0[8], 1, 0, 0);
            func_8432D8E8(arg0, func_8433903C, &D_843861D0[8], 1, 0, 1);
            func_8432D8E8(arg0, func_8433903C, &D_843861D0[8], 1, 0, 2);
            func_8432D844(arg0, func_84338EF0, &D_843861D0[0xA], 4);
            func_8140826C(arg0, 0x20);
            break;

        case 3:
            func_81408158(arg0);
            break;
    }
    func_81409D0C(arg0);
}

void func_84339248(unk_D_8140E720* arg0) {
    UNUSED s32 pad[3];
    s16 sp22 = func_8140C038(arg0);
    s16 sp20 = func_8140C058(arg0);

    func_8140B938(arg0, 0.25f);
    func_8140959C(arg0, 4, 2, 2);
    func_8140A578(arg0, func_81400B28(0x200, -0xE00));
    func_8140A3C4(arg0, func_81400A78(0x400) + 0x100);
    func_8140BFEC(arg0, func_81400A78(0x1000) + 0x1000);
    func_8140A594(arg0, func_81400B00(0x1800));
    func_8140AD8C(arg0, (func_81400A78(0x28) * 0.1f) + 1.0f);
    func_8140D5A0(arg0, sp20);
    func_8140BC20(arg0, 0xC8);
    func_8140BCA8(arg0, sp22 * 2);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84339398(unk_D_8140E720* arg0) {
    if (arg0->unk_B8 == 1) {
        func_8140A76C(arg0, arg0->unk_B0, arg0->unk_9A.x);
        func_81409D0C(arg0);
        func_81408E90(arg0, -0.2f);
    }
}

void func_843393E8(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84339248(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408A1C(arg0);
                func_81408328(arg0);
            }
            break;

        case 3:
            func_8140B98C(arg0, 0.7f, 0.1f);
            func_814084D8(arg0, 0, 7, 1, 2, 0);
            break;

        case 4:
            func_81408150(arg0);
            break;
    }

    if (func_81408368(arg0) != 0) {
        func_84339398(arg0);
    }
}

void func_843394D4(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C038(arg0);

    func_8140B938(arg0, 0.75f - (sp26 * 0.1f));
    func_8140AD8C(arg0, 10.0f);
    func_8140D5A0(arg0, 0x28);
    func_8140BC20(arg0, (0xFF - (sp26 << 5)) & 0xFF);
    func_8140BCA8(arg0, sp26 + 1);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_8433958C(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_843394D4(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            func_8140826C(arg0, 0xA);
            func_81409D0C(arg0);
            break;

        case 4:
            func_81408158(arg0);
            break;
    }
}

void func_84339628(unk_D_8140E720* arg0) {
    func_8140B938(arg0, 1.0f);
    func_8140B95C(arg0, 2.0f);
    func_8140B974(arg0, 0.75f);
    func_8140D5A0(arg0, func_8140C058(arg0));
    func_814081BC(arg0);
}

void func_84339688(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84339628(arg0);
            break;

        case 2:
            func_814084D8(arg0, 0, 3, 1, 1, 0);
            func_8140BA1C(arg0);
            break;

        case 3:
            func_81408158(arg0);
            break;
    }
}

void func_84339710(unk_D_8140E720* arg0) {
    func_8140B938(arg0, 0.4f);
    func_8140B95C(arg0, 0.7f);
    func_8140B974(arg0, 0.1f);
    func_8140D5A0(arg0, func_8140C058(arg0));
    func_814083E8(arg0, 1);
    func_8140A2CC(arg0, func_81400A78(0x10000));
    func_814081BC(arg0);
}

void func_843397A0(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84339710(arg0);
            break;

        case 2:
            if (func_8140BA48(arg0) != 0) {
                func_8140B95C(arg0, 0.2f);
            }
            break;

        case 3:
            func_8140BA48(arg0);
            break;

        case 4:
            func_8140B95C(arg0, 0.7f);
            func_8140B974(arg0, 0.1f);
            arg0->unk_B2 = 2;
            break;
    }

    if (func_8140BDAC(arg0) != 0) {
        func_81408158(arg0);
    }
}

void func_84339874(unk_D_8140E720* arg0) {
    func_8140B938(arg0, 2.0f);
    func_81408F38(arg0, 10.0f);
    func_8140D5A0(arg0, func_8140C058(arg0));
    func_8140BC20(arg0, 0xFF);
    func_814083E8(arg0, 1);
    func_8140A2CC(arg0, func_81400A78(0x10000));
    func_814081BC(arg0);
}

void func_843398F8(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84339874(arg0);
            break;

        case 2:
            func_8140B9D0(arg0, 5.0f, 1.0f);
            break;

        case 3:
            func_8140B9D0(arg0, 0.0f, 1.0f);
            func_8140BC2C(arg0, 0x40, 0x20);
            break;

        case 4:
            func_81408158(arg0);
            break;
    }
}

void func_84339994(unk_D_8140E720* arg0) {
    func_8140C058(arg0);
    func_8140B938(arg0, 2.0f);
    func_81408F38(arg0, 10.0f);
    func_8140D658(arg0, func_81400A78(6));
    func_8140D68C(arg0, func_81400A78(6));
    func_814083E8(arg0, 1);
    func_8140A2CC(arg0, func_81400A78(0x10000));
    func_814081BC(arg0);
}

void func_84339A30(unk_D_8140E720* arg0) {
    func_8140C058(arg0);

    switch (arg0->unk_B2) {
        case 1:
            func_84339994(arg0);
            break;

        case 2:
            func_8140B9D0(arg0, 5.0f, 1.0f);
            break;

        case 3:
            func_8140B9D0(arg0, 0.0f, 1.0f);
            func_8140BC2C(arg0, 0x40, 0x20);
            break;

        case 4:
            func_81408158(arg0);
            break;
    }

    if (D_8140E6C4 == 0) {
        func_8140D658(arg0, func_81400A78(6));
        func_8140D68C(arg0, func_81400A78(6));
    }
}

void func_84339B20(unk_D_8140E720* arg0) {
    UNUSED s16 pad;
    s16 sp24;

    func_8140C058(arg0);
    sp24 = func_8140C038(arg0);
    func_8140B938(arg0, 2.0f);
    func_81408F38(arg0, 10.0f);
    func_8140D530(arg0, 0xA);
    func_8140D624(arg0, sp24 % 6);
    func_814083E8(arg0, 1);
    func_8140BCA8(arg0, sp24 * 2);
    func_8140A5B0(arg0, (sp24 << 0x10) / 10);
    func_8140A3EC(arg0, func_81400B4C(0x800, 0x400));
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84339C0C(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84339B20(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            func_8140B9D0(arg0, 4.0f, 1.0f);
            break;

        case 4:
            func_8140826C(arg0, 8);
            break;

        case 5:
            func_8140B9D0(arg0, 0.0f, 1.0f);
            break;

        case 6:
            func_81408158(arg0);
            break;
    }

    func_8140A4DC(arg0);
}

void func_84339CDC(unk_D_8140E720* arg0) {
    func_8140C038(arg0);
    func_8140D5A0(arg0, func_8140C058(arg0));
    func_8140B938(arg0, 1.35f);
    func_81408ED0(arg0, 5.0f);
    func_8140AD8C(arg0, 5.5f);
    func_8140A52C(arg0, func_81400A78(0x10000), func_81400A78(0x10000), 0);
    func_814081BC(arg0);
}

void func_84339D74(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84339CDC(arg0);
            break;

        case 2:
            func_8140BC2C(arg0, 0x20, 0x16);
            func_814084D8(arg0, 0, 7, 1, 2, 0);
            break;

        case 3:
            func_81408150(arg0);
            break;
    }

    if (func_8140819C(arg0) != 0) {
        func_8140ADBC(arg0, 3.4f, 1.0f);
        func_81409D0C(arg0);
    }
}

void func_84339E38(unk_D_8140E720* arg0) {
    func_8140C038(arg0);
    func_8140D5A0(arg0, func_8140C058(arg0));
    func_8140B938(arg0, 1.0f);
    func_81408ED0(arg0, 5.0f);
    func_8140AD8C(arg0, 4.0f);
    func_8140A52C(arg0, func_81400A78(0x10000), func_81400A78(0x10000), 0);
    func_814081BC(arg0);
}

void func_84339ECC(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84339E38(arg0);
            break;

        case 2:
            func_8140BC2C(arg0, 0x20, 0x16);
            func_814084D8(arg0, 0, 7, 1, 2, 0);
            break;

        case 3:
            func_81408150(arg0);
            break;
    }

    if (func_8140819C(arg0) != 0) {
        func_8140ADBC(arg0, 2.5f, 0.75f);
        func_81409D0C(arg0);
    }
}

void func_84339F8C(unk_D_8140E720* arg0) {
    func_8140C038(arg0);
    func_8140D5A0(arg0, func_8140C058(arg0));
    func_8140B938(arg0, 0.6f);
    func_81408ED0(arg0, 5.0f);
    func_8140AD8C(arg0, 3.0f);
    func_8140A52C(arg0, func_81400A78(0x10000), func_81400A78(0x10000), 0);
    func_814081BC(arg0);
}

void func_8433A024(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84339F8C(arg0);
            break;

        case 2:
            func_8140BC2C(arg0, 0x20, 0x16);
            func_814084D8(arg0, 0, 7, 1, 2, 0);
            break;

        case 3:
            func_81408150(arg0);
            break;
    }

    if (func_8140819C(arg0) != 0) {
        func_8140ADBC(arg0, 1.5f, 0.4f);
        func_81409D0C(arg0);
    }
}

void func_8433A0E8(unk_D_8140E720* arg0) {
    UNUSED s32 pad;

    switch (func_8140C058(arg0)) {
        case 0:
            func_8140D530(arg0, 0xA);
            func_8140D624(arg0, func_81400A78(6));
            break;

        case 1:
            func_8140D658(arg0, func_81400A78(6));
            func_8140D68C(arg0, func_81400A78(6));
            break;

        case 2:
            func_8140D708(arg0, func_81400A78(6));
            break;
    }

    func_8140B938(arg0, 0.8f);
    func_81408ED0(arg0, 5.0f);
    func_8140AD8C(arg0, 3.0f);
    func_8140A52C(arg0, func_81400A78(0x10000), func_81400A78(0x10000), 0);
    func_814081BC(arg0);
}

void func_8433A208(unk_D_8140E720* arg0) {
    s16 sp2E = func_8140C058(arg0);

    switch (arg0->unk_B2) {
        case 1:
            func_8433A0E8(arg0);
            break;

        case 2:
            func_8140BC2C(arg0, 0x20, 0x16);
            func_814084D8(arg0, 0, 7, 1, 2, 0);
            break;

        case 3:
            func_81408150(arg0);
            break;
    }

    if (func_8140819C(arg0) != 0) {
        func_8140ADBC(arg0, 1.5f, 0.5f);
        func_81409D0C(arg0);

        switch (sp2E) {
            case 0:
                func_8140D624(arg0, func_81400A78(6));
                break;

            case 1:
                if (D_8140E6C8 == 0) {
                    func_8140D658(arg0, func_81400A78(6));
                    func_8140D68C(arg0, func_81400A78(6));
                }
                break;

            case 2:
                func_8140D708(arg0, func_81400A78(6));
                break;
        }
    }
}

void func_8433A378(unk_D_8140E720* arg0) {
    s16 sp2E;
    s16 sp2C;
    s16 sp2A;

    sp2E = func_8140C038(arg0);
    sp2C = func_8140C058(arg0);
    sp2A = func_8140C040(arg0);

    func_8140D5A0(arg0, sp2C);
    func_8140B938(arg0, 0.6f);
    func_8140B95C(arg0, 1.2f);
    func_8140B974(arg0, 0.2f);

    switch (sp2A) {
        case 0:
            func_81408BE0(arg0, 0.0f, 10.0f, 0.0f);
            break;

        case 1:
            func_81408BE0(arg0, 0.0f, -5.0f, 10.0f);
            break;

        case 2:
            func_81408BE0(arg0, 0.0f, -5.0f, -10.0f);
            break;
    }

    func_81408ED0(arg0, 5.0f);
    func_8140AD8C(arg0, 1.0f);
    func_8140A52C(arg0, func_81400A78(0x10000), func_81400A78(0x10000), 0);
    func_8140BCA8(arg0, sp2E);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_8433A4D8(unk_D_8140E720* arg0) {
    func_8140C040(arg0);

    switch (arg0->unk_B2) {
        case 1:
            func_8433A378(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            func_8140BA1C(arg0);
            func_8140BC2C(arg0, 0x20, 0x16);
            func_814084D8(arg0, 0, 7, 1, 2, 0);
            func_8140ADBC(arg0, 1.5f, 0.1f);
            func_81409D0C(arg0);
            break;

        case 4:
            func_81408150(arg0);
            break;
    }
}

void func_8433A5C4(unk_D_8140E720* arg0) {
    s16 sp2E = func_8140C038(arg0);
    s16 sp2C = func_8140C058(arg0);

    func_8140959C(arg0, 0, 0xF, 0x14);
    func_81408E90(arg0, 5.0f);
    func_8140B938(arg0, 0.2f);
    func_8140AD8C(arg0, 2.5f);
    func_8140A52C(arg0, func_81400B00(0x2000), func_81400B00(0x2000), 0);
    func_8140D5A0(arg0, sp2C);
    func_8140BCA8(arg0, sp2E * 4);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_8433A698(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8433A5C4(arg0);
            break;

        case 2:
            if (func_8140826C(arg0, arg0->unk_A6) != 0) {
                func_8140BCA8(arg0, 2);
                func_81408328(arg0);
            }
            break;

        case 3:
            func_814084D8(arg0, 0, 7, 1, 1, 0);
            func_8140B98C(arg0, 0.5f, 0.1f);
            func_81409D0C(arg0);
            if (func_8140BDAC(arg0) != 0) {
                func_8140BC2C(arg0, 0, 0x20);
            }
            break;

        case 4:
            func_81408158(arg0);
            break;
    }
}

void func_8433A790(unk_D_8140E720* arg0) {
    s16 sp2E = func_8140C038(arg0);

    func_8140C058(arg0);
    func_8140959C(arg0, 0xA, 0x14, 0x14);
    func_8140B938(arg0, 0.25f);
    func_8140AD8C(arg0, 2.5f);
    func_8140A52C(arg0, func_81400B00(0x2000), func_81400B00(0x2000), 0);
    func_8140D750(arg0);
    func_8140BC20(arg0, 0xC8);
    func_8140BCA8(arg0, sp2E * 4);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_8433A858(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8433A790(arg0);
            break;

        case 2:
            if (func_8140826C(arg0, arg0->unk_A6) != 0) {
                func_8140BCA8(arg0, 2);
                func_81408328(arg0);
            }
            break;

        case 3:
            func_814084D8(arg0, 0, 7, 1, 1, 0);
            func_8140B98C(arg0, 0.4f, 0.1f);
            func_81409D0C(arg0);
            if (func_8140BDAC(arg0) != 0) {
                func_8140BC2C(arg0, 0, 0x20);
            }
            break;

        case 4:
            func_81408150(arg0);
            break;
    }
}

void func_8433A954(unk_D_8140E720* arg0) {
    s16 sp2E = func_8140C038(arg0);

    func_8140C058(arg0);
    func_8140959C(arg0, 0xA, 0x14, 0x14);
    func_8140B938(arg0, 0.4f);
    func_8140AD8C(arg0, 2.5f);
    func_8140A52C(arg0, func_81400B00(0x2000), func_81400B00(0x2000), 0);
    func_8140BAC8(arg0, 0xFF, 0xFF, 0xFF);
    func_8140D78C(arg0);
    func_8140BCA8(arg0, sp2E * 4);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_8433AA28(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8433A954(arg0);
            break;

        case 2:
            if (func_8140826C(arg0, arg0->unk_A6) != 0) {
                func_81408328(arg0);
                func_814083E8(arg0, 1);
            }
            break;

        case 3:
            func_8140B98C(arg0, 0.5f, 0.025f);
            func_814084D8(arg0, 2, 7, 1, 1, 0);
            func_81409D0C(arg0);
            break;

        case 4:
            func_81408150(arg0);
            break;
    }
}

void func_8433AB08(unk_D_8140E720* arg0) {
    Vec3s sp28;
    UNUSED s16 pad;
    s16 sp24;

    func_8140C058(arg0);
    sp24 = func_8140C038(arg0);
    func_8140B938(arg0, 0.05f);
    func_8140A428(arg0, arg0->unk_94.x, arg0->unk_94.y + 0x8000);
    func_8140A3A0(arg0, 0x800, 0x300);
    sp28.x = sp24 << 0xC;
    sp28.y = func_81400B4C(0x3000, 0x1000);
    sp28.z = 0;
    func_8140A4F0(arg0, sp28);
    func_8140D78C(arg0);
    func_8140BCA8(arg0, func_81400A78(0x10) + 8);
    func_8140AD8C(arg0, 4.0f);
    func_814081BC(arg0);
}

void func_8433AC00(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8433AB08(arg0);
            break;

        case 2:
            func_8140B98C(arg0, 0.15f, 0.01f);
            func_8140ADBC(arg0, 1.0f, 0.7f);
            func_8140A6BC(arg0);
            if (func_8140BDD0(arg0) != 0) {
                func_8140BCA8(arg0, func_81400ADC(0xC, 0x20));
                if (arg0->unk_94.y >= arg0->unk_A0.y) {
                    func_8140A400(arg0, -0x4000);
                } else {
                    func_8140A400(arg0, 0x4000);
                }
            }
            break;

        case 3:
            func_8140A690(arg0);
            func_8140ADBC(arg0, 0.5f, 0.2f);
            func_8140BDD0(arg0);
            break;

        case 4:
            func_8140A690(arg0);
            func_814084D8(arg0, 0, 3, 1, 1, 0);
            break;

        case 5:
            func_81408150(arg0);
            break;
    }

    if (func_8140819C(arg0) != 0) {
        func_81409D5C(arg0);
    }
}

void func_8433AD70(unk_D_8140E720* arg0) {
    func_8140B938(arg0, 0.2f);
    func_8140D5A0(arg0, func_8140C058(arg0));
    func_8140BC20(arg0, 0xC8);
    func_8140BCA8(arg0, 0x18);
    arg0->unk_74 = 0.02f;
    func_814081BC(arg0);
}

void func_8433ADE0(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8433AD70(arg0);
            break;

        case 2:
            func_8140B98C(arg0, 2.0f, 0.02f);
            func_8140BBF0(arg0, 0xC8, 2);
            func_8140BDD0(arg0);
            break;

        case 3:
            func_81400760(&arg0->unk_74, 0.008f, 0.001f);
            func_8140B98C(arg0, 2.0f, arg0->unk_74);
            func_8140BAE4(arg0, 0x78, 8);
            func_8140BB44(arg0, 0x96, 8);
            func_8140BB14(arg0, 0x96, 8);
            func_8140BB90(arg0, 0x78, 8);
            func_8140BBC0(arg0, 0x96, 8);
            func_8140BBF0(arg0, 0x96, 8);
            func_8140BC5C(arg0, 0, 0xC);
            break;

        case 4:
            func_81408150(arg0);
            break;
    }
}

void func_8433AF20(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C040(arg0);

    func_8140B938(arg0, 0.05f);
    func_8140B95C(arg0, 0.3f);
    func_8140B974(arg0, 0.005f);

    switch (sp26) {
        case 0:
            func_8140A2B8(arg0, 0);
            break;

        case 1:
            func_8140A2B8(arg0, 0x5500);
            break;

        case 2:
            func_8140A2B8(arg0, -0x5600);
            break;
    }

    func_8140908C(arg0, 10.0f);
    func_8140D5A0(arg0, func_8140C058(arg0));
    func_8140BC20(arg0, 0xC8);
    func_8140BCA8(arg0, 0x18);
    func_814081BC(arg0);
}

void func_8433B014(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8433AF20(arg0);
            break;

        case 2:
            func_8140BBF0(arg0, 0xC8, 2);
            func_8140BDD0(arg0);
            break;

        case 3:
            func_8140BAE4(arg0, 0x78, 8);
            func_8140BB44(arg0, 0x96, 8);
            func_8140BB14(arg0, 0x96, 8);
            func_8140BB90(arg0, 0x78, 8);
            func_8140BBC0(arg0, 0x96, 8);
            func_8140BBF0(arg0, 0x96, 8);
            func_8140BC5C(arg0, 0, 0xC);
            break;

        case 4:
            func_81408150(arg0);
            break;
    }

    func_8140BA1C(arg0);
}

void func_8433B120(unk_D_8140E720* arg0) {
    UNUSED s16 pad;
    s16 sp2C;

    func_8140C038(arg0);
    sp2C = func_8140C058(arg0);
    func_8140B938(arg0, 0.5f);
    func_8140A52C(arg0, func_81400A78(0x10000), func_81400A78(0x10000), 0);
    func_81408ED0(arg0, 5.0f);
    func_8140AD8C(arg0, 1.0f);
    func_8140D5A0(arg0, sp2C);
    func_814081BC(arg0);
}

void func_8433B1B8(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8433B120(arg0);
            break;

        case 2:
            func_8140B98C(arg0, 0.3f, 0.02f);
            func_8140BC2C(arg0, 0x20, 0xC);
            func_81409D0C(arg0);
            func_81408E90(arg0, -1.0f);
            func_8140826C(arg0, 0x10);
            break;

        case 3:
            func_81408150(arg0);
            break;
    }

    if (arg0->unk_2C.y < 0.0f) {
        func_81408150(arg0);
    }
}

void func_8433B290(void) {
    func_8432EC28(4, func_8433958C, &D_843861D0[8], 0, 4, 0x11, D_843902E2, 0, 0);
}

void func_8433B2E8(void) {
    s32 sp34 = 0;

    if (func_8432F9CC(0x7C) != 0) {
        sp34 = 1;
    }

    if (func_8432F9CC(4) != 0) {
        sp34 = 1;
    }

    if (sp34 == 0) {
        func_8432EC28(0, func_8433958C, &D_843861D0[8], 0, 4, 0x11, D_843902E2, 0, 0);
    }
}

void func_8433B374(void) {
    func_8432ECA0(0, 1, 0x3C, func_84337E64, &D_843861D0[0x45], 0, 1, 0x11, D_843902E2, 0, 0);
}

void func_8433B3D8(void) {
    func_8432EC28(0, func_843529D8, &D_843861D0[0x34], 0, 1, 0x11, 9, 3, 5);
    func_8432EC28(0, func_8433AC00, &D_843861D0[0x45], 0, 0x10, 0x11, 9, 0, 0);
    func_8432EC28(8, func_8433AC00, &D_843861D0[0x45], 0, 0x10, 0x11, 9, 0, 0);
}

void func_8433B4AC(void) {
    func_8432EC28(3, func_84338A2C, &D_843861D0[0xE], 0, 1, 0x11, D_843902E2, 0, 1);
    func_8432EC28(3, func_84338A2C, &D_843861D0[0x19], 0, 1, 0x11, D_843902E2, 0, 1);
    func_8432EC28(4, func_8433913C, &D_8140E460, 0, 1, 0x11, D_843902E2, 0, 0);
}

void func_8433B58C(void) {
    func_8432ECA0(0, 1, 0xF, func_8433A024, &D_843861D0[0x19], 0, 1, 0x10, D_843902E2, 0x26, 0);
    func_8432EC28(0xC, func_8433B014, &D_843861D0[0x4B], 0, 1, 0xA, 0, 0x4C, 0);
    func_8432EC28(0xC, func_8433B014, &D_843861D0[0x4B], 0, 1, 0xA, 0, 0x4C, 1);
    func_8432EC28(0xC, func_8433B014, &D_843861D0[0x4B], 0, 1, 0xA, 0, 0x4C, 2);
    func_8432ECA0(4, 1, 0x10, func_8433B1B8, &D_843861D0[0xA], 0, 2, 0x11, D_843902E2, 0x4C, 0);
}

void func_8433B6FC(void) {
    func_8432ED0C(0, 0x40, 6);
    func_8432EC28(3, func_84338A2C, &D_843861D0[0xE], 0, 1, 0x11, D_843902E2, 0, 0);
    func_8432EC28(3, func_84338A2C, &D_843861D0[0x19], 0, 1, 0x11, D_843902E2, 0, 0);
    func_8432EC28(4, func_84338D84, &D_843861D0[8], 0, 1, 0x11, D_843902E2, 0, 0);
}

void func_8433B7E4(void) {
    func_8432F440(4, 0xA, 0x35, 0x10, 0xFF);
    func_8432EC28(0, func_84333E28, &D_843861D0[4], 0, 1, 0x10, D_843902E2, 0x35, 0);
    func_8432ECA0(0, 5, 3, func_84339D74, &D_843861D0[0x19], 0, 8, 0x10, D_843902E2, 0x26, 0);
    func_8432ECA0(0xA, 1, 8, func_8433A698, &D_843861D0[0x19], 0, 3, 0x11, D_843902E2, 0x26, 0);
    func_8432EC28(0xC, func_8433ADE0, &D_843861D0[0x4B], 0, 1, 0xA, 0, 0x4C, 0);
    func_8432ECA0(2, 1, 0x10, func_8433B1B8, &D_843861D0[0xA], 0, 4, 0x11, D_843902E2, 0x4C, 0);
}

void func_8433B988(void) {
    func_8432ED74(0, 0, 0x20, 0xA, 0xA0);
    func_8432ED0C(0, 8, 0x35);
    func_8432EC28(0, func_84339688, &D_843861D0[0x53], 0, 1, 0x10, D_843902E2, 0x40, 0);
    func_8432EC28(6, func_843397A0, &D_843861D0[0x53], 0x6E, 1, 0x10, D_843902E2, 0x40, 1);
    func_8432ECA0(0, 3, 0x1E, func_843393E8, &D_843861D0[0x4A], 0, 1, 0x11, D_843902E2, 0x13, 0);
}

void func_8433BAA8(void) {
    func_8432ED74(0, 0, 0x20, 0xA, 0xA0);
    func_8432ED0C(0, 8, 6);
    func_8432EC28(0, func_84339688, &D_843861D0[0x53], 0, 1, 0x10, D_843902E2, 0xD, 0);
    func_8432EC28(6, func_843397A0, &D_843861D0[0x53], 0x46, 1, 0x10, D_843902E2, 0xD, 1);
}

void func_8433BB78(void) {
    func_8432ED0C(0, 8, 6);
    func_8432ECA0(0, 1, 0x3C, func_8433837C, &D_843861D0[0x45], 0, 4, 0x11, D_843902E2, 0, 0);
    func_8432ECA0(0, 1, 0x3C, func_843380F0, &D_843861D0[0x45], 0, 1, 0x11, D_843902E2, 0, 0);
}

void func_8433BC38(void) {
    func_8432ED74(0, 0, 0x20, 0xA, 0xA0);
    func_8432ED0C(0, 8, 6);
    func_8432EC28(0, func_84339688, &D_843861D0[0x53], 0, 1, 0x10, D_843902E2, 0x41, 0);
    func_8432EC28(6, func_843397A0, &D_843861D0[0x53], 0x46, 1, 0x10, D_843902E2, 0x41, 1);
}

void func_8433BD08(void) {
    func_8432ED74(0, 0, 0x20, 0xA, 0xA0);
    func_8432F2C8(0, 0xA, 0xFF, 0, 0x10);
    func_8432ED0C(0, 0x20, 0x10);
    func_8432EC28(0, func_84339688, &D_843861D0[0x53], 0, 1, 0x10, D_843902E2, 0x2C, 0);
    func_8434A844();
    func_8432EC28(6, func_843397A0, &D_843861D0[0x53], 0x46, 1, 0x10, D_843902E2, 0x2C, 1);
}

void func_8433BDFC(void) {
    func_8432ED74(0, 0, 0x20, 0xA, 0xA0);
    func_8432ED0C(0, 8, 0x22);
    func_8432EC28(0, func_84339688, &D_843861D0[0x53], 0, 1, 0x10, D_843902E2, 0x17, 0);
    func_8432EC28(6, func_843397A0, &D_843861D0[0x53], 0x46, 1, 0x10, D_843902E2, 0x17, 1);
}

void func_8433BECC(void) {
    func_8432ED74(0, 0, 0x20, 0xA, 0xA0);
    func_8432ED0C(0, 8, 0x22);
    func_8432EC28(0, func_84339688, &D_843861D0[0x53], 0, 1, 0x10, D_843902E2, 0x17, 0);
}

void func_8433BF54(void) {
    func_8432F440(4, 0xA, 0x35, 0xC, 0xFF);
    func_8432EC28(0, func_84333E28, &D_843861D0[4], 0, 1, 0x10, D_843902E2, 0x35, 0);
    func_8432ECA0(0, 5, 3, func_84339D74, &D_843861D0[0x19], 0, 8, 0x10, D_843902E2, 0x26, 0);
    func_8432ECA0(0xA, 1, 3, func_8433A698, &D_843861D0[0x19], 0, 8, 0x11, D_843902E2, 0x26, 0);
}

void func_8433C06C(void) {
    func_8432F538(0, 0xA, 0x35, 0x10, 0xDC, 0x20);
    func_8432EC28(3, func_84333E28, &D_843861D0[4], 0, 1, 0x10, D_843902E2, 0x35, 0);
    func_8432ECA0(0, 5, 3, func_84339D74, &D_843861D0[0x19], 0, 8, 0x10, D_843902E2, 0x26, 0);
    func_8432ECA0(4, 4, 2, func_843398F8, &D_843861D0[0x54], 0, 1, 0x10, D_843902E2, 0x33, 0);
    func_8432ECA0(0xC, 1, 3, func_8433A698, &D_843861D0[0x19], 0, 8, 0x11, D_843902E2, 0x26, 0);
    func_8432ECA0(0xE, 4, 2, func_84350FC0, &D_843861D0[0x3D], 0, 6, 0x10, 0x64, 0, 0);
    func_8432ECA0(0, 2, 6, func_84352530, &D_843861D0[0x42], 0, 8, 0x11, 9, 0x18, 0xB);
    func_8432ED0C(0x30, 0x20, 0xA);
}

void func_8433C284(void) {
    func_8432F728(4, 0x32, 0x20, 0xA0);
    func_8432ECA0(4, 4, 3, func_84339A30, &D_843861D0[0x54], 0, 1, 0x10, D_843902E2, 0, 0);
    func_8432EC28(3, func_84333EE8, &D_843861D0[0x1B], 0, 1, 0x10, D_843902E2, 0x23, 0);
    func_8432ECA0(3, 5, 3, func_8433A208, &D_843861D0[0x19], 0, 8, 0x10, D_843902E2, 1, 0);
    func_8432ED0C(0x30, 0x20, 0xA);
}

void func_8433C3A0(void) {
    func_8432F440(4, 0xA, 0x23, 0x10, 0xFF);
    func_8432EC28(3, func_84333E28, &D_843861D0[4], 0, 1, 0x10, D_843902E2, 0x35, 0);
    func_8432ECA0(3, 5, 3, func_8433A208, &D_843861D0[0x19], 0, 8, 0x10, D_843902E2, 0, 0);
    func_8432EC28(0, func_8433AC00, &D_843861D0[0x45], 0, 0x10, 0x11, 9, 0, 0);
    func_8432EC28(8, func_8433AC00, &D_843861D0[0x45], 0, 0x10, 0x11, 9, 0, 0);
    func_8432ED0C(0x30, 0x20, 0xA);
}

void func_8433C4EC(void) {
    func_8432F728(4, 0x32, 0x20, 0xA0);
    func_8432EC28(4, func_84339C0C, &D_843861D0[0x54], 0, 9, 0x10, D_843902E2, 0, 0);
    func_8432ECA0(3, 5, 3, func_8433A208, &D_843861D0[0x19], 0, 8, 0x10, D_843902E2, 0, 0);
    func_8432ECA0(0xC, 1, 3, func_8433A698, &D_843861D0[0x19], 0, 8, 0x11, D_843902E2, 0x39, 0);
    func_8432ED0C(0x16, 0x20, 0xA);
}

void func_8433C604(void) {
    UNUSED s32 pad;

    func_8432F2C8(0, 0x19, 0xFF, 0, 8);
    func_8432F440(4, 0x19, 0x19, 0x10, 0xFF);
    func_8432EC28(3, func_84333E28, &D_843861D0[4], 0, 1, 0x10, D_843902E2, 0x19, 0);
    func_8432EC28(0, func_843398F8, &D_843861D0[0x34], 0, 1, 0x10, D_843902E2, 0x2C, 0);
    func_8432ECA0(4, 8, 1, func_843398F8, &D_843861D0[0x54], 0, 1, 0x10, D_843902E2, 0x2C, 0);
    func_8432ECA0(3, 5, 2, func_84339D74, &D_843861D0[0x19], 0, 8, 0x10, D_843902E2, 0xF, 0);
    func_8433E524();
}

void func_8433C784(void) {
    UNUSED s32 pad;

    func_8432F440(4, 0xA, 0x19, 0x10, 0xFF);
    func_8432EC28(0, func_843398F8, &D_843861D0[0x34], 0, 1, 0x10, D_843902E2, 0x17, 0);
    func_8432ECA0(4, 4, 1, func_843398F8, &D_843861D0[0x54], 0, 1, 0x10, D_843902E2, 0x17, 0);
    func_8432EC28(3, func_84333E28, &D_843861D0[4], 0, 1, 0x10, D_843902E2, 0x1A, 0);
    func_8432ECA0(3, 5, 3, func_84339D74, &D_843861D0[0x19], 0, 8, 0x10, D_843902E2, 0x17, 0);
    func_8432ECA0(0xC, 1, 3, func_8433A698, &D_843861D0[0x19], 0, 8, 0x11, D_843902E2, 0x17, 0);
    func_8432ED0C(0x16, 0x20, 0xA);
}

void func_8433C940(void) {
    UNUSED s32 pad;

    func_8432F440(4, 0xA, 0x19, 0x10, 0xFF);
    func_8432EC28(0, func_843398F8, &D_843861D0[0x34], 0, 1, 0x10, D_843902E2, 0x29, 0);
    func_8432ECA0(4, 4, 1, func_843398F8, &D_843861D0[0x54], 0, 1, 0x10, D_843902E2, 0x29, 0);
    func_8432EC28(3, func_84333E28, &D_843861D0[4], 0, 1, 0x10, D_843902E2, 0x1A, 0);
    func_8432ECA0(3, 5, 3, func_84339D74, &D_843861D0[0x19], 0, 8, 0x10, D_843902E2, 0x29, 0);
    func_8432ECA0(0xC, 1, 3, func_8433A698, &D_843861D0[0x19], 0, 8, 0x11, D_843902E2, 0x29, 0);
    func_8432ED0C(0x16, 0x20, 0xA);
}

void func_8433CAFC(void) {
    func_8432ECA0(0, 2, 8, func_8433A4D8, &D_843861D0[0x19], 0, 1, 0x11, D_843902E2, 0x49, 0);
    func_8432ECA0(0, 2, 8, func_8433A4D8, &D_843861D0[0x19], 0, 1, 0x11, D_843902E2, 0x4A, 1);
    func_8432ECA0(0, 2, 8, func_8433A4D8, &D_843861D0[0x19], 0, 1, 0x11, D_843902E2, 0x4B, 2);
}
