# AI Disclaimer
This project is was a collaborative effort by humans that used AI. AI was used for for *matching* functions and *annotating* where abundant evidence greatly reduced hallucination risk (either through prior human instruction, texture/string evidence, or abundant examples in the code base).

The original pret contributors (the first four years of contributions) did not use AI to our knowledge. Pret has no official relationship with us (Team Hippodrome) other sharing some members.

# Pokemon Stadium (US)
A WIP decomp of Pokemon Stadium (US).

It builds the following ROMs:

* US 1.0 (`VERSION=us`, default): `build/pokestadium-us.z64`, `md5: ed1378bc12115f71209a77844965ba50`
* US Rev. 1 / 1.1 (`VERSION=us_rev1`): `build/us_rev1/pokestadium-us_rev1.z64`, `md5: 40e03eda831c01e0a12294287fd240e2`
* US Rev. 2 / 1.2 (`VERSION=us_rev2`): `build/us_rev2/pokestadium-us_rev2.z64`, `md5: 6dc6820cef755fc1253d06df45c9bd2a`
* Japan, ポケモンスタジアム２ / Pocket Monsters Stadium 2 (`VERSION=jp`, `CP2J`): `build/jp/pokestadium-jp.z64`, `md5: 2449bb712a64e3363a6cbd56f5adeda5`
* Europe (`VERSION=eu`, `NPOP`): `build/eu/pokestadium-eu.z64`, `md5: 2859090d78581e0925a3af8045e81e4b`
* Europe Rev. 1 (`VERSION=eu_rev1`, `NPOP` rev 1): `build/eu_rev1/pokestadium-eu_rev1.z64`, `md5: 31ee2de8e65e30f5934c450dbaa924f0`
* France (`VERSION=fr`, `NPOF`): `build/fr/pokestadium-fr.z64`, `md5: 0e85a098d0f0e8a7eb572a69612a6873`
* Germany (`VERSION=de`, `NPOD`): `build/de/pokestadium-de.z64`, `md5: 24be2ccb0dea0755908c02bf67e22fe5`
* Spain (`VERSION=es`, `NPOS`): `build/es/pokestadium-es.z64`, `md5: d14a499bc4e324974eae3e42dec58625`
* Italy (`VERSION=it`, `NPOI`): `build/it/pokestadium-it.z64`, `md5: a81321759af38beb30a40fdaca2ea22a`

Note: To use this repository, you must already have a rom for the game.

# Prerequisites

Under Debian / Ubuntu (which we recommend using), you can install them with the following commands:

```bash
sudo apt update
sudo apt install make git build-essential binutils-mips-linux-gnu python3 python3-pip python3-venv
```

**Please also ensure that the Python version installed is >3.7.**

The build process has a few python packages required that are located in `requirements.txt`.

To install them simply run in a terminal:

```bash
python3 -m pip install -r requirements.txt
```

# To use
1. Place the supported Pokemon Stadium rom into the repository's "/baseroms/" folder as "baserom.z64", using the correct subfolder for your version.
2. Set up tools and extract the rom: `make init VERSION={version}`
3. Re-assemble the rom: `make VERSION={version}`

For Japanese and European versions: regenerate the config of those versions with `make VERSION=us` followed by `tools/port_version.py {version} --asm-changed`.
`make extract VERSION={Version}` reports errors for US-only unpacked asset views; the build
does not use them.

For contacts and other pret projects, see [pret.github.io](https://pret.github.io/).

Last mile decomp and annotation work done by [Team Hippodrome](https://discord.gg/8EvuQxbxu8).

Part of the [R.A.I.D. (Retro AI Development)](https://discord.gg/eCvnsvrjnY) community. 
