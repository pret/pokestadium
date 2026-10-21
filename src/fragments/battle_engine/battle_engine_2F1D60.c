#include "battle_engine.h"
#include "src/model_animation.h"
#include "src/model_renderer.h"
#include "src/model_renderer_callbacks.h"
#include "src/matrix.h"

void BattleScene_TriggerOwnerModelAnimation(ActivePokemon* active_pokemon) {
    ModelAnim_SetFrame(&active_pokemon->presentationState.displayObject, active_pokemon->presentationState.unk_180);
    ModelAnim_SetAnimation(&active_pokemon->presentationState.displayObject, active_pokemon->presentationState.unk_17C);
    BattleScene_SetOwnerPoseFlag(active_pokemon->presentationState.unk_168);
}

void BattleScene_ClearParticipantOwnerActiveFlag(ActivePokemon* active_pokemon) {
    active_pokemon->presentationState.unk_170 = 0;
}

void BattleScene_SetParticipantOwnerActiveFlag(ActivePokemon* active_pokemon) {
    active_pokemon->presentationState.unk_170 = 1;
}

void BattleScene_ClearBothOwnerActiveFlags(void) {
    sActivePokemon[0]->presentationState.unk_170 = 0;
    sActivePokemon[1]->presentationState.unk_170 = 0;
}

void BattleScene_SetBothOwnerActiveFlags(void) {
    sActivePokemon[0]->presentationState.unk_170 = 1;
    sActivePokemon[1]->presentationState.unk_170 = 1;
}

void BattleScene_SetOwnerPoseFlag(PresentationLayout* arg0) {
    arg0->node.flags |= 0x10;
}

void BattleScene_LoadOwnerCameraFramingConstants(ActivePokemon* active_pokemon) {
    s32 var_v0;

    if (active_pokemon == sActivePokemon[0]) {
        var_v0 = 0;
    } else {
        var_v0 = 1;
    }

    active_pokemon->presentationState.unk_168->unk_20 = D_843847BC[var_v0].unk_04;
    active_pokemon->presentationState.unk_168->unk_1C = D_843847BC[var_v0].unk_00;
    active_pokemon->presentationState.unk_168->unk_1E = D_843847BC[var_v0].unk_02;

    active_pokemon->presentationState.unk_178 = D_843847BC[var_v0].unk_14;

    active_pokemon->presentationState.unk_168->unk_34 = D_843847BC[var_v0].unk_0C;
    active_pokemon->presentationState.unk_168->unk_38 = D_843847BC[var_v0].unk_10;
    active_pokemon->presentationState.unk_168->unk_2C = D_843847BC[var_v0].unk_08;
}

void BattleScene_SetupOwnerCameraFraming(ActivePokemon* arg0, ActivePokemon* arg1) {
    if (sBattleScene.unk_00->unk_1C == 1) {
        BattleScene_SetBothOwnerActiveFlags();
    } else {
        BattleScene_ClearBothOwnerActiveFlags();
    }
    BattleScene_LoadOwnerCameraFramingConstants(arg0);
    BattleScene_LoadOwnerCameraFramingConstants(arg1);
}

void BattleScene_OwnerCameraLifecycleNop(void) {
}

void BattleScene_ApplyOwnerCameraFraming(ActivePokemon* active_pokemon) {
    s32 temp_v0;
    PresentationLayout* sp30;
    f32 tmp;
    f32 tmp2;

    sp30 = active_pokemon->presentationState.unk_168;
    temp_v0 = BattleScene_GetParticipantSideIndex(active_pokemon);

    active_pokemon->presentationState.unk_184 = D_84384578[temp_v0]->unk_0C;
    if (D_84384578[temp_v0]->unk_10 == 0xFF) {
        active_pokemon->presentationState.unk_186 = D_84384578[temp_v0]->unk_0E * active_pokemon->presentationState.unk_178;
        tmp = D_84384578[temp_v0]->unk_00.z * active_pokemon->presentationState.unk_178;
    } else {
        active_pokemon->presentationState.unk_186 = D_84384578[temp_v0]->unk_0E;
        tmp = D_84384578[temp_v0]->unk_00.z;
    }

    active_pokemon->presentationState.unk_190 = tmp;
    active_pokemon->presentationState.unk_188 = D_84384578[temp_v0]->unk_00.x;
    active_pokemon->presentationState.unk_180 = D_84384578[temp_v0]->unk_12;
    tmp2 = D_84384578[temp_v0]->unk_00.y;
    active_pokemon->presentationState.unk_194 = tmp2;

    BattleScene_SetCameraAtAndEyeFromAngles(sp30, active_pokemon->presentationState.displayObject.position.x + active_pokemon->presentationState.unk_190, active_pokemon->presentationState.displayObject.position.y + tmp2,
                  active_pokemon->presentationState.displayObject.position.z, active_pokemon->presentationState.unk_188, active_pokemon->presentationState.unk_184, active_pokemon->presentationState.unk_186);
}

void BattleScene_TickOwnerCameraFraming(ActivePokemon* active_pokemon) {
    BattleScene_ApplyOwnerCameraFraming(active_pokemon);
}

void BattleScene_InitializeOwnerCameraFraming(CameraNode* arg0, ActivePokemon* arg1, CameraNode* arg2, ActivePokemon* arg3) {
    arg1->presentationState.unk_168 = arg0;
    arg3->presentationState.unk_168 = arg2;
    BattleScene_SetupOwnerCameraFraming(arg1, arg3);
    BattleScene_TickOwnerCameraFraming(arg1);
    BattleScene_TickOwnerCameraFraming(arg3);
}

void BattleScene_TickOwnerSlideIn(ActivePokemon* arg0, s32 arg1) {
    s16 var_a0;
    PresentationLayout* temp_v0;

    arg0->presentationState.unk_168->node.flags |= 1;
    arg0->presentationState.displayObject.node.flags |= 1;

    if (arg0->presentationState.unk_178 == 1) {
        if ((arg0->presentationState.unk_168->unk_1C == -0x48) && !(arg0->state.flags & 0x800)) {
            BattleScene_TriggerOwnerModelAnimation(arg0);
        }

        if ((ModelRenderer_IsReady(0) != 0) && (arg0->presentationState.unk_18C == 0)) {
            arg0->presentationState.unk_18C = 2;
            ModelRenderer_OnSlotReady(0);
        }
        arg0->presentationState.unk_168->unk_1C = Math_StepToS32(arg0->presentationState.unk_168->unk_1C, 0x17, arg1, arg1);
    } else {
        if ((arg0->presentationState.unk_168->unk_1C == 0x15F) && !(arg0->state.flags & 0x800)) {
            BattleScene_TriggerOwnerModelAnimation(arg0);
        }

        arg0->presentationState.unk_168->unk_1C = Math_StepToS32(arg0->presentationState.unk_168->unk_1C, 0x103, arg1, arg1);

        if ((ModelRenderer_IsReady(1) != 0) && (arg0->presentationState.unk_18C == 0)) {
            arg0->presentationState.unk_18C = 2;
            ModelRenderer_OnSlotReady(1);
        }
    }
}

void BattleScene_TickOwnerSlideOut(ActivePokemon* arg0, s32 arg1) {
    if (arg0->presentationState.unk_178 == 1) {
        arg0->presentationState.unk_18C = 0;
        arg0->presentationState.unk_168->unk_1C = Math_StepToS32(arg0->presentationState.unk_168->unk_1C, -0x48, arg1, arg1);
        if (arg0->presentationState.unk_168->unk_1C == -0x48) {
            arg0->presentationState.unk_168->node.flags &= ~1;
            arg0->presentationState.displayObject.node.flags &= ~1;
        }
    } else {
        arg0->presentationState.unk_18C = 0;
        arg0->presentationState.unk_168->unk_1C = Math_StepToS32(arg0->presentationState.unk_168->unk_1C, 0x15F, arg1, arg1);
        if (arg0->presentationState.unk_168->unk_1C == 0x15F) {
            arg0->presentationState.unk_168->node.flags &= ~1;
            arg0->presentationState.displayObject.node.flags &= ~1;
        }
    }
}

void BattleScene_TickOwnerSlideAnimation(ActivePokemon* active_pokemon) {
    switch (active_pokemon->presentationState.unk_170) {
        case 0:
            BattleScene_TickOwnerSlideOut(active_pokemon, 9);
            break;

        case 1:
            BattleScene_TickOwnerSlideIn(active_pokemon, 9);
            break;
    }
}

void BattleScene_TickBothOwnerSlideAnimations(ActivePokemon* arg0, ActivePokemon* arg1) {
    if (gSessionContext.mode != SESSION_MODE_ATTRACT_DEMO_BATTLE) {
        BattleScene_TickOwnerSlideAnimation(arg0);
        BattleScene_TickOwnerSlideAnimation(arg1);
    }
}

s32 BattleScene_DispatchOwnerCameraLifecycle(s32 arg0, CameraNode* arg1, CameraNode* arg2) {
    switch (arg0) {
        case 0:
            BattleScene_OwnerCameraLifecycleNop();
            break;

        case 1:
        case 2:
            BattleScene_TickBothOwnerSlideAnimations(sActivePokemon[0], sActivePokemon[1]);
            break;

        case 3:
            BattleScene_InitializeOwnerCameraFraming(arg1, sActivePokemon[0], arg2, sActivePokemon[1]);
            break;
    }
    return 0;
}
