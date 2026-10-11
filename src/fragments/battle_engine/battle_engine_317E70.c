#include "battle_engine.h"
#include "src/geo_render.h"
#include "src/model_renderer.h"
#include "src/matrix.h"
#include "src/fragments/particle_math/particle_math.h"
#include "src/memory.h"

void BattleAnim_InitParticleSystem(void) {
    gBattleAnimEffectSlots = main_pool_alloc(sizeof(*gBattleAnimEffectSlots) * 300, 0);
    gParticlePool = main_pool_alloc(sizeof(*gParticlePool) * 300, 0);
    bzero(gBattleAnimEffectSlots, sizeof(*gBattleAnimEffectSlots) * 300);
    bzero(gParticlePool, sizeof(*gParticlePool) * 300);
    gBattleAnimEffectSlotIndex = 0;
    gParticlePoolIndex = 0;
}

BattleAnimEffectSlot* BattleAnim_AllocEffectSlot(void) {
    s32 i;
    s32 var_v0 = gBattleAnimEffectSlotIndex;
    BattleAnimEffectSlot* var_v1 = &gBattleAnimEffectSlots[var_v0];

    for (i = 0; i < 300; i++) {
        if (var_v1->unk_15 == 0) {
            break;
        }

        var_v0++;

        if (var_v0 >= 300) {
            var_v0 = 0;
            var_v1 = &gBattleAnimEffectSlots[0];
        } else {
            var_v1++;
        }
    }

    if (i >= 300) {
        var_v1 = -1;
    } else {
        var_v1->unk_15 = 1;

        gBattleAnimEffectSlotIndex = var_v0 + 1;
        if (gBattleAnimEffectSlotIndex >= 300) {
            gBattleAnimEffectSlotIndex = 0;
        }
    }

    return var_v1;
}

void BattleAnim_FreeEffectSlot(BattleAnimEffectSlot* arg0) {
    arg0->unk_0E = 0;
    arg0->unk_15 = 0;
    arg0->unk_14 = 0;
    arg0->unk_0C = arg0->unk_0E;
}

void BattleAnim_InitializeParticleChain(Particle* arg0, Vec3f arg1, Vec3s arg2, s32 arg3, s32 arg4) {
    while (arg0 != NULL) {
        ParticleMath_CopyVec3f(&arg0->unk_68, &arg1);
        ParticleMath_CopyVec3s(&arg0->unk_94, &arg2);
        arg0->unk_08 = arg3;
        arg0->unk_0C = arg4;
        arg0->unk_10 = 0;
        arg0->unk_14 = 0;
        arg0->unk_CD = 0xFF;

        arg0 = arg0->next;
    }
}

void BattleAnim_CloneParticleState(Particle* arg0, Particle* arg1, ParticleUpdateCallback arg2, ParticleDescriptor* arg3,
                   s32 arg4) {
    arg0->unk_08 = arg2;
    arg0->unk_0C = arg3;
    arg0->unk_10 = arg1->unk_10;
    arg0->unk_CF = arg1->unk_CF;
    arg0->unk_CA = arg1->unk_CA;
    arg0->unk_CC = 0x1C;
    arg0->unk_CD = 0xFF;
    arg0->unk_CE = arg1->unk_CE;
    arg0->unk_CB = arg1->unk_CB;
    arg0->unk_74 = arg1->unk_74;

    Particle_FieldAC_SetS16_0BED8(arg0, arg4);

    ParticleMath_CopyVec3f(&arg0->unk_38, &arg1->unk_38);
    ParticleMath_CopyVec3f(&arg0->unk_50, &arg1->unk_50);
    ParticleMath_CopyVec3f(&arg0->unk_68, &arg1->unk_68);
    ParticleMath_CopyVec3f(&arg0->unk_7C, &arg1->unk_7C);
    ParticleMath_CopyVec3s(&arg0->unk_94, &arg1->unk_94);
    ParticleMath_CopyVec3s(&arg0->unk_9A, &arg1->unk_9A);

    if (arg1->unk_CA == 4) {
        arg0->unk_CA = 0;
    }
}

void BattleAnim_EmitParticleBurst(Particle* arg0, ParticleUpdateCallback arg1, ParticleDescriptor* arg2, s16 arg3) {
    s16 i;
    Particle* temp_v0;

    for (i = 0; i < arg3; i++) {
        temp_v0 = Particle_New();
        if ((u32)temp_v0 == -1) {
            break;
        }
        BattleAnim_CloneParticleState(temp_v0, arg0, arg1, arg2, i);
    }
}

void BattleAnim_EmitParticleBurstWithMetadata(Particle* arg0, ParticleUpdateCallback arg1, ParticleDescriptor* arg2, s16 arg3, s16 arg4,
                   s16 arg5) {
    s16 i;
    Particle* temp_v0;

    for (i = 0; i < arg3; i++) {
        temp_v0 = Particle_New();
        if ((u32)temp_v0 == -1) {
            break;
        }
        BattleAnim_CloneParticleState(temp_v0, arg0, arg1, arg2, i);
        temp_v0->unk_CE = arg5;
        temp_v0->unk_CF = arg4;
    }
}

Particle* BattleAnim_CreateProceduralParticle(s16 arg0, s16 arg1, s32 arg2, f32 arg3) {
    Particle* temp_v0 = Particle_New();

    if ((u32)temp_v0 != -1) {
        Vec3f_SetComponentsDuplicate(&temp_v0->unk_38, arg0, arg1, 0.0f);
        Particle_UpdateWorldTransform(temp_v0);
        Vec3s_SetComponents(&temp_v0->unk_94, arg2, arg2, arg2);
        temp_v0->unk_1C = arg3;
        Particle_SetFlags(temp_v0, 0x108);
    }
    return temp_v0;
}

void BattleAnim_ReleaseParticleModel(Particle* arg0) {
    if (arg0->unk_14 != NULL) {
        if (Particle_HasFlags(arg0, 0x400) != 0) {
            BattleAnim_FreeParticleDisplayContext(arg0->unk_14);
        } else {
            BattleAnim_FreeOwnerDisplayContext(arg0->unk_14);
        }
    }
}

void BattleAnim_DestroyParticle(Particle* arg0) {
    BattleAnim_ReleaseParticleModel(arg0);
    arg0->unk_18 = 0;
    Particle_DisableAndDetach(arg0);
    Particle_Free(arg0);
}

void BattleAnim_InitializeParticleAnchor(Particle* arg0) {
    Vec3f sp3C;
    Vec3f sp30;
    Vec3s sp28;

    switch (arg0->unk_CC) {
        case 0:
            BattleScene_GetParticipantModelPosition(arg0->unk_10, &arg0->unk_68);
            break;

        case 1:
            BattleAnim_GetOwnerDefaultAnchorPosition(arg0->unk_10, &arg0->unk_68);
            break;

        case 27:
            BattleAnim_GetOwnerDefaultAnchorPosition(arg0->unk_10, &arg0->unk_68);
            arg0->unk_68.y = 0.0f;
            break;

        case 9:
            BattleAnim_GetOwnerBonePosition(arg0->unk_10, 0x64, &arg0->unk_68);
            break;

        case 10:
            BattleAnim_GetOwnerBonePosition(arg0->unk_10, 0x64, &arg0->unk_68);
            arg0->unk_68.y = 0.0f;
            break;

        case 11:
            BattleAnim_GetOwnerBonePosition(arg0->unk_10, 0x64, &arg0->unk_68);
            BattleScene_GetParticipantModelRotation(arg0->unk_10, &sp28);
            BattleScene_GetParticipantModelBoundsScaled(arg0->unk_10, &sp30);
            ParticleMath_MakeXZVectorFromAngle(&sp3C, sp30.x * 25.0f, sp28.y);
            ParticleMath_AddVec3f(&arg0->unk_68, &sp3C);
            break;

        case 12:
            BattleAnim_GetOwnerBonePosition(arg0->unk_10, 0x64, &arg0->unk_68);
            BattleScene_GetParticipantModelRotation(arg0->unk_10, &sp28);
            BattleScene_GetParticipantModelBoundsScaled(arg0->unk_10, &sp30);
            ParticleMath_MakeXZVectorFromAngle(&sp3C, sp30.x * 25.0f, sp28.y + 0x8000);
            ParticleMath_AddVec3f(&arg0->unk_68, &sp3C);
            break;

        case 13:
            BattleAnim_GetOwnerBonePosition(arg0->unk_10, 0x64, &arg0->unk_68);
            BattleScene_GetParticipantModelBoundsScaled(arg0->unk_10, &sp30);
            arg0->unk_68.y += sp30.y * 25.0f;
            break;

        case 14:
            BattleAnim_GetOwnerBonePosition(arg0->unk_10, 0x64, &arg0->unk_68);
            BattleScene_GetParticipantModelBoundsScaled(arg0->unk_10, &sp30);
            arg0->unk_68.y -= sp30.y * 25.0f;
            if (arg0->unk_68.y <= 0.0f) {
                arg0->unk_68.y = 0.0f;
            }
            break;

        case 15:
            BattleAnim_GetOwnerBonePosition(arg0->unk_10, 0x64, &arg0->unk_68);
            BattleScene_GetParticipantModelRotation(arg0->unk_10, &sp28);
            BattleScene_GetParticipantModelBoundsScaled(arg0->unk_10, &sp30);
            ParticleMath_MakeXZVectorFromAngle(&sp3C, sp30.x * 25.0f, sp28.y);
            ParticleMath_AddVec3f(&arg0->unk_68, &sp3C);
            arg0->unk_68.y = 0.0f;
            break;

        case 17:
            BattleAnim_GetOwnerBonePosition(arg0->unk_10, arg0->unk_CD, &arg0->unk_68);
            break;

        case 19:
            BattleAnim_GetOwnerBonePosition(arg0->unk_10, arg0->unk_CD, &arg0->unk_68);
            BattleScene_GetParticipantModelRotation(arg0->unk_10, &sp28);
            BattleScene_GetParticipantModelBoundsScaled(arg0->unk_10, &sp30);
            ParticleMath_MakeXZVectorFromAngle(&sp3C, sp30.x * 25.0f, sp28.y);
            ParticleMath_AddVec3f(&arg0->unk_68, &sp3C);
            break;

        case 30:
            BattleScene_GetParticipantAuxiliaryModelPosition(arg0->unk_10, &arg0->unk_68);
            break;
    }
}

void BattleAnim_UpdateParticleAnchor(Particle* arg0) {
    Vec3f sp3C;
    Vec3f sp30;
    Vec3s sp28;

    switch (arg0->unk_CC) {
        case 2:
            BattleAnim_GetOwnerBonePosition(arg0->unk_10, 0x64, &arg0->unk_68);
            break;

        case 3:
            BattleAnim_GetOwnerBonePosition(arg0->unk_10, 0x64, &arg0->unk_68);
            arg0->unk_68.y = 0.0f;
            break;

        case 4:
            BattleAnim_GetOwnerBonePosition(arg0->unk_10, 0x64, &arg0->unk_68);
            BattleScene_GetParticipantModelRotation(arg0->unk_10, &sp28);
            BattleScene_GetParticipantModelBoundsScaled(arg0->unk_10, &sp30);
            ParticleMath_MakeXZVectorFromAngle(&sp3C, sp30.x * 25.0f, sp28.y);
            ParticleMath_AddVec3f(&arg0->unk_68, &sp3C);
            break;

        case 5:
            BattleAnim_GetOwnerBonePosition(arg0->unk_10, 0x64, &arg0->unk_68);
            BattleScene_GetParticipantModelRotation(arg0->unk_10, &sp28);
            BattleScene_GetParticipantModelBoundsScaled(arg0->unk_10, &sp30);
            ParticleMath_MakeXZVectorFromAngle(&sp3C, sp30.x * 25.0f, sp28.y + 0x8000);
            ParticleMath_AddVec3f(&arg0->unk_68, &sp3C);
            break;

        case 6:
            BattleAnim_GetOwnerBonePosition(arg0->unk_10, 0x64, &arg0->unk_68);
            BattleScene_GetParticipantModelBoundsScaled(arg0->unk_10, &sp30);
            arg0->unk_68.y += sp30.y * 25.0f;
            break;

        case 7:
            BattleAnim_GetOwnerBonePosition(arg0->unk_10, 0x64, &arg0->unk_68);
            BattleScene_GetParticipantModelBoundsScaled(arg0->unk_10, &sp30);
            arg0->unk_68.y -= sp30.y * 25.0f;
            if (arg0->unk_68.y <= 0.0f) {
                arg0->unk_68.y = 0.0f;
            }
            break;

        case 8:
            BattleAnim_GetOwnerBonePosition(arg0->unk_10, 0x64, &arg0->unk_68);
            BattleScene_GetParticipantModelRotation(arg0->unk_10, &sp28);
            BattleScene_GetParticipantModelBoundsScaled(arg0->unk_10, &sp30);
            ParticleMath_MakeXZVectorFromAngle(&sp3C, sp30.x * 25.0f, sp28.y);
            ParticleMath_AddVec3f(&arg0->unk_68, &sp3C);
            arg0->unk_68.y = 0.0f;
            break;

        case 16:
            BattleAnim_GetOwnerBonePosition(arg0->unk_10, arg0->unk_CD, &arg0->unk_68);
            break;

        case 18:
            BattleAnim_GetOwnerBonePosition(arg0->unk_10, arg0->unk_CD, &arg0->unk_68);
            break;

        case 29:
            BattleScene_GetParticipantAuxiliaryModelPosition(arg0->unk_10, &arg0->unk_68);
            break;
    }
}

void BattleAnim_UpdateParticleCameraScale(Particle* arg0) {
    if ((arg0->unk_10 == NULL) || (Particle_HasFlags(arg0, 0x108) != 0)) {
        gParticleRenderContext.unk_00.x = 1.0f;
        gParticleRenderContext.unk_00.y = 1.0f;
        gParticleRenderContext.unk_00.z = 1.0f;
    } else if (Particle_LacksFlags(arg0, 0x800) != 0) {
        gParticleRenderContext.unk_00.x = BattleAnim_GetOwnerModelScale(arg0->unk_10);
        gParticleRenderContext.unk_00.y = BattleAnim_GetOwnerModelScale(arg0->unk_10);
        gParticleRenderContext.unk_00.z = BattleAnim_GetOwnerModelScale(arg0->unk_10);
    }
}

void BattleAnim_UpdateOrDestroyParticle(Particle* arg0) {
    if (Particle_IsInactive(arg0) != 0) {
        BattleAnim_DestroyParticle(arg0);
    } else {
        Particle_UpdateWorldTransform(arg0);
    }
}

void BattleAnim_UpdateParticlePool(void) {
    s32 i;
    Particle* var_s0 = gParticlePool;

    for (i = 0; i < 300; i++, var_s0++) {
        if (var_s0->unk_D0 != 0) {
            BattleAnim_UpdateParticleAnchor(var_s0);
            BattleAnim_UpdateParticleCameraScale(var_s0);
            var_s0->unk_08(var_s0);
            BattleAnim_UpdateOrDestroyParticle(var_s0);
        }
    }
}

void BattleAnim_InitializeParticleFromEffect(Particle* arg0, Battler* arg1, BattleAnimEffectSlot* arg2, s16 arg3) {
    if ((u32)arg0 == -1) {
        return;
    }

    if (1) {}
    if (1) {}
    if (1) {}
    if (1) {}
    if (1) {}
    if (1) {}

    while (arg0 != NULL) {
        arg0->unk_10 = arg1;
        arg0->unk_AC = arg3++;
        arg0->unk_08 = arg2->unk_00;
        arg0->unk_0C = arg2->unk_04;
        arg0->unk_CD = arg2->unk_19;
        arg0->unk_CE = arg2->unk_1A;
        arg0->unk_AA = arg2->unk_12;
        arg0->unk_CF = arg2->unk_1B;
        arg0->unk_CA = arg2->unk_17;
        arg0->unk_CC = arg2->unk_16;
        arg0->unk_CB = arg2->unk_18;
        arg0->unk_A6 = arg2->unk_10;

        if (arg1 != NULL) {
            BattleAnim_InitializeParticleAnchor(arg0);
            BattleScene_GetParticipantModelRotation(arg0->unk_10, &arg0->unk_94);
        }

        if ((arg2->unk_16 & 0xFFFFu) == 0x12) {
            arg0->unk_A6 = arg2->unk_10 * arg3;
        }

        arg0 = arg0->next;
    }
}

void BattleAnim_SpawnEffectParticles(BattleAnimEffectSlot* arg0, s32 arg1) {
    s16 i;
    s16 var_s2;
    ParticleDescriptor* temp_a2 = arg0->unk_04;
    ParticleDescriptorChild* temp_a3 = arg0->unk_04->unk_04.a;
    Battler* tmp08 = arg0->unk_08;
    s16 tmp12 = arg0->unk_12;

    switch (arg1) {
        case 0:
            var_s2 = tmp12;
            break;

        case 1:
            var_s2 = arg0->unk_10 / tmp12;
            arg0->unk_10 = tmp12;
            break;
    }

    if ((temp_a2->unk_00 == 1) && (temp_a3->unk_00 == 1)) {
        BattleAnim_InitializeParticleFromEffect(Particle_AllocChain(var_s2), tmp08, arg0, 0);
        return;
    }

    for (i = 0; i < var_s2; i++) {
        BattleAnim_InitializeParticleFromEffect(Particle_New(), tmp08, arg0, i);
    }
}

void BattleAnim_SpawnStandardParticles(BattleAnimEffectSlot* arg0) {
    BattleAnim_SpawnEffectParticles(arg0, 0);
}

void BattleAnim_SpawnBatchedParticles(BattleAnimEffectSlot* arg0) {
    BattleAnim_SpawnEffectParticles(arg0, 1);
}

void BattleAnim_SpawnSingleParticle(BattleAnimEffectSlot* arg0) {
    UNUSED s32 pad;
    Battler* sp18 = arg0->unk_08;

    BattleAnim_InitializeParticleFromEffect(Particle_New(), sp18, arg0, 0);
}

void BattleAnim_DispatchParticleEmission(BattleAnimEffectSlot* arg0) {
    switch (arg0->unk_16) {
        case 18:
            BattleAnim_SpawnBatchedParticles(arg0);
            break;

        case 22:
            BattleAnim_InitializeParticleFromEffect(BattleAnim_CreateProceduralParticle(0xA0, 0x78, 0, 1.0f), 0, arg0, 0);
            break;

        case 24:
            BattleAnim_InitializeParticleFromEffect(BattleAnim_CreateProceduralParticle(0, 0, 0, 1.0f), 0, arg0, 0);
            break;

        case 23:
            BattleAnim_SetEffectStateFlag(arg0->unk_19);
            break;

        case 25:
            BattleAnim_QueueEffectList9(arg0->unk_19);
            break;

        case 26:
            BattleAnim_SpawnSingleParticle(arg0);
            break;

        default:
            BattleAnim_SpawnStandardParticles(arg0);
            break;
    }
}

void BattleAnim_TickEffectSlots(void) {
    s32 i;
    BattleAnimEffectSlot* var_s0 = gBattleAnimEffectSlots;

    for (i = 0; i < 300; i++, var_s0++) {
        if (var_s0->unk_15 != 0) {
            var_s0->unk_0E--;
            if (var_s0->unk_0E <= 0) {
                if (var_s0->unk_14 >= 0) {
                    BattleAnim_DispatchParticleEmission(var_s0);
                    if (var_s0->unk_14 != 0x7F) {
                        var_s0->unk_14--;
                    }

                    if (var_s0->unk_14 <= 0) {
                        BattleAnim_FreeEffectSlot(var_s0);
                    } else {
                        var_s0->unk_0E = var_s0->unk_0C;
                    }
                } else if (var_s0->unk_14 == -1) {
                    var_s0->unk_0E = var_s0->unk_0C;
                    BattleAnim_DispatchParticleEmission(var_s0);
                }
            }
        }
    }
}

void BattleAnim_UpdateEffects(void) {
    BattleAnim_TickEffectSlots();
    BattleAnim_UpdateParticlePool();
}

void BattleAnim_CleanupEffectsRetainingCategories47(void) {
    s32 i;
    BattleAnimEffectSlot* var_s0 = gBattleAnimEffectSlots;
    Particle* var_s2 = gParticlePool;

    BattleAnim_ResetSpawnDelay();

    for (i = 0; i < 300; i++, var_s0++) {
        if (var_s0->unk_15 != 0) {
            if ((var_s0->unk_17 != 4) && (var_s0->unk_17 != 7)) {
                BattleAnim_FreeEffectSlot(var_s0);
            }
        }
    }

    for (i = 0; i < 300; i++, var_s2++) {
        if (var_s2->unk_D0 != 0) {
            if ((var_s2->unk_CA != 4) && (var_s2->unk_CA != 7)) {
                BattleAnim_DestroyParticle(var_s2);
            }
        }
    }
}

void BattleAnim_CleanupEffectsRetainingCategory4(void) {
    s32 i;
    BattleAnimEffectSlot* var_s0 = gBattleAnimEffectSlots;
    Particle* var_s2 = gParticlePool;

    for (i = 0; i < 300; i++, var_s0++) {
        if ((var_s0->unk_15 != 0) && (var_s0->unk_17 != 4)) {
            BattleAnim_FreeEffectSlot(var_s0);
        }
    }

    for (i = 0; i < 300; i++, var_s2++) {
        if ((var_s2->unk_D0 != 0) && (var_s2->unk_CA != 4)) {
            BattleAnim_DestroyParticle(var_s2);
        }
    }

    Model_SetMaterialColor(&D_84390010[0]->unk_000, 0xFF, 0xFF, 0xFF, 0);
    Model_SetMaterialColor(&D_84390010[1]->unk_000, 0xFF, 0xFF, 0xFF, 0);
    Model_SetMaterialAlpha(&D_84390010[0]->unk_000, 0xFF);
    Model_SetMaterialAlpha(&D_84390010[1]->unk_000, 0xFF);

    D_8439037E = 0xFF;
    D_8439037C = D_8439037E;
    D_8439037A = D_8439037C;
}

s32 BattleAnim_GetMoveFailedFlag(void) {
    return D_84390340;
}

void BattleAnim_UpdateMoveFailedFlag(void) {
    if (gBattleMoveFailed != 0) {
        D_84390340 = 1;
    } else {
        D_84390340 = 0;
    }
}

void BattleAnim_ClearEffectCallbacks(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if (gBattleAnimEffectUpdateFuncs[i] != NULL) {
            gBattleAnimEffectUpdateFuncs[i] = NULL;
            gBattleAnimEffectDrawFuncs[i] = NULL;
        }
    }

    D_84390340 = 0;
}

s32 BattleAnim_IsEffectSpawningEnabled(void) {
    s32 var_v1 = 0;

    if (D_843902F8 == 0) {
        var_v1 = 1;
    }
    return var_v1;
}

void BattleAnim_DisableEffectSpawning(void) {
    D_843902F8 = 1;
}

void BattleAnim_EnableEffectSpawning(void) {
    D_843902F8 = 0;
}

void BattleAnim_DisableEffectSpawningAlias(void) {
    BattleAnim_DisableEffectSpawning();
}

void BattleAnim_CleanupEffects(s32 arg0) {
    BattleAnim_ResetSpawnDelay();
    switch (arg0) {
        case 1:
            BattleAnim_CleanupEffectsRetainingCategories47();
            if (BattleAnim_IsEffectSpawningEnabled() != 0) {
                BattleAnim_ClearEffectCallbacks();
            }
            break;

        case 2:
            BattleAnim_CleanupEffectsRetainingCategory4();
            BattleAnim_ClearEffectCallbacks();
            BattleAnim_EnableEffectSpawning();
            BattleAnim_ReinitAuxiliaryEffects();
            break;
    }
}

void BattleAnim_StopParticlesForOwnerCategory(u8 arg0, Battler* arg1) {
    s32 i;
    Particle* var_s0 = gParticlePool;

    for (i = 0; i < 300; i++, var_s0++) {
        if ((var_s0->unk_D0 != 0) && (var_s0->unk_CA == 4) && (var_s0->unk_CB == arg0) && (arg1 == var_s0->unk_10)) {
            Particle_SetFlags(var_s0, 0x1000);
            Particle_AdvanceLifecycle(var_s0);
        }
    }
}

void BattleAnim_ResetSpawnDelay(void) {
    gBattleAnimSpawnDelay = 0;
}

void BattleAnim_SetSpawnDelay(s32 arg0) {
    gBattleAnimSpawnDelay = arg0;
}

void BattleAnim_AddSpawnDelay(s32 arg0) {
    gBattleAnimSpawnDelay += arg0;
}

void BattleAnim_ResetSpawnDelayAlias(void) {
    BattleAnim_ResetSpawnDelay();
}

BattleAnimEffectSlot* BattleAnim_CreateEffectSlot(s32 arg0, s32 arg1, s8 arg2, func_unk_D_8140E724 arg3, ParticleDescriptor* arg4,
                              Battler* arg5, s16 arg6, s16 arg7, u8 arg8, u8 arg9, u8 argA, u8 argB) {
    BattleAnimEffectSlot* sp1C = BattleAnim_AllocEffectSlot();

    if ((u32)sp1C != -1) {
        sp1C->unk_0E = arg0 + gBattleAnimSpawnDelay;
        sp1C->unk_0C = arg1;
        sp1C->unk_14 = arg2;
        sp1C->unk_00 = arg3;
        sp1C->unk_04 = arg4;
        sp1C->unk_08 = arg5;
        sp1C->unk_16 = arg8;
        sp1C->unk_10 = arg6;
        sp1C->unk_12 = arg7;
        sp1C->unk_19 = arg9;
        sp1C->unk_1A = argB;
        sp1C->unk_1B = argA;
        sp1C->unk_17 = BattleAnim_GetCurrentEffectList();
        sp1C->unk_18 = BattleAnim_GetQueuedResourceListId();
    }
    return sp1C;
}

BattleAnimEffectSlot* BattleAnim_CreateEffectSlotForCurrentOwner(s32 arg0, func_unk_D_8140E724 arg1, ParticleDescriptor* arg2, s16 arg3, s16 arg4, u8 arg5,
                              u8 arg6, u8 arg7, u8 arg8) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, arg1, arg2, gBattleAnimCurrentOwner, arg3, arg4, arg5, arg6, arg7, arg8);
}

BattleAnimEffectSlot* BattleAnim_CreateRepeatingEffectSlotForCurrentOwner(s32 arg0, s32 arg1, s8 arg2, func_unk_D_8140E724 arg3, ParticleDescriptor* arg4, s16 arg5,
                              s16 arg6, u8 arg7, u8 arg8, u8 arg9, u8 argA) {
    return BattleAnim_CreateEffectSlot(arg0, arg1, arg2, arg3, arg4, gBattleAnimCurrentOwner, arg5, arg6, arg7, arg8, arg9, argA);
}

BattleAnimEffectSlot* BattleAnim_SpawnGlobalTintColorFadeDetach(s32 arg0, s16 arg1, u8 arg2) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackGlobalTintColorFadeDetach, &gDefaultParticleDescriptor, NULL, 0, arg1, 0x16, 0, arg2, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaFadeInHoldOut(s32 arg0, s16 arg1, s16 arg2, u8 arg3, u8 arg4) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackDescriptor25AlphaFadeInHoldOut, &gBattleAnimParticleDescriptors[37], NULL, arg1, arg2, 0x16, arg4, arg3, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaHoldFadeOutFullAlpha(s32 arg0, s16 arg1, s16 arg2, u8 arg3) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackDescriptor25AlphaHoldFadeOut, &gBattleAnimParticleDescriptors[37], NULL, arg1, arg2, 0x16, 0xFF, arg3, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaHoldFadeOut(s32 arg0, s16 arg1, s16 arg2, u8 arg3, u8 arg4) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackDescriptor25AlphaHoldFadeOut, &gBattleAnimParticleDescriptors[37], NULL, arg1, arg2, 0x16, arg4, arg3, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaHoldFadeOutRepeating(s32 arg0, s32 arg1, s8 arg2, s16 arg3, s16 arg4, u8 arg5, u8 arg6) {
    return BattleAnim_CreateEffectSlot(arg0, arg1, arg2, BattleAnim_CallbackDescriptor25AlphaHoldFadeOut, &gBattleAnimParticleDescriptors[37], NULL, arg3, arg4, 0x16, arg6, arg5, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaFadeInHoldFullAlpha(s32 arg0, s16 arg1, s16 arg2, u8 arg3) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackDescriptor25AlphaFadeInHold, &gBattleAnimParticleDescriptors[37], NULL, arg1, arg2, 0x16, 0xFF, arg3, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaFadeInHold(s32 arg0, s16 arg1, s16 arg2, u8 arg3, u8 arg4) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackDescriptor25AlphaFadeInHold, &gBattleAnimParticleDescriptors[37], NULL, arg1, arg2, 0x16, arg4, arg3, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaFadeInHoldRepeating(s32 arg0, s32 arg1, s8 arg2, s16 arg3, s16 arg4, u8 arg5, u8 arg6) {
    return BattleAnim_CreateEffectSlot(arg0, arg1, arg2, BattleAnim_CallbackDescriptor25AlphaFadeInHold, &gBattleAnimParticleDescriptors[37], NULL, arg3, arg4, 0x16, arg6, arg5, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaHoldDetachFullAlpha(s32 arg0, s16 arg1, u8 arg2) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackDescriptor25AlphaHoldDetach, &gBattleAnimParticleDescriptors[37], NULL, arg1, 0, 0x16, 0xFF, arg2, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaHoldDetach(s32 arg0, s16 arg1, u8 arg2, u8 arg3) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackDescriptor25AlphaHoldDetach, &gBattleAnimParticleDescriptors[37], NULL, arg1, 0, 0x16, arg3, arg2, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25AlphaHoldDetachRepeating(s32 arg0, s32 arg1, s8 arg2, s16 arg3, u8 arg4, u8 arg5) {
    return BattleAnim_CreateEffectSlot(arg0, arg1, arg2, BattleAnim_CallbackDescriptor25AlphaHoldDetach, &gBattleAnimParticleDescriptors[37], NULL, arg3, 0, 0x16, arg5, arg4, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25PaletteFadeOut(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackDescriptor25PaletteFadeOut, &gBattleAnimParticleDescriptors[37], NULL, arg1, arg2, 0x16, arg4, arg3, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnDescriptor25PaletteFadeIn(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackDescriptor25PaletteFadeIn, &gBattleAnimParticleDescriptors[37], NULL, arg1, arg2, 0x16, arg4, arg3, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintRampDetach(s32 arg0, u8 arg1, s16 arg2, s16 arg3, s16 arg4) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackOwnerModelTintRampDetach, &gDefaultParticleDescriptor, gBattleAnimCurrentOwner, arg2, arg4, 0x1A, arg3, arg1, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintPulseDetach(s32 arg0, s16 arg1, u8 arg2, s16 arg3, s16 arg4, s16 arg5) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackOwnerModelTintPulseDetach, &gDefaultParticleDescriptor, gBattleAnimCurrentOwner, arg1, arg5, 0x1A, arg4, arg2, arg3);
}

BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintHoldFadeDetach(s32 arg0, s16 arg1, u8 arg2, s16 arg3, s16 arg4) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackOwnerModelTintHoldFadeDetach, &gDefaultParticleDescriptor, gBattleAnimCurrentOwner, arg1, arg4, 0x1A, 0, arg2, arg3);
}

BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintPaletteApproachInactive(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackOwnerModelTintPaletteApproachInactive, &gDefaultParticleDescriptor, gBattleAnimCurrentOwner, arg4, arg3, 0x1A, arg2, arg1, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintPaletteApproachInactiveAlt(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackOwnerModelTintPaletteApproachInactive, &gDefaultParticleDescriptor, gBattleAnimCurrentOwner, arg4, arg3, 0x1A, arg2, arg1, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintPaletteCycle(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackOwnerModelTintPaletteCycle, &gDefaultParticleDescriptor, gBattleAnimCurrentOwner, arg4, arg3, 0x1A, arg2, arg1, arg5);
}

BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintPaletteCycleVariant(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackOwnerModelTintPaletteCycle, &gDefaultParticleDescriptor, gBattleAnimCurrentOwner, arg4, arg3, 0x1A, arg2, arg1, arg5);
}

BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintPaletteFade(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackOwnerModelTintPaletteFade, &gDefaultParticleDescriptor, gBattleAnimCurrentOwner, arg4, arg3, 0x1A, arg2, arg1, arg5);
}

BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintRandomPaletteCycle(s32 arg0, s16 arg1, u8 arg2) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackOwnerModelTintRandomPaletteCycle, &gDefaultParticleDescriptor, gBattleAnimCurrentOwner, 0, arg1, 0x1A, arg2, 0, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelTintPaletteRotateFadeDetach(s32 arg0, s16 arg1, s16 arg2, u8 arg3) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackOwnerModelTintPaletteRotateFadeDetach, &gDefaultParticleDescriptor, gBattleAnimCurrentOwner, arg1, arg2, 0x1A, arg3, 0, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelAlphaFade(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackOwnerModelAlphaFade, &gDefaultParticleDescriptor, gBattleAnimCurrentOwner, arg1, arg3, 0x1A, arg2, 0, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelAlphaFadeFullPreset(s32 arg0) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackOwnerModelAlphaFade, &gDefaultParticleDescriptor, gBattleAnimCurrentOwner, 0xFF, 0xFF, 0x1A, 0xFF, 0, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnOwnerModelAlphaFadeZeroStartPreset(s32 arg0) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, BattleAnim_CallbackOwnerModelAlphaFade, &gDefaultParticleDescriptor, gBattleAnimCurrentOwner, 0, 0xFF, 0x1A, 0, 0, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnCategory17MarkerSlot(s32 arg0, u8 arg1) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, NULL, NULL, 0, 0, 0, 0x17, arg1, 0, 0);
}

BattleAnimEffectSlot* BattleAnim_SpawnCategory19MarkerSlot(s32 arg0, u8 arg1) {
    return BattleAnim_CreateEffectSlot(arg0, 0, 1, NULL, NULL, gBattleAnimCurrentOwner, 0, 0, 0x19, arg1, 0, 0);
}

void BattleAnim_EffectStartNop(void) {
}

void BattleAnim_EffectEndNop(void) {
}

void BattleAnim_SetEffectStateFlag(s32 arg0) {
    D_843902F4 = arg0;
}

void BattleAnim_ClearEffectStateFlag(void) {
    D_843902F4 = 0;
}

s32 BattleAnim_GetEffectStateFlag(void) {
    return D_843902F4;
}

s32 BattleAnim_IsCurrentOwnerSpecies(s32 arg0) {
    s32 sp1C = 0;

    if (BattleAnim_GetOwnerSpecies(gBattleAnimCurrentOwner) == arg0) {
        sp1C = 1;
    }
    return sp1C;
}

s32 BattleAnim_GetSecondaryOwnerSpecies(void) {
    return BattleAnim_GetOwnerSpecies(gBattleAnimSecondaryOwner);
}

s32 BattleAnim_GetTertiaryOwnerSpecies(void) {
    return BattleAnim_GetOwnerSpecies(gBattleAnimTertiaryOwner);
}

void BattleAnim_GetOwnerBonePosition(Battler* arg0, s16 arg1, Vec3f* arg2) {
    s32 sp24 = 0;

    if (arg0 != NULL) {
        if (arg1 == 0x64) {
            if (GeoRender_FindAnchorPosition(&arg0->unk_000, 0xA, arg2) != NULL) {
                sp24 = 1;
            } else if (GeoRender_FindAnchorPosition(&arg0->unk_000, 0x64, arg2) != NULL) {
                sp24 = 2;
            }
        } else {
            if (GeoRender_FindAnchorPosition(&arg0->unk_000, arg1, arg2) == NULL) {
                if (GeoRender_FindAnchorPosition(&arg0->unk_000, 0x64, arg2) != NULL) {
                    sp24 = 3;
                }
            } else {
                sp24 = 4;
            }
        }
    }

    if (sp24 == 0) {
        arg2->x = 0.0f;
        arg2->y = 0.0f;
        arg2->z = 0.0f;
    }
}

void BattleAnim_GetCurrentOwnerBonePosition(Vec3f* arg0) {
    BattleAnim_GetOwnerBonePosition(gBattleAnimCurrentOwner, 0x64, arg0);
}

void BattleAnim_GetSecondaryOwnerBonePosition(Vec3f* arg0) {
    BattleAnim_GetOwnerBonePosition(gBattleAnimSecondaryOwner, 0x64, arg0);
}

void BattleAnim_GetTertiaryOwnerBonePosition(Vec3f* arg0) {
    BattleAnim_GetOwnerBonePosition(gBattleAnimTertiaryOwner, 0x64, arg0);
}

void BattleAnim_GetSecondaryOwnerAnchorPosition(Vec3f* arg0) {
    if (gBattleAnimDefaultAnchor == 0xFF) {
        BattleAnim_GetOwnerDefaultAnchorPosition(gBattleAnimSecondaryOwner, arg0);
    } else {
        BattleAnim_GetOwnerBonePosition(gBattleAnimSecondaryOwner, gBattleAnimCurrentAnchor, arg0);
    }
}

void BattleAnim_GetTertiaryOwnerBone9Position(Vec3f* arg0) {
    BattleAnim_GetOwnerBonePosition(gBattleAnimTertiaryOwner, 9, arg0);
}

void BattleAnim_GetOwnerModelBoundsScaled(Battler* arg0, Vec3f* arg1) {
    BattleScene_GetParticipantModelBoundsScaled(arg0, arg1);
}

f32 BattleAnim_GetSpeciesBaseScale(Battler* arg0) {
    f32 ret = D_80075E40[arg0->unk_000.objectType] * 0.01f;

    return ret;
}

f32 BattleAnim_GetOwnerModelScale(Battler* arg0) {
    return BattleAnim_GetSpeciesBaseScale(arg0);
}

void BattleAnim_GetOwnerSpeciesBaseScaleAlias(Battler* arg0) {
    BattleAnim_GetSpeciesBaseScale(arg0);
}

f32 BattleAnim_GetSecondaryOwnerModelScale(void) {
    return BattleAnim_GetOwnerModelScale(gBattleAnimSecondaryOwner);
}

void BattleAnim_GetSecondaryOwnerSpeciesBaseScale(void) {
    BattleAnim_GetOwnerSpeciesBaseScaleAlias(gBattleAnimSecondaryOwner);
}

f32 BattleAnim_GetTertiaryOwnerModelScale(void) {
    return BattleAnim_GetOwnerModelScale(gBattleAnimTertiaryOwner);
}

void BattleAnim_GetTertiaryOwnerSpeciesBaseScale(void) {
    BattleAnim_GetOwnerSpeciesBaseScaleAlias(gBattleAnimTertiaryOwner);
}

unk_D_86002F34_00C* BattleAnim_GetCameraContext(void) {
    return gParticleRenderContext.unk_0C;
}

Particle* BattleAnim_SpawnSecondaryOwnerParticle(Vec3f arg0, u8 arg1) {
    Particle* sp1C = Particle_New();

    if ((u32)sp1C != -1) {
        ParticleMath_CopyVec3f(&sp1C->unk_68, &arg0);
        BattleAnim_ConfigureSecondaryOwnerParticleVariant(sp1C, arg1);
        sp1C->unk_10 = gBattleAnimSecondaryOwner;
        sp1C->unk_14 = NULL;
        sp1C->unk_CD = 0xFF;
        sp1C->unk_CC = 0x15;
        sp1C->unk_CA = 0;
    }
    return sp1C;
}

void BattleAnim_SetParticlePosition(Particle* arg0, Vec3f arg1) {
    if ((u32)arg0 != -1) {
        arg0->unk_68.x = arg1.x;
        arg0->unk_68.y = arg1.y;
        arg0->unk_68.z = arg1.z;
    }
}

void BattleAnim_MarkParticleInactive(Particle* arg0) {
    Particle_MarkInactive(arg0);
}

s16 BattleAnim_GetParticleAngleYToTertiaryOwner(Particle* arg0) {
    Vec3f sp24;
    s16 ret;

    BattleAnim_GetOwnerDefaultAnchorPosition(gBattleAnimTertiaryOwner, &sp24);
    ret = ParticleMath_AngleYBetweenPoints(arg0->unk_68, sp24) + arg0->unk_94.y;
    return ret;
}

void BattleAnim_SetGlobalTintFromParticle(Particle* arg0) {
    D_8439037A = arg0->prim_r;
    D_8439037C = arg0->prim_g;
    D_8439037E = arg0->prim_b;
}

void BattleAnim_LoadGlobalTintToParticle(Particle* arg0) {
    arg0->prim_r = D_8439037A;
    arg0->prim_g = D_8439037C;
    arg0->prim_b = D_8439037E;
}
