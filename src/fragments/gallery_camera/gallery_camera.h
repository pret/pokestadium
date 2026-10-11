#ifndef _FRAGMENT15_H_
#define _FRAGMENT15_H_

#include "global.h"
#include "src/controller.h"
#include "src/model_renderer.h"

typedef struct unk_D_8690B2F8 {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
} unk_D_8690B2F8; // size >= 0x10

typedef struct unk_D_8690A710 {
    /* 0x000 */ char unk000[0x4];
    /* 0x004 */ f32 unk_004;
    /* 0x008 */ f32 unk_008;
    /* 0x00C */ s32 unk_00C;
    /* 0x010 */ char unk010[0x4];
    /* 0x014 */ u8 unk_014;
    /* 0x015 */ char unk015[0x16F];
} unk_D_8690A710; // size = 0x184

typedef struct unk_D_8690B350 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
} unk_D_8690B350; // size = 0x10

typedef struct unk_D_8690B360 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
} unk_D_8690B360; // size = 0x18

typedef struct unk_D_8690B308 {
    /* 0x00 */ s16 unk_00[8];
    /* 0x18 */ f32 unk_10;
    /* 0x1C */ f32 unk_14;
    /* 0x20 */ f32 unk_18;
    /* 0x24 */ f32 unk_1C;
    /* 0x28 */ f32 unk_20;
    /* 0x2C */ f32 unk_24;
    /* 0x30 */ f32 unk_28;
    /* 0x34 */ f32 unk_2C;
    /* 0x38 */ s16 unk_30;
    /* 0x3A */ s16 unk_32;
    /* 0x3C */ s16 unk_34;
    /* 0x3E */ s16 unk_36;
} unk_D_8690B308; // size >= 0x38

typedef struct unk_D_8690B3C0 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
} unk_D_8690B3C0; // size >= 0x10

extern u8 D_5001950[];
extern u8 D_5003AE8[];

extern Vec3f D_86908C20;
extern Vec3f D_86908C2C;
extern Vec3f D_86908C38;
extern Vec3f D_86908C44;
extern char* D_86908C58[];
extern Color_RGB8 D_86908C98;
extern Color_RGB8 D_86908C9C;

extern const char D_8690A520[];
extern const char D_8690A52C[];
extern const char D_8690A538[];
extern const char D_8690A544[];
extern const char D_8690A550[];
extern const char D_8690A55C[];
extern const char D_8690A568[];
extern const char D_8690A574[];
extern const char D_8690A584[];
extern const char D_8690A594[];
extern const char D_8690A5A0[];
extern const char D_8690A5AC[];
extern const char D_8690A5B8[];
extern const char D_8690A5C8[];
extern const char D_8690A5D8[];
extern const char D_8690A5E8[];

extern char** gCameraHelpText;
extern f32 D_8690A708;
extern unk_D_8690A710* D_8690A710;
extern unk_D_8690B2F8 D_8690B2F8;
extern unk_D_8690B308 D_8690B308;
extern s32 D_8690B344;
extern s32 D_8690B348;
extern unk_D_8690B350 D_8690B350;
extern unk_D_8690B360 D_8690B360;

extern s32 D_8690B384;
extern s32 D_8690B388;
extern s32 D_8690B380;
extern s32 D_8690B38C;
extern Controller D_8690B390;
extern unk_D_8690B3C0 D_8690B3C0;
extern s8 D_8690B3D0[255];

s32 GalleryCamera_BgAngleCallbackA(s32 arg0, GraphNode* arg1);
s32 GalleryCamera_BgAngleCallbackB(s32 arg0, GraphNode* arg1);
s32 GalleryCamera_FogColorCallback(s32 arg0, GraphNode* arg1);
void Gallery_SetBackgroundTint(u8 arg0, u8 arg1, u8 arg2);
void Gallery_LoadPhotoTextures(void);
ModelLoadResult* Gallery_LoadSurfingPikachuIcon(BattleMon* arg0);
void Gallery_SetupPhotoModel(void);
void Gallery_FinalizeBackgroundLoad(void);
void Gallery_LoadBackgroundSet(s32 arg0);
void Gallery_InitBackgroundScene(void);
void GalleryCamera_ComputeFrameCornerPos(f32* arg0, f32* arg1, s16* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, s16 arg7);
void GalleryCamera_InitIntroSequence(void);
void GalleryCamera_CopyControllerState(Controller* arg0, Controller* arg1);
void func_86900A14(void);
void GalleryCamera_AddPolarOffset(f32* arg0, f32* arg1, s16 arg2, s16 arg3);
void Gallery_CameraReadInput(void);
void GalleryCamera_UpdatePokemonIdleAnim(void);
void GalleryCamera_UpdatePokemonEventLoop(void);
void GalleryCamera_ClearFinishedEventTrack(void);
void Gallery_CapturePhoto(void);
void Gallery_SwitchBackgroundSet(u16 arg0);
s32 Gallery_HandleBackgroundSwitchInput(void);
void Gallery_CameraUpdateTutorialText(void);
s32 Gallery_CameraExitState_Active(void);
s32 Gallery_CameraExitState_CountDown(void);
s32 Gallery_CameraExitState_SpinOut(void);
s32 Gallery_CameraExitState_ExpandBox(void);
s32 Gallery_CameraExitState_FadeOut(void);
s32 Gallery_CameraCheckExit(void);
void Gallery_CameraDraw(void);
void Gallery_CameraIntro(void);
void Gallery_CameraLoop(void);
void Gallery_CameraOutro(void);
void Gallery_CameraInit(s32 arg0);
s32 Gallery_CameraMain(s32 arg0, UNUSED s32 arg1);

f32 GalleryCamera_Distance3D(Vec3f arg0, Vec3f arg1);
f32 GalleryCamera_ComputeZoomDistance(f32 arg0);
f32 GalleryCamera_DistanceXZ(Vec3f arg0, Vec3f arg1);
void func_8690232C(void);
void GalleryCamera_InitFreeView(void);
void GalleryCamera_DebugAdjustZoomOffset(void);
void GalleryCamera_ResetFreeView(void);
s32 GalleryCamera_UpdateZoomFov(void);
void GalleryCamera_RotateVecByMatrix(Vec3f* arg0, MtxF* arg1);
void GalleryCamera_OrbitAtPoint(s16 arg0);
void GalleryCamera_HandleDPadInput(void);
void GalleryCamera_ClampToBoundaryCircle(Vec3f* arg0, Vec3f* arg1, Vec3f arg2, f32 arg3, s32 arg4);
void GalleryCamera_ClampAtToBoundaryCircle(Vec3f* arg0, Vec3f* arg1, Vec3f arg2, f32 arg3);
void GalleryCamera_ClampHeight(Vec3f* arg0, Vec3f* arg1, f32 arg2, f32 arg3, s32 arg4);
void GalleryCamera_ClampEyeToPanBounds(Vec3f* arg0, Vec3f* arg1);
void GalleryCamera_ClampOrbitBounds(Vec3f* arg0, Vec3f* arg1, s32 arg2);
void GalleryCamera_HandleFreeMoveInput(void);

void Gallery_DrawNicknameBanner(char*);
void Gallery_DrawBackgroundSelectMenu(s32);
void Gallery_CameraDrawHelpBalloon(void);
void Gallery_DrawPhotoCounterReel(void);
void Gallery_DrawPhotoCounterReelExit(void);
void Gallery_DrawFrameMarkers(void);
void Gallery_DrawTutorialTextBox(void);


#endif // _FRAGMENT15_H_
