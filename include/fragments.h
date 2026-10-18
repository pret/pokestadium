#ifndef _FRAGMENTS_H_
#define _FRAGMENTS_H_

// Linker-token aliases for FRAGMENT_ID and the FRAGMENT_LOAD family, not numeric IDs.
// Names identify the existing source modules, not recovered original identifiers.
// Segment membership is defined in the version's ROM YAML.
//@yamls/us/rom.yaml

#define FRAGMENT_GB_TOWER_EMULATOR fragment1
#define FRAGMENT_WIDGET_TOOLKIT fragment2
#define FRAGMENT_MINIGAME_ACTOR_FRAMEWORK fragment3
#define FRAGMENT_MINIGAME_SHARED_GRAPHICS fragment4
#define FRAGMENT_MINIGAME_SHARED_LIBRARY fragment5
#define FRAGMENT_MAGIKARP_GAME fragment6
#define FRAGMENT_CLEFAIRY_GAME fragment7
#define FRAGMENT_RATTATA_GAME fragment8
#define FRAGMENT_JIGGLYPUFF_DOODLE fragment9
#define FRAGMENT_DROWZEE_GAME fragment10
#define FRAGMENT_DYNAMO_GAME fragment11
#define FRAGMENT_MINIGAME_SAMPLE7_VIEWER fragment12
#define FRAGMENT_MINIGAME_SAMPLE8_VIEWER fragment13
#define FRAGMENT_SUSHI_GAME fragment14
#define FRAGMENT_GALLERY_CAMERA fragment15
#define FRAGMENT_CREDITS fragment16
#define FRAGMENT_DEMO_SCENES fragment17
#define FRAGMENT_EKANS_GAME fragment18
#define FRAGMENT_RANKING_DEBUG_TEST fragment19
#define FRAGMENT_METAPOD_GAME fragment20
#define FRAGMENT_SANDSHREW_GAME fragment21
#define FRAGMENT_PROFESSOR_OAK_LAB fragment22
#define FRAGMENT_LAB_PC fragment23
#define FRAGMENT_LAB_PC_LIST fragment24
#define FRAGMENT_POKEMON_LAB_SUPPORT fragment25
#define FRAGMENT_WIDGET_TREE fragment26
#define FRAGMENT_LAB_PC_ICONS fragment27
#define FRAGMENT_POKEDEX fragment28
#define FRAGMENT_LAB_UI_SUPPORT fragment29
#define FRAGMENT_POKEMON_LAB_UNUSED fragment30
#define FRAGMENT_PARTICLE_DATA_LIBRARY fragment31
#define FRAGMENT_FATAL_ERROR_SCREEN fragment32
#define FRAGMENT_TRANSFER_PAK_SELECT fragment33
#define FRAGMENT_PARTICLE_MATH fragment34
#define FRAGMENT_N64_LOGO fragment35
#define FRAGMENT_TITLE_SCREEN fragment36
#define FRAGMENT_AREA_SELECT fragment37
#define FRAGMENT_EVENT_BATTLE fragment38
#define FRAGMENT_MINIGAME_SELECT fragment39
#define FRAGMENT_GYM_LEADER_CASTLE_CLEAR fragment40
#define FRAGMENT_TRADE_MACHINE fragment41
#define FRAGMENT_GALLERY_SNAP fragment42
#define FRAGMENT_GALLERY_BACKGROUNDS fragment43
#define FRAGMENT_GALLERY_ALBUM fragment44
#define FRAGMENT_GALLERY_FILM_SELECT fragment45
#define FRAGMENT_GALLERY_ENLARGE fragment46
#define FRAGMENT_GALLERY_RENTAL_VIEWER fragment47
#define FRAGMENT_GALLERY_DEBUGGER fragment48
#define FRAGMENT_SNAP_PRINT_CLUB_BACKGROUND_SELECT fragment49
#define FRAGMENT_HALL_OF_FAME fragment50
#define FRAGMENT_GB_TOWER_UNUSED fragment51
#define FRAGMENT_MINIGAME_SAMPLE2_VIEWER fragment52
#define FRAGMENT_GB_TOWER_TEAM_PREP fragment53
#define FRAGMENT_RENTAL_HUB fragment54
#define FRAGMENT_RENTAL_RULES fragment55
#define FRAGMENT_OPTIONS fragment56
#define FRAGMENT_TRANSFER_PAK_CHECK fragment57
#define FRAGMENT_FREE_BATTLE_RULES fragment58
#define FRAGMENT_STADIUM_SELECT fragment59
#define FRAGMENT_CUP_SELECT fragment60
// TeamSelection entry and roster UI span both named and numbered source directories.
//@src/fragments/61/fragment61_2D78B0.c
//@src/fragments/rental_team_selection/rental_team_selection_2DB900.c
#define FRAGMENT_RENTAL_TEAM_SELECTION fragment61
#define FRAGMENT_BATTLE_ENGINE fragment62
#define FRAGMENT_BATTLE_PREP fragment63
#define FRAGMENT_BATTLE_ORDER_SELECT fragment64
#define FRAGMENT_GYM_LEADER_CASTLE fragment65
#define FRAGMENT_PIKACHU_REWARD fragment66
#define FRAGMENT_DEBUG_MENU_EXIT fragment67
// These stubs forward to DebugMenu_Exit; the slot numbers preserve their distinct identities.
//@src/fragments/debug_menu_slot68/debug_menu_slot68.c
#define FRAGMENT_DEBUG_MENU_SLOT68 fragment68
#define FRAGMENT_DEBUG_MENU_SLOT69 fragment69
#define FRAGMENT_DEBUG_MENU_SLOT70 fragment70
#define FRAGMENT_DEBUG_MENU_SLOT71 fragment71
#define FRAGMENT_DEBUG_MENU_SLOT72 fragment72
#define FRAGMENT_DEBUG_MENU_SLOT73 fragment73
#define FRAGMENT_DEBUG_MENU_SLOT74 fragment74
#define FRAGMENT_SNAP_PRINT_CLUB_PRINT_SEALS fragment75
#define FRAGMENT_DEBUG_MENU_SLOT76 fragment76
#define FRAGMENT_DEBUG_MENU_SLOT77 fragment77

#endif
