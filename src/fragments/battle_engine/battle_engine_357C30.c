#include "battle_engine.h"
#include "gfx_buffer.h"
#include "geo_render.h"
#include "gallery.h"
#include "battle_hud.h"

static s16 D_843C3500;
static unk_D_843C3508 D_843C3508[6];

void BattleAnim_SixSlotTrail_ResetPool(void) {
    s32 i;
    s32 j;
    unk_D_843C3508* var_v0;
    unk_D_843C3508_0A4* var_a0;
    unk_D_84389CE0 sp0 = {
        { 0, 0, 0, 0 },
        0,
    };

    D_843C3500 = 0;

    var_v0 = &D_843C3508[0];
    for (i = 0; i < 6; i++, var_v0++) {
        var_v0->unk_000 = 0;
        var_v0->unk_004 = 0;
        var_v0->unk_006 = 0;
        var_v0->unk_008 = sp0;
        var_v0->unk_00D = sp0;

        var_a0 = &var_v0->unk_0A4[0];
        for (j = 0; j < 20; j++, var_a0++) {
            var_a0->unk_00 = 0.0f;
            var_a0->unk_04 = 1.0f;
            var_a0->unk_08 = 0.0f;
            var_a0->unk_0C.x = 0.0f;
            var_a0->unk_0C.y = 0.0f;
            var_a0->unk_0C.z = 0.0f;
            var_a0->unk_18.x = 0.0f;
            var_a0->unk_18.y = 0.0f;
            var_a0->unk_18.z = 0.0f;
        }
    }
}

void BattleAnim_SixSlotTrail_Spawn(s16 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, u8 arg7, u8 arg8, u8 arg9,
                   u8 argA, u8 argB, u8 argC, u8 argD, u8 argE, u8 argF, f32 arg10, f32 arg11, f32 arg12, s16 arg13,
                   s32 arg14, s32 arg15, s16 arg16, s16 arg17, s16 arg18, s16 arg19, s16 arg1A, s16 arg1B, s16 arg1C,
                   s16 arg1D, unk_D_843C2C00_024* arg1E, unk_D_843C2C00_024* arg1F) {
    unk_D_843C3508* var_v0;
    unk_D_843C3508_0A4* var_v1_2;
    s32 i;
    s32 j;
    Vec3f spC;
    Vec3f sp0;

    var_v0 = &D_843C3508[0];
    spC.x = arg1;
    spC.y = arg2;
    spC.z = arg3;
    sp0.x = arg4;
    sp0.y = arg5;
    sp0.z = arg6;

    for (i = 0; i < 6; i++, var_v0++) {
        if (var_v0->unk_000 == 0) {
            var_v0->unk_000 = 1;
            var_v0->unk_002 = arg0;
            var_v0->unk_004 = 0;
            var_v0->unk_006 = arg13;
            var_v0->unk_080 = arg12;
            var_v0->unk_084 = arg10;
            var_v0->unk_020 = arg14;
            var_v0->unk_024 = arg15;
            var_v0->unk_068.unk_00 = 0;
            var_v0->unk_068.unk_02 = 0;
            var_v0->unk_074.unk_00 = 0;
            var_v0->unk_074.unk_02 = 0;
            var_v0->unk_068.unk_04 = arg16;
            var_v0->unk_068.unk_06 = arg17;
            var_v0->unk_074.unk_04 = arg1A;
            var_v0->unk_074.unk_06 = arg1B;
            var_v0->unk_068.unk_08 = arg18;
            var_v0->unk_068.unk_0A = arg19;
            var_v0->unk_074.unk_08 = arg1C;
            var_v0->unk_074.unk_0A = arg1D;
            var_v0->unk_028 = *arg1E;
            var_v0->unk_048 = *arg1F;
            var_v0->unk_01C = 0x46;
            var_v0->unk_014 = 1.0f;
            var_v0->unk_018 = 1.0f;
            var_v0->unk_008.unk_00.r = arg7;
            var_v0->unk_008.unk_00.g = arg8;
            var_v0->unk_008.unk_00.b = arg9;
            var_v0->unk_008.unk_00.a = argA;
            var_v0->unk_008.unk_04 = argB;
            var_v0->unk_00D.unk_00.r = argC;
            var_v0->unk_00D.unk_00.g = argD;
            var_v0->unk_00D.unk_00.b = argE;
            var_v0->unk_00D.unk_00.a = argF;

            var_v1_2 = &var_v0->unk_0A4[0];
            for (j = 0; j < 20; j++, var_v1_2++) {
                var_v1_2->unk_00 = 2.0f * j;
                var_v1_2->unk_04 = arg11;
                var_v1_2->unk_08 = 0.0f;
                var_v1_2->unk_0C = spC;
                var_v1_2->unk_18 = sp0;
            }
            break;
        }
    }
}

void BattleAnim_SixSlotTrail_ComputeCameraRelativeOffset(s32 arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3, f32 arg4, UNUSED f32 arg5, UNUSED f32 arg6,
                   UNUSED f32 arg7) {
    UNUSED s32 pad[36];
    CameraNode* temp_v0 = BattleAnim_GetCameraContext();
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp60;
    f32 sp5C;
    f32 sp58;

    sp60 = arg2->x - temp_v0->view.eyePosition.x;
    sp5C = arg2->y - temp_v0->view.eyePosition.y;
    sp58 = arg2->z - temp_v0->view.eyePosition.z;

    sp6C = arg1->x;
    sp68 = arg1->y;
    sp64 = arg1->z;

    Vec3f_CrossProductComponents(sp6C, sp68, sp64, sp60, sp5C, sp58, &sp54, &sp50, &sp4C);

    Vec3f_NormalizeComponents(&sp54, &sp50, &sp4C);

    switch (arg0) {
        case 0:
            arg3->x = arg4 * sp54;
            arg3->y = arg4 * sp50;
            arg3->z = arg4 * sp4C;
            break;

        case 1:
            arg3->x = -arg4 * sp54;
            arg3->y = -arg4 * sp50;
            arg3->z = -arg4 * sp4C;
            break;
    }
}

void BattleAnim_SixSlotTrail_ComputeRotatedOffset(f32 arg0, Vec3f* arg1, Vec3f* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    UNUSED Mtx sp70;
    Mtx sp30;
    UNUSED s32 pad;

    guRotateF(&sp30, (360.0f * arg0) / 6.2831855f, 1.0f, 0.0f, 0.0f);
    guMtxXFMF(&sp30, 0.0f, 0.0f, arg3, &arg2->x, &arg2->y, &arg2->z);
}

void BattleAnim_SixSlotTrail_UpdateSlot(unk_D_843C3508* arg0) {
    unk_D_843C3508_0A4* var_s0;
    s32 spA8;
    s32 i;
    Vec3f sp98;
    UNUSED s32 pad;
    f32 temp_fs1;
    f32 temp_fs1_2;
    f32 temp_fs2;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_s3;
    s32 temp_s4;

    var_s0 = &arg0->unk_0A4[0];
    for (i = 0; i < 20; i++, var_s0++) {
        if (var_s0->unk_00 > 0.0) {
            temp_s3 = RAND(20) + 2;
            temp_s2 = RAND(10) + 4;
            temp_s4 = RAND(20) + 2;
            temp_s1 = RAND(10) + 4;

            temp_fs1 = __sinf((((spA8 + temp_s3) % temp_s2) * 6.2831854820251465) / temp_s2);
            temp_fs2 =
                __sinf((((spA8 + temp_s4) % (temp_s1 + 20)) * 6.2831854820251465) / (temp_s1 + 20)) * (10.0 * temp_fs1);
            temp_fs1_2 = __sinf((((spA8 + temp_s4) % temp_s1) * 6.2831854820251465) / temp_s1) * 10.0;
            BattleAnim_GetSecondaryOwnerAnchorPosition(&sp98);
            var_s0->unk_0C.x = sp98.x;
            var_s0->unk_0C.y = sp98.y + temp_fs2;
            var_s0->unk_0C.z = sp98.z + temp_fs1_2;
            var_s0->unk_00 -= 1.0;
        } else {
            var_s0->unk_0C.x += var_s0->unk_18.x;
            var_s0->unk_0C.y += var_s0->unk_18.y;
            var_s0->unk_0C.z += var_s0->unk_18.z;
            var_s0->unk_08 += arg0->unk_084;
            var_s0->unk_04 += 3.0f;
            if (arg0->unk_080 < var_s0->unk_04) {
                var_s0->unk_04 = arg0->unk_080;
            }
        }
    }
}

s32 BattleAnim_SixSlotTrail_UpdateAll(void) {
    f32 temp_fv0;
    s32 i;
    s32 var_s2;
    unk_D_843C3508* var_s0;

    D_843C3500++;
    var_s2 = 0;
    var_s0 = &D_843C3508[0];

    for (i = 0; i < 6; i++, var_s0++) {
        if (var_s0->unk_000 == 1) {
            var_s0->unk_004++;
            if (var_s0->unk_006 < var_s0->unk_004) {
                var_s0->unk_000 = 0;
            } else {
                BattleAnim_SixSlotTrail_UpdateSlot(var_s0);
                var_s2++;
            }

            if (var_s0->unk_01C < D_843C3500) {
                s16 tmp = D_843C3500 - var_s0->unk_01C;

                temp_fv0 = tmp * 0.02f;
                var_s0->unk_014 = 1.0f - temp_fv0;
                var_s0->unk_018 = 1.0f - temp_fv0;

                if (temp_fv0 > 1.0f) {
                    var_s0->unk_014 = 0.0f;
                }

                if (var_s0->unk_018 < 0.0f) {
                    var_s0->unk_018 = 0.0f;
                }
            }
        }
    }

    if (var_s2 > 0) {
        return 0;
    }
    return -1;
}

Gfx* BattleAnim_SixSlotTrail_DrawSegments(Gfx* arg0, unk_D_843C3508* arg1) {
    s32 i;
    Vtx* temp_v0 = arg1->unk_088;

    for (i = 0; i < 19; i++) {
        gSPVertex(arg0++, temp_v0, 4, 0);
        gSP2Triangles(arg0++, 0, 2, 1, 0, 1, 2, 3, 0);
        temp_v0 += 2;
    }

    return arg0;
}

Gfx* BattleAnim_SixSlotTrail_LoadTextures(Gfx* arg0, unk_D_843C3508* arg1) {
    unk_D_843C2C00_064* ptr;
    UNUSED s32 pad[2];

    ptr = &arg1->unk_068;
    gDPLoadTextureTile_4b(arg0++, sBattleAnimAssetPointers[arg1->unk_020], G_IM_FMT_I, 32, 0, 0, 0, 31, 31, 0,
                          G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, ptr->unk_08, ptr->unk_0A);
    gDPSetTileSize(arg0++, G_TX_RENDERTILE, ptr->unk_00, ptr->unk_02, (ptr->unk_00 + 31) << 2, (ptr->unk_02 + 31) << 2);

    ptr = &arg1->unk_074;
    gDPLoadMultiTile_4b(arg0++, sBattleAnimAssetPointers[arg1->unk_024], 0x0100, 1, G_IM_FMT_I, 32, 0, 0, 0, 31, 31, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, ptr->unk_08, ptr->unk_0A);
    gDPSetTileSize(arg0++, 1, ptr->unk_00, ptr->unk_02, (ptr->unk_00 + 31) << 2, (ptr->unk_02 + 31) << 2);

    return arg0;
}

Gfx* BattleAnim_SixSlotTrail_DrawAll(Gfx* arg0) {
    static Gfx D_84389CE8[] = {
        gsDPPipeSync(),
        gsDPSetCycleType(G_CYC_2CYCLE),
        gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                              G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA),
        gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH),
        gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
        gsDPPipeSync(),
        gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_SURF2),
        gsDPSetTexturePersp(G_TP_PERSP),
        gsDPSetTextureDetail(G_TD_CLAMP),
        gsDPSetTextureLOD(G_TL_TILE),
        gsDPSetTextureLUT(G_TT_NONE),
        gsDPSetTextureConvert(G_TC_FILT),
        gsDPSetTextureFilter(G_TF_BILERP),
        gsSPEndDisplayList(),
    };

    s32 i;
    unk_D_843C3508* var_s6;
    unk_D_843C3508_0A4* var_s0;
    s32 j;
    s32 k;
    Vec3f spF0;
    Vtx* var_s1;
    s32 pad[12];

    BattleAnim_GetCameraContext();

    var_s6 = &D_843C3508[0];
    for (i = 0; i < 6; i++, var_s6++) {
        if (var_s6->unk_000 == 1) {
            var_s0 = &var_s6->unk_0A4[0];

            var_s6->unk_088 = Gfx_AllocDisplayList(sizeof(Vtx) * 40);
            var_s1 = var_s6->unk_088;

            for (j = 0; j < 20; j++, var_s0++) {
                for (k = 0; k < 2; k++) {
                    switch (var_s6->unk_002) {
                        case 0:
                            if (var_s0->unk_00 <= 0.0) {
                                BattleAnim_SixSlotTrail_ComputeRotatedOffset(var_s0->unk_08 + ((k % 2) * 3.1415927f), &var_s0->unk_18, &spF0,
                                              var_s0->unk_04, 1.0f, 0.0f, 0.0f);
                            }
                            break;

                        case 1:
                            if (var_s0->unk_00 <= 0.0) {
                                BattleAnim_SixSlotTrail_ComputeCameraRelativeOffset(k % 2, &var_s0->unk_18, &var_s0->unk_0C, &spF0, var_s0->unk_04, 1.0f,
                                              0.0f, 0.0f);
                            }
                            break;
                    }

                    var_s1->v.ob[0] = var_s0->unk_0C.x + spF0.x;
                    var_s1->v.ob[1] = var_s0->unk_0C.y + spF0.y;
                    var_s1->v.ob[2] = var_s0->unk_0C.z + spF0.z;

                    var_s1->v.tc[0] = (k % 2) << 0xA;
                    var_s1->v.tc[1] = (j * 0x400) / 20;

                    var_s1->v.cn[0] = 0xFF;
                    var_s1->v.cn[1] = 0xFF;
                    var_s1->v.cn[2] = 0xFF;
                    var_s1->v.cn[3] = 0x40;
                    var_s1++;
                }
            }

            gSPDisplayList(arg0++, D_84389CE8);

            Gfx_SetCombineMode(
                arg0++, var_s6->unk_028.unk_00, var_s6->unk_028.unk_04, var_s6->unk_028.unk_08, var_s6->unk_028.unk_0C,
                var_s6->unk_028.unk_10, var_s6->unk_028.unk_14, var_s6->unk_028.unk_18, var_s6->unk_028.unk_1C,
                var_s6->unk_048.unk_00, var_s6->unk_048.unk_04, var_s6->unk_048.unk_08, var_s6->unk_048.unk_0C,
                var_s6->unk_048.unk_10, var_s6->unk_048.unk_14, var_s6->unk_048.unk_18, var_s6->unk_048.unk_1C);

            gDPSetPrimColor(arg0++, 0, var_s6->unk_008.unk_04, var_s6->unk_008.unk_00.r, var_s6->unk_008.unk_00.g,
                            var_s6->unk_008.unk_00.b, (u8)(var_s6->unk_008.unk_00.a * var_s6->unk_014));
            gDPSetEnvColor(arg0++, var_s6->unk_00D.unk_00.r, var_s6->unk_00D.unk_00.g, var_s6->unk_00D.unk_00.b,
                           (u8)(var_s6->unk_00D.unk_00.a * var_s6->unk_018));

            arg0 = BattleAnim_SixSlotTrail_LoadTextures(arg0, var_s6);

            gDPPipeSync(arg0++);

            arg0 = BattleAnim_SixSlotTrail_DrawSegments(arg0, var_s6);
        }
    }

    return arg0;
}
