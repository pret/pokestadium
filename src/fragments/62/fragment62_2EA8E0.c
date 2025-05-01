#include "fragment62.h"
#include "src/11BA0.h"
#include "src/12D80.h"
#include "src/19840.h"
#include "src/1C720.h"
#include "src/1CF30.h"
#include "src/20330.h"
#include "src/32D10.h"
#include "src/3D140.h"
#include "src/3FB0.h"
#include "src/4BDC0.h"
#include "src/6A40.h"
#include "src/F420.h"
#include "src/controller.h"
#include "src/geo_layout.h"
#include "src/memmap.h"
#include "src/memory.h"

static unk_D_86002F34_00C D_8438E440;
static unk_D_8690A610 D_8438E530;
static GraphNode D_8438E550;
static GraphNode D_8438E568;
static GraphNode D_8438E580;
static unk_D_86002F34_00C D_8438E598;
static unk_D_86002F34_00C D_8438E688;
u8* D_8438E778;
u8* D_8438E77C;
static void* D_8438E780;
static GraphNode* D_8438E784;
static GraphNode* D_8438E788;
static GraphNode* D_8438E78C;
static unk_D_80068BB0* D_8438E790;
static unk_D_80068BB0* D_8438E794;
static unk_D_800AE540_1194* D_8438E798;
static s32 D_8438E79C;
static s32 D_8438E7A0;
static Color_RGBA8_u32 D_8438E7A4;
static f32 D_8438E7A8;
static s32 D_8438E7AC;

static u8 D_84384350[] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x11, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
};
static u32 D_84384364[] = {
    0x0C00FFFF,  0x05000000,  0x07000000,    &D_8438E440,   0x05000000, 0x0D000000,    0x05000000,  0x07000000,
    &D_8438E530, 0x14000000,  0x002D0019,    0xFFFFFF28,    0x08000000, func_84300058, 0x00000000,  0x14000000,
    0x002D0019,  0x80808028,  0x08000000,    func_843000C0, 0x00000000, 0x16646464,    0x0F000002,  0x05000000,
    0x1F00FFFF,  0x00000000,  0x00000000,    0x00000000,    0x00640064, 0x00640000,    0x08000000,  func_8430012C,
    0x00000000,  0x05000000,  0x07000000,    &D_8438E550,   0x06000000, 0x06000000,    0x0F000003,  0x05000000,
    0x1F00FFFF,  0x00000000,  0x00000000,    0x00000000,    0x00640064, 0x00640000,    0x08000000,  func_8430012C,
    0x00000000,  0x05000000,  0x07000000,    &D_8438E568,   0x06000000, 0x06000000,    0x0F000002,  0x05000000,
    0x1F00FFFF,  0x00000000,  0x00000000,    0x00000000,    0x00640064, 0x00640000,    0x08000000,  func_8430012C,
    0x00000000,  0x05000000,  0x07000000,    &D_8438E580,   0x06000000, 0x06000000,    0x0F000003,  0x05000000,
    0x0A000000,  &D_800AC840, 0x06000000,    0x0F000002,    0x05000000, 0x0A000000,    &D_800AC858, 0x06000000,
    0x09000000,  0x08000000,  func_84300020, 0x00000000,    0x06000000, 0x06000000,    0x06000000,  0x01000000,
};
static u32 D_843844C4[] = {
    0x0C00FFFF,  0x05000000, 0x07000000, &D_8438E598, 0x05000000, 0x0D000001, 0x05000000,
    0x14000000,  0x002D0019, 0xFFFFFF28, 0x16FFFFFF,  0x0F000003, 0x05000000, 0x0A000000,
    &D_800AC840, 0x06000000, 0x06000000, 0x06000000,  0x06000000, 0x01000000,
};
static u32 D_84384514[] = {
    0x0C00FFFF,  0x05000000, 0x07000000, &D_8438E688, 0x05000000, 0x0D000002, 0x05000000,
    0x14000000,  0x002D0019, 0xFFFFFF28, 0x16FFFFFF,  0x0F000003, 0x05000000, 0x0A000000,
    &D_800AC840, 0x06000000, 0x06000000, 0x06000000,  0x06000000, 0x01000000,
};

s32 func_84300020(s32 arg0, GraphNode* arg1) {
    if (arg0 == 2) {
        func_8432D0D8(5, &D_8438E440);
    }
    return 0;
}

s32 func_84300058(s32 arg0, unk_D_86002F34_alt18* arg1) {
    UNUSED s32 pad;
    f32 sp28;
    s16 sp26;
    s16 sp24;

    if (arg0 == 2) {
        func_800102A4(&D_8006F088->unk_60.at, &D_8006F088->unk_60.eye, &sp28, &sp26, &sp24);
        arg1->unk_1C = sp26 + 0x2000;
        arg1->unk_1E = sp24 - 0x2000;
    }
    return 0;
}

s32 func_843000C0(s32 arg0, unk_D_86002F34_alt18* arg1) {
    UNUSED s32 pad;
    f32 sp28;
    s16 sp26;
    s16 sp24;

    if (arg0 == 2) {
        func_800102A4(&D_8006F088->unk_60.at, &D_8006F088->unk_60.eye, &sp28, &sp26, &sp24);
        arg1->unk_1C = -0x2000 - sp26;
        arg1->unk_1E = sp24 + 0x6000;
    }
    return 0;
}

s32 func_8430012C(s32 arg0, unk_D_86002F58_004_000* arg1) {
    if (arg0 == 2) {
        func_8000E88C(&arg1->unk_030, D_8438E7A8, D_8438E7A8, D_8438E7A8);
        arg1->unk_03C.rgba = D_8438E7A4.rgba;
    }
    return 0;
}

void func_84300184(u8 arg0, u8 arg1, u8 arg2) {
    D_8438E7A4.r = arg0;
    D_8438E7A4.g = arg1;
    D_8438E7A4.b = arg2;

    if (((arg0 & arg1 & arg2) & 0xFF) == 0xFF) {
        if (D_8438E530.unk_00.unk_14 == 1) {
            D_8438E530.unk_00.unk_01 |= 1;
        }
    } else {
        D_8438E530.unk_00.unk_01 &= ~1;
    }
}

void func_843001FC(f32 arg0) {
    D_8438E7A8 = arg0;
}

u16 func_84300208(u16 arg0) {
    s32 r;
    s32 g;
    s32 b;

    r = ((((((arg0 >> 11) & 0x1F) << 3) + (((arg0 >> 11) & 0x1F) >> 2)) * D_8438E7A4.r) / 255) >> 3;
    g = ((((((arg0 >> 6) & 0x1F) << 3) + (((arg0 >> 6) & 0x1F) >> 2)) * D_8438E7A4.g) / 255) >> 3;
    b = ((((((arg0 >> 1) & 0x1F) << 3) + (((arg0 >> 1) & 0x1F) >> 2)) * D_8438E7A4.b) / 255) >> 3;

    return (r << 11) | (g << 6) | (b << 1) | 1;
}

void func_84300340(void) {
    s16 sp4E;
    s16 sp4C;
    s16 sp4A;
    s16 sp48;
    s16 sp46;
    s16 sp44;

    if ((u32)D_8438E780 == NULL) {
        func_800067E4(&gDisplayListHead, 0, 0, 0x140, 0xF0);
        return;
    }

    if ((u32)D_8438E780 == -1) {
        func_8000699C(&gDisplayListHead, 1);
        return;
    }

    if ((u32)D_8438E780 < 0x10000) {
        func_8000699C(&gDisplayListHead, func_84300208(D_8438E780));
        return;
    }

    sp4E = D_8438E440.unk_18.x;
    sp4A = D_8438E440.unk_18.y;
    sp4C = D_8438E440.unk_18.width + sp4E;
    sp48 = (D_8438E440.unk_18.height / 2) + sp4A;
    sp46 = D_8438E440.unk_18.height + sp4A;
    sp44 = 0x10000 / (D_8438E440.unk_18.height / 2);

    if ((D_8438E440.unk_18.width < 0x140) || (D_8438E440.unk_18.height < 0xF0)) {
        func_8000699C(&gDisplayListHead, 1);
    } else {
        func_800067E4(&gDisplayListHead, 0, 0, 0x140, 0xF0);
    }

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetCombineMode(gDisplayListHead++, G_CC_MODULATEI_PRIM, G_CC_MODULATEI_PRIM);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, D_8438E7A4.r, D_8438E7A4.g, D_8438E7A4.b, 255);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);

    gDPLoadTextureBlock(gDisplayListHead++, Memmap_GetFragmentVaddr(D_8438E780), G_IM_FMT_RGBA, G_IM_SIZ_32b, 4, 64, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, sp4E << 2, sp4A << 2, sp4C << 2, sp48 << 2, G_TX_RENDERTILE, 0, 0, 0, sp44);
    gSPTextureRectangle(gDisplayListHead++, sp4E << 2, sp48 << 2, sp4C << 2, sp46 << 2, G_TX_RENDERTILE, 0, 0x07E0, 0,
                        0);
    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_84300750(GraphNode* arg0, unk_D_80068BB0* arg1) {
    unk_D_86002F34_00C* sp2C = arg0->unk_0C;
    unk_D_86002F34_00C_018 sp20;

    if (sp2C->unk_00.unk_01 & 0x10) {
        sp20 = sp2C->unk_18;

        sp2C->unk_18.x = 0;
        sp2C->unk_18.y = 0;
        sp2C->unk_18.width = 0x4C;
        sp2C->unk_18.height = 0x4C;

        func_80006498(&gDisplayListHead, arg1);
        func_8000699C(&gDisplayListHead, 0x10D);
        func_80015094(arg0);

        sp2C->unk_00.unk_01 &= ~0x10;

        sp2C->unk_18 = sp20;
    }
}

void func_84300810(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    unk_D_800A7440 sp38;
    u16 tmp5;
    u16 tmp6;

    func_80005FC0(&sp38, arg0, arg1, arg2, arg3);

    if (func_80006030(&sp38) != 0) {
        if (!arg2) {}

        tmp5 = ((sp38.x1 - arg0) << 5);
        tmp6 = ((sp38.y2 - arg1) << 5);

        tmp5 += 0x10;
        tmp6 += 0x10;

        gSPTextureRectangle(gDisplayListHead++, sp38.x1 << 2, sp38.y2 << 2, ((sp38.y1 + 1) ^ 0) << 2,
                            ((sp38.x2 + 1) ^ 0) << 2, G_TX_RENDERTILE, tmp5, tmp6, 0x0800, 0x0800);

        if ((arg2 && arg2) ^ 0) {}
    }
}

void func_84300938(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8* arg4, s32 arg5) {
    gDPLoadTextureBlock(gDisplayListHead++, arg4, G_IM_FMT_RGBA, G_IM_SIZ_16b, arg5, (arg3 * 2) + 2, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    func_84300810(arg0, arg1, (arg0 + arg2) - 1, (arg1 + arg3) - 1);
}

void func_84300B34(GraphNode* arg0, unk_D_80068BB0* arg1) {
    s32 temp_s2;
    s32 temp_s3;
    unk_D_86002F34_00C* temp_v1 = arg0->unk_0C;
    unk_D_86002F34_00C_018* ptr = &arg0->unk_0C->unk_18;
    s32 img;

    temp_s2 = ptr->x;
    temp_s3 = ptr->y;

    temp_v1++;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_AVERAGE);

    img = arg1->img_p;
    func_84300938(temp_s2, temp_s3, 0x25, 0xA, img, 0x4C);
    img = arg1->img_p + 0xBE0;
    func_84300938(temp_s2, temp_s3 + 0xA, 0x25, 0xA, img, 0x4C);
    img = arg1->img_p + 0x17C0;
    func_84300938(temp_s2, temp_s3 + 0x14, 0x25, 0xA, img, 0x4C);
    img = arg1->img_p + 0x23A0;
    func_84300938(temp_s2, temp_s3 + 0x1E, 0x25, 7, img, 0x4C);

    gDPPipeSync(gDisplayListHead++);

    gDPSetTexturePersp(gDisplayListHead++, G_TP_PERSP);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
}

void func_84300D44(void) {
    s32 i;
    s32 j;
    s32 x;
    unk_D_800AE540_0004* temp_a2;
    unk_D_800AE540_1194* ptr = &D_8438E798[0];

    for (i = 0; i < 2; i++, ptr++) {
        for (j = 0; j < ptr->unk_01; j++) {
            temp_a2 = ptr->unk_08[j];
            for (x = 0; x < temp_a2->unk_002; x++) {
                temp_a2->unk_01C[x].unk_25 = 0;
            }
        }
    }
}

void func_84300DC0(void) {
    s32 i;
    s32 j;
    s32 x;
    s32 var_v0 = 0;
    unk_D_800AE540_0004* temp_a3;
    unk_D_800AE540_1194* ptr = &D_8438E798[0];

    for (i = 0; i < 2; i++, ptr++) {
        for (j = 0; j < ptr->unk_01; j++) {
            temp_a3 = ptr->unk_08[j];
            for (x = 0; x < temp_a3->unk_002; x++) {
                if ((temp_a3->unk_01C[x].unk_25 == 0) && (temp_a3->unk_01C[x].unk_02 == 0)) {
                    var_v0 = 1;
                    temp_a3->unk_01C[x].unk_25 = D_8438E7A0;
                }
            }
        }
    }

    if (var_v0 != 0) {
        D_8438E7A0 += 1;
    }
}

void func_84300E78(void) {
}

void func_84300E80(void) {
}

s32 func_84300E88(s32 arg0) {
    s32 sp1C;

    func_80015348();
    func_80032570();
    func_84307394(2, D_8438E798);
    func_84307A50(2, &D_8438E598, &D_8438E688);
    sp1C = func_8432AEE4(2, &D_8438E440);
    func_8432D0D8(2, &D_8438E440);
    func_84300750(D_8438E788, D_8438E790);
    func_84300750(D_8438E78C, D_8438E794);
    func_800079C4();
    func_84300340();
    func_80015094(D_8438E784);
    func_84307394(5, D_8438E798);
    func_84300B34(D_8438E788, D_8438E790);
    func_84300B34(D_8438E78C, D_8438E794);
    func_84300DC0();

    if (sp1C == 1) {
        D_8438E798[0].unk_1C = 1;
    }

    if (sp1C == 2) {
        D_8438E798[1].unk_1C = 1;
    }

    return sp1C;
}

s32 func_84300FBC(s32 arg0) {
    s32 sp1C = 0;

    if ((arg0 == 0) && BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        sp1C = func_84300E88(arg0);
    } else {
        func_80032570();
        func_800079C4();
        func_84300340();
        func_80015094(D_8438E784);
        func_84307394(5, D_8438E798);
        func_84300B34(D_8438E788, D_8438E790);
        func_84300B34(D_8438E78C, D_8438E794);
    }

    if ((arg0 == 0) && BTN_IS_PRESSED(gPlayer1Controller, BTN_START)) {
        D_8438E79C = 0;
    }
    return sp1C;
}

void func_84301094(void) {
    if (D_8438E7AC < 0) {
        D_8438E7AC++;
    } else if ((D_8438E7AC == 0) && (D_800AE540.unk_0000 == 0x10) && gPlayer1Controller->buttonPressed) {
        D_8438E7AC = 1;
    }
}

s32 func_843010EC(s32 arg0) {
    s32 sp1C = 0;

    Cont_StartReadInputs();
    func_8001C07C(&D_8438E798[0]);
    func_8001C1E8(&D_8438E798[0]);
    func_8001C07C(&D_8438E798[1]);
    func_8001C1E8(&D_8438E798[1]);
    Cont_ReadInputs();
    func_8001F730();

    switch (D_8438E79C) {
        case 0:
            sp1C = func_84300E88(arg0);
            break;

        case 1:
            sp1C = func_84300FBC(arg0);
            break;
    }

    if ((sp1C != 0) && (D_8438E7AC <= 0)) {
        D_8438E7AC = 1;
    }

    func_84301094();
    func_8001C248(&D_8438E798[0]);
    func_8001C248(&D_8438E798[1]);

    if ((arg0 != 2) && (D_8438E7AC == 1)) {
        D_8438E7AC = 2;
        func_8003DB84(0);
        if (D_800AE540.unk_0000 != 0x11) {
            func_8004B9C4(0x1E);
        }
        return 1;
    }
    return 0;
}

void func_8430123C(u8* arg0, s32 arg1) {
    s32 i;
    s32 j;

    for (i = 0; i < 6; i++) {
        for (j = 0; j < arg1; j++) {
            if (i == arg0[j]) {
                break;
            }
        }

        if (j == arg1) {
            arg0[arg1++] = i;
        }
    }
}

void func_8430128C(void) {
    unk_D_800AE540_0004* temp_s0;
    unk_D_800AE540_0004* temp_s1;
    u8 sp48[8];
    unk_D_800AE540_0004* temp_s2;
    s32 i;
    s32 var_s1;

    temp_s1 = D_800AE540.unk_1194[0].unk_08[0];
    temp_s2 = D_800AE540.unk_1194[0].unk_08[1];
    temp_s0 = D_800AE540.unk_1194[1].unk_08[0];

    if (temp_s0->unk_000 & 2) {
        if (D_800AE540.unk_0000 == 0) {
            if (D_800AE540.unk_0001 == 0) {
                var_s1 = temp_s0->unk_214->unk_002;
            } else {
                var_s1 = 3;
            }
            func_843831A0(temp_s1, temp_s2, temp_s0, D_800AE540.unk_11EC, sp48, D_800AE540.unk_0001, var_s1);
        } else {
            if (D_800AE540.unk_0001 == 8) {
                var_s1 = temp_s0->unk_214->unk_002;
            } else {
                var_s1 = 3;
            }
            func_843831A0(temp_s1, NULL, temp_s0, temp_s0->unk_018 & 0xFF, sp48, D_800AE540.unk_0001, var_s1);
        }
        func_8430123C(sp48, var_s1);
        temp_s0->unk_002 = var_s1;

        for (i = 0; i < temp_s0->unk_214->unk_002; i++) {
            temp_s0->unk_01C[i] = temp_s0->unk_214->unk_028[sp48[i]];
        }
    }
}

void func_843013E4(unk_D_800AE540_1194* arg0, unk_D_86002F30* arg1) {
    unk_D_800AE540_0004* temp_v0 = arg0->unk_08[0];

    arg0->unk_18 = arg1->unk_08->unk_00[0];
    arg0->unk_00 |= 0xA0;
    arg0->unk_1C = 0;
    arg0->unk_02 = temp_v0->unk_01C[0].unk_00.unk_00;
    arg0->unk_04 = temp_v0->unk_01C;
    func_8001C07C(arg0);
}

void func_84301430(unk_func_80007444* arg0) {
    MemoryBlock* sp44;
    u32* temp_v0_4;
    FragmentEntry sp3C;
    unk_D_8690A610_018* temp_v0_7;
    s32 pad;
    s16 sp32;
    unk_D_80068BB0* sp2C;
    unk_D_86002F30* sp28;

    func_84300184(0xFF, 0xFF, 0xFF);
    func_843001FC(1.0f);

    if (D_800AE540.unk_0000 == 0x11) {
        func_8001E94C(4, 0);
    } else if (D_800AE540.unk_0000 == 0x10) {
        func_8001E94C(7, 0);
    } else {
        func_8001E94C(3, 0);
    }

    D_8438E798[0].unk_10 = func_80019760(3);
    D_8438E798[1].unk_10 = func_80019760(3);
    func_8001987C();

    sp2C = main_pool_alloc(0x10, 0);
    func_800062E4(sp2C, 0, 2, 0x4C, 0x4C, arg0->unk_18[0]->depth_p->img_p);
    D_8438E790 = func_80006314(0, 2, 0x4C, 0x4C, 0);
    D_8438E794 = func_80006314(0, 2, 0x4C, 0x4C, 0);

    func_80006414(D_8438E790, sp2C);
    func_80006414(D_8438E794, sp2C);

    D_8438E778 = D_8438E790->img_p;
    D_8438E77C = D_8438E794->img_p;

    FRAGMENT_LOAD(fragment31);
    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_3000000, battle_ui, 0);

    if ((D_800AE540.unk_0000 == 0x10) || (D_800AE540.unk_0000 == 0xA)) {
        sp32 = D_84384350[D_800AE540.unk_0001];
        if (D_800AE540.unk_0001 == 7) {
            sp32 += D_800AE540.unk_0002;
        }
    } else {
        sp32 = D_84384350[D_800AE540.unk_0000];
        if (D_800AE540.unk_0000 == 7) {
            sp32 += D_800AE540.unk_0002;
        }
    }

    sp3C = func_8000484C(ASSET_LOAD2(stadium_models, 1, 1), sp32);
    D_8438E780 = sp3C(2, 0);

    sp28 = func_80019D18(0x9A);
    func_8430128C();
    func_843013E4(&D_8438E798[0], sp28);
    func_843013E4(&D_8438E798[1], sp28);

    func_84300D44();
    func_800110E0(NULL, &D_8438E440, 0, 0, 0x140, 0xF0);
    func_800110E0(NULL, &D_8438E598, 0x1E, 0x50, 0x4C, 0x4C);
    func_800110E0(NULL, &D_8438E688, 0xE2, 0x50, 0x4C, 0x4C);
    func_800113F8(0, &D_8438E530, 0x3C0, 0x3E8, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8001103C(NULL, &D_8438E550);
    func_8001103C(NULL, &D_8438E568);
    func_8001103C(NULL, &D_8438E580);
    func_80011E68(&D_8438E440, 30.0f, 192.0f, 24576.0f);
    func_8001BB20();
    func_84307394(0, D_8438E798);
    func_84307A50(0, &D_8438E598, &D_8438E688);
    func_8432AEE4(0, &D_8438E440);
    func_8432D0D8(0, &D_8438E440);

    sp44 = func_80002D10(main_pool_get_available(), 0);
    D_8438E784 = process_geo_layout(sp44, D_84384364);
    D_8438E788 = process_geo_layout(sp44, D_843844C4);
    D_8438E78C = process_geo_layout(sp44, D_84384514);

    temp_v0_4 = sp3C(0, 0);
    if (temp_v0_4 != NULL) {
        func_80012094(&D_8438E550, process_geo_layout(sp44, temp_v0_4));
    }

    temp_v0_4 = sp3C(1, 0);
    if (temp_v0_4 != NULL) {
        func_80012094(&D_8438E568, process_geo_layout(sp44, temp_v0_4));
    }

    temp_v0_4 = sp3C(3, 0);
    if (temp_v0_4 != NULL) {
        func_80012094(&D_8438E580, process_geo_layout(sp44, temp_v0_4));
    }

    func_80002D60(sp44);

    temp_v0_7 = sp3C(4, 0);
    if (temp_v0_7 == NULL) {
        D_8438E530.unk_00.unk_14 = 0;
        D_8438E530.unk_00.unk_01 &= ~1;
    } else {
        D_8438E530.unk_18.unk_00 = temp_v0_7->unk_00;
        D_8438E530.unk_18.unk_02 = temp_v0_7->unk_02;
        D_8438E530.unk_18.unk_04.rgba = temp_v0_7->unk_04.rgba;
        D_8438E530.unk_00.unk_14 = 1;
    }

    func_84307394(3, D_8438E798);
    func_84307A50(3, &D_8438E598, &D_8438E688);
    func_8432AEE4(3, &D_8438E440);
    func_8432D0D8(3, &D_8438E440);

    D_8438E7A0 = 1;
    D_8438E79C = 0;
}

void func_84301A24(void) {
}

s32 func_84301A2C(s32 arg0, unk_D_800AE540* arg1) {
    unk_func_80007444* sp24;

    D_8438E798 = D_800AE540.unk_1194;
    D_8438E7AC = -2;

    main_pool_push_state('BATL');

    func_80005E40(0x20000, 0);
    sp24 = func_80007444(0, 1, 3, 1, 2, 1);
    func_84301430(sp24);
    func_80007678(sp24);
    func_800077B4(1);
    func_800078D4(func_843010EC, 0x20, 0x10);
    func_800077B4(2);
    func_800076C0();
    func_80005EAC();

    main_pool_pop_state('BATL');

    return 0;
}
