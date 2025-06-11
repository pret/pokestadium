#include "fragment62.h"
#include "src/30640.h"
#include "src/6A40.h"
#include "include/math.h"
#include "src/math_util.h"

u8* D_843920C0[256];
s16 D_843924C0[0x10];
arg1_func_80019420* D_843924E0[40];
static s16 D_84392580;
static s16 D_84392582;
static Mtx D_84392588;
static s16 D_843925C8;
static s16 D_843925CA;
static s16 D_843925CC;
static s16 D_843925CE;
static s16 D_843925D0;
static s16 D_843925D2;
static s16 D_843925D4;
static s16 D_843925D6;
static s16 D_843925D8;
static s16 D_843925DA;

static const char D_8438D3D0[] = "calc_vector_ATtoDM() normal error!!!\n";
static const char D_8438D3F8[] = "calc_vector_ATtoDM2() normal error!!!\n";

void func_843592E0(void) {
}

void func_843592E8(void) {
}

void func_843592F0(void) {
}

void func_843592F8(void) {
}

void func_84359300(void) {
}

void func_84359308(void) {
}

void func_84359310(void) {
}

void func_84359318(void) {
}

void func_84359320(void) {
}

void func_84359328(void) {
}

void func_84359330(UNUSED s32 arg0) {
}

void func_84359338(UNUSED s32 arg0) {
}

void func_84359340(void) {
}

void func_84359348(void) {
    func_84359000(D_8439037A, D_8439037C, D_8439037E, 0xFF);
}

void func_84359380(void) {
    func_8436E920();
}

void func_843593A0(void) {
}

void func_843593A8(void) {
}

s32 func_843593B0(void) {
    return -1;
}

s32 func_843593B8(void) {
    return -1;
}

void func_843593C0(void) {
}

void func_843593C8(void) {
}

void func_843593D0(Vec3f* arg0) {
    func_8432FB90(arg0);
}

void func_843593F0(Vec3f* arg0) {
    func_8432FBBC(arg0);
}

void func_84359410(Vec3f* arg0) {
    func_8432FB90(arg0);
}

void func_84359430(Vec3f* arg0) {
    func_8432FB64(arg0);
}

f32 func_84359450(void) {
    return func_8432FD1C();
}

f32 func_84359470(void) {
    return func_8432FCD4();
}

void func_84359490(f32* arg0, f32* arg1, f32* arg2, f32* arg3, f32* arg4, f32* arg5) {
    Vec3f sp4C;
    Vec3f sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    UNUSED s32 pad[3];
    f32 sp24;
    f32 sp20;
    f32 sp1C;

    func_843593F0(&sp4C);
    func_84359410(&sp40);

    sp3C = sp4C.x;
    sp38 = sp4C.y;
    sp34 = sp4C.z;

    sp24 = sp40.x - sp4C.x;
    sp20 = sp40.y - sp4C.y;
    sp1C = sp40.z - sp4C.z;

    if (sp24 == 0.0f || sp20 == 0.0f || sp1C == 0.0f) {}

    func_80031B04(&sp24, &sp20, &sp1C);

    *arg0 = sp3C;
    *arg1 = sp38;
    *arg2 = sp34;
    *arg3 = sp24;
    *arg4 = sp20;
    *arg5 = sp1C;
}

void func_84359564(f32* arg0, f32* arg1, f32* arg2, f32* arg3, f32* arg4, f32* arg5) {
    Vec3f sp4C;
    Vec3f sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    UNUSED s32 pad[2];
    f32 tmp;
    f32 sp24;
    f32 sp20;
    f32 sp1C;

    func_843593F0(&sp4C);
    func_84359410(&sp40);

    sp3C = sp4C.x;
    sp38 = sp4C.y;
    sp34 = sp4C.z;

    tmp = sp40.y;
    if (tmp < 0.0f) {
        tmp = 0.0f;
    }

    sp24 = sp40.x - sp4C.x;
    sp20 = tmp - sp4C.y;
    sp1C = sp40.z - sp4C.z;

    if (sp24 == 0.0f || sp20 == 0.0f || sp1C == 0.0f) {}

    func_80031B04(&sp24, &sp20, &sp1C);

    *arg0 = sp3C;
    *arg1 = sp38;
    *arg2 = sp34;
    *arg3 = sp24;
    *arg4 = sp20;
    *arg5 = sp1C;
}

void func_84359650(void) {
    guRotateRPY(&D_84392588, 0.0f, 0.0f, 0.0f);
}

void func_84359684(void) {
    Vec3f sp24;
    f32 sp20;

    func_84359650();
    func_84359430(&sp24);
    sp20 = func_84359470();
    func_8435CA70();
    func_8435CAE8(sp24.x, sp24.y, sp24.z, 40.0f, sp20, 0);
}

s32 func_843596DC(void) {
    return func_8435D8C0();
}

void func_843596FC(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = func_8435DB14(gDisplayListHead);
}

void func_84359750(void) {
    Vec3f sp24;
    f32 sp20;

    func_84359650();
    func_84359430(&sp24);
    sp20 = func_84359450();
    func_8435CA70();
    func_8435CAE8(sp24.x, sp24.y, sp24.z, 40.0f, sp20, 1);
}

s32 func_843597AC(void) {
    return func_8435D8C0();
}

void func_843597CC(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = func_8435DB14(gDisplayListHead);
}

void func_84359820(void) {
    Vec3f sp24;
    f32 sp20;

    func_84359650();
    func_84359430(&sp24);
    sp20 = func_84359450();
    func_8435CA70();
    func_8435CAE8(sp24.x, sp24.y, sp24.z, 40.0f, sp20, 0);
    func_8435CAE8(sp24.x, sp24.y, sp24.z, 38.0f, sp20, 1);
}

s32 func_8435989C(void) {
    return func_8435D8C0();
}

void func_843598BC(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = func_8435DB14(gDisplayListHead);
}

void func_84359910(void) {
    Vec3f sp24;
    f32 sp20;

    func_84359650();
    func_84359430(&sp24);
    sp20 = func_84359470();
    func_8435CA70();
    func_8435CAE8(sp24.x, sp24.y, sp24.z, 40.0f, sp20, 0);
    func_8435CAE8(sp24.x, sp24.y, sp24.z, 38.0f, sp20, 1);
}

s32 func_8435998C(void) {
    return func_8435D8C0();
}

void func_843599AC(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = func_8435DB14(gDisplayListHead);
}

void func_84359A00(void) {
    Vec3f sp1C;

    func_843593F0(&sp1C);
    func_84359650();

    if (sp1C.x < 0.0) {
        func_8435EB9C(1, 0, 0x4650);
    } else {
        func_8435EB9C(-1, 0, 0x4650);
    }
}

s32 func_84359A6C(void) {
    return func_8435EDF8();
}

void func_84359A8C(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = func_8435EE78(gDisplayListHead);
}

void func_84359AE0(void) {
}

s32 func_84359AE8(void) {
    return -1;
}

void func_84359AF0(void) {
}

void func_84359AF8(void) {
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    UNUSED s32 pad;
    s32 sp54;

    func_84359490(&sp74, &sp70, &sp6C, &sp68, &sp64, &sp60);
    sp68 *= 8.0f;
    sp64 *= 4.0f;
    sp60 = 0.0f;
    sp64 += 6.0f;
    sp5C = func_84359470();
    sp54 = guRandom();
    func_84360EFC(sp74, sp70, sp6C, sp68, (((sp54 % 4) * 0.01f) + sp64) - 0.02f,
                  (sp60 - ((guRandom() % 5) * 0.3f)) + 0.6f, 3, 0x64, 0xC8, 0xFF, 0xC8, 0, 0x64, 0xC8, 0.1f, sp5C,
                  4.0f * sp5C, 0x3C);
}

void func_84359C84(void) {
    D_843925CE = 0;
    func_84359650();
    func_843605C0();
    func_84359AF8();
}

s32 func_84359CB8(void) {
    D_843925CE++;
    if (D_843925CE >= 0xB5) {
        return -1;
    }

    if ((D_843925CE < 0x78) && ((D_843925CE % 7) == 0)) {
        func_84359AF8();
    }
    return func_84361FB0();
}

void func_84359D28(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = func_84362084(gDisplayListHead);
}

void func_84359D7C(void) {
    Vec3f sp34;
    f32 sp30;

    func_84359650();
    func_84359410(&sp34);
    sp30 = func_84359450();
    func_84359650();
    func_8435FB90(sp34.x, sp34.y, sp34.z, sp30, 0x64, 0xC8, 0xFF, 0, 0x64, 0xC8);
}

s32 func_84359DF4(void) {
    return func_8435FD50();
}

void func_84359E14(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = func_8436032C(gDisplayListHead);
}

void func_84359E68(void) {
    UNUSED s32 pad[3];
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;

    sp40 = func_84359470();
    func_84359564(&sp58, &sp54, &sp50, &sp4C, &sp48, &sp44);
    sp4C *= 20.0f;
    sp48 *= 20.0f;
    sp44 *= 20.0f;
    sp58 += sp40 * (30.0f - (guRandom() % 60));
    sp54 += sp40 * (30.0f - (guRandom() % 60));
    sp50 += sp40 * (30.0f - (guRandom() % 60));
    func_84366B38(sp58, sp54, sp50, sp4C, sp48, sp44, 0xFF, 0xFF, 0, 0x3C, 0.3f, 0x1E);
}

void func_84359FE0(void) {
    D_843925D0 = 0;
    func_84359650();
    func_84366A10();
    func_84359E68();
}

s32 func_8435A014(void) {
    D_843925D0++;
    if (D_843925D0 >= 0x709) {
        return -1;
    }

    if ((D_843925D0 < 0x6EA) && ((D_843925D0 % 3) == 0)) {
        func_84359E68();
    }

    return func_84367014();
}

void func_8435A084(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = func_843670C8(gDisplayListHead);
}

void func_8435A0D8(void) {
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    UNUSED s32 pad;
    s32 sp54;

    func_84359490(&sp74, &sp70, &sp6C, &sp68, &sp64, &sp60);
    sp68 *= 8.0f;
    sp64 *= 4.0f;
    sp60 = 0.0f;
    sp64 += 6.0f;
    sp5C = func_84359470();
    sp54 = guRandom();
    func_84360B10(sp74, sp70, sp6C, sp68, (((sp54 % 5) * 0.1f) + sp64) - 0.2f,
                  (sp60 - ((guRandom() % 5) * 0.3f)) + 0.6f, 3, 0xFF, 0xFF, 0xFF, 0x64, 0x64, 0x96, 0x96, 0.1f, sp5C,
                  3.0f * sp5C, 0x3C);
}

void func_8435A298(void) {
    D_843925D2 = 0;
    func_84359650();
    func_843605C0();
    func_8435A0D8();
}

s32 func_8435A2CC(void) {
    D_843925D2++;
    if (D_843925D2 >= 0xB5) {
        return -1;
    }

    if ((D_843925D2 < 0x78) && ((D_843925D2 % 7) == 0)) {
        func_8435A0D8();
    }

    return func_84361FB0();
}

void func_8435A33C(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = func_84362084(gDisplayListHead);
}

void func_8435A390(void) {
    Vec3f sp34;
    f32 sp30;

    func_84359650();
    func_84359430(&sp34);
    sp30 = func_84359450();
    func_84359650();
    func_8435FB90(sp34.x, sp34.y, sp34.z, sp30, 0xFF, 0xFF, 0xFF, 0x64, 0x96, 0x96);
}

s32 func_8435A40C(void) {
    return func_8435FD50();
}

void func_8435A42C(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = func_8436032C(gDisplayListHead);
}

void func_8435A480(void) {
    Vec3f sp34;
    f32 sp30;

    func_84359650();
    func_84359430(&sp34);
    sp30 = func_84359450();
    func_84359650();
    func_8435FB90(sp34.x, sp34.y, sp34.z, sp30, 0xFF, 0xFF, 0x64, 0x96, 0x96, 0);
}

s32 func_8435A4F8(void) {
    return func_8435FD50();
}

void func_8435A518(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = func_8436032C(gDisplayListHead);
}

void func_8435A56C(void) {
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    UNUSED s32 pad;
    s32 sp54;

    func_84359490(&sp74, &sp70, &sp6C, &sp68, &sp64, &sp60);
    sp68 *= 8.0f;
    sp64 *= 4.0f;
    sp60 = 0.0f;
    sp64 += 6.0f;
    sp5C = func_84359470();
    sp54 = guRandom();
    func_84360EFC(sp74, sp70, sp6C, sp68, (((sp54 % 4) * 0.01f) + sp64) - 0.02f,
                  (sp60 - ((guRandom() % 5) * 0.3f)) + 0.6f, 3, 0xFF, 0xFF, 0x64, 0xFF, 0x96, 0x96, 0, 0.1f, sp5C,
                  4.0f * sp5C, 0x3C);
}

void func_8435A6F8(void) {
    D_843925D6 = 0;
    func_84359650();
    func_843605C0();
    func_8435A56C();
}

s32 func_8435A72C(void) {
    D_843925D6++;
    if (D_843925D6 >= 0xB5) {
        return -1;
    }

    if ((D_843925D6 < 0x78) && ((D_843925D6 % 7) == 0)) {
        func_8435A56C();
    }

    return func_84361FB0();
}

void func_8435A79C(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = func_84362084(gDisplayListHead);
}

void func_8435A7F0(void) {
    D_843925D8 = 0;
    func_84359650();
    func_8436B140();
}

s32 func_8435A81C(void) {
    UNUSED s32 pad[1];
    Vec3f sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    UNUSED s32 pad2[2];
    f32 var_fv0;
    f32 sp44;

    D_843925D8++;
    if (!(D_843925D8 & 1)) {
        sp44 = func_84359470();
        func_843593F0(&sp60);
        sp5C = (((guRandom() % 50) - 0x19) * sp44) + sp60.x;
        sp58 = (((guRandom() % 60) - 0x1E) * sp44) + sp60.y;
        sp54 = (((guRandom() % 50) - 0x19) * sp44) + sp60.z;
        var_fv0 = 10.0f;
        if (sp5C > 0.0) {
            var_fv0 = -var_fv0;
        }
        func_8436B270(sp5C, sp58, sp54, var_fv0, 0.0f, 0.0f, 0xFF, 0xFF, 0xFF, 0x64, 0.3f, 1.0f, 4.0f, 0x1E);
    }
    func_8436B8D8();
    return 0;
}

void func_8435A99C(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = func_8436B974(gDisplayListHead);
}

void func_8435A9F0(void) {
    D_843925DA = 0;
    func_84359650();
    func_8436A410();
}

s32 func_8435AA1C(void) {
    UNUSED s32 pad[1];
    Vec3f sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    UNUSED s32 pad2[2];
    f32 var_fv0;
    f32 sp44;

    D_843925DA++;
    if (!(D_843925DA & 1)) {
        sp44 = func_84359470();
        func_843593F0(&sp60);
        sp5C = (((guRandom() % 50) - 0x19) * sp44) + sp60.x;
        sp58 = (((guRandom() % 60) - 0x1E) * sp44) + sp60.y;
        sp54 = (((guRandom() % 50) - 0x19) * sp44) + sp60.z;
        var_fv0 = 10.0f;
        if (sp5C > 0.0) {
            var_fv0 = -var_fv0;
        }
        func_8436A540(sp5C, sp58, sp54, var_fv0, 0.0f, 0.0f, 0xFF, 0xFF, 0xFF, 0x64, 0.3f, 1.0f, 4.0f, 0x1E);
    }
    func_8436ABA8();
    return 0;
}

void func_8435AB9C(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = func_8436AC44(gDisplayListHead);
}

void func_8435ABF0(void) {
    Vec3f sp1C;

    func_84359650();
    func_843593F0(&sp1C);
    func_843638E0(0x708);
}

s32 func_8435AC20(void) {
    return func_843640A4();
}

void func_8435AC40(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = func_84364428(gDisplayListHead);
}

void func_8435AC94(void) {
    Vec3f sp1C;

    func_84359650();
    func_843593F0(&sp1C);
    func_84364A18(0x708);
}

s32 func_8435ACC4(void) {
    return func_84365288();
}

void func_8435ACE4(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = func_84365558(gDisplayListHead);
}

void func_8435AD38(void) {
    Vec3f sp1C;

    func_84359650();
    func_843593F0(&sp1C);
    func_84365A10(0x708);
}

s32 func_8435AD68(void) {
    return func_843661D0();
}

void func_8435AD88(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = func_84366560(gDisplayListHead);
}

void func_8435ADDC(void) {
    D_84392580 = 0;
    func_84359650();
    func_84367CB0();
}

s32 func_8435AE08(void) {
    s32 var_v1;
    Vec3f sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;

    D_84392580++;
    if (D_84392580 >= 0x32) {
        return -1;
    }

    if (D_84392580 < 4) {
        func_84359430(&sp68);
        sp64 = sp68.x;
        sp60 = sp68.y;
        sp5C = sp68.z;
        sp58 = 1.0f;
        sp4C = (((D_84392580 % 3) * M_PI_F) / 3.0) + 0.5235987901687622;
        sp54 = (f64)__sinf(sp4C);
        sp50 = (f64)__cosf(sp4C);
        func_80031B04(&sp58, &sp54, &sp50);
        sp54 *= 20.0;
        sp50 *= 20.0;
        sp58 = 10.0f;
        if (sp64 < 0.0) {
            sp58 = -sp58;
        }
        func_84367E2C(sp64, sp60, sp5C, sp58, sp54, sp50, 0xC0, 0xFF, 0xFF, 0x80, (((guRandom() % 2) * 2) - 1) * 0.3,
                      2.0f, 13.0f, 0x28);
    }

    if (D_84392580 >= 2) {
        var_v1 = func_843684CC();
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

void func_8435B048(void) {
    if (D_84392580 >= 2) {
        gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        gDisplayListHead = func_84368560(gDisplayListHead);
    }
}

void func_8435B0B0(void) {
    D_84392582 = 0;
    func_84359650();
    func_84368AB0();
}

s32 func_8435B0DC(void) {
    s32 var_v1;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;

    D_84392582++;
    if (((D_84392582 >> 2) < 4) && !(D_84392582 & 3)) {
        func_84359490(&sp60, &sp5C, &sp58, &sp54, &sp50, &sp4C);
        sp48 = ((2 - (((D_84392582 >> 2) + 2) % 3)) * 0.5235988f) + 0.34906587f;
        sp54 *= 7.0f * __cosf(sp48);
        sp50 = __sinf(sp48) * 10.0f;
        sp4C = 0.0f;
        func_84368C04(sp60, sp5C, sp58, sp54, sp50, 0.0f, 0xD0, 0xFF, 0xFF, 0x80, 0.8f, 2.0f, 4.0f, 0x28);
    }

    if (D_84392582 >= 2) {
        var_v1 = func_843692E8();
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

void func_8435B260(void) {
    if (D_84392582 >= 2) {
        gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        gDisplayListHead = func_84369388(gDisplayListHead);
    }
}

void func_8435B2C8(void) {
    Vec3f sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;

    D_843925C8 = 0;
    func_84359650();
    func_843697F0();
    func_84359490(&sp58, &sp54, &sp50, &sp4C, &sp48, &sp44);
    sp4C *= 5.0;
    sp48 *= 5.0;
    sp44 *= 5.0;
    func_84369950(sp58, sp54, sp50, sp4C, sp48, sp44, 0xC0, 0xFF, 0xFF, 0xA0, 0.6f, 2.0f, 4.0f, 0x28);
    sp5C.x = sp58;
    sp5C.y = sp54;
    sp5C.z = sp50;
    func_8432FD70(sp5C, 1);
}

s32 func_8435B408(void) {
    D_843925C8++;
    if (D_843925C8 >= 0x32) {
        return -1;
    }

    return func_84369F0C();
}

void func_8435B454(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = func_84369FA0(gDisplayListHead);
}

void func_8435B4A8(void) {
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;

    func_84359490(&sp5C, &sp58, &sp54, &sp50, &sp4C, &sp48);
    sp50 *= 6.0f;
    sp4C *= 6.0f;
    sp48 *= 6.0f;
    func_843606D0(sp5C, sp58, sp54, sp50, sp4C, sp48, 8, 0xFF, 0xFF, 0xFF, 0xB4, 0.3f, 2.0f, 20.0f, 0x3C);
}

void func_8435B580(void) {
    D_843925CA = 0;
    func_84359650();
    func_843605C0();
    func_8435B4A8();
}

s32 func_8435B5B4(void) {
    D_843925CA++;
    if (D_843925CA >= 0xB5) {
        return -1;
    }
    return func_84361FB0();
}

void func_8435B600(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = func_84362084(gDisplayListHead);
}

void func_8435B654(void) {
    static unk_D_843C2C00_024 D_84387FC0 = { 2, 1, 0xE, 1, 2, 2, 3, 1 };
    static unk_D_843C2C00_024 D_84387FE0 = { 3, 5, 0, 5, 3, 7, 0, 5 };
    static unk_D_843C2C00_024 D_84388000 = { 2, 1, 0xE, 1, 2, 1, 3, 1 };
    static unk_D_843C2C00_024 D_84388020 = { 3, 5, 0, 5, 0, 7, 5, 7 };

    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;

    func_84359490(&spB4, &spB0, &spAC, &spA8, &spA4, &spA0);
    spA8 *= 10.0f;
    spA4 *= 10.0f;
    spA0 *= 10.0f;
    func_8436BFB8(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 2.0f, 10.0f, 0x14, 0x8F, 0x8F, 6, 0xA, 0xF, 0xE,
                  -3, 5, 0, 0xF, &D_84387FC0, &D_84387FE0, 0xFF, 0xFF, 0, 0x96, 0x64, 0xFF, 0, 0xC8, 0x32, 0xFF, 0x96,
                  0xFF, 0x78);
    func_8436BFB8(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 3.0f, 15.0f, 0x14, 0x8F, 0x90, 2, 6, 0, 0xF, -4,
                  2, 0, 0, &D_84388000, &D_84388020, 0, 0xFF, 0x64, 0x96, 0x64, 0x64, 0, 0xFF, 0xC8, 0, 0, 0, 0);
}

void func_8435B8E8(void) {
    func_84359650();
    func_8436BE70();
    func_8435B654();
}

s32 func_8435B918(void) {
    return func_8436C62C();
}

void func_8435B938(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = func_8436CE34(gDisplayListHead);
}

void func_8435B98C(void) {
    static s32 D_84388040[] = { 3, 5, 1, 5, 1, 7, 3, 7 };
    static s32 D_84388060[] = { 0x1F, 0x1F, 0x1F, 0, 7, 7, 7, 0 };

    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;

    func_84359490(&spA4, &spA0, &sp9C, &sp98, &sp94, &sp90);
    sp94 += 0.2f * __cosf((RAND(10) * M_PI_F) / 10.0f);
    sp90 += 0.2f * __cosf((RAND(10) * M_PI_F) / 10.0f);

    sp98 *= 12.0f;
    sp94 *= 12.0f;
    sp90 *= 12.0f;

    func_8436D4A4(0, spA4, spA0, sp9C, sp98, sp94, sp90, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0, 0x64, 0xFF, 0xFF, 0.4f, 2.0f,
                  20.0f, 0x3C, 0x95, 0x95, 0, 0xA, 0, 0xD, 0, 0, 0, 0, D_84388040, D_84388060);
}

void func_8435BB64(void) {
    D_843925CC = 0;
    func_84359650();
    func_8436D370();
    func_8435B98C();
}

s32 func_8435BB98(void) {
    D_843925CC++;
    if ((D_843925CC % 10) == 0) {
        func_8435B98C();
    }
    return func_8436DE60();
}

void func_8435BBEC(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = func_8436E3BC(gDisplayListHead);
}

void func_8435BC40(void) {
    static unk_D_843C2C00_024 D_84388080 = { 3, 5, 1, 5, 6, 7, 2, 3 };
    static unk_D_843C2C00_024 D_843880A0 = { 0x1F, 0x1F, 0x1F, 0, 0, 7, 5, 7 };
    static unk_D_843C2C00_024 D_843880C0 = { 3, 5, 2, 5, 1, 7, 3, 7 };
    static unk_D_843C2C00_024 D_843880E0 = { 0x1F, 0x1F, 0x1F, 0, 0, 7, 5, 7 };

    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;

    func_84359490(&spB4, &spB0, &spAC, &spA8, &spA4, &spA0);
    spA8 *= 10.0f;
    spA4 *= 10.0f;
    spA0 *= 10.0f;
    func_8436BFB8(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 2.0f, 10.0f, 0x14, 0x93, 0x93, 5, 0xA, 0xF, 0xF,
                  -5, 5, 0xF, 0xF, &D_84388080, &D_843880A0, 0xC8, 0xC8, 0, 0x64, 0, 0, 0xC8, 0, 0xFF, 0, 0xFF, 0, 0x5A);
    func_8436BFB8(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 3.0f, 15.0f, 0x14, 0x91, 0x91, -2, 0xA, 0xF,
                  0xF, 5, 0xF, 0xF, 0xF, &D_843880C0, &D_843880E0, 0xFF, 0x32, 0x64, 0xC8, 0, 0x64, 0x32, 0xFF, 0xFF, 0,
                  0, 0, 0);
}

void func_8435BED8(void) {
    func_84359650();
    func_8436BE70();
    func_8435BC40();
}

s32 func_8435BF08(void) {
    return func_8436C62C();
}

void func_8435BF28(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = func_8436CE34(gDisplayListHead);
}

void func_8435BF7C(void) {
    static unk_D_843C2C00_024 D_84388100 = { 2, 1, 0xE, 1, 2, 7, 1, 3 };
    static unk_D_843C2C00_024 D_84388120 = { 3, 5, 0, 5, 0, 7, 5, 7 };
    static unk_D_843C2C00_024 D_84388140 = { 2, 1, 0xE, 1, 2, 7, 1, 3 };
    static unk_D_843C2C00_024 D_84388160 = { 3, 5, 0, 5, 0, 7, 5, 7 };

    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;

    func_84359490(&spB4, &spB0, &spAC, &spA8, &spA4, &spA0);
    spA8 *= 10.0f;
    spA4 *= 10.0f;
    spA0 *= 10.0f;
    func_8436BFB8(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 2.0f, 10.0f, 0x14, 0x97, 0x98, -5, 0x14, 0xF,
                  0xD, -5, 0x14, 0, 0xE, &D_84388100, &D_84388120, 0xFF, 0xFF, 0xFF, 0x32, 0x64, 0x64, 0, 0xFF, 0xFF,
                  0xC8, 0xFF, 0xFF, 0x96);
    func_8436BFB8(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 3.0f, 15.0f, 0x14, 0x97, 0x98, 5, 0xF, 0xF, 0xE,
                  0, 0xF, 0xF, 0xF, &D_84388140, &D_84388160, 0xFF, 0xFF, 0xFF, 0x32, 0x64, 0x64, 0x64, 0xFF, 0xFF, 0, 0,
                  0, 0);
}

void func_8435C220(void) {
    func_84359650();
    func_8436BE70();
    func_8435BF7C();
}

s32 func_8435C250(void) {
    return func_8436C62C();
}

void func_8435C270(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = func_8436CE34(gDisplayListHead);
}

void func_8435C2C4(void) {
    static unk_D_843C2C00_024 D_84388180 = { 2, 1, 0xE, 1, 2, 1, 3, 1 };
    static unk_D_843C2C00_024 D_843881A0 = { 3, 5, 0, 5, 0, 7, 5, 7 };

    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;

    func_84359490(&spB4, &spB0, &spAC, &spA8, &spA4, &spA0);
    spA8 *= 10.0f;
    spA4 *= 10.0f;
    spA0 *= 10.0f;
    func_8436BFB8(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 3.0f, 15.0f, 0x14, 0x97, 0x94, 0, 0x14, 0xE,
                  0xF, 0, 0x14, 0xF, 0xE, &D_84388180, &D_843881A0, 0xFF, 0xFF, 0xFF, 0x96, 0x96, 0xFF, 0xFF, 0, 0xFF,
                  0xFF, 0xFF, 0, 0x96);
}

void func_8435C448(void) {
    func_84359650();
    func_8436BE70();
    func_8435C2C4();
}

s32 func_8435C478(void) {
    return func_8436C62C();
}

void func_8435C498(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = func_8436CE34(gDisplayListHead);
}

void func_8435C4EC(void) {
    static unk_D_843C2C00_024 D_843881C0 = {
        0x00000002, 0x00000001, 0x0000000E, 0x00000001, 0x00000007, 0x00000007, 0x00000007, 0x00000003,
    };
    static unk_D_843C2C00_024 D_843881E0 = {
        0x00000003, 0x00000005, 0x00000000, 0x00000005, 0x00000007, 0x00000007, 0x00000007, 0x00000000,
    };
    static unk_D_843C2C00_024 D_84388200 = {
        0x00000002, 0x00000001, 0x0000000E, 0x00000001, 0x00000002, 0x00000001, 0x00000003, 0x00000001,
    };
    static unk_D_843C2C00_024 D_84388220 = {
        0x00000003, 0x00000005, 0x00000000, 0x00000005, 0x00000000, 0x00000007, 0x00000005, 0x00000007,
    };

    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;

    func_84359490(&spB4, &spB0, &spAC, &spA8, &spA4, &spA0);
    spA8 *= 12.0f;
    spA4 *= 12.0f;
    spA0 *= 12.0f;
    func_8436BFB8(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 2.0f, 10.0f, 0x14, 0x91, 0x92, 5, 0x1E, 0, 0xD,
                  -5, 0x1E, 0xF, 0xD, &D_843881C0, &D_843881E0, 0xFF, 0xFF, 0, 0xFF, 0x96, 0x32, 0, 0, 0xFF, 0xFF, 0xC8,
                  0x64, 0xC8);
    func_8436BFB8(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 3.0f, 15.0f, 0x14, 0x97, 0x96, 6, 0x14, 0xE,
                  0xF, -3, 0xA, 0, 0xF, &D_84388200, &D_84388220, 0xFF, 0xFF, 0x64, 0x96, 0xFF, 0xFF, 0x64, 0, 0xC8, 0, 0,
                  0, 0);
}

void func_8435C790(void) {
    static s32 D_84388240[] = {
        0x00000002, 0x00000001, 0x0000000E, 0x00000001, 0x00000002, 0x00000001, 0x00000003, 0x00000001,
    };
    static s32 D_84388260[] = {
        0x00000003, 0x00000005, 0x00000000, 0x00000005, 0x00000000, 0x00000007, 0x00000005, 0x00000007,
    };

    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;

    func_84359490(&spA4, &spA0, &sp9C, &sp98, &sp94, &sp90);

    sp94 += (0.4f * __cosf((RAND(10) * M_PI_F) / 10));
    sp90 += (0.4f * __cosf((RAND(10) * M_PI_F) / 10));

    sp98 *= 12.0f;
    sp94 *= 12.0f;
    sp90 *= 12.0f;

    func_8436D4A4(0, spA4, spA0, sp9C, sp98, sp94, sp90, 0xFF, 0xFF, 0x64, 0x32, 0xC8, 0xFF, 0x32, 0, 0xFF, 0.4f, 2.0f,
                  5.0f, 0x3C, 0x95, 0x95, 0, 0x14, 0, 0xD, 0, 0x19, 0, 0xD, D_84388240, D_84388260);
}

void func_8435C96C(void) {
    func_84359650();
    func_8436BE70();
    func_8435C4EC();
    func_8436D370();
    func_8435C790();
}

s32 func_8435C9AC(void) {
    D_843925D4++;
    if ((D_843925D4 % 10) == 0) {
        func_8435C790();
    }
    func_8436DE60();
    return func_8436C62C();
}

void func_8435CA08(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = func_8436CE34(gDisplayListHead);
    gDisplayListHead = func_8436E3BC(gDisplayListHead);
}
