#include "fragment63.h"
#include "src/12D80.h"
#include "src/19840.h"
#include "src/1C720.h"
#include "src/20470.h"
#include "src/4CBC0.h"
#include "src/6BC0.h"
#include "src/F420.h"
#include "src/math_util.h"
#include "src/memmap.h"
#include "src/memory.h"

static s16 D_84B16390[] = { -0x60, -0x20, 0x20, 0x60, -0x60, -0x20, 0x20, 0x60 };
static s16 D_84B163A0[] = { 0x30, 0x30, 0x30, 0x30, -0x30, -0x30, -0x30, -0x30 };
static f32 D_84B163B0[] = { 0.1f, 0.3f, 0.5f, 0.7f, 0.9f, 1.0f, 1.0f, 0.9f, 0.7f, 0.5f, 0.3f, 0.1f };
static Vtx D_84B163E0[] = {
    VTX(-32, 48, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(-32, 16, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, 16, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(32, 48, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, 16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(-32, -16, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, -16, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(32, 16, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, -16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-32, -48, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, -48, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(32, -16, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_84B164A0[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, COMBINED, COMBINED, 0, PRIM_LOD_FRAC, 0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84B163E0, 12, 0),
    gsDPLoadTextureBlock(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, 6, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(0x0F001000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, 6, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsDPLoadTextureBlock(0x0F002000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, 6, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};
static u32 D_84B16588[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_84B163E0, 0x05000000, 0x22010000,
    0x00000000, 0x08000000, func_84B0AC60, D_84B164A0, 0x06000000, 0x01000000, 0x00000000,
};
static Vtx D_84B165C0[] = {
    VTX(-24, 25, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-24, 0, 0, 0, 800, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(24, 0, 0, 1536, 800, 0xFF, 0xFF, 0xFF, 0xFF),   VTX(24, 25, 0, 1536, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-24, 0, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(-24, -25, 0, 0, 800, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(24, -25, 0, 1536, 800, 0xFF, 0xFF, 0xFF, 0xFF), VTX(24, 0, 0, 1536, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_84B16640[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, COMBINED, COMBINED, 0, PRIM_LOD_FRAC, 0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84B165C0, 8, 0),
    gsDPLoadTextureBlock(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 48, 25, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, 6, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(0x0F000960, G_IM_FMT_RGBA, G_IM_SIZ_16b, 48, 25, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, 6, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};
static u32 D_84B166E8[] = {
    0x17000000,    0x00000000, 0x00000000, 0x00000000, D_84B165C0, 0x05000000, 0x1B000000,
    0x00000000,    0x00000000, 0x00050000, 0x05000000, 0x22050000, 0x00000000, 0x08000000,
    func_84B0AD48, D_84B16640, 0x06000000, 0x06000000, 0x01000000, 0x00000000,
};
static Vtx D_84B16738[] = {
    VTX(-16, 16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-16, -16, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(16, -16, 0, 1024, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(16, 16, 0, 1024, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_84B16778[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineMode(G_CC_MODULATEIA, G_CC_PASS2),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84B16738, 4, 0),
    gsDPLoadTextureBlock_4b(0x0F000000, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                            5, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};
static u32 D_84B167E0[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_84B16738, 0x05000000, 0x22050000,
    0x00000000, 0x08000000, func_84B0AE30, D_84B16778, 0x06000000, 0x01000000, 0x00000000,
};
static Vtx D_84B16818[] = {
    VTX(-32, 32, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),       VTX(-32, 0, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, 0, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),   VTX(32, 32, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, 0, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),        VTX(-32, -32, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, -32, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(32, 0, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_84B16898[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, 0, 0,
                       0, COMBINED),
    gsDPSetPrimColor(0, 0, 0, 255, 255, 255),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84B16818, 8, 0),
    gsDPLoadTextureBlock_4b(0x02022640, G_IM_FMT_I, 64, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                            6, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock_4b(0x02022A40, G_IM_FMT_I, 64, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                            6, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsSPEndDisplayList(),
};
static u32 D_84B16948[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_84B16818, 0x05000000, 0x22050000,
    0x00000000, 0x08000000, func_84B0AF48, D_84B16898, 0x06000000, 0x01000000, 0x00000000,
};
static Vtx D_84B16980[] = {
    VTX(-16, 16, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-16, -16, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(16, -16, 0, 1024, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(16, 16, 0, 1024, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};
static Gfx D_84B169C0[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0, 0,
                       COMBINED),
    gsDPSetEnvColor(255, 255, 0, 255),
    gsDPSetPrimColor(0, 0, 255, 255, 255, 255),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_84B16980, 4, 0),
    gsDPLoadTextureBlock(D_2022E40, G_IM_FMT_IA, G_IM_SIZ_8b, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsSPEndDisplayList(),
};
static u32 D_84B16A38[] = {
    0x17000000, 0x00000000, 0x00000000, 0x00000000, D_84B16980, 0x05000000,
    0x22050000, D_84B169C0, 0x25000000, 0x06000000, 0x01000000,
};

s32 func_84B0AC60(s32 arg0, unk_func_80011B94* arg1) {
    unk_D_84B25A90* temp_v0;
    s32 tmp;

    if (arg0 == 5) {
        temp_v0 = (unk_D_84B25A90*)D_8006F09C->unk_000.unk_14;
        tmp = (D_8006F09C->unk_0A6 - temp_v0->unk_04->unk_0A6) % 8;

        gDPPipeSync(gDisplayListHead++);
        gSPSegment(gDisplayListHead++, 0x0F,
                   (u32)Memmap_GetSegmentVaddr(*(s32*)(temp_v0->unk_1C + tmp * 4)) & 0x1FFFFFFF);
        gSPDisplayList(gDisplayListHead++, arg1->unk_00.unk_14);

        func_80015684();
    }
    return 0;
}

s32 func_84B0AD48(s32 arg0, unk_func_80011B94* arg1) {
    unk_D_84B25A90* temp_v0;
    s32 tmp;

    if (arg0 == 5) {
        temp_v0 = (unk_D_84B25A90*)D_8006F09C->unk_000.unk_14;
        tmp = (D_8006F09C->unk_0A6 - temp_v0->unk_04->unk_0A6) % 8;

        gDPPipeSync(gDisplayListHead++);
        gSPSegment(gDisplayListHead++, 0x0F,
                   (u32)Memmap_GetSegmentVaddr(*(s32*)(temp_v0->unk_20 + tmp * 4)) & 0x1FFFFFFF);
        gSPDisplayList(gDisplayListHead++, arg1->unk_00.unk_14);

        func_80015684();
    }
    return 0;
}

s32 func_84B0AE30(s32 arg0, unk_func_80011B94* arg1) {
    unk_D_84B25A90* temp_a3;
    s32 tmp;

    if (arg0 == 5) {
        temp_a3 = (unk_D_84B25A90*)D_8006F09C->unk_000.unk_14;
        tmp = (D_8006F09C->unk_0A6 - temp_a3->unk_04->unk_0A6) - 0x10;

        if (temp_a3->unk_28[tmp] >= 0) {
            gDPPipeSync(gDisplayListHead++);
            gSPSegment(gDisplayListHead++, 0x0F,
                       (u32)Memmap_GetSegmentVaddr(temp_a3->unk_24[temp_a3->unk_28[tmp]]) & 0x1FFFFFFF);
            gSPDisplayList(gDisplayListHead++, arg1->unk_00.unk_14);

            func_80015684();

            temp_a3->unk_28[tmp]++;
            if (temp_a3->unk_28[tmp] == 8) {
                temp_a3->unk_28[tmp] = -1;
            }
        }
    }
    return 0;
}

s32 func_84B0AF48(s32 arg0, unk_func_80011B94* arg1) {
    UNUSED s32 pad[2];
    s16 sp1E;
    f32 temp_fv0;

    if (arg0 == 5) {
        temp_fv0 = D_8006F09C->unk_030.x;
        sp1E = (4.5f - temp_fv0) * 255.0f * 0.25f;
        if (temp_fv0 <= 4.0f) {
            temp_fv0 += 0.5f;
            func_8000E88C(&D_8006F09C->unk_030, temp_fv0, temp_fv0, temp_fv0);

            gDPPipeSync(gDisplayListHead++);
            gDPSetEnvColor(gDisplayListHead++, 0, 0, 255, sp1E);
            gSPDisplayList(gDisplayListHead++, arg1->unk_00.unk_14);

            func_80015684();
        }
    }
    return 0;
}

void func_84B0B054(void) {
}

void func_84B0B05C(unk_D_84B25A90* arg0) {
    s32 i;

    if (arg0->unk_01 == 0) {
        func_8004DF94(0x0110000D, 0, 0);
    }

    arg0->unk_01++;
    if (arg0->unk_01 < 0x10) {
        for (i = 0; i < 4; i++) {
            arg0->unk_04[0 + i].unk_01E.y -= 0x800;
            arg0->unk_04[8 + i].unk_01E.y -= 0x800;
        }

        for (i = 4; i < 8; i++) {
            arg0->unk_04[0 + i].unk_01E.y += 0x800;
            arg0->unk_04[8 + i].unk_01E.y += 0x800;
        }
    } else {
        for (i = 0; i < 8; i++) {
            func_8001BCF0(&arg0->unk_04[i]);
            func_84B00404(&arg0->unk_04[8 + i]);
            func_8001BC34(&arg0->unk_04[i], 0, 0, arg0->unk_08);
            arg0->unk_04[i].unk_01E.y = 0;
            arg0->unk_04[i].unk_000.unk_14 = arg0;
        }

        for (i = 0; i < 8; i++) {
            arg0->unk_28[i] = -1;
        }

        arg0->unk_01 = 0;
        arg0->unk_00 = 2;
    }
}

void func_84B0B228(unk_D_84B25A90* arg0) {
    s16 i;
    s16 var_s3;
    s16 var_a0;
    s16 var_a1;
    s16 var_a2;

    if (osTvType == OS_TV_PAL) {
        var_a0 = 5;
        var_a1 = 0x11;
        var_a2 = 0x22;
    } else {
        var_a0 = 6;
        var_a1 = 0x14;
        var_a2 = 0x28;
    }

    var_s3 = arg0->unk_01 / var_a0;
    arg0->unk_01++;
    if (D_800AE540.unk_0003 - 1 < var_s3) {
        var_s3 = D_800AE540.unk_0003 - 1;
    }

    if (var_s3 < D_800AE540.unk_0003 - 1) {
        if ((arg0->unk_01 % var_a0) == 0) {
            func_8004DF94(0x0110000E, var_s3 + 1, 0);
            func_8001BC34(&arg0->unk_04[8 + var_s3], 1, 0, arg0->unk_0C);
            func_8000E88C(&arg0->unk_04[8 + var_s3].unk_024, D_84B16390[var_s3], D_84B163A0[var_s3], -289.0f);
            arg0->unk_04[8 + var_s3].unk_000.unk_14 = arg0;
            func_8001BC34(&arg0->unk_04[16 + var_s3], 0, 0, arg0->unk_10);
            func_8000E88C(&arg0->unk_04[16 + var_s3].unk_024, D_84B16390[var_s3], D_84B163A0[var_s3] + 5, -289.0f);
            func_8000E88C(&arg0->unk_04[16 + var_s3].unk_030, 2.5f, 2.5f, 2.5f);
            arg0->unk_04[16 + var_s3].unk_000.unk_14 = arg0;
            arg0->unk_28[var_s3] = 0;
        }
    } else if (var_s3 == D_800AE540.unk_0003 - 1) {
        if (var_a1 == (arg0->unk_01 - (var_s3 * var_a0))) {
            func_8004DF94(0x0110000F, 0, 0);
            func_8001BC34(&arg0->unk_04[8 + var_s3], 1, 0, arg0->unk_0C);
            func_8000E88C(&arg0->unk_04[8 + var_s3].unk_024, D_84B16390[var_s3], D_84B163A0[var_s3], -289.0f);
            arg0->unk_04[8 + var_s3].unk_000.unk_14 = arg0;
            func_8001BC34(&arg0->unk_04[16 + var_s3], 0, 0, arg0->unk_10);
            func_8000E88C(&arg0->unk_04[16 + var_s3].unk_024, D_84B16390[var_s3], D_84B163A0[var_s3] + 5, -289.0f);
            func_8000E88C(&arg0->unk_04[16 + var_s3].unk_030, 6.0f, 6.0f, 6.0f);
            arg0->unk_04[16 + var_s3].unk_000.unk_14 = arg0;
            arg0->unk_28[var_s3] = 0;
            func_8001BC34(&arg0->unk_04[24], 0, 0, arg0->unk_14);
            func_8000E88C(&arg0->unk_04[24].unk_024, D_84B16390[var_s3], D_84B163A0[var_s3] + 5, -289.0f);
            arg0->unk_04[24].unk_000.unk_14 = arg0;

            for (i = 0; i < D_800AE540.unk_0003 - 1; i++) {
                arg0->unk_04[8 + i].unk_018 = 0;
            }
        } else {
            if (var_a2 == (arg0->unk_01 - (var_s3 * var_a0))) {
                for (i = 16; i < 25; i++) {
                    func_84B00404(&arg0->unk_04[i]);
                }

                arg0->unk_04[8 + var_s3].unk_018 = 0;
                arg0->unk_01 = 0;
                arg0->unk_00 = 3;
            }
        }
    }
}

void func_84B0B6EC(unk_D_84B25A90* arg0, unk_D_86002F58_004_000* arg1, s16 arg2) {
    u16 sp26;
    f32 temp_fv0;

    if (arg2 < D_800AE540.unk_0003) {
        if (arg1->unk_000.unk_0C == NULL) {
            func_8001BC34(arg1, 2, 0, arg0->unk_18);
        }

        sp26 = MathUtil_Random16();
        temp_fv0 = (MathUtil_Random_ZeroOne() * 20.0f) + 15.0f;

        arg1->unk_000.unk_14 = 0;

        arg1->unk_024.x = D_84B16390[arg2] + (COSS(sp26) * temp_fv0);
        arg1->unk_024.y = (D_84B163A0[arg2] + 5) + (SINS(sp26) * temp_fv0);
        arg1->unk_024.z = -289.0f;
    }
}

void func_84B0B7F4(unk_D_84B25A90* arg0) {
    s32 i;
    s32 temp_s0 = arg0->unk_01 % 4;

    func_84B0B6EC(arg0, &arg0->unk_04[16 + arg0->unk_01], temp_s0);
    func_84B0B6EC(arg0, &arg0->unk_04[28 + arg0->unk_01], 7 - temp_s0);

    for (i = 16; i < 41; i++) {
        if ((s32)arg0->unk_18 == (s32)arg0->unk_04[i].unk_000.unk_0C) {
            s32 idx = arg0->unk_04[i].unk_000.unk_14;

            func_8000E88C(&arg0->unk_04[i].unk_030, D_84B163B0[idx], D_84B163B0[idx], D_84B163B0[idx]);
            arg0->unk_04[i].unk_000.unk_14 = (idx + 1) % 12;
        }
    }

    arg0->unk_01 = (arg0->unk_01 + 1) % 12;
}

void func_84B0B984(unk_D_84B25A90* arg0) {
    static s16 D_84B16A64[] = { 0x300, 0x150, -0x150, -0x300, -0x300, -0x150, 0x150, 0x300 };
    static f32 D_84B16A74[] = { -3.0f, -2.0f, 2.0f, 3.0f, -3.0f, -2.0f, 2.0f, 3.0f };

    s32 i;

    arg0->unk_01++;
    if (arg0->unk_01 < 0x10) {
        for (i = 0; i < 4; i++) {
            arg0->unk_04[0 + i].unk_01E.x += 0x300;
            arg0->unk_04[8 + i].unk_01E.x += 0x300;
            arg0->unk_04[4 + i].unk_01E.x -= 0x300;
            arg0->unk_04[12 + i].unk_01E.x -= 0x300;

            arg0->unk_04[0 + i].unk_024.y += 2.0f * arg0->unk_01 * 0.5f;
            arg0->unk_04[8 + i].unk_024.y += 2.0f * arg0->unk_01 * 0.5f;
            arg0->unk_04[4 + i].unk_024.y -= 2.0f * arg0->unk_01 * 0.5f;
            arg0->unk_04[12 + i].unk_024.y -= 2.0f * arg0->unk_01 * 0.5f;
        }

        for (i = 0; i < 8; i++) {
            arg0->unk_04[0 + i].unk_01E.z += D_84B16A64[i];
            arg0->unk_04[8 + i].unk_01E.z += D_84B16A64[i];

            arg0->unk_04[0 + i].unk_024.x += (arg0->unk_01 * D_84B16A74[i] * 0.5f);
            arg0->unk_04[8 + i].unk_024.x += (arg0->unk_01 * D_84B16A74[i] * 0.5f);
        }
    } else {
        arg0->unk_01 = 0;
        arg0->unk_00 = 0;
    }
}

void func_84B0BBEC(unk_D_84B25A90* arg0) {
    switch (arg0->unk_00) {
        case 1:
            func_84B0B05C(arg0);
            break;

        case 2:
            func_84B0B228(arg0);
            break;

        case 3:
            func_84B0B7F4(arg0);
            break;

        case 4:
            func_84B0B984(arg0);
            break;
    }
}

void func_84B0BC6C(unk_D_84B25A90* arg0, unk_D_86002F58_004_000* arg1) {
    s32 i;

    arg0->unk_04 = arg1;
    arg0->unk_01 = 0;
    arg0->unk_00 = 1;

    for (i = 0; i < 8; i++) {
        func_8001BC34(&arg0->unk_04[8 + i], 0, 0, arg0->unk_08);
        arg0->unk_04[8 + i].unk_01E.y = -0x8000;
        arg0->unk_04[8 + i].unk_000.unk_14 = arg0;
    }

    func_8000E88C(&arg0->unk_04[8].unk_024, -96.0f, 48.0f, -289.0f);
    func_8000E88C(&arg0->unk_04[9].unk_024, -32.0f, 48.0f, -289.0f);
    func_8000E88C(&arg0->unk_04[10].unk_024, 32.0f, 48.0f, -289.0f);
    func_8000E88C(&arg0->unk_04[11].unk_024, 96.0f, 48.0f, -289.0f);
    func_8000E88C(&arg0->unk_04[12].unk_024, -96.0f, -48.0f, -289.0f);
    func_8000E88C(&arg0->unk_04[13].unk_024, -32.0f, -48.0f, -289.0f);
    func_8000E88C(&arg0->unk_04[14].unk_024, 32.0f, -48.0f, -289.0f);
    func_8000E88C(&arg0->unk_04[15].unk_024, 96.0f, -48.0f, -289.0f);
}

void func_84B0BDCC(unk_D_84B25A90* arg0) {
    s32 i;

    for (i = 16; i < 41; i++) {
        func_84B00404(&arg0->unk_04[i]);
    }

    arg0->unk_01 = 0;
    arg0->unk_00 = 4;
}

void func_84B0BE28(unk_D_84B25A90* arg0) {
    MemoryBlock* temp_v0;

    arg0->unk_00 = 0;
    arg0->unk_01 = 0;
    arg0->unk_20 = Memmap_GetSegmentVaddr(D_2021620);
    arg0->unk_1C = Memmap_GetSegmentVaddr(D_2018000);
    arg0->unk_24 = Memmap_GetSegmentVaddr(D_2023240);

    temp_v0 = func_80002D10(main_pool_get_available(), 0);

    arg0->unk_08 = process_geo_layout(temp_v0, D_84B16588);
    arg0->unk_0C = process_geo_layout(temp_v0, D_84B166E8);
    arg0->unk_10 = process_geo_layout(temp_v0, D_84B167E0);
    arg0->unk_14 = process_geo_layout(temp_v0, D_84B16948);
    arg0->unk_18 = process_geo_layout(temp_v0, D_84B16A38);

    func_80002D60(temp_v0);
}
