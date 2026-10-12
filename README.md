# AI Disclaimer
This project is was a collaborative effort by humans that used AI. AI was used for for *matching* functions and *annotating widely used structs and globals* where abundant evidence greatly reduced hallucination risk.

The original pret contributors (the first four years of contributions) did not use AI to our knowledge. Pret has no official relationship with us (Team Hippodrome) other sharing some members.

# Pokemon Stadium (US)
A WIP decomp of Pokemon Stadium (US).

It builds the following ROMs:

* US 1.0 (`VERSION=us`, default): `build/pokestadium-us.z64`, `md5: ed1378bc12115f71209a77844965ba50`
* US Rev. 1 / 1.1 (`VERSION=us_rev1`): `build/us_rev1/pokestadium-us_rev1.z64`, `md5: 40e03eda831c01e0a12294287fd240e2`
* US Rev. 2 / 1.2 (`VERSION=us_rev2`): `build/us_rev2/pokestadium-us_rev2.z64`, `md5: 6dc6820cef755fc1253d06df45c9bd2a`

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
2. Set up tools and extract the rom: `make init`
3. Re-assemble the rom: `make`

For US Rev. 2, place your ROM at `baseroms/us_rev2/baserom.z64`, then run
`make extract VERSION=us_rev2` and `make VERSION=us_rev2` after setting up the
tools and Python environment. Re-run extraction for each older target after
updating the shared sources, because new assembly fallbacks need their `.s` files.

For contacts and other pret projects, see [pret.github.io](https://pret.github.io/).

Last mile decomp and annotation work done by [Team Hippodrome](https://discord.gg/8EvuQxbxu8).

Part of the [R.A.I.D. (Retro AI Development)](https://discord.gg/eCvnsvrjnY) community. 
