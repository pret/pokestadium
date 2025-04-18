#ifndef _VARIABLES_H_
#define _VARIABLES_H_

#include "global.h"
#include "PR/leo.h"

// thread pris
#define THREAD_PRI_IDLE_INIT 100
#define THREAD_PRI_RESET 30

// thread IDs
#define THREAD_ID_IDLE 1
#define THREAD_ID_RESET 21

#define POOL_END_4MB 0x80400000
#define POOL_END_6MB 0x80600000

// game states
typedef enum {
    STATE_N64_LOGO_INTRO      = 0x01, // N64 Logo + Intro
    STATE_TITLE_SCREEN        = 0x02, // Title screen
    STATE_N64DD_BOOT_UNUSED   = 0x03, // seems to be unused, but boots an N64DD disk. Leftover from JP.
    STATE_MENU_SELECT         = 0x04, // Menu Select (select Battle Now!, POKeMON Stadium, etc)
    STATE_AREA_SELECT         = 0x10, // Area Select (select Stadium, GB Tower, Gym Leader Castle, etc)
    STATE_GALLERY             = 0x11, // Gallery
    STATE_EVENT_BATTLE        = 0x12, // Event Battle
    STATE_OPTIONS             = 0x13, // Options
    STATE_FAST_N64_LOGO       = 0x40, // N64 Logo but no Intro. The Sticker Station might use this for booting quickly and into Gallery mode.
    STATE_STADIUM_MENU        = 0x20, // POKeMON Stadium (the main Stadium mode) 
    STATE_FREE_BATTLE         = 0x21, // Free Battle
    STATE_VS_MEWTWO           = 0x22, // VS Mewtwo
    STATE_KIDS_CLUB           = 0x23, // Kids Club
    STATE_VICTORY_PALACE      = 0x24, // Victory Palace
    STATE_POKEMON_LAB         = 0x25, // POKeMON Lab
    STATE_GB_TOWER            = 0x26, // GB Tower
    STATE_GYM_LEADER_CASTLE   = 0x27, // Gym Leader Castle
    STATE_BATTLE_NOW_1P       = 0x28, // Battle Now! (1P)
    STATE_BATTLE_NOW_2P       = 0x29, // Battle Now! (2P)
    STATE_BATTLE_FROM_EVENT   = 0x2A, // Battle menu from Event Battle
    STATE_STUBBED_DEBUG       = 0x80, // stubbed/removed debug menu. This could have been the Early Pokedex Menu seen in the JP version.
    STATE_FAST_BATTLE         = 0x81, // most likely the P97/P98 mode(s) and uses GB Pak 1 and 2 for the teams for an immediate battle; skips even the VS screen and Battle Rule screen. However, the music/stadium used is probably set by some other menu, because it seems to use the outdoor Free Battle area + Poke Cup 1-3, which isnt correct.
    STATE_KIDS_CLUB_TITLE     = 0x82, // Kids Club, but it returns to the title screen. Possibly for a Kiosk/demo version.
} GameState;

/*
 * Dynamic heap with an indetermate amount of space. This pool can either end at 4MB or
 * 6MB depending on osMemSize, which is really strange as it should be using the whole
 * 8MB of the expansion pak.
 */
extern u8 gPool[];

extern Gfx* gDisplayListHead;
extern u64 _binary_assets_us_F3DEX2_bin_start[];

extern f32 gSineTable[];
extern f32 gCosineTable[0x1000];
extern s16 gArctanTable[0x401];
extern s32 D_B0000504;

extern u8 D_1000000[];
extern u8 D_8000000[];
extern u8 D_81000000[];
extern u8 D_1001800[];
extern Gfx D_1002480[];
extern Gfx D_1002508[];
extern Gfx D_1002590[];
extern u8 D_2000000[];
extern u8 D_3000000[];
extern u8 D_3000000_2[];
extern u8 D_04000000[];
extern u8 D_4000008[];
extern u8 D_4000810[];
extern u8 D_4001018[];
extern u8 D_4001820[];
extern u8 D_5000000[];
extern u8 D_6000000[];
extern u8 D_8D000000[];
extern u8 D_20144E0[];
extern u8 D_3044260[];
extern u8 D_20289E0[];
extern u8 D_2028A20[];
extern u8 D_2028A60[];
extern u8 D_2028AA0[];
extern u32 D_B0000D10;
extern u8 D_400C800[];
extern u8 D_400CA00[];
extern u8 D_400CC00[];
extern u8 D_400CE00[];
extern u8 D_400CF00[];
extern u8 D_400D100[];
extern u8 D_400D200[];
extern u8 D_04000000[];
extern u8 D_04000800[];
extern u8 D_04001000[];
extern u8 D_04001800[];
extern u8 D_04002000[];
extern u8 D_04002800[];
extern u8 D_04003000[];
extern u8 D_04003800[];
extern u8 D_04004000[];
extern u8 D_04005000[];
extern u8 D_04006000[];
extern u8 D_04007000[];
extern u8 D_04008000[];
extern u8 D_04009000[];
extern u8 D_0400A000[];
extern u8 D_0400B000[];
extern u8 D_4006A60[];
extern u8 D_40022E0[];
extern u8 D_4002368[];
extern u8 D_40025F0[];
extern u8 D_4002878[];
extern u8 D_4002B00[];
extern u8 D_4002D88[];
extern u8 D_4003010[];
extern u8 D_4003298[];
extern u8 D_4003520[];
extern u8 D_4001638[];
extern u8 D_4001680[];
extern u8 D_40016C8[];
extern u8 D_4001710[];
extern u8 D_4004A00[];
extern u8 D_4005570[];
extern u8 D_4001010[];
extern u8 D_4001C90[];
extern u8 D_4001FB8[];
extern u8 D_4006AB8[];
extern u8 D_4007750[];
extern u8 D_4007798[];
extern u8 D_40077E0[];
extern u8 D_4007828[];
extern u8 D_4006F40[];
extern u8 D_4006F88[];
extern u8 D_4006FD0[];
extern u8 D_4007018[];
extern u8 D_4007060[];
extern u8 D_40070A8[];
extern u8 D_40070F0[];
extern u8 D_4007138[];
extern u8 D_4007180[];
extern u8 D_40071C8[];
extern u8 D_4007BF0[];
extern u8 D_4007210[];
extern u8 D_4007318[];
extern u8 D_4007420[];
extern u8 D_4007528[];
extern u8 D_4001218[];
extern u8 D_4001320[];
extern u8 D_4001428[];
extern u8 D_4001530[];
extern u8 D_4007630[];
extern u8 D_4007678[];
extern u8 D_40076C0[];
extern u8 D_4007708[];
extern u8 D_4007948[];
extern u8 D_4007978[];
extern u8 D_04005C48[];
extern u8 D_04005F70[];
extern u8 D_04006298[];
extern u8 D_040065C0[];
extern u8 D_40068E8[];
extern u8 D_4006930[];
extern u8 D_4006978[];
extern u8 D_40069C0[];
extern u8 D_4007AD0[];
extern u8 D_4007B18[];
extern u8 D_4007B60[];
extern u8 D_4007BA8[];
extern u8 D_4004448[];
extern u8 D_4004FB8[];
extern u8 D_4003AD0[];
extern u8 D_400D780[];
extern u8 D_400D9C0[];
extern u8 D_4011638[];
extern u8 D_30099B8[];
extern u8 D_4003900[];
extern u8 D_4002900[];
extern u8 D_3001D20[];
extern u8 D_4011BF8[];
extern u8 D_4015080[];
extern u8 D_04017990[];
extern u8 D_0400B3E0[];
extern u8 D_04009040[];
extern u8 D_04006CA0[];
extern u8 D_04004900[];
extern u8 D_03005F80[];
extern u8 D_0400DC00[];
extern u8 D_300BF40[];
extern u8 D_300C140[];
extern u8 D_300C540[];
extern u8 D_300C640[];
extern u8 D_300C740[];
extern u8 D_300C840[];
extern u8 D_3009E38[];
extern u8 D_300AE38[];
extern u8 D_4004848[];
extern u8 D_4004AC8[];
extern u16 D_4004D48[];
extern u8 D_4006748[];
extern u16 D_4005F48[];
extern u8 D_4007048[];
extern u8 D_4003A38[];
extern u8 D_4007448[];
extern u8 D_3004540[];
extern u8 D_3005260[];
extern u8 D_03001000[];
extern u8 D_3001D20[];
extern u8 D_03002A40[];
extern u8 D_03003340[];
extern u8 D_03003C40[];
extern u8 D_300BE40[];
extern u8 D_300BE80[];
extern u8 D_300BEC0[];
extern u8 D_300BF00[];
extern u8 D_300C340[];
extern u8 D_300C3C0[];
extern u8 D_300C440[];
extern u8 D_300C4C0[];
extern u8 D_3028E00[];
extern u8 D_3029A80[];
extern u8 D_302A700[];
extern u8 D_302B380[];
extern u8 D_2000C80[];
extern u8 D_2000D80[];
extern u8 D_2000E80[];
extern u8 D_2000F80[];
extern u8 D_2006C00[];
extern u8 D_2007500[];
extern u8 D_20003C0[];
extern u8 D_20005C0[];
extern u8 D_20002C0[];
extern u8 D_2000300[];
extern u8 D_2000340[];
extern u8 D_2000380[];
extern u8 D_3024C80[];
extern u8 D_30260C0[];
extern u8 D_2000B40[];
extern u8 D_2000B80[];
extern u8 D_2000BC0[];
extern u8 D_2000C00[];
extern u8 D_302C000[];
extern u8 D_20287E0[];
extern u8 D_2028860[];
extern u8 D_20288E0[];
extern u8 D_2028960[];
extern u8 D_302FBC0[];
extern u8 D_30300C0[];
extern u8 D_30242C0[];
extern u8 D_30243A0[];
extern u8 D_302EBC0[];
extern u8 D_201D820[];
extern u8 D_201DB20[];
extern u8 D_201DE20[];
extern u8 D_201E120[];
extern u8 D_201E420[];
extern u8 D_2020420[];
extern u8 D_2022420[];
extern u8 D_2024420[];
extern u8 D_2026420[];
extern u8 D_3006668[];
extern u8 D_3000008[];
extern u8 D_3004EF0[];
extern u8 D_30055B0[];
extern u8 D_3005A18[];
extern u8 D_03000FD0[];
extern u8 D_03001F98[];
extern u8 D_03002F60[];
extern u8 D_03003F28[];
extern u8 D_3006060[];
extern u8 D_3008670[];
extern u8 D_3009678[];
extern u8 D_3012D80[];
extern u8 D_301C488[];
extern u8 D_2002480[];
extern u8 D_2002900[];
extern u8 D_2003900[];
extern u8 D_2004900[];
extern u8 D_2004C00[];
extern u8 D_2005A10[];
extern u8 D_2006820[];
extern u8 D_20068A0[];
extern u8 D_2006920[];
extern u8 D_20069A0[];
extern u8 D_2002000[];
extern u8 D_30C1290[];
extern u8 D_0302EE00[];
extern u8 D_03034580[];
extern u8 D_03039D00[];
extern u8 D_0303F480[];
extern u8 D_03044C00[];
extern u8 D_0304A380[];
extern u8 D_0304FB00[];
extern u8 D_03055280[];
extern u8 D_0305AA00[];
extern u8 D_03060180[];
extern u8 D_03065900[];
extern u8 D_03069528[];
extern u8 D_0306D150[];
extern u8 D_03070D78[];
extern u8 D_030749A0[];
extern u8 D_030785C8[];
extern u8 D_0307C1F0[];
extern u8 D_0307FE18[];
extern u8 D_03083A40[];
extern u8 D_03087668[];
extern u8 D_0300BB80[];
extern u8 D_03017700[];
extern u8 D_3023280[];
extern u8 D_0308B290[];
extern u8 D_0308D290[];
extern u8 D_0308F290[];
extern u8 D_03091290[];
extern u8 D_03093290[];
extern u8 D_03095290[];
extern u8 D_03097290[];
extern u8 D_03099290[];
extern u8 D_0309B290[];
extern u8 D_0309D290[];
extern u8 D_0309F290[];
extern u8 D_030A1290[];
extern u8 D_030A3290[];
extern u8 D_030A5290[];
extern u8 D_030A7290[];
extern u8 D_030A9290[];
extern u8 D_030AB290[];
extern u8 D_030AD290[];
extern u8 D_030AF290[];
extern u8 D_030B1290[];
extern u8 D_030B3290[];
extern u8 D_030B5290[];
extern u8 D_030B7290[];
extern u8 D_030B9290[];
extern u8 D_030BB290[];
extern u8 D_030BD290[];
extern u8 D_030BF290[];
extern u8 D_30CD390[];
extern u8 D_30CD410[];
extern u8 D_30CD490[];
extern u8 D_30CD510[];
extern u8 D_04001878[];
extern u8 D_040018E0[];
extern u8 D_04001948[];
extern u8 D_040019B0[];
extern u8 D_04001A18[];
extern u8 D_04001A80[];
extern u8 D_04001AF0[];
extern u8 D_04001B58[];
extern u8 D_04001BC0[];
extern u8 D_04001C28[];
extern u8 D_4001C90[];
extern u8 D_4001FB8[];
extern u8 D_30015E0[];
extern u8 D_30025E0[];
extern u8 D_3002C00[];
extern u8 D_302F690[];
extern u8 D_302F588[];
extern u8 D_302F5C8[];
extern u8 D_302F608[];
extern u8 D_302F648[];
extern u8 D_30387B0[];
extern u8 D_30387F0[];
extern u8 D_3038830[];
extern u8 D_3038870[];
extern u8 D_302F6E0[];
extern u8 D_302F740[];
extern u8 D_302F7A0[];
extern u8 D_302F800[];
extern u8 D_302F860[];
extern u8 D_302F8C0[];
extern u8 D_302F928[];
extern u8 D_302F988[];
extern u8 D_302F9E8[];
extern u8 D_302FA48[];
extern u8 D_3038C70[];
extern u8 D_3038D70[];
extern u8 D_3038E70[];
extern u8 D_3038F70[];
extern u8 D_3027168[];
extern u8 D_3027EE8[];
extern u8 D_3039070[];
extern u8 D_3039540[];
extern u8 D_3039A10[];
extern u8 D_3039FB0[];
extern u8 D_303A550[];
extern u8 D_303AAF0[];
extern u8 D_303B090[];
extern u8 D_303B630[];
extern u8 D_303BBD0[];
extern u8 D_303C170[];
extern u8 D_303C710[];
extern u8 D_303CCB0[];
extern u8 D_303D250[];
extern u8 D_303D7F0[];
extern u8 D_303DD90[];
extern u8 D_30388B0[];
extern u8 D_3038990[];
extern u8 D_3028C68[];
extern u8 D_3029468[];
extern u8 D_3029C68[];
extern u8 D_302A468[];
extern u8 D_30386B0[];
extern u8 D_30386F0[];
extern u8 D_3038730[];
extern u8 D_3038770[];
extern u8 D_3014468[];
extern u8 D_302DE68[];
extern u8 D_302E418[];
extern u8 D_302E9C8[];
extern u8 D_302EF78[];
extern u8 D_302F528[];
extern u8 D_303E330[];
extern u8 D_303FC30[];
extern u8 D_3040590[];
extern u8 D_3040270[];
extern u8 D_303F910[];
extern u8 D_303F5F0[];
extern u8 D_3040590[];
extern u8 D_303FF50[];
extern u8 D_3040BD0[];
extern u8 D_303E650[];
extern u8 D_303E970[];
extern u8 D_303EFB0[];
extern u8 D_303F2D0[];
extern u8 D_30408B0[];
extern u8 D_303EC90[];
extern u8 D_3040EF0[];
extern u8 D_302F6E0[];
extern u8 D_302F7A0[];
extern u8 D_302F800[];
extern u8 D_302F860[];
extern u8 D_302F8C0[];
extern u8 D_302F928[];
extern u8 D_302F988[];
extern u8 D_302F9E8[];
extern u8 D_302FA48[];
extern u8 D_302FAB0[];
extern u8 D_302FDB0[];
extern u8 D_30300B0[];
extern u8 D_30303B0[];
extern u8 D_302BE68[];
extern u8 D_30306B0[];
extern u8 D_30326B0[];
extern u8 D_30346B0[];
extern u8 D_30366B0[];
extern u8 D_302AC68[];
extern u8 D_302B568[];
extern u8 D_3026168[];
extern u8 D_3026368[];
extern u8 D_3026568[];
extern u8 D_3026768[];
extern u8 D_3026968[];
extern u8 D_3026B68[];
extern u8 D_3026D68[];
extern u8 D_3026F68[];
extern u8 D_300D868[];
extern u8 D_300EA68[];
extern u8 D_300FC68[];
extern u8 D_3010E68[];
extern u8 D_3012068[];
extern u8 D_3013268[];
extern u8 D_3012068[];
extern u8 D_3010E68[];
extern u8 D_300FC68[];
extern u8 D_300EA68[];
extern u8 D_3005D28[];
extern u8 D_300D108[];
extern u8 D_300D278[];
extern u8 D_3006000[];
extern u8 D_3009DC8[];
extern u8 D_300B768[];
extern u8 D_30079A0[];
extern u8 D_3009BC0[];
extern u8 D_30081A8[];
extern u8 D_3038A70[];
extern u8 D_3038AF0[];
extern u8 D_3038B70[];
extern u8 D_3038BF0[];
extern u8 D_4000C00[];
extern u8 D_201A620[];
extern u8 D_2028420[];
extern u8 D_2000C40[];
extern u8 D_2007E00[];
extern u8 D_2008700[];
extern u8 D_2009000[];
extern u8 D_2009900[];
extern u8 D_2001080[];
extern u8 D_2001550[];
extern u8 D_2001A20[];
extern u8 D_2001FC0[];
extern u8 D_2002560[];
extern u8 D_2002B00[];
extern u8 D_20030A0[];
extern u8 D_2003640[];
extern u8 D_2003BE0[];
extern u8 D_2004180[];
extern u8 D_2004720[];
extern u8 D_2004CC0[];
extern u8 D_2005260[];
extern u8 D_2005800[];
extern u8 D_2005DA0[];
extern u8 D_2006340[];
extern u8 D_20007C0[];
extern u8 D_20008A0[];
extern u8 D_200A200[];
extern u8 D_200A280[];
extern u8 D_200A300[];
extern u8 D_200A780[];
extern u8 D_2000980[];
extern u8 D_2000A60[];
extern u8 D_3008200[];
extern u8 D_4000C40[];
extern u8 D_4000DD0[];
extern u8 D_300F780[];
extern u8 D_3024480[];
extern u8 D_30256A0[];
extern u8 D_3026AE0[];
extern u8 D_2016010[];
extern u8 D_300F380[];
extern u8 D_300F400[];
extern u8 D_300F480[];
extern u8 D_300F500[];
extern u8 D_30229A0[];
extern u8 D_30229E0[];
extern u8 D_3022A20[];
extern u8 D_3022A60[];
extern u8 D_30111A0[];
extern u8 D_3017DA0[];
extern u8 D_301E9A0[];
extern u8 D_301F9A0[];
extern u8 D_30209A0[];
extern u8 D_30219A0[];
extern u8 D_30230C0[];
extern u8 D_30239C0[];
extern u8 D_3004E20[];
extern u8 D_3006020[];
extern u8 D_3007220[];
extern u8 D_3008420[];
extern u8 D_3009620[];
extern u8 D_3000FA0[];
extern u8 D_3001F40[];
extern u8 D_3002EE0[];
extern u8 D_3003E80[];
extern u8 D_300A820[];
extern u8 D_300B820[];
extern u8 D_300C820[];
extern u8 D_300D820[];
extern u8 D_300F240[];
extern u8 D_300F280[];
extern u8 D_300F2C0[];
extern u8 D_300F300[];
extern u8 D_300F340[];
extern u8 D_2000040[];
extern u8 D_2000240[];
extern u8 D_300E820[];
extern u8 D_300ED30[];
extern u8 D_300F580[];
extern u8 D_3022AA0[];
extern u8 D_200B3E0[];
extern u8 D_200C380[];
extern u8 D_200D320[];
extern u8 D_3008880[];
extern u8 D_302E440[];
extern u8 D_302E840[];
extern u8 D_3014760[];
extern u8 D_301A760[];
extern u8 D_3020760[];
extern u8 D_03028EC0[];
extern u8 D_03029C40[];
extern u8 D_0302A9C0[];
extern u8 D_0302B740[];
extern u8 D_0302C4C0[];
extern u8 D_0302D480[];
extern u8 D_3024000[];
extern u8 D_3009000[];
extern u8 D_3012000[];
extern u8 D_301B000[];

extern LEODiskID D_800818E0;

extern Gfx D_8006F518[];
extern Gfx D_8006F630[];
extern u8 D_82000000;
extern u8 D_81400000;
extern u8 D_86B00000;
extern u8 D_87800000;
extern u8 D_87900000;
extern u8 D_82100000;
extern u8 D_84300000;
extern u8 D_86200000;
extern u8 D_86800000;
extern u8 D_86C00000;
extern u8 D_87A00000;
extern u8 D_87000000[];

extern u8 D_800AF770[];

typedef struct unk_D_800A7440 {
	/* 0x00 */ s16 x1;
	/* 0x02 */ s16 y1;
	/* 0x04 */ s16 x2;
	/* 0x06 */ s16 y2;
} unk_D_800A7440; // size >= 0x8
extern unk_D_800A7440 D_800A7440;

extern struct unk_D_86002F58_004_000_000 D_800AC840;
extern struct unk_D_86002F58_004_000_000 D_800AC858;

typedef struct unk_D_8006FF00 {
	/* 0x00 */ u8 unk_00;
	/* 0x01 */ u8 unk_01;
	/* 0x02 */ s16 unk_02;
	/* 0x04 */ char* name;
	/* 0x08 */ s32 unk_08;
	/* 0x0C */ u8 unk_0C;
	/* 0x0D */ char unk_0D[0x3];
	/* 0x10 */ s16 unk_10;
	/* 0x12 */ s16 unk_12;
	/* 0x14 */ u32 unk_14;
	/* 0x18 */ char unk_18[0x4];
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
extern s32 D_80078ED4;
extern s32 D_80078ED8;
extern s32 D_80078EDC;

typedef struct unk_D_800A6CF4 {
    /* 0x00 */ char unk00[0x20];
    /* 0x20 */ s32 unk_20;
} unk_D_800A6CF4; // size = 0x24
extern unk_D_800A6CF4 D_800A6CF4;
extern u8 D_15C0000[];

extern Mtx D_8006F010;
extern u32 D_3010000;
extern u32 D_3016E80;
extern u32 D_30200C0;
extern u32 D_3004000;
extern u32 D_3008000;
extern u32 D_300C000;
extern u32 D_1003E78[];
extern u32 D_304F120[];

extern s32 D_800FC820;
extern u8* D_800FF9C0;

typedef struct unk_70D3A0 {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
} unk_70D3A0; // size = 0x10

typedef struct unk_D_70B10 {
    /* 0x00 */ char unk00[0x20];
} unk_D_70B10; // size = 0x20

extern u32 D_8C000000; // start of some rom area

typedef struct unk_D_80072B00 {
    /* 0x00 */ char unk00[2];
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ char unk04[1];
    /* 0x05 */ u8 unk_05;
} unk_D_80072B00; // size = 0x6
extern unk_D_80072B00 D_80072B00[];

typedef struct unk_D_80072338 {
    /* 0x00 */ char unk00[0x1];
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ char unk02[0xA];
} unk_D_80072338; // size = 0xC
extern unk_D_80072338 D_80072338[];

extern char D_8006FEE8[][0x1C];

#endif
