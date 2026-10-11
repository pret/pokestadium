#include "particle_data_library.h"
#include "battle_hud.h"
#include "geo_render.h"
#include "gfx_buffer.h"
#include "src/matrix.h"

typedef struct unk_D_810047E0 {
    /* 0x00 */ s16 active;
    /* 0x02 */ char unk02[0x2];
    /* 0x04 */ Vec3f position;
    /* 0x10 */ Vec3f velocity;
    /* 0x1C */ Vec3f scale;
    /* 0x28 */ s16 misc;
    /* 0x2A */ char unk2A[0x2];
} unk_D_810047E0; // size = 0x2C

typedef struct unk_arg2_func_81001D80 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08[1];
} unk_arg2_func_81001D80; // size = 0xC

typedef struct unk_D_81003FE0 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04[3];
    /* 0x0A */ s16 unk_0A;
} unk_D_81003FE0; // size = 0xC

typedef struct unk_D_81004160 {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
    /* 0x0C */ u32 unk_0C;
} unk_D_81004160; // size = 0x10

// .data
unk_D_81003FE0 D_81003FE0[18] = {
    { 0x002C, 0x0041, 0x0008, 0x0026, 0x0060, 0x0073 },
    { 0x0020, 0x0041, 0x0008, 0x0026, 0x0060, 0x0073 },
    { 0x0024, 0x0041, 0x0008, 0x0026, 0x0060, 0x0073 },
    { 0x002C, 0x0041, 0x0008, 0x0026, 0x0060, 0x0073 },
    { 0x0020, 0x0041, 0x0008, 0x0026, 0x0060, 0x0073 },
    { 0x002C, 0x0041, 0x0008, 0x0026, 0x0060, 0x0073 },
    { 0x0024, 0x0041, 0x0008, 0x0026, 0x0060, 0x0073 },
    { 0x0020, 0x0041, 0x0008, 0x0026, 0x0060, 0x0073 },
    { 0x0020, 0x0041, 0x0008, 0x0026, 0x0060, 0x0073 },
    { 0x0024, 0x0041, 0x0008, 0x0026, 0x0060, 0x0073 },
    { 0x002C, 0x0041, 0x0008, 0x0026, 0x0060, 0x0073 },
    { 0x0020, 0x0041, 0x0008, 0x0026, 0x0060, 0x0073 },
    { 0x002C, 0x0041, 0x0008, 0x0026, 0x0060, 0x0073 },
    { 0x0020, 0x0041, 0x0008, 0x0026, 0x0060, 0x0073 },
    { 0x002C, 0x0041, 0x0008, 0x0026, 0x0060, 0x0073 },
    { 0x0024, 0x0041, 0x0008, 0x0026, 0x0060, 0x0073 },
    { 0x002C, 0x0041, 0x0008, 0x0026, 0x0060, 0x0073 },
    { 0x0024, 0x0041, 0x0008, 0x0026, 0x0060, 0x0073 },
};
s16 D_810040B8[18] = {
    0x0011, 0x0007, 0x0006, 0x0005, 0x0004, 0x0003, 0x0002, 0x0001, 0x0000,
    0x0010, 0x000F, 0x000E, 0x000D, 0x000C, 0x000B, 0x000A, 0x0009, 0x0008,
};
f32 D_810040DC[12] = {
    0.5f, 0.6499999762f, 0.8000000119f, 0.9499999881f, 0.875f, 0.8000000119f,
    0.7250000238f, 0.6499999762f, 0.5749999881f, 0.5f, 0.4250000119f, 0.349999994f,
};
Vec3f D_8100410C = { 0.0f, 0.0f, 0.0f };
Vec3f D_81004118 = { 0.0f, 0.0f, 0.0f };
Vec3f D_81004124 = { 1.0f, 1.0f, 1.0f };
Vec3f D_81004130 = { 2.0f, 2.0f, 2.0f };
Vec3f D_8100413C = { 0.0f, 10.0f, 0.0f };
Vec3f D_81004148 = { 10000.0f, 10000.0f, 10000.0f };
Vec3f D_81004154 = { -10000.0f, -10000.0f, -10000.0f };
Vec3f D_81004160 = { 1.0f, 1.0f, 1.0f };
static u32 pad_D_8100416C = 0;

// .bss
static unk_D_810047E0 D_810047E0[2][10];
static s32 D_81004B50;
static s32 D_81004B54;


void Particle31_ResetSlot(DisplayObject* arg0, s32 arg1) {
    u8 var_v0 = arg0->effectSlot;
    s32 pad[2];
    Vec3f sp50 = D_8100410C;
    Vec3f sp44 = D_81004118;
    Vec3f sp38 = D_81004124;
    Vec3f sp2C = D_81004130;
    Vec3f sp20 = D_8100413C;
    Vec3f sp14 = D_81004148;
    Vec3f sp8 = D_81004154;

    if (var_v0 == 0xFF) {
        var_v0 = 0;
    } else if (var_v0 == 0xFE) {
        var_v0 = 0;
    }

    D_810047E0[var_v0 & 1][arg1].active = 0;
    D_810047E0[var_v0 & 1][arg1].misc = 0;
    D_810047E0[var_v0 & 1][arg1].position = sp50;
    D_810047E0[var_v0 & 1][arg1].velocity = sp44;
    D_810047E0[var_v0 & 1][arg1].scale = sp38;
}

void Particle31_ResetAllSlots(DisplayObject* arg0) {
    s32 i;

    for (i = 0; i < 10; i++) {
        Particle31_ResetSlot(arg0, i);
    }
}

void Particle31_ResetCounters(void) {
    D_81004B50 = 0;
    D_81004B54 = 0;
}

void Particle31_SpawnSpeciesEffect(unk_D_810047E0* arg0) {
    s32 var_v0;
    Vec3f sp90;
    Vec3f sp84;
    Vec3f sp78;
    s32 var_s1;
    f32 temp_fv0_2;
    Vec3f sp64 = D_81004160;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    u32 pad[2];
    f32 var_fs0;

    var_s1 = 0xA;
    guMtxXFMF(GeoRender_GetRelativeMatrix(-1)->mf, 0, 0, 0, &sp90.x, &sp90.y, &sp90.z);
    guMtxXFMF(GeoRender_GetRelativeMatrix(0)->mf, 0, 0, 0, &sp84.x, &sp84.y, &sp84.z);
    sp60 = D_8006F09C->scale.x;
    sp5C = D_8006F09C->scale.y;
    sp58 = D_8006F09C->scale.z;
    switch (D_8006F09C->objectType) {
    case 0x6D:
    case 0x6E:
        var_fs0 = 0.5f;
        sp64.x = 1.0f;
        sp64.y = 1.0f;
        sp64.z = 1.0f;
        break;
    case 0x92:
        var_fs0 = 1.0f;
        sp64.x = 0.1f;
        sp64.y = 0.1f;
        sp64.z = 0.1f;
        sp84.x += (f32) ((guRandom() % 10) - 5) * sp60;
        sp84.y += (f32) ((guRandom() % 10) - 5) * sp5C;
        sp84.z += (f32) ((guRandom() % 10) - 5) * sp58;
        break;
    case 0x4D:
        var_fs0 = 0.5f;
        sp64.x = 0.002f;
        sp64.y = 0.002f;
        sp64.z = 0.002f;
        sp84.x += (f32) ((guRandom() % 20) - 0xA) * sp60;
        sp84.y += (f32) ((guRandom() % 20) - 0xA) * sp5C;
        sp84.z += (f32) ((guRandom() % 20) - 0xA) * sp58;
        break;
    case 0x4E:
        var_fs0 = 0.5f;
        sp64.x = 0.002f;
        sp64.y = 0.002f;
        sp64.z = 0.002f;
        sp84.x += (f32) ((guRandom() % 20) - 0xA) * sp60;
        sp84.y += (f32) ((guRandom() % 10) - 5) * sp5C;
        sp84.z += (f32) ((guRandom() % 20) - 0xA) * sp58;
        break;
    case 0x90:
        var_fs0 = 0.0f;
        sp64.x = D_810040DC[0];
        sp64.y = D_810040DC[0];
        sp64.z = D_810040DC[0];
        sp84.x += (f32) ((guRandom() % 20) - 0xA) * sp60;
        sp84.y += (f32) ((guRandom() % 20) - 0xA) * sp5C;
        sp84.z += (f32) ((guRandom() % 20) - 0xA) * sp58;
        break;
    case 0x86:
        var_fs0 = 0.0f;
        sp64.x = D_810040DC[0];
        sp64.y = D_810040DC[0];
        sp64.z = D_810040DC[0];
        sp84.x += (f32) ((guRandom() % 60) - 0x1E) * sp60;
        sp84.y += (f32) ((guRandom() % 40) - 0xA) * sp5C;
        sp84.z += (f32) ((guRandom() % 60) - 0x1E) * sp58;
        break;
    case 0x5C:
        var_fs0 = 0.0f;
        var_s1 = 3;
        sp64.x = 20.0f;
        sp64.y = 20.0f;
        sp64.z = 20.0f;
        break;
    default:
        var_fs0 = 0.0f;
        break;
    }
    for (var_v0 = 0; var_v0 < 10; var_v0++) {
        if (var_v0 >= var_s1) {
            break;
        }
        if (arg0->active == 0) {
            sp78.x = sp84.x - sp90.x;
            sp78.y = sp84.y - sp90.y;
            sp78.z = sp84.z - sp90.z;
            temp_fv0_2 = sqrtf((sp78.x * sp78.x) + (sp78.y * sp78.y) + (sp78.z * sp78.z));
            if (temp_fv0_2 > 0.0f) {
                sp78.x /= temp_fv0_2;
                sp78.y /= temp_fv0_2;
                sp78.z /= temp_fv0_2;
            }
            arg0->velocity.x = (f32) (var_fs0 * sp78.x);
            arg0->velocity.y = (f32) (var_fs0 * sp78.y);
            arg0->velocity.z = (f32) (var_fs0 * sp78.z);
            arg0->position = sp84;
            arg0->scale = sp64;
            arg0->misc = 0;
            arg0->active = 1;
            break;
        }
        arg0++;
    }
}

void Particle31_UpdateSpeciesEffectTrigger(unk_D_810047E0* arg0) {
    s32 pad[1];
    s16 temp_v1;
    s32 var_a1;
    s16 temp_a0;
    s32 var_v0;
    s16* var_v1;

    var_a1 = D_8006F09C->transformAnim.frameFixed >> 0x10;
    switch (D_8006F09C->objectType) {
    case 0x6D:
    case 0x6E:
        temp_v1 = D_8006F09C->transformAnim.animationId;
        temp_a0 = D_810040B8[D_81004B54 % 18];
        switch(temp_v1) {
        case 4:
            if (var_a1 == D_81003FE0[temp_a0].unk_02) {
                Particle31_SpawnSpeciesEffect(arg0);
                return;
            }
            break;
        case 3:
                var_v0 = 0;
                var_v1 = &D_81003FE0[temp_a0].unk_00; 
                do {
                    if (var_a1 == var_v1[2]) {
                        Particle31_SpawnSpeciesEffect(arg0);
                    }
                    var_v0 += 2;
                    var_v1 ++;
                } while (var_v0 != 6);
                return;
            break;
        case 2:
            if (var_a1 == D_81003FE0[temp_a0].unk_0A) {
                Particle31_SpawnSpeciesEffect(arg0);
                return;
            }
            break;
        default:
            if (var_a1 == D_81003FE0[temp_a0].unk_00) {
                Particle31_SpawnSpeciesEffect(arg0);
                return;
            }
            return;
        }
        break;
    case 0x92:
        if ((guRandom() % 60) == 0) {
            Particle31_SpawnSpeciesEffect(arg0);
            return;
        }
        break;
    case 0x90:
        if ((guRandom() % 30) == 0) {
            Particle31_SpawnSpeciesEffect(arg0);
            return;
        }
        break;
    case 0x86:
        if ((guRandom() % 7) == 0) {
            Particle31_SpawnSpeciesEffect(arg0);
            return;
        }
        break;
    case 0x5C:
        Particle31_SpawnSpeciesEffect(arg0);
        return;
    case 0x4D:
    case 0x4E:
        if ((guRandom() % 7) == 0) {
            Particle31_SpawnSpeciesEffect(arg0);
        }
        break;
    }
}

Gfx* func_810010BC(Gfx* gfx, unk_D_810047E0* arg1, unk_arg2_func_81001D80* arg2, s16 arg3) {
    Mtx* sp294;
    Mtx sp250;
    Mtx sp210;
    Mtx sp1D0;
    Mtx sp190;
    s16 temp_v1;
    MtxF sp14C;
    MtxF sp10C;
    f32 temp_f0;
    f32 sp104;
    f32 sp100;
    f32 spFC;
    DisplayObject* ptr;

    sp294 = Gfx_AllocDisplayList(0x40);
    MtxF_ExtractScale(&sp14C, &D_8006F088->unk_60.mtxf);
    guMtxF2L(sp14C.mf, &sp1D0);
    if (D_8006F09C->effectSlot == 0xFE) {
        guScale(&sp250, D_8006F09C->scale.x * arg1->scale.x * 0.1f, D_8006F09C->scale.y * arg1->scale.y * 0.1f, D_8006F09C->scale.z * arg1->scale.z * 0.1f);
    } else {
        guScale(&sp250, D_8006F09C->scale.x * arg1->scale.x * 0.1f, D_8006F09C->scale.y * arg1->scale.y * 0.1f, D_8006F09C->scale.z * arg1->scale.z * 0.1f);
    }
    if (D_8006F09C->effectSlot == 0xFF) {
        if ((D_8006F09C->objectType == 0x5C) || (D_8006F09C->objectType == 0x6D) || (D_8006F09C->objectType == 0x6E)) {
            MtxF_Copy(&sp10C, GeoRender_GetRelativeMatrix(0));
            guMtxXFMF(sp10C.mf, 0, 0, 0, &spFC, &sp100, &sp104);
            guTranslate(&sp190, spFC, sp100, sp104);
            guMtxCatL(&sp250, &sp190, sp294);
        } else {
            guTranslate(&sp210, arg1->position.x, arg1->position.y, arg1->position.z);
            guMtxCatL(&sp250, &sp210, sp294);
        }
    } else if (D_8006F09C->objectType == 0x5C) {
        MtxF_Copy(&sp10C, GeoRender_GetRelativeMatrix(0));
        guMtxXFMF(sp10C.mf, 0, 0, 0, &spFC, &sp100, &sp104);
        guTranslate(&sp190, spFC, sp100, sp104);
        guMtxCatL(&sp250, &sp190, sp294);
    } else {
        guTranslate(&sp210, arg1->position.x, arg1->position.y, arg1->position.z);
        guMtxCatL(&sp250, &sp210, sp294);
    }
    guMtxCatL(&sp1D0, sp294, sp294);
    gSPMatrix(gfx++, sp294, G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gfx++, arg2->unk_00);
    switch (D_8006F09C->objectType) {
    case 0x6D:                                      
    case 0x6E:                                      
        gDPLoadTextureBlock_4b(gfx++, arg2->unk_08[arg1->misc / 2], G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                               G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gDPSetPrimColor(gfx++, 0, 0, 0x0A, 0x00, 0x00, 0xC8 - (arg1->misc * 0xD));
        break;
    case 0x5C:
        gDPLoadTextureBlock_4b(gfx++, arg2->unk_08[arg1->misc / 2], G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                               G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gDPSetEnvColor(gfx++, 0x32, 0x14, 0x46, 0x00);
        if (arg1->misc < 0xA) {
            gDPSetPrimColor(gfx++, 0, 0, 0x64, 0x46, 0x82, 0xFF);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 0x64, 0x46, 0x82, 0x28F - (arg1->misc * 0x28));
        }
        break;
    case 0x92:
    case 0x4D:
    case 0x4E:
        gDPLoadTextureBlock_4b(gfx++, arg2->unk_08[arg1->misc / 2], G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                               G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gDPSetPrimColor(gfx++, 0, 0, 0xFF, 0xFF, 0x00, 0xFA - (arg1->misc * 3));
        break;
    case 0x86:                                      
    case 0x90:                                      
        gDPLoadTextureBlock(gfx++, arg2->unk_08[arg1->misc / 2], G_IM_FMT_IA, G_IM_SIZ_16b, 32, 32, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
        if (arg1->misc < 4) {
            gDPSetPrimColor(gfx++, 0, 0, 0xFF, 0xFF, 0xFF, (arg1->misc * 0x14) + 0xB4);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 0xFF, 0xFF, 0xFF, 0x122 - (arg1->misc * 0xA));
        }
        break;
    default:                                        
        gDPLoadTextureBlock_4b(gfx++, arg2->unk_08[arg1->misc / 2], G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                               G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gDPSetPrimColor(gfx++, 0, 0, 0x0A, 0x00, 0x00, 0xC8 - (arg1->misc * 0xD));
        break;
    }
    gSPDisplayList(gfx++, arg2->unk_04);
    gSPPopMatrix(gfx++, G_MTX_MODELVIEW);
    if (func_800325AC() == 0) {
        ptr = D_8006F09C;
        switch (ptr->objectType) {
        case 0x6D:                                  
        case 0x6E:                                  
            if (ptr->effectSlot != 0xFF) {
                arg1->position.y += 0.5f * ptr->scale.y;
                arg1->misc++;
                arg1->scale.x += 0.1f;
                arg1->scale.y += 0.1f;
                arg1->scale.z += 0.1f;
                if (arg1->misc >= 0x10) {
                    arg1->active = 0;
                }
            }
            break;
        case 0x5C:                                  
            if (ptr->effectSlot == 0xFF) {
                arg1->misc += 2;
            } else {
                arg1->misc++;
            }
            if (arg1->misc >= 0x10) {
                arg1->active = 0;
            }
            break;
        case 0x92:                                  
            arg1->position.y += 1.5f * ptr->scale.y;
            arg1->misc++;
            arg1->scale.x += 0.005f;
            arg1->scale.y += 0.005f;
            arg1->scale.z += 0.005f;
            if (arg1->misc >= 0x10) {
                arg1->active = 0;
            }
            break;
        case 0x4D:                                  
            arg1->position.y += 0.75f * ptr->scale.y;
            arg1->misc++;
            arg1->scale.x += 0.005f;
            arg1->scale.y += 0.005f;
            arg1->scale.z += 0.005f;
            if (arg1->misc >= 0x10) {
                arg1->active = 0;
            }
            break;
        case 0x4E:                                  
            arg1->position.y += ptr->scale.y;
            arg1->misc++;
            arg1->scale.x += 0.005f;
            arg1->scale.y += 0.005f;
            arg1->scale.z += 0.005f;
            if (arg1->misc >= 0x10) {
                arg1->active = 0;
            }
            break;
        case 0x90:                                  
            arg1->position.y -= 0.5f * ptr->scale.y;
            arg1->misc++;
            temp_v1 = arg1->misc;
            temp_f0 = D_810040DC[temp_v1 % 12];
            arg1->scale.x = temp_f0;
            arg1->scale.y = temp_f0;
            arg1->scale.z = temp_f0;
            if ((temp_v1 >= 0xC) || (arg1->position.y < 0.0f)) {
                arg1->active = 0;
            }
            break;
        case 0x86:                                  
            arg1->misc++;
            temp_v1 = arg1->misc;
            temp_f0 = D_810040DC[temp_v1 % 12];
            arg1->scale.x = temp_f0;
            arg1->scale.y = temp_f0;
            arg1->scale.z = temp_f0;
            if ((temp_v1 >= 0xC) || (arg1->position.y < 0.0f)) {
                arg1->active = 0;
            }
            break;
        default:                                    
            arg1->misc++;
            if (arg1->misc >= 0x10) {
                arg1->active = 0;
            }
            break;
        }
        arg1->position.x = (f32) (arg1->position.x + arg1->velocity.x);
        arg1->position.y = (f32) (arg1->position.y + arg1->velocity.y);
        arg1->position.z = (f32) (arg1->position.z + arg1->velocity.z);
        arg1->velocity.x *= 0.9f;
        arg1->velocity.y *= 0.9f;
        arg1->velocity.z *= 0.9f;
    }
    D_81004B50 += 1;
    return gfx;
}

Gfx* Particle31_BuildDisplayList(Gfx* gfx, unk_D_810047E0* arg1, unk_arg2_func_81001D80* arg2, s16 arg3) {
    s32 i;

    for (i = 0; i < 10; i++, arg1++) {
        if (arg1->active == 1) {
            gfx = func_810010BC(gfx, arg1, arg2, arg3);
        }
    }
    return gfx;
}

void func_81001E24(s32 arg0, DisplayListState* state) {
    s32 pad[2];
    s32 sp5C;
    unk_D_810047E0* sp1C;
    s32 sp18;
    unk_D_810047E0* temp_a1_3;
    s32 temp_a0;
    s16 temp_a2;
    s16 temp_v0;
    s16 temp_v0_2;
    unk_D_810047E0* temp_a1_2;
    s32 temp_a1;
    Gfx* gfx;    
    s32 var_a3;
    s32 i;
    u8 temp_v1;
    s32 pad2[1];

    sp5C = state->addresses;
    if (arg0 == 2) {
        if (D_81004B54 == 0) {
            state->gfx = Gfx_AllocDisplayList(0x500);
        } else {
            state->gfx = Gfx_AllocDisplayList(0x80);
        }
        gfx = state->gfx;
        temp_v1 = D_8006F09C->effectSlot;
        if (temp_v1 == 0xFF) {
            temp_v0 = D_8006F09C->objectType;
            switch (D_8006F09C->objectType) {
                case 0x5C:
                    Particle31_UpdateSpeciesEffectTrigger(&D_810047E0);
                    if (D_81004B54 == 0) {
                        gfx = Particle31_BuildDisplayList(gfx, &D_810047E0, sp5C, 0);
                    }
                    break;
                case 0x6D:
                case 0x6E:
                    var_a3 = 0;
                    temp_v0_2 = D_8006F09C->transformAnim.animationId;
                    temp_a2 = D_810040B8[D_81004B54 % 18];
                    temp_a1 = (s32) D_8006F09C->transformAnim.frameFixed >> 0x10;
                    switch (temp_v0_2) {
                    case 4:
                        temp_a0 = D_81003FE0[temp_a2].unk_02;
                        if (((u32) temp_a1 >= (u32) temp_a0) && ((u32) temp_a1 < (u32) (temp_a0 + 0xF))) {
                            var_a3 = 1;
                        }
                        break;
                    case 3:
                        for (i = 0; i < 3; i++) {
                            temp_a0 = D_81003FE0[temp_a2].unk_04[i];
                            if (((u32) temp_a1 >= (u32) temp_a0) && ((u32) temp_a1 < (u32) (temp_a0 + 0xF))) {
                                var_a3 = 1;
                            }
                        }
                        break;
                    case 2:
                        temp_a0 = D_81003FE0[temp_a2].unk_0A;
                        if (((u32) temp_a1 >= (u32) temp_a0) && ((u32) temp_a1 < (u32) (temp_a0 + 0xF))) {
                            var_a3 = 1;
                        }
                        break;
                    default:
                        temp_a0 = D_81003FE0[temp_a2].unk_00;
                        if (((u32) temp_a1 >= (u32) temp_a0) && ((u32) temp_a1 < (u32) (temp_a0 + 0xF))) {
                            var_a3 = 1;
                        }
                        break;
                    }
                    if (var_a3 == 1) {
                        temp_a1_2 = &D_810047E0[0][D_81004B50];
                        if (temp_a1_2->active == 1) {
                            gfx = func_810010BC(gfx, temp_a1_2, sp5C, 0);
                        }
                    }
                    break;
            }
        } else if (temp_v1 == 0xFE) {
            if (D_81004B54 == 0) {
                gfx = Particle31_BuildDisplayList(gfx, &D_810047E0, sp5C, 0);
            }
        } else if (((s32) temp_v1 < 2) && (D_81004B50 >= 0) && (D_81004B50 < 0xB)) {
            temp_a1_3 = &D_810047E0[temp_v1 & 1][0];
            sp1C = temp_a1_3;
            sp18 = (s32) temp_v1;
            Particle31_UpdateSpeciesEffectTrigger(temp_a1_3);
            if (D_81004B54 == 0) {
                gfx = Particle31_BuildDisplayList(gfx, temp_a1_3, sp5C, (s16) temp_v1);
            }
        }
        gSPEndDisplayList(gfx);
    }
    D_81004B54 += 1;
}

void Particle31_PackSlotData(u8* arg0) {
    s32 i;
    s16 var_a1;
    s16 var_a2;
    s16 var_a3;
    s16 var_t0;
    s16 var_t1;
    s16 var_t2;
    u8 var_a0;
    u8 var_v0;

    for (i = 0; i < 10; i++) {
        if (D_810047E0[0][i].active == 1) {
            var_v0 = 0x80;
            var_a0 = D_810047E0[0][i].misc & 0x7F;
            var_a1 = D_810047E0[0][i].position.x * 10.0f;
            var_a2 = D_810047E0[0][i].position.y * 10.0f;
            var_a3 = D_810047E0[0][i].position.z * 10.0f;
            var_t0 = D_810047E0[0][i].velocity.x * 10.0f;
            var_t1 = D_810047E0[0][i].velocity.y * 10.0f;
            var_t2 = D_810047E0[0][i].velocity.z * 10.0f;
        } else {
            var_v0 = 0;
            var_a0 = 0;
            var_a1 = 0;
            var_a2 = 0;
            var_a3 = 0;
            var_t0 = 0;
            var_t1 = 0;
            var_t2 = 0;
        }

        if (var_t0) {}
        if (var_t1) {}
        if (var_t2) {}
        
        *arg0++ = (((var_v0 & 0xFF & 0xFF) & 0x80) | (var_a0 & 0x7F));
        *arg0++ = var_a1 & 0xFF;
        *arg0++ = (var_a1 >> 8) & 0xFF;
        *arg0++ = var_a2 & 0xFF;
        *arg0++ = (var_a2 >> 8) & 0xFF;
        *arg0++ = var_a3 & 0xFF;
        *arg0++ = (var_a3 >> 8) & 0xFF;
    }
}

void Particle31_UnpackSlotData(unk_arg0_func_81002260* arg0, u8* arg1) {
    unk_D_810047E0* var_v1;
    f32 var_fv0;
    s16 var_a2;
    s16 var_t0;
    s16 var_a0;
    u16 temp_t1;
    u16 temp_t2;
    u16 temp_t3;
    s32 temp_a3;
    s32 temp_a0;
    s32 i;

    for (i = 0; i < 10; i++) {
        var_v1 = &D_810047E0[0][i];
        temp_a0 = *arg1 & 0x80;
        temp_a3 = *arg1++;
        if (!temp_a0) {
            var_v1->active = 0;
            var_a0 = 0;
            var_a2 = 0;
            var_t0 = 0;
            arg1 += 6;
        } else {
            var_v1->active = 1;
            temp_t1 = (*arg1++);
            temp_t1 |= ((*arg1++) << 8);
            temp_t2 = (*arg1++);
            temp_t2 |= ((*arg1++) << 8);
            temp_t3 = (*arg1++);
            temp_t3 |= ((*arg1++) << 8);
            var_a0 = temp_t1;
            var_a2 = temp_t2;
            var_t0 = temp_t3;
        }
        temp_a3 &= 0x7F;
        var_v1->misc = temp_a3;
        switch (arg0->unk_1A) {
        case 0x92:
            var_fv0 = ((f32) var_v1->misc * 0.005f) + 0.1f;
            break;
        case 0x4D:
        case 0x4E:
            var_fv0 = ((f32) var_v1->misc * 0.005f) + 0.002f;
            break;
        case 0x86:
        case 0x90:
            var_fv0 = D_810040DC[var_v1->misc % 12];
            break;
        case 0x6D:
        case 0x6E:
            var_fv0 = ((f32) var_v1->misc * 0.1f) + 1.0f;
            break;
        case 0x5C:
            var_fv0 = 20.0f;
            break;
        default:
            var_fv0 = 1.0f;
            break;
        }        
        
        var_v1->scale.x = var_fv0;
        var_v1->scale.y = var_fv0;
        var_v1->scale.z = var_fv0;
        var_v1->position.x = var_a0 / 10.0f;
        var_v1->position.y = var_a2 / 10.0f;
        var_v1->position.z = var_t0 / 10.0f;
    };
}
