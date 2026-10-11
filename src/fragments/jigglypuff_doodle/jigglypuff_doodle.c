#include "jigglypuff_doodle.h"
#include "include/math.h"
#include "src/geo_render.h"
#include "src/model_animation_events.h"
#include "src/geo_layout.h"
#include "src/display_object_textures.h"
#include "src/model_renderer.h"
#include "src/graphics_textures.h"
#include "src/input.h"
#include "src/ui_graphics.h"
#include "src/gallery.h"
#include "src/jpeg_stream.h"
#include "src/gfx_buffer.h"
#include "src/gfx_rect.h"
#include "src/matrix.h"
#include "src/controller.h"
#include "src/fragments/widget_toolkit/widget_toolkit.h"
#include "src/fragments/minigame_shared_graphics/minigame_shared_graphics.h"
#include "src/memory.h"
#include "src/stage_loader.h"

// プリンのらくがき
static char D_86301600[] = {
    0xA5, 0xD7, 0xA5, 0xEA, 0xA5, 0xF3, 0xA4, 0xCE, 0xA4, 0xE9,
    0xA4, 0xAF, 0xA4, 0xAC, 0xA4, 0xAD, 0x00, 0x00, 0x00, 0x00,
};

// ３Ｄスティックでジャンプして
static char D_86301614[] = {
    0xA3, 0xB3, 0xA3, 0xC4, 0xA5, 0xB9, 0xA5, 0xC6, 0xA5, 0xA3, 0xA5, 0xC3, 0xA5, 0xAF, 0xA4, 0xC7,
    0xA5, 0xB8, 0xA5, 0xE3, 0xA5, 0xF3, 0xA5, 0xD7, 0xA4, 0xB7, 0xA4, 0xC6, 0x00, 0x00, 0x00, 0x00,
};

// Ａボタンでらくがきしよう。
static char D_86301634[] = {
    0xA3, 0xC1, 0xA5, 0xDC, 0xA5, 0xBF, 0xA5, 0xF3, 0xA4, 0xC7, 0xA4, 0xE9, 0xA4, 0xAF,
    0xA4, 0xAC, 0xA4, 0xAD, 0xA4, 0xB7, 0xA4, 0xE8, 0xA4, 0xA6, 0xA1, 0xA3, 0x00, 0x00,
};

static u32 D_86301650[] = {
    0x0C00FFFF, 0x05000000, 0x0B00001E, 0x00000000, 0x014000F0, 0x0000000F, 0x00000000, 0x00000000, 0x05000000,
    0x0D000000, 0x05000000, 0x0F000002, 0x14000000, 0x002B0012, 0xFFFFFF32, 0x16FFFFFF, 0x0F000003, 0x05000000,
    0x0A000000, 0x800AC840, 0x06000000, 0x06000000, 0x06000000, 0x06000000, 0x01000000,
};

typedef struct unk_D_86301730 {
    /* 0x000 */ s16 unk_000;
    /* 0x002 */ s16 unk_002;
    /* 0x004 */ DisplayObject unk_004;
    /* 0x16C */ Vec3f unk_16C;
    /* 0x178 */ s8 unk_178;
    /* 0x179 */ s8 unk_179;
    /* 0x17A */ s8 unk_17A;
    /* 0x17B */ s8 unk_17B;
    /* 0x17C */ u16 unk_17C;
    /* 0x17E */ char pad17E[6];
} unk_D_86301730; // size = 0x184

static unk_D_86002F30* D_86301710;
static unk_D_86002F34* D_86301714;
static unk_D_86002F34_00C* D_86301718;
static s16 D_8630171C;
static s16 D_8630171E;
static s16 D_86301720;
static u16 D_86301722;
static s32 D_86301724;
static FontContext* D_86301728;
static unk_D_86301730 D_86301730[4];
static u32 D_86301D40;
static unk_D_86301730* D_86301D44;
static DisplayObject* D_86301D48;
static s16 D_86301D4C;
static s16 D_86301D4E;
static s16 D_86301D50[4];
static DisplayObject D_86301D58;

void JigglypuffGame_SnapshotInputs(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_86301730[i].unk_17A = D_86301730[i].unk_178;
        D_86301730[i].unk_17B = D_86301730[i].unk_179;
    }

    D_86301730[0].unk_17C = gPlayer1Controller->buttonPressed;
    D_86301730[0].unk_178 = gPlayer1Controller->rawStickX;
    D_86301730[0].unk_179 = gPlayer1Controller->rawStickY;

    D_86301730[1].unk_17C = gPlayer2Controller->buttonPressed;
    D_86301730[1].unk_178 = gPlayer2Controller->rawStickX;
    D_86301730[1].unk_179 = gPlayer2Controller->rawStickY;

    D_86301730[2].unk_17C = gPlayer3Controller->buttonPressed;
    D_86301730[2].unk_178 = gPlayer3Controller->rawStickX;
    D_86301730[2].unk_179 = gPlayer3Controller->rawStickY;

    D_86301730[3].unk_17C = gPlayer4Controller->buttonPressed;
    D_86301730[3].unk_178 = gPlayer4Controller->rawStickX;
    D_86301730[3].unk_179 = gPlayer4Controller->rawStickY;
}

void JigglypuffGame_ReadInputs(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    Input_ResetRepeatState();
    JigglypuffGame_SnapshotInputs();
}

void JigglypuffGame_InitCamera(void) {
    D_86301718 = D_86301714->node.children;

    D_8630171C = 0x600;
    D_8630171E = 0;
    D_86301720 = 0x15E;

    D_86301718->unk_24.near = 100.0f;
    D_86301718->unk_24.far = 12800.0f;
    D_86301718->unk_24.fovy = 30.0f;

    D_86301718->unk_60.at.x = 0.0f;
    D_86301718->unk_60.at.y = 70.0f;
    D_86301718->unk_60.at.z = 0.0f;

    Camera_ComputeEyeFromAngles(&D_86301718->unk_60.at, &D_86301718->unk_60.eye, D_86301720, D_8630171C, D_8630171E);
}

void JigglypuffGame_UpdateEffects(void) {
}

void JigglypuffGame_DrawHud(s32 arg0) {
    s32 i;
    u8 sp40[] = {
        0,
        0,
        30,
    };
    u8 sp3C[] = {
        0,
        0,
        150,
    };

    if (arg0 == 0) {
        Ui_DrawGradientPanel(0x3A, 0x37, 0xC8, 0x64, sp40, sp3C);
    } else {
        Ui_DrawGradientPanel(0x5A, 0xD7, 0x96, 0x12, sp40, sp3C);
    }

    Font_BeginTranslucentTextRendering();

    switch (arg0) {
        case 0:
            Font_EnableTwoCycleTexturing();
            Font_SetActive(4, -2);
            Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
            Gfx_SetPrimColor(0xC8, 0xC8, 0x64, 0xFF);
            Font_Printf(0xA0 - (Text_MeasureStringWidth(D_86301728, D_86301600) / 2), 0x46, D_86301600);
            Font_SetActive(2, -2);
            Font_Printf(0xA0 - (Text_MeasureStringWidth(D_86301728, (char*)D_87A01110) / 2), 0x5A, (char*)D_87A01110);
            Font_Printf(0xA0 - (Text_MeasureStringWidth(D_86301728, D_86301614) / 2), 0x6E, D_86301614);
            Font_Printf(0xA0 - (Text_MeasureStringWidth(D_86301728, D_86301634) / 2), 0x7D, D_86301634);

            if (D_86301722 & 0x10) {
                Font_SetActive(4, -2);
                Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
                Gfx_SetPrimColor(5, 5, 0xFF, 0xFF);
                Font_Printf(0xA0 - (Text_MeasureStringWidth(D_86301728, "PUSH START") / 2), 0xAA, "PUSH START");
            }

            Font_DisableTwoCycleTexturing();

            for (i = 0; i < 4; i++) {
                D_86301D44 = &D_86301730[i];

                Font_SetActive(2, -2);
                Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xC8);
                Font_Printf(30 + (i * 0x46), 0xDA, "LV%02d", D_86301D44->unk_002);
            }
            break;

        default:
        case 2:
            Font_SetActive(2, -2);
            Gfx_SetEnvColor(0xFF, 0xFF, 5, 0xFA);
            Font_Printf(0x64, 0xD9, "TIME %02d:%02d.%02d", (D_86301D40 * 2) / 3600, ((D_86301D40 * 2) / 60) % 60,
                          (((D_86301D40 * 2) % 60) * 0x64) / 60);

            if ((D_86301D4C == 1) && ((D_86301D4E % 30) >= 0xF)) {
                Font_SetActive(0x20, -2);
                Gfx_SetEnvColor(0xFF, 5, 5, 0xFA);
                Font_Printf(0x96, 0x14, "%d", (D_86301D4E / 30) + 1);
            }

            if ((D_86301D40 != 0) && (D_86301D40 < 0xF)) {
                Font_SetActive(0x20, -2);
                Gfx_SetEnvColor(0xFF, 0xFF, 5, 0xFA);
                Font_Printf(0x78, 0x14, "GO!");
            }
            break;
    }

    Font_EndTexturedTextRendering();
}

void JigglypuffGame_DrawFrame(s32 arg0) {
    BgStage_DrawFrame();
    GfxImage_FillCurrent(&gDisplayListHead, 0x53D);
    GfxImage_ClearDepthRectangle(&gDisplayListHead, 0, 0, 0x140, 0xF0);
    GeoRender_AdvanceFrameCounter();
    Geo_RenderRootNode(D_86301714);
    JigglypuffGame_DrawHud(arg0);
    Widget_PauseMenuUpdate();
    BgStage_AdvanceFrame();
    D_86301722++;
}

s32 JigglypuffGame_WaitForStart(void) {
    s32 i;
    s32 var_s5;

    StageFade_StartFromOpaque(0x10);

    for (i = 0; i < 4; i++) {
        D_86301D44 = &D_86301730[i];
        D_86301D48 = &D_86301D44->unk_004;

        ModelAnim_SetAnimation(D_86301D48, 1);

        D_86301D48->transformAnim.speedFixed = 0x10000;
        D_86301D48->transformAnim.frameFixed = Rand_Range(0x14) << 0x10;

        D_86301D50[i] = 0;
    }

    var_s5 = 1;
    D_86301724 = 0;

    while (var_s5 == 1) {
        JigglypuffGame_ReadInputs();

        for (i = 0; i < 4; i++) {
            D_86301D44 = &D_86301730[i];

            if (D_86301D44->unk_17C & 1) {
                return -1;
            }

            if (D_86301D44->unk_17C & 0x1000) {
                var_s5 = 0;
            }
        }

        for (i = 0; i < 4; i++) {
            JigglypuffGame_UpdatePlayerPhysics(i);
        }

        JigglypuffGame_DrawFrame(D_86301724);
    }

    return 0;
}

void JigglypuffGame_ReadyCountdown(void) {
    s32 i;

    StageFade_StartFromOpaque(0x10);

    for (i = 0; i < 4; i++) {
        D_86301D44 = &D_86301730[i];
        D_86301D48 = &D_86301D44->unk_004;

        ModelAnim_SetAnimation(D_86301D48, 1);

        D_86301D48->transformAnim.speedFixed = 0x10000;
        D_86301D48->transformAnim.frameFixed = Rand_Range(0x14) << 0x10;

        D_86301D50[i] = 0;
    }

    D_86301D4C = 1;
    D_86301D4E = 0x5A;
    D_86301724 = 1;

    while (D_86301D4C == 1) {
        if (D_86301D4E > 0) {
            D_86301D4E--;
        } else {
            D_86301D4C = 0;
        }

        JigglypuffGame_ReadInputs();

        for (i = 0; i < 4; i++) {
            JigglypuffGame_UpdatePlayerPhysics(i);
        }

        JigglypuffGame_DrawFrame(D_86301724);
    }
}

void JigglypuffGame_ApplySeparationForce(s32 arg0) {
    s32 i;
    UNUSED s32 pad[2];
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 var_fs4;
    f32 var_fs5;
    UNUSED s32 pad2[11];
    f32 sp60;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 temp1;
    f32 temp2;
    f32 temp3;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;

    spA0 = D_86301D48->position.x;
    sp9C = D_86301D48->position.y;
    sp98 = D_86301D48->position.z;

    var_fs4 = 0.0f;
    var_fs5 = 0.0f;
    sp60 = 0.0f;

    for (i = 0; i < 4; i++) {
        if (i != arg0) {
            temp_fs0 = D_86301730[i].unk_004.position.x;
            temp_fs1 = D_86301730[i].unk_004.position.y;
            temp_fs2 = D_86301730[i].unk_004.position.z;

            temp1 = temp_fs0 - spA0;
            temp2 = temp_fs1 - sp9C;
            temp3 = temp_fs2 - sp98;

            temp_fv0 = sqrtf(SQ(temp1) + SQ(temp2) + SQ(temp3));
            if ((temp_fv0 < 32.0f) && (temp_fv0 > 0.0f)) {
                temp_fv1 = 32.0f - temp_fv0;

                var_fs4 += (-temp1 / temp_fv0) * temp_fv1;
                var_fs5 += (-temp2 / temp_fv0) * temp_fv1;
                sp60 += (-temp3 / temp_fv0) * temp_fv1;
            }
        }
    }

    temp_fs0 = D_86301D58.position.x;
    temp_fs1 = D_86301D58.position.y;
    temp_fs2 = D_86301D58.position.z;

    temp1 = temp_fs0 - spA0;
    temp2 = temp_fs1 - sp9C;
    temp3 = temp_fs2 - sp98;

    temp_fv0 = sqrtf(SQ(temp1) + SQ(temp2) + SQ(temp3));
    if ((temp_fv0 < 40.0f) && (temp_fv0 > 0.0f)) {
        temp_fv1 = 40.0f - temp_fv0;

        var_fs4 += (-temp1 / temp_fv0) * temp_fv1;
        var_fs5 += (-temp2 / temp_fv0) * temp_fv1;
        sp60 += (-temp3 / temp_fv0) * temp_fv1;
    }

    D_86301D48->position.x += var_fs4;
    D_86301D48->position.y += var_fs5;
    D_86301D48->position.z += sp60;
}

void JigglypuffGame_UpdatePlayerPhysics(s32 arg0) {
    s32 temp_a0;
    s32 temp_a2;

    D_86301D44 = &D_86301730[arg0];
    D_86301D48 = &D_86301D44->unk_004;

    switch (D_86301D44->unk_000) {
        case 1:
            break;

        case 0:
            D_86301D48->scale.y = ((D_86301D44->unk_179 + 256.0f) * 0.00390625f) + 0.2f;
            D_86301D48->rotation.y = D_86301D44->unk_178 << 8;

            D_86301D44->unk_16C.x = 0.0f;
            D_86301D44->unk_16C.y = 0.0f;

            temp_a2 = D_86301D44->unk_178 - D_86301D44->unk_17A;
            temp_a0 = D_86301D44->unk_179 - D_86301D44->unk_17B;

            if (temp_a0 > 10) {
                D_86301D44->unk_000 = 1;
                D_86301D44->unk_16C.y = temp_a0 * 0.2f;

                if (D_86301D44->unk_16C.y > 15.0f) {
                    D_86301D44->unk_16C.y = 15.0f;
                }

                D_86301D44->unk_16C.x = temp_a2 * 0.1f;
            } else if (Math_AbsF32(D_86301D44->unk_178) > 50.0f) {
                D_86301D44->unk_000 = 1;
                D_86301D44->unk_16C.y = 2.0f;
                D_86301D44->unk_16C.x = D_86301D44->unk_178 * 0.05f;
            }
            break;
    }

    JigglypuffGame_ApplySeparationForce(arg0);

    D_86301D48->position.x += D_86301D44->unk_16C.x;
    D_86301D48->position.y += D_86301D44->unk_16C.y;

    if (D_86301D48->position.y > 0.0f) {
        D_86301D44->unk_16C.y -= 1.0f;
    }

    if (D_86301D48->position.y < 0.0f) {
        D_86301D48->position.y = 0.0f;
        D_86301D44->unk_000 = 0;
    }

    if (D_86301D48->position.x < -100.0f) {
        D_86301D48->position.x = -100.0f;
        D_86301D44->unk_16C.x *= -1.0f;
    }

    if (D_86301D48->position.x > 100.0f) {
        D_86301D48->position.x = 100.0f;
        D_86301D44->unk_16C.x *= -1.0f;
    }

    if (Rand_Range(0x64) == 0) {
        ModelAnim_ClearEventTrack(D_86301D48);
        ModelAnim_SetEventTrack(D_86301D48, 3);
    }
}

void func_86300F60(void) {
}

void JigglypuffGame_PlayingLoop(void) {
    s32 i;
    s32 var_s6 = 1;

    for (i = 0; i < 4; i++) {
        D_86301D44 = &D_86301730[i];
        D_86301D48 = &D_86301D44->unk_004;

        ModelAnim_SetAnimation(D_86301D48, 1);

        D_86301D48->transformAnim.speedFixed = 0x10000;

        D_86301D50[i] = 0;
    }

    D_86301D40 = 0;
    D_86301724 = 2;

    while (var_s6 != 0) {
        JigglypuffGame_ReadInputs();
        JigglypuffGame_UpdateEffects();

        if (gPlayer1Controller->buttonPressed & 0x1000) {
            var_s6 = 0;
        }

        for (i = 0; i < 4; i++) {
            JigglypuffGame_UpdatePlayerPhysics(i);
        }

        D_86301D40++;
        JigglypuffGame_DrawFrame(D_86301724);
    }
}

void JigglypuffGame_ShowWinnerSequence(void) {
    s32 i;
    s32 j;
    int var = -1;

    for (i = 0; i < 4; i++) {
        D_86301D48 = &D_86301730[i].unk_004;

        if (i == var) {
            ModelAnim_SetAnimation(D_86301D48, 2);
            ModelAnim_SetEventTrack(D_86301D48, 6);
        } else {
            ModelAnim_SetAnimation(D_86301D48, 5);
            ModelAnim_SetEventTrack(D_86301D48, 7);
        }
    }

    D_86301724 = 3;

    for (j = 0; j < 0x5A; j++) {
        JigglypuffGame_ReadInputs();
        JigglypuffGame_DrawFrame(D_86301724);
    }
}

void JigglypuffGame_FadeOutLoop(void) {
    s32 i;

    StageFade_StartFromTransparent(30);

    for (i = 0; i < 30; i++) {
        JigglypuffGame_ReadInputs();
        JigglypuffGame_DrawFrame(D_86301724);
    }
}

void JigglypuffGame_WaitForExit(void) {
    D_86301724 = 4;
    Widget_PauseMenuTrigger(1);

    while (D_8780FC96 == 0) {
        JigglypuffGame_ReadInputs();
        JigglypuffGame_DrawFrame(D_86301724);
    }
}

void JigglypuffGame_Init(void) {
    s32 i;
    MemoryBlock* temp_v0 = MainPool_AllocState(main_pool_get_available(), 0);

    D_86301714 = process_geo_layout(temp_v0, &D_86301650);
    MainPool_FinalizeAllocation(temp_v0);
    ModelRenderer_InitDisplayRoots();
    PokeIcon_OpenModelArchives();
    D_86301710 = Model_LoadByArchiveIndex(0x27);

    for (i = 0; i < 4; i++) {
        D_86301D44 = &D_86301730[i];
        D_86301D48 = &D_86301D44->unk_004;

        ModelRenderer_AttachDisplayObject(D_86301D48);
        Model_InitDisplayObject(D_86301D48, 0, 0x27, D_86301710->unk_08->unk_00[0]);

        D_86301D48->position.x = (i - 1.5f) * 50.0f;
        D_86301D48->position.y = 0.0f;
        D_86301D48->position.z = 0.0f;

        D_86301D48->scale.x = 1.2f;
        D_86301D48->scale.y = 1.2f;
        D_86301D48->scale.z = 1.2f;

        D_86301D44->unk_16C.y = 0.0f;

        ModelAnim_SetAnimation(D_86301D48, 2);
        ModelAnim_ClearEventTrack(D_86301D48);

        D_86301D48->transformAnim.frameFixed = Rand_Range(5) << 0x10;
    }

    PokeIcon_OpenModelArchives();
    D_86301710 = Model_LoadByArchiveIndex(0x9A);
    D_86301D48 = &D_86301D58;

    ModelRenderer_AttachDisplayObject(D_86301D48);
    Model_InitDisplayObject(D_86301D48, 0, 0x9A, D_86301710->unk_08->unk_00[0]);

    D_86301D48->position.x = 0.0f;
    D_86301D48->position.y = 0.0f;
    D_86301D48->position.z = 0.0f;

    D_86301D48->scale.x = 8.0f;
    D_86301D48->scale.y = 8.0f;
    D_86301D48->scale.z = 8.0f;

    D_86301D48->rotation.y = 0;

    ModelAnim_SetAnimation(D_86301D48, 0);
    ModelAnim_ClearEventTrack(D_86301D48);
    D_86301D48->transformAnim.speedFixed = 0;
    JigglypuffGame_InitCamera();
}

void Minigame_JigglypuffDoodle(UNUSED s32 arg0, UNUSED s32 arg1) {
    unk_func_80007444* sp24;

    main_pool_push_state('MINI');

    Gfx_InitDisplayListBuffers(0x10000, 0);
    sp24 = StageContext_Allocate(0, 1, 3, 1, 2, 1);
    D_86301728 = Font_Init(0x26, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    FRAGMENT_LOAD(fragment31);

    Fragment_Load((((u32)&D_8D000000 & 0x0FF00000) >> 0x14) - 0x10, _5C7A70_ROM_START, _5C7A70_ROM_END);

    JigglypuffGame_Init();
    Widget_PauseMenuInit();
    StageContext_Activate(sp24);

    if (JigglypuffGame_WaitForStart() != -1) {
        JigglypuffGame_ReadyCountdown();
        JigglypuffGame_PlayingLoop();
        JigglypuffGame_ShowWinnerSequence();
        JigglypuffGame_WaitForExit();
    }

    JigglypuffGame_FadeOutLoop();
    StageContext_Deactivate();
    Font_Free();
    Gfx_FreeDisplayListBuffers();

    main_pool_pop_state('MINI');

    Widget_PauseMenuGetResult();
}

void func_863015EC(void) {
}
