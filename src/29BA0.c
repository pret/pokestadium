#include "29BA0.h"
#include "include/functions.h"
#include "src/20330.h"
#include "src/26820.h"
#include "src/373A0.h"
#include "src/30640.h"
#include "src/22630.h"
#include "src/3FB0.h"
#include "src/6A40.h"
#include "src/DDC0.h"
#include "src/2C1C0.h"
#include "src/26820.h"
#include "src/2FEA0.h"
#include "src/2E460.h"
#include "src/E1C0.h"
#include "src/19840.h"
#include "src/controller.h"
#include "src/dp_intro.h"
#include "src/gb_tower.h"
#include "src/memory.h"
#include "src/rsp.h"
#include "src/stage_loader.h"
#include "lib/ultralib/include/PR/os_internal_reg.h"

static s32 pad_D_80075660 = 0;
static s32 pad_D_80075664 = 0;
s32 gCurrentGameState = STATE_N64_LOGO_INTRO;
static s32 gLastGameState = STATE_N64_LOGO_INTRO;
static s32 pad_D_80075670 = 0;
static s16 D_80075674 = 0;
static s16 D_80075678 = 0;
static s16 D_8007567C = 0;

unk_D_800AE520 D_800AE520;
s32 pad_D_800AE534[2];
unk_D_800AE540 D_800AE540;
BinArchive* D_800AF738;

s32 Game_DoCopyProtection(s32 state) {
    u32 intr = osSetIntMask(1);

    // if the 16-bit value at ROM offset 0xE38 is not 0x828A, make the state an invalid one.
    if (!(HW_REG(PI_STATUS_REG, u32) & 3) && ((*(u32*)0xB0000E38 & 0xFFFF) != 0x828A)) {
        state = -0x10;
    }

    osSetIntMask(intr);

    return state;
}

s32 func_80029008(s32 arg0, u8* romStart, u8* romEnd, u32 arg3, u32 arg4) {
    s32 result;
    s32 (*func)(s32, s32);

    func = func_80004454(arg0, romStart, romEnd);

    result = func(arg3, arg4);

    main_pool_try_free(func);

    return result;
}

void func_80029048(s32 arg0, u8* arg1, u8* arg2, s32 arg3, s32 arg4) {
    D_800AE520.unk_00 = 1;
    D_800AE520.fragment_id = arg0;
    D_800AE520.rom_start = arg1;
    D_800AE520.rom_end = arg2;
    D_800AE520.arg0 = arg3;
    D_800AE520.arg1 = arg4;
}

unk_D_800AE540_0004* func_80029074(void) {
    return D_800AE540.unk_0004;
}

s16 func_80029080(void) {
    return D_80075674;
}

void func_8002908C(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 4)) {
        D_80075674 = arg0;
        D_80075678 = 1;
    }
}

void func_800290B4(void) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    func_8001F730();
}

s32 func_800290E4(s16 arg0) {
    s32 sp24;

    main_pool_push_state('Demo');

    FRAGMENT_LOAD(fragment34);
    FRAGMENT_LOAD(fragment2);
    FRAGMENT_LOAD(fragment3);

    D_800AE540.unk_0000 = arg0;

    sp24 = FRAGMENT_LOAD_AND_CALL(fragment17, arg0, 0);

    main_pool_pop_state('Demo');

    return sp24;
}

void func_800291E0(void) {
    main_pool_push_state('demo');

    FRAGMENT_LOAD(fragment34);
    FRAGMENT_LOAD(fragment2);
    FRAGMENT_LOAD(fragment3);

    if (D_800AE540.unk_11F2 != 0) {
        FRAGMENT_LOAD_AND_CALL(fragment16, 0, 0);
    } else {
        FRAGMENT_LOAD_AND_CALL(fragment16, 0, 1);
    }

    main_pool_pop_state('demo');
}

void func_80029310(void) {
    FRAGMENT_LOAD_AND_CALL(fragment35, 0, 0);

    main_pool_push_state('TITL');

    func_80005E40(0x10000, 0);
    func_80007678(func_80007444(0, 1, 3, 1, 2, 1));

    if (func_800290E4(0x12) == 2) {
        func_80006CF8(1);
        func_800077B4(2);
    }

    gCurrentGameState = STATE_TITLE_SCREEN;
}

void func_800293CC(void) {
    gCurrentGameState = FRAGMENT_LOAD_AND_CALL(fragment36, 0, &D_8007567C);

    if (gCurrentGameState == STATE_TITLE_SCREEN) {
        main_pool_push_state('DEMO');

        if (D_800AE540.unk_0000 == 0x10) {
            FRAGMENT_LOAD(fragment34);
            FRAGMENT_LOAD_AND_CALL(fragment62, 0, &D_800AE540);
        } else {
            ASSET_LOAD(D_3000000, _675FA0, 0);
            FRAGMENT_LOAD(fragment2);
            FRAGMENT_LOAD(fragment34);

            switch (D_800AE540.unk_0003) {
                case 3:
                    FRAGMENT_LOAD(fragment4);
                    FRAGMENT_LOAD_AND_CALL(fragment8, 1, 0);
                    break;

                case 9:
                    FRAGMENT_LOAD(fragment3);
                    FRAGMENT_LOAD_AND_CALL(fragment14, 1, 0);
                    break;

                case 13:
                    FRAGMENT_LOAD(fragment3);
                    FRAGMENT_LOAD_AND_CALL(fragment18, 1, 0);
                    break;
            }
        }

        main_pool_pop_state('DEMO');
        return;
    }

    D_800AE540.unk_0002 = 0;
    D_800AE540.unk_11F6 = 0;
    D_80075674 = -1;
}

void func_800296AC(void) {
    func_8000D2B4(1);
    func_80001BD4(2);
    LeoBootGame(D_800AA688);
}

void func_800296E0(void) {
    s32 temp_v0;
    unk_func_80007444* temp_s0;

    main_pool_push_state('DBUG');

    func_80005E40(0x10000, 0);
    temp_s0 = func_80007444(1, 1, 2, 0, 2, 1);

    FRAGMENT_LOAD(fragment34);
    func_80007678(temp_s0);
    FRAGMENT_LOAD_AND_CALL2(fragment67, 1, 0);

    while ((gCurrentGameState == STATE_STUBBED_DEBUG) && (D_800AE520.unk_00 != 0)) {
        D_800AE520.unk_00 = 0;
        gCurrentGameState = func_80029008(D_800AE520.fragment_id, D_800AE520.rom_start, D_800AE520.rom_end,
                                          D_800AE520.arg0, D_800AE520.arg1);
    }

    func_800076C0();
    func_80005EAC();

    main_pool_pop_state('DBUG');
}

void func_80029828(void) {
    gCurrentGameState = FRAGMENT_LOAD_AND_CALL(fragment37, 0, 0);
    D_80075674 = -1;
}

void func_80029884(void) {
    gCurrentGameState = FRAGMENT_LOAD_AND_CALL(fragment38, 0, 0);
}

void func_800298D4(void) {
    gCurrentGameState = FRAGMENT_LOAD_AND_CALL(fragment56, 0, 0);
}

void func_80029924(void) {
    s32 from_title_screen = gLastGameState == STATE_TITLE_SCREEN;

    gCurrentGameState = FRAGMENT_LOAD_AND_CALL(fragment57, 0, from_title_screen);
}

s16 func_80029984(s16 arg0) {
    main_pool_push_state('STAD');

    func_80005E40(0x18000, 0);
    func_80007678(func_80007444(1, 1, 2, 0, 2, 1));

    while ((arg0 > 0) && (arg0 < 5)) {
        switch (arg0) {
            case 1:
                if (FRAGMENT_LOAD_AND_CALL(fragment59, 0, 0) != 0) {
                    arg0 = 2;
                } else {
                    arg0 = 0;
                }
                break;

            case 2:
                if (FRAGMENT_LOAD_AND_CALL(fragment60, 0, 0) != 0) {
                    arg0 = 3;
                } else {
                    arg0 = 1;
                }
                break;

            case 3:
                if (FRAGMENT_LOAD_AND_CALL(fragment54, 0, 0) != 0) {
                    arg0 = 4;
                } else {
                    arg0 = 1;
                }
                break;

            case 4:
                if (FRAGMENT_LOAD_AND_CALL(fragment61, 0, 0) != 0) {
                    arg0 = 5;
                } else {
                    arg0 = 3;
                }
                break;
        }
    }

    func_800076C0();
    func_80005EAC();

    main_pool_pop_state('STAD');

    return arg0;
}

void func_80029BC0(void) {
    s16 sp4E = 1;

    while ((sp4E > 0) && (sp4E < 5)) {
        if (D_800AE540.unk_11F5 & 1) {
            sp4E = 5;
        } else {
            sp4E = func_80029984(sp4E);
        }

        if (sp4E == 5) {
            D_800AE540.unk_11F6 = 0;
            FRAGMENT_LOAD_AND_CALL(fragment63, 1, 0);

            while (!(D_800AE540.unk_11F6 & 1)) {
                FRAGMENT_LOAD_AND_CALL(fragment64, 0, 0);

                main_pool_push_state('STAD');

                FRAGMENT_LOAD(fragment34);
                FRAGMENT_LOAD_AND_CALL(fragment62, 0, &D_800AE540);

                main_pool_pop_state('STAD');

                FRAGMENT_LOAD_AND_CALL(fragment63, 2, 0);
            }

            if (D_800AE540.unk_11F6 & 0x20) {
                sp4E = 4;
            }

            if (D_800AE540.unk_11F6 & 0x800) {
                sp4E = 4;
            }

            if (D_800AE540.unk_11F6 & 2) {
                func_800290E4(0x11);
            }

            if (D_800AE540.unk_11F6 & 0x1000) {
                FRAGMENT_LOAD_AND_CALL(fragment66, 0, 0);
            }

            if (D_800AE540.unk_11F6 & 8) {
                func_800290E4(0x16);
            }

            if (D_800AE540.unk_11F6 & 0x10) {
                func_800290E4(0x17);
            }
        }
    }

    if (D_800AE540.unk_11F6 & 0x40) {
        gCurrentGameState = STATE_TITLE_SCREEN;
    } else {
        gCurrentGameState = STATE_AREA_SELECT;
    }
}

s32 func_80029E78(s16 arg0) {
    main_pool_push_state('FREE');

    func_80005E40(0x18000, 0);
    func_80007678(func_80007444(1, 1, 2, 0, 2, 1));

    while ((arg0 > 0) && (arg0 < 4)) {
        switch (arg0) {
            case 1:
                if (FRAGMENT_LOAD_AND_CALL(fragment58, 0, 0) != 0) {
                    arg0 = 2;
                } else {
                    arg0 = 0;
                }
                break;

            case 2:
                if (FRAGMENT_LOAD_AND_CALL(fragment54, 0, 0) != 0) {
                    arg0 = 3;
                } else {
                    arg0 = 1;
                }
                break;

            case 3:
                if (FRAGMENT_LOAD_AND_CALL(fragment61, 0, 1) != 0) {
                    arg0 = 4;
                } else {
                    arg0 = 2;
                }
                break;
        }
    }

    func_800076C0();
    func_80005EAC();
    main_pool_pop_state('FREE');

    return arg0;
}

void func_8002A06C(void) {
    s16 sp4E = 1;

    while ((sp4E > 0) && (sp4E < 4)) {
        sp4E = func_80029E78(sp4E);

        switch (sp4E) {
            case 4:
                D_800AE540.unk_11F6 = 0;
                FRAGMENT_LOAD_AND_CALL(fragment63, 0, 0);

                while (!(D_800AE540.unk_11F6 & 1)) {
                    FRAGMENT_LOAD_AND_CALL(fragment64, 0, 0);

                    main_pool_push_state('FREE');

                    FRAGMENT_LOAD(fragment34);
                    FRAGMENT_LOAD_AND_CALL(fragment62, 0, &D_800AE540);

                    main_pool_pop_state('FREE');

                    FRAGMENT_LOAD_AND_CALL(fragment63, 2, 0);
                }

                if (D_800AE540.unk_11F6 & 0x20) {
                    sp4E = 3;
                }

                if (D_800AE540.unk_11F6 & 0x80) {
                    sp4E = 1;
                }
                break;
        }
    }

    gCurrentGameState = STATE_AREA_SELECT;
}

s16 func_8002A260(s16 arg0) {
    main_pool_push_state('STAD');

    func_80005E40(0x18000, 0);
    func_80007678(func_80007444(1, 1, 2, 0, 2, 1));

    while ((arg0 > 0) && (arg0 < 3)) {
        switch (arg0) {
            case 1:
                if (FRAGMENT_LOAD_AND_CALL(fragment54, 0, 0) != 0) {
                    arg0 = 2;
                } else {
                    arg0 = 0;
                }
                break;

            case 2:
                if (FRAGMENT_LOAD_AND_CALL(fragment61, 0, 0) != 0) {
                    arg0 = 3;
                } else {
                    arg0 = 1;
                }
                break;
        }
    }

    func_800076C0();
    func_80005EAC();

    main_pool_pop_state('STAD');
    return arg0;
}

void func_8002A400(void) {
    s16 sp4E = 1;

    func_800290E4(0x18);
    func_8002B5EC(8, 8, 0);
    func_8002B840(0, func_8002B700(0, 0, "1P", func_8002311C(1)));
    func_8002B840(1, func_8002B700(-1, 0, "COM", func_8002311C(3)));

    while ((sp4E > 0) && (sp4E < 3)) {
        sp4E = func_8002A260(sp4E);

        switch (sp4E) {
            case 3:
                D_800AE540.unk_11F6 = 0;
                FRAGMENT_LOAD_AND_CALL(fragment63, 0, 0);

                while (!(D_800AE540.unk_11F6 & 1)) {
                    FRAGMENT_LOAD_AND_CALL(fragment64, 0, 0);

                    main_pool_push_state('STAD');

                    FRAGMENT_LOAD(fragment34);
                    FRAGMENT_LOAD_AND_CALL(fragment62, 0, &D_800AE540);

                    main_pool_pop_state('STAD');

                    FRAGMENT_LOAD_AND_CALL(fragment63, 2, 0);
                }

                if (D_800AE540.unk_11F6 & 0x20) {
                    sp4E = 2;
                }

                if (D_800AE540.unk_11F6 & 4) {
                    func_800291E0();
                    gCurrentGameState = STATE_N64_LOGO_INTRO;
                    return;
                }
                break;
        }
    }

    gCurrentGameState = STATE_AREA_SELECT;
}

void func_8002A670(void) {
    func_8002F2A0();
    gCurrentGameState = STATE_AREA_SELECT;
}

void func_8002A698(void) {
    func_8002FA40();
    gCurrentGameState = STATE_MENU_SELECT;
}

void func_8002A6C0(void) {
    if (FRAGMENT_LOAD_AND_CALL(fragment50, 0, 0) == 1) {
        func_800290E4(0x1A);
    }
    gCurrentGameState = STATE_AREA_SELECT;
}

void func_8002A728(void) {
    s32 sp34;
    UnkInputStruct8000D738 sp2C;
    unk_func_8002A728 sp24;

    main_pool_push_state('EMU0');

    if ((FRAGMENT_LOAD_AND_CALL(fragment33, 0, 0) == 0) && (D_80075674 >= 0) && (D_80075674 < 4)) {
        func_8000D278(4);
        func_8000D2B4(1);
        func_80001BD4(2);
        func_8000D358();

        sp2C.unk_04 = main_pool_alloc(0x4B00, 0);

        FRAGMENT_LOAD_AND_CALL(fragment53, D_80075674, &sp2C);
        func_8000D738(&sp2C);

        sp34 = func_8000D8A8();

        func_8000D8DC(&sp2C);
        func_80001BD4(2);
        func_8000D380();

        if (sp34 != 0) {
            func_8002B274(D_80075674, sp34);
        }

        func_80024040(D_80075674);
        func_80028AFC(2);
        func_80027F24(&sp24);

        sp24.unk_04 = sp2C.unk_00;

        func_80027F40(&sp24);
        func_80026684(0x14, 0);
        func_800284B4(2);
    }

    main_pool_pop_state('EMU0');

    gCurrentGameState = STATE_AREA_SELECT;
}

s16 func_8002A8A0(s16 arg0, s16 arg1) {
    main_pool_push_state('STAD');

    func_80005E40(0x18000, 0);
    func_80007678(func_80007444(1, 1, 2, 0, 2, 1));

    while ((arg0 > 0) && (arg0 < 4)) {
        switch (arg0) {
            case 1:
                if (FRAGMENT_LOAD_AND_CALL(fragment54, 0, 0) != 0) {
                    arg0 = 2;
                } else {
                    arg0 = 0;
                }
                break;

            case 2:
                if (FRAGMENT_LOAD_AND_CALL(fragment65, arg1, 0) != 0) {
                    arg0 = 3;
                } else {
                    arg0 = 1;
                }
                break;

            case 3:
                if (FRAGMENT_LOAD_AND_CALL(fragment61, 0, 0) != 0) {
                    arg0 = 4;
                } else {
                    arg0 = 2;
                }
                break;
        }

        arg1 = 0;
    }

    func_800076C0();
    func_80005EAC();

    main_pool_pop_state('STAD');

    return arg0;
}

void func_8002AAA8(void) {
    s16 sp4E = 1;
    s16 sp4C = 0;

    if (!(D_800AE540.unk_11F5 & 1)) {
        func_8002B5EC(7, 7, 0);
        func_8002B840(0, func_8002B700(0, 0, "1P", func_8002311C(1)));
        func_8002B840(1, func_8002B700(-1, 0, "COM", func_8002311C(3)));
    }

    while ((sp4E > 0) && (sp4E < 4)) {
        if (D_800AE540.unk_11F5 & 1) {
            sp4E = 4;
        } else {
            sp4E = func_8002A8A0(sp4E, sp4C);
        }

        if (sp4E == 4) {
            sp4C = 0;
            D_800AE540.unk_11F6 = 0;

            FRAGMENT_LOAD_AND_CALL(fragment63, 1, 0);

            while (!(D_800AE540.unk_11F6 & 1)) {
                FRAGMENT_LOAD_AND_CALL(fragment64, 0, 0);

                main_pool_push_state('STAD');

                FRAGMENT_LOAD(fragment34);
                FRAGMENT_LOAD_AND_CALL(fragment62, 0, &D_800AE540);

                main_pool_pop_state('STAD');

                FRAGMENT_LOAD_AND_CALL(fragment63, 2, 0);
            }

            if (D_800AE540.unk_11F6 & 0x200) {
                FRAGMENT_LOAD_AND_CALL(fragment40, 0, 0);
                func_800290E4(0x11);
                func_800290E4(0x15);
            }

            if (D_800AE540.unk_11F6 & 0x20) {
                sp4E = 3;
            }

            if (D_800AE540.unk_11F6 & 0x800) {
                sp4E = 3;
            }

            if (D_800AE540.unk_11F6 & 0x400) {
                sp4C = 1;
            }

            if (D_800AE540.unk_11F6 & 0x100) {
                sp4E = 2;
            }
        }
    }

    if (D_800AE540.unk_11F6 & 0x40) {
        gCurrentGameState = STATE_TITLE_SCREEN;
    } else {
        gCurrentGameState = STATE_AREA_SELECT;
    }
}

void func_8002ADE8(s32 arg0) {
    main_pool_push_state('QUIK');
    func_8002C394(arg0);

    FRAGMENT_LOAD_AND_CALL(fragment63, 0, 0);
    FRAGMENT_LOAD_AND_CALL(fragment64, 0, 0);

    main_pool_push_state('FIGT');

    FRAGMENT_LOAD(fragment34);
    FRAGMENT_LOAD_AND_CALL(fragment62, 0, &D_800AE540);

    main_pool_pop_state('FIGT');

    FRAGMENT_LOAD_AND_CALL(fragment63, 2, 0);

    main_pool_pop_state('QUIK');

    gCurrentGameState = STATE_MENU_SELECT;
}

void func_8002AF38(void) {
    main_pool_push_state('EVNT');

    FRAGMENT_LOAD_AND_CALL(fragment63, 0, 0);
    FRAGMENT_LOAD_AND_CALL(fragment64, 0, 0);

    main_pool_push_state('FIGT');

    FRAGMENT_LOAD(fragment34);
    FRAGMENT_LOAD_AND_CALL(fragment62, 0, &D_800AE540);

    main_pool_pop_state('FIGT');

    FRAGMENT_LOAD_AND_CALL(fragment63, 2, 0);

    main_pool_pop_state('EVNT');

    gCurrentGameState = STATE_EVENT_BATTLE;
}

void func_8002B07C(void) {
    void (*frag_43_entry)(void);

    FRAGMENT_LOAD_AND_CALL(fragment35, 0, 0);

    main_pool_push_state('DOSE');

    frag_43_entry = FRAGMENT_LOAD(fragment43);
    frag_43_entry();

    FRAGMENT_LOAD(fragment34);
    FRAGMENT_LOAD_AND_CALL(fragment75, 0, 0);

    gCurrentGameState = STATE_TITLE_SCREEN;

    main_pool_pop_state('DOSE');
}

void func_8002B180(void) {
    main_pool_push_state('STAD');

    func_8002BC64(1, 0, 2, 0);
    func_800367A0(0xA0, 0xA, 0);

    FRAGMENT_LOAD(fragment34);
    FRAGMENT_LOAD_AND_CALL(fragment62, 0, &D_800AE540);

    main_pool_pop_state('STAD');

    gCurrentGameState = STATE_TITLE_SCREEN;
}

void func_8002B244(void) {
}

void func_8002B24C(void) {
    func_8002F2A0();
    gCurrentGameState = STATE_TITLE_SCREEN;
}

void func_8002B274(s32 arg0, s32 arg1) {
    osViBlack(1);
    func_8000A924();
    func_8000D338();
    func_8002B310();
    func_80001AD4(1);
    func_80001C64();
    func_80001BD4(0xA);

    main_pool_pop_state('GAME');

    FRAGMENT_LOAD_AND_CALL(fragment32, arg0, arg1);
}

void func_8002B310(void) {
    func_80000DF4();
}

void Game_Thread(UNUSED void* arg) {
    s32 state;

    __osSetFpcCsr(0x01000C01U);

    Cont_SetupControllers();
    func_800196DC();

    main_pool_push_state('GAME');

    D_800AE540.unk_11F2 = 0;

    // is this game connected to a Sticker Station?
    if (func_8000B4C4() != 0) {
        gCurrentGameState = STATE_FAST_N64_LOGO;
    }

    while (1) {
        state = Game_DoCopyProtection(gCurrentGameState);

        switch (state) {
            case STATE_N64_LOGO_INTRO:
                func_80029310();
                break;
            case STATE_TITLE_SCREEN:
                func_800293CC();
                break;
            case STATE_N64DD_BOOT_UNUSED:
                func_800296AC();
                break;
            case STATE_AREA_SELECT:
                func_80029828();
                break;
            case STATE_GALLERY:
                func_8002A698();
                break;
            case STATE_EVENT_BATTLE:
                func_80029884();
                break;
            case STATE_OPTIONS:
                func_800298D4();
                break;
            case STATE_MENU_SELECT:
                func_80029924();
                break;
            case STATE_STADIUM_MENU:
                func_80029BC0();
                break;
            case STATE_FREE_BATTLE:
                func_8002A06C();
                break;
            case STATE_VS_MEWTWO:
                func_8002A400();
                break;
            case STATE_KIDS_CLUB:
                func_8002A670();
                break;
            case STATE_VICTORY_PALACE:
                func_8002A6C0();
                break;
            case STATE_POKEMON_LAB:
                func_8002EF44();
                break;
            case STATE_GB_TOWER:
                func_8002A728();
                break;
            case STATE_GYM_LEADER_CASTLE:
                func_8002AAA8();
                break;
            case STATE_BATTLE_NOW_1P:
                func_8002ADE8(1);
                break;
            case STATE_BATTLE_NOW_2P:
                func_8002ADE8(2);
                break;
            case STATE_BATTLE_FROM_EVENT:
                func_8002AF38();
                break;
            case STATE_STUBBED_DEBUG:
                func_800296E0();
                break;
            case STATE_FAST_BATTLE:
                func_8002B180();
                break;
            case STATE_KIDS_CLUB_TITLE:
                func_8002B24C();
                break;
            case STATE_FAST_N64_LOGO:
                func_8002B07C();
                break;
            // same as state 1: N64 Logo + Intro.
            default:
                func_80029310();
                break;
        }

        gLastGameState = state;
    }
}
