#include "fragment9.h"
#include "include/libc/math.h"
#include "src/12D80.h"
#include "src/18140.h"
#include "src/18480.h"
#include "src/19840.h"
#include "src/1C720.h"
#include "src/1CF30.h"
#include "src/20330.h"
#include "src/20470.h"
#include "src/30640.h"
#include "src/3FB0.h"
#include "src/6A40.h"
#include "src/6BC0.h"
#include "src/E890.h"
#include "src/controller.h"
#include "src/fragments/2/fragment2.h"
#include "src/fragments/4/fragment4.h"
#include "src/memory.h"
#include "src/stage_loader.h"

// プリンのらくがき
static char D_86301600[] = {
    0xA5, 0xD7, 0xA5, 0xEA, 0xA5, 0xF3, 0xA4, 0xCE, 0xA4, 0xE9,
    0xA4, 0xAF, 0xA4, 0xAC, 0xA4, 0xAD, 0x00, 0x00, 0x00, 0x00,
};

// ３Ｄスティックでジャンプして
static char D_86301614[] = {
    0xA3, 0xB3, 0xA3, 0xC4, 0xA5, 0xB9, 0xA5, 0xC6, 0xA5, 0xA3, 0xA5, 0xC3, 0xA5, 0xAF, 0xA4, 0xC7,
    0xA5, 0xB8, 0xA5, 0xE3, 0xA5, 0xF3, 0xA5, 0xD7, 0xA4, 0xB7, 0xA4, 0xC6, 0x00, 0x00, 0x00, 0x00,
};

// Ａボタンでらくがきしよう。
static char D_86301634[] = {
    0xA3, 0xC1, 0xA5, 0xDC, 0xA5, 0xBF, 0xA5, 0xF3, 0xA4, 0xC7, 0xA4, 0xE9, 0xA4, 0xAF,
    0xA4, 0xAC, 0xA4, 0xAD, 0xA4, 0xB7, 0xA4, 0xE8, 0xA4, 0xA6, 0xA1, 0xA3, 0x00, 0x00,
};

static u32 D_86301650[] = {
    0x0C00FFFF, 0x05000000, 0x0B00001E, 0x00000000, 0x014000F0, 0x0000000F, 0x00000000, 0x00000000, 0x05000000,
    0x0D000000, 0x05000000, 0x0F000002, 0x14000000, 0x002B0012, 0xFFFFFF32, 0x16FFFFFF, 0x0F000003, 0x05000000,
    0x0A000000, 0x800AC840, 0x06000000, 0x06000000, 0x06000000, 0x06000000, 0x01000000,
};

typedef struct unk_D_86301730 {
    /* 0x000 */ s16 unk_000;
    /* 0x002 */ s16 unk_002;
    /* 0x004 */ unk_D_86002F58_004_000 unk_004;
    /* 0x16C */ Vec3f unk_16C;
    /* 0x178 */ s8 unk_178;
    /* 0x179 */ s8 unk_179;
    /* 0x17A */ s8 unk_17A;
    /* 0x17B */ s8 unk_17B;
    /* 0x17C */ u16 unk_17C;
    /* 0x17E */ char pad17E[6];
} unk_D_86301730; // size = 0x184

static unk_D_86002F30* D_86301710;
static unk_D_86002F34* D_86301714;
static unk_D_86002F34_00C* D_86301718;
static s16 D_8630171C;
static s16 D_8630171E;
static s16 D_86301720;
static u16 D_86301722;
static s32 D_86301724;
static unk_D_800AC870* D_86301728;
static unk_D_86301730 D_86301730[4];
static u32 D_86301D40;
static unk_D_86301730* D_86301D44;
static unk_D_86002F58_004_000* D_86301D48;
static s16 D_86301D4C;
static s16 D_86301D4E;
static s16 D_86301D50[4];
static unk_D_86002F58_004_000 D_86301D58;

void func_86300020(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_86301730[i].unk_17A = D_86301730[i].unk_178;
        D_86301730[i].unk_17B = D_86301730[i].unk_179;
    }

    D_86301730[0].unk_17C = D_80068BA0->unk_08;
    D_86301730[0].unk_178 = D_80068BA0->unk_02;
    D_86301730[0].unk_179 = D_80068BA0->unk_04;

    D_86301730[1].unk_17C = D_80068BA4->unk_08;
    D_86301730[1].unk_178 = D_80068BA4->unk_02;
    D_86301730[1].unk_179 = D_80068BA4->unk_04;

    D_86301730[2].unk_17C = D_80068BA8->unk_08;
    D_86301730[2].unk_178 = D_80068BA8->unk_02;
    D_86301730[2].unk_179 = D_80068BA8->unk_04;

    D_86301730[3].unk_17C = D_80068BAC->unk_08;
    D_86301730[3].unk_178 = D_80068BAC->unk_02;
    D_86301730[3].unk_179 = D_80068BAC->unk_04;
}

void func_8630011C(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    func_8001F730();
    func_86300020();
}

void func_86300154(void) {
    D_86301718 = D_86301714->unk_0C;

    D_8630171C = 0x600;
    D_8630171E = 0;
    D_86301720 = 0x15E;

    D_86301718->unk_034 = 100.0f;
    D_86301718->unk_038 = 12800.0f;
    D_86301718->unk_02C = 30.0f;

    D_86301718->unk_0B4.x = 0.0f;
    D_86301718->unk_0B4.y = 70.0f;
    D_86301718->unk_0B4.z = 0.0f;

    func_80010354(&D_86301718->unk_0B4, &D_86301718->unk_0A8, D_86301720, D_8630171C, D_8630171E);
}

void func_86300230(void) {
}

void func_86300238(s32 arg0) {
    s32 i;
    u8 sp40[] = {
        0,
        0,
        30,
    };
    u8 sp3C[] = {
        0,
        0,
        150,
    };

    if (arg0 == 0) {
        func_8002053C(0x3A, 0x37, 0xC8, 0x64, sp40, sp3C);
    } else {
        func_8002053C(0x5A, 0xD7, 0x96, 0x12, sp40, sp3C);
    }

    func_8001F3F4();

    switch (arg0) {
        case 0:
            func_8001F470();
            func_8001EBE0(4, -2);
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            func_8001F36C(0xC8, 0xC8, 0x64, 0xFF);
            func_8001F1E8(0xA0 - (func_878013D4(D_86301728, D_86301600) / 2), 0x46, D_86301600);
            func_8001EBE0(2, -2);
            func_8001F1E8(0xA0 - (func_878013D4(D_86301728, (char*)D_87A01110) / 2), 0x5A, (char*)D_87A01110);
            func_8001F1E8(0xA0 - (func_878013D4(D_86301728, D_86301614) / 2), 0x6E, D_86301614);
            func_8001F1E8(0xA0 - (func_878013D4(D_86301728, D_86301634) / 2), 0x7D, D_86301634);

            if (D_86301722 & 0x10) {
                func_8001EBE0(4, -2);
                func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
                func_8001F36C(5, 5, 0xFF, 0xFF);
                func_8001F1E8(0xA0 - (func_878013D4(D_86301728, "PUSH START") / 2), 0xAA, "PUSH START");
            }

            func_8001F4C4();

            for (i = 0; i < 4; i++) {
                D_86301D44 = &D_86301730[i];

                func_8001EBE0(2, -2);
                func_8001F324(0xFF, 0xFF, 0xFF, 0xC8);
                func_8001F1E8(30 + (i * 0x46), 0xDA, "LV%02d", D_86301D44->unk_002);
            }
            break;

        default:
        case 2:
            func_8001EBE0(2, -2);
            func_8001F324(0xFF, 0xFF, 5, 0xFA);
            func_8001F1E8(0x64, 0xD9, "TIME %02d:%02d.%02d", (D_86301D40 * 2) / 3600, ((D_86301D40 * 2) / 60) % 60,
                          (((D_86301D40 * 2) % 60) * 0x64) / 60);

            if ((D_86301D4C == 1) && ((D_86301D4E % 30) >= 0xF)) {
                func_8001EBE0(0x20, -2);
                func_8001F324(0xFF, 5, 5, 0xFA);
                func_8001F1E8(0x96, 0x14, "%d", (D_86301D4E / 30) + 1);
            }

            if ((D_86301D40 != 0) && (D_86301D40 < 0xF)) {
                func_8001EBE0(0x20, -2);
                func_8001F324(0xFF, 0xFF, 5, 0xFA);
                func_8001F1E8(0x78, 0x14, "GO!");
            }
            break;
    }

    func_8001F444();
}

void func_863006D8(s32 arg0) {
    func_800079C4();
    func_8000699C(&gDisplayListHead, 0x53D);
    func_800067E4(&gDisplayListHead, 0, 0, 0x140, 0xF0);
    func_80015348();
    func_80015094(D_86301714);
    func_86300238(arg0);
    func_87804FD4();
    func_80007778();
    D_86301722++;
}

s32 func_86300764(void) {
    s32 i;
    s32 var_s5;

    func_80006C6C(0x10);

    for (i = 0; i < 4; i++) {
        D_86301D44 = &D_86301730[i];
        D_86301D48 = &D_86301D44->unk_004;

        func_8001BD04(D_86301D48, 1);

        D_86301D48->unk_04C = 0x10000;
        D_86301D48->unk_048 = func_878001E8(0x14) << 0x10;

        D_86301D50[i] = 0;
    }

    var_s5 = 1;
    D_86301724 = 0;

    while (var_s5 == 1) {
        func_8630011C();

        for (i = 0; i < 4; i++) {
            D_86301D44 = &D_86301730[i];

            if (D_86301D44->unk_17C & 1) {
                return -1;
            }

            if (D_86301D44->unk_17C & 0x1000) {
                var_s5 = 0;
            }
        }

        for (i = 0; i < 4; i++) {
            func_86300C50(i);
        }

        func_863006D8(D_86301724);
    }

    return 0;
}

void func_863008C0(void) {
    s32 i;

    func_80006C6C(0x10);

    for (i = 0; i < 4; i++) {
        D_86301D44 = &D_86301730[i];
        D_86301D48 = &D_86301D44->unk_004;

        func_8001BD04(D_86301D48, 1);

        D_86301D48->unk_04C = 0x10000;
        D_86301D48->unk_048 = func_878001E8(0x14) << 0x10;

        D_86301D50[i] = 0;
    }

    D_86301D4C = 1;
    D_86301D4E = 0x5A;
    D_86301724 = 1;

    while (D_86301D4C == 1) {
        if (D_86301D4E > 0) {
            D_86301D4E--;
        } else {
            D_86301D4C = 0;
        }

        func_8630011C();

        for (i = 0; i < 4; i++) {
            func_86300C50(i);
        }

        func_863006D8(D_86301724);
    }
}

void func_863009FC(s32 arg0) {
    s32 i;
    UNUSED s32 pad[2];
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 var_fs4;
    f32 var_fs5;
    UNUSED s32 pad2[11];
    f32 sp60;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 temp1;
    f32 temp2;
    f32 temp3;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;

    spA0 = D_86301D48->unk_024.x;
    sp9C = D_86301D48->unk_024.y;
    sp98 = D_86301D48->unk_024.z;

    var_fs4 = 0.0f;
    var_fs5 = 0.0f;
    sp60 = 0.0f;

    for (i = 0; i < 4; i++) {
        if (i != arg0) {
            temp_fs0 = D_86301730[i].unk_004.unk_024.x;
            temp_fs1 = D_86301730[i].unk_004.unk_024.y;
            temp_fs2 = D_86301730[i].unk_004.unk_024.z;

            temp1 = temp_fs0 - spA0;
            temp2 = temp_fs1 - sp9C;
            temp3 = temp_fs2 - sp98;

            temp_fv0 = sqrtf(SQ(temp1) + SQ(temp2) + SQ(temp3));
            if ((temp_fv0 < 32.0f) && (temp_fv0 > 0.0f)) {
                temp_fv1 = 32.0f - temp_fv0;

                var_fs4 += (-temp1 / temp_fv0) * temp_fv1;
                var_fs5 += (-temp2 / temp_fv0) * temp_fv1;
                sp60 += (-temp3 / temp_fv0) * temp_fv1;
            }
        }
    }

    temp_fs0 = D_86301D58.unk_024.x;
    temp_fs1 = D_86301D58.unk_024.y;
    temp_fs2 = D_86301D58.unk_024.z;

    temp1 = temp_fs0 - spA0;
    temp2 = temp_fs1 - sp9C;
    temp3 = temp_fs2 - sp98;

    temp_fv0 = sqrtf(SQ(temp1) + SQ(temp2) + SQ(temp3));
    if ((temp_fv0 < 40.0f) && (temp_fv0 > 0.0f)) {
        temp_fv1 = 40.0f - temp_fv0;

        var_fs4 += (-temp1 / temp_fv0) * temp_fv1;
        var_fs5 += (-temp2 / temp_fv0) * temp_fv1;
        sp60 += (-temp3 / temp_fv0) * temp_fv1;
    }

    D_86301D48->unk_024.x += var_fs4;
    D_86301D48->unk_024.y += var_fs5;
    D_86301D48->unk_024.z += sp60;
}

void func_86300C50(s32 arg0) {
    s32 temp_a0;
    s32 temp_a2;

    D_86301D44 = &D_86301730[arg0];
    D_86301D48 = &D_86301D44->unk_004;

    switch (D_86301D44->unk_000) {
        case 1:
            break;

        case 0:
            D_86301D48->unk_030.y = ((D_86301D44->unk_179 + 256.0f) * 0.00390625f) + 0.2f;
            D_86301D48->unk_01E.y = D_86301D44->unk_178 << 8;

            D_86301D44->unk_16C.x = 0.0f;
            D_86301D44->unk_16C.y = 0.0f;

            temp_a2 = D_86301D44->unk_178 - D_86301D44->unk_17A;
            temp_a0 = D_86301D44->unk_179 - D_86301D44->unk_17B;

            if (temp_a0 > 10) {
                D_86301D44->unk_000 = 1;
                D_86301D44->unk_16C.y = temp_a0 * 0.2f;

                if (D_86301D44->unk_16C.y > 15.0f) {
                    D_86301D44->unk_16C.y = 15.0f;
                }

                D_86301D44->unk_16C.x = temp_a2 * 0.1f;
            } else if (func_80031A6C(D_86301D44->unk_178) > 50.0f) {
                D_86301D44->unk_000 = 1;
                D_86301D44->unk_16C.y = 2.0f;
                D_86301D44->unk_16C.x = D_86301D44->unk_178 * 0.05f;
            }
            break;
    }

    func_863009FC(arg0);

    D_86301D48->unk_024.x += D_86301D44->unk_16C.x;
    D_86301D48->unk_024.y += D_86301D44->unk_16C.y;

    if (D_86301D48->unk_024.y > 0.0f) {
        D_86301D44->unk_16C.y -= 1.0f;
    }

    if (D_86301D48->unk_024.y < 0.0f) {
        D_86301D48->unk_024.y = 0.0f;
        D_86301D44->unk_000 = 0;
    }

    if (D_86301D48->unk_024.x < -100.0f) {
        D_86301D48->unk_024.x = -100.0f;
        D_86301D44->unk_16C.x *= -1.0f;
    }

    if (D_86301D48->unk_024.x > 100.0f) {
        D_86301D48->unk_024.x = 100.0f;
        D_86301D44->unk_16C.x *= -1.0f;
    }

    if (func_878001E8(0x64) == 0) {
        func_80017788(D_86301D48);
        func_8001BD9C(D_86301D48, 3);
    }
}

void func_86300F60(void) {
}

void func_86300F68(void) {
    s32 i;
    s32 var_s6 = 1;

    for (i = 0; i < 4; i++) {
        D_86301D44 = &D_86301730[i];
        D_86301D48 = &D_86301D44->unk_004;

        func_8001BD04(D_86301D48, 1);

        D_86301D48->unk_04C = 0x10000;

        D_86301D50[i] = 0;
    }

    D_86301D40 = 0;
    D_86301724 = 2;

    while (var_s6 != 0) {
        func_8630011C();
        func_86300230();

        if (D_80068BA0->unk_08 & 0x1000) {
            var_s6 = 0;
        }

        for (i = 0; i < 4; i++) {
            func_86300C50(i);
        }

        D_86301D40++;
        func_863006D8(D_86301724);
    }
}

void func_86301094(void) {
    s32 i;
    s32 j;
    int var = -1;

    for (i = 0; i < 4; i++) {
        D_86301D48 = &D_86301730[i].unk_004;

        if (i == var) {
            func_8001BD04(D_86301D48, 2);
            func_8001BD9C(D_86301D48, 6);
        } else {
            func_8001BD04(D_86301D48, 5);
            func_8001BD9C(D_86301D48, 7);
        }
    }

    D_86301724 = 3;

    for (j = 0; j < 0x5A; j++) {
        func_8630011C();
        func_863006D8(D_86301724);
    }
}

void func_86301168(void) {
    s32 i;

    func_80006CB4(30);

    for (i = 0; i < 30; i++) {
        func_8630011C();
        func_863006D8(D_86301724);
    }
}

void func_863011C8(void) {
    D_86301724 = 4;
    func_87802EB8(1);

    while (D_8780FC96 == 0) {
        func_8630011C();
        func_863006D8(D_86301724);
    }
}

void func_86301234(void) {
    s32 i;
    MemoryBlock* temp_v0 = func_80002D10(main_pool_get_available(), 0);

    D_86301714 = func_80018B70(temp_v0, &D_86301650);
    func_80002D60(temp_v0);
    func_8001BB20();
    func_8001987C();
    D_86301710 = func_80019D18(0x27);

    for (i = 0; i < 4; i++) {
        D_86301D44 = &D_86301730[i];
        D_86301D48 = &D_86301D44->unk_004;

        func_8001BB58(D_86301D48);
        func_8001BC34(D_86301D48, 0, 0x27, D_86301710->unk_08->unk_00[0]);

        D_86301D48->unk_024.x = (i - 1.5f) * 50.0f;
        D_86301D48->unk_024.y = 0.0f;
        D_86301D48->unk_024.z = 0.0f;

        D_86301D48->unk_030.x = 1.2f;
        D_86301D48->unk_030.y = 1.2f;
        D_86301D48->unk_030.z = 1.2f;

        D_86301D44->unk_16C.y = 0.0f;

        func_8001BD04(D_86301D48, 2);
        func_80017788(D_86301D48);

        D_86301D48->unk_048 = func_878001E8(5) << 0x10;
    }

    func_8001987C();
    D_86301710 = func_80019D18(0x9A);
    D_86301D48 = &D_86301D58;

    func_8001BB58(D_86301D48);
    func_8001BC34(D_86301D48, 0, 0x9A, D_86301710->unk_08->unk_00[0]);

    D_86301D48->unk_024.x = 0.0f;
    D_86301D48->unk_024.y = 0.0f;
    D_86301D48->unk_024.z = 0.0f;

    D_86301D48->unk_030.x = 8.0f;
    D_86301D48->unk_030.y = 8.0f;
    D_86301D48->unk_030.z = 8.0f;

    D_86301D48->unk_01E.y = 0;

    func_8001BD04(D_86301D48, 0);
    func_80017788(D_86301D48);
    D_86301D48->unk_04C = 0;
    func_86300154();
}

void func_86301474(UNUSED s32 arg0, UNUSED s32 arg1) {
    unk_func_80007444* sp24;

    main_pool_push_state('MINI');

    func_80005E40(0x10000, 0);
    sp24 = func_80007444(0, 1, 3, 1, 2, 1);
    D_86301728 = func_8001E94C(0x26, 0);

    ASSET_LOAD(D_1000000, _4BD6B0, 0);
    FRAGMENT_LOAD(func_80004454, fragment31);

    func_80004454((((u32)&D_8D000000 & 0x0FF00000) >> 0x14) - 0x10, _5C7A70_ROM_START, _5C7AD0_ROM_START);

    func_86301234();
    func_878029C0();
    func_80007678(sp24);

    if (func_86300764() != -1) {
        func_863008C0();
        func_86300F68();
        func_86301094();
        func_863011C8();
    }

    func_86301168();
    func_800076C0();
    func_8001E9CC();
    func_80005EAC();

    main_pool_pop_state('MINI');

    func_87803118();
}

void func_863015EC(void) {
}
