# Static Recompilation of IRIX Programs

Convert selected IRIX C toolchain programs into modern Linux or macOS programs

## Supported Programs

* IDO 5.3
  * cc, acpp, as0, as1, cfe, copt, ugen, ujoin, uld, umerge, uopt, usplit, ld, strip, upas
* IDO 7.1
  * cc, acpp, as0, as1, cfe, ugen, ujoin, uld, umerge, uopt, usplit, upas

## Dependencies

### Linux (Debian / Ubuntu)

```bash
sudo apt-get install build-essential
```

### macOS

[Install homebrew](https://brew.sh/) and then:

```bash
brew install make
```

## Building

First build the recomp binary itself

```bash
make setup
```

```bash
make VERSION=5.3
make VERSION=7.1
```

The build artifacts are located in `build/{7.1|5.3}/out`. Add `-j{thread num}` for multithreaded building.

By default, debug builds are created with less optimizations, debug flags, and unstripped binaries.
Add `RELEASE=1` to build release builds with optimizations and stripped binaries.

### Creating Universal ARM/x86_64 macOS Builds

By default, make build script create native binaries on macOS. This was done to minimize the time to build the recompiled suite.
In order to create "fat," universal ARM and x86_64, pass `TARGET=universal` to `gmake`.
