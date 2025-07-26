#ifndef _FRAGMENT18_H_
#define _FRAGMENT18_H_

#include "global.h"
#include "src/fragments/3/fragment3.h"

s32 func_86C00020(MiniActor* arg0);
void func_86C00090(s16 arg0, s32* arg1, s32* arg2);
void func_86C00110(s16 arg0, s16 arg1);
void func_86C00368(s16 arg0, s16 arg1);
void func_86C003AC(MiniActor* arg0);
void initEkans(MiniActor* ekans, s16 player);
void initEkanses(void);
f32 func_86C0063C(MiniActor* arg0);
s16 func_86C00668(MiniActor* arg0, s16 arg1);
void humanEkansControls(MiniActor* arg0);
void func_86C00AA4(void);
s32 func_86C00B0C(MiniActor* arg0);
s16 func_86C00BB4(void);
s16 func_86C00C40(MiniActor* arg0);
s16 func_86C00D50(MiniActor* arg0);
s32 func_86C00EF8(MiniActor* arg0);
void func_86C00F70(MiniActor* arg0);
void func_86C01100(MiniActor* arg0);
s16 func_86C01408(void);
s16 func_86C014A0(void);
void compEkansControls(MiniActor* arg0);
void func_86C016C8(MiniActor* arg0);
void func_86C01748(void);
void ekansFixDirToDiglett(MiniActor* arg0, s32 arg1, s32 arg2, f32 arg3, f32 arg4, f32 arg5);
void checkCollitionWithDigletts(MiniActor* arg0, s32 arg1);
void func_86C01AF8(void);
void func_86C01D2C(MiniActor* arg0, s32 arg1);
void func_86C01FAC(MiniActor* arg0, s32 arg1);
void func_86C021FC(MiniActor* arg0);
void anyEkansControls(MiniActor* arg0);
void func_86C02324(MiniActor* arg0, s32 arg1);
void func_86C0250C(void);
void miniEkansPhysics(void);
void initDiglett(MiniActor* diglett, s32 arg1);
void initDiglettHole(MiniActor* arg0, s32 arg1);
void func_86C0276C(void);
void func_86C027A4(void);
void func_86C027AC(void);
void func_86C027B4(void);
void func_86C027BC(void);
void initDigletts(void);
s16 func_86C028C0(s16 arg0);
void func_86C02A1C(MiniActor* arg0);
void func_86C02B78(MiniActor* arg0, s32 arg1);
void func_86C02C28(void);
void func_86C03008(void);
void ekansMinigameInitObjects(void);
s32 func_86C030EC(void);
void func_86C03128(void);
s32 func_86C031E4(void);
s32 func_86C03258(void);
void miniEkansStateMachine(void);
void func_86C034F8(void);
void func_86C03500(void);
void func_86C035E0(void);
void func_86C03608(void);
void func_86C03AB8(void);
void miniEkansDrawCountdown(void);
void fixSkansMinigameHUD(void);
void func_86C03E4C(void);
void func_86C03E8C(s32 arg0);
void func_86C03ED4(void);
void func_86C040B4(s32 arg0);
void initEkansMinigameAssets(void);
void showTutorialScreenEkansMinigame(void);
void ekansMinigameUpdate(void);
void func_86C044B4(void);
s32 ekansMinigameLoad(s32 arg0, UNUSED s32 arg1);

#endif // _FRAGMENT18_H_
