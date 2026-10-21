#include "battle_engine.h"
#include "src/geo_node.h"
#include "src/model_animation.h"
#include "src/text_system.h"
#include "src/audio_commands.h"
#include "src/matrix.h"
#include "src/memory.h"
#include "src/util.h"

#if defined(VERSION_JP)
// Points to the EUC-JP format "ゆけっ！ %s" ("Go! %s"); one of the adjacent format pointers from
// D_84386D80_jp in battle_engine_309ED0 data. The send-out messages pass the name for %s.
extern char* D_84386D84_jp;
#endif

void BattleScene_IntroSetupCamera(CameraNode* arg0) {
    BattleScene_ResetCameraFrameCounter();
    BattleScene_SetCameraClipPlanes(arg0, 20.0f, 12800.0f);
    BattleAnim_LoadModeResourceList(sActivePokemon[0]->sessionTeams, 3);
    arg0->perspective.verticalFieldOfView = 40.0f;
    sActivePokemon[0]->displayObject.node.flags &= ~1;
    sActivePokemon[1]->displayObject.node.flags &= ~1;
    Vec3f_SetComponentsDuplicate(&arg0->view.targetPosition, 0.0f, 75.0f, 0.0f);
    Vec3f_SetComponentsDuplicate(&arg0->view.eyePosition, -1.79f, 0.075f, 155.2f);
    sBattleScene.unk_00->unk_54 = 1;
    BattleScene_StartBattleMusic();
    sBattleScene.unk_00->unk_20 += 1;
}

void BattleScene_IntroSendOutFirstMon(UNUSED CameraNode* arg0) {
    if ((BattleScene_AdvanceCameraFrameCounterUntil(0xA) != 0) && (BattleAnim_TryRegisterAssetTables(sActivePokemon[0]) != 0)) {
        sActivePokemon[0]->displayObject.node.flags &= ~1;
        sActivePokemon[1]->displayObject.node.flags &= ~1;
        BattleScene_SetParticipantModelFlags(sActivePokemon[0], 1, 0);
        Audio_PlayCommand(1, 0xFE, 0);
        BattleAnim_QueueEffectList3(8, sActivePokemon[0], sActivePokemon[0], 0xFF, 0xFF);
        sBattleScene.unk_00->unk_20 += 1;
    }
}

void BattleScene_IntroSendOutSecondMon(UNUSED CameraNode* arg0) {
    sActivePokemon[0]->displayObject.node.flags &= ~1;
    sActivePokemon[1]->displayObject.node.flags &= ~1;
    if (sActivePokemon[0]->unk_4EC.position.y == 0.0f) {
        BattleScene_SelectBattleMusic();
        Audio_PlayCommand(1, 1, 0);
        BattleScene_SetParticipantModelFlags(sActivePokemon[1], 1, 0);
        BattleAnim_QueueEffectList3(0xA, sActivePokemon[1], sActivePokemon[1], 0xFF, 0xFF);
        sBattleScene.unk_00->unk_20 += 1;
    }
}

void BattleScene_IntroNarrowFov(CameraNode* arg0) {
    Vec3f sp3C;

    sActivePokemon[0]->displayObject.node.flags &= ~1;
    sActivePokemon[1]->displayObject.node.flags &= ~1;

    if (sActivePokemon[1]->unk_4EC.position.y == 0.0f) {
        arg0->perspective.verticalFieldOfView = 30.0f;
        BattleScene_SetParticipantModelFlags(sActivePokemon[0], 2, 0);
        BattleAnim_QueueEffectList3(0xB, sActivePokemon[0], sActivePokemon[0], 0xFF, 0xFF);
        Vec3f_SetComponentsDuplicate(&sp3C, -150.0f, 5.0f, 0.0f);
        BattleScene_SetCameraAtFromAnchor(sActivePokemon[0], arg0, sp3C, 0, 0, 0.0f, 0.0f);
        BattleScene_SetCameraEyeFromPosition(arg0, sp3C, sBattleScene.unk_00->unk_56 = 0x71C, 0x4000, sBattleScene.unk_00->unk_84 = 300.0f, 0.0f);
        sBattleScene.unk_00->unk_20 += 1;
    }
}

void BattleScene_IntroPanCamera(CameraNode* arg0) {
    Vec3f sp2C;

    Vec3f_SetComponentsDuplicate(&sp2C, -150.0f, 5.0f, 0.0f);
    sActivePokemon[0]->displayObject.node.flags &= ~1;
    sActivePokemon[1]->displayObject.node.flags &= ~1;
    BattleAnim_ApproachF(&sBattleScene.unk_00->unk_84, 40.0f, 0.1f);
    BattleAnim_StepToS16(&sBattleScene.unk_00->unk_56, 0xB6, 0x1E);
    BattleScene_SetCameraEyeFromPosition(arg0, sp2C, sBattleScene.unk_00->unk_56, 0x4000, sBattleScene.unk_00->unk_84, 0.0f);

    if ((sBattleScene.unk_00->unk_56 >= 0x2E) && (sActivePokemon[0]->unk_4EC.position.y == 2.5f)) {
        Audio_PlayCommand(2, 0, 0);
        sActivePokemon[0]->unk_4EC.node.renderFlags |= 0x20;
        sBattleScene.unk_00->unk_20 += 1;
    }
}

void BattleScene_IntroWaitFirstMonAnim(UNUSED CameraNode* arg0) {
    sActivePokemon[0]->displayObject.node.flags &= ~1;
    sActivePokemon[1]->displayObject.node.flags &= ~1;
    if (ModelAnim_IsAnimationDone(&sActivePokemon[0]->unk_4EC) == 1) {
        sBattleScene.unk_00->unk_20 += 1;
    }
}

void BattleScene_IntroRevealFirstMon(CameraNode* arg0) {
    ActivePokemonState* sp2C = &sActivePokemon[0]->state;
    TeamRoster* sp28 = sActivePokemon[0]->sessionTeams->teamMember[sp2C->unk_2C];

    sActivePokemon[0]->presentationState.unk_168->node.flags |= 1;
    sActivePokemon[0]->presentationState.displayObject.node.flags |= 1;
    BattleScene_TriggerOwnerModelAnimation(sActivePokemon[0]);
    sActivePokemon[0]->displayObject.node.flags &= ~1;
    sActivePokemon[1]->displayObject.node.flags &= ~1;
    BattleAnim_QueueEffectList3(3, sActivePokemon[0], sActivePokemon[0], 0xFF, 0xFF);
    sActivePokemon[0]->displayObject.node.flags |= 1;
    sActivePokemon[0]->unk_4EC.node.flags &= ~1;
    BattleScene_SelectCameraFollowPreset(sActivePokemon[0], arg0, 3);
    BattleScene_EnterStateRow(sActivePokemon[0], 0x10);
    sBattleScene.unk_00->unk_2C = 0;
#if defined(VERSION_JP)
    Battle_QueueMessage(gBattleMessageQueues->unk_088, 0x21, D_84386D84_jp,
                        sp28->pokemonPicked[sp2C->unk_18].unk_30);
#else
    Text_SetStringToken(0x19, (u32)sp28->pokemonPicked[sp2C->unk_18].unk_30);
    Battle_QueueMessage(gBattleMessageQueues->unk_088, 0x21);
#endif
    BattleBox_Open(0xC);
    Battle_TriggerTrainerPresentationCue(sActivePokemon[0]);
    sBattleScene.unk_00->unk_10 = 0;
    sBattleScene.unk_00->unk_20 += 1;
}

void BattleScene_IntroFirstMonSettle(CameraNode* arg0) {
    if (sBattleScene.unk_00->unk_10++ == 1) {
        BattleScene_SelectCameraFollowPreset(sActivePokemon[0], arg0, 3);
    }

    sActivePokemon[0]->presentationState.unk_168->node.flags &= ~1;
    sActivePokemon[0]->presentationState.displayObject.node.flags &= ~1;
    sActivePokemon[1]->displayObject.node.flags &= ~1;
    BattleScene_ReframeAndRecomputeDistanceForSwitch(arg0, sActivePokemon[0]);

    if (BattleScene_IsRowWaitCompleteWithEventCount(sActivePokemon[0], 0x3C) != 0) {
        sBattleScene.unk_00->unk_20 += 1;
    }
}

void BattleScene_IntroRevealSecondMon(CameraNode* arg0) {
    ActivePokemonState* sp2C = &sActivePokemon[1]->state;
    TeamRoster* sp28 = sActivePokemon[1]->sessionTeams->teamMember[sp2C->unk_2C];

    sActivePokemon[1]->presentationState.unk_168->node.flags |= 1;
    sActivePokemon[1]->presentationState.displayObject.node.flags |= 1;
    BattleScene_TriggerOwnerModelAnimation(sActivePokemon[1]);
    Audio_PlayCommand(2, 0, 0);
    BattleAnim_QueueEffectList3(3, sActivePokemon[1], sActivePokemon[1], 0xFF, 0xFF);
    BattleScene_ResetCameraFrameCounter();
    sActivePokemon[1]->displayObject.node.flags |= 1;
    BattleScene_SelectCameraFollowPreset(sActivePokemon[1], arg0, 3);
    BattleScene_EnterStateRow(sActivePokemon[1], 0x10);
    sBattleScene.unk_00->unk_10 = 0;
    sBattleScene.unk_00->unk_2C = 1;
#if defined(VERSION_JP)
    Battle_QueueMessage(gBattleMessageQueues->unk_088, 0x21, D_84386D84_jp,
                        sp28->pokemonPicked[sp2C->unk_18].unk_30);
#else
    Text_SetStringToken(0x19, (u32)sp28->pokemonPicked[sp2C->unk_18].unk_30);
    Battle_QueueMessage(gBattleMessageQueues->unk_088, 0x21);
#endif
    if (gSessionContext.mode != 8) {
        BattleBox_Open(0xC);
    }
    Battle_TriggerTrainerPresentationCue(sActivePokemon[1]);
    sBattleScene.unk_00->unk_20 += 1;
}

void BattleScene_IntroSecondMonSettle(CameraNode* arg0) {
    if (sBattleScene.unk_00->unk_10++ == 1) {
        BattleScene_SelectCameraFollowPreset(sActivePokemon[1], arg0, 3);
    }
    sActivePokemon[1]->presentationState.unk_168->node.flags &= ~1;
    sActivePokemon[1]->presentationState.displayObject.node.flags &= ~1;
    sActivePokemon[0]->displayObject.node.flags &= ~1;
    BattleScene_ReframeAndRecomputeDistanceForSwitch(arg0, sActivePokemon[1]);
    if (BattleScene_IsRowWaitCompleteWithEventCount(sActivePokemon[1], 0x3C) != 0) {
        BattleScene_BeginBattlePhase();
        sBattleScene.unk_00->unk_20 += 1;
    }
}

void BattleScene_IntroStepNop(UNUSED CameraNode* arg0) {
}

void BattleScene_IntroInitNop(void) {
}

void BattleScene_UpdateIntroSequence(CameraNode* arg0) {
    switch (sBattleScene.unk_00->unk_20) {
        case 0:
            BattleScene_IntroSetupCamera(arg0);

        case 1:
            BattleScene_IntroSendOutFirstMon(arg0);
            break;

        case 2:
            BattleScene_IntroSendOutSecondMon(arg0);
            break;

        case 3:
            BattleScene_IntroNarrowFov(arg0);
            break;

        case 4:
            BattleScene_IntroPanCamera(arg0);
            break;

        case 5:
            BattleScene_IntroWaitFirstMonAnim(arg0);
            break;

        case 6:
            BattleScene_IntroRevealFirstMon(arg0);
            break;

        case 7:
            BattleScene_IntroFirstMonSettle(arg0);
            break;

        case 8:
            BattleScene_IntroRevealSecondMon(arg0);
            break;

        case 9:
            BattleScene_IntroSecondMonSettle(arg0);
            break;

        case 10:
            BattleScene_IntroStepNop(arg0);
            break;
    }
}
