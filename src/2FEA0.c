#include "2FEA0.h"
#include "src/29BA0.h"
#include "src/3FB0.h"
#include "src/memory.h"

void func_8002F2A0(void) {
    u32 var_s0;
    u32 sp60;
    void (*func)(void);
    s32 sp58;
    UNUSED s32 pad[2];

    main_pool_push_state('KDCM');

    sp60 = 0;
    var_s0 = 0;
    sp58 = 1;

    func = FRAGMENT_LOAD(fragment2);
    func();

    while (sp58 != 0) {
        if ((var_s0 == 0) || (var_s0 == 1) || (var_s0 == 4)) {
            sp60 = FRAGMENT_LOAD_AND_CALL(fragment39, var_s0, sp60);
        }

        if (sp60 != 0) {
            main_pool_push_state('mini');

            ASSET_LOAD(D_3000000, kids_club_game_ui, 0);
            FRAGMENT_LOAD(fragment34);

            switch (sp60) {
                case 1: // magikarp minigame
                    FRAGMENT_LOAD(fragment4);
                    var_s0 = FRAGMENT_LOAD_AND_CALL(fragment6, 0, 0);
                    break;
                case 2: // clefairy minigame
                    FRAGMENT_LOAD(fragment4);
                    var_s0 = FRAGMENT_LOAD_AND_CALL(fragment7, 0, 0);
                    break;
                case 3: // rattata minigame
                    FRAGMENT_LOAD(fragment4);
                    var_s0 = FRAGMENT_LOAD_AND_CALL(fragment8, 0, 0);
                    break;
                case 4: // unfinished jigglypuff minigame
                    FRAGMENT_LOAD(fragment4);
                    var_s0 = FRAGMENT_LOAD_AND_CALL(fragment9, 0, 0);
                    break;
                case 5: // drowzee minigame
                    FRAGMENT_LOAD(fragment5);
                    var_s0 = FRAGMENT_LOAD_AND_CALL(fragment10, 0, 0);
                    break;
                case 6: // pikachu minigame
                    FRAGMENT_LOAD(fragment5);
                    var_s0 = FRAGMENT_LOAD_AND_CALL(fragment11, 0, 0);
                    break;
                case 7: // "minigame 7 sample" model viewer. debug placeholder?
                    FRAGMENT_LOAD(fragment5);
                    var_s0 = FRAGMENT_LOAD_AND_CALL(fragment12, 0, 0);
                    break;
                case 8: // "minigame 8 sample" model viewer. debug placeholder?
                    FRAGMENT_LOAD(fragment5);
                    var_s0 = FRAGMENT_LOAD_AND_CALL(fragment13, 0, 0);
                    break;
                case 9: // sushi go round
                    FRAGMENT_LOAD(fragment3);
                    var_s0 = FRAGMENT_LOAD_AND_CALL(fragment14, 0, 0);
                    break;
                case 10: // doesnt seem to load... crashes the game
                    FRAGMENT_LOAD(fragment3);
                    var_s0 = FRAGMENT_LOAD_AND_CALL(fragment15, 0, 0);
                    break;
                case 11: // credits? why from the kids club?
                    FRAGMENT_LOAD(fragment5);
                    var_s0 = FRAGMENT_LOAD_AND_CALL(fragment16, 0, 0);
                    break;
                case 12: // also crashes.
                    FRAGMENT_LOAD(fragment3);
                    var_s0 = FRAGMENT_LOAD_AND_CALL(fragment17, 0, 0);
                    break;
                case 13: // ekans minigame
                    FRAGMENT_LOAD(fragment3);
                    var_s0 = FRAGMENT_LOAD_AND_CALL(fragment18, 0, 0);
                    break;
                case 14: // crashes...
                    FRAGMENT_LOAD(fragment3);
                    var_s0 = FRAGMENT_LOAD_AND_CALL(fragment19, 0, 0);
                    break;
                case 15: // 
                    FRAGMENT_LOAD(fragment3);
                    var_s0 = FRAGMENT_LOAD_AND_CALL(fragment20, 0, 0);
                    break;
                case 16: // sandshrew minigame
                    FRAGMENT_LOAD(fragment3);
                    var_s0 = FRAGMENT_LOAD_AND_CALL(fragment21, 0, 0);
                    break;
            }

            main_pool_pop_state('mini');

            switch (var_s0) {
                case 0:
                case 1:
                case 3:
                case 4:
                    break;

                case 2:
                    sp58 = 0;
                    break;
            }
        } else {
            sp58 = 0;
        }
    }

    main_pool_pop_state('KDCM');
}
