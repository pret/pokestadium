#include "fragment17.h"
#include "src/12D80.h"
#include "src/17300.h"
#include "src/geo_layout.h"
#include "src/19840.h"
#include "src/1C720.h"
#include "src/1CF30.h"
#include "src/20330.h"
#include "src/26820.h"
#include "src/2E110.h"
#include "src/3FB0.h"
#include "src/4BDC0.h"
#include "src/6BC0.h"
#include "src/F420.h"
#include "src/controller.h"
#include "src/fragments/34/fragment34.h"
#include "src/memory.h"
#include "src/stage_loader.h"

typedef struct unk_D_86B0E5D8 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ u8 unk_06;
    /* 0x07 */ u8 unk_07;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
} unk_D_86B0E5D8; // size = 0xC

extern u32 D_86B0BD60[];
extern unk_D_86B0C4C8* D_86B0C4C8[];
extern unk_D_86B0C160 D_86B0C160[];
extern unk_D_86B0C264 D_86B0C264[];
extern u32 D_86B0CF9C[];
extern u32 D_86B0DA9C[];

s32 func_86B000D0(s32, GraphNode*);
s32 func_86B00158(s32, GraphNode*);
s32 func_86B00188(s32, GraphNode*);
s32 func_86B001B8(s32, GraphNode*);

static s16 D_86B0BBF0 = -0x3C6E;
static s16 D_86B0BBF4 = 0x38E;

static u32 D_86B0BBF8[] = {
    0x0C00FFFF, 0x05000000, 0x0B00001E, 0x00000000, 0x014000F0,  0x0000000F,    0x00000000,    0x00000000,
    0x05000000, 0x0D000000, 0x05000000, 0x1A050000, 0x08000000,  func_86B001B8, 0x00000000,    0x05000000,
    0x0F000002, 0x05000000, 0x06000000, 0x0F000002, 0x05000000,  0x06000000,    0x0F000002,    0x05000000,
    0x1F00FFFF, 0xC3920000, 0x00000000, 0xFC400000, 0x00640064,  0x00640000,    0x08000000,    func_86B00158,
    0x00000000, 0x05000000, 0x00000000, D_86B0CF9C, 0x06000000,  0x06000000,    0x0F000002,    0x05000000,
    0x1F00FFFF, 0x00000000, 0x00000000, 0x0514F79A, 0x00640064,  0x00640000,    0x08000000,    func_86B00188,
    0x00000000, 0x05000000, 0x00000000, D_86B0DA9C, 0x06000000,  0x06000000,    0x0F000002,    0x05000000,
    0x06000000, 0x06000000, 0x14000000, 0xF8E40000, 0xFFC89BFF,  0x08000000,    func_86B000D0, 0x00000000,
    0x16FFFFFF, 0x0F000003, 0x05000000, 0x0A000000, &D_800AC840, 0x06000000,    0x06000000,    0x06000000,
    0x06000000, 0x01000000,
};

static GraphNode* D_86B0E5D0;
static unk_D_86B0E5D4* D_86B0E5D4;
static unk_D_86B0E5D8* D_86B0E5D8;
s32 D_86B0E5DC;
char** D_86B0E5E0;
static BinArchive* D_86B0E5E4;
static u8* D_86B0E5E8;
static unk_D_86B0E5F0 D_86B0E5F0[4];
static s32 D_86B0EBB0;
static s32 D_86B0EBB4;
static u16 D_86B0EBB8;

s32 func_86B000D0(s32 arg0, GraphNode* arg1) {
    if (arg0 == 2) {
        unk_D_86002F34_alt18* ptr = (unk_D_86002F34_alt18*)arg1;

        D_86B0E5D8->unk_00 += D_86B0E5D8->unk_08;
        D_86B0E5D8->unk_02 += D_86B0E5D8->unk_0A;

        ptr->unk_1C = D_86B0E5D8->unk_00;
        ptr->unk_1E = D_86B0E5D8->unk_02;
        ptr->r = D_86B0E5D8->unk_05;
        ptr->g = D_86B0E5D8->unk_06;
        ptr->b = D_86B0E5D8->unk_07;
        ptr->a = D_86B0E5D8->unk_04;
    }

    return 0;
}

s32 func_86B00158(s32 arg0, GraphNode* arg1) {
    if (arg0 == 2) {
        unk_D_86002F58_004_000* ptr = (unk_D_86002F58_004_000*)arg1;

        ptr->unk_030.x = 1.5f;
        ptr->unk_030.y = 1.5f;
        ptr->unk_030.z = 1.5f;
        ptr->unk_01E.x = D_86B0BBF0;
    }

    return 0;
}

s32 func_86B00188(s32 arg0, GraphNode* arg1) {
    if (arg0 == 2) {
        unk_D_86002F58_004_000* ptr = (unk_D_86002F58_004_000*)arg1;

        ptr->unk_030.x = 1.0f;
        ptr->unk_030.y = 1.0f;
        ptr->unk_030.z = 1.0f;

        ptr->unk_01E.x = D_86B0BBF4;
    }
    return 0;
}

s32 func_86B001B8(s32 arg0, GraphNode* arg1) {
    if (arg0 == 2) {
        unk_D_86002F34_alt21* ptr = (unk_D_86002F34_alt21*)arg1;

        ptr->unk_1A = D_86B0E5D4->unk_04.unk_44;
    }
    return 0;
}

void func_86B001D8(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_86B0E5F0[i].unk_16C = 0;
    }
}

void func_86B001FC(unk_D_86B0E5F0* arg0) {
    while (arg0->unk_16C != 1) {
        func_8001BCF0(&arg0->unk_004);
        arg0++;
    }
    main_pool_pop_state('MONS');
}

void func_86B00258(void) {
    main_pool_push_state('MONS');
}

void func_86B0027C(unk_D_86B0E5F0* arg0, unk_D_86B0C4C8* arg1) {
    func_8001BB58(&arg0->unk_004);

    arg0->unk_000 = func_80019D18(arg1->unk_0C);

    func_8001BC34(&arg0->unk_004, 0, arg1->unk_0C, arg0->unk_000->unk_08->unk_00[0]);
    func_8001BD04(&arg0->unk_004, arg1->unk_10);

    if (arg1->unk_0C == 6) {
        arg0->unk_004.unk_0A6 = 0;
    } else {
        arg0->unk_004.unk_0A6 = 0xFF;
    }

    func_80017464(&arg0->unk_004, 0);
    arg0->unk_004.unk_000.unk_02 &= ~0x40;
}

void func_86B0032C(unk_D_86B0E5F0* arg0, unk_D_86B0C4C8* arg1) {
    arg0->unk_004.unk_024.x = arg1->unk_00.x;
    arg0->unk_004.unk_024.y = arg1->unk_00.y;
    arg0->unk_004.unk_024.z = arg1->unk_00.z;
}

void func_86B00348(s32 arg0) {
    D_86B0E5D8->unk_00 = D_86B0C264[arg0].unk_0C;
    D_86B0E5D8->unk_02 = D_86B0C264[arg0].unk_0E;
    D_86B0E5D8->unk_08 = D_86B0C264[arg0].unk_18;
    D_86B0E5D8->unk_0A = D_86B0C264[arg0].unk_1A;
    D_86B0E5D8->unk_05 = D_86B0C264[arg0].unk_10;
    D_86B0E5D8->unk_06 = D_86B0C264[arg0].unk_12;
    D_86B0E5D8->unk_07 = D_86B0C264[arg0].unk_14;
    D_86B0E5D8->unk_04 = D_86B0C264[arg0].unk_16;
}

void func_86B003CC(s32 arg0) {
    unk_D_86B0C4C8* var_s0 = D_86B0C4C8[arg0];
    unk_D_86B0E5F0* var_s1 = D_86B0E5F0;

    func_86B001D8();
    func_86B00258();

    while (var_s0->unk_0C != 0x98) {
        func_86B0027C(var_s1, var_s0);
        func_86B0032C(var_s1, var_s0);
        var_s1->unk_16C = 1;

        var_s1++;
        var_s0++;
    }

    func_86B00348(arg0);
}

void func_86B00470(s32 arg0) {
    unk_D_86B0C4C8* sp2C = D_86B0C4C8[arg0];
    unk_D_86B0E5F0* var_s1 = D_86B0E5F0;

    func_86B001FC(D_86B0E5F0);
    func_86B001D8();
    func_86B00258();

    while (sp2C->unk_0C != 0x98) {
        func_86B0027C(var_s1, sp2C);
        func_86B0032C(var_s1, sp2C);
        var_s1->unk_16C = 1;

        var_s1++;
        sp2C++;
    }

    func_86B00348(arg0);

    if (arg0 == 4) {
        func_8001BD9C(&D_86B0E5F0[0].unk_004, 0);
    }
}

void func_86B0054C(s32 arg0) {
    if (arg0 == 4) {
        D_86B0E5D4->unk_00->unk_60.at.x = -0.04f;
        D_86B0E5D4->unk_00->unk_60.at.y = 24.2f;
        D_86B0E5D4->unk_00->unk_60.at.z = -4.08f;
        D_86B0E5D4->unk_00->unk_60.eye.x = 0.04f;
        D_86B0E5D4->unk_00->unk_60.eye.y = 24.2f;
        D_86B0E5D4->unk_00->unk_60.eye.z = 177.41f;
        D_86B0E5D4->unk_00->unk_24.fovy = 25.0f;
    } else {
        D_86B0E5D4->unk_04.unk_00.x = D_86B0C264[arg0].unk_00.x;
        D_86B0E5D4->unk_04.unk_00.y = D_86B0C264[arg0].unk_00.y;
        D_86B0E5D4->unk_04.unk_00.z = D_86B0C264[arg0].unk_00.z;

        func_86B0194C(&D_86B0C160[arg0], D_86B0E5D4);
        func_86B01A40(&D_86B0E5D4->unk_04, D_86B0E5D4);
    }
}

void func_86B00680(void) {
}

void func_86B00688(void) {
    s32 i = 0;

    if ((D_86B0E5D4->unk_04.unk_4C != 5) && (D_86B0E5D4->unk_04.unk_4C != 6) && (D_86B0E5D4->unk_04.unk_4C != 7) &&
        (D_86B0E5D4->unk_04.unk_4C != 8)) {
        if (D_86B0E5D4->unk_04.unk_44 != 4) {
            while (D_86B0C4C8[D_86B0E5D4->unk_04.unk_44][i].unk_0C != 0x98) {
                if (func_800174E4(&D_86B0E5F0[i].unk_004) != 0) {
                    func_80017464(&D_86B0E5F0[i].unk_004, 0);
                }
                i++;
            }
        }
    }
}

void func_86B00794(void) {
    if (D_86B0E5D4->unk_04.unk_48 == 1) {
        func_8001F504(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 0, D_86B0EBB0);
    }
}

void func_86B007EC(void) {
    if (D_86B0E5D4->unk_04.unk_44 == 2) {
        func_86B01D8C(&D_86B0BD60, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 4, 0x80);
    }
}

s32 func_86B00848(s32 arg0) {
    unk_D_86B0E5F0* var_v0 = D_86B0E5F0;
    unk_D_86B0C4C8* var_v1 = D_86B0C4C8[arg0];
    s32 var_a1 = 1;

    while (var_v1->unk_0C != 0x98) {
        var_v0->unk_004.unk_024.z += 20.0f;
        if (var_v0->unk_004.unk_024.z <= 650.0f) {
            var_a1 = 0;
        }
        var_v0++;
        var_v1++;
    }
    return var_a1;
}

void func_86B008C4(void) {
    func_80007990(1);
    func_80006CB4(0xC);
    D_86B0E5D4->unk_04.unk_4C = 0;
    D_86B0E5D4->unk_04.unk_50 = 0;
}

void func_86B00904(void) {
    D_86B0E5D4->unk_04.unk_4C = 9;
    D_86B0E5D4->unk_04.unk_50 = 0;
    D_86B0E5F0->unk_004.unk_000.unk_01 &= ~1;
    D_86B0E5DC = 1;
}

void func_86B00944(s32 arg0) {
    unk_D_86B0C4C8* ptr1 = D_86B0C4C8[arg0];
    unk_D_86B0E5F0* ptr2 = &D_86B0E5F0[0];
    s16 sp88[] = {
        // D_86B0BD20
        0x1554,
        0x1554,
        0x1554,
        0x1554,
    };
    s16 sp80[] = {
        // D_86B0BD28
        0x18E2,
        0x11C6,
        0x1554,
        0x1554,
    };
    f32 sp70[] = { 1000.0f, 1000.0f, 2000.0f, 2000.0f }; // D_86B0BD30
    f32 sp60[] = { 1.0f, 1.0f, 100.0f, 50.0f };          // D_86B0BD40

    while (ptr1->unk_0C != 0x98) {
        if (func_86B01670(D_86B0E5D4->unk_00, &ptr2->unk_004, sp88[arg0], sp80[arg0], sp70[arg0], sp60[arg0]) != 0) {
            ptr2->unk_004.unk_000.unk_01 |= 1;
        } else {
            ptr2->unk_004.unk_000.unk_01 &= ~1;
        }
        ptr2++;
        ptr1++;
    }
}

void func_86B00AE4(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    func_8001F730();
}

void func_86B00B14(void) {
    D_86B0E5D4 = main_pool_alloc(sizeof(unk_D_86B0E5D4), 0);
    bzero(D_86B0E5D4, sizeof(unk_D_86B0E5D4));

    D_86B0E5D8 = main_pool_alloc(sizeof(unk_D_86B0E5D8), 0);
    bzero(D_86B0E5D8, sizeof(unk_D_86B0E5D8));

    D_86B0E5D4->unk_00 = D_86B0E5D0->unk_0C;

    D_86B0E5D4->unk_00->unk_24.near = 50.0f;
    D_86B0E5D4->unk_00->unk_24.far = 8400.0f;
    D_86B0E5D4->unk_00->unk_24.fovy = 30.0f;
    D_86B0E5D4->unk_00->unk_60.at.x = 50.0f;
    D_86B0E5D4->unk_00->unk_60.at.y = 50.0f;
    D_86B0E5D4->unk_00->unk_60.at.z = 50.0f;
    D_86B0E5D4->unk_00->unk_60.eye.x = 0.0f;
    D_86B0E5D4->unk_00->unk_60.eye.y = 0.0f;
    D_86B0E5D4->unk_00->unk_60.eye.z = 0.0f;
    D_86B0E5D4->unk_04.unk_4C = 8;
    D_86B0E5D4->unk_04.unk_50 = 0;
    D_86B0E5D4->unk_04.unk_48 = 0;
}

s32 func_86B00C34(void) {
    if (((gPlayer1Controller->buttonPressed & 0x1000) || (gPlayer1Controller->buttonPressed & 0x8000) ||
         (gPlayer1Controller->buttonPressed & 0x4000)) &&
        (D_86B0E5D4->unk_04.unk_48 == 0)) {
        if ((D_86B0E5D4->unk_04.unk_4C != 8) && (D_86B0E5D4->unk_04.unk_4C != 5)) {
            D_86B0E5D4->unk_04.unk_48 = 1;
            func_8004B9C4(0xA);
            D_86B0EBB0 = 0;
            D_86B0EBB4 = 2;
        }
    }

    if (D_86B0E5D4->unk_04.unk_48 == 1) {
        D_86B0EBB0 = func_8001046C(D_86B0EBB0, 0xFF, 0x1E, 0x1E);
        if (D_86B0EBB0 == 0xFF) {
            return 1;
        }
    }

    switch (D_86B0E5D4->unk_04.unk_4C) {
        case 5:
            if (D_86B0E5D4->unk_04.unk_48 == 1) {
                return 1;
            }

            if (D_86B0E5D4->unk_04.unk_44 == 4) {
                D_86B0E5D4->unk_04.unk_50 = 0;
                D_86B0EBB4 = 1;
                return 1;
            }

            D_86B0E5D4->unk_04.unk_44++;
            func_86B0054C(D_86B0E5D4->unk_04.unk_44);
            func_86B00470(D_86B0E5D4->unk_04.unk_44);
            D_86B0E5D4->unk_04.unk_4C = 6;
            D_86B0E5D4->unk_04.unk_50 = 0;
            break;

        case 6:
            if (D_86B0E5D4->unk_04.unk_50++ >= 4) {
                func_80007990(1);
                func_80006C6C(0x20);
                D_86B0E5D4->unk_04.unk_4C = 7;
                if ((D_86B0E5D4->unk_04.unk_44 == 0) || (D_86B0E5D4->unk_04.unk_44 == 1)) {
                    func_86B01AAC(&D_86B0E5D4->unk_04, D_86B0E5D4);
                }
            }
            break;

        case 7:
            if (D_86B0E5D4->unk_04.unk_44 == 4) {
                if (func_800174E4(&D_86B0E5F0[0].unk_004) != 0) {
                    func_86B00904();
                }
            } else {
                if (D_86B0E5D4->unk_04.unk_44 >= 2) {
                    if (func_86B00848(D_86B0E5D4->unk_04.unk_44) != 0) {
                        func_86B008C4();
                    }
                } else if (D_86B0E5D4->unk_04.unk_6C < D_86B0E5D4->unk_04.unk_30) {
                    func_86B008C4();
                }

                if ((D_86B0E5D4->unk_04.unk_44 == 0) || (D_86B0E5D4->unk_04.unk_44 == 1)) {
                    func_86B01AAC(&D_86B0E5D4->unk_04, D_86B0E5D4);
                }

                func_86B00944(D_86B0E5D4->unk_04.unk_44);
            }
            break;

        case 8:
            if (D_86B0E5D4->unk_04.unk_50++ >= 0xB) {
                D_86B0E5D4->unk_04.unk_44 = 0;
                func_86B0054C(D_86B0E5D4->unk_04.unk_44);
                D_86B0E5D4->unk_04.unk_4C = 6;
                D_86B0E5D4->unk_04.unk_50 = 0;
                func_86B003CC(D_86B0E5D4->unk_04.unk_44);
                func_8004B1CC(0x29);
            }
            break;

        case 9:
            if (D_86B0E5D4->unk_04.unk_50++ >= 3) {
                D_86B0E5D4->unk_04.unk_4C = 5;
                D_86B0E5D4->unk_04.unk_50 = 0;
            }
            break;

        default:
            if (D_86B0E5D4->unk_04.unk_44 != 4) {
                if (D_86B0E5D4->unk_04.unk_44 >= 2) {
                    func_86B00848(D_86B0E5D4->unk_04.unk_44);
                } else {
                    func_86B01AAC(&D_86B0E5D4->unk_04, D_86B0E5D4);
                }
            }

            if (D_86B0E5D4->unk_04.unk_50++ >= 0xE) {
                D_86B0E5D4->unk_04.unk_4C = 5;
                D_86B0E5D4->unk_04.unk_50 = 0;
            }
            break;
    }

    return 0;
}

void func_86B01004(void) {
}

void func_86B0100C(void) {
    func_800079C4();
    func_8000699C(&gDisplayListHead, 1);
    func_80015348();
    func_86B007EC();
    func_86B01C00(D_86B0E5E8);
    func_80015094(D_86B0E5D0);
    func_86B00794();
    func_86B02348();
    func_80007778();
}

void func_86B0107C(void) {
    s32 var_s1 = 1;
    s32 var_s0 = 0;

    while (var_s1 != 0) {
        func_86B00AE4();
        func_8140C5D0();

        if (func_86B00C34() != 0) {
            var_s1 = 0;
        }

        var_s0++;
        if (var_s0 == 0x50) {
            var_s0 = 0;
        }

        func_86B00688();
        func_86B0100C();
    }
}

void func_86B010FC(void) {
    func_86B0100C();
}

void func_86B0111C(void) {
    MemoryBlock* sp1C;

    sp1C = func_80002D10(main_pool_get_available(), 0);
    D_86B0E5D0 = process_geo_layout(sp1C, &D_86B0BBF8);

    func_80002D60(sp1C);
    func_8001BB20();
    func_8001987C();
    func_86B00B14();

    D_86B0EBB0 = 0;
    D_86B0E5DC = 0;
}

s32 func_86B01190(void) {
    main_pool_push_state('MINI');

    func_8001E94C(6, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    FRAGMENT_LOAD(fragment31);
    func_80004454((((u32)D_8D000000 & 0x0FF00000) >> 0x14) - 0x10, _5C7A70_ROM_START, _5C7A70_ROM_END);

    func_80028AFC(2);
    func_80027FA0(&D_86B0EBB8, 0);
    D_86B0E5E4 = ASSET_LOAD2(backgrounds, 1, 1);

    if (D_86B0EBB8 == 0x1F8) {
        D_86B0E5E8 = func_8000484C(D_86B0E5E4, 0x11);
    } else {
        D_86B0E5E8 = func_8000484C(D_86B0E5E4, 0);
    }

    func_8002D510();
    D_86B0E5E0 = func_8002D5AC(0x14);
    func_86B0111C();
    func_80007754();
    func_86B0107C();
    func_86B010FC();
    func_8000771C();
    func_8001E9CC();

    main_pool_pop_state('MINI');

    return D_86B0EBB4;
}
