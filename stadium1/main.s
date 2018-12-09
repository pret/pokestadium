.create "pokestadium.n64",0
.n64
.include "constants/pokemon_constants.s"
.include "constants/move_constants.s"

.include "rom_header.s"

.incbin "baserom.n64",0x40,0xC3F0-0x40

	lw a3,0x8(a0)
	lw t9,0xC(a0)
	lw t8,0x4(a0)
	add a3,a3,a0

.incbin "baserom.n64",0xC400,0x43478-0xC400

Normal43478:
	jr ra
	or $v0,$r0,$r0

Fire43478:
	jr ra
	addiu $v0,$r0,1

Water43478:
	jr ra
	addiu $v0,$r0,2

Electric43478:
	jr ra
	addiu $v0,$r0,3

Grass43478:
	jr ra
	addiu $v0,$r0,4

Ice43478:
	jr ra
	addiu $v0,$r0,5

Fighting43478:
	jr ra
	addiu $v0,$r0,6

Poison43478:
	jr ra
	addiu $v0,$r0,7

Ground43478:
	jr ra
	addiu $v0,$r0,8

Flying43478:
	jr ra
	addiu $v0,$r0,9

Psychic43478:
	jr ra
	addiu $v0,$r0,10

Bug43478:
	jr ra
	addiu $v0,$r0,11

Rock43478:
	jr ra
	addiu $v0,$r0,12

Ghost43478:
	jr ra
	addiu $v0,$r0,13

Dragon43478:
	jr ra
	addiu $v0,$r0,14

Invalid43478:
	or $v0,$r0,$r0
	jr ra
	nop

.incbin "baserom.n64",0x434FC,0x73C30-0x434FC

CharMap:
	.db 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20 ;
	.db 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20 ;
	.db 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20 ;
	.db 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20 ;
	.db 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20 ;
	.db 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20 ;
	.db 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20 ;
	.db 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20 ;
	.db 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20 ;
	.db 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20 ;
	.db 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20 ;
	.db 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20 ;
	.db 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20 ;
	.db 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20 ;
	.db 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20 ;
	.db 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20 ;
	.db 0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48 ; A  B  C  D  E  F  G  H
	.db 0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,0x50 ; I  J  K  L  M  N  O  P
	.db 0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58 ; Q  R  S  T  U  V  W  X
	.db 0x59,0x5A,0x28,0x29,0x3A,0x3B,0x5B,0x5D ; Y  Z  (  )  :  ;  [  ]
	.db 0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68 ; a  b  c  d  e  f  g  h
	.db 0x69,0x6A,0x6B,0x6C,0x6D,0x6E,0x6F,0x70 ; i  j  k  l  m  n  o  p
	.db 0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78 ; q  r  s  t  u  v  w  x
	.db 0x79,0x7A,0xE0,0xE8,0xE9,0xF9,0xDF,0xE7 ; y  z  à  è  é  ù  ß  ç
	.db 0xC4,0xD6,0xDC,0xE4,0xF6,0xFC,0xEB,0xEF ; Ä  Ö  Ü  ä  ö  ü  ë  ï
	.db 0xE2,0xF4,0xFB,0xEA,0xEE,0x20,0x20,0x20 ; â  ô  û  ê  î
	.db 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20 ;
	.db 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20 ;
	.db 0x27,0xBC,0xBD,0x2D,0x2B,0x20,0x3F,0x21 ; '  ¼  ½  -  +     ?  !
	.db 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0xA9 ;                      ♂
	.db 0xA5,0xD7,0x2E,0x2F,0x2C,0xBE,0x30,0x31 ; ¥  ×  .  /  ,  ♀  0  1
	.db 0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39 ; 2  3  4  5  6  7  8  9

.incbin "baserom.n64",0x73D30,0x100

TMHMMoves:
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

	.align 4

MonIndices1:
; Pokédex order.
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

	.align 4

MonIndices2:
; Pokémon in RGBY internal order.
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
	.db PKMN_152
	.db PKMN_152
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
	.db PKMN_152
	.db MAGMAR
	.db PKMN_152
	.db ELECTABUZZ
	.db MAGNETON
	.db KOFFING
	.db PKMN_152
	.db MANKEY
	.db SEEL
	.db DIGLETT
	.db TAUROS
	.db PKMN_152
	.db PKMN_152
	.db PKMN_152
	.db FARFETCH_D
	.db VENONAT
	.db DRAGONITE
	.db PKMN_152
	.db PKMN_152
	.db PKMN_152
	.db DODUO
	.db POLIWAG
	.db JYNX
	.db MOLTRES
	.db ARTICUNO
	.db ZAPDOS
	.db DITTO
	.db MEOWTH
	.db KRABBY
	.db PKMN_152
	.db PKMN_152
	.db PKMN_152
	.db VULPIX
	.db NINETALES
	.db PIKACHU
	.db RAICHU
	.db PKMN_152
	.db PKMN_152
	.db DRATINI
	.db DRAGONAIR
	.db KABUTO
	.db KABUTOPS
	.db HORSEA
	.db SEADRA
	.db PKMN_152
	.db PKMN_152
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
	.db PKMN_152
	.db DODRIO
	.db PRIMEAPE
	.db DUGTRIO
	.db VENOMOTH
	.db DEWGONG
	.db PKMN_152
	.db PKMN_152
	.db CATERPIE
	.db METAPOD
	.db BUTTERFREE
	.db MACHAMP
	.db PKMN_152
	.db GOLDUCK
	.db HYPNO
	.db GOLBAT
	.db MEWTWO
	.db SNORLAX
	.db MAGIKARP
	.db PKMN_152
	.db PKMN_152
	.db MUK
	.db PKMN_152
	.db KINGLER
	.db CLOYSTER
	.db PKMN_152
	.db ELECTRODE
	.db CLEFABLE
	.db WEEZING
	.db PERSIAN
	.db MAROWAK
	.db PKMN_152
	.db HAUNTER
	.db ABRA
	.db ALAKAZAM
	.db PIDGEOTTO
	.db PIDGEOT
	.db STARMIE
	.db BULBASAUR
	.db VENUSAUR
	.db TENTACRUEL
	.db PKMN_152
	.db GOLDEEN
	.db SEAKING
	.db PKMN_152
	.db PKMN_152
	.db PKMN_152
	.db PKMN_152
	.db PONYTA
	.db RAPIDASH
	.db RATTATA
	.db RATICATE
	.db NIDORINO
	.db NIDORINA
	.db GEODUDE
	.db PORYGON
	.db AERODACTYL
	.db PKMN_152
	.db MAGNEMITE
	.db PKMN_152
	.db PKMN_152
	.db CHARMANDER
	.db SQUIRTLE
	.db CHARMELEON
	.db WARTORTLE
	.db CHARIZARD
	.db PKMN_152
	.db PKMN_152
	.db PKMN_152
	.db PKMN_152
	.db ODDISH
	.db GLOOM
	.db VILEPLUME
	.db BELLSPROUT
	.db WEEPINBELL
	.db VICTREEBEL

	.align 4

MonIndices3:
; Pokémon in Japanese “alphabetical” order.
	.db EKANS      ; アーボ
	.db ARBOK      ; アーボック
	.db SEAKING    ; アズマオウ
	.db EEVEE      ; イーブイ
	.db GEODUDE    ; イシツブテ
	.db ONIX       ; イワーク
	.db ARCANINE   ; ウインディ
	.db WEEPINBELL ; ウツドン
	.db VICTREEBEL ; ウツボット
	.db HITMONCHAN ; エビワラー
	.db ELECTABUZZ ; エレブー
	.db PRIMEAPE   ; オコリザル
	.db SPEAROW    ; オニスズメ
	.db FEAROW     ; オニドリル
	.db OMASTAR    ; オムスター
	.db OMANYTE    ; オムナイト
	.db GROWLITHE  ; ガーディ
	.db MACHAMP    ; カイリキー
	.db DRAGONITE  ; カイリュー
	.db PINSIR     ; カイロス
	.db SNORLAX    ; カビゴン
	.db KABUTO     ; カブト
	.db KABUTOPS   ; カブトプス
	.db WARTORTLE  ; カメール
	.db BLASTOISE  ; カメックス
	.db FARFETCH_D ; カモネギ
	.db CUBONE     ; カラカラ
	.db MAROWAK    ; ガラガラ
	.db KANGASKHAN ; ガルーラ
	.db CATERPIE   ; キャタピー
	.db GYARADOS   ; ギャラドス
	.db RAPIDASH   ; ギャロップ
	.db NINETALES  ; キュウコン
	.db KINGLER    ; キングラー
	.db GLOOM      ; クサイハナ
	.db KRABBY     ; クラブ
	.db ABRA       ; ケーシィ
	.db GENGAR     ; ゲンガー
	.db TAUROS     ; ケンタロス
	.db MAGIKARP   ; コイキング
	.db MAGNEMITE  ; コイル
	.db GASTLY     ; ゴース
	.db HAUNTER    ; ゴースト
	.db MACHOKE    ; ゴーリキー
	.db KAKUNA     ; コクーン
	.db PSYDUCK    ; コダック
	.db RATTATA    ; コラッタ
	.db GOLDUCK    ; ゴルダック
	.db GOLBAT     ; ゴルバット
	.db GOLEM      ; ゴローニャ
	.db GRAVELER   ; ゴローン
	.db VENONAT    ; コンパン
	.db RHYDON     ; サイドン
	.db RHYHORN    ; サイホーン
	.db HITMONLEE  ; サワムラー
	.db ZAPDOS     ; サンダー
	.db JOLTEON    ; サンダース
	.db SANDSHREW  ; サンド
	.db SANDSLASH  ; サンドパン
	.db SEADRA     ; シードラ
	.db SHELLDER   ; シェルダー
	.db VAPOREON   ; シャワーズ
	.db DEWGONG    ; ジュゴン
	.db STARMIE    ; スターミー
	.db SCYTHER    ; ストライク
	.db ZUBAT      ; ズバット
	.db BEEDRILL   ; スピアー
	.db HYPNO      ; スリーパー
	.db DROWZEE    ; スリープ
	.db SQUIRTLE   ; ゼニガメ
	.db DUGTRIO    ; ダグトリオ
	.db HORSEA     ; タッツー
	.db EXEGGCUTE  ; タマタマ
	.db DIGLETT    ; ディグダ
	.db DODUO      ; ドードー
	.db DODRIO     ; ドードリオ
	.db KOFFING    ; ドガース
	.db TENTACRUEL ; ドククラゲ
	.db GOLDEEN    ; トサキント
	.db METAPOD    ; トランセル
	.db ODDISH     ; ナゾノクサ
	.db EXEGGUTOR  ; ナッシー
	.db NIDOKING   ; ニドキング
	.db NIDOQUEEN  ; ニドクイン
	.db NIDORAN_M  ; ニドラン♂
	.db NIDORAN_F  ; ニドラン♀
	.db NIDORINA   ; ニドリーナ
	.db NIDORINO   ; ニドリーノ
	.db MEOWTH     ; ニャース
	.db POLIWHIRL  ; ニョロゾ
	.db POLIWRATH  ; ニョロボン
	.db POLIWAG    ; ニョロモ
	.db SEEL       ; パウワウ
	.db DRAGONAIR  ; ハクリュー
	.db BUTTERFREE ; バタフリー
	.db PARAS      ; パラス
	.db PARASECT   ; パラセクト
	.db MR_MIME    ; バリヤード
	.db CLOYSTER   ; パルシェン
	.db WEEDLE     ; ビードル
	.db PIKACHU    ; ピカチュウ
	.db CLEFABLE   ; ピクシー
	.db PIDGEOT    ; ピジョット
	.db PIDGEOTTO  ; ピジョン
	.db CLEFAIRY   ; ピッピ
	.db CHARMANDER ; ヒトカゲ
	.db STARYU     ; ヒトデマン
	.db VOLTORB    ; ビリリダマ
	.db MOLTRES    ; ファイヤー
	.db FLAREON    ; ブースター
	.db ALAKAZAM   ; フーディン
	.db MAGMAR     ; ブーバー
	.db WIGGLYTUFF ; プクリン
	.db IVYSAUR    ; フシギソウ
	.db BULBASAUR  ; フシギダネ
	.db VENUSAUR   ; フシギバナ
	.db AERODACTYL ; プテラ
	.db ARTICUNO   ; フリーザー
	.db JIGGLYPUFF ; プリン
	.db GRIMER     ; ベトベター
	.db MUK        ; ベトベトン
	.db PERSIAN    ; ペルシアン
	.db LICKITUNG  ; ベロリンガ
	.db PIDGEY     ; ポッポ
	.db PONYTA     ; ポニータ
	.db PORYGON    ; ポリゴン
	.db BELLSPROUT ; マダツボミ
	.db WEEZING    ; マタドガス
	.db ELECTRODE  ; マルマイン
	.db MANKEY     ; マンキー
	.db DRATINI    ; ミニリュウ
	.db MEW        ; ミュウ
	.db MEWTWO     ; ミュウツー
	.db DITTO      ; メタモン
	.db TENTACOOL  ; メノクラゲ
	.db VENOMOTH   ; モルフォン
	.db TANGELA    ; モンジャラ
	.db SLOWBRO    ; ヤドラン
	.db SLOWPOKE   ; ヤドン
	.db KADABRA    ; ユンゲラー
	.db RAICHU     ; ライチュウ
	.db CHANSEY    ; ラッキー
	.db RATICATE   ; ラッタ
	.db LAPRAS     ; ラプラス
	.db VILEPLUME  ; ラフレシア
	.db CHARMELEON ; リザード
	.db CHARIZARD  ; リザードン
	.db JYNX       ; ルージュラ
	.db MAGNETON   ; レアコイル
	.db VULPIX     ; ロコン
	.db MACHOP     ; ワンリキー

	.align 4

MonIndices4:
; Inverse gojuuon.
	.db ABC_BULBASAUR
	.db ABC_IVYSAUR
	.db ABC_VENUSAUR
	.db ABC_CHARMANDER
	.db ABC_CHARMELEON
	.db ABC_CHARIZARD
	.db ABC_SQUIRTLE
	.db ABC_WARTORTLE
	.db ABC_BLASTOISE
	.db ABC_CATERPIE
	.db ABC_METAPOD
	.db ABC_BUTTERFREE
	.db ABC_WEEDLE
	.db ABC_KAKUNA
	.db ABC_BEEDRILL
	.db ABC_PIDGEY
	.db ABC_PIDGEOTTO
	.db ABC_PIDGEOT
	.db ABC_RATTATA
	.db ABC_RATICATE
	.db ABC_SPEAROW
	.db ABC_FEAROW
	.db ABC_EKANS
	.db ABC_ARBOK
	.db ABC_PIKACHU
	.db ABC_RAICHU
	.db ABC_SANDSHREW
	.db ABC_SANDSLASH
	.db ABC_NIDORAN_F
	.db ABC_NIDORINA
	.db ABC_NIDOQUEEN
	.db ABC_NIDORAN_M
	.db ABC_NIDORINO
	.db ABC_NIDOKING
	.db ABC_CLEFAIRY
	.db ABC_CLEFABLE
	.db ABC_VULPIX
	.db ABC_NINETALES
	.db ABC_JIGGLYPUFF
	.db ABC_WIGGLYTUFF
	.db ABC_ZUBAT
	.db ABC_GOLBAT
	.db ABC_ODDISH
	.db ABC_GLOOM
	.db ABC_VILEPLUME
	.db ABC_PARAS
	.db ABC_PARASECT
	.db ABC_VENONAT
	.db ABC_VENOMOTH
	.db ABC_DIGLETT
	.db ABC_DUGTRIO
	.db ABC_MEOWTH
	.db ABC_PERSIAN
	.db ABC_PSYDUCK
	.db ABC_GOLDUCK
	.db ABC_MANKEY
	.db ABC_PRIMEAPE
	.db ABC_GROWLITHE
	.db ABC_ARCANINE
	.db ABC_POLIWAG
	.db ABC_POLIWHIRL
	.db ABC_POLIWRATH
	.db ABC_ABRA
	.db ABC_KADABRA
	.db ABC_ALAKAZAM
	.db ABC_MACHOP
	.db ABC_MACHOKE
	.db ABC_MACHAMP
	.db ABC_BELLSPROUT
	.db ABC_WEEPINBELL
	.db ABC_VICTREEBEL
	.db ABC_TENTACOOL
	.db ABC_TENTACRUEL
	.db ABC_GEODUDE
	.db ABC_GRAVELER
	.db ABC_GOLEM
	.db ABC_PONYTA
	.db ABC_RAPIDASH
	.db ABC_SLOWPOKE
	.db ABC_SLOWBRO
	.db ABC_MAGNEMITE
	.db ABC_MAGNETON
	.db ABC_FARFETCH_D
	.db ABC_DODUO
	.db ABC_DODRIO
	.db ABC_SEEL
	.db ABC_DEWGONG
	.db ABC_GRIMER
	.db ABC_MUK
	.db ABC_SHELLDER
	.db ABC_CLOYSTER
	.db ABC_GASTLY
	.db ABC_HAUNTER
	.db ABC_GENGAR
	.db ABC_ONIX
	.db ABC_DROWZEE
	.db ABC_HYPNO
	.db ABC_KRABBY
	.db ABC_KINGLER
	.db ABC_VOLTORB
	.db ABC_ELECTRODE
	.db ABC_EXEGGCUTE
	.db ABC_EXEGGUTOR
	.db ABC_CUBONE
	.db ABC_MAROWAK
	.db ABC_HITMONLEE
	.db ABC_HITMONCHAN
	.db ABC_LICKITUNG
	.db ABC_KOFFING
	.db ABC_WEEZING
	.db ABC_RHYHORN
	.db ABC_RHYDON
	.db ABC_CHANSEY
	.db ABC_TANGELA
	.db ABC_KANGASKHAN
	.db ABC_HORSEA
	.db ABC_SEADRA
	.db ABC_GOLDEEN
	.db ABC_SEAKING
	.db ABC_STARYU
	.db ABC_STARMIE
	.db ABC_MR_MIME
	.db ABC_SCYTHER
	.db ABC_JYNX
	.db ABC_ELECTABUZZ
	.db ABC_MAGMAR
	.db ABC_PINSIR
	.db ABC_TAUROS
	.db ABC_MAGIKARP
	.db ABC_GYARADOS
	.db ABC_LAPRAS
	.db ABC_DITTO
	.db ABC_EEVEE
	.db ABC_VAPOREON
	.db ABC_JOLTEON
	.db ABC_FLAREON
	.db ABC_PORYGON
	.db ABC_OMANYTE
	.db ABC_OMASTAR
	.db ABC_KABUTO
	.db ABC_KABUTOPS
	.db ABC_AERODACTYL
	.db ABC_SNORLAX
	.db ABC_ARTICUNO
	.db ABC_ZAPDOS
	.db ABC_MOLTRES
	.db ABC_DRATINI
	.db ABC_DRAGONAIR
	.db ABC_DRAGONITE
	.db ABC_MEWTWO
	.db ABC_MEW

	.align 4

MoveIndices1:
; Moves in Japanese “alphabetical” order.
	.db THUNDERBOLT-1  ; １０まんボルト
	.db LOVELY_KISS-1  ; あくまのキッス
	.db DIG-1          ; あなをほる
	.db THRASH-1       ; あばれる
	.db CONFUSE_RAY-1  ; あやしいひかり
	.db BUBBLE-1       ; あわ
	.db CUT-1          ; いあいぎり
	.db RAGE-1         ; いかり
	.db SUPER_FANG-1   ; いかりのまえば
	.db STRING_SHOT-1  ; いとをはく
	.db SCREECH-1      ; いやなおと
	.db ROCK_THROW-1   ; いわおとし
	.db ROCK_SLIDE-1   ; いわなだれ
	.db SING-1         ; うたう
	.db SMOKESCREEN-1  ; えんまく
	.db DOUBLESLAP-1   ; おうふくビンタ
	.db MIRROR_MOVE-1  ; オウムがえし
	.db AURORA_BEAM-1  ; オーロラビーム
	.db STRENGTH-1     ; かいりき
	.db COUNTER-1      ; カウンター
	.db FLAMETHROWER-1 ; かえんほうしゃ
	.db SHARPEN-1      ; かくばる
	.db DOUBLE_TEAM-1  ; かげぶんしん
	.db GUST-1         ; かぜおこし
	.db HARDEN-1       ; かたくなる
	.db DISABLE-1      ; かなしばり
	.db RAZOR_WIND-1   ; かまいたち
	.db BIDE-1         ; がまん
	.db BITE-1         ; かみつく
	.db THUNDER-1      ; かみなり
	.db THUNDERPUNCH-1 ; かみなりパンチ
	.db KARATE_CHOP-1  ; からてチョップ
	.db CLAMP-1        ; からではさむ
	.db WITHDRAW-1     ; からにこもる
	.db CONSTRICT-1    ; からみつく
	.db FOCUS_ENERGY-1 ; きあいだめ
	.db SPORE-1        ; キノコのほうし
	.db LEECH_LIFE-1   ; きゅうけつ
	.db SLASH-1        ; きりさく
	.db CRABHAMMER-1   ; クラブハンマー
	.db HAZE-1         ; くろいきり
	.db LOW_KICK-1     ; けたぐり
	.db AGILITY-1      ; こうそくいどう
	.db SKY_ATTACK-1   ; ゴッドバード
	.db PSYBEAM-1      ; サイケこうせん
	.db PSYWAVE-1      ; サイコウェーブ
	.db PSYCHIC_M-1    ; サイコキネシス
	.db HYPNOSIS-1     ; さいみんじゅつ
	.db SUBMISSION-1   ; じごくぐるま
	.db RECOVER-1      ; じこさいせい
	.db EARTHQUAKE-1   ; じしん
	.db LICK-1         ; したでなめる
	.db TAIL_WHIP-1    ; しっぽをふる
	.db SELFDESTRUCT-1 ; じばく
	.db STUN_SPORE-1   ; しびれごな
	.db BIND-1         ; しめつける
	.db MIST-1         ; しろいきり
	.db FISSURE-1      ; じわれ
	.db ABSORB-1       ; すいとる
	.db HEADBUTT-1     ; ずつき
	.db DOUBLE_EDGE-1  ; すてみタックル
	.db SAND_ATTACK-1  ; すなかけ
	.db SWIFT-1        ; スピードスター
	.db KINESIS-1      ; スプーンまげ
	.db SMOG-1         ; スモッグ
	.db GROWTH-1       ; せいちょう
	.db SOLARBEAM-1    ; ソーラービーム
	.db SONICBOOM-1    ; ソニックブーム
	.db FLY-1          ; そらをとぶ
	.db TACKLE-1       ; たいあたり
	.db EXPLOSION-1    ; だいばくはつ
	.db FIRE_BLAST-1   ; だいもんじ
	.db WATERFALL-1    ; たきのぼり
	.db SLAM-1         ; たたきつける
	.db TWINEEDLE-1    ; ダブルニードル
	.db SOFTBOILED-1   ; タマゴうみ
	.db EGG_BOMB-1     ; タマゴばくだん
	.db BARRAGE-1      ; たまなげ
	.db MINIMIZE-1     ; ちいさくなる
	.db SEISMIC_TOSS-1 ; ちきゅうなげ
	.db SUPERSONIC-1   ; ちょうおんぱ
	.db PECK-1         ; つつく
	.db HORN_ATTACK-1  ; つのでつく
	.db HORN_DRILL-1   ; つのドリル
	.db WING_ATTACK-1  ; つばさでうつ
	.db SWORDS_DANCE-1 ; つるぎのまい
	.db VINE_WHIP-1    ; つるのムチ
	.db CONVERSION-1   ; テクスチャー
	.db TELEPORT-1     ; テレポート
	.db THUNDERSHOCK-1 ; でんきショック
	.db QUICK_ATTACK-1 ; でんこうせっか
	.db THUNDER_WAVE-1 ; でんじは
	.db POISON_GAS-1   ; どくガス
	.db TOXIC-1        ; どくどく
	.db POISONPOWDER-1 ; どくのこな
	.db POISON_STING-1 ; どくばり
	.db SPIKE_CANNON-1 ; とげキャノン
	.db ACID_ARMOR-1   ; とける
	.db TAKE_DOWN-1    ; とっしん
	.db JUMP_KICK-1    ; とびげり
	.db HI_JUMP_KICK-1 ; とびひざげり
	.db TRI_ATTACK-1   ; トライアタック
	.db DRILL_PECK-1   ; ドリルくちばし
	.db AMNESIA-1      ; ドわすれ
	.db NIGHT_SHADE-1  ; ナイトヘッド
	.db GROWL-1        ; なきごえ
	.db SURF-1         ; なみのり
	.db DOUBLE_KICK-1  ; にどげり
	.db LEER-1         ; にらみつける
	.db PAY_DAY-1      ; ネコにこばん
	.db SLEEP_POWDER-1 ; ねむりごな
	.db REST-1         ; ねむる
	.db CONFUSION-1    ; ねんりき
	.db BODY_SLAM-1    ; のしかかり
	.db HYDRO_PUMP-1   ; ハイドロポンプ
	.db HYPER_BEAM-1   ; はかいこうせん
	.db GUILLOTINE-1   ; ハサミギロチン
	.db VICEGRIP-1     ; はさむ
	.db POUND-1        ; はたく
	.db RAZOR_LEAF-1   ; はっぱカッター
	.db PETAL_DANCE-1  ; はなびらのまい
	.db SPLASH-1       ; はねる
	.db BUBBLEBEAM-1   ; バブルこうせん
	.db BARRIER-1      ; バリアー
	.db LIGHT_SCREEN-1 ; ひかりのかべ
	.db SCRATCH-1      ; ひっかく
	.db HYPER_FANG-1   ; ひっさつまえば
	.db EMBER-1        ; ひのこ
	.db DIZZY_PUNCH-1  ; ピヨピヨパンチ
	.db WHIRLWIND-1    ; ふきとばし
	.db BLIZZARD-1     ; ふぶき
	.db STOMP-1        ; ふみつけ
	.db FLASH-1        ; フラッシュ
	.db SLUDGE-1       ; ヘドロこうげき
	.db GLARE-1        ; へびにらみ
	.db TRANSFORM-1    ; へんしん
	.db ROAR-1         ; ほえる
	.db BONE_CLUB-1    ; ホネこんぼう
	.db BONEMERANG-1   ; ホネブーメラン
	.db FIRE_SPIN-1    ; ほのおのうず
	.db FIRE_PUNCH-1   ; ほのおのパンチ
	.db WRAP-1         ; まきつく
	.db DEFENSE_CURL-1 ; まるくなる
	.db ROLLING_KICK-1 ; まわしげり
	.db SUBSTITUTE-1   ; みがわり
	.db PIN_MISSILE-1  ; ミサイルばり
	.db WATER_GUN-1    ; みずでっぽう
	.db FURY_ATTACK-1  ; みだれづき
	.db FURY_SWIPES-1  ; みだれひっかき
	.db MEGA_DRAIN-1   ; メガドレイン
	.db MEGA_KICK-1    ; メガトンキック
	.db MEGA_PUNCH-1   ; メガトンパンチ
	.db MIMIC-1        ; ものまね
	.db LEECH_SEED-1   ; やどりぎのタネ
	.db METRONOME-1    ; ゆびをふる
	.db DREAM_EATER-1  ; ゆめくい
	.db ACID-1         ; ようかいえき
	.db MEDITATE-1     ; ヨガのポーズ
	.db REFLECT-1      ; リフレクター
	.db DRAGON_RAGE-1  ; りゅうのいかり
	.db ICE_PUNCH-1    ; れいとうパンチ
	.db ICE_BEAM-1     ; れいとうビーム
	.db COMET_PUNCH-1  ; れんぞくパンチ
	.db SKULL_BASH-1   ; ロケットずつき
	.db STRUGGLE-1     ; わるあがき

	.align 4

MoveIndices2:
; Inverse gojuuon.
	.db ABC_POUND
	.db ABC_KARATE_CHOP
	.db ABC_DOUBLESLAP
	.db ABC_COMET_PUNCH
	.db ABC_MEGA_PUNCH
	.db ABC_PAY_DAY
	.db ABC_FIRE_PUNCH
	.db ABC_ICE_PUNCH
	.db ABC_THUNDERPUNCH
	.db ABC_SCRATCH
	.db ABC_VICEGRIP
	.db ABC_GUILLOTINE
	.db ABC_RAZOR_WIND
	.db ABC_SWORDS_DANCE
	.db ABC_CUT
	.db ABC_GUST
	.db ABC_WING_ATTACK
	.db ABC_WHIRLWIND
	.db ABC_FLY
	.db ABC_BIND
	.db ABC_SLAM
	.db ABC_VINE_WHIP
	.db ABC_STOMP
	.db ABC_DOUBLE_KICK
	.db ABC_MEGA_KICK
	.db ABC_JUMP_KICK
	.db ABC_ROLLING_KICK
	.db ABC_SAND_ATTACK
	.db ABC_HEADBUTT
	.db ABC_HORN_ATTACK
	.db ABC_FURY_ATTACK
	.db ABC_HORN_DRILL
	.db ABC_TACKLE
	.db ABC_BODY_SLAM
	.db ABC_WRAP
	.db ABC_TAKE_DOWN
	.db ABC_THRASH
	.db ABC_DOUBLE_EDGE
	.db ABC_TAIL_WHIP
	.db ABC_POISON_STING
	.db ABC_TWINEEDLE
	.db ABC_PIN_MISSILE
	.db ABC_LEER
	.db ABC_BITE
	.db ABC_GROWL
	.db ABC_ROAR
	.db ABC_SING
	.db ABC_SUPERSONIC
	.db ABC_SONICBOOM
	.db ABC_DISABLE
	.db ABC_ACID
	.db ABC_EMBER
	.db ABC_FLAMETHROWER
	.db ABC_MIST
	.db ABC_WATER_GUN
	.db ABC_HYDRO_PUMP
	.db ABC_SURF
	.db ABC_ICE_BEAM
	.db ABC_BLIZZARD
	.db ABC_PSYBEAM
	.db ABC_BUBBLEBEAM
	.db ABC_AURORA_BEAM
	.db ABC_HYPER_BEAM
	.db ABC_PECK
	.db ABC_DRILL_PECK
	.db ABC_SUBMISSION
	.db ABC_LOW_KICK
	.db ABC_COUNTER
	.db ABC_SEISMIC_TOSS
	.db ABC_STRENGTH
	.db ABC_ABSORB
	.db ABC_MEGA_DRAIN
	.db ABC_LEECH_SEED
	.db ABC_GROWTH
	.db ABC_RAZOR_LEAF
	.db ABC_SOLARBEAM
	.db ABC_POISONPOWDER
	.db ABC_STUN_SPORE
	.db ABC_SLEEP_POWDER
	.db ABC_PETAL_DANCE
	.db ABC_STRING_SHOT
	.db ABC_DRAGON_RAGE
	.db ABC_FIRE_SPIN
	.db ABC_THUNDERSHOCK
	.db ABC_THUNDERBOLT
	.db ABC_THUNDER_WAVE
	.db ABC_THUNDER
	.db ABC_ROCK_THROW
	.db ABC_EARTHQUAKE
	.db ABC_FISSURE
	.db ABC_DIG
	.db ABC_TOXIC
	.db ABC_CONFUSION
	.db ABC_PSYCHIC_M
	.db ABC_HYPNOSIS
	.db ABC_MEDITATE
	.db ABC_AGILITY
	.db ABC_QUICK_ATTACK
	.db ABC_RAGE
	.db ABC_TELEPORT
	.db ABC_NIGHT_SHADE
	.db ABC_MIMIC
	.db ABC_SCREECH
	.db ABC_DOUBLE_TEAM
	.db ABC_RECOVER
	.db ABC_HARDEN
	.db ABC_MINIMIZE
	.db ABC_SMOKESCREEN
	.db ABC_CONFUSE_RAY
	.db ABC_WITHDRAW
	.db ABC_DEFENSE_CURL
	.db ABC_BARRIER
	.db ABC_LIGHT_SCREEN
	.db ABC_HAZE
	.db ABC_REFLECT
	.db ABC_FOCUS_ENERGY
	.db ABC_BIDE
	.db ABC_METRONOME
	.db ABC_MIRROR_MOVE
	.db ABC_SELFDESTRUCT
	.db ABC_EGG_BOMB
	.db ABC_LICK
	.db ABC_SMOG
	.db ABC_SLUDGE
	.db ABC_BONE_CLUB
	.db ABC_FIRE_BLAST
	.db ABC_WATERFALL
	.db ABC_CLAMP
	.db ABC_SWIFT
	.db ABC_SKULL_BASH
	.db ABC_SPIKE_CANNON
	.db ABC_CONSTRICT
	.db ABC_AMNESIA
	.db ABC_KINESIS
	.db ABC_SOFTBOILED
	.db ABC_HI_JUMP_KICK
	.db ABC_GLARE
	.db ABC_DREAM_EATER
	.db ABC_POISON_GAS
	.db ABC_BARRAGE
	.db ABC_LEECH_LIFE
	.db ABC_LOVELY_KISS
	.db ABC_SKY_ATTACK
	.db ABC_TRANSFORM
	.db ABC_BUBBLE
	.db ABC_DIZZY_PUNCH
	.db ABC_SPORE
	.db ABC_FLASH
	.db ABC_PSYWAVE
	.db ABC_SPLASH
	.db ABC_ACID_ARMOR
	.db ABC_CRABHAMMER
	.db ABC_EXPLOSION
	.db ABC_FURY_SWIPES
	.db ABC_BONEMERANG
	.db ABC_REST
	.db ABC_ROCK_SLIDE
	.db ABC_HYPER_FANG
	.db ABC_SHARPEN
	.db ABC_CONVERSION
	.db ABC_TRI_ATTACK
	.db ABC_SUPER_FANG
	.db ABC_SLASH
	.db ABC_SUBSTITUTE
	.db ABC_STRUGGLE

	.align 4

.incbin "baserom.n64",0x74240,32

; XXX what are these monotonically increasing 16-bit values?
.incbin "baserom.n64",0x74260,0x2000

.incbin "baserom.n64",0x76260,0x7C190-0x76260

	.db "S:%5.2f  H:%4d",0
	.align 4
	.db "X:%4d  Z:%4d",0
	.align 4
	.db "A:%04X  F:%3d",0
	.align 4

	.db "No",0 ; normal
	.align 4
	.db "Fa",0 ; faint
	.align 4
	.db "Sl",0 ; sleep
	.align 4
	.db "Po",0 ; poison
	.align 4
	.db "Bu",0 ; burn
	.align 4
	.db "Fr",0 ; freeze
	.align 4
	.db "Pa",0 ; paralyze
	.align 4
	.db "No",0 ; normal
	.align 4
	.db "Fi",0 ; fighting
	.align 4
	.db "Fl",0 ; flying
	.align 4
	.db "Po",0 ; poison
	.align 4
	.db "Gr",0 ; ground
	.align 4
	.db "Ro",0 ; rock
	.align 4
	.db "Fl",0 ; bird
	.align 4
	.db "Bu",0 ; bug
	.align 4
	.db "Gh",0 ; ghost
	.align 4
	.db "Fi",0 ; fire
	.align 4
	.db "Wa",0 ; water
	.align 4
	.db "Gr",0 ; grass
	.align 4
	.db "El",0 ; electric
	.align 4
	.db "Ps",0 ; psychic
	.align 4
	.db "Ic",0 ; ice
	.align 4
	.db "Dr",0 ; dragon
	.align 4

	.align 16

	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4
	.db "skill",0
	.align 4

	.align 16

.incbin "baserom.n64",0x7C750,0x7CD10-0x7C750

	.db "POKEMON",0
	.align 4
	.db "RED",0
	.align 4
	.db "GREEN",0
	.align 4
	.db "BLUE",0
	.align 4
	.db "YELLOW",0
	.align 4

	.align 16

; XXX ROM pointers?
.incbin "baserom.n64",0x7CD40,0x7CEC0-0x7CD40

	.db "1P",0
	.align 4
	.db "COM",0
	.align 4
	.db "1P",0
	.align 4
	.db "COM",0
	.align 4

.incbin "baserom.n64",0x7CED0,0x7CFD0-0x7CED0

	.db "1P",0
	.align 4
	.db "COM",0
	.align 4
	.db "1P",0
	.align 4
	.db "2P",0
	.align 4
	.db "COM",0
	.align 4

; XXX ROM pointers?
.incbin "baserom.n64",0x7CFE4,0x7D024-0x7CFE4
	.align 16

	.db "%d",0
	.align 16

; XXX ROM pointers?
.incbin "baserom.n64",0x7D040,0x7D110-0x7D040

	.db "og_normal_Fvector() zero div. err!",0xA,0
	.align 8

.incbin "baserom.n64",0x7D138,0x7D180-0x7D138

	.db "0x%08x ",0
	.align 4
	.db 0xA,0
	.align 4
	.db 0xA,0
	.align 4
	.db "%10.4f  ",0
	.align 4
	.db 0xA,0
	.align 4
	.db 0xA,0
	.align 4

	.align 16

.incbin "baserom.n64",0x7D1B0,0x7D794-0x7D1B0

	.dw 0x80000000 + Normal43478   - 0xC00
	.dw 0x80000000 + Fighting43478 - 0xC00
	.dw 0x80000000 + Flying43478   - 0xC00
	.dw 0x80000000 + Poison43478   - 0xC00
	.dw 0x80000000 + Ground43478   - 0xC00
	.dw 0x80000000 + Rock43478     - 0xC00
	.dw 0x80000000 + Invalid43478  - 0xC00
	.dw 0x80000000 + Bug43478      - 0xC00
	.dw 0x80000000 + Ghost43478    - 0xC00
	.dw 0x80000000 + Invalid43478  - 0xC00
	.dw 0x80000000 + Invalid43478  - 0xC00
	.dw 0x80000000 + Invalid43478  - 0xC00
	.dw 0x80000000 + Invalid43478  - 0xC00
	.dw 0x80000000 + Invalid43478  - 0xC00
	.dw 0x80000000 + Invalid43478  - 0xC00
	.dw 0x80000000 + Invalid43478  - 0xC00
	.dw 0x80000000 + Invalid43478  - 0xC00
	.dw 0x80000000 + Invalid43478  - 0xC00
	.dw 0x80000000 + Invalid43478  - 0xC00
	.dw 0x80000000 + Invalid43478  - 0xC00
	.dw 0x80000000 + Fire43478     - 0xC00
	.dw 0x80000000 + Water43478    - 0xC00
	.dw 0x80000000 + Grass43478    - 0xC00
	.dw 0x80000000 + Electric43478 - 0xC00
	.dw 0x80000000 + Psychic43478  - 0xC00
	.dw 0x80000000 + Ice43478      - 0xC00
	.dw 0x80000000 + Dragon43478   - 0xC00

.incbin "baserom.n64",0x7D800,0x7F388-0x7D800

	.db "RSP Gfx ucode F3DEX       fifo 2.06  Yoshitaka Yasumoto 1998 Nintendo.",0x0A,0
	.align 4

.incbin "baserom.n64",0x7F3D0,0x2000000-0x7F3D0

.close
