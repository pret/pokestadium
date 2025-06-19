#include "fragment62.h"
#include "src/17300.h"
#include "src/12D80.h"
#include "src/6A40.h"
#include "src/F420.h"
#include "src/math_util.h"

static f32 D_84387B00[] = {
    0.0f, 1.0f,  1.0f,  1.3f, 0.8f, 0.9f, 1.3f,  0.8f,  1.0f,  0.9f,  0.6f, 1.2f,  1.2f, 0.6f,  0.9f, 1.5f, 0.8f,
    1.5f, 1.5f,  0.8f,  1.0f, 0.8f, 1.0f, 0.65f, 1.1f,  0.75f, 0.8f,  0.8f, 0.8f,  0.8f, 1.0f,  1.0f, 0.8f, 1.2f,
    1.0f, 0.8f,  1.25f, 1.0f, 1.5f, 0.8f, 1.0f,  1.0f,  0.8f,  0.8f,  1.2f, 1.35f, 0.9f, 1.2f,  1.2f, 1.1f, 0.7f,
    1.1f, 0.9f,  1.5f,  1.0f, 0.9f, 1.0f, 1.3f,  1.0f,  1.38f, 1.15f, 1.4f, 1.3f,  1.2f, 1.0f,  1.0f, 0.9f, 1.3f,
    1.2f, 0.8f,  0.9f,  1.0f, 0.9f, 1.3f, 1.35f, 1.35f, 1.4f,  1.35f, 1.3f, 1.35f, 1.4f, 1.2f,  1.2f, 1.5f, 1.0f,
    1.0f, 0.85f, 1.0f,  1.2f, 1.7f, 1.2f, 1.3f,  1.2f,  1.2f,  0.9f,  1.5f, 1.0f,  1.0f, 1.3f,  2.0f, 0.8f, 1.2f,
    1.2f, 1.2f,  0.8f,  1.2f, 0.8f, 0.8f, 1.2f,  0.8f,  1.2f,  1.25f, 1.4f, 0.9f,  1.2f, 1.25f, 0.9f, 1.2f, 0.7f,
    1.1f, 1.0f,  1.2f,  1.0f, 0.8f, 1.2f, 1.2f,  1.2f,  1.2f,  1.2f,  1.2f, 1.35f, 1.2f, 0.8f,  0.8f, 1.2f, 0.9f,
    1.0f, 1.2f,  1.0f,  1.2f, 1.0f, 1.1f, 1.5f,  1.55f, 1.5f,  1.6f,  1.6f, 1.75f, 1.6f, 1.5f,  1.6f, 1.0f,
};
static f32 D_84387D60[] = {
    0.0f,   0.0f,   -8.0f, 0.0f,   -5.0f,  0.0f,   -10.0f, 0.0f,   -10.0f, 0.0f,   0.0f,   0.0f,   0.0f,   0.0f,
    -35.0f, 0.0f,   0.0f,  0.0f,   0.0f,   0.0f,   -10.0f, 0.0f,   0.0f,   -10.0f, -10.0f, -10.0f, -5.0f,  0.0f,
    -10.0f, -10.0f, 0.0f,  -10.0f, 0.0f,   0.0f,   -10.0f, 0.0f,   0.0f,   0.0f,   -15.0f, 0.0f,   0.0f,   0.0f,
    0.0f,   0.0f,   0.0f,  -15.0f, 0.0f,   0.0f,   0.0f,   0.0f,   -10.0f, -17.0f, 0.0f,   -10.0f, 0.0f,   0.0f,
    0.0f,   -10.0f, -5.0f, -10.0f, -10.0f, 0.0f,   0.0f,   0.0f,   0.0f,   0.0f,   0.0f,   0.0f,   0.0f,   -10.0f,
    0.0f,   0.0f,   0.0f,  0.0f,   0.0f,   0.0f,   0.0f,   0.0f,   -5.0f,  0.0f,   -22.0f, 0.0f,   -25.0f, -20.0f,
    10.0f,  0.0f,   0.0f,  0.0f,   10.0f,  -15.0f, 0.0f,   -5.0f,  0.0f,   -10.0f, 0.0f,   -10.0f, 0.0f,   10.0f,
    0.0f,   0.0f,   0.0f,  0.0f,   -35.0f, -10.0f, 0.0f,   0.0f,   0.0f,   0.0f,   -5.0f,  0.0f,   0.0f,   5.0f,
    -10.0f, 0.0f,   0.0f,  -2.0f,  0.0f,   0.0f,   -10.0f, -10.0f, 0.0f,   0.0f,   0.0f,   0.0f,   0.0f,   0.0f,
    -15.0f, 0.0f,   0.0f,  0.0f,   0.0f,   0.0f,   0.0f,   0.0f,   15.0f,  -5.0f,  0.0f,   0.0f,   0.0f,   0.0f,
    0.0f,   0.0f,   0.0f,  0.0f,   0.0f,   -15.0f, 0.0f,   -10.0f, -25.0f, -20.0f, -20.0f, 0.0f,
};

void func_84340DC0(void) {
    Mtx* sp3C = func_80005F5C(sizeof(Mtx) * 1);
    LookAt* sp38 = func_80005F5C(sizeof(LookAt) * 1);
    unk_D_86002F34_00C* temp_v0 = func_8432FD64();

    guLookAtReflect(sp3C, sp38, temp_v0->unk_60.eye.x, temp_v0->unk_60.eye.y, temp_v0->unk_60.eye.z,
                    temp_v0->unk_60.at.x, temp_v0->unk_60.at.y, temp_v0->unk_60.at.z, temp_v0->unk_60.up.x,
                    temp_v0->unk_60.up.y, temp_v0->unk_60.up.z);
}

void func_84340E40(unk_D_8140E720* arg0, s32 arg1) {
    f32 sp2C = 1.0f;
    s16 sp2A;
    s16 sp28;
    s16 sp26;
    s16 sp24 = func_8140C048(arg0);

    switch (func_8140C058(arg0)) {
        case 30:
            sp2A = 0x23;
            sp28 = 0x24;
            func_843432E4(arg0);
            break;

        case 0:
            sp2A = 0x66;
            sp28 = 0x67;
            sp2C = 0.5f;
            func_843497A8(arg0);
            break;

        case 1:
            sp2A = 0x68;
            sp28 = 0x69;
            sp2C = 0.5f;
            break;

        case 2:
            sp2A = 0x6A;
            sp28 = 0x6B;
            sp2C = 0.5f;
            func_84349940(arg0);
            break;

        case 3:
            sp2A = 0x73;
            sp28 = 0x74;
            sp2C = func_8434A574(arg0);
            break;

        case 4:
            sp2A = 0x78;
            sp28 = 0x79;
            func_8140BAC8(arg0, 0x50, 0x46, 0x3C);
            func_8140BB74(arg0, 0xFF, 0, 0);
            break;

        case 5:
            sp2A = 0x7B;
            sp28 = 0x7C;
            break;

        case 6:
            sp2A = 0x7D;
            sp28 = 0x7E;
            break;

        case 7:
            sp2A = 0x7F;
            sp28 = 0x80;
            break;

        case 8:
            sp2A = 0x81;
            sp28 = 0x82;
            sp2C = 5.0f;
            func_8140D5A0(arg0, 0x17);
            func_8140BC20(arg0, 0x64);
            break;

        case 42:
            sp2A = 0x81;
            sp28 = 0x82;
            func_81408F38(arg0, 300.0f);
            sp2C = 5.0f;
            func_8140D5A0(arg0, 0xC);
            func_8140BC20(arg0, 0x64);
            break;

        case 43:
            sp2A = 0x81;
            sp28 = 0x82;
            sp2C = 5.0f;
            func_8140D5A0(arg0, 0xF);
            func_8140BC20(arg0, 0x32);
            break;

        case 9:
            sp2A = 0x83;
            sp28 = 0x84;
            func_814082B4(arg0, 0x800);
            func_81408E90(arg0, 5.0f);
            break;

        case 10:
            sp2A = 0x85;
            sp28 = 0x86;
            sp2C = 0.5f;
            break;

        case 11:
            sp2A = 0x88;
            sp28 = 0x89;
            sp2C = func_8434AE68(arg0);
            break;

        case 12:
            sp2A = 0x8A;
            sp28 = 0x8B;
            break;

        case 13:
            sp2A = 0x9A;
            sp28 = 0x9B;
            sp2C = 1.5f;
            func_8434B0D8(arg0);

            switch (sp24) {
                case 1:
                    func_8140A594(arg0, 0x6000);
                    break;

                case 2:
                    func_8140A594(arg0, -0x4000);
                    break;
            }
            break;

        case 14:
            sp2A = 0x9C;
            sp2C = func_8434CA90(arg0);
            func_8140BC20(arg0, 0);
            break;

        case 15:
            sp2A = 0x9C;
            sp2C = 1.5f;
            func_8140BC20(arg0, 0);
            break;

        case 16:
            sp2A = 0x9D;
            sp28 = 0x9E;

            switch (func_843081BC(arg0->unk_10)) {
                case 0x5F:
                    func_81408F38(arg0, 15.0f);
                    func_81408CA0(arg0, 15.0f);
                    break;

                case 0x82:
                    func_81408F38(arg0, 15.0f);
                    break;
            }
            break;

        case 17:
            sp2A = 0xA3;
            sp28 = 0xA5;
            break;

        case 18:
            sp2A = 0xA3;
            sp28 = 0xA4;
            sp2C = 1.5f;
            break;

        case 19:
            sp2A = 0xA3;
            sp28 = 0xBB;
            sp2C = 1.5f;
            break;

        case 20:
            sp2A = 0xAA;
            sp28 = 0xAB;
            sp2C = 1.5f;
            break;

        case 21:
            sp2A = 0xAD;
            func_8140BF4C(arg0, 0xBE);
            func_8140BC20(arg0, 0);
            break;

        case 22:
            sp2A = 0x5C;
            sp28 = 0x5D;
            func_843495F0(arg0);
            break;

        case 23:
            sp2A = 0xAE;
            func_8140BC20(arg0, 0);
            break;

        case 24:
            sp2A = 0xAE;
            func_8140BC20(arg0, 0);
            break;

        case 25:
            sp2A = 0xAF;
            sp28 = 0xB0;
            func_8140BAC8(arg0, 0xFF, 0xFF, 0);
            func_8140BB74(arg0, 0xFF, 0, 0);
            func_81408CA0(arg0, 10.0f);
            break;

        case 26:
            sp2A = 0xB6;
            sp2C = func_8434DE24(arg0);
            func_8140BC20(arg0, 0);
            break;

        case 27:
            sp2A = 0xB3;
            sp28 = 0xB4;
            func_8140BC20(arg0, 0x64);
            func_8140BAC8(arg0, 0xFF, 0xFF, 0);
            func_8140BB74(arg0, 0xFF, 0, 0);
            sp2C = 0.8f;
            break;

        case 28:
            sp2A = 0xB3;
            sp28 = 0xB5;
            func_8140BC20(arg0, 0x64);
            func_8140BAC8(arg0, 0xFF, 0xFF, 0);
            func_8140BB74(arg0, 0xFF, 0, 0);
            sp2C = 0.8f;
            break;

        case 29:
            sp2A = 0xBE;
            sp28 = 0xBF;
            break;

        case 31:
            sp2A = 0xC0;
            sp28 = 0xC1;
            func_8140D5A0(arg0, 0x17);
            func_8140BC20(arg0, 0x32);
            sp2C = 1.2f;
            break;

        case 32:
            sp2A = 0xB1;
            sp28 = 0xB2;
            func_8140D5A0(arg0, 0);
            func_8140BC20(arg0, 0);
            break;

        case 33:
            sp2A = 0xB7;
            break;

        case 34:
            sp2A = 0x2E;
            sp28 = 0x2F;
            func_8140A594(arg0, -0x4000);
            sp2C = 0.5f;
            break;

        case 35:
            sp2A = 0x3B;
            sp28 = 0x3C;
            break;

        case 36:
            sp2A = 0x3D;
            sp28 = 0x3E;

            switch (sp24) {
                case 0:
                    sp26 = 0x6000;
                    break;

                case 1:
                    sp26 = 0x4000;
                    break;

                case 2:
                    sp26 = 0x2000;
                    break;
            }
            func_8140A594(arg0, sp26);
            break;

        case 37:
            sp2A = 0x40;
            sp28 = 0x41;
            break;

        case 38:
            sp2A = 0x4B;
            sp28 = 0x4C;
            break;

        case 39:
            sp2A = 0x4D;
            sp28 = 0x4E;
            func_8434749C(arg0);
            func_8140BAC8(arg0, 0xFF, 0xFF, 0xFF);
            func_8140BB74(arg0, 0x37, 0xFF, 0xFF);
            break;

        case 40:
            sp2A = 0x57;
            sp28 = 0x58;
            break;

        case 41:
            sp2A = 0x5A;
            sp28 = 0x5B;
            sp2C = func_84349424(arg0);
            break;
    }

    arg0->unk_14 = func_8432CB68(arg0);
    if (arg0->unk_14 != NULL) {
        switch (arg1) {
            case 0:
                func_8432CD70(arg0->unk_14, sp2A, sp28);
                break;

            case 1:
                func_8432CE00(arg0->unk_14, sp2A);
                func_8432CE78(arg0->unk_14, sp28);
                break;

            case 2:
                func_8432CE00(arg0->unk_14, sp2A);
                break;
        }
        func_8140B938(arg0, sp2C);
        func_814081BC(arg0);
    } else {
        func_81408158(arg0);
    }
}

void func_843416B0(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84340E40(arg0, 0);
            break;

        case 2:
            if (func_80017514(arg0->unk_14) != 0) {
                func_81408150(arg0);
            }
            break;
    }
}

void func_8434171C(unk_D_8140E720* arg0) {
    if (arg0->unk_B2 == 1) {
        func_84340E40(arg0, 0);
    }
}

void func_8434174C(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84340E40(arg0, 0);
            break;

        case 2:
            func_8140BC5C(arg0, arg0->unk_A6, func_8140C040(arg0));
            break;
    }
}

void func_843417AC(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84340E40(arg0, 1);
            break;

        case 2:
            if (func_8432CED4(arg0->unk_14) != 0) {
                func_814081BC(arg0);
            }
            break;

        case 3:
            func_81408158(arg0);
            break;
    }
}

void func_84341830(unk_D_8140E720* arg0) {
    if (arg0->unk_B2 == 1) {
        func_84340E40(arg0, 2);
    }
}

void func_84341860(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84340E40(arg0, 2);
            break;

        case 2:
            func_8140BC5C(arg0, arg0->unk_A6, func_8140C040(arg0));
            break;
    }
}

Gfx* func_843418C0(Gfx* arg0, u8* arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9,
                   s16 argA, s16 argB) {
    gDPLoadTextureTile_4b(arg0++, arg1, G_IM_FMT_I, arg2, 0, 0, 0, arg2 - 1, arg2 - 1, 0, G_TX_NOMIRROR | G_TX_WRAP,
                          G_TX_NOMIRROR | G_TX_WRAP, arg3, arg3, arg6, arg7);

    func_81406204(arg0++, arg4, arg5, arg2, arg2);

    gDPLoadMultiTile_4b(arg0++, arg1, 0x0100, 1, G_IM_FMT_I, arg2, 0, 0, 0, arg2 - 1, arg2 - 1, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, arg3, arg3, argA, argB);

    func_81406288(arg0++, arg8, arg9, arg2, arg2);
    return arg0;
}

Gfx* func_84341B84(Gfx* arg0, arg1_func_8434E21C* arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7,
                   s16 arg8, s16 arg9, s16 argA, s16 argB) {
    gDPLoadTextureTile_4b(arg0++, arg1->unk_00, G_IM_FMT_I, arg2, arg2, 0, 0, arg2 - 1, arg2 - 1, 0,
                          G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, arg3, arg3, arg6, arg7);

    func_81406204(arg0++, arg4, arg5, arg2, arg2);

    gDPLoadMultiTile_4b(arg0++, arg1->unk_04, 0x0100, 1, G_IM_FMT_I, arg2, arg2, 0, 0, arg2 - 1, arg2 - 1, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, arg3, arg3, argA, argB);
    func_81406288(arg0++, arg8, arg9, arg2, arg2);
    return arg0;
}

void func_84341E50(Gfx* arg0) {
    unk_D_8140E720* temp_v0 = func_8432CB60(D_8006F09C);

    gDPPipeSync(arg0++);

    gDPSetPrimColor(arg0++, 0, 0, temp_v0->prim_r, temp_v0->prim_g, temp_v0->prim_b, temp_v0->prim_a);
    gDPSetEnvColor(arg0++, temp_v0->env_r, temp_v0->env_g, temp_v0->env_b, 255);

    gSPEndDisplayList(arg0++);
}

void func_84341F08(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = func_80005F5C(sizeof(Gfx) * 30);
        func_84341E50(arg1->unk_18);
    }
}

void func_84341F44(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2) {
    s16 mask = 5;
    unk_D_8140E720* sp40;
    s16 var_a2;
    s16 sp3C;
    s16 sp3A;
    s16 sp38;
    s16 sp36;
    s16 w = 32;
    s16 h = 32;
    s16 sp30;
    s16 sp2E;
    s16 sp2C;
    s16 sp2A;
    s32 temp_v0_2;

    sp40 = func_8432CB60(D_8006F09C);
    temp_v0_2 = func_8140C040(sp40);
    var_a2 = 0x80;

    switch (temp_v0_2) {
        case 0:
            var_a2 = 0x96;
            sp3C = 2;
            sp3A = 0;
            sp38 = -2;
            sp36 = 0;
            sp30 = 0xC;
            sp2E = 0;
            sp2C = 0xF;
            sp2A = 0;
            break;

        case 1:
            var_a2 = 0xFF;
            sp3C = 0;
            sp3A = 0;
            sp38 = 0xF;
            sp36 = 0;
            sp30 = 0xF;
            sp2E = 0;
            sp2C = 0xE;
            sp2A = 0xD;
            break;

        case 2:
            var_a2 = 0xFF;
            sp3C = 0;
            sp3A = 0;
            sp38 = 1;
            sp36 = 0;
            sp30 = 1;
            sp2E = 1;
            sp2C = 7;
            sp2A = 1;
            break;
    }

    gDPPipeSync(arg0++);
    gDPSetPrimColor(arg0++, 0, var_a2, sp40->prim_r, sp40->prim_g, sp40->prim_b, sp40->prim_a);
    gDPSetEnvColor(arg0++, sp40->env_r, sp40->env_g, sp40->env_b, 255);

    gDPLoadTextureTile_4b(arg0++, arg1->unk_00, G_IM_FMT_I, w, h, 0, 0, w - 1, h - 1, 0, G_TX_NOMIRROR | G_TX_WRAP,
                          G_TX_NOMIRROR | G_TX_WRAP, mask, mask, sp30, sp2E);

    func_81406204(arg0++, sp3C, sp3A, w, h);

    gDPLoadMultiTile_4b(arg0++, arg1->unk_04, 0x0100, 1, G_IM_FMT_I, w, h, 0, 0, w - 1, h - 1, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, mask, mask, sp2C, sp2A);

    func_81406288(arg0++, sp38, sp36, w, h);

    gSPEndDisplayList(arg0++);
}

void func_84342304(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = func_80005F5C(sizeof(Gfx) * 30);
        func_84341F44(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_8434234C(unk_D_8140E720* arg0) {
    func_8140B938(arg0, 3.0f);
    func_81408E90(arg0, 10.0f);
    func_81408ED0(arg0, 15.0f);
    func_8140AD8C(arg0, -5.0f);
    func_8140D530(arg0, 0xA);
    func_8140D568(arg0, 0x19);
    func_8140BC20(arg0, 0x96);
    func_814081BC(arg0);
}

void func_843423C8(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8434234C(arg0);
            break;

        case 2:
            func_8140BDD0(arg0);
            break;

        case 3:
            func_8140BC5C(arg0, 0, 0x20);
            break;

        case 4:
            func_81408158(arg0);
            break;
    }

    func_8140B98C(arg0, 0.0f, 0.1f);
    func_81409CBC(arg0);
}

void func_84342478(unk_D_8140E720* arg0) {
    f32 sp1C = 0.0f;
    f32 sp18 = 0.0f;

    switch (func_843081BC(arg0->unk_10)) {
        case 0x2D:
            sp1C = 15.0f;
            break;

        case 0x36:
            sp18 = 10.0f;
            break;

        case 0x3B:
            sp1C = 10.0f;
            sp18 = 10.0f;
            break;

        case 0x4D:
            sp1C = 10.0f;
            break;

        case 0x4F:
            sp1C = 10.0f;
            sp18 = -10.0f;
            break;

        case 0x59:
            sp1C = 20.0f;
            sp18 = -10.0f;
            break;

        case 0x60:
            sp1C = 15.0f;
            break;

        case 0x66:
            sp1C = 10.0f;
            break;

        case 0x67:
            sp1C = 15.0f;
            break;

        case 0x6C:
            sp1C = 15.0f;
            break;

        case 0x6F:
            sp1C = 15.0f;
            break;

        case 0x73:
            sp1C = 15.0f;
            break;

        case 0x7A:
            sp1C = 15.0f;
            break;

        case 0x7D:
            sp1C = 15.0f;
            break;

        case 0x7F:
            sp18 = 15.0f;
            break;

        case 0x82:
            sp1C = 15.0f;
            sp18 = 5.0f;
            break;

        case 0x94:
            sp1C = 15.0f;
            break;
    }
    func_81408ED0(arg0, sp1C);
    func_81408E90(arg0, sp18);
}

void func_8434261C(unk_D_8140E720* arg0) {
    Vec3f sp34;
    UNUSED s32 pad[2];
    s16 sp2A = func_8140C048(arg0);

    func_8140B938(arg0, 0.05f);

    switch (sp2A) {
        case 0:
            sp34.x = 0;
            sp34.y = -5.0f;
            sp34.z = 0.0f;
            break;

        case 1:
            sp34.x = 0;
            sp34.y = 5.0f;
            sp34.z = 10.0f;
            break;

        case 2:
            sp34.x = 0;
            sp34.y = 5.0f;
            sp34.z = -10.0f;
            break;
    }

    func_81408D78(arg0, sp34);
    func_81408E90(arg0, 10.0f);
    func_84342478(arg0);
    func_8140AD8C(arg0, 0.0f);
    func_8140D530(arg0, 0xA);
    func_8140D568(arg0, 0x19);
    func_8140BC20(arg0, 0x96);
    func_814081BC(arg0);
}

void func_84342758(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8434261C(arg0);
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

    func_8140B98C(arg0, 10.0f, 0.05f);
    func_81409CBC(arg0);
}

void func_84342808(void) {
    func_8432F8E8(0x55, 1);
    func_8432ECA0(0, 8, 0xC, func_84342758, &D_843861D0[0x24], 0xA, 1, 4, 0, 0, 0);
    func_8432ECA0(0, 8, 0xC, func_84342758, &D_843861D0[0x24], 0xA, 1, 4, 1, 0, 0);
    func_8432ECA0(0, 8, 0xC, func_84342758, &D_843861D0[0x24], 0xA, 1, 4, 2, 0, 0);
}

void func_84342908(void) {
    func_8432ED0C(0x30, 0x20, 0xA);
    func_8432ECA0(0, 0xC, 0xA, func_843423C8, &D_843861D0[0x24], 0x14, 1, 4, D_843902E2, 0, 0);
}

void func_84342980(unk_D_8140E720* arg0) {
    f32 sp24 = 0.0f;
    f32 sp20 = 0.0f;
    f32 sp1C = 0.12f;

    switch (func_843081BC(arg0->unk_10)) {
        case 0x4:
            sp24 = 5.0f;
            break;
        case 0xF:
            sp24 = 5.0f;
            break;
        case 0x16:
            sp24 = 3.0f;
            break;
        case 0x1F:
            sp24 = 5.0f;
            break;
        case 0x22:
            sp24 = 3.0f;
            break;
        case 0x24:
            sp24 = 15.0f;
            sp20 = 15.0f;
            break;
        case 0x2A:
            sp20 = 12.0f;
            break;
        case 0x2D:
            sp24 = -15.0f;
            sp20 = 20.0f;
            break;
        case 0x39:
            sp24 = 10.0f;
            break;
        case 0x41:
            sp24 = 8.0f;
            break;
        case 0x4A:
            sp24 = 10.0f;
            break;
        case 0x4C:
            sp24 = 2.0f;
            break;
        case 0x4F:
            sp20 = 8.0f;
            sp24 = 7.0f;
            break;
        case 0x50:
            sp20 = 5.0f;
            sp24 = 7.0f;
            break;
        case 0x54:
            sp20 = 20.0f;
            sp24 = 20.0f;
            break;
        case 0x55:
            sp24 = 20.0f;
            sp20 = 25.0f;
            break;
        case 0x5A:
            sp24 = -15.0f;
            sp20 = 7.0f;
            break;
        case 0x5B:
            sp24 = -10.0f;
            break;
        case 0x5E:
            sp24 = 5.0f;
            break;
        case 0x61:
            sp24 = 5.0f;
            break;
        case 0x73:
            sp24 = 12.0f;
            break;
        case 0x7F:
            sp24 = 3.0f;
            break;
        case 0x80:
            sp24 = 3.0f;
            break;
        case 0x82:
            sp1C = 0.08f;
            sp20 = 5.0f;
            break;
        case 0x83:
            sp1C = 0.08f;
            sp24 = 5.0f;
            break;
        case 0x86:
            sp24 = 3.0f;
            break;
        case 0x88:
            sp24 = 3.0f;
            break;
        case 0x8A:
            sp24 = 15.0f;
            break;
        case 0x8C:
            sp24 = 12.0f;
            sp20 = 10.0f;
            break;
        case 0x8E:
            sp24 = 10.0f;
            break;
        case 0x91:
            sp24 = 3.0f;
            break;
    }

    func_81408ED0(arg0, sp24 + 5.0f);
    func_81408E90(arg0, sp20);
    func_8140B938(arg0, sp1C);
}

void func_84342C54(unk_D_8140E720* arg0) {
    func_84342980(arg0);
    func_814081BC(arg0);
}

void func_84342C7C(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84342C54(arg0);
            break;

        case 3:
            func_8140BC5C(arg0, 0, 0x20);
            break;

        case 4:
            func_81408158(arg0);

        case 2:
            break;
    }
}

void func_84342CF0(void) {
    func_8432EC28(0, func_84342C7C, &D_843861D0[0x2F], 0, 1, 0x10, D_843902E2, 0, 0);
}

void func_84342D48(unk_D_8140E720* arg0) {
    f32 var_fs0 = 0.0f;

    switch (func_843081BC(arg0->unk_10)) {
        case 0xF:
            var_fs0 = -13.0f;
            break;
        case 0x10:
            var_fs0 = -35.0f;
            func_81408ED0(arg0, -5.0f);
            break;
        case 0x11:
            var_fs0 = -45.0f;
            func_81408ED0(arg0, -10.0f);
            break;
        case 0x12:
            var_fs0 = -45.0f;
            func_81408ED0(arg0, -10.0f);
            break;
        case 0x16:
            var_fs0 = -15.0f;
            break;
        case 0x19:
            var_fs0 = -10.0f;
            break;
        case 0x22:
            var_fs0 = 10.0f;
            break;
        case 0x29:
            func_81408ED0(arg0, -10.0f);
            var_fs0 = -60.0f;
            break;
        case 0x34:
            var_fs0 = -10.0f;
            break;
        case 0x36:
            var_fs0 = -5.0f;
            break;
        case 0x3B:
            var_fs0 = 25.0f;
            break;
        case 0x4A:
            var_fs0 = -30.0f;
            break;
        case 0x4C:
            var_fs0 = -10.0f;
            break;
        case 0x4D:
            var_fs0 = -5.0f;
            break;
        case 0x51:
            var_fs0 = -30.0f;
            break;
        case 0x52:
            var_fs0 = -8.0f;
            break;
        case 0x5A:
            var_fs0 = -12.0f;
            break;
        case 0x5B:
            var_fs0 = -15.0f;
            break;
        case 0x64:
            var_fs0 = -12.0f;
            break;
        case 0x66:
            var_fs0 = -20.0f;
            break;
        case 0x67:
            var_fs0 = 5.0f;
            func_81408ED0(arg0, 10.0f);
            break;
        case 0x6C:
            var_fs0 = 10.0f;
            break;
        case 0x70:
            var_fs0 = 15.0f;
            func_81408ED0(arg0, -10.0f);
            break;
        case 0x74:
            var_fs0 = -20.0f;
            break;
        case 0x75:
            var_fs0 = -10.0f;
            break;
        case 0x79:
            var_fs0 = -8.0f;
            break;
        case 0x7A:
            var_fs0 = -5.0f;
            break;
        case 0x7B:
            var_fs0 = -5.0f;
            break;
        case 0x7F:
            var_fs0 = 5.0f;
            break;
        case 0x80:
            var_fs0 = -12.0f;
            break;
        case 0x82:
            var_fs0 = -10.0f;
            func_8140B938(arg0, 0.15f);
            break;
        case 0x86:
            var_fs0 = -5.0f;
            func_8140901C(arg0, 5.0f);
            break;
        case 0x87:
            var_fs0 = -15.0f;
            break;
        case 0x89:
            var_fs0 = -30.0f;
            break;
        case 0x93:
            var_fs0 = 18.0f;
            func_81408ED0(arg0, -15.0f);
            break;
        case 0x94:
            var_fs0 = 15.0f;
            break;
        case 0x97:
            var_fs0 = -13.0f;
            break;
    }
    func_81408E90(arg0, var_fs0);
}

void func_84343064(unk_D_8140E720* arg0, s16 arg1) {
    Vec3f sp24;

    arg0->unk_14 = func_8432CB68(arg0);

    if (arg0->unk_14 != NULL) {
        func_8432CD70(arg0->unk_14, 0x21, 0x22);
        func_8140B938(arg0, 0.2f);
        func_84342D48(arg0);
        func_8000E88C(&sp24, (arg1 * 5.0f * 2) + -10.0f, 5.0f, 10.0f);
        func_814091B4(arg0, sp24);

        switch (arg1) {
            case 0:
                func_8140A2CC(arg0, 0x1400);
                break;

            case 1:
                func_81408E90(arg0, 2.0f);
                func_8140A2CC(arg0, 0);
                break;

            case 2:
                func_8140A2CC(arg0, -0x1400);
                break;
        }

        func_814081BC(arg0);
    } else {
        func_81408158(arg0);
    }
}

void func_843431B0(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C038(arg0);

    switch (arg0->unk_B2) {
        case 1:
            func_8140BCA8(arg0, sp26 * 8);
            func_814081BC(arg0);
            break;

        case 2:
            if (func_8140BDAC(arg0) != 0) {
                func_84343064(arg0, sp26);
            }
            break;

        case 3:
            if (func_80017514(arg0->unk_14) != 0) {
                func_814081BC(arg0);
            }
            break;

        case 4:
            func_81408158(arg0);
            break;
    }
}

void func_84343288(void) {
    func_8432F8E8(0x55, 1);
    func_8432EC28(0, func_843431B0, &D_8140E460, 0x1E, 3, 6, 0, 0, 0);
}

void func_843432E4(unk_D_8140E720* arg0) {
    f32 sp1C = 10.0f;
    f32 sp18 = 0.0f;

    switch (func_843081BC(arg0->unk_10)) {
        case 0x5:
            sp18 = 10.0f;
            break;
        case 0xB:
            sp1C = 20.0f;
            break;
        case 0xC:
            sp1C = 8.0f;
            break;
        case 0xD:
            sp1C = 15.0f;
            break;
        case 0xF:
            sp1C = -10.0f;
            break;
        case 0x11:
            sp18 = 35.0f;
            sp1C = 0.0f;
            break;
        case 0x12:
            sp18 = 35.0f;
            sp1C = -5.0f;
            break;
        case 0x15:
            sp1C = 4.0f;
            break;
        case 0x16:
            sp18 = 5.0f;
            sp1C = 0.0f;
            break;
        case 0x18:
            sp18 = 8.0f;
            break;
        case 0x1C:
            sp18 = 5.0f;
            break;
        case 0x21:
            sp18 = 5.0f;
            break;
        case 0x26:
            sp1C = 15.0f;
            sp18 = 15.0f;
            break;
        case 0x28:
            sp1C = 15.0f;
            sp18 = 5.0f;
            break;
        case 0x29:
            sp1C = 0.0f;
            break;
        case 0x2A:
            sp18 = 20.0f;
            break;
        case 0x2B:
            sp1C = 15.0f;
            break;
        case 0x2D:
            sp1C = 10.0f;
            sp18 = 15.0f;
            func_8140901C(arg0, -1.0f);
            break;
        case 0x30:
            sp18 = 30.0f;
            sp1C = -2.0f;
            func_8140901C(arg0, -5.0f);
            break;
        case 0x31:
            sp1C = 5.0f;
            break;
        case 0x32:
            sp1C = 20.0f;
            break;
        case 0x33:
            sp1C = 25.0f;
            break;
        case 0x34:
            sp1C = 20.0f;
            break;
        case 0x36:
            sp1C = 15.0f;
            break;
        case 0x3B:
            sp1C = 20.0f;
            sp18 = 10.0f;
            break;
        case 0x3C:
            sp1C = 5.0f;
            break;
        case 0x3D:
            sp1C = 5.0f;
            break;
        case 0x3F:
            sp1C = 5.0f;
            break;
        case 0x40:
            sp18 = 10.0f;
            sp1C = 0.0f;
            break;
        case 0x41:
            sp1C = 20.0f;
            break;
        case 0x43:
            sp1C = 0.0f;
            break;
        case 0x44:
            sp18 = 8.0f;
            break;
        case 0x46:
            sp1C = -15.0f;
            break;
        case 0x47:
            sp1C = -5.0f;
            break;
        case 0x48:
            sp1C = -8.0f;
            break;
        case 0x49:
            sp1C = 0.0f;
            break;
        case 0x4B:
            sp1C = 0.0f;
            break;
        case 0x4C:
            sp1C = 0.0f;
            break;
        case 0x4D:
            sp1C = -10.0f;
            sp18 = 15.0f;
            break;
        case 0x4E:
            sp1C = -5.0f;
            break;
        case 0x4F:
            sp18 = 10.0f;
            break;
        case 0x51:
            sp1C = 0.0f;
            break;
        case 0x54:
            sp1C = 5.0f;
            break;
        case 0x55:
            sp1C = 5.0f;
            break;
        case 0x56:
            sp1C = 15.0f;
            sp18 = 15.0f;
            break;
        case 0x58:
            sp18 = 15.0f;
            break;
        case 0x59:
            sp18 = 40.0f;
            break;
        case 0x5B:
            sp1C = 0.0f;
            break;
        case 0x5C:
            sp18 = 10.0f;
            break;
        case 0x5D:
            sp18 = 15.0f;
            break;
        case 0x5E:
            sp1C = 5.0f;
            sp18 = 5.0f;
            break;
        case 0x5F:
            func_8140901C(arg0, 23.0f);
            sp1C = -10.0f;
            sp18 = 0.0f;
            break;
        case 0x60:
            sp1C = 5.0f;
            sp18 = 10.0f;
            break;
        case 0x61:
            sp18 = 10.0f;
            break;
        case 0x62:
            sp18 = 10.0f;
            break;
        case 0x63:
            sp1C = 15.0f;
            sp18 = 60.0f;
            break;
        case 0x65:
            sp1C = 0.0f;
            sp18 = 20.0f;
            break;
        case 0x66:
            sp18 = 10.0f;
            break;
        case 0x67:
            sp18 = 40.0f;
            break;
        case 0x68:
            sp1C = 15.0f;
            break;
        case 0x6A:
            sp1C = 8.0f;
            break;
        case 0x6B:
            sp1C = 15.0f;
            break;
        case 0x6C:
            sp18 = 15.0f;
            break;
        case 0x6D:
            sp1C = 5.0f;
            break;
        case 0x6E:
            sp1C = 5.0f;
            break;
        case 0x6F:
            sp18 = 15.0f;
            sp1C = 0.0f;
            break;
        case 0x70:
            sp1C = 17.0f;
            sp18 = 10.0f;
            break;
        case 0x73:
            sp18 = 50.0f;
            break;
        case 0x75:
            sp1C = -10.0f;
            sp18 = 25.0f;
            break;
        case 0x77:
            sp1C = 0.0f;
            break;
        case 0x79:
            sp18 = 10.0f;
            sp1C = 5.0f;
            func_8140901C(arg0, -3.0f);
            break;
        case 0x7B:
            sp1C = 5.0f;
            break;
        case 0x7C:
            sp18 = 10.0f;
            break;
        case 0x7D:
            sp18 = 10.0f;
            break;
        case 0x7F:
            sp1C = 25.0f;
            break;
        case 0x80:
            sp18 = 5.0f;
            sp1C = -5.0f;
            func_8140901C(arg0, 3.0f);
            break;
        case 0x82:
            sp1C = 15.0f;
            sp18 = 20.0f;
            func_8140901C(arg0, 3.0f);
            break;
        case 0x83:
            sp18 = 10.0f;
            break;
        case 0x84:
            sp1C = 15.0f;
            break;
        case 0x85:
            sp1C = 20.0f;
            break;
        case 0x86:
            sp18 = 10.0f;
            break;
        case 0x8B:
            sp1C = 5.0f;
            break;
        case 0x8D:
            sp18 = 15.0f;
            sp1C = 0.0f;
            break;
        case 0x8E:
            sp1C = -15.0f;
            sp18 = 25.0f;
            break;
        case 0x8F:
            sp1C = 15.0f;
            sp18 = 30.0f;
            break;
        case 0x90:
            sp18 = 15.0f;
            break;
        case 0x91:
            sp1C = 15.0f;
            sp18 = 10.0f;
            break;
        case 0x92:
            sp1C = 15.0f;
            sp18 = 20.0f;
            break;
        case 0x94:
            sp18 = 15.0f;
            break;
        case 0x95:
            func_81408FAC(arg0, 1.0f);
            sp1C = 10.0f;
            sp18 = 15.0f;
            break;
        case 0x96:
            sp18 = 20.0f;
            sp1C = 7.0f;
            break;
        case 0x97:
            break;
    }
    func_81408E90(arg0, sp1C);
    func_81408ED0(arg0, sp18);
}

void func_84343988(void) {
    func_8432EC28(0, func_8434171C, &D_8140E460, 0x1E, 1, 0xB, 0, 0x1E, 0);
    func_8432EB2C(0xF);

    switch (func_8432C544()) {
        case 0x70:
            func_8432ECA0(0, 0x10, 8, func_8435226C, &D_843861D0[0x44], 0, 4, 0xB, 0, 0x18, 5);
            break;

        case 0x71:
            func_8432ED0C(0, 0x10, 0x20);
            func_8432F344(0, 0, 0xA, 0, 0xFF, 0x30);
            func_8432ECA0(0, 0x10, 8, func_8435226C, &D_843861D0[0x44], 0, 8, 0xB, 0, 0x17, 5);
            func_8432ED74(0, 1, 0x20, 0xA, 0xFF);
            break;

        case 0x73:
            func_8432ED0C(0, 0x10, 0x20);
            func_8432F344(0, 0, 0xA, 0, 0xFF, 0x30);
            func_8432ECA0(0, 0x10, 8, func_8435226C, &D_843861D0[0x44], 0, 8, 0xB, 0, 0, 5);
            func_8432ED74(0, 1, 0x20, 0xA, 0xFF);
            break;
    }
}

void func_84343B9C(Gfx* arg0, s32 arg1, u16 arg2) {
    func_84340DC0();

    switch (func_8432C544()) {
        case 0x70:
            gDPPipeSync(arg0++);
            gDPSetPrimColor(arg0++, 0, 0x80, 255, 255, 255, 255);
            gDPSetEnvColor(arg0++, 155, 255, 255, 255);
            break;

        case 0x71:
            gDPPipeSync(arg0++);
            gDPSetPrimColor(arg0++, 0, 0x80, 255, 255, 255, 255);
            gDPSetEnvColor(arg0++, 255, 255, 100, 255);
            break;

        case 0x73:
            gDPPipeSync(arg0++);
            gDPSetPrimColor(arg0++, 0, 0x80, 255, 255, 100, 255);
            gDPSetEnvColor(arg0++, 255, 100, 0, 255);
            break;
    }

    arg0 = func_843418C0(arg0, arg1, 0x20, 5, 0, 2, 0, 0, 0, 1, 0, 0);

    gSPEndDisplayList(arg0++);
}

void func_84343D24(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = func_80005F5C(sizeof(Gfx) * 30);
        func_84343B9C(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_84343D6C(unk_D_8140E720* arg0) {
    f32 sp24 = 1.2f;
    f32 sp20 = 0.0f;
    s32 temp_v0 = func_843081BC(arg0->unk_10);

    if (temp_v0 < 0x98) {
        sp24 = D_84387B00[temp_v0];
        sp20 = D_84387D60[temp_v0];
    }

    switch (temp_v0) {
        case 0x29:
            func_81408E90(arg0, 35.0f);
            break;

        case 0x57:
            func_81408E90(arg0, -10.0f);
            break;

        case 0x94:
            func_8140901C(arg0, 15.0f);
            break;
    }

    func_8140B938(arg0, sp24);
    func_81408ED0(arg0, sp20);
}

void func_84343E44(unk_D_8140E720* arg0, UNUSED s16 arg1) {
    arg0->unk_14 = func_8432CB68(arg0);
    if (arg0->unk_14 != NULL) {
        func_8432CD70(arg0->unk_14, 0x25, 0x26);
        func_84343D6C(arg0);
        func_8140BCA8(arg0, 0x20);
        func_814081BC(arg0);
    } else {
        func_81408158(arg0);
    }
}

void func_84343EB4(unk_D_8140E720* arg0) {
    s16 temp_a1 = func_8140C038(arg0);

    switch (arg0->unk_B2) {
        case 1:
            func_84343E44(arg0, temp_a1);
            break;

        case 2:
            if (func_8140BDAC(arg0) != 0) {
                func_8432D8E8(arg0, func_8435226C, &D_843861D0[0x42], 8, 0x18, 3);
                func_8140BCA8(arg0, 0x10);
            }
            break;

        case 3:
            func_8140B9D0(arg0, 0.0f, 0.05f);
            func_8140BC2C(arg0, 0, 8);
            break;

        case 4:
            func_81408158(arg0);
            break;
    }
}

void func_84343FA4(Gfx* arg0, u16 arg1) {
    unk_D_86002F58_004_000* tmp = D_8006F09C;

    gDPPipeSync(arg0++);

    gDPSetPrimColor(arg0++, 0, 0x80, 255, 255, 255, tmp->unk_01D);

    func_81406204(arg0++, 1, 1, 0x20, 0x20);
    func_81406288(arg0++, 2, 2, 0x20, 0x20);

    gSPEndDisplayList(arg0++);
}

void func_84344050(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = func_80005F5C(sizeof(Gfx) * 10);
        func_84343FA4(arg1->unk_18, D_8006F084);
    }
}

void func_84344094(void) {
    func_8432EC28(0, func_84343EB4, &D_8140E460, 0x1E, 1, 7, 0, 0, 0);
    func_8432EC28(0x14, func_84332BE4, &D_8140E460, 0x50, 1, 0, 0, 0x35, 0);
}

void func_8434411C(unk_D_8140E720* arg0) {
    s16 sp26;
    u16 sp24;
    u16 sp22;

    sp26 = func_8432C544();
    sp24 = 0x19;
    sp22 = 0xA;
    func_8140BECC(arg0, 7);
    func_8140B938(arg0, 1.0f);
    func_81408BE0(arg0, 160.0f, 120.0f, 0.0f);

    switch (sp26) {
        case 0x4E:
        case 0x93:
            break;

        case 0x4D:
            sp24 = 0x3E;
            sp22 = 0;
            break;

        case 0x4F:
            sp24 = 0x35;
            break;
    }

    func_8140D530(arg0, sp24);
    func_8140D568(arg0, sp22);
    func_8140BC20(arg0, 0);
    func_814081BC(arg0);
}

void func_843441F8(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8434411C(arg0);
            break;

        case 2:
            func_8140BC5C(arg0, 0xFF, 4);
            break;
    }
}

void func_84344248(void) {
    func_8432EC28(8, func_843441F8, &D_843861D0[0x32], 0, 1, 0x18, 0, 0, 0);
    func_8432EC28(8, func_843441F8, &D_843861D0[0x31], 0, 1, 0x18, 0, 0, 0);
    func_8432ECA0(0, 3, 0x14, func_84353AEC, &D_843861D0[0x47], 0, 1, 0x10, 0x64, 0, 0);
}

void func_84344318(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C058(arg0);

    func_8140BECC(arg0, 7);
    func_8140B938(arg0, 1.0f);
    func_81408BE0(arg0, 160.0f, 120.0f, 0.0f);
    func_8140D5A0(arg0, sp26);
    func_8140BC20(arg0, 0);
    func_814081BC(arg0);
}

void func_84344390(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84344318(arg0);
            break;

        case 2:
            func_8140BC5C(arg0, 0xB4, 8);
            break;
    }
}

void func_843443E0(void) {
    func_8432EC28(8, func_84344390, &D_843861D0[0x33], 0, 1, 0x18, 0, 0x1C, 0);
    func_8432EC28(0, func_84353AEC, &D_843861D0[0x47], 0, 0xF, 0x11, D_843902E2, 0, 0);
}

void func_84344474(void) {
    func_8432EC28(8, func_84344390, &D_843861D0[0x33], 0, 1, 0x18, 0, 0x1E, 0);
    func_8432EC28(0, func_84353AEC, &D_843861D0[0x47], 0, 0xF, 0x11, D_843902E2, 0, 0);
}

void func_84344508(void) {
    func_8432EC28(8, func_84344390, &D_843861D0[0x33], 0, 1, 0x18, 0, 0x1D, 0);
    func_8432EC28(0, func_84353AEC, &D_843861D0[0x47], 0, 0xF, 0x11, D_843902E2, 0, 0);
}

void func_8434459C(unk_D_8140E720* arg0) {
    func_8140B938(arg0, 0.2f);
    func_8140D5A0(arg0, 0xD);
    func_8140BC20(arg0, 0xFF);
    func_814081BC(arg0);
}

void func_843445E4(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8434459C(arg0);
            break;

        case 2:
            func_814084D8(arg0, 0, 7, 1, 2, 0);
            func_8140BC2C(arg0, 0x20, 0x18);
            break;

        case 3:
            func_81408158(arg0);
            break;
    }

    func_8140B98C(arg0, 0.1f, 0.01f);
}

void func_84344698(unk_D_8140E720* arg0) {
    s16 sp2E = func_8140C038(arg0);

    func_8140B938(arg0, 0.5f);
    func_8140AD8C(arg0, 4.5f);
    func_8140A52C(arg0, func_81400B28(0x800, -0x3800), func_81400B00(0x1400), 0);
    func_8140BCA8(arg0, sp2E * 2);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84344734(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84344698(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                arg0->unk_14 = func_8432CB68(arg0);
                func_8432CE00(arg0->unk_14, 0x9F);
                func_81408328(arg0);
                func_8140BCA8(arg0, func_81400A78(3));
            }
            break;

        case 3:
            if (func_8140BDD0(arg0) != 0) {
                func_8432D8E8(arg0, func_8435226C, &D_843861D0[0x42], 1, 0x17, 4);
            }
            break;

        case 4:
            func_8140826C(arg0, 0x1E);
            break;

        case 5:
            func_81408158(arg0);
            break;
    }

    if (func_81408368(arg0) != 0) {
        func_8140A76C(arg0, 0x1800, 0x400);
        func_81409D0C(arg0);
        func_8140A5B0(arg0, 0x2000);
        func_8432D844(arg0, func_843445E4, &D_843861D0[0x4A], 1);
    }
}

void func_84344888(unk_D_8140E720* arg0) {
    f32 sp1C = 0.0f;

    if (func_843081BC(arg0->unk_10) == 0x8C) {
        sp1C = 5.0f;
    }
    func_81408E90(arg0, sp1C);
}

void func_843448D8(unk_D_8140E720* arg0) {
    arg0->unk_14 = func_8432CB68(arg0);
    if (arg0->unk_14 != NULL) {
        func_8432CD70(arg0->unk_14, 0x2B, 0x2C);
        func_8140B938(arg0, 0.25f);
        func_8140A2B8(arg0, func_81400A78(0x10000));
        func_84344888(arg0);
        func_814081BC(arg0);
    } else {
        func_81408158(arg0);
    }
}

void func_8434495C(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8140BCA8(arg0, func_81400A78(0x18));
            func_814081BC(arg0);
            break;

        case 2:
            if (func_8140BDAC(arg0) != 0) {
                func_843448D8(arg0);
                func_8432EC28(0, func_8435226C, &D_843861D0[0x42], 0, 1, 0x10, arg0->unk_CD, 0x17, 4);
            }
            break;

        case 3:
            if (func_80017514(arg0->unk_14) != 0) {
                func_814081BC(arg0);
            }
            break;
    }
}

void func_84344A4C(void) {
    func_8432ECA0(0, 4, 5, func_84344734, &D_8140E460, 0, 2, 0x11, D_843902E2, 0, 0);
    func_8432ECA0(0, 8, 3, func_84354A10, &D_843861D0[0x4A], 0, 1, 0x11, D_843902E2, 0x33, 6);
}

void func_84344B04(void) {
    s32 i;
    s32 var_s2 = 0;
    s32 tmp;
    s32 end = D_843902E8->unk_000.unk_0A7;

    if (end != 0) {
        for (i = 0; i < end; i++) {
            tmp = D_843902E8->unk_000.unk_0A8[i].unk_00;
            func_8432EC28(0, func_8434495C, &D_8140E460, 0, 1, 0x10, tmp, 0, 0);
            var_s2++;
            if (var_s2 >= 8) {
                break;
            }
        }
    }
}

void func_84344BDC(void) {
    func_8432EC28(0, func_8434171C, &D_8140E460, 0, 1, 0xA, 0, 0x22, 0);
    func_8432ECA0(4, 2, 4, func_8435226C, &D_843861D0[0x42], 0, 4, 9, 0, 0x17, 1);
}

void func_84344C7C(Gfx* arg0, u8* arg1) {
    func_84340DC0();
    arg0 = func_843418C0(arg0, arg1, 0x20, 5, 2, 0, 0, 0, 1, 0, 0, 0);
    gSPEndDisplayList(arg0++);
}

void func_84344CE8(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = func_80005F5C(sizeof(Gfx) * 30);
        func_84344C7C(arg1->unk_18, arg1->unk_14);
    }
}

void func_84344D28(unk_D_8140E720* arg0) {
    arg0->unk_14 = func_8432CC54(arg0);
    if (arg0->unk_14 != NULL) {
        func_8432CE00(arg0->unk_14, 0x30);
        func_814082B4(arg0, 0x200);
        func_8140B950(arg0, 5.3f);
        func_8140BC20(arg0, 0);
        func_814081BC(arg0);
    } else {
        func_81408158(arg0);
    }
}

void func_84344DA4(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84344D28(arg0);
            break;

        case 2:
            func_8140BC5C(arg0, 0xFF, 0x20);
            break;
    }

    if (func_8140819C(arg0) != 0) {
        func_8432D340(&arg0->unk_50, 3700.0f);
    }
}

void func_84344E20(unk_D_8140E720* arg0) {
    UNUSED s32 pad[2];
    s16 sp26 = func_8140C038(arg0);
    UNUSED s16 pad2;
    s16 sp22;

    func_8140C040(arg0);
    sp22 = func_8140C058(arg0);
    func_8140BCA8(arg0, sp26 * 2);
    func_8140D5A0(arg0, func_8140C058(arg0));
    func_8140B938(arg0, 1.2f);
    func_8140B95C(arg0, 1.0f);
    func_8140B974(arg0, 0.02f);
    func_8140959C(arg0, 5, 0xF, 0xF);
    func_81408E90(arg0, 10.0f);
    func_8140AD8C(arg0, (func_81400A78(0xA) * 0.5f) + 8.0f);
    func_8140D5A0(arg0, sp22);
    func_8140BC20(arg0, 0xC8);
    func_8140BF4C(arg0, 4);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84344F58(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84344E20(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
                func_8140BCA8(arg0, 4);
            }
            break;

        case 3:
            func_8140BA1C(arg0);
            func_814084D8(arg0, 1, 7, 1, 2, 0);
            func_81409EA0(arg0);
            func_8140BC2C(arg0, 0x40, 8);
            break;

        case 4:
            func_81408150(arg0);
            break;
    }
}

void func_84345038(void) {
    func_8432ED0C(0, 0x10, 0x35);
    func_8432EFB4(0, 0xFF, 0x10, 0xA, 0x96);
    func_8432EC28(0, func_84344DA4, &D_8140E460, 0x1E, 1, 0x14, 0, 0, 0);
}

void func_843450B4(void) {
    func_8432ECA0(0, 0xA, 2, func_843416B0, &D_8140E460, 0, 1, 0xC, 0, 0x2A, 0);
    func_8432F538(4, 0xA, 0x35, 8, 0xC8, 0x18);
    func_8432EB20(4);
    func_8432ECA0(0, 5, 5, func_84344F58, &D_843861D0[0x4A], 0, 4, 0xB, 9, 0x13, 0);
    func_8432ECA0(0, 3, 8, func_84352464, &D_843861D0[0x44], 0, 4, 0xB, 9, 0x18, 0xB);
    func_8432ECA0(0, 7, 3, func_84339ECC, &D_843861D0[0x19], 0, 6, 0x10, D_843902E2, 0x26, 0);
    func_8432ED0C(0x32, 0x20, 0xA);
}

void func_8434523C(Gfx* arg0, s32 arg1, u16 arg2) {
    unk_D_8140E720* temp_v0 = func_8432CB60(D_8006F09C);

    gDPPipeSync(arg0++);
    gDPSetPrimColor(arg0++, 0, 0x80, 255, 255, 255, temp_v0->prim_a);

    arg0 = func_84341B84(arg0, arg1, 0x40, 6, -4, 0xF, 0, 0, -0xF, 5, 0, 0);

    gSPEndDisplayList(arg0++);
}

void func_843452F0(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = func_80005F5C(sizeof(Gfx) * 30);
        func_8434523C(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_84345338(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2) {
    arg0 = func_84341B84(arg0, arg1, 0x40, 6, -4, 0xF, 0, 0, -5, 5, 0, 0);

    gSPEndDisplayList(arg0++);
}

void func_8434539C(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = func_80005F5C(sizeof(Gfx) * 30);
        func_84345338(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_843453E4(Gfx* arg0, u8* arg1, UNUSED u16 arg2) {
    arg0 = func_843418C0(arg0, arg1, 0x20, 5, -8, -0x1E, 0, 0, -0xB, -0xA, 0, 0);

    gSPEndDisplayList(arg0++);
}

void func_84345448(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = func_80005F5C(sizeof(Gfx) * 30);
        func_843453E4(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_84345490(void) {
}

void func_84345498(unk_D_8140E720* arg0) {
    f32 sp1C = 5.0f;

    switch (func_843081BC(arg0->unk_10)) {
        case 0xF:
            sp1C = -10.0f;
            break;

        case 0x10:
            sp1C = -30.0f;
            break;

        case 0x11:
            sp1C = -35.0f;
            break;

        case 0x12:
            sp1C = -35.0f;
            break;

        case 0x29:
            sp1C = -50.0f;
            break;

        case 0x3B:
            sp1C = 23.0f;
            break;

        case 0x4A:
            sp1C = -25.0f;
            break;

        case 0x5A:
            sp1C = -8.0f;
            break;

        case 0x5F:
            sp1C = -20.0f;
            func_8140901C(arg0, 10.0f);
            break;

        case 0x64:
            sp1C = -10.0f;
            break;

        case 0x89:
            sp1C = -25.0f;
            break;

        case 0x93:
            sp1C = 17.0f;
            break;

        case 0x97:
            sp1C = -10.0f;
            break;
    }
    func_81408E90(arg0, sp1C);
}

void func_84345618(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C058(arg0);
    s16 sp24;

    arg0->unk_14 = func_8432CB68(arg0);

    if (arg0->unk_14 != NULL) {
        func_8432CD70(arg0->unk_14, 0x31, 0x32);
        func_8140B938(arg0, 0.25f);
        func_84345498(arg0);
        switch (sp26) {
            case 0:
                sp24 = 0;
                break;

            case 1:
                sp24 = 0x5555;
                break;

            case 2:
                sp24 = -0x5556;
                break;
        }

        func_8140A594(arg0, sp24);
        func_814081BC(arg0);
    } else {
        func_81408158(arg0);
    }
}

void func_843456DC(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84345618(arg0);
            break;

        case 2:
            if (func_80017514(arg0->unk_14) != 0) {
                func_814081BC(arg0);
            }
            break;

        case 3:
            func_81408158(arg0);
            break;
    }
}

void func_8434575C(void) {
    func_8432EC28(0, func_843456DC, &D_8140E460, 0x1E, 1, 6, D_843902E2, 0, 0);
    func_8432EC28(0, func_843456DC, &D_8140E460, 0x1E, 1, 6, D_843902E2, 1, 0);
    func_8432EC28(0, func_843456DC, &D_8140E460, 0x1E, 1, 6, D_843902E2, 2, 0);
}

void func_84345838(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C058(arg0);
    u16 sp24;

    switch (func_8432C544()) {
        case 0x47:
            sp24 = 0x18;
            break;

        case 0x48:
            sp24 = 0x1F;
            break;

        case 0x8D:
            sp24 = 0x21;
            break;
    }

    func_8140D5A0(arg0, sp24);

    arg0->unk_14 = func_8432CB68(arg0);
    if (arg0->unk_14 != NULL) {
        func_8432CE00(arg0->unk_14, 0x33);
        if (sp26 == 0) {
            func_8432CE3C(arg0->unk_14, 0x34);
        } else {
            func_8432CE78(arg0->unk_14, 0x34);
        }
        func_8140B938(arg0, 1.0f);
        func_814081BC(arg0);
    } else {
        func_81408158(arg0);
    }
}

void func_84345920(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84345838(arg0);
            break;

        case 2:
            if (func_8432CED4(arg0->unk_14) != 0) {
                func_814081BC(arg0);
            }
            break;

        case 3:
            func_81408158(arg0);
            break;
    }
}

void func_843459A0(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84345838(arg0);
            break;

        case 2:
            if (func_80017514(arg0->unk_14) != 0) {
                func_814081BC(arg0);
            }
            break;

        case 3:
            func_81408158(arg0);
            break;
    }
}

void func_84345A20(Gfx* arg0, UNUSED s32 arg1, UNUSED u16 arg2) {
    unk_D_8140E720* temp_v0 = func_8432CB60(D_8006F09C);

    gDPPipeSync(arg0++);

    gDPSetPrimColor(arg0++, 0, 0, temp_v0->prim_r, temp_v0->prim_g, temp_v0->prim_b, temp_v0->prim_a);
    gDPSetEnvColor(arg0++, temp_v0->env_r, temp_v0->env_g, temp_v0->env_b, 0);

    gSPEndDisplayList(arg0++);
}

void func_84345AE0(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = func_80005F5C(sizeof(Gfx) * 30);
        func_84345A20(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_84345B28(void) {
    func_8432EC28(0, func_84345920, &D_8140E460, 0, 1, 2, D_843902E2, 1, 0);
}

void func_84345B84(void) {
    switch (func_8432C544()) {
        case 0x8D:
            func_8432F638(0, 0xC, 0x41, 2, 0xC8, 0x10);
            break;

        case 0x47:
            func_8432F638(0, 0x37, 0x41, 2, 0xC8, 0x10);
            break;

        case 0x48:
            func_8432F638(0, 0x29, 0x41, 2, 0xC8, 0x10);
            break;
    }

    func_8432EC28(0, func_843459A0, &D_8140E460, 0, 1, 2, D_843902E2, 0, 0);
}

void func_84345C78(unk_D_8140E720* arg0) {
    arg0->unk_14 = func_8432CB68(arg0);
    if (arg0->unk_14 != NULL) {
        func_8432CE00(arg0->unk_14, 0x35);
        func_8140B938(arg0, 5.0f);
        func_81408E90(arg0, -100.0f);
        func_8140BC20(arg0, 0);
        func_814081BC(arg0);
    } else {
        func_81408158(arg0);
    }
}

void func_84345CF0(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84345C78(arg0);
            break;

        case 2:
            func_8140BC5C(arg0, 0x80, 0x10);
            break;

        case 3:
            func_8140BDD0(arg0);
            break;

        case 4:
            func_8140BC5C(arg0, 0, 0x20);
            break;
    }
}

void func_84345D74(void) {
    func_8432EC28(0, func_84345CF0, &D_8140E460, 0xA, 1, 0xA, 0, 0, 0);
}

void func_84345DC4(unk_D_8140E720* arg0) {
    arg0->unk_14 = func_8432CB68(arg0);
    if (arg0->unk_14 != NULL) {
        func_8432CE00(arg0->unk_14, 0x35);
        func_8140B938(arg0, 5.0f);
        func_81408E90(arg0, -100.0f);
        func_8140BC20(arg0, 0);
        func_814081BC(arg0);
    } else {
        func_81408158(arg0);
    }
}

void func_84345E3C(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84345DC4(arg0);
            break;

        case 2:
            func_8140BC5C(arg0, 0x80, 0x10);
            break;

        case 3:
            func_8140BDD0(arg0);
            break;

        case 4:
            func_8140BC5C(arg0, 0, 0x20);
            break;
    }
}

void func_84345EC0(void) {
    func_8432EC28(0, func_84345E3C, &D_8140E460, 0x40, 1, 0xA, 0, 0, 0);
    func_8432F7A0(0, 0xFF, 0, 0x10);
    func_8432F7A0(0x2D, 0, 0xFF, 0x20);
}

void func_84345F38(Gfx* arg0, s32 arg1, u16 arg2) {
    UNUSED s32 pad;
    unk_D_8140E720* sp28 = func_8432CB60(D_8006F09C);

    func_81406204(arg0++, 1, 0x28, 0x20, 0x20);
    func_81406288(arg0++, -1, 0x1E, 0x20, 0x20);

    gDPPipeSync(arg0++);

    gDPSetPrimColor(arg0++, 0, 0x80, 255, 255, 255, sp28->prim_a);
    gDPSetEnvColor(arg0++, 255, 55, 100, 255);

    gSPEndDisplayList(arg0++);
}

void func_84346014(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = func_80005F5C(sizeof(Gfx) * 30);
        func_84345F38(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_8434605C(Gfx* arg0, UNUSED s32 arg1, UNUSED u16 arg2) {
    unk_D_8140E720* temp_v0 = func_8432CB60(D_8006F09C);

    gDPPipeSync(arg0++);

    gDPSetPrimColor(arg0++, 0, 0x80, 255, 255, 255, temp_v0->prim_a);
    gDPSetEnvColor(arg0++, 255, 255, 100, 255);

    gSPEndDisplayList(arg0++);
}

void func_843460EC(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = func_80005F5C(sizeof(Gfx) * 30);
        func_8434605C(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_84346134(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C058(arg0);

    arg0->unk_14 = func_8432CB68(arg0);
    if (arg0->unk_14 != NULL) {
        if (sp26 == 0) {
            func_8432CD70(arg0->unk_14, 0x36, 0x37);
            func_8140B938(arg0, 0.75f);
        } else {
            func_8432CD70(arg0->unk_14, 0x61, 0x62);
            func_8140B938(arg0, 1.0f);
        }
        func_814081BC(arg0);
    } else {
        func_81408158(arg0);
    }
}

void func_843461D0(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84346134(arg0);
            break;

        case 2:
            if (func_80017514(arg0->unk_14) != 0) {
                func_814081BC(arg0);
            }
            break;

        case 3:
            func_81408158(arg0);
            break;
    }
}

void func_84346250(unk_D_8140E720* arg0) {
    u16 sp26 = func_8140C058(arg0);

    arg0->unk_14 = func_8432CB68(arg0);
    if (arg0->unk_14 != NULL) {
        func_8432CD70(arg0->unk_14, 0x39, 0x3A);
        func_8140B938(arg0, 0.5f);

        switch (sp26) {
            case 0:
                break;

            case 1:
                func_81408E18(arg0, -10.0f, 0.0f, 20.0f);
                break;

            case 2:
                func_81408E18(arg0, 10.0f, 0.0f, -20.0f);
                break;

            case 3:
                func_81408E18(arg0, 20.0f, 0.0f, -20.0f);
                break;

            case 4:
                func_81408E18(arg0, -20.0f, 0.0f, 20.0f);
                break;

            case 5:
                func_81408E18(arg0, 15.0f, 0.0f, -25.0f);
                break;

            case 6:
                func_81408E18(arg0, 20.0f, 0.0f, 30.0f);
                break;

            case 7:
                func_81408E18(arg0, 15.0f, 0.0f, -10.0f);
                break;

            case 8:
                func_8140B938(arg0, 1.5f);
                break;
        }
        func_8140BAC8(arg0, 0xFF, 0xFF, 0xFF);
        func_814081BC(arg0);
    } else {
        func_81408158(arg0);
    }
}

void func_843463C8(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84346250(arg0);
            break;

        case 2:
            func_8140826C(arg0, 0xA);
            break;

        case 3:
            func_8140BAE4(arg0, 0, 0x10);
            func_8140BB14(arg0, 0, 0x20);
            if (func_80017514(arg0->unk_14) != 0) {
                func_814081BC(arg0);
            }
            break;

        case 4:
            func_81408158(arg0);
            break;
    }
}

void func_84346488(unk_D_8140E720* arg0) {
    f32 sp1C = 0.6f;
    f32 sp18 = 0.0f;

    switch (func_843081BC(arg0->unk_10)) {
        case 0x3:
            sp1C = 1.0f;
            sp18 = 5.0f;
            break;

        case 0x22:
            sp1C = 1.0f;
            sp18 = 5.0f;
            break;

        case 0x4C:
            sp1C = 0.8f;
            sp18 = 5.0f;
            break;

        case 0x5E:
            sp1C = 0.8f;
            sp18 = 5.0f;
            break;

        case 0x80:
            sp1C = 0.8f;
            sp18 = 10.0f;
            break;

        case 0x82:
            sp18 = 20.0f;
            break;

        case 0x88:
            sp1C = 1.2f;
            sp18 = 10.0f;
            break;

        case 0x8E:
            sp1C = 1.2f;
            sp18 = 20.0f;
            break;

        case 0x91:
            sp1C = 1.2f;
            sp18 = 15.0f;
            break;

        case 0x95:
            sp18 = 10.0f;
            break;
    }

    func_8140B938(arg0, sp1C);
    func_81408F38(arg0, sp18);
}

void func_84346634(unk_D_8140E720* arg0) {
    arg0->unk_14 = func_8432CB68(arg0);
    if (arg0->unk_14 != NULL) {
        func_8432CE00(arg0->unk_14, 0x38);
        func_84346488(arg0);
        func_8140BC20(arg0, 0);
        func_814081BC(arg0);
    } else {
        func_81408158(arg0);
    }
}

void func_8434669C(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84346634(arg0);
            break;

        case 2:
            func_8140BC5C(arg0, 0xFF, 4);
            break;
    }
}

void func_843466EC(Gfx* arg0, s32 arg1, u16 arg2) {
    unk_D_8140E720* temp_v0 = func_8432CB60(D_8006F09C);

    gDPPipeSync(arg0++);

    gDPSetPrimColor(arg0++, 0, 0xC8, 255, 255, 255, temp_v0->prim_a);
    gDPSetEnvColor(arg0++, 255, 155, 0, 255);

    arg0 = func_84341B84(arg0, arg1, 0x20, 5, 1, 0, 0, 0, -1, 0, 0, 0);

    gSPEndDisplayList(arg0++);
}

void func_843467B0(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = func_80005F5C(sizeof(Gfx) * 30);
        func_843466EC(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_843467F8(Gfx* arg0, u8* arg1, UNUSED u16 arg2) {
    unk_D_8140E720* temp_v0 = func_8432CB60(D_8006F09C);

    gDPPipeSync(arg0++);

    gDPSetPrimColor(arg0++, 0, 0, 255, 255, 255, temp_v0->prim_r);
    gDPSetEnvColor(arg0++, 255, 155, 0, 255);
    gDPSetCombineLERP(arg0++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED,
                      0, 0, 0, COMBINED);
    gDPSetTextureLUT(arg0++, G_TT_NONE);
    gSPTexture(arg0++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPLoadTextureBlock_4b(arg0++, arg1, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                           G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPEndDisplayList(arg0++);
}

void func_84346960(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = func_80005F5C(sizeof(Gfx) * 30);
        func_843467F8(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_843469A8(Gfx* arg0, u8* arg1, UNUSED u16 arg2) {
    unk_D_8140E720* temp_v0 = func_8432CB60(D_8006F09C);

    gDPPipeSync(arg0++);

    gDPSetPrimColor(arg0++, 0, 0, 255, 255, 255, temp_v0->prim_g);
    gDPSetEnvColor(arg0++, 255, 255, 0, 255);
    gDPSetCombineLERP(arg0++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED,
                      0, 0, 0, COMBINED);
    gDPSetTextureLUT(arg0++, G_TT_NONE);
    gSPTexture(arg0++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPLoadTextureBlock_4b(arg0++, arg1, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                           G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPEndDisplayList(arg0++);
}

void func_84346B10(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = func_80005F5C(sizeof(Gfx) * 30);
        func_843469A8(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_84346B58(void) {
    func_8432EC28(0, func_843461D0, &D_8140E460, 0, 1, 0xA, 0, 0, 0);
    func_8432EC28(0, func_8434669C, &D_8140E460, 0, 1, 0xA, 0, 0, 0);
}

void func_84346BE0(void) {
    func_8432EC28(0, func_843463C8, &D_8140E460, 0, 1, 0xA, 0, 1, 0);
    func_8432EC28(2, func_843463C8, &D_8140E460, 0, 1, 0xA, 0, 2, 0);
    func_8432EC28(5, func_843463C8, &D_8140E460, 0, 1, 0xA, 0, 3, 0);
    func_8432EC28(8, func_843463C8, &D_8140E460, 0, 1, 0xA, 0, 0, 0);
    func_8432EC28(9, func_843463C8, &D_8140E460, 0, 1, 0xA, 0, 5, 0);
    func_8432EC28(0xA, func_843463C8, &D_8140E460, 0, 1, 0xA, 0, 6, 0);
    func_8432EC28(0xD, func_843463C8, &D_8140E460, 0, 1, 0xA, 0, 7, 0);
    func_8432ECA0(0xA, 3, 2, func_84350DAC, &D_843861D0[0x3F], 0, 0x10, 0xA, 0, 0x11, 0);
}

void func_84346DC4(void) {
    func_8432EC28(0, func_843461D0, &D_8140E460, 0, 1, 0xA, 0, 1, 0);
    func_8432EC28(0, func_8434669C, &D_8140E460, 0, 1, 0xA, 0, 0, 0);
}

void func_84346E50(void) {
    func_8432EC28(0, func_843463C8, &D_8140E460, 0, 1, 0xA, 0, 8, 0);
    func_8432ECA0(0xA, 3, 2, func_84350DAC, &D_843861D0[0x3E], 0, 0x10, 0xA, 0, 0x11, 0);
}

void func_84346EEC(void) {
    func_8432EC28(0, func_843416B0, &D_8140E460, 0, 1, 0xA, 0, 0x23, 0);
}

void func_84346F40(void) {
    func_8432EC28(0, func_843416B0, &D_8140E460, 0, 1, 0xA, 0, 0x24, 0);
    func_8432EC28(8, func_843416B0, &D_8140E460, 0, 1, 0xA, 1, 0x24, 0);
    func_8432EC28(0x10, func_843416B0, &D_8140E460, 0, 1, 0xA, 2, 0x24, 0);
    func_8432F344(0x5F, 0, 0xA, 0, 0xFF, 8);
    func_8432ECA0(0x5F, 8, 0xC, func_8435226C, &D_843861D0[0x42], 0, 8, 9, 0, 0x17, 6);
}

void func_84347080(unk_D_8140E720* arg0) {
    arg0->unk_14 = func_8432CB68(arg0);
    if (arg0->unk_14 != NULL) {
        func_8432CE00(arg0->unk_14, 0x60);
        func_8140BECC(arg0, 7);
        func_814082B4(arg0, 0x200);
        func_8140B950(arg0, 3.3f);
        func_8140BC20(arg0, 0);
        func_814081BC(arg0);
    } else {
        func_81408158(arg0);
    }
}

void func_84347108(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84347080(arg0);
            break;

        case 2:
            func_8140BC2C(arg0, 0x9B, 8);
            break;

        case 3:
            func_81408150(arg0);
            break;
    }

    if (func_8140819C(arg0) != 0) {
        func_8432D340(&arg0->unk_50, 200.0f);
    }
}

void func_8434719C(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2) {
    func_8432CB60(D_8006F09C);

    gDPPipeSync(arg0++);
    gDPSetEnvColor(arg0++, 155, 255, 255, 255);

    arg0 = func_84341B84(arg0, arg1, 0x20, 5, 2, 1, 0xE, 0xF, 0, 4, 0xC, 5);

    gSPEndDisplayList(arg0++);
}

void func_84347254(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = func_80005F5C(sizeof(Gfx) * 30);
        func_8434719C(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_8434729C(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2) {
    unk_D_8140E720* temp_v0 = func_8432CB60(D_8006F09C);

    gDPPipeSync(arg0++);
    gDPSetPrimColor(arg0++, 0, 0x80, 255, 255, 255, temp_v0->prim_a);
    gDPSetEnvColor(arg0++, 0, 255, 255, 255);

    arg0 = func_84341B84(arg0, arg1, 0x20, 5, -3, -5, 0xD, 3, 0, -2, 0xF, 2);

    gSPEndDisplayList(arg0++);
}

void func_84347374(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = func_80005F5C(sizeof(Gfx) * 30);
        func_8434729C(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_843473BC(void) {
    func_8432EC28(0, func_843416B0, &D_8140E460, 0, 1, 0xE, 0, 0x25, 0);
    func_8432EC28(0, func_84347108, &D_8140E460, 0, 1, 0x14, 0, 0, 0);
}

void func_84347448(void) {
    func_8432EC28(0, func_843416B0, &D_8140E460, 0, 1, 0xE, 0, 0x25, 0);
}

void func_8434749C(unk_D_8140E720* arg0) {
    f32 var_fs0 = 0.0f;

    switch (func_843081BC(arg0->unk_10)) {
        case 0x5:
            func_81408F38(arg0, 10.0f);
            break;

        case 0xC:
            var_fs0 = 20.0f;
            break;

        case 0xD:
            var_fs0 = -5.0f;
            func_81408F38(arg0, 15.0f);
            break;

        case 0x34:
            var_fs0 = -10.0f;
            break;

        case 0x4A:
            var_fs0 = 10.0f;
            break;

        case 0x4D:
            var_fs0 = 10.0f;
            func_81408ED0(arg0, 10.0f);
            break;

        case 0x5A:
            var_fs0 = -5.0f;
            func_81408ED0(arg0, 5.0f);
            break;

        case 0x66:
            var_fs0 = -5.0f;
            break;

        case 0x6A:
            var_fs0 = 15.0f;
            break;

        case 0x91:
            var_fs0 = 15.0f;
            break;

        case 0x94:
            var_fs0 = -15.0f;
            break;

        case 0x97:
            var_fs0 = 20.0f;
            break;
    }

    if (var_fs0 != 0.0f) {
        func_81408E90(arg0, var_fs0);
    }
}

void func_84347670(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84340E40(arg0, 0);
            break;

        case 2:
            func_8140826C(arg0, arg0->unk_A6);
            break;

        case 3:
            func_81408158(arg0);
            break;
    }
}

void func_843476D8(unk_D_8140E720* arg0) {
    func_8140B938(arg0, 2.0f);
    func_81408F38(arg0, 10.0f);
    func_8140D5A0(arg0, func_8140C058(arg0));
    func_8140BC20(arg0, 0xC8);
    func_814083E8(arg0, 1);
    func_8140A2CC(arg0, func_81400A78(0x10000));
    func_814081BC(arg0);
}

void func_8434775C(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_843476D8(arg0);
            break;

        case 2:
            func_8140B9D0(arg0, 10.0f, 1.0f);
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

void func_843477F8(unk_D_8140E720* arg0) {
    UNUSED s16 pad;
    s16 sp34;
    Vec3s sp2C;
    UNUSED s32 pad2[3];

    func_8140C038(arg0);
    sp34 = func_8140C058(arg0);
    func_8140959C(arg0, 5, 5, 5);
    func_8140B938(arg0, 1.5f);
    func_8140AD8C(arg0, 1.5f);
    sp2C.x = func_81400A78(0x2000) - 0x1000;
    sp2C.y = func_81400A78(0x10000);
    sp2C.z = 0;
    func_8140A4F0(arg0, sp2C);
    func_8140A5CC(arg0, sp2C.x, sp2C.y);
    func_8140A3A0(arg0, 0, 0);
    func_8140D5A0(arg0, sp34);
    func_8140BC20(arg0, 0x80);
    func_8140BCA8(arg0, arg0->unk_AC * 2);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84347904(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_843477F8(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_8140BCA8(arg0, 0xA);
                func_81408328(arg0);
            }
            break;

        case 3:
            func_814084D8(arg0, 0, 7, 1, 2, 0);
            func_8140B98C(arg0, 2.5f, 0.25f);
            func_81409D0C(arg0);
            func_81408E90(arg0, 0.5f);
            if (func_8140BDAC(arg0) != 0) {
                func_8140BC2C(arg0, 0x20, 0x10);
                func_8140BB14(arg0, 0, 0x14);
                func_8140BB90(arg0, 0, 0x14);
            }
            break;

        case 4:
            func_81408150(arg0);
            break;
    }
}

void func_84347A20(unk_D_8140E720* arg0) {
    UNUSED s32 pad[2];
    UNUSED s16 pad2;
    s16 sp24;

    func_8140C038(arg0);
    sp24 = func_8140C058(arg0);
    func_8140C040(arg0);
    func_8140B938(arg0, 1.0f);
    func_8140959C(arg0, 0xF, 0xF, 0x14);
    func_8140AD8C(arg0, (func_81400A78(0x32) * 0.02f) + 1.0f);
    func_8140D5A0(arg0, sp24);
    func_8140BC20(arg0, 0x80);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84347AF0(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84347A20(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
                func_8140BCA8(arg0, 5);
            }
            break;

        case 3:
            func_814084D8(arg0, 0, 7, 1, 2, 0);
            func_81409F60(arg0);
            if (func_8140BDAC(arg0) != 0) {
                func_8140BB14(arg0, 0, 0x14);
                func_8140BB90(arg0, 0, 0x14);
                func_8140BC2C(arg0, 0x20, 4);
            }
            break;

        case 4:
            func_81408150(arg0);
            break;
    }
}

void func_84347BF4(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2) {
    unk_D_8140E720* temp_v0 = func_8432CB60(D_8006F09C);

    gDPPipeSync(arg0++);

    gDPSetPrimColor(arg0++, 0, 0x78, temp_v0->prim_r, temp_v0->prim_g, temp_v0->prim_b, temp_v0->prim_a);
    gDPSetEnvColor(arg0++, temp_v0->env_r, temp_v0->env_g, temp_v0->env_b, temp_v0->unk_B0);
    gDPSetCombineLERP(arg0++, TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, PRIMITIVE,
                      ENVIRONMENT, COMBINED, ENVIRONMENT, COMBINED, 0, PRIMITIVE, ENVIRONMENT);

    arg0 = func_84341B84(arg0, arg1, 0x20, 5, 2, 0xA, 0xD, 0xF, -2, 5, 0xE, 0xF);

    gSPEndDisplayList(arg0++);
}

void func_84347D2C(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = func_80005F5C(sizeof(Gfx) * 30);
        func_84347BF4(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_84347D74(unk_D_8140E720* arg0) {
    func_8140C040(arg0);

    switch (arg0->unk_B2) {
        case 1:
            func_84340E40(arg0, 2);
            func_8140B938(arg0, 0.5f);
            func_8140BFEC(arg0, 0x64);
            func_8140D5A0(arg0, 0x17);
            func_8140BCA8(arg0, 5);
            break;

        case 2:
            func_8140B98C(arg0, 7.0f, 0.25f);
            if (func_8140BDD0(arg0) != 0) {
                func_8140BCA8(arg0, 5);
            }
            break;

        case 3:
            func_8140B98C(arg0, 7.0f, 0.25f);
            func_8140D908(arg0, 0x1A, 0x19);
            if (func_8140BDAC(arg0) != 0) {
                func_8140C000(arg0, 0, 8);
                func_8140BC5C(arg0, 0, 0x10);
            }
            break;

        case 4:
            func_81408150(arg0);
            break;
    }
}

void func_84347E9C(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C040(arg0);

    switch (arg0->unk_B2) {
        case 1:
            func_84340E40(arg0, 2);
            func_8140B938(arg0, 0.5f);
            func_8140BFEC(arg0, 0x64);
            func_8140D5A0(arg0, 0x17);
            func_8140BCA8(arg0, 5);

            switch (sp26) {
                case 0:
                    func_81408C88(arg0, 15.0f);
                    func_81408CA0(arg0, 15.0f);
                    break;

                case 1:
                    func_81408C88(arg0, -15.0f);
                    func_81408CB8(arg0, 15.0f);
                    func_81408CA0(arg0, -10.0f);
                    break;

                case 2:
                    func_81408C88(arg0, -10.0f);
                    func_81408CB8(arg0, -15.0f);
                    break;
            }
            break;

        case 2:
            func_8140B98C(arg0, 5.0f, 0.15f);
            if (func_8140BDD0(arg0) != 0) {
                func_8140BCA8(arg0, 5);
            }
            break;

        case 3:
            func_8140B98C(arg0, 5.0f, 0.15f);
            func_8140D908(arg0, 0x1A, 0x19);
            if (func_8140BDAC(arg0) != 0) {
                func_8140C000(arg0, 0, 8);
                func_8140BC5C(arg0, 0, 0x10);
            }
            break;

        case 4:
            func_81408150(arg0);
            break;
    }
}

void func_84348058(unk_D_8140E720* arg0) {
    func_8140C040(arg0);

    switch (arg0->unk_B2) {
        case 1:
            func_84340E40(arg0, 2);
            func_8140B938(arg0, 0.25f);
            func_8140BFEC(arg0, 0x64);
            func_8140D5A0(arg0, 0x17);
            func_8140BCA8(arg0, 5);
            func_81408ED0(arg0, 30.0f);
            break;

        case 2:
            func_8140B98C(arg0, 5.0f, 0.3f);
            if (func_8140BDD0(arg0) != 0) {
                func_8140BCA8(arg0, 5);
            }
            break;

        case 3:
            func_8140B98C(arg0, 5.0f, 0.3f);
            func_8140D908(arg0, 0x1A, 0x19);
            if (func_8140BDAC(arg0) != 0) {
                func_8140C000(arg0, 0, 8);
                func_8140BC5C(arg0, 0, 0x10);
            }
            break;

        case 4:
            func_81408150(arg0);
            break;
    }
}

void func_84348194(unk_D_8140E720* arg0) {
    UNUSED s32 pad[2];
    s16 sp26 = func_8140C038(arg0);

    func_8140C040(arg0);
    func_8140C058(arg0);
    func_8140BCA8(arg0, sp26 * 2);
    func_8140D5A0(arg0, func_8140C058(arg0));
    func_8140B938(arg0, 1.2f);
    func_8140B95C(arg0, 1.0f);
    func_8140B974(arg0, 0.02f);
    func_8140959C(arg0, 5, 0xF, 0xF);
    func_81408E90(arg0, 10.0f);
    func_8140AD8C(arg0, (func_81400A78(0xA) * 0.5f) + 8.0f);
    func_8140D530(arg0, 0x19);
    func_8140D568(arg0, 0x19);
    func_8140BC20(arg0, 0xC8);
    func_8140BF4C(arg0, 4);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_843482D4(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84348194(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
                func_8140BCA8(arg0, 4);
            }
            break;

        case 3:
            func_8140BA1C(arg0);
            func_814084D8(arg0, 1, 7, 1, 2, 0);
            func_81409EA0(arg0);
            func_8140BB14(arg0, 0, 0x20);
            func_8140BBF0(arg0, 0, 0x20);
            if (func_8140BDAC(arg0) != 0) {
                break;
            }
            break;

        case 4:
            func_81408150(arg0);
            break;
    }
}

void func_843483D4(unk_D_8140E720* arg0) {
    UNUSED s32 pad[2];
    s16 sp26 = func_8140C038(arg0);
    UNUSED s16 pad2;
    s16 sp22;

    func_8140C040(arg0);
    sp22 = func_8140C058(arg0);
    func_8140BCA8(arg0, sp26 * 2);
    func_8140D5A0(arg0, func_8140C058(arg0));
    func_8140B938(arg0, 1.0f);
    func_8140B95C(arg0, 0.5f);
    func_8140B974(arg0, 0.01f);
    func_8140959C(arg0, 0xA, 0, 0xF);
    func_81408ED0(arg0, 10.0f);
    func_81408E90(arg0, 5.0f);
    func_8140AD8C(arg0, (func_81400A78(0xA) * 0.5f) + 8.0f);
    func_8140D5A0(arg0, sp22);
    func_8140BC20(arg0, 0xB4);
    func_8140BF4C(arg0, 4);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_84348514(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_843483D4(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
                func_8140BCA8(arg0, 4);
            }
            break;

        case 3:
            func_8140BC5C(arg0, 0x40, 0x10);
            if (func_8140BDAC(arg0) != 0) {
                func_8140D908(arg0, 0x16, 0x20);
            }
            func_8140ADBC(arg0, 4.0f, 0.5f);
            func_81409EA0(arg0);
            break;

        case 4:
            func_81408150(arg0);
            break;
    }

    if (func_81408368(arg0) != 0) {
        func_8140BA1C(arg0);
        func_814083FC(arg0, 0, 7, 1, 2, 0);
    }
}

void func_84348630(void) {
    func_8432ED0C(0, 0x10, 6);
    func_8432EC28(0, func_84347670, &D_8140E460, 0x19, 1, 0xE, 0, 0x27, 0);
    func_8432EFB4(0, 0, 4, 0x1C, 0x80);
    func_8432EC28(0x16, func_8434775C, &D_843861D0[0x54], 0, 1, 0xC, 0, 0x25, 0);
    func_8432EE5C(0x1A, 3, 0x20, 0x1C, 0x96);
    func_8432EC28(0x1B, func_84347D74, &D_8140E460, 0, 1, 9, 0, 0x21, 0);
    func_8432EC28(0x1E, func_84347E9C, &D_8140E460, 0, 1, 9, 0, 0x21, 0);
    func_8432EC28(0x22, func_84347E9C, &D_8140E460, 0, 1, 9, 0, 0x21, 1);
    func_8432EC28(0x26, func_84347E9C, &D_8140E460, 0, 1, 9, 0, 0x21, 2);
    func_8432EC28(0x28, func_84347904, &D_843861D0[0x48], 0, 6, 0x10, 9, 0x1A, 0);
    func_8432ECA0(0x32, 2, 2, func_84347AF0, &D_843861D0[0x4A], 0, 1, 9, 0, 0x1A, 0);
    func_8432ECA0(0x33, 2, 2, func_84347AF0, &D_843861D0[0x4A], 0, 1, 9, 0, 0x1A, 0);
    func_8432ECA0(0x34, 2, 2, func_84347AF0, &D_843861D0[0x4A], 0, 1, 9, 0, 0x1A, 0);
    func_8432ECA0(0x36, 2, 2, func_84347AF0, &D_843861D0[0x4A], 0, 1, 9, 0, 0x1A, 0);
    func_8432F2C8(0x16, 0xA, 0, 0xFF, 0x40);
    func_8432F2C8(0x24, 0xA, 0xFF, 0xDC, 0xC);
    func_8432F4BC(0x28, 0xA, 0x19, 0x10, 0xDC);
    func_8432F4BC(0x38, 0x19, 0x13, 0x10, 0xDC);
    func_8432F4BC(0x40, 0x13, 0x10, 0x10, 0xDC);
    func_8432F2C8(0x48, 0x10, 0xDC, 0xB4, 6);
}

void func_843489FC(void) {
    func_8432ED0C(0, 0xFF, 6);
    func_8432EC28(0, func_84348058, &D_8140E460, 0, 1, 0xB, 0, 0x21, 0);
    func_8432EC28(4, func_84348058, &D_8140E460, 0, 1, 0xB, 0, 0x21, 0);
    func_8432ECA0(0xA, 8, 4, func_843416B0, &D_8140E460, 0, 1, 0xC, 0, 0x2B, 0);
    func_8432ECA0(0xC, 8, 5, func_84334F84, &D_843861D0[0x46], 0, 5, 0x10, 9, 0x48, 0);
    func_8432ECA0(0xC, 4, 0xA, func_843482D4, &D_843861D0[0x4A], 0, 4, 0xB, 9, 0, 0);
    func_8432ECA0(0xC, 4, 0xA, func_84348514, &D_843861D0[0x4F], 0, 4, 0xE, 9, 0x1A, 0);
    func_8432F2C8(3, 0xA, 0, 0xFF, 0x40);
    func_8432F2C8(0xA, 0xA, 0xFF, 0xE6, 5);
    func_8432F4BC(0x10, 0xA, 0x19, 0x10, 0xDC);
    func_8432F4BC(0x18, 0x19, 0xB, 0x10, 0xD2);
    func_8432F4BC(0x28, 0xB, 0x10, 0x10, 0xC8);
    func_8432F2C8(0x30, 0x10, 0xC8, 0xB4, 6);
}

void func_84348C6C(UNUSED s32 arg0, UNUSED s32 arg1) {
}

void func_84348C78(UNUSED s32 arg0, UNUSED s32 arg1) {
}

void func_84348C84(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C058(arg0);

    arg0->unk_14 = func_8432CC54(arg0);
    if (arg0->unk_14 != NULL) {
        if (sp26 == 0) {
            func_8432CE00(arg0->unk_14, 0x55);
        } else {
            func_8432CE00(arg0->unk_14, 0x63);
        }
        func_8432CE3C(arg0->unk_14, 0x56);
        func_814082B4(arg0, 0x200);
        func_8140BECC(arg0, 7);
        func_8140B950(arg0, 1.0f);
        func_8140D5A0(arg0, 0x24);
        func_8140BC20(arg0, 0);
        func_814081BC(arg0);
    } else {
        func_81408158(arg0);
    }
}

void func_84348D4C(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C058(arg0);
    s32 sp20 = 0;
    f32 var_fv0;

    switch (arg0->unk_B2) {
        case 1:
            func_84348C84(arg0);
            break;

        case 2:
            func_8140826C(arg0, 0xE);
            func_8140BB14(arg0, 0xFF, 7);
            func_8140BB44(arg0, 0xFF, 0x13);
            func_8140BBF0(arg0, 0xFF, 0x13);
            func_8140BC2C(arg0, 0xFF, 0x13);
            break;

        case 3:
            func_8140826C(arg0, 0x10);
            func_8140BB44(arg0, 0, 0x11);
            func_8140BBF0(arg0, 0, 0x11);
            func_8140BC2C(arg0, 0, 0x11);
            break;

        case 4:
            if (func_80017514(arg0->unk_14) != 0) {
                func_81408150(arg0);
            }
            break;
    }

    if (func_8140819C(arg0) != 0) {
        if (func_843081BC(arg0->unk_10) == 0x5F) {
            sp20 = 1;
        } else if (func_843081BC(arg0->unk_10) == 0x82) {
            sp20 = 1;
        }

        if (sp26 == 0) {
            if (sp20 != 0) {
                var_fv0 = 120.0f;
            } else {
                var_fv0 = 170.0f;
            }
            func_8432D340(&arg0->unk_50, var_fv0);
        } else {
            if (sp20 != 0) {
                var_fv0 = 90.0f;
            } else {
                var_fv0 = 140.0f;
            }
            func_8432D340(&arg0->unk_50, var_fv0);
        }
    }
}

void func_84348F24(Gfx* arg0, s32 arg1, u16 arg2) {
    unk_D_8140E720* temp_v0 = func_8432CB60(D_8006F09C);

    gDPPipeSync(arg0++);

    gDPSetPrimColor(arg0++, 0, 0, temp_v0->prim_r, temp_v0->prim_g, temp_v0->prim_b, temp_v0->prim_a);
    gDPSetEnvColor(arg0++, temp_v0->env_r, temp_v0->env_g, temp_v0->env_b, 0);

    arg0 = func_84341B84(arg0, arg1, 0x20, 5, 0, 0, 0, 0, 0, 0, 0, 0);

    gSPEndDisplayList(arg0++);
}

void func_84349010(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = func_80005F5C(sizeof(Gfx) * 30);
        func_84348F24(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_84349058(void) {
    func_8432EC28(0, func_84348D4C, &D_8140E460, 0, 1, 0x14, 0, 0, 0);
}

void func_843490A8(void) {
    func_8432ED0C(0, 0x20, 0);
    func_8432EC28(0, func_84348D4C, &D_8140E460, 0, 1, 0x14, 0, 0, 0);
}

void func_84349108(void) {
    func_8432EC28(0, func_84348D4C, &D_8140E460, 0, 1, 0x14, 0, 1, 0);
}

void func_8434915C(void) {
    func_84356A74();
}

void func_8434917C(void) {
    func_8432F2C8(0, 0xC, 0, 0xFF, 0x40);
    func_84356A74();
    func_8432F2C8(0x30, 0xC, 0xFF, 0, 2);
}

void func_843491D4(Gfx* arg0, u8* arg1, UNUSED u16 arg2) {
    func_8432CB60(D_8006F09C);
    arg0 = func_843418C0(arg0, arg1, 0x20, 5, -4, -4, 0xD, 6, 4, 4, 0xF, 1);

    gSPEndDisplayList(arg0++);
}

void func_84349264(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = func_80005F5C(sizeof(Gfx) * 30);
        func_843491D4(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_843492AC(Gfx* arg0, u8* arg1, UNUSED u16 arg2) {
    func_8432CB60(D_8006F09C);
    arg0 = func_843418C0(arg0, arg1, 0x20, 5, 1, -1, 0xE, 0xE, -1, 1, 2, 2);

    gSPEndDisplayList(arg0++);
}

void func_8434933C(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = func_80005F5C(sizeof(Gfx) * 30);
        func_843492AC(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_84349384(void) {
    func_8432EC28(0, func_843416B0, &D_8140E460, 0, 1, 2, 0, 0x28, 0);
    func_8432ECA0(4, 8, 0xC, func_8435226C, &D_843861D0[0x42], 0, 8, 9, 0, 0x22, 6);
}

f32 func_84349424(unk_D_8140E720* arg0) {
    f32 sp1C = 1.0f;

    switch (func_843081BC(arg0->unk_10)) {
        case 0x3B:
            sp1C = 1.45f;
            break;

        case 0x5F:
            func_8140901C(arg0, 20.0f);
            sp1C = 0.9f;
            break;

        case 0x82:
            sp1C = 0.9f;
            break;
    }
    return sp1C;
}

void func_843494AC(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84340E40(arg0, 0);
            break;

        case 2:
            break;

        case 3:
            func_81408158(arg0);
            break;
    }
}

void func_84349504(void) {
    func_8432EC28(0, func_843494AC, &D_8140E460, 0, 1, 0xA, 0, 0x29, 0);
    func_8432ECA0(5, 2, 0xA, func_84354D58, &D_843861D0[0x4A], 0, 2, 0xA, 0, 0x44, 9);
    func_8432ECA0(0xA, 5, 6, func_84354E44, &D_843861D0[0x30], 0, 3, 0xA, 0, 0x44, 0xB);
}

void func_843495F0(unk_D_8140E720* arg0) {
    if (func_843081BC(arg0->unk_10) == 0x5F) {
        func_8140901C(arg0, 20.0f);
    }
}

void func_84349628(void) {
    func_8432EC28(0, func_8434171C, &D_8140E460, 0, 1, 0xA, 0, 0x16, 0);
}

void func_8434967C(void) {
    func_8432EC28(0, func_8434171C, &D_8140E460, 0, 1, 0xA, 0, 0x1D, 0);
    func_8432ECA0(0, 3, 3, func_843529D8, &D_843861D0[0x34], 0, 1, 0xE, 9, 0, 0xF);
    func_8432ECA0(4, 1, 4, func_84354D58, &D_843861D0[0x4A], 0, 8, 0x1B, 0, 0x44, 0xA);
    func_8432EC28(4, func_84354E44, &D_843861D0[0x30], 0, 0xC, 0x1B, 0, 0x44, 0xB);
}

void func_843497A8(unk_D_8140E720* arg0) {
    f32 sp1C = 0.0f;

    switch (func_843081BC(arg0->unk_10)) {
        case 0x57:
            sp1C = -20.0f;
            func_8140901C(arg0, 10.0f);
            break;

        case 0x5F:
            sp1C = -20.0f;
            func_8140901C(arg0, 15.0f);
            break;
    }
    func_81408E90(arg0, sp1C);
}

void func_84349830(void) {
    func_8432EC28(0, func_843416B0, &D_8140E460, 0, 1, 0xB, 0, 0, 0);
    func_8432F93C(0x28, 1);
    func_8432ECA0(4, 4, 3, func_8435226C, &D_843861D0[0x42], 0, 4, 0xB, 0, 0x17, 0xA);
}

void func_843498D8(void) {
    func_8432EC28(0, func_843416B0, &D_8140E460, 0, 1, 4, 0, 1, 0);
    func_8432EDE8(0x1D, 2, 0x20, 0x14);
}

void func_84349940(unk_D_8140E720* arg0) {
    f32 sp1C = 0.0f;
    f32 sp18 = 0.0f;

    switch (func_843081BC(arg0->unk_10)) {
        case 0x3B:
            sp1C = 30.0f;
            break;

        case 0x4F:
            sp18 = 10.0f;
            break;

        case 0x66:
            sp1C = 15.0f;
            break;
    }

    if (sp18 != 0.0f) {
        func_81408ED0(arg0, sp18);
    }

    if (sp1C != 0.0f) {
        func_81408CA0(arg0, sp1C);
    }
}

void func_84349A14(void) {
    func_8432EC28(0, func_843416B0, &D_8140E460, 0, 1, 0xB, D_843902E2, 2, 0);
}

void func_84349A70(unk_D_8140E720* arg0) {
    func_8140C048(arg0);
    arg0->unk_14 = func_8432CB68(arg0);
    if (arg0->unk_14 != NULL) {
        func_8432CD70(arg0->unk_14, 0x71, 0x72);
        func_8140B938(arg0, 1.0f);
        func_8140BCA8(arg0, 0x1E);
        func_814081BC(arg0);
    } else {
        func_81408158(arg0);
    }
}

void func_84349AE8(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84349A70(arg0);
            break;

        case 2:
            if (func_80017514(arg0->unk_14) != 0) {
                func_81408150(arg0);
            }
            break;
    }
}

void func_84349B50(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C048(arg0);

    arg0->unk_14 = func_8432CB68(arg0);
    if (arg0->unk_14 != NULL) {
        switch (sp26) {
            case 0:
                func_81408BE0(arg0, 8.0f, 0.0f, -10.0f);
                break;

            case 1:
                func_81408BE0(arg0, -10.0f, 0.0f, 12.0f);
                break;

            case 2:
                func_81408BE0(arg0, 0.0f, 0.0f, -2.0f);
                break;

            case 3:
                func_81408BE0(arg0, 15.0f, 0.0f, 3.0f);
                break;
        }

        func_8432CD70(arg0->unk_14, 0x6E, 0x6F);
        func_8140B938(arg0, 1.0f);
        func_8140BCA8(arg0, 0x1E);
        func_814081BC(arg0);
    } else {
        func_81408158(arg0);
    }
}

void func_84349C74(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84349B50(arg0);
            break;

        case 2:
            func_8140BDD0(arg0);
            break;

        case 3:
            func_8140B9D0(arg0, 0.0f, 0.05f);
            func_8140BC5C(arg0, 0, 0x10);
            break;

        case 4:
            func_81408158(arg0);
            break;
    }
}

void func_84349D10(Gfx* arg0, u8* arg1, UNUSED u16 arg2) {
    UNUSED s32 pad[2];
    s16 sp2E = func_8140C058(func_8432CB60(D_8006F09C));
    u8 sp2D;
    u8 sp2C;
    u8 sp2B;
    u8 sp2A;
    u8 sp29;
    u8 sp28;

    gDPLoadTextureBlock(arg0++, arg1, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_81406204(arg0++, 5, 0, 0x20, 0x20);

    switch (sp2E) {
        case 0:
            sp2D = 0x96;
            sp2C = 0x32;
            sp2B = 0x32;
            sp2A = 0;
            sp29 = 0;
            sp28 = 0;
            break;

        case 1:
            sp2D = 0x78;
            sp2C = 0x96;
            sp2B = 0;
            sp2A = 0x64;
            sp29 = 0x78;
            sp28 = 0;
            break;

        case 2:
            sp2D = 0x46;
            sp2C = 0;
            sp2B = 0x78;
            sp2A = 0x64;
            sp29 = 0;
            sp28 = 0x96;
            break;

        case 3:
            sp2D = 0x64;
            sp2C = 0x96;
            sp2B = 0x96;
            sp2A = 0x64;
            sp29 = 0x96;
            sp28 = 0x96;
            break;
    }

    gDPSetPrimColor(arg0++, 0, 0xFF, sp2D, sp2C, sp2B, 255);
    gDPSetEnvColor(arg0++, sp2A, sp29, sp28, 255);

    gSPEndDisplayList(arg0++);
}

void func_84349F80(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = func_80005F5C(sizeof(Gfx) * 30);
        func_84349D10(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_84349FC8(Gfx* arg0, UNUSED arg1_func_8434E21C* arg1, UNUSED u16 arg2) {
    unk_D_86002F58_004_000* sp24 = D_8006F09C;
    s32 tmp = func_8432CB60(D_8006F09C);
    UNUSED u8 sp1F;
    UNUSED u8 sp1E;
    u8 sp1D;
    u8 sp1C;
    u8 sp1B;
    u8 sp1A;
    u8 sp19;
    u8 sp18;

    switch (func_8140C058(tmp)) {
        case 0:
            sp1D = 0xFF;
            sp1C = 0x96;
            sp1B = 0x32;
            sp1A = 0;
            sp19 = 0;
            sp18 = 0;
            break;

        case 1:
            sp1D = 0xFF;
            sp1C = 0xFF;
            sp1B = 0xFF;
            sp1A = 0x96;
            sp19 = 0xB4;
            sp18 = 0;
            break;

        case 2:
            sp1D = 0xFF;
            sp1C = 0xFF;
            sp1B = 0xFF;
            sp1A = 0x96;
            sp19 = 0;
            sp18 = 0xC8;
            break;

        case 3:
            sp1D = 0x64;
            sp1C = 0xFF;
            sp1B = 0xFF;
            sp1A = 0xC8;
            sp19 = 0xFF;
            sp18 = 0xFF;
            break;
    }

    gDPSetCombineLERP(arg0++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED,
                      0, 0, 0, COMBINED);
    gDPSetPrimColor(arg0++, 0, 0xFF, sp1D, sp1C, sp1B, sp24->unk_01D);
    gDPSetEnvColor(arg0++, sp1A, sp19, sp18, 255);

    gSPEndDisplayList(arg0++);
}

void func_8434A18C(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = func_80005F5C(sizeof(Gfx) * 30);
        func_84349FC8(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

s16 func_8434A1D4(void) {
    s16 sp1E;

    switch (func_8432C544()) {
        case 0x7C:
            sp1E = 0;
            break;

        case 0x33:
            sp1E = 1;
            break;

        case 0x5C:
            sp1E = 2;
            break;

        case 0x7A:
            sp1E = 3;
            break;
    }

    return sp1E;
}

s16 func_8434A244(void) {
    s16 sp1E;

    switch (func_8432C544()) {
        case 0x7C:
            sp1E = 0x12;
            break;

        case 0x33:
            sp1E = 0x2B;
            break;

        case 0x5C:
            sp1E = 0x3E;
            break;

        case 0x7A:
            sp1E = 0x39;
            break;
    }

    return sp1E;
}

s16 func_8434A2B4(void) {
    s16 sp1E;

    switch (func_8432C544()) {
        case 0x7C:
            sp1E = 8;
            break;

        case 0x33:
            sp1E = 0x33;
            break;

        case 0x5C:
            sp1E = 0x33;
            break;

        case 0x7A:
            sp1E = 0x33;
            break;
    }

    return sp1E;
}

void func_8434A324(void) {
    func_8432EC28(0, func_84349AE8, &D_8140E460, 0, 1, 0x11, D_843902E2, func_8434A1D4(), 0);
}

void func_8434A384(void) {
    s16 sp4E;
    s16 sp44;
    s16 sp4A;

    sp4E = func_8434A1D4();
    sp44 = func_8434A244();
    sp4A = func_8434A2B4();

    func_8432F2C8(4, sp44, 0, 0xFF, 0x10);
    func_8432EC28(0, func_84349C74, &D_8140E460, 0, 1, 0xA, 0, sp4E, 0);
    func_8432EC28(4, func_84349C74, &D_8140E460, 0, 1, 0xA, 1, sp4E, 0);
    func_8432EC28(8, func_84349C74, &D_8140E460, 0, 1, 0xA, 2, sp4E, 0);
    func_8432EC28(0xC, func_84349C74, &D_8140E460, 0, 1, 0xA, 3, sp4E, 0);
    func_8432F2C8(0x28, sp44, 0xFF, 0, 0x10);
    func_8432ECA0(6, 4, 0xA, func_84354A10, &D_843861D0[0x3D], 0, 1, 9, 0, sp4A, 0);
    func_8432ECA0(7, 8, 5, func_84354A10, &D_843861D0[0x3D], 0, 1, 9, 0, sp4A, 0);
}

f32 func_8434A574(unk_D_8140E720* arg0) {
    f32 sp1C = 0.5f;
    f32 sp18 = 0.0f;

    switch (func_843081BC(arg0->unk_10)) {
        case 0x57:
            sp18 = -15.0f;
            break;

        case 0x5F:
            sp1C = 0.3f;
            break;

        case 0x82:
            sp18 = 10.0f;
            break;

        case 0x83:
            sp1C = 0.4f;
            sp18 = 7.0f;
            break;
    }

    func_8140BC20(arg0, 0);
    func_81408E90(arg0, sp18 + 5.0f);
    return sp1C;
}

void func_8434A654(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2) {
    func_8432CB60(D_8006F09C);
    arg0 = func_84341B84(arg0, arg1, 0x20, 5, 0, 0, 1, 1, 0, -3, 1, 1);

    gSPEndDisplayList(arg0++);
}

void func_8434A6D8(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = func_80005F5C(sizeof(Gfx) * 30);
        func_8434A654(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_8434A720(Gfx* arg0, UNUSED arg1_func_8434E21C* arg1, UNUSED u16 arg2) {
    unk_D_8140E720* temp_v0 = func_8432CB60(D_8006F09C);

    gDPPipeSync(arg0++);

    gDPSetPrimColor(arg0++, 0, 0, 255, 0, 0, temp_v0->prim_a);
    gSPEndDisplayList(arg0++);
}

void func_8434A794(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = func_80005F5C(sizeof(Gfx) * 30);
        func_8434A720(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_8434A7DC(void) {
    func_8432ED0C(0, 0x10, 6);
    func_8432EC28(0, func_8434174C, &D_8140E460, 0x64, 1, 0xB, 0, 3, 6);
}

void func_8434A844(void) {
    func_8432EC28(0, func_843416B0, &D_8140E460, 0, 1, 0xA, 0, 0x26, 0);
}

void func_8434A898(void) {
    UNUSED s16 pad;
    s16 sp34;

    switch (func_8432C544()) {
        case 0x59:
            sp34 = 0x10;
            break;

        case 0x5A:
            sp34 = 0;
            break;
    }

    func_8432ED0C(0, 0x10, sp34);
    func_8432EC28(0, func_843416B0, &D_8140E460, 0, 1, 0xA, 0, 0x26, 0);
}

void func_8434A930(void) {
    func_8432EC28(6, func_8434171C, &D_8140E460, 0, 1, 0xA, 0, 4, 2);
    func_8432EC28(0, func_843416B0, &D_8140E460, 0, 1, 0xA, 0, 5, 0);
    func_84358598();
}

void func_8434A9CC(void) {
    func_8434A930();
}

void func_8434A9EC(void) {
    func_8432F2C8(4, 0xA, 0, 0xFF, 0x40);
    func_8432F884(8);
    func_8432EC28(0xC, func_8434171C, &D_8140E460, 0, 1, 0xE, 0, 6, 0);
    func_843588D8();
}

void func_8434AA6C(void) {
    func_8432F2C8(6, 0xA, 0, 0xFF, 0x40);
    func_8432F884(0xA);
    func_8432EC28(0xC, func_8434171C, &D_8140E460, 0, 1, 0xA, 0, 7, 0);
    func_843588D8();
}

void func_8434AAEC(Gfx* arg0, u8 arg1, UNUSED u16 arg2) {
    u8* var_a3;
    s32 idx = arg1 * 0xB48;

    if (func_84307F00(func_8432CB60(D_8006F09C)->unk_10) == 0) {
        var_a3 = D_8438E778 + idx;
    } else {
        var_a3 = D_8438E77C + idx;
    }

    gDPLoadTextureTile(arg0++, var_a3, G_IM_FMT_RGBA, G_IM_SIZ_16b, 76, 0, 0, 0, 75, 18, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                       G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPEndDisplayList(arg0++);
}

void func_8434AC44(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = func_80005F5C(sizeof(Gfx) * 30);
        func_8434AAEC(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_8434AC8C(void) {
    func_8432ECA0(0, 8, 6, func_843416B0, &D_8140E460, 0, 1, 9, 0, 8, 0);
}

void func_8434ACEC(void) {
    func_8432ED0C(0, 0x20, 0x10);
    func_8434AC8C();
}

void func_8434AD1C(void) {
    func_8432EC28(0, func_8434171C, &D_8140E460, 0, 1, 0xE, 0, 9, 0);
}

void func_8434AD70(void) {
    s32 var_s0 = 0;

    if (func_8432F9CC(0x5C) != 0) {
        var_s0 = 1;
    } else if (func_8432F9CC(0x5D) != 0) {
        var_s0 = 1;
    } else if (func_8432F9CC(0x5E) != 0) {
        var_s0 = 1;
    } else if (func_8432F9CC(0x5A) != 0) {
        var_s0 = 1;
    } else if (func_8432F9CC(0x6C) != 0) {
        var_s0 = 1;
    } else if (func_8432F9CC(0x2A) != 0) {
        var_s0 = 1;
    }

    if (var_s0 == 0) {
        func_8432EC28(0, func_843416B0, &D_8140E460, 0, 1, 0x10, D_843902E2, 0xA, 0);
    }
}

f32 func_8434AE68(unk_D_8140E720* arg0) {
    f32 sp1C = 0.0f;
    f32 sp18 = 1.0f;

    switch (func_843081BC(arg0->unk_10)) {
        case 0x24:
            sp18 = 1.2f;
            sp1C = 10.0f;
            break;

        case 0x34:
            sp18 = 0.8f;
            break;

        case 0x36:
            sp1C = 15.0f;
            break;

        case 0x3B:
            sp1C = 30.0f;
            sp18 = 0.8f;
            break;

        case 0x5A:
            sp1C = 10.0f;
            break;

        case 0x5F:
            func_8140901C(arg0, 15.0f);
            sp1C = 10.0f;
            sp18 = 0.5f;
            break;

        case 0x66:
            sp1C = 15.0f;
            sp18 = 0.8f;
            break;

        case 0x7D:
            sp1C = 8.0f;
            break;

        case 0x7E:
            sp1C = 15.0f;
            sp18 = 0.8f;
            break;

        case 0x82:
            sp1C = 10.0f;
            sp18 = 0.4f;
            break;

        case 0x83:
            sp1C = 10.0f;
            sp18 = 0.4f;
            break;
    }

    func_81408E90(arg0, sp1C);
    return sp18;
}

void func_8434B000(void) {
    func_8432EC28(0, func_843416B0, &D_8140E460, 0, 1, 0xB, 0, 0xB, 0);
    func_8432ED0C(0x2A, 0x10, 0x17);
}

void func_8434B064(void) {
    func_8432F344(0, 1, 0x18, 0xFF, 0, 8);
    func_8432EC28(0, func_843416B0, &D_8140E460, 0, 1, 9, 0, 0xC, 0);
}

void func_8434B0D8(unk_D_8140E720* arg0) {
    f32 sp1C = 0.0f;

    switch (func_843081BC(arg0->unk_10)) {
        case 0x34:
            sp1C = 12.0f;
            break;

        case 0x36:
            sp1C = 20.0f;
            break;
    }
    func_81408E90(arg0, sp1C);
}

void func_8434B14C(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C048(arg0);

    arg0->unk_14 = func_8432CB68(arg0);

    if (arg0->unk_14 != NULL) {
        if ((sp26 == 0) || (sp26 == 1)) {
            func_8432CE00(arg0->unk_14, 0x8C);
        } else if ((sp26 == 2) || (sp26 == 3)) {
            func_8432CE00(arg0->unk_14, 0x8E);
        } else {
            func_8432CE00(arg0->unk_14, 0x8D);
        }

        func_8140B938(arg0, 1.0f);
        func_8434B0D8(arg0);
        func_8140BC20(arg0, 0);
        func_814081BC(arg0);
    } else {
        func_81408158(arg0);
    }
}

void func_8434B21C(unk_D_8140E720* arg0) {
    u32 temp_v0 = func_8140C048(arg0);

    switch (arg0->unk_B2) {
        case 1:
            func_8434B14C(arg0);
            break;

        case 2:
            if ((temp_v0 == 0) || ((s32)temp_v0 == 1)) {
                func_8140BC5C(arg0, 0x80, 8);
            } else if (temp_v0 == 3) {
                func_8140BC5C(arg0, 0xFF, 0xFF);
            } else {
                func_8140BC5C(arg0, 0xFF, 4);
            }
            break;
    }
}

void func_8434B2B8(Gfx* arg0, u8* arg1, UNUSED u16 arg2) {
    u8* a1;
    unk_D_8140E720* spC8;
    u8 var_t0;
    s16 spC4;
    s16 spC2;
    s16 spC0;
    s16 spBE;
    s16 var_a1;
    s16 var_a2;
    s16 var_a3;
    s16 var_s1;
    UNUSED s16 pad2;
    s16 spB2;
    s16 spB0;
    s16 spAE;
    s16 spAC;
    u16 temp_v0_2;
    s16 var_t2;
    s16 var_t1;

    spC8 = func_8432CB60(D_8006F09C);
    temp_v0_2 = func_8140C048(spC8);
    var_s1 = 0x20;
    var_t1 = 5;
    var_t2 = 5;
    var_a3 = 0;
    var_a1 = 0;
    var_a2 = 0;
    var_t0 = spC8->prim_a;

    switch (temp_v0_2) {
        case 0:
            spC4 = -1;
            spC2 = -1;
            spC0 = 1;
            spBE = -1;
            spB2 = 0xF;
            spB0 = 0;
            spAE = 0xE;
            spAC = 0xF;
            break;

        case 1:
            spC4 = -1;
            spC2 = 1;
            spC0 = 1;
            spBE = 1;
            spB2 = 0xF;
            spB0 = 0;
            spAE = 0xE;
            spAC = 0xF;
            break;

        case 2:
            spC4 = -2;
            spC2 = 2;
            spC0 = 2;
            var_a3 = 0xFF;
            spBE = 3;
            spB2 = 0xC;
            spB0 = 1;
            spAE = 0xC;
            spAC = 0;
            break;

        case 3:
            spC4 = -2;
            spC2 = -2;
            spC0 = 2;
            var_a3 = 0xFF;
            spBE = -3;
            spB2 = 0xC;
            spB0 = 1;
            spAE = 0xC;
            spAC = 0;
            break;

        case 4:
            var_a2 = 0xFF;
            var_a1 = 0x9B;
            spC4 = 1;
            spC2 = 1;
            spC0 = -1;
            spBE = -1;
            spB2 = 0xC;
            spB0 = 1;
            spAE = 0xC;
            spAC = 0;

            break;

        case 5:
            spC0 = -0xA;
            spBE = -0xF;
            spC4 = 0;
            spC2 = 0;
            spB2 = 0xF;
            spB0 = 1;
            spAE = 0xF;
            spAC = 1;
            var_a2 = 0xFF;
            var_a1 = 0xFF;
            var_a3 = 0xFF;
            var_t0 = 0x32;
            break;

        case 6:
            spC4 = 2;
            spC2 = -1;
            spC0 = -2;
            spBE = -2;
            spB2 = 0xD;
            spB0 = 0xE;
            spAE = 0xC;
            spAC = 0xE;
            var_a2 = 0xFF;
            var_a1 = 0xFF;
            var_a3 = 0xFF;
            var_s1 = 0x40;
            var_t1 = 6;
            var_t2 = 6;
            break;

        case 7:
            spC4 = 1;
            spC2 = 1;
            spC0 = -1;
            spBE = -1;
            spB2 = 0xD;
            spB0 = 0xF;
            spAE = 0xF;
            spAC = 0xE;
            var_a2 = 0xFF;
            var_a3 = 0x80;
            break;

        case 8:
            spC4 = 1;
            spC2 = 1;
            spC0 = -1;
            spBE = -1;
            spB2 = 0xD;
            spB0 = 0xF;
            spAE = 0xF;
            spAC = 0xE;
            var_a1 = 0xFF;
            var_a3 = 0xFF;
            break;

        case 9:
            spC4 = 1;
            spC2 = 1;
            spC0 = -1;
            spBE = -1;
            spB2 = 0xD;
            spB0 = 0xF;
            spAE = 0xF;
            spAC = 0xE;
            var_a2 = 0x64;
            var_a1 = 0xFF;
            break;

        case 10:
            spC4 = -1;
            spC2 = -1;
            spC0 = 1;
            spBE = -1;
            spB2 = 0xD;
            spB0 = 0;
            spAE = 0xC;
            spAC = 0xF;
            var_a2 = 0xC8;
            var_a1 = 0x64;
            break;

        case 11:
            spC4 = -1;
            spC2 = -1;
            spC0 = 1;
            spBE = -1;
            spB2 = 0xD;
            spB0 = 0;
            spAE = 0xC;
            spAC = 0xF;
            var_a1 = 0xFF;
            var_a3 = 0xFF;
            break;

        case 12:
            spC4 = -1;
            spC2 = -1;
            spC0 = 1;
            spBE = -1;
            spB2 = 0xD;
            spB0 = 0;
            spAE = 0xC;
            spAC = 0xF;
            var_a2 = 0xC8;
            var_a1 = 0xFF;
            break;

        case 13:
            spC4 = -1;
            spC2 = -1;
            spC0 = 1;
            spBE = -1;
            spB2 = 0xD;
            spB0 = 0;
            spAE = 0xC;
            spAC = 0xF;
            var_a2 = 0xFF;
            break;
    }

    a1 = arg1;

    gDPPipeSync(arg0++);
    gDPSetPrimColor(arg0++, 0, 0x80, var_a2, var_a1, var_a3, var_t0);

    gDPLoadTextureTile_4b(arg0++, arg1, G_IM_FMT_I, var_s1, var_s1, 0, 0, var_s1 - 1, var_s1 - 1, 0,
                          G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, var_t2, var_t1, spB2, spB0);

    func_81406204(arg0++, spC4, spC2, var_s1, var_s1);

    gDPLoadMultiTile_4b(arg0++, a1, 0x0100, 1, G_IM_FMT_I, var_s1, var_s1, 0, 0, var_s1 - 1, var_s1 - 1, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, var_t2, var_t1, spAE, spAC);

    func_81406288(arg0++, spC0, spBE, var_s1, var_s1);

    gSPEndDisplayList(arg0++);
}

void func_8434BA28(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = func_80005F5C(sizeof(Gfx) * 30);
        func_8434B2B8(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_8434BA70(void) {
    func_8432EC28(0, func_8434B21C, &D_8140E460, 0, 1, 0xC, 0, 0, 0);
    func_8432EC28(0, func_843417AC, &D_8140E460, 0, 1, 9, 0, 0xD, 0);
    func_8432EC28(4, func_843417AC, &D_8140E460, 0, 1, 9, 1, 0xD, 0);
    func_8432EC28(8, func_843417AC, &D_8140E460, 0, 1, 9, 2, 0xD, 0);
    func_8432EC28(0xC, func_843417AC, &D_8140E460, 0, 1, 9, 0, 0xD, 0);
    func_8432EC28(0x10, func_843417AC, &D_8140E460, 0, 1, 9, 1, 0xD, 0);
    func_8432EC28(0x14, func_843417AC, &D_8140E460, 0, 1, 9, 2, 0xD, 0);
    func_8432EC28(0x18, func_843417AC, &D_8140E460, 0, 1, 9, 0, 0xD, 0);
    func_8432EC28(0x1C, func_843417AC, &D_8140E460, 0, 1, 9, 1, 0xD, 0);
    func_8432EC28(0x20, func_843417AC, &D_8140E460, 0, 1, 9, 2, 0xD, 0);
    func_8432ED0C(0, 8, 0x35);
}

void func_8434BCD4(void) {
    func_8432EC28(0, func_8434B21C, &D_8140E460, 0, 1, 0xC, 1, 0, 0);
    func_8432EC28(0, func_843416B0, &D_8140E460, 0, 1, 9, 0, 0xD, 0);
    func_8432EC28(4, func_843416B0, &D_8140E460, 0, 1, 9, 1, 0xD, 0);
    func_8432EC28(8, func_843416B0, &D_8140E460, 0, 1, 9, 2, 0xD, 0);
    func_8432EC28(0xC, func_843416B0, &D_8140E460, 0, 1, 9, 0, 0xD, 0);
    func_8432EC28(0x10, func_843416B0, &D_8140E460, 0, 1, 9, 1, 0xD, 0);
    func_8432EC28(0x14, func_843416B0, &D_8140E460, 0, 1, 9, 2, 0xD, 0);
    func_8432EC28(0x18, func_843416B0, &D_8140E460, 0, 1, 9, 0, 0xD, 0);
    func_8432EC28(0x1C, func_843416B0, &D_8140E460, 0, 1, 9, 1, 0xD, 0);
    func_8432EC28(0x20, func_843416B0, &D_8140E460, 0, 1, 9, 2, 0xD, 0);
}

void func_8434BF2C(void) {
    switch (func_8432C544()) {
        case 0x8D:
            func_8432ED0C(0, 0x10, 6);
            func_8432EC28(0, func_84341860, &D_8140E460, 0x80, 1, 0xC, 0xD, 0x1A, 0x20);
            break;

        case 0x47:
            func_8432ED0C(0, 0x10, 0x3A);
            func_8432EC28(0, func_84341860, &D_8140E460, 0x80, 1, 0xC, 0xB, 0x1A, 0x20);
            break;

        case 0x48:
            func_8432ED0C(0, 0x10, 0x21);
            func_8432EC28(0, func_84341860, &D_8140E460, 0x80, 1, 0xC, 0xC, 0x1A, 0x20);
            break;
    }
}

void func_8434C070(void) {
    func_8432EC28(0, func_8434B21C, &D_8140E460, 0, 1, 0xC, 4, 0, 0);
}

void func_8434C0C4(void) {
    func_8432EC28(0, func_8434B21C, &D_8140E460, 0, 1, 0xC, 2, 0, 0);
    func_8432ED0C(0, 8, 0);
    func_8432EB2C(0x40);
    func_8432EDE8(0, 2, 0x10, 0xA);
}

void func_8434C144(void) {
    func_8432EDE8(0, 2, 0x10, 0xA);
    func_8432F2C8(4, 0xA, 0xFF, 0, 8);
    func_8432EC28(0, func_8434B21C, &D_8140E460, 0, 1, 0xC, 3, 0, 0);
    func_8432ECA0(4, 4, 4, func_843529D8, &D_843861D0[0x34], 0, 3, 9, 0, 0x18, 0xD);
}

void func_8434C214(unk_D_8140E720* arg0) {
    arg0->unk_14 = func_8432CB68(arg0);
    if (arg0->unk_14 != NULL) {
        func_8432CD70(arg0->unk_14, 0x42, 0xC2);
        func_8140B938(arg0, 1.0f);
        func_8140D5A0(arg0, 0x23);
        func_8140BC20(arg0, 0);
        func_8140BF4C(arg0, 0);
        func_814081BC(arg0);
    } else {
        func_81408158(arg0);
    }
}

void func_8434C29C(unk_D_8140E720* arg0) {
    s16 sp26;

    switch (arg0->unk_B2) {
        case 1:
            func_8434C214(arg0);
            break;

        case 2:
            func_8140BC2C(arg0, 0xFF, 8);
            func_8140BF60(arg0, 0xC8, 6);
            break;
    }

    func_8432D424(&sp26);
    func_8140A2B8(arg0, sp26);
}

void func_8434C320(unk_D_8140E720* arg0) {
    arg0->unk_14 = func_8432CB68(arg0);
    if (arg0->unk_14 != NULL) {
        func_8432CD70(arg0->unk_14, 0x42, 0xC2);
        func_8432CDD8(arg0->unk_14, 0x28);
        func_8140B938(arg0, 1.0f);
        func_8140D5A0(arg0, 0x23);
        func_8140BF4C(arg0, 0xFF);
        func_814081BC(arg0);
    } else {
        func_81408158(arg0);
    }
}

void func_8434C3A8(unk_D_8140E720* arg0) {
    s16 sp1E;

    if (arg0->unk_B2 == 1) {
        func_8434C320(arg0);
    }
    func_8432D424(&sp1E);
    func_8140A2B8(arg0, sp1E);
}

void func_8434C3F0(Gfx* arg0, u8 arg1, UNUSED u16 arg2) {
    unk_D_8140E720* temp_v0 = func_8432CB60(D_8006F09C);

    switch (arg1) {
        case 0:
            gDPPipeSync(arg0++);
            gDPSetPrimColor(arg0++, 0, 0, temp_v0->prim_r, temp_v0->prim_g, temp_v0->prim_b, temp_v0->prim_a);
            break;

        case 1:
            gDPPipeSync(arg0++);
            gDPSetPrimColor(arg0++, 0, 0, temp_v0->prim_r, temp_v0->prim_g, temp_v0->prim_b, temp_v0->unk_AE);
            break;
    }

    gDPSetEnvColor(arg0++, temp_v0->env_r, temp_v0->env_g, temp_v0->env_b, 0);
    gDPSetCombineLERP(arg0++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED,
                      0, 0, 0, COMBINED);

    gSPEndDisplayList(arg0++);
}

void func_8434C548(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = func_80005F5C(sizeof(Gfx) * 30);
        func_8434C3F0(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_8434C590(void) {
    func_8432ED0C(0, 8, 3);
    func_8432EC28(0, func_8434C29C, &D_8140E460, 0, 1, 0xA, 0, 0, 0);
}

void func_8434C5F0(void) {
    func_8432ED0C(0x10, 0x10, 0xA);
}

void func_8434C618(void) {
    func_8432EC28(0, func_8434C29C, &D_8140E460, 0, 1, 0xA, 0, 0, 0);
    func_8432ED0C(0, 0x20, 3);
    func_8432F2C8(8, 0xA, 0, 0xFF, 0x40);
    func_8432EF40(0xC, 5, 0x10, 0xA);
    func_8432EC28(0xC, func_843529D8, &D_843861D0[0x34], 0, 4, 9, 0, 0x18, 0xD);
    func_8432EB2C(0x21);
    func_8432EDE8(0, 0, 0x10, 0xA);
    func_8432F2C8(0, 0xA, 0xFF, 0, 0x10);
}

void func_8434C720(void) {
    func_8432EC28(0, func_8434C3A8, &D_8140E460, 0, 1, 0xA, 0, 0, 0);
    func_8432EDE8(0, 0, 0x10, 0xA);
    func_8432ED0C(0, 0x20, 3);
    func_8432F2C8(8, 0xA, 0, 0xFF, 0x40);
    func_8432EC28(0xC, func_843529D8, &D_843861D0[0x34], 0, 4, 9, 0, 0x18, 0xD);
    func_8432EB2C(0x21);
    func_8432F2C8(0, 0xA, 0xFF, 0, 0x10);
}

void func_8434C814(Gfx* arg0, u8* arg1, UNUSED u16 arg2) {
    unk_D_8140E720* temp_v0 = func_8432CB60(D_8006F09C);

    gDPPipeSync(arg0++);
    gDPSetPrimColor(arg0++, 0, 0x80, 100, 200, 255, temp_v0->prim_a);

    gDPLoadTextureTile_4b(arg0++, arg1, G_IM_FMT_I, 32, 0, 0, 0, 31, 31, 0, G_TX_NOMIRROR | G_TX_WRAP,
                          G_TX_NOMIRROR | G_TX_WRAP, 5, 5, 14, 15);

    func_81406314(arg0++, -0xB, -8, 0x20, 0x20);

    gDPLoadMultiTile_4b(arg0++, arg1, 0x0100, 1, G_IM_FMT_I, 32, 0, 0, 0, 31, 31, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, 5, 5, 13, 15);

    func_81406388(arg0++, 0x35, -4, 0x20, 0x20);

    gSPEndDisplayList(arg0++);
}

void func_8434CA48(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = func_80005F5C(sizeof(Gfx) * 30);
        func_8434C814(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

f32 func_8434CA90(unk_D_8140E720* arg0) {
    f32 sp1C = 2.5f;

    if (func_843081BC(arg0->unk_10) == 0x5F) {
        sp1C = 1.75f;
    }
    return sp1C;
}

void func_8434CAD8(void) {
    func_8432EC28(0, func_84341860, &D_8140E460, 0xFF, 1, 0xC, 0, 0xE, 8);
    func_8432EB2C(4);
    func_8432ECA0(0, 4, 0x10, func_84354A10, &D_843861D0[0x4A], 0, 2, 0xE, 0, 0x4E, 3);
    func_8432ECA0(0, 4, 0x10, func_84354A10, &D_843861D0[0x19], 0, 2, 0xE, 0, 0x4D, 3);
    func_8432ECA0(0, 4, 0x10, func_84354A10, &D_843861D0[0xE], 0, 2, 0xE, 0, 0x4D, 3);
    func_8432ECA0(0, 8, 5, func_84354A10, &D_843861D0[0xA], 0, 2, 0xE, 0, 0x4D, 4);
}

void func_8434CC68(void) {
    func_8432EC28(0, func_84341860, &D_8140E460, 0xFF, 1, 0xC, 0, 0xF, 0x40);
    func_8432F440(4, 0xA, 0x35, 0xC, 0xFF);
    func_8432EC28(0, func_84333E28, &D_843861D0[4], 0, 1, 0x10, D_843902E2, 0x35, 0);
    func_8432ECA0(0, 5, 3, func_84339D74, &D_843861D0[0x19], 0, 8, 0x10, D_843902E2, 0x4D, 0);
    func_8432ECA0(0xA, 1, 3, func_8433A698, &D_843861D0[0x19], 0, 8, 0x11, D_843902E2, 0x4D, 0);
    func_8432EB2C(0x10);
    func_8432ECA0(0, 4, 5, func_84354A10, &D_843861D0[0xA], 0, 1, 0xE, 0, 0x4D, 4);
}

void func_8434CE14(void) {
    func_8432EB2C(0x41);
    func_8432ECA0(0, 4, 0x20, func_84354A10, &D_843861D0[0x4A], 0, 2, 7, 0, 0x33, 8);
    func_8432ECA0(0, 4, 0x20, func_84354A10, &D_843861D0[0x19], 0, 2, 7, 0, 0xC, 8);
    func_8432ECA0(0, 4, 0x20, func_84354A10, &D_843861D0[0xE], 0, 2, 7, 0, 0xC, 8);
    func_8432ECA0(0, 8, 0xA, func_84354A10, &D_843861D0[0xA], 0, 2, 7, 0, 0xC, 4);
}

void func_8434CF64(void) {
    func_8432ECA0(0, 4, 4, func_84354BE4, &D_843861D0[0x4A], 0, 3, 0xE, 0, 0x33, 0xC);
    func_8432ECA0(0, 4, 4, func_84354BE4, &D_843861D0[0x19], 0, 3, 0xE, 0, 0xC, 0xC);
    func_8432ECA0(0, 4, 4, func_84354BE4, &D_843861D0[0xE], 0, 3, 0xE, 0, 0xC, 0xC);
    func_8432ECA0(0, 4, 4, func_84354BE4, &D_843861D0[0xA], 0, 3, 0xE, 0, 0xC, 4);
    func_8432ECA0(0, 2, 0xC, func_84337C6C, &D_843861D0[0x45], 0, 4, 0x11, 7, 0x33, 0);
}

void func_8434D0F8(void) {
    func_8432EC28(0, func_843416B0, &D_8140E460, 0, 1, 0x13, D_843902E2, 0x10, 0);
    func_8432EDE8(0x22, 0, 0x10, 0xA);
}

void func_8434D168(unk_D_8140E720* arg0) {
    func_8140B938(arg0, 0.2f);
    func_8140D5A0(arg0, 0x33);
    func_8140BC20(arg0, 0xFF);
    func_814081BC(arg0);
}

void func_8434D1B0(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8434D168(arg0);
            break;

        case 2:
            func_814084D8(arg0, 0, 7, 1, 2, 0);
            func_8140BC2C(arg0, 0x20, 0x40);
            break;

        case 3:
            func_81408158(arg0);
            break;
    }
    func_8140B98C(arg0, 0.5f, 0.1f);
}

void func_8434D260(unk_D_8140E720* arg0) {
    func_8140C038(arg0);
    func_8140B938(arg0, 0.3f);
    func_8140A52C(arg0, -0x1000, 0, 0);
    func_8140A414(arg0, func_8432FE44(arg0));
    func_8140A3D8(arg0, 0x80);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_8434D2E0(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8434D260(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                arg0->unk_14 = func_8432CB68(arg0);
                func_8432CD70(arg0->unk_14, 0xA0, 0xA1);
                func_81408328(arg0);
            }
            break;

        case 3:
            if (func_8140826C(arg0, 0xA) != 0) {
                func_8140AD8C(arg0, 8.0f);
                func_8432D844(arg0, func_8434D1B0, &D_843861D0[0x4A], 1);
                func_8432D8E8(arg0, func_84354FA8, &D_843861D0[0x3D], 0xC, 0x33, 0);
            }
            break;

        case 4:
            func_8432D844(arg0, func_8434D1B0, &D_843861D0[0x4A], 1);
            func_8140A76C(arg0, 0x1000, 0x200);
            func_8140A6BC(arg0);
            func_8140826C(arg0, 0xF);
            break;

        case 5:
            func_81408158(arg0);
            break;
    }

    if (func_81408368(arg0) != 0) {
        func_81409D0C(arg0);
    }
}

void func_8434D448(void) {
    func_8432EC28(0, func_8434D2E0, &D_8140E460, 0, 1, 0x11, D_843902E2, 0, 0);
}

void func_8434D4A0(unk_D_8140E720* arg0) {
    func_8140C038(arg0);
    func_8140B938(arg0, 0.4f);
    func_81408CA0(arg0, 15.0f);
    func_81408ED0(arg0, 50.0f);
    func_8140A52C(arg0, 0x800, -0x8000, 0);
    func_8140AD8C(arg0, 8.0f);
    func_814081BC(arg0);
    arg0->unk_14 = func_8432CB68(arg0);
    func_8432CE00(arg0->unk_14, 0xA0);
}

void func_8434D530(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8434D4A0(arg0);
            break;

        case 2:
            func_8432D844(arg0, func_8434D1B0, &D_843861D0[0x4A], 1);
            func_8140A76C(arg0, 0x1000, 0x80);
            func_8140826C(arg0, 7);
            break;

        case 3:
            func_81408158(arg0);
            break;
    }

    if (func_81408368(arg0) != 0) {
        func_81409D0C(arg0);
    }
}

void func_8434D5EC(void) {
    func_8432EC28(0, func_8434D530, &D_8140E460, 0, 1, 0x11, D_843902E2, 0, 0);
    func_8432EC28(5, func_843529D8, &D_843861D0[0x34], 0, 1, 0x11, 9, 0, 6);
    func_8432EC28(7, func_84351984, &D_843861D0[0x3D], 0, 8, 0x11, 9, 0, 0);
}

void func_8434D6C0(unk_D_8140E720* arg0) {
    arg0->unk_14 = func_8432CB68(arg0);
    if (arg0->unk_14 != NULL) {
        func_8432CE00(arg0->unk_14, 0xA2);
        func_8140B938(arg0, 1.0f);
        func_8140BC20(arg0, 0);
        func_814081BC(arg0);
    } else {
        func_81408158(arg0);
    }
}

void func_8434D72C(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8434D6C0(arg0);
            break;

        case 2:
            func_8140BC5C(arg0, 0x80, 8);
            break;
    }
}

void func_8434D77C(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2) {
    UNUSED s32 pad;
    unk_D_8140E720* sp48 = func_8432CB60(D_8006F09C);
    UNUSED s16 pad2;
    s16 sp44;
    s16 sp42;

    switch (func_8140C058(sp48)) {
        case 0:
            sp44 = -5;
            sp42 = 3;
            break;

        case 1:
            sp44 = 5;
            sp42 = -3;
            break;
    }

    gDPPipeSync(arg0++);
    gDPSetPrimColor(arg0++, 0, 0x80, 55, 255, 255, sp48->prim_a);

    arg0 = func_84341B84(arg0++, arg1, 0x20, 5, 1, sp44, 0xD, 0xC, -1, sp42, 0xB, 0xD);
    gSPEndDisplayList(arg0++);
}

void func_8434D890(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = func_80005F5C(sizeof(Gfx) * 30);
        func_8434D77C(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_8434D8D8(void) {
    func_8432ED0C(0, 0x10, 0);
    func_8432EC28(0, func_8434D72C, &D_8140E460, 0, 1, 9, 0, 0, 0);
}

void func_8434D938(void) {
    func_8432F344(0, 2, 0xA, 0xFF, 0, 0x10);
    func_8432EC28(0, func_8434D72C, &D_8140E460, 0, 1, 9, 0, 1, 0);
    func_8432ECA0(4, 4, 4, func_843529D8, &D_843861D0[0x34], 0, 3, 9, 0, 0x18, 0xD);
}

void func_8434D9F8(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84340E40(arg0, 2);
            break;

        case 2:
            func_8140BC5C(arg0, arg0->unk_A6, func_8140C040(arg0));
            break;

        case 3:
            func_8140826C(arg0, 0x20);
            break;

        case 4:
            func_8140BC5C(arg0, 0, 0xA);
            break;

        case 5:
            func_81408158(arg0);
            break;
    }
}

void func_8434DA94(void) {
    func_8432ED0C(0, 5, 0);
    func_8432EC28(0, func_84341860, &D_8140E460, 0xFF, 1, 0xC, 8, 0x18, 5);
    func_8432F344(0x32, 1, 0xA, 0, 0xFF, 0x20);
    func_8432ED74(0x32, 1, 0x20, 0xA, 0xFF);
}

void func_8434DB40(void) {
    func_8432ED0C(0, 6, 0);
    func_8432EC28(0, func_84341860, &D_8140E460, 0xFF, 1, 0xC, 7, 0x17, 6);
    func_8432ED74(0x32, 1, 0x20, 0xA, 0xFF);
    func_8432F344(0x32, 1, 0xA, 0, 0xFF, 0x20);
}

void func_8434DBEC(void) {
    func_8432ED0C(0, 0x40, 0);
    func_8432EC28(0, func_8434D9F8, &D_8140E460, 0xFF, 1, 0xC, 8, 0x18, 0x20);
    func_8432ECA0(4, 4, 4, func_843529D8, &D_843861D0[0x34], 0, 3, 9, 0, 0x18, 0xD);
    func_8432F2C8(8, 0xA, 0, 0xFF, 0x40);
    func_8432EDE8(0, 0, 0x10, 0xA);
    func_8432EB2C(0x21);
    func_8432F2C8(0, 0xA, 0xFF, 0, 4);
    func_8432ED0C(8, 4, 0xA);
}

void func_8434DD08(void) {
    func_8432ED0C(0, 0x40, 0);
    func_8432EC28(0, func_8434D9F8, &D_8140E460, 0xFF, 1, 0xC, 7, 0x17, 0x20);
    func_8432ECA0(4, 4, 4, func_843529D8, &D_843861D0[0x34], 0, 3, 9, 0, 0x18, 0xD);
    func_8432F2C8(8, 0xA, 0, 0xFF, 0x40);
    func_8432EDE8(0, 0, 0x10, 0xA);
    func_8432EB2C(0x21);
    func_8432F2C8(0, 0xA, 0xFF, 0, 4);
    func_8432ED0C(8, 4, 0xA);
}

f32 func_8434DE24(unk_D_8140E720* arg0) {
    f32 sp1C = 1.0f;

    if (func_843081BC(arg0->unk_10) == 0x34) {
        sp1C = 1.75f;
    }
    return sp1C;
}

void func_8434DE6C(void) {
    s16 sp46 = 7;

    if (func_8432F9CC(0x14) != 0) {
        sp46 = D_843902E2;
    }
    func_8432ED0C(0, 0x10, 6);
    func_8432EC28(0, func_84341860, &D_8140E460, 0x80, 1, 0xC, 0xA, 0x1A, 4);
    func_8432F344(0, 1, 0xC, 0, 0xC8, 3);
    func_8432ECA0(0x3C, 4, 0xE, func_84354A10, &D_843861D0[0x3D], 0, 1, 0x11, sp46, 0x33, 7);
    func_8432ECA0(0x3D, 8, 7, func_84354A10, &D_843861D0[0x3D], 0, 1, 0x11, sp46, 0x33, 7);
}

void func_8434DFC0(void) {
    func_8432ED0C(0, 0x20, 6);
    func_8432EC28(0, func_84341860, &D_8140E460, 0x80, 1, 0xC, 0xA, 0x1A, 0x20);
}

void func_8434E02C(void) {
    func_84358C18(0xE);
    func_8432ED0C(0, 2, 0x10);
    func_8432F2C8(0, 0xC, 0, 0xC8, 4);
    func_8432F440(0x32, 0xC, 0x19, 2, 0xC8);
    func_8432EC28(0x40, func_84334154, &D_843861D0[0x4F], 0, 0x20, 7, 0, 0, 0);
}

void func_8434E0CC(void) {
    func_8432ED0C(0, 0x20, 6);
    func_8432F2C8(0, 0x14, 0, 0x80, 0x10);
    func_8432F7A0(0, 0xFF, 0, 0x10);
    func_8432EC28(0, func_8434174C, &D_8140E460, 0xFF, 1, 9, D_843902E2, 0x12, 0x20);
    func_8432ECA0(0, 1, 0xC, func_84354A10, &D_843861D0[0x3D], 0, 1, 9, 0, 0x16, 5);
}

void func_8434E1B8(void) {
    func_8432EC28(0, func_843416B0, &D_8140E460, 0, 1, 9, 0, 0x13, 0);
    func_8432EB20(4);
    func_8433C940();
}

void func_8434E21C(Gfx* arg0, arg1_func_8434E21C* arg1, UNUSED u16 arg2) {
    unk_D_8140E720* temp_v0;
    UNUSED s32 pad;
    s16 var_t2;
    s16 tmp;
    s16 sp82;
    s16 sp80;
    s16 sp7E;
    s16 sp7C;
    s16 sp7A;
    s16 sp78;
    s16 sp76;
    s16 sp74;
    s16 var_s1;
    s16 var_t1;
    UNUSED s16 pad2;
    s16 var_t5;

    temp_v0 = func_8432CB60(D_8006F09C);
    var_t1 = 0x96;
    var_t2 = 0xFF;
    var_s1 = 0x20;
    var_t5 = 5;
    tmp = arg1->unk_0A;

    switch (tmp) {
        case 1:
            sp82 = -5;
            sp80 = -0xF;
            sp7E = -0xA;
            sp7C = -0xA;
            sp7A = 0;
            sp78 = 1;
            sp76 = 0;
            sp74 = 1;
            break;

        case 2:
            sp82 = 5;
            sp80 = -0xF;
            sp7E = 0;
            sp7C = -0xA;
            sp7A = 0;
            sp78 = 0xF;
            sp76 = 0;
            sp74 = 0xF;
            break;

        case 3:
            sp82 = 5;
            sp80 = -0xF;
            sp7C = -0xA;
            sp7E = 0;
            sp7A = 1;
            sp78 = 1;
            sp76 = 1;
            sp74 = 1;
            break;

        case 4:
            sp82 = 5;
            sp80 = -0xF;
            sp7E = 0;
            sp7C = -0xA;
            sp7A = 0;
            sp78 = 0;
            sp76 = 0;
            sp74 = 0;
            break;

        case 5:
            sp82 = -5;
            sp80 = -0xA;
            sp7E = 0;
            sp7C = 0;
            sp7A = 1;
            sp78 = 0;
            sp76 = 0;
            sp74 = 0;
            var_t1 = 0x78;
            var_t2 = 0xC8;
            var_s1 = 0x40;
            var_t5 = 6;
            break;

        case 6:
            sp82 = 0;
            sp80 = -0xA;
            sp7E = 0;
            sp7C = 0;
            sp7A = 1;
            sp78 = 1;
            sp76 = 0;
            sp74 = 0;
            var_t1 = 0x78;
            var_t2 = 0xC8;
            var_s1 = 0x40;
            var_t5 = 6;
            break;
    }

    gDPPipeSync(arg0++);
    gDPSetPrimColor(arg0++, 0, var_t1, 255, var_t2, 0, temp_v0->prim_a);

    gDPLoadTextureTile_4b(arg0++, arg1->unk_00, G_IM_FMT_I, 32, 32, 0, 0, 31, 31, 0, G_TX_NOMIRROR | G_TX_WRAP,
                          G_TX_NOMIRROR | G_TX_WRAP, 5, 5, sp7A, sp78);

    func_81406204(arg0++, sp82, sp80, 0x20, 0x20);

    gDPLoadMultiTile_4b(arg0++, arg1->unk_04, 0x0100, 1, G_IM_FMT_I, var_s1, 0, 0, 0, var_s1 - 1, var_s1 - 1, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, var_t5, var_t5, sp76, sp74);

    func_81406288(arg0++, sp7E, sp7C, var_s1, var_s1);

    gSPEndDisplayList(arg0++);
}

void func_8434E6AC(s32 arg0, arg1_func_84344CE8* arg1) {
    if (arg0 == 2) {
        arg1->unk_18 = func_80005F5C(sizeof(Gfx) * 30);
        func_8434E21C(arg1->unk_18, arg1->unk_14, D_8006F084);
    }
}

void func_8434E6F4(void) {
    func_8432EC28(0, func_843416B0, &D_8140E460, 0, 1, 0xE, 5, 0x14, 0);
}

void func_8434E74C(void) {
    func_8432EC28(0, func_84341860, &D_8140E460, 0xBE, 1, 9, 6, 0x15, 2);
    func_8432F2C8(8, 0xA, 0, 0xFF, 4);
    func_84358E24();
}

void func_8434E7CC(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84340E40(arg0, 0);
            func_8140BCA8(arg0, 2);
            break;

        case 2:
            func_8140BB14(arg0, 0, 0x20);

            if (func_8140BDAC != NULL) {
                func_8140BC2C(arg0, 0, 0x20);
            }

            if (func_80017514(arg0->unk_14) != 0) {
                func_81408150(arg0);
            }
            break;
    }
}

void func_8434E870(void) {
    func_8432F2C8(4, 0xA, 0xFF, 0, 0x20);
    func_8432EC28(4, func_8434E7CC, &D_8140E460, 0, 1, 9, 0, 0x19, 0);
}

void func_8434E8E0(void) {
    func_8432EC28(0, func_843416B0, &D_8140E460, 0, 1, 0x11, D_843902E2, 0x1B, 1);
}

void func_8434E940(void) {
    func_8432EC28(0, func_843416B0, &D_8140E460, 0, 1, 0x11, D_843902E2, 0x1C, 1);
}

void func_8434E9A0(void) {
    func_8432ED0C(0, 0x20, 0);
    func_8432EC28(0, func_843416B0, &D_8140E460, 0, 1, 0x11, D_843902E2, 0x1B, 1);
}

void func_8434EA10(void) {
    func_8432F2C8(0, 0xC, 0, 0xFF, 0x40);
    func_8432EC28(0, func_843416B0, &D_8140E460, 0, 1, 0x11, D_843902E2, 0x1C, 1);
    func_8432F2C8(0x30, 0xC, 0xFF, 0, 2);
}

void func_8434EAA8(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C040(arg0);

    switch (arg0->unk_B2) {
        case 1:
            func_84340E40(arg0, 0);
            if (sp26 == 1) {
                func_8140B938(arg0, 1.5f);
                func_81408F38(arg0, 40.0f);
            }
            break;

        case 2:
            func_8140D908(arg0, 0x33, 0x40);
            func_8140BC5C(arg0, 0xFF, 0x40);
            break;

        case 3:
            func_8140D908(arg0, 0, 0x40);
            func_8140BC5C(arg0, 0, 0x40);
            break;

        case 4:
            func_81408150(arg0);
            break;
    }
}

void func_8434EBA0(void) {
    func_8432ECA0(0, 2, 3, func_8434EAA8, &D_8140E460, 0, 1, 0x11, D_843902E2, 0x20, 0);
}

void func_8434EC08(void) {
    func_8432EC28(0, func_8434EAA8, &D_8140E460, 0, 1, 0x11, D_843902E2, 0x20, 1);
}

void func_8434EC68(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_84340E40(arg0, 0);
            break;

        case 2:
            func_8140D908(arg0, 0x33, 0x24);
            func_8140BC2C(arg0, 0xFF, 0x1D);
            if (func_80017514(arg0->unk_14) != 0) {
                func_81408150(arg0);
            }
            break;
    }
}

void func_8434ECF4(void) {
    func_8432EC28(0, func_8434EC68, &D_8140E460, 0, 1, 0xA, 0, 0x1F, 0);
}

void func_8434ED48(void) {
    func_8432ED0C(0, 8, 0x22);
}

void func_8434ED70(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C038(arg0);
    s16 sp24 = func_8140C058(arg0);

    func_8140C040(arg0);

    switch (sp26) {
        case 0:
            func_81408BE0(arg0, 0.0f, 0.0f, 0.0f);
            break;

        case 1:
            func_81408BE0(arg0, 0.0f, 10.0f, 10.0f);
            break;

        case 2:
            func_81408BE0(arg0, 0.0f, 15.0f, -15.0f);
            break;
    }

    func_8140B938(arg0, 0.1f);
    func_8140B95C(arg0, 2.0f);
    func_8140B974(arg0, 0.0625f);
    func_8140D5A0(arg0, sp24);
    func_8140BC20(arg0, 0xFF);
    func_8140BCA8(arg0, sp26 * 8);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_8434EEA4(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8434ED70(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
                func_8140BCA8(arg0, 0xA);
            }
            break;

        case 3:
            func_8140BA1C(arg0);
            if (func_8140BDAC(arg0) != 0) {
                func_8140BC5C(arg0, 0, 0x10);
            }
            break;

        case 4:
            func_81408150(arg0);
            break;
    }
}

void func_8434EF68(void) {
    func_8432EC28(0, func_8434EEA4, &D_843861D0[0x39], 8, 3, 2, 0, 0x45, 0);
}

void func_8434EFBC(void) {
    func_8432EC28(0, func_8434EEA4, &D_843861D0[0x39], 8, 3, 2, 0, 0x47, 0);
}

void func_8434F010(void) {
    func_8432EC28(0, func_843431B0, &D_8140E460, 0x1E, 3, 6, 0, 0, 0);
}

void func_8434F060(void) {
    func_8432EC28(0, func_843529D8, &D_843861D0[0x34], 0, 1, 0x11, 9, 0, 6);
}

void func_8434F0B8(void) {
    func_8432EC28(0x10, func_843529D8, &D_843861D0[0x34], 0, 1, 0x11, 9, 0, 6);
}

void func_8434F110(unk_D_8140E720* arg0) {
    s16 sp26 = func_8140C038(arg0);
    s16 sp24 = func_8140C058(arg0);

    func_8140C040(arg0);

    switch (sp26) {
        case 0:
            func_81408BE0(arg0, 0.0f, 0.0f, 0.0f);
            break;

        case 1:
            func_81408BE0(arg0, 0.0f, 10.0f, 10.0f);
            break;

        case 2:
            func_81408BE0(arg0, 0.0f, 15.0f, -15.0f);
            break;
    }

    func_8140B938(arg0, 0.01f);
    func_8140B95C(arg0, 0.5f);
    func_8140B974(arg0, 0.05f);
    func_8140D5A0(arg0, sp24);
    func_8140BC20(arg0, 0xFF);
    func_8140BCA8(arg0, sp26 * 8);
    func_81408348(arg0);
    func_814081BC(arg0);
}

void func_8434F248(unk_D_8140E720* arg0) {
    switch (arg0->unk_B2) {
        case 1:
            func_8434F110(arg0);
            break;

        case 2:
            if (func_8140BDD0(arg0) != 0) {
                func_81408328(arg0);
                func_8140BCA8(arg0, 0xA);
            }
            break;

        case 3:
            func_8140BA1C(arg0);
            func_814099E0(arg0, 1.0f);
            if (func_8140BDD0(arg0) != 0) {
                func_8140BCA8(arg0, 0x10);
            }
            break;

        case 4:
            func_8140ADBC(arg0, 4.0f, 0.5f);
            func_814099E0(arg0, arg0->unk_74);
            func_8140BC2C(arg0, 0, 0x10);
            if (func_8140BDD0(arg0) != 0) {
                break;
            }
            break;

        case 5:
            func_81408150(arg0);
            break;
    }
}

void func_8434F350(void) {
    func_8432EC28(0, func_8434F248, &D_843861D0[0x39], 8, 3, 2, 0, 0x46, 0);
    func_8432EC28(0x10, func_8434F248, &D_843861D0[0x39], 8, 3, 2, 0, 0x46, 0);
}
