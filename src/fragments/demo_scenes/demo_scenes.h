#ifndef _FRAGMENT17_H_
#define _FRAGMENT17_H_

#include "global.h"

typedef struct unk_D_86B0E5D4_04 {
    /* 0x00 */ Vec3f unk_00;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ char unk10[0x2];
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ s16 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ s16 unk_20;
    /* 0x22 */ s16 unk_22;
    /* 0x24 */ char unk24[0x2];
    /* 0x26 */ s16 unk_26;
    /* 0x28 */ s16 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ char unk40[0x4];
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ s32 unk_48;
    /* 0x4C */ s32 unk_4C;
    /* 0x50 */ s32 unk_50;
    /* 0x54 */ char unk54[0x14];
    /* 0x68 */ f32 unk_68;
    /* 0x6C */ f32 unk_6C;
    /* 0x70 */ f32 unk_70;
    /* 0x74 */ f32 unk_74;
} unk_D_86B0E5D4_04; // size >= 0x78

typedef struct unk_D_86B0E5D4 {
    /* 0x00 */ unk_D_86002F34_00C* unk_00;
    /* 0x04 */ unk_D_86B0E5D4_04 unk_04;
} unk_D_86B0E5D4; // size = 0x7C

typedef struct unk_D_86B0C160 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s16 unk_16;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ s16 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
} unk_D_86B0C160; // size = 0x34

typedef struct unk_D_86B0E5F0 {
    /* 0x000 */ unk_D_86002F30* unk_000;
    /* 0x004 */ DisplayObject unk_004;
    /* 0x16C */ s32 unk_16C;
} unk_D_86B0E5F0; // size = 0x170

typedef struct unk_D_86B0C4C8 {
    /* 0x00 */ Vec3f unk_00;
    /* 0x0C */ u8 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ u16 unk_10;
    /* 0x12 */ char unk12[0x2];
} unk_D_86B0C4C8; // size = 0x14

typedef struct unk_D_86B0DAE0_000 {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ u16 unk_08;
    /* 0x0A */ u16 unk_0A;
    /* 0x0C */ u16 unk_0C;
    /* 0x0E */ u16 unk_0E;
    /* 0x10 */ u16 unk_10;
    /* 0x12 */ u16 unk_12;
    /* 0x14 */ u16 unk_14;
    /* 0x16 */ u16 unk_16;
} unk_D_86B0DAE0_000; // size = 0x18

typedef struct unk_D_86B0DAE0 {
    /* 0x00 */ unk_D_86B0DAE0_000 unk_00;
    /* 0x18 */ unk_D_86B0DAE0_000 unk_18;
} unk_D_86B0DAE0; // size = 0x30

typedef struct unk_D_86B0FA78 {
    /* 0x000 */ unk_D_86002F30* unk_000;
    /* 0x004 */ DisplayObject unk_004;
    /* 0x16C */ s32 unk_16C;
    /* 0x170 */ s32 unk_170;
    /* 0x174 */ s32 unk_174;
    /* 0x178 */ s32 unk_178;
    /* 0x17C */ s32 unk_17C;
    /* 0x180 */ s16 unk_180;
} unk_D_86B0FA78; // size = 0x184

typedef struct unk_D_86B0FA50 {
    /* 0x00 */ char unk00[0x80];
    /* 0x80 */ s32 unk_80;
    /* 0x84 */ s32 unk_84;
    /* 0x88 */ s32 unk_88;
    /* 0x8C */ s32 unk_8C;
    /* 0x90 */ s32 unk_90;
    /* 0x94 */ char unk94[0x4];
    /* 0x98 */ f32 unk_98;
    /* 0x9C */ s16 unk_9C;
    /* 0x9E */ s16 unk_9E;
    /* 0xA0 */ s16 unk_A0;
    /* 0xA4 */ f32 unk_A4;
    /* 0xA8 */ f32 unk_A8;
    /* 0xAC */ f32 unk_AC;
    /* 0xB0 */ unk_D_86B0DAE0_000 unk_B0;
} unk_D_86B0FA50; // size = 0xC8

typedef struct unk_D_86B0FA7C {
    /* 0x00 */ unk_D_86002F34_00C* unk_00;
    /* 0x04 */ Vec3f unk_04;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ char unk14[0x2];
    /* 0x16 */ s16 unk_16;
    /* 0x18 */ s16 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ s16 unk_24;
    /* 0x26 */ s16 unk_26;
    /* 0x28 */ char unk28[0x2];
    /* 0x2A */ s16 unk_2A;
    /* 0x2C */ s16 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ char unk48[0x34];
} unk_D_86B0FA7C; // size = 0x7C

typedef struct unk_D_86B0C264 {
    /* 0x00 */ Vec3f unk_00;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ u16 unk_10;
    /* 0x10 */ u16 unk_12;
    /* 0x14 */ u16 unk_14;
    /* 0x14 */ u16 unk_16;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
} unk_D_86B0C264; // size = 0x1C

extern unk_D_86B0C160 D_86B0E040[];
extern s32 D_86B0E5DC;
extern char** D_86B0E5E0;
extern unk_D_86B0FA78* D_86B0FA78;
extern unk_D_86B0FA7C* D_86B0FA7C;
extern unk_70D3A0 D_86B10660;

s32 Stage_DispatchDemoScene(UNUSED s32 arg0, UNUSED s32 arg1);

s32 Diorama_LogoRotateColorCallback(s32 arg0, GraphNode* arg1);
s32 Diorama_ScaleRotateCallbackA(s32 arg0, GraphNode* arg1);
s32 Diorama_ScaleRotateCallbackB(s32 arg0, GraphNode* arg1);
s32 Diorama_GroupStateCallback(s32 arg0, GraphNode* arg1);
void Diorama_ClearModelSlots(void);
void Diorama_FreeModelSlots(unk_D_86B0E5F0* arg0);
void Diorama_PushModelPool(void);
void Diorama_InitModelSlot(unk_D_86B0E5F0* arg0, unk_D_86B0C4C8* arg1);
void Diorama_SetModelSlotPosition(unk_D_86B0E5F0* arg0, unk_D_86B0C4C8* arg1);
void Diorama_SetGlowFromGroup(s32 arg0);
void Diorama_LoadModelGroup(s32 arg0);
void Diorama_SwitchModelGroup(s32 arg0);
void Diorama_SetGroupCamera(s32 arg0);
void func_86B00680(void);
void Diorama_LoopIdleAnimations(void);
void Diorama_DrawFadeOverlay(void);
void Diorama_DrawGroupTransitionOverlay(void);
s32 Diorama_SlideModelsForward(s32 arg0);
void Diorama_BeginGroupTransition(void);
void Diorama_FinishSequence(void);
void Diorama_UpdateProximityHighlight(s32 arg0);
void Diorama_ReadControllerInput(void);
void Diorama_InitSceneState(void);
s32 Diorama_UpdateStateMachine(void);
void func_86B01004(void);
void Diorama_RenderFrame(void);
void Diorama_RunLoop(void);
void Diorama_RenderFinalFrame(void);
void Diorama_InitScene(void);
s32 Stage_ShowBootDiorama(void);

u16 MathUtil_RandomU16Range(s32);
Vec3f* Vec3f_Copy(Vec3f*, Vec3f*);
void Math_EaseTowardF(f32*, f32, f32);

u16 Diorama_IsModelInCameraCone(unk_D_86002F34_00C* arg0, DisplayObject* arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5);
void DioramaCamKeyframe_SetAngles(unk_D_86B0E5D4_04* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void DioramaCamKeyframe_SetDistance(unk_D_86B0E5D4_04* arg0, f32 arg1, f32 arg2);
void DioramaCamKeyframe_SetAtAngles(unk_D_86B0E5D4_04* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void DioramaCamKeyframe_SetAtDistance(unk_D_86B0E5D4_04* arg0, f32 arg1, f32 arg2);
void DioramaCamKeyframe_SetTransitionSpeed(unk_D_86B0E5D4_04* arg0, f32 arg1, f32 arg2);
void Diorama_LoadCameraKeyframe(unk_D_86B0C160* arg0, unk_D_86B0E5D4* arg1);
void Diorama_SetCameraToKeyframeStart(unk_D_86B0E5D4_04* arg0, unk_D_86B0E5D4* arg1);
s32 Diorama_UpdateCameraKeyframe(unk_D_86B0E5D4_04* arg0, unk_D_86B0E5D4* arg1);

void Diorama_DrawEndBackgroundTiles(u8*);
void Diorama_DrawFullscreenTexture(u8*, s32, s32, s32, s32, u8, u8);
void Diorama_DrawEndCaption(void);

s32 Completion_LightAngleCallbackA(s32 arg0, GraphNode* arg1);
s32 Completion_LightAngleCallbackB(s32 arg0, GraphNode* arg1);
void Completion_SelectBonusPokemon(void);
void Completion_LoadModels(void);
void Completion_ResetSceneStep(void);
void Completion_ResetDialogToIdle(void);
void Completion_PositionBonusModel(void);
void Completion_InitDialogBoxParams(void);
void Completion_InitCamera(void);
s32 Completion_WrapDialogText(void);
void Completion_DrawSpeciesRewardText(s16 arg0, s16 arg1);
void Completion_DrawWrappedDialogText(s16 arg0, s16 arg1);
void Completion_ResetDialogText(void);
void Completion_DrawDialogBox(void);
void Completion_UpdateGiftDialogFirstTime(void);
void Completion_UpdateGiftDialogWithExisting(void);
void Completion_DrawLogoBanner(void);
s32 Completion_AnimateLogoBannerColor(void);
Gfx* Completion_DrawBlinkingCursorIcon(void);
s32 Completion_SlideLogoBannerIn(void);
s32 Completion_SlideLogoBannerOut(void);
s32 Completion_MoveCameraToFront(void);
void Completion_StartGiftDialog(void);
void Completion_AbortDialogToIdle(void);
void Completion_HandleAcceptDeclineInput(void);
void Completion_HandleContinuePrompt(void);
void Completion_UpdateCryEventTrack(void);
void Completion_LoopBonusModelIdleAnim(void);
void Completion_ClampAnimTimer(void);
void Completion_ReadControllerInput(void);
s32 Completion_UpdateSceneSteps(void);
void Completion_DrawDialog(void);
void Completion_RenderFrame(UNUSED s32 arg0);
void Completion_FadeIn(void);
void Completion_RunLoop(void);
void Completion_FadeOutAndSave(void);
void Completion_InitScene(void);
s32 Stage_ShowCompletionScene(void);

void UI_DrawSplitGradientPanel(u8* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 width, u8 height, u8 uls, u8 ult, u8 lrs, u8 lrt, u8 argB, u8 argC, unk_D_86B0DAE0* argD, s32 argE);
void UI_DrawAlphaQuad(s32, s32, s32, s32, s32);

s32 Intro_LightAngleCallbackA(s32 arg0, GraphNode* arg1);
s32 Intro_LightAngleCallbackB(s32 arg0, GraphNode* arg1);
s32 Intro_FogColorCallback(s32 arg0, GraphNode* arg1);
void Intro_SetBackgroundTint(u8 arg0, u8 arg1, u8 arg2);
void Intro_LoadPokemonTextures(void);
void Intro_LoadShowcaseModel(void);
void Intro_ReplaceShowcaseModel(void);
void Intro_SetupOrbitCamera(void);
void Intro_LoadStageModel(void);
void Intro_SetupStaticCamera(void);
s32 Intro_StepRotationOvershoot(DisplayObject* arg0, s16 arg1, s16 arg2);
s32 Intro_StepRotationToTarget(DisplayObject* arg0, s16 arg1, s16 arg2);
s32 Intro_UpdateModelLanding(void);
void Intro_EmitLandingParticles(void);
void Intro_FadeInBackgroundTint(void);
void Intro_UpdateCryEventTrack(void);
void Intro_SetupTextPanel(unk_D_86B0FA50* arg0, u8* arg1, f32 arg2, s16 arg3, s16 arg4, s16 arg5);
void Intro_ConfigureTextPanels(void);
void Intro_StartFirstShowcase(void);
void Intro_BeginOrbitCamera(void);
void Intro_StartFinalStageModel(void);
void Intro_BeginStaticCamera(void);
void Intro_TriggerTextPanelExit(void);
void Intro_SelectPartyRoster(void);
void Intro_ReadControllerInput(void);
s32 Intro_UpdateShowcaseSequence(void);
s32 Intro_StepPanelBounce(unk_D_86B0FA50* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
void Intro_DrawTextPanels(void);
void Intro_RenderFrame(void);
void Intro_RenderBlackFrame(void);
void Intro_FadeInSequence(void);
void Intro_RunLoop(void);
void Intro_FadeOutSequence(void);
void Stage_LoadModels(void);
s32 Stage_ShowIntro(void);

s16 Intro_GetTrackedModelFacingOffset(void);
s32 Util_ByteInArray(u8 arg0, u8* arg1, s32 arg2);
void Intro_ComputeFollowPoint(unk_D_86B0FA78* arg0, Vec3f* arg1);
void Intro_UpdateOrbitCamera(void);
f32 Intro_ClampOrbitDistance(f32 arg0, f32 arg1);
void IntroCamKeyframe_SetAngles(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void IntroCamKeyframe_SetDistance(f32 arg0, f32 arg1);
void IntroCamKeyframe_SetAtAngles(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void IntroCamKeyframe_SetAtDistance(f32 arg0, f32 arg1);
void IntroCamKeyframe_SetTransitionSpeed(f32 arg0, f32 arg1);
void Intro_LoadCameraKeyframe(unk_D_86B0C160* arg0, unk_D_86002F34_00C* arg1);
s32 Intro_UpdateCameraKeyframe(unk_D_86002F34_00C* arg0);

void WipeTransition_Start(s32 arg0, s32 arg1);
s32 WipeTransition_GetState(void);
void WipeTransition_Update(void);
Gfx* WipeTransition_BuildBrickDisplayList(Gfx* gfx, u32 arg1);
void WipeTransition_Draw(void);
void UI_DrawClippedTextureRect(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7);
void UI_DrawTiledTexture(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8* arg4, UNUSED s32 arg5);
void UI_DrawGradientTexture(u8* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, unk_D_86B0DAE0_000* arg5);
void UI_DrawTextureRgba16(u8* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);

void MewtwoIntro_DrawOverlay(void);
void MewtwoIntro_InitCamera(void);
void MewtwoIntro_ReadControllerInput(void);
void MewtwoIntro_DrawBackgroundTiles(u8* arg0);
void MewtwoIntro_RenderFrame(void);
s32 MewtwoIntro_UpdateFade(void);
void MewtwoIntro_RunLoop(void);
void MewtwoIntro_InitScene(void);
s32 Stage_ShowMewtwoIntro(void);

void FirstClearBonus_InitCamera(void);
void FirstClearBonus_InitState(void);
void func_86B0A81C(void);
void FirstClearBonus_DrawDialogFrame(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7);
void FirstClearBonus_ShowDialogBox(void);
void FirstClearBonus_HideDialogBox(void);
s32 FirstClearBonus_RevealNextChar(void);
void FirstClearBonus_DrawDialogBox(void);
void FirstClearBonus_DrawDialogText(void);
void FirstClearBonus_UpdateDialogSequence(void);
void FirstClearBonus_ReadControllerInput(void);
void func_86B0B4C8(void);
void FirstClearBonus_DrawBackgroundTiles(u8* arg0);
void FirstClearBonus_RenderFrame(void);
s32 FirstClearBonus_UpdateScene(void);
void FirstClearBonus_RunLoop(void);
void FirstClearBonus_InitScene(void);
s32 Stage_ShowFirstClearBonusScene(void);

#endif // _FRAGMENT17_H_
