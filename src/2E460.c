#include "2E460.h"
#include "src/20330.h"
#include "src/22630.h"
#include "src/26820.h"
#include "src/29BA0.h"
#include "src/49790.h"
#include "src/6A40.h"
#include "src/controller.h"
#include "src/memory.h"
#include "src/stage_loader.h"

#pragma GLOBAL_ASM("asm/us/nonmatchings/2E460/func_8002D860.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2E460/func_8002D8C8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2E460/func_8002DCB8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2E460/func_8002DD64.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2E460/func_8002DD98.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2E460/func_8002DE44.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2E460/func_8002DE78.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2E460/func_8002DF68.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2E460/func_8002E0F4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2E460/func_8002E128.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2E460/func_8002E244.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2E460/func_8002E5A0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2E460/func_8002E8E4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2E460/func_8002EBD8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2E460/func_8002EC08.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2E460/func_8002EC1C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2E460/func_8002ECDC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2E460/func_8002ED08.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2E460/func_8002ED40.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2E460/func_8002ED78.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2E460/func_8002EDEC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2E460/func_8002EE1C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2E460/func_8002EE78.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2E460/func_8002EEA8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2E460/func_8002EEEC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2E460/func_8002EF18.s")

void func_8002EF44(void) {
    s32 game_state;
    s32 var_s4;

    FRAGMENT_LOAD_AND_CALL(fragment33, 1, 0);

    if (func_80029080() == -1) {
        gCurrentGameState = STATE_AREA_SELECT;
        return;
    }

    var_s4 = 0;
    game_state = STATE_POKEMON_LAB;

    do {
        if (game_state == STATE_POKEMON_LAB) {
            main_pool_push_state('PLAB');

            if (func_80029080() != -1) {
                func_80028AFC(3);
                func_80023D60(func_80029080());
            }

            func_80005E40(0x16000, 0);
            func_80007678(func_80007444(1, 1, 2, 0, 2, 1));

            FRAGMENT_LOAD_AND_CALL2(fragment22, var_s4, 0);

            while ((game_state == STATE_POKEMON_LAB) && (D_800AE520.unk_00 != 0)) {
                D_800AE520.unk_00 = 0;
                game_state = func_80029008(D_800AE520.fragment_id, D_800AE520.rom_start, D_800AE520.rom_end,
                                           D_800AE520.arg0, D_800AE520.arg1);
            }

            func_800076C0();
            func_80005EAC();

            main_pool_pop_state('PLAB');
        } else {
            switch (game_state) {
                case 0x10000:
                    FRAGMENT_LOAD_AND_CALL(fragment41, 0, 0);
                    var_s4 = 2;
                    game_state = STATE_POKEMON_LAB;
                    break;

                case 0x10001:
                    FRAGMENT_LOAD_AND_CALL(fragment33, 0, 0);
                    var_s4 = 1;
                    game_state = STATE_POKEMON_LAB;
                    break;
            }
        }
    } while (game_state != STATE_AREA_SELECT);

    gCurrentGameState = STATE_AREA_SELECT;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/2E460/func_8002F1C0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2E460/func_8002F264.s")
