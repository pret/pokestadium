#!/usr/bin/env bash
# Build the local public baseline image.
#
# Unlike a plain `docker build`, this stages a persistent, incrementally
# maintained host checkout's own build (asm/, assets/, lib/ultralib/build/,
# build/) into the image instead of compiling inside Docker. A `COPY . /work`
# followed by `make extract && make rom` inside the Dockerfile busts its own
# build cache on every single repo change -- including to the Dockerfile
# itself -- so every previous rebuild paid the full ~20-30 minute bake from
# scratch regardless of how small the actual change was. Make's own
# incremental dependency tracking on a real, persistent checkout does not
# have that problem: a small change (the common case -- a yaml-touching PR
# merging) rebuilds in a couple of minutes, because only what actually
# changed gets recompiled.
#
# Usage:
#   POKESTADIUM_BASEROM=/private/path/baserom.z64 ci/build-baseline.sh
#
# Environment:
#   POKESTADIUM_CI_CHECKOUT   the persistent, incrementally-built host
#                               checkout (default: a fixed path next to this
#                               repo's own sibling checkouts -- see below).
#                               Created and `make setup`/`make venv`'d once
#                               if it doesn't exist yet; never destroyed.
#   POKESTADIUM_BASEROM       a legally-obtained retail ROM dump, used when
#                               the local baseline image cannot seed the
#                               first-time persistent checkout.
#   POKESTADIUM_DECOMP_AGENT_IMAGE       image tag to build (default:
#                               pokestadium-decomp-agent:latest).

set -euo pipefail

repo_root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
ci_checkout="${POKESTADIUM_CI_CHECKOUT:-$HOME/projects/pokestadium-ci-baseline}"
target_sha="$(git -C "$repo_root" rev-parse HEAD)"
image="${POKESTADIUM_DECOMP_AGENT_IMAGE:-pokestadium-decomp-agent:latest}"

echo "build-baseline.sh: target commit $target_sha" >&2
echo "build-baseline.sh: persistent checkout at $ci_checkout" >&2

# Create the persistent checkout once. This never happens in normal
# operation on a runner that already has it -- only on a fresh runner, or
# after a deliberate `rm -rf` recovery.
if [ ! -d "$ci_checkout/.git" ]; then
    echo "build-baseline.sh: persistent checkout does not exist yet, cloning" >&2
    mkdir -p "$(dirname "$ci_checkout")"
    git clone --quiet "$(git -C "$repo_root" remote get-url origin)" "$ci_checkout"
fi

baserom="$ci_checkout/baseroms/us/baserom.z64"
if [ ! -f "$baserom" ]; then
    source_baserom="${POKESTADIUM_BASEROM:-}"
    if [ -n "$source_baserom" ] && [ -f "$source_baserom" ]; then
        echo "build-baseline.sh: seeding the private baseline checkout from POKESTADIUM_BASEROM" >&2
        mkdir -p "$(dirname "$baserom")"
        cp "$source_baserom" "$baserom"
    elif docker image inspect "$image" >/dev/null 2>&1; then
        echo "build-baseline.sh: seeding the private baseline checkout from the existing local image" >&2
        mkdir -p "$(dirname "$baserom")"
        seed_container="$(docker create --platform linux/amd64 "$image")"
        if ! docker cp "$seed_container:/work/baseroms/us/baserom.z64" "$baserom"; then
            docker rm "$seed_container" >/dev/null
            echo "build-baseline.sh: local image does not contain /work/baseroms/us/baserom.z64" >&2
            exit 1
        fi
        docker rm "$seed_container" >/dev/null
    else
        echo "build-baseline.sh: first-time setup needs POKESTADIUM_BASEROM or an existing $image containing the private retail ROM" >&2
        exit 1
    fi
fi

if [ ! -f "$ci_checkout/.build-baseline-setup" ]; then
    echo "build-baseline.sh: initializing the persistent toolchain" >&2
    ( cd "$ci_checkout" && make venv && make setup )
    touch "$ci_checkout/.build-baseline-setup"
fi

# Sync the persistent checkout to the exact commit being built. A plain
# `git pull` would merge; this checkout only ever mirrors upstream, so hard
# reset to whatever ref triggered this build.
git -C "$ci_checkout" fetch --quiet origin "$target_sha"
# --force: this checkout only mirrors upstream, but a build run in it leaves
# tracked generated files modified, and a plain checkout then aborts with
# "local changes would be overwritten" and leaves the image stale.
git -C "$ci_checkout" checkout --quiet --force --detach "$target_sha"

# Re-extract only when yamls/ actually changed since the last extraction --
# splat's output depends on it, nothing else does. A plain `git diff
# --quiet` against the previous commit is not available here (this
# checkout may have jumped several commits, or none, since its last
# build), so compare a content hash of yamls/ against a marker this script
# itself writes after a successful extraction.
yamls_hash="$(cd "$ci_checkout" && find yamls -type f -print0 | sort -z | xargs -0 shasum -a 256 | shasum -a 256 | cut -d' ' -f1)"
marker="$ci_checkout/asm/.build-baseline-yamls-hash"
if [ ! -d "$ci_checkout/asm" ] || [ ! -f "$marker" ] || [ "$(cat "$marker" 2>/dev/null)" != "$yamls_hash" ]; then
    echo "build-baseline.sh: yamls/ changed (or first build) -- re-extracting" >&2
    ( cd "$ci_checkout" && make extract )
    mkdir -p "$ci_checkout/asm"
    echo "$yamls_hash" > "$marker"
else
    echo "build-baseline.sh: yamls/ unchanged since the last extraction, reusing asm/assets" >&2
fi

# Incremental, not forced: only what actually changed (relative to this
# same persistent checkout's own last build) gets recompiled. The baseline
# checkout is built on the ARM64 macOS runner, where Apple Clang cannot model
# the MIPS 32-bit pointer width used by the repository's optional host syntax
# checker (-m32 is not a usable target there). The PR gate still performs its
# authoritative host checks inside the Linux container; this host build only
# needs to produce the MIPS objects/map that are staged into the image.
build_jobs="$(sysctl -n hw.ncpu 2>/dev/null || nproc)"
( cd "$ci_checkout" && make RUN_CC_CHECK=0 COMPARE=0 -j"$build_jobs" rom )

# The staged objects, map and libultra archive are only useful to the PR gate
# if relinking them actually reproduces retail. COMPARE=0 above keeps make from
# treating a mismatch as a build failure, so verify it here instead -- without
# this check a persistent checkout that has quietly accumulated a bad
# incremental artifact bakes straight into the image, and then every PR that
# touches only src/*.c fails the gate on the incremental relink path while a
# forced full rebuild of the very same tree still passes. (That is exactly how
# a parallel-build race that left build/lib/libultra.a missing one freshly
# compiled member -- vimodefpallpn1.o, 0x50 bytes of .data -- went unnoticed:
# the image also ships a retail seed ROM at build/pokestadium-us.z64, so the
# baked tree looks healthy until something forces a relink.)
verify_baseline_rom() {
    ( cd "$ci_checkout" \
        && tr -d '\r' < baseroms/us/checksum.md5 | md5sum -c - >/dev/null 2>&1 )
}

if ! verify_baseline_rom; then
    echo "build-baseline.sh: baseline ROM does not match retail; the persistent" >&2
    echo "build-baseline.sh: checkout has a stale incremental artifact. Rebuilding" >&2
    echo "build-baseline.sh: libultra and relinking before staging." >&2
    ( cd "$ci_checkout" && make libclean )
    ( cd "$ci_checkout" && make RUN_CC_CHECK=0 COMPARE=0 -j"$build_jobs" rom )
    if ! verify_baseline_rom; then
        echo "build-baseline.sh: baseline ROM still does not match retail after a" >&2
        echo "build-baseline.sh: libultra rebuild. Refusing to bake a baseline image" >&2
        echo "build-baseline.sh: the PR gate cannot trust. Investigate, or recover" >&2
        echo "build-baseline.sh: with: make -C $ci_checkout clean libclean" >&2
        exit 1
    fi
fi
echo "build-baseline.sh: baseline ROM matches retail" >&2

# --- Stage a throwaway Docker build context from the persistent checkout ---
staging_dir="$(mktemp -d "${TMPDIR:-/tmp}/pokestadium-baseline-build.XXXXXX")"
cleanup() { rm -rf "$staging_dir"; }
trap cleanup EXIT

for path in src include text tools linker_scripts lib yamls Makefile requirements.txt ci; do
    cp -a "$ci_checkout/$path" "$staging_dir/$path"
done

# Leave out anything git does not track under tools/ (local venvs, checkouts,
# scratch scripts the persistent checkout accumulated). gate-pr.sh syncs tools/
# from the PR checkout, sees those as "only in the image", deletes them, and
# treats that as a tools change, which forces a full rebuild on every run.
( cd "$ci_checkout" && git ls-files --others --directory -z -- tools ) \
    | while IFS= read -r -d '' extra; do
        case "$extra" in */__pycache__/|tools/vtxdis) continue ;; esac
        rm -rf "$staging_dir/${extra%/}"
    done
mkdir -p "$staging_dir/prebuilt"
cp -a "$ci_checkout/asm" "$staging_dir/prebuilt/asm"
cp -a "$ci_checkout/assets" "$staging_dir/prebuilt/assets"
cp -a "$ci_checkout/lib/ultralib/build" "$staging_dir/prebuilt/lib-ultralib-build"
cp -a "$ci_checkout/build" "$staging_dir/prebuilt/build"

baserom="$staging_dir/baseroms/us/baserom.z64"
mkdir -p "$(dirname "$baserom")"
cp "$ci_checkout/baseroms/us/baserom.z64" "$baserom"
cp "$ci_checkout/baseroms/us/checksum.md5" "$staging_dir/baseroms/us/checksum.md5"

docker build \
    --platform linux/amd64 \
    --tag "$image" \
    --file "$staging_dir/ci/Dockerfile" \
    "$staging_dir"

echo "build-baseline.sh: built $image from $target_sha (persistent checkout at $ci_checkout)"

# Per-version baselines for the gate (see ci/build-region-baselines.sh). Only
# when the runner has the retail dumps and a cache directory configured; a
# failure here leaves the image usable (the gate falls back to cold builds).
# POKESTADIUM_REGION_BASELINES limits it to the listed versions (default: all).
if [ -n "${POKESTADIUM_BASEROM_DIR:-}" ] && [ -n "${POKESTADIUM_REGION_CACHE_DIR:-}" ]; then
    echo "build-baseline.sh: building the per-version baselines into $POKESTADIUM_REGION_CACHE_DIR" >&2
    bash "$ci_checkout/ci/build-region-baselines.sh" "$image" "$POKESTADIUM_BASEROM_DIR" \
        "$POKESTADIUM_REGION_CACHE_DIR" "$ci_checkout/baseroms" ${POKESTADIUM_REGION_BASELINES:-} \
        || echo "build-baseline.sh: some per-version baselines failed; the gate builds those cold" >&2
fi
