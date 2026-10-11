#include "demo_scenes.h"
#include "src/geo_node.h"
#include "src/geo_render.h"
#include "src/model_animation_events.h"
#include "src/geo_layout.h"
#include "src/display_object_textures.h"
#include "src/model_renderer.h"
#include "src/graphics_textures.h"
#include "src/input.h"
#include "src/game_state.h"
#include "src/jpeg_stream.h"
#include "src/audio_loop_point.h"
#include "src/audio_commands_category2.h"
#include "src/gfx_buffer.h"
#include "src/gfx_rect.h"
#include "src/matrix.h"
#include "src/controller.h"
#include "src/fragments/minigame_actor_framework/minigame_actor_framework.h"
#include "src/fragments/particle_math/particle_math.h"
#include "src/memory.h"
#include "src/stage_loader.h"
#include "src/util.h"
#include "src/gb_save.h"

extern u8 D_3000180[];
extern u8 D_3000780[];
extern u8 D_3001220[];
extern u8 D_3001B80[];
extern u8 D_30024E0[];
extern u8 D_30032A0[];
extern u8 D_3004060[];
extern u8 D_3004E20[];
extern u8 D_3005780[];
extern u8 D_30060E0[];
extern u8 D_3006B80[];
extern u8 D_300C6D0[];

s32 Intro_LightAngleCallbackA(s32, GraphNode*);
s32 Intro_LightAngleCallbackB(s32, GraphNode*);
s32 Intro_FogColorCallback(s32, GraphNode*);

typedef struct unk_D_86B0DD58 {
    /* 0x00 */ u8 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
} unk_D_86B0DD58; // size = 0xC

static unk_D_86B0DAE0_000 D_86B0DCE0[4] = {
    {
        0x00FF,
        0x00E1,
        0x0000,
        0x0000,
        0x0000,
        0x0000,
        0x0000,
        0x0000,
        0x0000,
        0x0000,
        0x0000,
        0x0000,
    },
    {
        0x00FF,
        0x00FF,
        0x00FF,
        0x00FF,
        0x00FF,
        0x0064,
        0x00FF,
        0x0007,
        0x0040,
        0x0040,
        0x0040,
        0x0019,
    },
    {
        0x00FF,
        0x00FF,
        0x009B,
        0x009B,
        0x009B,
        0x0000,
        0x00FF,
        0x00FF,
        0x0032,
        0x0032,
        0x0032,
        0x0032,
    },
    {
        0x00FF,
        0x00FF,
        0x00FF,
        0x00FF,
        0x00FF,
        0x0064,
        0x00FF,
        0x00FF,
        0x0080,
        0x0080,
        0x0080,
        0x0032,
    },
};
static u8 D_86B0DD40[] = {
    0, 0xFF, 0, 0xE1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0xFF, 0, 3, 0, 0x11, 0, 0x11, 0, 0x11, 0, 7,
};

static unk_D_86B0DD58 D_86B0DD58[20] = {
    { 0xA7, 47.5f, 30.0f }, { 0xA8, 47.5f, 30.0f }, { 0xA9, 47.5f, 30.0f }, { 0xAA, 47.5f, 30.0f },
    { 0xA5, 66.5f, 85.0f }, { 0xA5, 66.5f, 85.0f }, { 0xA7, 0.0f, 0.0f },   { 0xA7, 0.0f, 0.0f },
    { 0xA7, 0.0f, 0.0f },   { 0xA7, 0.0f, 0.0f },   { 0xA7, 0.0f, 0.0f },   { 0xA7, 0.0f, 0.0f },
    { 0xA7, 0.0f, 0.0f },   { 0xA7, 0.0f, 0.0f },   { 0xA7, 0.0f, 0.0f },   { 0xA7, 0.0f, 0.0f },
    { 0xA7, 0.0f, 0.0f },   { 0xA7, 0.0f, 0.0f },   { 0xA7, 0.0f, 0.0f },   { 0xA7, 0.0f, 0.0f },
};

static u8 gStageModelIndices[] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x11, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
};

static unk_D_8690A610 D_86B0F9D0;
static DisplayNodeHeader D_86B0F9F0;
static DisplayNodeHeader D_86B0FA08;
static DisplayNodeHeader D_86B0FA20;
static u32 D_86B0FA38;
static Color_RGBA8_u32 D_86B0FA3C;
static u8 D_86B0FA40;
static s16 D_86B0FA42;
static s16 D_86B0FA44;
static s16 D_86B0FA46;
static f32 D_86B0FA48;
static void* D_86B0FA4C;
static unk_D_86B0FA50* D_86B0FA50;
static unk_D_86B0FA50* D_86B0FA54;
static unk_D_86B0FA50* D_86B0FA58;
static unk_D_86B0FA50* D_86B0FA5C;
static unk_D_86B0FA50* D_86B0FA60;
static s16 D_86B0FA64;
static s16 D_86B0FA66;
static s16 D_86B0FA68;
static f32 D_86B0FA6C;
static s32 D_86B0FA70;
static s32 D_86B0FA74;
unk_D_86B0FA78* D_86B0FA78;
unk_D_86B0FA7C* D_86B0FA7C;
static u8 D_86B0FA80[0xBE0];
unk_70D3A0 D_86B10660;
static unk_D_70B10 D_86B10670;
static TeamRoster* D_86B10690;
static BattleSessionTeams* D_86B10694;

static u32 D_86B0DE5C[] = {
    0x0C00FFFF, 0x05000000,    0x0B00001E,  0x00000000,    0x014000F0,  0x0000000F,  0x00000000, 0x00000000,
    0x05000000, 0x0D000000,    0x05000000,  0x07000000,    &D_86B0F9D0, 0x14000000,  0x002D0019, 0xFFFFFF28,
    0x08000000, Intro_LightAngleCallbackA, 0x00000000,  0x14000000,    0x002D0019,  0x80808028,  0x08000000, Intro_LightAngleCallbackB,
    0x00000000, 0x16646464,    0x0F000002,  0x05000000,    0x1F00FFFF,  0x00000000,  0x00000000, 0x00000000,
    0x00640064, 0x00640000,    0x08000000,  Intro_FogColorCallback, 0x00000000,  0x05000000,  0x07000000, &D_86B0F9F0,
    0x06000000, 0x06000000,    0x0F000003,  0x05000000,    0x1F00FFFF,  0x00000000,  0x00000000, 0x00000000,
    0x00640064, 0x00640000,    0x08000000,  Intro_FogColorCallback, 0x00000000,  0x05000000,  0x07000000, &D_86B0FA08,
    0x06000000, 0x06000000,    0x0F000002,  0x05000000,    0x1F00FFFF,  0x00000000,  0x00000000, 0x00000000,
    0x00640064, 0x00640000,    0x08000000,  Intro_FogColorCallback, 0x00000000,  0x05000000,  0x07000000, &D_86B0FA20,
    0x06000000, 0x06000000,    0x0F000003,  0x05000000,    0x0A000000,  &D_800AC840, 0x06000000, 0x0F000002,
    0x05000000, 0x0A000000,    &D_800AC858, 0x06000000,    0x09000000,  0x06000000,  0x06000000, 0x06000000,
    0x01000000,
};

s32 Intro_LightAngleCallbackA(s32 arg0, GraphNode* arg1) {
    unk_D_86002F34_alt18* ptr = (unk_D_86002F34_alt18*)arg1;
    f32 sp28;
    s16 sp26;
    s16 sp24;

    if (arg0 == 2) {
        Vec3f_CalculateDistanceAngles(&D_8006F088->unk_60.at, &D_8006F088->unk_60.eye, &sp28, &sp26, &sp24);
        ptr->unk_1C = sp26 + 0x2000;
        ptr->unk_1E = sp24 - 0x2000;
    }

    return 0;
}

s32 Intro_LightAngleCallbackB(s32 arg0, GraphNode* arg1) {
    unk_D_86002F34_alt18* ptr = (unk_D_86002F34_alt18*)arg1;
    f32 sp28;
    s16 sp26;
    s16 sp24;

    if (arg0 == 2) {
        Vec3f_CalculateDistanceAngles(&D_8006F088->unk_60.at, &D_8006F088->unk_60.eye, &sp28, &sp26, &sp24);
        ptr->unk_1C = -0x2000 - sp26;
        ptr->unk_1E = sp24 + 0x6000;
    }

    return 0;
}

s32 Intro_FogColorCallback(s32 arg0, GraphNode* arg1) {
    DisplayObject* ptr = (DisplayObject*)arg1;

    if (arg0 == 2) {
        ptr->textureTint.rgba = D_86B0FA3C.rgba;
    }

    return 0;
}

void Intro_SetBackgroundTint(u8 arg0, u8 arg1, u8 arg2) {
    u8 v = arg0 & arg1 & arg2;

    D_86B0FA3C.r = arg0;
    D_86B0FA3C.g = arg1;
    D_86B0FA3C.b = arg2;

    if (v == 0xFF) {
        if (D_86B0F9D0.node.callbackArg == 1) {
            D_86B0F9D0.node.flags |= 1;
        }
    } else {
        D_86B0F9D0.node.flags &= ~1;
    }
}

void Intro_LoadPokemonTextures(void) {
    UNUSED s32 pad[2];
    u8* sp24;
    u8* temp_a1;
    u8* sp1C;

    temp_a1 = (u32)_70D3A0_ROM_START + (D_80075BD0[D_86B0FA78->unk_174 - 1] & 0xFFFFFF);
    sp24 = (u32)_70D3A0_ROM_START +
           ((((D_86B0FA78->unk_174 ^ 0) * sizeof(unk_D_70B10)) - sizeof(unk_D_70B10) + (u32)D_70B10) & 0xFFFFFF);
    sp1C = (u32)_70D3A0_ROM_START +
           (((D_86B0FA78->unk_174 * sizeof(unk_70D3A0)) - sizeof(unk_70D3A0) + (u32)D_70110) & 0xFFFFFF);

    Dma_WriteChunks(D_86B0FA80, temp_a1, temp_a1 + 0xBC0, 0);
    Dma_WriteChunks(&D_86B10660, sp1C, sp1C + sizeof(unk_70D3A0), 0);
    Dma_WriteChunks(&D_86B10670, sp24, sp24 + sizeof(unk_D_70B10), 0);
}

void Intro_LoadShowcaseModel(void) {
    D_86B0FA78->unk_174 = D_86B10690->unk_01C[D_86B0FA78->unk_17C].unk_00.unk_00;
    ModelRenderer_AttachDisplayObject(&D_86B0FA78->unk_004);
    PokeIcon_OpenModelArchives();

    D_86B0FA78->unk_000 = Model_LoadForPokemon(&D_86B10690->unk_01C[D_86B0FA78->unk_17C]);
    Model_InitDisplayObject(&D_86B0FA78->unk_004, 0, D_86B0FA78->unk_174, D_86B0FA78->unk_000->unk_08->unk_00[0]);
    ModelAnim_SetAnimation(&D_86B0FA78->unk_004, 0);
    D_86B0FA78->unk_004.effectSlot = 0;
    Intro_LoadPokemonTextures();
    D_86B0FA78->unk_004.position.y += D_86B10660.unk_08;
    D_86B0FA78->unk_170 = 0;
    ModelAnim_SetEventFrame(&D_86B0FA78->unk_004, 0);
    ModelAnim_SetEventTrack(&D_86B0FA78->unk_004, -1);
}

void Intro_ReplaceShowcaseModel(void) {
    ModelRenderer_ClearDisplayObject(&D_86B0FA78->unk_004);

    main_pool_pop_state('MONS');

    main_pool_push_state('MONS');

    Intro_LoadShowcaseModel();
}

void Intro_SetupOrbitCamera(void) {
    D_86B0FA7C->unk_00->unk_24.fovy = 30.0f;
    D_86B0FA7C->unk_00->unk_24.near = 30.0f;
    D_86B0FA7C->unk_00->unk_24.far = 6400.0f;
    Intro_ComputeFollowPoint(D_86B0FA78, &D_86B0FA7C->unk_04);
    Intro_LoadCameraKeyframe(&D_86B0E040[D_86B0FA78->unk_17C], D_86B0FA7C->unk_00);
    Intro_UpdateOrbitCamera();
}

void Intro_LoadStageModel(void) {
    ModelRenderer_ClearDisplayObject(&D_86B0FA78->unk_004);

    main_pool_pop_state('MONS');

    main_pool_push_state('MONS');

    D_86B0FA78->unk_174 = D_86B0DD58[D_86B0FA44].unk_00;
    ModelRenderer_AttachDisplayObject(&D_86B0FA78->unk_004);
    PokeIcon_OpenModelArchives();
    D_86B0FA78->unk_000 = Model_LoadByArchiveIndex(D_86B0FA78->unk_174);
    Model_InitDisplayObject(&D_86B0FA78->unk_004, 0, D_86B0FA78->unk_174, D_86B0FA78->unk_000->unk_08->unk_00[0]);
    ModelAnim_SetAnimation(&D_86B0FA78->unk_004, 0);
    Vec3f_SetComponentsDuplicate(&D_86B0FA78->unk_004.position, 0.0f, 300.0f, 0.0f);
}

void Intro_SetupStaticCamera(void) {
    D_86B0FA46 = 0;
    D_86B0FA48 = 0.0f;
    D_86B0FA7C->unk_00->unk_24.fovy = 40.0f;
    D_86B0FA7C->unk_00->unk_24.near = 30.0f;
    D_86B0FA7C->unk_00->unk_24.far = 6400.0f;

    Vec3f_SetComponentsDuplicate(&D_86B0FA7C->unk_00->unk_60.at, D_86B0FA78->unk_004.position.x,
                  D_86B0DD58[D_86B0FA44].unk_04 + D_86B0FA78->unk_004.position.y, D_86B0FA78->unk_004.position.z);

    if ((D_86B0FA44 == 4) || (D_86B0FA44 == 5)) {
        Vec3f_SetComponentsDuplicate(&D_86B0FA7C->unk_00->unk_60.eye, 0, 100.0f, 328.0f);
    } else {
        Vec3f_SetComponentsDuplicate(&D_86B0FA7C->unk_00->unk_60.eye, 0, 100.0f, 250.0f);
    }
}

s32 Intro_StepRotationOvershoot(DisplayObject* arg0, s16 arg1, s16 arg2) {
    if (arg1 > 0) {
        arg0->rotation.y -= arg1;
        if ((arg0->rotation.y < arg2) && ((arg2 - arg1) < arg0->rotation.y)) {
            return 1;
        }
    } else {
        arg0->rotation.y -= arg1;
        if ((arg2 < arg0->rotation.y) && (arg0->rotation.y < (arg2 - arg1))) {
            return 1;
        }
    }
    return 0;
}

s32 Intro_StepRotationToTarget(DisplayObject* arg0, s16 arg1, s16 arg2) {
    if ((((arg0->rotation.y - arg2) / 182) < 0x3D) && (((arg0->rotation.y - arg2) / 182) >= 0)) {
        arg1 = (arg0->rotation.y - arg2) / 9;
    }
    arg0->rotation.y -= arg1;

    if (arg1 > 0) {
        if ((arg2 >= arg0->rotation.y) && (arg0->rotation.y >= (arg2 - arg1))) {
            arg0->rotation.y = arg2;
            return 1;
        }
    } else if ((arg0->rotation.y >= arg2) && ((arg2 - arg1) >= arg0->rotation.y)) {
        arg0->rotation.y = arg2;
        return 1;
    }
    return 0;
}

s32 Intro_UpdateModelLanding(void) {
    if (D_86B0FA46 < 3) {
        if ((D_86B0FA46 <= 0) && (Intro_StepRotationOvershoot(&D_86B0FA78->unk_004, 0x71C, 0) != 0)) {
            D_86B0FA46++;
        }

        if ((D_86B0FA46 > 0) && (Intro_StepRotationToTarget(&D_86B0FA78->unk_004, 0x71C, 0) != 0)) {
            D_86B0FA46++;
        }
    }

    Math_EaseTowardF(&D_86B0FA48, 0.1f, 0.02f);
    Math_EaseTowardF(&D_86B0FA78->unk_004.position.y, 0.0f, D_86B0FA48);

    if (D_86B0FA78->unk_004.position.y <= 0.25f) {
        D_86B0FA78->unk_004.position.y = 0.0f;
    }

    Vec3f_SetComponentsDuplicate(&D_86B0FA7C->unk_00->unk_60.at, D_86B0FA78->unk_004.position.x,
                  D_86B0DD58[D_86B0FA44].unk_04 + D_86B0FA78->unk_004.position.y, D_86B0FA78->unk_004.position.z);

    if (D_86B0FA78->unk_004.position.y <= 0.5f) {
        return 1;
    }
    return 0;
}

void Intro_EmitLandingParticles(void) {
    Vec3f sp44;

    if (D_86B0FA40 == 0) {
        D_86B0FA40 = 1;
        Audio_PlayCategory11SoundCommand(0x0110000F, 0, 0);
    }

    if (D_86B0FA78->unk_178 & 1) {
        Vec3f_SetComponentsDuplicate(&sp44, D_86B0FA78->unk_004.position.x,
                      D_86B0DD58[D_86B0FA44].unk_08 + (MathUtil_RandomU16Range(0x28) - 0x14), D_86B0FA78->unk_004.position.z);
        Particle_EmitBurstAtTransform(1.0f, sp44, D_86B0FA78->unk_004.rotation, MiniFx_UpdatePalette17DelayedRevealFallParticle, &gMiniFxParticleDescriptorIa8Variant, 1);

        if ((D_86B0FA78->unk_178 >= 0xA) && (D_86B0FA78->unk_178 & 1)) {
            Vec3f_SetComponentsDuplicate(&sp44, D_86B0FA78->unk_004.position.x,
                          D_86B0DD58[D_86B0FA44].unk_08 + (MathUtil_RandomU16Range(0x28) - 0x14), D_86B0FA78->unk_004.position.z);
            Particle_EmitBurstAtTransform(1.0f, sp44, D_86B0FA78->unk_004.rotation, MiniFx_UpdatePalette17DelayedRevealFallParticle, &gMiniFxParticleDescriptorIa8Variant, 1);
        }

        if ((D_86B0FA78->unk_178 >= 0x14) && (D_86B0FA78->unk_178 & 1)) {
            Vec3f_SetComponentsDuplicate(&sp44, D_86B0FA78->unk_004.position.x,
                          D_86B0DD58[D_86B0FA44].unk_08 + (MathUtil_RandomU16Range(0x28) - 0x14), D_86B0FA78->unk_004.position.z);
            Particle_EmitBurstAtTransform(1.0f, sp44, D_86B0FA78->unk_004.rotation, MiniFx_UpdatePalette17DelayedRevealFallParticle, &gMiniFxParticleDescriptorIa8Variant, 1);
        }

        if ((D_86B0FA78->unk_178 >= 0x1E) && (D_86B0FA78->unk_178 & 1)) {
            Vec3f_SetComponentsDuplicate(&sp44, D_86B0FA78->unk_004.position.x,
                          D_86B0DD58[D_86B0FA44].unk_08 + (MathUtil_RandomU16Range(0x28) - 0x14), D_86B0FA78->unk_004.position.z);
            Particle_EmitBurstAtTransform(1.0f, sp44, D_86B0FA78->unk_004.rotation, MiniFx_UpdatePalette17DelayedRevealFallParticle, &gMiniFxParticleDescriptorIa8Variant, 1);
        }
    }
}

void Intro_FadeInBackgroundTint(void) {
    D_86B0FA78->unk_180 = Math_StepToF(D_86B0FA78->unk_180, 100.0f, 2.0f, 2.0f);
    Intro_SetBackgroundTint(D_86B0FA78->unk_180, D_86B0FA78->unk_180, D_86B0FA78->unk_180);
}

void Intro_UpdateCryEventTrack(void) {
    if (((D_86B0FA78->unk_178 % 50) == 0) && (D_86B0FA78->unk_170 == 0) && (D_86B0FA80[0xA51] != 0xFF)) {
        ModelAnim_ClearEventTrack(&D_86B0FA78->unk_004);
        ModelAnim_SetEventTrack(&D_86B0FA78->unk_004, D_86B0FA80[0xA51]);
        D_86B0FA78->unk_170 = 1;
    } else if ((D_86B0FA78->unk_170 == 1) && (ModelAnim_IsEventTrackNearEnd(&D_86B0FA78->unk_004) == 1)) {
        D_86B0FA78->unk_170 = 0;
        ModelAnim_SetEventFrame(&D_86B0FA78->unk_004, 0);
        ModelAnim_SetEventTrack(&D_86B0FA78->unk_004, -1);
    }
}

void Intro_SetupTextPanel(unk_D_86B0FA50* arg0, u8* arg1, f32 arg2, s16 arg3, s16 arg4, s16 arg5) {
    arg0->unk_80 = arg1;
    arg0->unk_98 = arg2;
    arg0->unk_9C = arg3;
    arg0->unk_9E = arg4;
    arg0->unk_A0 = arg5;

    arg0->unk_88 = 0;
    arg0->unk_8C = 0;
    arg0->unk_84 = 0;
    arg0->unk_A4 = 0;
    arg0->unk_AC = 0.0f;

    arg0->unk_B0.unk_00 = D_86B0DCE0->unk_00;
    arg0->unk_B0.unk_02 = D_86B0DCE0->unk_02;
    arg0->unk_B0.unk_04 = D_86B0DCE0->unk_04;
    arg0->unk_B0.unk_06 = D_86B0DCE0->unk_06;
    arg0->unk_B0.unk_08 = D_86B0DCE0->unk_08;
    arg0->unk_B0.unk_0A = D_86B0DCE0->unk_0A;
}

void Intro_ConfigureTextPanels(void) {
    if (D_800AE540.unk_11F2 == 1) {
        Intro_SetupTextPanel(D_86B0FA60, &D_300C6D0, -250.0f, 0xC8, 0x18, 0x18);
    }

    Intro_SetupTextPanel(D_86B0FA54, &D_3000180, -250.0f, 0xC8, 0x40, 0x18);

    if (D_800AE540.unk_0002 == 0) {
        Intro_SetupTextPanel(D_86B0FA5C, &D_30060E0, -170.0f, 0x3C, 0x88, 0x14);
    } else if (D_800AE540.unk_0002 == 1) {
        Intro_SetupTextPanel(D_86B0FA5C, &D_3006B80, -170.0f, 0x3C, 0x78, 0x14);
    } else if (D_800AE540.unk_0002 == 2) {
        Intro_SetupTextPanel(D_86B0FA5C, &D_3004E20, -170.0f, 0x3C, 0x78, 0x14);
    } else if (D_800AE540.unk_0002 == 3) {
        Intro_SetupTextPanel(D_86B0FA5C, &D_3005780, -170.0f, 0x3C, 0x78, 0x14);
    }

    switch (D_800AE540.unk_0001) {
        case 1:
            Intro_SetupTextPanel(D_86B0FA58, &D_30024E0, -100.0f, 0x1E, 0xB0, 0x14);
            break;

        case 2:
            Intro_SetupTextPanel(D_86B0FA58, &D_30032A0, -100.0f, 0x1E, 0xB0, 0x14);
            break;

        case 3:
            Intro_SetupTextPanel(D_86B0FA58, &D_3004060, -100.0f, 0x1E, 0xB0, 0x14);
            break;

        case 4:
            Intro_SetupTextPanel(D_86B0FA58, &D_3000780, -100.0f, 0x1E, 0x88, 0x14);
            break;

        case 5:
            Intro_SetupTextPanel(D_86B0FA58, &D_3001220, -100.0f, 0x1E, 0x78, 0x14);
            break;

        case 6:
            Intro_SetupTextPanel(D_86B0FA58, &D_3001B80, -100.0f, 0x1E, 0x78, 0x14);
            break;

        default:
            Intro_SetupTextPanel(D_86B0FA58, &D_30024E0, -100.0f, 0x1E, 0xB0, 0x14);
            break;
    }
}

void Intro_StartFirstShowcase(void) {
    D_86B0FA78->unk_16C = 0;
    D_86B0FA78->unk_17C = 0;
    D_86B0FA78->unk_174 = 0;

    main_pool_push_state('MONS');

    Intro_LoadShowcaseModel();
}

void Intro_BeginOrbitCamera(void) {
    D_86B0FA7C->unk_00 = D_87906050->node.children;
    D_87906054 = D_86B0FA7C->unk_00;
    Intro_SetupOrbitCamera();
}

void Intro_StartFinalStageModel(void) {
    D_86B0FA78->unk_16C = 6;
    D_86B0FA78->unk_17C = 6;
    D_86B0FA78->unk_174 = 0;

    main_pool_push_state('MONS');

    Intro_LoadStageModel();
}

void Intro_BeginStaticCamera(void) {
    D_86B0FA7C->unk_00 = D_87906050->node.children;
    D_87906054 = D_86B0FA7C->unk_00;
    Intro_SetupStaticCamera();
}

void Intro_TriggerTextPanelExit(void) {
    D_86B0FA50->unk_90 = 3;
}

void Intro_SelectPartyRoster(void) {
    if (D_800AE540.unk_1194[0].unk_1C == 1) {
        D_86B10690 = D_800AE540.unk_1194[0].unk_08[0];
        D_86B10694 = &D_800AE540.unk_1194[0];
    } else {
        D_86B10690 = D_800AE540.unk_1194[1].unk_08[0];
        D_86B10694 = &D_800AE540.unk_1194[1];
    }
}

void Intro_ReadControllerInput(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    Input_ResetRepeatState();
}

s32 Intro_UpdateShowcaseSequence(void) {
    switch (D_86B0FA78->unk_16C) {
        case 0:
            Intro_SetupOrbitCamera();
            Intro_UpdateCameraKeyframe(D_86B0FA7C->unk_00);
            D_86B0FA78->unk_170 = 0;
            D_86B0FA78->unk_16C += 1;
            break;

        case 1:
            Intro_UpdateCryEventTrack();
            if (D_86B0FA78->unk_178++ == 0x19) {
                D_86B0FA50->unk_90 = 0;
            }

            if (Intro_UpdateCameraKeyframe(D_86B0FA7C->unk_00) != 0) {
                if ((D_800AE540.unk_0001 == 7) && (D_86B0FA78->unk_17C == 5)) {
                    return 1;
                }
                WipeTransition_Start(3, 0x1E);
                D_86B0FA78->unk_16C += 1;
            }
            break;

        case 2:
            WipeTransition_Update();
            if (WipeTransition_GetState() == 1) {
                D_86B0FA78->unk_17C++;
                if (D_86B0FA78->unk_17C == 6) {
                    D_86B0FA78->unk_170 = 0;
                    Intro_LoadStageModel();
                    Intro_SetupStaticCamera();
                    D_86B0FA50->unk_90 = 3;
                    D_86B0FA78->unk_178 = 0;
                    WipeTransition_Start(2, 0x1E);
                    D_86B0FA78->unk_16C = 6;
                } else {
                    D_86B0FA78->unk_170 = 0;
                    Intro_ReplaceShowcaseModel();
                    Intro_SetupOrbitCamera();
                    D_86B0FA50->unk_90 = 3;
                    D_86B0FA78->unk_178 = 0;
                    WipeTransition_Start(2, 0x1E);
                    D_86B0FA78->unk_16C++;
                }
            }
            break;

        case 3:
            WipeTransition_Update();
            if (D_86B0FA78->unk_178++ > 0) {
                Intro_UpdateCameraKeyframe(D_86B0FA7C->unk_00);
            }

            if (WipeTransition_GetState() == 0) {
                D_86B0FA78->unk_178 = 0;
                D_86B0FA78->unk_16C = 1;
            }
            break;

        case 6:
            D_86B0FA78->unk_180 = 0xFF;
            WipeTransition_Update();
            Intro_UpdateModelLanding();
            if (WipeTransition_GetState() == 0) {
                D_86B0FA78->unk_16C++;
            }
            break;

        case 7:
            if (Intro_UpdateModelLanding() != 0) {
                D_86B0FA78->unk_178 = 0;
                D_86B0FA50->unk_90 = 0;
                Audio_PlayCategory11SoundCommand(0x01100002, 0, 0);
                D_86B0FA40 = 0;
                D_86B0FA78->unk_16C++;
            }
            break;

        case 8:
            if (D_86B0FA58->unk_84 != 0) {
                Intro_EmitLandingParticles();
            }
            if (D_86B0FA78->unk_178++ >= 0x41) {
                D_86B0FA64 = 0;
                Vec3f_CalculateDistanceAngles(&D_87906054->unk_60.at, &D_87906054->unk_60.eye, &D_86B0FA6C, &D_86B0FA66, &D_86B0FA68);
                D_86B0FA78->unk_16C++;
            }
            break;

        case 9:
            Intro_FadeInBackgroundTint();

            if (D_86B0FA58->unk_84 != 0) {
                Intro_EmitLandingParticles();
            }

            if (gPlayer1Controller->buttonDown & 0xC000) {
                return 1;
            }

            if (D_86B0FA78->unk_178++ >= 0x3E9) {
                D_86B0FA78->unk_178 = 0x64;
            }

            D_86B0FA64 = Math_StepToS32(D_86B0FA64, 0x3C, 1, 1);
            D_86B0FA68 += D_86B0FA64;
            Camera_ComputeEyeFromAngles(&D_87906054->unk_60.at, &D_87906054->unk_60.eye, D_86B0FA6C, D_86B0FA66, D_86B0FA68);
            break;
    }

    if ((D_86B0FA74 == 2) && (D_86B0FA70 == 0x12C)) {
        Audio_StartMusicTrack(0x5B);
    }
    return 0;
}

s32 Intro_StepPanelBounce(unk_D_86B0FA50* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 temp_fa1;
    f32 sp20;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_4;
    f32* new_var;

    sp20 = arg0->unk_A4;

    temp_fv0 = Math_StepToF(sp20, 0.0f, 0.0f, 0.0f);
    arg0->unk_A4 = temp_fv0;
    if (temp_fv0 >= 0.0f) {
        temp_fv0 = 0;
        if ((arg0 && arg0) && arg0) {}
    }
    temp_fv0_2 = COSS(0) * temp_fv0;
    temp_fa1 = -arg3;

    new_var = &arg0->unk_AC;

    temp_fv0_4 = (-temp_fa1) - (arg2 * ((sp20 * arg0->unk_AC) + temp_fv0_2));
    arg0->unk_AC = (temp_fv0_4 * arg5) + ((*new_var) + temp_fv0_2);

    if (arg0->unk_AC >= 28.0) {
        arg0->unk_AC = 28.0f;
    }

    arg0->unk_98 += arg0->unk_AC;
    if (temp_fa1 >= 0) {
        if ((arg0->unk_98 < arg4) && (arg0->unk_98 >= 0.0f)) {
            arg0->unk_98 = arg4;
            arg0->unk_AC *= -arg1;
        }
    } else if ((arg4 < arg0->unk_98) && (arg0->unk_98 >= 0.0f)) {
        arg0->unk_98 = arg4;
        arg0->unk_AC *= -arg1;
        if (arg0->unk_A8 == arg0->unk_AC) {
            return 1;
        }
        arg0->unk_A8 = arg0->unk_AC;
    }

    return 0;
}

void Intro_DrawTextPanels(void) {
    if (D_86B0FA78->unk_17C == 6) {
        switch (D_86B0FA50->unk_90) {
            case 3:
                break;

            case 0:
                Intro_ConfigureTextPanels();
                D_86B0FA50->unk_90++;
                break;

            case 1:
                Intro_StepPanelBounce(D_86B0FA54, 0.25f, 0.0f, 3.0f, 0xA3 - (D_86B0FA54->unk_9E / 2), 1.7f);
                UI_DrawGradientTexture(D_86B0FA54->unk_80, D_86B0FA54->unk_98, D_86B0FA54->unk_9C, D_86B0FA54->unk_9E,
                              D_86B0FA54->unk_A0, &D_86B0FA54->unk_B0);
                D_86B0FA58->unk_84 =
                    Intro_StepPanelBounce(D_86B0FA58, 0.25f, 0.0f, 3.0f, 0xA3 - (D_86B0FA58->unk_9E / 2), 1.7f);
                UI_DrawGradientTexture(D_86B0FA58->unk_80, D_86B0FA58->unk_98, D_86B0FA58->unk_9C, D_86B0FA58->unk_9E,
                              D_86B0FA58->unk_A0, &D_86B0FA54->unk_B0);

                if (D_800AE540.unk_11F2 == 1) {
                    UI_DrawTextureRgba16(D_86B0FA60->unk_80, (s16)D_86B0FA58->unk_98 + D_86B0FA58->unk_9E,
                                  D_86B0FA58->unk_9C - 2, D_86B0FA60->unk_9E, D_86B0FA60->unk_A0);
                }

                if ((D_86B0FA44 != 4) && (D_86B0FA44 != 5)) {
                    Intro_StepPanelBounce(D_86B0FA5C, 0.25f, 0.0f, 3.0f, 0xA3 - (D_86B0FA5C->unk_9E / 2), 1.7f);
                    UI_DrawGradientTexture(D_86B0FA5C->unk_80, D_86B0FA5C->unk_98, D_86B0FA5C->unk_9C, D_86B0FA5C->unk_9E,
                                  D_86B0FA5C->unk_A0, &D_86B0FA54->unk_B0);
                }

                if (D_86B0FA58->unk_84 != 0) {
                    D_86B0FA54->unk_B0.unk_00 = Math_StepToS32(
                        D_86B0FA54->unk_B0.unk_00, D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_00,
                        D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_0C, D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_0C);
                    D_86B0FA54->unk_B0.unk_02 = Math_StepToS32(
                        D_86B0FA54->unk_B0.unk_02, D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_02,
                        D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_0E, D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_0E);
                    D_86B0FA54->unk_B0.unk_04 = Math_StepToS32(
                        D_86B0FA54->unk_B0.unk_04, D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_04,
                        D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_10, D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_10);
                    D_86B0FA54->unk_B0.unk_06 = Math_StepToS32(
                        D_86B0FA54->unk_B0.unk_06, D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_06,
                        D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_12, D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_12);
                    D_86B0FA54->unk_B0.unk_08 = Math_StepToS32(
                        D_86B0FA54->unk_B0.unk_08, D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_08,
                        D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_14, D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_14);
                    D_86B0FA54->unk_B0.unk_0A = Math_StepToS32(
                        D_86B0FA54->unk_B0.unk_0A, D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_0A,
                        D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_16, D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_16);
                    if ((D_86B0FA54->unk_B0.unk_00 == D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_00) &&
                        (D_86B0FA54->unk_B0.unk_02 == D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_02) &&
                        (D_86B0FA54->unk_B0.unk_04 == D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_04) &&
                        (D_86B0FA54->unk_B0.unk_06 == D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_06) &&
                        (D_86B0FA54->unk_B0.unk_08 == D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_08) &&
                        (D_86B0FA54->unk_B0.unk_0A == D_86B0DCE0[D_86B0FA54->unk_88 + 1].unk_0A)) {

                        D_86B0FA54->unk_88++;
                        if (D_86B0FA54->unk_88 == 4) {
                            D_86B0FA50->unk_90++;
                        }
                    }
                }
                break;

            case 2:
                UI_DrawGradientTexture(D_86B0FA54->unk_80, D_86B0FA54->unk_98, D_86B0FA54->unk_9C, D_86B0FA54->unk_9E,
                              D_86B0FA54->unk_A0, D_86B0DD40);
                UI_DrawGradientTexture(D_86B0FA58->unk_80, D_86B0FA58->unk_98, D_86B0FA58->unk_9C, D_86B0FA58->unk_9E,
                              D_86B0FA58->unk_A0, D_86B0DD40);

                if (D_800AE540.unk_11F2 == 1) {
                    UI_DrawTextureRgba16(D_86B0FA60->unk_80, (s16)D_86B0FA58->unk_98 + D_86B0FA58->unk_9E,
                                  D_86B0FA58->unk_9C - 2, D_86B0FA60->unk_9E, D_86B0FA60->unk_A0);
                }

                if ((D_86B0FA44 != 4) && (D_86B0FA44 != 5)) {
                    UI_DrawGradientTexture(D_86B0FA5C->unk_80, D_86B0FA5C->unk_98, D_86B0FA5C->unk_9C, D_86B0FA5C->unk_9E,
                                  D_86B0FA5C->unk_A0, D_86B0DD40);
                }
                break;
        }
    } else {
        switch (D_86B0FA50->unk_90) {
            case 3:
                break;

            case 0:
                D_86B0FA50->unk_98 = -80.0f;
                D_86B0FA50->unk_9C = 0xB4;
                D_86B0FA50->unk_A4 = 0.0f;
                D_86B0FA50->unk_AC = 0.0f;
                sprintf(D_86B0FA50->unk00, "%s", D_86B10690->unk_01C[D_86B0FA78->unk_17C].unk_30);
                D_86B0FA50->unk_90++;
                break;

            case 1:
                Font_BeginTranslucentTextRendering();
                Font_EnableTwoCycleTexturing();
                Font_SetActive(0x10, 0);
                Gfx_SetPrimColor(0, 0x82, 0xFF, 0xFF);
                Gfx_SetEnvColor(0xC8, 0xFF, 0xFF, 0xFF);
                Intro_StepPanelBounce(D_86B0FA50, 0.35f, 0.0f, 4.0f, 160.0f, 1.4f);
                Font_Printf((s32)D_86B0FA50->unk_98 - (Font_MeasureTextExtent(0x10, 0, D_86B0FA50->unk00) / 2),
                              D_86B0FA50->unk_9C, D_86B0FA50->unk00);
                Font_DisableTwoCycleTexturing();
                Font_EndTexturedTextRendering();
                break;
        }
    }

    WipeTransition_Draw();
}

void Intro_RenderFrame(void) {
    BgStage_DrawFrame();

    if ((D_86B0FA38 == -1) || (D_86B0FA38 == 0)) {
        GfxImage_FillCurrent(&gDisplayListHead, 1);
    } else if (D_86B0FA38 < 0x10000) {
        GfxImage_FillCurrent(&gDisplayListHead, D_86B0FA38);
    } else {
        GfxImage_FillCurrent(&gDisplayListHead, 0xA6BF);
    }

    GeoRender_AdvanceFrameCounter();
    Geo_RenderRootNode(&D_87906050->node);
    Intro_DrawTextPanels();
    MiniFx_DrawParticles();
    BgStage_AdvanceFrame();
}

void Intro_RenderBlackFrame(void) {
    BgStage_DrawFrame();
    GfxImage_FillCurrent(&gDisplayListHead, 1);
    GeoRender_AdvanceFrameCounter();
    Geo_RenderRootNode(&D_87906050->node);
    Gfx_FillRectWithDisplayState(0, 0, 0x140, 0xF0, 0, 0, 0, 0xFF);
    BgStage_AdvanceFrame();
}

void Intro_FadeInSequence(void) {
    s32 i;

    for (i = 0; i < 18; i++) {
        Intro_ReadControllerInput();

        if (i < 3) {
            StageContext_SetClearColor(1);
            StageFade_StartFromOpaque(0x10);
            Intro_RenderBlackFrame();
        }
    }

    if (D_86B0FA74 == 2) {
        Audio_StartMusicTrack(0x44);
    } else {
        Audio_StartMusicTrack(8);
    }
}

void Intro_RunLoop(void) {
    s32 var_s0 = 1;
    void (*temp_s2)(void) = (void*)Util_ConvertAddrToVirtAddr(Particle_UpdateFrameCountersAlias);

    D_86B0FA70 = 0;
    while (var_s0 != 0) {
        D_86B0FA70++;

        Intro_ReadControllerInput();
        MiniFx_UpdateParticles();

        if (Intro_UpdateShowcaseSequence() != 0) {
            var_s0 = 0;
        }

        temp_s2();
        Intro_RenderFrame();
    }
}

void Intro_FadeOutSequence(void) {
    s32 i;
    s32 var_s1;
    void (*temp_s2)(void) = Util_ConvertAddrToVirtAddr(Particle_UpdateFrameCountersAlias);

    if (D_800AE540.unk_0001 == 7) {
        for (i = 0; i < 100; i++) {
            Intro_ReadControllerInput();
            MiniFx_UpdateParticles();

            temp_s2();

            Intro_RenderFrame();
        }
    }

    if (D_800AE540.unk_0001 == 7) {
        var_s1 = 0x64;
    } else {
        var_s1 = 0xA;
    }

    StageFade_StartFromTransparent(var_s1);
    Audio_FadeOutAll(var_s1 - 2);

    for (i = 0; i < var_s1; i++) {
        if (D_800AE540.unk_0001 == 7) {
            Intro_ReadControllerInput();
            MiniFx_UpdateParticles();
            temp_s2();
            Intro_RenderFrame();
        } else {
            Intro_ReadControllerInput();
            MiniFx_UpdateParticles();
            Intro_UpdateShowcaseSequence();
            temp_s2();
            Intro_RenderFrame();
        }
    }

    if (D_800AE540.unk_0001 == 7) {
        for (i = 0; i < 30; i++) {
            Intro_ReadControllerInput();
            MiniFx_UpdateParticles();

            temp_s2();

            Intro_RenderFrame();
        }
    }
}

void Stage_LoadModels(void) {
    MemoryBlock* sp34;
    UNUSED s32 pad;
    FragmentEntry sp2C;
    void* temp_v0_3;
    unk_D_8690A610_018* temp_v0_6;

    D_86B0FA42 = gStageModelIndices[D_800AE540.unk_0001];
    if (D_800AE540.unk_0001 == 7) {
        D_86B0FA42 += D_800AE540.unk_0002;
    }

    switch (D_800AE540.unk_0001) {
        case 1:
            D_86B0FA44 = 4;
            break;

        case 2:
            D_86B0FA44 = 4;
            break;

        case 3:
            D_86B0FA44 = D_800AE540.unk_0002;
            break;

        case 4:
            D_86B0FA44 = 5;
            break;

        case 5:
            D_86B0FA44 = 5;
            break;

        case 6:
            D_86B0FA44 = D_800AE540.unk_0002;
            break;

        default:
            D_86B0FA44 = 0;
            break;
    }

    sp2C = BinArchive_GetFile(BinArchive_Open(stadium_models_ROM_START, _5C7A70_ROM_START, 1, 1), D_86B0FA42);

    D_86B0FA4C = sp2C(2, 0);
    GeoNode_CreateFog(0, &D_86B0F9D0, 0x3C0, 0x3E8, 0xFF, 0xFF, 0xFF, 0xFF);
    GeoNode_CreateContainer(NULL, &D_86B0F9F0);
    GeoNode_CreateContainer(NULL, &D_86B0FA08);
    GeoNode_CreateContainer(NULL, &D_86B0FA20);
    sp34 = MainPool_AllocState(main_pool_get_available(), 0);
    D_87906050 = process_geo_layout(sp34, D_86B0DE5C);

    temp_v0_3 = sp2C(0, 0);
    if (temp_v0_3 != NULL) {
        GraphNode_AppendChild(&D_86B0F9F0, process_geo_layout(sp34, temp_v0_3));
    }

    temp_v0_3 = sp2C(1, 0);
    if (temp_v0_3 != NULL) {
        GraphNode_AppendChild(&D_86B0FA08, process_geo_layout(sp34, temp_v0_3));
    }

    temp_v0_3 = sp2C(3, 0);
    if (temp_v0_3 != NULL) {
        GraphNode_AppendChild(&D_86B0FA20, process_geo_layout(sp34, temp_v0_3));
    }

    D_86B0FA38 = sp2C(2, 0);
    MainPool_FinalizeAllocation(sp34);

    temp_v0_6 = sp2C(4, 0);
    if (temp_v0_6 == NULL) {
        D_86B0F9D0.node.callbackArg = 0;
        D_86B0F9D0.node.flags &= ~1;
    } else {
        D_86B0F9D0.unk_18.unk_00 = temp_v0_6->unk_00;
        D_86B0F9D0.unk_18.unk_02 = temp_v0_6->unk_02;
        D_86B0F9D0.unk_18.unk_04.rgba = temp_v0_6->unk_04.rgba;
        D_86B0F9D0.node.callbackArg = 1;
    }

    ModelRenderer_InitDisplayRoots();
    Intro_SetBackgroundTint(0xFF, 0xFF, 0xFF);
    MiniFx_Init();

    D_86B0FA78 = main_pool_alloc(sizeof(unk_D_86B0FA78), 0);
    bzero(D_86B0FA78, sizeof(unk_D_86B0FA78));

    D_86B0FA7C = main_pool_alloc(sizeof(unk_D_86B0FA7C), 0);
    bzero(D_86B0FA7C, sizeof(unk_D_86B0FA7C));

    D_86B0FA50 = main_pool_alloc(sizeof(unk_D_86B0FA50), 0);
    bzero(D_86B0FA50, sizeof(unk_D_86B0FA50));

    D_86B0FA54 = main_pool_alloc(sizeof(unk_D_86B0FA50), 0);
    bzero(D_86B0FA54, sizeof(unk_D_86B0FA50));

    D_86B0FA58 = main_pool_alloc(sizeof(unk_D_86B0FA50), 0);
    bzero(D_86B0FA58, sizeof(unk_D_86B0FA50));

    D_86B0FA5C = main_pool_alloc(sizeof(unk_D_86B0FA50), 0);
    bzero(D_86B0FA5C, sizeof(unk_D_86B0FA50));

    D_86B0FA60 = main_pool_alloc(sizeof(unk_D_86B0FA50), 0);
    bzero(D_86B0FA60, sizeof(unk_D_86B0FA50));

    Intro_SelectPartyRoster();

    switch (D_800AE540.unk_0001) {
        case 1:
        case 2:
        case 4:
        case 5:
        case 7:
            Intro_StartFirstShowcase();
            Intro_BeginOrbitCamera();
            Intro_TriggerTextPanelExit();
            D_86B0FA74 = 0;
            break;

        default:
            if (D_800AE540.unk_0002 == 3) {
                D_86B0FA74 = 1;
                Intro_StartFirstShowcase();
                Intro_BeginOrbitCamera();
                Intro_TriggerTextPanelExit();
            } else {
                D_86B0FA74 = 2;
                Intro_StartFinalStageModel();
                Intro_BeginStaticCamera();
                Intro_TriggerTextPanelExit();
            }
            break;
    }
}

s32 Stage_ShowIntro(void) {
    unk_func_80007444* sp24;

    main_pool_push_state('DEMO');

    Gfx_InitDisplayListBuffers(0x10000, 0);
    sp24 = StageContext_Allocate(0, 1, 3, 1, 2, 1);
    Font_Init(0x10, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_3000000, cup_clear_ui, 0);

    FRAGMENT_LOAD(fragment31);

    Stage_LoadModels();
    StageContext_Activate(sp24);
    Intro_FadeInSequence();
    Intro_RunLoop();
    Intro_FadeOutSequence();
    StageContext_Deactivate();
    Font_Free();
    Gfx_FreeDisplayListBuffers();

    main_pool_pop_state('DEMO');

    return 0;
}
