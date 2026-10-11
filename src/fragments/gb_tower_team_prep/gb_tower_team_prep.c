#include "gb_tower_team_prep.h"
#include "src/display_object_textures.h"
#include "src/poke_icon.h"
#include "src/pokemon_stats.h"
#include "src/save_data.h"
#include "src/jpeg_stream.h"
#include "src/gfx_buffer.h"
#include "src/gfx_rect.h"
#include "src/controller.h"
#include "src/memory.h"
#include "src/stage_loader.h"

static ModelLoadContext* D_82A00370;
static unk_func_8001A024* D_82A00374;
static BattleMon D_82A00378[6];

static s32 D_82A00360 = 0;

void GbTower_LoadPartyFromDeck(s32 arg0) {
    s32 i;
    DeckHandle* temp_v0;

    if (GbSave_EnsureMainDataLoaded(arg0) != 0) {
        temp_v0 = Deck_Open(0x20, arg0, 0, 0);
        D_82A00360 = Deck_ReadEntries(D_82A00378, 6, temp_v0);
        Deck_CloseAndFlush(temp_v0);
    }

    for (i = 0; i < D_82A00360; i++) {
        func_8001A46C(D_82A00374, i, &D_82A00378[i], 1);
    }
}

s32 GbTower_TeamPrepFrameCallback(u8 arg0) {
    Cont_StartReadInputs();
    Cont_ReadInputs();
    PokeIcon_ProcessAllSlots(D_82A00374, 0);
    BgStage_DrawFrame();
    GfxImage_FillCurrent(&gDisplayListHead, 1);
    return 0;
}

void GbTower_BuildPartyResult(UnkInputStruct8000D738* arg0) {
    s32 i;
    GameOptions sp34;
    u16(*var_s1)[0x640] = arg0->unk_04[0];

    Save_GetOptions(&sp34);
    arg0->unk_02 = sp34.unk_00;
    arg0->unk_00 = sp34.unk_04;
    arg0->unk_03 = D_82A00360;

    for (i = 0; i < D_82A00360; i++, var_s1++) {
        _bcopy(PokeIcon_GetImage(D_82A00374, i), var_s1, sizeof(var_s1[0]));
    }

    if (D_82A00360 < 6) {
        bzero(var_s1, 0x4B00 + (-D_82A00360 * 0xC80));
    }
}

s32 GbTower_TeamPrep(s32 arg0, UnkInputStruct8000D738* arg1) {
    unk_func_80007444* sp24;

    main_pool_push_state('PREP');

    Gfx_InitDisplayListBuffers(0x10000, 0);
    sp24 = StageContext_Allocate(0, 1, 2, 0, 1, 1);

    ASSET_LOAD(D_1000000, common_menu1_ui, 0);
    FRAGMENT_LOAD(fragment31);

    D_82A00370 = PokeIcon_AllocFramebuffers(1);
    D_82A00374 = PokeIcon_CreateRenderList(D_82A00370, 6, 0x28, 0x28);
    PokeIcon_OpenModelArchives();
    GbTower_LoadPartyFromDeck(arg0);
    Save_EnsureBankLoaded(2);
    StageContext_Activate(sp24);
    BgStage_RunUntilCondition(8, GbTower_TeamPrepFrameCallback);
    StageContext_Deactivate();
    GbTower_BuildPartyResult(arg1);
    Gfx_FreeDisplayListBuffers();

    main_pool_pop_state('PREP');

    return D_82A00360;
}
