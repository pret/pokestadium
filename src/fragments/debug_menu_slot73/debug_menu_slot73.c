#include "debug_menu_slot73.h"
#include "src/game_state.h"

s32 DebugMenu_ForwardSlot73(UNUSED s32 arg0, UNUSED s32 arg1, UNUSED s32 arg2) {
    FRAGMENT_LOAD_AND_CALL2(FRAGMENT_DEBUG_MENU_EXIT, 0, 0);
    return 0x80;
}
