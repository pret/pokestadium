#ifndef _FRAGMENT21_H_
#define _FRAGMENT21_H_

#include "global.h"
#include "src/fragments/3/fragment3.h"

void func_86F00020(s16 arg0, s16 arg1);
void func_86F00188(s16 arg0, s16 arg1);
void initSandshrew(MiniActor* sandshrew, s32 player);
void initSandshrews(void);
void miniSandshewReangle(MiniActor* sandshrew);
void miniSandshewReangleAll(void);
void miniSandshewChangeAnim(MiniActor* actor, s32 animID);
void sandshrewDecreaseVel(MiniActor* arg0, f32 arg1);
void sandshrewChangeState(MiniActor* sandshrew, s32 arg1);
void sandshrewHumanControls(MiniActor* sandshrew);
void sandshrewCompControls(MiniActor* arg0);
void func_86F00920(MiniActor* sandshrew);
void func_86F00D04(void);
void initSandshrewHole(MiniActor* a0, s32 arg1);
void initSandshrewHoles(void);
void func_86F00F68(MiniActor* sandshrewHole, MiniActor* sandshrewPlayer);
void func_86F01014(void);
void initSandshrewWaterGeiser(MiniActor* arg0, s32 arg1);
void initSandshrewGeisers(void);
void func_86F011E8(MiniActor* geiser);
void func_86F012B8(void);
void func_86F0132C(void);
void func_86F013B8(void);
void func_86F01488(void);
void sandshrewMinigameInitObjects(void);
s32 func_86F014F8(void);
void func_86F0164C(void);
s32 func_86F016D8(void);
void func_86F0174C(void);
void func_86F018E4(void);
void func_86F01904(void);
void func_86F01C40(void);
void fixSandshrewMinigameHUD(void);
void func_86F01EB4(void);
void func_86F01EF4(s32 arg0);
void func_86F01F58(s32 arg0);
void sandshrewMinigameInit(void);
void func_86F0204C(void);
void func_86F02230(void);
void func_86F02320(void);
s32 sandshrewMinigameLoad(s32 arg0, UNUSED s32 arg1);

#endif // _FRAGMENT21_H_
