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

// Battle fragment entry, scene construction, and per-frame rendering.
// Stage archive entries provide layouts 0/1/3, backdrop 2, and optional fog 4.
// Thumbnail cameras render to separate 76 x 76 images before the main scene.

static CameraNode sStageCamera;
static unk_D_8690A610 sStageFog;
static GraphNode sStageLayout0;
static GraphNode sStageLayout1;
static GraphNode sStageLayout3;
static CameraNode sSide1ThumbnailCamera;
static CameraNode sSide2ThumbnailCamera;
// Exported: battle_engine_32B680.c reads these to texture the HUD thumbnails.
u8* sSide1PokemonThumbnailImage;
u8* sSide2PokemonThumbnailImage;
static void* sStageBackdrop;
static GraphNode* sStageRoot;
static GraphNode* sSide1ThumbnailRoot;
static GraphNode* sSide2ThumbnailRoot;
static DepthBuffer* sSide1PokemonThumbnail;
static DepthBuffer* sSide2PokemonThumbnail;
static BattleSessionTeams* sBattleSides;
static s32 sIsPaused;
static s32 sNextFaintBatch;
static Color_RGBA8_u32 sTintColor;
static f32 sStageScale;
// Initial countdown -2 -> 0, completion latch 1, audio-shutdown latch 2.
static s32 sCompletionGate;

// Indexed by gSessionContext.mode, or by ruleCategory for Event and attract-demo battles.
// Values are stadium_models arena file indices, not session modes. Gym Leader Castle
// adds modeSelection (0-9) to its base value 7, reaching Castle arenas 7-16.
static u8 sBattleModeDispatch[] = {
    0,     // [SESSION_MODE_ANYTHING_GOES]       -> arena 0 (Free Battle)
    1,     // [SESSION_MODE_NINTENDO_CUP_97]     -> arena 1 (Nintendo Cup '97 / Poke Cup R1)
    2,     // [SESSION_MODE_NINTENDO_CUP_98]     -> arena 2 (Nintendo Cup '98 / Poke Cup R2)
    3,     // [SESSION_MODE_NINTENDO_CUP_99]     -> arena 3 (Nintendo Cup '99 / Poke Cup R3)
    4,     // [SESSION_MODE_PETIT_CUP]           -> arena 4 (Petit Cup)
    5,     // [SESSION_MODE_PIKA_CUP]            -> arena 5 (Pika Cup)
    6,     // [SESSION_MODE_PRIME_CUP]           -> arena 6 (Prime Cup)
    7,     // [SESSION_MODE_GYM_LEADER_CASTLE]   -> arenas 7..16 (7 + modeSelection)
    17,    // [SESSION_MODE_VS_MEWTWO]           -> arena 17 (Vs. Mewtwo)
    1,     // [SESSION_MODE_BATTLE_NOW]          -> arena 1
    0,     // [SESSION_MODE_EVENT_BATTLE]        -> not read; BattleScene_Init indexes by ruleCategory
    0, 0, 0, 0, 0, // 11-15: Unknown
    1,     // [SESSION_MODE_ATTRACT_DEMO_BATTLE] -> not read; BattleScene_Init indexes by ruleCategory
    1, 1,  // 17-18: Cutscenes
    1,     // 19: Unknown
    // The ROM table ends here at 20 bytes. Modes 20-26 index past it into the
    // first bytes of sStageGeoLayout (0x0C, 0x00, 0xFF, 0xFF, 0x05, 0x00, 0x00).
    // Adding entries would shift .data and break ROM identity.
};
static u32 sStageGeoLayout[] = {
    0x0C00FFFF,  0x05000000,  0x07000000,    &sStageCamera,   0x05000000, 0x0D000000,    0x05000000,  0x07000000,
    &sStageFog, 0x14000000,  0x002D0019,    0xFFFFFF28,    0x08000000, Battle_StageLightAngleCallbackA, 0x00000000,  0x14000000,
    0x002D0019,  0x80808028,  0x08000000,    Battle_StageLightAngleCallbackB, 0x00000000, 0x16646464,    0x0F000002,  0x05000000,
    0x1F00FFFF,  0x00000000,  0x00000000,    0x00000000,    0x00640064, 0x00640000,    0x08000000,  Battle_StageMaterialTintCallback,
    0x00000000,  0x05000000,  0x07000000,    &sStageLayout0,   0x06000000, 0x06000000,    0x0F000003,  0x05000000,
    0x1F00FFFF,  0x00000000,  0x00000000,    0x00000000,    0x00640064, 0x00640000,    0x08000000,  Battle_StageMaterialTintCallback,
    0x00000000,  0x05000000,  0x07000000,    &sStageLayout1,   0x06000000, 0x06000000,    0x0F000002,  0x05000000,
    0x1F00FFFF,  0x00000000,  0x00000000,    0x00000000,    0x00640064, 0x00640000,    0x08000000,  Battle_StageMaterialTintCallback,
    0x00000000,  0x05000000,  0x07000000,    &sStageLayout3,   0x06000000, 0x06000000,    0x0F000003,  0x05000000,
    0x0A000000,  &D_800AC840, 0x06000000,    0x0F000002,    0x05000000, 0x0A000000,    &D_800AC858, 0x06000000,
    0x09000000,  0x08000000,  Battle_StageGeoDispatchCallback, 0x00000000,    0x06000000, 0x06000000,    0x06000000,  0x01000000,
};
static u32 sSide1ThumbnailLayout[] = {
    0x0C00FFFF,  0x05000000, 0x07000000, &sSide1ThumbnailCamera, 0x05000000, 0x0D000001, 0x05000000,
    0x14000000,  0x002D0019, 0xFFFFFF28, 0x16FFFFFF,  0x0F000003, 0x05000000, 0x0A000000,
    &D_800AC840, 0x06000000, 0x06000000, 0x06000000,  0x06000000, 0x01000000,
};
static u32 sSide2ThumbnailLayout[] = {
    0x0C00FFFF,  0x05000000, 0x07000000, &sSide2ThumbnailCamera, 0x05000000, 0x0D000002, 0x05000000,
    0x14000000,  0x002D0019, 0xFFFFFF28, 0x16FFFFFF,  0x0F000003, 0x05000000, 0x0A000000,
    &D_800AC840, 0x06000000, 0x06000000, 0x06000000,  0x06000000, 0x01000000,
};

// called every frame: bug boy in GLC
// Geo_ProcessNodeChildren invokes render callbacks with event 2.
//@src/geo_render.c
s32 Battle_StageGeoDispatchCallback(s32 event, GraphNode* node) {
    if (event == 2) {
        BattleAnim_DispatchPresentation(5, &sStageCamera);
    }
    return 0;
}
// called every frame: bug boy in GLC
// Orient the first stage light relative to the current camera's viewing axis.
s32 Battle_StageLightAngleCallbackA(s32 event, unk_D_86002F34_alt18* light) {
    UNUSED s32 pad;
    f32 distance;
    s16 angle_x;
    s16 angle_y;

    if (event == 2) {
        Vec3f_CalculateDistanceAngles(&D_8006F088->view.targetPosition, &D_8006F088->view.eyePosition, &distance, &angle_x, &angle_y);
        light->unk_1C = angle_x + 0x2000;
        light->unk_1E = angle_y - 0x2000;
    }
    return 0;
}

// called every frame: bug boy in GLC
// The second light uses the opposite elevation and an azimuth offset of 135 degrees.
s32 Battle_StageLightAngleCallbackB(s32 event, unk_D_86002F34_alt18* light) {
    UNUSED s32 pad;
    f32 distance;
    s16 angle_x;
    s16 angle_y;

    if (event == 2) {
        Vec3f_CalculateDistanceAngles(&D_8006F088->view.targetPosition, &D_8006F088->view.eyePosition, &distance, &angle_x, &angle_y);
        light->unk_1C = -0x2000 - angle_x;
        light->unk_1E = angle_y + 0x6000;
    }
    return 0;
}

// called every frame: bug boy in GLC
// Apply presentation effects to each of the three stage-layout containers.
s32 Battle_StageMaterialTintCallback(s32 event, DisplayObject* object) {
    if (event == 2) {
        Vec3f_SetComponentsDuplicate(&object->scale, sStageScale, sStageScale, sStageScale);
        object->textureTint.rgba = sTintColor.rgba;
    }
    return 0;
}

// called every frame: bug boy in GLC
// A nonwhite tint disables fog. White re-enables it only when archive entry 4
// supplied fog parameters; without parameters, white leaves the flags unchanged.
void Battle_SetStageTintColor(u8 r, u8 g, u8 b) {
    sTintColor.r = r;
    sTintColor.g = g;
    sTintColor.b = b;

    if (((r & g & b) & 0xFF) == 0xFF) {
        if (sStageFog.node.callbackArg == 1) {
            sStageFog.node.flags |= 1;
        }
    } else {
        sStageFog.node.flags &= ~1;
    }
}

// Called at the start of battles
// Uniform scale consumed by the stage material callbacks, not the Pokemon models.
void Battle_SetStageScale(f32 scale) {
    sStageScale = scale;
}

// called every frame: bug boy in GLC
// Expand RGBA5551 channels to eight bits for tinting, then repack with alpha set.
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
// Archive entry 2 returns a tagged backdrop value: NULL clears depth, -1 fills
// black, a value below 0x10000 is RGBA5551, and larger values address a texture.
// The 4 x 64 RGBA32 texture stretches over the upper half; its last row fills below.
void Battle_DrawStageBackdrop(void) {
    s16 left;
    s16 right;
    s16 top;
    s16 middle;
    s16 bottom;
    s16 texture_step_y;

    if ((u32)sStageBackdrop == NULL) {
        GfxImage_ClearDepthRectangle(&gDisplayListHead, 0, 0, 0x140, 0xF0);
        return;
    }

    if ((u32)sStageBackdrop == -1) {
        GfxImage_FillCurrent(&gDisplayListHead, 1);
        return;
    }

    if ((u32)sStageBackdrop < 0x10000) {
        GfxImage_FillCurrent(&gDisplayListHead, Battle_TintTexel16(sStageBackdrop));
        return;
    }

    left = sStageCamera.viewport.x;
    top = sStageCamera.viewport.y;
    right = sStageCamera.viewport.width + left;
    middle = (sStageCamera.viewport.height / 2) + top;
    bottom = sStageCamera.viewport.height + top;
    texture_step_y = 0x10000 / (sStageCamera.viewport.height / 2);

    if ((sStageCamera.viewport.width < 0x140) || (sStageCamera.viewport.height < 0xF0)) {
        GfxImage_FillCurrent(&gDisplayListHead, 1);
    } else {
        GfxImage_ClearDepthRectangle(&gDisplayListHead, 0, 0, 0x140, 0xF0);
    }

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetCombineMode(gDisplayListHead++, G_CC_MODULATEI_PRIM, G_CC_MODULATEI_PRIM);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, sTintColor.r, sTintColor.g, sTintColor.b, 255);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);

    gDPLoadTextureBlock(gDisplayListHead++, Memmap_GetFragmentVaddr(sStageBackdrop), G_IM_FMT_RGBA, G_IM_SIZ_32b, 4, 64, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, left << 2, top << 2, right << 2, middle << 2, G_TX_RENDERTILE, 0, 0, 0, texture_step_y);
    gSPTextureRectangle(gDisplayListHead++, left << 2, middle << 2, right << 2, bottom << 2, G_TX_RENDERTILE, 0, 0x07E0, 0,
                        0);
    gSPDisplayList(gDisplayListHead++, gUiRestoreTextureDL);
}

/*
    Makes and Freezes the thumbnail of active pokemon
*/
// Capture only when camera flag 0x10 requests a refresh. Restoring the viewport
// keeps the camera's on-screen placement separate from its off-screen render size.
void Battle_RenderActivePokemonThumbnail(GraphNode* thumbnail_root, DepthBuffer* thumbnail) {
    CameraNode* camera_node = thumbnail_root->children;
    CameraViewport viewport;

    if (camera_node->node.flags & 0x10) {
        viewport = camera_node->viewport;

        camera_node->viewport.x = 0;
        camera_node->viewport.y = 0;
        camera_node->viewport.width = 76;
        camera_node->viewport.height = 76;

        GfxImage_SetRenderTarget(&gDisplayListHead, thumbnail);
        GfxImage_FillCurrent(&gDisplayListHead, 0x10D);
        Geo_RenderRootNode(thumbnail_root);

        camera_node->node.flags &= ~0x10;

        camera_node->viewport = viewport;
    }
}

// called every frame: bug boy in GLC
// Rectangle's legacy field order is left/right/bottom/top (x1/y1/x2/y2).
// Use clipped destination offsets as 10.5 texture coordinates with a half-texel bias.
//@src/gfx_rect.c
void Battle_DrawClippedTextureRect(s32 x1, s32 y1, s32 x2, s32 y2) {
    struct Rectangle destination;
    u16 texture_spread_x;
    u16 texture_spread_y;

    GfxRect_SetBounds(&destination, x1, y1, x2, y2);

    if (GfxRect_ClipToScissor(&destination) != 0) {
        if (!x2) {}

        texture_spread_x = ((destination.x1 - x1) << 5);
        texture_spread_y = ((destination.y2 - y1) << 5);

        texture_spread_x += 0x10;
        texture_spread_y += 0x10;

        gSPTextureRectangle(gDisplayListHead++, destination.x1 << 2, destination.y2 << 2, ((destination.y1 + 1) ^ 0) << 2,
                            ((destination.x2 + 1) ^ 0) << 2, G_TX_RENDERTILE, texture_spread_x, texture_spread_y, 0x0800, 0x0800);

        if ((x2 && x2) ^ 0) {} // karodo
    }
}

// called every frame: bug boy in GLC
// Load full-width source rows and draw at half size using the clipped rectangle helper.
void Battle_DrawTexturedRectSegment(s32 x1, s32 y1, s32 draw_width, s32 height, u8* texture, s32 load_width) {
    gDPLoadTextureBlock(gDisplayListHead++, texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, load_width, (height * 2) + 2, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    Battle_DrawClippedTextureRect(x1, y1, (x1 + draw_width) - 1, (y1 + height) - 1);
}

/*
    Fills in the texture of the pokemon thumbnail
*/
// Blit the captured side image as four strips, producing a 37 x 37 thumbnail.
void Battle_FillActivePokemonThumbnail(GraphNode* thumbnail_root, DepthBuffer* thumbnail) {
    s32 x;
    s32 y;
    CameraNode* camera_node = thumbnail_root->children;
    CameraViewport* viewport = &thumbnail_root->children->viewport;
    s32 image_address;

    x = viewport->x;
    y = viewport->y;

    camera_node++;

    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_AVERAGE);

    image_address = thumbnail->img_p;
    Battle_DrawTexturedRectSegment(x, y, 37, 10, image_address, 76);
    image_address = thumbnail->img_p + 0xBE0;
    Battle_DrawTexturedRectSegment(x, y + 10, 37, 10, image_address, 76);
    image_address = thumbnail->img_p + 0x17C0;
    Battle_DrawTexturedRectSegment(x, y + 20, 37, 10, image_address, 76);
    image_address = thumbnail->img_p + 0x23A0;
    Battle_DrawTexturedRectSegment(x, y + 30, 37, 7, image_address, 76);

    gDPPipeSync(gDisplayListHead++);

    gDPSetTexturePersp(gDisplayListHead++, G_TP_PERSP);
    gDPSetTextureFilter(gDisplayListHead++, G_TF_BILERP);
}

// Clear the faint-batch stamps for every picked Pokemon, including teammate rosters.
// BattleMon.unk_25 is written by Battle_UpdateFaintBatches when its current HP reaches zero.
void Battle_ResetFaintBatches(void) {
    s32 side_index;
    s32 trainer_index;
    s32 pokemon_index;
    TeamRoster* roster;
    BattleSessionTeams* side = &sBattleSides[0];

    for (side_index = 0; side_index < 2; side_index++, side++) {
        for (trainer_index = 0; trainer_index < side->unk_01; trainer_index++) {
            roster = side->teamMember[trainer_index];
            for (pokemon_index = 0; pokemon_index < roster->numberOfPokemonChosen; pokemon_index++) {
                roster->pokemonPicked[pokemon_index].unk_25 = 0;
            }
        }
    }
}

// called every frame: bug boy in GLC
// Stamp newly observed zero-HP Pokemon with the same batch number this frame.
// Increment once per nonempty batch, so simultaneous faints share a stamp.
void Battle_UpdateFaintBatches(void) {
    s32 side_index;
    s32 trainer_index;
    s32 pokemon_index;
    s32 found_faint = 0;
    TeamRoster* roster;
    BattleSessionTeams* side = &sBattleSides[0];

    for (side_index = 0; side_index < 2; side_index++, side++) {
        for (trainer_index = 0; trainer_index < side->unk_01; trainer_index++) {
            roster = side->teamMember[trainer_index];
            for (pokemon_index = 0; pokemon_index < roster->numberOfPokemonChosen; pokemon_index++) {
                if ((roster->pokemonPicked[pokemon_index].unk_25 == 0) && (roster->pokemonPicked[pokemon_index].unk_02 == 0)) {
                    found_faint = 1;
                    roster->pokemonPicked[pokemon_index].unk_25 = sNextFaintBatch;
                }
            }
        }
    }

    if (found_faint != 0) {
        sNextFaintBatch += 1;
    }
}

// Empty retail hook; its intended purpose is not established.
void func_84300E78(void) {
}

// Empty retail hook; its intended purpose is not established.
void func_84300E80(void) {
}

// called every frame: bug boy in GLC
// Advance simulation/presentation, capture dirty thumbnails, then draw the scene and UI.
s32 BattleScene_UpdateFrame(s32 fade_mode) {
    s32 battle_result;

    GeoRender_AdvanceFrameCounter();
    ModelAnim_UpdateFrameChangeState();
    BattleScene_DispatchLifecycle(2, sBattleSides);
    BattleScene_DispatchOwnerCameraLifecycle(2, &sSide1ThumbnailCamera, &sSide2ThumbnailCamera);
    battle_result = BattleScene_Dispatch(2, &sStageCamera);
    BattleAnim_DispatchPresentation(2, &sStageCamera);
    Battle_RenderActivePokemonThumbnail(sSide1ThumbnailRoot, sSide1PokemonThumbnail);
    Battle_RenderActivePokemonThumbnail(sSide2ThumbnailRoot, sSide2PokemonThumbnail);
    BgStage_DrawFrame();
    Battle_DrawStageBackdrop();
    Geo_RenderRootNode(sStageRoot);
    BattleScene_DispatchLifecycle(5, sBattleSides);
    Battle_FillActivePokemonThumbnail(sSide1ThumbnailRoot, sSide1PokemonThumbnail);
    Battle_FillActivePokemonThumbnail(sSide2ThumbnailRoot, sSide2PokemonThumbnail);
    Battle_UpdateFaintBatches();

    if (battle_result == 1) {
        sBattleSides[0].unk_1C = 1;
    }

    if (battle_result == 2) {
        sBattleSides[1].unk_1C = 1;
    }

    return battle_result;
}

/*
    No idea what the hell this is, it's not drawing the Run selection cursor and nothing else in battle would use START
    Stadium doesn't have pausing so it's not that either
    preliminary guess: unused pausing debug option, sIsPaused can never be 1 through the current code
*/
// Dormant frame-step path: this translation unit initializes the selector to zero
// and never sets it to one. A steps and Start resumes only while fade_mode is zero.
s32 BattleScene_UpdatePausedFrame(s32 fade_mode) {
    s32 battle_result = 0;

    if ((fade_mode == 0) && BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        battle_result = BattleScene_UpdateFrame(fade_mode);
    } else {
        ModelAnim_UpdateFrameChangeState();
        BgStage_DrawFrame();
        Battle_DrawStageBackdrop();
        Geo_RenderRootNode(sStageRoot);
        BattleScene_DispatchLifecycle(5, sBattleSides);
        Battle_FillActivePokemonThumbnail(sSide1ThumbnailRoot, sSide1PokemonThumbnail);
        Battle_FillActivePokemonThumbnail(sSide2ThumbnailRoot, sSide2PokemonThumbnail);
    }

    if ((fade_mode == 0) && BTN_IS_PRESSED(gPlayer1Controller, BTN_START)) {
        sIsPaused = 0;
    }
    return battle_result;
}

// triggers every frame: bug boy in GLC
// Count the initial two callbacks toward zero; once the gate is zero, the attract
// demo battle (mode 16) can request exit on a button press. The normal path waits for the scene result.
void Battle_UpdateCompletionGate(void) {
    if (sCompletionGate < 0) {
        sCompletionGate++;
    } else if ((sCompletionGate == 0) && (gSessionContext.mode == SESSION_MODE_ATTRACT_DEMO_BATTLE) && gPlayer1Controller->buttonPressed) {
        sCompletionGate = 1;
    }
}

// triggers every frame: bug boy in GLC
// BgStage_WaitForCondition passes the current fade mode and starts the exit fade
// after a nonzero return. Latch 2 prevents repeating the audio shutdown request.
//@src/stage_loader.c
s32 Battle_FrameCallback(s32 fade_mode) {
    s32 battle_result = 0;

    Cont_StartReadInputs();
    Trainer_RequestPokeIcon(&sBattleSides[0]);
    PokeIcon_WaitFrameLoadForObject(&sBattleSides[0]);
    Trainer_RequestPokeIcon(&sBattleSides[1]);
    PokeIcon_WaitFrameLoadForObject(&sBattleSides[1]);
    Cont_ReadInputs();
    Input_ResetRepeatState();

    switch (sIsPaused) {
        case 0:
            battle_result = BattleScene_UpdateFrame(fade_mode);
            break;

        case 1:
            battle_result = BattleScene_UpdatePausedFrame(fade_mode);
            break;
    }

    if ((battle_result != 0) && (sCompletionGate <= 0)) {
        sCompletionGate = 1;
    }

    Battle_UpdateCompletionGate();
    PokeIcon_RequestBackgroundForObject(&sBattleSides[0]);
    PokeIcon_RequestBackgroundForObject(&sBattleSides[1]);

    if ((fade_mode != 2) && (sCompletionGate == 1)) {
        sCompletionGate = 2;
        func_8003DB84(0);
        if (gSessionContext.mode != 0x11) {
            Audio_FadeOutAll(0x1E);
        }
        return 1;
    }
    return 0;
}

// triggers on battle start: bug boy in glc
// Preserve the picked prefix and append missing roster indices 0..5 in order.
// This completes the copy order; it does not choose additional battle participants.
void Battle_CompleteRosterOrder(u8* roster_order, s32 number_of_pokemon_picked) {
    s32 roster_index;
    s32 picked_index;

    for (roster_index = 0; roster_index < 6; roster_index++) {
        for (picked_index = 0; picked_index < number_of_pokemon_picked; picked_index++) {
            if (roster_index == roster_order[picked_index]) {
                break;
            }
        }

        if (picked_index == number_of_pokemon_picked) {
            roster_order[number_of_pokemon_picked++] = roster_index;
        }
    }
}

// triggers on battle start: bug boy in glc
// Ask the COM selection routine for the picked prefix, then copy the brought
// roster in that order. numberOfPokemonChosen keeps only the prefix length.
//@src/fragments/battle_engine/battle_engine_361050.c
void Battle_SelectComRoster(void) {
    TeamRoster* com_roster;
    TeamRoster* player_roster;
    u8 order_of_picked_pokemon[8];
    TeamRoster* player_teammate_roster;
    s32 i;
    s32 number_of_pokemon_picked;

    player_roster = gSessionContext.battleSides[0].teamMember[0];
    // In Free Battle Team Battle, side 0 can have a second allied trainer in teamMember[1].
    player_teammate_roster = gSessionContext.battleSides[0].teamMember[1];
    com_roster = gSessionContext.battleSides[1].teamMember[0];

    if (com_roster->unk_000 & 2) {
        // Free Battle can consider both allied trainers; other modes pass only one.
        if (gSessionContext.mode == SESSION_MODE_ANYTHING_GOES) {
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
        Battle_CompleteRosterOrder(order_of_picked_pokemon, number_of_pokemon_picked);
        com_roster->numberOfPokemonChosen = number_of_pokemon_picked;

        for (i = 0; i < com_roster->rosterInfo->numberOfPokemonCanBePicked; i++) {
            com_roster->pokemonPicked[i] = com_roster->rosterInfo->unk_028[order_of_picked_pokemon[i]];
        }
    }
}

// triggers at the start of battle: bug boy in glc
// Seed icon/presentation state from the side's first trainer and first picked Pokemon.
void BattleScene_InitializeParticipantPresentation(BattleSessionTeams* side, unk_D_86002F30* model) {
    TeamRoster* first_trainer = side->teamMember[0];

    side->unk_18 = model->unk_08->unk_00[0];
    side->sessionIsBusy |= 0xA0;
    side->unk_1C = 0;
    side->unk_02 = first_trainer->pokemonPicked[0].unk_00.unk_00;
    side->unk_04 = first_trainer->pokemonPicked;
    Trainer_RequestPokeIcon(side);
}

// triggers at the start of battle: bug boy in glc
// Allocate thumbnail targets, load the mode/ruleset arena, and construct all three roots.
void BattleScene_Init(unk_func_80007444* stage_context) {
    MemoryBlock* layout_pool;
    u32* stage_layout;
    FragmentEntry arena_entry;
    unk_D_8690A610_018* fog_parameters;
    s32 pad;
    s16 arena_index;
    DepthBuffer* thumbnail_depth;
    unk_D_86002F30* model;

    Battle_SetStageTintColor(0xFF, 0xFF, 0xFF);
    Battle_SetStageScale(1.0f);

    if (gSessionContext.mode == 0x11) {
        Font_Init(4, 0);
    } else if (gSessionContext.mode == SESSION_MODE_ATTRACT_DEMO_BATTLE) {
        Font_Init(7, 0);
    } else {
        Font_Init(3, 0);
    }

    sBattleSides[0].unk_10 = PokeIcon_AllocFramebuffers(3);
    sBattleSides[1].unk_10 = PokeIcon_AllocFramebuffers(3);
    PokeIcon_OpenModelArchives();

    thumbnail_depth = main_pool_alloc(0x10, 0);
    GfxImage_Initialize(thumbnail_depth, 0, 2, 0x4C, 0x4C, stage_context->unk_18[0]->depth_p->img_p);
    sSide1PokemonThumbnail = GfxImage_Allocate(0, 2, 0x4C, 0x4C, 0);
    sSide2PokemonThumbnail = GfxImage_Allocate(0, 2, 0x4C, 0x4C, 0);

    GfxImage_AttachDepthBuffer(sSide1PokemonThumbnail, thumbnail_depth);
    GfxImage_AttachDepthBuffer(sSide2PokemonThumbnail, thumbnail_depth);

    sSide1PokemonThumbnailImage = sSide1PokemonThumbnail->img_p;
    sSide2PokemonThumbnailImage = sSide2PokemonThumbnail->img_p;

    FRAGMENT_LOAD(FRAGMENT_PARTICLE_DATA_LIBRARY);
    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_3000000, battle_ui, 0);

    // Modes 16/10 use the ruleset as the arena key; other modes use the mode itself.
    // Castle key 7 adds the selected location to the table's base entry.
    if ((gSessionContext.mode == SESSION_MODE_ATTRACT_DEMO_BATTLE) || (gSessionContext.mode == SESSION_MODE_EVENT_BATTLE)) {
        arena_index = sBattleModeDispatch[gSessionContext.ruleCategory];
        if (gSessionContext.ruleCategory == RULE_CATEGORY_GYM_LEADER_CASTLE) {
            arena_index += gSessionContext.modeSelection;
        }
    } else {
        arena_index = sBattleModeDispatch[gSessionContext.mode];
        if (gSessionContext.mode == SESSION_MODE_GYM_LEADER_CASTLE) {
            arena_index += gSessionContext.modeSelection;
        }
    }

    arena_entry = BinArchive_GetFile(ASSET_LOAD2(stadium_models, 1, 1), arena_index);
    sStageBackdrop = arena_entry(2, 0);

    model = Model_LoadByArchiveIndex(0x9A);
    Battle_SelectComRoster();
    BattleScene_InitializeParticipantPresentation(&sBattleSides[0], model);
    BattleScene_InitializeParticipantPresentation(&sBattleSides[1], model);

    Battle_ResetFaintBatches();
    GeoNode_CreateCamera(NULL, &sStageCamera, 0, 0, 0x140, 0xF0);
    GeoNode_CreateCamera(NULL, &sSide1ThumbnailCamera, 0x1E, 0x50, 0x4C, 0x4C);
    GeoNode_CreateCamera(NULL, &sSide2ThumbnailCamera, 0xE2, 0x50, 0x4C, 0x4C);
    GeoNode_CreateFog(0, &sStageFog, 0x3C0, 0x3E8, 0xFF, 0xFF, 0xFF, 0xFF);
    GeoNode_CreateContainer(NULL, &sStageLayout0);
    GeoNode_CreateContainer(NULL, &sStageLayout1);
    GeoNode_CreateContainer(NULL, &sStageLayout3);
    GeoCamera_SetPerspective(&sStageCamera, 30.0f, 192.0f, 24576.0f);
    ModelRenderer_InitDisplayRoots();
    BattleScene_DispatchLifecycle(0, sBattleSides);
    BattleScene_DispatchOwnerCameraLifecycle(0, &sSide1ThumbnailCamera, &sSide2ThumbnailCamera);
    BattleScene_Dispatch(0, &sStageCamera);
    BattleAnim_DispatchPresentation(0, &sStageCamera);

    layout_pool = MainPool_AllocState(main_pool_get_available(), 0);
    sStageRoot = process_geo_layout(layout_pool, sStageGeoLayout);
    sSide1ThumbnailRoot = process_geo_layout(layout_pool, sSide1ThumbnailLayout);
    sSide2ThumbnailRoot = process_geo_layout(layout_pool, sSide2ThumbnailLayout);

    // Selectors 0, 1, and 3 each attach geometry beneath a stage tint/scale callback.
    stage_layout = arena_entry(0, 0);
    if (stage_layout != NULL) {
        GraphNode_AppendChild(&sStageLayout0, process_geo_layout(layout_pool, stage_layout));
    }

    stage_layout = arena_entry(1, 0);
    if (stage_layout != NULL) {
        GraphNode_AppendChild(&sStageLayout1, process_geo_layout(layout_pool, stage_layout));
    }

    stage_layout = arena_entry(3, 0);
    if (stage_layout != NULL) {
        GraphNode_AppendChild(&sStageLayout3, process_geo_layout(layout_pool, stage_layout));
    }

    MainPool_FinalizeAllocation(layout_pool);

    // callbackArg records whether this arena supplied fog, for Battle_SetStageTintColor.
    fog_parameters = arena_entry(4, 0);
    if (fog_parameters == NULL) {
        sStageFog.node.callbackArg = 0;
        sStageFog.node.flags &= ~1;
    } else {
        sStageFog.unk_18.unk_00 = fog_parameters->unk_00;
        sStageFog.unk_18.unk_02 = fog_parameters->unk_02;
        sStageFog.unk_18.unk_04.rgba = fog_parameters->unk_04.rgba;
        sStageFog.node.callbackArg = 1;
    }

    BattleScene_DispatchLifecycle(3, sBattleSides);
    BattleScene_DispatchOwnerCameraLifecycle(3, &sSide1ThumbnailCamera, &sSide2ThumbnailCamera);
    BattleScene_Dispatch(3, &sStageCamera);
    BattleAnim_DispatchPresentation(3, &sStageCamera);

    sNextFaintBatch = 1;
    sIsPaused = 0;
}

// Empty retail hook; no purpose is established by callers in this fragment.
void func_84301A24(void) {
}

// triggers at the start of battle, battle init
// The fragment entry uses global session state; both entry arguments are unused.
// Pool state BATL owns the scene allocations until the fade-driven loop completes.
s32 Battle_Main(s32 arg0, SessionContext* arg1) {
    unk_func_80007444* stage_context;

    sBattleSides = gSessionContext.battleSides;
    sCompletionGate = -2;

    main_pool_push_state('BATL');

    Gfx_InitDisplayListBuffers(0x20000, 0);
    stage_context = StageContext_Allocate(0, 1, 3, 1, 2, 1);
    BattleScene_Init(stage_context);
    StageContext_Activate(stage_context);
    StageLoader_RunFrames(1);
    BgStage_WaitForCondition(Battle_FrameCallback, 0x20, 0x10);
    StageLoader_RunFrames(2);
    StageContext_Deactivate();
    Gfx_FreeDisplayListBuffers();

    main_pool_pop_state('BATL');

    return 0;
}
