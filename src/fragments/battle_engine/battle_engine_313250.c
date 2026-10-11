#include "battle_engine.h"
#include "src/geo_node.h"
#include "src/model_animation.h"
#include "src/text_system.h"
#include "src/audio_commands.h"
#include "src/matrix.h"
#include "src/memory.h"
#include "src/util.h"

void BattleScene_IntroSetupCamera(unk_D_86002F34_00C* arg0) {
    BattleScene_ResetCameraFrameCounter();
    BattleScene_SetCameraClipPlanes(arg0, 20.0f, 12800.0f);
    BattleAnim_LoadModeResourceList(D_84390010[0]->unk_720, 3);
    arg0->unk_24.fovy = 40.0f;
    D_84390010[0]->unk_000.node.flags &= ~1;
    D_84390010[1]->unk_000.node.flags &= ~1;
    Vec3f_SetComponentsDuplicate(&arg0->unk_60.at, 0.0f, 75.0f, 0.0f);
    Vec3f_SetComponentsDuplicate(&arg0->unk_60.eye, -1.79f, 0.075f, 155.2f);
    gBattleScene.unk_00->unk_54 = 1;
    BattleScene_StartBattleMusic();
    gBattleScene.unk_00->unk_20 += 1;
}

void BattleScene_IntroSendOutFirstMon(UNUSED unk_D_86002F34_00C* arg0) {
    if ((BattleScene_AdvanceCameraFrameCounterUntil(0xA) != 0) && (BattleAnim_TryRegisterAssetTables(D_84390010[0]) != 0)) {
        D_84390010[0]->unk_000.node.flags &= ~1;
        D_84390010[1]->unk_000.node.flags &= ~1;
        BattleScene_SetParticipantModelFlags(D_84390010[0], 1, 0);
        Audio_PlayCommand(1, 0xFE, 0);
        BattleAnim_QueueEffectList3(8, D_84390010[0], D_84390010[0], 0xFF, 0xFF);
        gBattleScene.unk_00->unk_20 += 1;
    }
}

void BattleScene_IntroSendOutSecondMon(UNUSED unk_D_86002F34_00C* arg0) {
    D_84390010[0]->unk_000.node.flags &= ~1;
    D_84390010[1]->unk_000.node.flags &= ~1;
    if (D_84390010[0]->unk_4EC.position.y == 0.0f) {
        BattleScene_SelectBattleMusic();
        Audio_PlayCommand(1, 1, 0);
        BattleScene_SetParticipantModelFlags(D_84390010[1], 1, 0);
        BattleAnim_QueueEffectList3(0xA, D_84390010[1], D_84390010[1], 0xFF, 0xFF);
        gBattleScene.unk_00->unk_20 += 1;
    }
}

void BattleScene_IntroNarrowFov(unk_D_86002F34_00C* arg0) {
    Vec3f sp3C;

    D_84390010[0]->unk_000.node.flags &= ~1;
    D_84390010[1]->unk_000.node.flags &= ~1;

    if (D_84390010[1]->unk_4EC.position.y == 0.0f) {
        arg0->unk_24.fovy = 30.0f;
        BattleScene_SetParticipantModelFlags(D_84390010[0], 2, 0);
        BattleAnim_QueueEffectList3(0xB, D_84390010[0], D_84390010[0], 0xFF, 0xFF);
        Vec3f_SetComponentsDuplicate(&sp3C, -150.0f, 5.0f, 0.0f);
        BattleScene_SetCameraAtFromAnchor(D_84390010[0], arg0, sp3C, 0, 0, 0.0f, 0.0f);
        BattleScene_SetCameraEyeFromPosition(arg0, sp3C, gBattleScene.unk_00->unk_56 = 0x71C, 0x4000, gBattleScene.unk_00->unk_84 = 300.0f, 0.0f);
        gBattleScene.unk_00->unk_20 += 1;
    }
}

void BattleScene_IntroPanCamera(unk_D_86002F34_00C* arg0) {
    Vec3f sp2C;

    Vec3f_SetComponentsDuplicate(&sp2C, -150.0f, 5.0f, 0.0f);
    D_84390010[0]->unk_000.node.flags &= ~1;
    D_84390010[1]->unk_000.node.flags &= ~1;
    BattleAnim_ApproachF(&gBattleScene.unk_00->unk_84, 40.0f, 0.1f);
    BattleAnim_StepToS16(&gBattleScene.unk_00->unk_56, 0xB6, 0x1E);
    BattleScene_SetCameraEyeFromPosition(arg0, sp2C, gBattleScene.unk_00->unk_56, 0x4000, gBattleScene.unk_00->unk_84, 0.0f);

    if ((gBattleScene.unk_00->unk_56 >= 0x2E) && (D_84390010[0]->unk_4EC.position.y == 2.5f)) {
        Audio_PlayCommand(2, 0, 0);
        D_84390010[0]->unk_4EC.node.renderFlags |= 0x20;
        gBattleScene.unk_00->unk_20 += 1;
    }
}

void BattleScene_IntroWaitFirstMonAnim(UNUSED unk_D_86002F34_00C* arg0) {
    D_84390010[0]->unk_000.node.flags &= ~1;
    D_84390010[1]->unk_000.node.flags &= ~1;
    if (ModelAnim_IsAnimationDone(&D_84390010[0]->unk_4EC) == 1) {
        gBattleScene.unk_00->unk_20 += 1;
    }
}

void BattleScene_IntroRevealFirstMon(unk_D_86002F34_00C* arg0) {
    BattlerState* sp2C = &D_84390010[0]->unk_654;
    TeamRoster* sp28 = D_84390010[0]->unk_720->unk_08[sp2C->unk_2C];

    D_84390010[0]->unk_728.unk_168->node.flags |= 1;
    D_84390010[0]->unk_728.unk_000.node.flags |= 1;
    BattleScene_TriggerOwnerModelAnimation(D_84390010[0]);
    D_84390010[0]->unk_000.node.flags &= ~1;
    D_84390010[1]->unk_000.node.flags &= ~1;
    BattleAnim_QueueEffectList3(3, D_84390010[0], D_84390010[0], 0xFF, 0xFF);
    D_84390010[0]->unk_000.node.flags |= 1;
    D_84390010[0]->unk_4EC.node.flags &= ~1;
    BattleScene_SelectCameraFollowPreset(D_84390010[0], arg0, 3);
    BattleScene_EnterStateRow(D_84390010[0], 0x10);
    gBattleScene.unk_00->unk_2C = 0;
    Text_SetStringToken(0x19, (u32)sp28->unk_01C[sp2C->unk_18].unk_30);
    Battle_QueueMessage(gBattleMessageQueues->unk_088, 0x21);
    BattleBox_Open(0xC);
    Battle_TriggerTrainerPresentationCue(D_84390010[0]);
    gBattleScene.unk_00->unk_10 = 0;
    gBattleScene.unk_00->unk_20 += 1;
}

void BattleScene_IntroFirstMonSettle(unk_D_86002F34_00C* arg0) {
    if (gBattleScene.unk_00->unk_10++ == 1) {
        BattleScene_SelectCameraFollowPreset(D_84390010[0], arg0, 3);
    }

    D_84390010[0]->unk_728.unk_168->node.flags &= ~1;
    D_84390010[0]->unk_728.unk_000.node.flags &= ~1;
    D_84390010[1]->unk_000.node.flags &= ~1;
    BattleScene_ReframeAndRecomputeDistanceForSwitch(arg0, D_84390010[0]);

    if (BattleScene_IsRowWaitCompleteWithEventCount(D_84390010[0], 0x3C) != 0) {
        gBattleScene.unk_00->unk_20 += 1;
    }
}

void BattleScene_IntroRevealSecondMon(unk_D_86002F34_00C* arg0) {
    BattlerState* sp2C = &D_84390010[1]->unk_654;
    TeamRoster* sp28 = D_84390010[1]->unk_720->unk_08[sp2C->unk_2C];

    D_84390010[1]->unk_728.unk_168->node.flags |= 1;
    D_84390010[1]->unk_728.unk_000.node.flags |= 1;
    BattleScene_TriggerOwnerModelAnimation(D_84390010[1]);
    Audio_PlayCommand(2, 0, 0);
    BattleAnim_QueueEffectList3(3, D_84390010[1], D_84390010[1], 0xFF, 0xFF);
    BattleScene_ResetCameraFrameCounter();
    D_84390010[1]->unk_000.node.flags |= 1;
    BattleScene_SelectCameraFollowPreset(D_84390010[1], arg0, 3);
    BattleScene_EnterStateRow(D_84390010[1], 0x10);
    gBattleScene.unk_00->unk_10 = 0;
    gBattleScene.unk_00->unk_2C = 1;
    Text_SetStringToken(0x19, (u32)sp28->unk_01C[sp2C->unk_18].unk_30);
    Battle_QueueMessage(gBattleMessageQueues->unk_088, 0x21);
    if (D_800AE540.unk_0000 != 8) {
        BattleBox_Open(0xC);
    }
    Battle_TriggerTrainerPresentationCue(D_84390010[1]);
    gBattleScene.unk_00->unk_20 += 1;
}

void BattleScene_IntroSecondMonSettle(unk_D_86002F34_00C* arg0) {
    if (gBattleScene.unk_00->unk_10++ == 1) {
        BattleScene_SelectCameraFollowPreset(D_84390010[1], arg0, 3);
    }
    D_84390010[1]->unk_728.unk_168->node.flags &= ~1;
    D_84390010[1]->unk_728.unk_000.node.flags &= ~1;
    D_84390010[0]->unk_000.node.flags &= ~1;
    BattleScene_ReframeAndRecomputeDistanceForSwitch(arg0, D_84390010[1]);
    if (BattleScene_IsRowWaitCompleteWithEventCount(D_84390010[1], 0x3C) != 0) {
        BattleScene_BeginBattlePhase();
        gBattleScene.unk_00->unk_20 += 1;
    }
}

void BattleScene_IntroStepNop(UNUSED unk_D_86002F34_00C* arg0) {
}

void BattleScene_IntroInitNop(void) {
}

void BattleScene_UpdateIntroSequence(unk_D_86002F34_00C* arg0) {
    switch (gBattleScene.unk_00->unk_20) {
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
