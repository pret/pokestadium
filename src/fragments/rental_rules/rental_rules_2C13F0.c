#include "rental_rules.h"
#include "src/poke_icon.h"
#include "src/graphics_textures.h"
#include "src/ui_graphics.h"
#include "src/gb_data.h"
#include "src/text_system.h"
#include "src/audio_sfx.h"
#include "src/gfx_rect.h"

static u16 D_83003EF0[151][0x640];
static unk_D_83079E70 D_83079E70;

s32 RentalRules_SpeciesMatchesCategory(s16 arg0, s16 arg1) {
    s32 var_v1;
    s16 sp2;

    if ((arg0 <= 0) || (arg0 >= 0x98)) {
        return 0;
    }

    var_v1 = 0;
    switch (arg1) {
        case 0:
            var_v1 = 1;
            break;

        case 1:
            sp2 = 1;
            break;

        case 2:
            sp2 = 2;
            break;

        case 3:
            sp2 = 1;
            break;

        case 4:
            sp2 = 8;
            break;

        case 5:
            sp2 = 0x10;
            break;

        case 6:
            sp2 = 0x20;
            break;

        case 7:
            var_v1 = 1;
            break;

        case 8:
            var_v1 = 1;
            break;
    }

    if (var_v1 == 0) {
        if (D_8006FEE8[arg0][8] & sp2) {
            var_v1 = 1;
        } else {
            var_v1 = 0;
        }
    }
    return var_v1;
}

s16 RentalRules_CountMatchingSpecies(s16 arg0) {
    s16 i;
    s16 var_s1 = 0;

    for (i = 1; i < 152; i++) {
        if (RentalRules_SpeciesMatchesCategory(i, arg0) != 0) {
            var_s1++;
        }
    }

    return var_s1;
}

s32 RentalRules_BuildSpeciesPage(unk_D_83079E70_000* arg0, s16 arg1, s16 arg2) {
    s32 i;
    s16 var_a0;
    s32 var_s1;
    s32 var_s3;

    for (i = 0; i < 6; i++) {
        arg0->unk_00[i].unk_00 = 0;
        arg0->unk_00[i].unk_02 = 0;
    }

    var_s3 = 0;
    var_s1 = (arg1 * 6) + 1;
    for (i = 0; i < 6; i++, var_s1++) {
        var_a0 = var_s1;
        if ((var_a0 <= 0) || (var_a0 >= 0x98)) {
            var_a0 = 0;
        } else {
            var_s3++;
        }
        arg0->unk_00[i].unk_00 = var_a0;

        if (RentalRules_SpeciesMatchesCategory(var_a0, arg2) != 0) {
            arg0->unk_00[i].unk_02 = 1;
        } else {
            arg0->unk_00[i].unk_02 = 0;
        }
    }

    return var_s3;
}

unk_D_83079E70_000* RentalRules_AdvancePageNode(unk_D_83079E70_000* arg0, s32 arg1) {
    while (arg1-- > 0) {
        arg0 = arg0->unk_18;
    }

    return arg0;
}

s32 RentalRules_ScrollPageUp(unk_D_83079E70* arg0) {
    s32 sp1C = 0;

    if (RentalRules_BuildSpeciesPage(arg0->unk_10->unk_1C, arg0->unk_08 - 1, D_800AE540.unk_0001) > 0) {
        arg0->unk_00 = 3;
        arg0->unk_02 = 4;
        arg0->unk_08--;
        arg0->unk_10 = arg0->unk_10->unk_1C;
        arg0->unk_0A = -1;
        arg0->unk_0C = -1;
        sp1C = 1;
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
    }

    return sp1C;
}

s32 RentalRules_ScrollPageDown(unk_D_83079E70* arg0) {
    s32 sp1C = 0;

    if (RentalRules_BuildSpeciesPage(RentalRules_AdvancePageNode(arg0->unk_10, 5), arg0->unk_08 + 5, D_800AE540.unk_0001) > 0) {
        arg0->unk_00 = 3;
        arg0->unk_02 = 4;
        arg0->unk_08++;
        arg0->unk_10 = arg0->unk_10->unk_18;
        arg0->unk_0A = 1;
        arg0->unk_0C = -1;
        sp1C = 1;
        Audio_PlaySoundEffectById(SFX_MENU_SCROLL);
    }

    return sp1C;
}

void RentalRules_ListUpdateOpen(unk_D_83079E70* arg0) {
    arg0->unk_02--;
    arg0->unk_04 = ((5 - arg0->unk_02) << 0xA) / 5;
    if (arg0->unk_02 <= 0) {
        arg0->unk_00 = 2;
        arg0->unk_02 = 0;
        arg0->unk_0C = 2;
    }
}

void RentalRules_ListUpdateShown(unk_D_83079E70* arg0) {
    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A | BTN_B)) {
        arg0->unk_00 = 4;
        arg0->unk_02 = 5;
        arg0->unk_0C = -1;
        Audio_PlaySoundEffectById(SFX_MENU_BACK);
    } else if (BTN_IS_DOWN(gPlayer1Controller, BTN_DUP)) {
        RentalRules_ScrollPageUp(arg0);
    } else if (BTN_IS_DOWN(gPlayer1Controller, BTN_DDOWN)) {
        RentalRules_ScrollPageDown(arg0);
    }
}

void RentalRules_ListUpdateScrolling(unk_D_83079E70* arg0) {
    s32 var_v1;

    arg0->unk_02--;
    if (arg0->unk_02 <= 0) {
        var_v1 = 0;
        if (BTN_IS_DOWN(gPlayer1Controller, BTN_DUP)) {
            var_v1 = RentalRules_ScrollPageUp(arg0);
        } else if (BTN_IS_DOWN(gPlayer1Controller, BTN_DDOWN)) {
            var_v1 = RentalRules_ScrollPageDown(arg0);
        }

        if (var_v1 == 0) {
            arg0->unk_00 = 2;
            arg0->unk_02 = 0;
            arg0->unk_0C = 2;
        }
    }
}

void RentalRules_ListUpdateClose(unk_D_83079E70* arg0) {
    arg0->unk_02--;
    arg0->unk_04 = (arg0->unk_02 << 0xA) / 5;
    if (arg0->unk_02 <= 0) {
        arg0->unk_00 = 0;
        arg0->unk_02 = 0;
        arg0->unk_0C = -1;
    }
}

void RentalRules_DrawScrollbar(s16 arg0, s16 arg1, unk_D_83079E70* arg2) {
    static s16 D_83003B70 = 0;

    s16 temp_t0;

    gSPDisplayList(gDisplayListHead++, D_8006F558);
    gDPSetEnvColor(gDisplayListHead++, 130, 130, 220, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 60, 60, 150, 255);

    Gfx_DrawTextureIa8(arg0, arg1, 0x10, 8, D_200A200, 0x10, 0);
    Gfx_DrawTextureIa8(arg0, arg1 + 0x114, 0x10, 8, D_200A280, 0x10, 0);
    Gfx_DrawTexturedRectClipped(arg0, arg1 + 8, 0x10, 0x10C, 0, 0, 0x400, 0, 0);

    if (arg2->unk_00 != 3) {
        temp_t0 = (arg2->unk_08 * 0x10C) / 21;
    } else if (arg2->unk_0A > 0) {
        temp_t0 = (((arg2->unk_08 * 4) - arg2->unk_02) * 0x10C) / 84;
    } else {
        temp_t0 = (((arg2->unk_08 * 4) + arg2->unk_02) * 0x10C) / 84;
    }

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    if (D_83003B70 < 4) {
        Gfx_DrawTextureRgba16(arg0 - 4, (arg1 + temp_t0) - 4, 0x18, 0x18, D_200A300, 0x18, 0);
    } else {
        Gfx_DrawTextureRgba16(arg0 - 4, (arg1 + temp_t0) - 4, 0x18, 0x18, D_200A780, 0x18, 0);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    Font_BeginTranslucentTextRendering();
    D_83003B70 = (D_83003B70 + 1) % 8;
}

void RentalRules_DrawCloseButtonIcon(s16 arg0, s16 arg1) {
    gDPPipeSync(gDisplayListHead++);

    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetEnvColor(gDisplayListHead++, 60, 60, 160, 255);

    Gfx_DrawTextureI4(arg0, arg1, 0x20, 0x14, D_4000DD0, 0x20, 0);
}

void RentalRules_DrawSpeciesPage(s16 arg0, s16 arg1, unk_D_83079E70_000* arg2) {
    UNUSED s32 pad;
    s32 i;
    Color_RGB8* var_v0;
    Color_RGB8 sp78 = { 0x3C, 0x3C, 0xA0 };
    Color_RGB8 sp74 = { 0x64, 0x1E, 0x1E };
    Color_RGB8 sp70 = { 0x1E, 0x1E, 0x64 };
    s16 temp_s0;

    for (i = 0; i < 6; i++) {
        if (arg2->unk_00[i].unk_00 != 0) {
            if (arg2->unk_00[i].unk_02 != 0) {
                var_v0 = &sp78;
            } else {
                var_v0 = &sp74;
            }
        } else {
            var_v0 = &sp70;
        }
        RentalRules_DrawFilledPanel(arg0 + i * 0x54, arg1, 0x54, 0x3C, var_v0->r, var_v0->g, var_v0->b);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    for (i = 0; i < 6; i++) {
        temp_s0 = arg2->unk_00[i].unk_00;
        if (temp_s0 != NULL) {
            Gfx_DrawTextureRgba16(arg0 + (i * 0x54) + 0x16, arg1 + 3, 0x28, 0x28, D_83003EF0[temp_s0 - 1], 0x28, 0);
        }
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    Font_BeginTranslucentTextRendering();
    Font_SetActive(4, 0);
    Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);

    for (i = 0; i < 6; i++) {
        temp_s0 = arg2->unk_00[i].unk_00;
        if (temp_s0 != NULL) {
            Font_Printf(arg0 + (i * 0x54) + 2, arg1 + 0x2A, RentalRules_GetPokemonName(temp_s0));
        }
    }

    Font_EndTexturedTextRendering();
}

void RentalRules_ListInit(s32 arg0) {
    unk_D_83079E70* ptr = &D_83079E70;
    s32 i;

    ptr->unk_00 = 0;
    ptr->unk_04 = 0;

    for (i = 0; i < 6; i++) {
        ptr->unk_14[i].unk_18 = &ptr->unk_14[(i + 1) % 6];
        ptr->unk_14[i].unk_1C = &ptr->unk_14[(i + 5) % 6];
    }

    if (arg0 != 0) {
        for (i = 0; i < 151; i++) {
            PokeIcon_LoadModelTextureForMon(D_83003EF0[i], i + 1, NULL);
        }
    }
}

void RentalRules_ListUpdate(void) {
    unk_D_83079E70* ptr = &D_83079E70;

    if (ptr->unk_00 != 0) {
        switch (ptr->unk_00) {
            case 1:
                RentalRules_ListUpdateOpen(&D_83079E70);
                break;

            case 2:
                RentalRules_ListUpdateShown(&D_83079E70);
                break;

            case 3:
                RentalRules_ListUpdateScrolling(&D_83079E70);
                break;

            case 4:
                RentalRules_ListUpdateClose(&D_83079E70);
                break;
        }
    }
}

void RentalRules_ListDraw(void) {
    s16 spA6;
    s16 spA4;
    unk_D_83079E70* ptr = &D_83079E70;

    if (ptr->unk_04 == 0) {
        return;
    }

    spA6 = (((0x400 - ptr->unk_04) * 0x108) / 1024) + 0x38;
    spA4 = (((0x400 - ptr->unk_04) * 0xA8) / 1024) + 0x5C;
    RentalRules_DrawWindowFrame(spA6, spA4, (ptr->unk_04 * 0x210) / 1024, (ptr->unk_04 * 0x150) / 1024);

    if (ptr->unk_04 >= 0x400) {
        UNUSED s32 pad;
        s32 i;
        unk_D_83079E70_000* var_s0;

        RentalRules_DrawFilledPanel(spA6, spA4, 0x210, 0x24, 0x1E, 0x64, 0x64);
        RentalRules_DrawFilledPanel(spA6, spA4 + 0x24, 0x18, 0x12C, 0x1E, 0x1E, 0x64);
        RentalRules_DrawScrollbar(spA6 + 4, spA4 + 0x2C, ptr);

        gSPDisplayList(gDisplayListHead++, D_8006F518);

        RentalRules_DrawCloseButtonIcon(spA6 + 8, spA4 + 8);

        gSPDisplayList(gDisplayListHead++, D_8006F630);

        Font_BeginTranslucentTextRendering();
        Gfx_SetEnvColor(0xFF, 0xFF, 0xFF, 0xFF);
        Font_SetActive(8, 0);
        Text_SetNumberToken(3, ptr->unk_06);
        {
            char sp4C[64];
            Font_Printf(spA6 + 0x2C, spA4 + 8, Text_GetString(sp4C, sizeof(sp4C), D_830039C0, 3));
        }
        Font_EndTexturedTextRendering();

        if (ptr->unk_0C == 0) {
            return;
        }

        if (ptr->unk_00 == 3) {
            s16 sp4A = spA4 - ((ptr->unk_0A * 0x3C * (4 - ptr->unk_02)) / 4);
            Gfx_SetScissorRect(&gDisplayListHead, spA6 + 0x18, spA4 + 0x24, 0x1F8, 0x12C);
            if (ptr->unk_0A > 0) {
                var_s0 = ptr->unk_10->unk_1C;
                for (i = 0; i < 6; i++) {
                    RentalRules_DrawSpeciesPage(spA6 + 0x18, sp4A + 0x24 + i * 0x3C, var_s0);
                    var_s0 = var_s0->unk_18;
                }
            } else {
                var_s0 = ptr->unk_10;
                for (i = 0; i < 6; i++) {
                    RentalRules_DrawSpeciesPage(spA6 + 0x18, sp4A - 0x18 + i * 0x3C, var_s0);
                    var_s0 = var_s0->unk_18;
                }
            }
            Gfx_SetScissorRect(&gDisplayListHead, 0, 0, 0x280, 0x1E0);
        } else {
            var_s0 = ptr->unk_10;
            for (i = 0; i < 5; i++) {
                RentalRules_DrawSpeciesPage(spA6 + 0x18, spA4 + 0x24 + i * 0x3C, var_s0);
                var_s0 = var_s0->unk_18;
            }
        }

        if (ptr->unk_0C > 0) {
            ptr->unk_0C -= 1;
        }
    }

    if (1) {}
}

void RentalRules_ListOpen(void) {
    unk_D_83079E70* ptr = &D_83079E70;
    s32 i;

    ptr->unk_00 = 1;
    ptr->unk_02 = 5;
    ptr->unk_04 = 0;
    ptr->unk_08 = 0;
    ptr->unk_0A = 0;
    ptr->unk_0C = -1;
    ptr->unk_06 = RentalRules_CountMatchingSpecies(D_800AE540.unk_0001);
    ptr->unk_10 = &ptr->unk_14[0];

    for (i = 0; i < 5; i++) {
        RentalRules_BuildSpeciesPage(&ptr->unk_14[i], i, D_800AE540.unk_0001);
    }
}

s32 RentalRules_ListIsActive(void) {
    s32 ret;

    if (D_83079E70.unk_00 != 0) {
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}

s32 RentalRules_ListGetProgress(void) {
    return D_83079E70.unk_04;
}
