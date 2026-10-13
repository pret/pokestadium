#!/usr/bin/env bash
# Run the public PR ROM gate against a checkout directory.
#
# The caller supplies a checkout that may contain PR-controlled files. The
# checkout is mounted read-only into a disposable container. The host-side
# script is deliberately small and the container has no Docker socket,
# secrets, or network access.
#
# Regions: GATE_REGIONS (space separated, default "us") picks the ROM versions
# to build and compare. "us" is built incrementally from the baked baseline;
# every other version is extracted and built cold in the container from the
# retail dump found in POKESTADIUM_BASEROM_DIR/<version>/baserom.z64 on the
# runner (mounted read-only; never in the repo or the image). A version whose
# dump is missing is skipped with a warning, or fails the gate when
# GATE_REQUIRE_ALL_REGIONS=1. ci/affected_versions.py computes the list.

set -euo pipefail

usage() {
    echo "usage: $(basename "$0") <checkout-dir> [coverage-output-dir]" >&2
    exit 2
}

[ "$#" -ge 1 ] && [ "$#" -le 2 ] || usage

checkout_dir="$1"
coverage_output_dir="${2:-}"
if [ ! -d "$checkout_dir" ]; then
    echo "gate-pr.sh: checkout does not exist: $checkout_dir" >&2
    exit 1
fi
checkout_dir="$(cd "$checkout_dir" && pwd)"

for required in Makefile src include linker_scripts yamls tools lib; do
    if [ ! -e "$checkout_dir/$required" ]; then
        echo "gate-pr.sh: missing public checkout path: $required" >&2
        exit 1
    fi
done

image="${POKESTADIUM_DECOMP_AGENT_IMAGE:-pokestadium-decomp-agent:latest}"
log_file="$(mktemp "${TMPDIR:-/tmp}/pokestadium-gate.XXXXXX.log")"
cleanup() { rm -f "$log_file"; }
trap cleanup EXIT

docker_args=(
    run --rm
    --platform linux/amd64
    --network none
    --cap-drop=ALL
    --security-opt=no-new-privileges
    --pids-limit=2048
    -v "$checkout_dir:/src:ro"
)
if [ -n "$coverage_output_dir" ]; then
    mkdir -p "$coverage_output_dir"
    docker_args+=( -v "$coverage_output_dir:/out:rw" )
fi

regions="${GATE_REGIONS:-us}"
if [ -z "${regions// /}" ]; then
    echo "gate-pr.sh: no ROM version affected; nothing to build" >&2
    exit 0
fi
for region in $regions; do
    if [[ ! "$region" =~ ^[a-z0-9_]+$ ]] || [ ! -f "$checkout_dir/yamls/$region/rom.yaml" ]; then
        echo "gate-pr.sh: unknown or unbuildable region: $region" >&2
        exit 2
    fi
done
docker_args+=( -e "GATE_REGIONS=$regions" -e "GATE_REQUIRE_ALL_REGIONS=${GATE_REQUIRE_ALL_REGIONS:-0}" )
if [ -n "${POKESTADIUM_BASEROM_DIR:-}" ] && [ -d "$POKESTADIUM_BASEROM_DIR" ]; then
    docker_args+=( -v "$(cd "$POKESTADIUM_BASEROM_DIR" && pwd):/baseroms-extra:ro" )
fi

set +e
docker "${docker_args[@]}" \
    --entrypoint bash \
    "$image" \
    -c '
set -euo pipefail

# Overlay all tracked inputs that can affect the public root build. Never
# overlay baseroms: the baseline image owns the known retail reference.
want_us=0
case " ${GATE_REGIONS} " in *" us "*) want_us=1 ;; esac
library_changed=0
split_changed=0
headers_changed=0
tools_changed=0
linker_changed=0
makefile_changed=0

# Keep the baked source/object timestamps for unchanged files. A plain
# recursive copy makes every checkout file newer than the baked objects,
# which defeats the image cache and turns every PR into a full build.
# Use one native diff scan per tree, then overlay only reported changes.
sync_tree() {
    local source_dir="$1"
    local target_dir="$2"
    shift 2
    local diff_file
    local diff_status=0
    local line
    local relative
    local source_parent
    local source_file
    local target_file
    local target_parent

    mkdir -p "$target_dir"
    diff_file="$(mktemp)"
    if ! diff -qr "$@" "$source_dir" "$target_dir" >"$diff_file" 2>&1; then
        diff_status=1
    fi
    if [ "${diff_status}" -eq 0 ]; then
        rm -f "$diff_file"
        return 1
    fi

    mkdir -p "$target_dir"
    while IFS= read -r line || [ -n "$line" ]; do
        case "$line" in
        Files\ *\ and\ *\ differ)
            source_file="${line#Files }"
            source_file="${source_file% and * differ}"
            target_file="${line#* and }"
            target_file="${target_file% differ}"
            mkdir -p "$(dirname "$target_file")"
            cp -p "$source_file" "$target_file"
            ;;
        "Only in ${source_dir}"*)
            source_parent="${line#Only in }"
            source_parent="${source_parent%: *}"
            source_file="$source_parent/${line##*: }"
            relative="${source_file#${source_dir}/}"
            target_file="$target_dir/$relative"
            if [ -d "$source_file" ]; then
                mkdir -p "$target_file"
                cp -pR "$source_file/." "$target_file/"
            else
                mkdir -p "$(dirname "$target_file")"
                cp -p "$source_file" "$target_file"
            fi
            ;;
        "Only in ${target_dir}"*)
            target_parent="${line#Only in }"
            target_parent="${target_parent%: *}"
            target_file="$target_parent/${line##*: }"
            rm -rf "$target_file"
            ;;
        esac
    done <"$diff_file"
    rm -f "$diff_file"
    return 0
}

if sync_tree /src/src /work/src; then :; fi
if [ -d /src/hand_asm ]; then
    if sync_tree /src/hand_asm /work/hand_asm; then :; fi
fi
# text/ holds tracked edits consumed by the textdata.o recipe
# (tools/patch_textdata.py text/textdata.json); like hand_asm, most PRs have
# no reason to touch it, so only sync it when the checkout actually has one
# -- the baked image predates this directory and sync_tree creates it fresh.
if [ -d /src/text ]; then
    if sync_tree /src/text /work/text; then :; fi
fi
if sync_tree /src/include /work/include; then headers_changed=1; fi

# The Makefile C_FILES list is `git ls-files -- src`, resolved against the
# git repository baked into the image at build time (see ci/Dockerfile).
# That baked index only knows the files that existed at bake time, so a
# PR that adds a new src/*.c (or renames/removes one) needs the index
# refreshed to match what was just overlaid onto disk above, or the new
# file silently never gets compiled. Guarded on /work/.git existing so
# this degrades to a no-op -- not a hard failure -- against a baseline
# image built before this git-init was added.
if [ -d /work/.git ]; then
    git -C /work add -A src include
fi

if sync_tree /src/tools /work/tools --exclude=__pycache__ --exclude=vtxdis; then tools_changed=1; fi
# yamls/us/header.yaml symbol_addrs_path lists these files as direct splat
# extraction inputs (address->name resolution baked into asm/ at extract
# time), same as the yamls themselves -- but they live under linker_scripts/,
# so a lone rename/add/remove here must also trigger make extract below, not
# just the full-recompile linker_changed already forces. Checked before the
# general linker_scripts sync_tree overwrites /work, so this reflects what
# actually changed, not the post-sync (already-identical) state.
symbol_addrs_changed=0
for f in /src/linker_scripts/us/symbol_addrs*.txt; do
    [ -e "$f" ] || continue
    rel="${f#/src/}"
    if ! cmp -s "$f" "/work/$rel" 2>/dev/null; then
        symbol_addrs_changed=1
    fi
done
if sync_tree /src/linker_scripts /work/linker_scripts --exclude=auto --exclude=pokestadium.ld; then linker_changed=1; fi
if sync_tree /src/lib /work/lib --exclude=build --exclude=extracted; then library_changed=1; fi
makefile_changed=0
if [ ! -f /work/Makefile ] || ! cmp -s /src/Makefile /work/Makefile; then
    makefile_changed=1
fi
if [ "${makefile_changed}" -eq 1 ]; then
    cp -p /src/Makefile /work/Makefile
fi

# The baked venv must match the checked-in requirements. Rebuilding it would
# require network access, so force a baseline rebuild for dependency changes.
if ! cmp -s /src/requirements.txt /work/requirements.txt; then
    echo "gate-pr.sh: requirements.txt changed; rebuild the public baseline image" >&2
    exit 3
fi

# A YAML or symbol_addrs*.txt change changes the split. Re-extract before
# compiling against it. Confirmed live, 2026-09-26 (PR #106): a clean,
# yamls-untouched symbol_addrs_code.txt rename left the already-baked
# /work/asm disassembly labeling the renamed address under its old name, so a
# still-unmatched sibling GLOBAL_ASM block elsewhere that calls it failed to
# link with an undefined reference -- even under the full rebuild
# linker_changed alone already forces, since that only recompiles existing
# asm/*.s text, it never regenerates it.
if sync_tree /src/yamls /work/yamls || [ "${symbol_addrs_changed}" -eq 1 ]; then
    split_changed=1
    echo "gate-pr.sh: split inputs changed; re-running extraction" >&2
    if [ "${want_us}" -eq 1 ]; then make extract; fi
    # extract regenerates linker_scripts/us/*.ld from whatever /work/asm the
    # baked image already had, which can predate this split and disagree
    # with the linker script already synced from /src above and already
    # verified with a real build. Re-sync on top so that already-verified
    # version is what actually gets built, not a second, possibly
    # different regeneration against a stale local tree.
    sync_tree /src/linker_scripts /work/linker_scripts --exclude=auto --exclude=pokestadium.ld || true
fi

# A library change invalidates the baked lib objects. This remains inside the
# disposable container and does not touch the host checkout.
if [ "${library_changed}" -eq 1 ]; then
    make libclean
fi

# Rebuild a direct-IDO seed when extraction or libclean removed the baked map.
# The coalescing wrapper needs that map to resolve dlabels before it can safely
# apply an opted-in fold. The final ROM build is always forced after the PR
# overlay: the image contains a retail seed ROM, and timestamp-based make
# decisions must never be allowed to accept that seed without compiling the
# checked-out sources.
if [ "${want_us}" -eq 0 ]; then
    :
elif [ "${split_changed}" -eq 1 ]; then
    rm -rf /work/build
elif [ "${linker_changed}" -eq 1 ]; then
    rm -f /work/build/pokestadium-us.map \
        /work/build/pokestadium-us.elf \
        /work/build/pokestadium-us.z64
fi
if [ "${want_us}" -eq 1 ] && [ ! -f /work/build/pokestadium-us.map ]; then
    echo "gate-pr.sh: linked map missing; rebuilding direct-IDO seed" >&2
    # CC= on the make command line overrides every target-specific CC
    # assignment in the Makefile, including the one that routes
    # still-unmatched GLOBAL_ASM files through asm-processor. That turns
    # those files into empty stubs for this seed build, which can fail to
    # link if anything (for example an aliases.ld entry) references one of
    # the now-missing symbols. This seed build only exists to hand the
    # coalescing wrapper a reference map; it is not the gate verdict, and
    # the real, correctly-compiled build always runs next regardless of
    # whether this step produced a map. Tolerate its failure here.
    make CC=tools/ido/linux/7.1/cc COMPARE=0 -j2 rom || true
fi

# Produce the proposed coverage snapshot even when the ROM build later
# fails, so reviewers can inspect the exact PR delta in the artifact.
if [ -d /out ]; then
    python3 /src/ci/update_coverage.py \
        --repo-root /src \
        --baseline /src/COVERAGE.md \
        --output /out/COVERAGE.md
fi

# Force every root object through its recipe. Each C-object recipe performs the
# host syntax check before invoking IDO, so this forced build covers the whole
# C tree without running a second serial cc-check pass. libultra is rebuilt
# with FIXUPS by the root Makefile; disabling the nested archive comparison
# lets that source build run without a private libultra base archive. Use all
# available container CPUs by default; the override is useful for diagnosing
# runner contention without weakening the gate.
build_jobs="${POKESTADIUM_DECOMP_JOBS:-$(nproc)}"
case "${build_jobs}" in
    ""|*[!0-9]*|0)
        echo "gate-pr.sh: POKESTADIUM_DECOMP_JOBS must be a positive integer" >&2
        exit 2
        ;;
esac
echo "gate-pr.sh: building with ${build_jobs} parallel job(s); per-object host syntax checks enabled"
# linker_changed alone (above) only forces a fresh LINK of the existing
# cached objects -- correct when the only thing that moved is where
# already-correct objects land, but not when the checked-out
# linker_scripts/symbol table content itself differs from what this
# baked image was built against. symbol_addrs_code.txt declares symbols
# for many unrelated functions in one shared file; a still-unmatched
# owners own .c/.s content can be byte-identical to what the image
# already has cached (so sync_tree correctly leaves its .o alone) while
# the symbol IT depends on was renamed or removed elsewhere by other,
# unrelated merges that landed on master since this image was last
# rebuilt -- that stale cached .o then fails to link against the fresh
# table with an "undefined reference," in files this PR never touched.
# Confirmed live, 2026-09-26 (PR #94): a clean symbol rename failed this
# gate with undefined references in 8 unrelated still-GLOBAL_ASM files,
# not a checksum mismatch -- the build never even reached the checksum
# comparison. Treat any linker_scripts diff as tree-wide, the same as
# split/header/tool/Makefile changes already are.
if [ "${want_us}" -eq 1 ]; then
    full_build=0
    if [ "${split_changed}" -eq 1 ] || [ "${headers_changed}" -eq 1 ] || [ "${tools_changed}" -eq 1 ] || [ "${makefile_changed}" -eq 1 ] || [ "${linker_changed}" -eq 1 ]; then
        full_build=1
    fi
    if [ "${full_build}" -eq 1 ]; then
        echo "gate-pr.sh: forcing a full rebuild because split, header, tool, linker-script, or Makefile inputs changed"
        make -B COMPARE=0 -j"${build_jobs}" rom
    else
        echo "gate-pr.sh: reusing cached objects and rebuilding changed source inputs"
        make COMPARE=0 -j"${build_jobs}" rom
    fi
    md5sum -c baseroms/us/checksum.md5
    echo "gate-pr.sh: region us OK"
fi

# Every other requested version builds cold from its own retail dump.
for region in ${GATE_REGIONS}; do
    [ "${region}" = us ] && continue
    dump="/baseroms-extra/${region}/baserom.z64"
    if [ ! -f "${dump}" ]; then
        if [ "${GATE_REQUIRE_ALL_REGIONS}" = 1 ]; then
            echo "gate-pr.sh: FAIL -- no retail dump for region ${region} on the runner" >&2
            exit 1
        fi
        echo "gate-pr.sh: region ${region} SKIPPED (no retail dump on the runner)" >&2
        continue
    fi
    want_md5="$(tr -d "\r" < "/src/baseroms/${region}/checksum.md5" | cut -d" " -f1)"
    have_md5="$(md5sum "${dump}" | cut -d" " -f1)"
    if [ "${want_md5}" != "${have_md5}" ]; then
        echo "gate-pr.sh: FAIL -- dump for ${region} is ${have_md5}, expected ${want_md5}" >&2
        exit 1
    fi
    mkdir -p "/work/baseroms/${region}"
    cp "${dump}" "/work/baseroms/${region}/baserom.z64"
    cp "/src/baseroms/${region}/checksum.md5" "/work/baseroms/${region}/checksum.md5"
    echo "gate-pr.sh: region ${region}: extracting and building"
    make VERSION="${region}" extract
    make VERSION="${region}" COMPARE=1 -j"${build_jobs}" rom
    echo "gate-pr.sh: region ${region} OK"
done
' >"$log_file" 2>&1
status=$?
set -e

# The build emits one "Binning object:"/"Assembling:" line per file --
# hundreds of them on a full build, never diagnostic on their own. Drop
# just those from the console; the full, unfiltered log is still saved
# below when a coverage_output_dir is given, so nothing is actually lost,
# only what floods a routine run's console view. On failure, still show
# every remaining (non-per-file) line so the real error surrounding
# context is visible; on success, only the tail (the checksum result)
# actually matters.
quiet_log() {
    grep -Ev '^(\x1b\[[0-9;]*m)?(Binning object|Assembling):' "$1"
}
if [ "$status" -ne 0 ]; then
    quiet_log "$log_file"
else
    quiet_log "$log_file" | tail -15
fi
if [ -n "$coverage_output_dir" ]; then
    cp "$log_file" "$coverage_output_dir/gate.log"
fi
echo "gate-pr.sh: container exit status $status" >&2

if [ "$status" -ne 0 ]; then
    echo "gate-pr.sh: FAIL -- public build/compare failed" >&2
    exit "$status"
fi

# Make's colored output can leave an ANSI reset sequence immediately before
# md5sum's result. The md5sum exit status above is authoritative; this check
# is only a readable-log sanity check and therefore must not require the line
# to start at column zero.
skipped=""
for region in $regions; do
    if grep -q "region $region SKIPPED" "$log_file"; then
        skipped="$skipped $region"
        echo "::warning::gate-pr.sh: region $region was NOT checked (no retail dump on the runner)" >&2
    elif ! grep -q "gate-pr.sh: region $region OK" "$log_file"; then
        echo "gate-pr.sh: FAIL -- region $region reported no success line" >&2
        exit 1
    fi
done
if [[ " $regions " == *" us "* ]] && ! grep -q 'build/pokestadium-us\.z64: OK' "$log_file"; then
    echo "gate-pr.sh: FAIL -- expected checksum acceptance line was absent" >&2
    exit 1
fi

echo "gate-pr.sh: PASS -- regions: $regions${skipped:+ (not checked:$skipped)}" >&2
