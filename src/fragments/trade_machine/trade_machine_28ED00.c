#include "trade_machine.h"
#include "src/geo_render.h"
#include "src/model_renderer.h"
#include "src/graphics_textures.h"
#include "src/ui_graphics.h"
#include "src/game_state.h"
#include "src/text_system.h"
#include "src/audio_sfx.h"
#include "src/matrix.h"
#include "src/geo_layout.h"
#include "src/math_util.h"
#include "src/memmap.h"
#include "src/memory.h"

s32 Trade_DrawBox3DModel(s32 arg0, GraphNode* arg1);

static unk_D_82F20A40 D_82F20A40;
static unk_D_82F20A88 D_82F20A88[4];
static GraphNode* D_82F210C8;
static GraphNode* D_82F210CC;
static s16 D_82F210D0;
static s16 D_82F210D2;
static s16 D_82F210D4;
static s16 D_82F210D8[2];

static Vtx D_82F13CB0[] = {
    VTX(-32, 64, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-32, 32, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, 32, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF), VTX(32, 64, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-32, 32, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-32, 0, 0, 0, 1024, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(32, 0, 0, 2048, 1024, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(32, 32, 0, 2048, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-16, 39, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF),      VTX(-16, 15, 0, 0, 768, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(16, 15, 0, 1024, 768, 0xFF, 0xFF, 0xFF, 0xFF),  VTX(16, 39, 0, 1024, 0, 0xFF, 0xFF, 0xFF, 0xFF),
};

static Gfx D_82F13D70[] = {
    gsSPSetGeometryMode(G_CULL_BACK),
    gsDPSetCombineLERP(0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPVertex(D_82F13CB0, 12, 0),
    gsDPLoadTextureBlock(0x0F000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
    gsDPLoadTextureBlock(0x0F001000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
    gsDPLoadTextureBlock(0x0E000000, G_IM_FMT_IA, G_IM_SIZ_8b, 32, 24, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                         G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
    gsSPEndDisplayList(),
};

static u32 D_82F13E58[] = {
    0x17000000, 0x00000000, 0x00000000,    0x00000000, D_82F13CB0, 0x05000000, 0x22050000,
    0x00000000, 0x08000000, Trade_DrawBox3DModel, D_82F13D70, 0x06000000, 0x01000000,
};

static u32 D_82F13E8C[] = {
    0x0C000000, 0x05000000, 0x0B00002D,  0x00000000, 0x028001E0, 0x00000000, 0xFDBD0000, 0x00000243,
    0x05000000, 0x0D000000, 0x05000000,  0x14000000, 0x002D013B, 0xFFFFFF32, 0x16FFFFFF, 0x0F000002,
    0x05000000, 0x0A000000, &D_800AC840, 0x06000000, 0x06000000, 0x06000000, 0x06000000, 0x01000000,
};
static s16 D_82F13EEC[] = {
    0x007E,
    0x013C,
    0x0184,
    0x0000,
};
static s16 D_82F13EF4[] = {
    0x007E,
    0x0120,
    0x0184,
    0x0038,
};
static s16 D_82F13EFC[] = {
    0x00A1,
    0x013C,
    0x013E,
    0x0000,
};
static s16 D_82F13F04[] = {
    0x00A1,
    0x0120,
    0x013E,
    0x0038,
};
static s16 D_82F13F0C[] = {
    0x007D,
    0x0149,
    0x0186,
    0x0000,
};
static s16 D_82F13F14[] = {
    0x007D,
    0x0120,
    0x0186,
    0x0052,
};
static s16 D_82F13F1C[] = {
    0x00CC,
    0x013C,
    0x00E8,
    0x0000,
};
static s16 D_82F13F24[] = {
    0x00CC,
    0x0120,
    0x00E8,
    0x0038,
};
static u8* D_82F13F2C[] = {
    D_302FAB0,
    D_302FDB0,
    D_30300B0,
    D_30303B0,
};

s32 Trade_DrawBox3DModel(s32 arg0, GraphNode* arg1) {
    if (arg0 == 5) {
        s32 idx = D_8006F09C->node.callbackArg;

        gDPPipeSync(gDisplayListHead++);
        gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, D_8006F09C->lodFraction);

        if (D_82F20A88[idx].unk_024 != NULL) {
            gSPSegment(gDisplayListHead++, 0x0F, Memmap_GetSegmentVaddr(D_82F20A88[idx].unk_024));
            gSPSegment(gDisplayListHead++, 0x0E, Memmap_GetSegmentVaddr(D_82F13F2C[D_82F20A88[idx].unk_002]));
            gSPDisplayList(gDisplayListHead++, arg1->callbackArg);
        }
        GeoRender_ApplyMaterialState();
    }
    return 0;
}

s16 Trade_GetBoxSlotType(unk_D_82F14450* arg0) {
    s16 ret;

    switch (arg0->unk_00) {
        case 0:
            if (arg0->unk_04 == 0) {
                ret = 4;
            } else if (arg0->unk_03 == 0) {
                ret = 3;
            } else {
                ret = 0;
            }
            break;

        case 2:
            ret = 1;
            break;

        case 3:
            ret = 2;
            break;

        default:
            ret = -1;
            break;
    }

    return ret;
}

void Trade_SetupBoxSlots(s16 arg0) {
    s16 temp_v0;
    unk_D_82F20A88* var_s0;
    s32 i;

    var_s0 = &D_82F20A88[0];
    for (i = 0; i < 4; i++, var_s0++) {
        var_s0->unk_000 = 0;
        var_s0->unk_002 = -1;
        var_s0->unk_004 = 0;
        var_s0->unk_024 = NULL;
    }

    D_82F210D0 = 1;

    for (i = 0; i < 4; i++) {
        temp_v0 = Trade_GetBoxSlotType(&D_82F14450[i]);
        if (temp_v0 == -1) {
            continue;
        }

        if (i != D_82F210D8[0]) {
            var_s0 = &D_82F20A88[D_82F210D0++];
        } else {
            var_s0 = &D_82F20A88[0];
        }

        var_s0->unk_002 = i;
        var_s0->unk_004 = temp_v0;

        switch (var_s0->unk_004) {
            case 0:
            case 2:
            case 3:
            case 4:
                switch (D_82F14450[i].unk_01) {
                    case 1:
                        var_s0->unk_024 = D_30306B0;
                        break;

                    case 2:
                        var_s0->unk_024 = D_30326B0;
                        break;

                    case 3:
                        var_s0->unk_024 = D_30346B0;
                        break;

                    case 7:
                        var_s0->unk_024 = D_30366B0;
                        break;
                }
                break;

            case 1:
                var_s0->unk_024 = D_302BE68;
                break;
        }
    }

    var_s0 = &D_82F20A88[0];
    for (i = 0; i < D_82F210D0; i++, var_s0++) {
        DisplayObject* ptr = &var_s0->unk_028;

        ModelRenderer_AttachDisplayObject(ptr);
        Model_InitDisplayObject(ptr, 0, 0, D_82F210CC);
        ptr->node.callbackArg = i;
        ptr->node.flags &= ~1;
    }
}

void Trade_SetBoxSlotAnimState(unk_D_82F20A88* arg0, s16 arg1) {
    DisplayObject* temp_v0 = &arg0->unk_028;

    arg0->unk_000 = arg1;

    switch (arg0->unk_000) {
        case 0:
            temp_v0->node.flags &= ~1;
            break;

        case 1:
            if ((((s32)arg0 - (s32)D_82F20A88) / 400) == 0) {
                arg0->unk_006 = 0xF8;
                arg0->unk_008 = 0xB8;
            }

            arg0->unk_010 = 0;
            arg0->unk_00C = 0;
            arg0->unk_00E = 0;
            arg0->unk_012 = 0;

            if (arg0->unk_004 != 0) {
                arg0->unk_014 = 0x80;
            } else {
                arg0->unk_014 = 0xFF;
            }

            arg0->unk_018 = 1.0f;
            arg0->unk_01C = 1.0f;
            arg0->unk_020 = 1.0f;
            temp_v0->node.flags |= 1;
            break;

        case 2:
            arg0->unk_006 = ((((s32)arg0 - (s32)D_82F20A88) / 400) * 0x88) + 0x30;
            arg0->unk_008 = 0x17C;
            arg0->unk_00A = arg0->unk_006;
            arg0->unk_010 = 0xA;
            arg0->unk_00C = 0;
            arg0->unk_00E = 0;
            arg0->unk_012 = 0;

            if (arg0->unk_004 != 0) {
                arg0->unk_014 = 0x80;
            } else {
                arg0->unk_014 = 0xFF;
            }

            arg0->unk_01C = 1.0f;
            arg0->unk_020 = 1.0f;
            arg0->unk_018 = 0.0f;
            temp_v0->node.flags |= 1;
            break;

        case 4:
            arg0->unk_010 = 0;
            arg0->unk_00A = arg0->unk_006;

            if ((((s32)arg0 - (s32)D_82F20A88) / 400) & 1) {
                arg0->unk_00C = -0x8000;
            } else {
                arg0->unk_00C = 0;
            }

            arg0->unk_00E = arg0->unk_00C;
            arg0->unk_018 = 1.0f;
            break;

        case 3:
            arg0->unk_006 = ((((s32)arg0 - (s32)D_82F20A88) / 400) * 0x88) + 0x30;
            arg0->unk_008 = 0x17C;
            arg0->unk_010 = 0xA;
            arg0->unk_00C = 0;
            arg0->unk_00E = 0;
            arg0->unk_012 = 0;
            arg0->unk_01C = 1.0f;
            arg0->unk_020 = 1.0f;
            break;

        case 5:
            arg0->unk_010 = 0xA;
            break;

        case 6:
            arg0->unk_010 = 0xA;
            break;
    }
}

void Trade_UpdateBoxSlotFlyIn(unk_D_82F20A88* arg0) {
    arg0->unk_010--;
    arg0->unk_018 = (0xA - arg0->unk_010) / 10.0f;
    if (arg0->unk_010 <= 0) {
        Trade_SetBoxSlotAnimState(arg0, 4);
    }
}

void Trade_UpdateBoxSlotBob(unk_D_82F20A88* arg0) {
    static s16 D_82F13F38[] = { 0x5C0, 0x680, 0x580 };

    s32 temp_lo = arg0 - &D_82F20A88[0];
    s16 var_a2;
    s16 var_a3;
    f32 var_fv0;
    f32 var_fv1;

    if (temp_lo - 1 == D_82F210D2) {
        var_fv0 = 1.5f;
        var_a2 = D_82F13F38[temp_lo - 1] * 2;
        var_fv1 = 0.06f;
        var_a3 = 0x3000;
    } else {
        var_a2 = D_82F13F38[temp_lo - 1];
        var_fv1 = 0.02f;
        var_a3 = 0x2000;
        var_fv0 = 1.0f;
    }

    arg0->unk_006 = arg0->unk_00A - (SINS(arg0->unk_00C) * (6.0f * var_fv0));

    arg0->unk_012 = SINS(arg0->unk_00C) * (1536.0f * var_fv0);
    arg0->unk_01C = (SINS(arg0->unk_00E) * var_fv1) + 1.0f;
    arg0->unk_020 = (COSS(arg0->unk_00E) * var_fv1) + 1.0f;

    arg0->unk_00C += var_a2;
    arg0->unk_00E += var_a3 + ((MathUtil_Random16() & 0xF) * 0x10);
}

void Trade_UpdateBoxSlotBobIdle(unk_D_82F20A88* arg0) {
    Trade_UpdateBoxSlotBob(arg0);
}

void Trade_UpdateBoxSlotFlyOut(unk_D_82F20A88* arg0) {
    arg0->unk_010 -= 1;
    arg0->unk_006 = 0x208 - (((0x208 - arg0->unk_00A) * arg0->unk_010) / 10);
    arg0->unk_008 = 0xB8 - ((arg0->unk_010 * -0xC4) / 10);
    if (arg0->unk_010 <= 0) {
        Trade_SetBoxSlotAnimState(arg0, 1);
        D_82F210D8[1] = arg0->unk_002;
    }
}

void Trade_UpdateBoxSlotFadeOut(unk_D_82F20A88* arg0) {
    arg0->unk_010--;
    arg0->unk_014 = (arg0->unk_010 * 0xFF) / 10;
    if (arg0->unk_010 <= 0) {
        Trade_SetBoxSlotAnimState(arg0, 0);
        D_82F210D8[1] = -1;
    }
}

void Trade_UpdateBoxSlotShrink(unk_D_82F20A88* arg0) {
    Trade_UpdateBoxSlotBob(arg0);
    arg0->unk_010--;
    arg0->unk_018 = arg0->unk_010 / 10.0f;
    if (arg0->unk_010 <= 0) {
        Trade_SetBoxSlotAnimState(arg0, 0);
    }
}

void Trade_UpdateBoxSlotTransforms(void) {
    s32 i;
    unk_D_82F20A88* var_s0 = &D_82F20A88[0];

    for (i = 0; i < D_82F210D0; i++, var_s0++) {
        switch (var_s0->unk_000) {
            case 0:
            case 1:
                break;

            case 2:
                Trade_UpdateBoxSlotFlyIn(var_s0);
                break;

            case 4:
                Trade_UpdateBoxSlotBobIdle(var_s0);
                break;

            case 3:
                Trade_UpdateBoxSlotFlyOut(var_s0);
                break;

            case 6:
                Trade_UpdateBoxSlotShrink(var_s0);
                break;

            case 5:
                Trade_UpdateBoxSlotFadeOut(var_s0);
                break;
        }

        if (var_s0->unk_000 != 0) {
            DisplayObject* ptr = &var_s0->unk_028;

            Vec3f_SetComponentsDuplicate(&ptr->position, var_s0->unk_006 - 320.0f, 240.0f - var_s0->unk_008, -579.0f);
            ptr->rotation.z = var_s0->unk_012;
            ptr->lodFraction = var_s0->unk_014;
            ptr->scale.x = var_s0->unk_01C * var_s0->unk_018;
            ptr->scale.y = var_s0->unk_020 * var_s0->unk_018;
        }
    }
}

void Trade_ResetBoxMachineFlow(void) {
    unk_D_82F20A40* ptr = &D_82F20A40;
    s32 i;

    ptr->unk_00 = 1;
    ptr->unk_02 = 0xA;
    ptr->unk_04 = 0;
    ptr->unk_06.unk_00 = 0x40;
    ptr->unk_06.unk_02 = 0x8C;
    ptr->unk_06.unk_04 = 0x200;
    ptr->unk_06.unk_06 = 0;

    for (i = 0; i < 3; i++) {
        ptr->unk_0E[i].unk_00 = 0x7C + i * 0x88;
        ptr->unk_0E[i].unk_02 = 0x10C;
        ptr->unk_0E[i].unk_04 = 0x78;
        ptr->unk_0E[i].unk_06 = 0;
    }

    ptr->unk_26.unk_00 = 0x38;
    ptr->unk_26.unk_02 = 0x1A4;
    ptr->unk_26.unk_04 = 0x210;
    ptr->unk_26.unk_06 = 0;
    ptr->unk_2E.unk_00 = 0xCC;
    ptr->unk_2E.unk_02 = 0x130;
    ptr->unk_2E.unk_04 = 0xE8;
    ptr->unk_2E.unk_06 = 0;
    ptr->unk_36.unk_00 = 0;
    ptr->unk_36.unk_02 = 0;
    ptr->unk_36.unk_04 = 0;
    ptr->unk_36.unk_06 = 0;

    D_82F210D8[1] = -1;
    D_82F210D2 = -1;

    if (D_82F20A88[0].unk_004 == 0) {
        D_82F210D2 = 0;
    }
}

s32 Trade_GetSelectedBox(s16 arg0) {
    return D_82F210D8[arg0];
}

s32 Trade_GetBoxMachineFlowState(void) {
    return D_82F20A40.unk_00;
}

void Trade_UpdateBoxMachineFlowOpen(unk_D_82F20A40* arg0, s32 arg1) {
    s32 i;

    arg0->unk_02--;
    if (arg1 != 0) {
        arg0->unk_06.unk_00 = 0x40 - ((arg0->unk_02 * 0) / 10);
        arg0->unk_06.unk_02 = 0x48 - ((arg0->unk_02 * -0x44) / 10);
        arg0->unk_06.unk_04 = 0x200 - ((arg0->unk_02 * 0) / 10);
        arg0->unk_06.unk_06 = 0x88 - ((arg0->unk_02 * 0x88) / 10);
    }

    for (i = 0; i < 3; i++) {
        arg0->unk_0E[i].unk_00 = ((i * 0x88) - ((arg0->unk_02 * 0) / 10)) + 0x7C;
        arg0->unk_0E[i].unk_02 = 0xF0 - ((arg0->unk_02 * -0x1C) / 10);
        arg0->unk_0E[i].unk_04 = 0x78 - ((arg0->unk_02 * 0) / 10);
        arg0->unk_0E[i].unk_06 = 0x38 - ((arg0->unk_02 * 0x38) / 10);
    }

    if (arg1 != 0) {
        arg0->unk_26.unk_00 = 0x38 - ((arg0->unk_02 * 0) / 10);
        arg0->unk_26.unk_02 = 0x190 - ((arg0->unk_02 * -0x14) / 10);
        arg0->unk_26.unk_04 = 0x210 - ((arg0->unk_02 * 0) / 10);
        arg0->unk_26.unk_06 = 0x28 - ((arg0->unk_02 * 0x28) / 10);
    }

    if (arg0->unk_02 <= 0) {
        arg0->unk_00 = 2;
        arg0->unk_02 = 0;
        Trade_SetBoxSlotAnimState(D_82F20A88, 1);

        for (i = 0; i < 3; i++) {
            if (D_82F20A88[i + 1].unk_002 != -1) {
                Trade_SetBoxSlotAnimState(&D_82F20A88[i + 1], 2);
            }
        }
    }
}

void Trade_UpdateBoxMachineFlowSelect(unk_D_82F20A40* arg0) {
    s32 i;
    s16 tmp;

    MathUtil_Random16();

    tmp = D_82F210D2;

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DLEFT) && (D_82F210D2 != -1) && (D_82F210D2 > 0)) {
        D_82F210D2 -= 1;
    }

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DRIGHT) && (D_82F210D2 != -1) && (D_82F210D2 < (D_82F210D0 - 2))) {
        D_82F210D2 += 1;
    }

    if (D_82F210D2 != tmp) {
        Audio_PlaySoundEffectById(SFX_PAK_CURSOR);
    }

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A) && (D_82F210D2 != -1)) {
        if (D_82F20A88[D_82F210D2 + 1].unk_004 == 0) {
            arg0->unk_00 = 6;
            arg0->unk_02 = 0xA;

            for (i = 0; i < 3; i++) {
                if (D_82F20A88[i + 1].unk_002 != -1) {
                    if (i != D_82F210D2) {
                        Trade_SetBoxSlotAnimState(&D_82F20A88[i + 1], 6);
                    } else {
                        Trade_SetBoxSlotAnimState(&D_82F20A88[i + 1], 3);
                    }
                }
            }
            Audio_PlaySoundEffectById(SFX_MENU_CONFIRM);
        } else {
            arg0->unk_00 = 3;
            arg0->unk_02 = 0xA;
            arg0->unk_04 = D_82F20A88[D_82F210D2 + 1].unk_004;

            switch (arg0->unk_04) {
                case 1:
                    arg0->unk_40 = &D_82F13EEC;
                    arg0->unk_44 = &D_82F13EF4;
                    break;

                case 2:
                    arg0->unk_40 = &D_82F13EFC;
                    arg0->unk_44 = &D_82F13F04;
                    break;

                case 3:
                    arg0->unk_40 = &D_82F13F0C;
                    arg0->unk_44 = &D_82F13F14;
                    break;

                case 4:
                    arg0->unk_40 = &D_82F13F1C;
                    arg0->unk_44 = &D_82F13F24;
                    break;

                default:
                    arg0->unk_44 = NULL;
                    arg0->unk_40 = NULL;
                    break;
            }
        }
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
        arg0->unk_00 = 0xB;
        arg0->unk_02 = 0xA;

        for (i = 0; i < 4; i++) {
            Trade_SetBoxSlotAnimState(&D_82F20A88[i], 0);
        }

        Audio_PlaySoundEffectById(SFX_MENU_BACK);
    }
}

void Trade_UpdateBoxMachineFlowFrameMove(unk_D_82F20A40* arg0) {
    arg0->unk_02--;
    arg0->unk_36.unk_00 = arg0->unk_44->unk_00 - (((arg0->unk_44->unk_00 - arg0->unk_40->unk_00) * arg0->unk_02) / 10);
    arg0->unk_36.unk_02 = arg0->unk_44->unk_02 - (((arg0->unk_44->unk_02 - arg0->unk_40->unk_02) * arg0->unk_02) / 10);
    arg0->unk_36.unk_04 = arg0->unk_44->unk_04 - (((arg0->unk_44->unk_04 - arg0->unk_40->unk_04) * arg0->unk_02) / 10);
    arg0->unk_36.unk_06 = arg0->unk_44->unk_06 - (((arg0->unk_44->unk_06 - arg0->unk_40->unk_06) * arg0->unk_02) / 10);
    if (arg0->unk_02 <= 0) {
        arg0->unk_00 = 4;
        arg0->unk_02 = 0;
    }
}

void Trade_UpdateBoxMachineFlowConfirmWait(unk_D_82F20A40* arg0) {
    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A | BTN_B)) {
        arg0->unk_00 = 5;
        arg0->unk_02 = 0xA;
    }
}

void Trade_UpdateBoxMachineFlowFrameReturn(unk_D_82F20A40* arg0) {
    arg0->unk_02--;
    arg0->unk_36.unk_00 = arg0->unk_40->unk_00 - (((arg0->unk_40->unk_00 - arg0->unk_44->unk_00) * arg0->unk_02) / 10);
    arg0->unk_36.unk_02 = arg0->unk_40->unk_02 - (((arg0->unk_40->unk_02 - arg0->unk_44->unk_02) * arg0->unk_02) / 10);
    arg0->unk_36.unk_04 = arg0->unk_40->unk_04 - (((arg0->unk_40->unk_04 - arg0->unk_44->unk_04) * arg0->unk_02) / 10);
    arg0->unk_36.unk_06 = arg0->unk_40->unk_06 - (((arg0->unk_40->unk_06 - arg0->unk_44->unk_06) * arg0->unk_02) / 10);
    if (arg0->unk_02 <= 0) {
        arg0->unk_00 = 2;
        arg0->unk_02 = 0;
        arg0->unk_04 = 0;
        arg0->unk_44 = NULL;
        arg0->unk_40 = NULL;
    }
}

void Trade_UpdateBoxMachineSlots(unk_D_82F20A40* arg0, s16 arg1, s16 arg2) {
    unk_D_82F20A40_00E* ptr;
    s32 i;
    s32 tmp;

    for (i = 0; i < 3; i++) {
        ptr = &arg0->unk_0E[i];

        if ((ptr->unk_04 == 0x78) && (ptr->unk_06 == 0)) {
            continue;
        }

        tmp = (ptr->unk_00 * 0) / arg2;

        ptr->unk_00 = (0x7C + (i * 0x88)) - (tmp);
        ptr->unk_02 = 0x10C - ((arg1 * 0x1C) / arg2);
        ptr->unk_04 = 0x78 - (tmp);
        ptr->unk_06 = -((arg1 * -0x38) / arg2);
    }
}

void Trade_UpdateBoxMachineFlowPanelsFull(unk_D_82F20A40* arg0) {
    s32 i;

    arg0->unk_02--;
    Trade_UpdateBoxMachineSlots(arg0, arg0->unk_02, 0xA);
    if (arg0->unk_02 <= 0) {
        arg0->unk_00 = 7;
        arg0->unk_02 = 0xA;

        for (i = 0; i < 3; i++) {
            arg0->unk_0E[i].unk_00 = 0x7C + i * 0x88;
            arg0->unk_0E[i].unk_02 = 0x10C;
            arg0->unk_0E[i].unk_04 = 0x78;
            arg0->unk_0E[i].unk_06 = 0;
        }
    }
}

void Trade_UpdateBoxMachineFlowConfirmOpen(unk_D_82F20A40* arg0) {
    arg0->unk_02--;
    arg0->unk_2E.unk_00 = 0xCC - (arg0->unk_02 * 0) / 10;
    arg0->unk_2E.unk_02 = 0xF8 - ((arg0->unk_02 * -0x38) / 10);
    arg0->unk_2E.unk_04 = 0xE8 - (arg0->unk_02 * 0) / 10;
    arg0->unk_2E.unk_06 = 0x70 - ((arg0->unk_02 * 0x70) / 10);
    if (arg0->unk_02 <= 0) {
        arg0->unk_00 = 8;
        arg0->unk_02 = 0;
        D_82F210D4 = 0;
    }
}

void Trade_UpdateBoxMachineFlowConfirmInput(unk_D_82F20A40* arg0) {
    s16 tmp;
    s32 var_a2;

    var_a2 = 0;
    tmp = D_82F210D4;

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP) && (D_82F210D4 > 0)) {
        D_82F210D4 -= 1;
    }

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DDOWN) && (D_82F210D4 <= 0)) {
        D_82F210D4 += 1;
    }

    if (D_82F210D4 != tmp) {
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
    }

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        var_a2 = 1;
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
        var_a2 = 1;
        D_82F210D4 = 1;
    }

    if (var_a2 != 0) {
        if (D_82F210D4 == 0) {
            arg0->unk_00 = 0xB;
            arg0->unk_02 = 0xA;
            Trade_SetBoxSlotAnimState(D_82F20A88, 0);
            Trade_SetBoxSlotAnimState(&D_82F20A88[D_82F210D2 + 1], 0);
            Audio_PlaySoundEffectById(0x1B);
        } else {
            arg0->unk_00 = 9;
            arg0->unk_02 = 0xA;
            Trade_SetBoxSlotAnimState(&D_82F20A88[D_82F210D2 + 1], 5);
            Audio_PlaySoundEffectById(SFX_MENU_BACK);
        }
    }
}

void Trade_UpdateBoxMachineRect(unk_D_82F20A40_00E* arg0, s16 arg1, s16 arg2) {
    if ((arg0->unk_04 != 0xE8) || (arg0->unk_06 != 0)) {
        s32 tmp = (arg0->unk_00 * 0) / arg2;

        arg0->unk_00 = 0xCC - tmp;
        arg0->unk_02 = 0x130 - ((arg1 * 0x38) / arg2);
        arg0->unk_04 = 0xE8 - tmp;
        arg0->unk_06 = -((arg1 * -0x70) / arg2);
    }
}

void Trade_UpdateBoxMachineFlowConfirmDone(unk_D_82F20A40* arg0) {
    if (arg0->unk_02 > 0) {
        arg0->unk_02--;
    }

    Trade_UpdateBoxMachineRect(&arg0->unk_2E, arg0->unk_02, 0xA);

    if ((arg0->unk_02 <= 0) && (D_82F210D8[1] == -1)) {
        arg0->unk_00 = 0xA;
        arg0->unk_02 = 0xA;
    }
}

void Trade_UpdateBoxMachineFlowClose(unk_D_82F20A40* arg0) {
    arg0->unk_02--;
    arg0->unk_06.unk_00 = 0x40 - (arg0->unk_02 * 0) / 10;
    arg0->unk_06.unk_02 = 0x8C - ((arg0->unk_02 * 0x44) / 10);
    arg0->unk_06.unk_04 = 0x200 - (arg0->unk_02 * 0) / 10;
    arg0->unk_06.unk_06 = -((arg0->unk_02 * -0x88) / 10);

    Trade_UpdateBoxMachineSlots(arg0, arg0->unk_02, 0xA);
    Trade_UpdateBoxMachineRect(&arg0->unk_2E, arg0->unk_02, 0xA);

    arg0->unk_26.unk_00 = 0x38 - (arg0->unk_02 * 0) / 10;
    arg0->unk_26.unk_02 = 0x1A4 - ((arg0->unk_02 * 0x14) / 10);
    arg0->unk_26.unk_04 = 0x210 - (arg0->unk_02 * 0) / 10;
    arg0->unk_26.unk_06 = -((arg0->unk_02 * -0x28) / 10);

    if (arg0->unk_02 <= 0) {
        arg0->unk_00 = 0;
        arg0->unk_02 = 0;
    }
}

void Trade_DrawBoxMachineTopBar(unk_D_82F20A40* arg0) {
    Color_RGB8* var_v0;
    unk_D_82F20A40_00E* temp_s4 = &arg0->unk_06;
    s32 i;
    unk_D_82F14450* ptr;

    Trade_DrawPickScreenFrame(temp_s4->unk_00, temp_s4->unk_02, temp_s4->unk_04, temp_s4->unk_06);

    if ((temp_s4->unk_04 == 0x200) && (temp_s4->unk_06 == 0x88)) {
        gSPDisplayList(gDisplayListHead++, D_8006F498);

        Gfx_FillRectRgba(temp_s4->unk_00, temp_s4->unk_02, temp_s4->unk_04, temp_s4->unk_06, 0x32, 0x32, 0x96, 0xFF);

        gSPDisplayList(gDisplayListHead++, D_8006F630);

        for (i = 0; i < 2; i++) {
            Color_RGB8 sp5C = { 0x1E, 0x1E, 0x64 };
            Color_RGB8 sp58 = { 0x64, 0x64, 0xC8 };

            if (D_82F210D8[i] == -1) {
                var_v0 = &sp58;
            } else {
                var_v0 = &sp5C;
            }

            Trade_DrawRoundedFrameSmall(temp_s4->unk_00 + (i * 0x110) + 0x10, temp_s4->unk_02 + 0x28, 0xD0, 0x50, var_v0->r,
                          var_v0->g, var_v0->b, 0xFF);
        }

        Trade_DrawBoxMachineTransferArrows(temp_s4->unk_00 + 0xE0, temp_s4->unk_02 + 0x28);
        Font_BeginTranslucentTextRendering();
        Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
        Font_SetActive(0x10, 0);
        Font_Printf(temp_s4->unk_00 + 0x5A, temp_s4->unk_02 + 8, Text_GetString(NULL, 0, gTradeStrings, 1));

        for (i = 0; i < 2; i++) {
            if (D_82F210D8[i] != -1) {
                if (i == 0) {
                    if (D_82F20A88[0].unk_004 == 0) {
                        Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
                    } else {
                        Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0x80);
                    }
                } else {
                    Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
                }

                ptr = &D_82F14450[D_82F210D8[i]];
                if (ptr) {}

                Font_SetActive(0x10, 0);
                Font_Printf(temp_s4->unk_00 + (i * 0x110) + 0x24, temp_s4->unk_02 + 0x3C, ptr->unk_08);
                Font_SetActive(8, 0);
                Font_Printf(temp_s4->unk_00 + (i * 0x110) + 0x24, temp_s4->unk_02 + 0x54, "ID%05d", ptr->unk_06);
            }
        }

        Font_EndTexturedTextRendering();
    }
}

void Trade_DrawBoxMachineSlots(unk_D_82F20A40* arg0) {
    s32 i;
    Color_RGB8* var_v0;
    s32 var_v1;
    char* var_s0_2;
    unk_D_82F14450* var_s2;
    Color_RGB8 sp88 = { 0x1E, 0x1E, 0x82 };
    Color_RGB8 sp84 = { 0x64, 0x1E, 0x1E };
    char sp68[28];
    unk_D_82F20A40_00E* ptr;

    for (i = 0; i < 3; i++) {
        ptr = &arg0->unk_0E[i];

        if ((arg0->unk_0E[i].unk_04 == 0x78) && (ptr->unk_06 == 0)) {
            continue;
        }

        if (D_82F20A88[i + 1].unk_002 == -1) {
            var_v1 = 0x80;
        } else {
            var_v1 = 0xFF;
        }

        if (D_82F20A88[i + 1].unk_004 == 0) {
            var_v0 = &sp88;
        } else {
            var_v0 = &sp84;
        }

        Trade_DrawRoundedFrameLarge(ptr->unk_00, ptr->unk_02, ptr->unk_04, ptr->unk_06, var_v0->r, var_v0->g, var_v0->b, var_v1);
    }

    Font_BeginTranslucentTextRendering();
    Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);

    for (i = 0; i < 3; i++) {
        var_s2 = NULL;
        if (D_82F20A88[i + 1].unk_002 == -1) {
            continue;
        }

        ptr = &arg0->unk_0E[i];

        switch (D_82F20A88[i + 1].unk_004) {
            case 0:
            case 3:
            case 4:
                var_s2 = &D_82F14450[D_82F20A88[i + 1].unk_002];
                break;
        }

        if ((arg0->unk_0E[i].unk_04 == 0x78) && (ptr->unk_06 == 0x38)) {
            Font_SetActive(8, 0);
            if (var_s2 != NULL) {
                var_s0_2 = var_s2->unk_08;
            } else {
                var_s0_2 = "?????";
            }

            Font_Printf(((ptr->unk_04 - Font_MeasureTextExtent(0, 0, var_s0_2)) / 2) + ptr->unk_00, ptr->unk_02 + 8, var_s0_2);
            Font_SetActive(4, 0);

            if (var_s2 != NULL) {
                sprintf(sp68, "ID%05d", var_s2->unk_06);
                var_s0_2 = sp68;
            } else {
                var_s0_2 = "ID*****";
            }

            Font_Printf(((ptr->unk_04 - Font_MeasureTextExtent(0, 0, var_s0_2)) / 2) + ptr->unk_00, ptr->unk_02 + 0x20,
                          var_s0_2);
        }
    }

    Font_EndTexturedTextRendering();
}

void Trade_DrawBoxMachineTitle(unk_D_82F20A40* arg0) {
    unk_D_82F20A40_00E* temp_s1 = &arg0->unk_26;
    char* temp_v0;

    Trade_DrawRoundedFrameLarge(arg0->unk_26.unk_00, arg0->unk_26.unk_02, arg0->unk_26.unk_04, arg0->unk_26.unk_06, 0x1E, 0x1E, 0x82,
                  0xFF);
    if ((temp_s1->unk_04 == 0x210) && (temp_s1->unk_06 == 0x28)) {
        Font_BeginTranslucentTextRendering();
        Font_SetActive(0x10, 0);
        Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
        temp_v0 = Text_GetString(NULL, 0, gTradeStrings, 2);
        Font_Printf((temp_s1->unk_00 - (Font_MeasureTextExtent(0, 0, temp_v0) / 2)) + 0x108, temp_s1->unk_02 + 8, temp_v0);
        Font_EndTexturedTextRendering();
    }
}

void Trade_DrawBoxMachineConfirm(unk_D_82F20A40* arg0) {
    char* temp_v0;
    unk_D_82F20A40_00E* temp_s3 = &arg0->unk_2E;
    s32 i;
    s32 tmp;
    Color_RGB8 sp54 = { 0x1E, 0x1E, 0x82 };
    char* sp4C[2];

    if ((temp_s3->unk_04 == 0xE8) && (temp_s3->unk_06 == 0)) {
        return;
    }

    if ((temp_s3->unk_04 >= 0xE) && (temp_s3->unk_06 >= 0xE)) {
        Ui_DrawGradientPanel(temp_s3->unk_00, temp_s3->unk_02, temp_s3->unk_04, temp_s3->unk_06, &sp54, &sp54);
    }

    if ((temp_s3->unk_04 != 0xE8) || (temp_s3->unk_06 != 0x70)) {
        return;
    }

    Font_BeginTranslucentTextRendering();
    Font_SetActive(0x10, 0);
    Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
    temp_v0 = Text_GetString(NULL, 0, gTradeStrings, 3);
    tmp = (temp_s3->unk_00 - (Font_MeasureTextExtent(0, 0, temp_v0) / 2)) + 0x74;
    Font_Printf(tmp, temp_s3->unk_02 + 0x10, temp_v0);

    for (i = 0; i < 2; i++) {
        sp4C[0] = Text_GetString(NULL, 0, gTradeStrings, 4);
        sp4C[1] = Text_GetString(NULL, 0, gTradeStrings, 5);
        if (i != D_82F210D4) {
            Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
        } else {
            Gfx_SetEnvColor(0xFF, 0xFF, 0, 0xFF);
        }
        // clang-format off
        tmp = (temp_s3->unk_00 - (Font_MeasureTextExtent(0, 0, sp4C[i]) / 2)) + 0x74; Font_Printf(tmp, temp_s3->unk_02 + (i * 0x1C) + 0x2C, sp4C[i]);
        // clang-format on
    }

    Font_EndTexturedTextRendering();
}

void Trade_DrawBoxMachineBanner(unk_D_82F20A40* arg0) {
    UNUSED s32 pad;
    char* sp48;
    unk_D_82F20A40_00E* temp_s0 = &arg0->unk_36;
    Color_RGB8 sp40 = { 0x64, 0x1E, 0x1E };

    if (arg0->unk_04 == 0) {
        return;
    }

    if ((arg0->unk_40 == NULL) || (arg0->unk_44 == NULL)) {
        return;
    }

    if ((arg0->unk_36.unk_04 != arg0->unk_40->unk_04) || (arg0->unk_36.unk_06 != arg0->unk_40->unk_06)) {

        if ((temp_s0->unk_04 >= 0xE) && (temp_s0->unk_06 >= 0xE)) {
            Ui_DrawGradientPanel(temp_s0->unk_00, temp_s0->unk_02, temp_s0->unk_04, temp_s0->unk_06, &sp40, &sp40);
        }

        if ((temp_s0->unk_04 >= arg0->unk_44->unk_04) && (temp_s0->unk_06 >= arg0->unk_44->unk_06)) {
            Font_BeginTranslucentTextRendering();
            Font_SetActive(0x10, 0);
            Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
            Font_SetLineHeight(0x1A);

            switch (arg0->unk_04) {
                case 1:
                    sp48 = Text_GetString(NULL, 0, gTradeStrings, 6);
                    Font_Printf((temp_s0->unk_00 + (temp_s0->unk_04 / 2)) - (Font_MeasureTextExtent(0, 0, sp48) / 2),
                                  temp_s0->unk_02 + 0x10, sp48);
                    break;

                case 2:
                    sp48 = Text_GetString(NULL, 0, gTradeStrings, 7);
                    Font_Printf((temp_s0->unk_00 + (temp_s0->unk_04 / 2)) - (Font_MeasureTextExtent(0, 0, sp48) / 2),
                                  temp_s0->unk_02 + 0x10, sp48);
                    break;

                case 3:
                    sp48 = Text_GetString(NULL, 0, gTradeStrings, 8);
                    Font_Printf((temp_s0->unk_00 + (temp_s0->unk_04 / 2)) - (Font_MeasureTextExtent(0, 0, sp48) / 2),
                                  temp_s0->unk_02 + 0x10, sp48);
                    break;

                case 4:
                    sp48 = Text_GetString(NULL, 0, gTradeStrings, 9);
                    Font_Printf((temp_s0->unk_00 + (temp_s0->unk_04 / 2)) - (Font_MeasureTextExtent(0, 0, sp48) / 2),
                                  temp_s0->unk_02 + 0x10, sp48);
                    break;
            }

            Font_EndTexturedTextRendering();
        }
    }
}

void Trade_DrawBoxMachineTransferArrows(s16 arg0, s16 arg1) {
    static s16 D_82F13F5C = 0;

    s16 sp86 = ROUND_MAX(2.0f * SINS(D_82F13F5C));

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPLoadTextureBlock(gDisplayListHead++, D_302AC68, G_IM_FMT_RGBA, G_IM_SIZ_16b, 48, 24, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(arg0 + sp86, arg1, 0x30, 0x18, 0, 0, 0x400, 0x400, 0);
    Gfx_DrawTexturedRectClipped((arg0 - sp86) + 0x10, arg1 + 0x28, 0x30, 0x18, 0x600, 0, -0x400, 0x400, 0);

    gDPLoadTextureBlock(gDisplayListHead++, D_302B568, G_IM_FMT_RGBA, G_IM_SIZ_16b, 48, 24, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    Gfx_DrawTexturedRectClipped(arg0 + sp86, arg1 + 0x18, 0x30, 0x18, 0, 0, 0x400, 0x400, 0);
    Gfx_DrawTexturedRectClipped((arg0 - sp86) + 0x10, arg1 + 0x40, 0x30, 0x18, 0x600, 0, -0x400, 0x400, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    D_82F13F5C += 0x1000;
}

void Trade_DrawBoxMachineCursor(s16 arg0) {
    static s16 D_82F13F60 = 0;

    s16 sp1E;
    UNUSED s16 sp1C;
    s16 sp1A;
    s32 var_v1 = 0;

    switch (arg0) {
        case 2:
            if (D_82F210D2 != -1) {
                var_v1 = 1;
                sp1E = (D_82F210D2 * 0x88) + 0x78;
                sp1A = 0x154;
            }
            break;

        case 8:
            var_v1 = 1;
            sp1E = 0xE4;
            sp1A = (D_82F210D4 * 0x1C) + 0x12A;
            break;
    }

    if (var_v1 != 0) {
        s16 sins = SINS(D_82F13F60) * 3.0f;

        Ui_DrawTextureMarker(sp1E + sins, sp1A);
    }

    D_82F13F60 += 0x1000;
}

void Trade_InitBoxMachine(void) {
    UNUSED s32 pad;
    s32 i;
    MemoryBlock* sp1C = MainPool_AllocState(main_pool_get_available(), 0);

    D_82F210C8 = process_geo_layout(sp1C, D_82F13E8C);
    D_82F210CC = process_geo_layout(sp1C, D_82F13E58);
    MainPool_FinalizeAllocation(sp1C);

    D_82F20A40.unk_00 = 0;
    D_82F20A40.unk_02 = 0;
    D_82F20A40.unk_04 = 0;

    for (i = 0; i < 2; i++) {
        D_82F210D8[i] = -1;
    }

    D_82F210D8[0] = GbSave_GetActivePort();
    D_82F210D2 = 0;
    Trade_SetupBoxSlots(D_82F210D8[0]);
}

void Trade_UpdateBoxMachine(void) {
    unk_D_82F20A40* ptr = &D_82F20A40;

    if (ptr->unk_00 == 0) {
        return;
    }

    switch (ptr->unk_00) {
        case 1:
            Trade_UpdateBoxMachineFlowOpen(ptr, 1);
            break;

        case 10:
            Trade_UpdateBoxMachineFlowOpen(ptr, 0);
            break;

        case 2:
            Trade_UpdateBoxMachineFlowSelect(ptr);
            break;

        case 3:
            Trade_UpdateBoxMachineFlowFrameMove(ptr);
            break;

        case 4:
            Trade_UpdateBoxMachineFlowConfirmWait(ptr);
            break;

        case 5:
            Trade_UpdateBoxMachineFlowFrameReturn(ptr);
            break;

        case 6:
            Trade_UpdateBoxMachineFlowPanelsFull(ptr);
            break;

        case 7:
            Trade_UpdateBoxMachineFlowConfirmOpen(ptr);
            break;

        case 8:
            Trade_UpdateBoxMachineFlowConfirmInput(ptr);
            break;

        case 9:
            Trade_UpdateBoxMachineFlowConfirmDone(ptr);
            break;

        case 11:
            Trade_UpdateBoxMachineFlowClose(ptr);
            break;
    }

    Trade_UpdateBoxSlotTransforms();
}

void Trade_DrawBoxMachine(void) {
    unk_D_82F20A40* ptr = &D_82F20A40;

    if (ptr->unk_00 != 0) {
        GeoRender_AdvanceFrameCounter();
        Trade_DrawBoxMachineTopBar(&D_82F20A40);
        Trade_DrawBoxMachineSlots(&D_82F20A40);
        Trade_DrawBoxMachineTitle(&D_82F20A40);
        Trade_DrawBoxMachineConfirm(&D_82F20A40);
        Geo_RenderRootNode(D_82F210C8);
        Trade_DrawBoxMachineCursor(ptr->unk_00);
        Trade_DrawBoxMachineBanner(&D_82F20A40);
    }
}
