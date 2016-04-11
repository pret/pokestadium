.create "pokestadiumgs.n64",0
.n64
.include "constants/type_constants.s"
.include "constants/move_constants.s"
.include "constants/item_constants.s"
.incbin "baseromgs.n64",0,0x98a14

TMHMMoves:
	.db DYNAMICPUNCH
	.db HEADBUTT
	.db CURSE
	.db ROLLOUT
	.db ROAR
	.db TOXIC
	.db ZAP_CANNON
	.db ROCK_SMASH
	.db PSYCH_UP
	.db HIDDEN_POWER
	.db SUNNY_DAY
	.db SWEET_SCENT
	.db SNORE
	.db BLIZZARD
	.db HYPER_BEAM
	.db ICY_WIND
	.db PROTECT
	.db RAIN_DANCE
	.db GIGA_DRAIN
	.db ENDURE
	.db FRUSTRATION
	.db SOLARBEAM
	.db IRON_TAIL
	.db DRAGONBREATH
	.db THUNDER
	.db EARTHQUAKE
	.db RETURN
	.db DIG
	.db PSYCHIC_M
	.db SHADOW_BALL
	.db MUD_SLAP
	.db DOUBLE_TEAM
	.db ICE_PUNCH
	.db SWAGGER
	.db SLEEP_TALK
	.db SLUDGE_BOMB
	.db SANDSTORM
	.db FIRE_BLAST
	.db SWIFT
	.db DEFENSE_CURL
	.db THUNDERPUNCH
	.db DREAM_EATER
	.db DETECT
	.db REST
	.db ATTRACT
	.db THIEF
	.db STEEL_WING
	.db FIRE_PUNCH
	.db FURY_CUTTER
	.db NIGHTMARE
	.db CUT
	.db FLY
	.db SURF
	.db STRENGTH
	.db FLASH
	.db WHIRLPOOL
	.db WATERFALL
	.align

.incbin "baseromgs.n64",0x98a50,0x98a90-0x98a50

SUPER_EFFECTIVE    EQU 20
NOT_VERY_EFFECTIVE EQU 05
NO_EFFECT          EQU 00

TypeMatchup:
	.db NORMAL,    ROCK,      NOT_VERY_EFFECTIVE
	.db NORMAL,    STEEL,     NOT_VERY_EFFECTIVE
	.db FIRE,      FIRE,      NOT_VERY_EFFECTIVE
	.db FIRE,      WATER,     NOT_VERY_EFFECTIVE
	.db FIRE,      GRASS,     SUPER_EFFECTIVE
	.db FIRE,      ICE,       SUPER_EFFECTIVE
	.db FIRE,      BUG,       SUPER_EFFECTIVE
	.db FIRE,      ROCK,      NOT_VERY_EFFECTIVE
	.db FIRE,      DRAGON,    NOT_VERY_EFFECTIVE
	.db FIRE,      STEEL,     SUPER_EFFECTIVE
	.db WATER,     FIRE,      SUPER_EFFECTIVE
	.db WATER,     WATER,     NOT_VERY_EFFECTIVE
	.db WATER,     GRASS,     NOT_VERY_EFFECTIVE
	.db WATER,     GROUND,    SUPER_EFFECTIVE
	.db WATER,     ROCK,      SUPER_EFFECTIVE
	.db WATER,     DRAGON,    NOT_VERY_EFFECTIVE
	.db ELECTRIC,  WATER,     SUPER_EFFECTIVE
	.db ELECTRIC,  ELECTRIC,  NOT_VERY_EFFECTIVE
	.db ELECTRIC,  GRASS,     NOT_VERY_EFFECTIVE
	.db ELECTRIC,  GROUND,    NO_EFFECT
	.db ELECTRIC,  FLYING,    SUPER_EFFECTIVE
	.db ELECTRIC,  DRAGON,    NOT_VERY_EFFECTIVE
	.db GRASS,     FIRE,      NOT_VERY_EFFECTIVE
	.db GRASS,     WATER,     SUPER_EFFECTIVE
	.db GRASS,     GRASS,     NOT_VERY_EFFECTIVE
	.db GRASS,     POISON,    NOT_VERY_EFFECTIVE
	.db GRASS,     GROUND,    SUPER_EFFECTIVE
	.db GRASS,     FLYING,    NOT_VERY_EFFECTIVE
	.db GRASS,     BUG,       NOT_VERY_EFFECTIVE
	.db GRASS,     ROCK,      SUPER_EFFECTIVE
	.db GRASS,     DRAGON,    NOT_VERY_EFFECTIVE
	.db GRASS,     STEEL,     NOT_VERY_EFFECTIVE
	.db ICE,       WATER,     NOT_VERY_EFFECTIVE
	.db ICE,       GRASS,     SUPER_EFFECTIVE
	.db ICE,       ICE,       NOT_VERY_EFFECTIVE
	.db ICE,       GROUND,    SUPER_EFFECTIVE
	.db ICE,       FLYING,    SUPER_EFFECTIVE
	.db ICE,       DRAGON,    SUPER_EFFECTIVE
	.db ICE,       STEEL,     NOT_VERY_EFFECTIVE
	.db ICE,       FIRE,      NOT_VERY_EFFECTIVE
	.db FIGHTING,  NORMAL,    SUPER_EFFECTIVE
	.db FIGHTING,  ICE,       SUPER_EFFECTIVE
	.db FIGHTING,  POISON,    NOT_VERY_EFFECTIVE
	.db FIGHTING,  FLYING,    NOT_VERY_EFFECTIVE
	.db FIGHTING,  PSYCHIC,   NOT_VERY_EFFECTIVE
	.db FIGHTING,  BUG,       NOT_VERY_EFFECTIVE
	.db FIGHTING,  ROCK,      SUPER_EFFECTIVE
	.db FIGHTING,  DARK,      SUPER_EFFECTIVE
	.db FIGHTING,  STEEL,     SUPER_EFFECTIVE
	.db POISON,    GRASS,     SUPER_EFFECTIVE
	.db POISON,    POISON,    NOT_VERY_EFFECTIVE
	.db POISON,    GROUND,    NOT_VERY_EFFECTIVE
	.db POISON,    ROCK,      NOT_VERY_EFFECTIVE
	.db POISON,    GHOST,     NOT_VERY_EFFECTIVE
	.db POISON,    STEEL,     NO_EFFECT
	.db GROUND,    FIRE,      SUPER_EFFECTIVE
	.db GROUND,    ELECTRIC,  SUPER_EFFECTIVE
	.db GROUND,    GRASS,     NOT_VERY_EFFECTIVE
	.db GROUND,    POISON,    SUPER_EFFECTIVE
	.db GROUND,    FLYING,    NO_EFFECT
	.db GROUND,    BUG,       NOT_VERY_EFFECTIVE
	.db GROUND,    ROCK,      SUPER_EFFECTIVE
	.db GROUND,    STEEL,     SUPER_EFFECTIVE
	.db FLYING,    ELECTRIC,  NOT_VERY_EFFECTIVE
	.db FLYING,    GRASS,     SUPER_EFFECTIVE
	.db FLYING,    FIGHTING,  SUPER_EFFECTIVE
	.db FLYING,    BUG,       SUPER_EFFECTIVE
	.db FLYING,    ROCK,      NOT_VERY_EFFECTIVE
	.db FLYING,    STEEL,     NOT_VERY_EFFECTIVE
	.db PSYCHIC,   FIGHTING,  SUPER_EFFECTIVE
	.db PSYCHIC,   POISON,    SUPER_EFFECTIVE
	.db PSYCHIC,   PSYCHIC,   NOT_VERY_EFFECTIVE
	.db PSYCHIC,   DARK,      NO_EFFECT
	.db PSYCHIC,   STEEL,     NOT_VERY_EFFECTIVE
	.db BUG,       FIRE,      NOT_VERY_EFFECTIVE
	.db BUG,       GRASS,     SUPER_EFFECTIVE
	.db BUG,       FIGHTING,  NOT_VERY_EFFECTIVE
	.db BUG,       POISON,    NOT_VERY_EFFECTIVE
	.db BUG,       FLYING,    NOT_VERY_EFFECTIVE
	.db BUG,       PSYCHIC,   SUPER_EFFECTIVE
	.db BUG,       GHOST,     NOT_VERY_EFFECTIVE
	.db BUG,       DARK,      SUPER_EFFECTIVE
	.db BUG,       STEEL,     NOT_VERY_EFFECTIVE
	.db ROCK,      FIRE,      SUPER_EFFECTIVE
	.db ROCK,      ICE,       SUPER_EFFECTIVE
	.db ROCK,      FIGHTING,  NOT_VERY_EFFECTIVE
	.db ROCK,      GROUND,    NOT_VERY_EFFECTIVE
	.db ROCK,      FLYING,    SUPER_EFFECTIVE
	.db ROCK,      BUG,       SUPER_EFFECTIVE
	.db ROCK,      STEEL,     NOT_VERY_EFFECTIVE
	.db GHOST,     NORMAL,    NO_EFFECT
	.db GHOST,     PSYCHIC,   SUPER_EFFECTIVE
	.db GHOST,     DARK,      NOT_VERY_EFFECTIVE
	.db GHOST,     STEEL,     NOT_VERY_EFFECTIVE
	.db GHOST,     GHOST,     SUPER_EFFECTIVE
	.db DRAGON,    DRAGON,    SUPER_EFFECTIVE
	.db DRAGON,    STEEL,     NOT_VERY_EFFECTIVE
	.db DARK,      FIGHTING,  NOT_VERY_EFFECTIVE
	.db DARK,      PSYCHIC,   SUPER_EFFECTIVE
	.db DARK,      GHOST,     SUPER_EFFECTIVE
	.db DARK,      DARK,      NOT_VERY_EFFECTIVE
	.db DARK,      STEEL,     NOT_VERY_EFFECTIVE
	.db STEEL,     FIRE,      NOT_VERY_EFFECTIVE
	.db STEEL,     WATER,     NOT_VERY_EFFECTIVE
	.db STEEL,     ELECTRIC,  NOT_VERY_EFFECTIVE
	.db STEEL,     ICE,       SUPER_EFFECTIVE
	.db STEEL,     ROCK,      SUPER_EFFECTIVE
	.db STEEL,     STEEL,     NOT_VERY_EFFECTIVE
	.db -1
	.align

.incbin "baseromgs.n64",0x98bd8,0x98ef0-0x98bd8

TypeBoostItems:
	.db HELD_NORMAL_BOOST,   NORMAL   ; Pink/Polkadot Bow
	.db HELD_FIGHTING_BOOST, FIGHTING ; Blackbelt
	.db HELD_FLYING_BOOST,   FLYING   ; Sharp Beak
	.db HELD_POISON_BOOST,   POISON   ; Poison Barb
	.db HELD_GROUND_BOOST,   GROUND   ; Soft Sand
	.db HELD_ROCK_BOOST,     ROCK     ; Hard Stone
	.db HELD_BUG_BOOST,      BUG      ; Silverpowder
	.db HELD_GHOST_BOOST,    GHOST    ; Spell Tag
	.db HELD_FIRE_BOOST,     FIRE     ; Charcoal
	.db HELD_WATER_BOOST,    WATER    ; Mystic Water
	.db HELD_GRASS_BOOST,    GRASS    ; Miracle Seed
	.db HELD_ELECTRIC_BOOST, ELECTRIC ; Magnet
	.db HELD_PSYCHIC_BOOST,  PSYCHIC  ; Twistedspoon
	.db HELD_ICE_BOOST,      ICE      ; Nevermeltice
	.db HELD_DRAGON_BOOST,   DRAGON   ; Dragon Scale
	.db HELD_DARK_BOOST,     DARK     ; Blackglasses
	.db HELD_STEEL_BOOST,    STEEL    ; Metal Coat
	.db -1
	.align 16

BaseStats:
; 22 bytes
; new pokédex position
; base hp, attack, defense, speed, special attack, special defense
; type1, type2
; gender ratio
; ???, ???
; growth rate
; egg groups
; TM/HMs (not including move tutor)
.incbin "baseromgs.n64",0x98f20,0x9a4b2-0x98f20

.incbin "baseromgs.n64",0x9a4b2,0x23a5000-0x9a4b2

Unknown0x23A5000:

.incbin "baseromgs.n64",0x23a5000,0x23a554c-0x23a5000

GameBoyHeaders:
; game id
; ROM title
; region
; revision
; checksum
; unknown1, pointer (to what?), unknown2

JAPAN     EQU 0
NON_JAPAN EQU 1

POKEMON_RED     EQU 1
POKEMON_GREEN   EQU 2
POKEMON_BLUE    EQU 3
POKEMON_YELLOW  EQU 4
POKEMON_GOLD    EQU 5
POKEMON_SILVER  EQU 6
POKEMON_CRYSTAL EQU 7

; no-intro: Pocket Monsters - Crystal Version (Japan)
	.db POKEMON_CRYSTAL
	.db "PM_CRYSTAL",0,"BXTJ"
	.db JAPAN
	.db 0
	.dh 0x9a40
	.dw 0x0d400000, UnknownGameBoy0x23a594c - Unknown0x23A5000, 0x000b0000

; no-intro: Pocket Monsters Gin (Japan) (Rev A)
	.db POKEMON_SILVER
	.db "POKEMON_SLVAAXJ"
	.db JAPAN
	.db 1
	.dh 0x1d34
	.dw 0x00520840, UnknownGameBoy0x23a5d6c - Unknown0x23A5000, 0x000b0000

; no-intro: Pocket Monsters Gin (Japan)
	.db POKEMON_SILVER
	.db "POKEMON_SLVAAXJ"
	.db JAPAN
	.db 0
	.dh 0x7691
	.dw 0x00520840, UnknownGameBoy0x23a618c - Unknown0x23A5000, 0x000b0000

; no-intro: Pocket Monsters Kin (Japan)
	.db POKEMON_GOLD
	.db "POKEMON_GLDAAUJ"
	.db JAPAN
	.db 0
	.dh 0x8a70
	.dw 0x00520840, UnknownGameBoy0x23a65ac - Unknown0x23A5000, 0x000b0000

; no-intro: Pocket Monsters Kin (Japan) (Rev A)
	.db POKEMON_GOLD
	.db "POKEMON_GLDAAUJ"
	.db JAPAN
	.db 1
	.dh 0x8460
	.dw 0x00520840, UnknownGameBoy0x23a69cc - Unknown0x23A5000, 0x000b0000

; no-intro: Pocket Monsters - Pikachu (Japan) (Rev D)
	.db POKEMON_YELLOW
	.db "POKEMON YELLOW",0
	.db JAPAN
	.db 3
	.dh 0xd984
	.dw 0x00000000, UnknownGameBoy0x23a6dec - Unknown0x23A5000, 0x00160000

; no-intro: Pocket Monsters - Pikachu (Japan) (Rev C)
	.db POKEMON_YELLOW
	.db "POKEMON YELLOW",0
	.db JAPAN
	.db 2
	.dh 0xedd9
	.dw 0x52fd2599, UnknownGameBoy0x23a720c - Unknown0x23A5000, 0x00160000

; no-intro: Pocket Monsters - Pikachu (Japan) (Rev B)
	.db POKEMON_YELLOW
	.db "POKEMON YELLOW",0
	.db JAPAN
	.db 1
	.dh 0x8858
	.dw 0x5afd2d99, UnknownGameBoy0x23a762c - Unknown0x23A5000, 0x00160000

; no-intro: Pocket Monsters - Pikachu (Japan) (Rev 0A)
	.db POKEMON_YELLOW
	.db "POKEMON YELLOW",0
	.db JAPAN
	.db 0
	.dh 0x9c29
	.dw 0xcef7dddb, UnknownGameBoy0x23a7a4c - Unknown0x23A5000, 0x00160000

; no-intro: Pocket Monsters - Ao (Japan)
	.db POKEMON_BLUE
	.db "POKEMON BLUE",0,0,0
	.db JAPAN
	.db 0
	.dh 0xdc36
	.dw 0x00000000, UnknownGameBoy0x23a7e6c - Unknown0x23A5000, 0x00150000

; no-intro: Pocket Monsters - Aka (Japan) (Rev A)
	.db POKEMON_RED
	.db "POKEMON RED",0,0,0,0
	.db JAPAN
	.db 1
	.dh 0xb866
	.dw 0x00000000, UnknownGameBoy0x23a828c - Unknown0x23A5000, 0x00150000

; no-intro: Pocket Monsters - Midori (Japan) (Rev A)
	.db POKEMON_GREEN
	.db "POKEMON GREEN",0,0
	.db JAPAN
	.db 1
	.dh 0xf547
	.dw 0x00000000, UnknownGameBoy0x23a86ac - Unknown0x23A5000, 0x00160000

; no-intro: Pocket Monsters - Midori (Japan)
	.db POKEMON_GREEN
	.db "POKEMON GREEN",0,0
	.db JAPAN
	.db 0
	.dh 0xddd5
	.dw 0x00000000, UnknownGameBoy0x23a8acc - Unknown0x23A5000, 0x00160000

; no-intro: Pocket Monsters - Aka (Japan)
	.db POKEMON_RED
	.db "POKEMON RED",0,0,0,0
	.db JAPAN
	.db 0
	.dh 0xa2c1
	.dw 0x00000000, UnknownGameBoy0x23a8eec - Unknown0x23A5000, 0x00150000

; not in no-intro
	.db POKEMON_CRYSTAL
	.db "PM_CRYSTAL",0,"base"
	.db NON_JAPAN
	.db 0
	.dh 0x5e1c
	.dw 0x000c0000, UnknownGameBoy0x23a930c - Unknown0x23A5000, 0x000b0000

; no-intro: Pokemon - Gold Version (USA, Europe)
	.db POKEMON_GOLD
	.db "POKEMON_GLDAAUE"
	.db NON_JAPAN
	.db 0
	.dh 0x682d
	.dw 0x00000000, UnknownGameBoy0x23a972c - Unknown0x23A5000, 0x000b0000

; no-intro: Pokemon - Silver Version (USA, Europe)
	.db POKEMON_SILVER
	.db "POKEMON_SLVAAXE"
	.db NON_JAPAN
	.db 0
	.dh 0x0dae
	.dw 0x00000000, UnknownGameBoy0x23a9b4c - Unknown0x23A5000, 0x000b0000

; no-intro: Pokemon - Yellow Version - Special Pikachu Edition (USA, Europe)
	.db POKEMON_YELLOW
	.db "POKEMON YELLOW",0
	.db NON_JAPAN
	.db 0
	.dh 0x047c
	.dw 0x8f918492, UnknownGameBoy0x23a9f6c - Unknown0x23A5000, 0x00180000

; no-intro: Pokemon - Red Version (USA, Europe)
	.db POKEMON_RED
	.db "POKEMON RED",0,0,0,0
	.db NON_JAPAN
	.db 0
	.dh 0x91e6
	.dw 0x807faba8, UnknownGameBoy0x23aa38c - Unknown0x23A5000, 0x00170000

; no-intro: Pokemon - Blue Version (USA, Europe)
	.db POKEMON_BLUE
	.db "POKEMON BLUE",0,0,0
	.db NON_JAPAN
	.db 0
	.dh 0x9d0a
	.dw 0x807faba8, UnknownGameBoy0x23aa7ac - Unknown0x23A5000, 0x00170000

; no-intro: Pokemon - Version Jaune - Edition Speciale Pikachu (France)
	.db POKEMON_YELLOW
	.db "POKEMON YELAPSF"
	.db NON_JAPAN
	.db 0
	.dh 0xb7c1
	.dw 0x8f83869c, UnknownGameBoy0x23aabcc - Unknown0x23A5000, 0x00180000

; no-intro: Pokemon - Version Rouge (France)
	.db POKEMON_RED
	.db "POKEMON RED",0,0,0,0
	.db NON_JAPAN
	.db 0
	.dh 0x7afc
	.dw 0x94ad7fda, UnknownGameBoy0x23aafec - Unknown0x23A5000, 0x00170000

; no-intro: Pokemon - Version Bleue (France)
	.db POKEMON_BLUE
	.db "POKEMON BLUE",0,0,0
	.db NON_JAPAN
	.db 0
	.dh 0x56a4
	.dw 0x94ad7fda, UnknownGameBoy0x23ab40c - Unknown0x23A5000, 0x00170000

; no-intro: Pokemon - Gelbe Edition - Special Pikachu Edition (Germany)
	.db POKEMON_YELLOW
	.db "POKEMON YELAPSD"
	.db NON_JAPAN
	.db 0
	.dh 0x66fb
	.dw 0x8f91c092, UnknownGameBoy0x23ab82c - Unknown0x23A5000, 0x00180000

; no-intro: Pokemon - Rote Edition (Germany)
	.db POKEMON_RED
	.db "POKEMON RED",0,0,0,0
	.db NON_JAPAN
	.db 0
	.dh 0x5cdc
	.dw 0x88a2a77f, UnknownGameBoy0x23abc4c - Unknown0x23A5000, 0x00170000

; no-intro: Pokemon - Blaue Edition (Germany)
	.db POKEMON_BLUE
	.db "POKEMON BLUE",0,0,0
	.db NON_JAPAN
	.db 0
	.dh 0x2ebc
	.dw 0x88a2a77f, UnknownGameBoy0x23ac06c - Unknown0x23A5000, 0x00170000

; no-intro: Pokemon - Versione Gialla - Speciale Edizione Pikachu (Italy)
	.db POKEMON_YELLOW
	.db "POKEMON YELAPSI"
	.db NON_JAPAN
	.db 0
	.dh 0x4e8f
	.dw 0x8f918492, UnknownGameBoy0x23ac48c - Unknown0x23A5000, 0x00180000

; no-intro: Pokemon - Versione Rossa (Italy)
	.db POKEMON_RED
	.db "POKEMON RED",0,0,0,0
	.db NON_JAPAN
	.db 0
	.dh 0x89d2
	.dw 0x95aea6ab, UnknownGameBoy0x23ac8ac - Unknown0x23A5000, 0x00170000

; no-intro: Pokemon - Versione Blu (Italy)
	.db POKEMON_BLUE
	.db "POKEMON BLUE",0,0,0
	.db NON_JAPAN
	.db 0
	.dh 0x5e9c
	.dw 0x95aea6ab, UnknownGameBoy0x23acccc - Unknown0x23A5000, 0x00170000

; no-intro: Pokemon - Edicion Amarilla - Edicion Especial Pikachu (Spain)
	.db POKEMON_YELLOW
	.db "POKEMON YELAPSS"
	.db NON_JAPAN
	.db 0
	.dh 0x5637
	.dw 0x8f918492, UnknownGameBoy0x23ad0ec - Unknown0x23A5000, 0x00180000

; no-intro: Pokemon - Edicion Roja (Spain)
	.db POKEMON_RED
	.db "POKEMON RED",0,0,0,0
	.db NON_JAPAN
	.db 0
	.dh 0x384a
	.dw 0xe593a47f, UnknownGameBoy0x23ad50c - Unknown0x23A5000, 0x00170000

; no-intro: Pokemon - Edicion Azul (Spain)
	.db POKEMON_BLUE
	.db "POKEMON BLUE",0,0,0
	.db NON_JAPAN
	.db 0
	.dh 0x14d7
	.dw 0xe593a47f, UnknownGameBoy0x23ad92c - Unknown0x23A5000, 0x00170000

UnknownGameBoy0x23a594c: ; Crystal Japan rev 0
.incbin "gameboy/00.bin"
UnknownGameBoy0x23a5d6c: ; Silver Japan rev 1
.incbin "gameboy/01.bin"
UnknownGameBoy0x23a618c: ; Silver Japan rev 0
.incbin "gameboy/02.bin"
UnknownGameBoy0x23a65ac: ; Gold Japan rev 0
.incbin "gameboy/03.bin"
UnknownGameBoy0x23a69cc: ; Gold Japan rev 1
.incbin "gameboy/04.bin"
UnknownGameBoy0x23a6dec: ; Yellow Japan rev 3
.incbin "gameboy/05.bin"
UnknownGameBoy0x23a720c: ; Yellow Japan rev 2
.incbin "gameboy/06.bin"
UnknownGameBoy0x23a762c: ; Yellow Japan rev 1
.incbin "gameboy/07.bin"
UnknownGameBoy0x23a7a4c: ; Yellow Japan rev 0
.incbin "gameboy/08.bin"
UnknownGameBoy0x23a7e6c: ; Blue Japan rev 0
.incbin "gameboy/09.bin"
UnknownGameBoy0x23a828c: ; Red Japan rev 1
.incbin "gameboy/0a.bin"
UnknownGameBoy0x23a86ac: ; Green Japan rev 1
.incbin "gameboy/0b.bin"
UnknownGameBoy0x23a8acc: ; Green Japan rev 0
.incbin "gameboy/0c.bin"
UnknownGameBoy0x23a8eec: ; Red Japan rev 0
.incbin "gameboy/0d.bin"
UnknownGameBoy0x23a930c: ; Crystal USA
.incbin "gameboy/0e.bin"
UnknownGameBoy0x23a972c: ; Gold USA
.incbin "gameboy/0f.bin"
UnknownGameBoy0x23a9b4c: ; Silver USA
.incbin "gameboy/10.bin"
UnknownGameBoy0x23a9f6c: ; Yellow USA
.incbin "gameboy/11.bin"
UnknownGameBoy0x23aa38c: ; Red USA
.incbin "gameboy/12.bin"
UnknownGameBoy0x23aa7ac: ; Blue USA
.incbin "gameboy/13.bin"
UnknownGameBoy0x23aabcc: ; Yellow France
.incbin "gameboy/14.bin"
UnknownGameBoy0x23aafec: ; Red France
.incbin "gameboy/15.bin"
UnknownGameBoy0x23ab40c: ; Blue France
.incbin "gameboy/16.bin"
UnknownGameBoy0x23ab82c: ; Yellow Germany
.incbin "gameboy/17.bin"
UnknownGameBoy0x23abc4c: ; Red Germany
.incbin "gameboy/18.bin"
UnknownGameBoy0x23ac06c: ; Blue Germany
.incbin "gameboy/19.bin"
UnknownGameBoy0x23ac48c: ; Yellow Italy
.incbin "gameboy/1a.bin"
UnknownGameBoy0x23ac8ac: ; Red Italy
.incbin "gameboy/1b.bin"
UnknownGameBoy0x23acccc: ; Blue Italy
.incbin "gameboy/1c.bin"
UnknownGameBoy0x23ad0ec: ; Yellow Spain
.incbin "gameboy/1d.bin"
UnknownGameBoy0x23ad50c: ; Red Spain
.incbin "gameboy/1e.bin"
UnknownGameBoy0x23ad92c: ; Blue Spain
.incbin "gameboy/1f.bin"

.incbin "baseromgs.n64",0x23add4c

.close
