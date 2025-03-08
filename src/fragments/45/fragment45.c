#include "fragment45.h"
#include "src/19840.h"
#include "src/1CF30.h"
#include "src/20330.h"
#include "src/2E110.h"
#include "src/30640.h"
#include "src/3FB0.h"
#include "src/20470.h"
#include "src/49790.h"
#include "src/6A40.h"
#include "src/controller.h"
#include "src/fragments/39/fragment39.h"
#include "src/fragments/43/fragment43.h"
#include "src/memory.h"
#include "src/stage_loader.h"

s32 D_836032F0;
s32 D_836032F4;
BinArchive* D_836032F8;
unk_D_83407B38 D_83603300;
s32 D_836033B4;
s32 D_836033B8;
s32 D_836033BC;
u16 D_836033C0;
s32 D_836033C4;
s32 D_836033C8;

void func_83600020(unk_D_83407B38* arg0) {
    s32 i;
    s32 sp40;
    unk_D_83403C60* temp_s0;
    s32 temp_v0;
    s32 idx;

    sp40 = 0;

    for (i = 35; i >= 0; i--) {
        if (func_800318C4(&D_83403C60[i]) == 0) {
            idx = i;
            while ((idx > 0) && func_800318C4(&D_83403C60[idx - 1]) == 0) {
                idx--;
            }
            sp40 = idx;
            break;
        }
    }

    for (i = 0; i < 24; i++) {
        if (D_83403C00[i] != 0) {
            idx = func_834007B4(D_83403C60, 0x24, sp40, 0);

            temp_s0 = arg0->unk_20[i]->unk_18;

            D_83403C60[idx] = *temp_s0;

            temp_v0 = func_83400870(D_83407ABC, 4);
            if (temp_v0 >= 0) {
                D_83407ABC[temp_v0] = *temp_s0;
            }

            temp_v0 = func_83400870(D_83407AC0, 0x10);
            if (temp_v0 >= 0) {
                D_83407AC0[temp_v0] = *temp_s0;
            }
        }
    }
}

s32 func_83600288(void) {
    s32 i;
    s32 sp28 = 0;

    for (i = 0; i < 0x18; i++) {
        if ((func_800318C4(&D_83402EE0[i]) != 0) && (D_83403C00[i] == 0)) {
            sp28 = 1;
            break;
        }
    }

    return sp28;
}

void func_83600310(unk_D_83407B38* arg0) {
    UNUSED s32 pad;
    s32 sp18 = arg0->unk_08 + 1;

    if (func_83402124(arg0, arg0->unk_08 - 1) > 0) {
        D_836033C4 = 1;
    } else {
        D_836033C4 = 0;
    }

    if (func_83402124(arg0, sp18) > 0) {
        D_836033C8 = 1;
    } else {
        D_836033C8 = 0;
    }
}

s32 func_83600384(unk_D_83407B38* arg0) {
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp1C;
    s32 idx;
    s32 i;
    unk_func_80031270* ptr;

    sp54 = 0;
    sp50 = arg0->unk_08;
    sp4C = arg0->unk_00;
    sp48 = arg0->unk_00 % 3;
    sp44 = arg0->unk_00 / 3;
    sp40 = 0;
    sp3C = 0;

    if (func_8003181C(arg0->unk_20, 0x25) != -1) {
        return 0;
    }

    if (gPlayer1Controller->buttonPressed & 0x800) {
        sp44--;
        if (sp44 < 0) {
            sp44 = 2;
        }
    }

    if (gPlayer1Controller->buttonPressed & 0x400) {
        sp44++;
        if (sp44 >= 3) {
            sp44 = 0;
        }
    }

    if (gPlayer1Controller->buttonPressed & 0x200) {
        sp48--;
        if ((sp44 == 2) && (sp48 == 1)) {
            sp48--;
        }

        if (sp44 < 2) {
            if (sp48 < 0) {
                if (D_836033C4 != 0) {
                    sp48 = 2;
                } else {
                    sp48 = 0;
                }
                sp40 = 1;
            }
        } else if (sp48 < 0) {
            sp48 = 2;
        }
    }

    if (gPlayer1Controller->buttonPressed & 0x100) {
        sp48++;
        if ((sp44 == 2) && (sp48 == 2)) {
            sp48++;
        }

        if (sp44 < 2) {
            if (sp48 >= 3) {
                if (D_836033C8 != 0) {
                    sp48 = 0;
                } else {
                    sp48 = 2;
                }
                sp3C = 1;
            }
        } else if (sp48 >= 3) {
            sp48 = 0;
        }
    }

    sp1C = sp44 * 3;

    arg0->unk_00 = sp1C + sp48;
    if (sp4C != arg0->unk_00) {
        D_836032F4 = 0;
        func_80048B90(1);
    }

    if ((gPlayer1Controller->buttonPressed & 0x20) || (sp40 != 0)) {
        s32 tmp = arg0->unk_08;
        if (D_836033C4 != 0) {
            tmp--;
            arg0->unk_08 = tmp;
        }
    } else if ((gPlayer1Controller->buttonPressed & 0x10) || (sp3C != 0)) {
        s32 tmp = arg0->unk_08;
        if (D_836033C8 != 0) {
            tmp++;
            arg0->unk_08 = tmp;
        }
    } else if (gPlayer1Controller->buttonPressed & 0x8000) {
        idx = (arg0->unk_08 * arg0->unk_14) + arg0->unk_00;
        if (sp1C < 6) {
            if (func_800317D8(arg0->unk_20[idx]) != 0) {
                if (D_83403C00[idx] == 0) {
                    if (D_836033B4 < D_836033B8) {
                        D_83403C00[idx] = 1;
                        D_836033B4++;
                        func_80048B90(0xD);
                    } else {
                        D_836032F4 = 1;
                        func_80048B90(8);
                    }
                } else {
                    D_83403C00[idx] = 0;
                    D_836033B4--;
                    func_80048B90(3);
                }
            } else {
                func_80048B90(8);
            }
        } else if (sp48 == 0) {
            sp54 = 1;
            func_80048B90(0x1C);
        } else if (func_83600288() != 0) {
            D_836032F0 = 2;
            D_836032F4 = 2;
            func_80048B90(0x31);
        } else {
            sp54 = 1;
            func_80048B90(3);
        }
    } else if (gPlayer1Controller->buttonPressed & 4) {
        idx = (arg0->unk_08 * arg0->unk_14) + arg0->unk_00;
        if ((sp1C < 6) && (func_800317D8(arg0->unk_20[idx]) != 0)) {
            func_80048B90(0x19);
            func_83400694(arg0->unk_20[idx]->unk_18);
            sp54 = 2;
        } else {
            func_80048B90(8);
        }
    }

    if (sp50 != arg0->unk_08) {
        D_836032F4 = 0;
        func_80048B90(0x27);
        func_83600310(arg0);

        for (i = 0; i < arg0->unk_14; i++) {
            ptr = arg0->unk_20[(arg0->unk_08 * arg0->unk_14) + i];

            if (ptr != NULL) {
                ptr->unk_00 = 0;
            }
        }
    }
    return sp54;
}

void func_8360086C(s32 arg0) {
    s32 i;

    D_836032F0 = 0;
    D_836032F4 = 0;
    D_836033B4 = 0;

    for (i = 0; i < 24; i++) {
        if (D_83403C00[i] != 0) {
            D_836033B4++;
        }
    }

    D_836033B8 = func_83400704(D_83403C60, 0x24, 0);
    D_836033C0 = 0xFFE3;

    if (arg0 != 0) {
        D_836033BC = 1;
    } else {
        D_836033BC = 0;
    }

    func_83401D68(&D_83603300, 0x88, 0x66, 6, 3, func_80019760(5), D_836032F8, D_83402EE0, 0x18, 1);

    if (D_83407AF8.unk_00 != -1) {
        func_834021EC(&D_83603300, &D_83407AF8);
    }

    func_83600310(&D_83603300);
}

void func_836009A4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 sp50;
    u8* var_s6;
    s32 i;
    u8* tmp_s6;

    sp50 = arg2 / 40;

    if (arg3 != 0) {
        var_s6 = D_4004848;
    } else {
        var_s6 = D_4004AC8;
    }
    tmp_s6 = var_s6;

    if (arg3 == 0) {
        gSPDisplayList(gDisplayListHead++, D_8006F498);

        func_8001C604(arg0, arg1, arg2, 4, 0, 0, 0, 0x80);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPLoadTextureBlock(gDisplayListHead++, var_s6, G_IM_FMT_IA, G_IM_SIZ_8b, 40, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 128);

    for (i = 0; i < sp50; i++) {
        func_8001C330(arg0 + 4 + i * 0x28, arg1 + 4, 0x28, 0x10, 0, 0, 0x400, 0x400, 0);
    }

    gDPPipeSync(gDisplayListHead++);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);

    if (var_s6 != tmp_s6) {
        gDPLoadTextureBlock(gDisplayListHead++, var_s6, G_IM_FMT_IA, G_IM_SIZ_8b, 40, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    }

    for (i = 0; i < sp50; i++) {
        func_8001C330(arg0 + i * 0x28, arg1, 0x28, 0x10, 0, 0, 0x400, 0x400, 0);
    }
}

void func_83600D68(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    gSPDisplayList(gDisplayListHead++, D_8006F4C0);
    gDPSetFillColor(gDisplayListHead++, 0x00000001);
    gDPFillRectangle(gDisplayListHead++, arg0, arg1, (arg0 + arg2) - 1, (arg1 + arg3) - 1);
    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_83600E20(s32 arg0, s32 arg1, s16 arg2) {
    s16 end = 16;
    s32 i;
    UNUSED s32 pad;
    s32 spC0;
    s32 spBC;
    s32 temp_v0_2;

    spC0 = 0x30;
    spBC = (s32)ROUND_MAX((SINS(arg2) + 1.0f) * 255.0f * 0.5f) & 0xFF;

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    for (i = 0; i < spC0; i += end) {
        temp_v0_2 = CLAMP_MAX(end, spC0 - i);

        gDPLoadTextureBlock(gDisplayListHead++, &D_4004D48[i * spC0], G_IM_FMT_RGBA, G_IM_SIZ_16b, spC0, temp_v0_2, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);

        func_8001C330(arg0, arg1 + i, spC0, temp_v0_2, 0, 0, 0x400, 0x400, 0);
    }

    gDPPipeSync(gDisplayListHead++);
    gDPSetCombineLERP(gDisplayListHead++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                      PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 255, 255, 255, spBC);
    gDPSetEnvColor(gDisplayListHead++, 255, 55, 0, 255);

    spC0 = 0x30;

    gDPLoadTextureBlock(gDisplayListHead++, D_4006748, G_IM_FMT_IA, G_IM_SIZ_8b, spC0, spC0, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    func_8001C330(arg0, arg1, spC0, spC0, 0, 0, 0x400, 0x400, 0);
}

void func_83601314(s32 arg0, s32 arg1, s16 arg2) {
    s32 temp_v0_2;
    s32 end = 0x20;
    s32 i;
    s32 spC0;
    s32 spBC;
    UNUSED s32 pad;

    spC0 = 0x20;
    spBC = (s32)ROUND_MAX((SINS(arg2) + 1.0f) * 255.0f * 0.5f) & 0xFF;

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    for (i = 0; i < spC0; i += end) {
        temp_v0_2 = CLAMP_MAX(end, spC0 - i);

        gDPLoadTextureBlock(gDisplayListHead++, &D_4005F48[i * spC0], G_IM_FMT_RGBA, G_IM_SIZ_16b, spC0, temp_v0_2, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);

        func_8001C330(arg0, arg1 + i, spC0, temp_v0_2, 0, 0, 0x400, 0x400, 0);
    }

    gDPPipeSync(gDisplayListHead++);
    gDPSetCombineLERP(gDisplayListHead++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                      PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 255, 255, 255, spBC);
    gDPSetEnvColor(gDisplayListHead++, 255, 55, 0, 255);

    spC0 = 0x20;

    gDPLoadTextureBlock(gDisplayListHead++, D_4007048, G_IM_FMT_IA, G_IM_SIZ_8b, spC0, spC0, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    func_8001C330(arg0, arg1, spC0, spC0, 0, 0, 0x400, 0x400, 0);
}

void func_83601800(unk_D_83407B38* arg0) {
    static s16 D_83603280 = 0;

    s32 temp_s0_2;
    s32 temp_s1;
    char sp70[16];
    s32 temp_s4;
    s32 temp_s5;
    s32 i;
    unk_func_80031270* temp_s0;

    for (i = 0; i < arg0->unk_14; i++) {
        temp_s5 = (arg0->unk_08 * arg0->unk_14) + i;
        temp_s0 = arg0->unk_20[temp_s5];
        if ((func_800317D8(temp_s0) != 0) && (temp_s0->unk_00 == 2)) {
            temp_s4 = (i / 3) * 0x6E;
            temp_s1 = (i % 3) * 0xA4;
            func_834018C0(temp_s0->unk_08->img_p, temp_s1 + 0x58, temp_s4 + 0x6E, 0x88, 0x66, 8, 0);
            if (D_83403C00[temp_s5] != 0) {
                func_83600E20(temp_s1 + 0xB0, temp_s4 + 0xA6, D_83603280);
            }
        }
        func_8001F3F4();
        func_8001EBE0(8, 0);
        sprintf(sp70, "%d", temp_s5 + 1);
        temp_s0_2 = func_8001F5B0(0, 0, sp70);
        func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
        func_8001F1E8((((i % 3) * 0xA4) - temp_s0_2) + 0x54, ((i / 3) * 0x6E) + 0x6E, sp70);
        func_8001F444();
    }

    D_83603280 += 0x400;
}

void func_83601A3C(unk_D_83407B38* arg0) {
    s32 temp_hi = arg0->unk_00 % 3;
    s32 temp_lo = arg0->unk_00 / 3;
    s32 var_a0;

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    if (temp_lo < 2) {
        func_83401B48((temp_hi * 0xA4) + 0x58, (temp_lo * 0x6E) + 0x6E, 0x88, 0x66);
        return;
    }

    var_a0 = -1;
    switch (temp_hi) {
        case 0:
            var_a0 = 0x30;
            break;

        case 1:
        case 2:
            var_a0 = 0x1E1;
            break;
    }

    if (var_a0 >= 0) {
        func_83401B48(var_a0, 0x172, 0x6C, 0x45);
    }
}

void func_83601B48(s32 arg0, s32 arg1) {
    static Color_RGBA8 D_83603284 = { 0x9A, 0x37, 0x54, 0xFF };
    static Color_RGBA8 D_83603288 = { 0xC3, 0x54, 0x84, 0xFF };
    static s16 D_8360328C = 0;

    char* sp84;
    s32 sp78;
    s32 sp7C;
    s32 sp80;
    Color_RGBA8 sp74;
    Color_RGBA8 sp70;

    sp84 = func_83402374(2);
    sp74 = D_83603284;
    sp70 = D_83603288;
    sp7C = SINS(D_8360328C) * 4.0f;
    func_83401110(arg0, arg1, 0x1B6, &sp74, &sp70);

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    gDPLoadTextureTile(gDisplayListHead++, D_4003A38, G_IM_FMT_IA, G_IM_SIZ_8b, 100, 36, 0, 0, 99, 35, 0,
                       G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                       G_TX_NOLOD);

    func_8001C330(arg0 + 0x36, arg1 - 3, 0x64, 0x24, 0, 0, 0x400, 0x400, 0);
    func_8001C330(arg0 + 0x11C, arg1 - 3, 0x64, 0x24, 0xC60, 0, -0x400, 0x400, 0);

    if (D_836033C4 != 0) {
        sp78 = sp7C;
        sp80 = 0xFF;
    } else {
        sp78 = 0;
        sp80 = 0x80;
    }

    gDPPipeSync(gDisplayListHead++);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sp80);

    func_83401D0C((arg0 - sp78) - 0x27, arg1 + 0x1A, 0);

    if (D_836033C8 != 0) {
        sp78 = sp7C;
        sp80 = 0xFF;
    } else {
        sp78 = 0;
        sp80 = 0x80;
    }

    gDPPipeSync(gDisplayListHead++);
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, sp80);

    func_83401D0C(arg0 + sp78 + 0x1A2, arg1 + 0x1A, 1);
    func_8001F3F4();
    func_8001EBE0(0x10, 0);

    sp78 = (0x1B6 - func_8001F5B0(0, 0, sp84)) / 2;
    func_8001F324(0, 0, 0, 0xFF);
    func_8001F1E8(arg0 + sp78 + 2, arg1 + 5, sp84);
    func_8001F324(0xFF, 0xFF, 0x77, 0xFF);
    func_8001F1E8(arg0 + sp78, arg1 + 3, sp84);
    func_8001F444();

    D_8360328C += 0x1000;
}

void func_83601F28(int arg0, int arg1, s32 arg2, f32 arg3) {
    s32 temp_s2;
    s32 temp_s3;
    f32 tmp = 1024.0f;
    s32 iter = 16;
    s32 spFC = 0x6C;
    s32 spF8 = 0x45;
    s32 temp_ft2 = ROUND_MAX((spFC * arg3) + 0.4f);
    s32 temp_fv1 = ROUND_MAX((spF8 * arg3) + 0.4f);
    s32 i;
    u16* spE4[] = { D_04000000, D_03005F80 };
    s16 spE0[] = { 0x39, 0x37 };
    u16* spDC = spE4[arg2];
    char* spD8 = func_83402374(spE0[arg2]);
    Color_RGB8 spD0[] = {
        { 0xE6, 0xDC, 0x0F },
        { 0xE6, 0x6E, 0x82 },
    };

    if (arg3 <= 0.0f) {
        return;
    }

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    for (i = 0; i < spF8; i += iter) {
        s32 temp_v0_2 = CLAMP_MAX(iter, spF8 - i);
        s32 temp_fv1_2 = ROUND_MAX((temp_v0_2 * arg3) + 0.4f);
        s32 temp_fa0 = ROUND_MAX((i * arg3) + 0.4f);

        gDPLoadTextureTile(gDisplayListHead++, &spDC[i * spFC], G_IM_FMT_RGBA, G_IM_SIZ_16b, spFC, 0, 0, 0, spFC,
                           temp_v0_2 - 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK,
                           G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        func_8001C330(arg0 + ((spFC - temp_ft2) / 2), arg1 + ((spF8 - temp_fv1) / 2) + temp_fa0, temp_ft2, temp_fv1_2,
                      0, 0, tmp / arg3, tmp / arg3, 0);
    }

    temp_s3 = (spFC - func_8001F5B0(0, 0, spD8)) / 2;
    temp_s2 = (spF8 - (func_834006CC(spD8) * 0x14)) / 2;

    func_8001F3F4();
    func_8001EBE0(8, 0);
    func_8001F3B4(0x14);
    func_8001F324(0, 0, 0, 0xFF);
    func_8001F1E8(arg0 + temp_s3 + 2, arg1 + temp_s2 + 2, spD8);
    func_8001F470();
    func_8001F324(spD0[arg2].r, spD0[arg2].g, spD0[arg2].b, 0xFF);
    func_8001F36C(0xFF, 0xFF, 0xFF, 0xFF);
    func_8001F1E8(arg0 + temp_s3, arg1 + temp_s2, spD8);
    func_8001F4C4();
    func_8001F444();
}

void func_83602458(void) {
    static Color_RGB8 D_836032A4 = { 0xCD, 0xD7, 0x9B };
    static Color_RGB8 D_836032A8 = { 0x28, 0x64, 0xAF };
    static Color_RGB8 D_836032AC = { 0xCD, 0xEB, 0x9B };
    static Color_RGB8 D_836032B0 = { 0, 0, 0xAF };

    s32 i;
    s32 r;
    s32 g;
    s32 b;
    s32 end = 0x1E0;
    s32 idx;

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetCombineMode(gDisplayListHead++, G_CC_BLENDPEDECALA, G_CC_BLENDPEDECALA);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPLoadTextureBlock_4b(gDisplayListHead++, D_4007448, G_IM_FMT_I, 128, 64, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 7, 6, G_TX_NOLOD, G_TX_NOLOD);

    idx = 0;
    for (i = 0; i < end; i += 0x40, idx++) {
        s32 temp_v0_2 = CLAMP_MAX(0x40, end - i);

        if (D_836033C0 & (1 << idx)) {
            r = (((D_836032AC.r - D_836032A4.r) * idx) / 8) + D_836032A4.r;
            g = (((D_836032AC.g - D_836032A4.g) * idx) / 8) + D_836032A4.g;
            b = (((D_836032AC.b - D_836032A4.b) * idx) / 8) + D_836032A4.b;

            gDPPipeSync(gDisplayListHead++);

            gDPSetPrimColor(gDisplayListHead++, 0, 0, r, g, b, 255);

            r = (((D_836032B0.r - D_836032A8.r) * idx) / 8) + D_836032A8.r;
            g = (((D_836032B0.g - D_836032A8.g) * idx) / 8) + D_836032A8.g;
            b = (((D_836032B0.b - D_836032A8.b) * idx) / 8) + D_836032A8.b;

            gDPSetEnvColor(gDisplayListHead++, r, g, b, 255);

            func_8001C330(0, i, 0x280, temp_v0_2, 0, 0, 0x400, 0x400, 0);
        }
    }
}

char* func_8360282C(unk_D_83407B38* arg0) {
    static s32 D_836032B4[] = { 0x21, 0x24 };

    char* var_v0;
    s32 temp_lo = arg0->unk_00 % 3;
    s32 temp_hi = arg0->unk_00 / 3;

    if (D_836032F4 == 0) {
        if (temp_hi < 2) {
            var_v0 = func_83402374(0x1E);
        } else if (temp_lo == 0) {
            var_v0 = func_83402374(0x22);
        } else {
            var_v0 = func_83402374(0x23);
        }
    } else {
        var_v0 = func_83402374(D_836032B4[D_836032F4 - 1]);
    }
    return var_v0;
}

void func_836028E8(unk_D_83407B38* arg0, s32 arg1, s32 arg2) {
    char* sp1C = func_8360282C(arg0);

    func_834008DC(arg1, arg2, 0x136, 0x4C);
    if (sp1C != NULL) {
        func_8001F3F4();
        func_8001EBE0(8, 0);
        func_8001F3B4(0x14);
        func_8001F1E8(arg1 + 0xA, arg2 + 8, sp1C);
        func_8001F444();
    }
}

void func_8360296C(s32 arg0, s32 arg1) {
    static s16 D_836032BC = 0;

    char sp28[255];
    char* sp24;
    s32 sp20;
    s32 sp1C;

    func_8002D600(2, 0x63);
    sp24 = func_834023A4(sp28, 0x100, 0x20);
    sp20 = func_8001F5B0(8, 0, sp24) / 2;
    func_83601314((arg0 - sp20) - 0x26, arg1 - 4, D_836032BC);
    func_8002D600(2, D_836033B8 - D_836033B4);

    sp24 = func_834023A4(sp28, 0x100, 0x20);
    sp1C = func_8001F5B0(8, 0, sp24);

    func_8001F3F4();
    func_8001EBE0(8, 0);
    func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
    func_8001F1E8((arg0 + sp20) - sp1C, arg1, sp24);
    func_8001F444();

    D_836032BC += 0x400;
}

void func_83602A8C(s32 arg0, s32 arg1) {
    char* sp2C;
    s32 sp28;

    sp2C = func_83402374(0x3C);
    sp28 = -func_8001F5B0(8, 0, sp2C) / 2;

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    func_8001C6AC((arg0 + sp28) - 0x20, arg1 - 2, 0x18, 0x18, D_30099B8, 0x18, 0);
    func_8001F3F4();
    func_8001EBE0(8, 0);
    func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
    func_8001F1E8(arg0 + sp28, arg1, sp2C);
    func_8001F444();
}

f32 func_83602B98(s32* arg0, u32* arg1, s32 arg2) {
    f32 coss;

    if (*arg0 < arg2) {
        *arg0 += 1;
        coss = 1.0f;
    } else {
        coss = (COSS(*arg1) * 0.1f) + 0.9f;

        *arg1 += 0x2000;
        if (*arg1 >= 0x10000) {
            *arg0 = 0;
            *arg1 = 0;
        }
    }

    return coss;
}

void func_83602C14(void) {
    static s32 D_836032C0 = 0;
    static u32 D_836032C4 = 0;
    static s32 D_836032C8 = 0;
    static u32 D_836032CC = 0;

    f32 tmp;
    s32 sp28;
    s32 sp24;
    UNUSED s32 pad;
    f32 sp1C;
    f32 sp18;

    func_83402210(&D_83603300, &sp28, &sp24, D_83603300.unk_00);
    func_800079C4();
    func_83602458();
    func_836009A4(0, 0x4F, 0x280, 1);
    func_836009A4(0, 0x151, 0x280, 0);
    func_83600D68(0, 0x5F, 0x280, 0xF2);
    func_83601800(&D_83603300);

    sp1C = func_83602B98(&D_836032C0, &D_836032C4, 0x1E);
    sp18 = func_83602B98(&D_836032C8, &D_836032CC, 0xF);

    tmp = ((sp24 >= 2) && (sp28 == 0)) ? sp18 : sp1C;
    func_83601F28(0x30, 0x172, 0, tmp);

    tmp = ((sp24 >= 2) && (sp28 != 0)) ? sp18 : sp1C;
    func_83601F28(0x1E1, 0x172, 1, tmp);

    func_83601A3C(&D_83603300);
    func_83601B48(0x65, 0x2B);
    func_836028E8(&D_83603300, 0xA5, 0x16B);
    func_8360296C(0xF0, 0x14E);
    func_83602A8C(0x1E0, 0x14E);
    func_80007778();
}

void func_83602D98(void) {
    if (gPlayer1Controller->buttonPressed & 0x8000) {
        D_836032F0 = 3;
        func_80007990(0xFFFF);
        func_80006CB4(0xF);
        func_80048B90(0x1D);
    } else if (gPlayer1Controller->buttonPressed & 0x4000) {
        D_836032F4 = 0;
        D_836032F0 = 1;
        func_80048B90(3);
    }
}

s32 func_83602E14(void) {
    static s32 D_836032D0 = 2;

    s32 sp1C = 1;
    s32 temp_v0_2;

    switch (D_836032F0) {
        case 0:
            if (func_80007604() == 0) {
                D_836032D0--;
                if (D_836032D0 <= 0) {
                    D_836032F0 = 1;
                }
            }
            break;

        case 1:
            temp_v0_2 = func_83600384(&D_83603300);
            if (temp_v0_2 != 0) {
                D_836032F0 = 3;
                if (temp_v0_2 == 2) {
                    func_80007990(1);
                    func_80006CB4(1);
                } else {
                    func_80007990(0xFFFF);
                    func_80006CB4(0xF);
                }
            }
            break;

        case 2:
            func_83602D98();
            break;

        case 3:
            if (func_80007604() == 1) {
                sp1C = 0;
            }
            break;
    }
    return sp1C;
}

void func_83602F1C(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    func_8001F730();
}

void func_83602F4C(void) {
    if (D_836033BC == 0) {
        func_80006C6C(1);
    } else {
        func_80006C6C(7);
    }

    do {
        func_83602F1C();

        switch (D_836032F0) {
            case 0:
            case 3:
                break;

            default:
                func_83401FD0(&D_83603300);
                break;
        }

        func_83602C14();
        func_834020D8();
    } while (func_83602E14() != 0);
}

s32 func_83602FF4(unk_D_83407B38* arg0) {
    s32 temp_hi = arg0->unk_00 % 3;
    s32 temp_lo = arg0->unk_00 / 3;
    s32 sp1C;

    if (temp_lo < 2) {
        sp1C = 4;
    } else if (temp_hi == 0) {
        sp1C = 3;
    } else {
        sp1C = 0;
    }

    if ((sp1C == 0) && (D_836033B4 > 0)) {
        func_83600020(arg0);
    }

    func_834021D8(&D_83603300, &D_83407AF8);
    return sp1C;
}

void func_836030A8(s32 arg0, UNUSED s32 arg1) {
    unk_func_80007444* sp24;

    main_pool_push_state('FILM');

    func_80005E40(0x10000, 0);
    sp24 = func_80007444(1, 0, 2, 0, 2, 1);
    D_8250A304 = func_8001E94C(0x18, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_5000000, snap_mode_ui, 0);
    ASSET_LOAD(D_3000000, gallery_ui, 0);
    ASSET_LOAD(D_04000000, _6A9750, 0);
    FRAGMENT_LOAD(fragment31);

    func_8001987C();
    D_836032F8 = func_800044F4(stadium_models_ROM_START, stadium_models_ROM_END, 1, 1);
    func_8002D510();
    func_83402340();
    func_8360086C(arg0);
    func_80007678(sp24);
    func_83602F4C();
    func_800076C0();
    func_8001E9CC();
    func_80005EAC();

    main_pool_pop_state('FILM');

    func_83602FF4(&D_83603300);
}
