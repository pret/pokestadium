#include "battle_engine.h"
#include "game_state.h"
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

static CameraNode D_8438E440;
static unk_D_8690A610 D_8438E530;
static GraphNode D_8438E550;
static GraphNode D_8438E568;
static GraphNode D_8438E580;
static CameraNode D_8438E598;
static CameraNode D_8438E688;
u8* sSide1PokemonThumbnailImage;
u8* sSide2PokemonThumbnailImage;
static void* D_8438E780;
static GraphNode* D_8438E784;
static GraphNode* D_8438E788;
static GraphNode* D_8438E78C;
static DepthBuffer* sSide1PokemonThumbnail;
static DepthBuffer* sSide2PokemonThumbnail;
static BattleSessionTeams* sBattleSides;
static s32 sIsPaused;
static s32 D_8438E7A0;
static Color_RGBA8_u32 sTintColor;
static f32 D_8438E7A8;
static s32 D_8438E7AC;

static u8 sBattleModeDispatch[] = {
    SESSION_MODE_ANYTHING_GOES, // SESSION_MODE_ANYTHING_GOES
    SESSION_MODE_NINTENDO_CUP_97, // SESSION_MODE_NINTENDO_CUP_97
    SESSION_MODE_NINTENDO_CUP_98, // SESSION_MODE_NINTENDO_CUP_98
    SESSION_MODE_NINTENDO_CUP_99, // SESSION_MODE_NINTENDO_CUP_99
    SESSION_MODE_PETIT_CUP, // SESSION_MODE_PETIT_CUP
    SESSION_MODE_PIKA_CUP, // SESSION_MODE_PIKA_CUP
    SESSION_MODE_PRIME_CUP, // SESSION_MODE_PRIME_CUP
    SESSION_MODE_GYM_LEADER_CASTLE, // SESSION_MODE_GYM_LEADER_CASTLE
    17, // SESSION_MODE_VS_MEWTWO
    SESSION_MODE_NINTENDO_CUP_97, // SESSION_MODE_BATTLE_NOW
    SESSION_MODE_ANYTHING_GOES, // SESSION_MODE_EVENT_BATTLE
    0, 0, 0, 0, 0, // 11-15: Unknown
    SESSION_MODE_NINTENDO_CUP_97, // SESSION_MODE_ATTRACT_DEMO_BATTLE
    SESSION_MODE_NINTENDO_CUP_97, SESSION_MODE_NINTENDO_CUP_97, // 17-18: Cutscenes
    SESSION_MODE_NINTENDO_CUP_97, // 19: Unknown
    // The ROM table ends here at 20 bytes. Modes 20-26 index past it into the
    // first bytes of D_84384364 (0x0C, 0x00, 0xFF, 0xFF, 0x05, 0x00, 0x00).
    // Adding entries would shift .data and break ROM identity.
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

// called every frame: bug boy in GLC
s32 Battle_StageGeoDispatchCallback(s32 arg0, GraphNode* arg1) {
    if (arg0 == 2) {
        BattleAnim_DispatchPresentation(5, &D_8438E440);
    }
    return 0;
}
// called every frame: bug boy in GLC
s32 Battle_StageLightAngleCallbackA(s32 arg0, unk_D_86002F34_alt18* arg1) {
    UNUSED s32 pad;
    f32 distance;
    s16 angle_x;
    s16 angle_y;

    if (arg0 == 2) {
        Vec3f_CalculateDistanceAngles(&D_8006F088->view.targetPosition, &D_8006F088->view.eyePosition, &distance, &angle_x, &angle_y);
        arg1->unk_1C = angle_x + 0x2000;
        arg1->unk_1E = angle_y - 0x2000;
    }
    return 0;
}

// called every frame: bug boy in GLC
s32 Battle_StageLightAngleCallbackB(s32 arg0, unk_D_86002F34_alt18* arg1) {
    UNUSED s32 pad;
    f32 sp28;
    s16 sp26;
    s16 sp24;

    if (arg0 == 2) {
        Vec3f_CalculateDistanceAngles(&D_8006F088->view.targetPosition, &D_8006F088->view.eyePosition, &sp28, &sp26, &sp24);
        arg1->unk_1C = -0x2000 - sp26;
        arg1->unk_1E = sp24 + 0x6000;
    }
    return 0;
}

// called every frame: bug boy in GLC
s32 Battle_StageMaterialTintCallback(s32 arg0, DisplayObject* arg1) {
    if (arg0 == 2) {
        Vec3f_SetComponentsDuplicate(&arg1->scale, D_8438E7A8, D_8438E7A8, D_8438E7A8);
        arg1->textureTint.rgba = sTintColor.rgba;
    }
    return 0;
}

// called every frame: bug boy in GLC
void Battle_SetStageTintColor(u8 r, u8 g, u8 b) {
    sTintColor.r = r;
    sTintColor.g = g;
    sTintColor.b = b;

    if (((r & g & b) & 0xFF) == 0xFF) {
        if (D_8438E530.node.callbackArg == 1) {
            D_8438E530.node.flags |= 1;
        }
    } else {
        D_8438E530.node.flags &= ~1;
    }
}

// Called at the start of battles
void BattleScene_SetModelUniformScale(f32 arg0) {
    D_8438E7A8 = arg0;
}

// called every frame: bug boy in GLC
u16 Battle_TintTexel16(u16 color) {
    s32 r;
    s32 g;
    s32 b;

    r = ((((((color >> 11) & 0x1F) << 3) + (((color >> 11) & 0x1F) >> 2)) * sTintColor.r) / 255) >> 3;
    g = ((((((color >> 6) & 0x1F) << 3) + (((color >> 6) & 0x1F) >> 2)) * sTintColor.g) / 255) >> 3;
    b = ((((((color >> 1) & 0x1F) << 3) + (((color >> 1) & 0x1F) >> 2)) * sTintColor.b) / 255) >> 3;

    return (r << 11) | (g << 6) | (b << 1) | 1;
}

// called every frame: bug boy in GLC
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

    sp4E = D_8438E440.viewport.x;
    sp4A = D_8438E440.viewport.y;
    sp4C = D_8438E440.viewport.width + sp4E;
    sp48 = (D_8438E440.viewport.height / 2) + sp4A;
    sp46 = D_8438E440.viewport.height + sp4A;
    sp44 = 0x10000 / (D_8438E440.viewport.height / 2);

    if ((D_8438E440.viewport.width < 0x140) || (D_8438E440.viewport.height < 0xF0)) {
        GfxImage_FillCurrent(&gDisplayListHead, 1);
    } else {
        GfxImage_ClearDepthRectangle(&gDisplayListHead, 0, 0, 0x140, 0xF0);
    }

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetCombineMode(gDisplayListHead++, G_CC_MODULATEI_PRIM, G_CC_MODULATEI_PRIM);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, sTintColor.r, sTintColor.g, sTintColor.b, 255);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);

    gDPLoadTextureBlock(gDisplayListHead++, Memmap_GetFragmentVaddr(D_8438E780), G_IM_FMT_RGBA, G_IM_SIZ_32b, 4, 64, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, sp4E << 2, sp4A << 2, sp4C << 2, sp48 << 2, G_TX_RENDERTILE, 0, 0, 0, sp44);
    gSPTextureRectangle(gDisplayListHead++, sp4E << 2, sp48 << 2, sp4C << 2, sp46 << 2, G_TX_RENDERTILE, 0, 0x07E0, 0,
                        0);
    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

/*
    Makes and Freezes the thumbnail of active pokemon
*/
void Battle_RenderActivePokemonThumbnail(GraphNode* pokemon, DepthBuffer* thumbnail) {
    CameraNode* camera_node = pokemon->children;
    CameraViewport viewport;

    if (camera_node->node.flags & 0x10) {
        viewport = camera_node->viewport;

        camera_node->viewport.x = 0;
        camera_node->viewport.y = 0;
        camera_node->viewport.width = 76;
        camera_node->viewport.height = 76;

        GfxImage_SetRenderTarget(&gDisplayListHead, thumbnail);
        GfxImage_FillCurrent(&gDisplayListHead, 0x10D);
        Geo_RenderRootNode(pokemon);

        camera_node->node.flags &= ~0x10;

        camera_node->viewport = viewport;
    }
}

// called every frame: bug boy in GLC
void Battle_DrawClippedTextureRect(s32 x1, s32 y1, s32 x2, s32 y2) {
    struct Rectangle dest;
    u16 texture_spread_x;
    u16 texture_spread_y;

    GfxRect_SetBounds(&dest, x1, y1, x2, y2);

    if (GfxRect_ClipToScissor(&dest) != 0) {
        if (!x2) {}

        texture_spread_x = ((dest.x1 - x1) << 5);
        texture_spread_y = ((dest.y2 - y1) << 5);

        texture_spread_x += 0x10;
        texture_spread_y += 0x10;

        gSPTextureRectangle(gDisplayListHead++, dest.x1 << 2, dest.y2 << 2, ((dest.y1 + 1) ^ 0) << 2,
                            ((dest.x2 + 1) ^ 0) << 2, G_TX_RENDERTILE, texture_spread_x, texture_spread_y, 0x0800, 0x0800);

        if ((x2 && x2) ^ 0) {}// karodo
    }
}

// called every frame: bug boy in GLC
void Battle_DrawTexturedRectSegment(s32 x1, s32 y1, s32 draw_width, s32 height, u8* texture, s32 load_width) {
    gDPLoadTextureBlock(gDisplayListHead++, texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, load_width, (height * 2) + 2, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    Battle_DrawClippedTextureRect(x1, y1, (x1 + draw_width) - 1, (y1 + height) - 1);
}

/*
    Fills in the texture of the pokemon thumbnail
*/
void Battle_FillActivePokemonThumbnail(GraphNode* pokemon, DepthBuffer* thumbnail) {
    s32 x;
    s32 y;
    CameraNode* camera_child_node = pokemon->children;
    CameraViewport* viewport = &pokemon->children->viewport;
    s32 img;

    x = viewport->x;
    y = viewport->y;

    camera_child_node++;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_AVERAGE);

    img = thumbnail->img_p;
    Battle_DrawTexturedRectSegment(x, y, 37, 10, img, 76);
    img = thumbnail->img_p + 0xBE0;
    Battle_DrawTexturedRectSegment(x, y + 10, 37, 10, img, 76);
    img = thumbnail->img_p + 0x17C0;
    Battle_DrawTexturedRectSegment(x, y + 20, 37, 10, img, 76);
    img = thumbnail->img_p + 0x23A0;
    Battle_DrawTexturedRectSegment(x, y + 30, 37, 7, img, 76);

    gDPPipeSync(gDisplayListHead++);

    gDPSetTexturePersp(gDisplayListHead++, G_TP_PERSP);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
}

// trigger unknown
// preliminary guess: initialization for Tag Team in free battle
void func_84300D44(void) {
    s32 i;
    s32 j;
    s32 x;
    TeamRoster* current_team_member;
    BattleSessionTeams* player_tag_team = &sBattleSides[0];

    for (i = 0; i < 2; i++, player_tag_team++) {
        for (j = 0; j < player_tag_team->unk_01; j++) {
            current_team_member = player_tag_team->teamMember[j];
            for (x = 0; x < current_team_member->numberOfPokemonChosen; x++) {
                current_team_member->pokemonPicked[x].unk_25 = 0;
            }
        }
    }
}

// called every frame: bug boy in GLC
void func_84300DC0(void) {
    s32 i;
    s32 j;
    s32 x;
    s32 var_v0 = 0;
    TeamRoster* temp_a3;
    BattleSessionTeams* player_side = &sBattleSides[0];

    for (i = 0; i < 2; i++, player_side++) {
        for (j = 0; j < player_side->unk_01; j++) {
            temp_a3 = player_side->teamMember[j];
            for (x = 0; x < temp_a3->numberOfPokemonChosen; x++) {
                if ((temp_a3->pokemonPicked[x].unk_25 == 0) && (temp_a3->pokemonPicked[x].unk_02 == 0)) {
                    var_v0 = 1;
                    temp_a3->pokemonPicked[x].unk_25 = D_8438E7A0;
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

// called every frame: bug boy in GLC
s32 BattleScene_UpdateFrame(s32 arg0) {
    s32 sp1C;

    GeoRender_AdvanceFrameCounter();
    ModelAnim_UpdateFrameChangeState();
    BattleScene_DispatchLifecycle(2, sBattleSides);
    BattleScene_DispatchOwnerCameraLifecycle(2, &D_8438E598, &D_8438E688);
    sp1C = BattleScene_Dispatch(2, &D_8438E440);
    BattleAnim_DispatchPresentation(2, &D_8438E440);
    Battle_RenderActivePokemonThumbnail(D_8438E788, sSide1PokemonThumbnail);
    Battle_RenderActivePokemonThumbnail(D_8438E78C, sSide2PokemonThumbnail);
    BgStage_DrawFrame();
    Battle_DrawStageBackdrop();
    Geo_RenderRootNode(D_8438E784);
    BattleScene_DispatchLifecycle(5, sBattleSides);
    Battle_FillActivePokemonThumbnail(D_8438E788, sSide1PokemonThumbnail);
    Battle_FillActivePokemonThumbnail(D_8438E78C, sSide2PokemonThumbnail);
    func_84300DC0();

    if (sp1C == 1) {
        sBattleSides[0].unk_1C = 1;
    }

    if (sp1C == 2) {
        sBattleSides[1].unk_1C = 1;
    }

    return sp1C;
}

/*
    No idea what the hell this is, it's not drawing the Run selection cursor and nothing else in battle would use START
    Stadium doesn't have pausing so it's not that either
    preliminary guess: unused pausing debug option, sIsPaused can never be 1 through the current code
*/
s32 BattleScene_UpdatePausedFrame(s32 arg0) {
    s32 sp1C = 0;

    if ((arg0 == 0) && BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        sp1C = BattleScene_UpdateFrame(arg0);
    } else {
        ModelAnim_UpdateFrameChangeState();
        BgStage_DrawFrame();
        Battle_DrawStageBackdrop();
        Geo_RenderRootNode(D_8438E784);
        BattleScene_DispatchLifecycle(5, sBattleSides);
        Battle_FillActivePokemonThumbnail(D_8438E788, sSide1PokemonThumbnail);
        Battle_FillActivePokemonThumbnail(D_8438E78C, sSide2PokemonThumbnail);
    }

    if ((arg0 == 0) && BTN_IS_PRESSED(gPlayer1Controller, BTN_START)) {
        sIsPaused = 0;
    }
    return sp1C;
}

// triggers every frame: bug boy in GLC
void Battle_UpdateCompletionGate(void) {
    if (D_8438E7AC < 0) {
        D_8438E7AC++;
    } else if ((D_8438E7AC == 0) && (gSessionContext.mode == 0x10) && gPlayer1Controller->buttonPressed) {
        D_8438E7AC = 1;
    }
}

// triggers every frame: bug boy in GLC
s32 Battle_FrameCallback(s32 arg0) {
    s32 sp1C = 0;

    Cont_StartReadInputs();
    Trainer_RequestPokeIcon(&sBattleSides[0]);
    PokeIcon_WaitFrameLoadForObject(&sBattleSides[0]);
    Trainer_RequestPokeIcon(&sBattleSides[1]);
    PokeIcon_WaitFrameLoadForObject(&sBattleSides[1]);
    Cont_ReadInputs();
    Input_ResetRepeatState();

    switch (sIsPaused) {
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
    PokeIcon_RequestBackgroundForObject(&sBattleSides[0]);
    PokeIcon_RequestBackgroundForObject(&sBattleSides[1]);

    if ((arg0 != 2) && (D_8438E7AC == 1)) {
        D_8438E7AC = 2;
        func_8003DB84(0);
        if (gSessionContext.mode != 0x11) {
            Audio_FadeOutAll(0x1E);
        }
        return 1;
    }
    return 0;
}

// triggers on battle start: bug boy in glc
void Battle_SelectComRosterOrder(u8* com_roster, s32 number_of_pokemon_picked) {
    s32 i;
    s32 j;

    for (i = 0; i < 6; i++) {
        for (j = 0; j < number_of_pokemon_picked; j++) {
            if (i == com_roster[j]) {
                break;
            }
        }

        if (j == number_of_pokemon_picked) {
            com_roster[number_of_pokemon_picked++] = i;
        }
    }
}

// triggers on battle start: bug boy in glc
void Battle_CompleteComRosterOrder(void) {
    TeamRoster* com_roster;
    TeamRoster* player_roster;
    u8 order_of_picked_pokemon[8];
    TeamRoster* player_teammate_roster;
    s32 i;
    s32 number_of_pokemon_picked;

    player_roster = gSessionContext.battleSides[0].teamMember[0];
    // Free battle does let two players play against the AI
    player_teammate_roster = gSessionContext.battleSides[0].teamMember[1];
    com_roster = gSessionContext.battleSides[1].teamMember[0];

    if (com_roster->unk_000 & 2) {
        if (gSessionContext.mode == 0) {
            if (gSessionContext.ruleCategory == RULE_CATEGORY_ANYTHING_GOES) {
                number_of_pokemon_picked = com_roster->rosterInfo->numberOfPokemonCanBePicked;
            } else {
                number_of_pokemon_picked = 3;
            }
            func_843831A0(player_roster, player_teammate_roster, com_roster, gSessionContext.aiDifficulty, order_of_picked_pokemon, gSessionContext.ruleCategory, number_of_pokemon_picked);
        } else {
            if (gSessionContext.ruleCategory == RULE_CATEGORY_VS_MEWTWO) {
                number_of_pokemon_picked = com_roster->rosterInfo->numberOfPokemonCanBePicked;
            } else {
                number_of_pokemon_picked = 3;
            }
            func_843831A0(player_roster, NULL, com_roster, com_roster->unk_018 & 0xFF, order_of_picked_pokemon, gSessionContext.ruleCategory, number_of_pokemon_picked);
        }
        Battle_SelectComRosterOrder(order_of_picked_pokemon, number_of_pokemon_picked);
        com_roster->numberOfPokemonChosen = number_of_pokemon_picked;

        for (i = 0; i < com_roster->rosterInfo->numberOfPokemonCanBePicked; i++) {
            com_roster->pokemonPicked[i] = com_roster->rosterInfo->unk_028[order_of_picked_pokemon[i]];
        }
    }
}

// triggers at the start of battle: bug boy in glc
void BattleScene_InitializeParticipantPresentation(BattleSessionTeams* arg0, unk_D_86002F30* arg1) {
    TeamRoster* temp_v0 = arg0->teamMember[0];

    arg0->unk_18 = arg1->unk_08->unk_00[0];
    arg0->unk_00 |= 0xA0;
    arg0->unk_1C = 0;
    arg0->unk_02 = temp_v0->pokemonPicked[0].unk_00.unk_00;
    arg0->unk_04 = temp_v0->pokemonPicked;
    Trainer_RequestPokeIcon(arg0);
}

// triggers at the start of battle: bug boy in glc
void BattleScene_Init(unk_func_80007444* arg0) {
    MemoryBlock* sp44;
    u32* temp_v0_4;
    FragmentEntry sp3C;
    unk_D_8690A610_018* temp_v0_7;
    s32 pad;
    s16 sp32;
    DepthBuffer* sp2C;
    unk_D_86002F30* sp28;

    Battle_SetStageTintColor(0xFF, 0xFF, 0xFF);
    BattleScene_SetModelUniformScale(1.0f);

    if (gSessionContext.mode == 0x11) {
        Font_Init(4, 0);
    } else if (gSessionContext.mode == 0x10) {
        Font_Init(7, 0);
    } else {
        Font_Init(3, 0);
    }

    sBattleSides[0].unk_10 = PokeIcon_AllocFramebuffers(3);
    sBattleSides[1].unk_10 = PokeIcon_AllocFramebuffers(3);
    PokeIcon_OpenModelArchives();

    sp2C = main_pool_alloc(0x10, 0);
    GfxImage_Initialize(sp2C, 0, 2, 0x4C, 0x4C, arg0->unk_18[0]->depth_p->img_p);
    sSide1PokemonThumbnail = GfxImage_Allocate(0, 2, 0x4C, 0x4C, 0);
    sSide2PokemonThumbnail = GfxImage_Allocate(0, 2, 0x4C, 0x4C, 0);

    GfxImage_AttachDepthBuffer(sSide1PokemonThumbnail, sp2C);
    GfxImage_AttachDepthBuffer(sSide2PokemonThumbnail, sp2C);

    sSide1PokemonThumbnailImage = sSide1PokemonThumbnail->img_p;
    sSide2PokemonThumbnailImage = sSide2PokemonThumbnail->img_p;

    FRAGMENT_LOAD(FRAGMENT_PARTICLE_DATA_LIBRARY);
    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_3000000, battle_ui, 0);

    if ((gSessionContext.mode == SESSION_MODE_ATTRACT_DEMO_BATTLE) || (gSessionContext.mode == SESSION_MODE_EVENT_BATTLE)) {
        sp32 = sBattleModeDispatch[gSessionContext.ruleCategory];
        if (gSessionContext.ruleCategory == SESSION_MODE_GYM_LEADER_CASTLE) {
            sp32 += gSessionContext.modeSelection;
        }
    } else {
        sp32 = sBattleModeDispatch[gSessionContext.mode];
        if (gSessionContext.mode == SESSION_MODE_GYM_LEADER_CASTLE) {
            sp32 += gSessionContext.modeSelection;
        }
    }

    sp3C = BinArchive_GetFile(ASSET_LOAD2(stadium_models, 1, 1), sp32);
    D_8438E780 = sp3C(2, 0);

    sp28 = Model_LoadByArchiveIndex(0x9A);
    Battle_CompleteComRosterOrder();
    BattleScene_InitializeParticipantPresentation(&sBattleSides[0], sp28);
    BattleScene_InitializeParticipantPresentation(&sBattleSides[1], sp28);

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
    BattleScene_DispatchLifecycle(0, sBattleSides);
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

    BattleScene_DispatchLifecycle(3, sBattleSides);
    BattleScene_DispatchOwnerCameraLifecycle(3, &D_8438E598, &D_8438E688);
    BattleScene_Dispatch(3, &D_8438E440);
    BattleAnim_DispatchPresentation(3, &D_8438E440);

    D_8438E7A0 = 1;
    sIsPaused = 0;
}

void func_84301A24(void) {
}

// triggers at the start of battle, battle init
s32 Battle_Main(s32 arg0, SessionContext* arg1) {
    unk_func_80007444* sp24;

    sBattleSides = gSessionContext.battleSides;
    D_8438E7AC = -2;

    main_pool_push_state('BATL');

    Gfx_InitDisplayListBuffers(0x20000, 0);
    sp24 = StageContext_Allocate(0, 1, 3, 1, 2, 1);
    BattleScene_Init(sp24);
    StageContext_Activate(sp24);
    StageLoader_RunFrames(1);
    BgStage_WaitForCondition(Battle_FrameCallback, 0x20, 0x10);
    StageLoader_RunFrames(2);
    StageContext_Deactivate();
    Gfx_FreeDisplayListBuffers();

    main_pool_pop_state('BATL');

    return 0;
}
