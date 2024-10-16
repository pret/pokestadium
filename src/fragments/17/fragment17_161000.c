#include "fragment17.h"
#include "src/F420.h"

u16 func_86B01670(unk_D_86002F34_00C* arg0, unk_D_86002F58_004_000* arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5) {
    UNUSED s32 pad[6];
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    unk_D_86002F58_004_000* arg11;
    f32 sp54;
    f32 sp50;
    UNUSED s32 pad3;
    f32 sp48;
    s16 sp46;
    s16 sp44;
    f32 sp40;
    UNUSED s32 pad2;
    f32 sp38;
    s32 sp34 = 0;

    func_800102A4(&arg0->unk_60.at, &arg0->unk_60.eye, &sp48, &sp46, &sp44);
    sp40 = (COSS(sp44 + 0x8000) * arg5) + arg0->unk_60.eye.z;
    sp38 = (SINS(sp44 + 0x8000) * arg5) + arg0->unk_60.eye.x;

    sp54 = (COSS((sp44 - arg3) + 0x8000) * arg4) + sp40;
    sp60 = (SINS((sp44 - arg3) + 0x8000) * arg4) + sp38;

    sp50 = (COSS((sp44 + arg2) + 0x8000) * arg4) + sp40;
    sp5C = (SINS((sp44 + arg2) + 0x8000) * arg4) + sp38;

    sp6C =
        ((sp54 - arg1->unk_024.z) * (sp5C - arg1->unk_024.x)) - ((sp50 - arg1->unk_024.z) * (sp60 - arg1->unk_024.x));

    arg11 = arg1;

    sp68 = ((sp50 - arg11->unk_024.z) * (sp38 - arg11->unk_024.x)) -
           ((sp40 - arg11->unk_024.z) * (sp5C - arg11->unk_024.x));
    sp64 = ((sp40 - arg11->unk_024.z) * (sp60 - arg11->unk_024.x)) -
           ((sp54 - arg11->unk_024.z) * (sp38 - arg11->unk_024.x));

    if (((sp6C >= 0.0f) && (sp68 >= 0.0f) && (sp64 >= 0.0f)) || ((sp6C <= 0.0f) && (sp68 <= 0.0f) && (sp64 <= 0.0f))) {
        sp34 = 1;
    }

    return sp34;
}

void func_86B01898(unk_D_86B0E5D4_04* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    arg0->unk_0C = arg1;
    arg0->unk_0E = arg2;
    arg0->unk_20 = arg3;
    arg0->unk_22 = arg4;
}

void func_86B018D4(unk_D_86B0E5D4_04* arg0, f32 arg1, f32 arg2) {
    arg0->unk_18 = arg1;
    arg0->unk_2C = arg2;
}

void func_86B018E8(unk_D_86B0E5D4_04* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    arg0->unk_12 = arg1;
    arg0->unk_14 = arg2;
    arg0->unk_26 = arg3;
    arg0->unk_28 = arg4;
}

void func_86B01924(unk_D_86B0E5D4_04* arg0, f32 arg1, f32 arg2) {
    arg0->unk_1C = arg1;
    arg0->unk_30 = arg2;
}

void func_86B01938(unk_D_86B0E5D4_04* arg0, f32 arg1, f32 arg2) {
    arg0->unk_34 = arg1;
    arg0->unk_38 = arg2;
}

void func_86B0194C(unk_D_86B0C160* arg0, unk_D_86B0E5D4* arg1) {
    unk_D_86B0E5D4_04* ptr = &arg1->unk_04;
    unk_D_86002F34_00C* ptr2 = arg1->unk_00;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;

    ptr->unk_74 = 0.0f;
    ptr->unk_68 = 0;

    if (arg0->unk_30 != 255.0f) {
        ptr2->unk_24.fovy = ptr->unk_3C = arg0->unk_30;
    } else {
        ptr->unk_3C = arg0->unk_30;
    }

    sp34 = arg0->unk_0C;
    sp30 = arg0->unk_20;
    sp2C = arg0->unk_10;
    sp28 = arg0->unk_24;

    func_86B01898(ptr, arg0->unk_00, arg0->unk_02, arg0->unk_14, arg0->unk_16);
    func_86B018D4(ptr, sp34, sp30);
    func_86B018E8(ptr, arg0->unk_06, arg0->unk_08, arg0->unk_1A, arg0->unk_1C);
    func_86B01924(ptr, sp2C, sp28);
    func_86B01938(ptr, arg0->unk_28, arg0->unk_2C);
}

void func_86B01A40(unk_D_86B0E5D4_04* arg0, unk_D_86B0E5D4* arg1) {
    unk_D_86002F34_00C* sp2C = arg1->unk_00;

    func_80010354(&arg0->unk_00, &sp2C->unk_60.at, arg0->unk_18, arg0->unk_0C, arg0->unk_0E);
    func_80010354(&sp2C->unk_60.at, &sp2C->unk_60.eye, arg0->unk_1C, arg0->unk_12, arg0->unk_14);
}

s32 func_86B01AAC(unk_D_86B0E5D4_04* arg0, unk_D_86B0E5D4* arg1) {
    unk_D_86002F34_00C* temp_s2 = arg1->unk_00;
    Vec3f sp58;
    Vec3f sp4C;
    UNUSED s32 pad[3];
    f32 sp3C;
    s16 sp3A;
    s16 sp38;

    if (arg0->unk_3C != 255.0f) {
        temp_s2->unk_24.fovy = arg0->unk_3C;
    } else {
        func_86B0145C(&temp_s2->unk_24.fovy, 30.0f, 0.06f);
    }

    func_80010354(&arg0->unk_00, &sp58, arg0->unk_18, arg0->unk_0C, arg0->unk_0E);
    func_80010354(&arg0->unk_00, &sp4C, arg0->unk_2C, arg0->unk_20, arg0->unk_22);
    func_800102A4(&sp58, &sp4C, &sp3C, &sp3A, &sp38);

    arg1->unk_04.unk_68 = func_800104AC(arg1->unk_04.unk_68, sp3C, arg0->unk_34, arg0->unk_34);

    func_80010354(&sp58, &temp_s2->unk_60.at, arg1->unk_04.unk_68, sp3A, sp38);
    func_80010354(&temp_s2->unk_60.at, &temp_s2->unk_60.eye, arg0->unk_1C, arg0->unk_12, arg0->unk_14);

    arg1->unk_04.unk_6C = sp3C - arg1->unk_04.unk_68;
    if (arg1->unk_04.unk_6C <= 5.0f) {
        return 1;
    }

    return 0;
}
