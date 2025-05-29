#include "fragment62.h"
#include "src/1C720.h"

void func_84333130(unk_D_8140E720* arg0, s16 arg1) {
    UNUSED s32 pad[3];
    s16 sp22 = func_8140C038(arg0);

    func_8140B938(arg0, 0.25f);
    func_8140A578(arg0, func_81400B28(0x400, 0xE00));
    func_8140A594(arg0, func_81400B00(0x400));
    func_8140AD8C(arg0, 2.5f);

    switch (arg1) {
        case 0:
            func_8140D5A0(arg0, 0x17);
            break;

        case 1:
            func_8140D5A0(arg0, 0x18);
            break;
    }

    func_8140BCA8(arg0, sp22 * 2);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84333210(unk_D_8140E720* arg0) {
    switch (arg0->unk_B8) {
        case 1:
            if (func_81408A78(arg0, 2) != 0) {
                func_81408A68(arg0);
            }
            break;

        case 2:
            func_8140A7DC(arg0, -0x400, 0x200);
            if (func_81408A78(arg0, 0x10) != 0) {
                func_81408A68(arg0);
            }
            break;
    }

    if (arg0->unk_B8 > 0) {
        func_81409D0C(arg0);
    }
}

void func_843332B4(unk_D_8140E720* arg0) {
    s16 sp2E = func_8140C058(arg0);

    switch (arg0->unk_B2) {
        case 1:
            func_84333130(arg0, sp2E);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408A1C(arg0);
                func_81408328(arg0);
                func_8140BCA8(arg0, 0xB);
            }
            break;

        case 3:
            func_8140B98C(arg0, 0.75f, 0.03f);

            switch (sp2E) {
                case 0:
                    func_8140BB44(arg0, 0, 0x18);
                    func_8140BBF0(arg0, 0, 0x18);
                    break;

                case 1:
                    func_8140BAE4(arg0, 0, 0x18);
                    func_8140BBF0(arg0, 0x78, 0xC);
                    break;
            }

            if (func_8140BDD0(arg0) != 0) {
                func_8140BCA8(arg0, 0xC);
            }
            break;

        case 4:
            func_8140B98C(arg0, 0.75f, 0.02f);
            switch (sp2E) {
                case 0:
                    func_8140BB14(arg0, 0, 0x10);
                    func_8140BB90(arg0, 0, 0x10);
                    break;

                case 1:
                    func_8140BB14(arg0, 0x78, 0xC);
                    func_8140BBF0(arg0, 0, 0xA);
                    break;
            }

            if ((func_8140BDAC(arg0) != 0) && (func_8140BC2C(arg0, 0, 0x18) != 0)) {
                func_814081BC(arg0);
            }
            break;

        case 5:
            func_81408150(arg0);
            break;
    }

    if (func_81408368(arg0) != 0) {
        func_814083FC(arg0, 0, 7, 1, 2, -1);
        func_84333210(arg0);
    }
}

void func_843334DC(unk_D_8140E720* arg0) {
    UNUSED s32 pad[3];
    s16 sp22 = func_8140C038(arg0);

    func_8140B938(arg0, 0.25f);
    func_8140A594(arg0, func_81400B00(0x400));
    func_8140AD8C(arg0, D_84392058[0]);
    func_8140D5A0(arg0, 0x17);
    func_8140BCA8(arg0, sp22 * 2);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84333570(unk_D_8140E720* arg0) {
    switch (arg0->unk_B8) {
        case 1:
            if (func_81408A78(arg0, 2) != 0) {
                func_81408A68(arg0);
                func_8140A5B0(arg0, 0x2900);
            }
            break;

        case 2:
            func_8140A578(arg0, 0xC00);
            break;
    }

    if (arg0->unk_B8 > 0) {
        func_81409E24(arg0);
    }
}

void func_84333600(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_843334DC(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408A1C(arg0);
                func_81408328(arg0);
                func_8140BCA8(arg0, 0xB);
            }
            break;

        case 3:
            func_8140B98C(arg0, 0.75f, 0.03f);
            func_8140BB44(arg0, 0, 0x18);
            func_8140BBF0(arg0, 0, 0x20);
            if (func_8140BDD0(arg0) != 0) {
                func_8140BCA8(arg0, 0xC);
            }
            break;

        case 4:
            func_8140B98C(arg0, 0.75f, 0.02f);
            func_8140BB14(arg0, 0, 0x10);
            func_8140BB90(arg0, 0, 0x10);
            if ((func_8140BDAC(arg0) != 0) && (func_8140BC2C(arg0, 0, 0xC) != 0)) {
                func_814081BC(arg0);
            }
            break;

        case 5:
            func_81408150(arg0);
            break;
    }

    if (func_81408368(arg0) != 0) {
        func_814083FC(arg0, 0, 7, 1, 2, -1);
        func_84333570(arg0);
    }
}

void func_8433378C(unk_D_8140E720* arg0) {
    UNUSED s32 pad[3];
    s16 sp22 = func_8140C038(arg0);
    s16 sp20 = func_8140C058(arg0);

    func_8140B938(arg0, 0.4f);
    func_8140A578(arg0, func_81400B28(0x200, 0xE00));
    func_8140A594(arg0, func_81400B00(0x1800));
    func_8140AD8C(arg0, 2.0f);

    switch (sp20) {
        case 0:
            func_8140D5A0(arg0, 0x1A);
            break;

        case 1:
            func_8140D5A0(arg0, 6);
            break;
    }

    func_8140BC20(arg0, 0xC8);
    func_8140BCA8(arg0, sp22 * 2);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84333884(unk_D_8140E720* arg0) {
    switch (arg0->unk_B8) {
        case 1:
            if (func_81408A78(arg0, 1) != 0) {
                func_81408A68(arg0);
            }
            break;

        case 2:
            func_8140A7DC(arg0, -0x1800, 0x800);
            if (func_81408A78(arg0, 0x10) != 0) {
                func_81408A68(arg0);
            }
            break;
    }

    if (arg0->unk_B8 > 0) {
        func_81409D0C(arg0);
    }
}

void func_84333928(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8433378C(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408A1C(arg0);
                func_81408328(arg0);
            }
            break;

        case 3:
            func_814084D8(arg0, 0, 7, 1, 2, 0);
            func_8140BC2C(arg0, 0x20, 4);
            func_8140B98C(arg0, 0.75f, 0.05f);
            break;

        case 4:
            func_81408150(arg0);
            break;
    }

    if (func_81408368(arg0) != 0) {
        func_84333884(arg0);
    }
}

void func_84333A20(unk_D_8140E720* arg0, s16 arg1) {
    UNUSED s32 pad[3];
    s16 sp22 = func_8140C038(arg0);

    func_8140B938(arg0, 0.2f);
    func_8140A578(arg0, func_81400B28(0x200, 0xE00));
    func_8140A594(arg0, func_81400B00(0x2000));
    func_8140AD8C(arg0, 2.0f);

    switch (arg1) {
        case 0:
            func_8140D5A0(arg0, 0x17);
            break;

        case 1:
            func_8140D5A0(arg0, 0x18);
            break;
    }

    func_8140BCA8(arg0, sp22 * 2);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84333B04(unk_D_8140E720* arg0) {
    switch (arg0->unk_B8) {
        case 1:
            if (func_81408A78(arg0, arg0->unk_AE) != 0) {
                func_81408A68(arg0);
            }
            break;

        case 2:
            func_8140A76C(arg0, 0x4000, 0x800);
            if (func_81408A78(arg0, 0x10) != 0) {
                func_81408A68(arg0);
            }
            break;
    }

    if (arg0->unk_B8 > 0) {
        func_81409D0C(arg0);
    }
}

void func_84333BA8(unk_D_8140E720* arg0) {
    s16 temp_v0 = func_8140C058(arg0);

    switch (arg0->unk_B2) {
        case 1:
            func_84333A20(arg0, temp_v0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408A1C(arg0);
                func_81408328(arg0);
                func_8140BF4C(arg0, func_81400A78(3));
                func_8140BCA8(arg0, 8);
            }
            break;

        case 3:
            switch (temp_v0) {
                case 0:
                    func_8140BB44(arg0, 0, 0x20);
                    func_8140BBF0(arg0, 0, 0x20);
                    break;

                case 1:
                    func_8140BAE4(arg0, 0, 0x20);
                    func_8140BBF0(arg0, 0x78, 0x10);
                    break;
            }
            func_8140BDD0(arg0);
            break;

        case 4:
            switch (temp_v0) {
                case 0:
                    func_8140BB14(arg0, 0, 0x20);
                    func_8140BB90(arg0, 0, 0x20);
                    break;

                case 1:
                    func_8140BB14(arg0, 0x78, 0xC);
                    func_8140BBF0(arg0, 0, 0xA);
                    break;
            }

            if (func_8140BC2C(arg0, 0, 0x18) != 0) {
                func_814081BC(arg0);
            }
            break;

        case 5:
            func_81408150(arg0);
            break;
    }

    if (func_81408368(arg0) != 0) {
        func_814083FC(arg0, 0, 7, 1, 2, -1);
        func_8140B98C(arg0, 0.02f, 0.015f);
        func_84333B04(arg0);
        if (arg0->unk_2C.y <= 0.0f) {
            func_81408150(arg0);
        }
    }
}

void func_84333DC4(unk_D_8140E720* arg0) {
    func_81408F38(arg0, 33.0f);
    func_8140B938(arg0, 0.67f);
    func_8140D530(arg0, func_8140C058(arg0));
    func_8140BC20(arg0, 0xC8);
    func_814081BC(arg0);
}

void func_84333E28(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84333DC4(arg0);
            break;

        case 2:
            if (func_8140B98C(arg0, 6.67f, 0.67f) != 0) {
                func_814081BC(arg0);
            }
            break;

        case 3:
            func_8140826C(arg0, 0);
            break;

        case 4:
            if (func_8140BC2C(arg0, 0x20, 8) != 0) {
                func_814081BC(arg0);
            }
            break;

        case 5:
            func_81408158(arg0);
            break;
    }
}

void func_84333EE8(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84333DC4(arg0);
            break;

        case 2:
            if (func_8140B98C(arg0, 8.0f, 1.0f) != 0) {
                func_814081BC(arg0);
            }
            break;

        case 3:
            func_8140826C(arg0, 8);
            break;

        case 4:
            if (func_8140BC2C(arg0, 0x20, 8) != 0) {
                func_814081BC(arg0);
            }
            break;

        case 5:
            func_81408158(arg0);
            break;
    }

    func_8140A5B0(arg0, 0x1000);
}

void func_84333FBC(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84333DC4(arg0);
            break;

        case 2:
            if (func_8140B98C(arg0, 8.0f, 1.0f) != 0) {
                func_814081BC(arg0);
            }
            break;

        case 3:
            func_8140826C(arg0, 8);
            break;

        case 4:
            if (func_8140BC2C(arg0, 0x20, 8) != 0) {
                func_814081BC(arg0);
            }
            break;

        case 5:
            func_81408158(arg0);
            break;
    }

    func_8140A5B0(arg0, 0x1000);

    if (D_8140E6CC == 0) {
        func_8140D658(arg0, func_81400A78(6));
    }
}

void func_843340B8(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C038(arg0);

    func_8140B938(arg0, 0.5f);
    func_8140AF24(arg0, 2.0f);
    func_8140A3D8(arg0, func_81400A78(0x10000));
    func_8140D5A0(arg0, 0x1A);
    func_8140BC20(arg0, 0xFF);
    func_8140BCA8(arg0, sp26 * 4);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84334154(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_843340B8(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
                func_8140BCA8(arg0, 0x10);
            }
            break;

        case 3:
            func_814084D8(arg0, 0, 7, 1, 2, -1);
            func_8140B98C(arg0, 1.0f, 0.1f);
            func_814099E0(arg0, 2.0f);
            func_8140B7C8(arg0, 10.0f, 0x800);
            func_8140BB14(arg0, 0, 4);
            func_8140BB90(arg0, 0, 4);
            if ((func_8140BDAC(arg0) != 0) && (func_8140BC2C(arg0, 0, 0x18) != 0)) {
                func_814081BC(arg0);
            }
            break;

        case 4:
            func_81408158(arg0);
            break;
    }
}

void func_84334294(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C038(arg0);

    func_8140B938(arg0, 0.5f);
    func_81408CA0(arg0, 10.0f);
    func_8140AF24(arg0, 1.0f);
    func_8140D5A0(arg0, 0x1A);
    func_8140BC20(arg0, 0xFF);
    func_81408348(arg0);
    func_8140A3D8(arg0, (sp26 << 0x10) / 18);
    func_8140BCA8(arg0, sp26 * 3);
    func_814081BC(arg0);
}

void func_84334350(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84334294(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            func_8140B98C(arg0, 1.0f, 0.1f);
            break;
    }

    if (func_81408368(arg0) != 0) {
        func_8140B7C8(arg0, 50.0f, 0);
    }
}

void func_843343F8(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C038(arg0);

    func_8140B938(arg0, 1.0f);
    func_81408CA0(arg0, 10.0f);
    func_8140AF24(arg0, 1.0f);
    func_8140D5A0(arg0, 0x1A);
    func_8140BC20(arg0, 0xFF);
    func_81408348(arg0);
    func_8140A3D8(arg0, (sp26 << 0x10) / 18);
    func_8140BCA8(arg0, 0);
    func_814081BC(arg0);
}

void func_843344A0(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 3:
            break;

        case 1:
            func_843343F8(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
            }
            break;

        case 4:
            func_8140BC5C(arg0, 0, 0x10);
            break;

        case 5:
            func_81408158(arg0);
            break;
    }

    if (func_81408368(arg0) != 0) {
        func_8140B7C8(arg0, 50.0f, 0);
    }
}

void func_84334558(unk_D_8140E720* arg0) {
    func_8140B938(arg0, 0.4f);
    func_8140D5A0(arg0, 0x1A);
    func_8140BC20(arg0, 0xA0);
    func_814081BC(arg0);
}

void func_843345A0(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84334558(arg0);
            break;

        case 2:
            func_814084D8(arg0, 2, 7, 1, 2, 0);
            func_8140BC2C(arg0, 0x20, 0x18);
            break;

        case 3:
            func_81408158(arg0);
            break;
    }

    func_8140B98C(arg0, 0.6f, 0.05f);
}

void func_84334654(unk_D_8140E720* arg0) {
    func_8140B938(arg0, 0.4f);
    func_8140AD8C(arg0, 8.0f);
    func_8140D5A0(arg0, 0x29);
    func_814083E8(arg0, 2);
    func_8140BC20(arg0, 0xFF);
    func_814081BC(arg0);
}

void func_843346BC(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84334654(arg0);
            break;

        case 2:
            func_814084D8(arg0, 3, 5, 1, 1, 0);
            break;

        case 3:
            func_8140826C(arg0, 0xF);
            break;

        case 4:
            func_81408158(arg0);
            break;
    }

    if (func_81408368(arg0) != 0) {
        func_8140D908(arg0, 0x2A, 0x1C);
        func_81409D0C(arg0);
        func_8432D844(arg0, func_843345A0, &D_843861D0[0x4A], 1);
    }
}

void func_843347A4(unk_D_8140E720* arg0) {
    func_8140C038(arg0);
    func_8140AD8C(arg0, 0.2f);
    func_8140B938(arg0, 1.0f);
    func_8140D5A0(arg0, 0x1D);
    func_8140BC20(arg0, 0xFF);
    func_814081BC(arg0);
}

void func_84334808(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_843347A4(arg0);
            break;

        case 2:
            func_8140826C(arg0, 1);
            break;

        case 3:
            func_814084D8(arg0, 0, 3, 1, 2, 0);
            func_81409EA0(arg0);
            func_8140D908(arg0, 0, 0x20);
            func_8140B98C(arg0, 1.5f, 0.1f);
            break;

        case 4:
            func_81408150(arg0);
            break;
    }
}

void func_843348DC(unk_D_8140E720* arg0) {
    Vec3s sp28;
    UNUSED s32 pad[1];

    func_8140C058(arg0);
    func_8140C038(arg0);
    func_8140B938(arg0, 0.45f);
    sp28.x = func_81400B00(0x2000);
    sp28.y = func_81400B28(0x3000, 0);
    sp28.z = 0;
    func_8140A4F0(arg0, sp28);
    func_8140D5A0(arg0, 0x1D);
    func_8140BC20(arg0, 0x64);
    func_8140AD8C(arg0, 2.5f);
    func_814081BC(arg0);
}

void func_84334994(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_843348DC(arg0);
            break;

        case 2:
            func_814084D8(arg0, 0, 7, 1, 2, 0);
            func_8140ADBC(arg0, 0.5, 0.5f);
            func_8140BC2C(arg0, 0x20, 4);
            break;

        case 3:
            func_81408150(arg0);
            break;
    }

    if (func_8140819C(arg0) != 0) {
        func_8140B98C(arg0, 0.75f, 0.1f);
        func_81409D0C(arg0);
        func_8140D908(arg0, 0x1A, 0x10);
    }
}

void func_84334A78(unk_D_8140E720* arg0, u8 arg1) {
    u16 sp1E;

    func_8140BEF8(arg0, arg1);

    switch (arg1) {
        case 0:
            sp1E = 0x1A;
            break;

        case 1:
            sp1E = 0x2A;
            break;

        case 2:
            sp1E = 0x24;
            break;

        case 3:
            sp1E = 0x2C;
            break;
    }

    func_8140D5A0(arg0, sp1E);
}

void func_84334B04(void) {
}

void func_84334B0C(unk_D_8140E720* arg0) {
    UNUSED u16 pad;
    u16 sp1C;
    u16 sp1A;

    switch (func_8140C058(arg0)) {
        case 0:
            sp1C = 0x2E;
            sp1A = 0x10;
            break;

        case 1:
            sp1C = 0x2D;
            sp1A = 0x10;
            break;

        case 2:
            sp1C = 0x2D;
            sp1A = 0x10;
            break;

        case 3:
            sp1C = 0x2B;
            sp1A = 0x10;
            break;
    }

    func_8140D908(arg0, sp1C, sp1A);
}

void func_84334BAC(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C038(arg0);
    s16 sp24 = func_8140C058(arg0);
    s16 sp22 = func_8140C040(arg0);

    switch (sp26) {
        case 0:
            func_81408BE0(arg0, 0.0f, -5.0f, 0.0f);
            break;

        case 1:
            func_81408BE0(arg0, 0.0f, 5.0f, 5.0f);
            break;

        case 2:
            func_81408BE0(arg0, 0.0f, 5.0f, -5.0f);
            break;
    }

    switch (sp22) {
        case 0:
            func_8140B938(arg0, 0.5f);
            func_8140B95C(arg0, 1.0f);
            func_8140B974(arg0, 0.1f);
            break;

        case 1:
            func_8140B938(arg0, 0.75f);
            func_8140B95C(arg0, 1.5f);
            func_8140B974(arg0, 0.15f);
            break;

        case 2:
            func_8140B938(arg0, 1.0f);
            func_8140B95C(arg0, 2.0f);
            func_8140B974(arg0, 0.2f);
            break;
    }

    func_8140D5A0(arg0, sp24);
    func_814083E8(arg0, 1);
    func_8140BC20(arg0, 0xC8);
    func_8140BCA8(arg0, sp26 * 2);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84334D7C(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84334BAC(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            func_8140BA1C(arg0);
            func_814084D8(arg0, 2, 7, 1, 1, 0);
            if (arg0->unk_C7 >= 6) {
                func_8140BC2C(arg0, 0x64, 0x4E);
            }
            break;

        case 4:
            func_81408150(arg0);
            break;
    }
}

void func_84334E4C(unk_D_8140E720* arg0) {
    Vec3f sp2C;
    s16 sp2A;
    s16 sp28;

    sp2A = func_8140C038(arg0);
    sp28 = func_8140C058(arg0);
    sp2C.x = func_81400B00(0xA);
    sp2C.y = func_81400B28(0xF, 0xA);
    sp2C.z = func_81400B00(0xF);
    func_81408D78(arg0, sp2C);
    func_8140AD8C(arg0, (func_81400A78(5) * 0.25f) + 3.0f);
    func_8140B938(arg0, 0.75f);
    func_8140D5A0(arg0, sp28);
    func_8140BC20(arg0, 0xFF);
    func_8140BCA8(arg0, sp2A * 2);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84334F84(unk_D_8140E720* arg0) {
    func_8140C040(arg0);

    switch (arg0->unk_B2) {
        case 1:
            func_84334E4C(arg0);
            break;
        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            func_81409EA0(arg0);
            func_8140BA1C(arg0);
            func_814084D8(arg0, 1, 7, 1, 1, 0);

            if (arg0->unk_C7 >= 6) {
                func_8140BC2C(arg0, 0x64, 0x4E);
            }

            if (arg0->unk_C7 >= 4) {}
            break;

        case 4:
            func_81408150(arg0);
            break;
    }
}

void func_8433507C(unk_D_8140E720* arg0) {
    Vec3s sp30;
    Vec3f sp24;
    s16 sp22;
    s16 sp20;

    sp22 = func_8140C038(arg0);
    sp20 = func_8140C058(arg0);
    sp24.x = func_81400B00(0xA);
    sp24.y = func_81400B28(0xA, 5);
    sp24.z = func_81400B00(0xA);
    func_81408D78(arg0, sp24);
    func_8140B938(arg0, 1.0f);
    func_8140AD8C(arg0, 0.5f);
    sp30.x = func_81400B00(0x2000);
    sp30.y = func_81400B00(0x2000);
    sp30.z = 0;
    func_8140A4F0(arg0, sp30);
    func_8140D5A0(arg0, sp20);
    func_8140BC20(arg0, 0xC8);
    func_8140BCA8(arg0, sp22 * 2);
    func_814083E8(arg0, 2);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_843351C8(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8433507C(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            func_814084D8(arg0, 2, 7, 1, 1, 0);
            func_8140B98C(arg0, 1.2f, 0.05f);
            func_8140BC2C(arg0, 0x64, 0x10);
            func_81409D0C(arg0);
            break;

        case 4:
            func_81408158(arg0);
            break;
    }
}

void func_843352AC(unk_D_8140E720* arg0) {
    s16 sp36 = func_8140C038(arg0);
    Vec3s sp30;
    UNUSED s32 pad[3];

    func_8140959C(arg0, 5, 5, 5);
    func_8140B938(arg0, 0.5f);
    func_8140AD8C(arg0, 1.0f);
    sp30.x = 0x2000 - func_81400A78(0x4000);
    sp30.y = 0x2000 - func_81400A78(0x4000);
    sp30.z = 0;
    func_8140A4F0(arg0, sp30);
    func_8140A5CC(arg0, sp30.x, sp30.y);
    func_8140A3A0(arg0, 0, 0);
    func_8140D5A0(arg0, 0x1A);
    func_8140BC20(arg0, 0xC8);
    func_8140BCA8(arg0, sp36 * 3);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_843353C4(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_843352AC(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_8140BCA8(arg0, 0xA);
                func_81408328(arg0);
            }
            break;

        case 3:
            func_8140B98C(arg0, 1.0f, 0.1f);
            func_8140BAE4(arg0, 0, 0xC);
            func_8140BB14(arg0, 0, 0x20);
            func_81409D0C(arg0);
            func_81408E90(arg0, 0.4f);
            func_84334B0C(arg0);
            if ((func_8140BDAC(arg0) != 0) && (func_8140BC2C(arg0, 0x20, 0x10) != 0)) {
                func_814081BC(arg0);
            }
            break;

        case 4:
            func_81408158(arg0);
            break;
    }
}

void func_843354E0(unk_D_8140E720* arg0) {
    s16 sp36 = func_8140C038(arg0);
    Vec3s sp30;
    Vec3f sp24;

    sp24.x = func_81400B00(0x19);
    sp24.y = func_81400B28(0xF, 5);
    sp24.z = func_81400B00(0xA);
    func_81408D78(arg0, sp24);
    func_8140B938(arg0, 0.15f);
    func_8140AD8C(arg0, 0.5f);
    sp30.x = 0x2000 - func_81400A78(0x4000);
    sp30.y = 0x2000 - func_81400A78(0x4000);
    sp30.z = 0;
    func_8140A4F0(arg0, sp30);
    func_8140A5CC(arg0, sp30.x, sp30.y);
    func_8140A3A0(arg0, 0, 0);
    func_84334A78(arg0, (sp36 % 4) & 0xFF);
    func_8140BC20(arg0, 0xC8);
    func_8140BCA8(arg0, sp36 * 1);
    func_814083E8(arg0, 2);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84335668(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_843354E0(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            func_814084D8(arg0, 2, 7, 1, 1, 0);
            func_8140B98C(arg0, 0.45000002f, 0.075f);
            func_8140BC2C(arg0, 0x64, 0x10);
            func_81409D0C(arg0);
            break;

        case 4:
            func_81408158(arg0);
            break;
    }
}

void func_8433574C(unk_D_8140E720* arg0) {
    s16 sp36 = func_8140C038(arg0);
    Vec3s sp30;
    UNUSED s32 pad[3];

    func_8140959C(arg0, 5, 0xA, 0xA);
    func_8140B938(arg0, 0.90000004f);
    func_8140AD8C(arg0, 1.0f);
    sp30.x = func_81400B00(0x2000);
    sp30.y = func_81400A78(0x10000);
    sp30.z = 0;
    func_8140A4F0(arg0, sp30);
    func_84334A78(arg0, (sp36 % 4) & 0xFF);
    func_8140BC20(arg0, 0xC8);
    func_8140BCA8(arg0, 0);
    func_814083E8(arg0, 2);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84335848(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8433574C(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_8140BCA8(arg0, 5);
                func_81408328(arg0);
            }
            break;

        case 3:
            func_814084D8(arg0, 0, 7, 1, 2, 0);
            func_8140B98C(arg0, 1.05f, 0.075f);
            func_8140ADBC(arg0, 0.5, 0.5f);
            func_81409D0C(arg0);
            if (func_8140BDAC(arg0) != 0) {
                func_814099E0(arg0, 0.5f);
                func_8140BC2C(arg0, 0x64, 0x10);
            }
            break;

        case 4:
            func_81408150(arg0);
            break;
    }
}

void func_8433595C(unk_D_8140E720* arg0) {
    s16 sp36 = func_8140C038(arg0);
    Vec3s sp30;
    UNUSED s32 pad[3];

    func_8140959C(arg0, 5, 5, 5);
    func_8140B938(arg0, 0.75f);
    func_8140AD8C(arg0, 1.0f);
    sp30.x = 0x2000 - func_81400A78(0x4000);
    sp30.y = func_81400A78(0x10000);
    sp30.z = 0;
    func_8140A4F0(arg0, sp30);
    func_8140A5CC(arg0, sp30.x, sp30.y);
    func_8140A3A0(arg0, 0, 0);
    func_84334A78(arg0, (sp36 % 4) & 0xFF);
    func_8140BC20(arg0, 0xC8);
    func_8140BCA8(arg0, sp36 * 3);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84335A84(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8433595C(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_8140BCA8(arg0, 0xA);
                func_81408328(arg0);
            }
            break;

        case 3:
            func_8140BAE4(arg0, 0, 0xC);
            func_8140BB14(arg0, 0, 0x20);
            func_8140B98C(arg0, 1.5f, 0.15f);
            func_84334B0C(arg0);
            func_81409D0C(arg0);
            func_81408E90(arg0, 0.4f);
            if ((func_8140BDAC(arg0) != 0) && (func_8140BC2C(arg0, 0x20, 0x10) != 0)) {
                func_814081BC(arg0);
            }
            break;

        case 4:
            func_81408158(arg0);
            break;
    }
}

void func_84335BA0(unk_D_8140E720* arg0) {
    s16 sp36;
    Vec3s sp30;
    Vec3f sp24;

    sp36 = func_8140C038(arg0);
    sp24.x = func_81400B00(0x14);
    sp24.y = func_81400B28(0xF, 0xA);
    sp24.z = func_81400B00(0xF);
    func_81408D78(arg0, sp24);
    func_8140B938(arg0, 0.1f);
    sp30.x = func_81400A78(0x10000);
    sp30.y = func_81400A78(0x10000);
    sp30.z = 0;
    func_8140A4F0(arg0, sp30);
    func_8140A5CC(arg0, sp30.x, sp30.y);
    func_8140A3A0(arg0, 0, 0);
    func_84334A78(arg0, (sp36 % 4) & 0xFF);
    func_8140BC20(arg0, 0xC8);
    func_8140BCA8(arg0, sp36 * 2);
    func_814083E8(arg0, 2);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84335D10(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84335BA0(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            func_814084D8(arg0, 2, 7, 1, 1, 0);
            func_8140B98C(arg0, 0.3f, 0.05f);
            func_8140BC2C(arg0, 0x64, 0x10);
            break;

        case 4:
            func_81408158(arg0);
            break;
    }
}

void func_84335DEC(unk_D_8140E720* arg0) {
    s16 temp_s1 = func_8140C038(arg0);

    func_8140B938(arg0, 0.75f);

    switch (temp_s1) {
        case 0:
            func_81408BE0(arg0, 0.0f, -3.0f, 0.0f);
            break;

        case 1:
            func_81408BE0(arg0, 0.0f, 3.0f, 3.0f);
            break;

        case 2:
            func_81408BE0(arg0, 0.0f, 3.0f, -3.0f);
            break;
    }

    func_8140D5A0(arg0, 0x17);
    func_8140BC20(arg0, 0xFF);
    func_8140BCA8(arg0, temp_s1 * 4);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84335EF8(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84335DEC(arg0);
            break;

        case 2:
            if (func_8140826C(arg0, arg0->unk_A6) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            func_814084D8(arg0, 0, 7, 1, 1, 0);
            func_8140B98C(arg0, 1.0f, 0.02f);
            func_8140BB44(arg0, 0, 0x20);
            func_8140BBF0(arg0, 0, 0x20);
            if (arg0->unk_C7 >= 6) {
                func_8140BB14(arg0, 0, 0x20);
                func_8140BC2C(arg0, 0x64, 0x4E);
            }
            break;

        case 4:
            func_81408150(arg0);
            break;
    }
}

void func_84336014(unk_D_8140E720* arg0, s16 arg1, s16 arg2) {
    UNUSED s32 pad[2];
    s16 sp26 = func_8140C038(arg0);

    func_81408CA0(arg0, -10.0f);
    func_81408ED0(arg0, 50.0f);
    func_8140B938(arg0, 0.5f);
    func_8140AD8C(arg0, 5.0f);

    switch (arg1) {
        case 0:
            func_8140A578(arg0, func_81400B00(0x800));
            func_8140A594(arg0, func_81400B28(0x1000, 0x8000));
            break;

        case 1:
            func_8140A578(arg0, func_81400B00(0xA00));
            func_8140A594(arg0, func_81400B4C(0xD00, 0xF400) + 0x8000);
            break;
    }

    switch (arg2) {
        case 0:
            func_8140D5A0(arg0, 0x1A);
            break;

        case 1:
            func_8140D5A0(arg0, 6);
            break;
    }

    func_8140BC20(arg0, 0xC8);
    func_8140BCA8(arg0, sp26 * 4);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_8433617C(unk_D_8140E720* arg0, s32 arg1) {
    s16 temp_v0 = func_8140C058(arg0);

    switch (arg0->unk_B2) {
        case 1:
            func_84336014(arg0, arg1, temp_v0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            func_8140BCA8(arg0, 0xC);
            func_814081BC(arg0);
            break;

        case 4:
            switch (temp_v0) {
                case 0:
                    func_8140BB14(arg0, 0, 0x10);
                    func_8140BB90(arg0, 0, 0x10);
                    break;

                case 1:
                    func_8140BB14(arg0, 0, 0xA);
                    func_8140BBF0(arg0, 0, 5);
                    break;
            }

            if ((func_8140BDAC(arg0) != 0) && (func_8140BC2C(arg0, 0, 0x18) != 0)) {
                func_814081BC(arg0);
            }
            break;

        case 5:
            func_81408158(arg0);
            break;
    }

    if (func_81408368(arg0) != 0) {
        func_8140A76C(arg0, -0xC00, 0x100);
        func_8140B98C(arg0, 1.2f, 0.04f);
        func_81409D0C(arg0);
        func_814083FC(arg0, 0, 7, 1, 2, -1);
    }
}

void func_84336320(unk_D_8140E720* arg0) {
    func_8433617C(arg0, 0);
}

void func_84336340(unk_D_8140E720* arg0) {
    func_8433617C(arg0, 1);
}

void func_84336360(unk_D_8140E720* arg0) {
    s16 sp36 = func_8140C058(arg0);
    UNUSED s32 pad[3];
    s16 sp26 = func_8140C038(arg0);

    func_8140B938(arg0, 0.4f);
    func_81408ED0(arg0, 15.0f);
    func_8140A578(arg0, func_81400B28(0x200, 0xE00));
    func_8140A594(arg0, func_81400B28(0x3800, 0x8000));
    func_8140A400(arg0, -0x4000);
    func_8140A3C4(arg0, 0x1000);
    func_8140AD8C(arg0, 3.0f);

    switch (sp36) {
        case 0:
            func_8140D5A0(arg0, 0x1A);
            break;

        case 1:
            func_8140D5A0(arg0, 6);
            break;
    }

    func_8140BC20(arg0, 0xC8);
    func_8140BCA8(arg0, sp26 * 2);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84336480(unk_D_8140E720* arg0) {
    switch (arg0->unk_B8) {
        case 1:
            if (func_81408A78(arg0, 1) != 0) {
                func_81408A68(arg0);
            }
            break;

        case 2:
            func_8140A690(arg0);
            if (func_81408A78(arg0, 0x10) != 0) {
                func_81408A68(arg0);
            }
            break;
    }

    if (arg0->unk_B8 > 0) {
        func_81409D0C(arg0);
    }
}

void func_84336520(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84336360(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408A1C(arg0);
                func_81408328(arg0);
            }
            break;

        case 3:
            func_814084D8(arg0, 0, 7, 1, 2, 0);
            func_8140BC2C(arg0, 0x20, 4);
            func_8140B98C(arg0, 1.2f, 0.1f);
            break;

        case 4:
            func_81408150(arg0);
            break;
    }

    if (func_81408368(arg0) != 0) {
        func_84336480(arg0);
    }
}

void func_8433661C(unk_D_8140E720* arg0) {
    UNUSED s32 pad[3];
    s16 sp22 = func_8140C038(arg0);
    s16 sp20 = func_8140C058(arg0);

    func_8140B938(arg0, 0.6f);
    func_81408E90(arg0, 15.0f);
    func_81408F38(arg0, 20.0f);

    switch (sp20) {
        case 0:
            func_8140AD8C(arg0, 1.5f);
            func_8140A578(arg0, -0x4000);
            break;

        case 1:
            func_8140AD8C(arg0, 2.0f);
            func_8140A594(arg0, 0x4000);
            func_8140A578(arg0, -0xE00);
            break;

        case 2:
            func_8140AD8C(arg0, 2.0f);
            func_8140A594(arg0, -0x4000);
            func_8140A578(arg0, -0xE00);
            break;

        case 3:
            func_8140AD8C(arg0, 2.5f);
            func_8140A594(arg0, 0x4000);
            func_8140A578(arg0, 0x2000);
            break;

        case 4:
            func_8140AD8C(arg0, 2.5f);
            func_8140A594(arg0, -0x4000);
            func_8140A578(arg0, 0x2000);
            break;
    }

    func_8140D5A0(arg0, 0x17);
    func_8140BCA8(arg0, sp22 * 2);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_8433679C(unk_D_8140E720* arg0) {
    switch (arg0->unk_B8) {
        case 1:
            if (func_81408A78(arg0, 2) != 0) {
                func_81408A68(arg0);
            }
            break;

        case 2:
            if (func_81408A78(arg0, 0x10) != 0) {
                func_81408A68(arg0);
            }
            break;
    }

    if (arg0->unk_B8 > 0) {
        func_81409DAC(arg0);
    }
}

void func_84336830(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8433661C(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408A1C(arg0);
                func_81408328(arg0);
                func_8140BCA8(arg0, 0xB);
            }
            break;

        case 3:
            func_8140BB44(arg0, 0, 0x18);
            func_8140BBF0(arg0, 0, 0x18);
            if (func_8140BDD0(arg0) != 0) {
                func_8140BCA8(arg0, 0xC);
            }
            break;

        case 4:
            func_8140BB14(arg0, 0, 0x10);
            func_8140BB90(arg0, 0, 0x10);
            if ((func_8140BDAC(arg0) != 0) && (func_8140BC2C(arg0, 0, 0x40) != 0)) {
                func_814081BC(arg0);
            }
            break;

        case 5:
            func_81408150(arg0);
            break;
    }

    if (func_81408368(arg0) != 0) {
        func_8140B98C(arg0, 0.8f, 0.025f);
        func_814083FC(arg0, 0, 7, 1, 2, -1);
        func_8433679C(arg0);
    }
}

void func_843369AC(unk_D_8140E720* arg0) {
    UNUSED s32 pad[3];
    s16 sp22 = func_8140C038(arg0);

    func_8140C058(arg0);
    func_8140B938(arg0, 0.7f);
    func_81409248(arg0, 0xF);
    func_8140935C(arg0, 0xF, 0xA);
    func_814092C8(arg0, 0xF);
    func_8140D5A0(arg0, 0x1A);
    func_8140BC20(arg0, 0xC8);
    func_8140BCA8(arg0, sp22 * 4);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84336A58(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_843369AC(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408A1C(arg0);
                func_81408328(arg0);
                func_8140BCA8(arg0, 8);
            }
            break;

        case 3:
            func_8140BB14(arg0, 0, 0x10);
            func_8140BB90(arg0, 0, 0x10);
            if ((func_8140BDAC(arg0) != 0) && (func_8140BC2C(arg0, 0x20, 0x18) != 0)) {
                func_814081BC(arg0);
            }
            break;

        case 4:
            func_81408150(arg0);
            break;
    }

    if (func_81408368(arg0) != 0) {
        func_8140B98C(arg0, 1.0f, 0.025f);
        func_814083FC(arg0, 0, 7, 1, 2, 0);
    }
}

void func_84336B8C(void) {
    func_8432EE5C(0, 0, 0x40, 0xA, 0xC8);
    func_8432EC28(1, func_84334808, &D_843861D0[0x34], 0, 1, 0x10, D_843902E2, 0, 0);
    func_8432EC28(2, func_84334994, &D_843861D0[0x3D], 0, 3, 0x11, D_843902E2, 0, 0);
    func_8432EC28(4, func_843346BC, &D_843861D0[0x46], 0, 1, 0x11, D_843902E2, 0, 0);
}

void func_84336C80(void) {
    func_8432EE5C(2, 0, 0x40, 0xA, 0xC8);
    func_8432F2C8(0, 0xC, 0xFF, 0, 0x30);
    func_8432EC28(4, func_84335668, &D_843861D0[0x46], 0, 6, 0x10, 9, 0, 0);
    func_8432EC28(8, func_84335668, &D_843861D0[0x46], 0, 6, 0x10, 9, 0, 0);
    func_8432ECA0(0, 2, 2, func_84335A84, &D_843861D0[0x3D], 0, 4, 0x10, 9, 0, 0);
    func_8432ECA0(0, 2, 2, func_84335848, &D_843861D0[0x47], 0, 4, 0x10, 9, 0, 0);
}

void func_84336DD8(void) {
    func_8432EE5C(2, 0, 0x40, 0xA, 0xC8);
    func_8432F2C8(2, 0xB, 0xC8, 0, 0x10);
    func_8432EC28(0, func_84335EF8, &D_843861D0[0x46], 0, 3, 0x10, 9, 0, 0);
    func_8432EC28(0xA, func_84335D10, &D_843861D0[0x46], 0, 8, 0x11, 9, 0, 0);
    func_8432ECA0(0xC, 2, 2, func_84335A84, &D_843861D0[0x3D], 0, 4, 0x11, 9, 0, 0);
}

void func_84336EE8(void) {
    func_8432F8E8(0x64, 1);
    func_8432ED0C(0, 8, 6);
    func_8432ECA0(0, 2, 0x3C, func_843332B4, &D_843861D0[0x4F], 0, 1, 0x11, D_843902E2, 0, 0);
    func_8432ECA0(0, 4, 0x1E, func_84333928, &D_843861D0[0x3D], 0, 1, 0x11, D_843902E2, 0, 0);
    func_8432ECA0(0, 4, 0x1E, func_84333BA8, &D_843861D0[0x4F], 0, 1, 0x11, D_843902E2, 0, 0);
}

void func_84337000(void) {
    func_8432F638(0xA, 0xB, 0x10, 8, 0xC8, 0x10);
    func_8432ECA0(0, 2, 0x14, func_84336320, &D_843861D0[0x4E], 0, 1, 0x11, 9, 0, 0);
    func_8432ECA0(0, 2, 2, func_84336340, &D_843861D0[0x4E], 0, 0xC, 0x11, 9, 0, 0);
    func_8432ECA0(0xE, 8, 5, func_84336520, &D_843861D0[0x3D], 0, 2, 0x11, 9, 0, 0);
    func_8432F2C8(0x3C, 0x10, 0xC8, 0, 8);
    func_8432ECA0(0x3A, 2, 2, func_84354A10, &D_843861D0[0x3D], 0, 1, 9, 0, 0x33, 0);
    func_8432ECA0(0x3C, 2, 2, func_84354A10, &D_843861D0[0x3D], 0, 1, 9, 0, 0x33, 0);
}

void func_843371C0(void) {
    func_8432ED0C(0, 8, 6);
    func_8432ECA0(0, 2, 0x3C, func_843332B4, &D_843861D0[0x4F], 0, 1, 0x11, D_843902E2, 1, 0);
    func_8432ECA0(0, 4, 0x1E, func_84333928, &D_843861D0[0x3D], 0, 1, 0x11, D_843902E2, 1, 0);
    func_8432ECA0(0, 4, 0x1E, func_84333BA8, &D_843861D0[0x4F], 0, 1, 0x11, D_843902E2, 1, 0);
}

void func_843372D8(void) {
    func_8432F638(0xA, 0x35, 0x2E, 8, 0xC8, 0x10);
    func_8432ECA0(0, 2, 0x14, func_84336320, &D_843861D0[0x4E], 0, 1, 0x11, 9, 1, 0);
    func_8432ECA0(0, 2, 2, func_84336340, &D_843861D0[0x4E], 0, 0xC, 0x11, 9, 1, 0);
    func_8432ECA0(0xE, 8, 5, func_84336520, &D_843861D0[0x3D], 0, 2, 0x11, 9, 1, 0);
    func_8432F2C8(0x3C, 0x2E, 0xC8, 0, 8);
    func_8432ECA0(0x3A, 2, 2, func_84354A10, &D_843861D0[0x3D], 0, 1, 9, 0, 0x18, 0);
    func_8432ECA0(0x3C, 2, 2, func_84354A10, &D_843861D0[0x3D], 0, 1, 9, 0, 0x18, 0);
}

void func_843374A4(void) {
    func_8432ED0C(0, 8, 6);
    func_8432ECA0(0, 2, 0x50, func_843332B4, &D_843861D0[0x4F], 0, 1, 0x11, D_843902E2, 0, 0);
    func_8432ECA0(0, 4, 0x28, func_84333928, &D_843861D0[0x3D], 0, 1, 0x11, D_843902E2, 0, 0);
    func_8432ECA0(0, 4, 0x28, func_84333BA8, &D_843861D0[0x4F], 0, 1, 0x11, D_843902E2, 0, 0);
}

void func_843375B0(void) {
    func_8432EC28(0, func_84334350, &D_843861D0[2], 0, 0x12, 0xE, 0, 0, 0);
    func_8432EC28(8, func_84334154, &D_843861D0[0x4F], 0, 0x20, 7, 0, 0, 0);
    func_8432F638(8, 0xB, 0x10, 8, 0xC8, 0x10);
}

void func_8433765C(void) {
}

void func_84337664(void) {
}

void func_8433766C(void) {
    func_8432EC28(0, func_84333E28, &D_843861D0[4], 0, 1, 0x10, 9, 0x14, 0);
    func_8432EE5C(0, 0, 0x40, 0xA, 0xC8);
    func_8432F440(4, 0xA, 0x19, 0x20, 0xFF);
    func_8432EC28(0, func_84334D7C, &D_843861D0[0x46], 0, 3, 0x10, 9, 0x17, 2);
    func_8432EC28(6, func_84334D7C, &D_843861D0[0x46], 0, 3, 0x10, 9, 0x2C, 1);
    func_8432EC28(0xC, func_84334D7C, &D_843861D0[0x46], 0, 3, 0x10, 9, 0x1A, 1);
    func_8432EC28(0x12, func_84334D7C, &D_843861D0[0x46], 0, 2, 0x10, 9, 0x1A, 0);
    func_8432EC28(0x14, func_843351C8, &D_843861D0[0x48], 0, 3, 0x11, 9, 0x1A, 0);
    func_8432ECA0(0x14, 2, 2, func_843353C4, &D_843861D0[0x3D], 0, 6, 0x11, 9, 0, 0);
    func_8432EC28(0x18, func_84335D10, &D_843861D0[0x46], 0, 8, 0x11, 9, 0, 0);
}

void func_843378CC(void) {
}

void func_843378D4(void) {
    func_8432ED0C(0, 0xFF, 0);
    func_8432F638(0xA, 0xB, 0x10, 8, 0xC8, 0x10);
    func_8432ECA0(4, 8, 0x14, func_84336520, &D_843861D0[0x3D], 0, 2, 0xE, 0, 0, 0);
    func_8432ECA0(4, 8, 0x14, func_84336A58, &D_843861D0[0x4F], 0, 2, 9, 0, 0, 0);
    func_8432ECA0(0, 6, 0x28, func_84336830, &D_843861D0[0x4F], 0, 1, 9, 0, 0, 0);
    func_8432ECA0(0, 4, 0x3C, func_84336830, &D_843861D0[0x4F], 0, 1, 9, 0, 1, 0);
    func_8432ECA0(0, 4, 0x3C, func_84336830, &D_843861D0[0x4F], 0, 1, 9, 0, 2, 0);
    func_8432ECA0(0, 3, 0x50, func_84336830, &D_843861D0[0x4F], 0, 1, 9, 0, 3, 0);
    func_8432ECA0(0, 3, 0x50, func_84336830, &D_843861D0[0x4F], 0, 1, 9, 0, 4, 0);
}
