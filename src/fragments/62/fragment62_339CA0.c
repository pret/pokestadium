#include "fragment62.h"
#include "src/17300.h"
#include "src/12D80.h"
#include "src/6A40.h"
#include "src/F420.h"
#include "src/math_util.h"

void func_8434F3E0(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C038(arg0);
    s16 sp24 = func_8140C058(arg0);

    switch (func_8140C040(arg0)) {
        case 0:
            func_8140A578(arg0, 0x4000);
            break;

        case 1:
            func_8140A578(arg0, -0x3000);
            func_8140A594(arg0, 0x4000);
            func_8140A5B0(arg0, 0x2000);
            break;

        case 2:
            func_8140A578(arg0, 0x2000);
            func_8140A594(arg0, 0x2000);
            func_8140A5B0(arg0, 0x2000);
            break;

        case 3:
            func_8140A578(arg0, -0x8000);
            func_8140A594(arg0, 0x2000);
            func_8140A5B0(arg0, 0x6000);
            break;

        case 4:
            func_8140A578(arg0, -0x4000);
            func_8140A594(arg0, 0x4000);
            func_8140A5B0(arg0, 0x4000);
            break;
    }

    func_81408E90(arg0, 10.0f);
    func_8140910C(arg0, (sp26 - 1) * 10.0f);
    func_8140B938(arg0, 1.0f);
    func_8140D5A0(arg0, sp24);
    func_814081BC(arg0);
}

void func_8434F554(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8434F3E0(arg0);
            break;

        case 2:
            func_814084D8(arg0, 0, 7, 1, 1, 0);
            break;

        case 3:
            func_8140BC5C(arg0, 0, 0x40);
            break;

        case 4:
            func_81408150(arg0);
            break;
    }
    func_8140B98C(arg0, 3.5f, 0.25f);
}

void func_8434F610(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C038(arg0);

    func_8140C058(arg0);

    switch (sp26) {
        case 0:
            func_8140A578(arg0, 0x5800);
            func_8140A594(arg0, 0x5800);
            func_8140A5B0(arg0, -0x6000);
            break;

        case 1:
            func_8140A578(arg0, 0x6000);
            func_8140A594(arg0, 0);
            func_8140A5B0(arg0, 0x5800);
            break;

        case 2:
            func_8140A578(arg0, 0x2000);
            func_8140A594(arg0, 0x2000);
            func_8140A5B0(arg0, 0x2000);
            break;

        case 3:
            func_8140A578(arg0, 0x6000);
            break;

        case 4:
            func_8140A578(arg0, 0);
            func_8140A594(arg0, 0);
            func_8140A5B0(arg0, 0);
            break;

        case 5:
            func_8140A578(arg0, 0x6000);
            func_8140A594(arg0, 0x2800);
            func_8140A5B0(arg0, 0x5800);
            break;
    }

    func_81408E90(arg0, 10.0f);
    func_8140B938(arg0, 1.0f);
    func_8140D5A0(arg0, 0xC);
    func_8140BCA8(arg0, sp26 * 3);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_8434F7A4(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8434F610(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            func_814084D8(arg0, 0, 7, 1, 1, 0);
            func_8140B98C(arg0, 3.5f, 0.25f);
            break;

        case 4:
            func_8140BC5C(arg0, 0, 0x40);
            func_8140B98C(arg0, 3.5f, 0.25f);
            break;

        case 5:
            func_81408150(arg0);
            break;
    }
}

void func_8434F888(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C038(arg0);
    s16 sp24 = func_8140C058(arg0);

    switch (sp26) {
        case 0:
            func_8140A578(arg0, 0x5800);
            func_8140A594(arg0, 0x5800);
            func_8140A5B0(arg0, -0x6000);
            break;

        case 1:
            func_8140A578(arg0, 0x6000);
            func_8140A594(arg0, 0);
            func_8140A5B0(arg0, 0x5800);
            break;

        case 2:
            func_8140A578(arg0, 0x2000);
            func_8140A594(arg0, 0x2000);
            func_8140A5B0(arg0, 0x2000);
            break;

        case 3:
            func_8140A578(arg0, 0x6000);
            break;

        case 4:
            func_8140A578(arg0, 0);
            func_8140A594(arg0, 0);
            func_8140A5B0(arg0, 0);
            break;

        case 5:
            func_8140A578(arg0, 0x6000);
            func_8140A594(arg0, 0x2800);
            func_8140A5B0(arg0, 0x5800);
            break;
    }

    switch (sp24) {
        case 0:
            func_81409404(arg0, 0xA, 3);
            func_8140935C(arg0, 0xF, 0xA);
            func_81409514(arg0, 0xF, 3);
            func_8140D5A0(arg0, 0xD);
            break;

        case 1:
            func_81409404(arg0, 0xA, 5);
            func_8140935C(arg0, 0x14, 5);
            func_81409514(arg0, 0xA, 5);
            func_8140D5A0(arg0, 0xE);
            break;
    }

    func_8140B938(arg0, 1.0f);
    func_8140BCA8(arg0, sp26 * 2);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_8434FA98(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8434F888(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            func_814084D8(arg0, 0, 7, 2, 1, 0);
            break;

        case 4:
            func_81408150(arg0);
            break;
    }
}

void func_8434FB3C(unk_D_8140E720* arg0) {
    s16 sp26 = func_843081BC(D_843902EC);

    func_8140B938(arg0, 1.0f);
    func_8140D5A0(arg0, func_8140C058(arg0));

    if (sp26 == 0x42) {
        func_81408BE0(arg0, 320.0f, 0.0f, 0.0f);
        func_8140A5B0(arg0, -0x2800);
    } else {
        func_8140A5B0(arg0, 0x2500);
    }
    func_814081BC(arg0);
}

void func_8434FBE4(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C040(arg0);

    switch (arg0->unk_B2) {
        case 1:
            func_8434FB3C(arg0);
            break;

        case 2:
            func_8140826C(arg0, 0x14);
            break;

        case 3:
            func_81408158(arg0);
            break;
    }

    func_8140B98C(arg0, 6.2f, 1.0f);

    if (sp26 == 0) {
        func_8140BB14(arg0, 0, 0x18);
        func_8140BB44(arg0, 0, 0x18);
        func_8140BBF0(arg0, 0, 0x18);
        func_8140BBC0(arg0, 0, 0x18);
    }
}

void func_8434FCC4(unk_D_8140E720* arg0) {
    s16 sp26 = func_843081BC(D_843902EC);

    func_8140B938(arg0, 1.0f);

    if (sp26 == 0x42) {
        func_8140A5B0(arg0, 0x2500);
    } else {
        func_81408BE0(arg0, 320.0f, 0.0f, 0.0f);
        func_8140A5B0(arg0, -0x2800);
    }

    func_8140D5A0(arg0, func_8140C058(arg0));
    func_814081BC(arg0);
}

void func_8434FD6C(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C040(arg0);

    switch (arg0->unk_B2) {
        case 1:
            func_8434FCC4(arg0);
            break;

        case 2:
            func_8140826C(arg0, 0x14);
            break;

        case 3:
            func_81408150(arg0);
            break;
    }

    func_8140B98C(arg0, 6.0f, 1.0f);

    if (sp26 == 0) {
        func_8140BB14(arg0, 0, 0x18);
        func_8140BB44(arg0, 0, 0x18);
        func_8140BBF0(arg0, 0, 0x18);
        func_8140BBC0(arg0, 0, 0x18);
    }
    func_8140BC2C(arg0, 0, 0x10);
}

void func_8434FE58(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C040(arg0);
    s16 sp24 = func_8140C058(arg0);
    s16 sp22 = func_843081BC(D_843902EC);

    func_8140B938(arg0, 1.0f);

    if (sp22 == 0x42) {
        func_8140A578(arg0, -0x2000);
        func_8140A594(arg0, 0x4000);
    } else {
        func_8140A578(arg0, 0x2000);
        func_8140A594(arg0, 0x4000);
    }

    switch (sp26) {
        case 0:
            func_81408E90(arg0, -10.0f);
            break;

        case 2:
            func_81408E90(arg0, 10.0f);
            break;
    }

    func_8140D5A0(arg0, sp24);
    func_814081BC(arg0);
}

void func_8434FF40(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8434FE58(arg0);
            break;

        case 2:
            func_8140826C(arg0, 8);
            break;

        case 3:
            func_8140BC5C(arg0, 0, 0x20);
            break;

        case 4:
            func_81408158(arg0);
            break;
    }

    func_814083FC(arg0, 0, 7, 1, 2, 0);
    func_8140B98C(arg0, 5.0f, 0.4f);
}

void func_8435000C(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C040(arg0);
    s16 sp24 = func_8140C058(arg0);
    s16 sp22 = func_843081BC(D_843902EC);

    func_8140B938(arg0, 1.0f);

    if (sp22 == 0x42) {
        func_8140A578(arg0, -0x2000);
        func_8140A594(arg0, 0x4000);
    } else {
        func_8140A578(arg0, 0x2000);
        func_8140A594(arg0, 0x4000);
    }

    switch (sp26) {
        case 0:
            func_81408E90(arg0, -10.0f);
            break;

        case 2:
            func_81408E90(arg0, 10.0f);
            break;
    }

    func_8140D5A0(arg0, sp24);
    func_8140BC20(arg0, 0x80);
    func_814081BC(arg0);
}

void func_84350100(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8435000C(arg0);
            break;

        case 2:
            func_8140826C(arg0, 8);
            break;

        case 3:
            func_8140BC5C(arg0, 0, 0x10);
            break;

        case 4:
            func_81408158(arg0);
            break;
    }

    func_814083FC(arg0, 0, 7, 1, 2, 0);
    func_8140B98C(arg0, 5.0f, 0.4f);
}

void func_843501CC(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C038(arg0);
    s16 sp24 = func_8140C058(arg0);

    func_8140B938(arg0, 1.0f);
    func_8140AD8C(arg0, 0.4f);
    func_8140D5A0(arg0, sp24);
    func_8140BC20(arg0, 0x64);
    func_8140BCA8(arg0, sp26 * 4);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84350260(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_843501CC(arg0);
            break;

        case 2:
            if (func_8140826C(arg0, arg0->unk_A6) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            func_814084D8(arg0, 0, 7, 1, 2, 0);
            func_8140BC2C(arg0, 0x64, 6);
            func_81409EA0(arg0);
            break;

        case 4:
            func_81408150(arg0);
            break;
    }
}

void func_84350330(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C038(arg0);
    s16 sp24 = func_8140C058(arg0);

    func_8140B938(arg0, 0.25f);
    arg0->unk_5C.y = (MathUtil_Random_ZeroOne() * 0.5f) + 0.25f;
    func_8140A594(arg0, 0x1800 - ((0x3000 / func_8140C068(arg0)) * sp26));
    func_8140AD8C(arg0, (2.0f * MathUtil_Random_ZeroOne()) + 3.0f);
    func_8140D5A0(arg0, sp24);
    func_8140BC20(arg0, 0xB4);
    func_814081BC(arg0);
}

void func_8435043C(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84350330(arg0);
            break;

        case 2:
            func_814084D8(arg0, 0, 7, 1, 2, 0);
            func_8140B98C(arg0, 0.75f, 0.025f);
            func_8140ADBC(arg0, 0.5f, 0.25f);
            func_814099E0(arg0, arg0->unk_5C.y);
            func_81409CBC(arg0);
            break;

        case 3:
            func_8140BC5C(arg0, 0, 0x20);
            break;

        case 4:
            func_81408150(arg0);
            break;
    }
}

void func_84350520(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C038(arg0);
    s16 sp24 = func_8140C058(arg0);

    func_8140B938(arg0, 0.5f);
    arg0->unk_5C.y = (MathUtil_Random_ZeroOne() * 0.5f) + 0.25f;
    func_8140A594(arg0, 0x1800 - ((0x3000 / func_8140C068(arg0)) * sp26));
    func_8140AD8C(arg0, (MathUtil_Random_ZeroOne() * 2.5f) + 3.0f);
    func_8140D5A0(arg0, sp24);
    func_8140BC20(arg0, 0xB4);
    func_814081BC(arg0);
}

void func_84350634(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84350520(arg0);
            break;

        case 2:
            func_814084D8(arg0, 0, 7, 1, 3, 0);
            func_8140B98C(arg0, 1.0f, 0.05f);
            func_8140ADBC(arg0, 0.5f, 0.25f);
            func_814099E0(arg0, arg0->unk_5C.y);
            break;

        case 3:
            if (func_8140BC2C(arg0, 0, 0x20) != 0) {
                func_814081BC(arg0);
            }
            break;

        case 4:
            func_81408150(arg0);
            break;
    }
    func_81409CBC(arg0);
}

void func_84350728(unk_D_8140E720* arg0) {
    UNUSED s16 pad;
    s16 sp24 = func_8140C038(arg0);

    func_8140B938(arg0, 0.25f);
    arg0->unk_5C.y = (MathUtil_Random_ZeroOne() * 0.5f) + 0.4f;
    func_8140A594(arg0, 0x800 - ((0x1000 / func_8140C068(arg0)) * sp24));
    func_8140AD8C(arg0, (2.0f * MathUtil_Random_ZeroOne()) + 5.0f);
    func_8140D5A0(arg0, 0x32);
    func_8140BC20(arg0, 0xFF);
    func_814081BC(arg0);
}

void func_84350828(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84350728(arg0);
            break;

        case 2:
            func_814084D8(arg0, 0, 7, 1, 2, 0);
            func_8140BC2C(arg0, 0x64, 9);
            func_8140B98C(arg0, 0.4f, 0.025f);
            func_814099E0(arg0, arg0->unk_5C.y);
            func_81409CBC(arg0);
            break;

        case 3:
            func_81408150(arg0);
            break;
    }
}

void func_843508F0(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C038(arg0);

    func_8140B938(arg0, 0.4f);
    func_8140959C(arg0, 0, 0, 0xA);
    arg0->unk_5C.y = (MathUtil_Random_ZeroOne() * 0.5f) + 0.25f;
    func_8140A594(arg0, 0x2000 - ((0x4000 / func_8140C068(arg0)) * sp26));
    func_8140AD8C(arg0, MathUtil_Random_ZeroOne() + 1.0f);
    func_8140D5A0(arg0, 0xA);
    func_8140BC20(arg0, 0x64);
    func_814081BC(arg0);
}

void func_84350A04(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_843508F0(arg0);
            break;

        case 2:
            func_814084D8(arg0, 0, 7, 1, 2, 0);
            func_8140B98C(arg0, 0.75f, 0.025f);
            func_8140ADBC(arg0, 0.5f, 0.2f);
            func_814099E0(arg0, arg0->unk_5C.y);
            func_81409CBC(arg0);
            break;

        case 3:
            if (func_8140BC2C(arg0, 0, 0x20) != 0) {
                func_814081BC(arg0);
            }
            break;

        case 4:
            func_81408150(arg0);
            break;
    }
}

void func_84350AFC(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C038(arg0);

    func_8140B938(arg0, 0.3f);
    func_8140959C(arg0, 0xA, 5, 0xA);
    func_81408E90(arg0, 15.0f);
    func_8140AD8C(arg0, (func_81400A78(0xA) * 0.1f) + 1.5f);
    func_8140BCA8(arg0, sp26 * 2);
    func_8140D5A0(arg0, 0x32);
    func_8140BC20(arg0, 0xFF);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84350BE4(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84350AFC(arg0);
            break;

        case 2:
            if (func_8140826C(arg0, arg0->unk_A6) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            func_8140B98C(arg0, 0.5f, 0.02f);
            func_814083FC(arg0, 0, 7, 1, 2, 0);
            func_8140BC2C(arg0, 0x64, 6);
            if (func_81409F84(arg0) != 0) {
                func_814081BC(arg0);
            }
            break;

        case 4:
            func_81408150(arg0);
            break;
    }
}

void func_84350CD8(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C038(arg0);

    func_8140B938(arg0, 0.25f);
    func_8140A594(arg0, sp26 << 0xC);
    func_8140AD8C(arg0, (2.0f * MathUtil_Random_ZeroOne()) + 6.0f);
    func_8140AF24(arg0, (MathUtil_Random_ZeroOne() * 3.0f) + 1.0f);
    func_8140D5A0(arg0, 0xA);
    func_8140BC20(arg0, 0x64);
    func_8140BCA8(arg0, 7);
    func_814081BC(arg0);
}

void func_84350DAC(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84350CD8(arg0);
            break;

        case 2:
            func_814084D8(arg0, 0, 7, 1, 2, 0);
            func_8140B98C(arg0, 0.8f, 0.1f);
            func_8140ADBC(arg0, 1.0, 1.0f);
            if (func_8140BDAC(arg0) != 0) {
                func_8140B180(arg0, 0.5f, 0.4f);
                func_81409C6C(arg0);
            }
            break;

        case 3:
            func_81409C6C(arg0);
            func_8140BC5C(arg0, 0, 0x20);
            break;

        case 4:
            func_81408150(arg0);
            break;
    }

    if (func_8140819C(arg0) != 0) {
        func_81409CBC(arg0);
    }
}

void func_84350EC8(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C038(arg0);

    switch (func_8140C058(arg0)) {
        case 0:
            func_8140B938(arg0, 0.75f);
            func_8140959C(arg0, 0xF, 0xF, 0xF);
            func_81408E90(arg0, 15.0f);
            func_8140AD8C(arg0, 1.0f);
            break;

        case 1:
            func_8140B938(arg0, 0.5f);
            func_8140959C(arg0, 3, 3, 3);
            func_8140AD8C(arg0, 0.4f);
            break;
    }

    func_8140BCA8(arg0, sp26 * 4);
    func_8140D5A0(arg0, 0x13);
    func_8140BC20(arg0, 0xC8);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84350FC0(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84350EC8(arg0);
            break;

        case 2:
            if (func_8140826C(arg0, arg0->unk_A6) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            func_814084D8(arg0, 0, 7, 1, 2, 0);
            func_8140BC2C(arg0, 0x64, 6);
            func_81409F84(arg0);
            break;

        case 4:
            func_81408150(arg0);
            break;
    }
}

void func_84351090(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C038(arg0);

    func_81409708(arg0, 0xF, 0xF);
    func_8140B938(arg0, 1.0f);
    func_8140AD8C(arg0, 0.2f);
    func_8140BAC8(arg0, 0xFF, 0xFF, 0xFF);
    func_8140BB74(arg0, 0xFF, 0x64, 0);
    func_8140BC20(arg0, 0xFF);
    func_8140BCA8(arg0, sp26 * 4);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84351144(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84351090(arg0);
            break;

        case 2:
            if (func_8140826C(arg0, arg0->unk_A6) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            func_814084D8(arg0, 0, 7, 1, 2, 0);
            func_8140BAE4(arg0, 0x64, 9);
            func_8140BB90(arg0, 0, 0x10);
            func_8140BBF0(arg0, 0x32, 3);
            func_8140BBC0(arg0, 0xFF, 0x10);
            if (func_814081F0(arg0, 8) != 0) {
                func_8140BC2C(arg0, 0, 0x20);
            }
            func_81409EA0(arg0);
            break;

        case 4:
            func_81408158(arg0);
            break;
    }
}

void func_84351264(unk_D_8140E720* arg0) {
    func_8140B938(arg0, 0.1f);
    func_8140D5A0(arg0, 0x14);
    func_8140BC20(arg0, 0xFF);
    func_814081BC(arg0);
}

void func_843512AC(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84351264(arg0);
            break;

        case 2:
            func_8140B98C(arg0, 0.75f, 0.08125f);
            func_8140BC5C(arg0, 0, 0x20);
            break;

        case 3:
            func_81408158(arg0);
            break;
    }
}

void func_84351330(unk_D_8140E720* arg0) {
    Vec3s sp28;

    func_8140C038(arg0);
    func_8140B938(arg0, 0.1f);
    sp28.x = MathUtil_Random16();
    sp28.y = MathUtil_Random16();
    sp28.z = 0;
    func_8140A24C(arg0, sp28);
    func_8140D5A0(arg0, 0x15);
    func_8140BC20(arg0, 0xFF);
    func_8140BCA8(arg0, func_81400A78(5) + 8);
    func_8140AD8C(arg0, 5.0f);
    func_814081BC(arg0);
}

void func_843513F4(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84351330(arg0);
            break;

        case 2:
            func_8140ADBC(arg0, 2.0f, 0.5f);
            if ((func_8140BDAC(arg0) != 0) && (func_8140BC2C(arg0, 0, 0x40) != 0)) {
                func_814081BC(arg0);
            }
            break;

        case 3:
            func_81408150(arg0);
            break;
    }

    if (func_8140819C(arg0) != 0) {
        func_81409D0C(arg0);
    }
}

void func_843514B4(unk_D_8140E720* arg0) {
    Vec3s sp28;
    s16 sp26 = func_8140C058(arg0);

    func_8140C038(arg0);

    sp28.x = func_81400B00(0x2000);
    sp28.y = func_81400B28(0x2000, 0x8000);
    sp28.z = 0;
    func_8140A4F0(arg0, sp28);

    switch (sp26) {
        case 0:
            func_8140B938(arg0, 0.2f);
            func_8140D5A0(arg0, 0x15);
            break;

        case 1:
            func_8140B938(arg0, 0.2f);
            func_8140D5A0(arg0, 0x1B);
            break;
    }

    func_8140BC20(arg0, 0xFF);
    func_8140BCA8(arg0, func_81400A78(5) + 8);
    func_8140AD8C(arg0, 6.0f);
    func_814081BC(arg0);
}

void func_843515C8(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_843514B4(arg0);
            break;

        case 2:
            func_8140B98C(arg0, 0.1f, 0.01f);
            func_8140ADBC(arg0, 3.0f, 0.75f);
            if ((func_8140BDAC(arg0) != 0) && (func_8140BC2C(arg0, 0, 0x40) != 0)) {
                func_814081BC(arg0);
            }
            break;

        case 3:
            func_81408150(arg0);
            break;
    }

    if (func_8140819C(arg0) != 0) {
        func_81409D0C(arg0);
    }
}

void func_843516A0(unk_D_8140E720* arg0) {
    Vec3s sp28;
    s16 sp26 = func_8140C058(arg0);

    func_8140C038(arg0);
    func_8140B938(arg0, 1.0f);

    switch (sp26) {
        case 0:
            func_8140D5A0(arg0, 8);
            func_8140BC20(arg0, 0x64);
            func_8140AD8C(arg0, 5.0f);
            sp28.x = func_81400B00(0x2000);
            sp28.y = func_81400B28(0x2000, 0x8000);
            sp28.z = 0;
            func_8140A4F0(arg0, sp28);
            break;

        case 1:
            func_8140D5A0(arg0, 8);
            func_8140BC20(arg0, 0x64);
            func_8140AD8C(arg0, 5.0f);
            sp28.x = func_81400B00(0x2000);
            sp28.y = func_81400B28(0x2000, 0x8000);
            sp28.z = 0;
            func_8140A4F0(arg0, sp28);
            break;

        case 2:
            func_8140D5A0(arg0, 8);
            func_8140BC20(arg0, 0x64);
            func_81408CA0(arg0, -10.0f);
            func_8140AD8C(arg0, 5.0f);
            sp28.x = func_81400B00(0x2000);
            sp28.y = func_81400B28(0x2000, 0x8000);
            sp28.z = 0;
            func_8140A4F0(arg0, sp28);
            break;

        case 3:
            func_8140D5A0(arg0, 9);
            func_8140BC20(arg0, 0x96);
            func_8140AD8C(arg0, 3.0f);
            sp28.x = func_81400B00(0x2000);
            sp28.y = func_81400B28(0x2000, 0x8000);
            sp28.z = 0;
            func_8140A4F0(arg0, sp28);
            break;

        case 4:
            func_8140D5A0(arg0, 5);
            func_8140BC20(arg0, 0x96);
            func_8140AD8C(arg0, 4.0f);
            sp28.x = func_81400B00(0x3000);
            sp28.y = func_81400B28(0x3000, 0x8000);
            sp28.z = 0;
            func_8140A4F0(arg0, sp28);
            break;
    }

    func_8140BCA8(arg0, func_81400A78(5) + 8);
    func_814081BC(arg0);
}

void func_84351984(unk_D_8140E720* arg0) {
    s16 sp2E = func_8140C058(arg0);

    switch (arg0->unk_B2) {
        case 1:
            func_843516A0(arg0);
            break;
        case 2:
            func_814084D8(arg0, 0, 7, 1, 2, 0);

            switch (sp2E) {
                case 3:
                    func_8140BAE4(arg0, 0, 9);
                    func_8140ADBC(arg0, 1.0f, 0.75f);
                    func_8140BC2C(arg0, 0x32, 6);
                    break;

                case 4:
                    func_8140ADBC(arg0, 1.0f, 0.75f);
                    func_81408E90(arg0, 0.5f);
                    func_8140BC2C(arg0, 0x32, 6);
                    break;

                default:
                    func_8140BB14(arg0, 0x64, 6);
                    func_8140ADBC(arg0, 2.0f, 0.5f);
                    break;
            }
            break;

        case 3:
            func_81408150(arg0);
            break;
    }

    if (func_8140819C(arg0) != 0) {
        func_81409D0C(arg0);
    }
}

void func_84351ADC(unk_D_8140E720* arg0) {
    s16 sp2E = func_8140C038(arg0);
    Vec3s sp28;

    func_8140B938(arg0, 0.1f);
    if (arg0->unk_68.y < 0.0f) {
        arg0->unk_68.y = 0.0f;
    }
    sp28.x = func_81400A78(0x10000);
    sp28.y = func_81400A78(0x10000);
    sp28.z = 0;
    func_8140A24C(arg0, sp28);
    func_8140A3EC(arg0, func_81400B4C(0x400, 0x400));
    func_8140AD8C(arg0, 8.0f);
    func_8140D5A0(arg0, 0x17);
    func_8140BCA8(arg0, sp2E * 0);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84351BCC(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84351ADC(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            func_8140B9D0(arg0, 0.3f, 0.05f);
            func_8140ADBC(arg0, 3.0f, 1.0f);
            break;

        case 4:
            func_8140826C(arg0, 2);
            break;

        case 5:
            func_8140B9D0(arg0, 0.05f, 0.05f);
            break;

        case 6:
            func_81408150(arg0);
            break;
    }

    if (func_81408368(arg0) != 0) {
        func_8140A4DC(arg0);
        func_8140B2B4(arg0);
        func_81409BDC(arg0);
    }
}

void func_84351CE4(unk_D_8140E720* arg0) {
    func_8432D844(arg0, func_84351BCC, &D_843861D0[0x42], 0xC);
    func_814081BC(arg0);
}

void func_84351D20(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84351CE4(arg0);
            break;

        case 2:
            func_81408150(arg0);
            break;
    }
}

void func_84351D70(unk_D_8140E720* arg0) {
    s16 sp2E = func_8140C038(arg0);
    s16 sp2C = func_8140C040(arg0);
    s16 sp2A = func_8140C058(arg0);
    Vec3s sp24;

    sp24.x = func_81400A78(0x10000);
    sp24.y = func_81400A78(0x10000);
    sp24.z = 0;

    func_8140A24C(arg0, sp24);
    func_8140AD8C(arg0, 0.0f);
    func_8140ADA4(arg0, 0.0f);
    func_8140D5A0(arg0, sp2A);
    func_8140B938(arg0, 0.0f);
    func_8140B95C(arg0, 0.3f);
    func_8140B974(arg0, 0.05f);
    func_8140BCA8(arg0, sp2E * 2);

    switch (sp2C) {
        case 0:
            func_8140910C(arg0, func_81400ADC(0x1E, 0xA));
            func_8140B95C(arg0, 0.2f);
            break;

        case 1:
            if (arg0->unk_68.y < 0) {
                arg0->unk_68.y = 0;
            }
            func_8140910C(arg0, func_81400ADC(0x28, 0xA));
            func_8140B95C(arg0, 0.3f);
            func_8140B974(arg0, 0.04f);
            break;

        case 2:
            func_8140B95C(arg0, 0.1f);
            func_8140B974(arg0, 0.03f);
            func_8140910C(arg0, func_81400ADC(0xC, 5));
            func_8140BCA8(arg0, sp2E * 1);
            break;

        case 3:
            func_8140AD8C(arg0, 0.2f);
            func_8140B938(arg0, 0.1f);
            func_8140910C(arg0, func_81400ADC(0x14, 0x1E));
            func_8140BCA8(arg0, sp2E * 4);
            break;

        case 5:
            func_8140959C(arg0, 0, 0xF, 0x19);
            func_81408E90(arg0, 15.0f);
            func_8140B95C(arg0, 0.15f);
            func_8140B974(arg0, 0.02f);
            func_8140AD8C(arg0, 0.1f);
            break;

        case 6:
            func_8140910C(arg0, func_81400ADC(0x1E, 0x14));
            func_8140AD8C(arg0, 0.3f);
            break;

        case 8:
            func_8140910C(arg0, func_81400ADC(8, 2));
            func_8140B95C(arg0, 0.1f);
            func_8140B974(arg0, 0.04f);
            func_8140AD8C(arg0, 0.4f);
            func_8140BCA8(arg0, 0);
            break;

        case 7:
            func_8140910C(arg0, func_81400ADC(0xA, 2));
            func_8140B95C(arg0, 0.2f);
            func_8140B974(arg0, 0.025f);
            func_8140AD8C(arg0, 1.0f);
            break;

        case 9:
            func_8140910C(arg0, func_81400ADC(0x1E, 0x14));
            func_8140B95C(arg0, 0.3f);
            func_8140B974(arg0, 0.025f);
            func_8140AD8C(arg0, 0.0f);
            func_8140ADA4(arg0, 0.02f);
            break;

        case 10:
            func_8140910C(arg0, func_81400ADC(0x19, 5));
            func_81408E90(arg0, 10.0f);
            func_8140B95C(arg0, 0.2f);
            break;

        case 11:
            func_8140910C(arg0, func_81400ADC(5, 5));
            func_8140AD8C(arg0, func_81400A78(5) + 5.0f);
            break;
    }
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_8435226C(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84351D70(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            if (func_8140BA48(arg0) != 0) {
                func_8140B95C(arg0, 0.0f);
            }
            break;

        case 4:
            func_8140BA48(arg0);
            break;

        case 5:
            func_81408150(arg0);
            break;
    }

    if (func_81408368(arg0) != 0) {
        func_81409FD8(arg0);
        if (arg0->unk_2C.y < 0.0f) {
            func_81408150(arg0);
        }
    }
}

void func_8435235C(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C038(arg0);
    s16 sp24 = func_8140C058(arg0);

    func_8140B938(arg0, 0.0f);
    func_8140B95C(arg0, 0.3f);
    func_8140B974(arg0, 0.05f);
    func_8140959C(arg0, 0xA, 0x14, 0x14);
    func_81408ED0(arg0, 15.0f);
    func_81408E90(arg0, 7.0f);
    func_8140AD8C(arg0, func_81400A78(5) + 8.0f);
    func_8140BCA8(arg0, sp26 * 2);
    func_8140D5A0(arg0, sp24);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84352464(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8435235C(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            if (func_8140BA48(arg0) != 0) {
                func_8140B95C(arg0, 0.0f);
            }
            break;

        case 4:
            func_8140BA48(arg0);
            break;

        case 5:
            func_81408150(arg0);
            break;
    }

    if (func_81408368(arg0) != 0) {
        func_81409EA0(arg0);
    }
}

void func_84352530(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84351D70(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            if (func_8140BA48(arg0) != 0) {
                func_8140B95C(arg0, 0.0f);
            }
            break;

        case 4:
            func_8140BA48(arg0);
            break;

        case 5:
            func_81408150(arg0);
            break;
    }

    if (func_81408368(arg0) != 0) {
        func_81409D0C(arg0);
        if (arg0->unk_2C.y < 0.0f) {
            func_81408150(arg0);
        }
    }
}

void func_84352620(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C038(arg0);

    func_8140B938(arg0, 0.7f);
    func_81408CA0(arg0, 10.0f);
    func_8140D5A0(arg0, 0x19);
    func_8140BC20(arg0, 0xFF);
    func_8140BCA8(arg0, sp26 * 4);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_843526A8(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84352620(arg0);
            break;

        case 2:
            if (func_8140826C(arg0, arg0->unk_A6) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            func_814084D8(arg0, 0, 5, 1, 1, 2);
            break;

        case 4:
            func_81408150(arg0);
            break;
    }
}

void func_84352754(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C038(arg0);
    s16 sp24 = func_8140C040(arg0);

    func_8140D5A0(arg0, func_8140C058(arg0));

    switch (sp24) {
        case 1:
            func_8140AD8C(arg0, 0.2f);
            func_8140B938(arg0, 1.0f);
            break;

        case 5:
            func_8140AD8C(arg0, 0.2f);
            func_8140B938(arg0, 1.0f);
            break;

        case 6:
            func_8140AD8C(arg0, 0.4f);
            func_8140B938(arg0, 1.5f);
            break;

        case 16:
            func_8140AD8C(arg0, 0.4f);
            func_8140B938(arg0, 2.0f);
            break;

        case 7:
            func_8140AD8C(arg0, 0.4f);
            func_8140B938(arg0, 1.5f);
            break;

        case 8:
            func_8140AD8C(arg0, 0.4f);
            func_8140B938(arg0, 1.5f);
            func_81408E90(arg0, -10.0f);
            break;

        case 12:
            func_8140B938(arg0, 0.75f);
            func_8140AD8C(arg0, 0.4f);
            func_8140959C(arg0, 8, 0xA, 8);
            break;

        case 13:
            func_8140B938(arg0, 1.0f);
            func_8140AD8C(arg0, 0.0f);
            func_81409248(arg0, 0x1E);
            func_8140935C(arg0, 0x14, 0xA);
            func_814092C8(arg0, 0x1E);
            break;

        case 14:
            func_8140B938(arg0, 1.0f);
            func_8140AD8C(arg0, 0.0f);
            func_81409248(arg0, 0x14);
            func_8140935C(arg0, 0x14, 0xA);
            func_814092C8(arg0, 0xF);
            break;

        case 15:
            func_8140B938(arg0, 1.5f);
            func_8140AD8C(arg0, 0.3f);
            func_8140959C(arg0, 0xA, 0xA, 0xA);
            break;
    }

    func_8140BC20(arg0, 0xFF);
    func_8140BCA8(arg0, sp26 * 4);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_843529D8(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84352754(arg0);
            break;

        case 2:
            if (func_8140826C(arg0, arg0->unk_A6) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            func_814084D8(arg0, 0, 3, 1, 1, 0);
            func_81409EA0(arg0);
            break;

        case 4:
            func_81408150(arg0);
            break;
    }
}

void func_84352A8C(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C038(arg0);

    switch (func_8140C058(arg0)) {
        case 0:
            func_8140D5A0(arg0, 0);
            func_8140AD8C(arg0, 0.2f);
            func_8140B938(arg0, 1.0f);
            func_8140BCA8(arg0, sp26 * 2);
            func_81408E90(arg0, 15.0f);
            break;

        case 1:
            func_8140D5A0(arg0, 0);
            func_8140AD8C(arg0, 0.2f);
            func_8140B938(arg0, 1.0f);
            func_8140BCA8(arg0, sp26 * 2);
            break;

        case 2:
            func_8140D5A0(arg0, 0);
            func_8140AD8C(arg0, 0.2f);
            func_8140B938(arg0, 1.0f);
            func_8140BCA8(arg0, sp26 * 2);
            func_81408E90(arg0, -10.0f);
            break;

        case 3:
            func_8140D5A0(arg0, 1);
            func_8140B938(arg0, 0.5f);
            func_8140AD8C(arg0, 0.4f);
            func_8140BCA8(arg0, sp26 * 2);
            break;

        case 4:
            func_8140D5A0(arg0, 2);
            func_8140B938(arg0, 0.5f);
            func_8140AD8C(arg0, 0.4f);
            func_8140BCA8(arg0, sp26 * 2);
            break;

        case 5:
            func_8140D5A0(arg0, 3);
            func_8140AD8C(arg0, 0.2f);
            func_8140B938(arg0, 1.0f);
            func_8140BCA8(arg0, sp26 * 2);
            break;

        case 6:
            func_8140D5A0(arg0, 0);
            func_8140AD8C(arg0, 0.4f);
            func_8140B938(arg0, 1.5f);
            func_8140BCA8(arg0, sp26 * 2);
            break;

        case 9:
            func_8140D5A0(arg0, 0);
            func_8140AD8C(arg0, 0.2f);
            func_8140B938(arg0, 1.0f);
            func_8140959C(arg0, 0xF, 0xF, 0xF);
            func_81408E90(arg0, 10.0f);
            func_8140BCA8(arg0, sp26 * 2);
            break;

        case 10:
            func_8140D5A0(arg0, 0);
            func_8140AD8C(arg0, 0.2f);
            func_8140B938(arg0, 1.0f);
            func_8140959C(arg0, 0x14, 0, 0x14);
            func_81408CA0(arg0, 0.0f);
            func_8140BCA8(arg0, sp26 * 2);
            break;

        case 11:
            func_8140D5A0(arg0, 0);
            func_8140AD8C(arg0, 0.2f);
            func_8140B938(arg0, 1.0f);
            func_8140959C(arg0, 0xA, 0, 0xA);
            func_81408CA0(arg0, 30.0f - (sp26 * 5.0f));
            func_8140BCA8(arg0, sp26 * 2);
            break;
    }

    func_8140BC20(arg0, 0xFF);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84352E64(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84352A8C(arg0);
            break;

        case 2:
            if (func_8140826C(arg0, arg0->unk_A6) != 0) {
                func_81408328(arg0);
                func_8140BCA8(arg0, 2);
            }
            break;

        case 3:
            func_814084D8(arg0, 0, 3, 1, 1, 0);
            func_81409EA0(arg0);
            if ((func_8140BDAC != 0) && (arg0->unk_B8 == 0)) {
                func_81408A68(arg0);
            }
            break;

        case 4:
            func_81408150(arg0);
            break;
    }

    if (arg0->unk_B8 == 1) {
        func_8432D8E8(arg0, func_84350260, &D_843861D0[0x3D], 1, 8, 0);
        func_81408A68(arg0);
    }
}

void func_84352F90(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C038(arg0);

    switch (func_8140C058(arg0)) {
        case 3:
            func_8140D5A0(arg0, 1);
            func_8140B938(arg0, 1.5f);
            func_8140AD8C(arg0, 0.4f);
            func_8140BCA8(arg0, sp26 * 2);
            func_8140BEEC(arg0, 0);
            break;

        case 4:
            func_8140D5A0(arg0, 2);
            func_8140B938(arg0, 1.5f);
            func_8140AD8C(arg0, 0.4f);
            func_8140BCA8(arg0, sp26 * 2);
            func_8140BEEC(arg0, 1);
            break;
    }

    func_8140BC20(arg0, 0xFF);
    func_81408348(arg0);
    func_814081BC(arg0);
}

s32 func_84353098(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84352F90(arg0);
            break;

        case 2:
            if (func_8140826C(arg0, arg0->unk_A6) != 0) {
                func_81408328(arg0);
                func_8140BCA8(arg0, 2);
            }
            break;

        case 3:
            func_814084D8(arg0, 0, 3, 1, 1, 0);
            func_81409EA0(arg0);
            if ((func_8140BDAC != NULL) && (arg0->unk_B8 == 0)) {
                func_81408A68(arg0);
            }
            break;

        case 4:
            func_81408150(arg0);
            break;
    }

    switch (arg0->unk_B8) {
        case 1:
            func_8432D844(arg0, func_843515C8, &D_843861D0[0x38], 8);
            func_81408A68(arg0);
            break;

        case 2:
            if (func_81408A78(arg0, 1) != 0) {
                func_8432D844(arg0, func_843515C8, &D_843861D0[0x38], 4);
                func_81408A68(arg0);
            }
            break;

        case 3:
            if (func_81408A78(arg0, 1) != 0) {
                func_8432D844(arg0, func_843515C8, &D_843861D0[0x38], 4);
                func_81408A68(arg0);
            }
            break;
    }
}

void func_8435324C(unk_D_8140E720* arg0) {
    func_8140C038(arg0);
    func_8140B938(arg0, 0.05f);
    func_8140D5A0(arg0, 7);
    func_8140BC20(arg0, 0xFF);
    func_8140BCA8(arg0, 0x32);
    func_814081BC(arg0);
}

void func_843532B0(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8435324C(arg0);
            break;

        case 2:
            func_814083FC(arg0, 0, 5, 1, 1, -1);
            func_8140B98C(arg0, 0.3f, 0.01f);
            func_8140BDD0(arg0);
            break;

        case 3:
            func_81408150(arg0);
            break;
    }
}

void func_84353354(unk_D_8140E720* arg0) {
    s16 sp2E;
    s16 sp2C;
    Vec3s sp24;

    sp2E = func_8140C038(arg0);
    sp2C = sp2E % 3;
    func_8140B938(arg0, 0.4f);
    func_8140AD8C(arg0, 1.0f);

    sp24.x = MathUtil_Random16();
    sp24.y = MathUtil_Random16();
    sp24.z = 0;
    func_8140A24C(arg0, sp24);

    switch (sp2C) {
        case 0:
            func_81408BE0(arg0, 0.0f, -2.0f, 0.0f);
            break;

        case 1:
            func_81408BE0(arg0, 0.0f, 2.0f, 2.0f);
            break;

        case 2:
            func_81408BE0(arg0, 0.0f, 2.0f, -2.0f);
            break;
    }

    func_8140D5A0(arg0, 0x17);
    func_8140BCA8(arg0, sp2E * 4);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_843534BC(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84353354(arg0);
            break;

        case 2:
            if (func_8140826C(arg0, arg0->unk_A6) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            func_814084D8(arg0, 0, 7, 1, 1, 0);
            func_8140ADBC(arg0, 0.2f, 0.25f);
            func_8140B98C(arg0, 0.5f, 0.02f);
            func_8140BB44(arg0, 0, 0x20);
            func_8140BBF0(arg0, 0, 0x20);
            if (arg0->unk_C7 >= 6) {
                func_8140BB14(arg0, 0, 0x20);
                func_8140BC2C(arg0, 0x64, 0x4E);
            }
            func_81409CBC(arg0);
            break;

        case 4:
            func_81408150(arg0);
            break;
    }
}

void func_843535F4(unk_D_8140E720* arg0) {
    s16 sp2E = func_8140C038(arg0);
    s16 sp2C = sp2E % 3;
    Vec3s sp24;

    func_8140B938(arg0, 0.4f);
    func_8140AD8C(arg0, 1.0f);

    sp24.x = MathUtil_Random16();
    sp24.y = MathUtil_Random16();
    sp24.z = 0;
    func_8140A24C(arg0, sp24);

    switch (sp2C) {
        case 0:
            func_81408BE0(arg0, 0.0f, -2.0f, 0.0f);
            break;

        case 1:
            func_81408BE0(arg0, 0.0f, 2.0f, 2.0f);
            break;

        case 2:
            func_81408BE0(arg0, 0.0f, 2.0f, -2.0f);
            break;
    }

    func_8140D5A0(arg0, 0x17);
    func_8140BCA8(arg0, sp2E * 4);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_8435375C(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_843535F4(arg0);
            break;

        case 2:
            if (func_8140826C(arg0, arg0->unk_A6) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            func_814084D8(arg0, 0, 7, 1, 1, 0);
            func_8140ADBC(arg0, 0.2f, 0.25f);
            func_8140B98C(arg0, 0.5f, 0.02f);
            func_8140BB44(arg0, 0, 0x20);
            func_8140BBF0(arg0, 0, 0x20);
            if (arg0->unk_C7 >= 6) {
                func_8140BB14(arg0, 0, 0x20);
                func_8140BC2C(arg0, 0x64, 0x4E);
            }
            func_81409CBC(arg0);
            break;

        case 4:
            func_81408150(arg0);
            break;
    }
}

void func_84353894(unk_D_8140E720* arg0) {
    s16 sp1E;

    switch (func_8432C544()) {
        case 0x4D:
            sp1E = 0x43;
            break;
        case 0x4E:
            sp1E = 5;
            break;
        case 0x4F:
            sp1E = 0xC;
            break;
        case 0x93:
            sp1E = 5;
            break;
        case 0x1C:
            sp1E = 0x31;
            break;
        case 0x6C:
            sp1E = 0x1C;
            break;
        case 0x7B:
            sp1E = 0x1E;
            break;
        case 0x36:
            sp1E = 0x1D;
            break;
        case 0x72:
            sp1E = 0x1E;
            break;
        case 0x8B:
            sp1E = 0x1E;
            break;
    }
    func_8140D5A0(arg0, sp1E);
}

void func_84353998(unk_D_8140E720* arg0) {
    Vec3s sp28;
    s16 sp26 = func_8140C038(arg0);
    s16 sp24 = func_8140C058(arg0);

    func_8140B938(arg0, 1.0f);
    sp28.x = MathUtil_Random16();
    sp28.y = MathUtil_Random16();
    sp28.z = 0;
    func_8140A24C(arg0, sp28);

    switch (sp24) {
        case 0:
            func_8140959C(arg0, 0xF, 0xF, 0xF);
            func_81408E90(arg0, 10.0f);
            func_8140AD8C(arg0, 1.0f);
            func_8140BCA8(arg0, sp26 * 2);
            break;

        case 1:
            func_8140959C(arg0, 0xA, 0xA, 0xA);
            func_81408E90(arg0, 10.0f);
            func_8140AD8C(arg0, 0.0f);
            func_8140BCA8(arg0, sp26 * 2);
            break;
    }

    func_84353894(arg0);
    func_8140BC20(arg0, 0xC8);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84353AEC(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84353998(arg0);
            break;

        case 2:
            if (func_8140826C(arg0, arg0->unk_A6) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            func_814084D8(arg0, 0, 7, 1, 2, 0);
            func_8140BC2C(arg0, 0x64, 6);
            func_8140B98C(arg0, 2.0f, 0.075f);
            func_81409D0C(arg0);
            break;

        case 4:
            func_81408150(arg0);
            break;
    }
}

void func_84353BD0(unk_D_8140E720* arg0) {
    func_8140B938(arg0, 0.2f);
    func_8140D5A0(arg0, func_8140C058(arg0));
    func_8140BC20(arg0, 0xC8);
    func_8140BCA8(arg0, 0x18);
    arg0->unk_74 = 0.02f;
    func_814081BC(arg0);
}

void func_84353C40(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84353BD0(arg0);
            break;

        case 2:
            func_8140B98C(arg0, 2.0f, 0.02f);
            func_8140BBF0(arg0, 0xC8, 2);
            func_8140BDD0(arg0);
            break;

        case 3:
            func_81400760(&arg0->unk_74, 0.008f, 0.001f);
            func_8140B98C(arg0, 2.0f, arg0->unk_74);
            func_8140BBF0(arg0, 0xC8, 2);
            func_8140BC5C(arg0, 0, 0xC);
            break;

        case 4:
            func_81408150(arg0);
            break;
    }
}

void func_84353D30(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C038(arg0);

    func_8140B938(arg0, 1.0f);
    func_8140959C(arg0, 0xF, 0xF, 0xF);
    func_8140AD8C(arg0, (func_81400A78(0x32) * 0.02f) + 0.5f);
    func_8140D5A0(arg0, func_8140C058(arg0));
    func_8140BC20(arg0, 0x64);
    func_8140BCA8(arg0, sp26 * 4);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84353E10(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84353D30(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_8140BCA8(arg0, func_81400A78(4) + 4);
                func_81408328(arg0);
            }
            break;

        case 3:
            func_8140BDD0(arg0);
            func_81409F60(arg0);
            break;

        case 4:
            func_814084D8(arg0, 0, 7, 1, 2, 0);
            func_8140BC2C(arg0, 0x40, 4);
            func_81409F60(arg0);
            break;

        case 5:
            func_81408150(arg0);
            break;
    }
}

void func_84353F08(unk_D_8140E720* arg0) {
    f32 sp24 = 0.0f;
    f32 sp20 = 0.0f;
    s32 sp1C = 0;

    switch (func_843081BC(arg0->unk_10)) {
        case 0x9:
            sp20 = 5.0f;
            break;

        case 0x19:
            sp20 = 0.0f;
            func_8140B938(arg0, 1.0f);
            break;

        case 0x37:
            sp20 = 8.0f;
            break;

        case 0x49:
            sp1C = 1;
            break;

        case 0x50:
            sp1C = 1;
            break;

        case 0x74:
            sp20 = 5.0f;
            break;

        case 0x82:
            func_8140B938(arg0, 1.5f);
            sp24 = -5.0f;
            sp20 = 10.0f;
            sp1C = 1;
            break;

        case 0x83:
            func_8140B938(arg0, 1.5f);
            sp20 = 5.0f;
            sp1C = 1;
            break;

        case 0x86:
            sp20 = 10.0f;
            break;

        case 0x95:
            sp20 = 10.0f;
            break;
    }

    if (sp1C == 0) {
        func_8140959C(arg0, 0xA, 0, 0x23);
    } else {
        func_8140959C(arg0, 0xF, 0, 0x2D);
    }

    func_81408ED0(arg0, 10.0f + sp24);
    func_81408E90(arg0, 5.0f + sp20);
}

void func_843540FC(unk_D_8140E720* arg0) {
    Vec3s sp30;
    s16 sp2E = func_8140C038(arg0);
    u16 sp2C = func_8140C040(arg0);

    func_8140BFEC(arg0, 2);
    func_8140BCA8(arg0, sp2E * 2);
    func_8140D5A0(arg0, func_8140C058(arg0));

    switch (sp2C) {
        case 0:
            func_8140B938(arg0, 1.0f);
            func_8140959C(arg0, 0xA, 0xA, 0xA);
            func_8140AD8C(arg0, (func_81400A78(0x32) * 0.02f) + 0.5f);
            func_8140BC20(arg0, 0x64);
            func_8140BF4C(arg0, 4);
            break;

        case 1:
            func_8140B938(arg0, 1.0f);
            func_8140959C(arg0, 0xA, 0xF, 0x3C);
            func_8140AD8C(arg0, (func_81400A78(0x32) * 0.04f) + 1.0f);
            func_8140BC20(arg0, 0x64);
            func_8140BF4C(arg0, 4);
            break;

        case 2:
            func_8140B938(arg0, 1.5f);
            func_8140959C(arg0, 0xF, 0x14, 0x19);
            func_8140AD8C(arg0, (func_81400A78(0x32) * 0.07f) + 4.0f);
            func_8140BC20(arg0, 0xA0);
            func_8140BCA8(arg0, sp2E);
            func_8140BF4C(arg0, 0xA);
            break;

        case 3:
            func_8140B938(arg0, 1.0f);
            func_8140959C(arg0, 0xA, 0, 0x19);
            func_81408ED0(arg0, 10.0f);
            func_81408E90(arg0, 5.0f);
            func_8140AD8C(arg0, (func_81400A78(0xA) * 0.05f) + 0.2f);
            func_8140BC20(arg0, 0xFF);
            func_8140BF4C(arg0, 2);
            func_8140BFEC(arg0, 2);
            break;

        case 8:
            func_8140B938(arg0, 1.2f);
            func_84353F08(arg0);
            func_8140AD8C(arg0, (func_81400A78(0xA) * 0.05f) + 0.2f);
            func_8140BC20(arg0, 0xFF);
            func_8140BF4C(arg0, 2);
            func_8140BFEC(arg0, 2);
            func_8140BCA8(arg0, sp2E);
            break;

        case 12:
            func_8140B938(arg0, 1.2f);
            func_8140959C(arg0, 0xA, 0, 0x28);
            func_81408ED0(arg0, 10.0f);
            func_81408E90(arg0, 5.0f);
            func_8140AD8C(arg0, (func_81400A78(0xA) * 0.05f) + 0.2f);
            func_8140BC20(arg0, 0xFF);
            func_8140BF4C(arg0, 2);
            func_8140BFEC(arg0, 2);
            func_8140BCA8(arg0, sp2E);
            break;

        case 4:
            func_8140B938(arg0, 0.5f);
            func_8140959C(arg0, 0xA, 0, 0x14);
            func_8140AD8C(arg0, (func_81400A78(0xA) * 0.05f) + 0.5f);
            func_8140BC20(arg0, 0xFF);
            func_8140BF4C(arg0, 2);
            func_8140BFEC(arg0, 2);
            break;

        case 5:
            func_8140B938(arg0, 1.0f);
            func_8140959C(arg0, 0xF, 0xF, 0xF);
            func_8140AD8C(arg0, (func_81400A78(0x32) * 0.02f) + 1.0f);
            func_8140BC20(arg0, 0x80);
            func_8140BF4C(arg0, 4);
            break;

        case 6:
            func_8140B938(arg0, 0.5f);
            func_8140959C(arg0, 5, 5, 5);
            func_8140AD8C(arg0, 0.5f);
            func_8140BC20(arg0, 0xC8);
            func_8140BF4C(arg0, 4);
            break;

        case 7:
            func_8140B938(arg0, 0.5f);
            func_8140959C(arg0, 0xA, 0, 5);
            func_81408E90(arg0, 10.0f);
            func_8140AD8C(arg0, (func_81400A78(0x14) * 0.02f) + 0.5f);
            func_8140BC20(arg0, 0xC8);
            func_8140BF4C(arg0, 4);
            break;

        case 9:
            func_8140B938(arg0, 1.0f);
            func_8140959C(arg0, 0xA, 0, 0xA);
            sp30.x = func_81400B00(0x1800) - 0x4000;
            sp30.y = func_81400A78(0x10000);
            sp30.z = 0;
            func_8140A4F0(arg0, sp30);
            func_8140AD8C(arg0, (func_81400A78(0x14) * 0.15f) + 3.0f);
            func_8140B2B4(arg0);
            func_8140BCA8(arg0, sp2E);
            func_8140BF4C(arg0, 0xA);
            break;

        case 10:
            func_8140B938(arg0, 0.8f);
            func_8140959C(arg0, 0xF, 0, 0xF);
            sp30.x = func_81400B00(0x1000) - 0x4000;
            sp30.y = func_81400A78(0x10000);
            sp30.z = 0;
            func_8140A4F0(arg0, sp30);
            func_8140AD8C(arg0, (func_81400A78(0x14) * 0.15f) + 4.0f);
            func_8140B2B4(arg0);
            func_8140BCA8(arg0, 0);
            func_8140BF4C(arg0, 0xA);
            break;

        case 11:
            func_8140B938(arg0, 0.05f);
            func_8140959C(arg0, 0xA, 0, 0xA);
            sp30.x = func_81400B00(0x1000) - 0x4000;
            sp30.y = func_81400A78(0x10000);
            sp30.z = 0;
            func_8140A4F0(arg0, sp30);
            func_8140AD8C(arg0, (func_81400A78(0x14) * 0.3f) + 6.0f);
            func_8140B2B4(arg0);
            func_8140BC20(arg0, 0xFF);
            func_8140BCA8(arg0, sp2E);
            func_8140BF4C(arg0, 0xA);
            break;
    }

    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84354A10(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_843540FC(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            func_814084D8(arg0, 0, 7, 1, arg0->unk_B0, 0);
            func_8140BC2C(arg0, 0x40, arg0->unk_AE);
            func_81409F60(arg0);
            break;

        case 4:
            func_81408150(arg0);
            break;
    }
}

void func_84354ADC(unk_D_8140E720* arg0) {
    f32 sp1C = 50.0f;
    f32 sp18 = 30.0f;

    switch (func_843081BC(arg0->unk_10)) {
        case 3:
            sp1C = 40.0f;
            break;

        case 0x5F:
            sp1C = 25.0f;
            break;

        case 0x67:
            sp1C = 35.0f;
            break;

        case 0x71:
            sp18 = 35.0f;
            break;

        case 0x73:
            sp1C = 40.0f;
            break;

        case 0x82:
            sp1C = 20.0f;
            break;

        case 0x83:
            sp1C = 30.0f;
            break;
    }

    func_81408ED0(arg0, sp1C);
    func_81408E90(arg0, sp18);
    func_8140ADA4(arg0, 0.4f);
}

void func_84354BE4(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_843540FC(arg0);
            func_84354ADC(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
                func_81408A1C(arg0);
                func_8140BCA8(arg0, 0x14);
            }
            break;

        case 3:
            func_814083FC(arg0, 0, 7, 1, 2, 0);
            func_8140BC2C(arg0, 0x40, 2);
            func_81409FD8(arg0);
            func_81409F00(arg0, 10.0f);
            func_8140BDD0(arg0);
            break;

        case 4:
            func_81408150(arg0);
            break;
    }

    switch (arg0->unk_B8) {
        case 1:
            func_8140AE40(arg0, 1.0f, 0.1f);
            if (func_81408A78(arg0, 4) != 0) {
                func_81408A68(arg0);
                func_8140ADA4(arg0, 0.2f);
            }
            break;

        case 2:
            func_8140AE40(arg0, -0.5f, 0.2f);
            break;
    }
}

void func_84354D58(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_843540FC(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            func_814084D8(arg0, 0, 7, 1, arg0->unk_B0, 0);
            func_8140BC2C(arg0, 0x40, arg0->unk_AE);
            break;

        case 4:
            func_81408150(arg0);
            break;
    }

    if (func_8140819C(arg0) != 0) {
        func_8140B0A4(arg0, -2.0f, 0.3f);
        func_81409BDC(arg0);
    }
}

void func_84354E44(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_843540FC(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            if (arg0->unk_2C.y < 0.0f) {
                func_81408150(arg0);
            }
            break;
    }

    if (func_8140819C(arg0) != 0) {
        func_8140B0A4(arg0, -10.0f, 0.8f);
        func_81409BDC(arg0);
    }
}

void func_84354F0C(unk_D_8140E720* arg0) {
    UNUSED s32 pad;

    func_8140C038(arg0);
    func_8140C048(arg0);
    func_8140D5A0(arg0, func_8140C058(arg0));
    func_8140B938(arg0, 0.5f);
    func_8140A52C(arg0, func_81400A78(0x10000), func_81400A78(0x10000), 0);
    func_8140AD8C(arg0, 0.75f);
    func_8140BC20(arg0, 0xFF);
    func_814081BC(arg0);
}

void func_84354FA8(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84354F0C(arg0);
            break;

        case 2:
            func_814084D8(arg0, 0, 7, 1, 2, 0);
            func_8140BC2C(arg0, 0x80, 8);
            func_81409D0C(arg0);
            break;

        case 3:
            func_81408150(arg0);
            break;
    }
}

void func_84355040(unk_D_8140E720* arg0) {
    Vec3s sp28;
    s16 sp26 = func_8140C058(arg0);

    func_8140C038(arg0);
    sp28.x = func_81400B28(0x1000, -0x2000);
    sp28.y = func_81400B28(0x1000, 0x8000);
    sp28.z = 0;
    func_8140A4F0(arg0, sp28);
    func_8140B938(arg0, 0.05f);
    func_8140B95C(arg0, 0.25f);
    func_8140B974(arg0, 0.02f);
    func_8140D5A0(arg0, sp26);
    func_8140BCA8(arg0, 8);
    func_8140AD8C(arg0, (func_81400A78(8) * 0.25f) + 2.0f);
    func_8140B2B4(arg0);
    func_814081BC(arg0);
}

void func_84355164(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84355040(arg0);
            break;

        case 2:
            func_814084D8(arg0, 1, 7, 1, 2, 0);
            if (func_8140BDAC(arg0) != 0) {
                func_8140BC2C(arg0, 0x64, 0x10);
            }
            break;

        case 3:
            func_81408150(arg0);
            break;
    }

    if (func_8140819C(arg0) != 0) {
        func_8140BA1C(arg0);
        func_8140B0A4(arg0, -1.5f, 0.1f);
        func_81409BDC(arg0);
    }
}

void func_84355240(unk_D_8140E720* arg0) {
    switch (arg0->unk_A6) {
        case 0:
            func_81408BE0(arg0, 0.0f, -5.0f, -10.0f);
            break;

        case 1:
            func_81408BE0(arg0, 0.0f, 8.0f, 8.0f);
            break;

        case 2:
            func_81408BE0(arg0, 0.0f, 3.0f, 0.0f);
            break;

        case 3:
            func_81408BE0(arg0, 0.0f, -3.0f, 5.0f);
            break;
    }

    func_8140BCA8(arg0, 6);
    func_814081BC(arg0);
}

void func_84355330(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84355240(arg0);
            break;

        case 2:
            func_8432D844(arg0, func_84355164, &D_843861D0[0x50], 1);
            func_8140BDD0(arg0);
            break;

        case 3:
            func_81408150(arg0);
            break;
    }
}

void func_843553B4(void) {
}

void func_843553BC(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_843540FC(arg0);
            break;

        case 2:
            func_814084D8(arg0, 1, 7, 1, 2, 0);
            if (func_8140BDAC(arg0) != 0) {
                func_8140BC2C(arg0, 0x64, 0x10);
            }
            break;

        case 3:
            func_81408150(arg0);
            break;
    }

    if (func_8140819C(arg0) != 0) {
        func_8140BA1C(arg0);
        func_8140B0A4(arg0, -1.5f, 0.2f);
        func_81409BDC(arg0);
    }
}

void func_84355498(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C058(arg0);

    func_8140B938(arg0, 0.2f);
    func_81408E90(arg0, 5.0f);
    func_8140D5A0(arg0, sp26);
    func_8140BC20(arg0, 0x40);
    func_814081BC(arg0);
}

void func_84355500(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84355498(arg0);
            break;

        case 2:
            func_8140B98C(arg0, 8.0f, 0.1f);
            func_8140BC2C(arg0, 0xFF, 4);
            break;

        case 3:
            func_81408158(arg0);
            break;
    }
}

void func_84355584(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C038(arg0);
    s16 sp24 = func_8140C058(arg0);

    func_8140AD8C(arg0, 100.0f);
    func_8140ADA4(arg0, 3.0f);
    func_8140A094(arg0, 2.0f);
    func_8140A3D8(arg0, 0x400);
    func_8140D5A0(arg0, sp24);
    func_8140B938(arg0, 0.5f - (sp26 * 0.04f));
    func_8140BC20(arg0, (0xFF - (sp26 * 0x10)) & 0xFF);
    func_8140BCA8(arg0, sp26 + 1);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84355670(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84355584(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
                func_8140BCA8(arg0, 0x18);
            }
            break;

        case 3:
            if ((func_8140BDAC(arg0) != 0) && (func_8140B98C(arg0, 0.0f, 0.05f) != 0)) {
                func_814081BC(arg0);
            }
            break;

        case 4:
            func_81408158(arg0);
            break;
    }

    if (func_81408368(arg0) != 0) {
        func_8140AE00(arg0, 0.0f);
        func_8140A4C8(arg0);
        func_81409C94(arg0);
        func_81409B18(arg0, 0.0f);
        func_8140BBC0(arg0, 0xFF, 4);
        func_8140BBF0(arg0, 0xFF, 4);
    }
}

void func_84355794(unk_D_8140E720* arg0) {
    func_8140C038(arg0);
    func_8140A2B8(arg0, func_81400A78(0x10000));
    func_81409900(arg0, func_81400B4C(0x28, 0x28));
    func_8432D844(arg0, func_84355670, &D_843861D0[0x44], 5);
    func_814081BC(arg0);
}

void func_8435581C(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84355794(arg0);
            break;

        case 2:
            func_81408158(arg0);
            break;
    }
}

void func_8435586C(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C038(arg0);

    func_8140BAC8(arg0, 0xDC, 0xFF, 0xFF);
    func_8140D568(arg0, 0x35);
    arg0->unk_1C = (sp26 * 0.05f) + 0.5f;
    func_8140AD8C(arg0, 2.0f);
    func_8140BC20(arg0, (0xFF - (sp26 << 5)) & 0xFF);
    func_8140BCA8(arg0, sp26 + 1);
    func_814083E8(arg0, 0xF);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_8435593C(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8435586C(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
                func_81401020(&arg0->unk_7C, arg0->unk_50, D_84390348, arg0->unk_74);
            }
            break;

        case 3:
            func_8140B14C(arg0, 1.5f);
            if (func_8140826C(arg0, 4) != 0) {
                func_8140AD8C(arg0, 10.0f);
                func_8140BCA8(arg0, func_81401020(&arg0->unk_7C, arg0->unk_50, D_84390348, arg0->unk_74));
            }
            break;

        case 4:
            func_8140B98C(arg0, 0.1f, 0.02f);
            func_8140BAE4(arg0, 0xFF, 4);
            func_8140BB90(arg0, 0xFF, 8);
            func_8140BBF0(arg0, 0xFF, 8);
            func_8140BDD0(arg0);
            break;

        case 5:
            func_81408158(arg0);
            break;
    }

    if (func_81408368(arg0) != 0) {
        func_81409BDC(arg0);
    }
}

void func_84355B08(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C038(arg0);

    func_8140B938(arg0, 0.5f);
    func_81409930(arg0, 100.0f);
    func_8140BCA8(arg0, sp26 + 1);
    func_8140D530(arg0, 0xA);
    func_8140D568(arg0, 0x35);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84355B8C(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84355B08(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            if (func_814084D8(arg0, 0, 0xF, 2, 1, 0) != 0) {
                func_8432D844(arg0, func_8435593C, &D_843861D0[0x26], 5);
            }
            break;

        case 4:
            func_81408158(arg0);
            break;
    }
}

void func_84355C54(unk_D_8140E720* arg0) {
    f32 sp24;
    s16 sp22 = func_8140C038(arg0);

    sp24 = (sp22 + 15.0f) / 20.0f;
    if (sp24 >= 1.0f) {
        sp24 = 1.0f;
    }

    func_8140B938(arg0, sp24);
    func_8140B95C(arg0, 8.0f * sp24);
    func_8140B974(arg0, 0.35f * sp24);
    func_81408E90(arg0, 10.0f);
    func_814083E8(arg0, 0xF);
    func_8140D530(arg0, 0xA);
    func_8140D568(arg0, 0x35);
    func_8140BC20(arg0, 0xFF);
    func_8140BCA8(arg0, sp22 * 8);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84355D70(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84355C54(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
            }
            break;

        case 3:
            func_8140826C(arg0, 0xC);
            break;

        case 4:
            func_8140BC5C(arg0, 0x20, 0x20);
            break;

        case 5:
            func_81408158(arg0);
            break;
    }

    if (func_81408368(arg0) != 0) {
        func_8140BA1C(arg0);
        func_8140BBF0(arg0, 0, 0x10);
        func_8140BBC0(arg0, 0, 8);
    }
}

void func_84355E58(void) {
    func_8432EC28(0, func_843529D8, &D_843861D0[0x34], 0, 1, 0x11, 7, 0, 7);
    func_8432EC28(2, func_84351984, &D_843861D0[0x3D], 0, 8, 0x11, 7, 1, 0);
}

void func_84355EF0(void) {
    func_8432EC28(0, func_843529D8, &D_843861D0[0x34], 0, 1, 0x11, 7, 0, 6);
    func_8432EC28(2, func_84351984, &D_843861D0[0x3D], 0, 8, 0x11, 7, 1, 0);
}

void func_84355F88(void) {
    func_8432EC28(0, func_843529D8, &D_843861D0[0x34], 0, 1, 0x11, 9, 0, 8);
    func_8432EC28(2, func_84351984, &D_843861D0[0x3D], 0, 8, 0x11, 9, 2, 0);
}

void func_84356020(void) {
    func_8432EC28(0, func_843529D8, &D_843861D0[0x34], 0, 1, 0x11, 9, 0, 6);
    func_8432EC28(2, func_84351984, &D_843861D0[0x3D], 0, 8, 0x11, 9, 0, 0);
}

void func_843560B4(void) {
    func_8432EC28(0, func_843529D8, &D_843861D0[0x34], 0, 1, 0x11, 9, 0, 0x10);
    func_8432EC28(2, func_84351984, &D_843861D0[0x3D], 0, 8, 0x11, 9, 0, 0);
}

void func_84356148(void) {
    func_8432EC28(0, func_84353098, &D_843861D0[0x34], 0, 1, 0x11, 9, 3, 0);
}

void func_843561A0(void) {
    func_8432EC28(0, func_84353098, &D_843861D0[0x34], 0, 1, 0x11, 9, 4, 0);
}

void func_843561F8(void) {
    func_8432EC28(0, func_843529D8, &D_843861D0[0x34], 0, 7, 0x11, 9, 1, 0xC);
}

void func_84356254(void) {
    s32 temp_s1 = D_843902E2 & 0xFF;

    func_8432ECA0(0, 8, 6, func_8435226C, &D_843861D0[0x42], 0, 8, 0x11, temp_s1, 0x18, 2);
    func_8432ECA0(1, 8, 6, func_8435226C, &D_843861D0[0x42], 0, 8, 0x11, temp_s1, 0x18, 2);
    func_8432ECA0(2, 8, 6, func_8435226C, &D_843861D0[0x42], 0, 8, 0x11, temp_s1, 0x18, 2);
    func_8432ECA0(4, 8, 6, func_8435226C, &D_843861D0[0x42], 0, 8, 0x11, temp_s1, 0x18, 2);
    func_8432ECA0(0, 6, 0xC, func_84350FC0, &D_843861D0[0x4A], 0, 2, 0x11, temp_s1, 1, 0);
    func_8432ECA0(1, 6, 0xA, func_84350FC0, &D_843861D0[0x4A], 0, 2, 0x11, temp_s1, 1, 0);
}

void func_8435643C(void) {
    UNUSED s32 pad;

    func_8432EC28(0, func_843529D8, &D_843861D0[0x34], 0, 1, 0x11, 9, 3, 5);
    func_8432EC28(2, func_84350FC0, &D_843861D0[0x3D], 0, 8, 0x10, 0x64, 0, 0);
    func_8432EC28(3, func_84350FC0, &D_843861D0[0x3D], 0, 8, 0x10, 0x64, 0, 0);
    func_8432EC28(4, func_8435226C, &D_843861D0[0x42], 0, 8, 9, 0, 0x18, 0);
    func_8432EC28(8, func_8435226C, &D_843861D0[0x42], 0, 4, 9, 0, 0x18, 0);
    func_8432EC28(0xC, func_8435226C, &D_843861D0[0x42], 0, 4, 9, 0, 0x18, 0);
    func_8432F2C8(0, 0x35, 0xE0, 0, 0x20);
}

void func_843565DC(void) {
    func_8432EC28(0, func_843529D8, &D_843861D0[0x34], 0, 1, 0x11, 9, 3, 5);
    func_8432EC28(4, func_843526A8, &D_843861D0[0x40], 0, 1, 0x10, 0x64, 0, 0);
    func_8432ECA0(0, 4, 5, func_8433CCFC, &D_843861D0[0x11], 8, 4, 2, 0, 0, 0);
    func_8432EE5C(0, 0, 0x40, 0xA, 0xC8);
    func_8432F2C8(0, 0x19, 0xE1, 0, 0x40);
}

void func_843566F4(void) {
    func_8432EC28(0, func_84351144, &D_843861D0[0x34], 0, 5, 0x11, D_843902E2, 0, 0);
}

void func_8435674C(void) {
    func_8432ECA0(0, 3, 2, func_84350DAC, &D_843861D0[0x3F], 0, 0x10, 0xA, 0, 0x11, 0);
    func_8432ECA0(0x28, 3, 2, func_84350DAC, &D_843861D0[0x3F], 0, 0x10, 0xA, 0, 0x11, 0);
}

void func_843567F4(void) {
    func_8432EC28(0, func_84352E64, &D_843861D0[0x34], 0, 1, 0x11, 9, 0, 0);
    func_8432EC28(0, func_843512AC, &D_843861D0[0x36], 0, 1, 0xA, 0, 0, 0);
    func_8432ECA0(4, 3, 2, func_84350DAC, &D_843861D0[0x3F], 0, 0x10, 0xA, 0, 0x11, 0);
}

void func_843568C8(void) {
    func_8432EC28(0, func_84352E64, &D_843861D0[0x34], 0, 5, 0x11, 0x64, 9, 0);
    func_8432EC28(8, func_843512AC, &D_843861D0[0x36], 0, 1, 0xA, 0, 0, 0);
    func_8432ECA0(0xC, 3, 2, func_84350DAC, &D_843861D0[0x3F], 0, 0x10, 0xA, 0, 0x11, 0);
}

void func_843569A0(void) {
    func_8432EC28(0, func_84352E64, &D_843861D0[0x34], 0, 5, 0xA, 0, 0xA, 0);
    func_8432EC28(8, func_843512AC, &D_843861D0[0x36], 0, 1, 0xA, 0, 0, 0);
    func_8432ECA0(0xC, 3, 2, func_84350DAC, &D_843861D0[0x3F], 0, 0x10, 0xA, 0, 0x11, 0);
}

void func_84356A74(void) {
    func_8432EC28(0, func_84352E64, &D_843861D0[0x34], 0, 7, 0xA, 0, 0xB, 0);
}

void func_84356AC8(void) {
    func_8432ED0C(0, 8, 0x22);
}

void func_84356AF0(void) {
    func_8432EC28(0xC, func_8435226C, &D_843861D0[0x42], 0, 8, 9, 0, 0x17, 1);
    func_8432EC28(0x12, func_8435226C, &D_843861D0[0x42], 0, 0xA, 9, 0, 0x17, 1);
    func_8432EC28(0x20, func_8435226C, &D_843861D0[0x42], 0, 5, 9, 0, 0x17, 1);
    func_8432EC28(0, func_84351D20, &D_8140E460, 0, 2, 9, 0, 0, 0);
    func_8432EC28(3, func_84351D20, &D_8140E460, 0, 2, 9, 0, 0, 0);
    func_8432EC28(5, func_84351D20, &D_8140E460, 0, 2, 9, 0, 0, 0);
    func_8432EC28(8, func_84351D20, &D_8140E460, 0, 2, 9, 0, 0, 0);
}

void func_84356CA4(void) {
    func_8432ECA0(0, 3, 2, func_84350DAC, &D_843861D0[0x3F], 0, 0x10, 0xA, 0, 0x11, 0);
}

void func_84356D04(void) {
    func_8432ECA0(0, 3, 2, func_8435043C, &D_843861D0[0x4A], 0, 3, 0x11, D_843902E2, 0x11, 0);
    func_8432ECA0(0, 4, 2, func_84350634, &D_843861D0[0x4A], 0, 2, 0x11, D_843902E2, 0x11, 0);
}

void func_84356DBC(void) {
    UNUSED s32 pad;

    func_8432EC28(0, func_8434F554, &D_843861D0[0x29], 0, 1, 0x10, D_843902E2, 0xB, 0);
    func_8432EC28(4, func_8434F554, &D_843861D0[0x29], 0, 1, 0x10, D_843902E2, 0xB, 1);
    func_8432EC28(0xA, func_8434F554, &D_843861D0[0x29], 0, 1, 0x10, D_843902E2, 0xB, 2);
    func_8432EC28(0x1E, func_8434FBE4, &D_843861D0[0x41], 0, 1, 0x18, 0, 0xF, 0);
    func_8432EDE8(0x23, 0, 0x10, 0x14);
}

void func_84356EF4(void) {
    func_8432EE5C(0, 2, 0x10, 0x14, 0xFF);
    func_8432EC28(3, func_8434FF40, &D_843861D0[0x2A], 0, 1, 0x10, D_843902E2, 0x10, 2);
    func_8432EC28(3, func_8434FD6C, &D_843861D0[0x41], 0, 1, 0x18, 0, 0xF, 0);
}

void func_84356FAC(void) {
    s16 tmp = func_843081BC(D_843902EC);

    if (tmp == 0x7B) {
        func_84356DBC();
        return;
    }

    func_8432EC28(0, func_8434F554, &D_843861D0[0x29], 0, 3, 0x10, D_843902E2, 0xB, 0);
    func_8432EC28(4, func_8434F554, &D_843861D0[0x29], 0, 3, 0x10, D_843902E2, 0xB, 1);
    func_8432EC28(0xA, func_8434F554, &D_843861D0[0x29], 0, 3, 0x10, D_843902E2, 0xB, 2);
    func_8432EC28(0x1E, func_8434FBE4, &D_843861D0[0x28], 0, 1, 0x18, 0, 0xF, 0);
    func_8432EDE8(0x23, 0, 0x10, 0x14);
}

void func_84357110(void) {
    s16 tmp = func_843081BC(D_843902EC);

    if (tmp == 0x7B) {
        func_84356EF4();
        return;
    }

    func_8432EE5C(0, 2, 0x10, 0x14, 0xFF);
    func_8432EC28(3, func_8434FF40, &D_843861D0[0x2A], 0, 1, 0x10, D_843902E2, 0x10, 0);
    func_8432EC28(3, func_8434FF40, &D_843861D0[0x2A], 0, 1, 0x10, D_843902E2, 0x10, 1);
    func_8432EC28(3, func_8434FF40, &D_843861D0[0x2A], 0, 1, 0x10, D_843902E2, 0x10, 2);
    func_8432EC28(3, func_8434FD6C, &D_843861D0[0x28], 0, 1, 0x18, 0, 0xF, 0);
}

void func_8435727C(void) {
    UNUSED s16 pad;
    s16 sp3C = func_843081BC(D_843902EC);
    s16 sp3A = 3;

    if (sp3C == 0x7B) {
        sp3A = 1;
    }

    func_8432EC28(0, func_8434F554, &D_843861D0[0x29], 0, sp3A, 0x10, D_843902E2, 0xB, 0);
    func_8432EC28(4, func_8434F554, &D_843861D0[0x29], 0, sp3A, 0x10, D_843902E2, 0xB, 1);
    func_8432EC28(0xA, func_8434F554, &D_843861D0[0x29], 0, sp3A, 0x10, D_843902E2, 0xB, 2);

    if (sp3C == 0x7B) {
        func_8432EC28(0x1E, func_8434FBE4, &D_843861D0[0x41], 0, 1, 0x18, 0, 0xF, 0);
    } else {
        func_8432EC28(0x1E, func_8434FBE4, &D_843861D0[0x28], 0, 1, 0x18, 0, 0xF, 0);
    }
    func_8432EDE8(0x23, 0, 0x10, 0x14);
}

void func_8435742C(void) {
    s16 tmp = func_843081BC(D_843902EC);

    if (tmp == 0x7B) {
        func_8432EC28(0, func_8434FBE4, &D_843861D0[0x41], 0, 1, 0x18, 0, 0xF, 0);
    } else {
        func_8432EC28(0, func_8434FBE4, &D_843861D0[0x28], 0, 1, 0x18, 0, 0xF, 0);
    }
    func_8432EE5C(5, 0, 8, 0x14, 0x80);
}

void func_843574FC(void) {
    s16 tmp = func_843081BC(D_843902EC);

    if (tmp == 0x7B) {
        func_8432EE5C(0, 2, 8, 0x14, 0x80);
        func_8432EC28(3, func_84350100, &D_843861D0[0x2A], 0, 1, 0x10, D_843902E2, 0x10, 2);
        func_8432EC28(3, func_8434FD6C, &D_843861D0[0x41], 0, 1, 0x18, 0, 0xF, 0);
    } else {
        func_8432EE5C(0, 2, 8, 0x14, 0x80);
        func_8432EC28(3, func_84350100, &D_843861D0[0x2A], 0, 1, 0x10, D_843902E2, 0x10, 0);
        func_8432EC28(3, func_84350100, &D_843861D0[0x2A], 0, 1, 0x10, D_843902E2, 0x10, 1);
        func_8432EC28(3, func_84350100, &D_843861D0[0x2A], 0, 1, 0x10, D_843902E2, 0x10, 2);
        func_8432EC28(3, func_8434FD6C, &D_843861D0[0x28], 0, 1, 0x18, 0, 0xF, 0);
    }
}

void func_84357700(void) {
    UNUSED s32 pad;

    func_8432EC28(0, func_8434F554, &D_843861D0[0x29], 0, 1, 0x10, D_843902E2, 0xD, 0);
    func_8432EC28(4, func_8434F554, &D_843861D0[0x29], 0, 1, 0x10, D_843902E2, 0xD, 1);
    func_8432EC28(0xA, func_8434F554, &D_843861D0[0x29], 0, 1, 0x10, D_843902E2, 0xD, 2);
    func_8432EC28(0x1E, func_8434FBE4, &D_843861D0[0x41], 0, 1, 0x18, 0, 0xD, 1);
    func_8432EDE8(0x23, 0, 0x10, 0x29);
}

void func_8435783C(void) {
    UNUSED s32 pad;

    func_8432EE5C(0, 2, 0x10, 0x29, 0xFF);
    func_8432EC28(3, func_8434FF40, &D_843861D0[0x2A], 0, 1, 0x10, D_843902E2, 0xD, 2);
    func_8432EC28(3, func_8434FD6C, &D_843861D0[0x41], 0, 1, 0x18, 0, 0xD, 1);
    func_8432ECA0(0, 1, 5, func_84340940, &D_843861D0[0x2B], 0, 2, 0xE, 0, 0, 0);
    func_8432ECA0(0, 1, 5, func_84340940, &D_843861D0[0x2B], 0, 2, 0xE, 0, 0, 0);
    func_8432ECA0(0, 2, 0xF, func_84340940, &D_843861D0[0x2B], 0, 1, 0xE, 0, 0, 0);
}

void func_843579C0(void) {
    func_8432ECA0(0, 1, 0x24, func_843534BC, &D_843861D0[0x46], 0, 1, 0x11, D_843902E2, 0, 0);
    func_8432EC28(0, func_843532B0, &D_843861D0[0x40], 0, 1, 0x10, D_843902E2, 0, 0);
}

void func_84357A64(void) {
    func_8432EC28(0, func_8434F7A4, &D_843861D0[0x29], 0, 6, 0x10, 0x64, 0, 0);
}

void func_84357AB8(void) {
    func_8432ED0C(0, 8, 0x28);
}

void func_84357AE0(void) {
    func_8432EC28(0, func_8434FA98, &D_843861D0[0x29], 0, 8, 0x10, 9, 0, 0);
    func_8432EC28(0x10, func_8434FA98, &D_843861D0[0x29], 0, 0xA, 0x10, 9, 0, 0);
    func_8432ED0C(0x46, 4, 0xA);
}

void func_84357B80(void) {
    func_8432ED0C(0, 8, 0x17);
}

void func_84357BA8(void) {
    func_8432EB2C(0x10);
    func_8432EC28(0, func_8434FA98, &D_843861D0[0x29], 0, 8, 0x10, 9, 1, 0);
    func_8432EC28(0x10, func_8434FA98, &D_843861D0[0x29], 0, 8, 0x10, 9, 1, 0);
    func_8432EC28(0x20, func_8434FA98, &D_843861D0[0x29], 0, 8, 0x10, 9, 1, 0);
    func_8432EC28(0x30, func_8434FA98, &D_843861D0[0x29], 0, 8, 0x10, 9, 1, 0);
}

void func_84357CC8(void) {
    switch (func_8432C544()) {
        case 0x4D:
            func_8432F344(0, 0x64, 0x3E, 0, 0xA0, 4);
            break;

        case 0x4E:
            func_8432F344(0, 0x64, 0x19, 0, 0xA0, 4);
            break;

        case 0x4F:
            func_8432F344(0, 0x64, 0x2F, 0, 0xA0, 4);
            break;

        case 0x93:
            func_8432F344(0, 0x64, 0x19, 0, 0xA0, 4);
            break;

        case 0x7B:
            func_8432F344(0, 0x64, 0x3E, 0, 0xA0, 4);
            break;

        case 0x8B:
            func_8432F344(0, 0x64, 0x3E, 0, 0xA0, 4);
            break;
    }
    func_8432EC28(0, func_84353AEC, &D_843861D0[0x47], 0, 7, 0x10, 0x64, 1, 0);
}

void func_84357E60(void) {
    func_8432ECA0(0, 2, 3, func_84350828, &D_843861D0[0x49], 0, 8, 0x11, D_843902E2, 0, 0);
    func_8432ECA0(0, 3, 2, func_8435043C, &D_843861D0[0x47], 0, 6, 0x11, D_843902E2, 0x31, 0);
    func_8432ECA0(0, 4, 2, func_84350634, &D_843861D0[0x47], 0, 4, 0x11, D_843902E2, 0x31, 0);
}

void func_84357F64(void) {
    func_8432EC28(0, func_84350BE4, &D_843861D0[0x49], 0, 5, 0x10, 0x64, 0, 0);
    func_8432EC28(3, func_84350BE4, &D_843861D0[0x49], 0, 5, 0x10, 0x64, 0, 0);
    func_8432EC28(0, func_84353AEC, &D_843861D0[0x47], 0, 7, 0x10, 0x64, 1, 0);
}

void func_84358034(void) {
    func_8432F7A0(0, 0xFF, 0x30, 6);
    func_8432F7A0(0x24, 0, 0, 0xFF);
    func_8432F2C8(0, 0x23, 0, 0xFF, 8);
    func_8432EB2C(6);
    func_8432EC28(2, func_84353C40, &D_843861D0[0x4B], 0, 1, 0xA, 0, 0x2F, 0);
    func_8432ECA0(0, 8, 4, func_84353E10, &D_843861D0[0x3D], 0, 3, 9, 0, 0x30, 0);
}

void func_8435811C(void) {
    func_8432ED0C(0, 0x20, 6);
    func_8432F2C8(8, 0xA, 0, 0xFF, 0x40);
    func_8432EF40(0xC, 5, 0x10, 0xA);
    func_8432EC28(0xC, func_843529D8, &D_843861D0[0x34], 0, 4, 9, 0, 0x18, 0xD);
    func_8432EB2C(0x21);
    func_8432EDE8(0, 0, 0x10, 0xA);
    func_8432ED0C(0, 0x10, 0xA);
    func_8432F2C8(0, 0xA, 0xFF, 0, 0x10);
}

void func_843581FC(void) {
    func_8432ED0C(0, 0x20, 6);
    func_8432F2C8(8, 0xA, 0, 0xFF, 0x40);
    func_8432EDE8(0, 0, 0x10, 0xA);
    func_8432EB2C(0x21);
    func_8432ED0C(0, 0x10, 0xA);
    func_8432F2C8(0, 0xA, 0xFF, 0, 0x10);
}

void func_84358288(void) {
    UNUSED s32 pad;

    func_8432F344(0, 1, 0xC, 0, 0xC8, 0x10);
    func_8432ECA0(6, 4, 0xE, func_84354A10, &D_843861D0[0x3D], 0, 1, 0x11, 7, 0x1A, 0);
    func_8432ECA0(7, 8, 7, func_84354A10, &D_843861D0[0x3D], 0, 1, 0x11, 7, 0x1A, 0);
    func_8432EC28(0, func_84334154, &D_843861D0[0x4F], 0, 0x20, 7, 0, 0, 0);
    func_8434DFC0();
}

void func_8435839C(void) {
    func_8432F344(0, 1, 0xC, 0, 0xC8, 4);
    func_8432ECA0(4, 3, 2, func_84350DAC, &D_843861D0[0x3F], 0, 0x10, 0xA, 0, 0x11, 0);
    func_8432ECA0(6, 4, 0xE, func_84354A10, &D_843861D0[0x3D], 0, 1, 0x11, 7, 0x33, 7);
    func_8432ECA0(7, 8, 7, func_84354A10, &D_843861D0[0x3D], 0, 1, 0x11, 7, 0x33, 7);
}

void func_843584C0(void) {
    func_8432ED0C(0, 0x20, 6);
    func_8434AC8C();
    func_8432ECA0(8, 3, 2, func_84350DAC, &D_843861D0[0x3F], 0, 0x10, 0xA, 0, 0x11, 0);
}

void func_84358538(void) {
    func_8432ECA0(4, 3, 2, func_84350DAC, &D_843861D0[0x3F], 0, 0x10, 0xA, 0, 0x11, 0);
}

void func_84358598(void) {
    func_8432EC28(4, func_84354A10, &D_843861D0[0x4A], 0, 8, 0xA, 0, 0x33, 1);
    func_8432EC28(5, func_84354A10, &D_843861D0[0x4A], 0, 8, 0xA, 0, 0x33, 1);
    func_8432EC28(6, func_84354A10, &D_843861D0[0x4A], 0, 8, 0xA, 0, 0x33, 1);
    func_8432EC28(7, func_84354A10, &D_843861D0[0x4A], 0, 8, 0xA, 0, 0x33, 1);
    func_8432EC28(8, func_843529D8, &D_843861D0[0x51], 0, 5, 0x11, 9, 0x17, 0xE);
    func_8432EC28(0x10, func_843529D8, &D_843861D0[0x51], 0, 5, 0x11, 9, 0x17, 0xE);
}

void func_84358738(void) {
    func_8432EC28(4, func_84354A10, &D_843861D0[0x4A], 0, 8, 0xA, 0, 0x33, 1);
    func_8432EC28(5, func_84354A10, &D_843861D0[0x4A], 0, 8, 0xA, 0, 0x33, 1);
    func_8432EC28(6, func_84354A10, &D_843861D0[0x4A], 0, 8, 0xA, 0, 0x33, 1);
    func_8432EC28(7, func_84354A10, &D_843861D0[0x4A], 0, 8, 0xA, 0, 0x33, 1);
    func_8432EC28(8, func_843529D8, &D_843861D0[0x51], 0, 5, 0x11, 9, 0x17, 0xE);
    func_8432EC28(0x10, func_843529D8, &D_843861D0[0x51], 0, 5, 0x11, 9, 0x17, 0xE);
}

void func_843588D8(void) {
    func_8432EC28(0, func_84354A10, &D_843861D0[0x3D], 0, 8, 0xE, 0, 0x33, 2);
    func_8432EC28(0, func_84354A10, &D_843861D0[0x3D], 0, 2, 0xE, 0, 0x33, 2);
    func_8432EC28(0, func_84354A10, &D_843861D0[0x3D], 0, 2, 0xE, 0, 0x33, 2);
    func_8432EC28(0, func_84354A10, &D_843861D0[0x3D], 0, 2, 0xE, 0, 0x33, 2);
    func_8432EC28(4, func_84354A10, &D_843861D0[0x3D], 0, 8, 0xE, 0, 0x33, 2);
    func_8432EC28(8, func_84354A10, &D_843861D0[0x3D], 0, 8, 0xE, 0, 0x33, 2);
}

void func_84358A5C(void) {
    func_8432F2C8(4, 0xA, 0, 0xFF, 0x40);
    func_8432F2C8(9, 0xA, 0xFF, 0, 0x40);
    func_8432EC28(0, func_84354A10, &D_843861D0[0x3D], 0, 8, 0xE, 0, 0x33, 2);
    func_8432EC28(1, func_84354A10, &D_843861D0[0x3D], 0, 8, 0xE, 0, 0x33, 2);
    func_8432EC28(2, func_84354A10, &D_843861D0[0x3D], 0, 8, 0xE, 0, 0x33, 2);
    func_8432EC28(4, func_84354A10, &D_843861D0[0x3D], 0, 8, 0xE, 0, 0x33, 2);
    func_8432EC28(4, func_84354A10, &D_843861D0[0x3D], 0, 8, 0xE, 0, 0x33, 2);
    func_8432EC28(8, func_84354A10, &D_843861D0[0x3D], 0, 8, 0xE, 0, 0x33, 2);
}

void func_84358C18(s32 arg0) {
    func_8432ECA0(0, 1, 4, func_8435581C, &D_8140E460, 0, 1, 2, 0, arg0, 0);
    func_8432ECA0(8, 1, 4, func_8435581C, &D_8140E460, 0, 1, 2, 0, arg0, 0);
    func_8432ECA0(0x10, 1, 8, func_8435581C, &D_8140E460, 0, 1, 2, 0, arg0, 0);
    func_8432ECA0(0x18, 1, 8, func_8435581C, &D_8140E460, 0, 1, 2, 0, arg0, 0);
    func_8432ECA0(0x20, 1, 8, func_8435581C, &D_8140E460, 0, 1, 2, 0, arg0, 0);
    func_8432ECA0(0x30, 1, 8, func_8435581C, &D_8140E460, 0, 1, 2, 0, arg0, 0);
    func_8432ECA0(0x3C, 1, 8, func_8435581C, &D_8140E460, 0, 1, 2, 0, arg0, 0);
}

void func_84358DE4(void) {
    func_8432ED0C(0, 8, 6);
    func_84358C18(0xE);
    func_8432ED0C(0x64, 0x20, 0xA);
}

void func_84358E24(void) {
    func_8432ED0C(0, 8, 6);
    func_84358C18(0x17);
    func_8432EC28(0xA, func_84355500, &D_843861D0[0x3C], 0x1A, 1, 5, 0, 0x33, 0);
    func_8432ED0C(0x64, 0x20, 0xA);
}

void func_84358EA0(void) {
    func_8432F344(0xA, 1, 0xA, 0, 0xFF, 0x20);
}

void func_84358EDC(void) {
    func_8432ED0C(0, 8, 6);
    func_84358C18(0xC);
    func_8432F728(4, 0x32, 0x20, 0xA0);
    func_8432ECA0(4, 8, 5, func_8435226C, &D_843861D0[0x42], 0, 8, 9, 0, 0xC, 9);
}

void func_84358F6C(void) {
    func_8432F2C8(0, 0xA, 0xFF, 0, 0x20);
    func_8432ECA0(4, 2, 2, func_8435226C, &D_843861D0[0x42], 0, 8, 9, 0, 0x17, 1);
}
