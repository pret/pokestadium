# AI Disclaimer
This project is was a collaborative effort by humans that used AI. AI was used for for *matching* functions and *annotating widely used structs and globals* where abundant evidence greatly reduced hallucination risk.

The original pret contributors (the first four years of contributions) did not use AI to our knowledge. Pret has no official relationship with us (Team Hippodrome) other sharing some members.

# Pokemon Stadium (US)
A WIP decomp of Pokemon Stadium (US).

It builds the following ROMs:

* US 1.0 (`VERSION=us`, default): `build/pokestadium-us.z64`, `md5: ed1378bc12115f71209a77844965ba50`

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
1. Place the US Pokemon Stadium 1.0 rom into the repository's "/baseroms/us/" folder as "baserom.z64".
2. Set up tools and extract the rom: `make init`
3. Re-assemble the rom: `make`

For contacts and other pret projects, see [pret.github.io](https://pret.github.io/).

Last mile decomp and annotation work done by [Team Hippodrome](https://discord.gg/8EvuQxbxu8).

Part of the [R.A.I.D. (Retro AI Development)](https://discord.gg/eCvnsvrjnY) community. 
