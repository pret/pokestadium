# Code of Conduct

Don't act a fool.

Never delete `oldnotes`. It stands as a testament to manual decomping that this project stands on.

# Editor setup and cross-file renaming

For VS Code, install the recommended **clangd** extension and run:

```sh
python3 tools/clangd_config.py
```

Then restart the clangd language server and let background indexing finish before
using F2 on shared symbols. The workspace task can keep the database current
automatically, including source-file additions and moves; ordinary identifier
renames do not require regenerating it. No ROM, IDO compiler, or custom VS Code
extension is needed for this editor setup.

See [docs/clangd.md](docs/clangd.md) for automatic-task permissions, regional
analysis views, verification, and the limits of C-aware rename.

# Team Hippodrome Decomp Style Guide

## Formatting
IDO is NOT whitespace neutral: white space materially impacts matching code. Therefore: you should assume any changes to the spacing of the code can cause a matching function to not match.

## Naming
### N64 Type Aliases
|Type|Alias|
|---|---|
|`unsigned char`|`u8`|
|`signed char`|`s8`|
|`short unsigned int`|`u16`|
|`short signed int`|`s16`|
|`long unsigned int`|`u32`|
|`long signed int`|`s32`|
|`long long unsigned int`|`u64`|
|`long long signed int`|`s64`|
|`float`|`f32`|
|`double`|`f64`|

### Cases

|Object|Style|Examples|
|---|---|---|
|Global-to-Game "Global" Variables|`gCamelCase`|`gPlayer1Controller`, `gSessionContext`,`gDisplayListHead`|
|Global-to-Fragment "Global" Variables|`sCamelCase` |`sCasteMapNodes`, `sSide2HpBar`,`sRuleDescWindow`|
|Local Function Variables (including arguments)|`snake_case`|`selected_menu_item`,`cpu_pokemon`,`type_effectiveness`|
|Functions|`{Domain}_{Purpose}`|`RentalHub_MenuLoop`,`Title_FadeOut`,`GraphNode_AppendChild`|
|Macro Variables|`CAPITAL_CASE`|`PIKACHU_SPECIES`, `CONFIRM_SFX`, `GIOVANNI`|
|External Library Functions (e.g. libultra)|Leave as is|`gSPDisplayList`,`gSPSprite2DBase`
|Structs|`TitleCase`|`QualifyingPokemonDisplay`,`HallOfFameSlot`,`GymLeader`|

### Naming Known Tokens
As the goal of a decomp is to be readable to a wide variety of people (recomp devs, romhackers, speedrunners, video essayists, AI assistants helping a confused player) our decomp repos tolerate more specific naming than most modern "good practice". Function names can go up to 50 characters, so names like `RentalRules_QualifyingSpeciesWindowDraw` are acceptable. 

### Naming Unknown Tokens
|Object|Style|Examples|
|---|---|---|
|Global Variables|`D_{Address}`|`D_8421187C`|
|Functions|`func_{address}` |`func_8420DBA0`|
|Structs|`unk_func_{address of func}` or `unk_D_{address of variable}`|`unk_func_80031270`,`unk_D_84102450`|
|Struct attributes|`unk_{offset}`|`unk_0A`,`unk_C0`|
|Function Arguments|`arg{index}`|`arg0`,`arg4`|
|Local variables|`var_{register}`|`var_v0`,`var_s1`|

### Spelling
Use American English (color, mom, etc.) for all spelling.

### Terminology
#### Technical 
Do not use yaw, pitch, and roll to describe rotations about an axis since those terms are body-relative, while most rotations in Pokemon Stadium are world-relative. use rotationX, rotationY, and rotationZ.

Prefer technically correct obscure language over ambiguous common language. For example: `alpha` instead of `fadeLevel`.

Do not include non-alphanumeric or non-ASCII symbols in variable names even if lore accurate (Nidoran♂ should be `NIDORAN_MALE`)

Consequently: Do not include é in Pokémon for variable names as IDO does not accept non-ASCII characters in indentifiers. The é is optional for documentation and comments.

#### Mechanics
The format stadium uses is commonly called "bring 6, pick 3." To disambiguate between Pokemon in the party and Pokemon chosen to for a particular battle, we say "brought Pokemon" and "picked Pokemon".

As AI is now a term to refer to a technology, use the term "COM" to refer to the non-player trainers since that is the label in Free Battle. Battle AI procedures may still be called `BattleAi` as a function domain.

#### Game

Use English names for Pokemon and Characters.

Never use the name Poke cup, all versions of the game still contain duplicate internal strings for Poke Cup as in the Japanese Version, Poke cup was five different versions called Nintendo Cup.

The adopted term term for the creature in Kanghakhan's pouch is Kangaskid

##### Area Names 

Because the areas in Stadium are rather poorly named (and even have contradictory names between the game's dialogue and their label) this repo uses the more common names regardless of what the selection label is:

|Area Label|Repo/Common Name|
|---|---|
|Victory Palace|Hall of Fame|
|Pokemon Lab|Professor Oak's Lab|
|Kid's Club|Minigames|


#### Sensitive Language
Using the term "blackface" and "purpleface" to describe Jynx's coloration in the Jp and US 1.0 versions is discouraged. Use the term "original color" and "purple color"/"new color". 

Nidoqueen's animation did change between JP and US 1.0 so potentially we do in fact have to refer to Nidoqueen's breasts to document this change. Use the word breasts, not slang terms like boobs and not whatever the technical animal husbandry name for the breasts of whatever animal Nidoqueen is supposed to be is.

That said: out of code use of these sensitives terms is none of our business.

## Comments 
### Fakes: Decomp Slop and Karodo 
"Fakes" refer to a variety of coding anti-patterns that enable a function match through register coloring, but serve no other purpose. There are two types of fakes:
- **Decomp Slop:** are fakes that no programmer would ever write, such as 
	- Type casting doom loops: `*((void **) (((u8 *) (*((void **) (((u8 *) arg0) + 0)))) + 4))`
	- Arithmetic nops: `arg0 + 1 - 1`, `var++; var--;` 
- **Karodo** (from 過労 + code, "overworked code") are debugging idioms that were left in the ROM but have since had their debugging functionality omitted:
	- Empty if statements `if (1) {}`
	- Empty enumeration: `for (i=0; i < n; i++) {}`
	- Empty pause: `while (0) {}`

It is our philosophy that even the worst, most disgusting match is better than the most beautiful non-match: thus, it is not legitimate to reject a new match simply because it contains fakes.

That being said, fakes should always be marked as with a `// FAKE` comment when used or encountered so other maintainers can attempt to create matches that does. If you encounter fakes while annotating, please mark them as such even if the original committer didn't (we all sometimes don't fully read the agent's output).

Karodo is acceptable to leave in with a `// karodo` comment if there appears to be no other way to get rid of it. Decomp slop should never have its `// FAKE` label changed. Never launder decomp slop as karodo.

### Bugs
Bugs left in the original game code should be label `//!bug`

### Cross References
Reference other files with `//@{path}`

## Numbers
Use Hex only for:
- One off Powers of 2
- One off (power of 2 - 1) (`0xFF` and such)
- Colors
- Addresses
- Masks

Otherwise, keep numbers in decimal.
