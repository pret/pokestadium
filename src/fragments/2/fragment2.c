#include "fragment2.h"
#include "src/1CF30.h"
#include "src/2E110.h"
#include "src/controller.h"

extern u32 D_878067F0[];
extern u32 D_87807690[];
extern u32 D_87808530[];
extern u32 D_878093D0[];
extern u32 D_8780B110[];
extern u32 D_8780BFB0[];
extern u32 D_8780CE50[];
extern u32 D_8780DCF0[];
extern u32 D_8780A270[];
extern u32 D_878064F0[];
extern u32 D_87806670[];
extern u32 D_878065B0[];
extern u32 D_87806730[];

char** D_87806330 = NULL;

static s32 D_8780FA20;
static s32 D_8780FA24;
u16 D_8780FA28;
s16 D_8780FA2A;
s16 D_8780FA2C;

s16 D_8780FA30[4];
s16 D_8780FA38;
s16 D_8780FA3A;
s16 D_8780FA40[4];
s16 D_8780FA48;

static s32 pad_D_8780FA4C;

s16 D_8780FA50;
s16 D_8780FA52[2][4];
s16 D_8780FA68[4];

void func_87800020(void) {
    func_8002D510();
    D_87806330 = func_8002D5AC(0x1D);
    D_8780FA24 = func_8002D5AC(0x14);
}

void func_8780005C(void) {
    static s32 D_87806334 = 0;

    s32 sp24;
    s16 temp_s0;

    if (!(Cont_GetControllerBits() & 1)) {
        sp24 = func_8001F5B0(4, 0, func_8002D7C0(NULL, 0, D_8780FA24, 0));
        temp_s0 = 0x50 - D_87806334;

        gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 16, 0, 304, 240);

        func_8001F3F4();
        func_8001EBE0(4, 0);
        func_8001F1E8(temp_s0, 0xB3, func_8002D7C0(NULL, 0, D_8780FA24, 0));

        temp_s0 += sp24 + 0x1E;
        if (temp_s0 < 0x140) {
            func_8001F1E8(temp_s0, 0xB3, func_8002D7C0(NULL, 0, D_8780FA24, 0));
        }

        func_8001F444();

        gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 0, 320, 240);

        D_87806334++;
        if (D_87806334 >= (sp24 + 0x50)) {
            D_87806334 = 0x32;
        }
    }
}

void func_878001D0(void) {
    D_8780FA20++;
}

u32 func_878001E8(s32 arg0) {
    u32 temp_a0 = guRandom() + D_8780FA20;
    u32 var_v1;

    if (arg0 == 0) {
        var_v1 = 0;
    } else {
        var_v1 = (temp_a0 / 10) % arg0;
    }

    return var_v1;
}

void func_8780024C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    UNUSED s32 pad;
    s32 spF0 = arg2 - 2;
    s32 temp_lo = ((arg4 - arg3) * spF0) / arg4;
    s32 sp1C = (arg2 - temp_lo) - 2;

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    gDPPipeSync(gDisplayListHead++);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 0, 0, 0, 0);
    gDPSetCombineMode(gDisplayListHead++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);

    gSPTextureRectangle(gDisplayListHead++, (arg0 - 2) << 2, (arg1 - 2) << 2, (arg0 + arg2 + 8) << 2, (arg1 + 16) << 2,
                        G_TX_RENDERTILE, 0, 0, 0, 0);

    gDPSetCombineMode(gDisplayListHead++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPLoadTextureBlock(gDisplayListHead++, D_878064F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 12, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    gSPTextureRectangle(gDisplayListHead++, arg0 << 2, arg1 << 2, (arg0 + 2) << 2, (arg1 + 0xC) << 2, G_TX_RENDERTILE,
                        0, 0, 0x0400, 0x0400);

    gDPLoadTextureBlock(gDisplayListHead++, D_87806670, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 12, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    gSPTextureRectangle(gDisplayListHead++, ((arg0 + spF0) + 2) << 2, arg1 << 2, ((arg0 + spF0) + 4) << 2,
                        (arg1 + 0xC) << 2, G_TX_RENDERTILE, 0x00C0, 0, 0x0400, 0x0400);

    if (sp1C > 0) {
        gDPLoadTextureBlock(gDisplayListHead++, D_87806730, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 12, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gDisplayListHead++, (arg0 + 2) << 2, arg1 << 2, ((arg0 + 2) + sp1C) << 2, (arg1 + 0xC) << 2,
                            G_TX_RENDERTILE, 0, 0, 0, 0x0400);
    }

    if (temp_lo > 0) {
        gDPLoadTextureBlock(gDisplayListHead++, D_878065B0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 12, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gDisplayListHead++, ((arg0 + 2) + sp1C) << 2, arg1 << 2,
                            (((arg0 + 2) + sp1C) + temp_lo) << 2, (arg1 + 0xC) << 2, G_TX_RENDERTILE, 0, 0, 0, 0x0400);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_878009BC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u32* spCC;
    s32 temp_lo = ((arg3 - arg2) * 0x30) / arg3;
    s32 sp14 = 0x30 - temp_lo;

    if (arg2 < ((arg3 * 0xA) / 48)) {
        spCC = D_87806730;
    } else if (arg2 < ((arg3 * 0x1B) / 48)) {
        spCC = D_87806730;
    } else {
        spCC = D_878065B0;
    }

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    gDPLoadTextureBlock(gDisplayListHead++, D_878064F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 5, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, arg0 << 2, arg1 << 2, (arg0 + 0x10) << 2, (arg1 + 5) << 2, G_TX_RENDERTILE,
                        0, 0, 0x0400, 0x0400);

    gDPLoadTextureBlock(gDisplayListHead++, D_87806670, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 5, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPTextureRectangle(gDisplayListHead++, (arg0 + 0x40) << 2, arg1 << 2, (arg0 + 0x41) << 2, (arg1 + 5) << 2,
                        G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);

    if (sp14 > 0) {
        gDPLoadTextureBlock(gDisplayListHead++, spCC, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 5, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gDisplayListHead++, (arg0 + 0x10) << 2, arg1 << 2, (arg0 + sp14 + 0x10) << 2,
                            (arg1 + 5) << 2, G_TX_RENDERTILE, 0, 0, 0, 0x0400);
    }

    if (temp_lo > 0) {
        gDPLoadTextureBlock(gDisplayListHead++, D_1003E78, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 5, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gDisplayListHead++, ((arg0 + sp14) + 0x10) << 2, arg1 << 2,
                            ((arg0 + sp14) + temp_lo + 0x10) << 2, (arg1 + 5) << 2, G_TX_RENDERTILE, 0, 0, 0, 0x0400);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

s16 D_87806338 = -1;
u32* D_8780633C[] = { D_878067F0, D_87807690, D_87808530, D_878093D0 };
u32* D_8780634C[] = { D_8780B110, D_8780BFB0, D_8780CE50, D_8780DCF0, D_8780A270 };

#ifdef NON_MATCHING
void func_878010C8(s16 arg0) {
    s32 i;

    D_8780FA28 = 0;
    D_87806338 = arg0;
    D_8780FA2A = 0;
    D_8780FA2C = 0;

    for (i = 0; i < 4; i++) {
        D_8780FA30[i] = 1;
    }

    if (arg0 == 3) {
        D_8780FA38 = 1;
    } else {
        D_8780FA38 = 3;
    }

    D_8780FA3A = 3;

    for (i = 0; i < 4; i++) {
        D_8780FA40[i] = 0;
    }

    for (i = 0; i < 4; i++) {
        D_8780FA68[i] = 0;
    }

    func_87800020();
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/2/fragment2/func_878010C8.s")
#endif

void func_8780118C(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    gDPPipeSync(gDisplayListHead++);
    gDPSetRenderMode(gDisplayListHead++,
                     IM_RD | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | FORCE_BL |
                         GBL_c1(G_BL_CLR_MEM, G_BL_0, G_BL_CLR_MEM, G_BL_1MA),
                     IM_RD | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | FORCE_BL |
                         GBL_c2(G_BL_CLR_MEM, G_BL_0, G_BL_CLR_MEM, G_BL_1MA));
    gDPSetCombineMode(gDisplayListHead++, G_CC_SHADE, G_CC_SHADE);
    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPFillRectangle(gDisplayListHead++, arg0, arg1, arg0 + arg2, arg1 + arg3);
}

void func_87801290(s32* arg0, s32* arg1, char* arg2, char* arg3, s32 arg4) {
    s32 var_a1;
    s32 var_t2;
    s8 sp38[0x100];
    s8* var_a2;
    s32 sp30;
    s8* var_t0;
    s8* var_t1;
    s8* var_v0;

    *arg0 = -1;
    var_t1 = arg2;
    *arg1 = -1;
    var_t0 = sp38;
    var_t2 = 0;

    while (*var_t1 != 0) {
        var_a2 = arg3;
        var_v0 = var_t1;

        if (*var_t1 != *var_a2) {
            *var_t0++ = *var_t1;
        } else {
            var_a1 = 1;

            while (*var_a2 != 0) {
                if (*var_v0 != *var_a2) {
                    var_a1 = 0;
                    break;
                }

                var_v0++;
                var_a2++;
            }

            if (var_a1 != 0) {
                var_t2 = 1;
                break;
            }

            *var_t0++ = *var_t1;
        }
        var_t1++;
    }

    *var_t0 = 0;
    var_t0 = sp38;
    var_a2 = var_t0;
    sp30 = 0;

    while (*var_t0 != 0) {
        if (*var_t0 == 0xA) {
            sp30 += 1;
            var_a2 = var_t0;
        }
        var_t0++;
    }

    if (var_t2 != 0) {
        *arg0 = func_8001F5B0(0, 0, (char*)var_a2);
        *arg1 = arg4 * sp30;
    }
}

s32 func_878013D4(UNUSED unk_D_800AC870* arg0, char* arg1) {
    return func_8001F5B0(0, 0, arg1);
}

// Needs in-function static to match, but D_8780FA70 is referenced in fragment 20 and 39?
#ifdef NON_MATCHING
void func_87801400(s32 arg0, s16 arg1, s16 arg2, f32 arg3, f32 arg4) {
    static u32* D_8780FA70;

    f32 temp_fa0;
    f32 temp_fv1;
    s16 a;
    s16 b;
    u32* var_t3;

    if ((arg3 != 0.0f) && (arg4 != 0.0f)) {
        if (arg0 < 0) {
            arg0 = -1 - arg0;
            D_8780FA70 = D_8780634C[arg0];
        } else {
            D_8780FA70 = D_8780633C[arg0 % 4];
        }

        gDPLoadTextureBlock(gDisplayListHead++, D_8780FA70, G_IM_FMT_RGBA, G_IM_SIZ_32b, 36, 26, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);

        a = ROUND_MAX(36.0f * arg3);
        b = ROUND_MAX(26.0f * arg4);

        func_8001C330(arg1, arg2, a, b, 0, 0, 1024.0f / arg3, 1024.0f / arg4, 0);
    }
}
#else
u32* D_8780FA70;
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/2/fragment2/func_87801400.s")
#endif

void func_87801644(s32 arg0, s16 arg1, s16 arg2, f32 arg3) {
    func_87801400(arg0, arg1, arg2, arg3, arg3);
}

void func_87801684(s16 arg0, s16 arg1, unk_func_87801684* arg2) {
    static unk_func_87801684* D_87806360 = NULL;
    static unk_func_87801684* D_8780FA74;
    static s16 D_8780FA78;

    if ((D_87806360 != arg2) || (arg2 == NULL)) {
        D_87806360 = arg2;
        if (arg2 == NULL) {
            return;
        }
        D_8780FA74 = arg2;
        D_8780FA78 = arg2->unk_04;
    }

    D_8780FA78--;
    if (D_8780FA78 <= 0) {
        D_8780FA74++;
        if (D_8780FA74->unk_00 == NULL) {
            D_8780FA74 = arg2;
        }
        D_8780FA78 = D_8780FA74->unk_04;
    }

    func_8001C8C4(arg0, arg1, 0x10, 0x10, D_8780FA74->unk_00, 0x10, 0);
}

void func_87801754(s16 arg0, s16 arg1, unk_func_87801684* arg2) {
    static unk_func_87801684* D_87806364 = NULL;
    static unk_func_87801684* D_8780FA7C;
    static s16 D_8780FA80;

    if ((D_87806364 != arg2) || (arg2 == NULL)) {
        D_87806364 = arg2;
        if (arg2 == NULL) {
            return;
        }
        D_8780FA7C = arg2;
        D_8780FA80 = arg2->unk_04;
    }

    D_8780FA80--;
    if (D_8780FA80 <= 0) {
        D_8780FA7C++;
        if (D_8780FA7C->unk_00 == NULL) {
            D_8780FA7C = arg2;
        }
        D_8780FA80 = D_8780FA7C->unk_04;
    }

    func_8001C8C4(arg0, arg1, 0x10, 0x10, D_8780FA7C->unk_00, 0x10, 0);
}

void func_87801824(s16 arg0, s16 arg1, unk_func_87801684* arg2) {
    static unk_func_87801684* D_87806368 = NULL;
    static unk_func_87801684* D_8780FA84;
    static s16 D_8780FA88;

    if ((D_87806368 != arg2) || (arg2 == NULL)) {
        D_87806368 = arg2;
        if (arg2 == NULL) {
            return;
        }
        D_8780FA84 = arg2;
        D_8780FA88 = arg2->unk_04;
    }

    D_8780FA88--;
    if (D_8780FA88 <= 0) {
        D_8780FA84++;
        if (D_8780FA84->unk_00 == NULL) {
            D_8780FA84 = arg2;
        }
        D_8780FA88 = D_8780FA84->unk_04;
    }

    func_8001C8C4(arg0, arg1, 0x10, 0x10, D_8780FA84->unk_00, 0x10, 0);
}

void func_878018F4(s16 arg0, s16 arg1, unk_func_87801684* arg2) {
    static unk_func_87801684* D_8780636C = NULL;
    static unk_func_87801684* D_8780FA8C;
    static s16 D_8780FA90;

    if ((D_8780636C != arg2) || (arg2 == NULL)) {
        D_8780636C = arg2;
        if (arg2 == NULL) {
            return;
        }
        D_8780FA8C = arg2;
        D_8780FA90 = arg2->unk_04;
    }

    D_8780FA90--;
    if (D_8780FA90 <= 0) {
        D_8780FA8C++;
        if (D_8780FA8C->unk_00 == NULL) {
            D_8780FA8C = arg2;
        }
        D_8780FA90 = D_8780FA8C->unk_04;
    }

    gDPLoadTextureTile(gDisplayListHead++, D_8780FA8C->unk_00, G_IM_FMT_RGBA, G_IM_SIZ_32b, 40, 0, 0, 0, 39, 19, 0,
                       G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                       G_TX_NOLOD);

    func_8001C330(arg0, arg1, 0x28, 0x14, 0, 0, 0x400, 0x400, 0);
}

void func_87801AC0(s16 arg0, s16 arg1, unk_func_87801684* arg2) {
    static unk_func_87801684* D_87806370 = NULL;
    static unk_func_87801684* D_8780FA94;
    static s16 D_8780FA98;

    if ((D_87806370 != arg2) || (arg2 == NULL)) {
        D_87806370 = arg2;
        if (arg2 == NULL) {
            return;
        }
        D_8780FA94 = arg2;
        D_8780FA98 = arg2->unk_04;
    }

    D_8780FA98--;
    if (D_8780FA98 <= 0) {
        D_8780FA94++;
        if (D_8780FA94->unk_00 == NULL) {
            D_8780FA94 = arg2;
        }
        D_8780FA98 = D_8780FA94->unk_04;
    }

    gDPLoadTextureTile(gDisplayListHead++, D_8780FA94->unk_00, G_IM_FMT_RGBA, G_IM_SIZ_32b, 40, 0, 0, 0, 39, 19, 0,
                       G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                       G_TX_NOLOD);

    func_8001C330(arg0, arg1, 0x28, 0x14, 0, 0, 0x400, 0x400, 0);
}

void func_87801C8C(s16 arg0, s16 arg1, unk_func_87801684* arg2) {
    static unk_func_87801684* D_87806374 = NULL;
    static unk_func_87801684* D_8780FA9C;
    static s16 D_8780FAA0;

    if ((D_87806374 != arg2) || (arg2 == NULL)) {
        D_87806374 = arg2;
        if (arg2 == NULL) {
            return;
        }
        D_8780FA9C = arg2;
        D_8780FAA0 = arg2->unk_04;
    }

    D_8780FAA0--;
    if (D_8780FAA0 <= 0) {
        D_8780FA9C++;
        if (D_8780FA9C->unk_00 == NULL) {
            D_8780FA9C = arg2;
        }
        D_8780FAA0 = D_8780FA9C->unk_04;
    }

    func_8001C8C4(arg0, arg1, 0x18, 0x13, D_8780FA9C->unk_00, 0x18, 0);
}

void func_87801D5C(s16 arg0, s16 arg1, s16 arg2, unk_func_87801684* arg3) {
    static unk_func_87801684* D_87806378[] = {
        NULL,
        NULL,
    };
    static unk_func_87801684* D_8780FAA8[2];
    static s16 D_8780FAB0[2];

    if ((arg3 != D_87806378[arg0]) || (arg3 == NULL)) {
        D_87806378[arg0] = arg3;
        if (arg3 == NULL) {
            return;
        }
        D_8780FAA8[arg0] = arg3;
        D_8780FAB0[arg0] = arg3->unk_04;
    }

    D_8780FAB0[arg0]--;
    if (D_8780FAB0[arg0] <= 0) {
        D_8780FAA8[arg0]++;
        if (D_8780FAA8[arg0]->unk_00 == NULL) {
            D_8780FAA8[arg0] = arg3;
        }
        D_8780FAB0[arg0] = D_8780FAA8[arg0]->unk_04;
    }

    gDPLoadTextureTile(gDisplayListHead++, D_8780FAA8[arg0]->unk_00, G_IM_FMT_RGBA, G_IM_SIZ_32b, 28, 0, 0, 0, 27, 27,
                       0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                       G_TX_NOLOD);

    func_8001C330(arg1, arg2, 0x1C, 0x1C, 0, 0, 0x400, 0x400, 0);
}

void func_87801F48(s16 arg0, s16 arg1, s16 arg2) {
    static u32 D_87806380[] = { 0x03049CA0, 0x0304B1C0, 0x0304C6E0, 0x0304DC00 };

    u32 sp34 = D_87806380[arg0];

    gDPLoadTextureTile(gDisplayListHead++, sp34, G_IM_FMT_RGBA, G_IM_SIZ_16b, 52, 0, 0, 0, 51, 25, 0,
                       G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                       G_TX_NOLOD);

    func_8001C330(arg1, arg2, 0x34, 0x1A, 0, 0, 0x400, 0x400, 0);

    gDPLoadTextureTile(gDisplayListHead++, sp34 + 0xA90, G_IM_FMT_RGBA, G_IM_SIZ_16b, 52, 0, 0, 0, 51, 25, 0,
                       G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                       G_TX_NOLOD);

    func_8001C330(arg1, arg2 + 0x1A, 0x34, 0x1A, 0, 0, 0x400, 0x400, 0);
}

void func_878021B4(s16 arg0, s16 arg1) {
    u32* ptr = D_304F120;
    s32 i;

    for (i = 0; i < 7; i++, ptr += 800) {
        gDPLoadTextureTile(gDisplayListHead++, ptr, G_IM_FMT_RGBA, G_IM_SIZ_32b, 100, 0, 0, 0, 99, 7, 0,
                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                           G_TX_NOLOD);

        func_8001C330(arg0, arg1 + (i * 8), 0x64, 8, 0, 0, 0x400, 0x400, 0);
    }
}
