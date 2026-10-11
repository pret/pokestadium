#include "demo_scenes.h"
#include "game_state.h"

s32 Stage_DispatchDemoScene(UNUSED s32 arg0, UNUSED s32 arg1) {
    switch (gSessionContext.mode) {
        case 18:
            return Stage_ShowBootDiorama();

        case 17:
            return Stage_ShowIntro();

        case 21:
            return Stage_ShowCompletionScene();

        case 26:
            return Stage_ShowCompletionScene();

        case 22:
        case 23:
            return Stage_ShowFirstClearBonusScene();

        case 24:
            return Stage_ShowMewtwoIntro();
    }
}
