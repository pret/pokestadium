#include "battle_engine.h"
#include "src/model_animation.h"
#include "src/model_renderer.h"
#include "src/matrix.h"

static f32 D_84384600[] = { 1.0f, 2.0f };

void BattleAnim_InitSwayOffset(ActivePokemon* arg0, f32 arg1, s16 arg2) {
    arg0->unk_498 = arg1;
    arg0->swayState.unk_0C.z = COSS(arg2) * arg1;
    arg0->swayState.unk_0C.y = SINS(arg2) * arg1;
    arg0->unk_49C = 0.01f;
}

void BattleAnim_UpdateSwayPhysicsToOwner(ActivePokemon* arg0, ActivePokemon* arg1, f32 arg2, f32 arg3, s32 arg4) {
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    UNUSED s32 pad;
    Vec3f sp3C;
    UNUSED s32 pad2;
    f32 temp_fa1;
    f32 temp_fa2;
    f32 var_fa0;

    sp54 = arg1->unk_49C;
    sp50 = arg1->unk_498;
    sp4C = 18.0f;
    arg1->unk_498 = Math_StepToF(sp50, arg2, arg3, arg3);

    var_fa0 = arg1->unk_498;
    if (arg2 <= var_fa0) {
        if (&arg1->swayState.unk_0C) {}
        var_fa0 = 0.0f;
    }

    sp3C.z = COSS(arg4) * var_fa0;
    sp3C.y = SINS(arg4) * var_fa0;

    temp_fa1 = -sp54 * ((sp50 * arg1->swayState.unk_0C.z) + sp3C.z);
    temp_fa2 = -sp4C - (sp54 * ((sp50 * arg1->swayState.unk_0C.y) + sp3C.y));

    arg1->swayState.unk_0C.z = (arg1->swayState.unk_0C.z + sp3C.z + (temp_fa1 * 0.05f));
    arg1->swayState.unk_0C.y = (arg1->swayState.unk_0C.y + sp3C.y + (temp_fa2 * 0.05f));

    sp3C.y = arg1->swayState.unk_0C.y;
    arg1->swayState.unk_0C.x = 0.0f;

    BattleAnim_Vec3fSetPolarXZ(&sp3C, arg1->swayState.unk_0C.z, arg0->displayObject.rotation.y + 0x4000);
    Vec3f_AddInPlace(&arg0->displayObject.position, &sp3C);
}

void BattleAnim_UpdateSwayPhysicsToTarget(UNUSED ActivePokemon* arg0, ActivePokemon* arg1, f32 arg2, f32 arg3, s32 arg4, s32 arg5) {
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    UNUSED s32 pad;
    Vec3f sp3C;
    UNUSED s32 pad2;
    f32 temp_fa1;
    f32 temp_fa2;
    f32 var_fa0;

    sp54 = arg1->unk_49C;
    sp50 = arg1->unk_498;
    sp4C = 20.0f;
    arg1->unk_498 = Math_StepToF(sp50, arg2, arg3, arg3);

    var_fa0 = arg1->unk_498;
    if (arg2 <= var_fa0) {
        if (&arg1->swayState.unk_0C) {}
        var_fa0 = 0.0f;
    }

    sp3C.z = COSS(arg4) * var_fa0;
    sp3C.y = SINS(arg4) * var_fa0;

    temp_fa1 = -sp54 * ((sp50 * arg1->swayState.unk_0C.z) + sp3C.z);
    temp_fa2 = -sp4C - (sp54 * ((sp50 * arg1->swayState.unk_0C.y) + sp3C.y));

    arg1->swayState.unk_0C.z = (arg1->swayState.unk_0C.z + sp3C.z + (temp_fa1 * 0.05f));
    arg1->swayState.unk_0C.y = (arg1->swayState.unk_0C.y + sp3C.y + (temp_fa2 * 0.05f));
    sp3C.y = arg1->swayState.unk_0C.y;
    arg1->swayState.unk_0C.x = 0.0f;

    BattleAnim_Vec3fSetPolarXZ(&sp3C, arg1->swayState.unk_0C.z, arg5);
    Vec3f_AddInPlace(&arg1->unk_4EC.position, &sp3C);
}

void BattleScene_HideParticipantSecondaryModels(ActivePokemon* active_pokemon) {
    s32 i;

    for (i = 0; i < 2; i++) {
        Vec3f_SetComponentsDuplicate(&active_pokemon->unk_168[i].unk_000.scale, 1.0f, 1.0f, 1.0f);
        active_pokemon->unk_168[i].unk_000.node.flags &= ~1;
        active_pokemon->unk_168[i].unk_169 = 0;
    }
}

void BattleScene_ShowSecondaryModelsAtMainTransform(ActivePokemon* arg0) {
    s32 i;
    s16 sp64[] = { 0x0, 0xE38, 0xF1C8 }; // D_84384608

    for (i = 0; i < 2; i++) {
        arg0->unk_168[i].unk_16C = 0;
        arg0->unk_168[i].unk_16A = sp64[i];
        arg0->unk_168[i].unk_000.lodFraction = 0;
        arg0->unk_168[i].unk_000.node.flags |= 1;
        BattleAnim_Vec3fCopy(&arg0->unk_168[i].unk_000.position, &arg0->displayObject.position);
        BattleAnim_Vec3sCopy(&arg0->unk_168[i].unk_000.rotation, &arg0->displayObject.rotation);
        BattleAnim_Vec3fCopy(&arg0->unk_168[i].unk_000.scale, &arg0->displayObject.scale);
    }
}

void BattleScene_UpdateSecondaryModelOrbit(ActivePokemon* arg0) {
    s32 i;
    f32 tmp;
    Vec3f sp5C = { 0.0f, 0.0f, 0.0f };         // D_84384610
    f32 sp4C[] = { 0.3f, -0.4f, -0.2f, 0.4f }; // D_8438461C

    for (i = 0; i < 2; i++) {
        arg0->unk_168[i].unk_000.lodFraction = Math_StepToS32(arg0->unk_168[i].unk_000.lodFraction, 0x3C, 5, 5);
        arg0->unk_168[i].unk_16C = Math_StepToS32(arg0->unk_168[i].unk_16C, 0x38E, 0x64, 0x64);
        arg0->unk_168[i].unk_16C = Math_StepToS32(arg0->unk_168[i].unk_16C, 0x38E, 0x64, 0x64);
        arg0->unk_168[i].unk_16A += arg0->unk_168[i].unk_16C;

        tmp = SINS(arg0->unk_168[i].unk_16A) * (BattleScene_GetParticipantModelRadiusScaled(arg0) * sp4C[i]);
        BattleAnim_Vec3fSetPolarXZ(&sp5C, tmp, arg0->displayObject.rotation.y);

        arg0->unk_168[i].unk_000.position.x = arg0->displayObject.position.x + sp5C.x;
        arg0->unk_168[i].unk_000.position.y = arg0->displayObject.position.y + sp5C.y;
        arg0->unk_168[i].unk_000.position.z = arg0->displayObject.position.z + sp5C.z;

        ModelAnim_SetFrame(&arg0->unk_168[i].unk_000, arg0->displayObject.transformAnim.frameFixed >> 0x10);
        ModelAnim_SetAnimation(&arg0->unk_168[i].unk_000, arg0->displayObject.transformAnim.animationId);
    }
}

void BattleScene_ShowSecondaryModelsAtMainPose(ActivePokemon* active_pokemon) {
    s32 i;

    for (i = 0; i < 2; i++) {
        active_pokemon->unk_168[i].unk_169 = 0;
        active_pokemon->unk_168[i].unk_000.lodFraction = 0x3C;
        active_pokemon->unk_168[i].unk_000.node.flags |= 1;
        Vec3f_SetComponentsDuplicate(&active_pokemon->unk_168[i].unk_000.scale, 1.0f, 1.0f, 1.0f);
        BattleAnim_Vec3fCopy(&active_pokemon->unk_168[i].unk_000.position, &active_pokemon->displayObject.position);
        BattleAnim_Vec3sCopy(&active_pokemon->unk_168[i].unk_000.rotation, &active_pokemon->displayObject.rotation);
    }
}

s32 BattleScene_ShrinkSecondaryModelsToScale(ActivePokemon* active_pokemon) {
    s32 i;
    f32 temp_fv0_2;
    f32 sp5C[] = { 0.007f, 0.005f, 0.039f }; // D_8438462C

    for (i = 0; i < 2; i++) {
        BattleAnim_Vec3fCopy(&active_pokemon->unk_168[i].unk_000.position, &active_pokemon->displayObject.position);

        temp_fv0_2 = Math_StepToF(active_pokemon->unk_168[i].unk_000.scale.x, 0.8f, sp5C[i], sp5C[i]);
        active_pokemon->unk_168[i].unk_000.scale.x = temp_fv0_2;
        active_pokemon->unk_168[i].unk_000.scale.y = temp_fv0_2;
        active_pokemon->unk_168[i].unk_000.scale.z = temp_fv0_2;

        ModelAnim_SetFrame(&active_pokemon->unk_168[i].unk_000, active_pokemon->displayObject.transformAnim.frameFixed >> 0x10);
        ModelAnim_SetAnimation(&active_pokemon->unk_168[i].unk_000, active_pokemon->displayObject.transformAnim.animationId);

        if (active_pokemon->unk_168[i].unk_000.scale.y < 0.8) {
            active_pokemon->unk_168[i].unk_169 = 1;
        }
    }

    return 0;
}

void BattleScene_ShowSecondaryModelsStaggeredFrame(ActivePokemon* active_pokemon) {
    s32 i;

    for (i = 0; i < 2; i++) {
        active_pokemon->unk_168[i].unk_169 = 0;
        active_pokemon->unk_168[i].unk_000.lodFraction = 0x41 - i * 4;
        active_pokemon->unk_168[i].unk_000.node.flags |= 1;

        ModelAnim_SetFrame(&active_pokemon->unk_168[i].unk_000, active_pokemon->displayObject.transformAnim.frameFixed >> 0x10);
        ModelAnim_SetAnimation(&active_pokemon->unk_168[i].unk_000, active_pokemon->displayObject.transformAnim.animationId);
        Vec3f_SetComponentsDuplicate(&active_pokemon->unk_168[i].unk_000.scale, 1.0f, 1.0f, 1.0f);
        BattleAnim_Vec3fCopy(&active_pokemon->unk_168[i].unk_000.position, &active_pokemon->displayObject.position);
        BattleAnim_Vec3sCopy(&active_pokemon->unk_168[i].unk_000.rotation, &active_pokemon->displayObject.rotation);
        BattleAnim_Vec3fCopy(&active_pokemon->unk_168[i].unk_000.scale, &active_pokemon->displayObject.scale);
    }
}

void BattleScene_UpdateSecondaryModelTrailPosition(ActivePokemon* arg0, s16 arg1) {
    s32 i;
    f32 sp90;
    s16 sp8E;
    s16 sp8C;
    UNUSED s32 pad;
    f32 sp7C[3] = { 0.2f, 0.25f, 0.3f };   // D_84384638
    f32 sp70[3] = { 0.98f, 0.96f, 0.95f }; // D_84384644

    for (i = 0; i < 2; i++) {
        ModelAnim_SetFrame(&arg0->unk_168[i].unk_000, arg0->displayObject.transformAnim.frameFixed >> 0x10);
        ModelAnim_SetAnimation(&arg0->unk_168[i].unk_000, arg0->displayObject.transformAnim.animationId);
        Vec3f_CalculateDistanceAngles(&arg0->displayObject.position, &arg0->unk_168[i].unk_000.position, &sp90, &sp8E, &sp8C);
        Camera_ComputeEyeFromAngles(&arg0->displayObject.position, &arg0->unk_168[i].unk_000.position, sp7C[i] * sp90, sp8E, sp8C);
        BattleAnim_StepToS16(&arg0->unk_168[i].unk_000.rotation.y, arg0->displayObject.rotation.y, sp70[i] * arg1);
    }
}

void BattleScene_ResetParticipantModelFlags(ActivePokemon* active_pokemon) {
    BattleScene_SetParticipantModelFlags(active_pokemon, 0, 0);
}

void BattleAnim_StatusIdleCase1Sub0(UNUSED ActivePokemon* arg0, ActivePokemon* arg1) {
    arg1->unk_4EC.node.flags |= 1;
    if (arg1 == sActivePokemon[0]) {
        Vec3f_SetComponentsDuplicate(&arg1->unk_4EC.position, 35.0f, 50.0f, -250.0f);
    } else {
        Vec3f_SetComponentsDuplicate(&arg1->unk_4EC.position, -35.0f, 50.0f, -250.0f);
    }
    BattleAnim_InitSwayOffset(arg1, 20.0f, 0x1FFE);
    arg1->animationFlags2++;
    arg1->unk_4EC.node.renderFlags &= ~0x20;
    ModelAnim_SetFrame(&arg1->unk_4EC, 0);
}

void BattleAnim_StatusIdleCase1Sub1(ActivePokemon* arg0, ActivePokemon* arg1) {
    if (arg1 == sSide1ActivePokemon) {
        BattleAnim_UpdateSwayPhysicsToTarget(arg0, arg1, 0, 0, 0x1FFE, 0x4440);
    } else {
        BattleAnim_UpdateSwayPhysicsToTarget(arg0, arg1, 0, 0, 0x1FFE, 0x3BB8);
    }

    arg1->unk_4EC.rotation.x += 0x1555;
    arg1->unk_4EC.rotation.z += 0xE38;

    if (arg1->unk_4EC.position.y < 0) {
        arg1->unk_4EC.node.flags &= ~1;
        arg1->unk_4EC.position.y = 0.0f;
        arg1->swayState.unk_0C.y = 0.0f;
        BattleScene_ResetParticipantModelFlags(arg1);
    }
}

void BattleAnim_StatusIdleCase1(ActivePokemon* arg0, ActivePokemon* arg1) {
    switch (arg1->animationFlags2) {
        case 0:
            BattleAnim_StatusIdleCase1Sub0(arg0, arg1);

        case 1:
            BattleAnim_StatusIdleCase1Sub1(arg0, arg1);
            break;
    }
}

void BattleAnim_StatusIdleCase2Sub0(UNUSED ActivePokemon* arg0, ActivePokemon* arg1) {
    Vec3f_SetComponentsDuplicate(&arg1->unk_4EC.position, arg1->unk_4B0 * -150.0f, 100.0f, 0.0f);
    arg1->animationFlags2++;
    BattleAnim_InitSwayOffset(arg1, 0.0f, 0x3FFC);
    arg1->unk_4EC.node.flags |= 1;
    arg1->unk_4EC.node.renderFlags &= ~0x20;
    ModelAnim_SetFrame(&arg1->unk_4EC, 0);
}

void BattleAnim_StatusIdleCase2Sub1(ActivePokemon* arg0, ActivePokemon* arg1) {
    arg1->unk_4EC.rotation.x += 0x1555;
    arg1->unk_4EC.rotation.z += 0xE38;

    BattleAnim_UpdateSwayPhysicsToTarget(arg0, arg1, 0.0f, 0.0f, 0x4000, 0);

    if (arg1->unk_4EC.position.y < 0) {
        arg1->unk_4EC.rotation.x = 0;
        arg1->unk_4EC.rotation.z = 0;
        if (arg1 == sSide1ActivePokemon) {
            arg1->unk_4EC.rotation.y = 0x4000;
        } else {
            arg1->unk_4EC.rotation.y = -0x4000;
        }
        arg1->swayState.unk_0C.y = 0.0f;
        arg1->unk_4EC.position.y = 2.5f;
        BattleScene_ResetParticipantModelFlags(arg1);
    }
}

void BattleAnim_StatusIdleCase2(ActivePokemon* arg0, ActivePokemon* arg1) {
    switch (arg1->animationFlags2) {
        case 0:
            BattleAnim_StatusIdleCase2Sub0(arg0, arg1);

        case 1:
            BattleAnim_StatusIdleCase2Sub1(arg0, arg1);
            break;
    }
}

void BattleAnim_StatusIdleCase3Sub0(UNUSED ActivePokemon* arg0, ActivePokemon* arg1) {
    Vec3f_SetComponentsDuplicate(&arg1->swayState, 0.0f, 0.0f, 0.0f);
    Vec3f_SetComponentsDuplicate(&arg1->swayState.unk_0C, 0.0f, 0.0f, 0.0f);
    BattleAnim_InitSwayOffset(arg1, D_84384600[0], 0x4000);
    BattleScene_ShowSecondaryModelsStaggeredFrame(arg1);
    arg1->animationFlags2++;
}

void BattleAnim_StatusIdleCase3Sub1(ActivePokemon* arg0, ActivePokemon* arg1) {
    BattleAnim_UpdateSwayPhysicsToOwner(arg0, arg1, 1.45f, 0.015f, 0x4000);
    BattleScene_UpdateSecondaryModelTrailPosition(arg1, 0);
    if (arg0->displayObject.position.y >= 200.0f) {
        arg1->swayState.unk_0C.y = 0.0f;
        BattleScene_ResetParticipantModelFlags(arg1);
        BattleScene_HideParticipantSecondaryModels(arg1);
    }
}

void BattleAnim_StatusIdleCase3(ActivePokemon* arg0, ActivePokemon* arg1) {
    switch (arg1->animationFlags2) {
        case 0:
            BattleAnim_StatusIdleCase3Sub0(arg0, arg1);

        case 1:
            BattleAnim_StatusIdleCase3Sub1(arg0, arg1);
            break;
    }
}

void BattleAnim_StatusIdleCase14Sub0(UNUSED ActivePokemon* arg0, ActivePokemon* arg1) {
    Vec3f_SetComponentsDuplicate(&arg1->swayState, 0.0f, 0.0f, 0.0f);
    Vec3f_SetComponentsDuplicate(&arg1->swayState.unk_0C, 0.0f, 0.0f, 0.0f);
    BattleAnim_InitSwayOffset(arg1, D_84384600[0], 0x4000);
    arg1->animationFlags2++;
}

void BattleAnim_StatusIdleCase14Sub1(ActivePokemon* arg0, ActivePokemon* arg1) {
    BattleAnim_UpdateSwayPhysicsToOwner(arg0, arg1, 2.0f, 0.002f, 0x4000);
    if ((arg0->displayObject.position.y - BattleScene_GetParticipantModelHeight(arg1)) >= 90.0f) {
        arg1->animationFlags2++;
        arg1->swayState.unk_0C.y = 0.0f;
    }
}

void func_8430A4E0(UNUSED ActivePokemon* arg0, UNUSED ActivePokemon* arg1) {
}

void BattleAnim_StatusIdleCase14(ActivePokemon* arg0, ActivePokemon* arg1) {
    switch (arg1->animationFlags2) {
        case 0:
            BattleAnim_StatusIdleCase14Sub0(arg0, arg1);

        case 1:
            BattleAnim_StatusIdleCase14Sub1(arg0, arg1);
            break;

        case 2:
            func_8430A4E0(arg0, arg1);
            break;
    }
}

s32 BattleAnim_ApproachAngleAndCheckThreshold(ActivePokemon* arg0, s16 arg1, s16 arg2) {
    arg0->displayObject.rotation.y -= arg1;

    if (arg1 > 0) {
        if ((arg2 >= arg0->displayObject.rotation.y) && ((arg2 - arg1) < arg0->displayObject.rotation.y)) {
            return 1;
        }
    } else if ((arg0->displayObject.rotation.y >= arg2) && (arg0->displayObject.rotation.y < (arg2 - arg1))) {
        return 1;
    }

    return 0;
}

void BattleAnim_StatusIdleCase4Sub0(UNUSED ActivePokemon* arg0, ActivePokemon* arg1) {
    BattleScene_ShowSecondaryModelsStaggeredFrame(arg1);
    arg1->unk_4A6 = 0;
    arg1->unk_4A4 = 0;
    arg1->animationState = 0;
    arg1->animationFlags2++;
}

void BattleAnim_StatusIdleCase4Sub1(ActivePokemon* arg0, ActivePokemon* arg1) {
    arg1->unk_4A6 = Math_StepToS32(arg1->unk_4A6, 0x3330, 0x16C, 0x16C);

    if (BattleAnim_ApproachAngleAndCheckThreshold(arg0, arg1->unk_4A6, arg1->unk_4B0 << 0xE) != 0) {
        arg1->animationState += 1;
    }

    BattleScene_UpdateSecondaryModelTrailPosition(arg1, arg1->unk_4A6);

    if (arg1->animationState == 3) {
        arg1->animationFlags2 += 1;
    }
}

void BattleAnim_StatusIdleCase4Sub2(ActivePokemon* arg0, ActivePokemon* arg1) {
    f32 tmp = 0x4000 - arg0->displayObject.rotation.y;
    f32 var_fa1;
    s16 sp26;
    s32 sp20;

    var_fa1 = (131072.0 - tmp) / 131072.0;
    if (var_fa1 >= 1.0f) {
        var_fa1 -= 1.0f;
    }

    sp26 = (arg1->unk_4A6 * var_fa1) * 0.8;
    if (sp26 < 0xE38) {
        sp26 = 0xE38;
    }
    sp20 = BattleAnim_ApproachAngleAndCheckThreshold(arg0, sp26, arg1->unk_4B0 << 0xE);
    BattleScene_UpdateSecondaryModelTrailPosition(arg1, sp26);

    if (sp20 != 0) {
        arg0->displayObject.rotation.y = arg1->unk_4B0 << 0xE;
        BattleScene_ResetParticipantModelFlags(arg1);
        BattleScene_HideParticipantSecondaryModels(arg1);
    }
}

void BattleAnim_StatusIdleCase4(ActivePokemon* arg0, ActivePokemon* arg1) {
    switch (arg1->animationFlags2) {
        case 0:
            BattleAnim_StatusIdleCase4Sub0(arg0, arg1);

        case 1:
            BattleAnim_StatusIdleCase4Sub1(arg0, arg1);
            break;

        case 2:
            BattleAnim_StatusIdleCase4Sub2(arg0, arg1);
            break;
    }
}

void BattleAnim_StatusIdleCase5Sub0(UNUSED ActivePokemon* arg0, ActivePokemon* arg1) {
    arg1->unk_4A6 = 0;
    arg1->unk_4A4 = 0;
    arg1->animationState = 0;
    arg1->animationFlags2++;
}

void BattleAnim_StatusIdleCase5Sub1(ActivePokemon* arg0, ActivePokemon* arg1) {
    arg1->unk_4A6 = Math_StepToS32(arg1->unk_4A6, 0x3FFC, 0x16C, 0x16C);

    if (BattleAnim_ApproachAngleAndCheckThreshold(arg0, arg1->unk_4A6, arg1->unk_4B0 << 0xE) != 0) {
        arg1->animationState += 1;
    }

    if (arg1->animationState >= 3) {
        BattleScene_ShowSecondaryModelsStaggeredFrame(arg1);
        arg1->animationFlags2 += 1;
    }
}

void BattleAnim_StatusIdleCase5Sub2(ActivePokemon* arg0, ActivePokemon* arg1) {
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    UNUSED s16 pad;
    u8 sp28[] = { 0x5F, 0x92 }; // D_84384650

    BattleAnim_ApproachAngleAndCheckThreshold(arg0, arg1->unk_4A6, arg1->unk_4B0 << 0xE);

    if (BattleScene_ByteArrayContains(arg1->displayObject.objectType, sp28, sizeof(sp28)) != 0) {
        sp30 = 10.3f;
        sp34 = 10.0f;
        sp2C = 0.035f;
    } else {
        sp30 = 3.8f;
        sp34 = 3.5f;
        sp2C = 0.045f;
    }

    BattleScene_UpdateSecondaryModelTrailPosition(arg1, arg1->unk_4A6);
    BattleAnim_ApproachF(&arg0->displayObject.position.y, -(BattleAnim_GetOwnerModelHeight(arg1) * sp30), sp2C);

    if (arg0->displayObject.position.y <= -(BattleAnim_GetOwnerModelHeight(arg1) * sp34)) {
        Vec3s_SetComponents(&arg0->displayObject.rotation, 0, arg1->unk_4B0 << 0xE, 0);
        BattleScene_ResetParticipantModelFlags(arg1);
        BattleScene_HideParticipantSecondaryModels(arg1);
    }
}

void BattleAnim_StatusIdleCase5(ActivePokemon* arg0, ActivePokemon* arg1) {
    switch (arg1->animationFlags2) {
        case 0:
            BattleAnim_StatusIdleCase5Sub0(arg0, arg1);

        case 1:
            BattleAnim_StatusIdleCase5Sub1(arg0, arg1);
            break;

        case 2:
            BattleAnim_StatusIdleCase5Sub2(arg0, arg1);
            break;
    }
}

void BattleAnim_StatusIdleCase6Sub0(ActivePokemon* arg0, ActivePokemon* arg1) {
    arg1->unk_4A6 = 0;
    arg1->unk_4A4 = 0;
    arg1->animationState = 0;
    arg1->unk_4A0 = 0.0f;
    BattleScene_PositionParticipantModel(arg1);
    Vec3s_SetComponents(&arg0->displayObject.rotation, 0, arg1->unk_4B0 << 0xE, 0);
    BattleScene_ShowSecondaryModelsStaggeredFrame(arg1);
    arg1->animationFlags2++;
}

void BattleAnim_StatusIdleCase6Sub1(ActivePokemon* arg0, ActivePokemon* arg1) {
    f32 tmp;
    Vec3f sp20 = { 0.0f, 0.0f, 0.0f }; // D_84384654

    BattleAnim_ApproachF(&arg1->unk_4A0, 50.0f, 0.1f);
    arg1->unk_4A6 += 0xE38;
    tmp = SINS(arg1->unk_4A6) * arg1->unk_4A0;
    BattleAnim_Vec3fSetPolarXZ(&sp20, tmp, arg0->displayObject.rotation.y);
    BattleScene_PositionParticipantModel(arg1);
    Vec3f_AddInPlace(&arg0->displayObject.position, &sp20);
    BattleScene_UpdateSecondaryModelTrailPosition(arg1, 0);

    if (arg1->unk_4A0 > 49.0f) {
        arg1->animationFlags2++;
    }
}

void BattleAnim_StatusIdleCase6Sub2(ActivePokemon* arg0, ActivePokemon* arg1) {
    f32 tmp;
    Vec3f sp20 = { 0.0f, 0.0f, 0.0f };

    BattleAnim_ApproachF(&arg1->unk_4A0, 0.0f, 0.1f);
    arg1->unk_4A6 += 0xE38;

    tmp = SINS(arg1->unk_4A6) * arg1->unk_4A0;
    BattleAnim_Vec3fSetPolarXZ(&sp20, tmp, arg0->displayObject.rotation.y);

    BattleScene_PositionParticipantModel(arg1);
    Vec3f_AddInPlace(&arg0->displayObject.position, &sp20);
    BattleScene_UpdateSecondaryModelTrailPosition(arg1, 0);

    if (arg1->unk_4A0 <= 0.5f) {
        BattleScene_PositionParticipantModel(arg1);
        Vec3s_SetComponents(&arg0->displayObject.rotation, 0, arg1->unk_4B0 << 0xE, 0);
        BattleScene_ResetParticipantModelFlags(arg1);
        BattleScene_HideParticipantSecondaryModels(arg1);
    }
}

void BattleAnim_StatusIdleCase6(ActivePokemon* arg0, ActivePokemon* arg1) {
    switch (arg1->animationFlags2) {
        case 0:
            BattleAnim_StatusIdleCase6Sub0(arg0, arg1);

        case 1:
            BattleAnim_StatusIdleCase6Sub1(arg0, arg1);
            break;

        case 2:
            BattleAnim_StatusIdleCase6Sub2(arg0, arg1);
            break;
    }
}

void BattleAnim_StatusIdleCase7Sub0(ActivePokemon* arg0, ActivePokemon* arg1) {
    BattleScene_ShowSecondaryModelsAtMainTransform(arg1);
    arg1->unk_4AC = 0;
    BattleScene_PositionParticipantModel(arg1);
    Vec3s_SetComponents(&arg0->displayObject.rotation, 0, arg1->unk_4B0 << 0xE, 0);
    arg1->animationFlags2++;
}

void BattleAnim_StatusIdleCase7Sub1(UNUSED ActivePokemon* arg0, ActivePokemon* arg1) {
    BattleScene_UpdateSecondaryModelOrbit(arg1);
    arg1->unk_4AC++;
    if (arg1->unk_4AC == 0x3C) {
        BattleScene_ResetParticipantModelFlags(arg1);
        BattleScene_HideParticipantSecondaryModels(arg1);
    }
}

void BattleAnim_StatusIdleCase7(ActivePokemon* arg0, ActivePokemon* arg1) {
    switch (arg1->animationFlags2) {
        case 0:
            BattleAnim_StatusIdleCase7Sub0(arg0, arg1);

        case 1:
            BattleAnim_StatusIdleCase7Sub1(arg0, arg1);
            break;
    }
}

void BattleAnim_ResetOwnerFacingAndExitStatusIdle(ActivePokemon* arg0) {
    UNUSED s32 pad;
    CameraNode* sp18 = sBattleScene.unk_00->unk_DC;

    BattleScene_PositionParticipantModel(arg0);
    Vec3s_SetComponents(&arg0->displayObject.rotation, 0, arg0->unk_4B0 << 0xE, 0);
    Vec3f_SetComponentsDuplicate(&sp18->view.upDirection, 0.0f, 1.0f, 0.0f);
    BattleScene_ResetParticipantModelFlags(arg0);
}

void BattleAnim_StatusIdleCase8Sub0(ActivePokemon* arg0, ActivePokemon* arg1) {
    arg1->unk_4A6 = 0;
    arg1->unk_4A8 = 0;
    arg1->unk_4A4 = 0;
    arg1->animationState = 0;
    arg1->unk_4A0 = 0.0f;
    BattleScene_PositionParticipantModel(arg1);
    Vec3s_SetComponents(&arg0->displayObject.rotation, 0, arg1->unk_4B0 << 0xE, 0);
    arg1->animationFlags2++;
}

void BattleAnim_StatusIdleCase8Sub1(UNUSED ActivePokemon* arg0, ActivePokemon* arg1) {
    CameraNode* temp_s0 = sBattleScene.unk_00->unk_DC;
    f32 temp_fa0;
    f32 temp_fa1_2;
    f32 temp_ft4;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 temp_fv0_2;
    f32 temp_fv1_2;

    BattleAnim_StepToS16(&arg1->unk_4A4, 0x5B0, 0x3C);
    BattleAnim_StepToS16(&arg1->unk_4A8, -0x8000, arg1->unk_4A4);

    sp2C = temp_s0->view.targetPosition.x - temp_s0->view.eyePosition.x;
    sp28 = temp_s0->view.targetPosition.y - temp_s0->view.eyePosition.y;
    sp24 = temp_s0->view.targetPosition.z - temp_s0->view.eyePosition.z;

    temp_fv0_2 = sqrtf(SQ(sp2C) + SQ(sp28) + SQ(sp24));

    temp_fa0 = sp2C / temp_fv0_2;
    temp_fv1_2 = sp28 / temp_fv0_2;
    temp_fa1_2 = sp24 / temp_fv0_2;

    temp_ft4 = 1.0 - COSS(arg1->unk_4A8);

    temp_s0->view.upDirection.x = (temp_ft4 * temp_fa0 * temp_fv1_2) - (SINS(arg1->unk_4A8) * temp_fa1_2);
    temp_s0->view.upDirection.y = COSS(arg1->unk_4A8) + ((temp_ft4 * temp_fv1_2) * temp_fv1_2);
    temp_s0->view.upDirection.z = (SINS(arg1->unk_4A8) * temp_fa0) + ((temp_ft4 * temp_fv1_2) * temp_fa1_2);

    if (arg1->displayObject.position.y < 0.0f) {
        arg1->displayObject.position.y = 0.0f;
    }
}

void BattleAnim_StatusIdleCase8(ActivePokemon* arg0, ActivePokemon* arg1) {
    switch (arg1->animationFlags2) {
        case 0:
            BattleAnim_StatusIdleCase8Sub0(arg0, arg1);

        case 1:
            BattleAnim_StatusIdleCase8Sub1(arg0, arg1);
            break;
    }
}

void BattleAnim_StatusIdleCase9Sub0(ActivePokemon* arg0, ActivePokemon* arg1) {
    if (arg0->displayObject.scale.y != 1.0f) {
        BattleScene_ResetParticipantModelFlags(arg1);
    } else {
        BattleScene_ShowSecondaryModelsAtMainPose(arg1);
        arg1->animationFlags2++;
    }
}

void BattleAnim_StatusIdleCase9Sub1(ActivePokemon* arg0, ActivePokemon* arg1) {
    f32 temp_fv0;

    temp_fv0 = Math_StepToF(arg0->displayObject.scale.x, 0.8f, 0.01f, 0.01f);
    arg0->displayObject.scale.x = temp_fv0;
    arg0->displayObject.scale.y = temp_fv0;
    arg0->displayObject.scale.z = temp_fv0;

    BattleScene_ShrinkSecondaryModelsToScale(arg1);

    if (arg0->displayObject.scale.y <= 0.8) {
        BattleScene_ResetParticipantModelFlags(arg1);
        BattleScene_HideParticipantSecondaryModels(arg1);
    }
}

void BattleAnim_StatusIdleCase9(ActivePokemon* arg0, ActivePokemon* arg1) {
    switch (arg1->animationFlags2) {
        case 0:
            BattleAnim_StatusIdleCase9Sub0(arg0, arg1);

        case 1:
            BattleAnim_StatusIdleCase9Sub1(arg0, arg1);
            break;
    }
}

void BattleAnim_StatusIdleCase12Sub0(UNUSED ActivePokemon* arg0, ActivePokemon* arg1) {
    arg1->animationFlags2++;
}

void BattleAnim_StatusIdleCase12Sub1(ActivePokemon* arg0, UNUSED ActivePokemon* arg1) {
    arg0->displayObject.scale.x = Math_StepToF(arg0->displayObject.scale.x, 0.0f, 0.05f, 0.05f);
    arg0->displayObject.scale.y = Math_StepToF(arg0->displayObject.scale.y, 0.0f, 0.05f, 0.05f);
    arg0->displayObject.scale.z = Math_StepToF(arg0->displayObject.scale.z, 0.0f, 0.05f, 0.05f);

    if (arg0->displayObject.scale.y <= 0.1) {
        Vec3f_SetComponentsDuplicate(&arg0->displayObject.scale, 0.001f, 0.001f, 0.001f);
    }
}

void BattleAnim_StatusIdleCase12(ActivePokemon* arg0, ActivePokemon* arg1) {
    switch (arg1->animationFlags2) {
        case 0:
            BattleAnim_StatusIdleCase12Sub0(arg0, arg1);

        case 1:
            BattleAnim_StatusIdleCase12Sub1(arg0, arg1);
            break;
    }
}

void BattleAnim_StatusIdleCase13Sub0(ActivePokemon* arg0, ActivePokemon* arg1) {
    arg1->unk_4A4 = 0x16C;
    arg1->unk_4A6 = 0;
    arg1->unk_4A8 = 0;
    arg1->unk_4A0 = 0.4f;
    arg1->swayState.unk_0C.x = arg0->displayObject.scale.x;
    arg1->swayState.unk_0C.y = arg0->displayObject.scale.y;
    arg1->swayState.unk_0C.z = arg0->displayObject.scale.z;
    arg1->animationFlags2++;
}

void BattleAnim_StatusIdleCase13Sub1(ActivePokemon* arg0, ActivePokemon* arg1) {
    f32 var_fv0;

    // clang-format off
    if ((arg1->unk_4A4 >= 0) && (arg1->unk_4A4 <= 0x8000)) { arg1->unk_4A4 += 0x2D; }
    // clang-format on

    arg1->unk_4A8 = SINS(arg1->unk_4A4) * 182.0f * 15.0f;

    if ((arg1->unk_4A6 >= 0) && (arg1->unk_4A6 <= 0x4000)) {
        arg1->unk_4A6 += arg1->unk_4A8;
    }

    if (arg1->state.runtime.unk_56 == 0) {
        var_fv0 = 1.0f;
    } else {
        var_fv0 = 0.8f;
    }

    arg0->displayObject.scale.x = var_fv0 - (SINS(arg1->unk_4A6) * arg1->unk_4A0);
    arg0->displayObject.scale.y = (SINS(arg1->unk_4A6) * arg1->unk_4A0) + var_fv0;
    arg0->displayObject.scale.z = var_fv0 - (SINS(arg1->unk_4A6) * arg1->unk_4A0);

    if ((arg1->unk_4A6 >= 0x4000) && (arg1->unk_4A6 >= 0x4000)) {
        arg1->unk_4A8 = 0x1554;
        arg1->animationFlags2++;
    }
}

void BattleAnim_StatusIdleCase13Sub2(ActivePokemon* arg0, ActivePokemon* arg1) {
    f32 var_fv0;
    f32 var_fv1;

    arg1->unk_4A6 += arg1->unk_4A8;
    var_fv1 = SINS(arg1->unk_4A6) * arg1->unk_4A0;
    if (var_fv1 <= 0.01f) {
        arg1->unk_4A8 += 0x444;
        arg1->unk_4A0 *= 0.8f;
        if (1) {}
        var_fv1 = SINS(arg1->unk_4A6) * arg1->unk_4A0;
    }

    if (arg1->state.runtime.unk_56 == 0) {
        var_fv0 = 1.0f;
    } else {
        var_fv0 = 0.8f;
    }

    arg0->displayObject.scale.x = var_fv0 - var_fv1;
    arg0->displayObject.scale.y = (SINS(arg1->unk_4A6) * arg1->unk_4A0) + var_fv0;
    arg0->displayObject.scale.z = var_fv0 - (SINS(arg1->unk_4A6) * arg1->unk_4A0);

    if (arg1->unk_4A0 <= 0.01f) {
        arg0->displayObject.scale.x = var_fv0;
        arg0->displayObject.scale.y = var_fv0;
        arg0->displayObject.scale.z = var_fv0;
        BattleScene_ResetParticipantModelFlags(arg1);
    }
}

void BattleAnim_StatusIdleCase13(ActivePokemon* arg0, ActivePokemon* arg1) {
    switch (arg1->animationFlags2) {
        case 0:
            BattleAnim_StatusIdleCase13Sub0(arg0, arg1);

        case 1:
            BattleAnim_StatusIdleCase13Sub1(arg0, arg1);
            break;

        case 2:
            BattleAnim_StatusIdleCase13Sub2(arg0, arg1);
            break;
    }
}

void BattleAnim_StatusIdleCase15Sub0(ActivePokemon* arg0, ActivePokemon* arg1) {
    arg1->unk_4A8 = 0x71C;
    arg1->unk_4A0 = 0.4f;
    arg1->swayState.unk_0C.x = arg0->displayObject.scale.x;
    arg1->swayState.unk_0C.y = arg0->displayObject.scale.y;
    arg1->swayState.unk_0C.z = arg0->displayObject.scale.z;
    arg1->animationFlags2++;
}

void BattleAnim_StatusIdleCase15Sub1(ActivePokemon* arg0, ActivePokemon* arg1) {
    BattleMonRuntime* temp_a0 = &arg1->state.runtime;
    s16 sp22;

    arg1->unk_4A8 += 0xCCC;
    sp22 = arg1->unk_4A8;

    arg1->unk_4A0 = Math_StepToF(arg1->unk_4A0, 0.0f, 0.02f, 0.02f);

    if (sp22 > 0) {
        sp22 *= -1;
    }

    if (temp_a0->unk_56 == 0) {
        arg0->displayObject.scale.x = 1.0f - (SINS(sp22) * arg1->unk_4A0);
        arg0->displayObject.scale.y = (SINS(sp22) * arg1->unk_4A0) + 1.0f;
        arg0->displayObject.scale.z = 1.0f - (SINS(sp22) * arg1->unk_4A0);
    } else {
        arg0->displayObject.scale.x = 0.8 - (SINS(sp22) * arg1->unk_4A0);
        arg0->displayObject.scale.y = (SINS(sp22) * arg1->unk_4A0) + 0.8;
        arg0->displayObject.scale.z = 0.8 - (SINS(sp22) * arg1->unk_4A0);
    }

    if (arg1->unk_4A0 <= 0.01f) {
        if (temp_a0->unk_56 == 0) {
            Vec3f_SetComponentsDuplicate(&arg0->displayObject.scale, 1.0f, 1.0f, 1.0f);
        } else {
            Vec3f_SetComponentsDuplicate(&arg0->displayObject.scale, 0.8f, 0.8f, 0.8f);
        }
        BattleScene_ResetParticipantModelFlags(arg1);
    }
}

void BattleAnim_StatusIdleCase15(ActivePokemon* arg0, ActivePokemon* arg1) {
    switch (arg1->animationFlags2) {
        case 0:
            BattleAnim_StatusIdleCase15Sub0(arg0, arg1);

        case 1:
            BattleAnim_StatusIdleCase15Sub1(arg0, arg1);
            break;
    }
}

void BattleAnim_StatusIdleCase16Sub0(UNUSED ActivePokemon* arg0, ActivePokemon* arg1) {
    arg1->unk_4AC = 0;
    arg1->animationFlags2++;
}

void BattleAnim_StatusIdleCase16Sub1(ActivePokemon* arg0, ActivePokemon* arg1) {
    BattleMonRuntime* ptr = &arg1->state.runtime;
    UNUSED s32 pad;
    f32 temp_fs0;

    if (ptr->unk_56 == 0) {
        temp_fs0 = (1.0f - Strip400_GetTailFadeRatio()) * 0.6f;
        BattleAnim_ApproachF(&arg0->displayObject.scale.x, 1.0f - temp_fs0, 0.5f);
        BattleAnim_ApproachF(&arg0->displayObject.scale.y, 1.0f + temp_fs0, 0.5f);
        BattleAnim_ApproachF(&arg0->displayObject.scale.z, 1.0f - temp_fs0, 0.5f);
    } else {
        temp_fs0 = (1.0f - Strip400_GetTailFadeRatio()) * 0.3f;
        BattleAnim_ApproachF(&arg0->displayObject.scale.x, 0.8 - temp_fs0, 0.5f);
        BattleAnim_ApproachF(&arg0->displayObject.scale.y, temp_fs0 + 0.8, 0.5f);
        BattleAnim_ApproachF(&arg0->displayObject.scale.z, 0.8 - temp_fs0, 0.5f);
    }
}

void BattleAnim_StatusIdleCase16(ActivePokemon* arg0, ActivePokemon* arg1) {
    switch (arg1->animationFlags2) {
        case 0:
            BattleAnim_StatusIdleCase16Sub0(arg0, arg1);

        case 1:
            BattleAnim_StatusIdleCase16Sub1(arg0, arg1);
            break;
    }
}

void BattleAnim_StatusIdleCase10Sub0(UNUSED ActivePokemon* arg0, ActivePokemon* arg1) {
    arg1->animationState = 0;
    arg1->animationFlags2++;
}

void BattleAnim_StatusIdleCase10Sub1(ActivePokemon* arg0, ActivePokemon* arg1) {
    f32 sp24;
    f32 sp20;

    arg1->animationState++;
    sp20 = TerrainGrid_SampleHeightAndSlope(arg0->displayObject.position.x, arg0->displayObject.position.z, &sp24);
    arg0->displayObject.position.y = BattleScene_GetParticipantModelHeight(arg1) + sp20;
    arg0->displayObject.rotation.x = (s16)sp24 * 0xB6;

    if (arg1->animationState == 0x12C) {
        arg0->displayObject.position.y = BattleScene_GetParticipantModelHeight(arg1);
        arg0->displayObject.rotation.x = 0;
        BattleScene_ResetParticipantModelFlags(arg1);
    }
}

void BattleAnim_StatusIdleCase10(ActivePokemon* arg0, ActivePokemon* arg1) {
    switch (arg1->animationFlags2) {
        case 0:
            BattleAnim_StatusIdleCase10Sub0(arg0, arg1);

        case 1:
            BattleAnim_StatusIdleCase10Sub1(arg0, arg1);
            break;
    }
}

void BattleAnim_StatusIdleCase0(UNUSED ActivePokemon* arg0, UNUSED ActivePokemon* arg1) {
}

void BattleAnim_UpdateOwnerStatusIdleAnimation(s32 side_index) {
    ActivePokemon* owner = sActivePokemon[side_index];
    ActivePokemon* animated_pokemon = sActivePokemon[side_index];

    switch (sActivePokemon[side_index]->animationFlags1) {
        case 0:
            BattleAnim_StatusIdleCase0(owner, animated_pokemon);
            break;

        case 1:
            BattleAnim_StatusIdleCase1(owner, animated_pokemon);
            break;

        case 2:
            BattleAnim_StatusIdleCase2(owner, animated_pokemon);
            break;

        case 3:
            BattleAnim_StatusIdleCase3(owner, animated_pokemon);
            break;

        case 4:
            BattleAnim_StatusIdleCase4(owner, animated_pokemon);
            break;

        case 5:
            BattleAnim_StatusIdleCase5(owner, animated_pokemon);
            break;

        case 6:
            BattleAnim_StatusIdleCase6(owner, animated_pokemon);
            break;

        case 7:
            BattleAnim_StatusIdleCase7(owner, animated_pokemon);
            break;

        case 8:
            BattleAnim_StatusIdleCase8(owner, animated_pokemon);
            break;

        case 9:
            BattleAnim_StatusIdleCase9(owner, animated_pokemon);
            break;

        case 10:
            BattleAnim_StatusIdleCase10(owner, animated_pokemon);
            break;

        case 12:
            BattleAnim_StatusIdleCase12(owner, animated_pokemon);
            break;

        case 13:
            BattleAnim_StatusIdleCase13(owner, animated_pokemon);
            break;

        case 14:
            BattleAnim_StatusIdleCase14(owner, animated_pokemon);
            break;

        case 15:
            BattleAnim_StatusIdleCase15(owner, animated_pokemon);
            break;

        case 16:
            BattleAnim_StatusIdleCase16(owner, animated_pokemon);
            break;

        default:
            BattleScene_ResetParticipantModelFlags(animated_pokemon);
            break;
    }
}

void BattleAnim_SetOwnerSecondaryStatusFlags(ActivePokemon* arg0, u8 arg1, u8 arg2) {
    arg0->unk_4E8 = arg1;
    arg0->unk_4E9 = arg2;
}

void BattleAnim_ClearOwnerSecondaryStatusFlags(ActivePokemon* arg0) {
    arg0->unk_4E8 = 0;
    arg0->unk_4E9 = 0;
}

void BattleAnim_InitSecondarySwayOffset(ActivePokemon* arg0, f32 arg1, s16 arg2) {
    arg0->unk_4E4 = arg1;
    arg0->unk_4D8.z = COSS(arg2) * arg1;
    arg0->unk_4D8.y = SINS(arg2) * arg1;
}

void BattleAnim_UpdateSecondarySwayPhysics(ActivePokemon* arg0, ActivePokemon* arg1, UNUSED f32 arg2, UNUSED f32 arg3, UNUSED s32 arg4) {
    f32 tmp1 = 0.01f;
    f32 tmp2 = 18.0f;
    Vec3f sp2C;
    f32 temp_fa1;
    f32 temp_fa2;

    temp_fa1 = -tmp1 * arg1->unk_4D8.z;
    temp_fa2 = -tmp2 - (tmp1 * arg1->unk_4D8.y);

    arg1->unk_4D8.z = arg1->unk_4D8.z + (temp_fa1 * 0.05f);
    arg1->unk_4D8.y = arg1->unk_4D8.y + (temp_fa2 * 0.05f);
    sp2C.y = arg1->unk_4D8.y;
    arg1->unk_4D8.x = 0.0f;

    BattleAnim_Vec3fSetPolarXZ(&sp2C, arg1->unk_4D8.z, arg0->displayObject.rotation.y + 0x4000);
    Vec3f_AddInPlace(&arg0->displayObject.position, &sp2C);
}

void BattleAnim_SecondaryStatusCaseBSub0(UNUSED ActivePokemon* arg0, ActivePokemon* arg1) {
    Vec3f_SetComponentsDuplicate(&arg1->unk_4CC, 0.0f, 0.0f, 0.0f);
    Vec3f_SetComponentsDuplicate(&arg1->unk_4D8, 0.0f, 0.0f, 0.0f);
    BattleAnim_InitSecondarySwayOffset(arg1, 23.0f, 0x2E36);
    arg1->unk_4E9++;
}

void BattleAnim_SecondaryStatusCaseBSub1(ActivePokemon* arg0, ActivePokemon* arg1) {
    BattleAnim_UpdateSecondarySwayPhysics(arg0, arg1, 0, 0, 0x2E36);
    if (arg1->displayObject.position.y < BattleScene_GetParticipantModelHeight(arg1)) {
        arg1->unk_4D8.y = 0.0f;
        arg1->displayObject.position.y = BattleScene_GetParticipantModelHeight(arg1);
        BattleAnim_ClearOwnerSecondaryStatusFlags(arg1);
    }
}

void BattleAnim_SecondaryStatusCaseB(ActivePokemon* arg0, ActivePokemon* arg1) {
    switch (arg1->unk_4E9) {
        case 0:
            BattleAnim_SecondaryStatusCaseBSub0(arg0, arg1);

        case 1:
            BattleAnim_SecondaryStatusCaseBSub1(arg0, arg1);
            break;
    }
}

void BattleAnim_SecondaryStatusDefault(UNUSED ActivePokemon* arg0, UNUSED ActivePokemon* arg1) {
}

void BattleAnim_UpdateOwnerSecondaryStatusAnimation(s32 arg0) {
    ActivePokemon* temp_v0 = sActivePokemon[arg0];
    ActivePokemon* temp_v1 = sActivePokemon[arg0];

    if (temp_v1->unk_4E8 == 0xB) {
        BattleAnim_SecondaryStatusCaseB(temp_v0, temp_v1);
    } else {
        BattleAnim_SecondaryStatusDefault(temp_v0, temp_v1);
    }
}

static s32 pad_D_8438466C = 0;

s16 sChargeMoveCues[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0,    0, 0xA9, 0, 0, 0, 0, 0, 0xAA, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0,    0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0,    0, 0,    0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0,    0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0xAB, 0,    0, 0,    0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0xAC, 0, 0, 0, 0, 0, 0,    0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0,    0, 0,    0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0xAD, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0xAE, 0, 0,    0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0,    0, 0,
};

unk_D_843847BC D_843847BC[2] = {
    {
        0xFFB8,
        0x0048,
        0x0020,
        10.0f,
        10.0f,
        1280.0f,
        0x0001,
    },
    {
        0x015F,
        0x0080,
        0x0020,
        10.0f,
        10.0f,
        1280.0f,
        0xFFFF,
    },
};

unk_D_86B0C160 D_843847EC[] = {
    {
        0,
        0,
        0,
        0,
        14563,
        0.0f,
        4.5f,
        0,
        0,
        0,
        9102,
        0,
        0.0f,
        8.5f,
        0.10000000149011612f,
        0.019999999552965164f,
        30.0f,
    },
    {
        0,
        0,
        0,
        0,
        12743,
        0.0f,
        8.0f,
        0,
        0,
        0,
        0,
        0,
        0.0f,
        4.0f,
        0.15000000596046448f,
        0.009999999776482582f,
        30.0f,
    },
    {
        0,
        16384,
        0,
        0,
        7281,
        3.5f,
        3.0f,
        0,
        -16384,
        0,
        0,
        0,
        0.0f,
        3.0f,
        0.15000000596046448f,
        0.019999999552965164f,
        50.0f,
    },
};
unk_D_86B0C160 D_84384888[] = {
    {
        0,
        0,
        0,
        364,
        7281,
        0.0f,
        8.0f,
        0,
        0,
        0,
        364,
        0,
        1.0f,
        2.0f,
        0.30000001192092896f,
        0.009999999776482582f,
        70.0f,
    },
    {
        0,
        0,
        0,
        0,
        30030,
        0.0f,
        3.5f,
        0,
        0,
        0,
        1820,
        3640,
        0.0f,
        20.0f,
        0.15000000596046448f,
        0.009999999776482582f,
        50.0f,
    },
};

unk_D_86B0C160 D_843848F0 = {
    0, 0, 0, 0, 0, 0.0f, 0.0f, 0, 0, 0, 0, 5461, 0.0f, 3.5f, 0.20000000298023224f, 0.05999999865889549f, 200.0f,
};

unk_D_86B0C160 D_84384924 = {
    0, 0, 0, 0, 0, 0.0f, 0.0f, 0, 0, 0, 4550, 31850, 0.0f, 6.0f, 0.20000000298023224f, 0.03999999910593033f, 200.0f,
};

unk_D_86B0C160 D_84384958 = {
    0, 0, 0, 0, 0, 0.0f, 0.0f, 0, 0, 0, 3640, -32768, 0.0f, 6.0f, 0.20000000298023224f, 0.07999999821186066f, 200.0f,
};

unk_D_86B0C160 D_8438498C = {
    0, 0, 0, 0, 0, 0.0f, 0.0f, 0, 0, 0, 0, 0, 0.0f, 3.5f, 0.20000000298023224f, 0.05999999865889549f, 200.0f,
};

unk_D_86B0C160 D_843849C0[] = {
    {
        0,
        0,
        0,
        0,
        14563,
        1.0f,
        4.5f,
        0,
        0,
        0,
        9102,
        0,
        0.0f,
        8.5f,
        0.10000000149011612f,
        0.019999999552965164f,
        200.0f,
    },
    {
        0,
        0,
        0,
        10922,
        0,
        0.0f,
        8.5f,
        0,
        0,
        0,
        0,
        0,
        0.0f,
        4.0f,
        0.25f,
        0.019999999552965164f,
        200.0f,
    },
    {
        0,
        0,
        0,
        0,
        14563,
        0.0f,
        3.5f,
        0,
        0,
        0,
        9102,
        7281,
        0.0f,
        8.5f,
        0.15000000596046448f,
        0.019999999552965164f,
        200.0f,
    },
    {
        0,
        0,
        0,
        0,
        14563,
        0.0f,
        6.5f,
        0,
        0,
        0,
        0,
        0,
        0.0f,
        4.0f,
        0.20000000298023224f,
        0.019999999552965164f,
        200.0f,
    },
    {
        0,
        0,
        0,
        7281,
        16384,
        0.0f,
        7.5f,
        0,
        0,
        0,
        0,
        0,
        0.0f,
        3.5f,
        0.20000000298023224f,
        0.019999999552965164f,
        200.0f,
    },
    {
        0,
        0,
        0,
        -1820,
        16384,
        0.0f,
        4.5f,
        0,
        0,
        0,
        1820,
        0,
        0.0f,
        3.5f,
        0.20000000298023224f,
        0.019999999552965164f,
        200.0f,
    },
};

unk_D_86B0C160 D_84384AF8 = {
    0, 0, 0, 2184, 0, 0.0f, 10.5f, 0, 0, 0, 182, 0, 0.0f, 2.0f, 0.20000000298023224f, 0.014999999664723873f, 50.0f,
};

unk_D_86B0C160 D_84384B2C[] = {
    {
        0,
        0,
        0,
        10922,
        0,
        0.0f,
        600.0f,
        0,
        0,
        0,
        0,
        0,
        0.0f,
        550.0f,
        0.20000000298023224f,
        0.03999999910593033f,
        40.0f,
    },
    {
        0,
        0,
        0,
        10922,
        12743,
        0.0f,
        625.0f,
        0,
        0,
        0,
        0,
        0,
        0.0f,
        450.0f,
        0.20000000298023224f,
        0.029999999329447746f,
        40.0f,
    },
    {
        0,
        0,
        0,
        -546,
        0,
        0.0f,
        450.0f,
        0,
        0,
        0,
        10922,
        0,
        0.0f,
        500.0f,
        0.20000000298023224f,
        0.02500000037252903f,
        40.0f,
    },
    {
        0,
        0,
        0,
        0,
        -12743,
        0.0f,
        750.0f,
        0,
        0,
        0,
        0,
        0,
        0.0f,
        450.0f,
        0.20000000298023224f,
        0.03999999910593033f,
        40.0f,
    },
    {
        0,
        0,
        0,
        -546,
        0,
        0.0f,
        50.0f,
        0,
        0,
        0,
        -546,
        0,
        0.0f,
        400.0f,
        0.20000000298023224f,
        0.029999999329447746f,
        80.0f,
    },
};

Vec3f D_84384C30[] = {
    { 0.17000000178813934f, 11.5f, -1.5f },
    { 0.10999999940395355f, 27.0f, -2.5f },
    { 0.12999999523162842f, 55.0f, 15.0f },
    { 0.2199999988079071f, 0.0f, -0.5f },
    { 0.1599999964237213f, 14.5f, 2.5f },
    { 0.3199999928474426f, 0.0f, 0.0f },
    { 0.20000000298023224f, 7.0f, 0.5f },
    { 0.20999999344348907f, 12.0f, -3.5f },
    { 0.23000000417232513f, -18.5f, 9.5f },
    { 0.4099999964237213f, -2.5f, -1.5f },
    { 0.1899999976158142f, 7.0f, 1.0f },
    { 0.2800000011920929f, 0.0f, 4.0f },
    { 0.2800000011920929f, 2.5f, 0.5f },
    { 0.23999999463558197f, -1.5f, -3.0f },
    { 0.2199999988079071f, 6.0f, 6.5f },
    { 0.6800000071525574f, -1.5f, -1.5f },
    { 0.800000011920929f, 0.0f, -3.5f },
    { 0.49000000953674316f, -0.5f, -55.0f },
    { 0.27000001072883606f, 2.5f, 2.5f },
    { 0.2800000011920929f, 0.0f, 0.0f },
    { 0.28999999165534973f, 4.0f, -2.5f },
    { 0.23999999463558197f, 0.0f, 2.5f },
    { 0.27000001072883606f, 0.0f, -6.0f },
    { 0.2800000011920929f, 7.5f, 17.5f },
    { 0.33000001311302185f, 0.0f, -3.0f },
    { 0.4000000059604645f, 0.0f, -6.0f },
    { 0.4000000059604645f, 0.0f, -7.0f },
    { 0.28999999165534973f, 0.0f, -5.5f },
    { 0.20999999344348907f, 5.5f, 5.0f },
    { 0.20999999344348907f, 6.5f, 0.0f },
    { 0.2199999988079071f, 11.0f, -7.5f },
    { 0.23999999463558197f, 8.5f, 3.0f },
    { 0.1599999964237213f, 17.5f, 0.0f },
    { 0.20999999344348907f, 14.0f, -6.5f },
    { 0.18000000715255737f, 0.0f, 3.0f },
    { 0.15000000596046448f, 9.0f, 9.0f },
    { 0.3100000023841858f, 0.0f, -2.5f },
    { 0.18000000715255737f, 0.0f, 4.5f },
    { 0.23000000417232513f, 0.0f, 0.0f },
    { 0.1899999976158142f, 0.0f, 15.0f },
    { 0.4099999964237213f, -2.0f, 0.0f },
    { 0.5400000214576721f, -34.5f, -43.5f },
    { 0.20999999344348907f, 0.0f, -2.0f },
    { 0.20999999344348907f, 0.0f, 0.0f },
    { 0.23999999463558197f, 0.0f, 14.0f },
    { 0.27000001072883606f, 0.0f, -2.5f },
    { 0.12999999523162842f, 8.5f, 2.5f },
    { 0.12999999523162842f, 14.0f, 11.5f },
    { 0.4000000059604645f, 0.0f, 0.0f },
    { 0.2199999988079071f, 0.0f, 0.0f },
    { 0.20000000298023224f, 0.0f, 0.0f },
    { 0.4000000059604645f, 0.0f, 0.0f },
    { 0.15000000596046448f, 19.5f, -2.5f },
    { 0.1599999964237213f, 3.5f, 3.5f },
    { 0.1899999976158142f, 10.5f, -8.0f },
    { 0.4000000059604645f, 0.0f, 0.0f },
    { 0.20999999344348907f, 0.0f, -5.5f },
    { 0.23999999463558197f, 3.5f, 1.5f },
    { 0.1899999976158142f, 21.5f, 6.0f },
    { 0.28999999165534973f, 0.0f, 0.0f },
    { 0.23000000417232513f, 0.0f, 0.0f },
    { 0.2199999988079071f, -4.5f, -0.5f },
    { 0.23000000417232513f, 4.0f, 0.0f },
    { 0.1899999976158142f, 16.0f, -2.5f },
    { 0.18000000715255737f, 14.0f, -4.0f },
    { 0.15000000596046448f, 11.0f, 0.0f },
    { 0.25f, 8.5f, -6.0f },
    { 0.25f, 10.0f, -4.0f },
    { 0.3700000047683716f, 0.0f, -5.0f },
    { 0.20000000298023224f, 0.0f, 0.0f },
    { 0.14000000059604645f, 17.5f, 16.5f },
    { 0.23999999463558197f, 0.0f, 0.0f },
    { 0.23999999463558197f, 0.0f, 0.0f },
    { 0.28999999165534973f, 0.0f, 0.0f },
    { 0.1899999976158142f, 0.0f, 0.0f },
    { 0.1899999976158142f, 11.0f, 0.0f },
    { 0.1599999964237213f, 8.0f, 0.0f },
    { 0.17000000178813934f, -7.5f, -7.0f },
    { 0.25999999046325684f, 12.5f, 5.0f },
    { 0.1899999976158142f, 0.0f, 2.5f },
    { 0.2800000011920929f, 0.0f, 0.0f },
    { 0.23000000417232513f, 0.0f, 0.0f },
    { 0.28999999165534973f, 0.0f, -3.0f },
    { 0.25f, 0.0f, 0.0f },
    { 0.23000000417232513f, 0.0f, 0.0f },
    { 0.25999999046325684f, 8.5f, 2.5f },
    { 0.23000000417232513f, 22.5f, 7.5f },
    { 0.25f, 0.0f, -2.5f },
    { 0.18000000715255737f, 0.0f, 5.0f },
    { 0.20000000298023224f, 0.0f, 2.0f },
    { 0.28999999165534973f, 0.0f, 0.0f },
    { 0.1599999964237213f, 0.0f, 0.0f },
    { 0.17000000178813934f, 5.0f, 0.0f },
    { 0.25999999046325684f, 0.0f, -10.5f },
    { 0.03999999910593033f, 74.0f, -7.5f },
    { 0.20999999344348907f, 7.5f, -1.0f },
    { 0.20000000298023224f, 0.0f, -0.5f },
    { 0.2199999988079071f, 0.0f, 0.0f },
    { 0.20000000298023224f, 0.0f, 9.5f },
    { 0.17000000178813934f, 0.0f, 0.0f },
    { 0.1899999976158142f, 0.0f, 0.0f },
    { 0.1899999976158142f, 0.0f, -3.5f },
    { 0.25f, 0.0f, 9.0f },
    { 0.2199999988079071f, 1.5f, -1.0f },
    { 0.23999999463558197f, -2.5f, -4.5f },
    { 0.23000000417232513f, -4.0f, 0.0f },
    { 0.23000000417232513f, 0.0f, 0.0f },
    { 0.27000001072883606f, 0.0f, 0.0f },
    { 0.17000000178813934f, 0.0f, 4.0f },
    { 0.20999999344348907f, -11.0f, 5.5f },
    { 0.17000000178813934f, 8.0f, 0.0f },
    { 0.2199999988079071f, 0.0f, 4.5f },
    { 0.1599999964237213f, 0.0f, 12.5f },
    { 0.15000000596046448f, 4.5f, 8.0f },
    { 0.28999999165534973f, 0.0f, 0.0f },
    { 0.25f, 0.0f, 5.0f },
    { 0.25f, 6.5f, 3.0f },
    { 0.3100000023841858f, 0.0f, 0.5f },
    { 0.23999999463558197f, 18.0f, 0.0f },
    { 0.1899999976158142f, 0.0f, 0.0f },
    { 0.14000000059604645f, 0.0f, 0.0f },
    { 0.23999999463558197f, 0.0f, 0.0f },
    { 0.23999999463558197f, 12.5f, 0.0f },
    { 0.18000000715255737f, 0.0f, 0.0f },
    { 0.18000000715255737f, 9.0f, 0.0f },
    { 0.20999999344348907f, 10.0f, -2.5f },
    { 0.20999999344348907f, 0.0f, 0.0f },
    { 0.1599999964237213f, 12.0f, 5.0f },
    { 0.4000000059604645f, -1.5f, 23.0f },
    { 0.14000000059604645f, 49.0f, 28.0f },
    { 0.20000000298023224f, 22.5f, 8.5f },
    { 0.25999999046325684f, 0.0f, 0.0f },
    { 0.2800000011920929f, 0.0f, 0.0f },
    { 0.25999999046325684f, 0.0f, 4.0f },
    { 0.25f, 11.0f, 0.0f },
    { 0.23000000417232513f, 8.0f, 0.0f },
    { 0.18000000715255737f, 5.5f, 4.5f },
    { 0.2199999988079071f, -0.5f, 2.5f },
    { 0.25f, 0.0f, 0.0f },
    { 0.25999999046325684f, 0.0f, -1.5f },
    { 0.20999999344348907f, 0.0f, 3.5f },
    { 0.1599999964237213f, 32.5f, 26.5f },
    { 0.05000000074505806f, -15.5f, -133.5f },
    { 0.27000001072883606f, 5.5f, -10.0f },
    { 0.4000000059604645f, 0.0f, 0.0f },
    { 0.2199999988079071f, 7.5f, -2.5f },
    { 0.3499999940395355f, 0.0f, 0.0f },
    { 0.23999999463558197f, -9.5f, 0.0f },
    { 0.1899999976158142f, 0.0f, 2.5f },
    { 0.25999999046325684f, 0.0f, -6.5f },
    { 0.30000001192092896f, 0.0f, 3.0f },
    { 0.3499999940395355f, -45.0f, -5.0f },
    { 0.4000000059604645f, 0.0f, 0.0f },
    { 0.4000000059604645f, 0.0f, 0.0f },
    { 0.4000000059604645f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f },
};
BattleSceneStateCallback sBattleSceneStateTickSentinel = BattleScene_StateCallbackNop;
BattleSceneStateRow sBattleSceneStateRowTable[] = {
    {
        0,
        {
            BattleScene_LoadRowResourceList,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
            BattleScene_TickStartRowAnimRecord,
            BattleScene_TickQueueRowEffectList3AtAnimEnd,
            BattleScene_TickPlaySpeciesSequence33,
            BattleScene_TickQueueList3Selector2OrC,
        },
        167,
        5,
        255,
    },
    {
        1,
        {
            BattleScene_EnterRowAnim166WithCry,
            BattleScene_SetOpponentEventTrackA6,
            BattleScene_ResetStateFrameCounter,
            BattleScene_TickRow1PlayOwnerCry,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
        },
        166,
        255,
        255,
    },
    {
        2,
        {
            BattleScene_StateCallbackNop,
            BattleScene_LoadRowResourceList,
            BattleScene_StateCallbackNop,
            BattleScene_TickAssetLoadQueueRowEffectList3,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
        },
        255,
        2,
        255,
    },
    {
        3,
        {
            BattleScene_EnterRow3StartMoveAnim,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
            BattleScene_TickRow3PlayMoveEffectScript,
            BattleScene_TickRow3PostEffectCamera,
            Battle_HandleStatBoostingMoveAnimation,
            BattleScene_StateCallbackNop,
        },
        255,
        255,
        255,
    },
    {
        4,
        {
            BattleScene_EnterRow4StartHitReactionAnim,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
            BattleScene_TickPlayMoveEffectEnd,
            BattleScene_TickRow4PostEndCamera,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
        },
        255,
        255,
        255,
    },
    {
        5,
        {
            BattleScene_StateRow56EnterNop,
            BattleScene_LoadMoveResourceList,
            BattleScene_StateCallbackNop,
            BattleScene_StateRow5Slot3Nop,
            BattleScene_StateRow5Slot4Nop,
            BattleScene_StateRow5Slot5Nop,
            BattleScene_StateRow5Slot6Nop,
        },
        255,
        255,
        255,
    },
    {
        6,
        {
            BattleScene_StateRow56EnterNop,
            BattleScene_LoadMoveResourceList,
            BattleScene_StateCallbackNop,
            BattleScene_StateRow6Slot3Nop,
            BattleScene_StateRow6Slot4Nop,
            BattleScene_StateRow6Slot5Nop,
            BattleScene_StateRow6Slot6Nop,
        },
        255,
        255,
        255,
    },
    {
        7,
        {
            BattleScene_LoadRowResourceList,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
            BattleScene_TickStartRowAnimRecord,
            BattleScene_StateRow7Slot4Nop,
            BattleScene_StateRow7Slot5Nop,
            BattleScene_TickQueueList3Selector2OrC,
        },
        167,
        5,
        255,
    },
    {
        8,
        {
            BattleScene_EnterRow8StartMappedMoveAnim,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
            BattleScene_TickRow8PlayMoveEffectScriptB,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
        },
        255,
        255,
        255,
    },
    {
        9,
        {
            BattleScene_EnterRow9SetEventTrack,
            BattleScene_EnterRow9QueueEffectList6,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
        },
        255,
        255,
        255,
    },
    {
        10,
        {
            BattleScene_StateCallbackNop,
            BattleScene_LoadRowResourceList,
            BattleScene_StateCallbackNop,
            BattleScene_TickAssetLoadQueueRowEffectList3,
            BattleScene_TickRow10CleanupAndEnterState18,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
        },
        255,
        3,
        255,
    },
    {
        11,
        {
            BattleScene_EnterRow11StartHitReactionAnim,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
            BattleScene_TickPlayMoveEffectEnd,
            BattleScene_TickRow11PostEndCamera,
            BattleScene_TickRow11QueueEffectList6,
            BattleScene_StateCallbackNop,
        },
        255,
        255,
        255,
    },
    {
        12,
        {
            BattleScene_ResetStateFrameCounter,
            BattleScene_Row12Slot1CameraCleanup,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
        },
        255,
        255,
        255,
    },
    {
        13,
        {
            BattleScene_Row13PlaySequences14And21,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
        },
        255,
        255,
        255,
    },
    {
        14,
        {
            BattleScene_EnterRow11StartHitReactionAnim,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
            BattleScene_TickRow14PlayMoveEffectEnd,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
        },
        255,
        255,
        255,
    },
    {
        15,
        {
            BattleScene_EnterRow15StartAnimA80Seq30,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
        },
        255,
        255,
        255,
    },
    {
        16,
        {
            BattleScene_EnterRowAnim166WithCry,
            BattleScene_SetOpponentEventTrackA6,
            BattleScene_ResetStateFrameCounter,
            BattleScene_TickRow16PlayCryAndSpeciesSound,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
        },
        166,
        255,
        255,
    },
    {
        17,
        {
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
            BattleScene_TickStartRowAnimRecord,
            BattleScene_TickQueueList3Selector2OrCFromB10,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
        },
        177,
        255,
        255,
    },
    {
        18,
        {
            BattleScene_EnterRowAnim166WithCry,
            BattleScene_SetOpponentEventTrackA6,
            BattleScene_ResetStateFrameCounter,
            BattleScene_TickRow18PlayCryAndSpeciesSound,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
        },
        166,
        255,
        255,
    },
    {
        19,
        {
            BattleScene_EnterRow19StartMoveAnimMidFrame,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
            BattleScene_TickRow19PlayMoveEffectScript,
            BattleScene_TickRow19PostEffectCamera,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
        },
        255,
        255,
        255,
    },
    {
        20,
        {
            BattleScene_StateCallbackNop,
            BattleScene_LoadRowResourceList,
            BattleScene_StateCallbackNop,
            BattleScene_TickAssetLoadQueueRowEffectList3,
            BattleScene_TickRow20CleanupAndEnterState18,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
        },
        255,
        1,
        255,
    },
    {
        21,
        {
            BattleScene_EnterRow21StartAnimRecord0,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
            BattleScene_TickRow21PlaySpeciesSound,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
            BattleScene_StateCallbackNop,
        },
        255,
        255,
        255,
    },
};
