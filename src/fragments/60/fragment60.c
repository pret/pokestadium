#include "fragment60.h"
#include "src/12D80.h"
#include "src/1C720.h"
#include "src/1CF30.h"
#include "src/20330.h"
#include "src/26820.h"
#include "src/3FB0.h"
#include "src/49790.h"
#include "src/F420.h"
#include "src/controller.h"
#include "src/geo_layout.h"
#include "src/memmap.h"
#include "src/memory.h"
#include "src/stage_loader.h"

static BinArchive* D_82E019B0;
static void* D_82E019B4;
static GraphNode* D_82E019B8;
static GraphNode* D_82E019BC;
static GraphNode* D_82E019C0;
static unk_D_86002F58_004_000 D_82E019C8[4];
static unk_D_86002F58_004_000 D_82E01F68[3];
static unk_func_80027FA0 D_82E023A0;
static s16 D_82E023A8;
static s16 D_82E023AA;

static u32 D_82E01110[] = {
    0x0C000000, 0x05000000, 0x0B00002D,  0x00000000, 0x028001E0, 0x00000000, 0xFDBD0000, 0x00000243,
    0x05000000, 0x0D000000, 0x05000000,  0x14000000, 0x00000000, 0xFFFFFF32, 0x16FFFFFF, 0x0F000002,
    0x05000000, 0x0A000000, &D_800AC840, 0x06000000, 0x06000000, 0x06000000, 0x06000000, 0x01000000,
};
static u8* D_82E01170[] = { D_3000000, D_3009000, D_3012000, D_301B000 };
static Vtx D_82E01180[] = {
    VTX(-128, 36, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-128, 12, 0, 0, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, 12, 0, 2048, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, 36, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82E011C0[] = {
    VTX(-64, 36, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, 12, 0, 2048, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 12, 0, 4096, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 36, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82E01200[] = {
    VTX(0, 36, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 12, 0, 4096, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, 12, 0, 6144, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, 36, 0, 6144, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82E01240[] = {
    VTX(64, 36, 0, 6144, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, 12, 0, 6144, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(128, 12, 0, 8192, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(128, 36, 0, 8192, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82E01280[] = {
    VTX(-128, 12, 0, 0, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-128, -12, 0, 0, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, -12, 0, 2048, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, 12, 0, 2048, 768, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82E012C0[] = {
    VTX(-64, 12, 0, 2048, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, -12, 0, 2048, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -12, 0, 4096, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 12, 0, 4096, 768, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82E01300[] = {
    VTX(0, 12, 0, 4096, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -12, 0, 4096, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -12, 0, 6144, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, 12, 0, 6144, 768, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82E01340[] = {
    VTX(64, 12, 0, 6144, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -12, 0, 6144, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(128, -12, 0, 8192, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(128, 12, 0, 8192, 768, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82E01380[] = {
    VTX(-128, -12, 0, 0, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-128, -36, 0, 0, 2304, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, -36, 0, 2048, 2304, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, -12, 0, 2048, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82E013C0[] = {
    VTX(-64, -12, 0, 2048, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-64, -36, 0, 2048, 2304, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -36, 0, 4096, 2304, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -12, 0, 4096, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82E01400[] = {
    VTX(0, -12, 0, 4096, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -36, 0, 4096, 2304, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -36, 0, 6144, 2304, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -12, 0, 6144, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Vtx D_82E01440[] = {
    VTX(64, -12, 0, 6144, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -36, 0, 6144, 2304, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(128, -36, 0, 8192, 2304, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(128, -12, 0, 8192, 1536, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_82E01480[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 0, 0, 63, 23, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82E01180, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 64, 0, 127, 23, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82E011C0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 128, 0, 191, 23, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82E01200, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 192, 0, 255, 23, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82E01240, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 0, 24, 63, 47, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82E01280, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 64, 24, 127, 47, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82E012C0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 128, 24, 191, 47, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82E01300, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 192, 24, 255, 47, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82E01340, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 0, 48, 63, 71, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82E01380, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 64, 48, 127, 71, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(D_82E013C0, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 128, 48, 191, 71, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82E01400, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, 0, 192, 48, 255, 71, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD),
    gsSPVertex(D_82E01440, 4, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};
static u32 D_82E01800[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_82E01180, 0x05000000, 0x22050000,
    0x00000000, 0x08000000, func_82E00274, 0x00000000, 0x06000000, 0x01000000, 0x00000000,
};
static Vtx D_82E01838[] = {
    VTX(-38, 18, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-38, 0, 0, 0, 576, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(38, 0, 0, 2432, 576, 0xFF, 0xFF, 0xFF, 0xFF),   VTX(38, 18, 0, 2432, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-38, 0, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(-38, -18, 0, 0, 576, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(38, -18, 0, 2432, 576, 0xFF, 0xFF, 0xFF, 0xFF), VTX(38, 0, 0, 2432, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_82E018B8[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_82E01838, 8, 0),
    gsDPLoadTextureBlock(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 76, 18, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(0x0F000AB0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 76, 18, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};
static u32 D_82E01960[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_82E01838, 0x05000000, 0x22050000,
    0x00000000, 0x08000000, func_82E0036C, 0x00000000, 0x06000000, 0x01000000,
};

void func_82E00020(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    func_8001F730();
}

void func_82E00050(void) {
}

void func_82E00058(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    static s16 D_82E01994 = 0;

    s16 sp56 = SINS(D_82E01994) * 2;
    UNUSED s32 pad[2];

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, arg4, arg5, arg6, arg7);

    func_8001CADC((arg0 + sp56) - 8, (arg1 + sp56) - 8, 0x10, 0x10, D_2000C80, 0x10, 0);
    func_8001CADC((arg0 + sp56) - 8, ((arg1 + arg3) - sp56) - 8, 0x10, 0x10, D_2000F80, 0x10, 0);
    func_8001CADC(((arg0 + arg2) - sp56) - 8, (arg1 + sp56) - 8, 0x10, 0x10, D_2000D80, 0x10, 0);
    func_8001CADC(((arg0 + arg2) - sp56) - 8, ((arg1 + arg3) - sp56) - 8, 0x10, 0x10, D_2000E80, 0x10, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    D_82E01994 += 0x2000;
}

s32 func_82E00274(s32 arg0, unk_func_80011B94* arg1) {
    s32 temp_a3;
    s32 var_t0;

    if (arg0 == 5) {
        temp_a3 = D_8006F09C->unk_000.unk_14;
        if (D_82E023AA >= temp_a3) {
            var_t0 = 0xFF;
        } else {
            var_t0 = 0x80;
        }

        gDPPipeSync(gDisplayListHead++);
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, var_t0);
        gSPSegment(gDisplayListHead++, 0x0F, Memmap_GetSegmentVaddr(D_82E01170[temp_a3]));
        gSPDisplayList(gDisplayListHead++, D_82E01480);

        func_80015684();
    }
    return 0;
}

s32 func_82E0036C(s32 arg0, unk_func_80011B94* arg1) {
    s32 var_a3;

    if (arg0 == 5) {
        s32 tmp = D_8006F09C->unk_000.unk_14;

        if (tmp < D_82E023AA) {
            var_a3 = 0xFF;
        } else {
            var_a3 = 0x80;
        }

        gDPPipeSync(gDisplayListHead++);
        gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, var_a3);
        gSPSegment(gDisplayListHead++, 0x0F, Memmap_GetSegmentVaddr(D_3024000));
        gSPDisplayList(gDisplayListHead++, D_82E018B8);

        func_80015684();
    }
    return 0;
}

void func_82E0045C(s32 arg0, s32 arg1) {
    func_800079C4();
    func_8001D924(D_82E019B4);
    func_80015094(D_82E019B8);

    if (arg0 == 0) {
        if ((arg1 >= 0) && (arg1 < 0xB)) {
            D_82E019C8[0].unk_01E.y = ((0xA - arg1) * -0x5000) / 10;
        }

        if ((arg1 >= 2) && (arg1 < 0xD)) {
            D_82E01F68[0].unk_01E.y = ((0xC - arg1) * -0x5000) / 10;
        }

        if ((arg1 >= 4) && (arg1 < 0xF)) {
            D_82E019C8[1].unk_01E.y = ((0xE - arg1) * -0x5000) / 10;
        }

        if ((arg1 >= 6) && (arg1 < 0x11)) {
            D_82E01F68[1].unk_01E.y = ((0x10 - arg1) * -0x5000) / 10;
        }

        if ((arg1 >= 8) && (arg1 < 0x13)) {
            D_82E019C8[2].unk_01E.y = ((0x12 - arg1) * -0x5000) / 10;
        }

        if ((arg1 >= 0xA) && (arg1 < 0x15)) {
            D_82E01F68[2].unk_01E.y = ((0x14 - arg1) * -0x5000) / 10;
        }

        if ((arg1 >= 0xC) && (arg1 < 0x17)) {
            D_82E019C8[3].unk_01E.y = ((0x16 - arg1) * -0x5000) / 10;
        }
    }

    if (arg0 == 2) {
        if ((arg1 >= 0) && (arg1 < 0xB)) {
            D_82E019C8[0].unk_01E.y = ((arg1 - 0) * 0x5000) / 10;
        }

        if ((arg1 >= 2) && (arg1 < 0xD)) {
            D_82E01F68[0].unk_01E.y = (((arg1 - 0x2) * 0x5000)) / 10;
        }

        if ((arg1 >= 4) && (arg1 < 0xF)) {
            D_82E019C8[1].unk_01E.y = (((arg1 - 0x4) * 0x5000)) / 10;
        }

        if ((arg1 >= 6) && (arg1 < 0x11)) {
            D_82E01F68[1].unk_01E.y = (((arg1 - 0x6) * 0x5000)) / 10;
        }

        if ((arg1 >= 8) && (arg1 < 0x13)) {
            D_82E019C8[2].unk_01E.y = (((arg1 - 0x8) * 0x5000)) / 10;
        }

        if ((arg1 >= 0xA) && (arg1 < 0x15)) {
            D_82E01F68[2].unk_01E.y = (((arg1 - 0xA) * 0x5000)) / 10;
        }

        if ((arg1 >= 0xC) && (arg1 < 0x17)) {
            D_82E019C8[3].unk_01E.y = (((arg1 - 0xC) * 0x5000)) / 10;
        }
    }

    if (arg0 == 1) {
        func_82E00058(0xD0, (D_82E023A8 * 0x6C) + 0x32, 0xE0, 0x38, 0xFF, 0xF0, 0x64, 0xFF);
    }
    func_80007778();
}

void func_82E00A54(void) {
    s32 i;
    unk_D_86002F58_004_000* var_s1;
    unk_D_86002F58_004_000* var_s2;

    for (var_s1 = &D_82E019C8[0], i = 0; i < 4; i++, var_s1++) {
        func_8001BC34(var_s1, 0, 0, D_82E019BC);
        D_82E019C8[i].unk_01E.y = -0x5000;
    }

    func_8000E88C(&D_82E019C8[0].unk_024, 0.0f, 162.0f, -579.0f);
    func_8000E88C(&D_82E019C8[1].unk_024, 0.0f, 54.0f, -579.0f);
    func_8000E88C(&D_82E019C8[2].unk_024, 0.0f, -54.0f, -579.0f);
    func_8000E88C(&D_82E019C8[3].unk_024, 0.0f, -162.0f, -579.0f);

    for (var_s2 = &D_82E01F68[0], i = 0; i < 3; i++, var_s2++) {
        func_8001BC34(var_s2, 0, 0, D_82E019C0);
        D_82E01F68[i].unk_01E.y = -0x5000;
    }

    func_8000E88C(&D_82E01F68[0].unk_024, 0.0f, 108.0f, -579.0f);
    func_8000E88C(&D_82E01F68[1].unk_024, 0.0f, 0, -579.0f);
    func_8000E88C(&D_82E01F68[2].unk_024, 0.0f, -108.0f, -579.0f);
}

s32 func_82E00BDC(void) {
    s32 var_v1 = 'exec';

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        func_80048B90(0x26);
        D_800AE540.unk_0002 = D_82E023A8;
        var_v1 = 'slct';
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
        func_80048B90(3);
        var_v1 = 'quit';
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP)) {
        if (D_82E023A8 > 0) {
            func_80048B90(1);
            D_82E023A8--;
        }
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DDOWN) && (D_82E023A8 < D_82E023AA)) {
        func_80048B90(1);
        D_82E023A8++;
    }
    return var_v1;
}

s32 func_82E00CF0(void) {
    s16 i;
    s32 temp_v0 = 'exec';
    s32 temp_v1;

    func_82E00A54();
    D_82E023A8 = D_82E023AA;

    for (i = 0; i < 23; i++) {
        func_82E00020();
        func_82E0045C(0, i);
    }

    while (temp_v0 == 'exec') {
        func_82E00020();
        func_82E0045C(1, 0);
        temp_v0 = func_82E00BDC();
    }

    temp_v1 = temp_v0 == 'slct';
    if (temp_v1) {
        for (i = 0; i < 23; i++) {
            func_82E00020();
            func_82E0045C(2, i);
        }
    } else {
        func_80007990(0xFFFF);
        func_80006CB4(8);
        while (func_80007604() != 1) {
            func_82E00020();
            func_82E0045C(1, 0);
        }
        func_800077B4(2);
    }
    return temp_v1;
}

void func_82E00E2C(void) {
    MemoryBlock* temp_v0 = func_80002D10(main_pool_get_available(), 0);
    s32 i;
    unk_D_86002F58_004_000* var_s2;

    D_82E019B8 = process_geo_layout(temp_v0, &D_82E01110);
    D_82E019BC = process_geo_layout(temp_v0, &D_82E01800);
    D_82E019C0 = process_geo_layout(temp_v0, &D_82E01960);
    func_80002D60(temp_v0);
    func_8001BB20();

    for (var_s2 = &D_82E019C8[0], i = 0; i < 4; var_s2++, i++) {
        func_8001BB58(var_s2);
        D_82E019C8[i].unk_000.unk_14 = i;
    }

    for (var_s2 = &D_82E01F68[0], i = 0; i < 3; var_s2++, i++) {
        func_8001BB58(var_s2);
        D_82E01F68[i].unk_000.unk_14 = i;
    }
}

s32 func_82E00F2C(UNUSED s32 arg0, UNUSED s32 arg1) {
    s16 var_v1 = -1;
    s32 sp18 = 1;

    switch (D_800AE540.unk_0000) {
        case 3:
            var_v1 = 9;
            break;

        case 6:
            var_v1 = 0xC;
            break;
    }

    if (var_v1 != -1) {
        main_pool_push_state('LVSL');

        func_8001E94C(0x10, 0);
        func_80028AFC(2);
        func_80027FA0(&D_82E023A0, D_800AE540.unk_11F2);
        if (D_800AE540.unk_0000 == 3) {
            D_82E023AA = D_82E023A0.unk_05;
        } else {
            D_82E023AA = D_82E023A0.unk_06;
        }
        if (D_82E023AA == 4) {
            D_82E023AA -= 1;
        }

        ASSET_LOAD(D_1000000, common_menu1_ui, 0);
        ASSET_LOAD(D_2000000, common_menu2_ui, 0);
        ASSET_LOAD(D_3000000, cup_ball_select_ui, 0);

        D_82E019B0 = ASSET_LOAD2(backgrounds, 1, 1);
        D_82E019B4 = func_8000484C(D_82E019B0, var_v1);

        func_82E00E2C();
        func_80007754();
        sp18 = func_82E00CF0();
        func_8000771C();

        main_pool_pop_state('LVSL');
    }
    return sp18;
}
