#include "battle_prep.h"
#include "src/geo_render.h"
#include "src/model_renderer.h"
#include "src/graphics_textures.h"
#include "src/ui_graphics.h"
#include "src/save_data.h"
#include "src/audio_sfx.h"
#include "src/matrix.h"
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
    0x00000000, 0x08000000, BattlePrepStarBurst_DrawStarIcon, D_84B16BA0, 0x06000000, 0x01000000,
};
static u32 D_84B16CFC[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_84B16AA0, 0x05000000, 0x22050000,
    0x00000000, 0x08000000, BattlePrepStarBurst_DrawTrailIcon, D_84B16BA0, 0x06000000, 0x01000000,
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
    0x00000000, 0x08000000, BattlePrepStarBurst_DrawSparkParticle, D_84B16D70, 0x06000000, 0x01000000, 0x00000000,
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
    0x00000000, 0x08000000, BattlePrepStarBurst_DrawRainbowParticle, D_84B16E50, 0x06000000, 0x01000000,
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

s32 BattlePrepStarBurst_DrawStarIcon(s32 arg0, unk_func_80011B94* arg1) {
    unk_D_84B25AC0* temp_a0;
    u8* var_a0;

    if (arg0 == 5) {
        temp_a0 = (unk_D_84B25AC0*)D_8006F09C->node.callbackArg;
        if (temp_a0->unk_5A2 != 0) {
            var_a0 = D_3018800;
        } else {
            var_a0 = D_301C800;
        }

        gDPPipeSync(gDisplayListHead++);
        gSPSegment(gDisplayListHead++, 0x0F, (u32)Memmap_GetSegmentVaddr(var_a0) & 0x1FFFFFFF);
        gSPDisplayList(gDisplayListHead++, arg1->display_node_header.callbackArg);

        GeoRender_ApplyMaterialState();
    }
    return 0;
}

s32 BattlePrepStarBurst_DrawTrailIcon(s32 arg0, unk_func_80011B94* arg1) {
    UNUSED s32 pad;

    if (arg0 == 5) {
        gDPPipeSync(gDisplayListHead++);
        gSPSegment(gDisplayListHead++, 0x0F, (u32)Memmap_GetSegmentVaddr(D_3020800) & 0x1FFFFFFF);
        gSPDisplayList(gDisplayListHead++, arg1->display_node_header.callbackArg);

        GeoRender_ApplyMaterialState();
    }
    return 0;
}

s32 BattlePrepStarBurst_DrawSparkParticle(s32 arg0, unk_func_80011B94* arg1) {
    unk_D_84B25AC0_000* temp_a0;

    if (arg0 == 5) {
        temp_a0 = (unk_D_84B25AC0_000*)D_8006F09C->node.callbackArg;

        gDPPipeSync(gDisplayListHead++);
        gSPSegment(gDisplayListHead++, 0x0F, (u32)temp_a0->unk_0C & 0x1FFFFFFF);
        gDPSetEnvColor(gDisplayListHead++, temp_a0->unk_08.r, temp_a0->unk_08.g, temp_a0->unk_08.b, 255);
        gSPDisplayList(gDisplayListHead++, arg1->display_node_header.callbackArg);

        GeoRender_ApplyMaterialState();
    }
    return 0;
}

void BattlePrepStarBurst_InitSparkSlot(unk_D_84B25AC0_000* arg0, unk_D_86002F34* arg1, s16 arg2, s16 arg3, s16 arg4) {
    arg0->unk_04 = 0;
    arg0->unk_06 = arg4;
    arg0->unk_08.r = 0x50;
    arg0->unk_08.g = 0x64;
    Model_InitDisplayObject(arg0->unk_00, 0, 0, arg1);
    Vec3f_SetComponentsDuplicate(&arg0->unk_00->scale, 2.0f, 2.0f, 2.0f);
    arg0->unk_00->node.callbackArg = arg0;
    arg0->unk_00->position.x = (COSS(arg4) * 52.0f) + arg2;
    arg0->unk_00->position.y = (SINS(arg4) * 26.0f) + arg3;
    arg0->unk_00->position.z = -289.0f;
}

void BattlePrepStarBurst_UpdateSparkSlot(unk_D_84B25AC0_000* arg0) {
    s16 temp_v0;
    DisplayObject* temp_v1;
    DisplayObject* temp_v1_2;

    if (arg0->unk_04 < 0x10) {
        arg0->unk_0C = Memmap_GetSegmentVaddr(((s32*)Memmap_GetSegmentVaddr(D_2023240))[(arg0->unk_04 / 2)]);
        arg0->unk_08.b = ((arg0->unk_04 * -0x5A) / 16) + 0x82;
        arg0->unk_00->position.x += 2.0f * COSS(arg0->unk_06);
        arg0->unk_00->position.y += 2.0f * SINS(arg0->unk_06);
        arg0->unk_04++;
    } else if (arg0->unk_04 == 0x10) {
        BattlePrep_ResetDisplayObject(arg0->unk_00);
        arg0->unk_04++;
    }
}

s32 BattlePrepStarBurst_DrawRainbowParticle(s32 arg0, unk_func_80011B94* arg1) {
    unk_D_84B25AC0_0A0* temp_v1;

    if (arg0 == 5) {
        temp_v1 = (unk_D_84B25AC0_0A0*)D_8006F09C->node.callbackArg;

        gDPPipeSync(gDisplayListHead++);
        gDPSetEnvColor(gDisplayListHead++, temp_v1->unk_0A.r, temp_v1->unk_0A.g, temp_v1->unk_0A.b, temp_v1->unk_0A.a);
        gSPDisplayList(gDisplayListHead++, arg1->display_node_header.callbackArg);

        GeoRender_ApplyMaterialState();
    }
    return 0;
}

void BattlePrepStarBurst_InitRainbowParticle(unk_D_84B25AC0_0A0* arg0, unk_D_86002F34* arg1, s16 arg2, s16 arg3, s16 arg4) {
    arg0->unk_06 = 0;
    arg0->unk_04 = 0;
    arg0->unk_08 = arg4;
    Model_InitDisplayObject(arg0->unk_00, 2, 0, arg1);
    arg0->unk_00->node.callbackArg = arg0;
    arg0->unk_00->position.x = (COSS(arg4) * 60.0f) + arg2;
    arg0->unk_00->position.y = (SINS(arg4) * 30.0f) + arg3;
    arg0->unk_00->position.z = -289.0f;
}

void BattlePrepStarBurst_SpawnTrailCopy(unk_D_84B25AC0_0A0* arg0, unk_D_84B25AC0_0A0* arg1) {
    arg0->unk_06 = 0;
    arg0->unk_04 = 1;
    arg0->unk_0A = arg1->unk_0A;
    Model_InitDisplayObject(arg0->unk_00, 1, 0, &arg1->unk_00->node.children->node);
    arg0->unk_00->node.callbackArg = arg0;
    arg0->unk_00->position = arg1->unk_00->position;
    arg0->unk_00->scale = arg1->unk_00->scale;
}

void BattlePrepStarBurst_SpawnFlashCopy(unk_D_84B25AC0_0A0* arg0, unk_D_84B25AC0_0A0* arg1, s16 arg2) {
    arg0->unk_06 = 0;
    arg0->unk_04 = 2;
    arg0->unk_08 = arg1->unk_08 + arg2;

    Color_SetRGBA(&arg0->unk_0A, 0xFF, 0xFF, 0xFF, 0xFF);
    Model_InitDisplayObject(arg0->unk_00, 1, 0, &arg1->unk_00->node.children->node);
    arg0->unk_00->node.callbackArg = arg0;
    arg0->unk_00->position = arg1->unk_00->position;
    Vec3f_SetComponentsDuplicate(&arg0->unk_00->scale, 0.5f, 0.5f, 0.5f);
}

void BattlePrepStarBurst_SpawnScatterParticle(unk_D_84B25AC0_0A0* arg0, unk_D_86002F34* arg1, Vec3f* arg2) {
    arg0->unk_06 = 0;
    arg0->unk_04 = 3;
    Color_SetRGBA(&arg0->unk_0A, 0xFF, 0xFF, 0xC8, 0xFF);
    arg0->unk_0A.b = (MathUtil_Random16() % 200) + 0x32;
    Model_InitDisplayObject(arg0->unk_00, 2, 0, arg1);
    Vec3f_SetComponentsDuplicate(&arg0->unk_00->scale, 0.6f, 0.6f, 0.6f);
    arg0->unk_00->node.callbackArg = arg0;
    arg0->unk_00->position.x = ((MathUtil_Random_ZeroOne() - 0.5f) * 50.0f) + arg2->x;
    arg0->unk_00->position.y = ((MathUtil_Random_ZeroOne() - 0.5f) * 40.0f) + arg2->y;
    arg0->unk_00->position.z = arg2->z;
}

void BattlePrepStarBurst_UpdateRainbowGradientStep(unk_D_84B25AC0_0A0* arg0) {
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

        arg0->unk_00->position.x += 3.0f * COSS(arg0->unk_08);
        arg0->unk_00->position.y += (3.0f * SINS(arg0->unk_08)) - (arg0->unk_06 * 0.0625f);
        Vec3f_SetComponentsDuplicate(&arg0->unk_00->scale, temp_fv0, temp_fv0, temp_fv0);
        if (!(arg0->unk_06 & 3)) {
            BattlePrepStarBurst_SpawnTrailCopy(&arg0[arg0->unk_06 / 4 + 1], arg0);
        }
        arg0->unk_06++;
    } else if (arg0->unk_06 == 0x10) {
        BattlePrepStarBurst_SpawnFlashCopy(&arg0[5], &arg0[0], -0x6500);
        BattlePrepStarBurst_SpawnFlashCopy(&arg0[6], &arg0[0], 0);
        BattlePrepStarBurst_SpawnFlashCopy(&arg0[7], &arg0[0], 0x6500);
        BattlePrep_ResetDisplayObject(arg0->unk_00);
        arg0->unk_06 = -1;
    }
}

void BattlePrepStarBurst_UpdateTrailFadeStep(unk_D_84B25AC0_0A0* arg0) {
    arg0->unk_06++;
    if ((arg0->unk_06 >= 8) && (arg0->unk_06 < 0x10)) {
        Vec3f_SetComponentsDuplicate(&arg0->unk_00->scale, arg0->unk_00->scale.x * 0.8f, arg0->unk_00->scale.x * 0.8f,
                      arg0->unk_00->scale.x * 0.8f);
    } else if (arg0->unk_06 == 0x10) {
        BattlePrep_ResetDisplayObject(arg0->unk_00);
        arg0->unk_06 = -1;
    }
}

void BattlePrepStarBurst_UpdateFlashFadeStep(unk_D_84B25AC0_0A0* arg0) {
    f32 temp_fv0;
    f32 temp_fv1;

    if (arg0->unk_06 < 0x10) {
        temp_fv0 = arg0->unk_00->scale.x * 0.9f;
        temp_fv1 = (20.0f - arg0->unk_06) / 5.0f;
        arg0->unk_00->position.x += temp_fv1 * COSS(arg0->unk_08);
        arg0->unk_00->position.y += temp_fv1 * SINS(arg0->unk_08);
        Vec3f_SetComponentsDuplicate(&arg0->unk_00->scale, temp_fv0, temp_fv0, temp_fv0);
        arg0->unk_06++;
    } else if (arg0->unk_06 == 0x10) {
        BattlePrep_ResetDisplayObject(arg0->unk_00);
        arg0->unk_06 = -1;
    }
}

void BattlePrepStarBurst_UpdateScatterFallStep(unk_D_84B25AC0_0A0* arg0) {
    if (arg0->unk_06 < 0x14) {
        Vec3f_SetComponentsDuplicate(&arg0->unk_00->scale, arg0->unk_00->scale.x - 0.025f, arg0->unk_00->scale.x - 0.025f,
                      arg0->unk_00->scale.x - 0.025f);
        arg0->unk_0A.a -= 5;
        arg0->unk_00->position.y -= 2.0f;
        arg0->unk_06++;
    } else if (arg0->unk_06 == 0x14) {
        BattlePrep_ResetDisplayObject(arg0->unk_00);
        arg0->unk_06 = -1;
    }
}

void BattlePrepStarBurst_UpdateRainbowParticle(unk_D_84B25AC0_0A0* arg0) {
    switch (arg0->unk_04) {
        case 0:
            BattlePrepStarBurst_UpdateRainbowGradientStep(arg0);
            break;

        case 1:
            BattlePrepStarBurst_UpdateTrailFadeStep(arg0);
            break;

        case 2:
            BattlePrepStarBurst_UpdateFlashFadeStep(arg0);
            break;

        case 3:
            BattlePrepStarBurst_UpdateScatterFallStep(arg0);
            break;
    }
}

void BattlePrepStarBurst_UpdateBurstEffect(unk_D_84B25AC0* arg0) {
    s32 i;
    s32 j;

    arg0->unk_5A1++;
    if (arg0->unk_5A1 < 0x25) {
        if (arg0->unk_5A2 != 0) {
            for (i = 0; i < 10; i++) {
                for (j = 0; j < 8; j++) {
                    if (arg0->unk_0A0[i][j].unk_06 >= 0) {
                        BattlePrepStarBurst_UpdateRainbowParticle(&arg0->unk_0A0[i][j]);
                    }
                }
            }
        } else {
            for (i = 0; i < 10; i++) {
                if (arg0->unk_000[i].unk_04 >= 0) {
                    BattlePrepStarBurst_UpdateSparkSlot(&arg0->unk_000[i]);
                }
            }
        }
    } else {
        arg0->unk_5A1 = 0;
        arg0->unk_5A0 = 0;
    }
}

void BattlePrepStarBurst_UpdateFlightArc(unk_D_84B25AC0* arg0) {
    s16 i;
    s16 var_s2;

    arg0->unk_5A1++;
    if (arg0->unk_5A1 > 0) {
        arg0->unk_5A8->node.flags |= 1;
        arg0->unk_5A8->position.z -= 8.0f;
        if (arg0->unk_5A3 != 0) {
            arg0->unk_5A8->rotation.z += 0x400;
            arg0->unk_5A8->position.x = (COSS(arg0->unk_5A8->rotation.z + 0x6000) * 70.71f) + 82.0f;
            arg0->unk_5A8->position.y = (SINS(arg0->unk_5A8->rotation.z + 0x6000) * 70.71f) + -2.0f;
        } else {
            arg0->unk_5A8->rotation.z -= 0x400;
            arg0->unk_5A8->position.x = (COSS(arg0->unk_5A8->rotation.z + 0x2000) * 70.71f) + -82.0f;
            arg0->unk_5A8->position.y = (SINS(arg0->unk_5A8->rotation.z + 0x2000) * 70.71f) + -98.0f;
        }

        if (arg0->unk_5A1 == 0x10) {
            if (arg0->unk_5A2 != 0) {
                var_s2 = 0x2000;
                for (i = 0; i < 5; i++, var_s2 += 0x3000) {
                    BattlePrepStarBurst_InitRainbowParticle(&arg0->unk_0A0[i], arg0->unk_5B8, arg0->unk_5A8->position.x, arg0->unk_5A8->position.y,
                                  var_s2);
                    BattlePrepStarBurst_UpdateRainbowParticle(&arg0->unk_0A0[i]);
                }

                var_s2 = 0x6000;
                for (i = 5; i < 10; i++, var_s2 -= 0x3000) {
                    BattlePrepStarBurst_InitRainbowParticle(&arg0->unk_0A0[i], arg0->unk_5B8, arg0->unk_5A8->position.x, arg0->unk_5A8->position.y,
                                  var_s2);
                    BattlePrepStarBurst_UpdateRainbowParticle(&arg0->unk_0A0[i]);
                }

                arg0->unk_5A1 = 0;
                arg0->unk_5A0 = 1;
            } else {
                var_s2 = 0x3000;
                for (i = 0; i < 5; i++, var_s2 += 0x2800) {
                    BattlePrepStarBurst_InitSparkSlot(&arg0->unk_000[i], arg0->unk_5B4, arg0->unk_5A8->position.x, arg0->unk_5A8->position.y,
                                  var_s2);
                    BattlePrepStarBurst_UpdateSparkSlot(&arg0->unk_000[i]);
                }

                var_s2 = 0x5000;
                for (i = 5; i < 10; i++, var_s2 -= 0x2800) {
                    BattlePrepStarBurst_InitSparkSlot(&arg0->unk_000[i], arg0->unk_5B4, arg0->unk_5A8->position.x, arg0->unk_5A8->position.y,
                                  var_s2);
                    BattlePrepStarBurst_UpdateSparkSlot(&arg0->unk_000[i]);
                }

                arg0->unk_5A1 = 0;
                arg0->unk_5A0 = 1;
            }
        }
    }
}

void BattlePrepStarBurst_UpdateRainbowAftermath(unk_D_84B25AC0* arg0) {
    s32 i;
    s32 j;

    arg0->unk_5A1++;
    if (arg0->unk_5A1 >= 4) {
        arg0->unk_5A8->position.y += arg0->unk_5A4;
        arg0->unk_5A4 -= 0.5f;
        arg0->unk_5A8->position.x -= 20.0f;
        arg0->unk_5A8->rotation.z += 0x400;

        if (arg0->unk_5A1 < 0xE) {
            for (i = 0; i < 4; i++) {
                BattlePrepStarBurst_SpawnScatterParticle(&arg0->unk_0A0[arg0->unk_5A1 - 4][0 + i], arg0->unk_5B8, &arg0->unk_5A8->position);
                BattlePrepStarBurst_SpawnScatterParticle(&arg0->unk_0A0[arg0->unk_5A1 - 4][4 + i], arg0->unk_5B8, &arg0->unk_5A8->position);
            }
        }

        for (j = 0; j < 10; j++) {
            for (i = 0; i < 8; i++) {
                if (arg0->unk_0A0[j][i].unk_06 >= 0) {
                    BattlePrepStarBurst_UpdateRainbowParticle(&arg0->unk_0A0[j][i]);
                }
            }
        }

        if (arg0->unk_5A1 == 0x22) {
            BattlePrep_ResetDisplayObject(arg0->unk_5A8);
            arg0->unk_5A0 = 0;
        }
    }
}

void BattlePrepStarBurst_UpdateSparkAftermath(unk_D_84B25AC0* arg0) {
    arg0->unk_5A1++;
    if (arg0->unk_5A1 >= 4) {
        arg0->unk_5A8->position.y += arg0->unk_5A4;
        arg0->unk_5A4 -= 1.0f;
        if (arg0->unk_5A2 != 0) {
            arg0->unk_5A8->position.x -= 10.0f;
            arg0->unk_5A8->rotation.z += 0x400;
        } else {
            arg0->unk_5A8->rotation.z -= 0x400;
        }

        if (arg0->unk_5A1 == 0x20) {
            BattlePrep_ResetDisplayObject(arg0->unk_5A8);
            arg0->unk_5A0 = 0;
        }
    }
}

void BattlePrepStarBurst_UpdateExitSlide(unk_D_84B25AC0* arg0) {
    if ((arg0->unk_5A1 < 0x14) && (arg0->unk_5A3 != 0) && (arg0->unk_5A1 < 7)) {
        arg0->unk_5A8->position.x += 40.0f;
    }

    arg0->unk_5A1++;
    if (arg0->unk_5A1 == 0x2C) {
        arg0->unk_5A1 = 0;
        arg0->unk_5A0 = 0;
    }
}

void BattlePrepStarBurst_UpdateFirstClearExit(unk_D_84B25AC0* arg0) {
    s32 tmp;

    if (arg0->unk_5A3 != 0) {
        if (arg0->unk_5A1 >= 0) {
            arg0->unk_5A8->position.x += 40.0f;
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

void BattlePrepStarBurst_Update(unk_D_84B25AC0* arg0) {
    switch (arg0->unk_5A0) {
        case 1:
            BattlePrepStarBurst_UpdateBurstEffect(arg0);
            break;

        case 2:
            BattlePrepStarBurst_UpdateFlightArc(arg0);
            break;

        case 3:
            BattlePrepStarBurst_UpdateRainbowAftermath(arg0);
            break;

        case 4:
            BattlePrepStarBurst_UpdateSparkAftermath(arg0);
            break;

        case 5:
            BattlePrepStarBurst_UpdateExitSlide(arg0);
            break;

        case 7:
            BattlePrepStarBurst_UpdateFirstClearExit(arg0);
            break;
    }
}

void BattlePrepStarBurst_Launch(unk_D_84B25AC0* arg0, DisplayObject* arg1, DisplayObject* arg2) {
    s32 i;
    s32 j;

    arg0->unk_5A8 = arg1;
    arg0->unk_5AC = arg2;
    Model_InitDisplayObject(arg1, 1, 0, arg0->unk_5B0);
    arg0->unk_5A8->node.callbackArg = arg0;

    if (arg0->unk_5A2 == -1) {
        arg0->unk_5A1 = 0;
        arg0->unk_5A0 = 5;
        if (arg0->unk_5A3 != 0) {
            Vec3f_SetComponentsDuplicate(&arg0->unk_5A8->position, -280.0f, 0.0f, -289.0f);
        } else {
            Vec3f_SetComponentsDuplicate(&arg0->unk_5A8->position, -372.0f, 0.0f, -289.0f);
        }
        return;
    }

    if (arg0->unk_5A2 != 0) {
        arg0->unk_5A1 = 0;
    } else {
        arg0->unk_5A1 = -6;
    }

    arg0->unk_5A0 = 2;
    arg0->unk_5A8->node.flags &= ~1;
    if (arg0->unk_5A3 != 0) {
        Vec3f_SetComponentsDuplicate(&arg0->unk_5A8->position, 32.0f, 48.0f, -161.0f);
        arg0->unk_5A8->rotation.z = -0x4000;
    } else {
        Vec3f_SetComponentsDuplicate(&arg0->unk_5A8->position, -32.0f, -48.0f, -161.0f);
        arg0->unk_5A8->rotation.z = 0x4000;
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

void BattlePrepStarBurst_StartExit(unk_D_84B25AC0* arg0) {
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

void BattlePrepStarBurst_Init(unk_D_84B25AC0* arg0, s8 arg1, s8 arg2) {
    GraphNode* var_v0;
    MemoryBlock* temp_v0;

    arg0->unk_5A0 = 0;
    arg0->unk_5A1 = 0;
    arg0->unk_5A3 = arg1;
    arg0->unk_5A2 = arg2;

    temp_v0 = MainPool_AllocState(main_pool_get_available(), 0);
    if (arg2 == -1) {
        arg0->unk_5B0 = process_geo_layout(temp_v0, D_84B16CFC);
    } else {
        arg0->unk_5B0 = process_geo_layout(temp_v0, D_84B16CC8);
    }
    arg0->unk_5B4 = process_geo_layout(temp_v0, D_84B16DD8);
    arg0->unk_5B8 = process_geo_layout(temp_v0, D_84B16EB8);
    MainPool_FinalizeAllocation(temp_v0);
}
