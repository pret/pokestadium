# Pokemon Stadium (US)
A WIP decomp of Pokemon Stadium (US).

It builds the following ROMs:

* US 1.0 (`VERSION=us`, default): `build/pokestadium-us.z64`, `md5: ed1378bc12115f71209a77844965ba50`
* US Rev. 1 / 1.1 (`VERSION=us_rev1`): `build/us_rev1/pokestadium-us_rev1.z64`, `md5: 40e03eda831c01e0a12294287fd240e2`

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

## US Rev. 1

Place your big-endian US Rev. 1 ROM in `baseroms/us_rev1/baserom.z64`.
Its SHA-1 must be `488bb6d112427823d77fcecdd9297fd86875263d`.
After installing the prerequisites above, initialize and build this target with:

```powershell
make init VERSION=us_rev1
make VERSION=us_rev1
```

If the tools and Python environment are already set up, use:

```powershell
make extract VERSION=us_rev1
make VERSION=us_rev1
```

Source is shared between the two targets. Assembly fallbacks and packed assets
are extracted from each target's own ROM, and Rev. 1 objects use a separate
build directory. Run `make extract VERSION=us` before building US 1.0 if its
assets have not yet been extracted. `make init`/`make distclean` remove shared
extraction directories; `make clean` for the default target removes the entire
`build` directory, including the nested Rev. 1 build.

Rev. 1 currently keeps its changed GB Tower function `func_8120572C` in
extracted assembly rather than matching C. This is revision support, not a
claim that the revised function has been decompiled. Both targets retain their
normal full-ROM checksum verification. ROMs are not distributed by this repo.

For contacts and other pret projects, see [pret.github.io](https://pret.github.io/).
