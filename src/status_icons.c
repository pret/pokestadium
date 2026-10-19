/**
 * Pokemon species data. Despite the file name, the two icon-index helpers at the
 * bottom are the only code here; the bulk is the base stats table D_8006FF00
 * (152 species, aliased as gBaseStats) plus the name tables it indexes:
 *
 *   .data    sPokemonNames   writable name slots, filled in at runtime
 *            D_8006FF00      152 species records, three fields per record
 *                            pointing at that species' name slot
 *   .rodata  sStatusNames    7 slots, indexed by Status_ToDisplayIconIndex()
 *            sTypeNames      16 slots, indexed by PokemonType_ToDisplayIndex()
 *            sMoveNames      165 move slots, never localised
 *            D_8007BB50..    item names, dead data
 *
 * The Japanese build (VERSION_JP) has real text instead of placeholders: .data holds one
 * Pokedex entry per record ahead of D_8006FF00, and .rodata holds the species names and
 * categories, sStatusNames and one array per type and move name.
 */
#include "status_icons.h"

#if defined(VERSION_JP)
// Species names and categories ("たね" for Bulbasaur, the Seed Pokemon) in record order;
// each record's name and unk_08 point at its pair.
const char sSpeciesName001[0xC] = "フシギダネ";
const char sSpeciesCategory001[0x8] = "たね";
const char sSpeciesName002[0xC] = "フシギソウ";
const char sSpeciesCategory002[0x8] = "たね";
const char sSpeciesName003[0xC] = "フシギバナ";
const char sSpeciesCategory003[0x8] = "たね";
const char sSpeciesName004[0xC] = "ヒトカゲ";
const char sSpeciesCategory004[0x8] = "とかげ";
const char sSpeciesName005[0xC] = "リザード";
const char sSpeciesCategory005[0x8] = "かえん";
const char sSpeciesName006[0xC] = "リザードン";
const char sSpeciesCategory006[0x8] = "かえん";
const char sSpeciesName007[0xC] = "ゼニガメ";
const char sSpeciesCategory007[0xC] = "かめのこ";
const char sSpeciesName008[0xC] = "カメール";
const char sSpeciesCategory008[0x8] = "かめ";
const char sSpeciesName009[0xC] = "カメックス";
const char sSpeciesCategory009[0x8] = "こうら";
const char sSpeciesName010[0xC] = "キャタピー";
const char sSpeciesCategory010[0xC] = "いもむし";
const char sSpeciesName011[0xC] = "トランセル";
const char sSpeciesCategory011[0x8] = "さなぎ";
const char sSpeciesName012[0xC] = "バタフリー";
const char sSpeciesCategory012[0xC] = "ちょうちょ";
const char sSpeciesName013[0xC] = "ビードル";
const char sSpeciesCategory013[0x8] = "けむし";
const char sSpeciesName014[0xC] = "コクーン";
const char sSpeciesCategory014[0x8] = "さなぎ";
const char sSpeciesName015[0xC] = "スピアー";
const char sSpeciesCategory015[0xC] = "どくばち";
const char sSpeciesName016[0x8] = "ポッポ";
const char sSpeciesCategory016[0x8] = "ことり";
const char sSpeciesName017[0xC] = "ピジョン";
const char sSpeciesCategory017[0x8] = "とり";
const char sSpeciesName018[0xC] = "ピジョット";
const char sSpeciesCategory018[0x8] = "とり";
const char sSpeciesName019[0xC] = "コラッタ";
const char sSpeciesCategory019[0x8] = "ねずみ";
const char sSpeciesName020[0x8] = "ラッタ";
const char sSpeciesCategory020[0x8] = "ねずみ";
const char sSpeciesName021[0xC] = "オニスズメ";
const char sSpeciesCategory021[0x8] = "ことり";
const char sSpeciesName022[0xC] = "オニドリル";
const char sSpeciesCategory022[0xC] = "くちばし";
const char sSpeciesName023[0x8] = "アーボ";
const char sSpeciesCategory023[0x8] = "へび";
const char sSpeciesName024[0xC] = "アーボック";
const char sSpeciesCategory024[0x8] = "コブラ";
const char sSpeciesName025[0xC] = "ピカチュウ";
const char sSpeciesCategory025[0x8] = "ねずみ";
const char sSpeciesName026[0xC] = "ライチュウ";
const char sSpeciesCategory026[0x8] = "ねずみ";
const char sSpeciesName027[0x8] = "サンド";
const char sSpeciesCategory027[0x8] = "ねずみ";
const char sSpeciesName028[0xC] = "サンドパン";
const char sSpeciesCategory028[0x8] = "ねずみ";
const char sSpeciesName029[0xC] = "ニドラン♀";
const char sSpeciesCategory029[0xC] = "どくばり";
const char sSpeciesName030[0xC] = "ニドリーナ";
const char sSpeciesCategory030[0xC] = "どくばり";
const char sSpeciesName031[0xC] = "ニドクイン";
const char sSpeciesCategory031[0x8] = "ドリル";
const char sSpeciesName032[0xC] = "ニドラン♂";
const char sSpeciesCategory032[0xC] = "どくばり";
const char sSpeciesName033[0xC] = "ニドリーノ";
const char sSpeciesCategory033[0xC] = "どくばり";
const char sSpeciesName034[0xC] = "ニドキング";
const char sSpeciesCategory034[0x8] = "ドリル";
const char sSpeciesName035[0x8] = "ピッピ";
const char sSpeciesCategory035[0xC] = "ようせい";
const char sSpeciesName036[0xC] = "ピクシー";
const char sSpeciesCategory036[0xC] = "ようせい";
const char sSpeciesName037[0x8] = "ロコン";
const char sSpeciesCategory037[0x8] = "きつね";
const char sSpeciesName038[0xC] = "キュウコン";
const char sSpeciesCategory038[0x8] = "きつね";
const char sSpeciesName039[0x8] = "プリン";
const char sSpeciesCategory039[0xC] = "ふうせん";
const char sSpeciesName040[0xC] = "プクリン";
const char sSpeciesCategory040[0xC] = "ふうせん";
const char sSpeciesName041[0xC] = "ズバット";
const char sSpeciesCategory041[0xC] = "こうもり";
const char sSpeciesName042[0xC] = "ゴルバット";
const char sSpeciesCategory042[0xC] = "こうもり";
const char sSpeciesName043[0xC] = "ナゾノクサ";
const char sSpeciesCategory043[0xC] = "ざっそう";
const char sSpeciesName044[0xC] = "クサイハナ";
const char sSpeciesCategory044[0xC] = "ざっそう";
const char sSpeciesName045[0xC] = "ラフレシア";
const char sSpeciesCategory045[0xC] = "フラワー";
const char sSpeciesName046[0x8] = "パラス";
const char sSpeciesCategory046[0x8] = "きのこ";
const char sSpeciesName047[0xC] = "パラセクト";
const char sSpeciesCategory047[0x8] = "きのこ";
const char sSpeciesName048[0xC] = "コンパン";
const char sSpeciesCategory048[0xC] = "こんちゅう";
const char sSpeciesName049[0xC] = "モルフォン";
const char sSpeciesCategory049[0x8] = "どくが";
const char sSpeciesName050[0xC] = "ディグダ";
const char sSpeciesCategory050[0x8] = "もぐら";
const char sSpeciesName051[0xC] = "ダグトリオ";
const char sSpeciesCategory051[0x8] = "もぐら";
const char sSpeciesName052[0xC] = "ニャース";
const char sSpeciesCategory052[0xC] = "ばけねこ";
const char sSpeciesName053[0xC] = "ペルシアン";
const char sSpeciesCategory053[0xC] = "シャムネコ";
const char sSpeciesName054[0xC] = "コダック";
const char sSpeciesCategory054[0x8] = "あひる";
const char sSpeciesName055[0xC] = "ゴルダック";
const char sSpeciesCategory055[0x8] = "あひる";
const char sSpeciesName056[0xC] = "マンキー";
const char sSpeciesCategory056[0xC] = "ぶたざる";
const char sSpeciesName057[0xC] = "オコリザル";
const char sSpeciesCategory057[0xC] = "ぶたざる";
const char sSpeciesName058[0xC] = "ガーディ";
const char sSpeciesCategory058[0x8] = "こいぬ";
const char sSpeciesName059[0xC] = "ウインディ";
const char sSpeciesCategory059[0xC] = "でんせつ";
const char sSpeciesName060[0xC] = "ニョロモ";
const char sSpeciesCategory060[0x8] = "おたま";
const char sSpeciesName061[0xC] = "ニョロゾ";
const char sSpeciesCategory061[0x8] = "おたま";
const char sSpeciesName062[0xC] = "ニョロボン";
const char sSpeciesCategory062[0x8] = "おたま";
const char sSpeciesName063[0xC] = "ケーシィ";
const char sSpeciesCategory063[0xC] = "ねんりき";
const char sSpeciesName064[0xC] = "ユンゲラー";
const char sSpeciesCategory064[0xC] = "ねんりき";
const char sSpeciesName065[0xC] = "フーディン";
const char sSpeciesCategory065[0xC] = "ねんりき";
const char sSpeciesName066[0xC] = "ワンリキー";
const char sSpeciesCategory066[0xC] = "かいりき";
const char sSpeciesName067[0xC] = "ゴーリキー";
const char sSpeciesCategory067[0xC] = "かいりき";
const char sSpeciesName068[0xC] = "カイリキー";
const char sSpeciesCategory068[0xC] = "かいりき";
const char sSpeciesName069[0xC] = "マダツボミ";
const char sSpeciesCategory069[0xC] = "フラワー";
const char sSpeciesName070[0xC] = "ウツドン";
const char sSpeciesCategory070[0xC] = "ハエとり";
const char sSpeciesName071[0xC] = "ウツボット";
const char sSpeciesCategory071[0xC] = "ハエとり";
const char sSpeciesName072[0xC] = "メノクラゲ";
const char sSpeciesCategory072[0x8] = "くらげ";
const char sSpeciesName073[0xC] = "ドククラゲ";
const char sSpeciesCategory073[0x8] = "くらげ";
const char sSpeciesName074[0xC] = "イシツブテ";
const char sSpeciesCategory074[0xC] = "がんせき";
const char sSpeciesName075[0xC] = "ゴローン";
const char sSpeciesCategory075[0xC] = "がんせき";
const char sSpeciesName076[0xC] = "ゴローニャ";
const char sSpeciesCategory076[0xC] = "メガトン";
const char sSpeciesName077[0xC] = "ポニータ";
const char sSpeciesCategory077[0xC] = "ひのうま";
const char sSpeciesName078[0xC] = "ギャロップ";
const char sSpeciesCategory078[0xC] = "ひのうま";
const char sSpeciesName079[0x8] = "ヤドン";
const char sSpeciesCategory079[0x8] = "まぬけ";
const char sSpeciesName080[0xC] = "ヤドラン";
const char sSpeciesCategory080[0xC] = "やどかり";
const char sSpeciesName081[0x8] = "コイル";
const char sSpeciesCategory081[0xC] = "じしゃく";
const char sSpeciesName082[0xC] = "レアコイル";
const char sSpeciesCategory082[0xC] = "じしゃく";
const char sSpeciesName083[0xC] = "カモネギ";
const char sSpeciesCategory083[0xC] = "かるがも";
const char sSpeciesName084[0xC] = "ドードー";
const char sSpeciesCategory084[0xC] = "ふたごどり";
const char sSpeciesName085[0xC] = "ドードリオ";
const char sSpeciesCategory085[0xC] = "みつごどり";
const char sSpeciesName086[0xC] = "パウワウ";
const char sSpeciesCategory086[0x8] = "あしか";
const char sSpeciesName087[0xC] = "ジュゴン";
const char sSpeciesCategory087[0x8] = "あしか";
const char sSpeciesName088[0xC] = "ベトベター";
const char sSpeciesCategory088[0x8] = "ヘドロ";
const char sSpeciesName089[0xC] = "ベトベトン";
const char sSpeciesCategory089[0x8] = "ヘドロ";
const char sSpeciesName090[0xC] = "シェルダー";
const char sSpeciesCategory090[0xC] = "２まいがい";
const char sSpeciesName091[0xC] = "パルシェン";
const char sSpeciesCategory091[0xC] = "２まいがい";
const char sSpeciesName092[0x8] = "ゴース";
const char sSpeciesCategory092[0xC] = "ガスじょう";
const char sSpeciesName093[0xC] = "ゴースト";
const char sSpeciesCategory093[0xC] = "ガスじょう";
const char sSpeciesName094[0xC] = "ゲンガー";
const char sSpeciesCategory094[0xC] = "シャドー";
const char sSpeciesName095[0xC] = "イワーク";
const char sSpeciesCategory095[0xC] = "いわへび";
const char sSpeciesName096[0xC] = "スリープ";
const char sSpeciesCategory096[0xC] = "さいみん";
const char sSpeciesName097[0xC] = "スリーパー";
const char sSpeciesCategory097[0xC] = "さいみん";
const char sSpeciesName098[0x8] = "クラブ";
const char sSpeciesCategory098[0xC] = "さわがに";
const char sSpeciesName099[0xC] = "キングラー";
const char sSpeciesCategory099[0x8] = "はさみ";
const char sSpeciesName100[0xC] = "ビリリダマ";
const char sSpeciesCategory100[0x8] = "ボール";
const char sSpeciesName101[0xC] = "マルマイン";
const char sSpeciesCategory101[0x8] = "ボール";
const char sSpeciesName102[0xC] = "タマタマ";
const char sSpeciesCategory102[0x8] = "たまご";
const char sSpeciesName103[0xC] = "ナッシー";
const char sSpeciesCategory103[0xC] = "やしのみ";
const char sSpeciesName104[0xC] = "カラカラ";
const char sSpeciesCategory104[0x8] = "こどく";
const char sSpeciesName105[0xC] = "ガラガラ";
const char sSpeciesCategory105[0xC] = "ほねずき";
const char sSpeciesName106[0xC] = "サワムラー";
const char sSpeciesCategory106[0x8] = "キック";
const char sSpeciesName107[0xC] = "エビワラー";
const char sSpeciesCategory107[0x8] = "パンチ";
const char sSpeciesName108[0xC] = "ベロリンガ";
const char sSpeciesCategory108[0xC] = "なめまわし";
const char sSpeciesName109[0xC] = "ドガース";
const char sSpeciesCategory109[0xC] = "どくガス";
const char sSpeciesName110[0xC] = "マタドガス";
const char sSpeciesCategory110[0xC] = "どくガス";
const char sSpeciesName111[0xC] = "サイホーン";
const char sSpeciesCategory111[0xC] = "とげとげ";
const char sSpeciesName112[0xC] = "サイドン";
const char sSpeciesCategory112[0x8] = "ドリル";
const char sSpeciesName113[0xC] = "ラッキー";
const char sSpeciesCategory113[0x8] = "たまご";
const char sSpeciesName114[0xC] = "モンジャラ";
const char sSpeciesCategory114[0xC] = "ツルじょう";
const char sSpeciesName115[0xC] = "ガルーラ";
const char sSpeciesCategory115[0x8] = "おやこ";
const char sSpeciesName116[0xC] = "タッツー";
const char sSpeciesCategory116[0xC] = "ドラゴン";
const char sSpeciesName117[0xC] = "シードラ";
const char sSpeciesCategory117[0xC] = "ドラゴン";
const char sSpeciesName118[0xC] = "トサキント";
const char sSpeciesCategory118[0xC] = "きんぎょ";
const char sSpeciesName119[0xC] = "アズマオウ";
const char sSpeciesCategory119[0xC] = "きんぎょ";
const char sSpeciesName120[0xC] = "ヒトデマン";
const char sSpeciesCategory120[0xC] = "ほしがた";
const char sSpeciesName121[0xC] = "スターミー";
const char sSpeciesCategory121[0x8] = "なぞの";
const char sSpeciesName122[0xC] = "バリヤード";
const char sSpeciesCategory122[0xC] = "バリアー";
const char sSpeciesName123[0xC] = "ストライク";
const char sSpeciesCategory123[0xC] = "かまきり";
const char sSpeciesName124[0xC] = "ルージュラ";
const char sSpeciesCategory124[0xC] = "ひとがた";
const char sSpeciesName125[0xC] = "エレブー";
const char sSpeciesCategory125[0xC] = "でんげき";
const char sSpeciesName126[0xC] = "ブーバー";
const char sSpeciesCategory126[0x8] = "ひふき";
const char sSpeciesName127[0xC] = "カイロス";
const char sSpeciesCategory127[0xC] = "くわがた";
const char sSpeciesName128[0xC] = "ケンタロス";
const char sSpeciesCategory128[0xC] = "あばれうし";
const char sSpeciesName129[0xC] = "コイキング";
const char sSpeciesCategory129[0x8] = "さかな";
const char sSpeciesName130[0xC] = "ギャラドス";
const char sSpeciesCategory130[0xC] = "きょうあく";
const char sSpeciesName131[0xC] = "ラプラス";
const char sSpeciesCategory131[0xC] = "のりもの";
const char sSpeciesName132[0xC] = "メタモン";
const char sSpeciesCategory132[0xC] = "へんしん";
const char sSpeciesName133[0xC] = "イーブイ";
const char sSpeciesCategory133[0x8] = "しんか";
const char sSpeciesName134[0xC] = "シャワーズ";
const char sSpeciesCategory134[0xC] = "あわはき";
const char sSpeciesName135[0xC] = "サンダース";
const char sSpeciesCategory135[0xC] = "かみなり";
const char sSpeciesName136[0xC] = "ブースター";
const char sSpeciesCategory136[0x8] = "ほのお";
const char sSpeciesName137[0xC] = "ポリゴン";
const char sSpeciesCategory137[0xC] = "シージー";
const char sSpeciesName138[0xC] = "オムナイト";
const char sSpeciesCategory138[0xC] = "うずまき";
const char sSpeciesName139[0xC] = "オムスター";
const char sSpeciesCategory139[0xC] = "うずまき";
const char sSpeciesName140[0x8] = "カブト";
const char sSpeciesCategory140[0x8] = "こうら";
const char sSpeciesName141[0xC] = "カブトプス";
const char sSpeciesCategory141[0x8] = "こうら";
const char sSpeciesName142[0x8] = "プテラ";
const char sSpeciesCategory142[0x8] = "かせき";
const char sSpeciesName143[0xC] = "カビゴン";
const char sSpeciesCategory143[0xC] = "いねむり";
const char sSpeciesName144[0xC] = "フリーザー";
const char sSpeciesCategory144[0xC] = "れいとう";
const char sSpeciesName145[0xC] = "サンダー";
const char sSpeciesCategory145[0xC] = "でんげき";
const char sSpeciesName146[0xC] = "ファイヤー";
const char sSpeciesCategory146[0x8] = "かえん";
const char sSpeciesName147[0xC] = "ミニリュウ";
const char sSpeciesCategory147[0xC] = "ドラゴン";
const char sSpeciesName148[0xC] = "ハクリュー";
const char sSpeciesCategory148[0xC] = "ドラゴン";
const char sSpeciesName149[0xC] = "カイリュー";
const char sSpeciesCategory149[0xC] = "ドラゴン";
const char sSpeciesName150[0xC] = "ミュウツー";
const char sSpeciesCategory150[0xC] = "いでんし";
const char sSpeciesName151[0x8] = "ミュウ";
const char sSpeciesCategory151[0xC] = "しんしゅ";
const char sSpeciesName152[0xC] = "みがわり";
const char sSpeciesCategory152[0xC] = "みがわり";

// 0xC zero bytes before sStatusNames; no word in the Japanese ROM holds an address in this range.
const char D_8007FDE4[0xC] = { 0 };

// Indexed by Status_ToDisplayIconIndex(); gb_data's status table (sStatusDisplayInfo in the
// shared C) points at each slot.
//@src/gb_data.c
const char sStatusNames[7][8] = {"ふつう", "ひんし", "ねむり", "どく", "やけど", "こおり", "まひ"};

// Indexed by PokemonType_ToDisplayIndex(); sTypeName06 is the unused Bird type. The names
// differ in length, so each is its own array and gb_data's type table points at each one.
const char sTypeName00[0xC] = "ノーマル";
const char sTypeName01[0xC] = "かくとう";
const char sTypeName02[0x8] = "ひこう";
const char sTypeName03[0x8] = "どく";
const char sTypeName04[0x8] = "じめん";
const char sTypeName05[0x8] = "いわ";
const char sTypeName06[0x8] = "とり";
const char sTypeName07[0x8] = "むし";
const char sTypeName08[0xC] = "ゴースト";
const char sTypeName09[0x8] = "ほのお";
const char sTypeName10[0x8] = "みず";
const char sTypeName11[0x8] = "くさ";
const char sTypeName12[0x8] = "でんき";
const char sTypeName13[0xC] = "エスパー";
const char sTypeName14[0x8] = "こおり";
const char sTypeName15[0xC] = "ドラゴン";
const char sTypeName16[0x4] = "";

// One name per Gen 1 move, in move ID order (Pound first). gb_data .data holds a
// pointer to sMoveName000 next to sMoveComments.
const char sMoveName000[0x8] = "はたく";
const char sMoveName001[0x10] = "からてチョップ";
const char sMoveName002[0x10] = "おうふくビンタ";
const char sMoveName003[0x10] = "れんぞくパンチ";
const char sMoveName004[0x10] = "メガトンパンチ";
const char sMoveName005[0x10] = "ネコにこばん";
const char sMoveName006[0x10] = "ほのおのパンチ";
const char sMoveName007[0x10] = "れいとうパンチ";
const char sMoveName008[0x10] = "かみなりパンチ";
const char sMoveName009[0xC] = "ひっかく";
const char sMoveName010[0x8] = "はさむ";
const char sMoveName011[0x10] = "ハサミギロチン";
const char sMoveName012[0xC] = "かまいたち";
const char sMoveName013[0x10] = "つるぎのまい";
const char sMoveName014[0xC] = "いあいぎり";
const char sMoveName015[0xC] = "かぜおこし";
const char sMoveName016[0x10] = "つばさでうつ";
const char sMoveName017[0xC] = "ふきとばし";
const char sMoveName018[0xC] = "そらをとぶ";
const char sMoveName019[0xC] = "しめつける";
const char sMoveName020[0x10] = "たたきつける";
const char sMoveName021[0xC] = "つるのムチ";
const char sMoveName022[0xC] = "ふみつけ";
const char sMoveName023[0xC] = "にどげり";
const char sMoveName024[0x10] = "メガトンキック";
const char sMoveName025[0xC] = "とびげり";
const char sMoveName026[0xC] = "まわしげり";
const char sMoveName027[0xC] = "すなかけ";
const char sMoveName028[0x8] = "ずつき";
const char sMoveName029[0xC] = "つのでつく";
const char sMoveName030[0xC] = "みだれづき";
const char sMoveName031[0xC] = "つのドリル";
const char sMoveName032[0xC] = "たいあたり";
const char sMoveName033[0xC] = "のしかかり";
const char sMoveName034[0xC] = "まきつく";
const char sMoveName035[0xC] = "とっしん";
const char sMoveName036[0xC] = "あばれる";
const char sMoveName037[0x10] = "すてみタックル";
const char sMoveName038[0x10] = "しっぽをふる";
const char sMoveName039[0xC] = "どくばり";
const char sMoveName040[0x10] = "ダブルニードル";
const char sMoveName041[0x10] = "ミサイルばり";
const char sMoveName042[0x10] = "にらみつける";
const char sMoveName043[0xC] = "かみつく";
const char sMoveName044[0xC] = "なきごえ";
const char sMoveName045[0x8] = "ほえる";
const char sMoveName046[0x8] = "うたう";
const char sMoveName047[0x10] = "ちょうおんぱ";
const char sMoveName048[0x10] = "ソニックブーム";
const char sMoveName049[0xC] = "かなしばり";
const char sMoveName050[0x10] = "ようかいえき";
const char sMoveName051[0x8] = "ひのこ";
const char sMoveName052[0x10] = "かえんほうしゃ";
const char sMoveName053[0xC] = "しろいきり";
const char sMoveName054[0x10] = "みずでっぽう";
const char sMoveName055[0x10] = "ハイドロポンプ";
const char sMoveName056[0xC] = "なみのり";
const char sMoveName057[0x10] = "れいとうビーム";
const char sMoveName058[0x8] = "ふぶき";
const char sMoveName059[0x10] = "サイケこうせん";
const char sMoveName060[0x10] = "バブルこうせん";
const char sMoveName061[0x10] = "オーロラビーム";
const char sMoveName062[0x10] = "はかいこうせん";
const char sMoveName063[0x8] = "つつく";
const char sMoveName064[0x10] = "ドリルくちばし";
const char sMoveName065[0x10] = "じごくぐるま";
const char sMoveName066[0xC] = "けたぐり";
const char sMoveName067[0xC] = "カウンター";
const char sMoveName068[0x10] = "ちきゅうなげ";
const char sMoveName069[0xC] = "かいりき";
const char sMoveName070[0xC] = "すいとる";
const char sMoveName071[0x10] = "メガドレイン";
const char sMoveName072[0x10] = "やどりぎのタネ";
const char sMoveName073[0xC] = "せいちょう";
const char sMoveName074[0x10] = "はっぱカッター";
const char sMoveName075[0x10] = "ソーラービーム";
const char sMoveName076[0xC] = "どくのこな";
const char sMoveName077[0xC] = "しびれごな";
const char sMoveName078[0xC] = "ねむりごな";
const char sMoveName079[0x10] = "はなびらのまい";
const char sMoveName080[0xC] = "いとをはく";
const char sMoveName081[0x10] = "りゅうのいかり";
const char sMoveName082[0x10] = "ほのおのうず";
const char sMoveName083[0x10] = "でんきショック";
const char sMoveName084[0x10] = "１０まんボルト";
const char sMoveName085[0xC] = "でんじは";
const char sMoveName086[0xC] = "かみなり";
const char sMoveName087[0xC] = "いわおとし";
const char sMoveName088[0x8] = "じしん";
const char sMoveName089[0x8] = "じわれ";
const char sMoveName090[0xC] = "あなをほる";
const char sMoveName091[0xC] = "どくどく";
const char sMoveName092[0xC] = "ねんりき";
const char sMoveName093[0x10] = "サイコキネシス";
const char sMoveName094[0x10] = "さいみんじゅつ";
const char sMoveName095[0x10] = "ヨガのポーズ";
const char sMoveName096[0x10] = "こうそくいどう";
const char sMoveName097[0x10] = "でんこうせっか";
const char sMoveName098[0x8] = "いかり";
const char sMoveName099[0xC] = "テレポート";
const char sMoveName100[0x10] = "ナイトヘッド";
const char sMoveName101[0xC] = "ものまね";
const char sMoveName102[0xC] = "いやなおと";
const char sMoveName103[0x10] = "かげぶんしん";
const char sMoveName104[0x10] = "じこさいせい";
const char sMoveName105[0xC] = "かたくなる";
const char sMoveName106[0x10] = "ちいさくなる";
const char sMoveName107[0xC] = "えんまく";
const char sMoveName108[0x10] = "あやしいひかり";
const char sMoveName109[0x10] = "からにこもる";
const char sMoveName110[0xC] = "まるくなる";
const char sMoveName111[0xC] = "バリアー";
const char sMoveName112[0x10] = "ひかりのかべ";
const char sMoveName113[0xC] = "くろいきり";
const char sMoveName114[0x10] = "リフレクター";
const char sMoveName115[0xC] = "きあいだめ";
const char sMoveName116[0x8] = "がまん";
const char sMoveName117[0xC] = "ゆびをふる";
const char sMoveName118[0x10] = "オウムがえし";
const char sMoveName119[0x8] = "じばく";
const char sMoveName120[0x10] = "タマゴばくだん";
const char sMoveName121[0x10] = "したでなめる";
const char sMoveName122[0xC] = "スモッグ";
const char sMoveName123[0x10] = "ヘドロこうげき";
const char sMoveName124[0x10] = "ホネこんぼう";
const char sMoveName125[0xC] = "だいもんじ";
const char sMoveName126[0xC] = "たきのぼり";
const char sMoveName127[0x10] = "からではさむ";
const char sMoveName128[0x10] = "スピードスター";
const char sMoveName129[0x10] = "ロケットずつき";
const char sMoveName130[0x10] = "とげキャノン";
const char sMoveName131[0xC] = "からみつく";
const char sMoveName132[0xC] = "ドわすれ";
const char sMoveName133[0x10] = "スプーンまげ";
const char sMoveName134[0xC] = "タマゴうみ";
const char sMoveName135[0x10] = "とびひざげり";
const char sMoveName136[0xC] = "へびにらみ";
const char sMoveName137[0xC] = "ゆめくい";
const char sMoveName138[0xC] = "どくガス";
const char sMoveName139[0xC] = "たまなげ";
const char sMoveName140[0xC] = "きゅうけつ";
const char sMoveName141[0x10] = "あくまのキッス";
const char sMoveName142[0x10] = "ゴッドバード";
const char sMoveName143[0xC] = "へんしん";
const char sMoveName144[0x8] = "あわ";
const char sMoveName145[0x10] = "ピヨピヨパンチ";
const char sMoveName146[0x10] = "キノコのほうし";
const char sMoveName147[0xC] = "フラッシュ";
const char sMoveName148[0x10] = "サイコウェーブ";
const char sMoveName149[0x8] = "はねる";
const char sMoveName150[0x8] = "とける";
const char sMoveName151[0x10] = "クラブハンマー";
const char sMoveName152[0x10] = "だいばくはつ";
const char sMoveName153[0x10] = "みだれひっかき";
const char sMoveName154[0x10] = "ホネブーメラン";
const char sMoveName155[0x8] = "ねむる";
const char sMoveName156[0xC] = "いわなだれ";
const char sMoveName157[0x10] = "ひっさつまえば";
const char sMoveName158[0xC] = "かくばる";
const char sMoveName159[0x10] = "テクスチャー";
const char sMoveName160[0x10] = "トライアタック";
const char sMoveName161[0x10] = "いかりのまえば";
const char sMoveName162[0xC] = "きりさく";
const char sMoveName163[0xC] = "みがわり";
const char sMoveName164[0xC] = "わるあがき";

// Pokedex entry texts, one per D_8006FF00 record; each record's unk_18 points at its
// entry. Record 152 (the substitute doll) has one too.
static char sPokedexText001[0x6C] = "せなかの　きゅうこんのような　ふくろは\nからだと　ともに　そだつ。なかには\nタネが　たくさん　はいっている。";
static char sPokedexText002[0x68] = "せなかの　つぼみは　ようぶんを\nからだから　もらっているらしい。\nそだつと　おおきなはなが　さくという。";
static char sPokedexText003[0x6C] = "たいようエネルギーを　からだに\nためこむときは　ひなたで　うごかずに\nじっと　していることが　おおいという。";
static char sPokedexText004[0x64] = "うまれたばかりの　ときは　しっぽの\nほのおに　なれていないので　やけどを\nすることも　あるらしい。";
static char sPokedexText005[0x6C] = "せいかくは　かなり　あらいらしい。\nするどい　ツメで　あいてを　ズタズタに\nするまで　こうげきを　やめない。";
static char sPokedexText006[0x70] = "はきだす　ほのおのおんどは　ものすごく\n１００００トンもある　ひょうざんでも\nみるみるうちに　とかして　しまう。";
static char sPokedexText007[0x70] = "うまれてから　こうらが　できあがるまで　\nしばらく　じかんが　かかる。くちから　\nきょうりょくな　あわを　だす。";
static char sPokedexText008[0x70] = "すいちゅうに　ながく　もぐるときは\nふさふさの　しっぽのけの　すきまに\nくうきの　あわを　たくさん　ためこむ。　";
static char sPokedexText009[0x70] = "こうらの　ふんしゃこうから　たいほうの\nたまのように　うちだされる　みずは\nコンクリートの　かべも　ぶちぬく。";
static char sPokedexText010[0x64] = "あたまにある　おおきな　めだまのような\nもようで　てきを　おどろかして　\nおいはらい　みを　まもる。";
static char sPokedexText011[0x70] = "かたくなるときは　そとがわの　カラだけ\nへんかして　かたくなる。カラの　なかは　\nそのままなので　やわらかい。";
static char sPokedexText012[0x70] = "ハネの　りんぷんに　もうどくがある。\nとおくで　はばたくすがたを　みかけたら\nすいこまないように　きをつけよう。";
static char sPokedexText013[0x74] = "もりや　くさちで　たくさん　みかける。\nあたまに　どくばりを　もっているので\nふみつけると　さされる　ことがある。";
static char sPokedexText014[0x74] = "ほとんど　うごかないので　しんだように\nみえてしまう。しかし　カラのなかでは\nあたらしい　からだが　つくられている。";
static char sPokedexText015[0x6C] = "もうスピードで　とびまわり　おしりと\nりょうての　どくばりで　さす。\nしゅうだんで　あらわれる　こともある。";
static char sPokedexText016[0x6C] = "てきと　むりに　たたかおうとは　せず\nあいてが　ちいさく　よわいものなら\nはばたいて　ふきとばして　しまう。";
static char sPokedexText017[0x6C] = "おおきな　なわばりの　ちゅうしんに\nすを　つくる。はったつした　あしの\nツメで　すばやくエサを　とらえる。";
static char sPokedexText018[0x74] = "ぜんそくりょくで　とぶときの　はやさは\nものすごい。おとに　きがついたときには　\nもう　とおりすぎた　あとである。";
static char sPokedexText019[0x70] = "すばやく　はしりまわり　かたいものを\nみつけては　かじっている。おちつきが\nなく　じっとしていられない　ようだ。";
static char sPokedexText020[0x6C] = "てきに　おそわれると　うしろあしで\nたちあがり　はを むきだして　あいてを\nおどすような　なきごえを　だす。";
static char sPokedexText021[0x74] = "はねが　みじかいので　ながい　きょりを\nとぶことが　できない。エサを　たべる\nときいがいは　いそがしく　とびまわる。";
static char sPokedexText022[0x6C] = "おおきな　つばさで　じょうずに　かぜを\nとらえて　ゆっくりと　そらを\nとびまわることが　すきな　ポケモン。";
static char sPokedexText023[0x68] = "くさちを　おともなく　いどうしながら\nこうぶつの　ポッポや　オニスズメの\nたまごを　さがしまわるという。";
static char sPokedexText024[0x60] = "てきに　であうと　あたまを　もちあげ\nおなかの　おそろしい　もようを\nみせつけて　おどろかす。";
static char sPokedexText025[0x6C] = "ひとけの　ない　もりに　すむ。\nでんきを　ほっぺたの　でんきぶくろに\nためて　いざというとき　ほうでんする。";
static char sPokedexText026[0x74] = "でんげきは　１０まんボルトに　たっする\nこともある。しっぽが　でんきを　にがす\nため　じぶんじしんは　しびれない。";
static char sPokedexText027[0x74] = "えものを　とるときは　あなの　ふちで\nようすを　うかがい　あなに　ちかづくと\nあっというまに　ひきずりこんでしまう。";
static char sPokedexText028[0x74] = "せなかを　まるめ　トゲトゲの　ボールに\nなって　ぶつかってくる。　するどい\nツメで　ひっかく　こうげきも　とくい。";
static char sPokedexText029[0x70] = "ちいさいと　おもって　ゆだんすると\nきょうりょくな　どくばりで　いきなり\nさされる。メスは　ツノが　ちいさい。";
static char sPokedexText030[0x68] = "メスなので　ふだんは　やさしい。\nしかし　いったんおこると　かみついたり\nひっかいたりして　あばれだす。";
static char sPokedexText031[0x74] = "とても　かたい　はりのような　ウロコは　\nこうふんすると　さかだつ。かんろくある\nからだから　おおわざを　くりだす。";
static char sPokedexText032[0x74] = "おおきな　みみで　きけんを　かんじとり\nおこると　どくばりを　だす。からだの\nトゲが　おおきいと　どくが　つよい。";
static char sPokedexText033[0x70] = "そのツノは　ダイヤモンドよりも　かたく\nしかも　ささると　きょうれつな　どくを\nあいての　からだに　そそぎこむ。";
static char sPokedexText034[0x70] = "まるで　いしのよろいを　みにまとった　\nような　ひふと　ながい　ツノをもつ。\nするどいツノには　どくも　ある。";
static char sPokedexText035[0x74] = "かわいいので　ペットにしたがる　ひとが\nおおいが　なかなか　みつけられない。\nかぎられた　ばしょだけで　みつかる。";
static char sPokedexText036[0x68] = "とても　みみが　よいため　おおきな\nおとや　さわがしさを　きらい\nひとが　いるところには　でてこない。";
static char sPokedexText037[0x70] = "１ぽんの　しろい　しっぽが　わかれて\n６ぽんの　うつくしい　しっぽに　なる。\nせいちょうすると　さらに　ふえる。";
static char sPokedexText038[0x68] = "ふざけて　しっぽを　つかんだ　だけで\n１０００ねんもの　ながい　あいだ\nしゅうねんぶかく　たたるという。";
static char sPokedexText039[0x70] = "おおきな　まるい　ひとみで　みつめて\nきもちのよい　うたをうたう。うたを\nきいた　ポケモンは　ねむってしまう。";
static char sPokedexText040[0x78] = "けがわは　こうきゅうひんに　なるくらい\nしなやかで　キメこまやか。おこらせると\nくうきを　すって　どんどん　ふくらむ。";
static char sPokedexText041[0x70] = "めと　はながない かわりに　くちから\nちょうおんぱを　だして　はんしゃおんを\nおおきな　みみで　ききわけて　とぶ。";
static char sPokedexText042[0x78] = "かみついた　あいてのちを　たいりょうに\nすいまくる。ちをすった　あいてによって\nじぶんの　けつえきがたが　へんかする。";
static char sPokedexText043[0x74] = "ひるまは　あたまの　くさだけを　だして\nじめんに　うまっている。ぬこうとすると\nおおごえで　さけぶと　いわれている。";
static char sPokedexText044[0x70] = "めしべの　においは　おそろしく　くさく\n２キロさきまで　とどく。うっかり\nすいこむと　きを　うしなってしまう。";
static char sPokedexText045[0x70] = "はなびらから　アレルギーを　ひきおこす\nかふんを　ばらまく。はなびらが\nおおきいほど　かふんを　たくさんだす。";
static char sPokedexText046[0x74] = "きのねっこから　ようぶんを　すいとって\nからだが　そだつ。せなかの　キノコは\nからだから　エキスを　すって　そだつ。";
static char sPokedexText047[0x74] = "キノコが　ムシを　あやつって　カサから\nどくほうしを　まきちらす。このほうしを\nちゅうごくでは　かんぽうやくにする。";
static char sPokedexText048[0x6C] = "くらやみでも　レーダーのような　めを　\nつかって　うごきまわれるが　あかりに\nあつまる　しゅうせいもある。";
static char sPokedexText049[0x6C] = "はねの　りんぷんは　もうどくのこな。\nはばたくたびに　ばらまくので\nかざしもに　たつと　どくに　やられる。";
static char sPokedexText050[0x70] = "じめんの　そとにでている　おおきさは\nやく２０センチ。しかし　ほんとうの\nおおきさは　いまだに　わかっていない。";
static char sPokedexText051[0x70] = "みつごの　ディグダで　いつもいっしょに\nうごき　まわる。ちか１００キロまで\nほって　じしんを　おこすこともある。";
static char sPokedexText052[0x70] = "ひるまは　ねているが　よるに　なると\nめを　かがやかせて　だいすきな　　\nコインを　ひろい　あつめて　よろこぶ。";
static char sPokedexText053[0x74] = "うつくしい　けなみに　ひかれ　ペットに\nしたがる　ひとも　おおいが　なかなか\nきしょうが　はげしくて　むずかしい。";
static char sPokedexText054[0x70] = "みかけは　ぼんやり　している　ようだが\nなやみの　ずつうが　ひどくなると　\nふしぎな　ちからを　はっきしだす。　";
static char sPokedexText055[0x70] = "てあしの　ゆびには　みずかきがあって\nおよぎが　うまい。ゆうぐれの　みずうみ\nなどで　ゆうがに　およいでいる。";
static char sPokedexText056[0x6C] = "なにかの　はずみで　すぐ　おこりだし\nおこると　あばれだす。みのこなしが\nかるく　うかつに　ちかよれない。";
static char sPokedexText057[0x70] = "もうれつに　おこりながら　どこまでも\nおいかけてくるが　どうして　おこるのか\nわからないので　なだめようがない。";
static char sPokedexText058[0x74] = "ひとなつこくて　せいじつな　ポケモン。\nなわばり　いしきが　とても　つよいので\nゆだんして　ちかづくと　かまれるぞ。";
static char sPokedexText059[0x70] = "ちゅうごくでは　その　うつくしさが\nでんせつと　なっている　ポケモン。\nとぶように　かろやかに　はしるという。";
static char sPokedexText060[0x6C] = "おなかの　うずまきは　ひふが　うすくて\nないぞうが　すけて　いるため。\nあるくより　およぐほうが　とくい。";
static char sPokedexText061[0x74] = "すいちゅう　りくじょうの　どちらでも\nせいかつできるが　すいちゅうが　すき。\nりくでは　あせで　ひふを　しめらせる。";
static char sPokedexText062[0x78] = "およぎが　とくいで　こじんメドレーなら\nオリンピックの　せんしゅより　はやい。\nいきつぎを　あまりしなくても　へいき。";
static char sPokedexText063[0x70] = "ねむっていても　あいてが　たたかおうと\nすると　すぐに　けはいを　かんじて\nとおくの　ばしょへ　テレポートする。";
static char sPokedexText064[0x6C] = "ちょうのうりょくを　つかう　ときには\nすべての　のうさいぼうが　はたらき\nとてもつよい　アルファはをだす。";
static char sPokedexText065[0x70] = "ちょうのうりょくを　あやつるポケモン。\nちのうが　たかく　あいての　じゃくてん\nなどを　いっしゅんで　みぬく。";
static char sPokedexText066[0x74] = "ぜんしんが　きんにくなので　からだの　\nどこにでも　ちからこぶが　つくれる。\n１００にんの　おとなを　なげとばせる。";
static char sPokedexText067[0x70] = "ちからは　おどろくほど　つよいのだが\nけっして　じまんする　ことはなく\nパワーセーブベルトで　おさえている。　";
static char sPokedexText068[0x74] = "４ほんの　うでから　アッパー　フック\nストレート　からてチョップを　どうじに　\nくりだす　テクニックも　もっている。";
static char sPokedexText069[0x74] = "ちいさな　ムシを　つかまえて　たべる\nしょくちゅうしょくぶつの　いっしゅ。\nねっこを　あしのかわりにして　あるく。";
static char sPokedexText070[0x6C] = "きれあじ　するどい　ハッパをもつ。　\nどくのこなで　あいての　うごきをとめ\nようかいえきで　とかしてしまう。";
static char sPokedexText071[0x6C] = "ミツの　あまい　かおりで　えものを\nさそいこむ。むしはもちろん　ときには\nおおきな　どうぶつも　エサとなる。";
static char sPokedexText072[0x70] = "すきとおった　めだまから　ひかりの\nビームを　はっしゃする。あさせを\nただよい　つりびとを　さすこともある。　";
static char sPokedexText073[0x68] = "しょくしゅは　８０ぽんもある。\nえものに　からみついた　しょくしゅは\nどんなことを　しても　はなれない。";
static char sPokedexText074[0x68] = "のぼりざかを　いどう　するとき\nだんさが　あるところでも　りょううでを\nきように　つかって　のりこえる。";
static char sPokedexText075[0x70] = "やまの　さかみちを　ころがってくる。\nくさや　きなど　じゃまな　ものは\nどんどん　なぎたおして　すすんでいく。";
static char sPokedexText076[0x68] = "おもさ　３００キロの　からだは\nがんせきの　ように　かたく　1ねんに\n１かい　だっぴして　おおきくなる。";
static char sPokedexText077[0x68] = "１かいのジャンプで　とうきょうタワーも\nとびこえる。ヒヅメの　かたさは\nダイヤモンドの　１０ばいもある。";
static char sPokedexText078[0x70] = "れっしゃや　くるまが　はしっているのを\nみると　おいかけずには　いられない。\nさいこう　じそくは　２４０キロ。";
static char sPokedexText079[0x74] = "しっぽで　さかななどを　つるいがいは\nボーッと　している　まぬけポケモン。\nねても　おきても　あまり　かわらない。";
static char sPokedexText080[0x78] = "ヤドンが　シェルダーに　しっぽをかまれ\nヤドランに　なった。シェルダーは　その\nかみごこちを　きに　いっているようだ。";
static char sPokedexText081[0x6C] = "どこからともなく　あらわれる。\nはんじゅうりょくで　ちゅうに　ういて\nさゆうの　ユニットから　ほうでんする。";
static char sPokedexText082[0x70] = "たいようの　こくてんが　ふえてくると\nあらわれる　れんけつした　コイル。\nこうでんあつ　などを　ほうしゃする。";
static char sPokedexText083[0x78] = "いつも　もちあるいている　しょくぶつの\nクキは　すの　ざいりょうにも　ぶきにも\nなるというが　なんのクキだか　ふめい。";
static char sPokedexText084[0x6C] = "ふたつの　あたまをもつ　ポケモン。\nとぶよりも　はしるのが　とくいで\nじそく　１００キロの　スピードをだす。";
static char sPokedexText085[0x78] = "よろこび　かなしみ　いかりを　あらわす\n３つの　あたまで　さくせんを　たてる。\nねるときも　１つは　おきているらしい。";
static char sPokedexText086[0x78] = "みずいろの　けで　おおわれた　ぶあつい　\nひふをもち　れいか４０どの　さむさでも\nひょうざんを　わって　すすんでゆく。";
static char sPokedexText087[0x74] = "まっしろな　けで　おおわれた　からだの\nなかに　ねつエネルギーを　たくわえて\nさむい　うみも　８ノットで　およぐ。";
static char sPokedexText088[0x74] = "ヘドロが　つきからの　エックスせんを　\nあびて　へんかした。ヘドロや　はいえき\nなど　きたないモノが　だいこうぶつ。";
static char sPokedexText089[0x74] = "じめんに　まざっていると　わからない。\nきたない　ヘドロを　まとった　からだに\nさわると　もうどくに　おかされる。";
static char sPokedexText090[0x70] = "カラは　ダイヤモンドよりも　かたい。\nかいていの　すなの　なかに　かくれて\nやわらかい　したで　エサを　とる。";
static char sPokedexText091[0x70] = "ナパームだんでも　こわせないほどの\nとてつもなく　かたい　カラを　もつ。\nカラの　なかみを　みたものは　いない。";
static char sPokedexText092[0x70] = "うすい　ガスのようなもので　からだが\nできていて　つつまれると　きぜつする。\nかぜの　つよいひは　でてこない。";
static char sPokedexText093[0x74] = "なにもない　ところで　つまづいたり\nひとけのない　ばしょで　おとがしたら\nそれは　ゴーストの　せいかもしれない。　";
static char sPokedexText094[0x70] = "やまで　そうなん　しそうな　ひとを\nねらって　あらわれる。　つきのよるに\nわらうかげの　げんいんとも　いわれる。";
static char sPokedexText095[0x68] = "８メートルいじょうも　ある　おおきな\nからだを　くねらせて　つちのなかを\nじそく８０キロで　ほりすすむ。";
static char sPokedexText096[0x6C] = "さいみんじゅつで　あいてを　ねむらせ\nユメを　たべる。でんせつの　いきもの\nバクの　しそんと　いわれている。";
static char sPokedexText097[0x6C] = "うっかり　めを　あわせて　しまったら\nさいみんじゅつを　かけられないように\nめを　つぶってしまうのが　よい。";
static char sPokedexText098[0x68] = "かいがんや　はまべに　すんでいる。\nハサミは　とれると　はえかわり\nはえかわると　まえより　つよくなる。";
static char sPokedexText099[0x70] = "１まんばりきの　パワーの　ハサミを\nつかえば　シェルダーや　パルシェンの\nカラでも　こじあけて　しまうらしい。";
static char sPokedexText100[0x74] = "おもに　はつでんしょに　あらわれるが\nでんしゃの　パンタグラフに　くっついて\nでんきを　すいとることも　あるという。";
static char sPokedexText101[0x70] = "ものすごい　エレクトンエネルギーを\nためこんでいて　ちょっとした　しげきで\nだいばくはつする。かなり　あぶない。";
static char sPokedexText102[0x74] = "しょくぶつの　タネのような　いきもの。\n１ぴき　みつけて　あとを　おいかけると\nいつのまにか　かずが　ふえている。";
static char sPokedexText103[0x74] = "それぞれの　みは　べつべつの　いしきを\nもった　あたまである。これが　じめんに\nおちると　タマタマに　なるらしい。";
static char sPokedexText104[0x74] = "なくなった　ははおやの　ホネを　いつも\nかぶっていて　すがおは　みせない。　　\nつきよには　さびしげな　こえでなく。";
static char sPokedexText105[0x6C] = "ホネを　ぶきに　つかうようになって\nあらっぽくなったが　もとは　からだも\nちいさく　よわい　ポケモンだった。";
static char sPokedexText106[0x74] = "じゆうじざいに　のびちぢみする　あしで\nあいてを　けって　けって　けりまくる。\nキックのオニと　よぶひとたちもいる。";
static char sPokedexText107[0x74] = "とくいの　みえないパンチの　スピードは\nしんかんせんより　はやい。３ぷんごとに\nきゅうけい　しながら　うごきまわる。";
static char sPokedexText108[0x68] = "しんちょうの　２ばいもある　したを\nじゆうにつかって　エサをとる。\nなめられると　ビリビリ　しびれる。";
static char sPokedexText109[0x74] = "もうどくの　ガスが　いっぱい　つまった\nうすい　ふうせんのような　ポケモン。\nだいばくはつを　おこす　こともある。";
static char sPokedexText110[0x74] = "どくガスの　ふきだまりで　ごくまれに\nうまれる　ふたごの　ドガース。２つの\nどくガスは　せいぶんが　ちがうらしい。";
static char sPokedexText111[0x6C] = "にんげんの　１０００ばい　かたいほねと\nつよい　ちからで　こうそうビルでも\nたいあたりで　コナゴナにする。";
static char sPokedexText112[0x70] = "よろいの　ような　ひふで　２０００どの\nマグマの　なかでも　いきられる。\nツノで　がんせきにも　あなを　あける。";
static char sPokedexText113[0x74] = "すごく　おいしい　たまごを　まいにち\nうんでくれる。たいせつに　そだてると\nたまごは　もっと　おいしくなるらしい。";
static char sPokedexText114[0x6C] = "かいそうの　ような　あおい　つるが\nたくさん　からんでいて　しょうたいが\nみえない。なんにでも　からみつく。";
static char sPokedexText115[0x74] = "メスは　３ねんほど　おなかの　ふくろで\nこどもを　そだてる。こどもが　エサを\nとれるようになると　ふくろからだす。";
static char sPokedexText116[0x74] = "しっぽで　からだの　バランスを　とって\nくちから　スミを　ふきだす。そのスミで\nムシを　うちおとしたり　するらしい。";
static char sPokedexText117[0x74] = "まえを　むいたまま　うしろに　およげる\nきような　ポケモン。トゲに　さされると\nいたみで　きぜつ　することがある。";
static char sPokedexText118[0x68] = "おビレが　しなやかに　ゆれるドレスの\nようで　うつくしい。すいちゅうを\n５ノットの　はやさで　およぐ。　";
static char sPokedexText119[0x74] = "あきには　たまごを　うむために　かわを\nさかのぼってゆく。ほかの　きせつは\nじぶんの　すを　つくって　すんでいる。";
static char sPokedexText120[0x6C] = "からだを　きられても　もとに　もどり\nよるには　コアと　よばれる　からだの\nちゅうしんが　あかく　ひかる。";
static char sPokedexText121[0x74] = "ひとの　みていない　ところでは　コアが\nなないろに　あやしく　ひかるという。\nうちゅうからの　ポケモンかもしれない。";
static char sPokedexText122[0x70] = "パントマイムが　とくいで　だいすき。\nじゃまをすると　おおきな　てのひらで\nおうふくビンタを　してくるという。";
static char sPokedexText123[0x74] = "ものすごい　はやさで　うごき　するどい\nカマで　あいてを　きりさく。ごくまれに\nハネを　つかって　とぶこともある。";
static char sPokedexText124[0x74] = "いみふめいの　なぞのことばを　つかう。\nみているひとが　おもわず　おどりだす\nあやしい　こしふりが　とくちょうだ。";
static char sPokedexText125[0x6C] = "でんきを　もとめて　はつでんしょ\nなどに　あらわれる。すがたを　けした\nとき　だいていでんが　おこるという。";
static char sPokedexText126[0x68] = "たいおんが　１２００ど　もあり　いつも\nオレンジいろに　もえている。\nかざんの　ちかくに　すんでいる。";
static char sPokedexText127[0x74] = "あたまの２ほんの　ながいツノで　てきを　\nはさんで　ちぎる。からだが　かたい\nあいては　はさんだまま　なげとばす。";
static char sPokedexText128[0x70] = "おおきなからだを　じぶんの　しっぽで\nむちうちながら　とっしん　してくる。\nしかし　まっすぐにしか　すすめない。";
static char sPokedexText129[0x5C] = "あいてが　どんなポケモンでも　どんなに　\nおそろしい　わざを　しかけようとも\nただ　はねる。";
static char sPokedexText130[0x64] = "きわめて　きょうぼうな　せいかくで\nおおきな　としを　かいめつ　させる\nほどの　はかいりょくをもつ。";
static char sPokedexText131[0x68] = "にんげんの　ことばが　りかいできて\nひとを　せなかに　のせるのがすき。\nぜつめつ　すんぜんの　ポケモン。";
static char sPokedexText132[0x6C] = "さいぼうの　そしきを　くみかえて\nあいて　そっくりに　へんしんできる。\nふだんは　かたちが　きまっていない。";
static char sPokedexText133[0x70] = "ふきそくな　いでんしを　もっていて\nいしがもつ　ほうしゃせんを　あびると\n３しゅるいの　ポケモンに　しんかする。";
static char sPokedexText134[0x70] = "みずべに　しずかに　たたずんでいる。\nさいぼうが　みずの　ぶんしと　にている\nつくりなので　みずに　とけこめる。";
static char sPokedexText135[0x70] = "やく１００００ボルトの　でんげきと\nさかだてると　はりの　ようになって\nあいてを　つらぬく　たいもうが　ぶき。";
static char sPokedexText136[0x6C] = "はきだす　ほのおは　１７００ど。\nからだに　ほのおを　ためているときは\nたいおんは　９００どを　こえている。";
static char sPokedexText137[0x70] = "からだが　プログラムで　できているので\nでんしくうかんを　じゆうに　うごける。　　\nじんこうの　ポケモンである。";
static char sPokedexText138[0x6C] = "ぜつめつした　こだいの　ポケモン。\nかせきから　さいせい　された。\n１０ぽんのあしを　くねらせて　およぐ。";
static char sPokedexText139[0x70] = "しょくしゅで　あいてに　からみつき\nするどい　キバで　かみついてくる。\nカラが　おおきすぎて　うごきがにぶい。";
static char sPokedexText140[0x70] = "こだい　うみだった　ちそうからでた\nかせきを　さいせいさせた　ポケモン。\nひっくり　かえされると　おきられない。";
static char sPokedexText141[0x70] = "すいちゅうでは　はやい　スピードで\nおよぐ。えものを　カマで　きりさき\nたいえきを　ぜんぶ　すいとってしまう。";
static char sPokedexText142[0x6C] = "こだいの　きょうりゅうの　いでんしから　\nよみがえらせた　ポケモン。\nキバが　するどく　かなり　きょうぼう。";
static char sPokedexText143[0x6C] = "たべては　ねむるを　くりかえし　ただ\nふとりつづけるだけの　なまけもの。\nたべている　ときだけ　おきている。";
static char sPokedexText144[0x70] = "ながい　おばねが　いんしょうてきな\nでんせつの　とりポケモン。ゆきやまで\nこごえそうになると　あらわれるという。";
static char sPokedexText145[0x74] = "きょだいな　いなずまを　ともなって\nあらわれる　でんせつの　とりポケモン。\nそらをとぶと　バチバチと　おとがする。";
static char sPokedexText146[0x70] = "ひのとりとして　いいつたえられてきた\nでんせつの　とりポケモン。はばたくたび\nつばさが　あかるく　もえあがる。";
static char sPokedexText147[0x78] = "こどもでも　しんちょうは　２メートルを\nこえる。かずが　すくなく　ながいあいだ\nまぼろしのポケモンと　よばれつづけた。";
static char sPokedexText148[0x68] = "うみや　みずうみ　などにすみ　てんきを\nかえる　ちからを　もつという。\nそらを　とぶことも　あるようだ。";
static char sPokedexText149[0x68] = "にんげんなみの　ちのうをもち　そらを\nとべば　１６じかんほどで　ちきゅうを\n１まわりする　うみのけしん。";
static char sPokedexText150[0x70] = "いでんしの　くみかえで　うみだされた\nきょうぼうな　エスパーポケモン。\nつめたく　ひかるめが　とても　こわい。";
static char sPokedexText151[0x74] = "ぜつめつしてしまったと　おもわれていた\nみなみアメリカの　まぼろしのポケモン。\nさいきん　みたひとが　ふえたという。";
static char sPokedexText152[0x14] = "みがわりにんぎょう";

unk_D_8006FF00 D_8006FF00[152] = {
    {
        0x01, 0x00, 1270,
        (char*) sSpeciesName001,
        (s32) sSpeciesCategory001,
        0x3D, 0x07, 69,
        -45, 70,
        0x003C73E2,
        (u32) sPokedexText001,
    },
    {
        0x02, 0x00, 839,
        (char*) sSpeciesName002,
        (s32) sSpeciesCategory002,
        0x35, 0x0A, 130,
        -40, 45,
        0x003D0046,
        (u32) sPokedexText002,
    },
    {
        0x03, 0x00, 509,
        (char*) sSpeciesName003,
        (s32) sSpeciesCategory003,
        0x31, 0x14, 1000,
        -30, 40,
        0x003CFFC4,
        (u32) sPokedexText003,
    },
    {
        0x04, 0x0A, 1583,
        (char*) sSpeciesName004,
        (s32) sSpeciesCategory004,
        0x3D, 0x06, 85,
        -25, 20,
        0x003C6C42,
        (u32) sPokedexText004,
    },
    {
        0x05, 0x00, 957,
        (char*) sSpeciesName005,
        (s32) sSpeciesCategory005,
        0x35, 0x0B, 190,
        -10, 55,
        0x003BFFEC,
        (u32) sPokedexText005,
    },
    {
        0x06, 0x00, 620,
        (char*) sSpeciesName006,
        (s32) sSpeciesCategory006,
        0x35, 0x11, 905,
        -20, 15,
        0x003BEC31,
        (u32) sPokedexText006,
    },
    {
        0x07, 0x00, 1910,
        (char*) sSpeciesName007,
        (s32) sSpeciesCategory007,
        0x3D, 0x05, 90,
        -50, 30,
        0x003C9800,
        (u32) sPokedexText007,
    },
    {
        0x08, 0x00, 1060,
        (char*) sSpeciesName008,
        (s32) sSpeciesCategory008,
        0x35, 0x0A, 225,
        -50, 30,
        0x003BEC00,
        (u32) sPokedexText008,
    },
    {
        0x09, 0x00, 730,
        (char*) sSpeciesName009,
        (s32) sSpeciesCategory009,
        0x35, 0x10, 855,
        -30, 35,
        0x003C6BCE,
        (u32) sPokedexText009,
    },
    {
        0x0A, 0x00, 5017,
        (char*) sSpeciesName010,
        (s32) sSpeciesCategory010,
        0x3D, 0x03, 29,
        -30, 80,
        0x003C1814,
        (u32) sPokedexText010,
    },
    {
        0x0B, 0x00, 1490,
        (char*) sSpeciesName011,
        (s32) sSpeciesCategory011,
        0x35, 0x07, 99,
        -20, 60,
        0x003CB000,
        (u32) sPokedexText011,
    },
    {
        0x0C, 0x04, 997,
        (char*) sSpeciesName012,
        (s32) sSpeciesCategory012,
        0x35, 0x0B, 320,
        -40, 50,
        0x003E8464,
        (u32) sPokedexText012,
    },
    {
        0x0D, 0x00, 3380,
        (char*) sSpeciesName013,
        (s32) sSpeciesCategory013,
        0x3D, 0x03, 32,
        0, 50,
        0x003BF414,
        (u32) sPokedexText013,
    },
    {
        0x0E, 0x00, 1729,
        (char*) sSpeciesName014,
        (s32) sSpeciesCategory014,
        0x35, 0x06, 100,
        -25, 40,
        0x003C045A,
        (u32) sPokedexText014,
    },
    {
        0x0F, 0x00, 910,
        (char*) sSpeciesName015,
        (s32) sSpeciesCategory015,
        0x37, 0x0A, 295,
        -20, 50,
        0x003FC400,
        (u32) sPokedexText015,
    },
    {
        0x10, 0x00, 3400,
        (char*) sSpeciesName016,
        (s32) sSpeciesCategory016,
        0x3D, 0x03, 18,
        -30, 30,
        0x003C7FF6,
        (u32) sPokedexText016,
    },
    {
        0x11, 0x00, 900,
        (char*) sSpeciesName017,
        (s32) sSpeciesCategory017,
        0x35, 0x0B, 300,
        -30, 30,
        0x003C401E,
        (u32) sPokedexText017,
    },
    {
        0x12, 0x08, 693,
        (char*) sSpeciesName018,
        (s32) sSpeciesCategory018,
        0x35, 0x0F, 395,
        -35, 20,
        0x003C6BEC,
        (u32) sPokedexText018,
    },
    {
        0x13, 0x00, 1960,
        (char*) sSpeciesName019,
        (s32) sSpeciesCategory019,
        0x3D, 0x03, 35,
        -40, 60,
        0x003C8800,
        (u32) sPokedexText019,
    },
    {
        0x14, 0x00, 1280,
        (char*) sSpeciesName020,
        (s32) sSpeciesCategory020,
        0x35, 0x07, 185,
        -30, 30,
        0x003C8400,
        (u32) sPokedexText020,
    },
    {
        0x15, 0x00, 3090,
        (char*) sSpeciesName021,
        (s32) sSpeciesCategory021,
        0x3D, 0x03, 20,
        -30, 20,
        0x003C53E2,
        (u32) sPokedexText021,
    },
    {
        0x16, 0x12, 897,
        (char*) sSpeciesName022,
        (s32) sSpeciesCategory022,
        0x37, 0x0C, 380,
        -25, 30,
        0x003ECBA6,
        (u32) sPokedexText022,
    },
    {
        0x17, 0x00, 1779,
        (char*) sSpeciesName023,
        (s32) sSpeciesCategory023,
        0x3D, 0x14, 69,
        -30, 40,
        0x003D0032,
        (u32) sPokedexText023,
    },
    {
        0x18, 0x00, 730,
        (char*) sSpeciesName024,
        (s32) sSpeciesCategory024,
        0x35, 0x23, 650,
        -70, 30,
        0x003BC81E,
        (u32) sPokedexText024,
    },
    {
        0x19, 0x00, 2400,
        (char*) sSpeciesName025,
        (s32) sSpeciesCategory025,
        0x3F, 0x04, 60,
        -15, 25,
        0x003BCC28,
        (u32) sPokedexText025,
    },
    {
        0x1A, 0x00, 1350,
        (char*) sSpeciesName026,
        (s32) sSpeciesCategory026,
        0x35, 0x08, 300,
        -15, 25,
        0x003C4C00,
        (u32) sPokedexText026,
    },
    {
        0x1B, 0x00, 1599,
        (char*) sSpeciesName027,
        (s32) sSpeciesCategory027,
        0x3D, 0x06, 120,
        -40, 40,
        0x003C9400,
        (u32) sPokedexText027,
    },
    {
        0x1C, 0x00, 1040,
        (char*) sSpeciesName028,
        (s32) sSpeciesCategory028,
        0x35, 0x0A, 295,
        -20, 25,
        0x003C2C46,
        (u32) sPokedexText028,
    },
    {
        0x1D, 0x00, 2130,
        (char*) sSpeciesName029,
        (s32) sSpeciesCategory029,
        0x3D, 0x04, 70,
        -60, 70,
        0x003C1C32,
        (u32) sPokedexText029,
    },
    {
        0x1E, 0x00, 1135,
        (char*) sSpeciesName030,
        (s32) sSpeciesCategory030,
        0x35, 0x08, 200,
        -80, 80,
        0x003C942D,
        (u32) sPokedexText030,
    },
    {
        0x1F, 0x00, 795,
        (char*) sSpeciesName031,
        (s32) sSpeciesCategory031,
        0x37, 0x0D, 600,
        -60, 80,
        0x003C43EC,
        (u32) sPokedexText031,
    },
    {
        0x20, 0x00, 1550,
        (char*) sSpeciesName032,
        (s32) sSpeciesCategory032,
        0x3D, 0x05, 90,
        -70, 20,
        0x003D2FD8,
        (u32) sPokedexText032,
    },
    {
        0x21, 0x00, 1100,
        (char*) sSpeciesName033,
        (s32) sSpeciesCategory033,
        0x35, 0x09, 195,
        -70, 20,
        0x003D57CE,
        (u32) sPokedexText033,
    },
    {
        0x22, 0x00, 860,
        (char*) sSpeciesName034,
        (s32) sSpeciesCategory034,
        0x37, 0x0E, 620,
        -50, 30,
        0x003C6F9C,
        (u32) sPokedexText034,
    },
    {
        0x23, 0x15, 1540,
        (char*) sSpeciesName035,
        (s32) sSpeciesCategory035,
        0x3D, 0x06, 75,
        -40, 50,
        0x003BF428,
        (u32) sPokedexText035,
    },
    {
        0x24, 0x00, 685,
        (char*) sSpeciesName036,
        (s32) sSpeciesCategory036,
        0x35, 0x0D, 400,
        -40, 50,
        0x003B8400,
        (u32) sPokedexText036,
    },
    {
        0x25, 0x00, 1523,
        (char*) sSpeciesName037,
        (s32) sSpeciesCategory037,
        0x3D, 0x06, 99,
        -30, 35,
        0x003C0C14,
        (u32) sPokedexText037,
    },
    {
        0x26, 0x00, 950,
        (char*) sSpeciesName038,
        (s32) sSpeciesCategory038,
        0x35, 0x0B, 199,
        -30, 50,
        0x003BBC00,
        (u32) sPokedexText038,
    },
    {
        0x27, 0x00, 1620,
        (char*) sSpeciesName039,
        (s32) sSpeciesCategory039,
        0x3D, 0x05, 55,
        -40, 40,
        0x003CDBF6,
        (u32) sPokedexText039,
    },
    {
        0x28, 0x00, 800,
        (char*) sSpeciesName040,
        (s32) sSpeciesCategory040,
        0x35, 0x0A, 120,
        -40, 40,
        0x003BE7E2,
        (u32) sPokedexText040,
    },
    {
        0x29, 0x00, 1080,
        (char*) sSpeciesName041,
        (s32) sSpeciesCategory041,
        0x3D, 0x08, 75,
        -30, 30,
        0x0033280A,
        (u32) sPokedexText041,
    },
    {
        0x2A, 0x00, 730,
        (char*) sSpeciesName042,
        (s32) sSpeciesCategory042,
        0x35, 0x10, 550,
        -25, 30,
        0x003C5400,
        (u32) sPokedexText042,
    },
    {
        0x2B, 0x0B, 1860,
        (char*) sSpeciesName043,
        (s32) sSpeciesCategory043,
        0x3D, 0x05, 54,
        -40, 70,
        0x003C2C28,
        (u32) sPokedexText043,
    },
    {
        0x2C, 0x00, 1190,
        (char*) sSpeciesName044,
        (s32) sSpeciesCategory044,
        0x35, 0x08, 86,
        -40, 65,
        0x003C6000,
        (u32) sPokedexText044,
    },
    {
        0x2D, 0x00, 637,
        (char*) sSpeciesName045,
        (s32) sSpeciesCategory045,
        0x35, 0x0C, 186,
        -25, 60,
        0x003C5FEC,
        (u32) sPokedexText045,
    },
    {
        0x2E, 0x00, 2160,
        (char*) sSpeciesName046,
        (s32) sSpeciesCategory046,
        0x3D, 0x03, 54,
        -20, 30,
        0x003D13EC,
        (u32) sPokedexText046,
    },
    {
        0x2F, 0x00, 950,
        (char*) sSpeciesName047,
        (s32) sSpeciesCategory047,
        0x35, 0x0A, 295,
        -20, 35,
        0x003CCBE2,
        (u32) sPokedexText047,
    },
    {
        0x30, 0x00, 740,
        (char*) sSpeciesName048,
        (s32) sSpeciesCategory048,
        0x35, 0x0A, 300,
        -60, 60,
        0x003CABEC,
        (u32) sPokedexText048,
    },
    {
        0x31, 0x02, 763,
        (char*) sSpeciesName049,
        (s32) sSpeciesCategory049,
        0x35, 0x0F, 125,
        -60, 100,
        0x003E9C18,
        (u32) sPokedexText049,
    },
    {
        0x32, 0x00, 4000,
        (char*) sSpeciesName050,
        (s32) sSpeciesCategory050,
        0x3D, 0x02, 8,
        -20, 35,
        0x003D6800,
        (u32) sPokedexText050,
    },
    {
        0x33, 0x00, 1150,
        (char*) sSpeciesName051,
        (s32) sSpeciesCategory051,
        0x33, 0x07, 333,
        -20, 35,
        0x003D1000,
        (u32) sPokedexText051,
    },
    {
        0x34, 0x00, 2400,
        (char*) sSpeciesName052,
        (s32) sSpeciesCategory052,
        0x3D, 0x04, 42,
        -40, 35,
        0x003C2C00,
        (u32) sPokedexText052,
    },
    {
        0x35, 0x00, 1040,
        (char*) sSpeciesName053,
        (s32) sSpeciesCategory053,
        0x35, 0x0A, 320,
        -20, 50,
        0x003DB01E,
        (u32) sPokedexText053,
    },
    {
        0x36, 0x00, 1230,
        (char*) sSpeciesName054,
        (s32) sSpeciesCategory054,
        0x3D, 0x08, 196,
        -20, 30,
        0x003C6800,
        (u32) sPokedexText054,
    },
    {
        0x37, 0x00, 701,
        (char*) sSpeciesName055,
        (s32) sSpeciesCategory055,
        0x35, 0x11, 766,
        -60, 50,
        0x003C3800,
        (u32) sPokedexText055,
    },
    {
        0x38, 0x00, 1600,
        (char*) sSpeciesName056,
        (s32) sSpeciesCategory056,
        0x35, 0x05, 280,
        -35, 30,
        0x003CD400,
        (u32) sPokedexText056,
    },
    {
        0x39, 0x00, 880,
        (char*) sSpeciesName057,
        (s32) sSpeciesCategory057,
        0x37, 0x0A, 320,
        -35, 40,
        0x003C5BE2,
        (u32) sPokedexText057,
    },
    {
        0x3A, 0x00, 1350,
        (char*) sSpeciesName058,
        (s32) sSpeciesCategory058,
        0x3D, 0x07, 190,
        -35, 10,
        0x003C7432,
        (u32) sPokedexText058,
    },
    {
        0x3B, 0x00, 491,
        (char*) sSpeciesName059,
        (s32) sSpeciesCategory059,
        0x37, 0x13, 1550,
        -30, 20,
        0x003C8C64,
        (u32) sPokedexText059,
    },
    {
        0x3C, 0x00, 1300,
        (char*) sSpeciesName060,
        (s32) sSpeciesCategory060,
        0x3D, 0x06, 124,
        -50, 50,
        0x003D1FD8,
        (u32) sPokedexText060,
    },
    {
        0x3D, 0x00, 930,
        (char*) sSpeciesName061,
        (s32) sSpeciesCategory061,
        0x35, 0x0A, 200,
        -50, 50,
        0x003CA3EC,
        (u32) sPokedexText061,
    },
    {
        0x3E, 0x41, 725,
        (char*) sSpeciesName062,
        (s32) sSpeciesCategory062,
        0x35, 0x0D, 540,
        -50, 50,
        0x003C2FCE,
        (u32) sPokedexText062,
    },
    {
        0x3F, 0x00, 1400,
        (char*) sSpeciesName063,
        (s32) sSpeciesCategory063,
        0x3D, 0x09, 195,
        -20, 30,
        0x003D83D8,
        (u32) sPokedexText063,
    },
    {
        0x40, 0x00, 850,
        (char*) sSpeciesName064,
        (s32) sSpeciesCategory064,
        0x35, 0x0D, 565,
        -30, 30,
        0x003C97CE,
        (u32) sPokedexText064,
    },
    {
        0x41, 0x00, 733,
        (char*) sSpeciesName065,
        (s32) sSpeciesCategory065,
        0x33, 0x0F, 480,
        -30, 30,
        0x003C1000,
        (u32) sPokedexText065,
    },
    {
        0x42, 0x00, 1510,
        (char*) sSpeciesName066,
        (s32) sSpeciesCategory066,
        0x3D, 0x08, 195,
        -40, 60,
        0xFDBC3BD8,
        (u32) sPokedexText066,
    },
    {
        0x43, 0x00, 882,
        (char*) sSpeciesName067,
        (s32) sSpeciesCategory067,
        0x35, 0x0F, 705,
        -70, 60,
        0x003C67CE,
        (u32) sPokedexText067,
    },
    {
        0x44, 0x00, 750,
        (char*) sSpeciesName068,
        (s32) sSpeciesCategory068,
        0x37, 0x10, 1300,
        -70, 80,
        0x003BCC00,
        (u32) sPokedexText068,
    },
    {
        0x45, 0x00, 1761,
        (char*) sSpeciesName069,
        (s32) sSpeciesCategory069,
        0x3D, 0x07, 40,
        -20, 25,
        0x003B7028,
        (u32) sPokedexText069,
    },
    {
        0x46, 0x23, 929,
        (char*) sSpeciesName070,
        (s32) sSpeciesCategory070,
        0x35, 0x0A, 64,
        -25, 40,
        0x0039A800,
        (u32) sPokedexText070,
    },
    {
        0x47, 0x00, 550,
        (char*) sSpeciesName071,
        (s32) sSpeciesCategory071,
        0x35, 0x11, 155,
        -30, 30,
        0x00006400,
        (u32) sPokedexText071,
    },
    {
        0x48, 0x00, 909,
        (char*) sSpeciesName072,
        (s32) sSpeciesCategory072,
        0x35, 0x09, 455,
        -40, 40,
        0x00014000,
        (u32) sPokedexText072,
    },
    {
        0x49, 0x00, 620,
        (char*) sSpeciesName073,
        (s32) sSpeciesCategory073,
        0x35, 0x10, 550,
        -40, 40,
        0x0000F000,
        (u32) sPokedexText073,
    },
    {
        0x4A, 0x00, 1090,
        (char*) sSpeciesName074,
        (s32) sSpeciesCategory074,
        0x3D, 0x04, 200,
        -180, 180,
        0x0038D000,
        (u32) sPokedexText074,
    },
    {
        0x4B, 0x00, 800,
        (char*) sSpeciesName075,
        (s32) sSpeciesCategory075,
        0x35, 0x0A, 1050,
        -180, 180,
        0x003D23B0,
        (u32) sPokedexText075,
    },
    {
        0x4C, 0x00, 700,
        (char*) sSpeciesName076,
        (s32) sSpeciesCategory076,
        0x33, 0x0E, 3000,
        -50, 20,
        0x003C8BE7,
        (u32) sPokedexText076,
    },
    {
        0x4D, 0x03, 880,
        (char*) sSpeciesName077,
        (s32) sSpeciesCategory077,
        0x35, 0x0A, 300,
        -25, 20,
        0x003C2C3C,
        (u32) sPokedexText077,
    },
    {
        0x4E, 0x00, 530,
        (char*) sSpeciesName078,
        (s32) sSpeciesCategory078,
        0x35, 0x11, 950,
        -25, 20,
        0x003C0432,
        (u32) sPokedexText078,
    },
    {
        0x4F, 0x00, 767,
        (char*) sSpeciesName079,
        (s32) sSpeciesCategory079,
        0x35, 0x0C, 360,
        -40, 40,
        0x003D2400,
        (u32) sPokedexText079,
    },
    {
        0x50, 0x00, 590,
        (char*) sSpeciesName080,
        (s32) sSpeciesCategory080,
        0x35, 0x10, 785,
        -40, 40,
        0x003CEC64,
        (u32) sPokedexText080,
    },
    {
        0x51, 0x00, 2087,
        (char*) sSpeciesName081,
        (s32) sSpeciesCategory081,
        0x3D, 0x03, 60,
        -180, 180,
        0x0033A000,
        (u32) sPokedexText081,
    },
    {
        0x52, 0x00, 1180,
        (char*) sSpeciesName082,
        (s32) sSpeciesCategory082,
        0x33, 0x0A, 600,
        -180, 180,
        0x0000FC00,
        (u32) sPokedexText082,
    },
    {
        0x53, 0x00, 1330,
        (char*) sSpeciesName083,
        (s32) sSpeciesCategory083,
        0x3D, 0x08, 150,
        -30, 30,
        0x003C43F6,
        (u32) sPokedexText083,
    },
    {
        0x54, 0x00, 780,
        (char*) sSpeciesName084,
        (s32) sSpeciesCategory084,
        0x35, 0x0E, 392,
        -10, 40,
        0x003C2C00,
        (u32) sPokedexText084,
    },
    {
        0x55, 0x00, 614,
        (char*) sSpeciesName085,
        (s32) sSpeciesCategory085,
        0x35, 0x12, 852,
        -10, 40,
        0x003BBC00,
        (u32) sPokedexText085,
    },
    {
        0x56, 0x00, 1107,
        (char*) sSpeciesName086,
        (s32) sSpeciesCategory086,
        0x35, 0x0B, 900,
        -40, 30,
        0x003DFBD8,
        (u32) sPokedexText086,
    },
    {
        0x57, 0x00, 1340,
        (char*) sSpeciesName087,
        (s32) sSpeciesCategory087,
        0x35, 0x11, 1200,
        -10, 10,
        0x00005F67,
        (u32) sPokedexText087,
    },
    {
        0x58, 0x00, 908,
        (char*) sSpeciesName088,
        (s32) sSpeciesCategory088,
        0x35, 0x09, 300,
        -180, 180,
        0x003D5800,
        (u32) sPokedexText088,
    },
    {
        0x59, 0x00, 480,
        (char*) sSpeciesName089,
        (s32) sSpeciesCategory089,
        0x35, 0x0C, 300,
        -180, 180,
        0x003D8C3C,
        (u32) sPokedexText089,
    },
    {
        0x5A, 0x00, 2037,
        (char*) sSpeciesName090,
        (s32) sSpeciesCategory090,
        0x3D, 0x03, 40,
        -70, 40,
        0x003DBBD5,
        (u32) sPokedexText090,
    },
    {
        0x5B, 0x00, 543,
        (char*) sSpeciesName091,
        (s32) sSpeciesCategory091,
        0x37, 0x0F, 1325,
        -70, 60,
        0x003A3400,
        (u32) sPokedexText091,
    },
    {
        0x5C, 0x00, 365,
        (char*) sSpeciesName092,
        (s32) sSpeciesCategory092,
        0x3D, 0x0D, 1,
        -80, 50,
        0x0000A80A,
        (u32) sPokedexText092,
    },
    {
        0x5D, 0x00, 460,
        (char*) sSpeciesName093,
        (s32) sSpeciesCategory093,
        0x35, 0x10, 1,
        -70, 30,
        0x0000E000,
        (u32) sPokedexText093,
    },
    {
        0x5E, 0x00, 703,
        (char*) sSpeciesName094,
        (s32) sSpeciesCategory094,
        0x33, 0x0F, 405,
        -90, 30,
        0x003C3000,
        (u32) sPokedexText094,
    },
    {
        0x5F, 0x2D, 290,
        (char*) sSpeciesName095,
        (s32) sSpeciesCategory095,
        0x37, 0x58, 2100,
        -180, 180,
        0xE73CF7E2,
        (u32) sPokedexText095,
    },
    {
        0x60, 0x00, 930,
        (char*) sSpeciesName096,
        (s32) sSpeciesCategory096,
        0x35, 0x0A, 324,
        -10, 30,
        0x003C7814,
        (u32) sPokedexText096,
    },
    {
        0x61, 0x00, 800,
        (char*) sSpeciesName097,
        (s32) sSpeciesCategory097,
        0x33, 0x10, 756,
        -15, 30,
        0x003BF3D8,
        (u32) sPokedexText097,
    },
    {
        0x62, 0x00, 1100,
        (char*) sSpeciesName098,
        (s32) sSpeciesCategory098,
        0x3D, 0x04, 65,
        -20, 30,
        0x003E0FF6,
        (u32) sPokedexText098,
    },
    {
        0x63, 0x00, 494,
        (char*) sSpeciesName099,
        (s32) sSpeciesCategory099,
        0x35, 0x0D, 600,
        -20, 25,
        0x003D7C0F,
        (u32) sPokedexText099,
    },
    {
        0x64, 0x00, 1840,
        (char*) sSpeciesName100,
        (s32) sSpeciesCategory100,
        0x3D, 0x05, 104,
        -70, 10,
        0x003C6400,
        (u32) sPokedexText100,
    },
    {
        0x65, 0x00, 800,
        (char*) sSpeciesName101,
        (s32) sSpeciesCategory101,
        0x33, 0x0C, 666,
        -70, 10,
        0x003C5000,
        (u32) sPokedexText101,
    },
    {
        0x66, 0x00, 1160,
        (char*) sSpeciesName102,
        (s32) sSpeciesCategory102,
        0x3D, 0x04, 25,
        -50, 40,
        0x003E4400,
        (u32) sPokedexText102,
    },
    {
        0x67, 0x00, 600,
        (char*) sSpeciesName103,
        (s32) sSpeciesCategory103,
        0x33, 0x14, 1200,
        -30, 40,
        0x003C2400,
        (u32) sPokedexText103,
    },
    {
        0x68, 0x00, 2500,
        (char*) sSpeciesName104,
        (s32) sSpeciesCategory104,
        0x3D, 0x04, 65,
        -25, 5,
        0x003C2800,
        (u32) sPokedexText104,
    },
    {
        0x69, 0x00, 1140,
        (char*) sSpeciesName105,
        (s32) sSpeciesCategory105,
        0x35, 0x0A, 450,
        -25, 5,
        0x003C4000,
        (u32) sPokedexText105,
    },
    {
        0x6A, 0x00, 723,
        (char*) sSpeciesName106,
        (s32) sSpeciesCategory106,
        0x35, 0x0F, 498,
        -20, 50,
        0x003C5FE2,
        (u32) sPokedexText106,
    },
    {
        0x6B, 0x0A, 870,
        (char*) sSpeciesName107,
        (s32) sSpeciesCategory107,
        0x35, 0x0E, 502,
        -20, 50,
        0x003BE800,
        (u32) sPokedexText107,
    },
    {
        0x6C, 0x1C, 767,
        (char*) sSpeciesName108,
        (s32) sSpeciesCategory108,
        0x35, 0x0C, 655,
        -50, 30,
        0x003C9C00,
        (u32) sPokedexText108,
    },
    {
        0x6D, 0x00, 1500,
        (char*) sSpeciesName109,
        (s32) sSpeciesCategory109,
        0x3D, 0x06, 10,
        -60, 90,
        0x003FDC00,
        (u32) sPokedexText109,
    },
    {
        0x6E, 0x00, 855,
        (char*) sSpeciesName110,
        (s32) sSpeciesCategory110,
        0x35, 0x0C, 95,
        -60, 90,
        0x003FB800,
        (u32) sPokedexText110,
    },
    {
        0x6F, 0x00, 860,
        (char*) sSpeciesName111,
        (s32) sSpeciesCategory111,
        0x35, 0x0A, 1150,
        -180, 180,
        0x003D87EC,
        (u32) sPokedexText111,
    },
    {
        0x70, 0x00, 523,
        (char*) sSpeciesName112,
        (s32) sSpeciesCategory112,
        0x35, 0x13, 1200,
        -180, 180,
        0x003C9832,
        (u32) sPokedexText112,
    },
    {
        0x71, 0x00, 850,
        (char*) sSpeciesName113,
        (s32) sSpeciesCategory113,
        0x33, 0x0B, 346,
        -50, 60,
        0x003C9C00,
        (u32) sPokedexText113,
    },
    {
        0x72, 0x00, 1000,
        (char*) sSpeciesName114,
        (s32) sSpeciesCategory114,
        0x35, 0x0A, 350,
        -40, 20,
        0x003C5400,
        (u32) sPokedexText114,
    },
    {
        0x73, 0x00, 479,
        (char*) sSpeciesName115,
        (s32) sSpeciesCategory115,
        0x33, 0x16, 800,
        -30, 50,
        0x003CB85A,
        (u32) sPokedexText115,
    },
    {
        0x74, 0x00, 2110,
        (char*) sSpeciesName116,
        (s32) sSpeciesCategory116,
        0x3D, 0x04, 80,
        -40, 40,
        0x003F2400,
        (u32) sPokedexText116,
    },
    {
        0x75, 0x00, 827,
        (char*) sSpeciesName117,
        (s32) sSpeciesCategory117,
        0x35, 0x0C, 250,
        -30, 35,
        0x003EBC00,
        (u32) sPokedexText117,
    },
    {
        0x76, 0x16, 2340,
        (char*) sSpeciesName118,
        (s32) sSpeciesCategory118,
        0x3D, 0x06, 150,
        -60, 40,
        0x00004CA0,
        (u32) sPokedexText118,
    },
    {
        0x77, 0x02, 1000,
        (char*) sSpeciesName119,
        (s32) sSpeciesCategory119,
        0x35, 0x0D, 390,
        -50, 30,
        0x0000DC32,
        (u32) sPokedexText119,
    },
    {
        0x78, 0x00, 1430,
        (char*) sSpeciesName120,
        (s32) sSpeciesCategory120,
        0x35, 0x08, 345,
        -10, 30,
        0x003BF000,
        (u32) sPokedexText120,
    },
    {
        0x79, 0x00, 1047,
        (char*) sSpeciesName121,
        (s32) sSpeciesCategory121,
        0x33, 0x0B, 800,
        -40, 50,
        0x003BB800,
        (u32) sPokedexText121,
    },
    {
        0x7A, 0x00, 895,
        (char*) sSpeciesName122,
        (s32) sSpeciesCategory122,
        0x35, 0x0D, 545,
        -30, 50,
        0x003BDFE2,
        (u32) sPokedexText122,
    },
    {
        0x7B, 0x00, 653,
        (char*) sSpeciesName123,
        (s32) sSpeciesCategory123,
        0x37, 0x0F, 560,
        -30, 50,
        0x003CE324,
        (u32) sPokedexText123,
    },
    {
        0x7C, 0x00, 691,
        (char*) sSpeciesName124,
        (s32) sSpeciesCategory124,
        0x33, 0x0E, 406,
        -10, 30,
        0x003C6800,
        (u32) sPokedexText124,
    },
    {
        0x7D, 0x17, 817,
        (char*) sSpeciesName125,
        (s32) sSpeciesCategory125,
        0x35, 0x0B, 300,
        -20, 30,
        0x003C5000,
        (u32) sPokedexText125,
    },
    {
        0x7E, 0x00, 700,
        (char*) sSpeciesName126,
        (s32) sSpeciesCategory126,
        0x35, 0x0D, 445,
        -15, 30,
        0x003BFC64,
        (u32) sPokedexText126,
    },
    {
        0x7F, 0x00, 703,
        (char*) sSpeciesName127,
        (s32) sSpeciesCategory127,
        0x37, 0x0F, 550,
        -60, 130,
        0x003BE400,
        (u32) sPokedexText127,
    },
    {
        0x80, 0x00, 670,
        (char*) sSpeciesName128,
        (s32) sSpeciesCategory128,
        0x33, 0x0E, 884,
        -10, 30,
        0x003CE000,
        (u32) sPokedexText128,
    },
    {
        0x81, 0x00, 1329,
        (char*) sSpeciesName129,
        (s32) sSpeciesCategory129,
        0x3D, 0x09, 100,
        -30, 25,
        0x003D2800,
        (u32) sPokedexText129,
    },
    {
        0x82, 0x00, 380,
        (char*) sSpeciesName130,
        (s32) sSpeciesCategory130,
        0x33, 0x41, 2350,
        -20, 50,
        0x0038B000,
        (u32) sPokedexText130,
    },
    {
        0x83, 0x00, 400,
        (char*) sSpeciesName131,
        (s32) sSpeciesCategory131,
        0x33, 0x19, 2200,
        -30, 20,
        0x003AB014,
        (u32) sPokedexText131,
    },
    {
        0x84, 0x00, 2200,
        (char*) sSpeciesName132,
        (s32) sSpeciesCategory132,
        0x3B, 0x03, 40,
        -60, 20,
        0x003D5800,
        (u32) sPokedexText132,
    },
    {
        0x85, 0x00, 2600,
        (char*) sSpeciesName133,
        (s32) sSpeciesCategory133,
        0x3D, 0x03, 65,
        -30, 30,
        0x003D8C00,
        (u32) sPokedexText133,
    },
    {
        0x86, 0x00, 980,
        (char*) sSpeciesName134,
        (s32) sSpeciesCategory134,
        0x33, 0x0A, 290,
        -20, 50,
        0xF8BCCF6A,
        (u32) sPokedexText134,
    },
    {
        0x87, 0x00, 1370,
        (char*) sSpeciesName135,
        (s32) sSpeciesCategory135,
        0x33, 0x08, 245,
        -25, 20,
        0x003C8FE2,
        (u32) sPokedexText135,
    },
    {
        0x88, 0x00, 1148,
        (char*) sSpeciesName136,
        (s32) sSpeciesCategory136,
        0x37, 0x09, 250,
        -20, 30,
        0x003C401E,
        (u32) sPokedexText136,
    },
    {
        0x89, 0x00, 960,
        (char*) sSpeciesName137,
        (s32) sSpeciesCategory137,
        0x35, 0x08, 365,
        -40, 40,
        0x00366000,
        (u32) sPokedexText137,
    },
    {
        0x8A, 0x00, 2240,
        (char*) sSpeciesName138,
        (s32) sSpeciesCategory138,
        0x3D, 0x04, 75,
        -15, 60,
        0x003D07AB,
        (u32) sPokedexText138,
    },
    {
        0x8B, 0x00, 909,
        (char*) sSpeciesName139,
        (s32) sSpeciesCategory139,
        0x35, 0x0A, 350,
        -15, 60,
        0x003CA7B5,
        (u32) sPokedexText139,
    },
    {
        0x8C, 0x00, 2000,
        (char*) sSpeciesName140,
        (s32) sSpeciesCategory140,
        0x3D, 0x05, 115,
        -20, 30,
        0x003D5800,
        (u32) sPokedexText140,
    },
    {
        0x8D, 0x00, 774,
        (char*) sSpeciesName141,
        (s32) sSpeciesCategory141,
        0x35, 0x0D, 405,
        -40, 50,
        0x003C8C00,
        (u32) sPokedexText141,
    },
    {
        0x8E, 0x22, 394,
        (char*) sSpeciesName142,
        (s32) sSpeciesCategory142,
        0x37, 0x12, 590,
        -60, 60,
        0x003E6800,
        (u32) sPokedexText142,
    },
    {
        0x8F, 0x00, 510,
        (char*) sSpeciesName143,
        (s32) sSpeciesCategory143,
        0x33, 0x15, 4600,
        -10, 60,
        0x003D5829,
        (u32) sPokedexText143,
    },
    {
        0x90, 0x00, 650,
        (char*) sSpeciesName144,
        (s32) sSpeciesCategory144,
        0x31, 0x11, 554,
        -20, 30,
        0x003BD400,
        (u32) sPokedexText144,
    },
    {
        0x91, 0x06, 600,
        (char*) sSpeciesName145,
        (s32) sSpeciesCategory145,
        0x31, 0x10, 526,
        -20, 25,
        0x00002800,
        (u32) sPokedexText145,
    },
    {
        0x92, 0x00, 600,
        (char*) sSpeciesName146,
        (s32) sSpeciesCategory146,
        0x35, 0x14, 600,
        -20, 20,
        0x003BAC00,
        (u32) sPokedexText146,
    },
    {
        0x93, 0x00, 1050,
        (char*) sSpeciesName147,
        (s32) sSpeciesCategory147,
        0x3D, 0x12, 33,
        -40, 20,
        0x1E3C7C00,
        (u32) sPokedexText147,
    },
    {
        0x94, 0x00, 570,
        (char*) sSpeciesName148,
        (s32) sSpeciesCategory148,
        0x35, 0x28, 165,
        -30, 10,
        0x21FC3BC4,
        (u32) sPokedexText148,
    },
    {
        0x95, 0x00, 473,
        (char*) sSpeciesName149,
        (s32) sSpeciesCategory149,
        0x31, 0x16, 2100,
        -20, 25,
        0x003C1FF6,
        (u32) sPokedexText149,
    },
    {
        0x96, 0x00, 540,
        (char*) sSpeciesName150,
        (s32) sSpeciesCategory150,
        0x20, 0x14, 1220,
        -70, 90,
        0x003C2400,
        (u32) sPokedexText150,
    },
    {
        0x97, 0x00, 2000,
        (char*) sSpeciesName151,
        (s32) sSpeciesCategory151,
        0x20, 0x04, 40,
        -40, 60,
        0x003F7400,
        (u32) sPokedexText151,
    },
    {
        0x98, 0x00, 1510,
        (char*) sSpeciesName152,
        (s32) sSpeciesCategory152,
        0x00, 0x0A, 50,
        -50, 50,
        0xFDBC3BD8,
        (u32) sPokedexText152,
    },
};

#else
// Pokemon name slots. Writable: ui_graphics fills these in at runtime via
// HAL_Strcpy(D_8006FF00[i].name, ...); the shipped contents are placeholders.
static char sPokemonNames[152][0xC] = {
    "pmname_001", "pmname_002", "pmname_003", "pmname_004",
    "pmname_005", "pmname_006", "pmname_007", "pmname_008",
    "pmname_009", "pmname_010", "pmname_011", "pmname_012",
    "pmname_013", "pmname_014", "pmname_015", "pmname_016",
    "pmname_017", "pmname_018", "pmname_019", "pmname_020",
    "pmname_021", "pmname_022", "pmname_023", "pmname_024",
    "pmname_025", "pmname_026", "pmname_027", "pmname_028",
    "pmname_029", "pmname_030", "pmname_031", "pmname_032",
    "pmname_033", "pmname_034", "pmname_035", "pmname_036",
    "pmname_037", "pmname_038", "pmname_039", "pmname_040",
    "pmname_041", "pmname_042", "pmname_043", "pmname_044",
    "pmname_045", "pmname_046", "pmname_047", "pmname_048",
    "pmname_049", "pmname_050", "pmname_051", "pmname_052",
    "pmname_053", "pmname_054", "pmname_055", "pmname_056",
    "pmname_057", "pmname_058", "pmname_059", "pmname_060",
    "pmname_061", "pmname_062", "pmname_063", "pmname_064",
    "pmname_065", "pmname_066", "pmname_067", "pmname_068",
    "pmname_069", "pmname_070", "pmname_071", "pmname_072",
    "pmname_073", "pmname_074", "pmname_075", "pmname_076",
    "pmname_077", "pmname_078", "pmname_079", "pmname_080",
    "pmname_081", "pmname_082", "pmname_083", "pmname_084",
    "pmname_085", "pmname_086", "pmname_087", "pmname_088",
    "pmname_089", "pmname_090", "pmname_091", "pmname_092",
    "pmname_093", "pmname_094", "pmname_095", "pmname_096",
    "pmname_097", "pmname_098", "pmname_099", "pmname_100",
    "pmname_101", "pmname_102", "pmname_103", "pmname_104",
    "pmname_105", "pmname_106", "pmname_107", "pmname_108",
    "pmname_109", "pmname_110", "pmname_111", "pmname_112",
    "pmname_113", "pmname_114", "pmname_115", "pmname_116",
    "pmname_117", "pmname_118", "pmname_119", "pmname_120",
    "pmname_121", "pmname_122", "pmname_123", "pmname_124",
    "pmname_125", "pmname_126", "pmname_127", "pmname_128",
    "pmname_129", "pmname_130", "pmname_131", "pmname_132",
    "pmname_133", "pmname_134", "pmname_135", "pmname_136",
    "pmname_137", "pmname_138", "pmname_139", "pmname_140",
    "pmname_141", "pmname_142", "pmname_143", "pmname_144",
    "pmname_145", "pmname_146", "pmname_147", "pmname_148",
    "pmname_149", "pmname_150", "pmname_151", "pmname_152",
};

unk_D_8006FF00 D_8006FF00[152] = {
    {
        0x01, 0x00, 1270,
        sPokemonNames[0],
        (s32) sPokemonNames[0],
        0x3D, 0x07, 69,
        -45, 70,
        0x003C73E2,
        (u32) sPokemonNames[0],
    },
    {
        0x02, 0x00, 839,
        sPokemonNames[1],
        (s32) sPokemonNames[1],
        0x35, 0x0A, 130,
        -40, 45,
        0x003D0046,
        (u32) sPokemonNames[1],
    },
    {
        0x03, 0x00, 509,
        sPokemonNames[2],
        (s32) sPokemonNames[2],
        0x31, 0x14, 1000,
        -30, 40,
        0x003CFFC4,
        (u32) sPokemonNames[2],
    },
    {
        0x04, 0x0A, 1583,
        sPokemonNames[3],
        (s32) sPokemonNames[3],
        0x3D, 0x06, 85,
        -25, 20,
        0x003C6C42,
        (u32) sPokemonNames[3],
    },
    {
        0x05, 0x00, 957,
        sPokemonNames[4],
        (s32) sPokemonNames[4],
        0x35, 0x0B, 190,
        -10, 55,
        0x003BFFEC,
        (u32) sPokemonNames[4],
    },
    {
        0x06, 0x00, 620,
        sPokemonNames[5],
        (s32) sPokemonNames[5],
        0x35, 0x11, 905,
        -20, 15,
        0x003BEC31,
        (u32) sPokemonNames[5],
    },
    {
        0x07, 0x00, 1910,
        sPokemonNames[6],
        (s32) sPokemonNames[6],
        0x3D, 0x05, 90,
        -50, 30,
        0x003C9800,
        (u32) sPokemonNames[6],
    },
    {
        0x08, 0x00, 1060,
        sPokemonNames[7],
        (s32) sPokemonNames[7],
        0x35, 0x0A, 225,
        -50, 30,
        0x003BEC00,
        (u32) sPokemonNames[7],
    },
    {
        0x09, 0x00, 730,
        sPokemonNames[8],
        (s32) sPokemonNames[8],
        0x35, 0x10, 855,
        -30, 35,
        0x003C6BCE,
        (u32) sPokemonNames[8],
    },
    {
        0x0A, 0x00, 5017,
        sPokemonNames[9],
        (s32) sPokemonNames[9],
        0x3D, 0x03, 29,
        -30, 80,
        0x003C1814,
        (u32) sPokemonNames[9],
    },
    {
        0x0B, 0x00, 1490,
        sPokemonNames[10],
        (s32) sPokemonNames[10],
        0x35, 0x07, 99,
        -20, 60,
        0x003CB000,
        (u32) sPokemonNames[10],
    },
    {
        0x0C, 0x04, 997,
        sPokemonNames[11],
        (s32) sPokemonNames[11],
        0x35, 0x0B, 320,
        -40, 50,
        0x003E8464,
        (u32) sPokemonNames[11],
    },
    {
        0x0D, 0x00, 3380,
        sPokemonNames[12],
        (s32) sPokemonNames[12],
        0x3D, 0x03, 32,
        0, 50,
        0x003BF414,
        (u32) sPokemonNames[12],
    },
    {
        0x0E, 0x00, 1729,
        sPokemonNames[13],
        (s32) sPokemonNames[13],
        0x35, 0x06, 100,
        -25, 40,
        0x003C045A,
        (u32) sPokemonNames[13],
    },
    {
        0x0F, 0x00, 910,
        sPokemonNames[14],
        (s32) sPokemonNames[14],
        0x37, 0x0A, 295,
        -20, 50,
        0x003FC400,
        (u32) sPokemonNames[14],
    },
    {
        0x10, 0x00, 3400,
        sPokemonNames[15],
        (s32) sPokemonNames[15],
        0x3D, 0x03, 18,
        -30, 30,
        0x003C7FF6,
        (u32) sPokemonNames[15],
    },
    {
        0x11, 0x00, 900,
        sPokemonNames[16],
        (s32) sPokemonNames[16],
        0x35, 0x0B, 300,
        -30, 30,
        0x003C401E,
        (u32) sPokemonNames[16],
    },
    {
        0x12, 0x08, 693,
        sPokemonNames[17],
        (s32) sPokemonNames[17],
        0x35, 0x0F, 395,
        -35, 20,
        0x003C6BEC,
        (u32) sPokemonNames[17],
    },
    {
        0x13, 0x00, 1960,
        sPokemonNames[18],
        (s32) sPokemonNames[18],
        0x3D, 0x03, 35,
        -40, 60,
        0x003C8800,
        (u32) sPokemonNames[18],
    },
    {
        0x14, 0x00, 1280,
        sPokemonNames[19],
        (s32) sPokemonNames[19],
        0x35, 0x07, 185,
        -30, 30,
        0x003C8400,
        (u32) sPokemonNames[19],
    },
    {
        0x15, 0x00, 3090,
        sPokemonNames[20],
        (s32) sPokemonNames[20],
        0x3D, 0x03, 20,
        -30, 20,
        0x003C53E2,
        (u32) sPokemonNames[20],
    },
    {
        0x16, 0x12, 897,
        sPokemonNames[21],
        (s32) sPokemonNames[21],
        0x37, 0x0C, 380,
        -25, 30,
        0x003ECBA6,
        (u32) sPokemonNames[21],
    },
    {
        0x17, 0x00, 1779,
        sPokemonNames[22],
        (s32) sPokemonNames[22],
        0x3D, 0x14, 69,
        -30, 40,
        0x003D0032,
        (u32) sPokemonNames[22],
    },
    {
        0x18, 0x00, 730,
        sPokemonNames[23],
        (s32) sPokemonNames[23],
        0x35, 0x23, 650,
        -70, 30,
        0x003BC81E,
        (u32) sPokemonNames[23],
    },
    {
        0x19, 0x00, 2400,
        sPokemonNames[24],
        (s32) sPokemonNames[24],
        0x3F, 0x04, 60,
        -15, 25,
        0x003BCC28,
        (u32) sPokemonNames[24],
    },
    {
        0x1A, 0x00, 1350,
        sPokemonNames[25],
        (s32) sPokemonNames[25],
        0x35, 0x08, 300,
        -15, 25,
        0x003C4C00,
        (u32) sPokemonNames[25],
    },
    {
        0x1B, 0x00, 1599,
        sPokemonNames[26],
        (s32) sPokemonNames[26],
        0x3D, 0x06, 120,
        -40, 40,
        0x003C9400,
        (u32) sPokemonNames[26],
    },
    {
        0x1C, 0x00, 1040,
        sPokemonNames[27],
        (s32) sPokemonNames[27],
        0x35, 0x0A, 295,
        -20, 25,
        0x003C2C46,
        (u32) sPokemonNames[27],
    },
    {
        0x1D, 0x00, 2130,
        sPokemonNames[28],
        (s32) sPokemonNames[28],
        0x3D, 0x04, 70,
        -60, 70,
        0x003C1C32,
        (u32) sPokemonNames[28],
    },
    {
        0x1E, 0x00, 1135,
        sPokemonNames[29],
        (s32) sPokemonNames[29],
        0x35, 0x08, 200,
        -80, 80,
        0x003C942D,
        (u32) sPokemonNames[29],
    },
    {
        0x1F, 0x00, 795,
        sPokemonNames[30],
        (s32) sPokemonNames[30],
        0x37, 0x0D, 600,
        -60, 80,
        0x003C43EC,
        (u32) sPokemonNames[30],
    },
    {
        0x20, 0x00, 1550,
        sPokemonNames[31],
        (s32) sPokemonNames[31],
        0x3D, 0x05, 90,
        -70, 20,
        0x003D2FD8,
        (u32) sPokemonNames[31],
    },
    {
        0x21, 0x00, 1100,
        sPokemonNames[32],
        (s32) sPokemonNames[32],
        0x35, 0x09, 195,
        -70, 20,
        0x003D57CE,
        (u32) sPokemonNames[32],
    },
    {
        0x22, 0x00, 860,
        sPokemonNames[33],
        (s32) sPokemonNames[33],
        0x37, 0x0E, 620,
        -50, 30,
        0x003C6F9C,
        (u32) sPokemonNames[33],
    },
    {
        0x23, 0x15, 1540,
        sPokemonNames[34],
        (s32) sPokemonNames[34],
        0x3D, 0x06, 75,
        -40, 50,
        0x003BF428,
        (u32) sPokemonNames[34],
    },
    {
        0x24, 0x00, 685,
        sPokemonNames[35],
        (s32) sPokemonNames[35],
        0x35, 0x0D, 400,
        -40, 50,
        0x003B8400,
        (u32) sPokemonNames[35],
    },
    {
        0x25, 0x00, 1523,
        sPokemonNames[36],
        (s32) sPokemonNames[36],
        0x3D, 0x06, 99,
        -30, 35,
        0x003C0C14,
        (u32) sPokemonNames[36],
    },
    {
        0x26, 0x00, 950,
        sPokemonNames[37],
        (s32) sPokemonNames[37],
        0x35, 0x0B, 199,
        -30, 50,
        0x003BBC00,
        (u32) sPokemonNames[37],
    },
    {
        0x27, 0x00, 1620,
        sPokemonNames[38],
        (s32) sPokemonNames[38],
        0x3D, 0x05, 55,
        -40, 40,
        0x003CDBF6,
        (u32) sPokemonNames[38],
    },
    {
        0x28, 0x00, 800,
        sPokemonNames[39],
        (s32) sPokemonNames[39],
        0x35, 0x0A, 120,
        -40, 40,
        0x003BE7E2,
        (u32) sPokemonNames[39],
    },
    {
        0x29, 0x00, 1080,
        sPokemonNames[40],
        (s32) sPokemonNames[40],
        0x3D, 0x08, 75,
        -30, 30,
        0x0033280A,
        (u32) sPokemonNames[40],
    },
    {
        0x2A, 0x00, 730,
        sPokemonNames[41],
        (s32) sPokemonNames[41],
        0x35, 0x10, 550,
        -25, 30,
        0x003C5400,
        (u32) sPokemonNames[41],
    },
    {
        0x2B, 0x0B, 1860,
        sPokemonNames[42],
        (s32) sPokemonNames[42],
        0x3D, 0x05, 54,
        -40, 70,
        0x003C2C28,
        (u32) sPokemonNames[42],
    },
    {
        0x2C, 0x00, 1190,
        sPokemonNames[43],
        (s32) sPokemonNames[43],
        0x35, 0x08, 86,
        -40, 65,
        0x003C6000,
        (u32) sPokemonNames[43],
    },
    {
        0x2D, 0x00, 637,
        sPokemonNames[44],
        (s32) sPokemonNames[44],
        0x35, 0x0C, 186,
        -25, 60,
        0x003C5FEC,
        (u32) sPokemonNames[44],
    },
    {
        0x2E, 0x00, 2160,
        sPokemonNames[45],
        (s32) sPokemonNames[45],
        0x3D, 0x03, 54,
        -20, 30,
        0x003D13EC,
        (u32) sPokemonNames[45],
    },
    {
        0x2F, 0x00, 950,
        sPokemonNames[46],
        (s32) sPokemonNames[46],
        0x35, 0x0A, 295,
        -20, 35,
        0x003CCBE2,
        (u32) sPokemonNames[46],
    },
    {
        0x30, 0x00, 740,
        sPokemonNames[47],
        (s32) sPokemonNames[47],
        0x35, 0x0A, 300,
        -60, 60,
        0x003CABEC,
        (u32) sPokemonNames[47],
    },
    {
        0x31, 0x02, 763,
        sPokemonNames[48],
        (s32) sPokemonNames[48],
        0x35, 0x0F, 125,
        -60, 100,
        0x003E9C18,
        (u32) sPokemonNames[48],
    },
    {
        0x32, 0x00, 4000,
        sPokemonNames[49],
        (s32) sPokemonNames[49],
        0x3D, 0x02, 8,
        -20, 35,
        0x003D6800,
        (u32) sPokemonNames[49],
    },
    {
        0x33, 0x00, 1150,
        sPokemonNames[50],
        (s32) sPokemonNames[50],
        0x33, 0x07, 333,
        -20, 35,
        0x003D1000,
        (u32) sPokemonNames[50],
    },
    {
        0x34, 0x00, 2400,
        sPokemonNames[51],
        (s32) sPokemonNames[51],
        0x3D, 0x04, 42,
        -40, 35,
        0x003C2C00,
        (u32) sPokemonNames[51],
    },
    {
        0x35, 0x00, 1040,
        sPokemonNames[52],
        (s32) sPokemonNames[52],
        0x35, 0x0A, 320,
        -20, 50,
        0x003DB01E,
        (u32) sPokemonNames[52],
    },
    {
        0x36, 0x00, 1230,
        sPokemonNames[53],
        (s32) sPokemonNames[53],
        0x3D, 0x08, 196,
        -20, 30,
        0x003C6800,
        (u32) sPokemonNames[53],
    },
    {
        0x37, 0x00, 701,
        sPokemonNames[54],
        (s32) sPokemonNames[54],
        0x35, 0x11, 766,
        -60, 50,
        0x003C3800,
        (u32) sPokemonNames[54],
    },
    {
        0x38, 0x00, 1600,
        sPokemonNames[55],
        (s32) sPokemonNames[55],
        0x35, 0x05, 280,
        -35, 30,
        0x003CD400,
        (u32) sPokemonNames[55],
    },
    {
        0x39, 0x00, 880,
        sPokemonNames[56],
        (s32) sPokemonNames[56],
        0x37, 0x0A, 320,
        -35, 40,
        0x003C5BE2,
        (u32) sPokemonNames[56],
    },
    {
        0x3A, 0x00, 1350,
        sPokemonNames[57],
        (s32) sPokemonNames[57],
        0x3D, 0x07, 190,
        -35, 10,
        0x003C7432,
        (u32) sPokemonNames[57],
    },
    {
        0x3B, 0x00, 491,
        sPokemonNames[58],
        (s32) sPokemonNames[58],
        0x37, 0x13, 1550,
        -30, 20,
        0x003C8C64,
        (u32) sPokemonNames[58],
    },
    {
        0x3C, 0x00, 1300,
        sPokemonNames[59],
        (s32) sPokemonNames[59],
        0x3D, 0x06, 124,
        -50, 50,
        0x003D1FD8,
        (u32) sPokemonNames[59],
    },
    {
        0x3D, 0x00, 930,
        sPokemonNames[60],
        (s32) sPokemonNames[60],
        0x35, 0x0A, 200,
        -50, 50,
        0x003CA3EC,
        (u32) sPokemonNames[60],
    },
    {
        0x3E, 0x41, 725,
        sPokemonNames[61],
        (s32) sPokemonNames[61],
        0x35, 0x0D, 540,
        -50, 50,
        0x003C2FCE,
        (u32) sPokemonNames[61],
    },
    {
        0x3F, 0x00, 1400,
        sPokemonNames[62],
        (s32) sPokemonNames[62],
        0x3D, 0x09, 195,
        -20, 30,
        0x003D83D8,
        (u32) sPokemonNames[62],
    },
    {
        0x40, 0x00, 850,
        sPokemonNames[63],
        (s32) sPokemonNames[63],
        0x35, 0x0D, 565,
        -30, 30,
        0x003C97CE,
        (u32) sPokemonNames[63],
    },
    {
        0x41, 0x00, 733,
        sPokemonNames[64],
        (s32) sPokemonNames[64],
        0x33, 0x0F, 480,
        -30, 30,
        0x003C1000,
        (u32) sPokemonNames[64],
    },
    {
        0x42, 0x00, 1510,
        sPokemonNames[65],
        (s32) sPokemonNames[65],
        0x3D, 0x08, 195,
        -40, 60,
        0xFDBC3BD8,
        (u32) sPokemonNames[65],
    },
    {
        0x43, 0x00, 882,
        sPokemonNames[66],
        (s32) sPokemonNames[66],
        0x35, 0x0F, 705,
        -70, 60,
        0x003C67CE,
        (u32) sPokemonNames[66],
    },
    {
        0x44, 0x00, 750,
        sPokemonNames[67],
        (s32) sPokemonNames[67],
        0x37, 0x10, 1300,
        -70, 80,
        0x003BCC00,
        (u32) sPokemonNames[67],
    },
    {
        0x45, 0x00, 1761,
        sPokemonNames[68],
        (s32) sPokemonNames[68],
        0x3D, 0x07, 40,
        -20, 25,
        0x003B7028,
        (u32) sPokemonNames[68],
    },
    {
        0x46, 0x23, 929,
        sPokemonNames[69],
        (s32) sPokemonNames[69],
        0x35, 0x0A, 64,
        -25, 40,
        0x0039A800,
        (u32) sPokemonNames[69],
    },
    {
        0x47, 0x00, 550,
        sPokemonNames[70],
        (s32) sPokemonNames[70],
        0x35, 0x11, 155,
        -30, 30,
        0x00006400,
        (u32) sPokemonNames[70],
    },
    {
        0x48, 0x00, 909,
        sPokemonNames[71],
        (s32) sPokemonNames[71],
        0x35, 0x09, 455,
        -40, 40,
        0x00014000,
        (u32) sPokemonNames[71],
    },
    {
        0x49, 0x00, 620,
        sPokemonNames[72],
        (s32) sPokemonNames[72],
        0x35, 0x10, 550,
        -40, 40,
        0x0000F000,
        (u32) sPokemonNames[72],
    },
    {
        0x4A, 0x00, 1090,
        sPokemonNames[73],
        (s32) sPokemonNames[73],
        0x3D, 0x04, 200,
        -180, 180,
        0x0038D000,
        (u32) sPokemonNames[73],
    },
    {
        0x4B, 0x00, 800,
        sPokemonNames[74],
        (s32) sPokemonNames[74],
        0x35, 0x0A, 1050,
        -180, 180,
        0x003D23B0,
        (u32) sPokemonNames[74],
    },
    {
        0x4C, 0x00, 700,
        sPokemonNames[75],
        (s32) sPokemonNames[75],
        0x33, 0x0E, 3000,
        -50, 20,
        0x003C8BE7,
        (u32) sPokemonNames[75],
    },
    {
        0x4D, 0x03, 880,
        sPokemonNames[76],
        (s32) sPokemonNames[76],
        0x35, 0x0A, 300,
        -25, 20,
        0x003C2C3C,
        (u32) sPokemonNames[76],
    },
    {
        0x4E, 0x00, 530,
        sPokemonNames[77],
        (s32) sPokemonNames[77],
        0x35, 0x11, 950,
        -25, 20,
        0x003C0432,
        (u32) sPokemonNames[77],
    },
    {
        0x4F, 0x00, 767,
        sPokemonNames[78],
        (s32) sPokemonNames[78],
        0x35, 0x0C, 360,
        -40, 40,
        0x003D2400,
        (u32) sPokemonNames[78],
    },
    {
        0x50, 0x00, 590,
        sPokemonNames[79],
        (s32) sPokemonNames[79],
        0x35, 0x10, 785,
        -40, 40,
        0x003CEC64,
        (u32) sPokemonNames[79],
    },
    {
        0x51, 0x00, 2087,
        sPokemonNames[80],
        (s32) sPokemonNames[80],
        0x3D, 0x03, 60,
        -180, 180,
        0x0033A000,
        (u32) sPokemonNames[80],
    },
    {
        0x52, 0x00, 1180,
        sPokemonNames[81],
        (s32) sPokemonNames[81],
        0x33, 0x0A, 600,
        -180, 180,
        0x0000FC00,
        (u32) sPokemonNames[81],
    },
    {
        0x53, 0x00, 1330,
        sPokemonNames[82],
        (s32) sPokemonNames[82],
        0x3D, 0x08, 150,
        -30, 30,
        0x003C43F6,
        (u32) sPokemonNames[82],
    },
    {
        0x54, 0x00, 780,
        sPokemonNames[83],
        (s32) sPokemonNames[83],
        0x35, 0x0E, 392,
        -10, 40,
        0x003C2C00,
        (u32) sPokemonNames[83],
    },
    {
        0x55, 0x00, 614,
        sPokemonNames[84],
        (s32) sPokemonNames[84],
        0x35, 0x12, 852,
        -10, 40,
        0x003BBC00,
        (u32) sPokemonNames[84],
    },
    {
        0x56, 0x00, 1107,
        sPokemonNames[85],
        (s32) sPokemonNames[85],
        0x35, 0x0B, 900,
        -40, 30,
        0x003DFBD8,
        (u32) sPokemonNames[85],
    },
    {
        0x57, 0x00, 1340,
        sPokemonNames[86],
        (s32) sPokemonNames[86],
        0x35, 0x11, 1200,
        -10, 10,
        0x00005F67,
        (u32) sPokemonNames[86],
    },
    {
        0x58, 0x00, 908,
        sPokemonNames[87],
        (s32) sPokemonNames[87],
        0x35, 0x09, 300,
        -180, 180,
        0x003D5800,
        (u32) sPokemonNames[87],
    },
    {
        0x59, 0x00, 480,
        sPokemonNames[88],
        (s32) sPokemonNames[88],
        0x35, 0x0C, 300,
        -180, 180,
        0x003D8C3C,
        (u32) sPokemonNames[88],
    },
    {
        0x5A, 0x00, 2037,
        sPokemonNames[89],
        (s32) sPokemonNames[89],
        0x3D, 0x03, 40,
        -70, 40,
        0x003DBBD5,
        (u32) sPokemonNames[89],
    },
    {
        0x5B, 0x00, 543,
        sPokemonNames[90],
        (s32) sPokemonNames[90],
        0x37, 0x0F, 1325,
        -70, 60,
        0x003A3400,
        (u32) sPokemonNames[90],
    },
    {
        0x5C, 0x00, 365,
        sPokemonNames[91],
        (s32) sPokemonNames[91],
        0x3D, 0x0D, 1,
        -80, 50,
        0x0000A80A,
        (u32) sPokemonNames[91],
    },
    {
        0x5D, 0x00, 460,
        sPokemonNames[92],
        (s32) sPokemonNames[92],
        0x35, 0x10, 1,
        -70, 30,
        0x0000E000,
        (u32) sPokemonNames[92],
    },
    {
        0x5E, 0x00, 703,
        sPokemonNames[93],
        (s32) sPokemonNames[93],
        0x33, 0x0F, 405,
        -90, 30,
        0x003C3000,
        (u32) sPokemonNames[93],
    },
    {
        0x5F, 0x2D, 290,
        sPokemonNames[94],
        (s32) sPokemonNames[94],
        0x37, 0x58, 2100,
        -180, 180,
        0xE73CF7E2,
        (u32) sPokemonNames[94],
    },
    {
        0x60, 0x00, 930,
        sPokemonNames[95],
        (s32) sPokemonNames[95],
        0x35, 0x0A, 324,
        -10, 30,
        0x003C7814,
        (u32) sPokemonNames[95],
    },
    {
        0x61, 0x00, 800,
        sPokemonNames[96],
        (s32) sPokemonNames[96],
        0x33, 0x10, 756,
        -15, 30,
        0x003BF3D8,
        (u32) sPokemonNames[96],
    },
    {
        0x62, 0x00, 1100,
        sPokemonNames[97],
        (s32) sPokemonNames[97],
        0x3D, 0x04, 65,
        -20, 30,
        0x003E0FF6,
        (u32) sPokemonNames[97],
    },
    {
        0x63, 0x00, 494,
        sPokemonNames[98],
        (s32) sPokemonNames[98],
        0x35, 0x0D, 600,
        -20, 25,
        0x003D7C0F,
        (u32) sPokemonNames[98],
    },
    {
        0x64, 0x00, 1840,
        sPokemonNames[99],
        (s32) sPokemonNames[99],
        0x3D, 0x05, 104,
        -70, 10,
        0x003C6400,
        (u32) sPokemonNames[99],
    },
    {
        0x65, 0x00, 800,
        sPokemonNames[100],
        (s32) sPokemonNames[100],
        0x33, 0x0C, 666,
        -70, 10,
        0x003C5000,
        (u32) sPokemonNames[100],
    },
    {
        0x66, 0x00, 1160,
        sPokemonNames[101],
        (s32) sPokemonNames[101],
        0x3D, 0x04, 25,
        -50, 40,
        0x003E4400,
        (u32) sPokemonNames[101],
    },
    {
        0x67, 0x00, 600,
        sPokemonNames[102],
        (s32) sPokemonNames[102],
        0x33, 0x14, 1200,
        -30, 40,
        0x003C2400,
        (u32) sPokemonNames[102],
    },
    {
        0x68, 0x00, 2500,
        sPokemonNames[103],
        (s32) sPokemonNames[103],
        0x3D, 0x04, 65,
        -25, 5,
        0x003C2800,
        (u32) sPokemonNames[103],
    },
    {
        0x69, 0x00, 1140,
        sPokemonNames[104],
        (s32) sPokemonNames[104],
        0x35, 0x0A, 450,
        -25, 5,
        0x003C4000,
        (u32) sPokemonNames[104],
    },
    {
        0x6A, 0x00, 723,
        sPokemonNames[105],
        (s32) sPokemonNames[105],
        0x35, 0x0F, 498,
        -20, 50,
        0x003C5FE2,
        (u32) sPokemonNames[105],
    },
    {
        0x6B, 0x0A, 870,
        sPokemonNames[106],
        (s32) sPokemonNames[106],
        0x35, 0x0E, 502,
        -20, 50,
        0x003BE800,
        (u32) sPokemonNames[106],
    },
    {
        0x6C, 0x1C, 767,
        sPokemonNames[107],
        (s32) sPokemonNames[107],
        0x35, 0x0C, 655,
        -50, 30,
        0x003C9C00,
        (u32) sPokemonNames[107],
    },
    {
        0x6D, 0x00, 1500,
        sPokemonNames[108],
        (s32) sPokemonNames[108],
        0x3D, 0x06, 10,
        -60, 90,
        0x003FDC00,
        (u32) sPokemonNames[108],
    },
    {
        0x6E, 0x00, 855,
        sPokemonNames[109],
        (s32) sPokemonNames[109],
        0x35, 0x0C, 95,
        -60, 90,
        0x003FB800,
        (u32) sPokemonNames[109],
    },
    {
        0x6F, 0x00, 860,
        sPokemonNames[110],
        (s32) sPokemonNames[110],
        0x35, 0x0A, 1150,
        -180, 180,
        0x003D87EC,
        (u32) sPokemonNames[110],
    },
    {
        0x70, 0x00, 523,
        sPokemonNames[111],
        (s32) sPokemonNames[111],
        0x35, 0x13, 1200,
        -180, 180,
        0x003C9832,
        (u32) sPokemonNames[111],
    },
    {
        0x71, 0x00, 850,
        sPokemonNames[112],
        (s32) sPokemonNames[112],
        0x33, 0x0B, 346,
        -50, 60,
        0x003C9C00,
        (u32) sPokemonNames[112],
    },
    {
        0x72, 0x00, 1000,
        sPokemonNames[113],
        (s32) sPokemonNames[113],
        0x35, 0x0A, 350,
        -40, 20,
        0x003C5400,
        (u32) sPokemonNames[113],
    },
    {
        0x73, 0x00, 479,
        sPokemonNames[114],
        (s32) sPokemonNames[114],
        0x33, 0x16, 800,
        -30, 50,
        0x003CB85A,
        (u32) sPokemonNames[114],
    },
    {
        0x74, 0x00, 2110,
        sPokemonNames[115],
        (s32) sPokemonNames[115],
        0x3D, 0x04, 80,
        -40, 40,
        0x003F2400,
        (u32) sPokemonNames[115],
    },
    {
        0x75, 0x00, 827,
        sPokemonNames[116],
        (s32) sPokemonNames[116],
        0x35, 0x0C, 250,
        -30, 35,
        0x003EBC00,
        (u32) sPokemonNames[116],
    },
    {
        0x76, 0x16, 2340,
        sPokemonNames[117],
        (s32) sPokemonNames[117],
        0x3D, 0x06, 150,
        -60, 40,
        0x00004CA0,
        (u32) sPokemonNames[117],
    },
    {
        0x77, 0x02, 1000,
        sPokemonNames[118],
        (s32) sPokemonNames[118],
        0x35, 0x0D, 390,
        -50, 30,
        0x0000DC32,
        (u32) sPokemonNames[118],
    },
    {
        0x78, 0x00, 1430,
        sPokemonNames[119],
        (s32) sPokemonNames[119],
        0x35, 0x08, 345,
        -10, 30,
        0x003BF000,
        (u32) sPokemonNames[119],
    },
    {
        0x79, 0x00, 1047,
        sPokemonNames[120],
        (s32) sPokemonNames[120],
        0x33, 0x0B, 800,
        -40, 50,
        0x003BB800,
        (u32) sPokemonNames[120],
    },
    {
        0x7A, 0x00, 895,
        sPokemonNames[121],
        (s32) sPokemonNames[121],
        0x35, 0x0D, 545,
        -30, 50,
        0x003BDFE2,
        (u32) sPokemonNames[121],
    },
    {
        0x7B, 0x00, 653,
        sPokemonNames[122],
        (s32) sPokemonNames[122],
        0x37, 0x0F, 560,
        -30, 50,
        0x003CE324,
        (u32) sPokemonNames[122],
    },
    {
        0x7C, 0x00, 691,
        sPokemonNames[123],
        (s32) sPokemonNames[123],
        0x33, 0x0E, 406,
        -10, 30,
        0x003C6800,
        (u32) sPokemonNames[123],
    },
    {
        0x7D, 0x17, 817,
        sPokemonNames[124],
        (s32) sPokemonNames[124],
        0x35, 0x0B, 300,
        -20, 30,
        0x003C5000,
        (u32) sPokemonNames[124],
    },
    {
        0x7E, 0x00, 700,
        sPokemonNames[125],
        (s32) sPokemonNames[125],
        0x35, 0x0D, 445,
        -15, 30,
        0x003BFC64,
        (u32) sPokemonNames[125],
    },
    {
        0x7F, 0x00, 703,
        sPokemonNames[126],
        (s32) sPokemonNames[126],
        0x37, 0x0F, 550,
        -60, 130,
        0x003BE400,
        (u32) sPokemonNames[126],
    },
    {
        0x80, 0x00, 670,
        sPokemonNames[127],
        (s32) sPokemonNames[127],
        0x33, 0x0E, 884,
        -10, 30,
        0x003CE000,
        (u32) sPokemonNames[127],
    },
    {
        0x81, 0x00, 1329,
        sPokemonNames[128],
        (s32) sPokemonNames[128],
        0x3D, 0x09, 100,
        -30, 25,
        0x003D2800,
        (u32) sPokemonNames[128],
    },
    {
        0x82, 0x00, 380,
        sPokemonNames[129],
        (s32) sPokemonNames[129],
        0x33, 0x41, 2350,
        -20, 50,
        0x0038B000,
        (u32) sPokemonNames[129],
    },
    {
        0x83, 0x00, 400,
        sPokemonNames[130],
        (s32) sPokemonNames[130],
        0x33, 0x19, 2200,
        -30, 20,
        0x003AB014,
        (u32) sPokemonNames[130],
    },
    {
        0x84, 0x00, 2200,
        sPokemonNames[131],
        (s32) sPokemonNames[131],
        0x3B, 0x03, 40,
        -60, 20,
        0x003D5800,
        (u32) sPokemonNames[131],
    },
    {
        0x85, 0x00, 2600,
        sPokemonNames[132],
        (s32) sPokemonNames[132],
        0x3D, 0x03, 65,
        -30, 30,
        0x003D8C00,
        (u32) sPokemonNames[132],
    },
    {
        0x86, 0x00, 980,
        sPokemonNames[133],
        (s32) sPokemonNames[133],
        0x33, 0x0A, 290,
        -20, 50,
        0xF8BCCF6A,
        (u32) sPokemonNames[133],
    },
    {
        0x87, 0x00, 1370,
        sPokemonNames[134],
        (s32) sPokemonNames[134],
        0x33, 0x08, 245,
        -25, 20,
        0x003C8FE2,
        (u32) sPokemonNames[134],
    },
    {
        0x88, 0x00, 1148,
        sPokemonNames[135],
        (s32) sPokemonNames[135],
        0x37, 0x09, 250,
        -20, 30,
        0x003C401E,
        (u32) sPokemonNames[135],
    },
    {
        0x89, 0x00, 960,
        sPokemonNames[136],
        (s32) sPokemonNames[136],
        0x35, 0x08, 365,
        -40, 40,
        0x00366000,
        (u32) sPokemonNames[136],
    },
    {
        0x8A, 0x00, 2240,
        sPokemonNames[137],
        (s32) sPokemonNames[137],
        0x3D, 0x04, 75,
        -15, 60,
        0x003D07AB,
        (u32) sPokemonNames[137],
    },
    {
        0x8B, 0x00, 909,
        sPokemonNames[138],
        (s32) sPokemonNames[138],
        0x35, 0x0A, 350,
        -15, 60,
        0x003CA7B5,
        (u32) sPokemonNames[138],
    },
    {
        0x8C, 0x00, 2000,
        sPokemonNames[139],
        (s32) sPokemonNames[139],
        0x3D, 0x05, 115,
        -20, 30,
        0x003D5800,
        (u32) sPokemonNames[139],
    },
    {
        0x8D, 0x00, 774,
        sPokemonNames[140],
        (s32) sPokemonNames[140],
        0x35, 0x0D, 405,
        -40, 50,
        0x003C8C00,
        (u32) sPokemonNames[140],
    },
    {
        0x8E, 0x22, 394,
        sPokemonNames[141],
        (s32) sPokemonNames[141],
        0x37, 0x12, 590,
        -60, 60,
        0x003E6800,
        (u32) sPokemonNames[141],
    },
    {
        0x8F, 0x00, 510,
        sPokemonNames[142],
        (s32) sPokemonNames[142],
        0x33, 0x15, 4600,
        -10, 60,
        0x003D5829,
        (u32) sPokemonNames[142],
    },
    {
        0x90, 0x00, 650,
        sPokemonNames[143],
        (s32) sPokemonNames[143],
        0x31, 0x11, 554,
        -20, 30,
        0x003BD400,
        (u32) sPokemonNames[143],
    },
    {
        0x91, 0x06, 600,
        sPokemonNames[144],
        (s32) sPokemonNames[144],
        0x31, 0x10, 526,
        -20, 25,
        0x00002800,
        (u32) sPokemonNames[144],
    },
    {
        0x92, 0x00, 600,
        sPokemonNames[145],
        (s32) sPokemonNames[145],
        0x35, 0x14, 600,
        -20, 20,
        0x003BAC00,
        (u32) sPokemonNames[145],
    },
    {
        0x93, 0x00, 1050,
        sPokemonNames[146],
        (s32) sPokemonNames[146],
        0x3D, 0x12, 33,
        -40, 20,
        0x1E3C7C00,
        (u32) sPokemonNames[146],
    },
    {
        0x94, 0x00, 570,
        sPokemonNames[147],
        (s32) sPokemonNames[147],
        0x35, 0x28, 165,
        -30, 10,
        0x21FC3BC4,
        (u32) sPokemonNames[147],
    },
    {
        0x95, 0x00, 473,
        sPokemonNames[148],
        (s32) sPokemonNames[148],
        0x31, 0x16, 2100,
        -20, 25,
        0x003C1FF6,
        (u32) sPokemonNames[148],
    },
    {
        0x96, 0x00, 540,
        sPokemonNames[149],
        (s32) sPokemonNames[149],
        0x20, 0x14, 1220,
        -70, 90,
        0x003C2400,
        (u32) sPokemonNames[149],
    },
    {
        0x97, 0x00, 2000,
        sPokemonNames[150],
        (s32) sPokemonNames[150],
        0x20, 0x04, 40,
        -40, 60,
        0x003F7400,
        (u32) sPokemonNames[150],
    },
    {
        0x98, 0x00, 1510,
        sPokemonNames[151],
        (s32) sPokemonNames[151],
        0x00, 0x0A, 50,
        -50, 50,
        0xFDBC3BD8,
        (u32) sPokemonNames[151],
    },
};

// Indexed by Status_ToDisplayIconIndex().
const char sStatusNames[7][4] = {"No", "Fa", "Sl", "Po", "Bu", "Fr", "Pa"};

// Indexed by PokemonType_ToDisplayIndex(); slot 6 is the unused Bird type.
const char sTypeNames[17][4] = {
    "No", "Fi", "Fl", "Po", "Gr", "Ro", "Fl", "Bu", "Gh", "Fi", "Wa", "Gr", "El", "Ps", "Ic", "Dr", "",
};

// One slot per Gen 1 move; the names never got localised.
const char sMoveNames[166][8] = {
    "skill", "skill", "skill", "skill", "skill", "skill", "skill", "skill",
    "skill", "skill", "skill", "skill", "skill", "skill", "skill", "skill",
    "skill", "skill", "skill", "skill", "skill", "skill", "skill", "skill",
    "skill", "skill", "skill", "skill", "skill", "skill", "skill", "skill",
    "skill", "skill", "skill", "skill", "skill", "skill", "skill", "skill",
    "skill", "skill", "skill", "skill", "skill", "skill", "skill", "skill",
    "skill", "skill", "skill", "skill", "skill", "skill", "skill", "skill",
    "skill", "skill", "skill", "skill", "skill", "skill", "skill", "skill",
    "skill", "skill", "skill", "skill", "skill", "skill", "skill", "skill",
    "skill", "skill", "skill", "skill", "skill", "skill", "skill", "skill",
    "skill", "skill", "skill", "skill", "skill", "skill", "skill", "skill",
    "skill", "skill", "skill", "skill", "skill", "skill", "skill", "skill",
    "skill", "skill", "skill", "skill", "skill", "skill", "skill", "skill",
    "skill", "skill", "skill", "skill", "skill", "skill", "skill", "skill",
    "skill", "skill", "skill", "skill", "skill", "skill", "skill", "skill",
    "skill", "skill", "skill", "skill", "skill", "skill", "skill", "skill",
    "skill", "skill", "skill", "skill", "skill", "skill", "skill", "skill",
    "skill", "skill", "skill", "skill", "skill", "skill", "skill", "skill",
    "skill", "skill", "skill", "skill", "skill", "skill", "skill", "skill",
    "skill", "skill", "skill", "skill", "skill", "skill", "skill", "skill",
    "skill", "skill", "skill", "skill", "skill", "",
};
#endif

// Item names. Dead data: nothing references these any more.
const char D_8007BB50[0x10] = "マスターボール";
const char D_8007BB60[0x10] = "ハイパーボール";
const char D_8007BB70[0x10] = "スーパーボール";
const char D_8007BB80[0x14] = "モンスターボール";
const char D_8007BB94[0x10] = "タウンマップ";
const char D_8007BBA4[0xC] = "じてんしゃ";
const char D_8007BBB0[0xC] = "？？？？？";
const char D_8007BBBC[0x10] = "サファリボール";
const char D_8007BBCC[0x10] = "ポケモンずかん";
const char D_8007BBDC[0xC] = "つきのいし";
const char D_8007BBE8[0xC] = "どくけし";
const char D_8007BBF4[0x10] = "やけどなおし";
const char D_8007BC04[0x10] = "こおりなおし";
const char D_8007BC14[0x10] = "ねむけざまし";
const char D_8007BC24[0xC] = "まひなおし";
const char D_8007BC30[0x14] = "かいふくのくすり";
const char D_8007BC44[0x14] = "まんたんのくすり";
const char D_8007BC58[0x14] = "すごいキズぐすり";
const char D_8007BC6C[0x10] = "いいキズぐすり";
const char D_8007BC7C[0xC] = "キズぐすり";
const char D_8007BC88[0x10] = "グレーバッジ";
const char D_8007BC98[0x10] = "ブルーバッジ";
const char D_8007BCA8[0x10] = "オレンジバッジ";
const char D_8007BCB8[0x14] = "レインボーバッジ";
const char D_8007BCCC[0x10] = "ピンクバッジ";
const char D_8007BCDC[0x10] = "ゴールドバッジ";
const char D_8007BCEC[0x14] = "クリムゾンバッジ";
const char D_8007BD00[0x10] = "グリーンバッジ";
const char D_8007BD10[0x10] = "あなぬけのヒモ";
const char D_8007BD20[0x14] = "むしよけスプレー";
const char D_8007BD34[0x10] = "ひみつのコハク";
const char D_8007BD44[0x10] = "ほのおのいし";
const char D_8007BD54[0x10] = "かみなりのいし";
const char D_8007BD64[0xC] = "みずのいし";
const char D_8007BD70[0x10] = "マックスアップ";
const char D_8007BD80[0xC] = "タウリン";
const char D_8007BD8C[0x10] = "ブロムヘキシン";
const char D_8007BD9C[0x10] = "インドメタシン";
const char D_8007BDAC[0xC] = "リゾチウム";
const char D_8007BDB8[0x10] = "ふしぎなアメ";
const char D_8007BDC8[0x10] = "こうらのカセキ";
const char D_8007BDD8[0x10] = "かいのカセキ";
const char D_8007BDE8[0x10] = "ひみつのカギ";
const char D_8007BDF8[0xC] = "？？？？？";
const char D_8007BE04[0x10] = "ひきかえけん";
const char D_8007BE14[0x10] = "ヨクアタール";
const char D_8007BE24[0x10] = "リーフのいし";
const char D_8007BE34[0xC] = "カードキー";
const char D_8007BE40[0xC] = "きんのたま";
const char D_8007BE4C[0x10] = "ポイントアップ";
const char D_8007BE5C[0x14] = "ピッピにんぎょう";
const char D_8007BE70[0x10] = "なんでもなおし";
const char D_8007BE80[0x10] = "げんきのかけら";
const char D_8007BE90[0x14] = "げんきのかたまり";
const char D_8007BEA4[0x14] = "エフェクトガード";
const char D_8007BEB8[0x14] = "シルバースプレー";
const char D_8007BECC[0x14] = "ゴールドスプレー";
const char D_8007BEE0[0x14] = "クリティカッター";
const char D_8007BEF4[0x8] = "コイン";
const char D_8007BEFC[0x10] = "おいしいみず";
const char D_8007BF0C[0x10] = "サイコソーダ";
const char D_8007BF1C[0x10] = "ミックスオレ";
const char D_8007BF2C[0x10] = "ふねのチケット";
const char D_8007BF3C[0x10] = "きんのいれば";
const char D_8007BF4C[0x10] = "プラスパワー";
const char D_8007BF5C[0x10] = "ディフェンダー";
const char D_8007BF6C[0xC] = "スピーダー";
const char D_8007BF78[0x14] = "スペシャルアップ";
const char D_8007BF8C[0x10] = "コインケース";
const char D_8007BF9C[0x10] = "おとどけもの";
const char D_8007BFAC[0x14] = "ダウジングマシン";
const char D_8007BFC0[0x10] = "シルフスコープ";
const char D_8007BFD0[0x10] = "ポケモンのふえ";
const char D_8007BFE0[0x14] = "エレベータのカギ";
const char D_8007BFF4[0x14] = "がくしゅうそうち";
const char D_8007C008[0x10] = "ボロのつりざお";
const char D_8007C018[0x10] = "いいつりざお";
const char D_8007C028[0x10] = "すごいつりざお";
const char D_8007C038[0x10] = "ポイントアップ";
const char D_8007C048[0x10] = "ピーピーエイド";
const char D_8007C058[0x14] = "ピーピーリカバー";
const char D_8007C06C[0x14] = "ピーピーエイダー";
const char D_8007C080[0x14] = "ピーピーマックス";
const char D_8007C094[0x4] = "";
const char D_8007C098[0x4] = "";
const char D_8007C09C[0x4] = "";

u32 Status_ToDisplayIconIndex(s32 arg0) {
    s32 ret;

    if (arg0 & 7) {
        ret = 2;
    } else if (arg0 & 8) {
        ret = 3;
    } else if (arg0 & 0x10) {
        ret = 4;
    } else if (arg0 & 0x20) {
        ret = 5;
    } else if (arg0 & 0x40) {
        ret = 6;
    } else {
        ret = 0;
    }

    return ret;
}

u32 PokemonType_ToDisplayIndex(s32 arg0) {
    if (arg0 >= 0x1B) {
        arg0 = 0;
    } else if (arg0 >= 0x14) {
        arg0 -= 0xB;
    }
    return arg0;
}
