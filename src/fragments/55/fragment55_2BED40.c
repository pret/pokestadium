#include "fragment55.h"
#include "src/1AB70.h"
#include "src/1CF30.h"
#include "src/20330.h"
#include "src/20470.h"
#include "src/26820.h"
#include "src/2E110.h"
#include "src/3FB0.h"
#include "src/49790.h"
#include "src/controller.h"
#include "src/memory.h"
#include "src/stage_loader.h"

static s16 D_83003C80;
static s16 D_83003C82;
static u16 D_83003C84;
static BinArchive* D_83003C88;
static void* D_83003C8C;
static s16 D_83003C90;
static s16 D_83003C92;
static s16 D_83003C94;
static s32 D_83003C98;
static char* D_83003C9C;
static s16* D_83003CA0;
static s16 D_83003CA4;
static s16 D_83003CA6;
static char* D_83003CA8;
static char* D_83003CAC;
static char* D_83003CB0;
static char* D_83003CB4;
static char* D_83003CB8;
static char* D_83003CBC;
static char* D_83003CC0;
static char* D_83003CC4;
static char* D_83003CC8;
static char* D_83003CCC;
static char* D_83003CD0;
static char* D_83003CD4;
static char* D_83003CD8;
static char* D_83003CDC;
unk_D_83003CE0 D_83003CE0;
unk_D_83003CE0 D_83003DE0;

char** D_830039C0 = NULL;
static char** D_830039C4 = NULL;
static u8 D_830039C8[] = {
    0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0F,
};
static s16 D_830039D4[] = {
    0x0007, 0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0023, 0xFFFF,
};
static s16 D_830039E8[] = {
    0x0007, 0x0000, 0x0001, 0x001D, 0x0003, 0x0004, 0x0005, 0x0009, 0x0023, 0xFFFF,
};
static s16 D_830039FC[] = {
    0x0007, 0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0023, 0xFFFF, 0x0000,
};
static s16 D_83003A10[] = {
    0x000B, 0x0000, 0x0001, 0x000A, 0x0004, 0x0005, 0x0006, 0x0023, 0xFFFF, 0x0000,
};
static s16 D_83003A24[] = {
    0x000B, 0x0000, 0x0001, 0x001E, 0x0004, 0x0005, 0x0009, 0x0023, 0xFFFF, 0x0000,
};
static s16 D_83003A38[] = {
    0x000B, 0x0000, 0x0001, 0x000A, 0x0004, 0x0005, 0x0023, 0xFFFF, 0x000E, 0x0000, 0x0001, 0x000C, 0x000D,
    0x0004, 0x0005, 0x0006, 0x0023, 0xFFFF, 0x000E, 0x0000, 0x0001, 0x001F, 0x000D, 0x0004, 0x0005, 0x0009,
    0x0023, 0xFFFF, 0x000E, 0x0000, 0x0001, 0x000C, 0x000D, 0x0004, 0x0005, 0x0023, 0xFFFF, 0x0000,
};
static s16 D_83003A84[] = {
    0x0013, 0x0000, 0x0001, 0x000F, 0x0010, 0x0011, 0x0012, 0x0004, 0x0005, 0x0006, 0x0023, 0xFFFF,
};
static s16 D_83003A9C[] = {
    0x0013, 0x0000, 0x0001, 0x0020, 0x0010, 0x0011, 0x0012, 0x0004, 0x0005, 0x0009, 0x0023, 0xFFFF,
};
static s16 D_83003AB4[] = {
    0x0013, 0x0000, 0x0001, 0x000F, 0x0010, 0x0011, 0x0012, 0x0004, 0x0005, 0x0023, 0xFFFF, 0x0000,
};
static s16 D_83003ACC[] = {
    0x0000, 0x0001, 0x0016, 0x0017, 0x0004, 0x0005, 0x0006, 0x0023, 0xFFFF, 0x0000,
};
static s16 D_83003AE0[] = {
    0x0000, 0x0001, 0x0021, 0x0017, 0x0004, 0x0005, 0x0009, 0x0023, 0xFFFF, 0x0000,
};
static s16 D_83003AF4[] = {
    0x0000, 0x0001, 0x0016, 0x0017, 0x0004, 0x0005, 0x0023, 0xFFFF,
};
static s16 D_83003B04[] = {
    0x0015, 0x0000, 0x0001, 0x0024, 0x0004, 0x0006, 0x0023, 0xFFFF,
};
static s16 D_83003B14[] = {
    0x0015, 0x0000, 0x0001, 0x0014, 0x0004, 0x0009, 0x0023, 0xFFFF,
};
static s16 D_83003B24[] = {
    0x0015, 0x0000, 0x0001, 0x0014, 0x0004, 0x0023, 0xFFFF, 0x0000,
};
static s16 D_83003B34[] = {
    0x0015, 0x001A, 0x0014, 0x0025, 0x0022, 0x0026, 0x0023, 0xFFFF,
};
static s16 D_83003B44[] = {
    0x0015, 0x0000, 0x0001, 0x0014, 0x0019, 0x0004, 0x0023, 0xFFFF,
};
static s16 D_83003B54[] = {
    0x0015, 0x001C, 0x001B, 0x0014, 0x0023, 0xFFFF,
};

char* func_83000020(s32 arg0) {
    return func_8002D7C0(NULL, 0, D_830039C4, arg0 - 1);
}

void func_83000058(void) {
    unk_func_80027FA0 sp20;

    if (D_800AE540.unk_0000 != 0xA) {
        D_83003C88 = func_800044F4(backgrounds_ROM_START, battle_headers_ROM_START, 1, 1);
        if (D_800AE540.unk_0000 == 7) {
            func_80028AFC(2);
            func_80027FA0(&sp20, D_800AE540.unk_11F2);
            if (sp20.unk_04 < 8) {
                D_83003C8C = func_8000484C(D_83003C88, 0xD);
            } else {
                D_83003C8C = func_8000484C(D_83003C88, 0x10);
            }
        } else {
            D_83003C8C = func_8000484C(D_83003C88, D_830039C8[D_800AE540.unk_0000]);
        }
    }
}

void func_83000130(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    func_8001F730();
}

s16* func_83000160(unk_D_800AE540* arg0) {
    s16* var_v1 = NULL;

    switch (arg0->unk_0001) {
        case 1:
            switch (arg0->unk_0000) {
                case 1:
                    var_v1 = D_830039D4;
                    break;
                case 10:
                    var_v1 = D_830039E8;
                    break;
                case 0:
                    var_v1 = D_830039FC;
                    break;
            }
            break;

        case 2:
            switch (arg0->unk_0000) {
                case 2:
                    var_v1 = D_83003A10;
                    break;
                case 10:
                    var_v1 = D_83003A24;
                    break;
                case 0:
                    var_v1 = D_83003A38;
                    break;
            }
            break;

        case 3:
            switch (arg0->unk_0000) {
                case 3:
                    var_v1 = D_830039D4;
                    break;
                case 10:
                    var_v1 = D_830039E8;
                    break;
                case 0:
                    var_v1 = D_830039FC;
                    break;
            }
            break;

        case 4:
            switch (arg0->unk_0000) {
                case 4:
                    var_v1 = D_83003A84;
                    break;
                case 10:
                    var_v1 = D_83003A9C;
                    break;
                case 0:
                    var_v1 = D_83003AB4;
                    break;
            }
            break;

        case 5:
            switch (arg0->unk_0000) {
                case 5:
                    var_v1 = D_83003ACC;
                    break;
                case 10:
                    var_v1 = D_83003AE0;
                    break;
                case 0:
                    var_v1 = D_83003AF4;
                    break;
            }
            break;

        case 6:
            switch (arg0->unk_0000) {
                case 6:
                    var_v1 = D_83003B04;
                    break;
                case 10:
                    var_v1 = D_83003B14;
                    break;
                case 0:
                    var_v1 = D_83003B24;
                    break;
            }
            break;

        case 0:
            switch (arg0->unk_0000) {
                case 0:
                    var_v1 = D_83003B34;
                    break;
            }
            break;

        case 7:
            switch (arg0->unk_0000) {
                case 7:
                    var_v1 = D_83003B44;
                    break;
            }
            break;

        case 8:
            switch (arg0->unk_0000) {
                case 8:
                    var_v1 = D_83003B54;
                    break;
            }
            break;
    }

    return var_v1;
}

char* func_830003A4(s8 arg0) {
    char* ret;

    switch (arg0) {
        case 0:
            ret = D_83003CAC;
            break;

        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            ret = D_83003CA8;
            break;

        case 7:
            ret = D_83003CB4;
            break;

        case 8:
            ret = D_83003CB8;
            break;

        case 10:
            ret = D_83003CB0;
            break;

        default:
            ret = NULL;
            break;
    }

    return ret;
}

char* func_83000418(s8 arg0) {
    char* ret;

    switch (arg0) {
        case 0:
            ret = D_83003CBC;
            break;

        case 1:
            ret = D_83003CC0;
            break;

        case 2:
            ret = D_83003CC4;
            break;

        case 3:
            ret = D_83003CC8;
            break;

        case 4:
            ret = D_83003CCC;
            break;

        case 5:
            ret = D_83003CD0;
            break;

        case 6:
            ret = D_83003CD4;
            break;

        case 7:
            ret = D_83003CD8;
            break;

        case 8:
            ret = D_83003CDC;
            break;

        default:
            ret = NULL;
            break;
    }

    return ret;
}

s32 func_830004BC(s16* arg0) {
    s32 ret = 0;

    while (*arg0 != -1) {
        if (D_83003DE0.unk_00[*arg0] == '\x00') {
            ret = 1;
            break;
        }
        arg0++;
    }

    return ret;
}

void func_83000508(void) {
    s32 temp_lo;

    D_83003C82--;

    D_83003C92 = temp_lo = ((0xA - D_83003C82) << 0xA) / 10;

    if (D_83003C84 & 4) {
        D_83003C94 = temp_lo;
    }

    if (D_83003C82 <= 0) {
        D_83003C80 = 1;
        D_83003C90 = 2;
    }
}

void func_8300059C(void) {
    s16 tmp = D_83003CA6;

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DUP)) {
        D_83003CA6--;
        if (D_83003CA6 < 0) {
            D_83003CA6 = D_83003CA4 - 1;
        }
    }

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_DDOWN)) {
        D_83003CA6++;
        if (D_83003CA6 >= D_83003CA4) {
            D_83003CA6 = 0;
        }
    }

    if (D_83003CA6 != tmp) {
        func_80048B90(1);
    }

    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        D_83003C80 = 2;
        D_83003C82 = 0;

        if (D_83003DE0.unk_00[D_83003CA0[D_83003CA6]] != NULL) {
            func_830025F8(D_83003CA0[D_83003CA6]);
        } else {
            func_830038DC();
            func_80048B90(4);
        }

        func_80048B90(2);
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
        D_83003C80 = 3;
        D_83003C82 = 0xA;
        D_83003C90 = -1;
        func_80048B90(3);
    }
}

void func_83000710(void) {
    if ((func_8300269C() == 0) && (func_83003988() == 0)) {
        D_83003C80 = 1;
    }
}

void func_83000750(void) {
    s32 temp_lo;

    D_83003C82--;
    temp_lo = (D_83003C82 << 0xA) / 10;

    D_83003C92 = temp_lo;
    if (D_83003C84 & 4) {
        D_83003C94 = temp_lo;
    }

    if (D_83003C82 <= 0) {
        D_83003C80 = 4;
        D_83003C82 = 2;
        D_83003C90 = -1;
    }
}

s32 func_830007C4(void) {
    s32 var_v1 = 0;

    D_83003C82--;
    if (D_83003C82 <= 0) {
        var_v1 = 1;
    }
    return var_v1;
}

void func_830007F4(void) {
    gDPPipeSync(gDisplayListHead++);

    gDPSetCycleType(gDisplayListHead++, G_CYC_1CYCLE);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetCombineLERP(gDisplayListHead++, ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, ENVIRONMENT, 0,
                      ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, ENVIRONMENT, 0);
    gDPSetRenderMode(gDisplayListHead++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetEnvColor(gDisplayListHead++, 140, 190, 200, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 110, 160, 170, 255);
    gSPClearGeometryMode(gDisplayListHead++, G_ZBUFFER | G_LIGHTING);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_302EBC0, G_IM_FMT_I, 128, 64, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 7, 6, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(0, 0, 0x280, 0x1E0, 0, 0, 0x400, 0x400, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_83000A30(void) {
    UNUSED s32 pad;
    s16 temp_s1;
    s16 spD8;

    if (D_83003C94 == 0) {
        return;
    }

    temp_s1 = (((-D_83003C94 * 0x10) + 0x4000) / 1024) + 0x28;
    spD8 = (D_83003C94 << 5) / 1024;

    gSPDisplayList(gDisplayListHead++, D_8006F558);
    gDPSetEnvColor(gDisplayListHead++, 100, 100, 200, 255);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 40, 40, 140, 255);

    gDPLoadTextureBlock(gDisplayListHead++, D_20003C0, G_IM_FMT_IA, G_IM_SIZ_8b, 16, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(0x38, temp_s1, 0x10, spD8, 0, 0, 0x3F0, 0x8000 / spD8, 0);

    gDPLoadTextureBlock(gDisplayListHead++, D_20005C0, G_IM_FMT_IA, G_IM_SIZ_8b, 16, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(0x240, temp_s1, 0x10, spD8, 0, 0, 0x400, 0x8000 / spD8, 0);
    func_8001C330(0x48, temp_s1, 0x1F8, spD8, 0, 0, 0, 0x8000 / spD8, 0);

    if (D_83003C94 < 0x400) {
        gSPDisplayList(gDisplayListHead++, D_8006F630);
    } else {
        gSPDisplayList(gDisplayListHead++, D_8006F518);

        func_8001C6AC(0x30, temp_s1 - 8, 0x30, 0x18, D_2006C00, 0x30, 0);
        func_8001C6AC(0x30, temp_s1 + 0x10, 0x30, 0x18, D_2007500, 0x30, 0);

        gSPDisplayList(gDisplayListHead++, D_8006F630);

        func_8001F3F4();
        func_8001EBE0(0x10, 0);

        if (D_83003C98 != 0) {
            char sp48[0x40];
            char* temp_v0_21;

            func_8001F324(0, 0, 0, 0xFF);
            func_8002D5D4(0x26, D_83003C98);
            temp_v0_21 = func_8002D7C0(sp48, sizeof(sp48), D_830039C0, 0);
            func_8001F1E8(0x6A, temp_s1 + 4, temp_v0_21);
            func_8001F324(0xFF, 0xFF, 0x77, 0xFF);
            func_8001F1E8(0x68, temp_s1 + 2, temp_v0_21);
        }

        func_8001F444();
    }
}

void func_83000F10(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    func_8001CADC(arg0 - 7, arg1 - 7, 8, 8, D_2000340, 8, 0);
    func_8001CADC((arg0 + arg2) - 1, arg1 - 7, 8, 8, D_2000380, 8, 0);
    func_8001C330(arg0 + 1, arg1 - 7, arg2 - 2, 8, 0, 0, 0, 0x400, 0);
    func_8001CADC(arg0 - 7, (arg1 + arg3) - 1, 8, 8, D_20002C0, 8, 0);
    func_8001C330(arg0 - 7, arg1 + 1, 8, arg3 - 2, 0, 0, 0x400, 0, 0);
    func_8001CADC((arg0 + arg2) - 1, (arg1 + arg3) - 1, 8, 8, D_2000300, 8, 0);
    func_8001C330(arg0 + 1, (arg1 + arg3) - 1, arg2 - 2, 8, 0, 0, 0, 0x400, 0);
    func_8001C330((arg0 + arg2) - 1, arg1 + 1, 8, arg3 - 2, 0, 0, 0x400, 0, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_83001178(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6) {
    gSPDisplayList(gDisplayListHead++, D_8006F518);

    gDPSetRenderMode(gDisplayListHead++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);
    gDPSetEnvColor(gDisplayListHead++, arg4, arg5, arg6, 255);

    func_8001CADC(arg0, arg1, 8, 8, D_2000B40, 8, 0);
    func_8001CADC((arg0 + arg2) - 8, arg1, 8, 8, D_2000B80, 8, 0);
    func_8001C330(arg0 + 8, arg1, arg2 - 0x10, 8, 0, 0, 0, 0x400, 0);
    func_8001CADC(arg0, (arg1 + arg3) - 8, 8, 8, D_2000BC0, 8, 0);
    func_8001C330(arg0, arg1 + 8, 8, arg3 - 0x10, 0, 0, 0x400, 0, 0);
    func_8001CADC((arg0 + arg2) - 8, (arg1 + arg3) - 8, 8, 8, D_2000C00, 8, 0);
    func_8001C330(arg0 + 8, (arg1 + arg3) - 8, arg2 - 0x10, 8, 0, 0, 0, 0x400, 0);
    func_8001C330((arg0 + arg2) - 8, arg1 + 8, 8, arg3 - 0x10, 0, 0, 0x400, 0, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F498);

    func_8001C604(arg0 + 8, arg1 + 8, arg2 - 0x10, arg3 - 0x10, arg4, arg5, arg6, 0xFF);

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_830014B0(s16 arg0, s16 arg1) {
    gDPLoadTextureTile(gDisplayListHead++, D_4000C40, G_IM_FMT_IA, G_IM_SIZ_8b, 20, 0, 0, 0, 19, 19, 0,
                       G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                       G_TX_NOLOD);

    func_8001C330(arg0, arg1, 0x14, 0x14, 0, 0, 0x400, 0x400, 0);
}

void func_830015EC(s16 arg0, s16 arg1) {
    s16 tmp;
    s32 i;
    char sp48[0x40];

    func_8001EBE0(0x10, 0);
    func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);

    if (D_83003C9C != NULL) {
        if (D_83003C9C != D_83003CBC) {
            func_8002D5D4(0x27, D_83003C9C);
            func_8001F1E8(arg0 + 0x10, arg1 + 4, func_8002D7C0(sp48, sizeof(sp48), D_830039C0, 1));
        } else {
            func_8001F1E8(arg0 + 0x10, arg1 + 4, D_83003C9C);
        }
    }

    func_8001F1E8(arg0 + 0x30, arg1 + 0x134, func_8002D7C0(NULL, 0, D_830039C0, 2));
    func_8001EBE0(8, 0);

    for (i = 0; i < D_83003CA4; i++) {
        if (i != D_83003CA6) {
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
        } else {
            func_8001F324(0xFF, 0xFF, 0, 0xFF);
        }
        tmp = D_83003CA0[i];
        func_8001F1E8(arg0 + 0x54, arg1 + 0x26 + i * 0x18, D_83003CE0.unk_00[tmp]);
    }
}

void func_830017C0(void) {
    static s16 D_83003B60 = 0;

    s32 i;
    s16 temp_s3;
    s16 temp_s2;

    if (D_83003C92 == 0) {
        return;
    }

    temp_s3 = (((-D_83003C92 * 0xA8) + 0x2A000) / 1024) + 0x5C;
    temp_s2 = (D_83003C92 * 0x150) / 1024;
    func_83000F10(0x38, temp_s3, 0x210, temp_s2);

    if (D_83003C92 >= 0x400) {
        func_83001178(0x38, temp_s3, 0x210, 0x20, 0x3C, 0x3C, 0xA0);
        func_83001178(0x38, temp_s3 + 0x20, 0x210, 0x110, 0x1E, 0x1E, 0x64);
        func_83001178(0x38, temp_s3 + 0x130, 0x210, 0x20, 0x3C, 0x3C, 0xA0);
        if ((func_830026C0() == 0) && (func_830039AC() == 0)) {
            s16 sins = SINS(D_83003B60) * 3.0f;

            func_800207FC(sins + 0x48, temp_s3 + (D_83003CA6 * 0x18) + 0x2A);
            D_83003B60 += 0x1000;
        }

        gSPDisplayList(gDisplayListHead++, D_8006F518);

        func_8001C6AC(0x48, temp_s3 + 0x132, 0x1C, 0x1C, D_04000000, 0x1C, 0);

        for (i = 0; i < D_83003CA4; i++) {
            func_830014B0(0x74, temp_s3 + 0x28 + i * 0x18);
        }

        gSPDisplayList(gDisplayListHead++, D_8006F630);

        func_8001F3F4();
        func_830015EC(0x38, temp_s3);
        func_8001F444();
    }
}

void func_83001A9C(void) {
    func_800079C4();
    if (D_83003C90 != 0) {
        if (D_800AE540.unk_0000 == 0xA) {
            func_830007F4();
        } else {
            func_8001D924(D_83003C8C);
        }

        func_83000A30();

        if (D_83003C90 > 0) {
            D_83003C90--;
        }
    }

    if ((func_830026C0() < 0x400) && (func_830039AC() < 0x400)) {
        func_830017C0();
    }

    func_8300243C();
    func_83003484();
    func_80007778();
}

void func_83001B64(void) {
    s32 i;

    for (i = 0; i < 29; i++) {
        D_83003CE0.unk_00[i] = func_8002D7C0(NULL, 0, D_830039C0, i + 4);
    }

    D_83003CE0.unk_74 = D_83003CE0.unk_00[2];
    D_83003CE0.unk_78 = D_83003CE0.unk_00[10];
    D_83003CE0.unk_7C = D_83003CE0.unk_00[12];
    D_83003CE0.unk_80 = D_83003CE0.unk_00[15];
    D_83003CE0.unk_84 = D_83003CE0.unk_00[22];
    D_83003CE0.unk_88 = D_83003CE0.unk_00[27];
    D_83003CE0.unk_8C = func_8002D7C0(NULL, 0, D_830039C0, 0x21);
    D_83003CE0.unk_90 = D_83003CE0.unk_00[20];
    D_83003CE0.unk_94 = D_83003CE0.unk_00[4];
    D_83003CE0.unk_98 = func_8002D7C0(NULL, 0, D_830039C0, 0x22);
}

void func_83001C4C(void) {
    s32 i;
    s32 var_s2 = 0;

    for (i = 0; i < 39; i++) {
        switch (i) {
            case 7:
            case 11:
            case 14:
            case 19:
            case 24:
                D_83003DE0.unk_00[i] = NULL;
                break;

            default:
                D_83003DE0.unk_00[i] = func_8002D7C0(NULL, 0, D_830039C0, var_s2 + 0x23);
                var_s2++;
                break;
        }
    }
}

void func_83001CF8(void) {
    D_83003C80 = 0;
    D_83003C82 = 0xA;
    D_83003C90 = -1;
    D_83003C92 = 0;
    func_80048B90(4);
    D_83003C98 = 0;
    D_83003C9C = NULL;
    D_83003CA6 = 0;
    D_83003C84 = 0;

    D_83003CA0 = func_83000160(&D_800AE540);
    if (D_83003CA0 == 0) {
        D_83003CA4 = 0;
    } else {
        D_83003CA4 = 0;
        while (D_83003CA0[D_83003CA4] != -1) {
            D_83003CA4++;
        }
    }

    func_83001B64();
    func_83001C4C();

    D_83003CA8 = func_8002D7C0(NULL, 0, D_830039C0, 0x46);
    D_83003CAC = func_8002D7C0(NULL, 0, D_830039C0, 0x45);
    D_83003CB0 = func_8002D7C0(NULL, 0, D_830039C0, 0x49);
    D_83003CB4 = func_8002D7C0(NULL, 0, D_830039C0, 0x47);
    D_83003CB8 = func_8002D7C0(NULL, 0, D_830039C0, 0x48);
    D_83003CBC = func_8002D7C0(NULL, 0, D_830039C0, 0x4A);
    D_83003CC0 = func_8002D7C0(NULL, 0, D_830039C0, 0x4D);
    D_83003CC4 = func_8002D7C0(NULL, 0, D_830039C0, 0x4C);
    D_83003CC8 = func_8002D7C0(NULL, 0, D_830039C0, 0x4B);
    D_83003CCC = func_8002D7C0(NULL, 0, D_830039C0, 0x4E);
    D_83003CD0 = func_8002D7C0(NULL, 0, D_830039C0, 0x4F);
    D_83003CD4 = func_8002D7C0(NULL, 0, D_830039C0, 0x50);

    D_83003CD8 = D_83003CB4;
    D_83003CDC = D_83003CB8;

    D_83003C98 = func_830003A4(D_800AE540.unk_0000);
    D_83003C9C = func_83000418(D_800AE540.unk_0001);

    if (D_800AE540.unk_11F2 != 0) {
        D_83003C84 |= 1;
    }

    if (func_830004BC(D_83003CA0) != 0) {
        D_83003C84 |= 2;
    }

    if (D_83003C84 & 4) {
        D_83003C94 = 0;
    } else {
        D_83003C94 = 0x400;
    }

    func_830023B8();

    func_830032D8((D_83003C84 & 2) ? 1 : 0);
}

s32 func_83002030(void) {
    s32 sp1C = 1;

    switch (D_83003C80) {
        case 0:
            func_83000508();
            break;

        case 1:
            func_8300059C();
            break;

        case 2:
            func_83000710();
            break;

        case 3:
            func_83000750();
            break;

        case 4:
            if (func_830007C4() != 0) {
                sp1C = 0;
            }
            break;
    }
    return sp1C;
}

void func_830020D0(void) {
    func_83001CF8();
    do {
        func_83000130();
        func_830023CC();
        func_830033F0();
        func_83001A9C();
    } while (func_83002030() != 0);
}

s32 func_83002120(UNUSED s32 arg0, UNUSED s32 arg1) {
    main_pool_push_state('EXPL');

    func_8001E94C(0x1C, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_2000000, common_menu2_ui, 0);
    ASSET_LOAD(D_3000000, menu_select_ui, 0);
    ASSET_LOAD(D_04000000, rental_rules_ui, 0);

    func_83000058();
    func_8001B058();
    func_8002D510();
    D_830039C0 = func_8002D5AC(0x20);
    D_830039C4 = func_8002D5AC(0x24);
    func_80007754();
    func_830020D0();
    func_8000771C();

    main_pool_pop_state('EXPL');

    return 0;
}
