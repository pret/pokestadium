# Public Pokemon Stadium GS ROM-gate baseline.
#
# This image is staged locally on the isolated Mac runner from a persistent,
# incrementally-maintained host checkout (see ci/build-baseline.sh) rather
# than compiled inside this Dockerfile. A `COPY . /work` followed by a full
# `make extract && make rom` inside Docker busts its own build cache on
# every single change anywhere in the repo (including to this Dockerfile),
# so every rebuild -- even one triggered by an unrelated one-line source
# change -- paid the full ~20-30 minute bake from scratch. Building natively
# on the host instead lets Make's own incremental dependency tracking do its
# job: a small change rebuilds in a couple of minutes, not from zero.
#
# The US baserom is supplied outside Git and is never published. The image
# contains only the build toolchain and generated baseline build state; it
# is not the workflow's authority to merge code.

FROM debian:bookworm-slim

ENV DEBIAN_FRONTEND=noninteractive \
    MIPS_BINUTILS_PREFIX=mips-linux-gnu- \
    DETECTED_OS=linux \
    PYTHON=/work/.venv/bin/python3

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        bash \
        build-essential \
        binutils-mips-linux-gnu \
        ca-certificates \
        gcc-multilib \
        git \
        make \
        python3 \
        python3-pip \
        python3-venv \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /work

# Git-tracked inputs, copied as their own layer so an unrelated change to
# generated/derived state (below) never busts this one, and vice versa.
COPY src ./src
COPY include ./include
# Tracked text edits; every version's textdata.o recipe depends on them.
COPY text ./text

# Makefile's C_FILES list is `git ls-files -- src`, so /work needs an
# actual git repository over src/ -- otherwise that command fails with
# "fatal: not a git repository", C_FILES silently comes back empty, and
# a full rebuild (rm -rf build, forced by any yamls/ change) compiles
# nothing, leaving the link step unable to find any src/*.o it needs.
# This was invisible until a PR that touched yamls/ actually forced a
# full rebuild: PR #46, 2026-09-17. ci/gate-pr.sh keeps this index in
# sync with whatever a PR overlays onto src/include afterward.
RUN git init -q \
    && git add src include \
    && git -c user.name="pokestadium-decomp-agent image" -c user.email="pokestadium-decomp-agent@localhost" \
        commit -q -m "baseline: src and include as shipped in the image"

COPY tools ./tools
COPY linker_scripts ./linker_scripts
COPY lib ./lib
COPY yamls ./yamls
COPY Makefile requirements.txt ./

# The exact pinned Python dependencies and repository tools. Built inside
# the image (not staged from the host) since a host-native venv's paths
# aren't portable into a container.
RUN make venv \
    && make setup

# Pre-built derived state from the host checkout's own incremental build --
# see ci/build-baseline.sh. Staged as separate layers, each cheap to
# invalidate on its own: a yaml-only change still busts asm/ (splat's
# output depends on it) but never touches the already-built lib/ultralib
# object archive, for example.
COPY prebuilt/asm ./asm
COPY prebuilt/assets ./assets
COPY prebuilt/lib-ultralib-build ./lib/ultralib/build
COPY prebuilt/build ./build
COPY baseroms ./baseroms

# The public repository is a partial decompilation, so it cannot be
# required to link before the gate has had a chance to validate the
# PR-controlled source; ci/gate-pr.sh always overlays the checkout and
# forces the real compile/link/checksum gate. Swap the final ROM for the
# raw retail dump so timestamp-based make decisions in that later gate can
# never mistake this baked seed for an already-verified build of the
# checked-out PR source -- it must always recompile for real. The ROM is
# supplied outside Git and is removed from the isolated checkout by
# ci/build-baseline.sh after the build.
RUN mkdir -p build \
    && cp baseroms/us/baserom.z64 build/pokestadium-us.z64 \
    && md5sum build/pokestadium-us.z64 baseroms/us/baserom.z64
