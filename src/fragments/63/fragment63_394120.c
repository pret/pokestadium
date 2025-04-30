#include "fragment63.h"
#include "src/12D80.h"
#include "src/1C720.h"
#include "src/1CF30.h"
#include "src/20470.h"
#include "src/232C0.h"
#include "src/26820.h"
#include "src/29BA0.h"
#include "src/2C1C0.h"
#include "src/2E110.h"
#include "src/49790.h"
#include "src/4CBC0.h"
#include "src/6A40.h"
#include "src/6BC0.h"
#include "src/DDC0.h"
#include "src/F420.h"
#include "src/memory.h"
#include "src/stage_loader.h"

s32 func_84B003D4(s32, unk_D_86002F34_alt8*);

unk_D_84B19910 D_84B19910[400];
s32 pad_D_84B1A590[2];
unk_D_84B1A598 D_84B1A598;
unk_D_84B259A8 D_84B259A8;
unk_D_84B259E8 D_84B259E8;
unk_D_84B25A28 D_84B25A28;
unk_D_84B25A58 D_84B25A58;
unk_D_84B25A90 D_84B25A90;
unk_D_84B25AC0 D_84B25AC0;
unk_D_84B25AC0 D_84B26080;
unk_D_84B26640 D_84B26640;
unk_func_80027FA0 D_84B26670;
char** D_84B26678;

static u8* D_84B0FB10[] = {
    D_3015100,
    D_3015700,
    D_3015D00,
    D_3016300,
};
static u32 D_84B0FB20[] = {
    0x0C000000, 0x05000000,    0x0B00002D, 0x00000000, 0x014000F0, 0x00000000,  0xFEDF0000,  0x00000121,  0x05000000,
    0x0D000000, 0x05000000,    0x0F000000, 0x05000000, 0x20050000, 0x00000000,  0x00000000,  0x00000000,  0x00000000,
    0x08000000, func_84B003D4, D_84B19910, 0x06000000, 0x0F000002, 0x05000000,  0x0A000000,  &D_800AC840, 0x06000000,
    0x06000000, 0x0D000001,    0x05000000, 0x0F000002, 0x05000000, 0x0A000000,  &D_800AC840, 0x06000000,  0x06000000,
    0x0D000002, 0x05000000,    0x0F000000, 0x05000000, 0x0A000000, &D_800AC840, 0x06000000,  0x06000000,  0x0D000003,
    0x05000000, 0x14000000,    0x002B0012, 0xFFFFFF32, 0x16FFFFFF, 0x0F000003,  0x05000000,  0x0A000000,  &D_800AC840,
    0x06000000, 0x06000000,    0x06000000, 0x06000000, 0x01000000,
};

void func_84B00020(void) {
    s16 temp_s0;
    unk_D_800AE540_0874* temp_v0;
    unk_func_80026268_arg0* var_s1;

    temp_v0 = D_800AE540.unk_1194[0].unk_08[0]->unk_214;
    temp_s0 = temp_v0->unk_002;
    var_s1 = temp_v0->unk_028;

    if ((D_800AE540.unk_0000 == 3) || (D_800AE540.unk_0000 == 6)) {
        if (D_800AE540.unk_0002 != 3) {
            return;
        }
    } else if ((D_800AE540.unk_0000 == 7) && (D_800AE540.unk_0002 != 9)) {
        return;
    }

    while (temp_s0-- > 0) {
        func_80022978(var_s1++, D_800AE540.unk_0000, D_800AE540.unk_11F2);
    }

    func_80026684(0x13, 0);
}

void func_84B000F0(void) {
    unk_func_8002A728 sp20;
    s32 sp1C = 0;

    func_80027F24(&sp20);

    if ((D_800AE540.unk_0000 == 3) && (D_800AE540.unk_0002 == 3) && !(D_84B26670.unk_00 & 8)) {
        sp1C = 1;
    }

    if ((D_800AE540.unk_0000 == 6) && (D_800AE540.unk_0002 == 3) && !(D_84B26670.unk_00 & 0x40)) {
        sp1C = 1;
    }

    if ((sp1C != 0) && (sp20.unk_00 < 2)) {
        sp20.unk_00++;
        func_80027F40(&sp20);
        if (sp20.unk_00 == 1) {
            D_800AE540.unk_11F6 |= 8;
        } else {
            D_800AE540.unk_11F6 |= 0x10;
        }
    }
}

void func_84B001D8(void) {
    if (((D_800AE540.unk_0000 != 3) || (D_800AE540.unk_0002 >= 3)) &&
        ((D_800AE540.unk_0000 != 6) || (D_800AE540.unk_0002 >= 3)) &&
        ((D_800AE540.unk_0000 != 7) || (D_800AE540.unk_0002 >= 9))) {
        D_84B26670.unk_00 |= (1 << D_800AE540.unk_0000);
        if (D_84B26670.unk_00 == 0xF8) {
            D_84B26670.unk_07 = 1;
            D_800AE540.unk_11F5 |= 4;
        }
        func_80027FE0(&D_84B26670, D_800AE540.unk_11F2);
    }
}

void func_84B00280(void) {
    if (D_800AE540.unk_0000 == 7) {
        if ((D_800AE540.unk_0002 >= D_84B26670.unk_04) && (D_800AE540.unk_0002 < 8)) {
            D_84B26670.unk_04 = D_800AE540.unk_0002 + 1;
            D_800AE540.unk_11F6 |= 0x400;
        }
    } else if (D_800AE540.unk_0000 == 3) {
        if ((D_800AE540.unk_0002 >= D_84B26670.unk_05) && (D_800AE540.unk_0002 < 4)) {
            D_84B26670.unk_05 = D_800AE540.unk_0002 + 1;
            D_800AE540.unk_11F6 |= 0x400;
        }
    } else if ((D_800AE540.unk_0000 == 6) && (D_800AE540.unk_0002 >= D_84B26670.unk_06) && (D_800AE540.unk_0002 < 4)) {
        D_84B26670.unk_06 = D_800AE540.unk_0002 + 1;
        D_800AE540.unk_11F6 |= 0x400;
    }
    func_80027FE0(&D_84B26670, D_800AE540.unk_11F2);
}

char* func_84B0037C(s32 arg0) {
    return func_8002D7C0(NULL, 0, D_84B26678, arg0);
}

char* func_84B003AC(char* arg0, s32 arg1, u32 arg2) {
    return func_8002D7C0(arg0, arg1, D_84B26678, arg2);
}

s32 func_84B003D4(s32 arg0, unk_D_86002F34_alt8* arg1) {
    if (arg0 == 5) {
        func_84B0345C(arg1->unk_00.unk_14);
        func_80015684();
    }
}

void func_84B00404(unk_D_86002F58_004_000* arg0) {
    func_8001BCF0(arg0);
    func_8000E88C(&arg0->unk_024, 0.0f, 0.0f, 0.0f);
    func_8000E88C(&arg0->unk_030, 1.0f, 1.0f, 1.0f);
    func_8000EB70(&arg0->unk_01E, 0, 0, 0);
}

void func_84B00478(void) {
    s32 i;

    for (i = 0; i < 128; i++) {
        func_84B00404(&D_84B1A598.unk_0008[i]);
    }
}

void func_84B004C0(s16 arg0, s16 arg1, char* arg2) {
    s32 sp1C = func_8001F5B0(2, 0, arg2);

    func_8001F3F4();
    func_8001F3B4(0xC);
    func_8001EBE0(2, 0);
    func_8001F1E8(0x20 - (sp1C / 2), arg1, arg2);
    func_8001F444();
}

void func_84B0053C(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    s16 temp_a2;
    s16 temp_s0_32;
    s16 var_s2;
    s16 var_s3;

    if (arg2 >= 0x10) {
        var_s3 = 8;
    } else {
        var_s3 = arg2 / 2;
    }
    if (arg3 >= 0x10) {
        var_s2 = 8;
    } else {
        var_s2 = arg3 / 2;
    }
    temp_a2 = arg2 - (var_s3 * 2);
    temp_s0_32 = arg3 - (var_s2 * 2);

    gSPDisplayList(gDisplayListHead++, D_8006F518);
    gDPSetEnvColor(gDisplayListHead++, arg4, arg5, arg6, arg7);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_3015080, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(arg0, arg1, var_s3, var_s2, 0, 0, 0x2000 / var_s3, 0x2000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_30150C0, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330((arg0 + arg2) - var_s3, arg1, var_s3, var_s2, 0, 0, 0x2000 / var_s3, 0x2000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_3015000, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330(arg0, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x2000 / var_s3, 0x2000 / var_s2, 0);

    gDPLoadTextureBlock_4b(gDisplayListHead++, D_3015040, G_IM_FMT_I, 16, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

    func_8001C330((arg0 + arg2) - var_s3, (arg1 + arg3) - var_s2, var_s3, var_s2, 0, 0, 0x2000 / var_s3,
                  0x2000 / var_s2, 0);

    gSPDisplayList(gDisplayListHead++, D_8006F498);

    if ((temp_a2 > 0) && (temp_s0_32 > 0)) {
        func_8001C604(arg0 + var_s3, arg1, temp_a2, var_s2, arg4, arg5, arg6, arg7);
        func_8001C604(arg0, arg1 + var_s3, arg2, temp_s0_32, arg4, arg5, arg6, arg7);
        func_8001C604(arg0 + var_s3, arg1 + var_s3 + temp_s0_32, temp_a2, var_s2, arg4, arg5, arg6, arg7);
    } else if (temp_a2 > 0) {
        func_8001C604(arg0 + var_s3, arg1, temp_a2, arg3, arg4, arg5, arg6, arg7);
    } else if (temp_s0_32 > 0) {
        func_8001C604(arg0, arg1 + var_s2, arg2, temp_s0_32, arg4, arg5, arg6, arg7);
    }

    gSPDisplayList(gDisplayListHead++, D_8006F630);
}

void func_84B00D3C(unk_D_80068BB0* arg0, s16 arg1, u8* arg2, u8* arg3) {
    unk_D_800AE540_1194* temp_v1 = &D_800AE540.unk_1194[arg1];

    func_80006498(&gDisplayListHead, arg0);

    gSPDisplayList(gDisplayListHead++, D_8006F4E0);

    func_8001C6AC(0, 0, 0x40, 0x20, arg3, 0x40, 0x200000);
    func_8001C6AC(0, 0x20, 0x40, 0x20, arg3 + 0x1000, 0x40, 0x200000);
    func_8001C6AC(0, 0x40, 0x40, 0x20, arg3 + 0x2000, 0x40, 0x200000);
    func_8001C6AC(4, 0x24, 0x38, 0x1C, arg2 + 0x208, 0x40, 0x200000);
    func_8001C6AC(4, 0x40, 0x38, 0x1C, arg2 + 0x1008, 0x40, 0x200000);

    if (D_800AE540.unk_0000 == 0 || D_800AE540.unk_0000 == 9) {
        if (temp_v1->unk_08[0]->unk_000 & 2) {
            func_8001C6AC(8, 4, 0x30, 0x10, &D_3016900, 0x30, 0x200000);
        } else if (temp_v1->unk_01 == 1) {
            func_8001C6AC(8, 4, 0x30, 0x10, D_84B0FB10[temp_v1->unk_08[0]->unk_001], 0x30, 0x200000);
        } else {
            if (temp_v1->unk_08[0]->unk_001 < temp_v1->unk_08[1]->unk_001) {
                func_8001C6AC(8, 4, 0x30, 0x10, D_84B0FB10[temp_v1->unk_08[0]->unk_001], 0x30, 0x200000);
                func_8001C6AC(8, 0x14, 0x30, 0x10, D_84B0FB10[temp_v1->unk_08[1]->unk_001], 0x30, 0x200000);
            } else {
                func_8001C6AC(8, 4, 0x30, 0x10, D_84B0FB10[temp_v1->unk_08[1]->unk_001], 0x30, 0x200000);
                func_8001C6AC(8, 0x14, 0x30, 0x10, D_84B0FB10[temp_v1->unk_08[0]->unk_001], 0x30, 0x200000);
            }
        }

        gSPDisplayList(gDisplayListHead++, D_8006F630);
    } else if ((arg1 == 0) || (D_800AE540.unk_0000 == 0xA)) {
        func_8001C6AC(8, 4, 0x30, 0x10, D_84B0FB10[temp_v1->unk_08[0]->unk_001], 0x30, 0x200000);

        gSPDisplayList(gDisplayListHead++, D_8006F630);

        func_84B004C0(arg1, 0x14, temp_v1->unk_08[0]->unk_214->unk_014);
    } else {
        gSPDisplayList(gDisplayListHead++, D_8006F630);

        func_84B004C0(arg1, 6, temp_v1->unk_08[0]->unk_214->unk_220);
    }
}

void func_84B0117C(s16 arg0) {
    static s16 D_84B0FC0C[] = {
        0x0300, 0x0150, 0xFEB0, 0xFD00, 0xFD00, 0xFEB0, 0x0150, 0x0300,
    };
    static f32 D_84B0FC1C[] = {
        -3.0f, -2.0f, 2.0f, 3.0f, -3.0f, -2.0f, 2.0f, 3.0f,
    };

    s32 i;

    if (arg0 < 0x10) {
        for (i = 0; i < 4; i++) {
            D_84B1A598.unk_0008[i + 0].unk_024.y += 2.0f * arg0 * 0.5f;
            D_84B1A598.unk_0008[i + 0].unk_01E.x += 0x300;
            D_84B1A598.unk_0008[i + 8].unk_024.y += 2.0f * arg0 * 0.5f;
            D_84B1A598.unk_0008[i + 8].unk_01E.x += 0x300;
            D_84B1A598.unk_0008[i + 4].unk_01E.x -= 0x300;
            // clang-format off
            D_84B1A598.unk_0008[i + 4].unk_024.y -= 2.0f * arg0 * 0.5f; D_84B1A598.unk_0008[i + 12].unk_01E.x -= 0x300;
            // clang-format on
            D_84B1A598.unk_0008[i + 12].unk_024.y -= 2.0f * arg0 * 0.5f;
        }

        for (i = 0; i < 8; i++) {
            D_84B1A598.unk_0008[i + 0].unk_01E.z += D_84B0FC0C[i];
            D_84B1A598.unk_0008[i + 8].unk_01E.z += D_84B0FC0C[i];

            D_84B1A598.unk_0008[i + 0].unk_024.x += arg0 * D_84B0FC1C[i] * 0.5f;
            D_84B1A598.unk_0008[i + 8].unk_024.x += arg0 * D_84B0FC1C[i] * 0.5f;
        }
    }
}

void func_84B01474(s16 arg0) {
    s32 i;

    if (arg0 < 0x10) {
        for (i = 0; i < 16; i++) {
            D_84B1A598.unk_0008[i].unk_01D = (-arg0 * 0x10) + 0xF0;
        }

        for (i = 28; i < 32; i++) {
            D_84B1A598.unk_0008[i].unk_01D = (-arg0 * 0x10) + 0xF0;
        }
    }
}

void func_84B014DC(void) {
    func_800079C4();
    func_8000699C(&gDisplayListHead, 1);
    func_80015094(D_84B1A598.unk_0004);
    func_84B0F464(&D_84B26640.unk_1C);
    func_84B0F464(&D_84B26640.unk_28);
    func_80007778();
}

void func_84B01538(void) {
    func_800290B4();
    func_84B03814(D_84B19910);
    func_84B073D8(&D_84B25A28);
    func_84B014DC();
}

s32 func_84B01578(void) {
    s32 i;
    s32 var_s1 = 0;

    func_8002C128();
    func_84B07CF8(&D_84B25A28, D_84B1A598.unk_0004->unk_0C);
    func_84B07758(&D_84B25A28, D_84B1A598.unk_B40C);
    func_8000D1F0(0x31);

    for (i = 0; i < 16; i++) {
        func_84B01538();
    }

    func_80006C6C(8);

    while (func_84B07AB8(&D_84B25A28, D_84B1A598.unk_0008) == 0) {
        func_84B01538();
        var_s1++;
    }

    while (var_s1 < 0x1E) {
        func_84B01538();
        var_s1++;
    }

    for (i = 0; i < 90; i++) {
        func_84B01538();
    }

    func_8000D278(0x20);
    func_80007990(1);
    func_80006CB4(0x10);

    for (i = 0; i < 18; i++) {
        func_84B01538();
    }

    if (D_800AE540.unk_11F5 & 1) {
        D_800AE540.unk_11F5 &= ~1;
        func_8002707C(0x15, 0);
        func_800284B4(2);
    }

    return 4;
}

void func_84B016F4(void) {
    func_800290B4();
    func_84B03814(D_84B19910);
    func_84B04A7C(&D_84B259A8);
    func_84B062E4(&D_84B259E8);
    func_84B073D8(&D_84B25A28);
    func_84B014DC();
}

void func_84B0174C(void) {
    func_84B05728(&D_84B259A8);
    func_84B06A54(&D_84B259E8, D_84B1A598.unk_B408, D_84B1A598.unk_B40C);
    func_84B07CF8(&D_84B25A28, D_84B1A598.unk_0004->unk_0C);
}

s32 func_84B017AC(void) {
    s32 i;
    s32 var_s1;

    if (osTvType == OS_TV_PAL) {
        var_s1 = 0x4B;
    } else {
        var_s1 = 0x5A;
    }

    func_8002C128();
    func_84B0174C();
    func_84B07758(&D_84B25A28, D_84B1A598.unk_B40C);

    for (i = 0; i < 16; i++) {
        func_84B016F4();
    }

    func_80006C6C(8);

    for (i = 0; i < 20; i++) {
        func_84B016F4();
    }

    func_84B04F78(&D_84B259A8, &D_84B1A598.unk_0008[0x10]);
    func_84B06364(&D_84B259E8, D_84B1A598.unk_0008, 0);
    func_8000D1F0(0x33);

    for (i = 0; i < var_s1; i++) {
        func_84B016F4();
    }

    func_84B0509C(&D_84B259A8);
    D_84B259E8.unk_00 = 2;

    for (i = 0; i < 16; i++) {
        func_84B016F4();
    }

    while (func_84B07AB8(&D_84B25A28, D_84B1A598.unk_0008) == 0) {
        func_84B016F4();
    }

    for (i = 0; i < var_s1; i++) {
        func_84B016F4();
    }

    func_8000D278(0x20);
    func_80007990(1);
    func_80006CB4(0x10);

    for (i = 0; i < 18; i++) {
        func_84B016F4();
    }

    if (D_800AE540.unk_11F5 & 1) {
        D_800AE540.unk_11F5 &= ~1;
        func_8002707C(0x15, 0);
        func_800284B4(2);
    }

    return 4;
}

void func_84B01994(void) {
    s32 i;
    s32 j;
    unk_D_800AE540_0004* var_a1;
    unk_D_800AE540_0874* temp_v1;

    if (!(D_800AE540.unk_11F5 & 2) && (D_800AE540.unk_11F2 == 1) && (D_800AE540.unk_0000 == 6) &&
        (D_800AE540.unk_0002 == 3)) {
        var_a1 = D_800AE540.unk_1194[0].unk_08[0];
        temp_v1 = var_a1->unk_214;

        for (i = 0; i < temp_v1->unk_002; i++) {
            s32 tmp = (temp_v1->unk_028[i].unk_52 & 0x70) >> 4;
            s32 tmp2 = temp_v1->unk_028[i].unk_52 & 0xF;

            if ((tmp >= 4) || (tmp2 >= 13)) {
                return;
            }
        }

        for (i = 0; i < var_a1->unk_002; i++) {
            unk_func_80026268_arg0* ptr = &var_a1->unk_01C[i];

            if (ptr->unk_00.unk_00 == 0x19) {
                for (j = 0; j < 4; j++) {
                    if (ptr->unk_09[j] == 0) {
                        break;
                    } else if (ptr->unk_09[j] == 0x39) {
                        return;
                    }
                }
                D_800AE540.unk_11F6 |= 0x1000;
                break;
            }
        }
    }
}

void func_84B01AA0(void) {
    func_800290B4();
    func_84B03814(D_84B19910);
    func_84B0A1F4(&D_84B25A58);
    func_84B062E4(&D_84B259E8);
    func_84B0BBEC(&D_84B25A90);
    func_84B0D4B4(&D_84B25AC0);
    func_84B0D4B4(&D_84B26080);
    func_84B0D970(&D_84B26640.unk_00);
    func_84B0D970(&D_84B26640.unk_10);
    func_84B0F8E8(&D_84B26640.unk_1C);
    func_84B0F8E8(&D_84B26640.unk_28);
    func_84B014DC();
}

void func_84B01B40(void) {
    s32 tmp;

    func_84B0A9D0(&D_84B25A58);
    func_84B06A54(&D_84B259E8, D_84B1A598.unk_B408, D_84B1A598.unk_B40C);
    func_84B0BE28(&D_84B25A90);

    if (D_84B1A598.unk_0003 != 0) {
        func_84B0D7A8(&D_84B25AC0, 1, -1);
        func_84B0D7A8(&D_84B26080, 0, -1);
    } else {
        func_84B0D7A8(&D_84B25AC0, 1, D_84B1A598.unk_0001);
        tmp = D_84B1A598.unk_0001 == 0;
        func_84B0D7A8(&D_84B26080, 0, tmp);
    }

    func_84B0DAA4(&D_84B26640.unk_00, 0);
    func_84B0DAA4(&D_84B26640.unk_10, 1);
}

void func_84B01C2C(void) {
    s32 i;

    func_84B0A544(&D_84B25A58, D_84B1A598.unk_B40C);

    for (i = 0; i < 8; i++) {
        func_84B01AA0();
    }

    if (D_800AE540.unk_1194[1].unk_08[0]->unk_000 & 2) {
        if (D_800AE540.unk_1194[0].unk_1C == 1) {
            func_8000D1F0(0x32);
        } else {
            func_8000D1F0(0x45);
        }
    } else {
        func_8000D1F0(0x32);
    }

    func_80006C6C(8);

    while (func_84B0A634(&D_84B25A58, D_84B1A598.unk_0008) == 0) {
        func_84B01AA0();
    }

    while (D_84B25A58.unk_00 != 0) {
        func_84B01AA0();
    }

    func_84B0D54C(&D_84B25AC0, &D_84B1A598.unk_0008[0x1C], &D_84B1A598.unk_0008[0x20]);
    func_84B0D54C(&D_84B26080, &D_84B1A598.unk_0008[0x1E], &D_84B1A598.unk_0008[0x20]);

    while ((D_84B259E8.unk_00 != 0) || (D_84B26080.unk_5A0 != 0)) {
        func_84B01AA0();
    }
}

void func_84B01DBC(void) {
    s32 i;

    func_84B0A544(&D_84B25A58, D_84B1A598.unk_B40C);

    for (i = 0; i < 8; i++) {
        func_84B01AA0();
    }

    func_8000D1F0(0x32);
    func_80006C6C(8);

    while (func_84B0A634(&D_84B25A58, D_84B1A598.unk_0008) == 0) {
        func_84B01AA0();
    }

    for (i = 0; i < 50; i++) {
        func_84B01AA0();
    }

    func_84B0D9D8(&D_84B26640.unk_00, &D_84B1A598.unk_0008[0x1A]);
    func_8004DF94(0x01100013, 0, 0);

    while (D_84B25A58.unk_00 != 0) {
        func_84B01AA0();
    }

    func_84B0DA90(&D_84B26640.unk_00);
    func_84B0D54C(&D_84B25AC0, &D_84B1A598.unk_0008[0x1C], &D_84B1A598.unk_0008[0x20]);
    func_84B0D54C(&D_84B26080, &D_84B1A598.unk_0008[0x1E], &D_84B1A598.unk_0008[0x20]);

    if (D_800AE540.unk_0003 < 8) {
        for (i = 0; i < 16; i++) {
            func_84B01AA0();
        }
        func_84B0D9D8(&D_84B26640.unk_10, &D_84B1A598.unk_0008[0x1B]);
        func_80048B90(0x28);
    }

    while ((D_84B259E8.unk_00 != 0) || (D_84B26080.unk_5A0 != 0)) {
        func_84B01AA0();
    }
}

void func_84B01F94(void) {
    s32 i;
    s32 tmp;

    func_84B0D718(&D_84B26080);
    tmp = D_84B1A598.unk_0001 == 0;
    func_84B06364(&D_84B259E8, D_84B1A598.unk_0008, tmp + 1);

    while ((D_84B259E8.unk_00 != 0) || (D_84B26080.unk_5A0 != 0)) {
        func_84B01AA0();
    }

    for (i = 0; i < 16; i++) {
        func_84B01AA0();
    }
}

void func_84B0204C(void) {
    s32 i;
    s32 j;

    while ((D_84B25AC0.unk_5A0 != 0) || (D_84B26080.unk_5A0 != 0)) {
        func_84B01AA0();
    }

    for (i = 16; i < ARRAY_COUNT(D_84B1A598.unk_0008); i++) {
        func_84B00404(&D_84B1A598.unk_0008[i]);
    }

    func_8004DF94(0x01100017, 0, 0);

    for (j = 0; j < 16; j++) {
        func_800290B4();
        func_84B0117C(j);
        func_84B03814(D_84B19910);
        func_84B014DC();
    }

    for (i = 0; i < 16; i++) {
        func_84B00404(&D_84B1A598.unk_0008[i]);
    }

    for (j = 0; j < 16; j++) {
        func_800290B4();
        func_84B03814(D_84B19910);
        func_84B014DC();
    }
}

void func_84B02188(void) {
    s32 i;

    func_8000D278(0x3C);

    for (i = 0; i < 16; i++) {
        func_800290B4();
        func_84B01474(i);
        func_84B03814(D_84B19910);
        func_84B014DC();
    }
}

void func_84B021FC(void) {
    s32 i;

    func_8000D278(0x3C);
    func_80007990(1);
    func_80006CB4(0x10);

    for (i = 0; i < 18; i++) {
        func_800290B4();
        func_84B03814(D_84B19910);
        func_84B014DC();
    }

    for (i = 0; i < 16; i++) {
        func_800290B4();
        func_84B03814(D_84B19910);
        func_84B014DC();
    }
}

s32 func_84B022A0(void) {
    s32 var_s2;
    s32 var_v0_2;

    if (D_800AE540.unk_0000 == 7) {
        func_84B0F950(&D_84B26640.unk_1C, 2);
    } else {
        func_84B0F950(&D_84B26640.unk_1C, 1);
    }

    var_s2 = func_84B0FADC(&D_84B26640.unk_1C);
    while (var_s2 == -1) {
        func_84B01AA0();
        var_s2 = func_84B0FADC(&D_84B26640.unk_1C);
    }

    if (var_s2 == 1) {
        if (func_8002847C() != 0) {
            func_84B0F950(&D_84B26640.unk_1C, 0xA);

            var_v0_2 = func_84B0FADC(&D_84B26640.unk_1C);
            while (var_v0_2 == -1) {
                func_84B01AA0();
                var_v0_2 = func_84B0FADC(&D_84B26640.unk_1C);
            }

            if (var_v0_2 == 1) {
                var_s2 = 0;
            }
        }
        if (var_s2 == 1) {
            D_800AE540.unk_0003 = D_800AE540.unk_0003 + 1;
            func_8002C538();
            func_800284B4(2);
        }
    }
    return var_s2;
}

s32 func_84B023C0(void) {
    s32 sp24 = 1;
    s32 var_v0;

    if (func_8002847C() != 0) {
        func_84B0F950(&D_84B26640.unk_1C, 0xA);

        var_v0 = func_84B0FADC(&D_84B26640.unk_1C);
        while (var_v0 == -1) {
            func_84B01AA0();
            var_v0 = func_84B0FADC(&D_84B26640.unk_1C);
        }

        if (var_v0 == 1) {
            sp24 = 0;
        }
    }

    if (sp24 != 0) {
        D_800AE540.unk_11F3--;
        func_8002C538();
        func_800284B4(2);
    }
    return sp24;
}

s32 func_84B02474(void) {
    s32 var_v0;

    if (D_800AE540.unk_1194[0].unk_1C == 1) {
        D_800AE540.unk_1194[0].unk_1E += 1;
    }

    if (D_800AE540.unk_1194[1].unk_1C == 1) {
        D_800AE540.unk_1194[1].unk_1E += 1;
    }

    func_84B01C2C();
    func_8004DF94(0x0110000F, 0, 0);
    func_84B0F950(&D_84B26640.unk_1C, 9);
    func_84B0F950(&D_84B26640.unk_28, 5);

    var_v0 = func_84B0FADC(&D_84B26640.unk_28);
    while (var_v0 == -1) {
        func_84B01AA0();
        var_v0 = func_84B0FADC(&D_84B26640.unk_28);
    }

    switch (var_v0) {
        case 0:
            D_800AE540.unk_11F6 |= 0x21;
            break;

        case 1:
            D_800AE540.unk_11F6 |= 0x81;
            break;

        case 2:
            D_800AE540.unk_11F6 |= 1;
            break;
    }

    func_84B0D718(&D_84B26080);
    func_84B0D718(&D_84B25AC0);
    func_8004DF94(0x0110000D, 0, 0);
    func_84B0204C();
    func_84B021FC();

    return 4;
}

s32 func_84B025D0(void) {
    func_84B01C2C();

    do {
        func_84B01AA0();
    } while (!(BTN_IS_PRESSED(gPlayer1Controller, BTN_A)));

    func_84B0D718(&D_84B26080);
    func_84B0D718(&D_84B25AC0);
    func_8004DF94(0x0110000D, 0, 0);
    func_84B0204C();
    func_84B021FC();

    return 4;
}

s32 func_84B02654(void) {
    UNUSED s32 pad[2];
    s32 sp2C = 4;
    s32 i;
    s32 var_s2;
    s32 var_v0;

    if (D_84B1A598.unk_0002 != 0) {
        func_84B01DBC();
    } else {
        func_84B01C2C();
    }

    func_84B01F94();

    if (D_800AE540.unk_1194[0].unk_1C == 1) {
        D_800AE540.unk_11F3 += D_84B1A598.unk_0002;
        if ((D_84B1A598.unk_0002 != 0) && (D_800AE540.unk_0003 < 8)) {
            func_84B0DA90(&D_84B26640.unk_10);
        }

        func_84B0D718(&D_84B25AC0);
        func_84B0BC6C(&D_84B25A90, D_84B1A598.unk_0008);

        while (D_84B25A90.unk_00 != 3) {
            func_84B01AA0();
        }

        if (D_800AE540.unk_0003 == 8) {
            for (i = 0; i < 120; i++) {
                func_84B01AA0();
                if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
                    break;
                }
            }

            func_84B00020();
            func_84B000F0();
            func_84B001D8();
            func_84B00280();
            func_80026684(0x14, 0);
            func_800284B4(2);
            func_84B0204C();
            func_84B021FC();
            func_84B01994();
            D_800AE540.unk_11F6 |= 3;
        } else if (func_84B022A0() == 1) {
            func_84B0204C();
            func_84B021FC();
            D_800AE540.unk_11F6 |= 0x41;
        } else {
            func_84B0204C();
            func_8000D278(0x50);
            D_800AE540.unk_0003++;
            sp2C = 1;
        }
    } else {
        var_s2 = 1;
        while (var_s2 != 0) {
            func_84B0F950(&D_84B26640.unk_1C, 7);
            func_84B0F950(&D_84B26640.unk_28, 3);

            var_v0 = func_84B0FADC(&D_84B26640.unk_28);
            while (var_v0 == -1) {
                func_84B01AA0();
                var_v0 = func_84B0FADC(&D_84B26640.unk_28);
            }

            switch (var_v0) {
                case 0:
                    sp2C = 1;
                    D_800AE540.unk_11F3--;
                    var_s2 = 0;
                    break;

                case 1:
                    if (func_84B023C0() != 0) {
                        var_s2 = 0;
                        D_800AE540.unk_11F6 |= 0x41;
                    }
                    break;

                case 2:
                    var_s2 = 0;
                    D_800AE540.unk_11F6 |= 0x21;
                    break;

                case 3:
                    var_s2 = 0;
                    D_800AE540.unk_11F6 |= 0x801;
                    break;

                case 4:
                    var_s2 = 0;
                    D_800AE540.unk_11F6 |= 1;
                    break;
            }
        }

        if (sp2C == 4) {
            func_84B0D718(&D_84B25AC0);
            func_84B0204C();
            func_84B021FC();
        } else {
            func_84B02188();
            func_84B00478();
        }
    }

    return sp2C;
}

s32 func_84B02984(void) {
    s32 sp28;
    s32 i;
    s32 sp24 = 4;
    s32 var_v0;

    func_84B01C2C();
    func_84B01F94();

    if (D_800AE540.unk_1194[0].unk_1C == 1) {
        if ((D_800AE540.unk_0003 == 4) || (D_800AE540.unk_0002 == 9)) {
            func_84B001D8();
            func_84B00280();
            func_84B00020();
            func_80026684(0x14, 0);
            func_800284B4(2);

            for (i = 0; i < 60; i++) {
                func_84B01AA0();
                if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
                    break;
                }
            }

            func_84B0D718(&D_84B25AC0);
            func_8004DF94(0x0110000D, 0, 0);
            func_84B0204C();
            func_8000D278(0x10);

            D_800AE540.unk_11F6 |= 1;
            if (D_800AE540.unk_0002 == 8) {
                D_800AE540.unk_11F6 |= 0x400;
            }

            if (D_800AE540.unk_0002 == 9) {
                D_800AE540.unk_11F6 |= 0x200;
            } else {
                D_800AE540.unk_11F6 |= 0x100;
            }
            sp24 = 3;
        } else if (func_84B022A0() == 1) {
            func_84B0D718(&D_84B25AC0);
            func_8004DF94(0x0110000D, 0, 0);
            func_84B0204C();
            func_84B021FC();
            D_800AE540.unk_11F6 |= 0x41;
        } else {
            func_84B0D718(&D_84B25AC0);
            func_8004DF94(0x0110000D, 0, 0);
            func_84B0204C();
            func_8000D278(0x50);
            D_800AE540.unk_0003++;
            sp24 = 1;
        }
    } else {
        func_84B0F950(&D_84B26640.unk_1C, 8);
        func_84B0F950(&D_84B26640.unk_28, 4);

        var_v0 = func_84B0FADC(&D_84B26640.unk_28);
        while (var_v0 == -1) {
            func_84B01AA0();
            var_v0 = func_84B0FADC(&D_84B26640.unk_28);
        }

        switch (var_v0) {
            case 0:
                D_800AE540.unk_11F6 |= 0x21;
                break;

            case 1:
                D_800AE540.unk_11F6 |= 0x801;
                break;

            case 2:
                D_800AE540.unk_11F6 |= 1;
                break;
        }

        func_84B0D718(&D_84B25AC0);
        func_84B0204C();
        func_84B021FC();

        if (D_800AE540.unk_0002 == 9) {
            D_800AE540.unk_0002 = 8;
        }
    }
    return sp24;
}

s32 func_84B02C40(void) {
    s32 var_v0;
    u16 sp2A;

    func_84B01C2C();
    if (D_800AE540.unk_1194[0].unk_1C == 1) {
        s32 tmp1 = !!(D_84B26670.unk_00 & 0x100);

        if ((D_800AE540.unk_11F2 == 0) & !tmp1) {
            func_80028070(&sp2A);
            sp2A |= 4;
            func_80028084(&sp2A);
        }

        func_84B001D8();
        func_80026684(0x14, 0);
        func_800284B4(2);
        func_84B0D718(&D_84B26080);
        func_84B0D718(&D_84B25AC0);
        func_8004DF94(0x0110000D, 0, 0);
        func_84B0204C();
        func_84B021FC();
        D_800AE540.unk_11F6 |= 5;
    } else {
        func_84B0F950(&D_84B26640.unk_28, 6);

        var_v0 = func_84B0FADC(&D_84B26640.unk_28);
        while (var_v0 == -1) {
            func_84B01AA0();
            var_v0 = func_84B0FADC(&D_84B26640.unk_28);
        }

        switch (var_v0) {
            case 0:
                D_800AE540.unk_11F6 |= 0x21;
                break;

            case 1:
                D_800AE540.unk_11F6 |= 1;
                break;
        }

        func_84B0D718(&D_84B26080);
        func_84B0D718(&D_84B25AC0);
        func_8004DF94(0x0110000D, 0, 0);
        func_84B0204C();
        func_84B021FC();
    }
    return 4;
}

u8 func_84B02DF8(void) {
    s32 i;
    u8 var_v1 = 0;

    if ((D_800AE540.unk_0000 > 0) && (D_800AE540.unk_0000 < 7)) {
        if (D_800AE540.unk_1194[0].unk_1C == 1) {
            var_v1 = 1;
            for (i = 0; i < 3; i++) {
                if (D_800AE540.unk_1194[0].unk_08[0]->unk_01C[i].unk_02 == 0) {
                    var_v1 = 0;
                }
            }
        }
    }

    return var_v1;
}

s32 func_84B02E5C(void) {
    s32 var_v0;

    D_84B1A598.unk_0002 = func_84B02DF8();
    func_84B01B40();

    switch (D_800AE540.unk_0000) {
        case 0:
            var_v0 = func_84B02474();
            break;

        case 1:
            var_v0 = func_84B02654();
            break;

        case 2:
            var_v0 = func_84B02654();
            break;

        case 3:
            var_v0 = func_84B02654();
            break;

        case 4:
            var_v0 = func_84B02654();
            break;

        case 5:
            var_v0 = func_84B02654();
            break;

        case 6:
            var_v0 = func_84B02654();
            break;

        case 7:
            var_v0 = func_84B02984();
            break;

        case 8:
            var_v0 = func_84B02C40();
            break;

        case 9:
            var_v0 = func_84B025D0();
            break;

        case 10:
            var_v0 = func_84B025D0();
            break;
    }
    return var_v0;
}

s32 func_84B02F60(void) {
    s32 i;
    s32 var_s1;

    if (D_800AE540.unk_0002 == 9) {
        var_s1 = 0x3C;
    } else {
        var_s1 = 0x4B;
    }

    func_84B05728(&D_84B259A8);
    func_84B050AC(&D_84B259A8, &D_84B1A598.unk_0008[0x10]);
    func_8000D1F0(0x3F);

    for (i = 0; i < var_s1; i++) {
        func_800290B4();
        func_84B03814(D_84B19910);
        func_84B04A7C(&D_84B259A8);
        func_84B014DC();
    }

    func_80007990(1);
    func_80006CB4(0x10);

    for (i = 0; i < 18; i++) {
        func_800290B4();
        func_84B03814(D_84B19910);
        func_84B04A7C(&D_84B259A8);
        func_84B014DC();
    }

    return 4;
}

void func_84B03064(void) {
    MemoryBlock* temp_v0;
    unk_D_86002F34_00C* ptr;
    unk_D_86002F58_004_000* ptr2;
    s32 i;

    D_84B1A598.unk_0001 = 0;
    D_84B1A598.unk_0003 = 0;
    if (D_800AE540.unk_1194[0].unk_1C == D_800AE540.unk_1194[1].unk_1C) {
        D_84B1A598.unk_0003 = 1;
    } else if (D_800AE540.unk_1194[0].unk_1C == 1) {
        D_84B1A598.unk_0001 = 1;
    }

    func_8001BB20();

    for (i = 0, ptr2 = &D_84B1A598.unk_0008[0]; i < 128; ptr2++, i++) {
        func_8001BB58(ptr2);
        D_84B1A598.unk_0008[i].unk_0A6 = i;
    }

    temp_v0 = func_80002D10(main_pool_get_available(), 0);
    D_84B1A598.unk_0004 = process_geo_layout(temp_v0, &D_84B0FB20);
    func_80002D60(temp_v0);

    ptr = D_84B1A598.unk_0004->unk_0C;
    ptr->unk_24.near = 10.0f;
    ptr->unk_24.far = 6000.0f;

    func_84B038F8(&D_84B19910);
    func_84B0FACC(&D_84B26640.unk_1C);
    func_84B0FACC(&D_84B26640.unk_28);
}

s32 func_84B03194(s32 arg0, UNUSED s32 arg1) {
    unk_func_80007444* sp2C;

    main_pool_push_state('EYEC');
    func_80028AFC(2);
    func_80027FA0(&D_84B26670, D_800AE540.unk_11F2);
    func_80005E40(0x18000, 0);
    sp2C = func_80007444(0, 1, 3, 1, 2, 1);
    func_8001E94C(0x17, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_2000000, badge_ui, 0);
    ASSET_LOAD(D_3000000, common_menu0_ui, 0);

    func_8002D510();
    D_84B26678 = func_8002D5AC(0x1B);
    func_8001B058();

    D_84B1A598.unk_B408 = func_800044F4(0x898000, NULL, 1, 1);
    D_84B1A598.unk_B40C = ASSET_LOAD2(battle_portraits, 1, 1);

    func_80007678(sp2C);
    func_84B03064();

    while (arg0 < 4) {
        main_pool_push_state('eye0');

        switch (arg0) {
            case 0:
                arg0 = func_84B01578();
                break;

            case 1:
                arg0 = func_84B017AC();
                break;

            case 2:
                arg0 = func_84B02E5C();
                break;

            case 3:
                arg0 = func_84B02F60();
                break;
        }

        main_pool_pop_state('eye0');
    }

    func_800076C0();
    func_8001E9CC();
    func_80005EAC();

    main_pool_pop_state('EYEC');

    return 0;
}
