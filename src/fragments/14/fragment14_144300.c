#include "fragment14.h"
#include "src/12D80.h"
#include "src/18480.h"
#include "src/19840.h"
#include "src/1C720.h"
#include "src/1CF30.h"
#include "src/20330.h"
#include "src/20470.h"
#include "src/2E110.h"
#include "src/3FB0.h"
#include "src/490A0.h"
#include "src/49790.h"
#include "src/4BA90.h"
#include "src/4BDC0.h"
#include "src/4CBC0.h"
#include "src/50860.h"
#include "src/6A40.h"
#include "src/6BC0.h"
#include "src/controller.h"
#include "src/fragments/2/fragment2.h"
#include "src/fragments/3/fragment3.h"
#include "src/memory.h"
#include "src/stage_loader.h"

typedef struct unk_D_86806E20 {
    /* 0x00 */ u8* texture;
    /* 0x02 */ s16 width;
    /* 0x04 */ s16 height;
} unk_D_86806E20; // size = 0x8

static u32 D_86806CD0[] = {
    0x0C00FFFF, 0x05000000, 0x0B00001E, 0x00000000, 0x014000F0, 0x0000000F, 0x00000000, 0x00000000,
    0x05000000, 0x0D000000, 0x05000000, 0x14000000, 0x002B0012, 0xFFFFFF32, 0x16FFFFFF, 0x0F000003,
    0x05000000, 0x1F00FFFF, 0x00000000, 0x00000000, 0xFFFF0000, 0x00640064, 0x00640000, 0x05000000,
    0x00000000, 0x87006D00, 0x06000000, 0x06000000, 0x05000000, 0x0A000000, 0x800AC840, 0x06000000,
    0x06000000, 0x06000000, 0x03000000, 0x87806398, 0x06000000, 0x01000000,
};

static Controller** D_86806D68 = &gPlayer1Controller;
static Controller** D_86806D6C = &gPlayer2Controller;
static Controller** D_86806D70 = &gPlayer3Controller;
static Controller** D_86806D74 = &gPlayer4Controller;

static s16 D_86806D78[] = { 0x1E, 0x1E, 0x108, 0x108 };
static s16 D_86806D80[] = { 0xCC, 0x10, 0x10, 0xCC };

static unk_D_86806E20 D_86806D88 = { 0x400C800, 32, 8 };
static unk_D_86806E20 D_86806D90 = { 0x400CA00, 32, 8 };
static unk_D_86806E20 D_86806D98 = { 0x400CC00, 32, 8 };
static unk_D_86806E20 D_86806DA0 = { 0x400CE00, 32, 4 };
static unk_D_86806E20 D_86806DA8 = { 0x400CF00, 32, 8 };
static unk_D_86806E20 D_86806DB0 = { 0x400D100, 32, 4 };
static unk_D_86806E20 D_86806DB8 = { 0x400D200, 32, 4 };
static unk_D_86806E20* D_86806DC0[] = { &D_86806D90, &D_86806D88, NULL };
static unk_D_86806E20* D_86806DCC[] = { &D_86806DA0, &D_86806D98, &D_86806D88, NULL };
static unk_D_86806E20* D_86806DDC[] = { &D_86806DA0, &D_86806DB0, &D_86806DA8, &D_86806D88, NULL };
static unk_D_86806E20* D_86806DF0[] = { &D_86806DA0, &D_86806DB0, &D_86806DB8, &D_86806DA8, &D_86806D88, NULL };
static unk_D_86806E20* D_86806E08[] = {
    &D_86806DA0, &D_86806DB0, &D_86806DB8, &D_86806DB8, &D_86806DA8, &D_86806D88,
};
static unk_D_86806E20** D_86806E20[] = { NULL, D_86806DC0, D_86806DCC, D_86806DDC, D_86806DF0, D_86806E08 };
static unk_func_87801684 D_86806E38[] = {
    { 0x0303ED80, 0xE }, { 0x0303F180, 2 }, { 0x0303F580, 6 }, { 0x0303F180, 2 }, { NULL, 0 },
};
static unk_func_87801684 D_86806E60[] = {
    { 0x03040580, 0x12 }, { 0x03040980, 2 }, { 0x03040D80, 8 }, { 0x03040980, 2 }, { NULL, 0 },
};
static unk_func_87801684 D_86806E88[] = {
    { 0x030397C0, 0xE }, { 0x03034E40, 2 }, { 0x03035A80, 2 }, { 0x03034E40, 2 }, { 0x030397C0, 2 }, { 0x0303D500, 2 },
    { 0x0303E140, 2 },   { 0x03038B80, 2 }, { 0x03037300, 2 }, { 0x03037F40, 2 }, { 0x03035A80, 2 }, { 0x0303BC80, 2 },
    { 0x0303B040, 2 },   { 0x0303A400, 2 }, { 0x030397C0, 2 }, { 0x030366C0, 2 }, { 0x03037300, 2 }, { 0x030366C0, 2 },
    { 0x030397C0, 2 },   { 0x0303A400, 2 }, { 0x0303B040, 2 }, { 0x0303A400, 2 }, { NULL, 0 },
};
static Color_RGB8 D_86806F40 = { 255, 255, 255 };
static Color_RGB8 D_86806F44[] = {
    { 0, 0, 0xFF },
    { 0, 0xFF, 0 },
    { 0xFF, 0, 0 },
    { 0xFF, 0xFF, 0 },
};
static Color_RGB8 D_86806F50[] = {
    { 255, 0, 0 },
    { 0, 255, 0 },
    { 255, 255, 100 },
};
static Color_RGB8 D_86806F5C[] = {
    { 0, 255, 0 },
    { 255, 255, 100 },
    { 255, 0, 0 },
};
static Color_RGB8 D_86806F68[] = {
    { 0, 0, 255 },
    { 255, 0, 0 },
    { 255, 255, 100 },
    { 0, 0, 0 },
};
static s32 D_86806F74[] = { 0x50002, 0x50002, 0x50001, 0x50002, 0, 0, 0 };

unk_D_86002F34* D_86807500;
static unk_D_800AC870* D_86807504;
static u32 D_86807508;
static s32 D_8680750C;
s32 D_86807510;
static Controller D_86807518;
static u16 D_8680753C;
static s16 D_8680753E;
static s16 D_86807540;

void func_86800020(s32 arg0) {
    if (D_8680753E == 0) {
        func_8004FC60(1, arg0);
        func_8004FC60(2, arg0);
    } else {
        func_8004B094(arg0);
    }
}

void func_86800070(void) {
    Controller* temp_v0;

    Cont_StartReadInputs();
    Cont_ReadInputs();
    func_8001F730();

    bzero(&D_86807518, sizeof(Controller));

    temp_v0 = *D_86806D68;
    D_86807518.buttonDown |= temp_v0->buttonDown;
    D_86807518.buttonPressed |= temp_v0->buttonPressed;
    D_86807518.unkA |= temp_v0->unkA;

    temp_v0 = *D_86806D6C;
    D_86807518.buttonDown |= temp_v0->buttonDown;
    D_86807518.buttonPressed |= temp_v0->buttonPressed;
    D_86807518.unkA |= temp_v0->unkA;

    temp_v0 = *D_86806D70;
    D_86807518.buttonDown |= temp_v0->buttonDown;
    D_86807518.buttonPressed |= temp_v0->buttonPressed;
    D_86807518.unkA |= temp_v0->unkA;

    temp_v0 = *D_86806D74;
    D_86807518.buttonDown |= temp_v0->buttonDown;
    D_86807518.buttonPressed |= temp_v0->buttonPressed;
    D_86807518.unkA |= temp_v0->unkA;

    if (1) {}
}

#ifdef NON_MATCHING
Gfx* func_868001A8(Gfx* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 sp34;
    unk_D_86806E20** var_a3;
    unk_D_86806E20* ptr;
    s32 var_s0;
    s32 var_v0;
    s32 var_v1;

    var_s0 = (arg1 != 0) ? arg2 + 6 : arg2;
    var_v1 = arg3 + 24;

    while (arg4 > 0) {
        sp34 = var_v1;

        if (arg4 < 5) {
            var_a3 = D_86806E20[arg4];
            arg4 = 0;
        } else {
            var_a3 = &D_86806E08[0];
            arg4 -= 5;
        }

        var_v0 = var_s0;
        while (*var_a3 != NULL) {
            ptr = *var_a3;
            sp34 -= (ptr->height * 3) / 4;

            gDPLoadTextureBlock(arg0++, ptr->texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, ptr->width, ptr->height, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);

            gSPTextureRectangle(arg0++, var_v0 << 2, sp34 << 2, (((ptr->width * 9) / 16) + var_v0) << 2,
                                (sp34 + ((ptr->height * 3) / 4)) << 2, G_TX_RENDERTILE, 0, 0, 0x071C, 0x0555);
            var_a3++;
        }

        if (arg1 == 0) {
            var_s0 += 20;
        } else {
            var_s0 -= 20;
        }
    }

    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/14/fragment14_144300/func_868001A8.s")
#endif

void func_868004F4(void) {
    s32 i;
    Gfx* var_s4 = gDisplayListHead;
    unk_D_86807558* ptr;

    for (i = 0, ptr = D_86807558; i < 4; i++, ptr++) {
        var_s4 = func_868001A8(var_s4, i / 2, D_86806D78[i], D_86806D80[i], ptr->unk_02A);
    }

    gDisplayListHead = var_s4;
}

void func_868005A8(Color_RGB8* arg0, Color_RGB8* arg1, s32 arg2, s32 arg3, s32 arg4) {
    Color_RGB8* var_v0;
    Color_RGB8* var_v1;
    f32 temp_fv0;
    f32 var_ft5;
    s32 temp_a0;
    s32 tmp;

    if (arg2 >= 2) {
        tmp = D_86807508 % arg3;
        temp_fv0 = tmp;
        temp_fv0 /= arg3;

        temp_a0 = (D_86807508 % (arg3 * arg2)) / arg3;

        if (arg4 == 0) {
            var_v0 = &arg1[temp_a0];
            var_v1 = &arg1[(temp_a0 + 1) % arg2];
        } else {
            temp_a0 = (arg2 - temp_a0);
            temp_a0--;

            var_v0 = &arg1[temp_a0];
            temp_a0--;

            if (temp_a0 < 0) {
                temp_a0 += arg2;
            }
            var_v1 = &arg1[temp_a0];
        }

        arg0->r = var_v0->r + ((var_v1->r - var_v0->r) * temp_fv0);
        arg0->g = var_v0->g + ((var_v1->g - var_v0->g) * temp_fv0);
        arg0->b = var_v0->b + ((var_v1->b - var_v0->b) * temp_fv0);
    }
}

void func_8680091C(s32 arg0, s16 arg1, s16 arg2, f32 arg3) {
    s16 sp36;
    s16 sp34;
    s16 sp32;

    if ((arg0 > 0) && (arg0 < 9) && (arg3 != 0.0f)) {
        sp36 = ROUND_MAX(1024.0f / arg3);
        sp34 = ROUND_MAX(32.0f * arg3);
        sp32 = ROUND_MAX(32.0f * arg3);

        gDPLoadTextureBlock(gDisplayListHead++, D_86807180[arg0].unk_08, G_IM_FMT_RGBA, G_IM_SIZ_32b, 32, 32, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);

        func_8001C330(arg1, arg2, sp34, sp32, 0, 0, sp36, sp36, 0);
    }
}

#ifdef NON_MATCHING
void func_86800B38(void) {
    s32 pad1;
    s32 pad2;
    s32 i;
    Color_RGB8 spD8[4];
    Color_RGB8 spD0[2];
    Color_RGB8 spC4[4];
    Color_RGB8 spB8[4];
    Color_RGB8 spB4 = D_86806F40;
    s32 var_v0;

    gSPDisplayList(gDisplayListHead++, D_8006F518);

    if (D_8680753C & 2) {
        func_868004F4();
        for (i = 0; i < 4; i++) {
            if ((i == 0) || (i == 3)) {
                var_v0 = -0x18;
            } else {
                var_v0 = 0x1C;
            }

            if (!(D_86807558[i].unk_002 & 4)) {
                func_87801644(i, D_86806D78[i], D_86806D80[i] + var_v0, 0.75f);
            } else {
                func_87801644(-1 - i, D_86806D78[i], D_86806D80[i] + var_v0, 0.75f);
            }
        }
    }

    if (D_8680753E != 0) {
        func_878021B4(0x1E, 0x17);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);

    if (D_8680753C & 1) {
        func_80020460(0x18, 0x16, 0x110, 0x90, 0x15);
        func_80020460(0x18, 0xA5, 0x110, 0x36, 0x14B);
        func_8780118C(0x17, 0x16, 2, 0x90);
        func_8780118C(0x127, 0x16, 2, 0x90);
    }

    func_8001F3F4();
    func_8001F470();

    if (D_8680753C & 1) {
        s32 spA4;
        s32 spA0;
        s32 sp9C;
        s32 sp98;
        s32 sp94;

        func_8001EBE0(2, 0);
        func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
        func_8001F36C(0xF9, 0xF4, 0, 0xFF);
        func_8001F1E8(0xA0 - (func_878013D4(D_86807504, func_8002D7C0(NULL, 0, D_87806330, 0xC)) / 2), 0x20,
                      func_8002D7C0(NULL, 0, D_87806330, 0xC));
        func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
        func_8001F36C(0xFF, 0xFF, 0xFF, 0xFF);
        func_8001F3B4(0xC);
        func_8001F1E8(0x28, 0x34, func_8002D7C0(NULL, 0, D_87806330, 0x32));
        func_8001F1E8(0x28, 0x4C, func_8002D7C0(NULL, 0, D_87806330, 0x33));
        func_8001F1E8(0x78, 0xB2, func_8002D7C0(NULL, 0, D_87806330, 0x5C));
        func_8001F1E8(0xDA, 0xB2, func_8002D7C0(NULL, 0, D_87806330, 0x5C));
        func_8001F1E8(0x86, 0xC8, func_8002D7C0(NULL, 0, D_87806330, 0x5C));
        func_8001F324(0xE6, 0xD2, 0xFF, 0xFF);
        func_8001F36C(0x82, 0x50, 0xD2, 0xFF);
        func_8001F1E8(0x8C, 0xB2, func_8002D7C0(NULL, 0, D_87806330, 0x34));
        func_8001F324(0xC8, 0xC8, 0xFF, 0xFF);
        func_8001F36C(0x50, 0x50, 0xFF, 0xFF);
        func_8001F1E8(0xEE, 0xB2, func_8002D7C0(NULL, 0, D_87806330, 0x35));
        func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
        func_8001F36C(0xFF, 0x80, 0x80, 0xFF);
        func_8001F1E8(0x9A, 0xC8, func_8002D7C0(NULL, 0, D_87806330, 0x14));
        func_87801290(&spA4, &spA0, func_8002D7C0(NULL, 0, D_87806330, 0x32), func_8002D7C0(NULL, 0, D_87806330, 0x5F),
                      0xC);
        func_8001F324(0xC8, 0xC8, 0xFF, 0xFF);
        func_8001F36C(0x50, 0x50, 0xFF, 0xFF);
        func_8001F1E8(spA4 + 0x28, spA0 + 0x34, func_8002D7C0(NULL, 0, D_87806330, 0x5F));
        func_8001EBE0(1, 0);
        func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
        func_8001F36C(0xFF, 0xFF, 0xFF, 0xFF);

        for (i = 0; i < 8; i++) {
            pad1 = i % 4;
            if (pad1) {}

            sp9C = func_8001F5B0(0, 0, func_8002D7C0(NULL, 0, D_87806330, 0x36));
            sp98 = func_8001F5B0(0, 0, func_8002D7C0(NULL, 0, D_87806330, i + 0x36));

            func_8001F1E8((((pad1 * 60) + sp9C) - sp98) + 0x46, ((i / 4) << 5) + 0x72,
                          func_8002D7C0(NULL, 0, D_87806330, i + 0x36));
        }
    }

    switch (D_8680750C) {
        s32 var_s4;
        s32 var_s7;

        case 4:
            break;

        case 2:
        case 3:
            if (D_8680753E == 0) {
                func_8001EBE0(4, 0);
                for (i = 0; i < 4; i++) {
                    f32 v;

                    if ((D_86807558[i].unk_040.unk_00 != 0) && (D_86807558[i].unk_040.unk_00 != 1)) {
                        if ((i / 2) != 0) {
                            var_s7 = -0x14;
                        } else {
                            var_s7 = 0x1E;
                        }

                        if ((i == 0) || (i == 3)) {
                            var_s4 = -0x16;
                        } else {
                            var_s4 = 0x1E;
                        }

                        if (D_86807558[i].unk_03E < 5) {
                            func_8001F324(0xFF, 0xFF, 0xFF, D_86807558[i].unk_040.unk_18);
                            func_8001F36C(D_86806F44[i].r, D_86806F44[i].g, D_86806F44[i].b,
                                          D_86807558[i].unk_040.unk_18);
                        } else {
                            func_868005A8(spD8, D_86806F68, 4, 4, 0);
                            func_8001F324(spD8[0].r, spD8[0].g, spD8[0].b, D_86807558[i].unk_040.unk_18);
                            func_8001F36C(spD8[0].r, spD8[0].g, spD8[0].b, D_86807558[i].unk_040.unk_18);
                        }

                        v = D_86807558[i].unk_040.unk_08;
                        func_8001F1E8(D_86806D78[i] + var_s7 + (s16)v,
                                      (D_86806D80[i] + var_s4) - (s16)D_86807558[i].unk_040.unk_0C, "x%d",
                                      D_86807558[i].unk_03E);
                    }
                }
            }
            break;

        case 5:
        case 6:
            func_8001EBE0(4, 0);

            for (i = 0; i < 4; i++) {
                char sp78[16];

                spD0[0] = spB4;
                spD0[1] = D_86806F44[i];

                func_868005A8(&spB8[i], spD0, 2, 0x1E, 0);
                func_868005A8(&spC4[i], spD0, 2, 0x1E, 1);

                if ((i / 2) != 0) {
                    var_s7 = -0x32;
                } else {
                    var_s7 = 0x1C;
                }

                if ((i == 0) || (i == 3)) {
                    var_s4 = -0x16;
                } else {
                    var_s4 = 0x1E;
                }

                if ((D_86807558[i].unk_028 == 1) && (D_86807558[i].unk_01C == D_86807558[i].unk_018) &&
                    (D_86807558[i].unk_018 > 0)) {
                    func_868005A8(&spD8, &D_86806F50, 3, 4, 0);
                    func_8001F324(spD8[0].r, spD8[0].g, spD8[0].b, 0xFF);
                    func_868005A8(&spD8, &D_86806F5C, 3, 4, 0);
                    func_8001F36C(spD8[0].r, spD8[0].g, spD8[0].b, 0xFF);
                } else {
                    func_8001F324(spB8[i].r, spB8[i].g, spB8[i].b, 0xFF);
                    func_8001F36C(spB8[i + 4].r, spB8[i + 4].g, spB8[i + 4].b, 0xFF);
                }

                func_8002D600(6, D_86807558[i].unk_01C);
                func_8001F1E8(D_86806D78[i] + var_s7, D_86806D80[i] + var_s4,
                              func_8002D7C0(&sp78, 0x20, D_87806330, 0x5E));
            }
            break;
    }

    func_8001F4C4();
    func_8001F444();

    if (D_8680753C & 1) {
        gSPDisplayList(gDisplayListHead++, D_8006F518);

        for (i = 0; i < 8; i++) {
            if ((i % 4) >= 2) {
                var_v0 = 0x3C;
            } else {
                var_v0 = 0x40;
            }

            pad1 = i % 4;
            func_8680091C(D_86807160[i], (var_v0 * pad1) + 0x28, ((i / 4) << 5) + 0x68, 0.75f);
        }

        func_87801D5C(0, 0x5A, 0xA8, D_86806E88);
        func_87801684(0xC8, 0xB0, D_86806E38);
        func_87801824(0x74, 0xC6, D_86806E60);
        func_87801F48(0, 0x19, 0xA6);
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/14/fragment14_144300/func_86800B38.s")
#endif

void func_86801644(void) {
    func_800079C4();
    func_800067E4(&gDisplayListHead, 0, 0, 0x140, 0xF0);

    if (D_8780FC94 == 0) {
        func_80015348();
    }

    func_80015094(D_86807500);
    func_87901C98();

    if (D_8780FC98 == 0) {
        func_86800B38();
    }

    if (D_8680753E == 0) {
        func_87804FD4();
    }

    if (D_8680753E != 0) {
        func_8780005C();
    }

    func_80007778();
}

void func_86801700(void) {
    func_878001E8(0x80);

    if (func_80007604() == 0) {
        if (D_8680753E != 0) {
            D_8680750C = 1;
            D_86807510 = 0x1C2;
            D_86807540 = 0xF;
        } else if (gPlayer1Controller->buttonPressed & 0x1000) {
            D_8680750C = 1;
            D_8680753C &= ~1;
            D_8680753C |= 2;
            D_86807510 = 0x708;
            D_86807540 = 0xF;
            func_8004B9C4(0x3C);
            func_86805108(0xF, 1);
        } else if ((D_8780FA2A == 0) && (gPlayer1Controller->buttonPressed & 0x4000)) {
            func_80048B90(3);
            D_8680750C = 7;
            D_86807540 = 0x1E;
            func_80006CB4(D_86807540);
            func_86800020(D_86807540 / 2);
            func_87802EB8(2);
        }
    }
}

s32 func_86801840(void) {
    s32 var_v1 = 0;

    if (D_8680753E == 0) {
        if (D_86807510 <= 0) {
            var_v1 = 1;
        }
    } else if (D_86807510 <= 0) {
        var_v1 = 1;
    }
    return var_v1;
}

#ifdef NON_MATCHING
s32 func_86801884(void) {
    s32 sp1C;
    s32 sp18;
    unk_D_86807558* ptr;
    s32 i;
    s32 temp_v0;
    s32 var_a0;

    sp1C = 0;

    sp18 = 0;
    if ((D_8680753E != 0) && (gPlayer1Controller->buttonPressed != 0)) {
        if (func_80007604() == 0) {
            sp18 = 1;
        }
    }

    if (((D_8780FC92 != 0) || (sp18 != 0)) && (D_8680750C != 7)) {
        D_8680750C = 7;
        D_86807540 = 0x1E;
        func_80006CB4(D_86807540);
        func_86800020(D_86807540 / 2);
    }

    switch (D_8680750C) {
        case 0:
            func_86801700();
            break;

        case 1:
            D_86807540 -= 1;
            if (D_86807540 <= 0) {
                D_8680750C = 2;
                func_8780295C(1);
            }
            break;

        case 2:
            temp_v0 = func_87802974();
            if ((temp_v0 >= 0) && (temp_v0 < 4)) {
                func_8004D9B0(D_86806F74[temp_v0], 0, 0);
            } else if (temp_v0 == -2) {
                D_8680750C = 3;
                func_86805108(0xF, 3);
                func_86806964(1);
            }
            break;

        case 3:
            if (D_8780FC94 == 0) {
                D_86807510--;
                if (((D_86807510 % 30) == 0) && (D_8680753E == 0)) {
                    if (((D_86807510 / 30) > 0) && ((D_86807510 / 30) < 6)) {
                        func_8004D9B0(0x50002, 0, 0);
                    }
                }
            }

            if (func_86801840() != 0) {
                if (D_8680753E == 0) {
                    D_8680750C = 4;
                    D_86807540 = 0x1E;
                    func_86805108(0xF, 2);
                    func_86806964(2);
                    func_8004B9C4(0xA);
                    func_8004D9B0(0x50004, 0, 0);
                } else {
                    D_8680750C = 7;
                    D_86807540 = 0x1E;
                    func_80006CB4(D_86807540);
                    func_86800020(D_86807540 / 2);
                    func_87802EB8(2);
                }
            }
            break;

        case 4:
            if (func_868055D4() != 0) {
                D_86807540--;
            }

            if (D_86807540 <= 0) {
                D_8680750C = 5;
                func_86805108(0xF, 4);
            }
            break;

        case 5:
            var_a0 = 1;
            ptr = &D_86807558[0];

            for (i = 0; i < 4; i++, ptr++) {
                if (ptr->unk_018 != ptr->unk_01C) {
                    var_a0 = 0;
                }
            }

            if ((var_a0 != 0) && (D_8780FC94 == 0)) {
                D_8680750C = 6;
                func_86805108(0xF, 5);
                func_87802EB8(1);
            }
            break;

        case 6:
            if (D_8780FC96 != 0) {
                D_8680750C = 7;
                D_86807540 = 0x1E;
                func_80006CB4(D_86807540);
                func_86800020(D_86807540 / 2);
            }
            break;

        case 7:
            if (D_86807540 > 0) {
                D_86807540--;
            }

            if ((D_86807540 <= 0) && (func_800484E0() == 0)) {
                sp1C = 1;
                func_8004B154();
            }
            break;
    }

    return sp1C;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/14/fragment14_144300/func_86801884.s")
#endif

void func_86801CA8(void) {
    s32 var_s0;

    func_800077B4(5);
    func_80006C6C(0x10);
    D_86807508 = 0;

    var_s0 = 1;
    while (var_s0 != 0) {
        func_86800070();
        func_878025D0();
        func_86805CB4();
        func_86806BF0();
        func_86805974();
        func_87901C20();
        func_86801644();

        if (func_86801884() != 0) {
            var_s0 = 0;
        }

        D_86807508++;
    }
}

void func_86801D48(void) {
    UNUSED s32 pad;
    MemoryBlock* sp18;

    sp18 = func_80002D10(main_pool_get_available(), 0);
    D_86807500 = (unk_D_86002F34_000*)func_80018B70(sp18, &D_86806CD0);

    func_80002D60(sp18);
    func_8001BB20();
    func_8001987C();
    func_87802528();
    func_86806A50();

    if (D_8680753E != 0) {
        func_86805858(1);
    } else {
        func_86805858(0);
    }

    func_86805BD4();
    func_87901620();
    func_878029C0();

    D_8680750C = 0;
    if (D_8680753E == 0) {
        D_8680753C |= 1;
    }

    func_86805108(0xF, 2);
}

void func_86801E2C(s32 arg0, UNUSED s32 arg1) {
    unk_func_80007444* sp24;

    if (arg0 == 1) {
        D_8680753E = 1;
        func_878010C8(9);
    } else {
        D_8680753E = 0;
    }

    main_pool_push_state('MINI');

    func_80005E40(0x18000, 0);
    sp24 = func_80007444(0, 1, 3, 1, 2, 1);
    D_86807504 = func_8001E94C(0x17, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_04000000, sushi_go_round_sprites, 0);

    FRAGMENT_LOAD(fragment31);
    func_80004454((((u32)D_87000000 & 0x0FF00000) >> 0x14) - 0x10, sushi_go_round_ROM_START, order_select_ui_ROM_START);

    func_86801D48();
    func_80007678(sp24);
    func_86801CA8();
    func_800076C0();
    func_8001E9CC();
    func_80005EAC();

    main_pool_pop_state('MINI');

    func_87803118();
}
