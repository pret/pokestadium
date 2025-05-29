#include "fragment62.h"

void func_8433E650(unk_D_8140E720* arg0) {
    Vec3s sp28;
    s16 sp26 = func_8140C058(arg0);
    s16 sp24 = func_8140C038(arg0);

    func_81408CA0(arg0, 2.5f);
    func_8140B938(arg0, 0.065789476f);
    func_8140AD8C(arg0, 0.0f);
    sp28.x = func_81400B00(0x5000);
    sp28.y = sp24 * (0x10000 / arg0->unk_AA);
    sp28.z = 0;
    func_8140A4F0(arg0, sp28);
    func_8140D530(arg0, sp26);
    func_8140BC20(arg0, 0x80);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_8433E758(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8433E650(arg0);
            break;

        case 2:
            if (func_8140826C(arg0, func_8140C038(arg0)) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            func_8140B98C(arg0, 1.3157895f, 0.16447368f);
            func_8140BDD0(arg0);
            break;

        case 4:
            func_8140BC5C(arg0, 0, 0x10);
            break;

        case 5:
            func_81408158(arg0);
            break;
    }

    func_8140A594(arg0, 0x400);
    func_81409D0C(arg0);
}

void func_8433E840(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C058(arg0);

    func_8140B938(arg0, 0.65789473f);
    func_8140D5A0(arg0, sp26);
    func_814083E8(arg0, 2);
    func_8140BC20(arg0, 0xC8);
    func_814081BC(arg0);
}

void func_8433E8A8(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8433E840(arg0);
            break;

        case 2:
            func_8140B98C(arg0, 6.5789475f, 0.32894737f);
            func_8140826C(arg0, 0xF);
            break;

        case 3:
            func_8140BDD0(arg0);
            break;

        case 4:
            func_8140BC5C(arg0, 0, 0x20);
            break;

        case 5:
            func_81408158(arg0);
            break;
    }
}

void func_8433E950(unk_D_8140E720* arg0) {
    s16 sp2E = func_8140C058(arg0);
    s16 sp2C = func_8140C038(arg0);

    func_8140B938(arg0, 0.05f);
    func_8140A270(arg0, func_81400A78(0x10000), func_81400A78(0x10000), 0);
    func_8140AD8C(arg0, 1.2f);
    func_8140D5A0(arg0, sp2E);
    func_8140BCA8(arg0, sp2C * 1);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_8433EA04(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8433E950(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            if (func_8140B98C(arg0, 0.15f, 0.025f) != 0) {
                func_814081BC(arg0);
            }
            break;

        case 4:
            if (func_8140B98C(arg0, 0.0f, 0.04f) != 0) {
                func_814081BC(arg0);
            }
            break;

        case 5:
            func_81408158(arg0);
            break;
    }

    func_8140ADBC(arg0, 0.2, 0.2f);
    func_81409D0C(arg0);
    func_81408E90(arg0, -1.0f);
}

void func_8433EB0C(unk_D_8140E720* arg0) {
    UNUSED s16 pad;
    s16 sp2C;

    func_8140C038(arg0);
    sp2C = func_8140C058(arg0);
    func_8140B938(arg0, 0.175f);
    func_8140A270(arg0, func_81400A78(0x10000), func_81400A78(0x10000), 0);
    func_8140D5A0(arg0, sp2C);
    func_8140BC20(arg0, 0x80);
    func_814081BC(arg0);
}

void func_8433EB9C(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8433EB0C(arg0);
            break;

        case 2:
            func_8140B98C(arg0, 0.1f, 0.01f);
            func_8140BC2C(arg0, 0, 8);
            func_81409D0C(arg0);
            func_8140BDD0(arg0);
            break;

        case 3:
            func_81408158(arg0);
            break;
    }
}

void func_8433EC40(unk_D_8140E720* arg0) {
    s16 sp2E;
    s16 sp2C;
    s16 temp_v0;
    Vec3s sp24;

    temp_v0 = func_8140C038(arg0);
    sp2E = temp_v0 / 8;
    sp2C = temp_v0 % 8;

    func_8140B938(arg0, 0.5f);
    sp24.x = 0x6000 - (sp2E * 0xC00);
    sp24.y = (sp2C << 0xC) + 0xB000;
    sp24.z = 0;
    func_8140A4F0(arg0, sp24);
    func_8140BAC8(arg0, 0xC8, 0xFF, 0xFF);
    func_8140BC20(arg0, 0x60);
    func_8140BCA8(arg0, sp2E);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_8433ED3C(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8433EC40(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_8140BCA8(arg0, 0xA);
                func_81408328(arg0);
            }
            break;

        case 3:
            func_8140A594(arg0, 0x200);
            func_8140B98C(arg0, 2.0f, 0.01f);
            func_8140BDD0(arg0);
            break;

        case 4:
            func_8140BC5C(arg0, 0, 0x10);
            break;

        case 5:
            func_81408150(arg0);
            break;
    }
}

void func_8433EE10(unk_D_8140E720* arg0) {
    s16 sp36;
    s16 sp34;
    s16 sp32 = func_8140C038(arg0);
    s16 sp30 = func_8140C058(arg0);
    s16 sp2E = func_8140C040(arg0);

    func_8140A270(arg0, func_81400A78(0x10000), func_81400A78(0x10000), 0);
    func_8140B938(arg0, 0.01f);
    func_8140D5A0(arg0, sp30);

    switch (sp2E) {
        case 0:
            func_8140BF4C(arg0, func_81400ADC(0x14, 0x14));
            func_8140BFEC(arg0, 0);
            sp36 = func_81400B4C(0x200, 0x200);
            sp34 = func_81400B4C(0x200, 0x200);
            func_8140BE14(arg0, 8);
            break;

        case 1:
            func_8140BF4C(arg0, func_81400ADC(0x28, 0x14));
            func_8140BFEC(arg0, 1);
            sp36 = func_81400B4C(0x200, 0x200);
            sp34 = func_81400B4C(0x200, 0x200);
            func_8140BE14(arg0, 0x10);
            break;

        case 2:
            func_8140BF4C(arg0, func_81400ADC(0x1E, 0x14));
            func_8140BFEC(arg0, 2);
            sp36 = func_81400B4C(0x200, 0x200);
            sp34 = func_81400B4C(0x200, 0x200);
            func_8140BE14(arg0, 0xA);
            break;

        case 3:
            func_8140BF4C(arg0, 0x1E - sp32);
            func_8140BFEC(arg0, 2);
            sp36 = func_81400B4C(0x200, 0x200);
            sp34 = func_81400B4C(0x200, 0x200);
            func_8140BE14(arg0, 0xA);
            break;
    }

    func_8140A3C4(arg0, sp36);
    func_8140A3D8(arg0, sp34);
    func_8140BCA8(arg0, sp32 * 2);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_8433F06C(unk_D_8140E720* arg0) {
    func_8140C040(arg0);

    switch (arg0->unk_B2) {
        case 1:
            func_8433EE10(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
                func_81408A68(arg0);
            }
            break;

        case 3:
            if (func_8140B9D0(arg0, 0.3f, 0.05f) != 0) {}
            break;

        case 4:
            if (func_8140826C(arg0, arg0->unk_A8) != 0) {
                func_81408A68(arg0);
            }
            break;

        case 5:
            func_8140B9D0(arg0, 0.0f, 0.05f);
            break;

        case 6:
            func_81408150(arg0);
            break;
    }

    if (func_81408368(arg0) != 0) {
        switch (arg0->unk_B8) {
            case 1:
                func_8140A4B4(arg0);
                func_81408CD0(arg0, arg0->unk_AE);
                break;

            case 2:
                func_8140A4B4(arg0);
                func_8140BF60(arg0, 0, arg0->unk_B0);
                func_81408CD0(arg0, arg0->unk_AE);
                break;
        }
    }

    func_81408E90(arg0, 10.0f);
}

void func_8433F208(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C058(arg0);

    func_8140B938(arg0, 0.2f);
    func_81408E90(arg0, 5.0f);
    func_8140D5A0(arg0, sp26);
    func_8140BC20(arg0, 0x40);
    func_814081BC(arg0);
}

void func_8433F270(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8433F208(arg0);
            break;

        case 2:
            func_8140B98C(arg0, 4.0f, 0.1f);
            func_8140BC2C(arg0, 0xC8, 8);
            func_8140BDD0(arg0);
            break;

        case 3:
            func_8140B98C(arg0, 0.25f, 0.5f);
            func_8432D8E8(arg0, func_8435226C, &D_843861D0[0x42], 6, 0x18, 7);
            if (func_8140826C(arg0, 6) != 0) {
                func_8140BF04(arg0, 9);
            }
            break;

        case 4:
            func_814099E0(arg0, 15.0f);
            func_8140826C(arg0, 0xA);
            func_8432D8E8(arg0, func_8435226C, &D_843861D0[0x42], 6, 0x18, 7);
            break;

        case 5:
            func_81408158(arg0);
            break;
    }
}

s16 func_8433F3B4(void) {
    s16 var_v1 = 0x3B;

    switch (D_800AE540.unk_0000) {
        case 0:
            var_v1 = 0xD;
            break;

        case 1:
            var_v1 = 0x3C;
            break;

        case 2:
            var_v1 = 0x3C;
            break;

        case 3:
            var_v1 = 3;
            break;

        case 4:
            var_v1 = 3;
            break;

        case 5:
            var_v1 = 3;
            break;
    }
    return var_v1;
}

void func_8433F414(void) {
    s16 sp3E = func_8433F3B4();

    func_8432ECA0(0, 1, 0x1E, func_8433EB9C, &D_843861D0[0x22], 0x10, 1, 0x1E, 0, sp3E, 0);
    func_8432ECA0(0, 1, 0x1E, func_8433EA04, &D_843861D0[0x42], 0x10, 2, 0x1E, 0, sp3E, 0);
}

void func_8433F4CC(void) {
    func_8433F414();
}

void func_8433F4EC(void) {
    func_8432ECA0(0xB, 1, 5, func_8435226C, &D_843861D0[0x42], 0, 5, 0x1E, 0, func_8433F3B4(), 8);
    func_8432EFB4(0xA, 2, 0x16, 7, 0xFF);
    func_8432EB20(0x10);
    func_8432EC28(0, func_8433ED3C, &D_843861D0[0x1C], 0, 0x40, 0x1E, 0, 0xA, 0);
}

void func_8433F5B4(void) {
    func_8433F4EC();
}

void func_8433F5D4(void) {
    UNUSED s32 pad;

    func_8432EDE8(0, 0, 0x10, 7);
    func_8432F2C8(0, 0xA, 0xFF, 0xFF, 0xFF);
    func_8432F7A0(0, 0xFF, 0xFF, 0xFF);
    func_8432F2C8(0x14, 0xA, 0xFF, 0, 8);
    func_8432EC28(0, func_8433E8A8, &D_843861D0[0x21], 4, 1, 2, 0, 0x50, 0);
    func_8432EC28(0, func_8433E8A8, &D_843861D0[0x23], 4, 1, 2, 0, 0x50, 0);
    func_8432EC28(0, func_8433E8A8, &D_843861D0[0x17], 4, 1, 2, 0, 0x50, 0);
    func_8432ECA0(0, 1, 4, func_8433E758, &D_843861D0[0x1C], 5, 0x10, 7, 0, 0x39, 0);
    func_8432ED0C(0x32, 0x10, 0xA);
}

void func_8433F758(void) {
    func_8432ED0C(0, 8, 6);
    func_8432ECA0(0, 4, 5, func_8433F06C, &D_843861D0[0x44], 0, 4, 9, 0, 0x3C, 1);
    func_8432ECA0(0, 4, 5, func_8433F06C, &D_843861D0[0x44], 0, 4, 9, 0, 0x3C, 1);
    func_8432ECA0(0x18, 1, 4, func_8433F06C, &D_843861D0[0x44], 0, 8, 9, 0, 0x3C, 2);
    func_8432ECA0(0x1E, 1, 8, func_8433F06C, &D_843861D0[0x44], 0, 8, 9, 0, 0x3C, 3);
    func_8432ECA0(0x1E, 1, 8, func_8433F06C, &D_843861D0[0x44], 0, 8, 9, 0, 0x3C, 3);
    func_8432F2C8(0x26, 0xA, 0, 0xFF, 4);
    func_8432EC28(0x2D, func_8433F270, &D_843861D0[0x38], 0x1A, 1, 2, 0, 0x3C, 0);
    func_8432F7A0(0x48, 0x40, 0, 0xFF);
    func_8432ED0C(0x55, 6, 0xA);
}

void func_8433F974(void) {
    UNUSED s32 pad;
    
    func_8432ED0C(0, 8, 6);
    func_8432ECA0(0, 1, 4, func_8433F06C, &D_843861D0[0x44], 0, 8, 9, 0, 0x3C, 2);
    func_8432ECA0(6, 1, 8, func_8433F06C, &D_843861D0[0x44], 0, 8, 9, 0, 0x3C, 3);
    func_8432ECA0(6, 1, 8, func_8433F06C, &D_843861D0[0x44], 0, 8, 9, 0, 0x3C, 3);
    func_8432F2C8(0xE, 0xA, 0, 0xFF, 4);
    func_8432EC28(0x14, func_8433F270, &D_843861D0[0x38], 0x1A, 1, 2, 0, 0x3C, 0);
    func_8432F7A0(0x2D, 0x40, 0, 0xFF);
    func_8432ED0C(0x32, 6, 0xA);
}

void func_8433FAF8(void) {
    func_8432ED0C(0, 8, 6);
    func_8432ECA0(0, 4, 5, func_8433F06C, &D_843861D0[0x44], 0, 4, 9, 0, 0x3C, 1);
    func_8432ECA0(0, 4, 5, func_8433F06C, &D_843861D0[0x44], 0, 4, 9, 0, 0x3C, 1);
    func_8432ECA0(0x18, 1, 4, func_8433F06C, &D_843861D0[0x44], 0, 8, 9, 0, 0x3C, 2);
    func_8432ECA0(0x1E, 1, 8, func_8433F06C, &D_843861D0[0x44], 0, 8, 9, 0, 0x3C, 3);
    func_8432ECA0(0x1E, 1, 8, func_8433F06C, &D_843861D0[0x44], 0, 8, 9, 0, 0x3C, 3);
    func_8432F2C8(0x26, 0xA, 0, 0xFF, 8);
    func_8432EC28(0x28, func_8433F270, &D_843861D0[0x38], 0x18, 1, 2, 0, 0x3C, 0);
    func_8432ED74(0x3C, 0, 0x40, 0xA, 0xFF);
    func_8432F7A0(0x40, 0xFF, 0, 0xFF);
    func_8432EB20(0x50);
    func_8433F5D4();
}

void func_8433FD30(void) {
    func_8432ED0C(0, 0xFF, 0);
    func_8432F2C8(0x14, 0, 0, 0xFF, 0x10);
}
