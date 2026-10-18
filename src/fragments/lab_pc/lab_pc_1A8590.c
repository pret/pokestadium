#include "lab_pc.h"
#include "src/graphics_textures.h"
#include "src/game_state.h"
#include "src/jpeg_stream.h"
#include "src/memory.h"
#include "src/stage_loader.h"

FontContext* LabPC_Enter(void) {
    FontContext* sp1C;

    main_pool_push_state('TERM');

    sp1C = Font_Init(0x1C, 0);

    ASSET_LOAD(D_04000000, fragment29_misc_1, 0);
    FRAGMENT_LOAD(FRAGMENT_WIDGET_TREE);
    FRAGMENT_LOAD(FRAGMENT_LAB_UI_SUPPORT);

    StageLoader_UpdateSegments();
    return sp1C;
}

void LabPC_Exit(void) {
    StageLoader_WaitForRetrace();

    main_pool_pop_state('TERM');
}

s32 LabPC_ExitToLabMain(UNUSED s32 arg0, UNUSED s32 arg1) {
    LabPC_ShowPokemon(LabPC_Enter(), 1);
    StageContext_SetClearColor(1);
    StageFade_StartFromTransparent(0xA);
    LabPC_Exit();

    FRAGMENT_LOAD_AND_CALL2(FRAGMENT_PROFESSOR_OAK_LAB, 1, 0);
    return 0x25;
}

s32 LabPC_Dispatch(s32 arg0, s32 arg1) {
    FontContext* temp_s0;
    s32 var_s1;

    if (arg0 == 5) {
        return LabPC_ExitToLabMain(arg0, arg1);
    }
    temp_s0 = LabPC_Enter();

    var_s1 = LabPC_ShowMenu(arg0, arg1);
    while (var_s1 != 0) {
        switch (var_s1) {
            case 1:
                LabPC_ShowPokemon(temp_s0, 0);
                break;

            case 2:
                LabPC_ShowItems(temp_s0);
                break;

            case 3:
                LabPC_ShowBoxes(temp_s0);
                break;
        }
        var_s1 = LabPC_ShowMenu(var_s1, arg1);
    }

    LabPC_Exit();

    return 0x25;
}
