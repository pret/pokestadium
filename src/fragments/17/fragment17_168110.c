#include "fragment17.h"
#include "src/F420.h"

typedef struct unk_D_86B0DFC0 {
    u8 unk_00[1];
} unk_D_86B0DFC0; // size = ??

static unk_D_86B0DFC0 D_86B0DFC0 = { 0x8E };

s16 func_86B08780(void) {
    return D_86B0FA78->unk_004.unk_01E.y + 0x8000;
}

s32 func_86B087A0(u8 arg0, u8* arg1, s32 arg2) {
    while (arg2--) {
        if (arg0 == *arg1) {
            return 1;
        }
        arg1++;
    }
    return 0;
}

void func_86B087E8(unk_D_86B0FA78* arg0, Vec3f* arg1) {
    f32 sp24 = 0.0f;
    unk_D_86B0DFC0 sp20 = D_86B0DFC0;

    if (func_86B087A0(D_86B0FA78->unk_174, sp20.unk_00, 1) != 0) {
        sp24 = D_86B10660.unk_04 / 1.5f;
    }

    if (D_86B10660.unk_08 != 0) {
        arg1->x = arg0->unk_004.unk_024.x;
        arg1->y = arg0->unk_004.unk_024.y + sp24;
        arg1->z = arg0->unk_004.unk_024.z;
    } else {
        arg1->x = arg0->unk_004.unk_024.x;
        arg1->y = arg0->unk_004.unk_024.y + D_86B10660.unk_04;
        arg1->z = arg0->unk_004.unk_024.z;
    }

    if (arg1->y < 0) {
        arg1->y = D_86B10660.unk_04;
    }
}

void func_86B088E4(void) {
    func_80010354(&D_86B0FA7C->unk_04, &D_86B0FA7C->unk_00->unk_60.at, D_86B0FA7C->unk_1C, D_86B0FA7C->unk_10,
                  func_86B08780() + D_86B0FA7C->unk_12);
    func_80010354(&D_86B0FA7C->unk_04, &D_86B0FA7C->unk_00->unk_60.eye, D_86B0FA7C->unk_20, D_86B0FA7C->unk_16,
                  func_86B08780() + D_86B0FA7C->unk_18);

    D_86B0FA7C->unk_00->unk_60.at.y += D_86B10660.unk_0C;
    if (D_86B0FA7C->unk_00->unk_60.eye.y <= 10.0f) {
        D_86B0FA7C->unk_00->unk_60.eye.y = 10.0f;
    }
}

f32 func_86B089B0(f32 arg0, f32 arg1) {
    f32 temp_fv1 = D_86B10660.unk_00 * arg0;

    if (arg1 < temp_fv1) {
        return arg1;
    }
    return temp_fv1;
}

void func_86B089E0(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    D_86B0FA7C->unk_10 = arg0;
    D_86B0FA7C->unk_12 = arg1;
    D_86B0FA7C->unk_24 = arg2;
    D_86B0FA7C->unk_26 = arg3;
}

void func_86B08A3C(f32 arg0, f32 arg1) {
    D_86B0FA7C->unk_1C = arg0;
    D_86B0FA7C->unk_30 = arg1;
}

void func_86B08A58(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    D_86B0FA7C->unk_16 = arg0;
    D_86B0FA7C->unk_18 = arg1;
    D_86B0FA7C->unk_2A = arg2;
    D_86B0FA7C->unk_2C = arg3;
}

void func_86B08AB4(f32 arg0, f32 arg1) {
    D_86B0FA7C->unk_20 = arg0;
    D_86B0FA7C->unk_34 = arg1;
}

void func_86B08AD0(f32 arg0, f32 arg1) {
    D_86B0FA7C->unk_38 = arg0;
    D_86B0FA7C->unk_3C = arg1;
}

void func_86B08AEC(unk_D_86B0C160* arg0, unk_D_86002F34_00C* arg1) {
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;

    D_86B0FA7C->unk_44 = 0.0f;
    if (arg0->unk_30 != 200.0f) {
        arg1->unk_24.fovy = D_86B0FA7C->unk_40 = arg0->unk_30;
    } else {
        D_86B0FA7C->unk_40 = arg0->unk_30;
    }

    sp34 = func_86B089B0(arg0->unk_0C, 500.0f);
    sp30 = func_86B089B0(arg0->unk_20, 500.0f);
    sp2C = func_86B089B0(arg0->unk_10, 500.0f);
    sp28 = func_86B089B0(arg0->unk_24, 500.0f);

    func_86B089E0(arg0->unk_00, func_86B08780() + arg0->unk_02, arg0->unk_14, func_86B08780() + arg0->unk_16);
    func_86B08A3C(sp34, sp30);

    func_86B08A58(arg0->unk_06, func_86B08780() + arg0->unk_08, arg0->unk_1A, func_86B08780() + arg0->unk_1C);
    func_86B08AB4(sp2C, sp28);
    func_86B08AD0(arg0->unk_28, arg0->unk_2C);
}

s32 func_86B08C44(unk_D_86002F34_00C* arg0) {
    Vec3f sp5C;
    Vec3f sp50;
    Vec3f sp44;
    Vec3f sp38;
    f32 sp34;
    f32 sp30;
    s16 sp2E;
    s16 sp2C;

    if (D_86B0FA7C->unk_40 != 200.0f) {
        arg0->unk_24.fovy = D_86B0FA7C->unk_40;
    } else {
        func_86B0145C(&arg0->unk_24.fovy, 30.0f, 0.06f);
    }

    func_86B0145C(&D_86B0FA7C->unk_44, D_86B0FA7C->unk_38, D_86B0FA7C->unk_3C);
    func_80010354(&D_86B0FA7C->unk_04, &sp50, D_86B0FA7C->unk_34, D_86B0FA7C->unk_2A,
                  func_86B08780() + D_86B0FA7C->unk_2C);

    if (sp50.y <= 10.0f) {
        sp50.y = 10.0f;
    }

    func_86B01404(&sp44, &arg0->unk_60.eye);
    func_800102A4(&sp44, &sp50, &sp34, &sp2E, &sp2C);
    func_80010354(&sp44, &arg0->unk_60.eye, D_86B0FA7C->unk_44 * sp34, sp2E, sp2C);
    func_80010354(&D_86B0FA7C->unk_04, &sp38, D_86B0FA7C->unk_30, D_86B0FA7C->unk_24,
                  func_86B08780() + D_86B0FA7C->unk_26);

    sp38.y += D_86B10660.unk_0C;

    func_86B01404(&sp5C, &arg0->unk_60.at);
    func_800102A4(&sp5C, &sp38, &sp30, &sp2E, &sp2C);
    func_80010354(&sp5C, &arg0->unk_60.at, D_86B0FA7C->unk_44 * sp30, sp2E, sp2C);

    if ((sp34 <= 1.0f) && (sp30 <= 1.0f)) {
        return 1;
    }
    return 0;
}
