#ifndef _FRAGMENT3_H_
#define _FRAGMENT3_H_

#include "global.h"
#include "src/fragments/34/fragment34.h"
#include "src/3FB0.h"
#include "src/controller.h"

typedef struct MiniActor {
    /* 0x000 */ unk_D_86002F58_004_000 unk_000;		// collider ? model ?
    /* 0x168 */ unk_D_86002F30* unk_168;
    /* 0x16C */ Vec3f scale;
    /* 0x178 */ char unk178[0x18];	//	unused
    /* 0x190 */ Vec3f totalPos;		//	all positions
    /* 0x19C */ Vec3f totalPos_alt;	//	all positions + height/2
    /* 0x1A8 */ Vec3f position_1;
    /* 0x1B4 */ Vec3f closestDiglettPos;//				**	ekans only
    /* 0x1C0 */ Vec3f position_2;
    /* 0x1CC */ f32 dist2DiglettLevelX;	//	1,2,4
    /* 0x1D0 */ f32 dist2DiglettLevelY;	//	unused
    /* 0x1D4 */ f32 dist2DiglettLevelZ;	//	1,2,4
    /* 0x1D8 */ Vec3f unk_1D8;		//	also position, unused
    /* 0x1E4 */ f32 middleHeight;
    /* 0x1E8 */ char unk1E8[0x4];	//	unused ?
    /* 0x1EC */ f32 unk_1EC;		//	always zero
    /* 0x1F0 */ f32 unk_1F0;		//	always zero
    /* 0x1F4 */ f32 unk_1F4;		//	always zero
    /* 0x1F8 */ f32 xSpeed;
    /* 0x1FC */ f32 ySpeed;
    /* 0x200 */ f32 zSpeed;
    /* 0x204 */ f32 xAccel;
    /* 0x208 */ f32 yAccel;
    /* 0x20C */ f32 zAccel;
    /* 0x210 */ f32 antiAcceleration;
    /* 0x214 */ Vec3s totalRot;
    /* 0x21A */ s16 xRot_1;
    /* 0x21C */ s16 yRot_1;
    /* 0x21E */ s16 zRot_1;
    /* 0x220 */ s16 unk_220;		//	x something
    /* 0x222 */ s16 unk_222;		//	y something ; ??? ; stick direction on sandshrew (?)
    /* 0x224 */ s16 unk_224;		//	z something
    /* 0x226 */ s16 xRot_2;
    /* 0x228 */ s16 yRot_2;			//	throwing direction on ekans
    /* 0x22A */ s16 zRot_2;
    /* 0x22C */ s16 unk_22C;		//	zero, x spinning speed ?
    /* 0x22E */ s16 ySpinSpeed;		//  y spinning speed on ekans
    /* 0x230 */ s16 unk_230;		//	zero, z spinning speed ?
    /* 0x232 */ s16 xRot_3;
    /* 0x234 */ s16 yRot_3;
    /* 0x236 */ s16 zRot_3;
    /* 0x238 */ s16 unk_238;		//	always zero
    /* 0x23A */ s16 unk_23A;		//	always zero
    /* 0x23C */ s16 unk_23C;		//	??? some value to send to unk_000->unk_018
    /* 0x23E */ s16 mainState;
    /* 0x240 */ s16 isSquashed;		//	on metapod
    /* 0x242 */ s16 compState;
    /* 0x244 */ s16 unk_244;		//	something metapod comp AI RNG
    /* 0x246 */ char unk246[0x2];	//	unused
    /* 0x248 */ s16 unk_248;		//	animation something 0,1,2
    /* 0x24A */ s16 unk_24A;		//	animation id or state?
    /* 0x24C */ s16 unk_24C;		//	texture animation ?
    /* 0x24E */ char unk24E[0x6];	//	unused
    /* 0x254 */ s32 unk_254;		//	always zero
    /* 0x258 */ s16 miniHealth;
    /* 0x25A */ s16 damageTimer;	//	** metapod only
    /* 0x25C */ s16 miniMaxHealth;	//	400 instead of 100 on metapod
    /* 0x25E */ s16 ekansAbbleToHoop;							//		**	ekans only
    /* 0x260 */ s16 midAirState;	//  mid air state, ekanses and falling rocks
    /* 0x262 */ s16 ekansIsMidAir;	//	ekans is in mid air				**	ekans only
    /* 0x264 */ s16 unk_264;        //  always zero
    /* 0x266 */ s16 collidingActorId;
    /* 0x268 */ s16 collidingActorId_alt;							//	**	ekans only
    /* 0x26A */ s16 unk_26A;        //	some flag related to collisions
    /* 0x26C */ s16 unk_26C;        //	animation something
    /* 0x26E */ s16 unk_26E;		//	animation something
    /* 0x270 */ s16 unk_270;		//	???								**	metapod only
    /* 0x272 */ s16 unk_272;        //  colliding with a rock on metapod's minigame ? ;
    /* 0x274 */ union{
    			f32 unk_274;
    			f32 diggingSpeed;
    			f32 launchForce;
    		};
    /* 0x278 */ char unk278[0x4];	//	unused
    /* 0x27C */ f32 diggingAccel2;	//
    /* 0x280 */ union {
    			f32 unk_280;
    			f32 stickMagnitude1;
    			f32 diggingAccel1;
    		};
    /* 0x284 */ f32 stickMagnitude2;    //	launch forse on ekans
    /* 0x288 */ f32 cubeRadio;		//	bottom of the hitbox / bounding box ?
    /* 0x28C */ f32 halfHeight;
    /* 0x290 */ s16 unk_290;		//	always zero
    /* 0x292 */ s16 unk_292;		//	always zero
    /* 0x294 */ s16 unk_294;		//	always zero
    /* 0x296 */ s16 unk_296;
    /* 0x298 */ s16 unk_298;		// timer after bouncin on digletts on ekans
    /* 0x29A */ union {
    			s16 unk_29A;
    			s16 sandshrewLastDir;
    			s16 ekansDiglettHitScore;
    			s16 metapodInputLockTimer;
    		};
    /* 0x29C */ s16 diglettIsGold;						//	**	diglett only
    /* 0x29E */ s16 unk_29E;	// something comp AI RNG	maybe timer to launch
    /* 0x2A0 */ union {
    			s16 unk_2A0;
    			s16 leftRightTimer;	//	on sandshrew, 20 to 0
    			s16 leftRightCount;	//	on ekans
    		};
    /* 0x2A2 */ s16 ekansScore;							//	**	ekans only
    /* 0x2A4 */ s16 unk_2A4;
    /* 0x2A6 */ s16 unk_2A6;		//	metapod state ?
    /* 0x2A8 */ s16 isWinner;
    /* 0x2AA */ s16 unk_2AA;
    /* 0x2AC */ s16 isComp;
    /* 0x2AE */ s16 unk_2AE;		//	???					**	metapod only
    /* 0x2B0 */ s16 sandshrewFailChances;	//	3,2,1,0		**	sandsrew only
    /* 0x2B2 */ s16 unk_2B2;
} MiniActor; // size = 0x2B4

// Possibly unk_D_86002F34_alt7, unk_D_86002F34_alt8, 
// unk_D_86002F34_alt9 or unk_D_86002F34_alt2
typedef struct arg1_func_87902F80 {
    /* 0x00 */ struct GraphNode unk_00;
    /* 0x18 */ Gfx* unk_18;
} arg1_func_87902F80; // size >= 0x1C

typedef struct unk_D_87903E00 {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ void* unk_04;
    /* 0x08 */ void* unk_08;
    /* 0x0C */ u32* unk_0C;
} unk_D_87903E00; // size = 0x10

typedef struct unk_D_87903E10 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ unk_D_87903E00* unk_04;
} unk_D_87903E10; // size = 0x8

extern s16 minigameState;
extern s16 minigameInputLock;
extern s16 D_87903DA8;
extern s16 D_87903DAC;
extern s16 D_87903DBC;
extern s16 D_87903DC0;
extern s16 miniTutoScreenState;
extern s16 D_87903DC8;
extern s16 D_87903DCC;
extern s16 D_87903DD0;
extern s16 D_87903DD4;

extern unk_D_87903E10 D_87903E10;
extern unk_D_87903E10 D_87903E28;
extern unk_D_87903E10 D_87903E40;
extern unk_D_87903E10 D_87903E58;
extern s16 miniInputLockTimer;
extern s16 D_87906042;
extern s16 miniShowHUB;
extern s16 miniDifficulty;
extern s16 D_87906048;
extern s16 D_8790604A;
extern unk_D_86002F34_00C* D_87906050;      // geo layout
extern unk_D_86002F34_00C* D_87906054;
extern s16 miniCameraXRot;
extern s16 miniCameraYRot;
extern s16 miniCameraDistance;
extern s16 miniCameraFov;
extern s16 miniCameraNear;
extern s16 miniCameraFar;
extern Vec3s miniCameraCoords;
extern s16 D_87906072;
extern s16 D_87906076;
extern s16 D_87906078;
extern f32 D_8790607C;
extern f32 D_87906080;
extern Vec3f D_87906088;
extern s16 D_87906094;
extern s16 D_87906096;
extern s16 D_87906098;
extern s16 D_8790609A;
extern Vec3s D_8790609C;

extern s16 D_879060A2;
extern s16 D_879060A4;
extern s16 D_879060A6;
extern s16 D_879060A8;
extern Vec3s D_879060AC;

extern s16 miniDebugMode;
extern s16 D_87903DB8;
extern Controller* miniControllerPtr;
extern s16 D_879060C0;
extern s16 miniEkansCountdown;
extern s8 D_879060C4[4];
extern s16 miniHudTransparency;
extern s16 D_879060CA;

extern Vec3f D_879060E0;
extern Vec3f D_87906100;
extern Vec3f D_87906110;

ret_func_80004454 func_87900020(void);
float MinigameGetVec3Distance_2d(MiniActor* arg0, MiniActor* arg1);
void MinigameGetVec3Distance_3d(MiniActor* arg0, MiniActor* arg1);
s32 func_879000C4(MiniActor* arg0, MiniActor* arg1);
s32 metapodRockCollisionCheck(MiniActor* arg0, MiniActor* arg1);
void miniChangeActorAnim(MiniActor* arg0, s16 arg1, s16 arg2, s16 arg3);
void miniChangeActorAnim_alt1(MiniActor* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void miniChangeActorAnim_alt2(MiniActor* arg0, s16 arg1, s16 arg2, s16 arg3);
s32 miniPokeIsIdleCheck(MiniActor* arg0);
void func_879003A0(MiniActor* poke);
void func_879004F8(unk_D_86002F58_004_000* arg0);
void func_87900528(void);
void hideMiniGameHUD(void);
void func_87900564(MiniActor* actor);
void minigameActorLocalOriginToZero(MiniActor* arg0);
void func_879005AC(MiniActor* arg0);
void miniEkansUpdatePos(MiniActor* ekans);
void miniActorAllToZero(MiniActor* actor);
void miniActorUpdateTransform(MiniActor* poke);
void func_87900808(MiniActor* arg0);
void func_87900854(void);
void func_87900920(void);
void func_879009B4(void);

void func_87900A50(void);
void miniUpdateCamera(void);
s32 minigameDebuggModeControl(void);
void showDebuggCameraInfo(void);
void showDebuggJoystickInfo(void);
void func_87901200(void);

void func_87901620(void);
s32 func_8790168C(void);
void func_87901720(unk_D_8140E728* arg0);
void func_87901804(s32 arg0, f32 arg1, Vec3f arg2, func_unk_D_8140E724_008 arg3, unk_D_8140E728_01C* arg4, s16 arg5, u8 arg6, u8 arg7);
void func_879018B0(s32 arg0, s32 arg1, s8 arg2, f32 arg3, Vec3f arg4, func_unk_D_8140E724_008 arg7, unk_D_8140E728_01C* arg8, s16 arg9, u8 argA, u8 argB);
void func_87901958(unk_D_8140E720* arg0, unk_D_8140E728* arg1, s16 arg2);
void func_87901A28(unk_D_8140E728* arg0);
void func_87901ADC(unk_D_8140E728* arg0);
void func_87901B08(void);
void func_87901BB0(unk_D_8140E720* arg0);
void func_87901BD4(unk_D_8140E720* arg0);
void func_87901C20(void);
void func_87901C98(void);
void func_87901DA0(unk_D_8140E720* arg0);
void func_87901F04(unk_D_8140E720* arg0);
void func_87901FA0(unk_D_8140E720* arg0);
void func_87902068(unk_D_8140E720* arg0);
void func_8790215C(unk_D_8140E720* arg0);
void func_87902224(unk_D_8140E720* arg0);
void func_87902318(unk_D_8140E720* arg0);
void func_879023EC(unk_D_8140E720* arg0);
void func_879024DC(unk_D_8140E720* arg0);
void func_87902608(unk_D_8140E720* arg0);
void func_879026D8(unk_D_8140E720* arg0);
void func_879027F0(unk_D_8140E720* arg0);
void func_879028E0(unk_D_8140E720* arg0);
void func_879029F0(unk_D_8140E720* arg0);
void func_87902AE0(unk_D_8140E720* arg0);
void func_87902C9C(unk_D_8140E720* arg0);
void func_87902D3C(Gfx* arg0, unk_D_86002F34_000_014* arg1, UNUSED u16 arg2);
void func_87902F80(s32 arg0, arg1_func_87902F80* arg1);
void func_87902FC8(Gfx* arg0, unk_D_86002F34_000_014* arg1, UNUSED u16 arg2);
void func_8790320C(s32 arg0, arg1_func_87902F80* arg1);

void func_87903260(void);
void func_87903294(void);
void func_879032BC(s16 arg0);
void func_87903358(s16 arg0, s16 arg1);
void func_879033FC(MiniActor* arg0);
void func_8790354C(void);

void func_87903600(void);
void func_879036B4(MiniActor* arg0);
void func_8790370C(void);
void func_879037D0(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4, s16 arg5, s16 arg6);
void func_87903838(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4, s16 arg5, s16 arg6);
void func_879038AC(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4, s16 arg5, s16 arg6);
Gfx* func_87903920(Gfx* arg0, arg1_func_87903D64_014* arg1);
void func_87903D64(s32 arg0, arg1_func_87903D64* arg1);

#endif // _FRAGMENT3_H_
