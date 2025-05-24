#include "fragment62.h"
#include "src/17300.h"
#include "src/1C720.h"
#include "src/F420.h"

static f32 D_84384600[] = { 1.0f, 2.0f };

void func_843093F0(unk_D_84390010* arg0, f32 arg1, s16 arg2) {
    arg0->unk_498 = arg1;
    arg0->unk_454.z = COSS(arg2) * arg1;
    arg0->unk_454.y = SINS(arg2) * arg1;
    arg0->unk_49C = 0.01f;
}

void func_84309448(unk_D_84390010* arg0, unk_D_84390010* arg1, f32 arg2, f32 arg3, s32 arg4) {
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    UNUSED s32 pad;
    Vec3f sp3C;
    UNUSED s32 pad2;
    f32 temp_fa1;
    f32 temp_fa2;
    f32 var_fa0;

    sp54 = arg1->unk_49C;
    sp50 = arg1->unk_498;
    sp4C = 18.0f;
    arg1->unk_498 = func_800104AC(sp50, arg2, arg3, arg3);

    var_fa0 = arg1->unk_498;
    if (arg2 <= var_fa0) {
        if (&arg1->unk_454) {}
        var_fa0 = 0.0f;
    }

    sp3C.z = COSS(arg4) * var_fa0;
    sp3C.y = SINS(arg4) * var_fa0;

    temp_fa1 = -sp54 * ((sp50 * arg1->unk_454.z) + sp3C.z);
    temp_fa2 = -sp4C - (sp54 * ((sp50 * arg1->unk_454.y) + sp3C.y));

    arg1->unk_454.z = (arg1->unk_454.z + sp3C.z + (temp_fa1 * 0.05f));
    arg1->unk_454.y = (arg1->unk_454.y + sp3C.y + (temp_fa2 * 0.05f));

    sp3C.y = arg1->unk_454.y;
    arg1->unk_454.x = 0.0f;

    func_8430C19C(&sp3C, arg1->unk_454.z, arg0->unk_000.unk_01E.y + 0x4000);
    func_8000E8B0(&arg0->unk_000.unk_024, &sp3C);
}

void func_843095A4(UNUSED unk_D_84390010* arg0, unk_D_84390010* arg1, f32 arg2, f32 arg3, s32 arg4, s32 arg5) {
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    UNUSED s32 pad;
    Vec3f sp3C;
    UNUSED s32 pad2;
    f32 temp_fa1;
    f32 temp_fa2;
    f32 var_fa0;

    sp54 = arg1->unk_49C;
    sp50 = arg1->unk_498;
    sp4C = 20.0f;
    arg1->unk_498 = func_800104AC(sp50, arg2, arg3, arg3);

    var_fa0 = arg1->unk_498;
    if (arg2 <= var_fa0) {
        if (&arg1->unk_454) {}
        var_fa0 = 0.0f;
    }

    sp3C.z = COSS(arg4) * var_fa0;
    sp3C.y = SINS(arg4) * var_fa0;

    temp_fa1 = -sp54 * ((sp50 * arg1->unk_454.z) + sp3C.z);
    temp_fa2 = -sp4C - (sp54 * ((sp50 * arg1->unk_454.y) + sp3C.y));

    arg1->unk_454.z = (arg1->unk_454.z + sp3C.z + (temp_fa1 * 0.05f));
    arg1->unk_454.y = (arg1->unk_454.y + sp3C.y + (temp_fa2 * 0.05f));
    sp3C.y = arg1->unk_454.y;
    arg1->unk_454.x = 0.0f;

    func_8430C19C(&sp3C, arg1->unk_454.z, arg5);
    func_8000E8B0(&arg1->unk_4EC.unk_024, &sp3C);
}

void func_843096EC(unk_D_84390010* arg0) {
    s32 i;

    for (i = 0; i < 2; i++) {
        func_8000E88C(&arg0->unk_168[i].unk_000.unk_030, 1.0f, 1.0f, 1.0f);
        arg0->unk_168[i].unk_000.unk_000.unk_01 &= ~1;
        arg0->unk_168[i].unk_169 = 0;
    }
}

void func_84309780(unk_D_84390010* arg0) {
    s32 i;
    s16 sp64[] = { 0x0, 0xE38, 0xF1C8 }; // D_84384608

    for (i = 0; i < 2; i++) {
        arg0->unk_168[i].unk_16C = 0;
        arg0->unk_168[i].unk_16A = sp64[i];
        arg0->unk_168[i].unk_000.unk_01D = 0;
        arg0->unk_168[i].unk_000.unk_000.unk_01 |= 1;
        func_8430C1E4(&arg0->unk_168[i].unk_000.unk_024, &arg0->unk_000.unk_024);
        func_8430C204(&arg0->unk_168[i].unk_000.unk_01E, &arg0->unk_000.unk_01E);
        func_8430C1E4(&arg0->unk_168[i].unk_000.unk_030, &arg0->unk_000.unk_030);
    }
}

void func_84309874(unk_D_84390010* arg0) {
    s32 i;
    f32 tmp;
    Vec3f sp5C = { 0.0f, 0.0f, 0.0f };         // D_84384610
    f32 sp4C[] = { 0.3f, -0.4f, -0.2f, 0.4f }; // D_8438461C

    for (i = 0; i < 2; i++) {
        arg0->unk_168[i].unk_000.unk_01D = func_8001046C(arg0->unk_168[i].unk_000.unk_01D, 0x3C, 5, 5);
        arg0->unk_168[i].unk_16C = func_8001046C(arg0->unk_168[i].unk_16C, 0x38E, 0x64, 0x64);
        arg0->unk_168[i].unk_16C = func_8001046C(arg0->unk_168[i].unk_16C, 0x38E, 0x64, 0x64);
        arg0->unk_168[i].unk_16A += arg0->unk_168[i].unk_16C;

        tmp = SINS(arg0->unk_168[i].unk_16A) * (func_84308598(arg0) * sp4C[i]);
        func_8430C19C(&sp5C, tmp, arg0->unk_000.unk_01E.y);

        arg0->unk_168[i].unk_000.unk_024.x = arg0->unk_000.unk_024.x + sp5C.x;
        arg0->unk_168[i].unk_000.unk_024.y = arg0->unk_000.unk_024.y + sp5C.y;
        arg0->unk_168[i].unk_000.unk_024.z = arg0->unk_000.unk_024.z + sp5C.z;

        func_80017464(&arg0->unk_168[i].unk_000, arg0->unk_000.unk_040.unk_08 >> 0x10);
        func_8001BD04(&arg0->unk_168[i].unk_000, arg0->unk_000.unk_040.unk_00);
    }
}

void func_84309A24(unk_D_84390010* arg0) {
    s32 i;

    for (i = 0; i < 2; i++) {
        arg0->unk_168[i].unk_169 = 0;
        arg0->unk_168[i].unk_000.unk_01D = 0x3C;
        arg0->unk_168[i].unk_000.unk_000.unk_01 |= 1;
        func_8000E88C(&arg0->unk_168[i].unk_000.unk_030, 1.0f, 1.0f, 1.0f);
        func_8430C1E4(&arg0->unk_168[i].unk_000.unk_024, &arg0->unk_000.unk_024);
        func_8430C204(&arg0->unk_168[i].unk_000.unk_01E, &arg0->unk_000.unk_01E);
    }
}

s32 func_84309B0C(unk_D_84390010* arg0) {
    s32 i;
    f32 temp_fv0_2;
    f32 sp5C[] = { 0.007f, 0.005f, 0.039f }; // D_8438462C

    for (i = 0; i < 2; i++) {
        func_8430C1E4(&arg0->unk_168[i].unk_000.unk_024, &arg0->unk_000.unk_024);

        temp_fv0_2 = func_800104AC(arg0->unk_168[i].unk_000.unk_030.x, 0.8f, sp5C[i], sp5C[i]);
        arg0->unk_168[i].unk_000.unk_030.x = temp_fv0_2;
        arg0->unk_168[i].unk_000.unk_030.y = temp_fv0_2;
        arg0->unk_168[i].unk_000.unk_030.z = temp_fv0_2;

        func_80017464(&arg0->unk_168[i].unk_000, arg0->unk_000.unk_040.unk_08 >> 0x10);
        func_8001BD04(&arg0->unk_168[i].unk_000, arg0->unk_000.unk_040.unk_00);

        if (arg0->unk_168[i].unk_000.unk_030.y < 0.8) {
            arg0->unk_168[i].unk_169 = 1;
        }
    }

    return 0;
}

void func_84309C50(unk_D_84390010* arg0) {
    s32 i;

    for (i = 0; i < 2; i++) {
        arg0->unk_168[i].unk_169 = 0;
        arg0->unk_168[i].unk_000.unk_01D = 0x41 - i * 4;
        arg0->unk_168[i].unk_000.unk_000.unk_01 |= 1;

        func_80017464(&arg0->unk_168[i].unk_000, arg0->unk_000.unk_040.unk_08 >> 0x10);
        func_8001BD04(&arg0->unk_168[i].unk_000, arg0->unk_000.unk_040.unk_00);
        func_8000E88C(&arg0->unk_168[i].unk_000.unk_030, 1.0f, 1.0f, 1.0f);
        func_8430C1E4(&arg0->unk_168[i].unk_000.unk_024, &arg0->unk_000.unk_024);
        func_8430C204(&arg0->unk_168[i].unk_000.unk_01E, &arg0->unk_000.unk_01E);
        func_8430C1E4(&arg0->unk_168[i].unk_000.unk_030, &arg0->unk_000.unk_030);
    }
}

void func_84309D78(unk_D_84390010* arg0, s16 arg1) {
    s32 i;
    f32 sp90;
    s16 sp8E;
    s16 sp8C;
    UNUSED s32 pad;
    f32 sp7C[3] = { 0.2f, 0.25f, 0.3f };   // D_84384638
    f32 sp70[3] = { 0.98f, 0.96f, 0.95f }; // D_84384644

    for (i = 0; i < 2; i++) {
        func_80017464(&arg0->unk_168[i].unk_000, arg0->unk_000.unk_040.unk_08 >> 0x10);
        func_8001BD04(&arg0->unk_168[i].unk_000, arg0->unk_000.unk_040.unk_00);
        func_800102A4(&arg0->unk_000.unk_024, &arg0->unk_168[i].unk_000.unk_024, &sp90, &sp8E, &sp8C);
        func_80010354(&arg0->unk_000.unk_024, &arg0->unk_168[i].unk_000.unk_024, sp7C[i] * sp90, sp8E, sp8C);
        func_8430C4F8(&arg0->unk_168[i].unk_000.unk_01E.y, arg0->unk_000.unk_01E.y, sp70[i] * arg1);
    }
}

void func_84309F0C(unk_D_84390010* arg0) {
    func_84308654(arg0, 0, 0);
}

void func_84309F30(UNUSED unk_D_84390010* arg0, unk_D_84390010* arg1) {
    arg1->unk_4EC.unk_000.unk_01 |= 1;
    if (arg1 == D_84390010[0]) {
        func_8000E88C(&arg1->unk_4EC.unk_024, 35.0f, 50.0f, -250.0f);
    } else {
        func_8000E88C(&arg1->unk_4EC.unk_024, -35.0f, 50.0f, -250.0f);
    }
    func_843093F0(arg1, 20.0f, 0x1FFE);
    arg1->unk_4B8++;
    arg1->unk_4EC.unk_000.unk_02 &= ~0x20;
    func_80017464(&arg1->unk_4EC, 0);
}

void func_84309FD4(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    if (arg1 == D_84390018) {
        func_843095A4(arg0, arg1, 0, 0, 0x1FFE, 0x4440);
    } else {
        func_843095A4(arg0, arg1, 0, 0, 0x1FFE, 0x3BB8);
    }

    arg1->unk_4EC.unk_01E.x += 0x1555;
    arg1->unk_4EC.unk_01E.z += 0xE38;

    if (arg1->unk_4EC.unk_024.y < 0) {
        arg1->unk_4EC.unk_000.unk_01 &= ~1;
        arg1->unk_4EC.unk_024.y = 0.0f;
        arg1->unk_454.y = 0.0f;
        func_84309F0C(arg1);
    }
}

void func_8430A090(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    switch (arg1->unk_4B8) {
        case 0:
            func_84309F30(arg0, arg1);

        case 1:
            func_84309FD4(arg0, arg1);
            break;
    }
}

void func_8430A0E4(UNUSED unk_D_84390010* arg0, unk_D_84390010* arg1) {
    func_8000E88C(&arg1->unk_4EC.unk_024, arg1->unk_4B0 * -150.0f, 100.0f, 0.0f);
    arg1->unk_4B8++;
    func_843093F0(arg1, 0.0f, 0x3FFC);
    arg1->unk_4EC.unk_000.unk_01 |= 1;
    arg1->unk_4EC.unk_000.unk_02 &= ~0x20;
    func_80017464(&arg1->unk_4EC, 0);
}

void func_8430A17C(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    arg1->unk_4EC.unk_01E.x += 0x1555;
    arg1->unk_4EC.unk_01E.z += 0xE38;

    func_843095A4(arg0, arg1, 0.0f, 0.0f, 0x4000, 0);

    if (arg1->unk_4EC.unk_024.y < 0) {
        arg1->unk_4EC.unk_01E.x = 0;
        arg1->unk_4EC.unk_01E.z = 0;
        if (arg1 == D_84390018) {
            arg1->unk_4EC.unk_01E.y = 0x4000;
        } else {
            arg1->unk_4EC.unk_01E.y = -0x4000;
        }
        arg1->unk_454.y = 0.0f;
        arg1->unk_4EC.unk_024.y = 2.5f;
        func_84309F0C(arg1);
    }
}

void func_8430A22C(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    switch (arg1->unk_4B8) {
        case 0:
            func_8430A0E4(arg0, arg1);

        case 1:
            func_8430A17C(arg0, arg1);
            break;
    }
}

void func_8430A280(UNUSED unk_D_84390010* arg0, unk_D_84390010* arg1) {
    func_8000E88C(&arg1->unk_448, 0.0f, 0.0f, 0.0f);
    func_8000E88C(&arg1->unk_454, 0.0f, 0.0f, 0.0f);
    func_843093F0(arg1, D_84384600[0], 0x4000);
    func_84309C50(arg1);
    arg1->unk_4B8++;
}

void func_8430A308(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    func_84309448(arg0, arg1, 1.45f, 0.015f, 0x4000);
    func_84309D78(arg1, 0);
    if (arg0->unk_000.unk_024.y >= 200.0f) {
        arg1->unk_454.y = 0.0f;
        func_84309F0C(arg1);
        func_843096EC(arg1);
    }
}

void func_8430A390(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    switch (arg1->unk_4B8) {
        case 0:
            func_8430A280(arg0, arg1);

        case 1:
            func_8430A308(arg0, arg1);
            break;
    }
}

void func_8430A3E4(UNUSED unk_D_84390010* arg0, unk_D_84390010* arg1) {
    func_8000E88C(&arg1->unk_448, 0.0f, 0.0f, 0.0f);
    func_8000E88C(&arg1->unk_454, 0.0f, 0.0f, 0.0f);
    func_843093F0(arg1, D_84384600[0], 0x4000);
    arg1->unk_4B8++;
}

void func_8430A464(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    func_84309448(arg0, arg1, 2.0f, 0.002f, 0x4000);
    if ((arg0->unk_000.unk_024.y - func_84307BAC(arg1)) >= 90.0f) {
        arg1->unk_4B8++;
        arg1->unk_454.y = 0.0f;
    }
}

void func_8430A4E0(UNUSED unk_D_84390010* arg0, UNUSED unk_D_84390010* arg1) {
}

void func_8430A4EC(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    switch (arg1->unk_4B8) {
        case 0:
            func_8430A3E4(arg0, arg1);

        case 1:
            func_8430A464(arg0, arg1);
            break;

        case 2:
            func_8430A4E0(arg0, arg1);
            break;
    }
}

s32 func_8430A558(unk_D_84390010* arg0, s16 arg1, s16 arg2) {
    arg0->unk_000.unk_01E.y -= arg1;

    if (arg1 > 0) {
        if ((arg2 >= arg0->unk_000.unk_01E.y) && ((arg2 - arg1) < arg0->unk_000.unk_01E.y)) {
            return 1;
        }
    } else if ((arg0->unk_000.unk_01E.y >= arg2) && (arg0->unk_000.unk_01E.y < (arg2 - arg1))) {
        return 1;
    }

    return 0;
}

void func_8430A5D4(UNUSED unk_D_84390010* arg0, unk_D_84390010* arg1) {
    func_84309C50(arg1);
    arg1->unk_4A6 = 0;
    arg1->unk_4A4 = 0;
    arg1->unk_4C0 = 0;
    arg1->unk_4B8++;
}

void func_8430A618(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    arg1->unk_4A6 = func_8001046C(arg1->unk_4A6, 0x3330, 0x16C, 0x16C);

    if (func_8430A558(arg0, arg1->unk_4A6, arg1->unk_4B0 << 0xE) != 0) {
        arg1->unk_4C0 += 1;
    }

    func_84309D78(arg1, arg1->unk_4A6);

    if (arg1->unk_4C0 == 3) {
        arg1->unk_4B8 += 1;
    }
}

void func_8430A6AC(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    f32 tmp = 0x4000 - arg0->unk_000.unk_01E.y;
    f32 var_fa1;
    s16 sp26;
    s32 sp20;

    var_fa1 = (131072.0 - tmp) / 131072.0;
    if (var_fa1 >= 1.0f) {
        var_fa1 -= 1.0f;
    }

    sp26 = (arg1->unk_4A6 * var_fa1) * 0.8;
    if (sp26 < 0xE38) {
        sp26 = 0xE38;
    }
    sp20 = func_8430A558(arg0, sp26, arg1->unk_4B0 << 0xE);
    func_84309D78(arg1, sp26);

    if (sp20 != 0) {
        arg0->unk_000.unk_01E.y = arg1->unk_4B0 << 0xE;
        func_84309F0C(arg1);
        func_843096EC(arg1);
    }
}

void func_8430A7BC(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    switch (arg1->unk_4B8) {
        case 0:
            func_8430A5D4(arg0, arg1);

        case 1:
            func_8430A618(arg0, arg1);
            break;

        case 2:
            func_8430A6AC(arg0, arg1);
            break;
    }
}

void func_8430A828(UNUSED unk_D_84390010* arg0, unk_D_84390010* arg1) {
    arg1->unk_4A6 = 0;
    arg1->unk_4A4 = 0;
    arg1->unk_4C0 = 0;
    arg1->unk_4B8++;
}

void func_8430A848(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    arg1->unk_4A6 = func_8001046C(arg1->unk_4A6, 0x3FFC, 0x16C, 0x16C);

    if (func_8430A558(arg0, arg1->unk_4A6, arg1->unk_4B0 << 0xE) != 0) {
        arg1->unk_4C0 += 1;
    }

    if (arg1->unk_4C0 >= 3) {
        func_84309C50(arg1);
        arg1->unk_4B8 += 1;
    }
}

void func_8430A8DC(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    UNUSED s16 pad;
    u8 sp28[] = { 0x5F, 0x92 }; // D_84384650

    func_8430A558(arg0, arg1->unk_4A6, arg1->unk_4B0 << 0xE);

    if (func_84307AE0(arg1->unk_000.unk_01A, sp28, sizeof(sp28)) != 0) {
        sp30 = 10.3f;
        sp34 = 10.0f;
        sp2C = 0.035f;
    } else {
        sp30 = 3.8f;
        sp34 = 3.5f;
        sp2C = 0.045f;
    }

    func_84309D78(arg1, arg1->unk_4A6);
    func_8430C718(&arg0->unk_000.unk_024.y, -(func_84308548(arg1) * sp30), sp2C);

    if (arg0->unk_000.unk_024.y <= -(func_84308548(arg1) * sp34)) {
        func_8000EB70(&arg0->unk_000.unk_01E, 0, arg1->unk_4B0 << 0xE, 0);
        func_84309F0C(arg1);
        func_843096EC(arg1);
    }
}

void func_8430AA18(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    switch (arg1->unk_4B8) {
        case 0:
            func_8430A828(arg0, arg1);

        case 1:
            func_8430A848(arg0, arg1);
            break;

        case 2:
            func_8430A8DC(arg0, arg1);
            break;
    }
}

void func_8430AA84(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    arg1->unk_4A6 = 0;
    arg1->unk_4A4 = 0;
    arg1->unk_4C0 = 0;
    arg1->unk_4A0 = 0.0f;
    func_84307C5C(arg1);
    func_8000EB70(&arg0->unk_000.unk_01E, 0, arg1->unk_4B0 << 0xE, 0);
    func_84309C50(arg1);
    arg1->unk_4B8++;
}

void func_8430AB00(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    f32 tmp;
    Vec3f sp20 = { 0.0f, 0.0f, 0.0f }; // D_84384654

    func_8430C718(&arg1->unk_4A0, 50.0f, 0.1f);
    arg1->unk_4A6 += 0xE38;
    tmp = SINS(arg1->unk_4A6) * arg1->unk_4A0;
    func_8430C19C(&sp20, tmp, arg0->unk_000.unk_01E.y);
    func_84307C5C(arg1);
    func_8000E8B0(&arg0->unk_000.unk_024, &sp20);
    func_84309D78(arg1, 0);

    if (arg1->unk_4A0 > 49.0f) {
        arg1->unk_4B8++;
    }
}

void func_8430ABF0(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    f32 tmp;
    Vec3f sp20 = { 0.0f, 0.0f, 0.0f };

    func_8430C718(&arg1->unk_4A0, 0.0f, 0.1f);
    arg1->unk_4A6 += 0xE38;

    tmp = SINS(arg1->unk_4A6) * arg1->unk_4A0;
    func_8430C19C(&sp20, tmp, arg0->unk_000.unk_01E.y);

    func_84307C5C(arg1);
    func_8000E8B0(&arg0->unk_000.unk_024, &sp20);
    func_84309D78(arg1, 0);

    if (arg1->unk_4A0 <= 0.5f) {
        func_84307C5C(arg1);
        func_8000EB70(&arg0->unk_000.unk_01E, 0, arg1->unk_4B0 << 0xE, 0);
        func_84309F0C(arg1);
        func_843096EC(arg1);
    }
}

void func_8430AD10(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    switch (arg1->unk_4B8) {
        case 0:
            func_8430AA84(arg0, arg1);

        case 1:
            func_8430AB00(arg0, arg1);
            break;

        case 2:
            func_8430ABF0(arg0, arg1);
            break;
    }
}

void func_8430AD7C(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    func_84309780(arg1);
    arg1->unk_4AC = 0;
    func_84307C5C(arg1);
    func_8000EB70(&arg0->unk_000.unk_01E, 0, arg1->unk_4B0 << 0xE, 0);
    arg1->unk_4B8++;
}

void func_8430ADE8(UNUSED unk_D_84390010* arg0, unk_D_84390010* arg1) {
    func_84309874(arg1);
    arg1->unk_4AC++;
    if (arg1->unk_4AC == 0x3C) {
        func_84309F0C(arg1);
        func_843096EC(arg1);
    }
}

void func_8430AE3C(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    switch (arg1->unk_4B8) {
        case 0:
            func_8430AD7C(arg0, arg1);

        case 1:
            func_8430ADE8(arg0, arg1);
            break;
    }
}

void func_8430AE90(unk_D_84390010* arg0) {
    UNUSED s32 pad;
    unk_D_84390240_000_0DC* sp18 = D_84390240.unk_00->unk_DC;

    func_84307C5C(arg0);
    func_8000EB70(&arg0->unk_000.unk_01E, 0, arg0->unk_4B0 << 0xE, 0);
    func_8000E88C(&sp18->unk_C0, 0.0f, 1.0f, 0.0f);
    func_84309F0C(arg0);
}

void func_8430AF08(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    arg1->unk_4A6 = 0;
    arg1->unk_4A8 = 0;
    arg1->unk_4A4 = 0;
    arg1->unk_4C0 = 0;
    arg1->unk_4A0 = 0.0f;
    func_84307C5C(arg1);
    func_8000EB70(&arg0->unk_000.unk_01E, 0, arg1->unk_4B0 << 0xE, 0);
    arg1->unk_4B8++;
}

void func_8430AF80(UNUSED unk_D_84390010* arg0, unk_D_84390010* arg1) {
    unk_D_84390240_000_0DC* temp_s0 = D_84390240.unk_00->unk_DC;
    f32 temp_fa0;
    f32 temp_fa1_2;
    f32 temp_ft4;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 temp_fv0_2;
    f32 temp_fv1_2;

    func_8430C4F8(&arg1->unk_4A4, 0x5B0, 0x3C);
    func_8430C4F8(&arg1->unk_4A8, -0x8000, arg1->unk_4A4);

    sp2C = temp_s0->unk_B4.x - temp_s0->unk_A8.x;
    sp28 = temp_s0->unk_B4.y - temp_s0->unk_A8.y;
    sp24 = temp_s0->unk_B4.z - temp_s0->unk_A8.z;

    temp_fv0_2 = sqrtf(SQ(sp2C) + SQ(sp28) + SQ(sp24));

    temp_fa0 = sp2C / temp_fv0_2;
    temp_fv1_2 = sp28 / temp_fv0_2;
    temp_fa1_2 = sp24 / temp_fv0_2;

    temp_ft4 = 1.0 - COSS(arg1->unk_4A8);

    temp_s0->unk_C0.x = (temp_ft4 * temp_fa0 * temp_fv1_2) - (SINS(arg1->unk_4A8) * temp_fa1_2);
    temp_s0->unk_C0.y = COSS(arg1->unk_4A8) + ((temp_ft4 * temp_fv1_2) * temp_fv1_2);
    temp_s0->unk_C0.z = (SINS(arg1->unk_4A8) * temp_fa0) + ((temp_ft4 * temp_fv1_2) * temp_fa1_2);

    if (arg1->unk_000.unk_024.y < 0.0f) {
        arg1->unk_000.unk_024.y = 0.0f;
    }
}

void func_8430B104(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    switch (arg1->unk_4B8) {
        case 0:
            func_8430AF08(arg0, arg1);

        case 1:
            func_8430AF80(arg0, arg1);
            break;
    }
}

void func_8430B158(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    if (arg0->unk_000.unk_030.y != 1.0f) {
        func_84309F0C(arg1);
    } else {
        func_84309A24(arg1);
        arg1->unk_4B8++;
    }
}

void func_8430B1B8(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    f32 temp_fv0;

    temp_fv0 = func_800104AC(arg0->unk_000.unk_030.x, 0.8f, 0.01f, 0.01f);
    arg0->unk_000.unk_030.x = temp_fv0;
    arg0->unk_000.unk_030.y = temp_fv0;
    arg0->unk_000.unk_030.z = temp_fv0;

    func_84309B0C(arg1);

    if (arg0->unk_000.unk_030.y <= 0.8) {
        func_84309F0C(arg1);
        func_843096EC(arg1);
    }
}

void func_8430B244(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    switch (arg1->unk_4B8) {
        case 0:
            func_8430B158(arg0, arg1);

        case 1:
            func_8430B1B8(arg0, arg1);
            break;
    }
}

void func_8430B298(UNUSED unk_D_84390010* arg0, unk_D_84390010* arg1) {
    arg1->unk_4B8++;
}

void func_8430B2AC(unk_D_84390010* arg0, UNUSED unk_D_84390010* arg1) {
    arg0->unk_000.unk_030.x = func_800104AC(arg0->unk_000.unk_030.x, 0.0f, 0.05f, 0.05f);
    arg0->unk_000.unk_030.y = func_800104AC(arg0->unk_000.unk_030.y, 0.0f, 0.05f, 0.05f);
    arg0->unk_000.unk_030.z = func_800104AC(arg0->unk_000.unk_030.z, 0.0f, 0.05f, 0.05f);

    if (arg0->unk_000.unk_030.y <= 0.1) {
        func_8000E88C(&arg0->unk_000.unk_030, 0.001f, 0.001f, 0.001f);
    }
}

void func_8430B374(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    switch (arg1->unk_4B8) {
        case 0:
            func_8430B298(arg0, arg1);

        case 1:
            func_8430B2AC(arg0, arg1);
            break;
    }
}

void func_8430B3C8(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    arg1->unk_4A4 = 0x16C;
    arg1->unk_4A6 = 0;
    arg1->unk_4A8 = 0;
    arg1->unk_4A0 = 0.4f;
    arg1->unk_454.x = arg0->unk_000.unk_030.x;
    arg1->unk_454.y = arg0->unk_000.unk_030.y;
    arg1->unk_454.z = arg0->unk_000.unk_030.z;
    arg1->unk_4B8++;
}

void func_8430B40C(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    f32 var_fv0;

    // clang-format off
    if ((arg1->unk_4A4 >= 0) && (arg1->unk_4A4 <= 0x8000)) { arg1->unk_4A4 += 0x2D; }
    // clang-format on

    arg1->unk_4A8 = SINS(arg1->unk_4A4) * 182.0f * 15.0f;

    if ((arg1->unk_4A6 >= 0) && (arg1->unk_4A6 <= 0x4000)) {
        arg1->unk_4A6 += arg1->unk_4A8;
    }

    if (arg1->unk_654.unk_38.unk_56 == 0) {
        var_fv0 = 1.0f;
    } else {
        var_fv0 = 0.8f;
    }

    arg0->unk_000.unk_030.x = var_fv0 - (SINS(arg1->unk_4A6) * arg1->unk_4A0);
    arg0->unk_000.unk_030.y = (SINS(arg1->unk_4A6) * arg1->unk_4A0) + var_fv0;
    arg0->unk_000.unk_030.z = var_fv0 - (SINS(arg1->unk_4A6) * arg1->unk_4A0);

    if ((arg1->unk_4A6 >= 0x4000) && (arg1->unk_4A6 >= 0x4000)) {
        arg1->unk_4A8 = 0x1554;
        arg1->unk_4B8++;
    }
}

void func_8430B550(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    f32 var_fv0;
    f32 var_fv1;

    arg1->unk_4A6 += arg1->unk_4A8;
    var_fv1 = SINS(arg1->unk_4A6) * arg1->unk_4A0;
    if (var_fv1 <= 0.01f) {
        arg1->unk_4A8 += 0x444;
        arg1->unk_4A0 *= 0.8f;
        if (1) {}
        var_fv1 = SINS(arg1->unk_4A6) * arg1->unk_4A0;
    }

    if (arg1->unk_654.unk_38.unk_56 == 0) {
        var_fv0 = 1.0f;
    } else {
        var_fv0 = 0.8f;
    }

    arg0->unk_000.unk_030.x = var_fv0 - var_fv1;
    arg0->unk_000.unk_030.y = (SINS(arg1->unk_4A6) * arg1->unk_4A0) + var_fv0;
    arg0->unk_000.unk_030.z = var_fv0 - (SINS(arg1->unk_4A6) * arg1->unk_4A0);

    if (arg1->unk_4A0 <= 0.01f) {
        arg0->unk_000.unk_030.x = var_fv0;
        arg0->unk_000.unk_030.y = var_fv0;
        arg0->unk_000.unk_030.z = var_fv0;
        func_84309F0C(arg1);
    }
}

void func_8430B68C(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    switch (arg1->unk_4B8) {
        case 0:
            func_8430B3C8(arg0, arg1);

        case 1:
            func_8430B40C(arg0, arg1);
            break;

        case 2:
            func_8430B550(arg0, arg1);
            break;
    }
}

void func_8430B6F8(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    arg1->unk_4A8 = 0x71C;
    arg1->unk_4A0 = 0.4f;
    arg1->unk_454.x = arg0->unk_000.unk_030.x;
    arg1->unk_454.y = arg0->unk_000.unk_030.y;
    arg1->unk_454.z = arg0->unk_000.unk_030.z;
    arg1->unk_4B8++;
}

void func_8430B734(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    unk_D_84390010_654_038* temp_a0 = &arg1->unk_654.unk_38;
    s16 sp22;

    arg1->unk_4A8 += 0xCCC;
    sp22 = arg1->unk_4A8;

    arg1->unk_4A0 = func_800104AC(arg1->unk_4A0, 0.0f, 0.02f, 0.02f);

    if (sp22 > 0) {
        sp22 *= -1;
    }

    if (temp_a0->unk_56 == 0) {
        arg0->unk_000.unk_030.x = 1.0f - (SINS(sp22) * arg1->unk_4A0);
        arg0->unk_000.unk_030.y = (SINS(sp22) * arg1->unk_4A0) + 1.0f;
        arg0->unk_000.unk_030.z = 1.0f - (SINS(sp22) * arg1->unk_4A0);
    } else {
        arg0->unk_000.unk_030.x = 0.8 - (SINS(sp22) * arg1->unk_4A0);
        arg0->unk_000.unk_030.y = (SINS(sp22) * arg1->unk_4A0) + 0.8;
        arg0->unk_000.unk_030.z = 0.8 - (SINS(sp22) * arg1->unk_4A0);
    }

    if (arg1->unk_4A0 <= 0.01f) {
        if (temp_a0->unk_56 == 0) {
            func_8000E88C(&arg0->unk_000.unk_030, 1.0f, 1.0f, 1.0f);
        } else {
            func_8000E88C(&arg0->unk_000.unk_030, 0.8f, 0.8f, 0.8f);
        }
        func_84309F0C(arg1);
    }
}

void func_8430B8FC(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    switch (arg1->unk_4B8) {
        case 0:
            func_8430B6F8(arg0, arg1);

        case 1:
            func_8430B734(arg0, arg1);
            break;
    }
}

void func_8430B950(UNUSED unk_D_84390010* arg0, unk_D_84390010* arg1) {
    arg1->unk_4AC = 0;
    arg1->unk_4B8++;
}

void func_8430B968(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    unk_D_84390010_654_038* ptr = &arg1->unk_654.unk_38;
    UNUSED s32 pad;
    f32 temp_fs0;

    if (ptr->unk_56 == 0) {
        temp_fs0 = (1.0f - func_8435FCD0()) * 0.6f;
        func_8430C718(&arg0->unk_000.unk_030.x, 1.0f - temp_fs0, 0.5f);
        func_8430C718(&arg0->unk_000.unk_030.y, 1.0f + temp_fs0, 0.5f);
        func_8430C718(&arg0->unk_000.unk_030.z, 1.0f - temp_fs0, 0.5f);
    } else {
        temp_fs0 = (1.0f - func_8435FCD0()) * 0.3f;
        func_8430C718(&arg0->unk_000.unk_030.x, 0.8 - temp_fs0, 0.5f);
        func_8430C718(&arg0->unk_000.unk_030.y, temp_fs0 + 0.8, 0.5f);
        func_8430C718(&arg0->unk_000.unk_030.z, 0.8 - temp_fs0, 0.5f);
    }
}

void func_8430BAB8(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    switch (arg1->unk_4B8) {
        case 0:
            func_8430B950(arg0, arg1);

        case 1:
            func_8430B968(arg0, arg1);
            break;
    }
}

void func_8430BB0C(UNUSED unk_D_84390010* arg0, unk_D_84390010* arg1) {
    arg1->unk_4C0 = 0;
    arg1->unk_4B8++;
}

void func_8430BB24(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    f32 sp24;
    f32 sp20;

    arg1->unk_4C0++;
    sp20 = func_8435E158(arg0->unk_000.unk_024.x, arg0->unk_000.unk_024.z, &sp24);
    arg0->unk_000.unk_024.y = func_84307BAC(arg1) + sp20;
    arg0->unk_000.unk_01E.x = (s16)sp24 * 0xB6;

    if (arg1->unk_4C0 == 0x12C) {
        arg0->unk_000.unk_024.y = func_84307BAC(arg1);
        arg0->unk_000.unk_01E.x = 0;
        func_84309F0C(arg1);
    }
}

void func_8430BBE4(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    switch (arg1->unk_4B8) {
        case 0:
            func_8430BB0C(arg0, arg1);

        case 1:
            func_8430BB24(arg0, arg1);
            break;
    }
}

void func_8430BC38(UNUSED unk_D_84390010* arg0, UNUSED unk_D_84390010* arg1) {
}

void func_8430BC44(s32 arg0) {
    unk_D_84390010* temp_a1 = D_84390010[arg0];
    unk_D_84390010* temp_a2 = D_84390010[arg0];

    switch (D_84390010[arg0]->unk_4B4) {
        case 0:
            func_8430BC38(temp_a1, temp_a2);
            break;

        case 1:
            func_8430A090(temp_a1, temp_a2);
            break;

        case 2:
            func_8430A22C(temp_a1, temp_a2);
            break;

        case 3:
            func_8430A390(temp_a1, temp_a2);
            break;

        case 4:
            func_8430A7BC(temp_a1, temp_a2);
            break;

        case 5:
            func_8430AA18(temp_a1, temp_a2);
            break;

        case 6:
            func_8430AD10(temp_a1, temp_a2);
            break;

        case 7:
            func_8430AE3C(temp_a1, temp_a2);
            break;

        case 8:
            func_8430B104(temp_a1, temp_a2);
            break;

        case 9:
            func_8430B244(temp_a1, temp_a2);
            break;

        case 10:
            func_8430BBE4(temp_a1, temp_a2);
            break;

        case 12:
            func_8430B374(temp_a1, temp_a2);
            break;

        case 13:
            func_8430B68C(temp_a1, temp_a2);
            break;

        case 14:
            func_8430A4EC(temp_a1, temp_a2);
            break;

        case 15:
            func_8430B8FC(temp_a1, temp_a2);
            break;

        case 16:
            func_8430BAB8(temp_a1, temp_a2);
            break;

        default:
            func_84309F0C(temp_a2);
            break;
    }
}

void func_8430BD9C(unk_D_84390010* arg0, u8 arg1, u8 arg2) {
    arg0->unk_4E8 = arg1;
    arg0->unk_4E9 = arg2;
}

void func_8430BDB0(unk_D_84390010* arg0) {
    arg0->unk_4E8 = 0;
    arg0->unk_4E9 = 0;
}

void func_8430BDBC(unk_D_84390010* arg0, f32 arg1, s16 arg2) {
    arg0->unk_4E4 = arg1;
    arg0->unk_4D8.z = COSS(arg2) * arg1;
    arg0->unk_4D8.y = SINS(arg2) * arg1;
}

void func_8430BE08(unk_D_84390010* arg0, unk_D_84390010* arg1, UNUSED f32 arg2, UNUSED f32 arg3, UNUSED s32 arg4) {
    f32 tmp1 = 0.01f;
    f32 tmp2 = 18.0f;
    Vec3f sp2C;
    f32 temp_fa1;
    f32 temp_fa2;

    temp_fa1 = -tmp1 * arg1->unk_4D8.z;
    temp_fa2 = -tmp2 - (tmp1 * arg1->unk_4D8.y);

    arg1->unk_4D8.z = arg1->unk_4D8.z + (temp_fa1 * 0.05f);
    arg1->unk_4D8.y = arg1->unk_4D8.y + (temp_fa2 * 0.05f);
    sp2C.y = arg1->unk_4D8.y;
    arg1->unk_4D8.x = 0.0f;

    func_8430C19C(&sp2C, arg1->unk_4D8.z, arg0->unk_000.unk_01E.y + 0x4000);
    func_8000E8B0(&arg0->unk_000.unk_024, &sp2C);
}

void func_8430BEC0(UNUSED unk_D_84390010* arg0, unk_D_84390010* arg1) {
    func_8000E88C(&arg1->unk_4CC, 0.0f, 0.0f, 0.0f);
    func_8000E88C(&arg1->unk_4D8, 0.0f, 0.0f, 0.0f);
    func_8430BDBC(arg1, 23.0f, 0x2E36);
    arg1->unk_4E9++;
}

void func_8430BF3C(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    func_8430BE08(arg0, arg1, 0, 0, 0x2E36);
    if (arg1->unk_000.unk_024.y < func_84307BAC(arg1)) {
        arg1->unk_4D8.y = 0.0f;
        arg1->unk_000.unk_024.y = func_84307BAC(arg1);
        func_8430BDB0(arg1);
    }
}

void func_8430BFB0(unk_D_84390010* arg0, unk_D_84390010* arg1) {
    switch (arg1->unk_4E9) {
        case 0:
            func_8430BEC0(arg0, arg1);

        case 1:
            func_8430BF3C(arg0, arg1);
            break;
    }
}

void func_8430C004(UNUSED unk_D_84390010* arg0, UNUSED unk_D_84390010* arg1) {
}

void func_8430C010(s32 arg0) {
    unk_D_84390010* temp_v0 = D_84390010[arg0];
    unk_D_84390010* temp_v1 = D_84390010[arg0];

    if (temp_v1->unk_4E8 == 0xB) {
        func_8430BFB0(temp_v0, temp_v1);
    } else {
        func_8430C004(temp_v0, temp_v1);
    }
}

static s32 pad_D_8438466C = 0;

s16 D_84384670[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0,    0, 0xA9, 0, 0, 0, 0, 0, 0xAA, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0,    0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0,    0, 0,    0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0,    0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0xAB, 0,    0, 0,    0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0xAC, 0, 0, 0, 0, 0, 0,    0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0,    0, 0,    0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0xAD, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0xAE, 0, 0,    0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0,    0, 0,
};

unk_D_843847BC D_843847BC[2] = {
    {
        0xFFB8,
        0x0048,
        0x0020,
        10.0f,
        10.0f,
        1280.0f,
        0x0001,
    },
    {
        0x015F,
        0x0080,
        0x0020,
        10.0f,
        10.0f,
        1280.0f,
        0xFFFF,
    },
};

unk_D_86B0C160 D_843847EC[] = {
    {
        0,
        0,
        0,
        0,
        14563,
        0.0f,
        4.5f,
        0,
        0,
        0,
        9102,
        0,
        0.0f,
        8.5f,
        0.10000000149011612f,
        0.019999999552965164f,
        30.0f,
    },
    {
        0,
        0,
        0,
        0,
        12743,
        0.0f,
        8.0f,
        0,
        0,
        0,
        0,
        0,
        0.0f,
        4.0f,
        0.15000000596046448f,
        0.009999999776482582f,
        30.0f,
    },
    {
        0,
        16384,
        0,
        0,
        7281,
        3.5f,
        3.0f,
        0,
        -16384,
        0,
        0,
        0,
        0.0f,
        3.0f,
        0.15000000596046448f,
        0.019999999552965164f,
        50.0f,
    },
};
unk_D_86B0C160 D_84384888[] = {
    {
        0,
        0,
        0,
        364,
        7281,
        0.0f,
        8.0f,
        0,
        0,
        0,
        364,
        0,
        1.0f,
        2.0f,
        0.30000001192092896f,
        0.009999999776482582f,
        70.0f,
    },
    {
        0,
        0,
        0,
        0,
        30030,
        0.0f,
        3.5f,
        0,
        0,
        0,
        1820,
        3640,
        0.0f,
        20.0f,
        0.15000000596046448f,
        0.009999999776482582f,
        50.0f,
    },
};

u32 D_843848F0[] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x15550000, 0x00000000, 0x40600000, 0x3E4CCCCD, 0x3D75C28F, 0x43480000,
};

u32 D_84384924[] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x000011C6,
    0x7C6A0000, 0x00000000, 0x40C00000, 0x3E4CCCCD, 0x3D23D70A, 0x43480000,
};

u32 D_84384958[] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000E38,
    0x80000000, 0x00000000, 0x40C00000, 0x3E4CCCCD, 0x3DA3D70A, 0x43480000,
};

u32 D_8438498C[] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x40600000, 0x3E4CCCCD, 0x3D75C28F, 0x43480000,
};

u32 D_843849C0[] = {
    0x00000000, 0x00000000, 0x38E30000, 0x3F800000, 0x40900000, 0x00000000, 0x0000238E, 0x00000000, 0x00000000,
    0x41080000, 0x3DCCCCCD, 0x3CA3D70A, 0x43480000, 0x00000000, 0x00002AAA, 0x00000000, 0x00000000, 0x41080000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x40800000, 0x3E800000, 0x3CA3D70A, 0x43480000, 0x00000000,
    0x00000000, 0x38E30000, 0x00000000, 0x40600000, 0x00000000, 0x0000238E, 0x1C710000, 0x00000000, 0x41080000,
    0x3E19999A, 0x3CA3D70A, 0x43480000, 0x00000000, 0x00000000, 0x38E30000, 0x00000000, 0x40D00000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x40800000, 0x3E4CCCCD, 0x3CA3D70A, 0x43480000, 0x00000000, 0x00001C71,
    0x40000000, 0x00000000, 0x40F00000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x40600000, 0x3E4CCCCD,
    0x3CA3D70A, 0x43480000, 0x00000000, 0x0000F8E4, 0x40000000, 0x00000000, 0x40900000, 0x00000000, 0x0000071C,
    0x00000000, 0x00000000, 0x40600000, 0x3E4CCCCD, 0x3CA3D70A, 0x43480000,
};

u32 D_84384AF8[] = {
    0x00000000, 0x00000888, 0x00000000, 0x00000000, 0x41280000, 0x00000000, 0x000000B6,
    0x00000000, 0x00000000, 0x40000000, 0x3E4CCCCD, 0x3C75C28F, 0x42480000,
};

u32 D_84384B2C[] = {
    0x00000000, 0x00002AAA, 0x00000000, 0x00000000, 0x44160000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x44098000, 0x3E4CCCCD, 0x3D23D70A, 0x42200000, 0x00000000, 0x00002AAA, 0x31C70000, 0x00000000, 0x441C4000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x43E10000, 0x3E4CCCCD, 0x3CF5C28F, 0x42200000, 0x00000000,
    0x0000FDDE, 0x00000000, 0x00000000, 0x43E10000, 0x00000000, 0x00002AAA, 0x00000000, 0x00000000, 0x43FA0000,
    0x3E4CCCCD, 0x3CCCCCCD, 0x42200000, 0x00000000, 0x00000000, 0xCE390000, 0x00000000, 0x443B8000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x43E10000, 0x3E4CCCCD, 0x3D23D70A, 0x42200000, 0x00000000, 0x0000FDDE,
    0x00000000, 0x00000000, 0x42480000, 0x00000000, 0x0000FDDE, 0x00000000, 0x00000000, 0x43C80000, 0x3E4CCCCD,
    0x3CF5C28F, 0x42A00000,
};

Vec3f D_84384C30[] = {
    { 0.17000000178813934f, 11.5f, -1.5f },
    { 0.10999999940395355f, 27.0f, -2.5f },
    { 0.12999999523162842f, 55.0f, 15.0f },
    { 0.2199999988079071f, 0.0f, -0.5f },
    { 0.1599999964237213f, 14.5f, 2.5f },
    { 0.3199999928474426f, 0.0f, 0.0f },
    { 0.20000000298023224f, 7.0f, 0.5f },
    { 0.20999999344348907f, 12.0f, -3.5f },
    { 0.23000000417232513f, -18.5f, 9.5f },
    { 0.4099999964237213f, -2.5f, -1.5f },
    { 0.1899999976158142f, 7.0f, 1.0f },
    { 0.2800000011920929f, 0.0f, 4.0f },
    { 0.2800000011920929f, 2.5f, 0.5f },
    { 0.23999999463558197f, -1.5f, -3.0f },
    { 0.2199999988079071f, 6.0f, 6.5f },
    { 0.6800000071525574f, -1.5f, -1.5f },
    { 0.800000011920929f, 0.0f, -3.5f },
    { 0.49000000953674316f, -0.5f, -55.0f },
    { 0.27000001072883606f, 2.5f, 2.5f },
    { 0.2800000011920929f, 0.0f, 0.0f },
    { 0.28999999165534973f, 4.0f, -2.5f },
    { 0.23999999463558197f, 0.0f, 2.5f },
    { 0.27000001072883606f, 0.0f, -6.0f },
    { 0.2800000011920929f, 7.5f, 17.5f },
    { 0.33000001311302185f, 0.0f, -3.0f },
    { 0.4000000059604645f, 0.0f, -6.0f },
    { 0.4000000059604645f, 0.0f, -7.0f },
    { 0.28999999165534973f, 0.0f, -5.5f },
    { 0.20999999344348907f, 5.5f, 5.0f },
    { 0.20999999344348907f, 6.5f, 0.0f },
    { 0.2199999988079071f, 11.0f, -7.5f },
    { 0.23999999463558197f, 8.5f, 3.0f },
    { 0.1599999964237213f, 17.5f, 0.0f },
    { 0.20999999344348907f, 14.0f, -6.5f },
    { 0.18000000715255737f, 0.0f, 3.0f },
    { 0.15000000596046448f, 9.0f, 9.0f },
    { 0.3100000023841858f, 0.0f, -2.5f },
    { 0.18000000715255737f, 0.0f, 4.5f },
    { 0.23000000417232513f, 0.0f, 0.0f },
    { 0.1899999976158142f, 0.0f, 15.0f },
    { 0.4099999964237213f, -2.0f, 0.0f },
    { 0.5400000214576721f, -34.5f, -43.5f },
    { 0.20999999344348907f, 0.0f, -2.0f },
    { 0.20999999344348907f, 0.0f, 0.0f },
    { 0.23999999463558197f, 0.0f, 14.0f },
    { 0.27000001072883606f, 0.0f, -2.5f },
    { 0.12999999523162842f, 8.5f, 2.5f },
    { 0.12999999523162842f, 14.0f, 11.5f },
    { 0.4000000059604645f, 0.0f, 0.0f },
    { 0.2199999988079071f, 0.0f, 0.0f },
    { 0.20000000298023224f, 0.0f, 0.0f },
    { 0.4000000059604645f, 0.0f, 0.0f },
    { 0.15000000596046448f, 19.5f, -2.5f },
    { 0.1599999964237213f, 3.5f, 3.5f },
    { 0.1899999976158142f, 10.5f, -8.0f },
    { 0.4000000059604645f, 0.0f, 0.0f },
    { 0.20999999344348907f, 0.0f, -5.5f },
    { 0.23999999463558197f, 3.5f, 1.5f },
    { 0.1899999976158142f, 21.5f, 6.0f },
    { 0.28999999165534973f, 0.0f, 0.0f },
    { 0.23000000417232513f, 0.0f, 0.0f },
    { 0.2199999988079071f, -4.5f, -0.5f },
    { 0.23000000417232513f, 4.0f, 0.0f },
    { 0.1899999976158142f, 16.0f, -2.5f },
    { 0.18000000715255737f, 14.0f, -4.0f },
    { 0.15000000596046448f, 11.0f, 0.0f },
    { 0.25f, 8.5f, -6.0f },
    { 0.25f, 10.0f, -4.0f },
    { 0.3700000047683716f, 0.0f, -5.0f },
    { 0.20000000298023224f, 0.0f, 0.0f },
    { 0.14000000059604645f, 17.5f, 16.5f },
    { 0.23999999463558197f, 0.0f, 0.0f },
    { 0.23999999463558197f, 0.0f, 0.0f },
    { 0.28999999165534973f, 0.0f, 0.0f },
    { 0.1899999976158142f, 0.0f, 0.0f },
    { 0.1899999976158142f, 11.0f, 0.0f },
    { 0.1599999964237213f, 8.0f, 0.0f },
    { 0.17000000178813934f, -7.5f, -7.0f },
    { 0.25999999046325684f, 12.5f, 5.0f },
    { 0.1899999976158142f, 0.0f, 2.5f },
    { 0.2800000011920929f, 0.0f, 0.0f },
    { 0.23000000417232513f, 0.0f, 0.0f },
    { 0.28999999165534973f, 0.0f, -3.0f },
    { 0.25f, 0.0f, 0.0f },
    { 0.23000000417232513f, 0.0f, 0.0f },
    { 0.25999999046325684f, 8.5f, 2.5f },
    { 0.23000000417232513f, 22.5f, 7.5f },
    { 0.25f, 0.0f, -2.5f },
    { 0.18000000715255737f, 0.0f, 5.0f },
    { 0.20000000298023224f, 0.0f, 2.0f },
    { 0.28999999165534973f, 0.0f, 0.0f },
    { 0.1599999964237213f, 0.0f, 0.0f },
    { 0.17000000178813934f, 5.0f, 0.0f },
    { 0.25999999046325684f, 0.0f, -10.5f },
    { 0.03999999910593033f, 74.0f, -7.5f },
    { 0.20999999344348907f, 7.5f, -1.0f },
    { 0.20000000298023224f, 0.0f, -0.5f },
    { 0.2199999988079071f, 0.0f, 0.0f },
    { 0.20000000298023224f, 0.0f, 9.5f },
    { 0.17000000178813934f, 0.0f, 0.0f },
    { 0.1899999976158142f, 0.0f, 0.0f },
    { 0.1899999976158142f, 0.0f, -3.5f },
    { 0.25f, 0.0f, 9.0f },
    { 0.2199999988079071f, 1.5f, -1.0f },
    { 0.23999999463558197f, -2.5f, -4.5f },
    { 0.23000000417232513f, -4.0f, 0.0f },
    { 0.23000000417232513f, 0.0f, 0.0f },
    { 0.27000001072883606f, 0.0f, 0.0f },
    { 0.17000000178813934f, 0.0f, 4.0f },
    { 0.20999999344348907f, -11.0f, 5.5f },
    { 0.17000000178813934f, 8.0f, 0.0f },
    { 0.2199999988079071f, 0.0f, 4.5f },
    { 0.1599999964237213f, 0.0f, 12.5f },
    { 0.15000000596046448f, 4.5f, 8.0f },
    { 0.28999999165534973f, 0.0f, 0.0f },
    { 0.25f, 0.0f, 5.0f },
    { 0.25f, 6.5f, 3.0f },
    { 0.3100000023841858f, 0.0f, 0.5f },
    { 0.23999999463558197f, 18.0f, 0.0f },
    { 0.1899999976158142f, 0.0f, 0.0f },
    { 0.14000000059604645f, 0.0f, 0.0f },
    { 0.23999999463558197f, 0.0f, 0.0f },
    { 0.23999999463558197f, 12.5f, 0.0f },
    { 0.18000000715255737f, 0.0f, 0.0f },
    { 0.18000000715255737f, 9.0f, 0.0f },
    { 0.20999999344348907f, 10.0f, -2.5f },
    { 0.20999999344348907f, 0.0f, 0.0f },
    { 0.1599999964237213f, 12.0f, 5.0f },
    { 0.4000000059604645f, -1.5f, 23.0f },
    { 0.14000000059604645f, 49.0f, 28.0f },
    { 0.20000000298023224f, 22.5f, 8.5f },
    { 0.25999999046325684f, 0.0f, 0.0f },
    { 0.2800000011920929f, 0.0f, 0.0f },
    { 0.25999999046325684f, 0.0f, 4.0f },
    { 0.25f, 11.0f, 0.0f },
    { 0.23000000417232513f, 8.0f, 0.0f },
    { 0.18000000715255737f, 5.5f, 4.5f },
    { 0.2199999988079071f, -0.5f, 2.5f },
    { 0.25f, 0.0f, 0.0f },
    { 0.25999999046325684f, 0.0f, -1.5f },
    { 0.20999999344348907f, 0.0f, 3.5f },
    { 0.1599999964237213f, 32.5f, 26.5f },
    { 0.05000000074505806f, -15.5f, -133.5f },
    { 0.27000001072883606f, 5.5f, -10.0f },
    { 0.4000000059604645f, 0.0f, 0.0f },
    { 0.2199999988079071f, 7.5f, -2.5f },
    { 0.3499999940395355f, 0.0f, 0.0f },
    { 0.23999999463558197f, -9.5f, 0.0f },
    { 0.1899999976158142f, 0.0f, 2.5f },
    { 0.25999999046325684f, 0.0f, -6.5f },
    { 0.30000001192092896f, 0.0f, 3.0f },
    { 0.3499999940395355f, -45.0f, -5.0f },
    { 0.4000000059604645f, 0.0f, 0.0f },
    { 0.4000000059604645f, 0.0f, 0.0f },
    { 0.4000000059604645f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f },
};
unk_D_84385384_func D_84385380 = func_843056DC;
unk_D_84385384 D_84385384[] = {
    {
        0,
        {
            func_843020B0,
            func_843056DC,
            func_843056DC,
            func_84301D08,
            func_84301DDC,
            func_84304C8C,
            func_84304D84,
        },
        167,
        5,
        255,
    },
    {
        1,
        {
            func_84303ECC,
            func_84305728,
            func_84301EEC,
            func_84304114,
            func_843056DC,
            func_843056DC,
            func_843056DC,
        },
        166,
        255,
        255,
    },
    {
        2,
        {
            func_843056DC,
            func_843020B0,
            func_843056DC,
            func_843045DC,
            func_843056DC,
            func_843056DC,
            func_843056DC,
        },
        255,
        2,
        255,
    },
    {
        3,
        {
            func_84302A78,
            func_843056DC,
            func_843056DC,
            func_84302C34,
            func_84302EF0,
            func_8430305C,
            func_843056DC,
        },
        255,
        255,
        255,
    },
    {
        4,
        {
            func_843037CC,
            func_843056DC,
            func_843056DC,
            func_84303A48,
            func_84303BB8,
            func_843056DC,
            func_843056DC,
        },
        255,
        255,
        255,
    },
    {
        5,
        {
            func_8430741C,
            func_8430203C,
            func_843056DC,
            func_84307424,
            func_8430742C,
            func_84307434,
            func_8430743C,
        },
        255,
        255,
        255,
    },
    {
        6,
        {
            func_8430741C,
            func_8430203C,
            func_843056DC,
            func_84307464,
            func_8430745C,
            func_84307454,
            func_8430744C,
        },
        255,
        255,
        255,
    },
    {
        7,
        {
            func_843020B0,
            func_843056DC,
            func_843056DC,
            func_84301D08,
            func_8430748C,
            func_84307444,
            func_84304D84,
        },
        167,
        5,
        255,
    },
    {
        8,
        {
            func_84304834,
            func_843056DC,
            func_843056DC,
            func_843048C8,
            func_843056DC,
            func_843056DC,
            func_843056DC,
        },
        255,
        255,
        255,
    },
    {
        9,
        {
            func_843049FC,
            func_84304ACC,
            func_843056DC,
            func_843056DC,
            func_843056DC,
            func_843056DC,
            func_843056DC,
        },
        255,
        255,
        255,
    },
    {
        10,
        {
            func_843056DC,
            func_843020B0,
            func_843056DC,
            func_843045DC,
            func_843029D0,
            func_843056DC,
            func_843056DC,
        },
        255,
        3,
        255,
    },
    {
        11,
        {
            func_8430506C,
            func_843056DC,
            func_843056DC,
            func_84303A48,
            func_843055E0,
            func_843054F0,
            func_843056DC,
        },
        255,
        255,
        255,
    },
    {
        12,
        {
            func_84301EEC,
            func_84304B50,
            func_843056DC,
            func_843056DC,
            func_843056DC,
            func_843056DC,
            func_843056DC,
        },
        255,
        255,
        255,
    },
    {
        13,
        {
            func_84304C20,
            func_843056DC,
            func_843056DC,
            func_843056DC,
            func_843056DC,
            func_843056DC,
            func_843056DC,
        },
        255,
        255,
        255,
    },
    {
        14,
        {
            func_8430506C,
            func_843056DC,
            func_843056DC,
            func_843052C0,
            func_843056DC,
            func_843056DC,
            func_843056DC,
        },
        255,
        255,
        255,
    },
    {
        15,
        {
            func_84303CB4,
            func_843056DC,
            func_843056DC,
            func_843056DC,
            func_843056DC,
            func_843056DC,
            func_843056DC,
        },
        255,
        255,
        255,
    },
    {
        16,
        {
            func_84303ECC,
            func_84305728,
            func_84301EEC,
            func_84304210,
            func_843056DC,
            func_843056DC,
            func_843056DC,
        },
        166,
        255,
        255,
    },
    {
        17,
        {
            func_843056DC,
            func_843056DC,
            func_843056DC,
            func_84301D08,
            func_84304F54,
            func_843056DC,
            func_843056DC,
        },
        177,
        255,
        255,
    },
    {
        18,
        {
            func_84303ECC,
            func_84305728,
            func_84301EEC,
            func_843043FC,
            func_843056DC,
            func_843056DC,
            func_843056DC,
        },
        166,
        255,
        255,
    },
    {
        19,
        {
            func_843033E0,
            func_843056DC,
            func_843056DC,
            func_843034D8,
            func_84303674,
            func_843056DC,
            func_843056DC,
        },
        255,
        255,
        255,
    },
    {
        20,
        {
            func_843056DC,
            func_843020B0,
            func_843056DC,
            func_843045DC,
            func_84304758,
            func_843056DC,
            func_843056DC,
        },
        255,
        1,
        255,
    },
    {
        21,
        {
            func_84303208,
            func_843056DC,
            func_843056DC,
            func_8430334C,
            func_843056DC,
            func_843056DC,
            func_843056DC,
        },
        255,
        255,
        255,
    },
};
