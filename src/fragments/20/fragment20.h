#ifndef _FRAGMENT20_H_
#define _FRAGMENT20_H_

#include "global.h"
#include "src/fragments/3/fragment3.h"

void func_86E00020(s16 arg0, s16 arg1);
void func_86E001A0(s16 arg0, s16 arg1);
void miniInitMetapodPlayer(MiniActor* metapod, s32 arg1);
void miniInitMetapodPlayers(void);
void func_86E0034C(MiniActor* metapod);
void miniMetapodHumanControls(MiniActor* metapod);
void func_86E004FC(MiniActor* metapod);
s32 func_86E00518(MiniActor* arg0, s32 arg1);
void func_86E0063C(MiniActor* metapod, s32 arg1);
void func_86E0073C(MiniActor* arg0, s32 arg1);
void func_86E007BC(MiniActor* metapod, s32 arg1);
void func_86E007CC(MiniActor* metapod, s32 player);
void miniMetapodCompControls(MiniActor* compMetapod, s32 nPlayer);
void miniUpdateMetapods(void);
s32 metapodRockCollisionCheck_void(void);
s32 func_86E00C34(s32 arg0);
void miniRockChecks(MiniActor* arg0, s32 nPlayer);
void miniMatapodChecks(MiniActor* metapod, s32 nPlayer);
void miniMatapodMinigameChecks(void);
void func_86E00F60(void);
void func_86E00FD8(void);
void miniInitRock(MiniActor* rock, s32 arg1);
void miniInitRocks(void);
void func_86E01188(void);
void func_86E01310(MiniActor* rock);
void func_86E01414(MiniActor* rock);
void miniRockStateMachine(MiniActor* rock);
void miniRockUpdatePosition(MiniActor* rock);
void miniUpdateRockTransform(MiniActor* rock);
void miniUpdateRocks(void);
void func_86E0182C(MiniActor* arg0);
void miniUpdateRocksPositions(void);
void func_86E01904(void);
void miniMetapodCameraControls(void);
void initMetapodMinigameAssets(void);
void func_86E019F4(void);
s32 func_86E01B08(void);
s32 func_86E01E34(void);
void func_86E01EB0(void);
s32 func_86E01EE8(void);
s32 func_86E01F50(void);
void miniMetapodMinigameStateMachine(void);
void func_86E02150(void);
void miniDrawMetapodHealth(void);
void miniDrawMetapodHeads(void);
void func_86E02308(void);
void func_86E026D0(void);
void func_86E027D4(void);
void miniMetapodDrawPlayerHUBs(s32 arg0);
void func_86E02880(s32 arg0);
void metapodMinigameInit(void);
void func_86E0296C(void);
void miniMetapodTutoScreenControls(void);
void func_86E02A28(void);
void func_86E02A64(void);
void func_86E02BB0(void);
void func_86E02C5C(void);
s32 metapodMinigameLoad(s32 arg0, s32 arg1);

#endif // _FRAGMENT20_H_
