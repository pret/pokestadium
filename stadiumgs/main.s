.create "pokestadiumgs.n64",0
.n64
.include "constants/pokemon_constants.s"
.include "constants/type_constants.s"
.include "constants/move_constants.s"
.include "constants/item_constants.s"
.incbin "baseromgs.n64",0,0x97f54

CarrierCartridgeString:
	.ascii "PokeMonStadium3CarrierCartridge",0

	.align 16

CharMap1:
; USA
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x0A,0x80 ;                   \n
	.db 0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ; \0
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x91,0x92,0x9B,0x9C,0x80,0x93,0x80,0x80 ; PO Ké “  ”     …
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x20 ;
	.db 0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48 ; A  B  C  D  E  F  G  H
	.db 0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,0x50 ; I  J  K  L  M  N  O  P
	.db 0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58 ; Q  R  S  T  U  V  W  X
	.db 0x59,0x5A,0x28,0x29,0x3A,0x3B,0x5B,0x5D ; Y  Z  (  )  :  ;  [  ]
	.db 0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68 ; a  b  c  d  e  f  g  h
	.db 0x69,0x6A,0x6B,0x6C,0x6D,0x6E,0x6F,0x70 ; i  j  k  l  m  n  o  p
	.db 0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78 ; q  r  s  t  u  v  w  x
	.db 0x79,0x7A,0x80,0x80,0x80,0x80,0x80,0x80 ; y  z
	.db 0xC4,0xD6,0xDC,0xE4,0xF6,0xFC,0x80,0x80 ; Ä  Ö  Ü  ä  ö  ü
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x94,0x95,0x96,0x97,0x98,0x99,0x9A,0x80 ; ’d ’l ’m ’r ’s ’t ’v
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x27,0xBC,0xBD,0x2D,0x80,0x80,0x3F,0x21 ; '  PK MN -        ?  !
	.db 0x2E,0x26,0xE9,0x80,0x80,0x80,0x80,0xA9 ; .  &  é              ♂
	.db 0xA5,0xD7,0x2E,0x2F,0x2C,0xBE,0x30,0x31 ; ¥  ×  .  /  ,  ♀  0  1
	.db 0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39 ; 2  3  4  5  6  7  8  9

CharMap2:
; Germany, France
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x0A,0x80 ;                   \n
	.db 0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ; \0
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x91,0x92,0x9B,0x9C,0x80,0x93,0x80,0x80 ; PO Ké “  ”     …
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x20 ;
	.db 0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48 ; A  B  C  D  E  F  G  H
	.db 0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,0x50 ; I  J  K  L  M  N  O  P
	.db 0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58 ; Q  R  S  T  U  V  W  X
	.db 0x59,0x5A,0x28,0x29,0x3A,0x3B,0x5B,0x5D ; Y  Z  (  )  :  ;  [  ]
	.db 0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68 ; a  b  c  d  e  f  g  h
	.db 0x69,0x6A,0x6B,0x6C,0x6D,0x6E,0x6F,0x70 ; i  j  k  l  m  n  o  p
	.db 0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78 ; q  r  s  t  u  v  w  x
	.db 0x79,0x7A,0xE0,0xE8,0xE9,0xF9,0xDF,0xE7 ; y  z  à  è  é  ù  ß  ç
	.db 0xC4,0xD6,0xDC,0xE4,0xF6,0xFC,0xEB,0xEF ; Ä  Ö  Ü  ä  ö  ü  ë  ï
	.db 0xE2,0xF4,0xFB,0xEA,0xEE,0x80,0x80,0x80 ; â  ô  û  ê  î
	.db 0x80,0x80,0x80,0x80,0x9D,0x9E,0x9F,0xA2 ;             c’ d’ j’ l’
	.db 0xA3,0xA4,0xA6,0xA7,0x98,0xA8,0xAB,0xAC ; m’ n’ p’ s’ ’s t’ u’ y’
	.db 0x27,0xBC,0xBD,0x2D,0x2B,0x80,0x3F,0x21 ; '  PK MN -  +     ?  !
	.db 0x2E,0x26,0xE9,0x80,0x80,0x80,0x80,0xA9 ; .  &  é              ♂
	.db 0xA5,0xD7,0x2E,0x2F,0x2C,0xBE,0x30,0x31 ; ¥  ×  .  /  ,  ♀  0  1
	.db 0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39 ; 2  3  4  5  6  7  8  9

CharMap3:
; Italy, Spain
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x0A,0x80 ;                   \n
	.db 0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ; \0
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80 ;
	.db 0x91,0x92,0x9B,0x9C,0x80,0x93,0x80,0x80 ; PO Ké “  ”     …
	.db 0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x20 ;
	.db 0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48 ; A  B  C  D  E  F  G  H
	.db 0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,0x50 ; I  J  K  L  M  N  O  P
	.db 0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58 ; Q  R  S  T  U  V  W  X
	.db 0x59,0x5A,0x28,0x29,0x3A,0x3B,0x5B,0x5D ; Y  Z  (  )  :  ;  [  ]
	.db 0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68 ; a  b  c  d  e  f  g  h
	.db 0x69,0x6A,0x6B,0x6C,0x6D,0x6E,0x6F,0x70 ; i  j  k  l  m  n  o  p
	.db 0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78 ; q  r  s  t  u  v  w  x
	.db 0x79,0x7A,0xE0,0xE8,0xE9,0xF9,0xC0,0xC1 ; y  z  à  è  é  ù  À  Á
	.db 0xC4,0xD6,0xDC,0xE4,0xF6,0xFC,0xC8,0xC9 ; Ä  Ö  Ü  ä  ö  ü  È  É
	.db 0xCC,0xCD,0xD1,0xD2,0xD3,0xD9,0xDA,0xE1 ; Ì  Í  Ñ  Ò  Ó  Ù  Ú  á
	.db 0xEC,0xED,0xF1,0xF2,0xF3,0xFA,0xB0,0x26 ; ì  í  ñ  ò  ó  ú  °  &
	.db 0x94,0x95,0x96,0x97,0x98,0x99,0x9A,0x80 ; ’d ’l ’m ’r ’s ’t ’v
	.db 0x27,0xBC,0xBD,0x2D,0xBF,0xA1,0x3F,0x21 ; '  PK MN -  ¿  ¡  ?  !
	.db 0x2E,0x26,0xE9,0x80,0x80,0x80,0x80,0xA9 ; .  &  é              ♂
	.db 0xA5,0xD7,0x2E,0x2F,0x2C,0xBE,0x30,0x31 ; ¥  ×  .  /  ,  ♀  0  1
	.db 0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39 ; 2  3  4  5  6  7  8  9

UnknownData0x98290: ; XXX what is this?
	.dw 0x80097380

TimeCapsuleAltItems:
	.db ITEM_19, LEFTOVERS
	.db ITEM_2D, BITTER_BERRY
	.db ITEM_32, GOLD_BERRY
	.db ITEM_5A, BERRY
	.db ITEM_64, BERRY
	.db ITEM_78, BERRY
	.db ITEM_87, BERRY
	.db ITEM_BE, BERRY
	.db ITEM_C3, BERRY
	.db ITEM_DC, BERRY
	.db HM_08,   BERRY
	.db -1,      BERRY
	.db 0

	.align

RBYTMHMMoves1:
	.db MEGA_PUNCH
	.db RAZOR_WIND
	.db SWORDS_DANCE
	.db WHIRLWIND
	.db MEGA_KICK
	.db TOXIC
	.db HORN_DRILL
	.db BODY_SLAM
	.db TAKE_DOWN
	.db DOUBLE_EDGE
	.db BUBBLEBEAM
	.db WATER_GUN
	.db ICE_BEAM
	.db BLIZZARD
	.db HYPER_BEAM
	.db PAY_DAY
	.db SUBMISSION
	.db COUNTER
	.db SEISMIC_TOSS
	.db RAGE
	.db MEGA_DRAIN
	.db SOLARBEAM
	.db DRAGON_RAGE
	.db THUNDERBOLT
	.db THUNDER
	.db EARTHQUAKE
	.db FISSURE
	.db DIG
	.db PSYCHIC_M
	.db TELEPORT
	.db MIMIC
	.db DOUBLE_TEAM
	.db REFLECT
	.db BIDE
	.db METRONOME
	.db SELFDESTRUCT
	.db EGG_BOMB
	.db FIRE_BLAST
	.db SWIFT
	.db SKULL_BASH
	.db SOFTBOILED
	.db DREAM_EATER
	.db SKY_ATTACK
	.db REST
	.db THUNDER_WAVE
	.db PSYWAVE
	.db EXPLOSION
	.db ROCK_SLIDE
	.db TRI_ATTACK
	.db SUBSTITUTE
	.db CUT
	.db FLY
	.db SURF
	.db STRENGTH
	.db FLASH

	.align

Pokered_MonIndices1:
	.db RGBY_BULBASAUR
	.db RGBY_IVYSAUR
	.db RGBY_VENUSAUR
	.db RGBY_CHARMANDER
	.db RGBY_CHARMELEON
	.db RGBY_CHARIZARD
	.db RGBY_SQUIRTLE
	.db RGBY_WARTORTLE
	.db RGBY_BLASTOISE
	.db RGBY_CATERPIE
	.db RGBY_METAPOD
	.db RGBY_BUTTERFREE
	.db RGBY_WEEDLE
	.db RGBY_KAKUNA
	.db RGBY_BEEDRILL
	.db RGBY_PIDGEY
	.db RGBY_PIDGEOTTO
	.db RGBY_PIDGEOT
	.db RGBY_RATTATA
	.db RGBY_RATICATE
	.db RGBY_SPEAROW
	.db RGBY_FEAROW
	.db RGBY_EKANS
	.db RGBY_ARBOK
	.db RGBY_PIKACHU
	.db RGBY_RAICHU
	.db RGBY_SANDSHREW
	.db RGBY_SANDSLASH
	.db RGBY_NIDORAN_F
	.db RGBY_NIDORINA
	.db RGBY_NIDOQUEEN
	.db RGBY_NIDORAN_M
	.db RGBY_NIDORINO
	.db RGBY_NIDOKING
	.db RGBY_CLEFAIRY
	.db RGBY_CLEFABLE
	.db RGBY_VULPIX
	.db RGBY_NINETALES
	.db RGBY_JIGGLYPUFF
	.db RGBY_WIGGLYTUFF
	.db RGBY_ZUBAT
	.db RGBY_GOLBAT
	.db RGBY_ODDISH
	.db RGBY_GLOOM
	.db RGBY_VILEPLUME
	.db RGBY_PARAS
	.db RGBY_PARASECT
	.db RGBY_VENONAT
	.db RGBY_VENOMOTH
	.db RGBY_DIGLETT
	.db RGBY_DUGTRIO
	.db RGBY_MEOWTH
	.db RGBY_PERSIAN
	.db RGBY_PSYDUCK
	.db RGBY_GOLDUCK
	.db RGBY_MANKEY
	.db RGBY_PRIMEAPE
	.db RGBY_GROWLITHE
	.db RGBY_ARCANINE
	.db RGBY_POLIWAG
	.db RGBY_POLIWHIRL
	.db RGBY_POLIWRATH
	.db RGBY_ABRA
	.db RGBY_KADABRA
	.db RGBY_ALAKAZAM
	.db RGBY_MACHOP
	.db RGBY_MACHOKE
	.db RGBY_MACHAMP
	.db RGBY_BELLSPROUT
	.db RGBY_WEEPINBELL
	.db RGBY_VICTREEBEL
	.db RGBY_TENTACOOL
	.db RGBY_TENTACRUEL
	.db RGBY_GEODUDE
	.db RGBY_GRAVELER
	.db RGBY_GOLEM
	.db RGBY_PONYTA
	.db RGBY_RAPIDASH
	.db RGBY_SLOWPOKE
	.db RGBY_SLOWBRO
	.db RGBY_MAGNEMITE
	.db RGBY_MAGNETON
	.db RGBY_FARFETCH_D
	.db RGBY_DODUO
	.db RGBY_DODRIO
	.db RGBY_SEEL
	.db RGBY_DEWGONG
	.db RGBY_GRIMER
	.db RGBY_MUK
	.db RGBY_SHELLDER
	.db RGBY_CLOYSTER
	.db RGBY_GASTLY
	.db RGBY_HAUNTER
	.db RGBY_GENGAR
	.db RGBY_ONIX
	.db RGBY_DROWZEE
	.db RGBY_HYPNO
	.db RGBY_KRABBY
	.db RGBY_KINGLER
	.db RGBY_VOLTORB
	.db RGBY_ELECTRODE
	.db RGBY_EXEGGCUTE
	.db RGBY_EXEGGUTOR
	.db RGBY_CUBONE
	.db RGBY_MAROWAK
	.db RGBY_HITMONLEE
	.db RGBY_HITMONCHAN
	.db RGBY_LICKITUNG
	.db RGBY_KOFFING
	.db RGBY_WEEZING
	.db RGBY_RHYHORN
	.db RGBY_RHYDON
	.db RGBY_CHANSEY
	.db RGBY_TANGELA
	.db RGBY_KANGASKHAN
	.db RGBY_HORSEA
	.db RGBY_SEADRA
	.db RGBY_GOLDEEN
	.db RGBY_SEAKING
	.db RGBY_STARYU
	.db RGBY_STARMIE
	.db RGBY_MR_MIME
	.db RGBY_SCYTHER
	.db RGBY_JYNX
	.db RGBY_ELECTABUZZ
	.db RGBY_MAGMAR
	.db RGBY_PINSIR
	.db RGBY_TAUROS
	.db RGBY_MAGIKARP
	.db RGBY_GYARADOS
	.db RGBY_LAPRAS
	.db RGBY_DITTO
	.db RGBY_EEVEE
	.db RGBY_VAPOREON
	.db RGBY_JOLTEON
	.db RGBY_FLAREON
	.db RGBY_PORYGON
	.db RGBY_OMANYTE
	.db RGBY_OMASTAR
	.db RGBY_KABUTO
	.db RGBY_KABUTOPS
	.db RGBY_AERODACTYL
	.db RGBY_SNORLAX
	.db RGBY_ARTICUNO
	.db RGBY_ZAPDOS
	.db RGBY_MOLTRES
	.db RGBY_DRATINI
	.db RGBY_DRAGONAIR
	.db RGBY_DRAGONITE
	.db RGBY_MEWTWO
	.db RGBY_MEW

	.align

Pokered_MonIndices2:
	.db RHYDON
	.db KANGASKHAN
	.db NIDORAN_M
	.db CLEFAIRY
	.db SPEAROW
	.db VOLTORB
	.db NIDOKING
	.db SLOWBRO
	.db IVYSAUR
	.db EXEGGUTOR
	.db LICKITUNG
	.db EXEGGCUTE
	.db GRIMER
	.db GENGAR
	.db NIDORAN_F
	.db NIDOQUEEN
	.db CUBONE
	.db RHYHORN
	.db LAPRAS
	.db ARCANINE
	.db MEW
	.db GYARADOS
	.db SHELLDER
	.db TENTACOOL
	.db GASTLY
	.db SCYTHER
	.db STARYU
	.db BLASTOISE
	.db PINSIR
	.db TANGELA
	.db CHIKORITA
	.db CHIKORITA
	.db GROWLITHE
	.db ONIX
	.db FEAROW
	.db PIDGEY
	.db SLOWPOKE
	.db KADABRA
	.db GRAVELER
	.db CHANSEY
	.db MACHOKE
	.db MR_MIME
	.db HITMONLEE
	.db HITMONCHAN
	.db ARBOK
	.db PARASECT
	.db PSYDUCK
	.db DROWZEE
	.db GOLEM
	.db CHIKORITA
	.db MAGMAR
	.db CHIKORITA
	.db ELECTABUZZ
	.db MAGNETON
	.db KOFFING
	.db CHIKORITA
	.db MANKEY
	.db SEEL
	.db DIGLETT
	.db TAUROS
	.db CHIKORITA
	.db CHIKORITA
	.db CHIKORITA
	.db FARFETCH_D
	.db VENONAT
	.db DRAGONITE
	.db CHIKORITA
	.db CHIKORITA
	.db CHIKORITA
	.db DODUO
	.db POLIWAG
	.db JYNX
	.db MOLTRES
	.db ARTICUNO
	.db ZAPDOS
	.db DITTO
	.db MEOWTH
	.db KRABBY
	.db CHIKORITA
	.db CHIKORITA
	.db CHIKORITA
	.db VULPIX
	.db NINETALES
	.db PIKACHU
	.db RAICHU
	.db CHIKORITA
	.db CHIKORITA
	.db DRATINI
	.db DRAGONAIR
	.db KABUTO
	.db KABUTOPS
	.db HORSEA
	.db SEADRA
	.db CHIKORITA
	.db CHIKORITA
	.db SANDSHREW
	.db SANDSLASH
	.db OMANYTE
	.db OMASTAR
	.db JIGGLYPUFF
	.db WIGGLYTUFF
	.db EEVEE
	.db FLAREON
	.db JOLTEON
	.db VAPOREON
	.db MACHOP
	.db ZUBAT
	.db EKANS
	.db PARAS
	.db POLIWHIRL
	.db POLIWRATH
	.db WEEDLE
	.db KAKUNA
	.db BEEDRILL
	.db CHIKORITA
	.db DODRIO
	.db PRIMEAPE
	.db DUGTRIO
	.db VENOMOTH
	.db DEWGONG
	.db CHIKORITA
	.db CHIKORITA
	.db CATERPIE
	.db METAPOD
	.db BUTTERFREE
	.db MACHAMP
	.db CHIKORITA
	.db GOLDUCK
	.db HYPNO
	.db GOLBAT
	.db MEWTWO
	.db SNORLAX
	.db MAGIKARP
	.db CHIKORITA
	.db CHIKORITA
	.db MUK
	.db CHIKORITA
	.db KINGLER
	.db CLOYSTER
	.db CHIKORITA
	.db ELECTRODE
	.db CLEFABLE
	.db WEEZING
	.db PERSIAN
	.db MAROWAK
	.db CHIKORITA
	.db HAUNTER
	.db ABRA
	.db ALAKAZAM
	.db PIDGEOTTO
	.db PIDGEOT
	.db STARMIE
	.db BULBASAUR
	.db VENUSAUR
	.db TENTACRUEL
	.db CHIKORITA
	.db GOLDEEN
	.db SEAKING
	.db CHIKORITA
	.db CHIKORITA
	.db CHIKORITA
	.db CHIKORITA
	.db PONYTA
	.db RAPIDASH
	.db RATTATA
	.db RATICATE
	.db NIDORINO
	.db NIDORINA
	.db GEODUDE
	.db PORYGON
	.db AERODACTYL
	.db CHIKORITA
	.db MAGNEMITE
	.db CHIKORITA
	.db CHIKORITA
	.db CHARMANDER
	.db SQUIRTLE
	.db CHARMELEON
	.db WARTORTLE
	.db CHARIZARD
	.db CHIKORITA
	.db CHIKORITA
	.db CHIKORITA
	.db CHIKORITA
	.db ODDISH
	.db GLOOM
	.db VILEPLUME
	.db BELLSPROUT
	.db WEEPINBELL
	.db VICTREEBEL

	.align

Moves:
; effect
; power
; type
; accuracy
; pp
; effect chance

.incbin "baseromgs.n64",0x98430,0x98a14-0x98430


GSCTMHMMoves:
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

RBYTMHMMoves2:
	.db MEGA_PUNCH
	.db RAZOR_WIND
	.db SWORDS_DANCE
	.db WHIRLWIND
	.db MEGA_KICK
	.db TOXIC
	.db HORN_DRILL
	.db BODY_SLAM
	.db TAKE_DOWN
	.db DOUBLE_EDGE
	.db BUBBLEBEAM
	.db WATER_GUN
	.db ICE_BEAM
	.db BLIZZARD
	.db HYPER_BEAM
	.db PAY_DAY
	.db SUBMISSION
	.db COUNTER
	.db SEISMIC_TOSS
	.db RAGE
	.db MEGA_DRAIN
	.db SOLARBEAM
	.db DRAGON_RAGE
	.db THUNDERBOLT
	.db THUNDER
	.db EARTHQUAKE
	.db FISSURE
	.db DIG
	.db PSYCHIC_M
	.db TELEPORT
	.db MIMIC
	.db DOUBLE_TEAM
	.db REFLECT
	.db BIDE
	.db METRONOME
	.db SELFDESTRUCT
	.db EGG_BOMB
	.db FIRE_BLAST
	.db SWIFT
	.db SKULL_BASH
	.db SOFTBOILED
	.db DREAM_EATER
	.db SKY_ATTACK
	.db REST
	.db THUNDER_WAVE
	.db PSYWAVE
	.db EXPLOSION
	.db ROCK_SLIDE
	.db TRI_ATTACK
	.db SUBSTITUTE
	.db CUT
	.db FLY
	.db SURF
	.db STRENGTH
	.db FLASH

	.align 16

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

.incbin "baseromgs.n64",0x9a4b2,0xa2250-0x9a4b2

GameBoyHeaderLogo:
	.db 0xCE,0xED,0x66,0x66,0xCC,0x0D,0x00,0x0B
	.db 0x03,0x73,0x00,0x83,0x00,0x0C,0x00,0x0D
	.db 0x00,0x08,0x11,0x1F,0x88,0x89,0x00,0x0E
	.db 0xDC,0xCC,0x6E,0xE6,0xDD,0xDD,0xD9,0x99
	.db 0xBB,0xBB,0x67,0x63,0x6E,0x0E,0xEC,0xCC
	.db 0xDD,0xDC,0x99,0x9F,0xBB,0xB9,0x33,0x3E

.incbin "baseromgs.n64",0xa2280,0x3f4ca0-0xa2280

StatLevelMultipliers:
        db 25, 100 ; 0.25×
        db 28, 100 ; 0.28×
        db 33, 100 ; 0.33×
        db 40, 100 ; 0.40×
        db 50, 100 ; 0.50×
        db 66, 100 ; 0.66×
        db  1,   1 ; 1.00×
        db 15,  10 ; 1.50×
        db  2,   1 ; 2.00×
        db 25,  10 ; 2.50×
        db  3,   1 ; 3.00×
        db 35,  10 ; 3.50×
        db  4,   1 ; 4.00×

	.align

AccuracyProbabilities:
	.db  33, 100 ;  33% −6
	.db  36, 100 ;  36% −5
	.db  43, 100 ;  43% −4
	.db  50, 100 ;  50% −3
	.db  60, 100 ;  60% −2
	.db  75, 100 ;  75% −1
	.db   1,   1 ; 100%  0
	.db 133, 100 ; 133% +1
	.db 166, 100 ; 166% +2
	.db   2,   1 ; 200% +3
	.db 233, 100 ; 233% +4
	.db 133,  50 ; 266% +5
	.db   3,   1 ; 300% +6

	.align

.incbin "baseromgs.n64",0x3f4cd8,0x3f4d0c-0x3f4cd8

CriticalMoves:
	.db KARATE_CHOP
	.db RAZOR_WIND
	.db RAZOR_LEAF
	.db CRABHAMMER
	.db SLASH
	.db AEROBLAST
	.db CROSS_CHOP
	.db -1

CriticalChances:
	.db 0x11 ; 6.25%
	.db 0x20 ; 12.1%
	.db 0x40 ; 24.6%
	.db 0x55 ; 33.2%
	.db 0x80 ; 49.6%
	.db 0x80 ; 49.6%
	.db 0x80 ; 49.6%

	.align

MetronomeExcepts:
	.db METRONOME
	.db STRUGGLE
	.db SKETCH
	.db MIMIC
	.db COUNTER
	.db MIRROR_COAT
	.db PROTECT
	.db DETECT
	.db ENDURE
	.db DESTINY_BOND
	.db SLEEP_TALK
	.db THIEF
	.db -1

	.align

ConsumableEffects:
	.db HELD_BERRY
	.db HELD_2
	.db HELD_5
	.db HELD_HEAL_POISON
	.db HELD_HEAL_FREEZE
	.db HELD_HEAL_BURN
	.db HELD_HEAL_SLEEP
	.db HELD_HEAL_PARALYZE
	.db HELD_HEAL_STATUS
	.db HELD_30
	.db HELD_ATTACK_UP
	.db HELD_DEFENSE_UP
	.db HELD_SPEED_UP
	.db HELD_SP_ATTACK_UP
	.db HELD_SP_DEFENSE_UP
	.db HELD_ACCURACY_UP
	.db HELD_EVASION_UP
	.db HELD_38
	.db HELD_71
	.db HELD_ESCAPE
	.db HELD_CRITICAL_UP
	.db -1

	.align

MoveGrammar0:
	.db SWORDS_DANCE
	.db GROWTH
	.db STRENGTH
	.db HARDEN
	.db MINIMIZE
	.db SMOKESCREEN
	.db WITHDRAW
	.db DEFENSE_CURL
	.db EGG_BOMB
	.db SMOG
	.db BONE_CLUB
	.db FLASH
	.db SPLASH
	.db ACID_ARMOR
	.db BONEMERANG
	.db REST
	.db SHARPEN
	.db SUBSTITUTE
	.db MIND_READER
	.db SNORE
	.db PROTECT
	.db SPIKES
	.db ENDURE
	.db ROLLOUT
	.db SWAGGER
	.db SLEEP_TALK
	.db HIDDEN_POWER
	.db PSYCH_UP
	.db EXTREMESPEED
	.db -1

	.align

MoveGrammar1:
	.db RECOVER
	.db TELEPORT
	.db BIDE
	.db SELFDESTRUCT
	.db AMNESIA
	.db FLAIL
	.db -1

	.align

MoveGrammar2:
	.db MEDITATE
	.db AGILITY
	.db MIMIC
	.db DOUBLE_TEAM
	.db BARRAGE
	.db TRANSFORM
	.db STRUGGLE
	.db SCARY_FACE
	.db -1

	.align

MoveGrammar3:
	.db POUND
	.db SCRATCH
	.db VICEGRIP
	.db WING_ATTACK
	.db FLY
	.db BIND
	.db SLAM
	.db HORN_ATTACK
	.db WRAP
	.db THRASH
	.db TAIL_WHIP
	.db LEER
	.db BITE
	.db GROWL
	.db ROAR
	.db SING
	.db PECK
	.db ABSORB
	.db STRING_SHOT
	.db EARTHQUAKE
	.db FISSURE
	.db DIG
	.db TOXIC
	.db SCREECH
	.db METRONOME
	.db LICK
	.db CLAMP
	.db CONSTRICT
	.db POISON_GAS
	.db BUBBLE
	.db SLASH
	.db SPIDER_WEB
	.db NIGHTMARE
	.db CURSE
	.db FORESIGHT
	.db CHARM
	.db ATTRACT
	.db ROCK_SMASH
	.db -1

	.align

BattleData0x03F4DA0: ; XXX what is this?
	.db 0x01
	.db 0x02
	.db 0x03
	.db 0x04
	.db 0x59
	.db 0x05
	.db 0x06
	.db 0x07
	.db 0xa1
	.db 0x08
	.db 0x09
	.db 0x0a
	.db 0x0b
	.db 0xa2
	.db 0x0c
	.db 0x0d
	.db 0x44
	.db -1

	.align

BattleData0x03F4DB4: ; XXX what is this?
	.db 0x01
	.db 0x02
	.db 0x07
	.db 0xA1
	.db 0x5C
	.db 0x0F
	.db -1

	.align

BattleData0x03F4DBC: ; XXX what is this?
	.db 0x01
	.db 0x02
	.db 0x03
	.db 0x04
	.db 0x59
	.db 0x05
	.db 0x06
	.db 0x07
	.db 0x87
	.db 0xa1
	.db 0x08
	.db 0x09
	.db 0x0a
	.db 0x0b
	.db 0xa2
	.db 0x0c
	.db 0x0d
	.db 0x0e
	.db -1

	.align

BattleData0x03F4DD0: ; XXX what is this?
	.db 0x01
	.db 0x02
	.db 0x03
	.db 0x04
	.db 0x59
	.db 0x05
	.db 0x06
	.db 0x07
	.db 0xa1
	.db 0x08
	.db 0x09
	.db 0x0a
	.db 0x0b
	.db 0xa2
	.db 0x10
	.db 0x0c
	.db 0x0d
	.db 0x44
	.db -1

	.align

BattleData0x03F4DE4: ; XXX what is this?
	.db 0x01
	.db 0x02
	.db 0x03
	.db 0x04
	.db 0x59
	.db 0x05
	.db 0x06
	.db 0x07
	.db 0x87
	.db 0xa1
	.db 0x08
	.db 0x09
	.db 0x0a
	.db 0x0b
	.db 0xa2
	.db 0x0c
	.db 0x0d
	.db 0x12
	.db -1

	.align

BattleData0x03F4DF8: ; XXX what is this?
	.db 0x01
	.db 0x02
	.db 0x03
	.db 0x04
	.db 0x59
	.db 0x05
	.db 0x06
	.db 0x07
	.db 0x87
	.db 0xa1
	.db 0x08
	.db 0x09
	.db 0x0a
	.db 0x0b
	.db 0xa2
	.db 0x0c
	.db 0x0d
	.db 0x13
	.db -1

	.align

BattleData0x03F4E0C: ; XXX what is this?
	.db 0x01
	.db 0x02
	.db 0x03
	.db 0x04
	.db 0x59
	.db 0x05
	.db 0x06
	.db 0x07
	.db 0x87
	.db 0xa1
	.db 0x08
	.db 0x09
	.db 0x0a
	.db 0x0b
	.db 0xa2
	.db 0x0c
	.db 0x0d
	.db 0x14
	.db -1

	.align

; arrays like the above continue in the same vein until 0x3f54cc
.incbin "baseromgs.n64",0x3f4e20,0x3f54cc-0x3f4e20

; XXX what is this?
; appears to be a repetitive array of 32-bit data?
.incbin "baseromgs.n64",0x3f54cc,0x3f59e0-0x3f54cc


.incbin "baseromgs.n64",0x3f59e0,0x23a5000-0x3f59e0

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
