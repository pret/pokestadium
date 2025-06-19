#include "fragment62.h"
#include "src/math_util.h"

void func_8433CC10(unk_D_8140E720* arg0) {
    UNUSED s32 pad;
    Vec3s sp2C;

    func_8140C038(arg0);
    func_8140B938(arg0, 0.05f);
    sp2C.x = func_81400A78(0x8000) - 0x4000;
    sp2C.y = func_81400A78(0x10000);
    sp2C.z = func_81400A78(0x800) - 0x400;
    func_8140A4F0(arg0, sp2C);
    func_8140910C(arg0, func_81400A78(0xA));
    func_8140A578(arg0, 0x4000);
    func_8140D5A0(arg0, func_8140C058(arg0));
    func_814081BC(arg0);
}

void func_8433CCFC(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8433CC10(arg0);
            break;

        case 2:
            func_8140BDD0(arg0);
            break;

        case 3:
            func_8140BC5C(arg0, 0, 0x40);
            break;

        case 4:
            func_81408158(arg0);
            break;
    }

    func_8140B98C(arg0, 1.0f, 0.05f);
    func_81409DAC(arg0);
}

void func_8433CDAC(unk_D_8140E720* arg0) {
    f32 sp1C = 0.0f;

    switch (func_843081BC(arg0->unk_10)) {
        case 0x6:
            sp1C = 15.0f;
            break;

        case 0x73:
            sp1C = 15.0f;
            break;

        case 0x87:
            sp1C = 10.0f;
            break;

        case 0x95:
            sp1C = 10.0f;
            break;

        case 0x1F:
            sp1C = 10.0f;
            break;

        case 0x22:
            sp1C = 10.0f;
            break;

        case 0x71:
            sp1C = 10.0f;
            break;
    }

    func_81408F38(arg0, sp1C);
    func_81408FAC(arg0, 5.0f);
}

void func_8433CEA4(unk_D_8140E720* arg0) {
    func_8140B938(arg0, 0.1f);
    func_8140AD8C(arg0, 0.0f);
    func_8433CDAC(arg0);
    func_8140D5A0(arg0, 0x17);
    func_814081BC(arg0);
}

void func_8433CEFC(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8433CEA4(arg0);
            break;

        case 2:
            func_8140B98C(arg0, 4.0f, 0.5f);
            func_8140BDD0(arg0);
            break;

        case 3:
            func_8140B98C(arg0, 0.1f, 0.5f);
            func_8140BC5C(arg0, 0, 0x20);
            break;

        case 4:
            func_81408158(arg0);
            break;
    }
}

void func_8433CFA8(unk_D_8140E720* arg0) {
    s16 sp2E = func_8140C038(arg0);
    Vec3s sp28;

    func_81408CA0(arg0, 15.0f);
    func_8140B938(arg0, 0.1f);
    func_8140AD8C(arg0, 0.0f);
    sp28.x = 0x4000 - func_81400A78(0x8000);
    sp28.y = sp2E << 0xD;
    sp28.z = 0;
    func_8140A4F0(arg0, sp28);
    func_8140D5A0(arg0, func_8140C058(arg0));
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_8433D070(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8433CFA8(arg0);
            break;

        case 2:
            if (func_8140826C(arg0, func_8140C038(arg0)) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            func_8140B98C(arg0, 3.0f, 0.1f);
            func_8140BDD0(arg0);
            break;

        case 4:
            func_8140BC5C(arg0, 0, 0x40);
            break;

        case 5:
            func_81408158(arg0);
            break;
    }

    func_8140A594(arg0, 0x400);
    func_81409D0C(arg0);
}

void func_8433D154(unk_D_8140E720* arg0) {
    s16 sp2E = func_8140C038(arg0);
    Vec3s sp28;

    func_81408CA0(arg0, 15.0f);
    func_8140B938(arg0, 0.1f);
    func_8140AD8C(arg0, MathUtil_Random_ZeroOne());
    sp28.x = 0x3000 - func_81400A78(0x6000);
    sp28.y = sp2E << 0xD;
    sp28.z = 0;
    func_8140A4F0(arg0, sp28);
    func_8140D5A0(arg0, func_8140C058(arg0));
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_8433D224(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8433D154(arg0);
            break;

        case 2:
            if (func_8140826C(arg0, func_8140C038(arg0)) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            func_8140B98C(arg0, 3.5f, 0.1f);
            func_8140BDD0(arg0);
            break;

        case 4:
            func_8140BC5C(arg0, 0, 0x40);
            break;

        case 5:
            func_81408158(arg0);
            break;
    }

    func_8140A594(arg0, 0x400);
    func_81409D0C(arg0);
}

void func_8433D308(unk_D_8140E720* arg0) {
    Vec3s sp28;

    func_8140C038(arg0);
    func_8140B938(arg0, 0.5f);
    func_8140AD8C(arg0, 0.0f);
    sp28.x = -0x4000;
    sp28.y = 0;
    sp28.z = (func_81400A78(0x10) << 0xB) - 0x4000;
    func_8140A4F0(arg0, sp28);
    func_8140D5A0(arg0, func_8140C058(arg0));
    func_814081BC(arg0);
}

void func_8433D3B0(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8433D308(arg0);
            break;

        case 2:
            func_8140B98C(arg0, 2.0f, 0.2f);
            func_8140BDD0(arg0);
            break;

        case 3:
            func_8140BC5C(arg0, 0, 0x40);
            break;

        case 4:
            func_81408158(arg0);
            break;
    }
    func_81409DAC(arg0);
}

void func_8433D460(unk_D_8140E720* arg0) {
    UNUSED s32 pad;
    Vec3s sp2C;

    func_8140C038(arg0);
    func_8140B938(arg0, 0.5f);
    func_8140B95C(arg0, (MathUtil_Random_ZeroOne() * 5.0f) + 1.0f);
    func_8140B974(arg0, 0.2f);
    func_8140AD8C(arg0, MathUtil_Random_ZeroOne() * 4.0f);
    sp2C.x = -0x4000;
    sp2C.y = 0;
    sp2C.z = (func_81400A78(0x10) << 0xB) - 0x4000;
    func_8140A4F0(arg0, sp2C);
    func_8140D5A0(arg0, func_8140C058(arg0));
    func_814081BC(arg0);
}

void func_8433D560(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8433D460(arg0);
            break;

        case 2:
            func_8140BA1C(arg0);
            func_8140BDD0(arg0);
            break;

        case 3:
            func_8140BC5C(arg0, 0, 0x40);
            break;

        case 4:
            func_81408158(arg0);
            break;
    }

    func_81409DAC(arg0);
}

void func_8433D604(unk_D_8140E720* arg0) {
    UNUSED s32 pad;
    Vec3s sp2C;
    UNUSED s32 pad2[2];

    func_8140C038(arg0);
    func_8140B938(arg0, 0.1f);
    func_8140B95C(arg0, 1.4f);
    func_8140B974(arg0, 0.1f);
    MathUtil_Random_ZeroOne();
    func_8140AD8C(arg0, 0.0f);
    sp2C.x = -0x4000;
    sp2C.y = 0;
    sp2C.z = (func_81400A78(0x10) << 0xB) - 0x4000;
    func_8140A4F0(arg0, sp2C);
    func_8140910C(arg0, 150.0f);
    func_8140A334(arg0);
    func_8140D5A0(arg0, func_8140C058(arg0));
    func_814081BC(arg0);
}

void func_8433D6EC(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8433D604(arg0);
            break;

        case 2:
            func_8140BDD0(arg0);
            break;

        case 3:
            func_8140BC5C(arg0, 0, 0x10);
            break;

        case 4:
            func_81408158(arg0);
            break;
    }

    func_8140BA1C(arg0);
    func_81409DAC(arg0);
}

void func_8433D790(unk_D_8140E720* arg0) {
    UNUSED s32 pad;
    Vec3s sp2C;
    UNUSED s32 pad2[2];

    func_8140C038(arg0);
    func_8140B938(arg0, 0.1f);
    func_8140B95C(arg0, 1.4f);
    func_8140B974(arg0, 0.1f);
    MathUtil_Random_ZeroOne();
    func_8140AD8C(arg0, 0.0f);
    sp2C.x = -0x4000;
    sp2C.y = 0;
    sp2C.z = 0;
    func_8140A4F0(arg0, sp2C);
    func_8140910C(arg0, 150.0f);
    func_8140A334(arg0);
    func_8140D5A0(arg0, func_8140C058(arg0));
    func_814081BC(arg0);
}

void func_8433D868(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8433D790(arg0);
            break;

        case 2:
            func_8140BDD0(arg0);
            break;

        case 3:
            func_8140BC5C(arg0, 0, 0x10);
            break;

        case 4:
            func_81408158(arg0);
            break;
    }

    func_8140BA1C(arg0);
    func_81409DAC(arg0);
}

void func_8433D90C(unk_D_8140E720* arg0) {
    UNUSED s32 pad;
    Vec3f sp30;
    Vec3s sp28;

    func_8140C038(arg0);
    func_8140B938(arg0, 0.1f);
    func_8140B95C(arg0, 2.0f);
    func_8140B974(arg0, 0.1f);
    sp28.x = 0;
    sp28.y = 0;
    sp28.z = -0x8000;
    func_8140A4F0(arg0, sp28);
    sp30.x = func_81400A78(0x64) + -50.0f;
    sp30.y = 200.0f;
    sp30.z = func_81400A78(0x64) + -50.0f;
    func_81408D78(arg0, sp30);
    func_8140D5A0(arg0, func_8140C058(arg0));
    func_814081BC(arg0);
}

void func_8433DA54(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8433D90C(arg0);
            break;

        case 2:
            func_8140BDD0(arg0);
            break;

        case 3:
            func_8140BC5C(arg0, 0, 0x40);
            break;

        case 4:
            func_81408158(arg0);
            break;
    }

    func_8140BA1C(arg0);
    func_81409DAC(arg0);
}

void func_8433DAF8(unk_D_8140E720* arg0) {
    UNUSED s32 pad[4];
    Vec3s sp28;

    func_8140C038(arg0);
    func_8140B938(arg0, 0.1f);
    func_8140B95C(arg0, 2.0f);
    func_8140B974(arg0, 0.1f);
    sp28.x = -0x1000 - func_81400A78(0x6000);
    sp28.y = func_81400A78(0x10000);
    sp28.z = func_81400A78(0x800) - 0x400;
    func_8140A4F0(arg0, sp28);
    func_8140910C(arg0, 200.0f);
    func_8140A578(arg0, -0x4000);
    func_8140D5A0(arg0, func_8140C058(arg0));
    func_814081BC(arg0);
}

void func_8433DBDC(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8433DAF8(arg0);
            break;

        case 2:
            func_8140BDD0(arg0);
            break;

        case 3:
            func_8140BC5C(arg0, 0, 0x40);
            break;

        case 4:
            func_81408158(arg0);
            break;
    }

    func_8140BA1C(arg0);
    func_81409DAC(arg0);
}

void func_8433DC80(void) {
    func_8432F8E8(0x64, 1);
    func_8432ED0C(0, 0x20, 3);
    func_8432ECA0(0, 3, 8, func_8433CCFC, &D_843861D0[0x11], 8, 4, 2, 0, 0x25, 0);
    func_8432EB2C(0x19);
    func_8432EC28(0, func_8433CEFC, &D_843861D0[0x15], 0xE, 1, 2, 0, 0x25, 0);
    func_8432EC28(0, func_8433CEFC, &D_843861D0[0x16], 0xE, 1, 2, 0, 0x25, 0);
    func_8432EE5C(8, 2, 8, 0xA, 0xFF);
    func_8432ECA0(8, 4, 2, func_8433D070, &D_843861D0[0xF], 0x14, 4, 7, 0, 0x25, 0);
    func_8432ECA0(8, 4, 2, func_8433D224, &D_843861D0[0xF], 0x14, 4, 7, 0, 0x25, 0);
    func_8432ECA0(8, 4, 2, func_8433D560, &D_843861D0[0x13], 0x14, 4, 7, 0, 0x25, 0);
    func_8432ECA0(8, 4, 2, func_8433D3B0, &D_843861D0[0x13], 0x14, 4, 7, 0, 0x25, 0);
}

void func_8433DECC(void) {
    func_8432EE5C(0x2C, 4, 0x10, 0xA, 0xFF);
    func_8432ED0C(0x30, 0x20, 0xA);
    func_8432ECA0(0, 8, 5, func_8433D3B0, &D_843861D0[0x12], 8, 3, 3, 0, 0x25, 0);
    func_8432ECA0(0, 4, 2, func_8433D070, &D_843861D0[0xF], 0x14, 4, 3, 0, 0x25, 0);
    func_8432ECA0(0, 4, 2, func_8433D224, &D_843861D0[0xF], 0x14, 4, 3, 0, 0x25, 0);
}

void func_8433DFF4(void) {
    func_8432EE5C(0, 4, 8, 0xA, 0xC8);
    func_8432ED0C(0x30, 0x20, 0xA);
    func_8432ECA0(0, 8, 5, func_8433D3B0, &D_843861D0[0x12], 8, 3, 3, 0, 0x25, 0);
    func_8432ECA0(0, 4, 2, func_8433D070, &D_843861D0[0xF], 0x14, 4, 3, 0, 0x25, 0);
    func_8432ECA0(0, 4, 2, func_8433D224, &D_843861D0[0xF], 0x14, 4, 3, 0, 0x25, 0);
    func_8434E6F4();
}

void func_8433E124(void) {
    func_8432F8E8(0x64, 1);
    func_8432ED0C(0, 0x10, 3);
    func_8432ECA0(0, 8, 3, func_8433D6EC, &D_843861D0[0x14], 2, 1, 2, 0, 0x25, 0);
    func_8432ECA0(0, 5, 5, func_8433D6EC, &D_843861D0[0x13], 2, 1, 2, 0, 0x25, 0);
    func_8432EB2C(0x23);
    func_8432EDE8(8, 4, 8, 0xA);
    func_8432ECA0(0, 4, 2, func_8433D560, &D_843861D0[0x13], 0x14, 4, 2, 0, 0x25, 0);
    func_8432ECA0(0, 5, 2, func_8433D3B0, &D_843861D0[0x13], 0x14, 4, 2, 0, 0x25, 0);
    func_8432ECA0(0, 6, 2, func_8433D070, &D_843861D0[0xF], 0x14, 2, 1, 0, 0x25, 0);
    func_8432ECA0(0, 4, 2, func_8433D224, &D_843861D0[0xF], 0x14, 2, 1, 0, 0x25, 0);
}

void func_8433E33C(void) {
    func_8432EDE8(0x22, 4, 0x10, 0xA);
    func_8432ED0C(0, 0x20, 3);
    func_8432ED0C(0x30, 0x20, 0xA);
    func_8432ECA0(0, 0xA, 2, func_8433DA54, &D_843861D0[0x10], 0xC, 1, 3, 0, 0x25, 0);
    func_8432ECA0(0, 5, 3, func_8433DBDC, &D_843861D0[0x10], 0xC, 2, 3, 0, 0x25, 0);
    func_8432ECA0(0, 8, 2, func_8433D6EC, &D_843861D0[0x13], 0xC, 3, 3, 0, 0x25, 0);
}

void func_8433E46C(void) {
    func_8432ECA0(0, 4, 5, func_8433CCFC, &D_843861D0[0x11], 8, 4, 0x10, D_843902E2, 0x25, 0);
    func_8432ECA0(0, 1, 0x24, func_8435375C, &D_843861D0[0x15], 0, 1, 0x11, D_843902E2, 0, 0);
}

void func_8433E524(void) {
    func_8432ECA0(8, 4, 2, func_8433D560, &D_843861D0[0x13], 0x14, 4, 7, 0, 0x2C, 0);
    func_8432ECA0(8, 4, 2, func_8433D3B0, &D_843861D0[0x13], 0x14, 3, 7, 0, 0xF, 0);
    func_8432EC28(8, func_8433D070, &D_843861D0[0xF], 0x14, 1, 7, 0, 0x2C, 0);
    func_8432EC28(8, func_8433D224, &D_843861D0[0xF], 0x14, 1, 7, 0, 0xF, 0);
}
