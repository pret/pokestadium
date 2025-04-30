#include "fragment63.h"
#include "src/12D80.h"
#include "src/1C720.h"
#include "src/1CF30.h"
#include "src/20470.h"
#include "src/26820.h"
#include "src/49790.h"
#include "src/F420.h"
#include "src/math_util.h"
#include "src/memmap.h"
#include "src/memory.h"

static Vtx D_84B16AA0[] = {
    VTX(-64, 32, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),        VTX(-64, -32, 0, 0, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, -32, 0, 1024, 2048, 0xFF, 0xFF, 0xFF, 0xFF), VTX(-32, 32, 0, 1024, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, 32, 0, 1024, 0, 0xFF, 0xFF, 0xFF, 0xFF),     VTX(-32, -32, 0, 1024, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, -32, 0, 2048, 2048, 0xFF, 0xFF, 0xFF, 0xFF),   VTX(0, 32, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 32, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(0, -32, 0, 2048, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, -32, 0, 3072, 2048, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(32, 32, 0, 3072, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, 32, 0, 3072, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(32, -32, 0, 3072, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(64, -32, 0, 4096, 2048, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(64, 32, 0, 4096, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_84B16BA0[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, COMBINED, COMBINED, 0, PRIM_LOD_FRAC, 0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84B16AA0, 16, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 0, 0, 0, 31, 63, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 0, 32, 0, 63, 63, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 0, 64, 0, 95, 63, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsDPLoadTextureTile(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 0, 96, 0, 127, 63, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
    gsSPEndDisplayList(),
};
static u32 D_84B16CC8[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_84B16AA0, 0x05000000, 0x22050000,
    0x00000000, 0x08000000, func_84B0BF10, D_84B16BA0, 0x06000000, 0x01000000,
};
static u32 D_84B16CFC[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_84B16AA0, 0x05000000, 0x22050000,
    0x00000000, 0x08000000, func_84B0BFE4, D_84B16BA0, 0x06000000, 0x01000000,
};
static Vtx D_84B16D30[] = {
    VTX(-16, 16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-16, -16, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(16, -16, 0, 1024, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(16, 16, 0, 1024, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_84B16D70[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, TEXEL0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84B16D30, 4, 0),
    gsDPLoadTextureBlock_4b(0x0F000000, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                            5, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};
static u32 D_84B16DD8[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_84B16D30, 0x05000000, 0x22050000,
    0x00000000, 0x08000000, func_84B0C094, D_84B16D70, 0x06000000, 0x01000000, 0x00000000,
};
static Vtx D_84B16E10[] = {
    VTX(-16, 16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-16, -16, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(16, -16, 0, 1024, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(16, 16, 0, 1024, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_84B16E50[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84B16E10, 4, 0),
    gsDPLoadTextureBlock_4b(D_3024800, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 5,
                            5, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};
static u32 D_84B16EB8[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_84B16E10, 0x05000000, 0x22050000,
    0x00000000, 0x08000000, func_84B0C3A4, D_84B16E50, 0x06000000, 0x01000000,
};
static Color_RGBA8 D_84B16EEC[] = { {
                                        0xFF,
                                        0x00,
                                        0x00,
                                        0xFF,
                                    },
                                    {
                                        0xE6,
                                        0x64,
                                        0x19,
                                        0xFF,
                                    },
                                    {
                                        0xFF,
                                        0xFF,
                                        0x00,
                                        0xFF,
                                    },
                                    {
                                        0xFF,
                                        0xFF,
                                        0xFF,
                                        0xFF,
                                    },
                                    {
                                        0xFF,
                                        0xFF,
                                        0xFF,
                                        0x80,
                                    } };

s32 func_84B0BF10(s32 arg0, unk_func_80011B94* arg1) {
    unk_D_84B25AC0* temp_a0;
    u8* var_a0;

    if (arg0 == 5) {
        temp_a0 = (unk_D_84B25AC0*)D_8006F09C->unk_000.unk_14;
        if (temp_a0->unk_5A2 != 0) {
            var_a0 = D_3018800;
        } else {
            var_a0 = D_301C800;
        }

        gDPPipeSync(gDisplayListHead++);
        gSPSegment(gDisplayListHead++, 0x0F, (u32)Memmap_GetSegmentVaddr(var_a0) & 0x1FFFFFFF);
        gSPDisplayList(gDisplayListHead++, arg1->unk_00.unk_14);

        func_80015684();
    }
    return 0;
}

s32 func_84B0BFE4(s32 arg0, unk_func_80011B94* arg1) {
    UNUSED s32 pad;

    if (arg0 == 5) {
        gDPPipeSync(gDisplayListHead++);
        gSPSegment(gDisplayListHead++, 0x0F, (u32)Memmap_GetSegmentVaddr(D_3020800) & 0x1FFFFFFF);
        gSPDisplayList(gDisplayListHead++, arg1->unk_00.unk_14);

        func_80015684();
    }
    return 0;
}

s32 func_84B0C094(s32 arg0, unk_func_80011B94* arg1) {
    unk_D_84B25AC0_000* temp_a0;

    if (arg0 == 5) {
        temp_a0 = (unk_D_84B25AC0_000*)D_8006F09C->unk_000.unk_14;

        gDPPipeSync(gDisplayListHead++);
        gSPSegment(gDisplayListHead++, 0x0F, (u32)temp_a0->unk_0C & 0x1FFFFFFF);
        gDPSetEnvColor(gDisplayListHead++, temp_a0->unk_08.r, temp_a0->unk_08.g, temp_a0->unk_08.b, 255);
        gSPDisplayList(gDisplayListHead++, arg1->unk_00.unk_14);

        func_80015684();
    }
    return 0;
}

void func_84B0C174(unk_D_84B25AC0_000* arg0, unk_D_86002F34* arg1, s16 arg2, s16 arg3, s16 arg4) {
    arg0->unk_04 = 0;
    arg0->unk_06 = arg4;
    arg0->unk_08.r = 0x50;
    arg0->unk_08.g = 0x64;
    func_8001BC34(arg0->unk_00, 0, 0, arg1);
    func_8000E88C(&arg0->unk_00->unk_030, 2.0f, 2.0f, 2.0f);
    arg0->unk_00->unk_000.unk_14 = arg0;
    arg0->unk_00->unk_024.x = (COSS(arg4) * 52.0f) + arg2;
    arg0->unk_00->unk_024.y = (SINS(arg4) * 26.0f) + arg3;
    arg0->unk_00->unk_024.z = -289.0f;
}

void func_84B0C278(unk_D_84B25AC0_000* arg0) {
    s16 temp_v0;
    unk_D_86002F58_004_000* temp_v1;
    unk_D_86002F58_004_000* temp_v1_2;

    if (arg0->unk_04 < 0x10) {
        arg0->unk_0C = Memmap_GetSegmentVaddr(((s32*)Memmap_GetSegmentVaddr(D_2023240))[(arg0->unk_04 / 2)]);
        arg0->unk_08.b = ((arg0->unk_04 * -0x5A) / 16) + 0x82;
        arg0->unk_00->unk_024.x += 2.0f * COSS(arg0->unk_06);
        arg0->unk_00->unk_024.y += 2.0f * SINS(arg0->unk_06);
        arg0->unk_04++;
    } else if (arg0->unk_04 == 0x10) {
        func_84B00404(arg0->unk_00);
        arg0->unk_04++;
    }
}

s32 func_84B0C3A4(s32 arg0, unk_func_80011B94* arg1) {
    unk_D_84B25AC0_0A0* temp_v1;

    if (arg0 == 5) {
        temp_v1 = (unk_D_84B25AC0_0A0*)D_8006F09C->unk_000.unk_14;

        gDPPipeSync(gDisplayListHead++);
        gDPSetEnvColor(gDisplayListHead++, temp_v1->unk_0A.r, temp_v1->unk_0A.g, temp_v1->unk_0A.b, temp_v1->unk_0A.a);
        gSPDisplayList(gDisplayListHead++, arg1->unk_00.unk_14);

        func_80015684();
    }
    return 0;
}

void func_84B0C45C(unk_D_84B25AC0_0A0* arg0, unk_D_86002F34* arg1, s16 arg2, s16 arg3, s16 arg4) {
    arg0->unk_06 = 0;
    arg0->unk_04 = 0;
    arg0->unk_08 = arg4;
    func_8001BC34(arg0->unk_00, 2, 0, arg1);
    arg0->unk_00->unk_000.unk_14 = arg0;
    arg0->unk_00->unk_024.x = (COSS(arg4) * 60.0f) + arg2;
    arg0->unk_00->unk_024.y = (SINS(arg4) * 30.0f) + arg3;
    arg0->unk_00->unk_024.z = -289.0f;
}

void func_84B0C534(unk_D_84B25AC0_0A0* arg0, unk_D_84B25AC0_0A0* arg1) {
    arg0->unk_06 = 0;
    arg0->unk_04 = 1;
    arg0->unk_0A = arg1->unk_0A;
    func_8001BC34(arg0->unk_00, 1, 0, &arg1->unk_00->unk_000.unk_0C->unk_00);
    arg0->unk_00->unk_000.unk_14 = arg0;
    arg0->unk_00->unk_024 = arg1->unk_00->unk_024;
    arg0->unk_00->unk_030 = arg1->unk_00->unk_030;
}

void func_84B0C5E4(unk_D_84B25AC0_0A0* arg0, unk_D_84B25AC0_0A0* arg1, s16 arg2) {
    arg0->unk_06 = 0;
    arg0->unk_04 = 2;
    arg0->unk_08 = arg1->unk_08 + arg2;

    func_8000E840(&arg0->unk_0A, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8001BC34(arg0->unk_00, 1, 0, &arg1->unk_00->unk_000.unk_0C->unk_00);
    arg0->unk_00->unk_000.unk_14 = arg0;
    arg0->unk_00->unk_024 = arg1->unk_00->unk_024;
    func_8000E88C(&arg0->unk_00->unk_030, 0.5f, 0.5f, 0.5f);
}

void func_84B0C6B4(unk_D_84B25AC0_0A0* arg0, unk_D_86002F34* arg1, Vec3f* arg2) {
    arg0->unk_06 = 0;
    arg0->unk_04 = 3;
    func_8000E840(&arg0->unk_0A, 0xFF, 0xFF, 0xC8, 0xFF);
    arg0->unk_0A.b = (MathUtil_Random16() % 200) + 0x32;
    func_8001BC34(arg0->unk_00, 2, 0, arg1);
    func_8000E88C(&arg0->unk_00->unk_030, 0.6f, 0.6f, 0.6f);
    arg0->unk_00->unk_000.unk_14 = arg0;
    arg0->unk_00->unk_024.x = ((MathUtil_Random_ZeroOne() - 0.5f) * 50.0f) + arg2->x;
    arg0->unk_00->unk_024.y = ((MathUtil_Random_ZeroOne() - 0.5f) * 40.0f) + arg2->y;
    arg0->unk_00->unk_024.z = arg2->z;
}

void func_84B0C7D0(unk_D_84B25AC0_0A0* arg0) {
    f32 temp_fv0;
    Color_RGBA8* color1;
    Color_RGBA8* color2;

    if (arg0->unk_06 < 0x10) {
        temp_fv0 = ((arg0->unk_06 * 0.5f) / 12.0f) + 0.3f;

        color1 = &D_84B16EEC[arg0->unk_06 / 4];
        color2 = &D_84B16EEC[arg0->unk_06 / 4 + 1];

        arg0->unk_0A.r = (((color2->r - color1->r) * (arg0->unk_06 % 4)) / 4) + color1->r;
        arg0->unk_0A.g = (((color2->g - color1->g) * (arg0->unk_06 % 4)) / 4) + color1->g;
        arg0->unk_0A.b = (((color2->b - color1->b) * (arg0->unk_06 % 4)) / 4) + color1->b;
        arg0->unk_0A.a = (((color2->a - color1->a) * (arg0->unk_06 % 4)) / 4) + color1->a;

        arg0->unk_00->unk_024.x += 3.0f * COSS(arg0->unk_08);
        arg0->unk_00->unk_024.y += (3.0f * SINS(arg0->unk_08)) - (arg0->unk_06 * 0.0625f);
        func_8000E88C(&arg0->unk_00->unk_030, temp_fv0, temp_fv0, temp_fv0);
        if (!(arg0->unk_06 & 3)) {
            func_84B0C534(&arg0[arg0->unk_06 / 4 + 1], arg0);
        }
        arg0->unk_06++;
    } else if (arg0->unk_06 == 0x10) {
        func_84B0C5E4(&arg0[5], &arg0[0], -0x6500);
        func_84B0C5E4(&arg0[6], &arg0[0], 0);
        func_84B0C5E4(&arg0[7], &arg0[0], 0x6500);
        func_84B00404(arg0->unk_00);
        arg0->unk_06 = -1;
    }
}

void func_84B0CA34(unk_D_84B25AC0_0A0* arg0) {
    arg0->unk_06++;
    if ((arg0->unk_06 >= 8) && (arg0->unk_06 < 0x10)) {
        func_8000E88C(&arg0->unk_00->unk_030, arg0->unk_00->unk_030.x * 0.8f, arg0->unk_00->unk_030.x * 0.8f,
                      arg0->unk_00->unk_030.x * 0.8f);
    } else if (arg0->unk_06 == 0x10) {
        func_84B00404(arg0->unk_00);
        arg0->unk_06 = -1;
    }
}

void func_84B0CACC(unk_D_84B25AC0_0A0* arg0) {
    f32 temp_fv0;
    f32 temp_fv1;

    if (arg0->unk_06 < 0x10) {
        temp_fv0 = arg0->unk_00->unk_030.x * 0.9f;
        temp_fv1 = (20.0f - arg0->unk_06) / 5.0f;
        arg0->unk_00->unk_024.x += temp_fv1 * COSS(arg0->unk_08);
        arg0->unk_00->unk_024.y += temp_fv1 * SINS(arg0->unk_08);
        func_8000E88C(&arg0->unk_00->unk_030, temp_fv0, temp_fv0, temp_fv0);
        arg0->unk_06++;
    } else if (arg0->unk_06 == 0x10) {
        func_84B00404(arg0->unk_00);
        arg0->unk_06 = -1;
    }
}

void func_84B0CBCC(unk_D_84B25AC0_0A0* arg0) {
    if (arg0->unk_06 < 0x14) {
        func_8000E88C(&arg0->unk_00->unk_030, arg0->unk_00->unk_030.x - 0.025f, arg0->unk_00->unk_030.x - 0.025f,
                      arg0->unk_00->unk_030.x - 0.025f);
        arg0->unk_0A.a -= 5;
        arg0->unk_00->unk_024.y -= 2.0f;
        arg0->unk_06++;
    } else if (arg0->unk_06 == 0x14) {
        func_84B00404(arg0->unk_00);
        arg0->unk_06 = -1;
    }
}

void func_84B0CC7C(unk_D_84B25AC0_0A0* arg0) {
    switch (arg0->unk_04) {
        case 0:
            func_84B0C7D0(arg0);
            break;

        case 1:
            func_84B0CA34(arg0);
            break;

        case 2:
            func_84B0CACC(arg0);
            break;

        case 3:
            func_84B0CBCC(arg0);
            break;
    }
}

void func_84B0CCFC(unk_D_84B25AC0* arg0) {
    s32 i;
    s32 j;

    arg0->unk_5A1++;
    if (arg0->unk_5A1 < 0x25) {
        if (arg0->unk_5A2 != 0) {
            for (i = 0; i < 10; i++) {
                for (j = 0; j < 8; j++) {
                    if (arg0->unk_0A0[i][j].unk_06 >= 0) {
                        func_84B0CC7C(&arg0->unk_0A0[i][j]);
                    }
                }
            }
        } else {
            for (i = 0; i < 10; i++) {
                if (arg0->unk_000[i].unk_04 >= 0) {
                    func_84B0C278(&arg0->unk_000[i]);
                }
            }
        }
    } else {
        arg0->unk_5A1 = 0;
        arg0->unk_5A0 = 0;
    }
}

void func_84B0CDEC(unk_D_84B25AC0* arg0) {
    s16 i;
    s16 var_s2;

    arg0->unk_5A1++;
    if (arg0->unk_5A1 > 0) {
        arg0->unk_5A8->unk_000.unk_01 |= 1;
        arg0->unk_5A8->unk_024.z -= 8.0f;
        if (arg0->unk_5A3 != 0) {
            arg0->unk_5A8->unk_01E.z += 0x400;
            arg0->unk_5A8->unk_024.x = (COSS(arg0->unk_5A8->unk_01E.z + 0x6000) * 70.71f) + 82.0f;
            arg0->unk_5A8->unk_024.y = (SINS(arg0->unk_5A8->unk_01E.z + 0x6000) * 70.71f) + -2.0f;
        } else {
            arg0->unk_5A8->unk_01E.z -= 0x400;
            arg0->unk_5A8->unk_024.x = (COSS(arg0->unk_5A8->unk_01E.z + 0x2000) * 70.71f) + -82.0f;
            arg0->unk_5A8->unk_024.y = (SINS(arg0->unk_5A8->unk_01E.z + 0x2000) * 70.71f) + -98.0f;
        }

        if (arg0->unk_5A1 == 0x10) {
            if (arg0->unk_5A2 != 0) {
                var_s2 = 0x2000;
                for (i = 0; i < 5; i++, var_s2 += 0x3000) {
                    func_84B0C45C(&arg0->unk_0A0[i], arg0->unk_5B8, arg0->unk_5A8->unk_024.x, arg0->unk_5A8->unk_024.y,
                                  var_s2);
                    func_84B0CC7C(&arg0->unk_0A0[i]);
                }

                var_s2 = 0x6000;
                for (i = 5; i < 10; i++, var_s2 -= 0x3000) {
                    func_84B0C45C(&arg0->unk_0A0[i], arg0->unk_5B8, arg0->unk_5A8->unk_024.x, arg0->unk_5A8->unk_024.y,
                                  var_s2);
                    func_84B0CC7C(&arg0->unk_0A0[i]);
                }

                arg0->unk_5A1 = 0;
                arg0->unk_5A0 = 1;
            } else {
                var_s2 = 0x3000;
                for (i = 0; i < 5; i++, var_s2 += 0x2800) {
                    func_84B0C174(&arg0->unk_000[i], arg0->unk_5B4, arg0->unk_5A8->unk_024.x, arg0->unk_5A8->unk_024.y,
                                  var_s2);
                    func_84B0C278(&arg0->unk_000[i]);
                }

                var_s2 = 0x5000;
                for (i = 5; i < 10; i++, var_s2 -= 0x2800) {
                    func_84B0C174(&arg0->unk_000[i], arg0->unk_5B4, arg0->unk_5A8->unk_024.x, arg0->unk_5A8->unk_024.y,
                                  var_s2);
                    func_84B0C278(&arg0->unk_000[i]);
                }

                arg0->unk_5A1 = 0;
                arg0->unk_5A0 = 1;
            }
        }
    }
}

void func_84B0D194(unk_D_84B25AC0* arg0) {
    s32 i;
    s32 j;

    arg0->unk_5A1++;
    if (arg0->unk_5A1 >= 4) {
        arg0->unk_5A8->unk_024.y += arg0->unk_5A4;
        arg0->unk_5A4 -= 0.5f;
        arg0->unk_5A8->unk_024.x -= 20.0f;
        arg0->unk_5A8->unk_01E.z += 0x400;

        if (arg0->unk_5A1 < 0xE) {
            for (i = 0; i < 4; i++) {
                func_84B0C6B4(&arg0->unk_0A0[arg0->unk_5A1 - 4][0 + i], arg0->unk_5B8, &arg0->unk_5A8->unk_024);
                func_84B0C6B4(&arg0->unk_0A0[arg0->unk_5A1 - 4][4 + i], arg0->unk_5B8, &arg0->unk_5A8->unk_024);
            }
        }

        for (j = 0; j < 10; j++) {
            for (i = 0; i < 8; i++) {
                if (arg0->unk_0A0[j][i].unk_06 >= 0) {
                    func_84B0CC7C(&arg0->unk_0A0[j][i]);
                }
            }
        }

        if (arg0->unk_5A1 == 0x22) {
            func_84B00404(arg0->unk_5A8);
            arg0->unk_5A0 = 0;
        }
    }
}

void func_84B0D31C(unk_D_84B25AC0* arg0) {
    arg0->unk_5A1++;
    if (arg0->unk_5A1 >= 4) {
        arg0->unk_5A8->unk_024.y += arg0->unk_5A4;
        arg0->unk_5A4 -= 1.0f;
        if (arg0->unk_5A2 != 0) {
            arg0->unk_5A8->unk_024.x -= 10.0f;
            arg0->unk_5A8->unk_01E.z += 0x400;
        } else {
            arg0->unk_5A8->unk_01E.z -= 0x400;
        }

        if (arg0->unk_5A1 == 0x20) {
            func_84B00404(arg0->unk_5A8);
            arg0->unk_5A0 = 0;
        }
    }
}

void func_84B0D3E4(unk_D_84B25AC0* arg0) {
    if ((arg0->unk_5A1 < 0x14) && (arg0->unk_5A3 != 0) && (arg0->unk_5A1 < 7)) {
        arg0->unk_5A8->unk_024.x += 40.0f;
    }

    arg0->unk_5A1++;
    if (arg0->unk_5A1 == 0x2C) {
        arg0->unk_5A1 = 0;
        arg0->unk_5A0 = 0;
    }
}

void func_84B0D450(unk_D_84B25AC0* arg0) {
    s32 tmp;

    if (arg0->unk_5A3 != 0) {
        if (arg0->unk_5A1 >= 0) {
            arg0->unk_5A8->unk_024.x += 40.0f;
        }
        tmp = arg0->unk_5A1;
    } else {
        tmp = arg0->unk_5A1;
    }

    arg0->unk_5A1++;
    if (arg0->unk_5A1 == 0xB) {
        arg0->unk_5A1 = 0;
        arg0->unk_5A0 = 0;
    }
}

void func_84B0D4B4(unk_D_84B25AC0* arg0) {
    switch (arg0->unk_5A0) {
        case 1:
            func_84B0CCFC(arg0);
            break;

        case 2:
            func_84B0CDEC(arg0);
            break;

        case 3:
            func_84B0D194(arg0);
            break;

        case 4:
            func_84B0D31C(arg0);
            break;

        case 5:
            func_84B0D3E4(arg0);
            break;

        case 7:
            func_84B0D450(arg0);
            break;
    }
}

void func_84B0D54C(unk_D_84B25AC0* arg0, unk_D_86002F58_004_000* arg1, unk_D_86002F58_004_000* arg2) {
    s32 i;
    s32 j;

    arg0->unk_5A8 = arg1;
    arg0->unk_5AC = arg2;
    func_8001BC34(arg1, 1, 0, arg0->unk_5B0);
    arg0->unk_5A8->unk_000.unk_14 = arg0;

    if (arg0->unk_5A2 == -1) {
        arg0->unk_5A1 = 0;
        arg0->unk_5A0 = 5;
        if (arg0->unk_5A3 != 0) {
            func_8000E88C(&arg0->unk_5A8->unk_024, -280.0f, 0.0f, -289.0f);
        } else {
            func_8000E88C(&arg0->unk_5A8->unk_024, -372.0f, 0.0f, -289.0f);
        }
        return;
    }

    if (arg0->unk_5A2 != 0) {
        arg0->unk_5A1 = 0;
    } else {
        arg0->unk_5A1 = -6;
    }

    arg0->unk_5A0 = 2;
    arg0->unk_5A8->unk_000.unk_01 &= ~1;
    if (arg0->unk_5A3 != 0) {
        func_8000E88C(&arg0->unk_5A8->unk_024, 32.0f, 48.0f, -161.0f);
        arg0->unk_5A8->unk_01E.z = -0x4000;
    } else {
        func_8000E88C(&arg0->unk_5A8->unk_024, -32.0f, -48.0f, -161.0f);
        arg0->unk_5A8->unk_01E.z = 0x4000;
    }

    for (i = 0; i < 10; i++) {
        arg0->unk_000[i].unk_00 = arg2++;
    }

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 8; j++) {
            arg0->unk_0A0[i][j].unk_00 = arg2++;
            arg0->unk_0A0[i][j].unk_06 = -1;
        }
    }
}

void func_84B0D718(unk_D_84B25AC0* arg0) {
    arg0->unk_5A1 = 0;
    if (arg0->unk_5A2 == -1) {
        arg0->unk_5A0 = 7;
    } else if (arg0->unk_5A3 != 0) {
        if (arg0->unk_5A2 != 0) {
            arg0->unk_5A4 = 10.0f;
            arg0->unk_5A0 = 3;
        } else {
            arg0->unk_5A4 = -10.0f;
            arg0->unk_5A0 = 4;
        }
    } else {
        if (arg0->unk_5A2 != 0) {
            arg0->unk_5A4 = 20.0f;
        } else {
            arg0->unk_5A4 = -10.0f;
        }
        arg0->unk_5A0 = 4;
    }
}

void func_84B0D7A8(unk_D_84B25AC0* arg0, s8 arg1, s8 arg2) {
    GraphNode* var_v0;
    MemoryBlock* temp_v0;

    arg0->unk_5A0 = 0;
    arg0->unk_5A1 = 0;
    arg0->unk_5A3 = arg1;
    arg0->unk_5A2 = arg2;

    temp_v0 = func_80002D10(main_pool_get_available(), 0);
    if (arg2 == -1) {
        arg0->unk_5B0 = process_geo_layout(temp_v0, D_84B16CFC);
    } else {
        arg0->unk_5B0 = process_geo_layout(temp_v0, D_84B16CC8);
    }
    arg0->unk_5B4 = process_geo_layout(temp_v0, D_84B16DD8);
    arg0->unk_5B8 = process_geo_layout(temp_v0, D_84B16EB8);
    func_80002D60(temp_v0);
}
