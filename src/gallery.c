#include "gallery.h"
#include "src/fragments/gallery_camera/gallery_camera.h"
#include "src/fragments/particle_data_library/particle_data_library.h"
#include "src/fragments/particle_math/particle_math.h"
#include "src/geo_node.h"
#include "src/geo_render.h"
#include "src/model_animation.h"
#include "src/model_animation_events.h"
#include "src/geo_layout.h"
#include "src/display_object_textures.h"
#include "src/model_renderer.h"
#include "src/graphics_textures.h"
#include "src/game_state.h"
#include "src/jpeg_stream.h"
#include "src/audio_sfx_wrapper.h"
#include "src/audio_loop_point.h"
#include "src/memory.h"
#include "src/util.h"

typedef struct {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;

    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
} unk_D_800761B0; /* size = 0x10 */

typedef struct unk_func_8003013C_arg1 {
    /* 0x00 */ u8 pad00[0x1C];
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ s16 unk_1E;
} unk_func_8003013C_arg1; // size >= 0x20

typedef struct unk_func_80031660_sp24 {
    /* 0x00 */ u8 pad00[0x18];
    /* 0x18 */ s32 unk_18;
} unk_func_80031660_sp24; // size = 0x1C

unk_func_80031270* D_80075F80 = NULL;
unk_func_80031270* D_80075F84 = NULL;
f32 D_80075F88[2] = { 40.0f, 25.0f };
unk_D_80068BB0* D_80075F90 = NULL;
s32 D_80075F94 = 0xC8;
s32 D_80075F98 = 0x2B;
s32 D_80075F9C = 0;
u32 D_80075FA0[115] = {
    0x0C00FFFF, 0x05000000, 0x0B00001E, 0x00000000, 0x014000F0, 0x0000000F,
    0x00000000, 0x00000000, 0x08000000, 0x80030010, 0x00000000, 0x05000000,
    0x0D000000, 0x05000000, 0x13FFFFFF, 0x03C003E8, 0x08000000, 0x80030228,
    0x00000000, 0x14000000, 0x002D0019, 0xFFFFFF28, 0x08000000, 0x8003013C,
    0x00000000, 0x14000000, 0x002D0019, 0x80808028, 0x08000000, 0x800301A4,
    0x00000000, 0x16646464, 0x0F000002, 0x05000000, 0x1F00FFFF, 0x00000000,
    0x00000000, 0x00000000, 0x00640064, 0x00640000, 0x05000000, 0x09000000,
    0x08000000, 0x80030240, 0x00000000, 0x06000000, 0x06000000, 0x0F000003,
    0x05000000, 0x1F00FFFF, 0x00000000, 0x00000000, 0x00000000, 0x00640064,
    0x00640000, 0x05000000, 0x09000000, 0x08000000, 0x80030240, 0x00000001,
    0x06000000, 0x06000000, 0x0F000002, 0x05000000, 0x1F00FFFF, 0x00000000,
    0x00000000, 0x00000000, 0x00640064, 0x00640000, 0x05000000, 0x09000000,
    0x08000000, 0x80030240, 0x00000002, 0x06000000, 0x06000000, 0x0F000003,
    0x05000000, 0x1F000000, 0x00000000, 0x00000000, 0xFF060000, 0x00640064,
    0x00640000, 0x08000000, 0x80030210, 0x00000000, 0x06000000, 0x06000000,
    0x06000000, 0x0B00002D, 0x00000000, 0x014000F0, 0x00000000, 0xFDBD0000,
    0x00000243, 0x08000000, 0x800300CC, 0x00000000, 0x05000000, 0x0D000000,
    0x05000000, 0x0F000002, 0x05000000, 0x22010000, 0x00000000, 0x08000000,
    0x800303C8, 0x00000000, 0x06000000, 0x06000000, 0x06000000, 0x06000000,
    0x01000000,
};
u32 D_8007616C[17] = {
    0x00000000, 0x00000001, 0x00000003, 0x00000004, 0x00000005, 0x00000006,
    0x00000007, 0x00000008, 0x00000009, 0x0000000A, 0x0000000B, 0x0000000C,
    0x0000000D, 0x0000000E, 0x0000000F, 0x00000011, 0x00000000,
};
unk_D_800761B0 D_800761B0[12] = {
    { 0, 0, -579, 0, 0, 0, 127, -256, },
    { 0, 0, -579, 0, 0, 0, 127, -256, },
    { 0, 0, -579, 0, 0, 0, 127, -256, },
    { 0, 0, -579, 0, 0, 0, 127, -256, },
    { 0, 0, -579, 0, 0, 0, 127, -256, },
    { 0, 0, -579, 0, 0, 0, 127, -256, },
    { 0, 0, -579, 0, 0, 0, 127, -256, },
    { 0, 0, -579, 0, 0, 0, 127, -256, },
    { 0, 0, -579, 0, 0, 0, 127, -256, },
    { 0, 0, -579, 0, 0, 0, 127, -256, },
    { 0, 0, -579, 0, 0, 0, 127, -256, },
    { 0, 0, -579, 0, 0, 0, 127, -256, },
};

void Gallery_ClearActiveScene(void);
void func_8340051C(void);

void Gallery_Dispatch(void) {
    s32 var_s6;
    u32* temp_s0;
    u32 var_s0;
    u32 var_s2;
    u32 sp64;
    u32 var_s5;
    u32 sp5C;
    s32 var_v0;
    unk_D_83407B00* val;

    val = &D_83407B30;
    var_s2 = 0;
    var_s5 = 0;

    main_pool_push_state('SNPM');
    Audio_StartMusicTrack(0x4B);

    FRAGMENT_LOAD(fragment43)();
    FRAGMENT_LOAD(fragment34);

    do {
        temp_s0 = Util_ConvertAddrToVirtAddr((u32)val);
        var_s6 = 1;

        main_pool_push_state('galy');

        switch (var_s5) {
            case 0:
                var_v0 = 0;
                if (*temp_s0 != 0) {
                    var_s0 = 1;
                } else {

                    switch (var_s2) {
                        case 4:
                            var_s0 = 2;
                            break;

                        default:
                            var_s0 = 0;
                            if (var_s2 == 7) {
                                var_v0 = 1;
                            }
                            break;
                    }
                }
                sp64 = FRAGMENT_LOAD_AND_CALL(fragment42, var_s0, var_v0);
                break;

            case 1:
            case 6:
                FRAGMENT_LOAD(fragment2)();
                // loaded, but doesnt use any GFX from it. speculated to have intended using the
                // button GFX for How to Snap, but it doesnt use them.
                ASSET_LOAD(D_3000000, kids_club_game_ui, 0);
                FRAGMENT_LOAD(fragment3);
                FRAGMENT_LOAD(fragment31);

                // determine if this is "How to Snap" or regular Snap Mode.
                if (var_s5 == 1) {
                    var_s0 = 0;
                } else {
                    var_s0 = 1;
                }

                switch (FRAGMENT_LOAD_AND_CALL(fragment15, var_s0, 0)) {
                    case 1:
                        sp64 = 5;
                        break;

                    case 2:
                        if (var_s0 == 1) {
                            sp64 = 5;
                        } else {
                            sp64 = 2;
                        }
                        break;

                    default:
                        sp64 = 5;
                        break;
                }
                break;

            case 2:
                if (var_s2 == 4) {
                    var_s0 = 0;
                } else {
                    var_s0 = 1;
                }
                sp64 = FRAGMENT_LOAD_AND_CALL(fragment45, var_s0, 0);
                break;

            case 3:
                var_v0 = 1;
                switch (var_s2) {
                    case 4:
                        var_s0 = sp5C;
                        var_v0 = 0;
                        break;

                    case 2:
                        var_s0 = 1;
                        break;

                    default:
                        if (*temp_s0 != 0) {
                            var_s0 = 2;
                        } else {
                            var_s0 = 0;
                        }
                        break;
                }

                sp64 = FRAGMENT_LOAD_AND_CALL(fragment44, var_s0, var_v0);
                if (sp64 == 4) {
                    sp5C = var_s0;
                }
                break;

            case 4:
                FRAGMENT_LOAD_AND_CALL(fragment46, 0, 0);
                sp64 = var_s2;
                break;

            case 5:
                FRAGMENT_LOAD(fragment61);
                switch (var_s2) {
                    case 1:
                        var_s0 = 1;
                        break;

                    case 6:
                        var_s0 = 2;
                        break;

                    default:
                        var_s0 = 0;
                        break;
                }
                sp64 = FRAGMENT_LOAD_AND_CALL(fragment47, var_s0, 0);
                break;

            case 7:
                FRAGMENT_LOAD_AND_CALL(fragment49, 0, 0);
                sp64 = 0;
                break;

            default:
                var_s6 = 0;
                break;
        }

        var_s2 = var_s5;
        var_s5 = sp64;

        main_pool_pop_state('galy');

    } while (var_s6 != 0);

    ((ret_func_80004454)Util_ConvertAddrToVirtAddr(func_8340051C))();

    main_pool_pop_state('SNPM');
}

void Gallery_ResetActiveScene(void) {
    Gallery_ClearActiveScene();
}

void Gallery_ClearPhotoRenderTarget(void) {
    D_80075F90 = 0;
}

s32 Gallery_GetPhotoPoseIndex(unk_D_83403C60* arg0) {
    return ((s32) arg0->unk_6C >> 2) & 3;
}

f32 Gallery_GetPhotoScaleIndex(unk_D_83403C60* arg0) {
    s32 index;
    f32* table;
    index = ((s32) arg0->unk_6C >> 1) & 1;
    table = (f32*)Util_ConvertAddrToVirtAddr(&D_80075F88);
    return table[index];
}

u32 Gallery_GetPhotoVariantIndex(unk_D_83403C60* arg0) {
    u8 v1 = arg0->unk_6C;
    v1 = v1 >> 4;
    return v1 & 0xF;
}

s32 Gallery_GetScenePoseIndex(s32 arg0) {
    unk_func_80031270* var_a1;
    UNUSED unk_func_80031270* sp1C;

    var_a1 = NULL;
    switch (arg0) {
    case 0:
        var_a1 = D_80075F80;
        break;
    case 2:
        var_a1 = D_80075F84;
        break;
    case 5:
        var_a1 = D_80075F84;
        break;
    }
    sp1C = var_a1;
    if (Gallery_IsSceneReady(var_a1) != 0) {
        return Gallery_GetPhotoPoseIndex(var_a1->unk_18);
    }
    return 0;
}

s32 Gallery_ConfigurePhotoCamera(s32 arg0, unk_D_86002F34_00C* arg1) {
    s32 pad;
    unk_D_83403C60_050_00C* src;

    if (arg0 == 2) {
        src = (unk_D_83403C60_050_00C*)((u8*)D_80075F84->unk_18 + 0x50);
        GeoCamera_SetViewport(arg1, 0, 0, D_80075F84->unk_04, D_80075F84->unk_06);
        GeoCamera_SetPerspective(arg1, Gallery_GetPhotoScaleIndex(D_80075F84->unk_18), 20.0f, 10000.0f);
        ((unk_D_83403C60_050_00C*)((u8*)arg1 + 0xA8))[0] = src[0];
        ((unk_D_83403C60_050_00C*)((u8*)arg1 + 0xA8))[1] = src[1];
        pad = 0;
    }
    return 0;
}

s32 Gallery_SetScenePoseCamera(s32 arg0, unk_D_86002F34_00C* arg1) {
    if (Gallery_GetScenePoseIndex(arg0) != 0) {
        if (arg0 == 2) {
            GeoCamera_SetViewport(arg1, 0, 0, D_80075F84->unk_04, D_80075F84->unk_06);
            GeoCamera_SetPerspective(arg1, 45.0f, 20.0f, 8000.0f);
        }
    }
    return 0;
}

s32 Gallery_SetCameraAngleOffsets(s32 arg0, unk_func_8003013C_arg1* arg1) {
    UNUSED s32 pad;
    f32 sp28;
    s16 sp26;
    s16 sp24;

    if (arg0 == 2) {
        Vec3f_CalculateDistanceAngles(&D_8006F088->unk_60.at, &D_8006F088->unk_60.eye, &sp28, &sp26, &sp24);
        arg1->unk_1C = (s16) (sp26 + 0x2000);
        arg1->unk_1E = (s16) (sp24 - 0x2000);
    }
    return 0;
}

s32 Gallery_SetCameraAngleOffsetsAlternate(s32 arg0, unk_func_8003013C_arg1* arg1) {
    UNUSED s32 pad;
    f32 sp28;
    s16 sp26;
    s16 sp24;

    if (arg0 == 2) {
        Vec3f_CalculateDistanceAngles(&D_8006F088->unk_60.at, &D_8006F088->unk_60.eye, &sp28, &sp26, &sp24);
        arg1->unk_1C = (s16) (-0x2000 - sp26);
        arg1->unk_1E = (s16) (sp24 + 0x6000);
    }
    return 0;
}

s32 Gallery_SetSceneModelNode(s32 arg0, DisplayObject* arg1) {
    if (arg0 == 0) {
        D_80075F80->unk_20 = arg1;
    }
    return 0;
}

s32 Gallery_SetSceneRenderState(s32 arg0, unk_func_80031270_024* arg1) {
    if (arg0 == 0) {
        D_80075F80->unk_24 = arg1;
    }
    return 0;
}

s32 Gallery_SetSceneGraphNode(s32 arg0, GraphNode* arg1) {
    s32 temp_v0;

    if (arg0 == 0) {
        temp_v0 = arg1->callbackArg;
        switch (temp_v0) {                          /* irregular */
        case 0:
            D_80075F80->unk_28 = arg1;
            break;
        case 1:
            D_80075F80->unk_2C = arg1;
            break;
        case 2:
            D_80075F80->unk_30 = arg1;
            break;
        }
        arg1->callbackArg = 0;
    }
    return 0;
}

void Gallery_InitializePhotoGrid(s32 arg0, s32 arg1) {
    s16 temp_a0;
    s16 temp_a1;
    s32 temp_a3;
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_a2;
    s32 i;
    unk_D_800761B0* var = &D_800761B0[10];
    unk_D_800761B0* var2 = &D_800761B0[11];

    temp_v0 = arg0 - 0xC8;
    temp_v1 = arg0 + 0xC8;
    temp_a2 = arg1 + 0x2B;
    temp_a3 = arg1 - 0x2B;
    for(i = 0; i < 12; i+=2) {
        D_800761B0[i].unk_00 = temp_v0;
        D_800761B0[i].unk_08 = 0;
        D_800761B0[i + 1].unk_00 = temp_v1;
        D_800761B0[i + 1].unk_08 = 0x18E0;
        if (i < 10) {
            temp_a0 = temp_a2 - (i * 0xA);
            D_800761B0[i].unk_02 = temp_a0;
            D_800761B0[i + 1].unk_02 = temp_a0;
            temp_a1 = (i * 5) << 5;
            D_800761B0[i].unk_0A = temp_a1;
            D_800761B0[i + 1].unk_0A = temp_a1;
        } else {
            D_800761B0[10].unk_02 = temp_a3;
            var->unk_0A = 0x540;
            D_800761B0[11].unk_02 = temp_a3;
            var2->unk_0A = 0x540;
        }
    }
}

s32 func_800303C8(s32 arg0, UNUSED GraphNode* arg1) {
    s32 temp_v0;
    s32 i;
    char* sp16C;

    temp_v0 = Gallery_GetScenePoseIndex(arg0);
    if ((temp_v0 != 0) && (arg0 == 2)) {
        sp16C = (char*)((u8*)D_80075F84->unk_18 + 0x73);
        D_80075F9C = Font_MeasureTextExtent(0x10, 0, sp16C);
        Gallery_InitializePhotoGrid(0, -0x96);
        GfxImage_SetRenderTarget(&gDisplayListHead, D_80075F90);
        GfxImage_FillCurrent(&gDisplayListHead, 0);
        gDPPipeSync(gDisplayListHead++);
        gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
        gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
        gDPSetTextureConvert(gDisplayListHead++, G_TC_FILT);
        gDPSetTextureLOD(gDisplayListHead++, G_TL_TILE);
        gDPSetTextureDetail(gDisplayListHead++, G_TD_CLAMP);
        gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
        gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGBA, G_CC_DECALRGBA);
        gDPSetRenderMode(gDisplayListHead++, G_RM_AA_TEX_EDGE, G_RM_AA_TEX_EDGE2);

        if (temp_v0 == 1) {
            for (i = 0; i < 2; i++) {
                gDPLoadTextureTile(gDisplayListHead++, D_5001950, G_IM_FMT_RGBA, G_IM_SIZ_16b, 100, 0, 0, (i * 15), 99, ((i + 1) * 15) - 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                gSPTextureRectangle(gDisplayListHead++, 0, (i * 15) << 2, 100 << 2, ((i + 1) * 15) << 2, 0, 0, (i * 15) << 5, 1 << 10, 1 << 10);
                gSPTextureRectangle(gDisplayListHead++, 100 << 2, (i * 15) << 2, 200 << 2, ((i + 1) * 15) << 2, 0, 100 << 5, (i * 15) << 5, -(1 << 10), 1 << 10);
            }
            gDPLoadTextureTile(gDisplayListHead++, D_5001950, G_IM_FMT_RGBA, G_IM_SIZ_16b, 100, 0, 0, 30, 99, 42, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(gDisplayListHead++, 0, 30 << 2, 100 << 2, 43 << 2, 0, 0, 30 << 5, 1 << 10, 1 << 10);
            gSPTextureRectangle(gDisplayListHead++, 100 << 2, 30 << 2, 200 << 2, 43 << 2, 0, 100 << 5, 30 << 5, -(1 << 10), 1 << 10);
            Font_BeginTranslucentTextRendering();
            Font_EnableTwoCycleTexturing();
            Gfx_SetEnvColor(0xF0, 0x78, 0x6E, 0xFF);
            Gfx_SetPrimColor(0xF0, 0xF0, 0x78, 0xFF);
            Font_SetActive(0x10, 0);
            Font_Printf(0x64 - ((s32) D_80075F9C / 2), 5, sp16C);
            Font_DisableTwoCycleTexturing();
            Font_EndTexturedTextRendering();
        } else {
            gDPLoadTextureTile(gDisplayListHead++, D_5003AE8, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 40, 0, 0, 31, 39, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(gDisplayListHead++, 16 << 2, 0 << 2, 152 << 2, 40 << 2, 0, 0, 0, 1 << 10, 1 << 10);
            gSPTextureRectangle(gDisplayListHead++, 152 << 2, 0 << 2, 185 << 2, 40 << 2, 0, 32 << 5, 0, -(1 << 10), 1 << 10);
            Font_BeginTranslucentTextRendering();
            Font_EnableTwoCycleTexturing();
            Gfx_SetEnvColor(0xDC, 0xFF, 0xDC, 0xFF);
            Gfx_SetPrimColor(0x78, 0xB4, 0xFF, 0xFF);
            Font_SetActive(0x10, 0);
            Font_Printf(0x64 - ((s32) D_80075F9C / 2), 7, sp16C);
            Font_DisableTwoCycleTexturing();
            Font_EndTexturedTextRendering();
        }
        GfxImage_SetRenderTarget(&gDisplayListHead, D_80075F84->unk_08);
        gDPPipeSync(gDisplayListHead++);
        gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
        gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGBA, G_CC_DECALRGBA);
        gDPSetRenderMode(gDisplayListHead++, G_RM_AA_TEX_EDGE, G_RM_AA_TEX_EDGE2);
        gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
        gSPMatrix(gDisplayListHead++, &D_8006F010, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPVertex(gDisplayListHead++, D_800761B0, 12, 0);
        for (i = 0; i < 10; i += 2) {
            gDPLoadMultiTile(gDisplayListHead++, D_80075F90->img_p, 0, 0, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_80075F94, D_80075F98, 0, i * 5, D_80075F94 - 1, (i + 2) * 5 - 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            gSP2Triangles(gDisplayListHead++, i, 2 + i, 1 + i, i, 1 + i, 2 + i, 3 + i, i);
        }
        gDPLoadMultiTile(gDisplayListHead++, D_80075F90->img_p, 0, 0, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_80075F94, D_80075F98, 0, 40, D_80075F94 - 1, D_80075F98 - 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSP2Triangles(gDisplayListHead++, 9, 8, 10, 0, 11, 9, 10, 0);
        gSPTexture(gDisplayListHead++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
    }
    return 0;
}

void Gallery_CopyPhotoMonFromBattleMon(unk_D_83402EE0_070* arg0, BattleMon* arg1) {
    s32 i;

    bzero(arg0, sizeof(unk_D_83402EE0_070));
    arg0->unk_00 = arg1->unk_0E;
    arg0->unk_02 = arg1->unk_00.unk_00;

    for (i = 0; i < 11; i++) {
        arg0->unk_03[i] = ((s8*)arg1->unk_30)[i];
    }

    for (i = 0; i < 11; i++) {
        arg0->unk_0E[i] = ((s8*)arg1->unk_3B)[i];
    }
}

void Gallery_CopyBattleMonFromPhotoMon(BattleMon* arg0, unk_D_83407AC8* arg1) {
    s32 i;

    bzero(arg0, sizeof(BattleMon));

    arg0->unk_0E = arg1->unk_00;
    arg0->unk_00.unk_00 = arg1->unk_02;

    for (i = 0; i < 11; i++) {
        arg0->unk_30[i] = arg1->unk_03[i];
    }

    for (i = 0; i < 11; i++) {
        arg0->unk_3B[i] = arg1->unk_0E[i];
    }
}

void Geo_LoadSceneGraphNode(unk_func_80031270* arg0, UNUSED s16 arg1, UNUSED s16 arg2) {
    UNUSED s32 pad;
    MemoryBlock* sp18;

    sp18 = MainPool_AllocState(main_pool_get_available(), 0);
    D_80075F80 = arg0;
    arg0->unk_1C = process_geo_layout(sp18, D_80075FA0);
    D_80075F80 = NULL;
    MainPool_FinalizeAllocation(sp18);
}

unk_func_80031270* Geo_CreateSceneInstance(s16 arg0, s16 arg1, unk_D_80068BB0* arg2, unk_D_80068BB0* arg3,
                                 ModelLoadContext* arg4, BinArchive* arg5, unk_D_83403C60* arg6) {
    UNUSED unk_D_80068BB0* var_v0;
    unk_func_80031270* temp_v0 = main_pool_alloc(sizeof(unk_func_80031270), 0);

    if (temp_v0 != NULL) {
        temp_v0->unk_00 = 0;
        temp_v0->unk_02 = 0;
        temp_v0->unk_04 = arg0;
        temp_v0->unk_06 = arg1;

        if (arg2 != NULL) {
            temp_v0->unk_08 = arg2;
        } else {
            temp_v0->unk_08 = GfxImage_Allocate(0, 2, arg0, arg1, 0);
        }

        if (arg3 != NULL) {
            temp_v0->unk_0C = arg3;
        } else {
            temp_v0->unk_0C = GfxImage_Allocate(0, 2, arg0, arg1, 1);
        }

        GfxImage_AttachDepthBuffer(temp_v0->unk_08, temp_v0->unk_0C);

        temp_v0->unk_10 = arg4;
        temp_v0->unk_14 = arg5;
        temp_v0->unk_18 = arg6;
        temp_v0->unk_34 = 0;

        if (D_80075F90 == 0) {
            D_80075F90 = GfxImage_Allocate(0, 2, 0xC8, 0x2B, 0);
        }

        Geo_LoadSceneGraphNode(temp_v0, arg0, arg1);
    }
    return temp_v0;
}

typedef union unk_func_80026268_arg0_000_raw {
    struct {
        u8 unk_00;
        u8 unk_01;
        u16 unk_02;
    };
    f32 raw;
} unk_func_80026268_arg0_000_raw; // size = 0x4

typedef struct unk_func_80026268_arg0_raw {
    /* 0x00 */ unk_func_80026268_arg0_000_raw unk_00;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ u8 unk_09[4];
    /* 0x0D */ u8 pad0D;
    /* 0x0E */ u16 unk_0E;
    /* 0x10 */ u32 unk_10;
    /* 0x14 */ u16 unk_14;
    /* 0x16 */ u16 unk_16;
    /* 0x18 */ u16 unk_18;
    /* 0x1A */ u16 unk_1A;
    /* 0x1C */ u16 unk_1C;
    /* 0x1E */ u16 unk_1E;
    /* 0x20 */ u8 unk_20[4];
    /* 0x24 */ u8 unk_24;
    /* 0x25 */ u8 unk_25;
    /* 0x26 */ u16 unk_26;
    /* 0x28 */ u16 unk_28;
    /* 0x2A */ u16 unk_2A;
    /* 0x2C */ u16 unk_2C;
    /* 0x2E */ u16 unk_2E;
    /* 0x30 */ u8 unk_30[11];
    /* 0x3B */ u8 unk_3B[11];
    /* 0x46 */ u8 unk_46[11];
    /* 0x51 */ char unk51[0x1];
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ u8 unk_53;
} unk_func_80026268_arg0_raw; // size = 0x54

typedef struct unk_D_83403C60_raw {
    /* 0x00 */ unk_func_80026268_arg0_raw unk_00;
    /* 0x54 */ char unk54[0x18];
    /* 0x6C */ u8 unk_6C;
    /* 0x6D */ char unk6D[0x3];
    /* 0x70 */ unk_D_83407AC8 unk_70;
    /* 0x8A */ char unk8A[0x2];
} unk_D_83403C60_raw; // size = 0x8C

void Gallery_InitializePhotoModel(unk_func_80031270* arg0) {
    s32 sp94;
    arg1_func_80010CA8 sp90;
    UNUSED s32 pad[3]; // BattleMon potentially bigger?
    BattleMon sp30;
    unk_D_83403C60_raw* temp_s1;
    void (*sp28)(void*, u32);

    temp_s1 = (unk_D_83403C60_raw*)arg0->unk_18;
    Gallery_CopyBattleMonFromPhotoMon(&sp30, &temp_s1->unk_70);
    Vec3f_SetComponentsDuplicate(&arg0->unk_20->position, 0, temp_s1->unk_00.unk_00.raw, 0); //?
    arg0->unk_20->effectSlot = 0xFE;
    sp94 = sp30.unk_00.unk_00;
    if (sp30.unk_00.unk_00 == 0x99) {
        sp30.unk_00.unk_00 = 0x19;
    }
    Model_ComputeSizeVariant(&sp90, &sp30);
    sp30.unk_00.unk_00 = sp94;
    PokeIcon_RequestFrameLoad(arg0->unk_10, sp30.unk_00.unk_00, sp90);
    PokeIcon_WaitFrameLoad(arg0->unk_10);
    ModelRenderer_ClearDisplayObject(arg0->unk_20);
    Model_InitDisplayObject(arg0->unk_20, 0, sp30.unk_00.unk_00, arg0->unk_10->loadedModel->modelRoot->unk_00[0]);
    sp28 = Util_ConvertAddrToVirtAddr(&Particle31_UnpackSlotData);
    sp28(arg0->unk_20, Util_ConvertAddrToVirtAddr(&temp_s1->unk_00.unk_09[1]));
    ModelAnim_SetAnimation(arg0->unk_20, temp_s1->unk_00.unk_05);
    ModelAnim_SetFrame(arg0->unk_20, temp_s1->unk_00.unk_06);
    ModelAnim_SetEventTrack(arg0->unk_20, temp_s1->unk_00.unk_08);
    ModelAnim_SetEventFrame(arg0->unk_20, (s16)temp_s1->unk_00.unk_09[0]);
}

void Gallery_LoadPhotoSceneGraph(unk_func_80031270* arg0) {
    MemoryBlock* sp24;
    FragmentEntry sp20;
    u32* temp_v0;
    u32* temp_v0_2;
    u32* temp_v0_3;
    unk_func_800314BC_temp_v4* temp_v0_4;
    unk_func_80031270_024* temp_v1;

    GeoNode_CreateContainer(0, arg0->unk_28);
    GeoNode_CreateContainer(0, arg0->unk_2C);
    GeoNode_CreateContainer(0, arg0->unk_30);
    sp20 = BinArchive_GetFile(arg0->unk_14, D_8007616C[Gallery_GetPhotoVariantIndex(arg0->unk_18)]);
    sp24 = MainPool_AllocState(main_pool_get_available(), 0);
    temp_v0 = sp20(0, 0);
    if (temp_v0 != NULL) {
        GraphNode_AppendChild(arg0->unk_28, process_geo_layout(sp24, temp_v0));
    }
    temp_v0_2 = sp20(1, 0);
    if (temp_v0_2 != NULL) {
        GraphNode_AppendChild(arg0->unk_2C, process_geo_layout(sp24, temp_v0_2));
    }
    temp_v0_3 = sp20(3, 0);
    if (temp_v0_3 != NULL) {
        GraphNode_AppendChild(arg0->unk_30, process_geo_layout(sp24, temp_v0_3));
    }
    arg0->unk_34 = sp20(2, 0);
    MainPool_FinalizeAllocation(sp24);
    temp_v0_4 = sp20(4, 0);
    if (temp_v0_4 == NULL) {
        temp_v1 = arg0->unk_24;
        temp_v1->unk_01 = (u8) (temp_v1->unk_01 & 0xFFFE);
        arg0->unk_24->unk_14 = 0;
        return;
    }
    arg0->unk_24->unk_18 = (s16) temp_v0_4->unk_00;
    arg0->unk_24->unk_1A = (s16) temp_v0_4->unk_02;
    arg0->unk_24->unk_1C = (s32) temp_v0_4->unk_04;
    arg0->unk_24->unk_14 = 1;
    temp_v1 = arg0->unk_24;
    temp_v1->unk_01 = (u8) (temp_v1->unk_01 | 1);
}

u8* Gallery_ProcessSceneInstance(unk_func_80031270* arg0) {
    unk_func_80031660_sp24* sp24;
    void (*sp20)();

    sp24 = (unk_func_80031660_sp24*)((u8*)arg0->unk_18 + 0x50);
    sp20 = Util_ConvertAddrToVirtAddr(&Particle_UpdateFrameCountersAlias);
    D_80075F84 = arg0;
    if (arg0->unk_00 == 1) {
        switch (arg0->unk_02) {
            case 2:
                Gallery_InitializePhotoModel(arg0);
                Gallery_LoadPhotoSceneGraph(arg0);
                break;
            case 1:
                GfxImage_SetRenderTarget(&gDisplayListHead, arg0->unk_08);

                if ((arg0->unk_34 == -1) || (arg0->unk_34 == 0)) {
                    GfxImage_FillCurrent(&gDisplayListHead, 1);
                } else if (arg0->unk_34 < 0x10000U) {
                    GfxImage_FillCurrent(&gDisplayListHead, arg0->unk_34);
                } else {
                    GfxImage_FillCurrent(&gDisplayListHead, 0xA6BF);
                }
                GeoRender_AdvanceFrameCounter();
                *((s32*)Util_ConvertAddrToVirtAddr(&gParticleFrameCounter)) = sp24->unk_18;
                sp20();
                Geo_RenderRootNode(arg0->unk_1C);
                break;
            default:
                break;
        }
 
    }
    switch (arg0->unk_00) {
        case 0:
            arg0->unk_00 = 1;
            arg0->unk_02 = 2;
            break;
        case 1:
            arg0->unk_02--;
            if (arg0->unk_02 <= 0) {
                arg0->unk_00 = 2;
            }
            break;
        case 2:
            break;
    }
    return arg0->unk_08->img_p;
}

s32 Gallery_IsSceneReady(unk_func_80031270* arg0) {
    s32 var_v1;
    s32 sp1C;
    unk_D_83403C60* temp_a0;

    var_v1 = 0;
    if (arg0 != NULL) {
        temp_a0 = arg0->unk_18;
        if (temp_a0 != 0) {
            sp1C = 0;
            var_v1 = sp1C;
            if (Gallery_IsPhotoSpeciesValid(temp_a0) != 0) {
                var_v1 = 1;
            }
        }
    }
    return var_v1;
}

s32 Gallery_FindReadyScene(unk_func_80031270** arg0, s32 arg1) {
    unk_func_80031270* temp_s1;
    s32 sp30;
    s32 i;

    sp30 = -1;

    for (i = 0; i < arg1; i++) {
        temp_s1 = arg0[i];
        if ((Gallery_IsSceneReady(temp_s1) != 0) && (temp_s1->unk_00 == 1)) {
            sp30 = i;
            break;
        }
    }
    return sp30;
}

unk_func_80031270* Gallery_GetActiveScene(void) {
    return D_80075F84;
}

void Gallery_ClearActiveScene(void) {
    D_80075F84 = 0;
}

s32 Gallery_IsPhotoSpeciesValid(unk_D_83403C60* arg0) {
    s32 v1 = 0;

    if ((arg0->unk_00.unk_04 > 0 && arg0->unk_00.unk_04 < 0x98) || arg0->unk_00.unk_04 == 0x99) {
        v1 = 1;
    }
    return v1;
}

void func_800318F0(void) {
    func_80036790();
}
