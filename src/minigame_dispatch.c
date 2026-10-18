#include "minigame_dispatch.h"
#include "src/game_state.h"
#include "src/jpeg_stream.h"
#include "src/memory.h"

s16 D_80075E40[160] = {
    0, 105, 150, 220, 70, 120, 188, 75, 110, 160,
    60, 80, 120, 60, 70, 100, 70, 130, 170, 80,
    110, 65, 160, 120, 180, 85, 105, 100, 130, 80,
    100, 160, 100, 120, 160, 100, 140, 80, 130, 90,
    120, 110, 160, 90, 100, 160, 80, 125, 130, 150,
    60, 120, 70, 105, 105, 170, 90, 120, 100, 190,
    100, 140, 170, 90, 150, 150, 80, 120, 160, 80,
    165, 170, 140, 160, 120, 140, 160, 110, 170, 140,
    160, 80, 110, 100, 140, 150, 110, 90, 140, 220,
    85, 170, 150, 180, 150, 250, 120, 160, 102, 160,
    100, 130, 110, 160, 60, 100, 150, 140, 150, 110,
    140, 130, 200, 150, 120, 220, 80, 140, 80, 140,
    90, 110, 140, 160, 140, 130, 130, 150, 160, 90,
    270, 250, 100, 65, 120, 120, 110, 120, 70, 120,
    90, 140, 200, 180, 170, 180, 180, 100, 200, 180,
    180, 85, 100, 40, 0, 0, 0, 0, 0, 0,
};

void MiniGame_Dispatch(void) {
    u32 var_s0;
    u32 sp60;
    void (*func)(void);
    s32 sp58;
    UNUSED s32 pad[2];

    main_pool_push_state('KDCM');

    sp60 = 0;
    var_s0 = 0;
    sp58 = 1;

    func = FRAGMENT_LOAD(FRAGMENT_WIDGET_TOOLKIT);
    func();

    while (sp58 != 0) {
        if ((var_s0 == 0) || (var_s0 == 1) || (var_s0 == 4)) {
            sp60 = FRAGMENT_LOAD_AND_CALL(FRAGMENT_MINIGAME_SELECT, var_s0, sp60);
        }

        if (sp60 != 0) {
            main_pool_push_state('mini');

            ASSET_LOAD(D_3000000, kids_club_game_ui, 0);
            FRAGMENT_LOAD(FRAGMENT_PARTICLE_MATH);

            switch (sp60) {
                case 1: // magikarp minigame
                    FRAGMENT_LOAD(FRAGMENT_MINIGAME_SHARED_GRAPHICS);
                    var_s0 = FRAGMENT_LOAD_AND_CALL(FRAGMENT_MAGIKARP_GAME, 0, 0);
                    break;
                case 2: // clefairy minigame
                    FRAGMENT_LOAD(FRAGMENT_MINIGAME_SHARED_GRAPHICS);
                    var_s0 = FRAGMENT_LOAD_AND_CALL(FRAGMENT_CLEFAIRY_GAME, 0, 0);
                    break;
                case 3: // rattata minigame
                    FRAGMENT_LOAD(FRAGMENT_MINIGAME_SHARED_GRAPHICS);
                    var_s0 = FRAGMENT_LOAD_AND_CALL(FRAGMENT_RATTATA_GAME, 0, 0);
                    break;
                case 4: // unfinished jigglypuff minigame
                    FRAGMENT_LOAD(FRAGMENT_MINIGAME_SHARED_GRAPHICS);
                    var_s0 = FRAGMENT_LOAD_AND_CALL(FRAGMENT_JIGGLYPUFF_DOODLE, 0, 0);
                    break;
                case 5: // drowzee minigame
                    FRAGMENT_LOAD(FRAGMENT_MINIGAME_SHARED_LIBRARY);
                    var_s0 = FRAGMENT_LOAD_AND_CALL(FRAGMENT_DROWZEE_GAME, 0, 0);
                    break;
                case 6: // pikachu minigame
                    FRAGMENT_LOAD(FRAGMENT_MINIGAME_SHARED_LIBRARY);
                    var_s0 = FRAGMENT_LOAD_AND_CALL(FRAGMENT_DYNAMO_GAME, 0, 0);
                    break;
                case 7: // "minigame 7 sample" model viewer. debug placeholder?
                    FRAGMENT_LOAD(FRAGMENT_MINIGAME_SHARED_LIBRARY);
                    var_s0 = FRAGMENT_LOAD_AND_CALL(FRAGMENT_MINIGAME_SAMPLE7_VIEWER, 0, 0);
                    break;
                case 8: // "minigame 8 sample" model viewer. debug placeholder?
                    FRAGMENT_LOAD(FRAGMENT_MINIGAME_SHARED_LIBRARY);
                    var_s0 = FRAGMENT_LOAD_AND_CALL(FRAGMENT_MINIGAME_SAMPLE8_VIEWER, 0, 0);
                    break;
                case 9: // sushi go round
                    FRAGMENT_LOAD(FRAGMENT_MINIGAME_ACTOR_FRAMEWORK);
                    var_s0 = FRAGMENT_LOAD_AND_CALL(FRAGMENT_SUSHI_GAME, 0, 0);
                    break;
                case 10: // seems to be the "snap mode" code. However, the asset UI isnt loaded, so this call will
                         // crash.
                    FRAGMENT_LOAD(FRAGMENT_MINIGAME_ACTOR_FRAMEWORK);
                    var_s0 = FRAGMENT_LOAD_AND_CALL(FRAGMENT_GALLERY_CAMERA, 0, 0);
                    break;
                case 11: // credits? why from the kids club?
                    FRAGMENT_LOAD(FRAGMENT_MINIGAME_SHARED_LIBRARY);
                    var_s0 = FRAGMENT_LOAD_AND_CALL(FRAGMENT_CREDITS, 0, 0);
                    break;
                case 12: // crashes. This fragment is the "Demo" cutscene bin, but this code passes an invalid demo ID,
                         // which doesnt exist.
                    FRAGMENT_LOAD(FRAGMENT_MINIGAME_ACTOR_FRAMEWORK);
                    var_s0 = FRAGMENT_LOAD_AND_CALL(FRAGMENT_DEMO_SCENES, 0, 0);
                    break;
                case 13: // ekans minigame
                    FRAGMENT_LOAD(FRAGMENT_MINIGAME_ACTOR_FRAMEWORK);
                    var_s0 = FRAGMENT_LOAD_AND_CALL(FRAGMENT_EKANS_GAME, 0, 0);
                    break;
                case 14: // crashes...
                    FRAGMENT_LOAD(FRAGMENT_MINIGAME_ACTOR_FRAMEWORK);
                    var_s0 = FRAGMENT_LOAD_AND_CALL(FRAGMENT_RANKING_DEBUG_TEST, 0, 0);
                    break;
                case 15: // metapod minigame
                    FRAGMENT_LOAD(FRAGMENT_MINIGAME_ACTOR_FRAMEWORK);
                    var_s0 = FRAGMENT_LOAD_AND_CALL(FRAGMENT_METAPOD_GAME, 0, 0);
                    break;
                case 16: // sandshrew minigame
                    FRAGMENT_LOAD(FRAGMENT_MINIGAME_ACTOR_FRAMEWORK);
                    var_s0 = FRAGMENT_LOAD_AND_CALL(FRAGMENT_SANDSHREW_GAME, 0, 0);
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
