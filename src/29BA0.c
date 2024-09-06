#include "global.h"
#include "memory.h"

s32 Game_DoCopyProtection(s32 state) {
    u32 intr = osSetIntMask(1);

    // if the 16-bit value at ROM offset 0xE38 is not 0x828A, make the state an invalid one.
    if (!(HW_REG(PI_STATUS_REG, u32) & 3) && ((*(u32*)0xB0000E38 & 0xFFFF) != 0x828A)) {
        state = -0x10;
    }
    osSetIntMask(intr);
    return state;
}

s32 func_80029008(s32 arg0, s32 romStart, s32 romEnd, s32 arg3, s32 arg4) {
    s32 result;
    s32 (*func)(s32, s32);

    func = func_80004454(arg0, romStart, romEnd);
    result = func(arg3, arg4);
    main_pool_try_free(func);
    return result;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_80029048.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_80029074.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_80029080.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_8002908C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_800290B4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_800290E4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_800291E0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_80029310.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_800293CC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_800296AC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_800296E0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_80029828.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_80029884.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_800298D4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_80029924.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_80029984.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_80029BC0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_80029E78.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_8002A06C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_8002A260.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_8002A400.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_8002A670.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_8002A698.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_8002A6C0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_8002A728.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_8002A8A0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_8002AAA8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_8002ADE8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_8002AF38.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_8002B07C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_8002B180.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_8002B244.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_8002B24C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_8002B274.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/29BA0/func_8002B310.s")

void Game_Thread(void *arg) {
    s32 state;

    __osSetFpcCsr(0x01000C01U);
    Cont_SetupControllers();
    func_800196DC();
    main_pool_push_state('GAME');
    D_800AF732 = 0;
    // is this game connected to a Sticker Station?
    if (func_8000B4C4() != 0) {
        gCurrentGameState = STATE_FAST_N64_LOGO;
    }
    while(1) {
        state = Game_DoCopyProtection(gCurrentGameState);
        switch (state) {
            case STATE_N64_LOGO_INTRO:    func_80029310();  break;
            case STATE_TITLE_SCREEN:      func_800293CC();  break;
            case STATE_N64DD_BOOT_UNUSED: func_800296AC();  break;
            case STATE_AREA_SELECT:       func_80029828();  break;
            case STATE_GALLERY:           func_8002A698();  break;
            case STATE_EVENT_BATTLE:      func_80029884();  break;
            case STATE_OPTIONS:           func_800298D4();  break;
            case STATE_MENU_SELECT:       func_80029924();  break;
            case STATE_STADIUM_MENU:      func_80029BC0();  break;
            case STATE_FREE_BATTLE:       func_8002A06C();  break;
            case STATE_VS_MEWTWO:         func_8002A400();  break;
            case STATE_KIDS_CLUB:         func_8002A670();  break;
            case STATE_VICTORY_PALACE:    func_8002A6C0();  break;
            case STATE_POKEMON_LAB:       func_8002EF44();  break;
            case STATE_GB_TOWER:          func_8002A728();  break;
            case STATE_GYM_LEADER_CASTLE: func_8002AAA8();  break;
            case STATE_BATTLE_NOW_1P:     func_8002ADE8(1); break;
            case STATE_BATTLE_NOW_2P:     func_8002ADE8(2); break;
            case STATE_BATTLE_FROM_EVENT: func_8002AF38();  break;
            case STATE_STUBBED_DEBUG:     func_800296E0();  break;
            case STATE_FAST_BATTLE:       func_8002B180();  break;
            case STATE_KIDS_CLUB_TITLE:   func_8002B24C();  break;
            case STATE_FAST_N64_LOGO:     func_8002B07C();  break;
            // same as state 1: N64 Logo + Intro.
            default:                      func_80029310();  break;
        }
        gLastGameState = state;
    }
}
