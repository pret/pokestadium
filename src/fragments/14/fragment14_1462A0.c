#include "fragment14.h"
#include "src/12D80.h"
#include "src/17300.h"
#include "src/geo_layout.h"
#include "src/19840.h"
#include "src/1C720.h"
#include "src/4CBC0.h"
#include "src/F420.h"
#include "src/fragments/2/fragment2.h"
#include "src/fragments/3/fragment3.h"
#include "src/fragments/34/fragment34.h"
#include "src/memmap.h"
#include "src/memory.h"

static f32 D_86806F90[] = { 10.0f, 30.0f, 10.0f };
static f32 D_86806F9C = 0.8f;
static f32 D_86806FA0 = 0.2f;
static f32 D_86806FA4 = 0.2f;
static f32 D_86806FA8 = -5.0f;
static f32 D_86806FAC = 0.9f;
static f32 D_86806FB0 = 20.0f;
static f32 D_86806FB4 = 20.0f;
static f32 D_86806FB8 = 130.0f;
static f32 D_86806FBC = 30.0f;
static f32 D_86806FC0 = 20.0f;
static f32 D_86806FC4 = 14681.355f;

static char D_86806FC8[] = " Mie";

static Vtx D_86806FD0[] = {
    VTX(-18, 26, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-18, 0, 0, 0, 832, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(18, 0, 0, 1152, 832, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(18, 26, 0, 1152, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};

static Gfx D_86807010[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_86806FD0, 4, 0),
    gsDPLoadTextureBlock(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_32b, 36, 26, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};

static u32 D_86807078[] = {
    0x17000000, 0x00000000, 0x00000000, 0x00000000, 0x86806FD0, 0x05000000, 0x22040000,
    0x00000000, 0x08000000, 0x86802084, 0x00000000, 0x06000000, 0x01000000,
};
static Controller** D_868070AC[] = {
    &gPlayer1Controller,
    &gPlayer2Controller,
    &gPlayer3Controller,
    &gPlayer4Controller,
};
static s32 D_868070BC[4][4] = {
    {
        0x00000002,
        0x00000001,
        0x00000001,
        0x00000002,
    },
    {
        0x00000003,
        0x00000002,
        0x00000001,
        0x00000002,
    },
    {
        0x00000003,
        0x00000002,
        0x00000002,
        0x00000003,
    },
    {
        0x00000003,
        0x00000003,
        0x00000002,
        0x00000003,
    },
};

static unk_D_86002F30* D_86807550;
unk_D_86807558 D_86807558[4];
s32 D_86808438[4];
static s32 D_86808448;
static Controller D_86808450;
static unk_D_86002F58_004_000_004* D_86808474;
static s16 D_86808478;
static s16 D_8680847A;
static s16 D_8680847C;
static s16 D_8680847E;
static s16 D_86808480;
static s32 pad_D_86808488[2];
static unk_D_86002F34_00C* D_86808490;
unk_D_86808498 D_86808498;

void func_86801FC0(unk_D_86807558* arg0) {
    unk_D_86002F58_004_000* ptr = &arg0->unk_24C;

    if (arg0->unk_0DC != 0) {
        ptr->unk_030.x = (SINS(arg0->unk_0E2 + 0x0000) * 0.3f) + 1.0f;
        ptr->unk_030.y = (SINS(arg0->unk_0E2 + 0x3200) * 0.3f) + 1.0f;
    } else {
        ptr->unk_030.y = 1.0f;
        ptr->unk_030.x = 1.0f;
    }

    ptr->unk_024 = arg0->unk_0E4.unk_0FC;

    if (D_8780FC94 == 0) {
        arg0->unk_0E2 += 0x1800;
    }
}

void func_86802084(s32 arg0, UNUSED s32 arg1) {
    UNUSED s32 pad;
    s32 idx;

    switch (arg0) {
        case 2:
            idx = D_8006F09C->unk_000.unk_14;
            func_86801FC0(&D_86807558[idx]);
            break;

        case 5:
            idx = D_8006F09C->unk_000.unk_14;
            gSPSegment(gDisplayListHead++, 0x0F, Memmap_GetSegmentVaddr(D_86807558[idx].unk_3B4));

            gDPPipeSync(gDisplayListHead++);

            gDPSetRenderMode(gDisplayListHead++,
                             AA_EN | Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | ALPHA_CVG_SEL | G_RM_PASS,
                             AA_EN | Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | ALPHA_CVG_SEL |
                                 GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM));
            gDPSetEnvColor(gDisplayListHead++, D_8006F09C->unk_03C.r, D_8006F09C->unk_03C.g, D_8006F09C->unk_03C.b,
                           D_8006F09C->unk_01D);
            gSPDisplayList(gDisplayListHead++, D_86807010);

            func_8001554C();
            func_80015684();
            break;
    }
}

s32 func_86802204(unk_D_86807558_098* arg0) {
    f32 temp_fs0;

    arg0->unk_00.x = ABS_NORMALIZED(arg0->unk_00.x);
    arg0->unk_00.y = ABS_NORMALIZED(arg0->unk_00.y);
    arg0->unk_00.z = ABS_NORMALIZED(arg0->unk_00.z);

    arg0->unk_0C.x = ABS_NORMALIZED(arg0->unk_0C.x);
    arg0->unk_0C.y = ABS_NORMALIZED(arg0->unk_0C.y);
    arg0->unk_0C.z = ABS_NORMALIZED(arg0->unk_0C.z);

    temp_fs0 = SQ(arg0->unk_00.x) + SQ(arg0->unk_00.y) + SQ(arg0->unk_00.z);
    if (temp_fs0 == 0.0f) {
        return -1;
    }

    temp_fs0 = 1.0f / sqrtf(temp_fs0);
    arg0->unk_00.x *= temp_fs0;
    arg0->unk_00.y *= temp_fs0;
    arg0->unk_00.z *= temp_fs0;

    arg0->unk_18.x = (arg0->unk_0C.y * arg0->unk_00.z) - (arg0->unk_0C.z * arg0->unk_00.y);
    arg0->unk_18.y = (arg0->unk_0C.z * arg0->unk_00.x) - (arg0->unk_0C.x * arg0->unk_00.z);
    arg0->unk_18.z = (arg0->unk_0C.x * arg0->unk_00.y) - (arg0->unk_0C.y * arg0->unk_00.x);

    temp_fs0 = SQ(arg0->unk_18.x) + SQ(arg0->unk_18.y) + SQ(arg0->unk_18.z);
    if (temp_fs0 == 0.0f) {
        return -1;
    }

    temp_fs0 = 1.0f / sqrtf(temp_fs0);
    arg0->unk_18.x *= temp_fs0;
    arg0->unk_18.y *= temp_fs0;
    arg0->unk_18.z *= temp_fs0;

    arg0->unk_18.x = ABS_NORMALIZED(arg0->unk_18.x);
    arg0->unk_18.y = ABS_NORMALIZED(arg0->unk_18.y);
    arg0->unk_18.z = ABS_NORMALIZED(arg0->unk_18.z);

    arg0->unk_0C.x = (arg0->unk_00.y * arg0->unk_18.z) - (arg0->unk_00.z * arg0->unk_18.y);
    arg0->unk_0C.y = (arg0->unk_00.z * arg0->unk_18.x) - (arg0->unk_00.x * arg0->unk_18.z);
    arg0->unk_0C.z = (arg0->unk_00.x * arg0->unk_18.y) - (arg0->unk_00.y * arg0->unk_18.x);

    return 0;
}

s16 func_8680262C(unk_D_86002F58_004_000* arg0, s16 arg1) {
    s32 i;
    s16 sp2A;

    if (func_80017514(arg0) != 0) {
        return arg1;
    }

    sp2A = -1;

    for (i = 0; i < arg1; i++) {
        if (func_80017484(arg0, i) != 0) {
            sp2A = i;
            break;
        }
    }

    return sp2A;
}

s16 func_868026B8(s16 arg0) {
    s16 ret;

    if (arg0 < 0x32) {
        ret = 2;
    } else {
        ret = 1;
    }
    return ret;
}

f32 func_868026E0(s16 arg0) {
    f32 var_fv1 = (2.0f * arg0) / 100.0f;

    if (var_fv1 < 0.5f) {
        var_fv1 = 0.5f;
    }
    return var_fv1;
}

void func_86802728(unk_D_86807558_040* arg0) {
    arg0->unk_00 = 0;
    arg0->unk_02 = 0;
    arg0->unk_18 = 0xFF;
    arg0->unk_0C = 0.0f;
    arg0->unk_08 = 0.0f;
    arg0->unk_14 = 0.0f;
    arg0->unk_10 = 0.0f;
}

void func_86802750(unk_D_86807558* arg0, s32 arg1, s32 arg2) {
    s32 i;
    unk_D_86002F58_004_000* sp24;
    s16 angle;
    f32 sqrt;

    arg0->unk_000 = arg1;
    arg0->unk_002 = 0;

    if (D_8780FA30[arg0->unk_000] == 1) {
        arg0->unk_002 |= 4;
    }

    if (arg2 != 0) {
        arg0->unk_002 |= 0x10;
    }

    arg0->unk_004 = 0x32;
    arg0->unk_006 = 0;

    if (arg0->unk_002 & 4) {
        arg0->unk_008 = D_868070BC[D_8780FA38][(D_8680847C + D_8680847A) % D_8680847E];
        arg0->unk_00C = D_8680847A;
        if (arg0->unk_00C == 0) {
            D_86808478 = arg0->unk_000;
        }

        D_8680847A++;

        if ((arg2 != 0) && (func_878001E8(4) == 0) && (D_86808480 <= 0)) {
            arg0->unk_008 = 4;
            D_86808480++;
        }
    } else {
        arg0->unk_008 = 0;
        arg0->unk_00C = 0x64;
    }

    arg0->unk_010 = 0;
    arg0->unk_014 = 0;
    arg0->unk_016 = 0;

    if (arg0->unk_002 & 4) {
        arg0->unk_016 |= 1;
        if ((arg0->unk_008 == 4) || (D_8780FA38 == 0)) {
            arg0->unk_016 &= ~1;
        }

        if (D_8780FA38 >= 2) {
            arg0->unk_016 |= 2;
        }
    }

    arg0->unk_018 = 0;
    arg0->unk_01C = 0;
    arg0->unk_020 = 0;
    arg0->unk_024 = 0;
    arg0->unk_028 = 0;
    arg0->unk_02A = 0;

    for (i = 0; i < 9; i++) {
        arg0->unk_02C[i] = 0;
    }

    arg0->unk_05C = 0;
    arg0->unk_03E = 1;

    func_86802728(&arg0->unk_040);
    arg0->unk_060 = 0;
    arg0->unk_064 = *D_868070AC[arg0->unk_000];

    angle = 0xE000 - (arg0->unk_000 << 0xE);

    arg0->unk_068.x = SINS(angle) * D_86806FB8;
    arg0->unk_068.y = 0.0f;
    arg0->unk_068.z = COSS(angle) * D_86806FB8;

    arg0->unk_074.x = 0.0f;
    arg0->unk_074.y = 0.0f;
    arg0->unk_074.z = 0.0f;

    arg0->unk_080.x = 0.0f;
    arg0->unk_080.y = 0.0f;
    arg0->unk_080.z = 0.0f;

    arg0->unk_08C.x = 0.0f;
    arg0->unk_08C.y = 0.0f;
    arg0->unk_08C.z = 0.0f;

    arg0->unk_098.unk_00.x = arg0->unk_068.x;
    arg0->unk_098.unk_00.y = 0.0f;
    arg0->unk_098.unk_00.z = arg0->unk_068.z;

    sqrt = sqrtf(SQ(arg0->unk_098.unk_00.x) + SQ(arg0->unk_098.unk_00.z));
    arg0->unk_098.unk_00.x *= 1.0f / sqrt;
    arg0->unk_098.unk_00.z *= 1.0f / sqrt;
    arg0->unk_098.unk_0C.x = 0.0f;
    arg0->unk_098.unk_0C.y = 1.0f;
    arg0->unk_098.unk_0C.z = 0.0f;

    func_86802204(&arg0->unk_098);

    arg0->unk_0BC = 0;
    arg0->unk_0BE = func_878001E8(0x5B) + 0x1E;
    arg0->unk_0C0 = 0;
    arg0->unk_0C4 = 0;
    arg0->unk_0CC = 0;
    arg0->unk_0D0.rgba = -0x100;
    arg0->unk_0C8 = 1.0f;
    arg0->unk_0D4 = func_868026B8(arg0->unk_004);
    arg0->unk_0D8 = func_868026E0(arg0->unk_004);
    arg0->unk_0DC = 0;
    arg0->unk_0E0 = 0;
    arg0->unk_0E2 = 0;

    sp24 = &arg0->unk_0E4;
    func_8001BB58(sp24);
    func_8001BB58(&arg0->unk_24C);

    arg0->unk_24C.unk_000.unk_14 = arg0->unk_000;

    func_8001BC34(sp24, 0, 0xA0, D_86807550->unk_08->unk_00[0]);
    func_8001BD04(sp24, arg0->unk_0C0);

    sp24->unk_040.unk_08 = func_878001E8(0x1E) << 0x10;

    func_8001BC34(&arg0->unk_24C, 0, 0, D_86808474);

    arg0->unk_24C.unk_000.unk_01 |= 1;
    arg0->unk_24C.unk_000.unk_02 |= 8;

    if (arg2 != 0) {
        arg0->unk_3B4 = D_8780633C[arg0->unk_000];
    } else if (arg0->unk_002 & 4) {
        arg0->unk_3B4 = D_8780634C[arg0->unk_000];
    } else {
        arg0->unk_3B4 = D_8780633C[arg0->unk_000];
    }
}

f32 func_86802BE4(s16 arg0) {
    f32 temp_fv0;
    s16 var_v1;
    s32 var_v0 = 0;

    if (arg0 < 0) {
        var_v0 = 1;
        arg0 *= -1;
    }

    if (arg0 < 0xA) {
        var_v1 = 0xA;
    } else {
        var_v1 = arg0;
    }

    if (var_v1 > 0x4A) {
        var_v1 = 0x4A;
    }

    var_v1 -= 10;
    temp_fv0 = var_v1;
    temp_fv0 /= 64;

    if (var_v0 != 0) {
        temp_fv0 = 0.0f - temp_fv0;
    }
    return temp_fv0;
}

s32 func_86802C6C(unk_D_86807558* arg0) {
    s32 sp1C = 0;
    f32 temp_fa0 = SQ(arg0->unk_068.x) + SQ(arg0->unk_068.z);

    if (SQ(D_86806FB8) < temp_fa0) {
        temp_fa0 = D_86806FB8 / sqrtf(temp_fa0);

        arg0->unk_074.x = 0.0f;
        arg0->unk_074.z = 0.0f;

        arg0->unk_068.x *= temp_fa0;
        arg0->unk_068.z *= temp_fa0;
    }

    if (arg0->unk_068.y <= 0.0f) {
        arg0->unk_068.y = 0.0f;
        arg0->unk_074.y = 0.0f;
        sp1C = 1;
    }

    return sp1C;
}

s32 func_86802D28(unk_D_86807558* arg0) {
    f32 var_fv0 = arg0->unk_068.x - D_86808498.unk_0C.x;
    s32 var_v1;

    if (var_fv0 < 0.0f) {
        if (!(var_fv0 > -280.0f)) {
            var_fv0 = -280.0f;
        }
    } else {
        if (!(var_fv0 < 280.0f)) {
            var_fv0 = 280.0f;
        }
    }

    var_fv0 = ((var_fv0 + 280.0f) * 320.0f) / 560.0f;
    var_v1 = ROUND_MAX(var_fv0);

    if (var_v1 < 0) {
        var_v1 = 0;
    } else if (var_v1 > 0x140) {
        var_v1 = 0x140;
    }
    return var_v1;
}

void func_86802E18(unk_D_86807558* arg0, u32 arg1) {
    arg0->unk_060 = arg1;

    switch (arg1) {
        case 0:
            arg0->unk_006 = 0;
            arg0->unk_0D0.rgba = -0x100;
            arg0->unk_0DC = 0;
            arg0->unk_0C0 = 0;
            arg0->unk_0C8 = 1.0f;
            break;

        case 1:
            arg0->unk_006 = 0x1E;
            arg0->unk_074.z = 0.0f;
            arg0->unk_074.x = 0.0f;
            func_8004D9B0(0x50008, arg0->unk_000 + 1, func_86802D28(arg0));
            arg0->unk_0C0 = 2;
            arg0->unk_0C8 = 1.0f;
            break;

        case 2:
            arg0->unk_006 = 0x3C;
            arg0->unk_0C0 = 7;
            arg0->unk_0DC = 0;
            arg0->unk_0C8 = 1.0f;
            func_8004D9B0(0x50009, arg0->unk_000 + 1, func_86802D28(arg0));
            break;

        case 3:
            arg0->unk_006 = 0x3C;
            arg0->unk_0C0 = 7;
            arg0->unk_0DC = 0;
            arg0->unk_0C8 = 1.0f;
            func_8004D9B0(0x5000A, arg0->unk_000 + 1, func_86802D28(arg0));
            break;

        case 4:
            arg0->unk_006 = 0;
            arg0->unk_0D0.rgba = -0x100;
            if ((arg0->unk_028 != 1) || (arg0->unk_018 == 0)) {
                arg0->unk_0C0 = 9;
                arg0->unk_24C.unk_000.unk_01 &= ~1;
            }
            arg0->unk_074.x = arg0->unk_074.z = 0.0f;
            arg0->unk_0C8 = 1.0f;
            break;
    }
}

s32 func_86802FB0(unk_D_868084D8* arg0, s32 arg1, s32 arg2) {
    if (arg0 == NULL) {
        return 1;
    }

    if (arg0->unk_0C == 0) {
        return 0;
    }

    if ((arg1 != 0) && (arg0->unk_0C == 1)) {
        return 0;
    }

    if (arg2 != 0) {
        if ((arg0->unk_10 != 1) && (arg0->unk_10 != 2)) {
            return 0;
        }
    } else if (arg0->unk_10 != 2) {
        return 0;
    }

    return 1;
}

unk_D_86807558* func_86803038(unk_D_86807558* arg0, unk_D_868084D8* arg1) {
    s32 i;
    unk_D_86807558* ret = NULL;
    unk_D_86807558* ptr;

    for (i = 0, ptr = D_86807558; i < 4; i++, ptr++) {
        if ((ptr != arg0) && (arg1 == ptr->unk_010)) {
            ret = ptr;
            break;
        }
    }

    return ret;
}

unk_D_868084D8* func_86803078(unk_D_86807558* arg0) {
    s32 i;
    f32 temp_fa0;
    f32 var_fs0;
    s32 var_s4;
    s32 var_s6;
    unk_D_86807558* temp_v0_2;
    unk_D_868084D8* var_s0;
    unk_D_868084D8* var_s5;

    var_s5 = NULL;

    if (!(arg0->unk_016 & 1)) {
        var_s6 = 0;
    } else {
        var_s6 = 1;
    }
    if (arg0->unk_016 & 2) {
        var_s4 = 1;
    } else {
        var_s4 = 0;
    }
    var_fs0 = 1e9f;

    for (i = 0, var_s0 = D_868084D8; i < 12; i++, var_s0++) {
        if (func_86802FB0(var_s0, var_s6, var_s4) == 0) {
            continue;
        }

        temp_v0_2 = func_86803038(arg0, var_s0);
        if (temp_v0_2 != NULL) {
            if (temp_v0_2->unk_00C >= arg0->unk_00C) {
                temp_v0_2->unk_010 = 0;
            } else {
                continue;
            }
        }

        temp_fa0 = SQ(var_s0->unk_14.x - arg0->unk_068.x) + SQ(var_s0->unk_14.z - arg0->unk_068.z);
        if (temp_fa0 < var_fs0) {
            var_s5 = var_s0;
            var_fs0 = temp_fa0;
        }
    }

    return var_s5;
}

unk_D_868084D8* func_868031A8(unk_D_86807558* arg0) {
    s32 i;
    f32 temp_fa0;
    f32 var_fs0;
    s16 var_a0;
    s32 var_s2;
    s32 var_s5;
    s32 var_s7;
    s32 var_v1;
    unk_D_86807558* temp_v0_2;
    unk_D_868084D8* var_s0;
    unk_D_868084D8* var_s4;

    if (!(arg0->unk_016 & 1)) {
        var_s7 = 0;
    } else {
        var_s7 = 1;
    }

    if (arg0->unk_016 & 2) {
        var_s5 = 1;
    } else {
        var_s5 = 0;
    }

    var_s2 = 0;
    var_fs0 = 1e9f;
    var_s4 = NULL;

    for (i = 0, var_s0 = D_868084D8; i < 12; i++, var_s0++) {
        if (func_86802FB0(var_s0, var_s7, var_s5) == 0) {
            continue;
        }

        temp_v0_2 = func_86803038(arg0, var_s0);
        if (temp_v0_2 != NULL) {
            if (temp_v0_2->unk_00C >= arg0->unk_00C) {
                temp_v0_2->unk_010 = NULL;
            } else {
                continue;
            }
        }

        var_v1 = func_86806930(var_s0);
        if (var_s0->unk_0C == arg0->unk_05C) {
            var_a0 = arg0->unk_03E;
            if (var_a0 < 5) {
                var_a0++;
            }
            var_v1 *= var_a0;
        }

        if (var_s2 < var_v1) {
            var_s4 = var_s0;
            var_s2 = var_v1;
            var_fs0 = SQ(var_s0->unk_14.x - arg0->unk_068.x) + SQ(var_s0->unk_14.z - arg0->unk_068.z);
        } else if (var_v1 == var_s2) {
            temp_fa0 = SQ(var_s0->unk_14.x - arg0->unk_068.x) + SQ(var_s0->unk_14.z - arg0->unk_068.z);
            if (temp_fa0 < var_fs0) {
                var_s4 = var_s0;
                var_fs0 = temp_fa0;
            }
        }
    }

    return var_s4;
}

unk_D_868084D8* func_86803374(unk_D_86807558* arg0) {
    s32 i;
    s16 sp4A;
    f32 temp_fa0;
    f32 var_fs0;
    s32 var_s4;
    s32 var_s6;
    s32 var_s7;
    unk_D_86807558* temp_v0_2;
    unk_D_868084D8* var_s0;
    unk_D_868084D8* var_s0_2;
    unk_D_868084D8* var_s5;

    if (!(arg0->unk_016 & 1)) {
        var_s6 = 0;
    } else {
        var_s6 = 1;
    }

    if (arg0->unk_016 & 2) {
        var_s7 = 1;
    } else {
        var_s7 = 0;
    }

    var_s5 = NULL;
    var_fs0 = 1e9f;

    if (arg0->unk_05C != 0) {
        for (i = 0, var_s0 = D_868084D8; i < 12; i++, var_s0++) {
            if ((func_86802FB0(var_s0, var_s6, var_s7) == 0) || (arg0->unk_05C != var_s0->unk_0C)) {
                continue;
            }

            temp_v0_2 = func_86803038(arg0, var_s0);
            if (temp_v0_2 != NULL) {
                if (temp_v0_2->unk_00C >= arg0->unk_00C) {
                    temp_v0_2->unk_010 = NULL;
                } else {
                    continue;
                }
            }

            temp_fa0 = SQ(var_s0->unk_14.x - arg0->unk_068.x) + SQ(var_s0->unk_14.z - arg0->unk_068.z);
            if (temp_fa0 < var_fs0) {
                var_s5 = var_s0;
                var_fs0 = temp_fa0;
            }
        }
    }

    if (var_s5 == NULL) {
        sp4A = 0;
        var_s4 = 0;

        for (i = 0; i < 8; i++) {
            s32 v = D_86807160[i];
            if (v != 1) {
                if (sp4A < func_86806950(v)) {
                    var_s4 = v;
                    sp4A = func_86806950(v);
                }
            }
        }

        if (var_s4 != 0) {
            for (i = 0, var_s0 = D_868084D8; i < 12; i++, var_s0++) {
                if ((func_86802FB0(var_s0, var_s6, var_s7) == 0) || (var_s4 != var_s0->unk_0C)) {
                    continue;
                }

                temp_v0_2 = func_86803038(arg0, var_s0);
                if (temp_v0_2 != NULL) {
                    if (temp_v0_2->unk_00C >= arg0->unk_00C) {
                        temp_v0_2->unk_010 = NULL;
                    } else {
                        continue;
                    }
                }

                temp_fa0 = SQ(var_s0->unk_14.x - arg0->unk_068.x) + SQ(var_s0->unk_14.z - arg0->unk_068.z);
                if (temp_fa0 < var_fs0) {
                    if (1) {}
                    var_s5 = var_s0;
                    var_fs0 = temp_fa0;
                }
            }
        }

        if (var_s5 == NULL) {
            var_s5 = func_868031A8(arg0);
        }
    }

    return var_s5;
}

unk_D_868084D8* func_868035FC(unk_D_86807558* arg0) {
    s32 i;
    f32 temp_fa0;
    f32 var_fs0;
    unk_D_868084D8* var_s0;
    unk_D_868084D8* var_s3;

    var_fs0 = 1e9f;
    var_s3 = NULL;

    for (i = 0, var_s0 = D_868084D8; i < 12; i++, var_s0++) {
        if ((func_86802FB0(var_s0, 0, 1) == 0) || (var_s0->unk_0C != 1)) {
            continue;
        }

        temp_fa0 = SQ(var_s0->unk_14.x - arg0->unk_068.x) + SQ(var_s0->unk_14.z - arg0->unk_068.z);
        if (temp_fa0 < var_fs0) {
            var_s3 = var_s0;
            var_fs0 = temp_fa0;
        }
    }

    if (var_s3 != NULL) {
        return var_s3;
    }

    for (i = 0, var_s0 = D_868084D8; i < 12; i++, var_s0++) {
        if ((func_86802FB0(var_s0, 0, 1) == 0) || !(var_s0->unk_02 & 2)) {
            continue;
        }

        temp_fa0 = SQ(var_s0->unk_14.x - arg0->unk_068.x) + SQ(var_s0->unk_14.z - arg0->unk_068.z);
        if (temp_fa0 < var_fs0) {
            if (1) {}
            var_s3 = var_s0;
            var_fs0 = temp_fa0;
        }
    }

    return var_s3;
}

void func_86803760(Vec3f* arg0, f32 arg1, s16* arg2, s16* arg3, f32 arg4) {
    unk_D_86808498* ptr = &D_86808498;
    f32 tmp1;
    f32 tmp2;

    arg1 = ABS_NORMALIZED(arg1);

    if (arg1 == 0.0f) {
        *arg2 = 0;
        *arg3 = 0;
        return;
    }

    arg1 = 1.0f / sqrtf(arg1);
    arg0->x *= arg1;
    arg0->z *= arg1;

    tmp1 = (0.0f - (arg0->x * ptr->unk_2C.x)) + (arg0->z * ptr->unk_2C.z);
    tmp2 = (arg0->x * ptr->unk_20.x) + (arg0->z * ptr->unk_20.z);

    *arg2 = 74.0f * tmp1 * arg4;
    *arg3 = 74.0f * tmp2 * arg4;
}

void func_868038A8(unk_D_86807558* arg0, Controller* arg1) {
    s16 var_a1;
    s16 var_a2;
    f32 sp60;
    Vec3f sp54;
    s32 sp50;
    f32 tmp;
    f32 temp_fv0;
    s16 sp40[] = { 0x002D, 0x0014, 0x000F, 0x0000 }; // D_868070FC
    f32 sp30[] = { 0.8f, 0.9f, 0.9f, 1.0f };         // D_86807104

    bzero(arg1, sizeof(Controller));
    sp50 = 0;

    if (!(arg0->unk_016 & 1)) {
        var_a1 = 0;
    } else {
        var_a1 = 1;
    }

    if (arg0->unk_016 & 2) {
        var_a2 = 1;
    } else {
        var_a2 = 0;
    }

    arg0->unk_014--;
    if (arg0->unk_014 <= 0) {
        sp50 = 1;
        arg0->unk_014 = sp40[D_8780FA38];
        arg0->unk_010 = NULL;
    } else {
        if (func_86802FB0(arg0->unk_010, var_a1, var_a2) == 0) {
            arg0->unk_010 = NULL;
        }
    }

    if (sp50 != 0) {
        switch (arg0->unk_008) {
            case 1:
                arg0->unk_010 = func_86803078(arg0);
                break;

            case 2:
                arg0->unk_010 = func_86803374(arg0);
                break;

            case 3:
                arg0->unk_010 = func_868031A8(arg0);
                break;

            case 4:
                arg0->unk_010 = func_868035FC(arg0);
                break;
        }
    }

    if (arg0->unk_010 == NULL) {
        if (arg0->unk_008 == 4) {
            sp54.x = 0.0f - arg0->unk_068.x;
            sp54.y = 0.0f;
            sp54.z = 0.0f - arg0->unk_068.z;

            temp_fv0 = SQ(sp54.x) + SQ(sp54.z);
            if (temp_fv0 > 30.0f) {
                func_86803760(&sp54, temp_fv0, &arg1->rawStickX, &arg1->rawStickY, 0.5f);
            }
        }
    } else {
        sp54.y = 0.0f;
        sp60 = func_86805E94(arg0->unk_010, &arg0->unk_068, &sp54);

        if ((sp60 <= 13225.0f) && (sp60 != 0.0f)) {
            tmp = (((sp54.x * arg0->unk_098.unk_00.x) + (sp54.y * arg0->unk_098.unk_00.y) +
                    (sp54.z * arg0->unk_098.unk_00.z)) /
                   sqrtf(sp60));
            if (tmp >= 0.8f) {
                arg1->buttonPressed |= 0x8000;
            } else {
                func_86803760(&sp54, sp60, &arg1->rawStickX, &arg1->rawStickY, sp30[D_8780FA38]);
            }
        } else {
            func_86803760(&sp54, sp60, &arg1->rawStickX, &arg1->rawStickY, sp30[D_8780FA38]);
        }
    }
}

f32 func_86803BC4(s16 arg0, s32 arg1) {
    static s16 D_86807114[] = {
        0x003C,
        0x000A,
        0x0028,
        0x0014,
    };
    static s16 D_8680711C[] = {
        0x003C,
        0x000A,
        0x0028,
        0x0014,
    };
    static s16* D_86807124[] = { D_86807114, D_8680711C };

    s16* temp_v0 = D_86807124[arg1];
    f32 ret;

    arg0 = temp_v0[0] - arg0;

    if (arg0 < temp_v0[1]) {
        ret = arg0 / (f32)temp_v0[1];
    } else if (temp_v0[2] < arg0) {
        ret = 1.0f - ((arg0 - temp_v0[2]) / (f32)temp_v0[3]);
    } else {
        ret = 1.0f;
    }

    return ret;
}

#ifdef NON_MATCHING
void func_86803C6C(unk_D_86807558* arg0) {
    s32 pad;
    s32 pad1;
    unk_D_86808498* ptr = &D_86808498;
    f32 spB8;
    f32 temp_fa0;
    f32 var_fv1;
    f32 spAC;
    f32 spA8;
    Controller* spA4;
    Controller sp80;
    f32 tmp;
    Vec3f sp70;
    Vec3f sp64;
    Vec3f sp58;
    Vec3f sp4C;

    if (arg0->unk_002 & 2) {
        if (!(arg0->unk_002 & 4)) {
            spA4 = arg0->unk_064;
        } else {
            func_868038A8(arg0, &sp80);
            spA4 = &sp80;
        }
    } else {
        spA4 = &D_86808450;
    }

    switch (arg0->unk_060) {
        case 0:
            if (spA4->buttonPressed & 0x8000) {
                func_86802E18(arg0, 1);
                return;
            }

            spAC = func_86802BE4(spA4->rawStickX);
            spA8 = func_86802BE4(spA4->rawStickY);
            break;

        case 2:
        case 3:
            arg0->unk_006--;
            if (arg0->unk_060 == 2) {
                spB8 = func_86803BC4(arg0->unk_006, 0);
            } else {
                spB8 = func_86803BC4(arg0->unk_006, 1);
            }

            if (arg0->unk_006 <= 0) {
                arg0->unk_006 = 0;
                func_86802E18(arg0, 0);
                return;
            }

            if (!(arg0->unk_006 & 0xF)) {
                arg0->unk_0E0 = func_878001E8(0x10000);
            }

            spAC = COSS(arg0->unk_0E0) * spB8;
            spA8 = SINS(arg0->unk_0E0) * spB8;
            spB8 = 1.0f - spB8;

            if (arg0->unk_060 == 2) {
                arg0->unk_0D0.g = arg0->unk_0D0.b = 255.0f * spB8;
                if (!(arg0->unk_006 & 0xF)) {
                    func_81407D48(1.0f, arg0->unk_0E4.unk_0FC, D_8006F05C, func_879023EC, &D_87903E10, 4);
                }
            } else {
                arg0->unk_0D0.r = arg0->unk_0D0.b = 255.0f * spB8;
            }
            break;
    }

    temp_fa0 = SQ(spAC) + SQ(spA8);
    if (temp_fa0 > 1.0f) {
        temp_fa0 = 1.0f / sqrtf(temp_fa0);
        spAC *= temp_fa0;
        spA8 *= temp_fa0;
    }

    sp70 = arg0->unk_068;
    sp64 = arg0->unk_074;

    sp58.y = D_86806FA8;

    var_fv1 = -D_86806F90[0] * spAC;
    temp_fa0 = D_86806F90[0] * spA8;

    var_fv1 = ABS_NORMALIZED(var_fv1);
    temp_fa0 = ABS_NORMALIZED(temp_fa0);

    sp4C.x = (ptr->unk_2C.x * var_fv1) + (temp_fa0 * ptr->unk_20.x);
    sp4C.z = (ptr->unk_2C.z * var_fv1) + (temp_fa0 * ptr->unk_20.z);

    sp4C.x = ABS_NORMALIZED(sp4C.x);
    sp4C.z = ABS_NORMALIZED(sp4C.z);

    sp58.x = sp4C.x - sp64.x;
    sp58.z = sp4C.z - sp64.z;

    sp58.x = ABS_NORMALIZED(sp58.x);
    sp58.z = ABS_NORMALIZED(sp58.z);

    if ((SQ(sp58.x) + SQ(sp58.z)) <= 0.000001f) {
        sp58.x = sp58.z = 0.0f;
    } else {
        if (((sp64.x * sp58.x) + (sp64.z * sp58.z)) >= 0.0f) {
            if (sp70.y > 0.0f) {
                var_fv1 = D_86806FA0;
            } else {
                var_fv1 = D_86806F9C;
            }
        } else {
            var_fv1 = D_86806FA4;
        }
        sp58.x *= var_fv1;
        sp58.z *= var_fv1;
    }

    arg0->unk_074.x = sp64.x + sp58.x;
    arg0->unk_074.y = sp64.y + sp58.y;
    arg0->unk_074.z = sp64.z + sp58.z;

    arg0->unk_074.x = ABS_NORMALIZED(arg0->unk_074.x);
    arg0->unk_074.y = ABS_NORMALIZED(arg0->unk_074.y);
    arg0->unk_074.z = ABS_NORMALIZED(arg0->unk_074.z);

    if (arg0->unk_060 == 0) {
        if ((SQ(arg0->unk_074.x) + SQ(arg0->unk_074.z)) < 0.25f) {
            if (arg0->unk_0C0 == 1) {
                arg0->unk_0C0 = 0;
                arg0->unk_0C8 = 1.0f;
            }
        } else {
            arg0->unk_0C0 = 1;
            arg0->unk_0C8 = 1.0f;
        }
    }

    arg0->unk_068.x = arg0->unk_074.x + sp70.x;
    arg0->unk_068.y = arg0->unk_074.y + sp70.y;
    arg0->unk_068.z = arg0->unk_074.z + sp70.z;

    func_86802C6C(arg0);

    temp_fa0 = SQ(sp4C.x) + SQ(sp4C.z);
    if (temp_fa0 > 0.0001f) {
        temp_fa0 = 1.0f / sqrtf(temp_fa0);
        sp4C.x *= temp_fa0;
        sp4C.z *= temp_fa0;

        if (((arg0->unk_098.unk_00.x * sp4C.x) + (sp4C.z * arg0->unk_098.unk_00.z)) < -0.95f) {
            var_fv1 = 0.3f;
        } else {
            var_fv1 = 0.0f;
        }

        arg0->unk_098.unk_00.x += (sp4C.x * D_86806FAC) + (var_fv1 * arg0->unk_098.unk_18.x);
        arg0->unk_098.unk_00.y = 0.0f;
        arg0->unk_098.unk_00.z += (sp4C.z * D_86806FAC) + (var_fv1 * arg0->unk_098.unk_18.z);

        arg0->unk_098.unk_00.x = ABS_NORMALIZED(arg0->unk_098.unk_00.x);
        arg0->unk_098.unk_00.z = ABS_NORMALIZED(arg0->unk_098.unk_00.z);
    }

    arg0->unk_0BE--;
    if (arg0->unk_0BE == 0) {
        if (arg0->unk_0BC == 0) {
            arg0->unk_0BC = func_878001E8(3) + 1;
            arg0->unk_0BE = 0xF;
        } else {
            arg0->unk_0BC--;
            if (arg0->unk_0BC == 0) {
                arg0->unk_0BE = func_878001E8(0x5B) + 0x1E;
            } else {
                arg0->unk_0BE = 0xF;
            }
        }
    }
}
#else
void func_86803C6C(unk_D_86807558* arg0);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/14/fragment14_1462A0/func_86803C6C.s")
#endif

#ifdef NON_MATCHING
unk_D_868084D8* func_86804634(unk_D_86807558* arg0) {
    s32 i;
    Vec3f sp14;
    unk_D_868084D8* var_v1;
    f32 sq;
    Vec3f* tmp;

    sp14 = arg0->unk_0E4.unk_0EC;

    for (i = 0, var_v1 = D_868084D8; i < 12; i++, var_v1++) {
        if (((var_v1->unk_02 & 1) != 0) && (var_v1->unk_10 == 2)) {
            if (SQ(D_86806FBC) >=
                SQ(var_v1->unk_14.x - sp14.x) + SQ(var_v1->unk_14.y - sp14.y) + SQ(var_v1->unk_14.z - sp14.z)) {
                break;
            }
        }
    }

    if (i == 0xC) {
        var_v1 = NULL;
    }

    return var_v1;
}
#else
unk_D_868084D8* func_86804634(unk_D_86807558* arg0);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/14/fragment14_1462A0/func_86804634.s")
#endif

s32 func_86804700(unk_D_86807558* arg0) {
    UNUSED s32 pad;
    s32 i;
    Vec3f sp2C;
    f32 temp_fa0;
    f32 temp_fv0;
    f32 temp_fv1;
    unk_D_86807558* var_v0;

    if (arg0->unk_0DC != 0) {
        return 1;
    }

    if (func_80017514(&arg0->unk_0E4) != 0) {
        return 2;
    }

    sp2C = arg0->unk_0E4.unk_0EC;

    for (i = 0, var_v0 = D_86807558; i < 4; i++, var_v0++) {
        if (arg0 == var_v0) {
            continue;
        }

        temp_fv0 = var_v0->unk_068.x - sp2C.x;
        temp_fv1 = (var_v0->unk_068.y + D_86806FB4) - sp2C.y;
        temp_fa0 = var_v0->unk_068.z - sp2C.z;

        if ((SQ(temp_fv0) + SQ(temp_fv1) + SQ(temp_fa0)) <= SQ(D_86806FC0 + D_86806FB0)) {
            return 3;
        }
    }

    return 0;
}

void func_86804884(unk_D_86807558* arg0) {
    s32 sp24;
    s32 sp20;

    if (arg0->unk_0DC->unk_02 & 2) {
        sp24 = 1;
    } else {
        sp24 = 0;
    }

    sp20 = arg0->unk_0DC->unk_0C;
    if (sp20 == arg0->unk_05C) {
        if (arg0->unk_03E < 5) {
            arg0->unk_03E++;
        }
        arg0->unk_040.unk_00 = 1;
    } else {
        arg0->unk_03E = 1;
    }
    arg0->unk_05C = sp20;

    arg0->unk_018 += func_86806930(arg0->unk_0DC) * arg0->unk_03E;
    arg0->unk_02A++;
    arg0->unk_02C[sp20]++;

    func_86806868(arg0->unk_0DC, 0, NULL);

    if (sp20 == 1) {
        func_86802E18(arg0, 2);
    } else if ((sp24 != 0) && (arg0->unk_002 & 2)) {
        func_86802E18(arg0, 3);
    } else {
        func_86802E18(arg0, 0);
    }
}

void func_868049C0(unk_D_86807558* arg0) {
    switch (arg0->unk_0C0) {
        case 2:
            if (func_80017514(&arg0->unk_0E4) != 0) {
                arg0->unk_0C0 = 3;
            }
            break;

        case 3:
            if (arg0->unk_0DC == NULL) {
                arg0->unk_0DC = func_86804634(arg0);
                if (arg0->unk_0DC != NULL) {
                    arg0->unk_0CC = func_8680262C(&arg0->unk_0E4, 0xD);
                    func_86806868(arg0->unk_0DC, 3, arg0);
                }
            }

            if (arg0->unk_0C8 >= 0.0f) {
                switch (func_86804700(arg0)) {
                    case 1:
                    case 2:
                        arg0->unk_0C8 = -1.0f;
                        break;

                    case 3:
                        if (func_8680262C(&arg0->unk_0E4, 0xD) < 3) {
                            arg0->unk_0C0 = 4;
                        } else {
                            arg0->unk_0C8 = -1.0f;
                        }
                        break;
                }
            } else if (func_80017484(&arg0->unk_0E4, 0) != 0) {
                if (arg0->unk_0DC == NULL) {
                    arg0->unk_0C0 = 4;
                } else if (arg0->unk_0DC->unk_0C != 1) {
                    arg0->unk_0C0 = 5;
                    arg0->unk_006 = arg0->unk_0D4;
                } else {
                    func_86804884(arg0);
                }
                arg0->unk_0C8 = 1.0f;
            }
            break;

        case 4:
            if (func_80017514(&arg0->unk_0E4) != 0) {
                func_86802E18(arg0, 0);
            }
            break;

        case 5:
            if (func_80017514(&arg0->unk_0E4) != 0) {
                arg0->unk_006--;
                if (arg0->unk_006 <= 0) {
                    arg0->unk_0C0 = 6;
                    arg0->unk_0C8 = arg0->unk_0D8;
                } else {
                    func_80017464(&arg0->unk_0E4, 0);
                }
            }
            break;

        case 6:
            if (func_80017514(&arg0->unk_0E4) != 0) {
                func_86804884(arg0);
            }
            break;
    }
}

void func_86804BD0(unk_D_86807558* arg0) {
    UNUSED s32 pad;
    Vec3f sp30;
    f32 temp_fa0;
    f32 tmp;

    if ((arg0->unk_028 != 1) || (arg0->unk_018 == 0)) {
        if (func_80017514(&arg0->unk_0E4) != 0) {
            func_80017464(&arg0->unk_0E4, 0x3D);
        }
    } else if (arg0->unk_0C0 == 8) {
        if (func_80017514(&arg0->unk_0E4) != 0) {
            func_86802E18(arg0, 0);
        }
    } else {
        sp30.x = D_86808498.unk_0C.x - arg0->unk_068.x;
        sp30.y = 0.0f;
        sp30.z = D_86808498.unk_0C.z - arg0->unk_068.z;

        temp_fa0 = 1.0f / sqrtf(SQ(sp30.x) + SQ(sp30.z));
        sp30.x *= temp_fa0;
        sp30.z *= temp_fa0;

        arg0->unk_098.unk_00.x += sp30.x * 0.3f;
        arg0->unk_098.unk_00.z += sp30.z * 0.3f;

        func_86802204(&arg0->unk_098);

        tmp = (sp30.x * arg0->unk_098.unk_00.x) + sp30.y + (sp30.z * arg0->unk_098.unk_00.z);

        if (tmp >= 0.95f) {
            arg0->unk_0C0 = 8;
        }
    }
}

void func_86804D38(unk_D_86807558* arg0) {
    s32 i;
    f32 sp68;
    f32 temp_fa0;
    f32 sp60;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 temp_fs3;
    f32 temp_fs4;
    f32 temp_fs5;
    f32 temp_fv0_3;
    f32 var_fs0;
    unk_D_86807558* var_s1;

    for (i = 0, var_s1 = D_86807558; i < 4; i++, var_s1++) {
        if (arg0 == var_s1) {
            continue;
        }

        temp_fs4 = var_s1->unk_068.x - arg0->unk_068.x;
        temp_fs5 = var_s1->unk_068.y - arg0->unk_068.y;
        sp60 = var_s1->unk_068.z - arg0->unk_068.z;

        temp_fa0 = SQ(temp_fs4) + SQ(temp_fs5) + SQ(sp60);
        if (temp_fa0 < (4.0f * D_86806FB0 * D_86806FB0)) {
            sp68 = sqrtf(temp_fa0);
            if (sp68 < 0.01f) {
                var_fs0 = 0.0f;
            } else {
                var_fs0 = 1.0f / sp68;
            }

            temp_fs1 = temp_fs4 * var_fs0;
            temp_fs2 = temp_fs5 * var_fs0;
            temp_fs3 = sp60 * var_fs0;

            temp_fv0_3 = sqrtf(SQ(var_s1->unk_074.x) + SQ(var_s1->unk_074.y) + SQ(var_s1->unk_074.z));
            arg0->unk_002 |= 1;

            arg0->unk_080.x -= temp_fs1 * temp_fv0_3;
            arg0->unk_080.y -= temp_fs2 * temp_fv0_3;
            arg0->unk_080.z -= temp_fs3 * temp_fv0_3;

            var_fs0 = (2.0f * D_86806FB0) - sp68;
            arg0->unk_08C.x -= temp_fs1 * var_fs0;
            arg0->unk_08C.y -= temp_fs2 * var_fs0;
            arg0->unk_08C.z -= temp_fs3 * var_fs0;
        }
    }
}

void func_86804F2C(unk_D_86807558* arg0) {
    if (arg0->unk_002 & 1) {
        arg0->unk_068.x += arg0->unk_080.x + arg0->unk_08C.x;
        arg0->unk_068.y += arg0->unk_080.y + arg0->unk_08C.y;
        arg0->unk_068.z += arg0->unk_080.z + arg0->unk_08C.z;

        arg0->unk_074 = arg0->unk_080;

        func_86802C6C(arg0);

        arg0->unk_002 &= ~1;
        arg0->unk_080.x = arg0->unk_080.y = arg0->unk_080.z = 0.0f;

        arg0->unk_08C = arg0->unk_080;
    }
}

void func_86805000(unk_D_86807558* arg0) {
    UNUSED s32 pad[3];
    f32 var_fv0;
    unk_D_86002F58_004_000* ptr = &arg0->unk_0E4;

    ptr->unk_024 = arg0->unk_068;

    func_86802204(&arg0->unk_098);

    var_fv0 = 1.0f - arg0->unk_098.unk_00.z;
    var_fv0 = var_fv0 * 32768.0f * 0.5f;
    if (arg0->unk_098.unk_00.x < 0.0f) {
        var_fv0 = 0.0f - var_fv0;
    }
    ptr->unk_01E.y = (s32)var_fv0 & 0xFFFF;

    ptr->unk_03C.rgba = arg0->unk_0D0.rgba;

    if (arg0->unk_0C4 != arg0->unk_0C0) {
        func_8001BD04(&arg0->unk_0E4, arg0->unk_0C0);
    }

    ptr->unk_040.unk_0C = (s32)(arg0->unk_0C8 * 65536.0f);
    if (arg0->unk_002 & 0x10) {
        ptr->unk_01D = 0xFF;
    } else {
        ptr->unk_01D = 0;
    }
}

void func_86805108(u16 arg0, s32 arg1) {
    static u16 D_8680712C[] = { 1, 2, 4, 8 };

    s32 i;

    for (i = 0; i < 4; i++) {
        if (!(D_8680712C[i] & arg0)) {
            return;
        }

        D_86808438[i] = arg1;
        if ((D_86808438[i] < 0) || (D_86808438[i] >= 6)) {
            D_86808438[i] = 0;
        }
    }
}

void func_868051E0(void) {
    unk_D_86807558* ptr2;
    s32 tmp;
    s32 i;
    s32 j;
    s32 var_v1;
    s32 sp3C[4];
    unk_D_86807558* ptr;
    s32 var_a2;

    if (D_86808438[0] != 4) {
        return;
    }

    for (i = 0; i < 4; i++) {
        sp3C[i] = i;
    }

    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 4; j++) {
            ptr = &D_86807558[sp3C[i]];
            ptr2 = &D_86807558[sp3C[j]];
            if (ptr->unk_018 < ptr2->unk_018) {
                tmp = sp3C[i];
                sp3C[i] = sp3C[j];
                sp3C[j] = tmp;
            }
        }
    }

    var_a2 = -1;
    var_v1 = 0;
    for (i = 0; i < 4; i++) {
        if (D_86808448 == -1) {
            D_86808448 = sp3C[i];
        }

        ptr = &D_86807558[sp3C[i]];
        if (var_a2 != ptr->unk_018) {
            var_v1++;
            var_a2 = ptr->unk_018;
        }

        ptr->unk_028 = var_v1;
    }

    for (i = 0, ptr = D_86807558; i < 4; i++, ptr++) {
        ptr->unk_002 |= 8;
        if ((ptr->unk_028 == 1) && (ptr->unk_018 > 0)) {
            func_87802F00(i);
        }
    }
}

void func_86805428(unk_D_86807558* arg0) {
    switch (D_86808438[arg0->unk_000]) {
        case 0:
        case 4:
            break;

        case 2:
            arg0->unk_002 &= ~2;
            break;

        case 1:
            arg0->unk_002 |= 0x10;
            break;

        case 3:
            arg0->unk_002 |= 2;
            break;

        case 5:
            arg0->unk_002 &= ~2;
            func_86802E18(arg0, 4);
            break;
    }

    D_86808438[arg0->unk_000] = 0;
}

void func_86805518(unk_D_86807558* arg0) {
    arg0->unk_020++;
    arg0->unk_01C += arg0->unk_020;
    if (arg0->unk_01C >= arg0->unk_018) {
        arg0->unk_01C = arg0->unk_018;
        arg0->unk_024 = arg0->unk_018;
        arg0->unk_020 = 0;
        arg0->unk_002 &= ~8;
        if (D_86808448 == arg0->unk_000) {
            func_8004D9B0(0x5000C, 0, 0);
        }
    } else if ((arg0->unk_01C - arg0->unk_024) >= 0xA) {
        arg0->unk_024 = arg0->unk_01C;
        if (D_86808448 == arg0->unk_000) {
            func_8004D9B0(0x5000B, 0, 0);
        }
    }
}

s32 func_868055D4(void) {
    s32 var_v1 = 0;
    s32 i;
    unk_D_86807558* var_a0;

    for (i = 0, var_a0 = D_86807558; i < 4; i++, var_a0++) {
        if ((var_a0->unk_060 != 0) || (var_a0->unk_0DC != 0)) {
            break;
        }
    }

    if (i == 4) {
        var_v1 = 1;
    }

    return var_v1;
}

void func_86805620(UNUSED unk_D_86807558* arg0, unk_D_86807558_040* arg1) {
    s32 i;

    switch (arg1->unk_00) {
        case 0:
            break;

        case 1:
            arg1->unk_00 = 2;
            arg1->unk_02 = 0xA;
            arg1->unk_04 = 0;
            arg1->unk_10 = 0.0f;
            arg1->unk_08 = arg1->unk_08;
            arg1->unk_0C += 5.0f;
            arg1->unk_14 = 5.0f;
            arg1->unk_18 = 0;
            break;

        case 2:
            if (arg1->unk_02 > 0) {
                arg1->unk_02--;
            }

            arg1->unk_18 = ((0xA - arg1->unk_02) * 0xFF) / 10;
            arg1->unk_14 += -1.0f;

            if (arg1->unk_0C <= 0.0f) {
                arg1->unk_0C = 0.0f;
                arg1->unk_14 = 0.0f;
                arg1->unk_04++;
                if (arg1->unk_04 < 3) {
                    arg1->unk_14 = 5.0f;
                    for (i = 0; i < arg1->unk_04; i++) {
                        arg1->unk_14 *= 0.5f;
                    }
                } else {
                    arg1->unk_00 = 3;
                    arg1->unk_02 = 0x1E;
                    arg1->unk_18 = 0xFF;
                }
            }
            arg1->unk_08 += arg1->unk_10;
            arg1->unk_0C += arg1->unk_14;
            break;

        case 3:
            arg1->unk_02--;
            if (arg1->unk_02 <= 0) {
                arg1->unk_00 = 4;
                arg1->unk_02 = 0xF;
            }
            break;

        case 4:
            arg1->unk_02--;
            arg1->unk_18 = (arg1->unk_02 * 0xFF) / 15;
            if (arg1->unk_02 <= 0) {
                func_86802728(arg1);
            }
            break;
    }
}

void func_86805858(s32 arg0) {
    s32 i;
    MemoryBlock* temp_v0;

    for (i = 0; i < 4; i++) {
        D_86808438[i] = 0;
    }

    bzero(&D_86808450, sizeof(Controller));

    D_86808448 = -1;
    D_86807550 = func_80019D18(0xA0);

    temp_v0 = func_80002D10(main_pool_get_available(), 0);
    D_86808474 = (unk_D_86002F58_004_000_004*)process_geo_layout(temp_v0, &D_86807078);
    func_80002D60(temp_v0);
    D_8680847A = 0;
    D_8680847E = 4 - D_8780FA2C;
    D_8680847C = func_878001E8(D_8680847E);
    D_86808480 = 0;

    for (i = 0; i < 4; i++) {
        func_86802750(&D_86807558[i], i, arg0);
    }
}

void func_86805974(void) {
    s32 i;
    unk_D_86807558* var_s0;

    if ((D_8780FC94 == 0) && (D_86808438[0] != 0)) {
        func_868051E0();
    }

    var_s0 = D_86807558;
    for (i = 0; i < 4; i++, var_s0++) {
        if (D_8780FC94 != 0) {
            continue;
        }

        var_s0->unk_0C4 = var_s0->unk_0C0;
        if (D_86808438[i] != 0) {
            func_86805428(var_s0);
        }

        switch (var_s0->unk_060) {
            case 0:
            case 2:
            case 3:
                func_86803C6C(var_s0);
                break;

            case 1:
                func_868049C0(var_s0);
                break;

            case 4:
                func_86804BD0(var_s0);
                break;
        }

        if (var_s0->unk_002 & 8) {
            func_86805518(var_s0);
        }

        func_86805620(var_s0, &var_s0->unk_040);
    }

    var_s0 = D_86807558;
    for (i = 0; i < 4; i++, var_s0++) {
        if (D_8780FC94 == 0) {
            func_86804D38(var_s0);
        }
    }

    var_s0 = D_86807558;
    for (i = 0; i < 4; i++, var_s0++) {
        if (D_8780FC94 == 0) {
            func_86804F2C(var_s0);
        }
        func_86805000(var_s0);
    }
}

void func_86805AF0(unk_D_86808498* arg0) {
    f32 temp_fa0;
    Vec3f sp20;

    arg0->unk_20.x = D_86808490->unk_60.at.x - D_86808490->unk_60.eye.x;
    arg0->unk_20.y = 0.0f;
    arg0->unk_20.z = D_86808490->unk_60.at.z - D_86808490->unk_60.eye.z;

    temp_fa0 = SQ(arg0->unk_20.x) + SQ(arg0->unk_20.z);
    if (temp_fa0 != 0.0f) {
        temp_fa0 = 1.0f / sqrtf(temp_fa0);
        arg0->unk_20.x *= temp_fa0;
        arg0->unk_20.y = 0.0f;
        arg0->unk_20.z *= temp_fa0;
    } else {
        arg0->unk_20.x = 0.0f;
        arg0->unk_20.z = 1.0f;
    }

    sp20.x = 0.0f;
    sp20.y = 1.0f;
    sp20.z = 0.0f;
    func_8000EA84(&arg0->unk_2C, &sp20, &arg0->unk_20);
}

void func_86805BD4(void) {
    D_87906054 = D_86808490 = D_86807500->unk_00.unk_0C;

    D_86808498.unk_00.x = 0.0f;
    D_86808498.unk_00.y = 0.0f;
    D_86808498.unk_00.z = -7.8f;

    D_86808498.unk_0C = D_8006F050;

    D_86808498.unk_18 = 0;
    D_86808498.unk_1A = 0x16A8;
    D_86808498.unk_1C = 880.0f;

    func_80010354(&D_86808498.unk_00, &D_86808498.unk_0C, D_86808498.unk_1C, D_86808498.unk_1A, D_86808498.unk_18);
    func_86805AF0(&D_86808498);

    D_86808490->unk_24.near = 50.0f;
    D_86808490->unk_24.far = 6400.0f;
}

void func_86805CB4(void) {
    func_80010354(&D_86808498.unk_00, &D_86808498.unk_0C, D_86808498.unk_1C, D_86808498.unk_1A, D_86808498.unk_18);
    func_86805AF0(&D_86808498);
    D_86808490->unk_60.eye = D_86808498.unk_0C;
    D_86808490->unk_60.at = D_86808498.unk_00;
}
