#!/usr/bin/env bash
# Build the per-version baselines the PR gate reuses.
#
# usage: ci/build-region-baselines.sh IMAGE BASEROM_DIR CACHE_DIR CHECKSUM_DIR [VERSION...]
#
# IMAGE         the freshly baked gate image (its /work is the current master tree)
# BASEROM_DIR   <version>/baserom.z64 retail dumps, mounted read-only
# CACHE_DIR     receives <version>.tar (asm/, assets/ and build/ of that version
#               after a full build that matched retail) and <version>.hash
# CHECKSUM_DIR  a checkout's baseroms/ directory, for the <version>/checksum.md5 files
# VERSION...    default: every version in ci/regions.json except us
#
# Each version is built in the same Linux container the gate uses, never on the
# macOS host, so the stored objects match what the gate would compile. A
# version whose build does not match retail is not cached. Existing caches are
# reused for the next build, so a refresh is incremental.

set -euo pipefail

[ "$#" -ge 4 ] || { sed -n '2,16p' "$0" >&2; exit 2; }
image="$1"; baseroms="$(cd "$2" && pwd)"; mkdir -p "$3"; cache="$(cd "$3" && pwd)"; checksums="$(cd "$4" && pwd)"
shift 4
here="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
if [ "$#" -gt 0 ]; then
    versions=("$@")
else
    versions=()
    while IFS= read -r v; do versions+=("$v"); done < <(python3 -c 'import json,sys; print("\n".join(k for k in json.load(open(sys.argv[1])) if not k.startswith("_") and k != "us"))' "$here/regions.json")
fi

failed=()
for v in "${versions[@]}"; do
    if [ ! -f "$baseroms/$v/baserom.z64" ]; then
        echo "build-region-baselines.sh: $v skipped (no dump in $baseroms)" >&2
        continue
    fi
    echo "build-region-baselines.sh: $v: building" >&2
    if docker run --rm --platform linux/amd64 --network none --cap-drop=ALL --security-opt=no-new-privileges \
        -e REGION="$v" \
        -v "$baseroms:/baseroms-extra:ro" -v "$cache:/cache:rw" -v "$checksums:/src-baseroms:ro" -v "$here:/ci-src:ro" \
        --entrypoint bash "$image" -c '
set -euo pipefail
. /ci-src/region_hash.sh
cd /work
mkdir -p "baseroms/$REGION"
cp "/baseroms-extra/$REGION/baserom.z64" "baseroms/$REGION/baserom.z64"
cp "/src-baseroms/$REGION/checksum.md5" "baseroms/$REGION/checksum.md5"
want="$(region_hash /work "$REGION")"
if [ -f "/cache/$REGION.tar" ] && [ "$(cat "/cache/$REGION.hash" 2>/dev/null)" = "$want" ]; then
    echo "build-region-baselines.sh: $REGION: reusing the cached split and objects"
    tar -xpf "/cache/$REGION.tar" --no-same-owner -C /work
else
    make VERSION="$REGION" extract
fi
make VERSION="$REGION" COMPARE=1 -j"$(nproc)" rom
# Everything make extract generates for this version (the shared .splat/ is not
# needed to build) plus its build tree.
tar -cpf "/cache/$REGION.tar.tmp" "asm/$REGION" "assets/$REGION" "build/$REGION" \
    "linker_scripts/$REGION/pokestadium.ld" "linker_scripts/$REGION/auto" "pokestadium-$REGION.yaml"
mv "/cache/$REGION.tar.tmp" "/cache/$REGION.tar"
echo "$want" > "/cache/$REGION.hash"
echo "build-region-baselines.sh: $REGION: cached ($(du -h "/cache/$REGION.tar" | cut -f1))"
'; then
        :
    else
        echo "build-region-baselines.sh: $v: FAILED, no cache written" >&2
        rm -f "$cache/$v.tar" "$cache/$v.hash" "$cache/$v.tar.tmp"
        failed+=("$v")
    fi
done
[ "${#failed[@]}" -eq 0 ] || { echo "build-region-baselines.sh: failed: ${failed[*]}" >&2; exit 1; }
