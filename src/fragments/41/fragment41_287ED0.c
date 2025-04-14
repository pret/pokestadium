#include "fragment41.h"
#include "src/19840.h"
#include "src/1C720.h"
#include "src/1CF30.h"
#include "src/20330.h"
#include "src/20470.h"
#include "src/225A0.h"
#include "src/22630.h"
#include "src/232C0.h"
#include "src/2E110.h"
#include "src/3FB0.h"
#include "src/49790.h"
#include "src/4BDC0.h"
#include "src/6A40.h"
#include "src/controller.h"
#include "src/memory.h"
#include "src/stage_loader.h"

typedef struct unk_D_82F14438 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ u16 unk_0C;
    /* 0x10 */ s8* unk_10;
} unk_D_82F14438; // size = 0x14

typedef struct unk_D_82F144B0 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
} unk_D_82F144B0; // size = 0xA

static unk_D_800AC870* D_82F14420;
s32 D_82F14424;
static s32 D_82F14428;
static s16 D_82F1442C;
static unk_D_82F13B78* D_82F14430;
static s32 pad_D_82F14434;
static unk_D_82F14438 D_82F14438;
static unk_D_82F14438* D_82F1444C;
unk_D_82F14450 D_82F14450[4];
static s16 D_82F144A8;
static s16 D_82F144AA;
static s32 pad_D_82F144AC;
static unk_D_82F144B0 D_82F144B0;
static s32 D_82F144BC;
static s32 D_82F144C0;
static char** D_82F144C4;
static char** D_82F144C8;
static char** D_82F144CC;

char** D_82F13B70 = NULL;
char** D_82F13B74 = NULL;
static unk_D_82F13B78 D_82F13B78[2] = {
    { 0x0140, 0x0168, NULL },
    { 0x0000, 0x0000, NULL },
};
static u16 D_82F13B88 = 0;

char* func_82F00020(s32 arg0) {
    return func_8002D7C0(NULL, 0, D_82F144C4, arg0 - 1);
}

char* func_82F00058(s32 arg0) {
    return func_8002D7C0(NULL, 0, D_82F144C8, arg0 - 1);
}

char* func_82F00090(s32 arg0) {
    return func_8002D7C0(NULL, 0, D_82F144CC, func_800219FC(arg0));
}

void func_82F000C8(s16 arg0) {
    unk_D_82F144B0* ptr = &D_82F144B0;

    switch (arg0) {
        case 0:
            ptr->unk_02 = 0;
            ptr->unk_04 = 0;
            ptr->unk_06 = 0x280;
            ptr->unk_08 = 0x1E0;
            break;

        case 1:
            ptr->unk_02 = 0;
            ptr->unk_04 = 0x154;
            ptr->unk_06 = 0x280;
            ptr->unk_08 = 0x8C;
            break;
    }
}

void func_82F00138(void) {
    D_82F144B0.unk_00 = -1;
    func_82F000C8(0);
}

void func_82F00164(void) {
    unk_D_82F144B0* ptr = &D_82F144B0;

    if ((ptr->unk_00 != 0) && (func_82F0FDCC() != 0)) {
        if (ptr->unk_00 > 0) {
            ptr->unk_00--;
        }

        gSPDisplayList(gDisplayListHead++, D_8006F4C0);
        gDPSetFillColor(gDisplayListHead++, 0x00010001);
        gDPFillRectangle(gDisplayListHead++, ptr->unk_02, ptr->unk_04, (ptr->unk_02 + ptr->unk_06) - 1,
                         (ptr->unk_04 + ptr->unk_08) - 1);
    }
}

void func_82F00284(void) {
    D_82F1444C = &D_82F14438;
    D_82F14438.unk_00 = 0;
    D_82F14438.unk_02 = 0;
    D_82F14438.unk_08 = 0;
    D_82F14438.unk_0A = 2;
    D_82F14438.unk_04 = 0;
    D_82F14438.unk_06 = 0;
    D_82F14438.unk_0C = 0;
    D_82F14438.unk_10 = NULL;
}

void func_82F002BC(s16 arg0, s16 arg1, s8* arg2, s32 arg3) {
    s8* ptr;

    D_82F1444C->unk_00 = 0;
    D_82F1444C->unk_02 = 0;

    ptr = arg2;
    if (ptr != NULL) {
        while (*ptr != '\x00') {
            D_82F1444C->unk_02++;
            ptr++;
        }
    }

    D_82F1444C->unk_08 = 0;
    D_82F1444C->unk_0A = 2;
    D_82F1444C->unk_04 = arg0;
    D_82F1444C->unk_06 = arg1;
    D_82F1444C->unk_0C = 0;

    if (arg3 != 0) {
        D_82F1444C->unk_0C |= 1;
    }

    D_82F1444C->unk_10 = arg2;
}

void func_82F0036C(void) {
    D_82F14430 = NULL;
}

void func_82F00378(unk_D_82F13B78* arg0, s32 arg1) {
    if (arg0 != D_82F14430) {
        D_82F1442C = 0;
    }

    D_82F14430 = arg0;

    if (NULL != arg0) {
        unk_D_82F13B78* ptr = &arg0[D_82F1442C];

        func_82F002BC(ptr->unk_00, ptr->unk_02, ptr->unk_04, arg1);
        D_82F1442C++;
    }
}

s32 func_82F003F8(unk_D_82F13B78* arg0) {
    unk_D_82F13B78* ptr = &arg0[D_82F1442C];
    s32 var_v1 = 0;

    if (ptr->unk_04 == NULL) {
        var_v1 = 1;
    }
    return var_v1;
}

void func_82F00424(void) {
    u8 tmp;

    if ((D_82F1444C->unk_10 != 0) && (D_82F1444C->unk_00 >= 0)) {
        if (gPlayer1Controller->buttonPressed & 0x8000) {
            D_82F1444C->unk_08 = 0;
            D_82F1444C->unk_0A = 1;
        } else {
            D_82F1444C->unk_08 -= 1;
        }

        if (D_82F1444C->unk_08 <= 0) {
            func_80048B90(0x01200001);
            D_82F1444C->unk_08 = D_82F1444C->unk_0A;

            D_82F1444C->unk_00++;

            tmp = D_82F1444C->unk_10[D_82F1444C->unk_00 - 1];
            if (tmp >= 0x80) {
                D_82F1444C->unk_00++;
            }

            if (D_82F1444C->unk_00 >= D_82F1444C->unk_02) {
                D_82F1444C->unk_00 = -1;
            }
        }
    }
}

s32 func_82F00524(void) {
    s32 var_v1 = 0;

    if (D_82F1444C->unk_10 != NULL) {
        if (D_82F1444C->unk_00 == -1) {
            var_v1 = 2;
        } else if (D_82F1444C->unk_00 >= 0) {
            var_v1 = 1;
        }
    }

    return var_v1;
}

void func_82F00568(void) {
    s32 i;
    s32 temp_t0;
    s8 sp38[0x100];

    if (D_82F1444C->unk_10 != NULL) {
        func_8001F3F4();
        func_8001EBE0(0x10, 0);

        if (D_82F1444C->unk_0C & 1) {
            s32 a = D_82F13B88;
            u8 arg = a & 0xF;

            arg = (arg * 0xFF) / 15;
            if (a & 0x10) {
                arg = 0xFF - arg;
            }
            func_8001F324(0xFF, 0xFF, 0xFF, arg);
        } else {
            func_8001F324(0xFF, 0xFF, 0xFF, 0xFF);
        }

        func_8001F3B4(0x1E);
        temp_t0 = func_8001F5B0(0, 0, D_82F1444C->unk_10) / 2;
        if (D_82F1444C->unk_00 == -1) {
            func_8001F1E8(D_82F1444C->unk_04 - temp_t0, D_82F1444C->unk_06, D_82F1444C->unk_10);
        } else {
            s8* p_sp38 = sp38;
            s8* other = D_82F1444C->unk_10;

            for (i = 0; i < D_82F1444C->unk_00; i++) {
                *p_sp38++ = *other++;
            }

            *p_sp38 = '\x00';
            func_8001F1E8(D_82F1444C->unk_04 - temp_t0, D_82F1444C->unk_06, &sp38);
        }
        func_8001F444();
        D_82F13B88++;
    }
}

void func_82F00704(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    func_8001F730();
}

void func_82F00734(void) {
    UNUSED s32 pad;
    unk_D_82F14450* ptr;
    unk_D_800AC910_040 sp40;
    u8 temp_s2 = Cont_GetControllerBits();
    s32 i;

    main_pool_push_state('info');

    for (i = 0, ptr = &D_82F14450[0]; i < 4; i++, ptr++) {
        func_80025040(i, &sp40);
        func_80023AF8(i);
        func_80021B5C(ptr->unk_08, sp40.unk_02);
        ptr->unk_06 = sp40.unk_00;
        ptr->unk_01 = func_80024F68(i);
        ptr->unk_00 = func_80024F00(i);
        ptr->unk_03 = func_80025370(i);
        ptr->unk_04 = func_8002539C(i);
        ptr->unk_05 = (temp_s2 & (1 << i)) != 0;
        ptr->unk_02 = func_80024F8C(i);
    }

    main_pool_pop_state('info');
}

void func_82F00838(void) {
    s32 i;
    unk_func_82F00838_sp30_00C sp50;
    unk_func_82F00838_sp30 sp30[2];

    for (i = 0; i < 2; i++) {
        func_82F0525C(i, &sp30[i]);
    }

    sp50 = sp30[0].unk_0C[sp30[0].unk_06];
    sp30[0].unk_0C[sp30[0].unk_06] = sp30[1].unk_0C[sp30[1].unk_06];
    sp30[1].unk_0C[sp30[1].unk_06] = sp50;

    func_82F051B8();
}

void func_82F00960(void) {
}

void func_82F00968(void) {
    func_8001BB20();
    func_8002D510();
    D_82F13B70 = func_8002D5AC(0x21);
    D_82F13B74 = func_8002D5AC(6);
    D_82F144C4 = func_8002D5AC(0x24);
    D_82F144C8 = func_8002D5AC(0x25);
    D_82F144CC = func_8002D5AC(0x26);
    D_82F13B78[0].unk_04 = func_8002D7C0(NULL, 0, D_82F13B70, 0);
    D_82F14428 = 0;
    func_82F0036C();
    D_82F14424 = 0;
    D_82F144A8 = 0;
    D_82F144BC = 0;
    func_82F00138();
    func_82F00284();
    func_82F13278();
    func_82F00734();
    func_82F09C6C();
    func_82F04FD4();
    func_82F0C190();
}

void func_82F00A58(void) {
    func_800079C4();
    func_82F00164();
    if (func_82F0FDCC() != 0) {
        func_82F13414();
    }
    func_82F00568();
    func_82F09E30();
    func_82F05110();
    func_82F0C320();
    func_82F00960();
    func_80007778();
}

void func_82F00AC8(s32 arg0) {
    D_82F14428 = arg0;

    switch (D_82F14428) {
        case 1:
            func_82F0036C();
            func_82F00378(D_82F13B78, 0);
            break;

        case 2:
            func_82F07958();
            func_82F002BC(0, 0, 0, 0);
            break;

        case 4:
            if (D_82F144A8 == 1) {
                if (D_82F144BC != 0) {
                    main_pool_pop_state('pmex');
                }
                main_pool_push_state('pmex');
                D_82F144BC = 1;
            }
            func_80023D60(func_82F07A54(D_82F144A8));
            func_82F01530(D_82F144A8, func_82F07A54(D_82F144A8));
            break;

        case 5:
            func_82F0A0A8(0);
            break;

        case 6:
            func_82F0A0A8(1);
            break;

        case 7:
            func_82F000C8(0);
            func_80006CB4(0xF);
            func_8004B9C4(0xF);
            break;
    }
}

void func_82F00C14(s16 arg0) {
    D_82F144AA = arg0;
    func_82F00AC8(3);
    func_82F0FDEC(D_82F144AA);
}

void func_82F00C50(void) {
    if (BTN_IS_PRESSED(gPlayer1Controller, BTN_A)) {
        if (func_82F003F8(D_82F13B78) == 0) {
            func_82F00378(D_82F13B78, 0);
        } else {
            func_82F00AC8(2);
        }
        func_80048B90(2);
        func_80048B90(4);
    } else if (BTN_IS_PRESSED(gPlayer1Controller, BTN_B)) {
        func_82F00AC8(7);
        func_80048B90(3);
    }
}

void func_82F00CE0(void) {
    func_82F000C8(1);
    if (func_82F07A74() == 0) {
        if (func_82F07A54(1) == -1) {
            func_82F00AC8(7);
        } else {
            func_82F00C14(1);
        }
    }
}

void func_82F00D3C(void) {
    func_82F000C8(0);

    switch (D_82F144AA) {
        case 1:
            if (func_82F13964(1) != 0) {
                func_82F00AC8(4);
            }
            break;

        case 19:
            if (func_82F13964(2) != 0) {
                func_82F00AC8(4);
            }
            break;

        case 4:
        case 8:
        case 11:
            if (func_82F13964(3) != 0) {
                func_82F00AC8(2);
            }
            break;

        case 20:
            if (func_82F13964(6) != 0) {
                func_82F00AC8(5);
            }
            break;

        case 21:
            if (func_82F13964(8) != 0) {
                func_82F00838();
                func_82F00C14(0xC);
            }
            break;

        case 12:
            if (func_82F13964(0xC) != 0) {
                if (D_82F144B0.unk_00 == -1) {
                    D_82F144B0.unk_00 = 5;
                }
            } else {
                D_82F144B0.unk_00 = -1;
            }

            if (func_82F13964(0xA) != 0) {
                func_82F00AC8(6);
            }
            break;
    }
}

void func_82F00E88(void) {
    unk_func_82F00838_sp30 sp20;

    if (func_82F018F8() == 0) {
        func_82F0525C(D_82F144A8, &sp20);

        if (sp20.unk_00 != 0) {
            if (D_82F144A8 == 0) {
                func_82F00C14(0x13);
            } else {
                func_82F00C14(0x14);
            }
            D_82F144A8 ^= 1;
        } else {
            if (D_82F144A8 == 0) {
                func_82F002BC(0, 0, NULL, 0);
                func_82F00C14(4);
                return;
            }
            func_82F00C14(8);
            D_82F144A8 = 0;
        }
    }
}

void func_82F00F3C(void) {
    func_82F000C8(1);

    if (func_82F0C16C() == 2) {
        if (D_82F144B0.unk_00 == -1) {
            D_82F144B0.unk_00 = 3;
        }
    } else {
        D_82F144B0.unk_00 = -1;
    }

    if (func_82F0C16C() == 0) {
        if (func_82F0C178() != 0) {
            func_82F00C14(0x15);
        } else {
            func_82F00C14(0xB);
        }
    }
}

void func_82F00FD8(void) {
    func_82F000C8(1);

    if (func_82F0C16C() == 2) {
        if (D_82F144B0.unk_00 == -1) {
            D_82F144B0.unk_00 = 3;
        }
    } else {
        D_82F144B0.unk_00 = -1;
    }

    if (func_82F0C16C() == 7) {
        D_82F144C0 = 0;
    } else {
        D_82F144C0 = 1;
    }

    if (func_82F0C16C() == 0) {
        if (func_82F0C184() != 0) {
            func_82F00AC8(2);
        } else {
            func_82F00AC8(7);
        }
    }
}

s32 func_82F0109C(void) {
    s32 sp1C = 1;

    switch (D_82F14428) {
        case 0:
            if (func_80007604() == 0) {
                func_82F00AC8(1);
            }
            break;

        case 1:
            func_82F00C50();
            break;

        case 2:
            func_82F00CE0();
            break;

        case 3:
            func_82F00D3C();
            break;

        case 4:
            func_82F00E88();
            break;

        case 5:
            func_82F00F3C();
            break;

        case 6:
            func_82F00FD8();
            break;

        case 7:
            if (func_80007604() == 1) {
                sp1C = 0;
            }
            break;
    }
    return sp1C;
}

void func_82F01180(void) {
    func_80006C6C(0x10);
    func_8004B1CC(0x10);
    func_8001F738(gPlayer1Controller);

    D_82F144C0 = 1;

    do {
        if (D_82F144C0 != 0) {
            func_82F00704();
        }
        func_82F00424();
        func_82F09D2C();
        func_82F0504C();
        func_82F0C254();
        func_82F132D0();
        func_82F00A58();
        D_82F14424++;
    } while (func_82F0109C() != 0);
}

s32 func_82F01234(s32 arg0, s32 arg1) {
    unk_func_80007444* sp24;

    main_pool_push_state('PMEX');

    func_80005E40(0x14000, 0);
    sp24 = func_80007444(1, 0, 2, 0, 2, 1);
    D_82F14420 = func_8001E94C(0x1E, 0);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    ASSET_LOAD(D_3000000, trade_select_ui, 0);

    FRAGMENT_LOAD(fragment31);

    func_8001987C();
    func_8001B058();
    func_82F00968();
    func_80007678(sp24);
    func_82F01180();
    func_800077B4(2);
    func_800076C0();
    func_8001E9CC();
    func_80005EAC();

    main_pool_pop_state('PMEX');

    return 0;
}
