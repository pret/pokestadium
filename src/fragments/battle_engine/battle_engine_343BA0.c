#include "battle_engine.h"
#include "src/gallery.h"
#include "src/gfx_buffer.h"
#include "include/math.h"
#include "src/math_util.h"

u8* gBattleAnimAssetPointers[256];
s16 gBattleAnimResourceList[0x10];
arg1_func_80019420* gBattleAnimResourceTablePointers[40];
static s16 D_84392580;
static s16 D_84392582;
static Mtx D_84392588;
static s16 D_843925C8;
static s16 D_843925CA;
static s16 D_843925CC;
static s16 D_843925CE;
static s16 D_843925D0;
static s16 D_843925D2;
static s16 D_843925D4;
static s16 D_843925D6;
static s16 D_843925D8;
static s16 D_843925DA;

#if !(defined(VERSION_US_REV2))
static const char D_8438D3D0[] = "calc_vector_ATtoDM() normal error!!!\n";
#endif
#if !(defined(VERSION_US_REV2))
static const char D_8438D3F8[] = "calc_vector_ATtoDM2() normal error!!!\n";
#endif

void BattleAnim_NoopUpdateHook(void) {
}

void func_843592E8(void) {
}

void func_843592F0(void) {
}

void func_843592F8(void) {
}

void func_84359300(void) {
}

void func_84359308(void) {
}

void func_84359310(void) {
}

void func_84359318(void) {
}

void func_84359320(void) {
}

void func_84359328(void) {
}

void func_84359330(UNUSED s32 arg0) {
}

void func_84359338(UNUSED s32 arg0) {
}

void func_84359340(void) {
}

void BattleAnim_DrawStoredColorOverlay(void) {
    BattleAnim_DrawFullScreenColorOverlay(D_8439037A, D_8439037C, D_8439037E, 0xFF);
}

void BattleAnim_ReinitAuxiliaryEffects(void) {
    AuxiliaryEffect_Init();
}

void BattleAnim_DefaultStartEffect_Init(void) {
}

void BattleAnim_DefaultEndEffect_Init(void) {
}

s32 BattleAnim_DefaultStartEffect_CompleteImmediately(void) {
    return -1;
}

s32 BattleAnim_DefaultEndEffect_CompleteImmediately(void) {
    return -1;
}

void BattleAnim_DefaultStartEffect_Draw(void) {
}

void BattleAnim_DefaultEndEffect_Draw(void) {
}

void Battle_GetTertiaryOwnerBonePositionUnused(Vec3f* arg0) {
    BattleAnim_GetTertiaryOwnerBonePosition(arg0);
}

void BattleAnim_EffectSecondaryOwnerAnchorPosition(Vec3f* arg0) {
    BattleAnim_GetSecondaryOwnerAnchorPosition(arg0);
}

void BattleAnim_EffectTertiaryOwnerBonePosition(Vec3f* arg0) {
    BattleAnim_GetTertiaryOwnerBonePosition(arg0);
}

void BattleAnim_EffectSecondaryOwnerBonePosition(Vec3f* arg0) {
    BattleAnim_GetSecondaryOwnerBonePosition(arg0);
}

f32 BattleAnim_EffectTertiaryOwnerModelScale(void) {
    return BattleAnim_GetTertiaryOwnerModelScale();
}

f32 BattleAnim_EffectSecondaryOwnerModelScale(void) {
    return BattleAnim_GetSecondaryOwnerModelScale();
}

#if defined(VERSION_US_REV2)
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/battle_engine/battle_engine_343BA0/BattleAnim_CalcVectorAtToDm.s")
#else
void BattleAnim_CalcVectorAtToDm(f32* arg0, f32* arg1, f32* arg2, f32* arg3, f32* arg4, f32* arg5) {
    Vec3f sp4C;
    Vec3f sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    UNUSED s32 pad[3];
    f32 sp24;
    f32 sp20;
    f32 sp1C;

    BattleAnim_EffectSecondaryOwnerAnchorPosition(&sp4C);
    BattleAnim_EffectTertiaryOwnerBonePosition(&sp40);

    sp3C = sp4C.x;
    sp38 = sp4C.y;
    sp34 = sp4C.z;

    sp24 = sp40.x - sp4C.x;
    sp20 = sp40.y - sp4C.y;
    sp1C = sp40.z - sp4C.z;

    if (sp24 == 0.0f || sp20 == 0.0f || sp1C == 0.0f) {}

    Vec3f_NormalizeComponents(&sp24, &sp20, &sp1C);

    *arg0 = sp3C;
    *arg1 = sp38;
    *arg2 = sp34;
    *arg3 = sp24;
    *arg4 = sp20;
    *arg5 = sp1C;
}
#endif

#if defined(VERSION_US_REV2)
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/battle_engine/battle_engine_343BA0/BattleAnim_CalcVectorAtToDm2.s")
#else
void BattleAnim_CalcVectorAtToDm2(f32* arg0, f32* arg1, f32* arg2, f32* arg3, f32* arg4, f32* arg5) {
    Vec3f sp4C;
    Vec3f sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    UNUSED s32 pad[2];
    f32 tmp;
    f32 sp24;
    f32 sp20;
    f32 sp1C;

    BattleAnim_EffectSecondaryOwnerAnchorPosition(&sp4C);
    BattleAnim_EffectTertiaryOwnerBonePosition(&sp40);

    sp3C = sp4C.x;
    sp38 = sp4C.y;
    sp34 = sp4C.z;

    tmp = sp40.y;
    if (tmp < 0.0f) {
        tmp = 0.0f;
    }

    sp24 = sp40.x - sp4C.x;
    sp20 = tmp - sp4C.y;
    sp1C = sp40.z - sp4C.z;

    if (sp24 == 0.0f || sp20 == 0.0f || sp1C == 0.0f) {}

    Vec3f_NormalizeComponents(&sp24, &sp20, &sp1C);

    *arg0 = sp3C;
    *arg1 = sp38;
    *arg2 = sp34;
    *arg3 = sp24;
    *arg4 = sp20;
    *arg5 = sp1C;
}
#endif

void BattleAnim_ResetSharedEffectMatrix(void) {
    guRotateRPY(&D_84392588, 0.0f, 0.0f, 0.0f);
}

void BattleAnim_Effect5RibbonMesh_Init(void) {
    Vec3f sp24;
    f32 sp20;

    BattleAnim_ResetSharedEffectMatrix();
    BattleAnim_EffectSecondaryOwnerBonePosition(&sp24);
    sp20 = BattleAnim_EffectSecondaryOwnerModelScale();
    RibbonMesh_Init();
    RibbonMesh_Spawn(sp24.x, sp24.y, sp24.z, 40.0f, sp20, 0);
}

s32 BattleAnim_Effect5RibbonMesh_Update(void) {
    return RibbonMesh_UpdatePool();
}

void BattleAnim_Effect5RibbonMesh_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = RibbonMesh_DrawPool(gDisplayListHead);
}

void BattleAnim_EndEffect1RibbonMesh_Init(void) {
    Vec3f sp24;
    f32 sp20;

    BattleAnim_ResetSharedEffectMatrix();
    BattleAnim_EffectSecondaryOwnerBonePosition(&sp24);
    sp20 = BattleAnim_EffectTertiaryOwnerModelScale();
    RibbonMesh_Init();
    RibbonMesh_Spawn(sp24.x, sp24.y, sp24.z, 40.0f, sp20, 1);
}

s32 BattleAnim_EndEffect1RibbonMesh_Update(void) {
    return RibbonMesh_UpdatePool();
}

void BattleAnim_EndEffect1RibbonMesh_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = RibbonMesh_DrawPool(gDisplayListHead);
}

void BattleAnim_EndEffect19RibbonMesh_Init(void) {
    Vec3f sp24;
    f32 sp20;

    BattleAnim_ResetSharedEffectMatrix();
    BattleAnim_EffectSecondaryOwnerBonePosition(&sp24);
    sp20 = BattleAnim_EffectTertiaryOwnerModelScale();
    RibbonMesh_Init();
    RibbonMesh_Spawn(sp24.x, sp24.y, sp24.z, 40.0f, sp20, 0);
    RibbonMesh_Spawn(sp24.x, sp24.y, sp24.z, 38.0f, sp20, 1);
}

s32 BattleAnim_EndEffect19RibbonMesh_Update(void) {
    return RibbonMesh_UpdatePool();
}

void BattleAnim_EndEffect19RibbonMesh_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = RibbonMesh_DrawPool(gDisplayListHead);
}

void BattleAnim_Effect54RibbonMesh_Init(void) {
    Vec3f sp24;
    f32 sp20;

    BattleAnim_ResetSharedEffectMatrix();
    BattleAnim_EffectSecondaryOwnerBonePosition(&sp24);
    sp20 = BattleAnim_EffectSecondaryOwnerModelScale();
    RibbonMesh_Init();
    RibbonMesh_Spawn(sp24.x, sp24.y, sp24.z, 40.0f, sp20, 0);
    RibbonMesh_Spawn(sp24.x, sp24.y, sp24.z, 38.0f, sp20, 1);
}

s32 BattleAnim_Effect54RibbonMesh_Update(void) {
    return RibbonMesh_UpdatePool();
}

void BattleAnim_Effect54RibbonMesh_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = RibbonMesh_DrawPool(gDisplayListHead);
}

void BattleAnim_StartEffect34TerrainGrid_Init(void) {
    Vec3f sp1C;

    BattleAnim_EffectSecondaryOwnerAnchorPosition(&sp1C);
    BattleAnim_ResetSharedEffectMatrix();

    if (sp1C.x < 0.0) {
        TerrainGrid_Init(1, 0, 0x4650);
    } else {
        TerrainGrid_Init(-1, 0, 0x4650);
    }
}

s32 BattleAnim_StartEffect34TerrainGrid_Update(void) {
    return TerrainGrid_Update();
}

void BattleAnim_StartEffect34TerrainGrid_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = TerrainGrid_Draw(gDisplayListHead);
}

void BattleAnim_EndEffect16_NoOpInit(void) {
}

s32 BattleAnim_EndEffect16_CompleteImmediately(void) {
    return -1;
}

void BattleAnim_EndEffect16_NoOpDraw(void) {
}

void BattleAnim_StartEffect19Radial20_EmitVariantD(void) {
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    UNUSED s32 pad;
    s32 sp54;

    BattleAnim_CalcVectorAtToDm(&sp74, &sp70, &sp6C, &sp68, &sp64, &sp60);
    sp68 *= 8.0f;
    sp64 *= 4.0f;
    sp60 = 0.0f;
    sp64 += 6.0f;
    sp5C = BattleAnim_EffectSecondaryOwnerModelScale();
    sp54 = guRandom();
    Radial20_VariantD(sp74, sp70, sp6C, sp68, (((sp54 % 4) * 0.01f) + sp64) - 0.02f,
                  (sp60 - ((guRandom() % 5) * 0.3f)) + 0.6f, 3, 0x64, 0xC8, 0xFF, 0xC8, 0, 0x64, 0xC8, 0.1f, sp5C,
                  4.0f * sp5C, 0x3C);
}

void BattleAnim_StartEffect19Radial20_Init(void) {
    D_843925CE = 0;
    BattleAnim_ResetSharedEffectMatrix();
    Radial20_ResetPool();
    BattleAnim_StartEffect19Radial20_EmitVariantD();
}

s32 BattleAnim_StartEffect19Radial20_Update(void) {
    D_843925CE++;
    if (D_843925CE >= 0xB5) {
        return -1;
    }

    if ((D_843925CE < 0x78) && ((D_843925CE % 7) == 0)) {
        BattleAnim_StartEffect19Radial20_EmitVariantD();
    }
    return Radial20_IsComplete();
}

void BattleAnim_StartEffect19Radial20_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = func_84362084(gDisplayListHead);
}

void BattleAnim_EndEffect9Radial20_Init(void) {
    Vec3f sp34;
    f32 sp30;

    BattleAnim_ResetSharedEffectMatrix();
    BattleAnim_EffectTertiaryOwnerBonePosition(&sp34);
    sp30 = BattleAnim_EffectTertiaryOwnerModelScale();
    BattleAnim_ResetSharedEffectMatrix();
    Radial20_Init(sp34.x, sp34.y, sp34.z, sp30, 0x64, 0xC8, 0xFF, 0, 0x64, 0xC8);
}

s32 BattleAnim_EndEffect9Radial20_Update(void) {
    return Radial20_Update();
}

void BattleAnim_EndEffect9Radial20_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = Strip400_Draw(gDisplayListHead);
}

void BattleAnim_StartEffect7TexturedRibbonSheet_Emit(void) {
    UNUSED s32 pad[3];
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;

    sp40 = BattleAnim_EffectSecondaryOwnerModelScale();
    BattleAnim_CalcVectorAtToDm2(&sp58, &sp54, &sp50, &sp4C, &sp48, &sp44);
    sp4C *= 20.0f;
    sp48 *= 20.0f;
    sp44 *= 20.0f;
    sp58 += sp40 * (30.0f - (guRandom() % 60));
    sp54 += sp40 * (30.0f - (guRandom() % 60));
    sp50 += sp40 * (30.0f - (guRandom() % 60));
    TexturedRibbonSheet_Start(sp58, sp54, sp50, sp4C, sp48, sp44, 0xFF, 0xFF, 0, 0x3C, 0.3f, 0x1E);
}

void BattleAnim_StartEffect7TexturedRibbonSheet_Init(void) {
    D_843925D0 = 0;
    BattleAnim_ResetSharedEffectMatrix();
    TexturedRibbonSheet_Init();
    BattleAnim_StartEffect7TexturedRibbonSheet_Emit();
}

s32 BattleAnim_StartEffect7TexturedRibbonSheet_Update(void) {
    D_843925D0++;
    if (D_843925D0 >= 0x709) {
        return -1;
    }

    if ((D_843925D0 < 0x6EA) && ((D_843925D0 % 3) == 0)) {
        BattleAnim_StartEffect7TexturedRibbonSheet_Emit();
    }

    return TexturedRibbonSheet_IsComplete();
}

void BattleAnim_StartEffect7TexturedRibbonSheet_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = TexturedRibbonSheet_Draw(gDisplayListHead);
}

void BattleAnim_StartEffect33Radial20_EmitVariantC(void) {
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    UNUSED s32 pad;
    s32 sp54;

    BattleAnim_CalcVectorAtToDm(&sp74, &sp70, &sp6C, &sp68, &sp64, &sp60);
    sp68 *= 8.0f;
    sp64 *= 4.0f;
    sp60 = 0.0f;
    sp64 += 6.0f;
    sp5C = BattleAnim_EffectSecondaryOwnerModelScale();
    sp54 = guRandom();
    Radial20_VariantC(sp74, sp70, sp6C, sp68, (((sp54 % 5) * 0.1f) + sp64) - 0.2f,
                  (sp60 - ((guRandom() % 5) * 0.3f)) + 0.6f, 3, 0xFF, 0xFF, 0xFF, 0x64, 0x64, 0x96, 0x96, 0.1f, sp5C,
                  3.0f * sp5C, 0x3C);
}

void BattleAnim_StartEffect33Radial20_Init(void) {
    D_843925D2 = 0;
    BattleAnim_ResetSharedEffectMatrix();
    Radial20_ResetPool();
    BattleAnim_StartEffect33Radial20_EmitVariantC();
}

s32 BattleAnim_StartEffect33Radial20_Update(void) {
    D_843925D2++;
    if (D_843925D2 >= 0xB5) {
        return -1;
    }

    if ((D_843925D2 < 0x78) && ((D_843925D2 % 7) == 0)) {
        BattleAnim_StartEffect33Radial20_EmitVariantC();
    }

    return Radial20_IsComplete();
}

void BattleAnim_StartEffect33Radial20_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = func_84362084(gDisplayListHead);
}

void BattleAnim_EndEffect32Radial20_Init(void) {
    Vec3f sp34;
    f32 sp30;

    BattleAnim_ResetSharedEffectMatrix();
    BattleAnim_EffectSecondaryOwnerBonePosition(&sp34);
    sp30 = BattleAnim_EffectTertiaryOwnerModelScale();
    BattleAnim_ResetSharedEffectMatrix();
    Radial20_Init(sp34.x, sp34.y, sp34.z, sp30, 0xFF, 0xFF, 0xFF, 0x64, 0x96, 0x96);
}

s32 BattleAnim_EndEffect32Radial20_Update(void) {
    return Radial20_Update();
}

void BattleAnim_EndEffect32Radial20_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = Strip400_Draw(gDisplayListHead);
}

void BattleAnim_EndEffect33Radial20_Init(void) {
    Vec3f sp34;
    f32 sp30;

    BattleAnim_ResetSharedEffectMatrix();
    BattleAnim_EffectSecondaryOwnerBonePosition(&sp34);
    sp30 = BattleAnim_EffectTertiaryOwnerModelScale();
    BattleAnim_ResetSharedEffectMatrix();
    Radial20_Init(sp34.x, sp34.y, sp34.z, sp30, 0xFF, 0xFF, 0x64, 0x96, 0x96, 0);
}

s32 BattleAnim_EndEffect33Radial20_Update(void) {
    return Radial20_Update();
}

void BattleAnim_EndEffect33Radial20_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = Strip400_Draw(gDisplayListHead);
}

void BattleAnim_StartEffect98Radial20_EmitVariantD(void) {
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    UNUSED s32 pad;
    s32 sp54;

    BattleAnim_CalcVectorAtToDm(&sp74, &sp70, &sp6C, &sp68, &sp64, &sp60);
    sp68 *= 8.0f;
    sp64 *= 4.0f;
    sp60 = 0.0f;
    sp64 += 6.0f;
    sp5C = BattleAnim_EffectSecondaryOwnerModelScale();
    sp54 = guRandom();
    Radial20_VariantD(sp74, sp70, sp6C, sp68, (((sp54 % 4) * 0.01f) + sp64) - 0.02f,
                  (sp60 - ((guRandom() % 5) * 0.3f)) + 0.6f, 3, 0xFF, 0xFF, 0x64, 0xFF, 0x96, 0x96, 0, 0.1f, sp5C,
                  4.0f * sp5C, 0x3C);
}

void BattleAnim_StartEffect98Radial20_Init(void) {
    D_843925D6 = 0;
    BattleAnim_ResetSharedEffectMatrix();
    Radial20_ResetPool();
    BattleAnim_StartEffect98Radial20_EmitVariantD();
}

s32 BattleAnim_StartEffect98Radial20_Update(void) {
    D_843925D6++;
    if (D_843925D6 >= 0xB5) {
        return -1;
    }

    if ((D_843925D6 < 0x78) && ((D_843925D6 % 7) == 0)) {
        BattleAnim_StartEffect98Radial20_EmitVariantD();
    }

    return Radial20_IsComplete();
}

void BattleAnim_StartEffect98Radial20_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = func_84362084(gDisplayListHead);
}

void BattleAnim_StartEffect11Trail50Alt_Init(void) {
    D_843925D8 = 0;
    BattleAnim_ResetSharedEffectMatrix();
    Trail50EffectAlt_Init();
}

s32 BattleAnim_StartEffect11Trail50Alt_Update(void) {
    UNUSED s32 pad[1];
    Vec3f sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    UNUSED s32 pad2[2];
    f32 var_fv0;
    f32 sp44;

    D_843925D8++;
    if (!(D_843925D8 & 1)) {
        sp44 = BattleAnim_EffectSecondaryOwnerModelScale();
        BattleAnim_EffectSecondaryOwnerAnchorPosition(&sp60);
        sp5C = (((guRandom() % 50) - 0x19) * sp44) + sp60.x;
        sp58 = (((guRandom() % 60) - 0x1E) * sp44) + sp60.y;
        sp54 = (((guRandom() % 50) - 0x19) * sp44) + sp60.z;
        var_fv0 = 10.0f;
        if (sp5C > 0.0) {
            var_fv0 = -var_fv0;
        }
        Trail50EffectAlt_Start(sp5C, sp58, sp54, var_fv0, 0.0f, 0.0f, 0xFF, 0xFF, 0xFF, 0x64, 0.3f, 1.0f, 4.0f, 0x1E);
    }
    Trail50EffectAlt_IsComplete();
    return 0;
}

void BattleAnim_StartEffect11Trail50Alt_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = Trail50EffectAlt_Draw(gDisplayListHead);
}

void BattleAnim_StartEffect57Trail50_Init(void) {
    D_843925DA = 0;
    BattleAnim_ResetSharedEffectMatrix();
    Trail50Effect_Init();
}

s32 BattleAnim_StartEffect57Trail50_Update(void) {
    UNUSED s32 pad[1];
    Vec3f sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    UNUSED s32 pad2[2];
    f32 var_fv0;
    f32 sp44;

    D_843925DA++;
    if (!(D_843925DA & 1)) {
        sp44 = BattleAnim_EffectSecondaryOwnerModelScale();
        BattleAnim_EffectSecondaryOwnerAnchorPosition(&sp60);
        sp5C = (((guRandom() % 50) - 0x19) * sp44) + sp60.x;
        sp58 = (((guRandom() % 60) - 0x1E) * sp44) + sp60.y;
        sp54 = (((guRandom() % 50) - 0x19) * sp44) + sp60.z;
        var_fv0 = 10.0f;
        if (sp5C > 0.0) {
            var_fv0 = -var_fv0;
        }
        Trail50Effect_Start(sp5C, sp58, sp54, var_fv0, 0.0f, 0.0f, 0xFF, 0xFF, 0xFF, 0x64, 0.3f, 1.0f, 4.0f, 0x1E);
    }
    Trail50Effect_IsComplete();
    return 0;
}

void BattleAnim_StartEffect57Trail50_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = Trail50Effect_Draw(gDisplayListHead);
}

void BattleAnim_StartEffect42Trail40_Init(void) {
    Vec3f sp1C;

    BattleAnim_ResetSharedEffectMatrix();
    BattleAnim_EffectSecondaryOwnerAnchorPosition(&sp1C);
    Trail40_Init(0x708);
}

s32 BattleAnim_StartEffect42Trail40_Update(void) {
    return Trail40_IsComplete();
}

void BattleAnim_StartEffect42Trail40_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = Trail40_Draw(gDisplayListHead);
}

void BattleAnim_StartEffect43Trail40Variant_Init(void) {
    Vec3f sp1C;

    BattleAnim_ResetSharedEffectMatrix();
    BattleAnim_EffectSecondaryOwnerAnchorPosition(&sp1C);
    Trail40Variant_InitPool(0x708);
}

s32 BattleAnim_StartEffect43Trail40Variant_Update(void) {
    return Trail40Variant_AdvanceTimer();
}

void BattleAnim_StartEffect43Trail40Variant_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = Trail40Variant_BuildGfx(gDisplayListHead);
}

void BattleAnim_StartEffect44Trail40GridAlt_Init(void) {
    Vec3f sp1C;

    BattleAnim_ResetSharedEffectMatrix();
    BattleAnim_EffectSecondaryOwnerAnchorPosition(&sp1C);
    Trail40GridAlt_Init(0x708);
}

s32 BattleAnim_StartEffect44Trail40GridAlt_Update(void) {
    return Trail40GridAlt_IsComplete();
}

void BattleAnim_StartEffect44Trail40GridAlt_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = Trail40GridAlt_Draw(gDisplayListHead);
}

void BattleAnim_StartEffect45FourStreamTrail_Init(void) {
    D_84392580 = 0;
    BattleAnim_ResetSharedEffectMatrix();
    FourStreamTrail_Init();
}

s32 BattleAnim_StartEffect45FourStreamTrail_Update(void) {
    s32 var_v1;
    Vec3f sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;

    D_84392580++;
    if (D_84392580 >= 0x32) {
        return -1;
    }

    if (D_84392580 < 4) {
        BattleAnim_EffectSecondaryOwnerBonePosition(&sp68);
        sp64 = sp68.x;
        sp60 = sp68.y;
        sp5C = sp68.z;
        sp58 = 1.0f;
        sp4C = (((D_84392580 % 3) * M_PI_F) / 3.0) + 0.5235987901687622;
        sp54 = (f64)__sinf(sp4C);
        sp50 = (f64)__cosf(sp4C);
        Vec3f_NormalizeComponents(&sp58, &sp54, &sp50);
        sp54 *= 20.0;
        sp50 *= 20.0;
        sp58 = 10.0f;
        if (sp64 < 0.0) {
            sp58 = -sp58;
        }
        FourStreamTrail_Start(sp64, sp60, sp5C, sp58, sp54, sp50, 0xC0, 0xFF, 0xFF, 0x80, (((guRandom() % 2) * 2) - 1) * 0.3,
                      2.0f, 13.0f, 0x28);
    }

    if (D_84392580 >= 2) {
        var_v1 = FourStreamTrail_IsComplete();
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

void BattleAnim_StartEffect45FourStreamTrail_Draw(void) {
    if (D_84392580 >= 2) {
        gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        gDisplayListHead = FourStreamTrail_Draw(gDisplayListHead);
    }
}

void BattleAnim_StartEffect62OwnerLinkedFourStream_Init(void) {
    D_84392582 = 0;
    BattleAnim_ResetSharedEffectMatrix();
    OwnerLinkedFourStream_Init();
}

s32 BattleAnim_StartEffect62OwnerLinkedFourStream_Update(void) {
    s32 var_v1;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;

    D_84392582++;
    if (((D_84392582 >> 2) < 4) && !(D_84392582 & 3)) {
        BattleAnim_CalcVectorAtToDm(&sp60, &sp5C, &sp58, &sp54, &sp50, &sp4C);
        sp48 = ((2 - (((D_84392582 >> 2) + 2) % 3)) * 0.5235988f) + 0.34906587f;
        sp54 *= 7.0f * __cosf(sp48);
        sp50 = __sinf(sp48) * 10.0f;
        sp4C = 0.0f;
        OwnerLinkedFourStream_Start(sp60, sp5C, sp58, sp54, sp50, 0.0f, 0xD0, 0xFF, 0xFF, 0x80, 0.8f, 2.0f, 4.0f, 0x28);
    }

    if (D_84392582 >= 2) {
        var_v1 = OwnerLinkedFourStream_IsComplete();
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

void BattleAnim_StartEffect62OwnerLinkedFourStream_Draw(void) {
    if (D_84392582 >= 2) {
        gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        gDisplayListHead = OwnerLinkedFourStream_Draw(gDisplayListHead);
    }
}

void BattleAnim_StartEffect67OwnerAnchoredFourStream_Init(void) {
    Vec3f sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;

    D_843925C8 = 0;
    BattleAnim_ResetSharedEffectMatrix();
    OwnerAnchoredFourStream_Init();
    BattleAnim_CalcVectorAtToDm(&sp58, &sp54, &sp50, &sp4C, &sp48, &sp44);
    sp4C *= 5.0;
    sp48 *= 5.0;
    sp44 *= 5.0;
    OwnerAnchoredFourStream_Start(sp58, sp54, sp50, sp4C, sp48, sp44, 0xC0, 0xFF, 0xFF, 0xA0, 0.6f, 2.0f, 4.0f, 0x28);
    sp5C.x = sp58;
    sp5C.y = sp54;
    sp5C.z = sp50;
    BattleAnim_SpawnSecondaryOwnerParticle(sp5C, 1);
}

s32 BattleAnim_StartEffect67OwnerAnchoredFourStream_Update(void) {
    D_843925C8++;
    if (D_843925C8 >= 0x32) {
        return -1;
    }

    return OwnerAnchoredFourStream_IsComplete();
}

void BattleAnim_StartEffect67OwnerAnchoredFourStream_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = OwnerAnchoredFourStream_Draw(gDisplayListHead);
}

void BattleAnim_StartEffect78Radial20_EmitVariantA(void) {
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;

    BattleAnim_CalcVectorAtToDm(&sp5C, &sp58, &sp54, &sp50, &sp4C, &sp48);
    sp50 *= 6.0f;
    sp4C *= 6.0f;
    sp48 *= 6.0f;
    Radial20_VariantA(sp5C, sp58, sp54, sp50, sp4C, sp48, 8, 0xFF, 0xFF, 0xFF, 0xB4, 0.3f, 2.0f, 20.0f, 0x3C);
}

void BattleAnim_StartEffect78Radial20_Init(void) {
    D_843925CA = 0;
    BattleAnim_ResetSharedEffectMatrix();
    Radial20_ResetPool();
    BattleAnim_StartEffect78Radial20_EmitVariantA();
}

s32 BattleAnim_StartEffect78Radial20_Update(void) {
    D_843925CA++;
    if (D_843925CA >= 0xB5) {
        return -1;
    }
    return Radial20_IsComplete();
}

void BattleAnim_StartEffect78Radial20_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = func_84362084(gDisplayListHead);
}

void BattleAnim_StartEffect26DoubleTextureTrail_Seed(void) {
    static unk_D_843C2C00_024 D_84387FC0 = { 2, 1, 0xE, 1, 2, 2, 3, 1 };
    static unk_D_843C2C00_024 D_84387FE0 = { 3, 5, 0, 5, 3, 7, 0, 5 };
    static unk_D_843C2C00_024 D_84388000 = { 2, 1, 0xE, 1, 2, 1, 3, 1 };
    static unk_D_843C2C00_024 D_84388020 = { 3, 5, 0, 5, 0, 7, 5, 7 };

    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;

    BattleAnim_CalcVectorAtToDm(&spB4, &spB0, &spAC, &spA8, &spA4, &spA0);
    spA8 *= 10.0f;
    spA4 *= 10.0f;
    spA0 *= 10.0f;
    DoubleTextureTrail_Spawn(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 2.0f, 10.0f, 0x14, 0x8F, 0x8F, 6, 0xA, 0xF, 0xE,
                  -3, 5, 0, 0xF, &D_84387FC0, &D_84387FE0, 0xFF, 0xFF, 0, 0x96, 0x64, 0xFF, 0, 0xC8, 0x32, 0xFF, 0x96,
                  0xFF, 0x78);
    DoubleTextureTrail_Spawn(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 3.0f, 15.0f, 0x14, 0x8F, 0x90, 2, 6, 0, 0xF, -4,
                  2, 0, 0, &D_84388000, &D_84388020, 0, 0xFF, 0x64, 0x96, 0x64, 0x64, 0, 0xFF, 0xC8, 0, 0, 0, 0);
}

void BattleAnim_StartEffect26DoubleTextureTrail_Init(void) {
    BattleAnim_ResetSharedEffectMatrix();
    DoubleTextureTrail_InitPool();
    BattleAnim_StartEffect26DoubleTextureTrail_Seed();
}

s32 BattleAnim_StartEffect26DoubleTextureTrail_Update(void) {
    return DoubleTextureTrail_UpdateAll();
}

void BattleAnim_StartEffect26DoubleTextureTrail_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = DoubleTextureTrail_DrawAll(gDisplayListHead);
}

void BattleAnim_StartEffect47SixSlotTrail_Seed(void) {
    static unk_D_843C2C00_024 D_84388040 = { 3, 5, 1, 5, 1, 7, 3, 7 };
    static unk_D_843C2C00_024 D_84388060 = { 0x1F, 0x1F, 0x1F, 0, 7, 7, 7, 0 };

    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;

    BattleAnim_CalcVectorAtToDm(&spA4, &spA0, &sp9C, &sp98, &sp94, &sp90);
    sp94 += 0.2f * __cosf((RAND(10) * M_PI_F) / 10.0f);
    sp90 += 0.2f * __cosf((RAND(10) * M_PI_F) / 10.0f);

    sp98 *= 12.0f;
    sp94 *= 12.0f;
    sp90 *= 12.0f;

    BattleAnim_SixSlotTrail_Spawn(0, spA4, spA0, sp9C, sp98, sp94, sp90, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0, 0x64, 0xFF, 0xFF, 0.4f, 2.0f,
                  20.0f, 0x3C, 0x95, 0x95, 0, 0xA, 0, 0xD, 0, 0, 0, 0, &D_84388040, &D_84388060);
}

void BattleAnim_StartEffect47SixSlotTrail_Init(void) {
    D_843925CC = 0;
    BattleAnim_ResetSharedEffectMatrix();
    BattleAnim_SixSlotTrail_ResetPool();
    BattleAnim_StartEffect47SixSlotTrail_Seed();
}

s32 BattleAnim_StartEffect47SixSlotTrail_Update(void) {
    D_843925CC++;
    if ((D_843925CC % 10) == 0) {
        BattleAnim_StartEffect47SixSlotTrail_Seed();
    }
    return BattleAnim_SixSlotTrail_UpdateAll();
}

void BattleAnim_StartEffect47SixSlotTrail_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = BattleAnim_SixSlotTrail_DrawAll(gDisplayListHead);
}

void BattleAnim_StartEffect4DoubleTextureTrail_Seed(void) {
    static unk_D_843C2C00_024 D_84388080 = { 3, 5, 1, 5, 6, 7, 2, 3 };
    static unk_D_843C2C00_024 D_843880A0 = { 0x1F, 0x1F, 0x1F, 0, 0, 7, 5, 7 };
    static unk_D_843C2C00_024 D_843880C0 = { 3, 5, 2, 5, 1, 7, 3, 7 };
    static unk_D_843C2C00_024 D_843880E0 = { 0x1F, 0x1F, 0x1F, 0, 0, 7, 5, 7 };

    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;

    BattleAnim_CalcVectorAtToDm(&spB4, &spB0, &spAC, &spA8, &spA4, &spA0);
    spA8 *= 10.0f;
    spA4 *= 10.0f;
    spA0 *= 10.0f;
    DoubleTextureTrail_Spawn(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 2.0f, 10.0f, 0x14, 0x93, 0x93, 5, 0xA, 0xF, 0xF,
                  -5, 5, 0xF, 0xF, &D_84388080, &D_843880A0, 0xC8, 0xC8, 0, 0x64, 0, 0, 0xC8, 0, 0xFF, 0, 0xFF, 0,
                  0x5A);
    DoubleTextureTrail_Spawn(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 3.0f, 15.0f, 0x14, 0x91, 0x91, -2, 0xA, 0xF,
                  0xF, 5, 0xF, 0xF, 0xF, &D_843880C0, &D_843880E0, 0xFF, 0x32, 0x64, 0xC8, 0, 0x64, 0x32, 0xFF, 0xFF, 0,
                  0, 0, 0);
}

void BattleAnim_StartEffect4DoubleTextureTrail_Init(void) {
    BattleAnim_ResetSharedEffectMatrix();
    DoubleTextureTrail_InitPool();
    BattleAnim_StartEffect4DoubleTextureTrail_Seed();
}

s32 BattleAnim_StartEffect4DoubleTextureTrail_Update(void) {
    return DoubleTextureTrail_UpdateAll();
}

void BattleAnim_StartEffect4DoubleTextureTrail_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = DoubleTextureTrail_DrawAll(gDisplayListHead);
}

void BattleAnim_StartEffect77DoubleTextureTrail_Seed(void) {
    static unk_D_843C2C00_024 D_84388100 = { 2, 1, 0xE, 1, 2, 7, 1, 3 };
    static unk_D_843C2C00_024 D_84388120 = { 3, 5, 0, 5, 0, 7, 5, 7 };
    static unk_D_843C2C00_024 D_84388140 = { 2, 1, 0xE, 1, 2, 7, 1, 3 };
    static unk_D_843C2C00_024 D_84388160 = { 3, 5, 0, 5, 0, 7, 5, 7 };

    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;

    BattleAnim_CalcVectorAtToDm(&spB4, &spB0, &spAC, &spA8, &spA4, &spA0);
    spA8 *= 10.0f;
    spA4 *= 10.0f;
    spA0 *= 10.0f;
    DoubleTextureTrail_Spawn(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 2.0f, 10.0f, 0x14, 0x97, 0x98, -5, 0x14, 0xF,
                  0xD, -5, 0x14, 0, 0xE, &D_84388100, &D_84388120, 0xFF, 0xFF, 0xFF, 0x32, 0x64, 0x64, 0, 0xFF, 0xFF,
                  0xC8, 0xFF, 0xFF, 0x96);
    DoubleTextureTrail_Spawn(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 3.0f, 15.0f, 0x14, 0x97, 0x98, 5, 0xF, 0xF, 0xE,
                  0, 0xF, 0xF, 0xF, &D_84388140, &D_84388160, 0xFF, 0xFF, 0xFF, 0x32, 0x64, 0x64, 0x64, 0xFF, 0xFF, 0,
                  0, 0, 0);
}

void BattleAnim_StartEffect77DoubleTextureTrail_Init(void) {
    BattleAnim_ResetSharedEffectMatrix();
    DoubleTextureTrail_InitPool();
    BattleAnim_StartEffect77DoubleTextureTrail_Seed();
}

s32 BattleAnim_StartEffect77DoubleTextureTrail_Update(void) {
    return DoubleTextureTrail_UpdateAll();
}

void BattleAnim_StartEffect77DoubleTextureTrail_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = DoubleTextureTrail_DrawAll(gDisplayListHead);
}

void BattleAnim_StartEffect70DoubleTextureTrail_Seed(void) {
    static unk_D_843C2C00_024 D_84388180 = { 2, 1, 0xE, 1, 2, 1, 3, 1 };
    static unk_D_843C2C00_024 D_843881A0 = { 3, 5, 0, 5, 0, 7, 5, 7 };

    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;

    BattleAnim_CalcVectorAtToDm(&spB4, &spB0, &spAC, &spA8, &spA4, &spA0);
    spA8 *= 10.0f;
    spA4 *= 10.0f;
    spA0 *= 10.0f;
    DoubleTextureTrail_Spawn(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 3.0f, 15.0f, 0x14, 0x97, 0x94, 0, 0x14, 0xE,
                  0xF, 0, 0x14, 0xF, 0xE, &D_84388180, &D_843881A0, 0xFF, 0xFF, 0xFF, 0x96, 0x96, 0xFF, 0xFF, 0, 0xFF,
                  0xFF, 0xFF, 0, 0x96);
}

void BattleAnim_StartEffect70DoubleTextureTrail_Init(void) {
    BattleAnim_ResetSharedEffectMatrix();
    DoubleTextureTrail_InitPool();
    BattleAnim_StartEffect70DoubleTextureTrail_Seed();
}

s32 BattleAnim_StartEffect70DoubleTextureTrail_Update(void) {
    return DoubleTextureTrail_UpdateAll();
}

void BattleAnim_StartEffect70DoubleTextureTrail_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = DoubleTextureTrail_DrawAll(gDisplayListHead);
}

void BattleAnim_StartEffect39DoubleTextureTrail_Seed(void) {
    static unk_D_843C2C00_024 D_843881C0 = {
        0x00000002, 0x00000001, 0x0000000E, 0x00000001, 0x00000007, 0x00000007, 0x00000007, 0x00000003,
    };
    static unk_D_843C2C00_024 D_843881E0 = {
        0x00000003, 0x00000005, 0x00000000, 0x00000005, 0x00000007, 0x00000007, 0x00000007, 0x00000000,
    };
    static unk_D_843C2C00_024 D_84388200 = {
        0x00000002, 0x00000001, 0x0000000E, 0x00000001, 0x00000002, 0x00000001, 0x00000003, 0x00000001,
    };
    static unk_D_843C2C00_024 D_84388220 = {
        0x00000003, 0x00000005, 0x00000000, 0x00000005, 0x00000000, 0x00000007, 0x00000005, 0x00000007,
    };

    f32 spB4;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;

    BattleAnim_CalcVectorAtToDm(&spB4, &spB0, &spAC, &spA8, &spA4, &spA0);
    spA8 *= 12.0f;
    spA4 *= 12.0f;
    spA0 *= 12.0f;
    DoubleTextureTrail_Spawn(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 2.0f, 10.0f, 0x14, 0x91, 0x92, 5, 0x1E, 0, 0xD,
                  -5, 0x1E, 0xF, 0xD, &D_843881C0, &D_843881E0, 0xFF, 0xFF, 0, 0xFF, 0x96, 0x32, 0, 0, 0xFF, 0xFF, 0xC8,
                  0x64, 0xC8);
    DoubleTextureTrail_Spawn(spB4, spB0, spAC, spA8, spA4, spA0, 0.0f, 5.0f, 1.2f, 3.0f, 15.0f, 0x14, 0x97, 0x96, 6, 0x14, 0xE,
                  0xF, -3, 0xA, 0, 0xF, &D_84388200, &D_84388220, 0xFF, 0xFF, 0x64, 0x96, 0xFF, 0xFF, 0x64, 0, 0xC8, 0,
                  0, 0, 0);
}

void BattleAnim_StartEffect39SixSlotTrail_Seed(void) {
    static unk_D_843C2C00_024 D_84388240 = {
        0x00000002, 0x00000001, 0x0000000E, 0x00000001, 0x00000002, 0x00000001, 0x00000003, 0x00000001,
    };
    static unk_D_843C2C00_024 D_84388260 = {
        0x00000003, 0x00000005, 0x00000000, 0x00000005, 0x00000000, 0x00000007, 0x00000005, 0x00000007,
    };

    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;

    BattleAnim_CalcVectorAtToDm(&spA4, &spA0, &sp9C, &sp98, &sp94, &sp90);

    sp94 += (0.4f * __cosf((RAND(10) * M_PI_F) / 10));
    sp90 += (0.4f * __cosf((RAND(10) * M_PI_F) / 10));

    sp98 *= 12.0f;
    sp94 *= 12.0f;
    sp90 *= 12.0f;

    BattleAnim_SixSlotTrail_Spawn(0, spA4, spA0, sp9C, sp98, sp94, sp90, 0xFF, 0xFF, 0x64, 0x32, 0xC8, 0xFF, 0x32, 0, 0xFF, 0.4f, 2.0f,
                  5.0f, 0x3C, 0x95, 0x95, 0, 0x14, 0, 0xD, 0, 0x19, 0, 0xD, &D_84388240, &D_84388260);
}

void BattleAnim_StartEffect39CombinedTrail_Init(void) {
    BattleAnim_ResetSharedEffectMatrix();
    DoubleTextureTrail_InitPool();
    BattleAnim_StartEffect39DoubleTextureTrail_Seed();
    BattleAnim_SixSlotTrail_ResetPool();
    BattleAnim_StartEffect39SixSlotTrail_Seed();
}

s32 BattleAnim_StartEffect39CombinedTrail_Update(void) {
    D_843925D4++;
    if ((D_843925D4 % 10) == 0) {
        BattleAnim_StartEffect39SixSlotTrail_Seed();
    }
    BattleAnim_SixSlotTrail_UpdateAll();
    return DoubleTextureTrail_UpdateAll();
}

void BattleAnim_StartEffect39CombinedTrail_Draw(void) {
    gSPMatrix(gDisplayListHead++, &D_84392588, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gDisplayListHead = DoubleTextureTrail_DrawAll(gDisplayListHead);
    gDisplayListHead = BattleAnim_SixSlotTrail_DrawAll(gDisplayListHead);
}
