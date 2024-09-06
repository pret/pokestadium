#ifndef _VARIABLES_H_
#define _VARIABLES_H_

#include "global.h"

// thread pris
#define THREAD_PRI_IDLE_INIT 100
#define THREAD_PRI_RESET 30

// thread IDs
#define THREAD_ID_IDLE 1
#define THREAD_ID_RESET 21

#define POOL_END_4MB 0x80400000
#define POOL_END_6MB 0x80600000

// game states
#define STATE_N64_LOGO_INTRO        0x01 // N64 Logo + Intro
#define STATE_TITLE_SCREEN          0x02 // Title screen
#define STATE_N64DD_BOOT_UNUSED     0x03 // seems to be unused, but boots an N64DD disk. Leftover from JP.
#define STATE_MENU_SELECT           0x04 // Menu Select (select Battle Now!, POKeMON Stadium, etc)
#define STATE_AREA_SELECT           0x10 // Area Select (select Stadium, GB Tower, Gym Leader Castle, etc)
#define STATE_GALLERY               0x11 // Gallery
#define STATE_EVENT_BATTLE          0x12 // Event Battle
#define STATE_OPTIONS               0x13 // Options
#define STATE_FAST_N64_LOGO         0x40 // N64 Logo but no Intro. The Sticker Station might use this for booting quickly and into Gallery mode.
#define STATE_STADIUM_MENU          0x20 // POKeMON Stadium (the main Stadium mode) 
#define STATE_FREE_BATTLE           0x21 // Free Battle
#define STATE_VS_MEWTWO             0x22 // VS Mewtwo
#define STATE_KIDS_CLUB             0x23 // Kids Club
#define STATE_VICTORY_PALACE        0x24 // Victory Palace
#define STATE_POKEMON_LAB           0x25 // POKeMON Lab
#define STATE_GB_TOWER              0x26 // GB Tower
#define STATE_GYM_LEADER_CASTLE     0x27 // Gym Leader Castle
#define STATE_BATTLE_NOW_1P         0x28 // Battle Now! (1P)
#define STATE_BATTLE_NOW_2P         0x29 // Battle Now! (2P)
#define STATE_BATTLE_FROM_EVENT     0x2A // Battle menu from Event Battle
#define STATE_STUBBED_DEBUG         0x80 // stubbed/removed debug menu. This could have been the Early Pokedex Menu seen in the JP version.
#define STATE_FAST_BATTLE           0x81 // most likely the P97/P98 mode(s) and uses GB Pak 1 and 2 for the teams for an immediate battle; skips even the VS screen and Battle Rule screen. However, the music/stadium used is probably set by some other menu, because it seems to use the outdoor Free Battle area + Poke Cup 1-3, which isnt correct.
#define STATE_KIDS_CLUB_TITLE       0x82 // Kids Club, but it returns to the title screen. Possibly for a Kiosk/demo version.

/*
 * Dynamic heap with an indetermate amount of space. This pool can either end at 4MB or
 * 6MB depending on osMemSize, which is really strange as it should be using the whole
 * 8MB of the expansion pak.
 */
extern u8 gPool[1];

extern Gfx* gDisplayListHead;

extern u32 D_1000000;
extern u32 D_3000000;
extern u32 D_4000000;
extern u32 D_4000008;
extern u32 D_4000810;
extern u32 D_4001018;
extern u32 D_4001820;
extern u32 D_5000000;
extern u32 D_6000000;
extern u32 D_81000000;
extern u32 D_8D000000;

typedef struct unk_D_80068BA0 {
    /* 0x00 */ char pad00[0x2];
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ u16 unk_08;
    /* 0x0A */ char pad0A[0x2];
} unk_D_80068BA0; // size >= 0xC

extern unk_D_80068BA0* D_80068BA0;
extern unk_D_80068BA0* D_80068BA4;
extern unk_D_80068BA0* D_80068BA8;
extern unk_D_80068BA0* D_80068BAC;
extern Gfx D_8006F518[];
extern Gfx D_8006F630[];

typedef struct unk_D_800A7450 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ void* unk_0C;
} unk_D_800A7450; // size >= 0x10
extern unk_D_800A7450 D_800A7450;

extern Mtx D_800A7468;
extern s32 gShowCPUProfiler;
extern s32 gShowMEMProfiler;


typedef struct unk_func_80007444 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s8 unk_0C;
    /* 0x0D */ s8 unk_0D;
    /* 0x0E */ s8 unk_0E;
    /* 0x0F */ s8 unk_0F;
    /* 0x10 */ s8 unk_10;
    /* 0x11 */ u8 unk_11;
    /* 0x12 */ u8 unk_12;
    /* 0x13 */ u8 unk_13;
    /* 0x14 */ u16 unk_14;
    /* 0x16 */ s8 unk_16;
    /* 0x18 */ void* unk_18[3];
} unk_func_80007444; // size = 0x24
extern unk_func_80007444* D_800A7464;

extern Gfx* D_800A74B0;

typedef struct unk_D_800A7440 {
	/* 0x00 */ s16 x1;
	/* 0x02 */ s16 y1;
	/* 0x04 */ s16 x2;
	/* 0x06 */ s16 y2;
} unk_D_800A7440; // size >= 0x8
extern unk_D_800A7440 D_800A7440;

extern struct unk_D_86002F58_004_000_000 D_800AC840;
extern struct unk_D_86002F58_004_000_000 D_800AC858;
extern struct unk_D_86002F58_004_000* D_8006F09C;

extern struct Vec3f D_8006F050;
extern struct Vec3s D_8006F05C;
extern struct Vec3f D_8006F064;

typedef struct unk_D_8006FF00 {
	/* 0x00 */ char unk_00[0x10];
	/* 0x10 */ s16 unk_10;
	/* 0x12 */ s16 unk_12;
	/* 0x14 */ char unk_14[0x8];
} unk_D_8006FF00; // size = 0x1C
extern unk_D_8006FF00 D_8006FF00[];

typedef struct unk_D_800AC870_sub {
	/* 0x00 */ s16 unk_00;
	/* 0x02 */ s16 unk_02;
	/* 0x04 */ u8* unk_04;
	/* 0x08 */ u8* unk_08;
} unk_D_800AC870_sub; // size = 0xC

typedef struct unk_D_800AC870 {
    /* 0x00 */ unk_D_800AC870_sub unk_00[6];
    /* 0x48 */ void* unk_48;
    /* 0x4C */ s32 unk_4C;
    /* 0x50 */ u8 unk_50;
    /* 0x51 */ s8 unk_51;
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ u8 unk_53;
} unk_D_800AC870; // size = 0x54
extern unk_D_800AC870* D_800AC870;

extern Gfx D_8006F498[];

extern f32 D_80077DD4;
extern f32 D_80077DD8;
extern f32 D_80077DDC;
extern f32 D_80077DE0;
extern s8 D_80077DE4;
extern s32 D_80078E60;
extern s32 D_80078E64;
extern s32 D_80078E68;
extern u8 D_8007840C;
extern s32 D_80078E70;
extern s32 D_80078ECC;
extern u8 D_80078ED0;
extern u8 D_80078390[];
extern u32 D_80078404;
extern s32 D_80078408;
extern s32 D_80078E74;
extern u8 D_80078E78;
extern u8 D_80078E7C;
extern u8 D_80078E80;
extern s32 D_80078EC8;
extern s32 D_800FC680;
extern s32 D_800FC684;
extern u32 D_800FC6DC;
extern s32 D_80078ED4;
extern s32 D_80078ED8;
extern s32 D_80078EDC;

typedef struct unk_D_800FC6E4 {
	/* 0x00 */ char pad00[0x8];
	/* 0x08 */ s32 unk_08;
	/* 0x0C */ u32 unk_0C[2];
} unk_D_800FC6E4; // size >= 0x10

extern unk_D_800FC6E4* D_800FC6E0;
extern unk_D_800FC6E4* D_800FC6E4;

extern s32 D_800FC688;
extern s32 D_800FC68C;
extern s32 D_800FC6A4;
extern s32 D_800FC6A8;

typedef struct unk_D_800FC6F4 {
    /* 0x00 */ char pad00[0x14];
    /* 0x14 */ u32 unk_14;
    /* 0x18 */ char pad18[0x4];
    /* 0x1C */ u32 unk_1C;
    /* 0x20 */ char pad20[0x4];
    /* 0x24 */ u32 unk_24;
} unk_D_800FC6F4; /// size >= 0x28
extern unk_D_800FC6F4* D_800FC6F4;

typedef struct unk_D_800FC6F8 {
    /* 0x00 */ u32 unk_00[2];
} unk_D_800FC6F8; // size = 0x8
extern unk_D_800FC6F8* D_800FC6F8;

typedef struct unk_D_800FC798 {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ u32 unk_04;
    /* 0x08 */ u32 unk_08;
} unk_D_800FC798; // size >= 0xC
extern unk_D_800FC798* D_800FC798;

typedef struct unk_D_800A6CF4 {
    /* 0x00 */ char unk00[0x20];
    /* 0x20 */ s32 unk_20;
} unk_D_800A6CF4; // size = 0x24
extern unk_D_800A6CF4 D_800A6CF4;

extern Mtx D_8006F010;
extern u32 D_3010000;
extern u32 D_3016E80;
extern u32 D_30200C0;
extern u32 D_3004000;
extern u32 D_3008000;
extern u32 D_300C000;
extern u32 D_1003E78[];
extern u32 D_304F120[];
extern u16 D_87B000C0;
extern u16 D_87B000C4;
extern u8 D_87B000C8;
extern u8 D_87B000CC;
extern u8 D_87B000D0;
extern u8 D_87B000D4;

extern s32 gCurrentGameState;
extern s32 gLastGameState;
extern s8 D_800AF732;

#endif
