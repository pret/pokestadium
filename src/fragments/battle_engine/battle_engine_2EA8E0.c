#include "battle_engine.h"
#include "src/geo_node.h"
#include "src/geo_render.h"
#include "src/display_object_textures.h"
#include "src/model_renderer.h"
#include "src/graphics_textures.h"
#include "src/input.h"
#include "src/battle_hud.h"
#include "src/3D140.h"
#include "src/jpeg_stream.h"
#include "src/audio_loop_point.h"
#include "src/gfx_buffer.h"
#include "src/matrix.h"
#include "src/controller.h"
#include "src/geo_layout.h"
#include "src/memmap.h"
#include "src/memory.h"

static unk_D_86002F34_00C D_8438E440;
static unk_D_8690A610 D_8438E530;
static GraphNode D_8438E550;
static GraphNode D_8438E568;
static GraphNode D_8438E580;
static unk_D_86002F34_00C D_8438E598;
static unk_D_86002F34_00C D_8438E688;
u8* D_8438E778;
u8* D_8438E77C;
static void* D_8438E780;
static GraphNode* D_8438E784;
static GraphNode* D_8438E788;
static GraphNode* D_8438E78C;
static unk_D_80068BB0* D_8438E790;
static unk_D_80068BB0* D_8438E794;
static BattleSessionTeams* D_8438E798;
static s32 D_8438E79C;
static s32 D_8438E7A0;
static Color_RGBA8_u32 D_8438E7A4;
static f32 D_8438E7A8;
static s32 D_8438E7AC;

static u8 D_84384350[] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x11, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
};
static u32 D_84384364[] = {
    0x0C00FFFF,  0x05000000,  0x07000000,    &D_8438E440,   0x05000000, 0x0D000000,    0x05000000,  0x07000000,
    &D_8438E530, 0x14000000,  0x002D0019,    0xFFFFFF28,    0x08000000, Battle_StageLightAngleCallbackA, 0x00000000,  0x14000000,
    0x002D0019,  0x80808028,  0x08000000,    Battle_StageLightAngleCallbackB, 0x00000000, 0x16646464,    0x0F000002,  0x05000000,
    0x1F00FFFF,  0x00000000,  0x00000000,    0x00000000,    0x00640064, 0x00640000,    0x08000000,  Battle_StageMaterialTintCallback,
    0x00000000,  0x05000000,  0x07000000,    &D_8438E550,   0x06000000, 0x06000000,    0x0F000003,  0x05000000,
    0x1F00FFFF,  0x00000000,  0x00000000,    0x00000000,    0x00640064, 0x00640000,    0x08000000,  Battle_StageMaterialTintCallback,
    0x00000000,  0x05000000,  0x07000000,    &D_8438E568,   0x06000000, 0x06000000,    0x0F000002,  0x05000000,
    0x1F00FFFF,  0x00000000,  0x00000000,    0x00000000,    0x00640064, 0x00640000,    0x08000000,  Battle_StageMaterialTintCallback,
    0x00000000,  0x05000000,  0x07000000,    &D_8438E580,   0x06000000, 0x06000000,    0x0F000003,  0x05000000,
    0x0A000000,  &D_800AC840, 0x06000000,    0x0F000002,    0x05000000, 0x0A000000,    &D_800AC858, 0x06000000,
    0x09000000,  0x08000000,  Battle_StageGeoDispatchCallback, 0x00000000,    0x06000000, 0x06000000,    0x06000000,  0x01000000,
};
static u32 D_843844C4[] = {
    0x0C00FFFF,  0x05000000, 0x07000000, &D_8438E598, 0x05000000, 0x0D000001, 0x05000000,
    0x14000000,  0x002D0019, 0xFFFFFF28, 0x16FFFFFF,  0x0F000003, 0x05000000, 0x0A000000,
    &D_800AC840, 0x06000000, 0x06000000, 0x06000000,  0x06000000, 0x01000000,
};
static u32 D_84384514[] = {
    0x0C00FFFF,  0x05000000, 0x07000000, &D_8438E688, 0x05000000, 0x0D000002, 0x05000000,
    0x14000000,  0x002D0019, 0xFFFFFF28, 0x16FFFFFF,  0x0F000003, 0x05000000, 0x0A000000,
    &D_800AC840, 0x06000000, 0x06000000, 0x06000000,  0x06000000, 0x01000000,
};

s32 Battle_StageGeoDispatchCallback(s32 arg0, GraphNode* arg1) {
    if (arg0 == 2) {
        BattleAnim_DispatchPresentation(5, &D_8438E440);
    }
    return 0;
}

s32 Battle_StageLightAngleCallbackA(s32 arg0, unk_D_86002F34_alt18* arg1) {
    UNUSED s32 pad;
    f32 sp28;
    s16 sp26;
    s16 sp24;

    if (arg0 == 2) {
        Vec3f_CalculateDistanceAngles(&D_8006F088->unk_60.at, &D_8006F088->unk_60.eye, &sp28, &sp26, &sp24);
        arg1->unk_1C = sp26 + 0x2000;
        arg1->unk_1E = sp24 - 0x2000;
    }
    return 0;
}

s32 Battle_StageLightAngleCallbackB(s32 arg0, unk_D_86002F34_alt18* arg1) {
    UNUSED s32 pad;
    f32 sp28;
    s16 sp26;
    s16 sp24;

    if (arg0 == 2) {
        Vec3f_CalculateDistanceAngles(&D_8006F088->unk_60.at, &D_8006F088->unk_60.eye, &sp28, &sp26, &sp24);
        arg1->unk_1C = -0x2000 - sp26;
        arg1->unk_1E = sp24 + 0x6000;
    }
    return 0;
}

s32 Battle_StageMaterialTintCallback(s32 arg0, DisplayObject* arg1) {
    if (arg0 == 2) {
        Vec3f_SetComponentsDuplicate(&arg1->scale, D_8438E7A8, D_8438E7A8, D_8438E7A8);
        arg1->textureTint.rgba = D_8438E7A4.rgba;
    }
    return 0;
}

void Battle_SetStageTintColor(u8 arg0, u8 arg1, u8 arg2) {
    D_8438E7A4.r = arg0;
    D_8438E7A4.g = arg1;
    D_8438E7A4.b = arg2;

    if (((arg0 & arg1 & arg2) & 0xFF) == 0xFF) {
        if (D_8438E530.node.callbackArg == 1) {
            D_8438E530.node.flags |= 1;
        }
    } else {
        D_8438E530.node.flags &= ~1;
    }
}

void BattleScene_SetModelUniformScale(f32 arg0) {
    D_8438E7A8 = arg0;
}

u16 Battle_TintTexel16(u16 arg0) {
    s32 r;
    s32 g;
    s32 b;

    r = ((((((arg0 >> 11) & 0x1F) << 3) + (((arg0 >> 11) & 0x1F) >> 2)) * D_8438E7A4.r) / 255) >> 3;
    g = ((((((arg0 >> 6) & 0x1F) << 3) + (((arg0 >> 6) & 0x1F) >> 2)) * D_8438E7A4.g) / 255) >> 3;
    b = ((((((arg0 >> 1) & 0x1F) << 3) + (((arg0 >> 1) & 0x1F) >> 2)) * D_8438E7A4.b) / 255) >> 3;

    return (r << 11) | (g << 6) | (b << 1) | 1;
}

void Battle_DrawStageBackdrop(void) {
    s16 sp4E;
    s16 sp4C;
    s16 sp4A;
    s16 sp48;
    s16 sp46;
    s16 sp44;

    if ((u32)D_8438E780 == NULL) {
        GfxImage_ClearDepthRectangle(&gDisplayListHead, 0, 0, 0x140, 0xF0);
        return;
    }

    if ((u32)D_8438E780 == -1) {
        GfxImage_FillCurrent(&gDisplayListHead, 1);
        return;
    }

    if ((u32)D_8438E780 < 0x10000) {
        GfxImage_FillCurrent(&gDisplayListHead, Battle_TintTexel16(D_8438E780));
        return;
    }

    sp4E = D_8438E440.unk_18.x;
    sp4A = D_8438E440.unk_18.y;
    sp4C = D_8438E440.unk_18.width + sp4E;
    sp48 = (D_8438E440.unk_18.height / 2) + sp4A;
    sp46 = D_8438E440.unk_18.height + sp4A;
    sp44 = 0x10000 / (D_8438E440.unk_18.height / 2);

    if ((D_8438E440.unk_18.width < 0x140) || (D_8438E440.unk_18.height < 0xF0)) {
        GfxImage_FillCurrent(&gDisplayListHead, 1);
    } else {
        GfxImage_ClearDepthRectangle(&gDisplayListHead, 0, 0, 0x140, 0xF0);
    }

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetCombineMode(gDisplayListHead++, G_CC_MODULATEI_PRIM, G_CC_MODULATEI_PRIM);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, D_8438E7A4.r, D_8438E7A4.g, D_8438E7A4.b, 255);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);

    gDPLoadTextureBlock(gDisplayListHead++, Memmap_GetFragmentVaddr(D_8438E780), G_IM_FMT_RGBA, G_IM_SIZ_32b, 4, 64, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, sp4E << 2, sp4A << 2, sp4C << 2, sp48 << 2, G_TX_RENDERTILE, 0, 0, 0, sp44);
    gSPTextureRectangle(gDisplayListHead++, sp4E << 2, sp48 << 2, sp4C << 2, sp46 << 2, G_TX_RENDERTILE, 0, 0x07E0, 0,
                        0);
    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void Battle_RenderStageThumbnail(GraphNode* arg0, unk_D_80068BB0* arg1) {
    unk_D_86002F34_00C* sp2C = arg0->children;
    unk_D_86002F34_00C_018 sp20;

    if (sp2C->node.flags & 0x10) {
        sp20 = sp2C->unk_18;

        sp2C->unk_18.x = 0;
        sp2C->unk_18.y = 0;
        sp2C->unk_18.width = 0x4C;
        sp2C->unk_18.height = 0x4C;

        GfxImage_SetRenderTarget(&gDisplayListHead, arg1);
        GfxImage_FillCurrent(&gDisplayListHead, 0x10D);
        Geo_RenderRootNode(arg0);

        sp2C->node.flags &= ~0x10;

        sp2C->unk_18 = sp20;
    }
}

void Battle_DrawClippedTextureRect(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    unk_D_800A7440 sp38;
    u16 tmp5;
    u16 tmp6;

    GfxRect_SetBounds(&sp38, arg0, arg1, arg2, arg3);

    if (GfxRect_ClipToScissor(&sp38) != 0) {
        if (!arg2) {}

        tmp5 = ((sp38.x1 - arg0) << 5);
        tmp6 = ((sp38.y2 - arg1) << 5);

        tmp5 += 0x10;
        tmp6 += 0x10;

        gSPTextureRectangle(gDisplayListHead++, sp38.x1 << 2, sp38.y2 << 2, ((sp38.y1 + 1) ^ 0) << 2,
                            ((sp38.x2 + 1) ^ 0) << 2, G_TX_RENDERTILE, tmp5, tmp6, 0x0800, 0x0800);

        if ((arg2 && arg2) ^ 0) {}
    }
}

void Battle_DrawTexturedRectSegment(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8* arg4, s32 arg5) {
    gDPLoadTextureBlock(gDisplayListHead++, arg4, G_IM_FMT_RGBA, G_IM_SIZ_16b, arg5, (arg3 * 2) + 2, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    Battle_DrawClippedTextureRect(arg0, arg1, (arg0 + arg2) - 1, (arg1 + arg3) - 1);
}

void Battle_DrawFaintOrderMarker(GraphNode* arg0, unk_D_80068BB0* arg1) {
    s32 temp_s2;
    s32 temp_s3;
    unk_D_86002F34_00C* temp_v1 = arg0->children;
    unk_D_86002F34_00C_018* ptr = &arg0->children->unk_18;
    s32 img;

    temp_s2 = ptr->x;
    temp_s3 = ptr->y;

    temp_v1++;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_AVERAGE);

    img = arg1->img_p;
    Battle_DrawTexturedRectSegment(temp_s2, temp_s3, 0x25, 0xA, img, 0x4C);
    img = arg1->img_p + 0xBE0;
    Battle_DrawTexturedRectSegment(temp_s2, temp_s3 + 0xA, 0x25, 0xA, img, 0x4C);
    img = arg1->img_p + 0x17C0;
    Battle_DrawTexturedRectSegment(temp_s2, temp_s3 + 0x14, 0x25, 0xA, img, 0x4C);
    img = arg1->img_p + 0x23A0;
    Battle_DrawTexturedRectSegment(temp_s2, temp_s3 + 0x1E, 0x25, 7, img, 0x4C);

    gDPPipeSync(gDisplayListHead++);

    gDPSetTexturePersp(gDisplayListHead++, G_TP_PERSP);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
}

void func_84300D44(void) {
    s32 i;
    s32 j;
    s32 x;
    TeamRoster* temp_a2;
    BattleSessionTeams* ptr = &D_8438E798[0];

    for (i = 0; i < 2; i++, ptr++) {
        for (j = 0; j < ptr->unk_01; j++) {
            temp_a2 = ptr->unk_08[j];
            for (x = 0; x < temp_a2->unk_002; x++) {
                temp_a2->unk_01C[x].unk_25 = 0;
            }
        }
    }
}

void func_84300DC0(void) {
    s32 i;
    s32 j;
    s32 x;
    s32 var_v0 = 0;
    TeamRoster* temp_a3;
    BattleSessionTeams* ptr = &D_8438E798[0];

    for (i = 0; i < 2; i++, ptr++) {
        for (j = 0; j < ptr->unk_01; j++) {
            temp_a3 = ptr->unk_08[j];
            for (x = 0; x < temp_a3->unk_002; x++) {
                if ((temp_a3->unk_01C[x].unk_25 == 0) && (temp_a3->unk_01C[x].unk_02 == 0)) {
                    var_v0 = 1;
                    temp_a3->unk_01C[x].unk_25 = D_8438E7A0;
                }
            }
        }
    }

    if (var_v0 != 0) {
        D_8438E7A0 += 1;
    }
}

void func_84300E78(void) {
}

void func_84300E80(void) {
}

s32 BattleScene_UpdateFrame(s32 arg0) {
    s32 sp1C;

    GeoRender_AdvanceFrameCounter();
    ModelAnim_UpdateFrameChangeState();
    BattleScene_DispatchLifecycle(2, D_8438E798);
    BattleScene_DispatchOwnerCameraLifecycle(2, &D_8438E598, &D_8438E688);
    sp1C = BattleScene_Dispatch(2, &D_8438E440);
    BattleAnim_DispatchPresentation(2, &D_8438E440);
    Battle_RenderStageThumbnail(D_8438E788, D_8438E790);
    Battle_RenderStageThumbnail(D_8438E78C, D_8438E794);
    BgStage_DrawFrame();
    Battle_DrawStageBackdrop();
    Geo_RenderRootNode(D_8438E784);
    BattleScene_DispatchLifecycle(5, D_8438E798);
    Battle_DrawFaintOrderMarker(D_8438E788, D_8438E790);
    Battle_DrawFaintOrderMarker(D_8438E78C, D_8438E794);
    func_84300DC0();

    if (sp1C == 1) {
        D_8438E798[0].unk_1C = 1;
    }

    if (sp1C == 2) {
        D_8438E798[1].unk_1C = 1;
    }

    return sp1C;
}

s32 BattleScene_UpdatePausedFrame(s32 arg0) {
    s32 sp1C = 0;

    if ((arg0 == 0) && BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        sp1C = BattleScene_UpdateFrame(arg0);
    } else {
        ModelAnim_UpdateFrameChangeState();
        BgStage_DrawFrame();
        Battle_DrawStageBackdrop();
        Geo_RenderRootNode(D_8438E784);
        BattleScene_DispatchLifecycle(5, D_8438E798);
        Battle_DrawFaintOrderMarker(D_8438E788, D_8438E790);
        Battle_DrawFaintOrderMarker(D_8438E78C, D_8438E794);
    }

    if ((arg0 == 0) && BTN_IS_PRESSED(gPlayer1Controller, BTN_START)) {
        D_8438E79C = 0;
    }
    return sp1C;
}

void Battle_UpdateCompletionGate(void) {
    if (D_8438E7AC < 0) {
        D_8438E7AC++;
    } else if ((D_8438E7AC == 0) && (D_800AE540.unk_0000 == 0x10) && gPlayer1Controller->buttonPressed) {
        D_8438E7AC = 1;
    }
}

s32 Battle_FrameCallback(s32 arg0) {
    s32 sp1C = 0;

    Cont_StartReadInputs();
    Trainer_RequestPokeIcon(&D_8438E798[0]);
    PokeIcon_WaitFrameLoadForObject(&D_8438E798[0]);
    Trainer_RequestPokeIcon(&D_8438E798[1]);
    PokeIcon_WaitFrameLoadForObject(&D_8438E798[1]);
    Cont_ReadInputs();
    Input_ResetRepeatState();

    switch (D_8438E79C) {
        case 0:
            sp1C = BattleScene_UpdateFrame(arg0);
            break;

        case 1:
            sp1C = BattleScene_UpdatePausedFrame(arg0);
            break;
    }

    if ((sp1C != 0) && (D_8438E7AC <= 0)) {
        D_8438E7AC = 1;
    }

    Battle_UpdateCompletionGate();
    PokeIcon_RequestBackgroundForObject(&D_8438E798[0]);
    PokeIcon_RequestBackgroundForObject(&D_8438E798[1]);

    if ((arg0 != 2) && (D_8438E7AC == 1)) {
        D_8438E7AC = 2;
        func_8003DB84(0);
        if (D_800AE540.unk_0000 != 0x11) {
            Audio_FadeOutAll(0x1E);
        }
        return 1;
    }
    return 0;
}

void func_8430123C(u8* arg0, s32 arg1) {
    s32 i;
    s32 j;

    for (i = 0; i < 6; i++) {
        for (j = 0; j < arg1; j++) {
            if (i == arg0[j]) {
                break;
            }
        }

        if (j == arg1) {
            arg0[arg1++] = i;
        }
    }
}

void func_8430128C(void) {
    TeamRoster* temp_s0;
    TeamRoster* temp_s1;
    u8 sp48[8];
    TeamRoster* temp_s2;
    s32 i;
    s32 var_s1;

    temp_s1 = D_800AE540.unk_1194[0].unk_08[0];
    temp_s2 = D_800AE540.unk_1194[0].unk_08[1];
    temp_s0 = D_800AE540.unk_1194[1].unk_08[0];

    if (temp_s0->unk_000 & 2) {
        if (D_800AE540.unk_0000 == 0) {
            if (D_800AE540.unk_0001 == 0) {
                var_s1 = temp_s0->unk_214->unk_002;
            } else {
                var_s1 = 3;
            }
            func_843831A0(temp_s1, temp_s2, temp_s0, D_800AE540.unk_11EC, sp48, D_800AE540.unk_0001, var_s1);
        } else {
            if (D_800AE540.unk_0001 == 8) {
                var_s1 = temp_s0->unk_214->unk_002;
            } else {
                var_s1 = 3;
            }
            func_843831A0(temp_s1, NULL, temp_s0, temp_s0->unk_018 & 0xFF, sp48, D_800AE540.unk_0001, var_s1);
        }
        func_8430123C(sp48, var_s1);
        temp_s0->unk_002 = var_s1;

        for (i = 0; i < temp_s0->unk_214->unk_002; i++) {
            temp_s0->unk_01C[i] = temp_s0->unk_214->unk_028[sp48[i]];
        }
    }
}

void BattleScene_InitializeParticipantPresentation(BattleSessionTeams* arg0, unk_D_86002F30* arg1) {
    TeamRoster* temp_v0 = arg0->unk_08[0];

    arg0->unk_18 = arg1->unk_08->unk_00[0];
    arg0->unk_00 |= 0xA0;
    arg0->unk_1C = 0;
    arg0->unk_02 = temp_v0->unk_01C[0].unk_00.unk_00;
    arg0->unk_04 = temp_v0->unk_01C;
    Trainer_RequestPokeIcon(arg0);
}

void func_84301430(unk_func_80007444* arg0) {
    MemoryBlock* sp44;
    u32* temp_v0_4;
    FragmentEntry sp3C;
    unk_D_8690A610_018* temp_v0_7;
    s32 pad;
    s16 sp32;
    unk_D_80068BB0* sp2C;
    unk_D_86002F30* sp28;

    Battle_SetStageTintColor(0xFF, 0xFF, 0xFF);
    BattleScene_SetModelUniformScale(1.0f);

    if (D_800AE540.unk_0000 == 0x11) {
        Font_Init(4, 0);
    } else if (D_800AE540.unk_0000 == 0x10) {
        Font_Init(7, 0);
    } else {
        Font_Init(3, 0);
    }

    D_8438E798[0].unk_10 = PokeIcon_AllocFramebuffers(3);
    D_8438E798[1].unk_10 = PokeIcon_AllocFramebuffers(3);
    PokeIcon_OpenModelArchives();

    sp2C = main_pool_alloc(0x10, 0);
    GfxImage_Initialize(sp2C, 0, 2, 0x4C, 0x4C, arg0->unk_18[0]->depth_p->img_p);
    D_8438E790 = GfxImage_Allocate(0, 2, 0x4C, 0x4C, 0);
    D_8438E794 = GfxImage_Allocate(0, 2, 0x4C, 0x4C, 0);

    GfxImage_AttachDepthBuffer(D_8438E790, sp2C);
    GfxImage_AttachDepthBuffer(D_8438E794, sp2C);

    D_8438E778 = D_8438E790->img_p;
    D_8438E77C = D_8438E794->img_p;

    FRAGMENT_LOAD(fragment31);
    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_3000000, battle_ui, 0);

    if ((D_800AE540.unk_0000 == 0x10) || (D_800AE540.unk_0000 == 0xA)) {
        sp32 = D_84384350[D_800AE540.unk_0001];
        if (D_800AE540.unk_0001 == 7) {
            sp32 += D_800AE540.unk_0002;
        }
    } else {
        sp32 = D_84384350[D_800AE540.unk_0000];
        if (D_800AE540.unk_0000 == 7) {
            sp32 += D_800AE540.unk_0002;
        }
    }

    sp3C = BinArchive_GetFile(ASSET_LOAD2(stadium_models, 1, 1), sp32);
    D_8438E780 = sp3C(2, 0);

    sp28 = Model_LoadByArchiveIndex(0x9A);
    func_8430128C();
    BattleScene_InitializeParticipantPresentation(&D_8438E798[0], sp28);
    BattleScene_InitializeParticipantPresentation(&D_8438E798[1], sp28);

    func_84300D44();
    GeoNode_CreateCamera(NULL, &D_8438E440, 0, 0, 0x140, 0xF0);
    GeoNode_CreateCamera(NULL, &D_8438E598, 0x1E, 0x50, 0x4C, 0x4C);
    GeoNode_CreateCamera(NULL, &D_8438E688, 0xE2, 0x50, 0x4C, 0x4C);
    GeoNode_CreateFog(0, &D_8438E530, 0x3C0, 0x3E8, 0xFF, 0xFF, 0xFF, 0xFF);
    GeoNode_CreateContainer(NULL, &D_8438E550);
    GeoNode_CreateContainer(NULL, &D_8438E568);
    GeoNode_CreateContainer(NULL, &D_8438E580);
    GeoCamera_SetPerspective(&D_8438E440, 30.0f, 192.0f, 24576.0f);
    ModelRenderer_InitDisplayRoots();
    BattleScene_DispatchLifecycle(0, D_8438E798);
    BattleScene_DispatchOwnerCameraLifecycle(0, &D_8438E598, &D_8438E688);
    BattleScene_Dispatch(0, &D_8438E440);
    BattleAnim_DispatchPresentation(0, &D_8438E440);

    sp44 = MainPool_AllocState(main_pool_get_available(), 0);
    D_8438E784 = process_geo_layout(sp44, D_84384364);
    D_8438E788 = process_geo_layout(sp44, D_843844C4);
    D_8438E78C = process_geo_layout(sp44, D_84384514);

    temp_v0_4 = sp3C(0, 0);
    if (temp_v0_4 != NULL) {
        GraphNode_AppendChild(&D_8438E550, process_geo_layout(sp44, temp_v0_4));
    }

    temp_v0_4 = sp3C(1, 0);
    if (temp_v0_4 != NULL) {
        GraphNode_AppendChild(&D_8438E568, process_geo_layout(sp44, temp_v0_4));
    }

    temp_v0_4 = sp3C(3, 0);
    if (temp_v0_4 != NULL) {
        GraphNode_AppendChild(&D_8438E580, process_geo_layout(sp44, temp_v0_4));
    }

    MainPool_FinalizeAllocation(sp44);

    temp_v0_7 = sp3C(4, 0);
    if (temp_v0_7 == NULL) {
        D_8438E530.node.callbackArg = 0;
        D_8438E530.node.flags &= ~1;
    } else {
        D_8438E530.unk_18.unk_00 = temp_v0_7->unk_00;
        D_8438E530.unk_18.unk_02 = temp_v0_7->unk_02;
        D_8438E530.unk_18.unk_04.rgba = temp_v0_7->unk_04.rgba;
        D_8438E530.node.callbackArg = 1;
    }

    BattleScene_DispatchLifecycle(3, D_8438E798);
    BattleScene_DispatchOwnerCameraLifecycle(3, &D_8438E598, &D_8438E688);
    BattleScene_Dispatch(3, &D_8438E440);
    BattleAnim_DispatchPresentation(3, &D_8438E440);

    D_8438E7A0 = 1;
    D_8438E79C = 0;
}

void func_84301A24(void) {
}

s32 Battle_Main(s32 arg0, SessionContext* arg1) {
    unk_func_80007444* sp24;

    D_8438E798 = D_800AE540.unk_1194;
    D_8438E7AC = -2;

    main_pool_push_state('BATL');

    Gfx_InitDisplayListBuffers(0x20000, 0);
    sp24 = StageContext_Allocate(0, 1, 3, 1, 2, 1);
    func_84301430(sp24);
    StageContext_Activate(sp24);
    StageLoader_RunFrames(1);
    BgStage_WaitForCondition(Battle_FrameCallback, 0x20, 0x10);
    StageLoader_RunFrames(2);
    StageContext_Deactivate();
    Gfx_FreeDisplayListBuffers();

    main_pool_pop_state('BATL');

    return 0;
}
