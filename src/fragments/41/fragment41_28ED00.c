#include "fragment41.h"
#include "src/12D80.h"
#include "src/1C720.h"
#include "src/1CF30.h"
#include "src/20470.h"
#include "src/29BA0.h"
#include "src/2E110.h"
#include "src/49790.h"
#include "src/F420.h"
#include "src/geo_layout.h"
#include "src/math_util.h"
#include "src/memmap.h"
#include "src/memory.h"

s32 func_82F06E50(s32 arg0, GraphNode* arg1);

static unk_D_82F20A40 D_82F20A40;
static unk_D_82F20A88 D_82F20A88[4];
static GraphNode* D_82F210C8;
static GraphNode* D_82F210CC;
static s16 D_82F210D0;
static s16 D_82F210D2;
static s16 D_82F210D4;
static s16 D_82F210D8[2];

static Vtx D_82F13CB0[] = {
    VTX(-32, 64, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-32, 32, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, 32, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(32, 64, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, 32, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-32, 0, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, 0, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(32, 32, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-16, 39, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-16, 15, 0, 0, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(16, 15, 0, 1024, 768, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(16, 39, 0, 1024, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};

static Gfx D_82F13D70[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_82F13CB0, 12, 0),
    gsDPLoadTextureBlock(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(0x0F001000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsDPLoadTextureBlock(0x0E000000, G_IM_FMT_IA, G_IM_SIZ_8b, 32, 24, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

static u32 D_82F13E58[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_82F13CB0, 0x05000000, 0x22050000,
    0x00000000, 0x08000000, func_82F06E50, D_82F13D70, 0x06000000, 0x01000000,
};

static u32 D_82F13E8C[] = {
    0x0C000000, 0x05000000, 0x0B00002D,  0x00000000, 0x028001E0, 0x00000000, 0xFDBD0000, 0x00000243,
    0x05000000, 0x0D000000, 0x05000000,  0x14000000, 0x002D013B, 0xFFFFFF32, 0x16FFFFFF, 0x0F000002,
    0x05000000, 0x0A000000, &D_800AC840, 0x06000000, 0x06000000, 0x06000000, 0x06000000, 0x01000000,
};
static s16 D_82F13EEC[] = {
    0x007E,
    0x013C,
    0x0184,
    0x0000,
};
static s16 D_82F13EF4[] = {
    0x007E,
    0x0120,
    0x0184,
    0x0038,
};
static s16 D_82F13EFC[] = {
    0x00A1,
    0x013C,
    0x013E,
    0x0000,
};
static s16 D_82F13F04[] = {
    0x00A1,
    0x0120,
    0x013E,
    0x0038,
};
static s16 D_82F13F0C[] = {
    0x007D,
    0x0149,
    0x0186,
    0x0000,
};
static s16 D_82F13F14[] = {
    0x007D,
    0x0120,
    0x0186,
    0x0052,
};
static s16 D_82F13F1C[] = {
    0x00CC,
    0x013C,
    0x00E8,
    0x0000,
};
static s16 D_82F13F24[] = {
    0x00CC,
    0x0120,
    0x00E8,
    0x0038,
};
static u8* D_82F13F2C[] = {
    D_302FAB0,
    D_302FDB0,
    D_30300B0,
    D_30303B0,
};

s32 func_82F06E50(s32 arg0, GraphNode* arg1) {
    if (arg0 == 5) {
        s32 idx = D_8006F09C->unk_000.unk_14;

        gDPPipeSync(gDisplayListHead++);
        gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, D_8006F09C->unk_01D);

        if (D_82F20A88[idx].unk_024 != NULL) {
            gSPSegment(gDisplayListHead++, 0x0F, Memmap_GetSegmentVaddr(D_82F20A88[idx].unk_024));
            gSPSegment(gDisplayListHead++, 0x0E, Memmap_GetSegmentVaddr(D_82F13F2C[D_82F20A88[idx].unk_002]));
            gSPDisplayList(gDisplayListHead++, arg1->unk_14);
        }
        func_80015684();
    }
    return 0;
}

s16 func_82F06F9C(unk_D_82F14450* arg0) {
    s16 ret;

    switch (arg0->unk_00) {
        case 0:
            if (arg0->unk_04 == 0) {
                ret = 4;
            } else if (arg0->unk_03 == 0) {
                ret = 3;
            } else {
                ret = 0;
            }
            break;

        case 2:
            ret = 1;
            break;

        case 3:
            ret = 2;
            break;

        default:
            ret = -1;
            break;
    }

    return ret;
}

void func_82F07004(s16 arg0) {
    s16 temp_v0;
    unk_D_82F20A88* var_s0;
    s32 i;

    var_s0 = &D_82F20A88[0];
    for (i = 0; i < 4; i++, var_s0++) {
        var_s0->unk_000 = 0;
        var_s0->unk_002 = -1;
        var_s0->unk_004 = 0;
        var_s0->unk_024 = NULL;
    }

    D_82F210D0 = 1;

    for (i = 0; i < 4; i++) {
        temp_v0 = func_82F06F9C(&D_82F14450[i]);
        if (temp_v0 == -1) {
            continue;
        }

        if (i != D_82F210D8[0]) {
            var_s0 = &D_82F20A88[D_82F210D0++];
        } else {
            var_s0 = &D_82F20A88[0];
        }

        var_s0->unk_002 = i;
        var_s0->unk_004 = temp_v0;

        switch (var_s0->unk_004) {
            case 0:
            case 2:
            case 3:
            case 4:
                switch (D_82F14450[i].unk_01) {
                    case 1:
                        var_s0->unk_024 = D_30306B0;
                        break;

                    case 2:
                        var_s0->unk_024 = D_30326B0;
                        break;

                    case 3:
                        var_s0->unk_024 = D_30346B0;
                        break;

                    case 7:
                        var_s0->unk_024 = D_30366B0;
                        break;
                }
                break;

            case 1:
                var_s0->unk_024 = D_302BE68;
                break;
        }
    }

    var_s0 = &D_82F20A88[0];
    for (i = 0; i < D_82F210D0; i++, var_s0++) {
        unk_D_86002F58_004_000* ptr = &var_s0->unk_028;

        func_8001BB58(ptr);
        func_8001BC34(ptr, 0, 0, D_82F210CC);
        ptr->unk_000.unk_14 = i;
        ptr->unk_000.unk_01 &= ~1;
    }
}

void func_82F07214(unk_D_82F20A88* arg0, s16 arg1) {
    unk_D_86002F58_004_000* temp_v0 = &arg0->unk_028;

    arg0->unk_000 = arg1;

    switch (arg0->unk_000) {
        case 0:
            temp_v0->unk_000.unk_01 &= ~1;
            break;

        case 1:
            if ((((s32)arg0 - (s32)D_82F20A88) / 400) == 0) {
                arg0->unk_006 = 0xF8;
                arg0->unk_008 = 0xB8;
            }

            arg0->unk_010 = 0;
            arg0->unk_00C = 0;
            arg0->unk_00E = 0;
            arg0->unk_012 = 0;

            if (arg0->unk_004 != 0) {
                arg0->unk_014 = 0x80;
            } else {
                arg0->unk_014 = 0xFF;
            }

            arg0->unk_018 = 1.0f;
            arg0->unk_01C = 1.0f;
            arg0->unk_020 = 1.0f;
            temp_v0->unk_000.unk_01 |= 1;
            break;

        case 2:
            arg0->unk_006 = ((((s32)arg0 - (s32)D_82F20A88) / 400) * 0x88) + 0x30;
            arg0->unk_008 = 0x17C;
            arg0->unk_00A = arg0->unk_006;
            arg0->unk_010 = 0xA;
            arg0->unk_00C = 0;
            arg0->unk_00E = 0;
            arg0->unk_012 = 0;

            if (arg0->unk_004 != 0) {
                arg0->unk_014 = 0x80;
            } else {
                arg0->unk_014 = 0xFF;
            }

            arg0->unk_01C = 1.0f;
            arg0->unk_020 = 1.0f;
            arg0->unk_018 = 0.0f;
            temp_v0->unk_000.unk_01 |= 1;
            break;

        case 4:
            arg0->unk_010 = 0;
            arg0->unk_00A = arg0->unk_006;

            if ((((s32)arg0 - (s32)D_82F20A88) / 400) & 1) {
                arg0->unk_00C = -0x8000;
            } else {
                arg0->unk_00C = 0;
            }

            arg0->unk_00E = arg0->unk_00C;
            arg0->unk_018 = 1.0f;
            break;

        case 3:
            arg0->unk_006 = ((((s32)arg0 - (s32)D_82F20A88) / 400) * 0x88) + 0x30;
            arg0->unk_008 = 0x17C;
            arg0->unk_010 = 0xA;
            arg0->unk_00C = 0;
            arg0->unk_00E = 0;
            arg0->unk_012 = 0;
            arg0->unk_01C = 1.0f;
            arg0->unk_020 = 1.0f;
            break;

        case 5:
            arg0->unk_010 = 0xA;
            break;

        case 6:
            arg0->unk_010 = 0xA;
            break;
    }
}

void func_82F07440(unk_D_82F20A88* arg0) {
    arg0->unk_010--;
    arg0->unk_018 = (0xA - arg0->unk_010) / 10.0f;
    if (arg0->unk_010 <= 0) {
        func_82F07214(arg0, 4);
    }
}

void func_82F07498(unk_D_82F20A88* arg0) {
    static s16 D_82F13F38[] = { 0x5C0, 0x680, 0x580 };

    s32 temp_lo = arg0 - &D_82F20A88[0];
    s16 var_a2;
    s16 var_a3;
    f32 var_fv0;
    f32 var_fv1;

    if (temp_lo - 1 == D_82F210D2) {
        var_fv0 = 1.5f;
        var_a2 = D_82F13F38[temp_lo - 1] * 2;
        var_fv1 = 0.06f;
        var_a3 = 0x3000;
    } else {
        var_a2 = D_82F13F38[temp_lo - 1];
        var_fv1 = 0.02f;
        var_a3 = 0x2000;
        var_fv0 = 1.0f;
    }

    arg0->unk_006 = arg0->unk_00A - (SINS(arg0->unk_00C) * (6.0f * var_fv0));

    arg0->unk_012 = SINS(arg0->unk_00C) * (1536.0f * var_fv0);
    arg0->unk_01C = (SINS(arg0->unk_00E) * var_fv1) + 1.0f;
    arg0->unk_020 = (COSS(arg0->unk_00E) * var_fv1) + 1.0f;

    arg0->unk_00C += var_a2;
    arg0->unk_00E += var_a3 + ((MathUtil_Random16() & 0xF) * 0x10);
}

void func_82F0761C(unk_D_82F20A88* arg0) {
    func_82F07498(arg0);
}

void func_82F0763C(unk_D_82F20A88* arg0) {
    arg0->unk_010 -= 1;
    arg0->unk_006 = 0x208 - (((0x208 - arg0->unk_00A) * arg0->unk_010) / 10);
    arg0->unk_008 = 0xB8 - ((arg0->unk_010 * -0xC4) / 10);
    if (arg0->unk_010 <= 0) {
        func_82F07214(arg0, 1);
        D_82F210D8[1] = arg0->unk_002;
    }
}

void func_82F07728(unk_D_82F20A88* arg0) {
    arg0->unk_010--;
    arg0->unk_014 = (arg0->unk_010 * 0xFF) / 10;
    if (arg0->unk_010 <= 0) {
        func_82F07214(arg0, 0);
        D_82F210D8[1] = -1;
    }
}

void func_82F07784(unk_D_82F20A88* arg0) {
    func_82F07498(arg0);
    arg0->unk_010--;
    arg0->unk_018 = arg0->unk_010 / 10.0f;
    if (arg0->unk_010 <= 0) {
        func_82F07214(arg0, 0);
    }
}

void func_82F077E0(void) {
    s32 i;
    unk_D_82F20A88* var_s0 = &D_82F20A88[0];

    for (i = 0; i < D_82F210D0; i++, var_s0++) {
        switch (var_s0->unk_000) {
            case 0:
            case 1:
                break;

            case 2:
                func_82F07440(var_s0);
                break;

            case 4:
                func_82F0761C(var_s0);
                break;

            case 3:
                func_82F0763C(var_s0);
                break;

            case 6:
                func_82F07784(var_s0);
                break;

            case 5:
                func_82F07728(var_s0);
                break;
        }

        if (var_s0->unk_000 != 0) {
            unk_D_86002F58_004_000* ptr = &var_s0->unk_028;

            func_8000E88C(&ptr->unk_024, var_s0->unk_006 - 320.0f, 240.0f - var_s0->unk_008, -579.0f);
            ptr->unk_01E.z = var_s0->unk_012;
            ptr->unk_01D = var_s0->unk_014;
            ptr->unk_030.x = var_s0->unk_01C * var_s0->unk_018;
            ptr->unk_030.y = var_s0->unk_020 * var_s0->unk_018;
        }
    }
}

void func_82F07958(void) {
    unk_D_82F20A40* ptr = &D_82F20A40;
    s32 i;

    ptr->unk_00 = 1;
    ptr->unk_02 = 0xA;
    ptr->unk_04 = 0;
    ptr->unk_06.unk_00 = 0x40;
    ptr->unk_06.unk_02 = 0x8C;
    ptr->unk_06.unk_04 = 0x200;
    ptr->unk_06.unk_06 = 0;

    for (i = 0; i < 3; i++) {
        ptr->unk_0E[i].unk_00 = 0x7C + i * 0x88;
        ptr->unk_0E[i].unk_02 = 0x10C;
        ptr->unk_0E[i].unk_04 = 0x78;
        ptr->unk_0E[i].unk_06 = 0;
    }

    ptr->unk_26.unk_00 = 0x38;
    ptr->unk_26.unk_02 = 0x1A4;
    ptr->unk_26.unk_04 = 0x210;
    ptr->unk_26.unk_06 = 0;
    ptr->unk_2E.unk_00 = 0xCC;
    ptr->unk_2E.unk_02 = 0x130;
    ptr->unk_2E.unk_04 = 0xE8;
    ptr->unk_2E.unk_06 = 0;
    ptr->unk_36.unk_00 = 0;
    ptr->unk_36.unk_02 = 0;
    ptr->unk_36.unk_04 = 0;
    ptr->unk_36.unk_06 = 0;

    D_82F210D8[1] = -1;
    D_82F210D2 = -1;

    if (D_82F20A88[0].unk_004 == 0) {
        D_82F210D2 = 0;
    }
}

s32 func_82F07A54(s16 arg0) {
    return D_82F210D8[arg0];
}

s32 func_82F07A74(void) {
    return D_82F20A40.unk_00;
}

void func_82F07A80(unk_D_82F20A40* arg0, s32 arg1) {
    s32 i;

    arg0->unk_02--;
    if (arg1 != 0) {
        arg0->unk_06.unk_00 = 0x40 - ((arg0->unk_02 * 0) / 10);
        arg0->unk_06.unk_02 = 0x48 - ((arg0->unk_02 * -0x44) / 10);
        arg0->unk_06.unk_04 = 0x200 - ((arg0->unk_02 * 0) / 10);
        arg0->unk_06.unk_06 = 0x88 - ((arg0->unk_02 * 0x88) / 10);
    }

    for (i = 0; i < 3; i++) {
        arg0->unk_0E[i].unk_00 = ((i * 0x88) - ((arg0->unk_02 * 0) / 10)) + 0x7C;
        arg0->unk_0E[i].unk_02 = 0xF0 - ((arg0->unk_02 * -0x1C) / 10);
        arg0->unk_0E[i].unk_04 = 0x78 - ((arg0->unk_02 * 0) / 10);
        arg0->unk_0E[i].unk_06 = 0x38 - ((arg0->unk_02 * 0x38) / 10);
    }

    if (arg1 != 0) {
        arg0->unk_26.unk_00 = 0x38 - ((arg0->unk_02 * 0) / 10);
        arg0->unk_26.unk_02 = 0x190 - ((arg0->unk_02 * -0x14) / 10);
        arg0->unk_26.unk_04 = 0x210 - ((arg0->unk_02 * 0) / 10);
        arg0->unk_26.unk_06 = 0x28 - ((arg0->unk_02 * 0x28) / 10);
    }

    if (arg0->unk_02 <= 0) {
        arg0->unk_00 = 2;
        arg0->unk_02 = 0;
        func_82F07214(D_82F20A88, 1);

        for (i = 0; i < 3; i++) {
            if (D_82F20A88[i + 1].unk_002 != -1) {
                func_82F07214(&D_82F20A88[i + 1], 2);
            }
        }
    }
}

void func_82F07DEC(unk_D_82F20A40* arg0) {
    s32 i;
    s16 tmp;

    MathUtil_Random16();

    tmp = D_82F210D2;

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DLEFT) && (D_82F210D2 != -1) && (D_82F210D2 > 0)) {
        D_82F210D2 -= 1;
    }

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DRIGHT) && (D_82F210D2 != -1) && (D_82F210D2 < (D_82F210D0 - 2))) {
        D_82F210D2 += 1;
    }

    if (D_82F210D2 != tmp) {
        func_80048B90(0x25);
    }

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A) && (D_82F210D2 != -1)) {
        if (D_82F20A88[D_82F210D2 + 1].unk_004 == 0) {
            arg0->unk_00 = 6;
            arg0->unk_02 = 0xA;

            for (i = 0; i < 3; i++) {
                if (D_82F20A88[i + 1].unk_002 != -1) {
                    if (i != D_82F210D2) {
                        func_82F07214(&D_82F20A88[i + 1], 6);
                    } else {
                        func_82F07214(&D_82F20A88[i + 1], 3);
                    }
                }
            }
            func_80048B90(2);
        } else {
            arg0->unk_00 = 3;
            arg0->unk_02 = 0xA;
            arg0->unk_04 = D_82F20A88[D_82F210D2 + 1].unk_004;

            switch (arg0->unk_04) {
                case 1:
                    arg0->unk_40 = &D_82F13EEC;
                    arg0->unk_44 = &D_82F13EF4;
                    break;

                case 2:
                    arg0->unk_40 = &D_82F13EFC;
                    arg0->unk_44 = &D_82F13F04;
                    break;

                case 3:
                    arg0->unk_40 = &D_82F13F0C;
                    arg0->unk_44 = &D_82F13F14;
                    break;

                case 4:
                    arg0->unk_40 = &D_82F13F1C;
                    arg0->unk_44 = &D_82F13F24;
                    break;

                default:
                    arg0->unk_44 = NULL;
                    arg0->unk_40 = NULL;
                    break;
            }
        }
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
        arg0->unk_00 = 0xB;
        arg0->unk_02 = 0xA;

        for (i = 0; i < 4; i++) {
            func_82F07214(&D_82F20A88[i], 0);
        }

        func_80048B90(3);
    }
}

void func_82F08084(unk_D_82F20A40* arg0) {
    arg0->unk_02--;
    arg0->unk_36.unk_00 = arg0->unk_44->unk_00 - (((arg0->unk_44->unk_00 - arg0->unk_40->unk_00) * arg0->unk_02) / 10);
    arg0->unk_36.unk_02 = arg0->unk_44->unk_02 - (((arg0->unk_44->unk_02 - arg0->unk_40->unk_02) * arg0->unk_02) / 10);
    arg0->unk_36.unk_04 = arg0->unk_44->unk_04 - (((arg0->unk_44->unk_04 - arg0->unk_40->unk_04) * arg0->unk_02) / 10);
    arg0->unk_36.unk_06 = arg0->unk_44->unk_06 - (((arg0->unk_44->unk_06 - arg0->unk_40->unk_06) * arg0->unk_02) / 10);
    if (arg0->unk_02 <= 0) {
        arg0->unk_00 = 4;
        arg0->unk_02 = 0;
    }
}

void func_82F081FC(unk_D_82F20A40* arg0) {
    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A | BTN_B)) {
        arg0->unk_00 = 5;
        arg0->unk_02 = 0xA;
    }
}

void func_82F0822C(unk_D_82F20A40* arg0) {
    arg0->unk_02--;
    arg0->unk_36.unk_00 = arg0->unk_40->unk_00 - (((arg0->unk_40->unk_00 - arg0->unk_44->unk_00) * arg0->unk_02) / 10);
    arg0->unk_36.unk_02 = arg0->unk_40->unk_02 - (((arg0->unk_40->unk_02 - arg0->unk_44->unk_02) * arg0->unk_02) / 10);
    arg0->unk_36.unk_04 = arg0->unk_40->unk_04 - (((arg0->unk_40->unk_04 - arg0->unk_44->unk_04) * arg0->unk_02) / 10);
    arg0->unk_36.unk_06 = arg0->unk_40->unk_06 - (((arg0->unk_40->unk_06 - arg0->unk_44->unk_06) * arg0->unk_02) / 10);
    if (arg0->unk_02 <= 0) {
        arg0->unk_00 = 2;
        arg0->unk_02 = 0;
        arg0->unk_04 = 0;
        arg0->unk_44 = NULL;
        arg0->unk_40 = NULL;
    }
}

void func_82F083B0(unk_D_82F20A40* arg0, s16 arg1, s16 arg2) {
    unk_D_82F20A40_00E* ptr;
    s32 i;
    s32 tmp;

    for (i = 0; i < 3; i++) {
        ptr = &arg0->unk_0E[i];

        if ((ptr->unk_04 == 0x78) && (ptr->unk_06 == 0)) {
            continue;
        }

        tmp = (ptr->unk_00 * 0) / arg2;

        ptr->unk_00 = (0x7C + (i * 0x88)) - (tmp);
        ptr->unk_02 = 0x10C - ((arg1 * 0x1C) / arg2);
        ptr->unk_04 = 0x78 - (tmp);
        ptr->unk_06 = -((arg1 * -0x38) / arg2);
    }
}

void func_82F084EC(unk_D_82F20A40* arg0) {
    s32 i;

    arg0->unk_02--;
    func_82F083B0(arg0, arg0->unk_02, 0xA);
    if (arg0->unk_02 <= 0) {
        arg0->unk_00 = 7;
        arg0->unk_02 = 0xA;

        for (i = 0; i < 3; i++) {
            arg0->unk_0E[i].unk_00 = 0x7C + i * 0x88;
            arg0->unk_0E[i].unk_02 = 0x10C;
            arg0->unk_0E[i].unk_04 = 0x78;
            arg0->unk_0E[i].unk_06 = 0;
        }
    }
}

void func_82F0856C(unk_D_82F20A40* arg0) {
    arg0->unk_02--;
    arg0->unk_2E.unk_00 = 0xCC - (arg0->unk_02 * 0) / 10;
    arg0->unk_2E.unk_02 = 0xF8 - ((arg0->unk_02 * -0x38) / 10);
    arg0->unk_2E.unk_04 = 0xE8 - (arg0->unk_02 * 0) / 10;
    arg0->unk_2E.unk_06 = 0x70 - ((arg0->unk_02 * 0x70) / 10);
    if (arg0->unk_02 <= 0) {
        arg0->unk_00 = 8;
        arg0->unk_02 = 0;
        D_82F210D4 = 0;
    }
}

void func_82F0866C(unk_D_82F20A40* arg0) {
    s16 tmp;
    s32 var_a2;

    var_a2 = 0;
    tmp = D_82F210D4;

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP) && (D_82F210D4 > 0)) {
        D_82F210D4 -= 1;
    }

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DDOWN) && (D_82F210D4 <= 0)) {
        D_82F210D4 += 1;
    }

    if (D_82F210D4 != tmp) {
        func_80048B90(1);
    }

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        var_a2 = 1;
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
        var_a2 = 1;
        D_82F210D4 = 1;
    }

    if (var_a2 != 0) {
        if (D_82F210D4 == 0) {
            arg0->unk_00 = 0xB;
            arg0->unk_02 = 0xA;
            func_82F07214(D_82F20A88, 0);
            func_82F07214(&D_82F20A88[D_82F210D2 + 1], 0);
            func_80048B90(0x1B);
        } else {
            arg0->unk_00 = 9;
            arg0->unk_02 = 0xA;
            func_82F07214(&D_82F20A88[D_82F210D2 + 1], 5);
            func_80048B90(3);
        }
    }
}

void func_82F087F8(unk_D_82F20A40_00E* arg0, s16 arg1, s16 arg2) {
    if ((arg0->unk_04 != 0xE8) || (arg0->unk_06 != 0)) {
        s32 tmp = (arg0->unk_00 * 0) / arg2;

        arg0->unk_00 = 0xCC - tmp;
        arg0->unk_02 = 0x130 - ((arg1 * 0x38) / arg2);
        arg0->unk_04 = 0xE8 - tmp;
        arg0->unk_06 = -((arg1 * -0x70) / arg2);
    }
}

void func_82F088F8(unk_D_82F20A40* arg0) {
    if (arg0->unk_02 > 0) {
        arg0->unk_02--;
    }

    func_82F087F8(&arg0->unk_2E, arg0->unk_02, 0xA);

    if ((arg0->unk_02 <= 0) && (D_82F210D8[1] == -1)) {
        arg0->unk_00 = 0xA;
        arg0->unk_02 = 0xA;
    }
}

void func_82F08968(unk_D_82F20A40* arg0) {
    arg0->unk_02--;
    arg0->unk_06.unk_00 = 0x40 - (arg0->unk_02 * 0) / 10;
    arg0->unk_06.unk_02 = 0x8C - ((arg0->unk_02 * 0x44) / 10);
    arg0->unk_06.unk_04 = 0x200 - (arg0->unk_02 * 0) / 10;
    arg0->unk_06.unk_06 = -((arg0->unk_02 * -0x88) / 10);

    func_82F083B0(arg0, arg0->unk_02, 0xA);
    func_82F087F8(&arg0->unk_2E, arg0->unk_02, 0xA);

    arg0->unk_26.unk_00 = 0x38 - (arg0->unk_02 * 0) / 10;
    arg0->unk_26.unk_02 = 0x1A4 - ((arg0->unk_02 * 0x14) / 10);
    arg0->unk_26.unk_04 = 0x210 - (arg0->unk_02 * 0) / 10;
    arg0->unk_26.unk_06 = -((arg0->unk_02 * -0x28) / 10);

    if (arg0->unk_02 <= 0) {
        arg0->unk_00 = 0;
        arg0->unk_02 = 0;
    }
}

void func_82F08B7C(unk_D_82F20A40* arg0) {
    Color_RGB8* var_v0;
    unk_D_82F20A40_00E* temp_s4 = &arg0->unk_06;
    s32 i;
    unk_D_82F14450* ptr;

    func_82F022DC(temp_s4->unk_00, temp_s4->unk_02, temp_s4->unk_04, temp_s4->unk_06);

    if ((temp_s4->unk_04 == 0x200) && (temp_s4->unk_06 == 0x88)) {
        gSPDisplayList(gDisplayListHead++, D_8006F498);

        func_8001C604(temp_s4->unk_00, temp_s4->unk_02, temp_s4->unk_04, temp_s4->unk_06, 0x32, 0x32, 0x96, 0xFF);

        gSPDisplayList(gDisplayListHead++, D_8006F630);

        for (i = 0; i < 2; i++) {
            Color_RGB8 sp5C = { 0x1E, 0x1E, 0x64 };
            Color_RGB8 sp58 = { 0x64, 0x64, 0xC8 };

            if (D_82F210D8[i] == -1) {
                var_v0 = &sp58;
            } else {
                var_v0 = &sp5C;
            }

            func_82F02FEC(temp_s4->unk_00 + (i * 0x110) + 0x10, temp_s4->unk_02 + 0x28, 0xD0, 0x50, var_v0->r,
                          var_v0->g, var_v0->b, 0xFF);
        }

        func_82F097D8(temp_s4->unk_00 + 0xE0, temp_s4->unk_02 + 0x28);
        func_8001F3F4();
        func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
        func_8001EBE0(0x10, 0);
        func_8001F1E8(temp_s4->unk_00 + 0x5A, temp_s4->unk_02 + 8, func_8002D7C0(NULL, 0, D_82F13B70, 1));

        for (i = 0; i < 2; i++) {
            if (D_82F210D8[i] != -1) {
                if (i == 0) {
                    if (D_82F20A88[0].unk_004 == 0) {
                        func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
                    } else {
                        func_8001F324(0xFF, 0xFF, 0xFF, 0x80);
                    }
                } else {
                    func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
                }

                ptr = &D_82F14450[D_82F210D8[i]];
                if (ptr) {}

                func_8001EBE0(0x10, 0);
                func_8001F1E8(temp_s4->unk_00 + (i * 0x110) + 0x24, temp_s4->unk_02 + 0x3C, ptr->unk_08);
                func_8001EBE0(8, 0);
                func_8001F1E8(temp_s4->unk_00 + (i * 0x110) + 0x24, temp_s4->unk_02 + 0x54, "ID%05d", ptr->unk_06);
            }
        }

        func_8001F444();
    }
}

void func_82F08EB4(unk_D_82F20A40* arg0) {
    s32 i;
    Color_RGB8* var_v0;
    s32 var_v1;
    char* var_s0_2;
    unk_D_82F14450* var_s2;
    Color_RGB8 sp88 = { 0x1E, 0x1E, 0x82 };
    Color_RGB8 sp84 = { 0x64, 0x1E, 0x1E };
    char sp68[28];
    unk_D_82F20A40_00E* ptr;

    for (i = 0; i < 3; i++) {
        ptr = &arg0->unk_0E[i];

        if ((arg0->unk_0E[i].unk_04 == 0x78) && (ptr->unk_06 == 0)) {
            continue;
        }

        if (D_82F20A88[i + 1].unk_002 == -1) {
            var_v1 = 0x80;
        } else {
            var_v1 = 0xFF;
        }

        if (D_82F20A88[i + 1].unk_004 == 0) {
            var_v0 = &sp88;
        } else {
            var_v0 = &sp84;
        }

        func_82F037EC(ptr->unk_00, ptr->unk_02, ptr->unk_04, ptr->unk_06, var_v0->r, var_v0->g, var_v0->b, var_v1);
    }

    func_8001F3F4();
    func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);

    for (i = 0; i < 3; i++) {
        var_s2 = NULL;
        if (D_82F20A88[i + 1].unk_002 == -1) {
            continue;
        }

        ptr = &arg0->unk_0E[i];

        switch (D_82F20A88[i + 1].unk_004) {
            case 0:
            case 3:
            case 4:
                var_s2 = &D_82F14450[D_82F20A88[i + 1].unk_002];
                break;
        }

        if ((arg0->unk_0E[i].unk_04 == 0x78) && (ptr->unk_06 == 0x38)) {
            func_8001EBE0(8, 0);
            if (var_s2 != NULL) {
                var_s0_2 = var_s2->unk_08;
            } else {
                var_s0_2 = "?????";
            }

            func_8001F1E8(((ptr->unk_04 - func_8001F5B0(0, 0, var_s0_2)) / 2) + ptr->unk_00, ptr->unk_02 + 8, var_s0_2);
            func_8001EBE0(4, 0);

            if (var_s2 != NULL) {
                sprintf(sp68, "ID%05d", var_s2->unk_06);
                var_s0_2 = sp68;
            } else {
                var_s0_2 = "ID*****";
            }

            func_8001F1E8(((ptr->unk_04 - func_8001F5B0(0, 0, var_s0_2)) / 2) + ptr->unk_00, ptr->unk_02 + 0x20,
                          var_s0_2);
        }
    }

    func_8001F444();
}

void func_82F0917C(unk_D_82F20A40* arg0) {
    unk_D_82F20A40_00E* temp_s1 = &arg0->unk_26;
    char* temp_v0;

    func_82F037EC(arg0->unk_26.unk_00, arg0->unk_26.unk_02, arg0->unk_26.unk_04, arg0->unk_26.unk_06, 0x1E, 0x1E, 0x82,
                  0xFF);
    if ((temp_s1->unk_04 == 0x210) && (temp_s1->unk_06 == 0x28)) {
        func_8001F3F4();
        func_8001EBE0(0x10, 0);
        func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
        temp_v0 = func_8002D7C0(NULL, 0, D_82F13B70, 2);
        func_8001F1E8((temp_s1->unk_00 - (func_8001F5B0(0, 0, temp_v0) / 2)) + 0x108, temp_s1->unk_02 + 8, temp_v0);
        func_8001F444();
    }
}

void func_82F09284(unk_D_82F20A40* arg0) {
    char* temp_v0;
    unk_D_82F20A40_00E* temp_s3 = &arg0->unk_2E;
    s32 i;
    s32 tmp;
    Color_RGB8 sp54 = { 0x1E, 0x1E, 0x82 };
    char* sp4C[2];

    if ((temp_s3->unk_04 == 0xE8) && (temp_s3->unk_06 == 0)) {
        return;
    }

    if ((temp_s3->unk_04 >= 0xE) && (temp_s3->unk_06 >= 0xE)) {
        func_8002053C(temp_s3->unk_00, temp_s3->unk_02, temp_s3->unk_04, temp_s3->unk_06, &sp54, &sp54);
    }

    if ((temp_s3->unk_04 != 0xE8) || (temp_s3->unk_06 != 0x70)) {
        return;
    }

    func_8001F3F4();
    func_8001EBE0(0x10, 0);
    func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
    temp_v0 = func_8002D7C0(NULL, 0, D_82F13B70, 3);
    tmp = (temp_s3->unk_00 - (func_8001F5B0(0, 0, temp_v0) / 2)) + 0x74;
    func_8001F1E8(tmp, temp_s3->unk_02 + 0x10, temp_v0);

    for (i = 0; i < 2; i++) {
        sp4C[0] = func_8002D7C0(NULL, 0, D_82F13B70, 4);
        sp4C[1] = func_8002D7C0(NULL, 0, D_82F13B70, 5);
        if (i != D_82F210D4) {
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
        } else {
            func_8001F324(0xFF, 0xFF, 0, 0xFF);
        }
        // clang-format off
        tmp = (temp_s3->unk_00 - (func_8001F5B0(0, 0, sp4C[i]) / 2)) + 0x74; func_8001F1E8(tmp, temp_s3->unk_02 + (i * 0x1C) + 0x2C, sp4C[i]);
        // clang-format on
    }

    func_8001F444();
}

void func_82F094B4(unk_D_82F20A40* arg0) {
    UNUSED s32 pad;
    char* sp48;
    unk_D_82F20A40_00E* temp_s0 = &arg0->unk_36;
    Color_RGB8 sp40 = { 0x64, 0x1E, 0x1E };

    if (arg0->unk_04 == 0) {
        return;
    }

    if ((arg0->unk_40 == NULL) || (arg0->unk_44 == NULL)) {
        return;
    }

    if ((arg0->unk_36.unk_04 != arg0->unk_40->unk_04) || (arg0->unk_36.unk_06 != arg0->unk_40->unk_06)) {

        if ((temp_s0->unk_04 >= 0xE) && (temp_s0->unk_06 >= 0xE)) {
            func_8002053C(temp_s0->unk_00, temp_s0->unk_02, temp_s0->unk_04, temp_s0->unk_06, &sp40, &sp40);
        }

        if ((temp_s0->unk_04 >= arg0->unk_44->unk_04) && (temp_s0->unk_06 >= arg0->unk_44->unk_06)) {
            func_8001F3F4();
            func_8001EBE0(0x10, 0);
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            func_8001F3B4(0x1A);

            switch (arg0->unk_04) {
                case 1:
                    sp48 = func_8002D7C0(NULL, 0, D_82F13B70, 6);
                    func_8001F1E8((temp_s0->unk_00 + (temp_s0->unk_04 / 2)) - (func_8001F5B0(0, 0, sp48) / 2),
                                  temp_s0->unk_02 + 0x10, sp48);
                    break;

                case 2:
                    sp48 = func_8002D7C0(NULL, 0, D_82F13B70, 7);
                    func_8001F1E8((temp_s0->unk_00 + (temp_s0->unk_04 / 2)) - (func_8001F5B0(0, 0, sp48) / 2),
                                  temp_s0->unk_02 + 0x10, sp48);
                    break;

                case 3:
                    sp48 = func_8002D7C0(NULL, 0, D_82F13B70, 8);
                    func_8001F1E8((temp_s0->unk_00 + (temp_s0->unk_04 / 2)) - (func_8001F5B0(0, 0, sp48) / 2),
                                  temp_s0->unk_02 + 0x10, sp48);
                    break;

                case 4:
                    sp48 = func_8002D7C0(NULL, 0, D_82F13B70, 9);
                    func_8001F1E8((temp_s0->unk_00 + (temp_s0->unk_04 / 2)) - (func_8001F5B0(0, 0, sp48) / 2),
                                  temp_s0->unk_02 + 0x10, sp48);
                    break;
            }

            func_8001F444();
        }
    }
}

void func_82F097D8(s16 arg0, s16 arg1) {
    static s16 D_82F13F5C = 0;

    s16 sp86 = ROUND_MAX(2.0f * SINS(D_82F13F5C));

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPLoadTextureBlock(gDisplayListHead++, D_302AC68, G_IM_FMT_RGBA, G_IM_SIZ_16b, 48, 24, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    func_8001C330(arg0 + sp86, arg1, 0x30, 0x18, 0, 0, 0x400, 0x400, 0);
    func_8001C330((arg0 - sp86) + 0x10, arg1 + 0x28, 0x30, 0x18, 0x600, 0, -0x400, 0x400, 0);

    gDPLoadTextureBlock(gDisplayListHead++, D_302B568, G_IM_FMT_RGBA, G_IM_SIZ_16b, 48, 24, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    func_8001C330(arg0 + sp86, arg1 + 0x18, 0x30, 0x18, 0, 0, 0x400, 0x400, 0);
    func_8001C330((arg0 - sp86) + 0x10, arg1 + 0x40, 0x30, 0x18, 0x600, 0, -0x400, 0x400, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    D_82F13F5C += 0x1000;
}

void func_82F09B70(s16 arg0) {
    static s16 D_82F13F60 = 0;

    s16 sp1E;
    UNUSED s16 sp1C;
    s16 sp1A;
    s32 var_v1 = 0;

    switch (arg0) {
        case 2:
            if (D_82F210D2 != -1) {
                var_v1 = 1;
                sp1E = (D_82F210D2 * 0x88) + 0x78;
                sp1A = 0x154;
            }
            break;

        case 8:
            var_v1 = 1;
            sp1E = 0xE4;
            sp1A = (D_82F210D4 * 0x1C) + 0x12A;
            break;
    }

    if (var_v1 != 0) {
        s16 sins = SINS(D_82F13F60) * 3.0f;

        func_800207FC(sp1E + sins, sp1A);
    }

    D_82F13F60 += 0x1000;
}

void func_82F09C6C(void) {
    UNUSED s32 pad;
    s32 i;
    MemoryBlock* sp1C = func_80002D10(main_pool_get_available(), 0);

    D_82F210C8 = process_geo_layout(sp1C, D_82F13E8C);
    D_82F210CC = process_geo_layout(sp1C, D_82F13E58);
    func_80002D60(sp1C);

    D_82F20A40.unk_00 = 0;
    D_82F20A40.unk_02 = 0;
    D_82F20A40.unk_04 = 0;

    for (i = 0; i < 2; i++) {
        D_82F210D8[i] = -1;
    }

    D_82F210D8[0] = func_80029080();
    D_82F210D2 = 0;
    func_82F07004(D_82F210D8[0]);
}

void func_82F09D2C(void) {
    unk_D_82F20A40* ptr = &D_82F20A40;

    if (ptr->unk_00 == 0) {
        return;
    }

    switch (ptr->unk_00) {
        case 1:
            func_82F07A80(ptr, 1);
            break;

        case 10:
            func_82F07A80(ptr, 0);
            break;

        case 2:
            func_82F07DEC(ptr);
            break;

        case 3:
            func_82F08084(ptr);
            break;

        case 4:
            func_82F081FC(ptr);
            break;

        case 5:
            func_82F0822C(ptr);
            break;

        case 6:
            func_82F084EC(ptr);
            break;

        case 7:
            func_82F0856C(ptr);
            break;

        case 8:
            func_82F0866C(ptr);
            break;

        case 9:
            func_82F088F8(ptr);
            break;

        case 11:
            func_82F08968(ptr);
            break;
    }

    func_82F077E0();
}

void func_82F09E30(void) {
    unk_D_82F20A40* ptr = &D_82F20A40;

    if (ptr->unk_00 != 0) {
        func_80015348();
        func_82F08B7C(&D_82F20A40);
        func_82F08EB4(&D_82F20A40);
        func_82F0917C(&D_82F20A40);
        func_82F09284(&D_82F20A40);
        func_80015094(D_82F210C8);
        func_82F09B70(ptr->unk_00);
        func_82F094B4(&D_82F20A40);
    }
}
