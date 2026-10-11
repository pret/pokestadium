#include "demo_scenes.h"
#include "src/geo_render.h"
#include "src/model_animation.h"
#include "src/geo_layout.h"
#include "src/display_object_textures.h"
#include "src/model_renderer.h"
#include "src/graphics_textures.h"
#include "src/input.h"
#include "src/save_data.h"
#include "src/text_system.h"
#include "src/jpeg_stream.h"
#include "src/audio_loop_point.h"
#include "src/gfx_rect.h"
#include "src/matrix.h"
#include "src/controller.h"
#include "src/fragments/particle_math/particle_math.h"
#include "src/memory.h"
#include "src/stage_loader.h"

typedef struct unk_D_86B0E5D8 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ u8 unk_06;
    /* 0x07 */ u8 unk_07;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
} unk_D_86B0E5D8; // size = 0xC

extern u32 D_86B0BD60[];
extern unk_D_86B0C4C8* D_86B0C4C8[];
extern unk_D_86B0C160 D_86B0C160[];
extern unk_D_86B0C264 D_86B0C264[];
extern u32 D_86B0CF9C[];
extern u32 D_86B0DA9C[];

s32 Diorama_LogoRotateColorCallback(s32, GraphNode*);
s32 Diorama_ScaleRotateCallbackA(s32, GraphNode*);
s32 Diorama_ScaleRotateCallbackB(s32, GraphNode*);
s32 Diorama_GroupStateCallback(s32, GraphNode*);

static s16 D_86B0BBF0 = -0x3C6E;
static s16 D_86B0BBF4 = 0x38E;

static u32 D_86B0BBF8[] = {
    0x0C00FFFF, 0x05000000, 0x0B00001E, 0x00000000, 0x014000F0,  0x0000000F,    0x00000000,    0x00000000,
    0x05000000, 0x0D000000, 0x05000000, 0x1A050000, 0x08000000,  Diorama_GroupStateCallback, 0x00000000,    0x05000000,
    0x0F000002, 0x05000000, 0x06000000, 0x0F000002, 0x05000000,  0x06000000,    0x0F000002,    0x05000000,
    0x1F00FFFF, 0xC3920000, 0x00000000, 0xFC400000, 0x00640064,  0x00640000,    0x08000000,    Diorama_ScaleRotateCallbackA,
    0x00000000, 0x05000000, 0x00000000, D_86B0CF9C, 0x06000000,  0x06000000,    0x0F000002,    0x05000000,
    0x1F00FFFF, 0x00000000, 0x00000000, 0x0514F79A, 0x00640064,  0x00640000,    0x08000000,    Diorama_ScaleRotateCallbackB,
    0x00000000, 0x05000000, 0x00000000, D_86B0DA9C, 0x06000000,  0x06000000,    0x0F000002,    0x05000000,
    0x06000000, 0x06000000, 0x14000000, 0xF8E40000, 0xFFC89BFF,  0x08000000,    Diorama_LogoRotateColorCallback, 0x00000000,
    0x16FFFFFF, 0x0F000003, 0x05000000, 0x0A000000, &D_800AC840, 0x06000000,    0x06000000,    0x06000000,
    0x06000000, 0x01000000,
};

static GraphNode* D_86B0E5D0;
static unk_D_86B0E5D4* D_86B0E5D4;
static unk_D_86B0E5D8* D_86B0E5D8;
s32 D_86B0E5DC;
char** D_86B0E5E0;
static BinArchive* D_86B0E5E4;
static u8* D_86B0E5E8;
static unk_D_86B0E5F0 D_86B0E5F0[4];
static s32 D_86B0EBB0;
static s32 D_86B0EBB4;
static u16 D_86B0EBB8;

s32 Diorama_LogoRotateColorCallback(s32 arg0, GraphNode* arg1) {
    if (arg0 == 2) {
        unk_D_86002F34_alt18* ptr = (unk_D_86002F34_alt18*)arg1;

        D_86B0E5D8->unk_00 += D_86B0E5D8->unk_08;
        D_86B0E5D8->unk_02 += D_86B0E5D8->unk_0A;

        ptr->unk_1C = D_86B0E5D8->unk_00;
        ptr->unk_1E = D_86B0E5D8->unk_02;
        ptr->r = D_86B0E5D8->unk_05;
        ptr->g = D_86B0E5D8->unk_06;
        ptr->b = D_86B0E5D8->unk_07;
        ptr->a = D_86B0E5D8->unk_04;
    }

    return 0;
}

s32 Diorama_ScaleRotateCallbackA(s32 arg0, GraphNode* arg1) {
    if (arg0 == 2) {
        DisplayObject* ptr = (DisplayObject*)arg1;

        ptr->scale.x = 1.5f;
        ptr->scale.y = 1.5f;
        ptr->scale.z = 1.5f;
        ptr->rotation.x = D_86B0BBF0;
    }

    return 0;
}

s32 Diorama_ScaleRotateCallbackB(s32 arg0, GraphNode* arg1) {
    if (arg0 == 2) {
        DisplayObject* ptr = (DisplayObject*)arg1;

        ptr->scale.x = 1.0f;
        ptr->scale.y = 1.0f;
        ptr->scale.z = 1.0f;

        ptr->rotation.x = D_86B0BBF4;
    }
    return 0;
}

s32 Diorama_GroupStateCallback(s32 arg0, GraphNode* arg1) {
    if (arg0 == 2) {
        unk_D_86002F34_alt21* ptr = (unk_D_86002F34_alt21*)arg1;

        ptr->unk_1A = D_86B0E5D4->unk_04.unk_44;
    }
    return 0;
}

void Diorama_ClearModelSlots(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_86B0E5F0[i].unk_16C = 0;
    }
}

void Diorama_FreeModelSlots(unk_D_86B0E5F0* arg0) {
    while (arg0->unk_16C != 1) {
        ModelRenderer_ClearDisplayObject(&arg0->unk_004);
        arg0++;
    }
    main_pool_pop_state('MONS');
}

void Diorama_PushModelPool(void) {
    main_pool_push_state('MONS');
}

void Diorama_InitModelSlot(unk_D_86B0E5F0* arg0, unk_D_86B0C4C8* arg1) {
    ModelRenderer_AttachDisplayObject(&arg0->unk_004);

    arg0->unk_000 = Model_LoadByArchiveIndex(arg1->unk_0C);

    Model_InitDisplayObject(&arg0->unk_004, 0, arg1->unk_0C, arg0->unk_000->unk_08->unk_00[0]);
    ModelAnim_SetAnimation(&arg0->unk_004, arg1->unk_10);

    if (arg1->unk_0C == 6) {
        arg0->unk_004.effectSlot = 0;
    } else {
        arg0->unk_004.effectSlot = 0xFF;
    }

    ModelAnim_SetFrame(&arg0->unk_004, 0);
    arg0->unk_004.node.renderFlags &= ~0x40;
}

void Diorama_SetModelSlotPosition(unk_D_86B0E5F0* arg0, unk_D_86B0C4C8* arg1) {
    arg0->unk_004.position.x = arg1->unk_00.x;
    arg0->unk_004.position.y = arg1->unk_00.y;
    arg0->unk_004.position.z = arg1->unk_00.z;
}

void Diorama_SetGlowFromGroup(s32 arg0) {
    D_86B0E5D8->unk_00 = D_86B0C264[arg0].unk_0C;
    D_86B0E5D8->unk_02 = D_86B0C264[arg0].unk_0E;
    D_86B0E5D8->unk_08 = D_86B0C264[arg0].unk_18;
    D_86B0E5D8->unk_0A = D_86B0C264[arg0].unk_1A;
    D_86B0E5D8->unk_05 = D_86B0C264[arg0].unk_10;
    D_86B0E5D8->unk_06 = D_86B0C264[arg0].unk_12;
    D_86B0E5D8->unk_07 = D_86B0C264[arg0].unk_14;
    D_86B0E5D8->unk_04 = D_86B0C264[arg0].unk_16;
}

void Diorama_LoadModelGroup(s32 arg0) {
    unk_D_86B0C4C8* var_s0 = D_86B0C4C8[arg0];
    unk_D_86B0E5F0* var_s1 = D_86B0E5F0;

    Diorama_ClearModelSlots();
    Diorama_PushModelPool();

    while (var_s0->unk_0C != 0x98) {
        Diorama_InitModelSlot(var_s1, var_s0);
        Diorama_SetModelSlotPosition(var_s1, var_s0);
        var_s1->unk_16C = 1;

        var_s1++;
        var_s0++;
    }

    Diorama_SetGlowFromGroup(arg0);
}

void Diorama_SwitchModelGroup(s32 arg0) {
    unk_D_86B0C4C8* sp2C = D_86B0C4C8[arg0];
    unk_D_86B0E5F0* var_s1 = D_86B0E5F0;

    Diorama_FreeModelSlots(D_86B0E5F0);
    Diorama_ClearModelSlots();
    Diorama_PushModelPool();

    while (sp2C->unk_0C != 0x98) {
        Diorama_InitModelSlot(var_s1, sp2C);
        Diorama_SetModelSlotPosition(var_s1, sp2C);
        var_s1->unk_16C = 1;

        var_s1++;
        sp2C++;
    }

    Diorama_SetGlowFromGroup(arg0);

    if (arg0 == 4) {
        ModelAnim_SetEventTrack(&D_86B0E5F0[0].unk_004, 0);
    }
}

void Diorama_SetGroupCamera(s32 arg0) {
    if (arg0 == 4) {
        D_86B0E5D4->unk_00->unk_60.at.x = -0.04f;
        D_86B0E5D4->unk_00->unk_60.at.y = 24.2f;
        D_86B0E5D4->unk_00->unk_60.at.z = -4.08f;
        D_86B0E5D4->unk_00->unk_60.eye.x = 0.04f;
        D_86B0E5D4->unk_00->unk_60.eye.y = 24.2f;
        D_86B0E5D4->unk_00->unk_60.eye.z = 177.41f;
        D_86B0E5D4->unk_00->unk_24.fovy = 25.0f;
    } else {
        D_86B0E5D4->unk_04.unk_00.x = D_86B0C264[arg0].unk_00.x;
        D_86B0E5D4->unk_04.unk_00.y = D_86B0C264[arg0].unk_00.y;
        D_86B0E5D4->unk_04.unk_00.z = D_86B0C264[arg0].unk_00.z;

        Diorama_LoadCameraKeyframe(&D_86B0C160[arg0], D_86B0E5D4);
        Diorama_SetCameraToKeyframeStart(&D_86B0E5D4->unk_04, D_86B0E5D4);
    }
}

void func_86B00680(void) {
}

void Diorama_LoopIdleAnimations(void) {
    s32 i = 0;

    if ((D_86B0E5D4->unk_04.unk_4C != 5) && (D_86B0E5D4->unk_04.unk_4C != 6) && (D_86B0E5D4->unk_04.unk_4C != 7) &&
        (D_86B0E5D4->unk_04.unk_4C != 8)) {
        if (D_86B0E5D4->unk_04.unk_44 != 4) {
            while (D_86B0C4C8[D_86B0E5D4->unk_04.unk_44][i].unk_0C != 0x98) {
                if (ModelAnim_IsAnimationDone(&D_86B0E5F0[i].unk_004) != 0) {
                    ModelAnim_SetFrame(&D_86B0E5F0[i].unk_004, 0);
                }
                i++;
            }
        }
    }
}

void Diorama_DrawFadeOverlay(void) {
    if (D_86B0E5D4->unk_04.unk_48 == 1) {
        Gfx_FillRectWithDisplayState(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 0, D_86B0EBB0);
    }
}

void Diorama_DrawGroupTransitionOverlay(void) {
    if (D_86B0E5D4->unk_04.unk_44 == 2) {
        Diorama_DrawFullscreenTexture(&D_86B0BD60, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 4, 0x80);
    }
}

s32 Diorama_SlideModelsForward(s32 arg0) {
    unk_D_86B0E5F0* var_v0 = D_86B0E5F0;
    unk_D_86B0C4C8* var_v1 = D_86B0C4C8[arg0];
    s32 var_a1 = 1;

    while (var_v1->unk_0C != 0x98) {
        var_v0->unk_004.position.z += 20.0f;
        if (var_v0->unk_004.position.z <= 650.0f) {
            var_a1 = 0;
        }
        var_v0++;
        var_v1++;
    }
    return var_a1;
}

void Diorama_BeginGroupTransition(void) {
    StageContext_SetClearColor(1);
    StageFade_StartFromTransparent(0xC);
    D_86B0E5D4->unk_04.unk_4C = 0;
    D_86B0E5D4->unk_04.unk_50 = 0;
}

void Diorama_FinishSequence(void) {
    D_86B0E5D4->unk_04.unk_4C = 9;
    D_86B0E5D4->unk_04.unk_50 = 0;
    D_86B0E5F0->unk_004.node.flags &= ~1;
    D_86B0E5DC = 1;
}

void Diorama_UpdateProximityHighlight(s32 arg0) {
    unk_D_86B0C4C8* ptr1 = D_86B0C4C8[arg0];
    unk_D_86B0E5F0* ptr2 = &D_86B0E5F0[0];
    s16 sp88[] = {
        // D_86B0BD20
        0x1554,
        0x1554,
        0x1554,
        0x1554,
    };
    s16 sp80[] = {
        // D_86B0BD28
        0x18E2,
        0x11C6,
        0x1554,
        0x1554,
    };
    f32 sp70[] = { 1000.0f, 1000.0f, 2000.0f, 2000.0f }; // D_86B0BD30
    f32 sp60[] = { 1.0f, 1.0f, 100.0f, 50.0f };          // D_86B0BD40

    while (ptr1->unk_0C != 0x98) {
        if (Diorama_IsModelInCameraCone(D_86B0E5D4->unk_00, &ptr2->unk_004, sp88[arg0], sp80[arg0], sp70[arg0], sp60[arg0]) != 0) {
            ptr2->unk_004.node.flags |= 1;
        } else {
            ptr2->unk_004.node.flags &= ~1;
        }
        ptr2++;
        ptr1++;
    }
}

void Diorama_ReadControllerInput(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    Input_ResetRepeatState();
}

void Diorama_InitSceneState(void) {
    D_86B0E5D4 = main_pool_alloc(sizeof(unk_D_86B0E5D4), 0);
    bzero(D_86B0E5D4, sizeof(unk_D_86B0E5D4));

    D_86B0E5D8 = main_pool_alloc(sizeof(unk_D_86B0E5D8), 0);
    bzero(D_86B0E5D8, sizeof(unk_D_86B0E5D8));

    D_86B0E5D4->unk_00 = D_86B0E5D0->children;

    D_86B0E5D4->unk_00->unk_24.near = 50.0f;
    D_86B0E5D4->unk_00->unk_24.far = 8400.0f;
    D_86B0E5D4->unk_00->unk_24.fovy = 30.0f;
    D_86B0E5D4->unk_00->unk_60.at.x = 50.0f;
    D_86B0E5D4->unk_00->unk_60.at.y = 50.0f;
    D_86B0E5D4->unk_00->unk_60.at.z = 50.0f;
    D_86B0E5D4->unk_00->unk_60.eye.x = 0.0f;
    D_86B0E5D4->unk_00->unk_60.eye.y = 0.0f;
    D_86B0E5D4->unk_00->unk_60.eye.z = 0.0f;
    D_86B0E5D4->unk_04.unk_4C = 8;
    D_86B0E5D4->unk_04.unk_50 = 0;
    D_86B0E5D4->unk_04.unk_48 = 0;
}

s32 Diorama_UpdateStateMachine(void) {
    if (((gPlayer1Controller->buttonPressed & 0x1000) || (gPlayer1Controller->buttonPressed & 0x8000) ||
         (gPlayer1Controller->buttonPressed & 0x4000)) &&
        (D_86B0E5D4->unk_04.unk_48 == 0)) {
        if ((D_86B0E5D4->unk_04.unk_4C != 8) && (D_86B0E5D4->unk_04.unk_4C != 5)) {
            D_86B0E5D4->unk_04.unk_48 = 1;
            Audio_FadeOutAll(0xA);
            D_86B0EBB0 = 0;
            D_86B0EBB4 = 2;
        }
    }

    if (D_86B0E5D4->unk_04.unk_48 == 1) {
        D_86B0EBB0 = Math_StepToS32(D_86B0EBB0, 0xFF, 0x1E, 0x1E);
        if (D_86B0EBB0 == 0xFF) {
            return 1;
        }
    }

    switch (D_86B0E5D4->unk_04.unk_4C) {
        case 5:
            if (D_86B0E5D4->unk_04.unk_48 == 1) {
                return 1;
            }

            if (D_86B0E5D4->unk_04.unk_44 == 4) {
                D_86B0E5D4->unk_04.unk_50 = 0;
                D_86B0EBB4 = 1;
                return 1;
            }

            D_86B0E5D4->unk_04.unk_44++;
            Diorama_SetGroupCamera(D_86B0E5D4->unk_04.unk_44);
            Diorama_SwitchModelGroup(D_86B0E5D4->unk_04.unk_44);
            D_86B0E5D4->unk_04.unk_4C = 6;
            D_86B0E5D4->unk_04.unk_50 = 0;
            break;

        case 6:
            if (D_86B0E5D4->unk_04.unk_50++ >= 4) {
                StageContext_SetClearColor(1);
                StageFade_StartFromOpaque(0x20);
                D_86B0E5D4->unk_04.unk_4C = 7;
                if ((D_86B0E5D4->unk_04.unk_44 == 0) || (D_86B0E5D4->unk_04.unk_44 == 1)) {
                    Diorama_UpdateCameraKeyframe(&D_86B0E5D4->unk_04, D_86B0E5D4);
                }
            }
            break;

        case 7:
            if (D_86B0E5D4->unk_04.unk_44 == 4) {
                if (ModelAnim_IsAnimationDone(&D_86B0E5F0[0].unk_004) != 0) {
                    Diorama_FinishSequence();
                }
            } else {
                if (D_86B0E5D4->unk_04.unk_44 >= 2) {
                    if (Diorama_SlideModelsForward(D_86B0E5D4->unk_04.unk_44) != 0) {
                        Diorama_BeginGroupTransition();
                    }
                } else if (D_86B0E5D4->unk_04.unk_6C < D_86B0E5D4->unk_04.unk_30) {
                    Diorama_BeginGroupTransition();
                }

                if ((D_86B0E5D4->unk_04.unk_44 == 0) || (D_86B0E5D4->unk_04.unk_44 == 1)) {
                    Diorama_UpdateCameraKeyframe(&D_86B0E5D4->unk_04, D_86B0E5D4);
                }

                Diorama_UpdateProximityHighlight(D_86B0E5D4->unk_04.unk_44);
            }
            break;

        case 8:
            if (D_86B0E5D4->unk_04.unk_50++ >= 0xB) {
                D_86B0E5D4->unk_04.unk_44 = 0;
                Diorama_SetGroupCamera(D_86B0E5D4->unk_04.unk_44);
                D_86B0E5D4->unk_04.unk_4C = 6;
                D_86B0E5D4->unk_04.unk_50 = 0;
                Diorama_LoadModelGroup(D_86B0E5D4->unk_04.unk_44);
                Audio_StartMusicTrack(0x29);
            }
            break;

        case 9:
            if (D_86B0E5D4->unk_04.unk_50++ >= 3) {
                D_86B0E5D4->unk_04.unk_4C = 5;
                D_86B0E5D4->unk_04.unk_50 = 0;
            }
            break;

        default:
            if (D_86B0E5D4->unk_04.unk_44 != 4) {
                if (D_86B0E5D4->unk_04.unk_44 >= 2) {
                    Diorama_SlideModelsForward(D_86B0E5D4->unk_04.unk_44);
                } else {
                    Diorama_UpdateCameraKeyframe(&D_86B0E5D4->unk_04, D_86B0E5D4);
                }
            }

            if (D_86B0E5D4->unk_04.unk_50++ >= 0xE) {
                D_86B0E5D4->unk_04.unk_4C = 5;
                D_86B0E5D4->unk_04.unk_50 = 0;
            }
            break;
    }

    return 0;
}

void func_86B01004(void) {
}

void Diorama_RenderFrame(void) {
    BgStage_DrawFrame();
    GfxImage_FillCurrent(&gDisplayListHead, 1);
    GeoRender_AdvanceFrameCounter();
    Diorama_DrawGroupTransitionOverlay();
    Diorama_DrawEndBackgroundTiles(D_86B0E5E8);
    Geo_RenderRootNode(D_86B0E5D0);
    Diorama_DrawFadeOverlay();
    Diorama_DrawEndCaption();
    BgStage_AdvanceFrame();
}

void Diorama_RunLoop(void) {
    s32 var_s1 = 1;
    s32 var_s0 = 0;

    while (var_s1 != 0) {
        Diorama_ReadControllerInput();
        Particle_UpdateFrameCounters();

        if (Diorama_UpdateStateMachine() != 0) {
            var_s1 = 0;
        }

        var_s0++;
        if (var_s0 == 0x50) {
            var_s0 = 0;
        }

        Diorama_LoopIdleAnimations();
        Diorama_RenderFrame();
    }
}

void Diorama_RenderFinalFrame(void) {
    Diorama_RenderFrame();
}

void Diorama_InitScene(void) {
    MemoryBlock* sp1C;

    sp1C = MainPool_AllocState(main_pool_get_available(), 0);
    D_86B0E5D0 = process_geo_layout(sp1C, &D_86B0BBF8);

    MainPool_FinalizeAllocation(sp1C);
    ModelRenderer_InitDisplayRoots();
    PokeIcon_OpenModelArchives();
    Diorama_InitSceneState();

    D_86B0EBB0 = 0;
    D_86B0E5DC = 0;
}

s32 Stage_ShowBootDiorama(void) {
    main_pool_push_state('MINI');

    Font_Init(6, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    FRAGMENT_LOAD(fragment31);
    Fragment_Load((((u32)D_8D000000 & 0x0FF00000) >> 0x14) - 0x10, _5C7A70_ROM_START, _5C7A70_ROM_END);

    Save_EnsureBankLoaded(2);
    Save_GetModeSettings(&D_86B0EBB8, 0);
    D_86B0E5E4 = ASSET_LOAD2(backgrounds, 1, 1);

    if (D_86B0EBB8 == 0x1F8) {
        D_86B0E5E8 = BinArchive_GetFile(D_86B0E5E4, 0x11);
    } else {
        D_86B0E5E8 = BinArchive_GetFile(D_86B0E5E4, 0);
    }

    Text_InitStringTables();
    D_86B0E5E0 = Text_GetStringTable(0x14);
    Diorama_InitScene();
    StageLoader_UpdateSegments();
    Diorama_RunLoop();
    Diorama_RenderFinalFrame();
    StageLoader_WaitForRetrace();
    Font_Free();

    main_pool_pop_state('MINI');

    return D_86B0EBB4;
}
