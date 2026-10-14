#include "session.h"
#include "src/gb_data.h"
#include "src/pokemon_stats.h"
#include "src/save_data.h"
#include "src/session.h"
#include "src/jpeg_stream.h"
#include "src/hal_libc.h"
#include "src/math_util.h"
#include "src/memory.h"
#include "src/controller.h"

u8 D_80075680[3] = { 1, 15, 30 };
static s16 D_80075684 = 0;

void Team_ClearTrainerSlot(BattleSessionTeams* arg0) {
    arg0->unk_00 = 0;
    arg0->unk_01 = 0;
    arg0->unk_02 = 0;
    arg0->unk_04 = 0;
    arg0->unk_14 = 0;
    arg0->unk_08[0] = 0;
    arg0->unk_08[1] = 0;
    arg0->unk_1D = 0;
    arg0->unk_20 = 0;
    arg0->unk_1E = 0;
}

void Session_SetMode(s32 arg0, s32 arg1, s32 arg2) {
    s32 i;
    s32 j;

    Team_ClearTrainerSlot(&gSessionContext.battleSides[0]);
    Team_ClearTrainerSlot(&gSessionContext.battleSides[1]);

    gSessionContext.mode = arg0;
    gSessionContext.ruleCategory = arg1;
    gSessionContext.modeSelection = arg2;
    gSessionContext.roundOrDemoId = 1;

    gSessionContext.timeLimitsEnabled = 0;
    gSessionContext.battleLimitMinutes = 0;
    gSessionContext.moveLimitSeconds = 0;
    gSessionContext.unk_11F4 = 0;
    gSessionContext.sessionFlags = 0;
    gSessionContext.continueCount = 0;
    gSessionContext.transitionFlags = 0;
    gSessionContext.aiDifficulty = 0;

    for (i = 0; i < 4; i++) {
        gSessionContext.trainerSlots[i].unk_000 = 0;
    }

    for (i = 0; i < 2; i++) {
        if (1) {
            for (j = 0; j < 4; j++) {
                gSessionContext.opponentHistory[i][j] = 0xFF;
            }
        }
    }
}

void Team_ResetOpponentHistory(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            gSessionContext.opponentHistory[i][j] = 0xFF;
        }
    }

    gSessionContext.roundOrDemoId = 1;
    gSessionContext.continueCount = 0;
}

TeamRoster* Trainer_Create(s32 arg0, s16 arg1, char* arg2, char* arg3) {
    s32 i;
    ExtendedRosterInfo* sp20;
    TeamRoster* sp1C = NULL;

    for (i = 0; i < 4; i++) {
        if ((gSessionContext.trainerSlots + i)->unk_000 == 0) {
            sp1C = &gSessionContext.trainerSlots[i];
            sp20 = &gSessionContext.rosterInfo[i];
            break;
        }
    }

    if (sp1C != NULL) {
        if (arg0 == -1) {
            sp1C->unk_000 = 3;
            sp1C->unk_001 = 1;
            sp1C->controller = &gControllers[0];
        } else {
            sp1C->unk_000 = 1;
            sp1C->unk_001 = arg0;
            sp1C->controller = &gControllers[arg0];
        }

        sp1C->unk_018 = 0;
        sp1C->unk_214 = sp20;
        sp1C->unk_002 = 0;

        sp20->unk_000 = 0;
        sp20->unk_002 = 0;
        sp20->unk_003 = 1;

        HAL_Strcpy(sp1C->unk_008, arg2);
        HAL_Strcpy(sp20->unk_014, arg2);
        HAL_Strcpy(sp20->unk_220, arg3);
    }
    return sp1C;
}

void Team_AddTrainer(s32 arg0, TeamRoster* arg1) {
    BattleSessionTeams* temp_v0 = &gSessionContext.battleSides[arg0];
    u8 idx = temp_v0->unk_01;

    if (idx < 2) {
        temp_v0->unk_08[idx] = arg1;
        temp_v0->unk_01++;
    }
}

void Trainer_AddPokemon(TeamRoster* arg0, BattleMon* arg1) {
    ExtendedRosterInfo* ptr = arg0->unk_214;
    s32 tmp = arg0->unk_002;

    if (tmp < 6) {
        arg0->unk_01C[tmp] = *arg1;
        ptr->unk_028[tmp] = *arg1;

        arg0->unk_002 = tmp + 1;
        ptr->unk_002 = tmp + 1;
    }
}

BattleMon* Pokemon_CreateDefault(BattleMon* arg0, u8 arg1, s16 arg2) {
    arg0->unk_00.unk_00 = arg1;
    arg0->unk_04 = 0;
    arg0->unk_05 = 0;

    arg0->unk_06 = D_80070FA0[arg1 - 1].unk_06;
    arg0->unk_07 = D_80070FA0[arg1 - 1].unk_07;

    arg0->unk_14 = 0x6400;
    arg0->unk_16 = 0x6400;
    arg0->unk_18 = 0x6400;
    arg0->unk_1A = 0x6400;
    arg0->unk_1C = 0x6400;

    arg0->unk_08 = 0;

    arg0->unk_09[0] = 0;
    arg0->unk_09[1] = 0;
    arg0->unk_09[2] = 0;
    arg0->unk_09[3] = 0;

    arg0->unk_0E = 0x7CF;
    arg0->unk_1E = 0xFFFF;

    arg0->unk_20[0] = 5;
    arg0->unk_20[1] = 5;
    arg0->unk_20[2] = 5;
    arg0->unk_20[3] = 5;

    arg0->unk_52 = 0;
    arg0->unk_53 = 0;
    arg0->unk_10 = Pokemon_ExpForLevel(arg1, arg2);

    Pokemon_RecalcStats(arg0);

    arg0->unk_02 = arg0->unk_26;

    Text_CopySpeciesName(arg0->unk_30, arg1);
    HAL_Strcpy(arg0->unk_3B, Text_GetPlayerLabel(0));
    return arg0;
}

void Session_SetupDemoBattle(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    s16 spD6;
    s32 spD0;
    s32 spCC;
    BattleMon sp78;
    BattleMon sp24;

    switch (arg0) {
        case 0:
            spD6 = 0x32;
            break;

        case 3:
            spD6 = 0x32;
            break;

        case 4:
            spD6 = 0x1E;
            break;

        case 5:
            spD6 = 0x19;
            break;

        case 6:
            spD6 = 0x64;
            break;

        case 7:
            spD6 = 0x64;
            break;
    }

    Session_SetMode(0x10, arg0, arg1);

    spD0 = Trainer_Create(0, 0, Text_GetPlayerLabel(1), Text_GetPlayerLabel(2));
    spCC = Trainer_Create(1, 0, Text_GetPlayerLabel(1), Text_GetPlayerLabel(2));

    Trainer_AddPokemon(spD0, Pokemon_CreateDefault(&sp78, arg2, spD6));
    Trainer_AddPokemon(spCC, Pokemon_CreateDefault(&sp24, arg3, spD6));

    Team_AddTrainer(0, spD0);
    Team_AddTrainer(1, spCC);
}

void Team_AddDeckTrainer(s32 arg0, s32 arg1, s32 arg2) {
    s32 i;
    BattleMon sp48;
    DeckHandle* temp_v0;
    TeamRoster* temp_s4;
    char sp34[11];

    GbSave_EnsureMainDataLoaded(arg2);
    GbSave_GetPlayerName(arg2, &sp34);

    temp_s4 = Trainer_Create(arg1, 0, &sp34, Text_GetPlayerLabel(1));
    temp_v0 = Deck_Open(0x20, arg2, 0, 0);

    if (temp_v0 != NULL) {
        for (i = 0; i < 6; i++) {
            if (Deck_ReadEntries(&sp48, 1, temp_v0) == 0) {
                break;
            }

            Trainer_AddPokemon(temp_s4, &sp48);
        }

        Deck_CloseAndFlush(temp_v0);
    }

    Team_AddTrainer(arg0, temp_s4);
}

void Team_BuildDeckOpponents(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    main_pool_push_state('RIVL');

    Session_SetMode(0, 3, 0);

    if (arg0 > 0) {
        Team_AddDeckTrainer(0, arg0 - 1, arg0 - 1);
    }

    if (arg1 > 0) {
        Team_AddDeckTrainer(0, arg1 - 1, arg1 - 1);
    }

    if (arg2 > 0) {
        Team_AddDeckTrainer(1, arg2 - 1, arg2 - 1);
    }

    if (arg3 > 0) {
        Team_AddDeckTrainer(1, arg3 - 1, arg3 - 1);
    }

    main_pool_pop_state('RIVL');
}

s32 Team_IsOpponentIndexUsed(s32 arg0) {
    s32 i;

    for (i = 0; i < gSessionContext.roundOrDemoId - 1; i++) {
        if (arg0 == gSessionContext.opponentHistory[0][i]) {
            return 1;
        }
    }

    return 0;
}

s32 Team_PickRandomOpponentIndex(s32 arg0) {
    s32 var_s0;
    s32 var_s1;
    s32 sp24;
    u8 temp_v1;

    var_s0 = -1;

    sp24 = (arg0 - gSessionContext.roundOrDemoId) + 1;
    if (gSessionContext.roundOrDemoId == 1) {
        return 0;
    }

    temp_v1 = gSessionContext.opponentHistory[0][gSessionContext.roundOrDemoId - 1];
    if (temp_v1 != 0xFF) {
        return temp_v1;
    }

    var_s1 = osGetCount() & 0xF;
    while (var_s1 > 0) {
        MathUtil_Random16();
        var_s1--;
    }

    var_s1 = MathUtil_Random16() % sp24;
    while (var_s1 >= 0) {
        var_s0++;
        while (Team_IsOpponentIndexUsed(var_s0) != 0) {
            var_s0++;
        }
        var_s1--;
    }

    return var_s0;
}

s16 Team_GetHighestPartyLevel(void) {
    s16 i;
    s16 var_v1 = 0;
    BattleMon* var_v0;

    var_v0 = &gSessionContext.battleSides[0].unk_08[0]->unk_214->unk_028[0];

    for (i = 0; i < gSessionContext.battleSides[0].unk_08[0]->unk_214->unk_002; i++, var_v0++) {
        if (var_v1 < var_v0->unk_24) {
            var_v1 = var_v0->unk_24;
        }
    }

    return var_v1;
}

void Team_ScaleOpponentToLevel(s16 arg0) {
    s16 i;
    BattleMon* var_s0;
    BattleMon* var_s1;

    if (arg0 < 0x33) {
        return;
    }

    var_s0 = gSessionContext.battleSides[1].unk_08[0]->unk_01C;
    var_s1 = gSessionContext.battleSides[1].unk_08[0]->unk_214->unk_028;

    for (i = 0; i < gSessionContext.battleSides[1].unk_08[0]->unk_002; i++, var_s1++, var_s0++) {
        var_s0->unk_24 = arg0;
        var_s0->unk_10 = Pokemon_ExpForLevel(var_s0->unk_00.unk_00, arg0);
        Pokemon_RecalcStats(var_s0);
        var_s0->unk_02 = var_s0->unk_26;

        *var_s1 = *var_s0;
    }
}

typedef struct PresetTrainer {
    /* 0x000 */ char unk_00[0x4];
    /* 0x004 */ char unk04[0x8];
    /* 0x00C */ char unk_0C[0x4];
    /* 0x010 */ char unk10[0x24];
    /* 0x034 */ u16 unk_34;
    /* 0x036 */ u16 unk_36;
    /* 0x038 */ BattleMon unk_38[1];
} PresetTrainer; // size >= 0x8C

typedef struct PresetTrainerSlot {
    /* 0x000 */ s32 unk_00;
    /* 0x004 */ PresetTrainer unk_004;
    /* 0x090 */ char unk090[0x1A0];
} PresetTrainerSlot; // size = 0x230

void Team_LoadPresetTrainer(s16 arg0, s16 arg1, s16 arg2, s32 arg3) {
    s32 i;
    s16 var_a1;
    TeamRoster* temp_s3;
    s32 var_s0;
    PresetTrainer* temp_s2;
    BattleMon* var_s1;
    PresetTrainerSlot* ptr;
    PresetTrainerSlot* temp_v1;

    temp_s3 = gSessionContext.battleSides[arg0].unk_08[0];
    if (gSessionContext.inRound2 != 0) {
        arg1 += 0x1F;
    }

    ptr = BinArchive_GetFile(D_800AF738, arg1);
    ptr += arg2;

    temp_s2 = &ptr->unk_004;

    gSessionContext.opponentHistory[0][gSessionContext.roundOrDemoId - 1] = arg2;

    temp_s3->unk_018 = temp_s2->unk_34;
    temp_s3->unk_002 = 0;

    for (i = 0; i < temp_s2->unk_36; i++) {
        Trainer_AddPokemon(temp_s3, &temp_s2->unk_38[i]);
    }

    HAL_Strcpy(temp_s3->unk_008, temp_s2->unk_00);
    HAL_Strcpy(temp_s3->unk_214->unk_014, temp_s2->unk_00);
    HAL_Strcpy(temp_s3->unk_214->unk_220, temp_s2->unk_0C);

    temp_s3->unk_214->unk_003 = (temp_s2->unk_34 >> 8) & 0xFF;

    if (arg3 != 0) {
        Team_ScaleOpponentToLevel(Team_GetHighestPartyLevel());
    }
}

void Team_LoadOpponentPreset(void) {
    s16 var_s0 = gSessionContext.roundOrDemoId - 1;
    s16 sp24 = gSessionContext.modeSelection;

    if ((gSessionContext.mode == 2) && (gSessionContext.inRound2 != 0)) {
        var_s0 = Team_PickRandomOpponentIndex(8);
    } else if ((gSessionContext.mode == 7) && (sp24 == 9)) {
        switch (gSessionContext.gbStarterChoice) {
            case 0x1:
                var_s0 = 4;
                break;

            case 0x2:
                var_s0 = 5;
                break;

            case 0x3:
                var_s0 = 3;
                break;

            case 0x99:
                var_s0 = 0;
                break;

            case 0xB0:
                var_s0 = 2;
                break;

            case 0xB1:
                var_s0 = 1;
                break;

            default:
                var_s0 = 6;
                break;
        }
    }

    main_pool_push_state('RIVL');

    D_800AF738 = BinArchive_Open(TRAINER_DATA_ROM_START, NULL, 1, 0);

    switch (gSessionContext.mode) {
        case 1:
            Team_LoadPresetTrainer(1, 6, var_s0, 0);
            break;

        case 2:
            Team_LoadPresetTrainer(1, 7, var_s0, 0);
            break;

        case 3:
            Team_LoadPresetTrainer(1, sp24 + 8, var_s0, 0);
            break;

        case 4:
            Team_LoadPresetTrainer(1, 0, var_s0, 0);
            break;

        case 5:
            Team_LoadPresetTrainer(1, 1, var_s0, 0);
            break;

        case 6:
            Team_LoadPresetTrainer(1, sp24 + 2, var_s0, 0);
            break;

        case 7:
            Team_LoadPresetTrainer(1, sp24 + 0xC, var_s0, 1);
            break;

        case 8:
            Team_LoadPresetTrainer(1, 0x16, var_s0, 0);
            break;
    }

    main_pool_pop_state('RIVL');
}

void Team_BuildQuickBattleTeams(s16 arg0) {
    main_pool_push_state('RIVL');

    D_800AF738 = BinArchive_Open(TRAINER_DATA_ROM_START, NULL, 1, 0);
    Session_SetMode(9, 6, 0);

    if (arg0 == 1) {
        Team_AddTrainer(0, Trainer_Create(0, 0, "1P", Text_GetPlayerLabel(1)));
        Team_AddTrainer(1, Trainer_Create(-1, 0, "COM", Text_GetPlayerLabel(3)));
    } else {
        Team_AddTrainer(0, Trainer_Create(0, 0, "1P", Text_GetPlayerLabel(1)));
        Team_AddTrainer(1, Trainer_Create(1, 0, "2P", Text_GetPlayerLabel(1)));
    }

    if (D_80075684 == 0) {
        Team_LoadPresetTrainer(0, 0x1D, 0, 0);
        Team_LoadPresetTrainer(1, 0x1D, 1, 0);
    } else {
        Team_LoadPresetTrainer(0, 0x1D, 1, 0);
        Team_LoadPresetTrainer(1, 0x1D, 0, 0);
    }

    D_80075684 ^= 1;

    main_pool_pop_state('RIVL');
}

void Session_SaveContinueData(void) {
    SessionContinueData sp20;
    ExtendedRosterInfo* sp1C = gSessionContext.battleSides[0].unk_08[0]->unk_214;

    sp20.unk_00 = gSessionContext.mode;
    sp20.unk_01 = gSessionContext.modeSelection;
    sp20.unk_02 = gSessionContext.roundOrDemoId;
    sp20.unk_04 = gSessionContext.continueCount;
    sp20.unk_03 = gSessionContext.inRound2;

    sp20.unk_0D = gSessionContext.gbStarterChoice;
    sp20.unk_0E = gSessionContext.battleSides[0].unk_08[0]->unk_018;

    _bcopy(gSessionContext.opponentHistory[0], &sp20.unk_05, 8);
    Text_TranscodeNameWrapper(&sp20.unk_10, &gSessionContext.battleSides[0].unk_08[0]->unk_008);
    Session_SaveContinueRecord(&sp20, sp1C->unk_028, sp1C->unk_002);
    Save_CommitTypedRecord(0x15, 0);
}

s32 Session_LoadContinueData(void) {
    SessionContinueData sp250;
    BattleMon sp58[6];
    s32 i;
    char sp44[0x10];
    s32 temp_v0;
    u16 tmp;

    temp_v0 = Session_LoadContinueRecord(&sp250, sp58);
    if (temp_v0 != -1) {
        Session_SetMode(sp250.unk_00, sp250.unk_00, sp250.unk_01);

        _bcopy(sp250.unk_05, gSessionContext.opponentHistory[0], 8);
        gSessionContext.roundOrDemoId = sp250.unk_02;
        gSessionContext.continueCount = sp250.unk_04;
        gSessionContext.inRound2 = sp250.unk_03;
        gSessionContext.gbStarterChoice = sp250.unk_0D;
        tmp = sp250.unk_0E;

        Text_UntranscodeNameWrapper(sp44, sp250.unk_10);
        Team_AddTrainer(0, Trainer_Create(0, tmp, sp44, sp44));
        Team_AddTrainer(1, Trainer_Create(-1, tmp, "COM", Text_GetPlayerLabel(3)));

        for (i = 0; i < temp_v0; i++) {
            Trainer_AddPokemon(gSessionContext.battleSides[0].unk_08[0], &sp58[i]);
        }

        gSessionContext.sessionFlags |= 3;
    }
    return (temp_v0 + 1) != 0;
}
