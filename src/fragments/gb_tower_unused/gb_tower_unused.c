#include "gb_tower_unused.h"
#include "src/game_state.h"

s32 Minigame2SampleViewer_PollInput(s32 arg0, s32 arg1) {
    FRAGMENT_LOAD_AND_CALL(FRAGMENT_TRANSFER_PAK_SELECT, 0, 0);
    return 0;
}
