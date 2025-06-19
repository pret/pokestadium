#include "fragment62.h"

void func_8433FD80(unk_D_8140E720* arg0) {
    func_8140BAC8(arg0, 0xFF, 0xFF, 0xFF);
    func_8140BC20(arg0, 0xFF);
    func_814081BC(arg0);
}

void func_8433FDC0(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 0:
            break;

        case 1:
            func_8433FD80(arg0);
            break;

        case 2:
            func_8140B98C(arg0, 3.0f, 0.025f);
            func_8140826C(arg0, 0x12C);
            break;

        case 3:
            if (func_8140BC2C(arg0, 0x20, 0x20) != 0) {
                func_814081BC(arg0);
            }
            break;

        case 4:
            func_81408158(arg0);
            break;
    }

    func_8140B7C8(arg0, 32.0f, 0x400);
}

void func_8433FE80(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C038(arg0);

    func_8140B938(arg0, 0.2f);
    func_8140AF24(arg0, 1.0f);
    func_8140A2A4(arg0, func_81400A78(0x10000));
    func_8140A2CC(arg0, func_81400A78(0x10000));
    func_8140A3D8(arg0, func_81400A78(0x10000));
    func_8140AD8C(arg0, 5.0f);
    func_8140BCA8(arg0, sp26 * 4);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_8433FF44(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8433FE80(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
                func_81408A1C(arg0);
            }
            break;

        case 3:
            if (func_8140826C(arg0, 0x32) != 0) {
                func_81408A68(arg0);
            }
            break;

        case 4:
            if (func_8140826C(arg0, 0x14) != 0) {}
            break;

        case 5:
            func_81408158(arg0);
            break;
    }

    switch (arg0->unk_B8) {
        case 1:
            func_8140ADBC(arg0, 50.0f, 0.5f);
            func_814099E0(arg0, 1.0f);
            func_8140B7C8(arg0, arg0->unk_74, 0x1000);
            func_8140A578(arg0, 0x2000);
            func_8140A5B0(arg0, 0x3000);
            break;

        case 2:
            func_8140ADBC(arg0, 0.0f, 1.0f);
            func_814099E0(arg0, -2.0f);
            func_8140B7C8(arg0, arg0->unk_74, 0x1000);
            func_8140A578(arg0, 0x2000);
            func_8140A5B0(arg0, 0x3000);
            break;
    }
}

void func_843400BC(unk_D_8140E720* arg0) {
    s16 sp2E = func_8140C038(arg0);

    func_8140B938(arg0, 0.5f);
    func_8140AD8C(arg0, 10.0f);
    func_8140A52C(arg0, func_81400B00(0x1000), func_81400B00(0x1000), 0);
    func_8140BCA8(arg0, sp2E * 4);
    func_8140D530(arg0, 0x24);
    func_8140D568(arg0, 0x24);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_8434016C(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_843400BC(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            func_8140826C(arg0, 0x46);
            break;

        case 4:
            func_81408158(arg0);
            break;
    }

    if (func_81408368(arg0) != 0) {
        func_81409D0C(arg0);
        func_8140A5B0(arg0, 0x2000);
    }
}

void func_84340230(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C038(arg0);

    func_8140B938(arg0, 0.12f);
    func_8140AF24(arg0, (func_81400A78(0x14) * 0.02f) + 0.25f);
    func_8140A2A4(arg0, func_81400A78(0x10000));
    func_8140A2CC(arg0, func_81400A78(0x10000));
    func_8140AD8C(arg0, 5.0f);
    func_8140BF4C(arg0, func_81400A78(0x800) + 0xC00);
    func_8140A3C4(arg0, func_81400B4C(0x800, 0x300));
    func_8140BFEC(arg0, func_81400B4C(0x800, 0x300));
    func_8140A3D8(arg0, func_81400A78(0x10000));
    func_8140A3EC(arg0, func_81400B4C(0x800, 0x300));
    func_81408E90(arg0, func_81400A78(0x1E));
    func_8140BCA8(arg0, sp26 * 2);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_843403D8(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84340230(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
                func_81408A1C(arg0);
                func_8140BCA8(arg0, func_81400A78(0xA) + 0x1E);
            }
            break;

        case 3:
            if (func_8140BDD0(arg0) != 0) {
                func_8140BCA8(arg0, 8);
                func_81408A68(arg0);
            }
            break;

        case 4:
            if (func_8140BDD0(arg0) != 0) {
                func_8140A3C4(arg0, func_81400B4C(0x1000, 0x600));
                func_8140BFEC(arg0, func_81400B4C(0x400, 0x400));
                func_8140A3EC(arg0, func_81400B4C(0x1000, 0x600));
                arg0->unk_38.x += arg0->unk_50.x;
                arg0->unk_50.x = 0;
                arg0->unk_38.z += arg0->unk_50.z;
                arg0->unk_50.z = 0;
                func_81408A68(arg0);
                arg0->unk_7C.y = -((func_81400A78(8) * 0.1f) + 0.5f);
            }
            break;

        case 5:
            func_8140826C(arg0, 0x46);
            break;

        case 6:
            func_81408150(arg0);
            break;
    }

    switch (arg0->unk_B8) {
        case 1:
            func_8140ADBC(arg0, 20.0f, 0.5f);
            func_814099E0(arg0, arg0->unk_7C.y);
            func_8140B7C8(arg0, arg0->unk_74, arg0->unk_AE);
            break;

        case 2:
            func_8140BF60(arg0, 0, 0x200);
            func_814099E0(arg0, arg0->unk_7C.y);
            func_8140B7C8(arg0, arg0->unk_74, arg0->unk_AE);
            break;

        case 3:
            func_814099E0(arg0, arg0->unk_7C.y);
            func_8140B7C8(arg0, 5.0f, 0x400);
            break;
    }

    if (func_81408368(arg0) != 0) {
        func_8140A4B4(arg0);
        func_8140A594(arg0, arg0->unk_B0);
        func_8140A4DC(arg0);
        if (arg0->unk_2C.y < 0.0f) {
            func_81408150(arg0);
        }
    }
}

void func_84340690(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C038(arg0);
    s16 sp24 = func_8140C040(arg0);

    func_8140AF24(arg0, 0.5f);

    switch (sp24) {
        case 0:
            func_8140B938(arg0, 0.12f);
            arg0->unk_5C.y = -((func_81400A78(0xA) * 0.1f) + 0.5f);
            func_81408E90(arg0, func_81400A78(0x28) + 0x1E);
            func_81409404(arg0, 0x1E, 0);
            func_81409514(arg0, 0x1E, 0);
            break;

        case 1:
            func_8140B938(arg0, 0.2f);
            arg0->unk_5C.y = -((func_81400A78(4) * 0.1f) + 0.2f);
            func_81408E90(arg0, func_81400B00(0x14) + 0x1E);
            func_81409404(arg0, 0xF, 5);
            func_81409514(arg0, 0x14, 5);
            break;
    }

    func_8140A2A4(arg0, func_81400A78(0x10000));
    func_8140A2CC(arg0, func_81400A78(0x10000));
    func_8140AD8C(arg0, func_81400A78(0x14) + 15.0f);
    func_8140BF4C(arg0, func_81400A78(0x300) + 0x400);
    func_8140A3D8(arg0, func_81400A78(0x10000));
    func_8140A3C4(arg0, func_81400B4C(0x800, 0x400));
    func_8140A3EC(arg0, func_81400B4C(0x800, 0x400));
    func_8140BCA8(arg0, sp26 * 2);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84340940(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C040(arg0);

    switch (arg0->unk_B2) {
        case 1:
            func_84340690(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
                func_81408A1C(arg0);
                switch (sp26) {
                    case 0:
                        func_8140BCA8(arg0, func_81400A78(0x1E) + 0x32);
                        break;

                    case 1:
                        func_8140BCA8(arg0, func_81400A78(0x1E) + 0x64);
                        break;
                }
            }
            break;

        case 3:
            func_8140BDD0(arg0);
            break;

        case 4:
            func_81408150(arg0);
            break;
    }

    if (arg0->unk_B8 == 1) {
        func_814099E0(arg0, arg0->unk_5C.y);
        func_8140B7C8(arg0, 5.0f, 0x400);
    }

    if (func_81408368(arg0) != 0) {
        func_8140A4B4(arg0);
        func_8140A4C8(arg0);
        func_8140A4DC(arg0);
        if (arg0->unk_2C.y < 0.0f) {
            func_81408150(arg0);
        }
    }
}

void func_84340AC4(void) {
}

void func_84340ACC(void) {
    func_8432F8E8(0x80, 1);
    func_8432EC28(0, func_8433FF44, &D_843861D0[0x2B], 0, 0x10, 0xA, 0, 0, 0);
    func_8432EC28(2, func_8433FF44, &D_843861D0[0x2B], 0, 0x10, 0xA, 0, 0, 0);
    func_8432EC28(4, func_8433FF44, &D_843861D0[0x2B], 0, 0x10, 0xA, 0, 0, 0);
    func_8432EC28(8, func_8433FF44, &D_843861D0[0x2B], 0, 8, 0xA, 0, 0, 0);
    func_8432EB2C(0x3A);
    func_8432EC28(0, func_8434016C, &D_843861D0[0x2E], 0, 0x10, 2, 0, 0, 0);
    func_8432EC28(0, func_8434016C, &D_843861D0[0x2E], 0, 0x10, 2, 0, 0, 0);
    func_8432EC28(0, func_8434016C, &D_843861D0[0x2E], 0, 0x10, 2, 0, 0, 0);
    func_8432EC28(0, func_8434016C, &D_843861D0[0x2E], 0, 0x10, 2, 0, 0, 0);
}

void func_84340CB0(void) {
    func_8432ECA0(0, 2, 0x14, func_843403D8, &D_843861D0[0x2C], 0, 4, 0xE, 0, 0, 0);
    func_84357BA8();
}

void func_84340D14(void) {
    func_8432ECA0(0, 2, 5, func_84340940, &D_843861D0[0x2D], 0, 1, 0xE, 0, 0, 1);
    func_8432ECA0(0, 4, 5, func_84340940, &D_843861D0[0x2D], 0, 1, 0xE, 0, 0, 1);
}
