#include "battle_engine.h"
#include "src/model_animation.h"
#include "src/model_renderer.h"
#include "src/model_renderer_callbacks.h"
#include "src/matrix.h"

void BattleScene_TriggerOwnerModelAnimation(Battler* arg0) {
    ModelAnim_SetFrame(&arg0->unk_728.unk_000, arg0->unk_728.unk_180);
    ModelAnim_SetAnimation(&arg0->unk_728.unk_000, arg0->unk_728.unk_17C);
    BattleScene_SetOwnerPoseFlag(arg0->unk_728.unk_168);
}

void BattleScene_ClearParticipantOwnerActiveFlag(Battler* arg0) {
    arg0->unk_728.unk_170 = 0;
}

void BattleScene_SetParticipantOwnerActiveFlag(Battler* arg0) {
    arg0->unk_728.unk_170 = 1;
}

void BattleScene_ClearBothOwnerActiveFlags(void) {
    D_84390010[0]->unk_728.unk_170 = 0;
    D_84390010[1]->unk_728.unk_170 = 0;
}

void BattleScene_SetBothOwnerActiveFlags(void) {
    D_84390010[0]->unk_728.unk_170 = 1;
    D_84390010[1]->unk_728.unk_170 = 1;
}

void BattleScene_SetOwnerPoseFlag(PresentationLayout* arg0) {
    arg0->node.flags |= 0x10;
}

void BattleScene_LoadOwnerCameraFramingConstants(Battler* arg0) {
    s32 var_v0;

    if (arg0 == D_84390010[0]) {
        var_v0 = 0;
    } else {
        var_v0 = 1;
    }

    arg0->unk_728.unk_168->unk_20 = D_843847BC[var_v0].unk_04;
    arg0->unk_728.unk_168->unk_1C = D_843847BC[var_v0].unk_00;
    arg0->unk_728.unk_168->unk_1E = D_843847BC[var_v0].unk_02;

    arg0->unk_728.unk_178 = D_843847BC[var_v0].unk_14;

    arg0->unk_728.unk_168->unk_34 = D_843847BC[var_v0].unk_0C;
    arg0->unk_728.unk_168->unk_38 = D_843847BC[var_v0].unk_10;
    arg0->unk_728.unk_168->unk_2C = D_843847BC[var_v0].unk_08;
}

void BattleScene_SetupOwnerCameraFraming(Battler* arg0, Battler* arg1) {
    if (gBattleScene.unk_00->unk_1C == 1) {
        BattleScene_SetBothOwnerActiveFlags();
    } else {
        BattleScene_ClearBothOwnerActiveFlags();
    }
    BattleScene_LoadOwnerCameraFramingConstants(arg0);
    BattleScene_LoadOwnerCameraFramingConstants(arg1);
}

void BattleScene_OwnerCameraLifecycleNop(void) {
}

void BattleScene_ApplyOwnerCameraFraming(Battler* arg0) {
    s32 temp_v0;
    PresentationLayout* sp30;
    f32 tmp;
    f32 tmp2;

    sp30 = arg0->unk_728.unk_168;
    temp_v0 = BattleScene_GetParticipantSideIndex(arg0);

    arg0->unk_728.unk_184 = D_84384578[temp_v0]->unk_0C;
    if (D_84384578[temp_v0]->unk_10 == 0xFF) {
        arg0->unk_728.unk_186 = D_84384578[temp_v0]->unk_0E * arg0->unk_728.unk_178;
        tmp = D_84384578[temp_v0]->unk_00.z * arg0->unk_728.unk_178;
    } else {
        arg0->unk_728.unk_186 = D_84384578[temp_v0]->unk_0E;
        tmp = D_84384578[temp_v0]->unk_00.z;
    }

    arg0->unk_728.unk_190 = tmp;
    arg0->unk_728.unk_188 = D_84384578[temp_v0]->unk_00.x;
    arg0->unk_728.unk_180 = D_84384578[temp_v0]->unk_12;
    tmp2 = D_84384578[temp_v0]->unk_00.y;
    arg0->unk_728.unk_194 = tmp2;

    BattleScene_SetCameraAtAndEyeFromAngles(sp30, arg0->unk_728.unk_000.position.x + arg0->unk_728.unk_190, arg0->unk_728.unk_000.position.y + tmp2,
                  arg0->unk_728.unk_000.position.z, arg0->unk_728.unk_188, arg0->unk_728.unk_184, arg0->unk_728.unk_186);
}

void BattleScene_TickOwnerCameraFraming(Battler* arg0) {
    BattleScene_ApplyOwnerCameraFraming(arg0);
}

void BattleScene_InitializeOwnerCameraFraming(unk_D_86002F34_00C* arg0, Battler* arg1, unk_D_86002F34_00C* arg2, Battler* arg3) {
    arg1->unk_728.unk_168 = arg0;
    arg3->unk_728.unk_168 = arg2;
    BattleScene_SetupOwnerCameraFraming(arg1, arg3);
    BattleScene_TickOwnerCameraFraming(arg1);
    BattleScene_TickOwnerCameraFraming(arg3);
}

void BattleScene_TickOwnerSlideIn(Battler* arg0, s32 arg1) {
    s16 var_a0;
    PresentationLayout* temp_v0;

    arg0->unk_728.unk_168->node.flags |= 1;
    arg0->unk_728.unk_000.node.flags |= 1;

    if (arg0->unk_728.unk_178 == 1) {
        if ((arg0->unk_728.unk_168->unk_1C == -0x48) && !(arg0->unk_654.unk_34 & 0x800)) {
            BattleScene_TriggerOwnerModelAnimation(arg0);
        }

        if ((ModelRenderer_IsReady(0) != 0) && (arg0->unk_728.unk_18C == 0)) {
            arg0->unk_728.unk_18C = 2;
            ModelRenderer_OnSlotReady(0);
        }
        arg0->unk_728.unk_168->unk_1C = Math_StepToS32(arg0->unk_728.unk_168->unk_1C, 0x17, arg1, arg1);
    } else {
        if ((arg0->unk_728.unk_168->unk_1C == 0x15F) && !(arg0->unk_654.unk_34 & 0x800)) {
            BattleScene_TriggerOwnerModelAnimation(arg0);
        }

        arg0->unk_728.unk_168->unk_1C = Math_StepToS32(arg0->unk_728.unk_168->unk_1C, 0x103, arg1, arg1);

        if ((ModelRenderer_IsReady(1) != 0) && (arg0->unk_728.unk_18C == 0)) {
            arg0->unk_728.unk_18C = 2;
            ModelRenderer_OnSlotReady(1);
        }
    }
}

void BattleScene_TickOwnerSlideOut(Battler* arg0, s32 arg1) {
    if (arg0->unk_728.unk_178 == 1) {
        arg0->unk_728.unk_18C = 0;
        arg0->unk_728.unk_168->unk_1C = Math_StepToS32(arg0->unk_728.unk_168->unk_1C, -0x48, arg1, arg1);
        if (arg0->unk_728.unk_168->unk_1C == -0x48) {
            arg0->unk_728.unk_168->node.flags &= ~1;
            arg0->unk_728.unk_000.node.flags &= ~1;
        }
    } else {
        arg0->unk_728.unk_18C = 0;
        arg0->unk_728.unk_168->unk_1C = Math_StepToS32(arg0->unk_728.unk_168->unk_1C, 0x15F, arg1, arg1);
        if (arg0->unk_728.unk_168->unk_1C == 0x15F) {
            arg0->unk_728.unk_168->node.flags &= ~1;
            arg0->unk_728.unk_000.node.flags &= ~1;
        }
    }
}

void BattleScene_TickOwnerSlideAnimation(Battler* arg0) {
    switch (arg0->unk_728.unk_170) {
        case 0:
            BattleScene_TickOwnerSlideOut(arg0, 9);
            break;

        case 1:
            BattleScene_TickOwnerSlideIn(arg0, 9);
            break;
    }
}

void BattleScene_TickBothOwnerSlideAnimations(Battler* arg0, Battler* arg1) {
    if (D_800AE540.unk_0000 != 0x10) {
        BattleScene_TickOwnerSlideAnimation(arg0);
        BattleScene_TickOwnerSlideAnimation(arg1);
    }
}

s32 BattleScene_DispatchOwnerCameraLifecycle(s32 arg0, unk_D_86002F34_00C* arg1, unk_D_86002F34_00C* arg2) {
    switch (arg0) {
        case 0:
            BattleScene_OwnerCameraLifecycleNop();
            break;

        case 1:
        case 2:
            BattleScene_TickBothOwnerSlideAnimations(D_84390010[0], D_84390010[1]);
            break;

        case 3:
            BattleScene_InitializeOwnerCameraFraming(arg1, D_84390010[0], arg2, D_84390010[1]);
            break;
    }
    return 0;
}
