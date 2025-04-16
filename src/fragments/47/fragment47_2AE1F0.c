#include "fragment47.h"
#include "src/12D80.h"
#include "src/1C720.h"
#include "src/1CF30.h"
#include "src/20470.h"
#include "src/22630.h"
#include "src/232C0.h"
#include "src/49790.h"
#include "src/F420.h"
#include "src/controller.h"
#include "src/fragments/61/fragment61.h"
#include "src/math_util.h"
#include "src/memmap.h"
#include "src/memory.h"

typedef struct unk_D_8380548C {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
} unk_D_8380548C; // size = 0xE

typedef struct unk_D_83806778 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ char unk_06[1];
    /* 0x07 */ char unk07[0xD];
} unk_D_83806778; // size = 0x14

static GraphNode* D_83805670;
static unk_D_86002F58_004_000_004* D_83805678[6];
static unk_D_86002F58_004_000_004* D_83805690;
static unk_D_86002F58_004_000 D_83805698[2][6];
static unk_D_83806778 D_83806778[4];
static u8* D_838067C8[4];
static s32 D_838067D8;
static s32 D_838067DC;
static s32 D_838067E0;
static s16 D_838067E4;
static s16 D_838067E6;

static u32 D_83804CC0[] = {
    0x0C000000,  0x05000000, 0x0B00002D, 0x00000000, 0x028001E0, 0x00000000, 0xFDBD0000,
    0x00000243,  0x05000000, 0x0D000000, 0x05000000, 0x0F000002, 0x05000000, 0x0A000000,
    &D_800AC840, 0x06000000, 0x06000000, 0x06000000, 0x06000000, 0x01000000,
};
static Vtx D_83804D10[] = {
    VTX(-32, 64, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-32, 32, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, 32, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(32, 64, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, 32, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-32, 0, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, 0, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(32, 32, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-16, 39, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-16, 15, 0, 0, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(16, 15, 0, 1024, 768, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(16, 39, 0, 1024, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_83804DD0[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_PASS2),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_83804D10, 12, 0),
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
static u32 D_83804EB8[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_83804D10, 0x05000000, 0x22040000,
    0x00000000, 0x08000000, func_83800900, D_83804DD0, 0x06000000, 0x01000000, 0x00000000,
};
static Vtx D_83804EF0[] = {
    VTX(-50, 68, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(-50, 51, 0, 0, 544, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(50, 51, 0, 3200, 544, 0xFF, 0xFF, 0xFF, 0xFF), VTX(50, 68, 0, 3200, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-50, 51, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(-50, 34, 0, 0, 544, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(50, 34, 0, 3200, 544, 0xFF, 0xFF, 0xFF, 0xFF), VTX(50, 51, 0, 3200, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-50, 34, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(-50, 17, 0, 0, 544, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(50, 17, 0, 3200, 544, 0xFF, 0xFF, 0xFF, 0xFF), VTX(50, 34, 0, 3200, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-50, 17, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(-50, 0, 0, 0, 544, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(50, 0, 0, 3200, 544, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(50, 17, 0, 3200, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_83804FF0[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_83804EF0, 16, 0),
    gsDPLoadTextureBlock(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 100, 17, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(0x0F000D48, G_IM_FMT_RGBA, G_IM_SIZ_16b, 100, 17, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsDPLoadTextureBlock(0x0F001A90, G_IM_FMT_RGBA, G_IM_SIZ_16b, 100, 17, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsDPLoadTextureBlock(0x0F0027D8, G_IM_FMT_RGBA, G_IM_SIZ_16b, 100, 17, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};
static u32 D_83805118[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_83804EF0, 0x05000000, 0x22050000,
    0x00000000, 0x08000000, func_83800900, D_83804FF0, 0x06000000, 0x01000000, 0x00000000,
};
static Vtx D_83805150[] = {
    VTX(-50, 64, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(-50, 48, 0, 0, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(50, 48, 0, 3200, 512, 0xFF, 0xFF, 0xFF, 0xFF), VTX(50, 64, 0, 3200, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-50, 48, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(-50, 32, 0, 0, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(50, 32, 0, 3200, 512, 0xFF, 0xFF, 0xFF, 0xFF), VTX(50, 48, 0, 3200, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-50, 32, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(-50, 16, 0, 0, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(50, 16, 0, 3200, 512, 0xFF, 0xFF, 0xFF, 0xFF), VTX(50, 32, 0, 3200, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-50, 16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(-50, 0, 0, 0, 512, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(50, 0, 0, 3200, 512, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(50, 16, 0, 3200, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_83805250[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_PASS2),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_83805150, 16, 0),
    gsDPLoadTextureBlock(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 100, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(0x0F000C80, G_IM_FMT_RGBA, G_IM_SIZ_16b, 100, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsDPLoadTextureBlock(0x0F001900, G_IM_FMT_RGBA, G_IM_SIZ_16b, 100, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsDPLoadTextureBlock(0x0F002580, G_IM_FMT_RGBA, G_IM_SIZ_16b, 100, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};
static u32 D_83805378[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_83805150, 0x05000000, 0x22040000,
    0x00000000, 0x08000000, func_83800900, D_83805250, 0x06000000, 0x01000000, 0x00000000,
};
static Vtx D_838053B0[] = {
    VTX(-36, 12, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-36, -12, 0, 0, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(36, -12, 0, 2304, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(36, 12, 0, 2304, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_838053F0[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(0, 0, 0, 0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_838053B0, 4, 0),
    gsDPLoadTextureBlock_4b(0x0F000000, G_IM_FMT_I, 80, 24, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                            G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};
static u32 D_83805458[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_838053B0, 0x05000000, 0x22050000,
    0x00000000, 0x08000000, func_83800900, D_838053F0, 0x06000000, 0x01000000,
};
static unk_D_8380548C D_8380548C[] = {
    {
        0x01,
        0x00,
        134,
        210,
        64,
        0,
        0,
        1472,
    },
    {
        0x01,
        0x00,
        258,
        210,
        64,
        -32768,
        -32768,
        1664,
    },
    {
        0x01,
        0x00,
        382,
        210,
        64,
        0,
        0,
        1408,
    },
    {
        0x01,
        0x00,
        506,
        210,
        64,
        -32768,
        -32768,
        1600,
    },
    {
        0x01,
        0x00,
        190,
        368,
        100,
        0,
        0,
        1568,
    },
    {
        0x01,
        0x00,
        450,
        368,
        100,
        -32768,
        -32768,
        1504,
    },
};
static s16 D_838054E0[] = { 0x46, 0x28, 0x1E, 0x1E, 0x1E, 0x1E, 0x28, 0x3C, 0x5A, 0x78, 0x6E, 0x64 };
static s16 D_838054F8[] = { 0x14, 0x3C, 0x5F, 0x78, 0x82, 0x87, 0x82, 0x78, 0x6E, 0x69, 0x66, 0x64 };
static s16 D_83805510[] = { 0x46, 0x32, 0x28, 0x1E, 0x19, 0x14, 0x14, 0x14, 0x19, 0x1E, 0x28, 0x32 };
static s16 D_83805528[] = { 0x64, 0x6E, 0x82, 0x96, 0xA0, 0xA0, 0x78, 0x50, 0x32, 0x1E, 0xA, 5 };

s32 func_83800900(s32 arg0, GraphNode* arg1) {
    u8* var_a0;
    u8* var_a3;

    if (arg0 == 5) {
        switch (D_8006F09C->unk_000.unk_14) {
            case 0:
                // clang-format off
                var_a0 = D_838067C8[0]; var_a3 = D_201D820;
                break;

            case 1:
                var_a0 = D_838067C8[1]; var_a3 = D_201DB20;
                break;

            case 2:
                var_a0 = D_838067C8[2]; var_a3 = D_201DE20;
                break;

            case 3:
                var_a0 = D_838067C8[3]; var_a3 = D_201E120;
                // clang-format on
                break;

            case 4:
                var_a0 = D_201A620;
                var_a3 = NULL;
                break;

            case 5:
                var_a0 = D_04001800;
                var_a3 = NULL;
                break;

            default:
                var_a0 = D_2028420;
                var_a3 = NULL;
                break;
        }

        gDPPipeSync(gDisplayListHead++);
        gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, D_8006F09C->unk_01D);
        gSPSegment(gDisplayListHead++, 0x0F, Memmap_GetSegmentVaddr(var_a0));
        gSPSegment(gDisplayListHead++, 0x0E, Memmap_GetSegmentVaddr(var_a3));
        gSPDisplayList(gDisplayListHead++, arg1->unk_14);

        func_80015684();
    }
    return 0;
}

void func_83800AA0(s32 arg0, f32 arg1) {
    s16 var_a2;
    f32 var_fa0;

    if (arg0 == D_838067E0) {
        var_fa0 = 0.06f;
        var_a2 = 0x3000;
    } else {
        var_fa0 = 0.02f;
        var_a2 = 0x2000;
    }

    D_83805698[0][arg0].unk_030.x = ((SINS(D_8380548C[arg0].unk_0A) * var_fa0) + 1.0f) * arg1;
    D_83805698[0][arg0].unk_030.y = ((COSS(D_8380548C[arg0].unk_0A) * var_fa0) + 1.0f) * arg1;

    D_83805698[1][arg0].unk_030.x = D_83805698[0][arg0].unk_030.x;
    D_83805698[1][arg0].unk_030.y = D_83805698[0][arg0].unk_030.y;

    D_8380548C[arg0].unk_0A += var_a2 + ((MathUtil_Random16() & 0xF) * 0x10);
}

void func_83800BA8(s32 arg0, f32 arg1) {
    f32 var_fv0;
    s16 var_v0;

    if (arg0 == D_838067E0) {
        var_fv0 = 1.5f;
        var_v0 = D_8380548C[arg0].unk_0C * 2;
    } else {
        var_fv0 = 1.0f;
        var_v0 = D_8380548C[arg0].unk_0C;
    }

    D_83805698[0][arg0].unk_01E.z = SINS(D_8380548C[arg0].unk_08) * (1536.0f * var_fv0);
    D_83805698[1][arg0].unk_024.x = D_83805698[0][arg0].unk_024.x =
        (D_8380548C[arg0].unk_02 - 320.0f) - (SINS(D_8380548C[arg0].unk_08) * (6.0f * var_fv0));

    D_8380548C[arg0].unk_08 += var_v0;
}

void func_83800CB0(void) {
    s32 i;
    u8 temp_s3 = Cont_GetControllerBits();
    unk_D_800AC910_040 sp48;

    for (i = 0; i < 4; i++) {
        func_80025040(i, &sp48);
        func_80021A90(D_83806778[i].unk_06, &sp48.unk_02);
        D_83806778[i].unk_04 = sp48.unk_00;
        D_83806778[i].unk_01 = func_80024F68(i);
        D_83806778[i].unk_00 = func_80024F00(i);
        D_83806778[i].unk_02 = func_80025370(i);
        D_83806778[i].unk_03 = (temp_s3 & (1 << i)) != 0;
    }
}

void func_83800D8C(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_83806778[i].unk_01 != 0) {
            switch (D_83806778[i].unk_01) {
                case 1:
                    D_838067C8[i] = D_201E420;
                    break;

                case 2:
                    D_838067C8[i] = D_2020420;
                    break;

                case 3:
                    D_838067C8[i] = D_2022420;
                    break;

                case 7:
                    D_838067C8[i] = D_2024420;
                    break;
            }

            if (D_83806778[i].unk_00 != 0) {
                D_8380548C[i].unk_01 = 0x14;
            }
        } else {
            D_838067C8[i] = &D_2026420;
            if (D_83806778[i].unk_00 == 2) {
                D_8380548C[i].unk_01 = 0x15;
            } else {
                D_8380548C[i].unk_00 = 0;
                D_8380548C[i].unk_01 = 1;
            }
        }
    }
}

void func_83800EFC(void) {
    MemoryBlock* temp_s1;
    s32 i;
    unk_D_86002F58_004_000_004* temp_v0_2;
    unk_D_86002F58_004_000* ptr;

    temp_s1 = func_80002D10(main_pool_get_available(), 0);
    D_838067D8 = 0;
    D_83805670 = process_geo_layout(temp_s1, D_83804CC0);
    temp_v0_2 = process_geo_layout(temp_s1, D_83804EB8);
    D_83805678[0] = temp_v0_2;
    D_83805678[1] = temp_v0_2;
    D_83805678[2] = temp_v0_2;
    D_83805678[3] = temp_v0_2;
    D_83805678[4] = process_geo_layout(temp_s1, D_83805378);
    D_83805678[5] = process_geo_layout(temp_s1, D_83805118);
    D_83805690 = process_geo_layout(temp_s1, D_83805458);
    func_80002D60(temp_s1);
    func_8001BB20();

    for (i = 0, ptr = &D_83805698[0][0]; i < 12; ptr++, i++) {
        func_8001BB58(ptr);
        D_83805698[0][i].unk_000.unk_14 = i;
    }

    func_83800CB0();
    func_83800D8C();
}

void func_8380101C(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        if (D_8380548C[i].unk_00 != 0) {
            func_8001BC34(D_83805698[0] + i, 0, 0, D_83805678[i]);
            func_8001BC34(D_83805698[1] + i, 0, 0, D_83805690);
            func_8000E88C(&D_83805698[0][i].unk_024, D_8380548C[i].unk_02 - 0x140, 0xF0 - D_8380548C[i].unk_04,
                          -579.0f);
            func_8000E88C(&D_83805698[1][i].unk_024, D_8380548C[i].unk_02 - 0x140, 0xE4 - D_8380548C[i].unk_04,
                          -579.0f);
            D_83805698[1][i].unk_01D = 0xB4;
        }
    }
}

s32 func_83801190(s32 arg0) {
    if (D_838067D8 == 0) {
        func_8380101C();
        if (arg0 < 0) {
            for (D_838067E0 = 0; D_838067E0 < 5; D_838067E0++) {
                if (D_8380548C[D_838067E0].unk_00 != 0) {
                    break;
                }
            }
        } else {
            D_838067E0 = arg0;
        }
        D_838067D8 = 1;
        D_838067DC = 0;
        return 1;
    }
    return 0;
}

void func_83801248(void) {
    s32 i;

    for (i = 0; i < 12; i++) {
        D_83805698[0][i].unk_030.x = D_838054E0[D_838067DC] / 100.0f;
        D_83805698[0][i].unk_030.y = D_838054F8[D_838067DC] / 100.0f;
    }

    D_838067E4 = ((((D_838067DC * 0x32) + 0x32) / 12) + 6) & (u16)~0x1;
    D_838067E6 = ((((D_838067DC * 0x24) + 0x24) / 12) + 4) & (u16)~0x1;

    D_838067DC++;
    if (D_838067DC == 0xC) {
        D_838067D8 = 3;
    }
}

void func_83801398(void) {
    s32 i;
    s32 var_a0;
    s32 var_v1;

    if (D_838067E0 >= 4) {
        if (D_838067E0 == 4) {
            var_v1 = 0;
            var_a0 = 1;
        } else {
            var_v1 = 3;
            var_a0 = -1;
        }

        for (i = 0; i < 4; i++) {
            if (D_8380548C[var_v1].unk_00 != 0) {
                D_838067E0 = var_v1;
                func_80048B90(1);
                break;
            }
            var_v1 = (var_v1 + var_a0) & 3;
        }
    }
}

void func_8380142C(void) {
    s32 var_v0;
    s32 i;

    if (D_838067E0 < 4) {
        var_v0 = (D_838067E0 / 2) + 4;

        for (i = 0; i < 2; i++) {
            if (D_8380548C[var_v0].unk_00 != 0) {
                D_838067E0 = var_v0;
                func_80048B90(1);
                break;
            }
            var_v0 ^= 1;
        }
    }
}

void func_838014B8(void) {
    s32 i;

    if ((D_838067E0 > 0) && (D_838067E0 < 4)) {
        for (i = D_838067E0 - 1; i >= 0; i--) {
            if (D_8380548C[i].unk_00 != 0) {
                D_838067E0 = i;
                func_80048B90(1);
                break;
            }
        }
    } else if (D_838067E0 == 5) {
        D_838067E0 = 4;
        func_80048B90(1);
    }
}

void func_83801554(void) {
    s32 i;

    if (D_838067E0 < 3) {
        for (i = D_838067E0 + 1; i < 4; i++) {
            if (D_8380548C[i].unk_00 != 0) {
                D_838067E0 = i;
                func_80048B90(1);
                break;
            }
        }
    } else if (D_838067E0 == 4) {
        D_838067E0 = 5;
        func_80048B90(1);
    }
}

void func_838015F4(void) {
    s32 i;

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        if (D_8380548C[D_838067E0].unk_01 == 0) {
            func_80048B90(0x01100012);
            D_838067D8 = 4;
        } else {
            func_80048B90(8);
            D_838067D8 = 6;
        }
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
        D_838067D8 = 5;
        func_80048B90(3);
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP)) {
        func_83801398();
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DDOWN)) {
        func_8380142C();
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DLEFT)) {
        func_838014B8();
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DRIGHT)) {
        func_83801554();
    }

    for (i = 0; i < 6; i++) {
        func_83800AA0(i, 1.0f);
        func_83800BA8(i, 1.0f);
    }
}

void func_83801744(void) {
    s32 i;

    D_838067DC--;
    if (D_838067DC == 0) {
        for (i = 0; i < 6; i++) {
            if (i != D_838067E0) {
                func_8001BCF0(&D_83805698[0][i]);
                func_8001BCF0(&D_83805698[1][i]);
            }
        }
        D_838067E4 = 0;
        D_838067E6 = 0;
        D_838067D8 = 2;
    } else {
        for (i = 0; i < 6; i++) {
            if (i == D_838067E0) {
                func_83800AA0(i, 1.0f);
                func_83800BA8(i, 1.0f);
            } else {
                func_83800AA0(i, D_838067DC / 12.0f);
                func_83800BA8(i, D_838067DC / 12.0f);
            }
            D_838067E4 = ((((D_838067DC * 0x32) + 0x32) / 12) + 6) & 0xFFFE;
            D_838067E6 = ((((D_838067DC * 0x24) + 0x24) / 12) + 4) & 0xFFFE;
        }
    }
}

void func_83801988(void) {
    s32 var_a1 = D_838067DC;

    if (var_a1 > 0xC) {
        var_a1 = 0xC;
    }

    if (D_838067DC < 0xC) {
        D_83805698[0][D_838067E0].unk_030.x = D_83805510[var_a1] / 100.0f;
        D_83805698[0][D_838067E0].unk_030.y = D_83805528[var_a1] / 100.0f;

        D_83805698[1][D_838067E0].unk_030.x = D_83805510[var_a1] / 100.0f;
        D_83805698[1][D_838067E0].unk_030.y = D_83805528[var_a1] / 100.0f;

        D_83805698[0][D_838067E0].unk_01E.z = 0;
    } else if (D_838067DC == 0xC) {
        func_8001BCF0(&D_83805698[0][D_838067E0]);
        func_8001BCF0(&D_83805698[1][D_838067E0]);
    } else if (D_838067DC == 0xE) {
        D_838067D8 = 0;
    }
    D_838067DC++;
}

void func_83801AE0(void) {
    s32 i;

    D_838067DC--;
    if (D_838067DC == 0) {
        for (i = 0; i < 6; i++) {
            func_8001BCF0(&D_83805698[0][i]);
            func_8001BCF0(&D_83805698[1][i]);
        }

        D_838067E0 = -2;
        D_838067E4 = 0;
        D_838067E6 = 0;
        D_838067D8 = 0;
    } else {
        for (i = 0; i < 6; i++) {
            func_83800AA0(i, D_838067DC / 12.0f);
            func_83800BA8(i, D_838067DC / 12.0f);
        }

        D_838067E4 = ((((D_838067DC * 0x32) + 0x32) / 12) + 6) & (u16)~1;
        D_838067E6 = ((((D_838067DC * 0x24) + 0x24) / 12) + 4) & (u16)~1;
    }
}

void func_83801C94(void) {
    s32 i;
    s32 var_v0;

    if (D_8380548C[D_838067E0].unk_01 == 0x15) {
        var_v0 = 0;
    } else {
        var_v0 = 1;
    }

    func_83402CE4(var_v0, gPlayer1Controller);
    if (func_83402DC8(var_v0) != -1) {
        D_838067D8 = 3;
    }

    for (i = 0; i < 6; i++) {
        func_83800AA0(i, 1.0f);
        func_83800BA8(i, 1.0f);
    }
}

void func_83801D64(void) {
    switch (D_838067D8) {
        case 1:
            func_83801248();
            break;

        case 2:
            func_83801988();
            break;

        case 3:
            func_838015F4();
            break;

        case 4:
            func_83801744();
            break;

        case 5:
            func_83801AE0();
            break;

        case 6:
            func_83801C94();
            break;
    }
}

void func_83801E00(void) {

    if (D_838067D8 == 3) {
        s32 tmp = D_8380548C[D_838067E0].unk_02 - (D_8380548C[D_838067E0].unk_06 / 2) - 0x1E;
        s32 tmp2 = D_8380548C[D_838067E0].unk_04 - 0x20;

        func_80020928(tmp, tmp2);
    }
}

void func_83801E84(s32 arg0, s16 arg1, s32 arg2) {
    Color_RGBA8 sp2C;

    if (D_8380548C[arg0].unk_00 != 0) {
        if (D_8380548C[arg0].unk_01 == 0) {
            func_8000E840(&sp2C, 0x1E, 0x1E, 0x82, 0xFF);
        } else {
            func_8000E840(&sp2C, 0x64, 0x1E, 0x1E, 0xFF);
        }
    } else {
        func_8000E840(&sp2C, 0x1E, 0x1E, 0x82, 0x80);
    }
    func_8420092C((arg0 << 7) + 0x44, arg1 + 0x54, 0x78, arg2, sp2C.r, sp2C.g, sp2C.b, sp2C.a);
}

void func_83801F84(s32 arg0) {
    UNUSED s32 pad;

    if (D_8380548C[arg0].unk_00 != 0) {
        if (D_8380548C[arg0].unk_01 == 0) {
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            func_8001EBE0(8, 0);
            func_8001F1E8(((arg0 << 7) - (func_8001F5B0(8, 0, D_83806778[arg0].unk_06) / 2)) + 0x80, 0x5C,
                          D_83806778[arg0].unk_06);
            func_8001F324(0xFF, 0xBE, 0xFF, 0xFF);
            func_8001EBE0(4, 0);
            func_8001F1E8(((arg0 << 7) - (func_8001F5B0(4, 0, "ID  00000") / 2)) + 0x80, 0x73, "ID  %05d",
                          D_83806778[arg0].unk_04);
        } else {
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
            func_8001EBE0(8, 0);
            func_8001F1E8(((arg0 << 7) - (func_8001F5B0(8, 0, "???????") / 2)) + 0x80, 0x5C, "???????");
            func_8001F324(0xFF, 0xBE, 0xFF, 0xFF);
            func_8001EBE0(4, 0);
            func_8001F1E8(((arg0 << 7) - (func_8001F5B0(4, 0, "ID  *****") / 2)) + 0x80, 0x73, "ID  *****");
        }
    }
}

void func_8380217C(void) {
    char* temp_v0;

    func_8001F3F4();
    func_83801F84(0);
    func_83801F84(1);
    func_83801F84(2);
    func_83801F84(3);
    func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
    func_8001EBE0(0x10, 0);
    if (D_838067E0 != 5) {
        temp_v0 = func_83402374(0x35);
        func_8001F1E8(0x140 - (func_8001F5B0(0, 0, temp_v0) / 2), 0x198, temp_v0);
    }
    func_8001EBE0(8, 0);
    temp_v0 = func_83402374(0x33);
    func_8001F1E8(0xC0 - (func_8001F5B0(0, 0, temp_v0) / 2), 0x102, temp_v0);
    temp_v0 = func_83402374(0x34);
    func_8001F1E8(0x1C0 - (func_8001F5B0(0, 0, temp_v0) / 2), 0x102, temp_v0);
    func_8001F444();
}

void func_838022C8(s32 arg0) {
    UNUSED s32 pad;
    s16 sp3A;
    s16 temp_s0;

    if ((D_838067D8 != 0) && (arg0 != 0)) {
        temp_s0 = (0x38 - D_838067E4) / 2;
        sp3A = (0x28 - D_838067E6) / 2;
        func_80015094(D_83805670);
        func_83801E00();

        if (D_838067E4 > 0) {
            func_83801E84(0, temp_s0, D_838067E4);
            func_83801E84(1, temp_s0, D_838067E4);
            func_83801E84(2, temp_s0, D_838067E4);
            func_83801E84(3, temp_s0, D_838067E4);
            func_8420092C(0x44, temp_s0 + 0xF0, 0xF8, D_838067E4, 0x78, 0x1E, 0x64, 0xFF);
            func_8420092C(0x144, temp_s0 + 0xF0, 0xF8, D_838067E4, 0x78, 0x1E, 0x64, 0xFF);
        }

        if (D_838067E6 > 0) {
            func_8420112C(0x38, sp3A + 0x190, 0x210, D_838067E6, 0x1E, 0x1E, 0x82, 0x96);
        }

        if (D_838067E4 == 0x38) {
            func_8380217C();
        }
    }
}

s32 func_8380248C(void) {
    if (D_838067D8 == 0) {
        return D_838067E0;
    }
    return -1;
}
