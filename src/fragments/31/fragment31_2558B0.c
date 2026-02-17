#include "fragment31.h"
#include "32D10.h"
#include "12D80.h"
#include "6A40.h"

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
    /* 0x04 */ char unk04[0x4];
    /* 0x08 */ s32 unk_08;
} unk_arg2_func_81001D80; // size = 0xC

typedef struct unk_D_81003FE0 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
} unk_D_81003FE0; // size = 0xC

extern unk_D_81003FE0 D_81003FE0[];
extern unk_D_81003FE0 D_81003FE2[];
extern unk_D_81003FE0 D_81003FEA[];
extern s16 D_810040B8[18];
extern unk_D_810047E0 D_810047E0[2][10];
extern unk_D_810047E0 D_81004998[2][10];
extern s32 D_81004B50;
extern s32 D_81004B54;
extern s16 D_81004B60;
extern f32 D_810040DC[12];
extern Vec3f D_81004160;
extern s32 D_81004170;

// Matching, just needs data to be done
#ifdef NON_MATCHING
void func_810005F0(unk_D_86002F58_004_000* arg0, s32 arg1) {
    u8 var_v0 = arg0->unk_0A6;
    s32 pad[2];
    Vec3f sp50 = { 0.0f, 0.0f, 0.0f };
    Vec3f sp44 = { 0.0f, 0.0f, 0.0f };
    Vec3f sp38 = { 1.0f, 1.0f, 1.0f };
    Vec3f sp2C = { 2.0f, 2.0f, 2.0f };
    Vec3f sp20 = { 0.0f, 10.0f, 0.0f };
    Vec3f sp14 = { 10000.0f, 10000.0f, 10000.0f };
    Vec3f sp8 = { -10000.0f, -10000.0f, -10000.0f };

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
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_2558B0/func_810005F0.s")
#endif

void func_810007A8(unk_D_86002F58_004_000* arg0) {
    s32 i;

    for (i = 0; i < 10; i++) {
        func_810005F0(arg0, i);
    }
}

void func_810007F8(void) {
    D_81004B50 = 0;
    D_81004B54 = 0;
}

#ifdef NON_MATCHING
void func_8100080C(unk_D_810047E0* arg0) {
    s32 var_s1;
    Vec3f sp90;
    Vec3f sp84;
    Vec3f sp78;
    Vec3f sp64;
    f32 sp60;
    f32 sp58;
    f32 temp_fa1;
    f32 temp_ft5;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 sp5C;
    f32 temp_fv1;
    f32 var_fs0;
    f32 var_ft4;
    f32 var_ft5;
    f32 var_fv1;
    s32 var_v0;
    unk_D_810047E0* var_s0;

    var_s0 = arg0;
    var_s1 = 0xA;
    sp64.x = D_81004160.x;
    sp64.y = D_81004160.y;
    sp64.z = D_81004160.z;
    guMtxXFMF(func_800123D4(-1)->mf, 0, 0, 0, &sp90.x, &sp90.y, &sp90.z);
    guMtxXFMF(func_800123D4(0)->mf, 0, 0, 0, &sp84.x, &sp84.y, &sp84.z);
    temp_fv1 = D_8006F09C->unk_030.x;
    sp5C = D_8006F09C->unk_030.y;
    sp58 = D_8006F09C->unk_030.z;
    switch (D_8006F09C->unk_01A) {
    case 0x6D:
    case 0x6E:
        var_fs0 = 0.5f;
        sp64.x = 0x3F800000;
        sp64.y = 0x3F800000;
        sp64.z = 0x3F800000;
        break;
    case 0x92:
        var_fs0 = 1.0f;
        sp60 = temp_fv1;
        sp64.x = 0x3DCCCCCD;
        sp64.y = 0x3DCCCCCD;
        sp64.z = 0x3DCCCCCD;
        sp84.x += (f32) ((guRandom() % 10) - 5) * temp_fv1;
        sp84.y += (f32) ((guRandom() % 10) - 5) * sp5C;
        sp84.z += (f32) ((guRandom() % 10) - 5) * sp58;
        break;
    case 0x4D:
        var_fs0 = 0.5f;
        sp60 = temp_fv1;
        sp64.x = 0x3B03126F;
        sp64.y = 0x3B03126F;
        sp64.z = 0x3B03126F;
        sp84.x += (f32) ((guRandom() % 20) - 0xA) * temp_fv1;
        sp84.y += (f32) ((guRandom() % 20) - 0xA) * sp5C;
        sp84.z += (f32) ((guRandom() % 20) - 0xA) * sp58;
        break;
    case 0x4E:
        var_fs0 = 0.5f;
        sp60 = temp_fv1;
        sp64.x = 0x3B03126F;
        sp64.y = 0x3B03126F;
        sp64.z = 0x3B03126F;
        sp84.x += (f32) ((guRandom() % 20) - 0xA) * temp_fv1;
        sp84.y += (f32) ((guRandom() % 10) - 5) * sp5C;
        sp84.z += (f32) ((guRandom() % 20) - 0xA) * sp58;
        break;
    case 0x90:
        var_fs0 = 0.0f;
        sp60 = temp_fv1;
        sp64.x = D_810040DC[0];
        sp64.y = D_810040DC[1];
        sp64.z = D_810040DC[2];
        sp84.x += (f32) ((guRandom() % 20) - 0xA) * temp_fv1;
        sp84.y += (f32) ((guRandom() % 20) - 0xA) * sp5C;
        sp84.z += (f32) ((guRandom() % 20) - 0xA) * sp58;
        break;
    case 0x86:
        var_fs0 = 0.0f;
        sp60 = temp_fv1;
        sp64.x = D_810040DC[0];
        sp64.y = D_810040DC[1];
        sp64.z = D_810040DC[2];
        sp84.x += (f32) ((guRandom() % 60) - 0x1E) * temp_fv1;
        sp84.y += (f32) ((guRandom() % 40) - 0xA) * sp5C;
        sp84.z += (f32) ((guRandom() % 60) - 0x1E) * sp58;
        break;
    case 0x5C:
        var_fs0 = 0.0f;
        var_s1 = 3;
        sp64.x = 0x41A00000;
        sp64.y = 0x41A00000;
        sp64.z = 0x41A00000;
        break;
    default:
        var_fs0 = 0.0f;
        break;
    }
    var_v0 = 0;
loop_11:
    var_v0 += 1;
    if (var_v0 < var_s1) {
        if (var_s0->active == 0) {
            temp_fv0 = sp84.x - sp90.x;
            temp_ft5 = sp84.y - sp90.y;
            sp78.x = temp_fv0;
            temp_fa1 = sp84.z - sp90.z;
            sp78.y = temp_ft5;
            sp78.z = temp_fa1;
            temp_fv0_2 = sqrtf((temp_fv0 * temp_fv0) + (temp_ft5 * temp_ft5) + (temp_fa1 * temp_fa1));
            var_fv1 = sp78.z;
            var_ft4 = sp78.x;
            var_ft5 = temp_ft5;
            if (temp_fv0_2 > 0.0f) {
                var_ft4 /= temp_fv0_2;
                var_ft5 /= temp_fv0_2;
                var_fv1 /= temp_fv0_2;
            }
            var_s0->velocity.x = (f32) (var_fs0 * var_ft4);
            var_s0->velocity.y = (f32) (var_fs0 * var_ft5);
            var_s0->velocity.z = (f32) (var_fs0 * var_fv1);
            var_s0->position.x = sp84.x;
            var_s0->position.y = sp84.y;
            var_s0->position.z = sp84.z;
            var_s0->scale.x = sp64.x;
            var_s0->scale.y = sp64.y;
            var_s0->scale.z = sp64.z;
            var_s0->misc = 0;
            var_s0->active = 1;
            return;
        }
        var_s0 += 0x2C;
        if (var_v0 == 0xA) {

        } else {
            goto loop_11;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_2558B0/func_8100080C.s")
#endif

#ifdef NON_MATCHING
void func_81000E78(unk_D_810047E0* arg0) {
    s16 temp_a0;
    unk_D_81003FE0* var_v1;
    s16 temp_v1;
    s32 var_a1;
    s32 var_v0;

    var_a1 = D_8006F09C->unk_040.unk_08 >> 0x10;
    switch (D_8006F09C->unk_01A) {
    case 0x6D:
    case 0x6E:
        temp_v1 = D_8006F09C->unk_040.unk_00;
        temp_a0 = D_810040B8[D_81004B54 % 18];
        if (temp_v1 != 2) {
            var_v0 = 0;
            if (temp_v1 != 3) {
                if (temp_v1 == 4) {
                    if (var_a1 == D_81003FE2[temp_a0].unk_00) {
                        func_8100080C(arg0);
                        return;
                    }
                } else if (var_a1 == D_81003FE0[temp_a0].unk_00) {
                    func_8100080C(arg0);
                    return;
                }
            } else {
                var_v1 = &D_81003FE0[temp_a0]; 
                do {
                    if (var_a1 == var_v1->unk_04) {
                        func_8100080C(arg0);
                    }
                    var_v0 += 2;
                    var_v1 += 2;
                } while (var_v0 != 6);
                return;
            }
        } else {
            if (var_a1 == D_81003FEA[temp_a0].unk_00) {
                func_8100080C(arg0);
                return;
            }
        default:
            return;
        }
        break;
    case 0x92:
        if ((guRandom() % 60) == 0) {
            func_8100080C(arg0);
            return;
        }
        break;
    case 0x90:
        if ((guRandom() % 30) == 0) {
            func_8100080C(arg0);
            return;
        }
        break;
    case 0x86:
        if ((guRandom() % 7) == 0) {
            func_8100080C(arg0);
            return;
        }
        break;
    case 0x5C:
        func_8100080C(arg0);
        return;
    case 0x4D:
    case 0x4E:
        if ((guRandom() % 7) == 0) {
            func_8100080C(arg0);
        }
        break;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_2558B0/func_81000E78.s")
#endif

Gfx* func_810010BC(Gfx*, unk_D_810047E0*, unk_arg2_func_81001D80*, s16);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_2558B0/func_810010BC.s")

Gfx* func_81001D80(Gfx* gfx, unk_D_810047E0* arg1, unk_arg2_func_81001D80* arg2, s16 arg3) {
    s32 i;

    for (i = 0; i < 10; i++, arg1++) {
        if (arg1->active == 1) {
            gfx = func_810010BC(gfx, arg1, arg2, arg3);
        }
    }
    return gfx;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_2558B0/func_81001E24.s")

#ifdef NON_MATCHING
void func_81002174(unk_D_83402EE0_00A* arg0) {
    s32 i;
    s16 var_a1;
    s16 var_a2;
    s16 var_a3;
    u8 var_a0;
    u8 var_v0;

    for (i = 0; i != 10; ) {
        if (D_810047E0[0][i].active == 1) {
            var_v0 = 0x80;
            var_a0 = D_810047E0[0][i].misc & 0x7F;
            var_a1 = D_810047E0[0][i].position.x * 10.0f;
            var_a2 = D_810047E0[0][i].position.y * 10.0f;
            var_a3 = D_810047E0[0][i].position.z * 10.0f;
        } else {
            var_v0 = 0;
            var_a0 = 0;
            var_a1 = 0;
            var_a2 = 0;
            var_a3 = 0;
        }
        
        arg0->unk_00[0] = ((var_v0 & 0x80) | (var_a0  & 0x7F));
        i++;
        arg0->unk_00[1] = var_a1;
        arg0->unk_00[2] = (var_a1 >> 8);
        arg0->unk_00[3] = var_a2;
        arg0->unk_00[4] = (var_a2 >> 8);
        arg0->unk_00[5] = var_a3;
        arg0->unk_00[6] = (var_a3 >> 8);
        arg0 += 1;
    }

    // FAKE - Stops unroll
    i = 0;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_2558B0/func_81002174.s")
#endif

#ifdef NON_MATCHING
void func_81002260(unk_arg0_func_81002260* arg0, unk_arg0_func_81002174* arg1) {
    unk_D_810047E0* temp_v0;
    f32 var_fv0;
    s16 var_a2;
    s16 var_t0;
    s32 temp_a0;
    s32 var_a0;
    s32 i;
    u8 temp_a3;
    unk_arg0_func_81002174* temp_a1;

    for (i = 0; i < 10; i++) {
        temp_a3 = arg1->unk_00;
        temp_a1 = arg1 + 1;
        if (!(temp_a3 & 0x80)) {
            D_810047E0[0][i].active = 0;
            var_a0 = 0;
            var_a2 = 0;
            var_t0 = 0;
            arg1 = temp_a1 + 6;
        } else {
            D_810047E0[0][i].active = 1;
            temp_a0 = ((arg1->unk_01 | (temp_a1->unk_01 << 8)) & 0xFFFF) << 0x10;
            arg1 = temp_a1 + 6;
            var_a0 = temp_a0 >> 0x10;
            var_a2 = (temp_a1->unk_02 | (temp_a1->unk_03 << 8)) & 0xFFFF;
            var_t0 = (temp_a1->unk_04 | (temp_a1->unk_05 << 8)) & 0xFFFF;
        }
        D_810047E0[0][i].misc = (s16) (temp_a3);
        switch (arg0->unk_1A) {
        case 0x92:
            var_fv0 = ((f32) D_810047E0[0][i].misc * 0.005f) + 0.1f;
            break;
        case 0x4D:
        case 0x4E:
            var_fv0 = ((f32) D_810047E0[0][i].misc * 0.005f) + 0.002f;
            break;
        case 0x86:
        case 0x90:
            var_fv0 = D_810040DC[D_810047E0[0][i].misc % 12];
            break;
        case 0x6D:
        case 0x6E:
            var_fv0 = ((f32) D_810047E0[0][i].misc * 0.1f) + 1.0f;
            break;
        case 0x5C:
            var_fv0 = 20.0f;
            break;
        default:
            var_fv0 = 1.0f;
            break;
        }
        // var_v1 += 0x2C;
        temp_v0->scale.x = var_fv0;
        temp_v0->scale.y = var_fv0;
        temp_v0->scale.z = var_fv0;
        temp_v0->position.x = (f32) ((f32) var_a0 / 10.0f);
        temp_v0->position.y = (f32) ((f32) var_a2 / 10.0f);
        temp_v0->position.z = (f32) ((f32) var_t0 / 10.0f);
    };
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_2558B0/func_81002260.s")
#endif
