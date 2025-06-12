#include "fragment62.h"

static s16 D_843C4D90;
static s16 D_843C4D92;
static s16 D_843C4D94;

static f32 D_8438A850 = 30.0f;

static Vtx D_8438A858[] = {
    VTX(1, -35, -35, 0, 0, 0x88, 0x00, 0x00, 0xFF), VTX(1, -50, 0, 0, 0, 0x88, 0x00, 0x00, 0xFF),
    VTX(1, 0, 0, 0, 0, 0x88, 0x00, 0x00, 0xFF),     VTX(1, -50, 0, 0, 0, 0x1D, 0x8C, 0x00, 0xFF),
    VTX(1, -35, -35, 0, 0, 0x1D, 0xAE, 0xAE, 0xFF), VTX(200, 0, 0, 0, 0, 0x78, 0x00, 0x00, 0xFF),
    VTX(1, 0, -49, 0, 0, 0x88, 0x00, 0x00, 0xFF),   VTX(1, 0, -49, 0, 0, 0x1D, 0x00, 0x8C, 0xFF),
    VTX(1, 35, -35, 0, 0, 0x88, 0x00, 0x00, 0xFF),  VTX(1, 35, -35, 0, 0, 0x1D, 0x52, 0xAE, 0xFF),
    VTX(1, 50, 0, 0, 0, 0x88, 0x00, 0x00, 0xFF),    VTX(1, 50, 0, 0, 0, 0x1D, 0x74, 0x00, 0xFF),
    VTX(1, 35, 35, 0, 0, 0x88, 0x00, 0x00, 0xFF),   VTX(1, 35, 35, 0, 0, 0x1D, 0x52, 0x52, 0xFF),
    VTX(1, 0, 49, 0, 0, 0x88, 0x00, 0x00, 0xFF),    VTX(1, 0, 49, 0, 0, 0x1D, 0x00, 0x74, 0xFF),
    VTX(1, -35, 35, 0, 0, 0x88, 0x00, 0x00, 0xFF),  VTX(1, -35, 35, 0, 0, 0x1D, 0xAE, 0x52, 0xFF),
};
static u32 D_8438A978[] = {
    0x77777777,
    0x77777777,
};
Gfx D_8438A980[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                          G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPLoadTextureBlock_4b(D_8438A978, G_IM_FMT_I, 4, 4, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 2, 2,
                            G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetCombineMode(G_CC_BLENDIA, G_CC_BLENDIA),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetPrimColor(0xFF, 0xFF, 197, 184, 122, 255),
    gsDPSetEnvColor(197, 184, 122, 255),
    gsSPVertex(D_8438A858, 18, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 0, 2, 0, 4, 7, 5, 0),
    gsSP2Triangles(8, 6, 2, 0, 7, 9, 5, 0),
    gsSP2Triangles(10, 8, 2, 0, 9, 11, 5, 0),
    gsSP2Triangles(12, 10, 2, 0, 11, 13, 5, 0),
    gsSP2Triangles(14, 12, 2, 0, 13, 15, 5, 0),
    gsSP2Triangles(16, 14, 2, 0, 15, 17, 5, 0),
    gsSP2Triangles(1, 16, 2, 0, 17, 3, 5, 0),
    gsSPEndDisplayList(),
};

static s32 pad_D_8438AA58[] = { 0, 0 };

static Gfx D_8438AA60[] = {
    gsSPEndDisplayList(),
};
static u32 D_8438AA68[] = {
    0x9FFFFFFF, 0xFFFFFFFF, 0x09FFFFFF, 0xFFFFFFFF, 0x009FFFFF, 0xFFFFFFFF, 0x0009FFFF, 0xFFFFFFFF, 0x00009FFF,
    0xFFFFFFFF, 0x000009FF, 0xFFFFFFFF, 0x0000009F, 0xFFFFFFFF, 0x00000009, 0xFFFFFFFF, 0x00000000, 0x9FFFFFFF,
    0x00000000, 0x09FFFFFF, 0x00000000, 0x009FFFFF, 0x00000000, 0x000FFFFF, 0x00000000, 0x000FFFFF, 0x00000000,
    0x009FFFFF, 0x00000000, 0x09FFFFFF, 0x00000000, 0x9FFFFFFF, 0x00000009, 0xFFFFFFFF, 0x0000009F, 0xFFFFFFFF,
    0x000009FF, 0xFFFFFFFF, 0x00009FFF, 0xFFFFFFFF, 0x0009FFFF, 0xFFFFFFFF, 0x009FFFFF, 0xFFFFFFFF, 0x09FFFFFF,
    0xFFFFFFFF, 0x9FFFFFFF, 0xFFFFFFFF, 0x9FFFFFFF, 0xFFFFFFFF, 0x09FFFFFF, 0xFFFFFFFF, 0x009FFFFF, 0xFFFFFFFF,
    0x0009FFFF, 0xFFFFFFFF, 0x00009FFF, 0xFFFFFFFF, 0x000009FF, 0xFFFFFFFF, 0x0000009F, 0xFFFFFFFF, 0x00000009,
    0xFFFFFFFF, 0x00000000, 0x9FFFFFFF, 0x00000000, 0x09FFFFFF, 0x00000000, 0x009FFFFF, 0x00000000, 0x000FFFFF,
    0x00000000, 0x000FFFFF, 0x00000000, 0x009FFFFF, 0x00000000, 0x09FFFFFF, 0x00000000, 0x9FFFFFFF, 0x00000009,
    0xFFFFFFFF, 0x0000009F, 0xFFFFFFFF, 0x000009FF, 0xFFFFFFFF, 0x00009FFF, 0xFFFFFFFF, 0x0009FFFF, 0xFFFFFFFF,
    0x009FFFFF, 0xFFFFFFFF, 0x09FFFFFF, 0xFFFFFFFF, 0x9FFFFFFF, 0xFFFFFFFF,
};
static Gfx D_8438ABE8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_ZBUFFER | G_CULL_BACK | G_LIGHTING),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_NOOP2),
    gsDPSetCombineMode(G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM),
    gsDPSetPrimColor(0, 0, 5, 5, 5, 255),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetTexturePersp(G_TP_NONE),
    gsSPEndDisplayList(),
};
static Gfx D_8438AC30[] = {
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsSPSetGeometryMode(G_ZBUFFER | G_CULL_BACK | G_LIGHTING),
    gsSPEndDisplayList(),
};

void func_8436EEF0(s32 arg0, s32 arg1) {
    D_843C4D90 = arg0;
    D_843C4D94 = arg1;

    if ((D_843C4D90 == 0) || ((D_843C4D90 != 1) && (D_843C4D90 != 2) && (D_843C4D90 == 3))) {
        D_843C4D92 = 0x140;
    } else {
        D_843C4D92 = 0;
    }
}

s32 func_8436EF48(void) {
    return D_843C4D90;
}

void func_8436EF54(void) {
    s16 var_v0 = D_843C4D92;

    switch (D_843C4D90) {
        case 2:
            if (var_v0 < 0x140) {
                var_v0 += D_843C4D94;
            } else {
                D_843C4D90 = 0;
            }
            break;

        case 3:
            if (var_v0 > 0) {
                var_v0 -= D_843C4D94;
            } else {
                D_843C4D90 = 1;
            }
            if (var_v0 < 0) {
                var_v0 = 0;
            }
            break;
    }
    D_843C4D92 = var_v0;
}

Gfx* func_8436EFE8(Gfx* arg0, s32 arg1) {
    s32 i;
    s16 left;
    s16 top;
    s32 temp_a1;
    s32 temp_v1;

    temp_a1 = arg1 & 1;
    temp_v1 = (arg1 + 1) & 1;

    gSPDisplayList(arg0++, D_8438ABE8);
    gDPLoadTextureBlock_4b(arg0++, D_8438AA68, G_IM_FMT_I, 12, 48, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gDPPipeSync(arg0++);

    for (i = temp_a1; i < 5; i += 2) {
        left = D_843C4D92 * 2 - 320;
        top = i * 48;
        gSPScisTextureRectangle(arg0++, left << 2, top << 2, (left + 640) << 2, (top + 24) << 2, 0, 0, 0, 1 << 6,
                                1 << 10);

        gSPScisTextureRectangle(arg0++, left << 2, (top + 24) << 2, (left + 640) << 2, (top + 48) << 2, 0, 0, 0, 1 << 6,
                                1 << 10);
    }

    for (i = temp_v1; i < 5; i += 2) {
        left = -D_843C4D92 * 2;
        top = i * 48;
        gSPScisTextureRectangle(arg0++, left << 2, top << 2, (left + 640) << 2, (top + 24) << 2, 0, 0x500, 0, -(1 << 6),
                                1 << 10);

        gSPScisTextureRectangle(arg0++, left << 2, (top + 24) << 2, (left + 640) << 2, (top + 48) << 2, 0, 0x500, 0,
                                -(1 << 6), 1 << 10);
    }

    gSPDisplayList(arg0++, D_8438AC30);

    return arg0;
}

void func_8436F664(void) {
    Gfx* gfx = gDisplayListHead;

    if (D_843C4D90 != 0) {
        if (D_843C4D90 == 2) {
            gfx = func_8436EFE8(gfx, 0);
        } else {
            gfx = func_8436EFE8(gfx, 1);
        }
    }
    gDisplayListHead = gfx;
}
