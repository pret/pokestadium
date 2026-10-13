#!/usr/bin/env bash
# Resolve Stadium 1 fragment symbols to N64 addresses, not host/JIT pointers.
# Formula: https://github.com/michiiik/pokestadium/blob/master/src/memmap.c
set -euo pipefail

usage() {
    cat <<'HELP'
Usage:
  bash stadium-function-address.sh FUNCTION LOADED_BASE VERSION

Examples:
  bash stadium-function-address.sh AreaSelect_AdvanceSparkleTrail 80200000 us
  bash stadium-function-address.sh AreaSelect_AdvanceSparkleTrail '?' us_rev2

LOADED_BASE is the 32-bit VALUE read from the fragment-table slot in
Project64, not the address of the slot. Hex with or without 0x is accepted.
Use '?' to print the slot to read without calculating a runtime address.

Versions: us, us_rev1, us_rev2, jp, eu, eu_rev1, de, fr, es, it

By default, fetch symbol files from a pinned pokestadium revision.
Environment overrides:
  STADIUM_REPO=/path/to/pokestadium
    Read local linker_scripts/VERSION/symbol_addrs*.txt instead (offline).
  STADIUM_REF=master
    Choose another upstream branch, tag, or commit when fetching.

Requires Bash 4+, awk, and (unless using STADIUM_REPO) curl.
This script does not read Project64 memory or verify your ROM identity.
HELP
}

fail() { printf 'Error: %s\n' "$*" >&2; exit 1; }

if [[ ${1:-} == --help || ${1:-} == -h ]]; then
    usage
    exit 0
fi
[[ $# == 3 ]] || { usage >&2; exit 1; }
(( BASH_VERSINFO[0] >= 4 )) || fail 'Bash 4 or newer is required.'

functionName=$1
loadedBaseText=$2
version=$3
[[ $functionName =~ ^[A-Za-z_][A-Za-z0-9_]*$ ]] ||
    fail 'FUNCTION must be an exact C symbol name.'
case $version in
    us|us_rev1|us_rev2|jp|eu|eu_rev1|de|fr|es|it) ;;
    *) fail "Unknown version '$version'. Use --help for supported versions." ;;
esac

# Validate before any downloads. All unprefixed input is hexadecimal.
if [[ $loadedBaseText != '?' ]]; then
    hexText=${loadedBaseText#0x}
    hexText=${hexText#0X}
    [[ $hexText =~ ^[0-9A-Fa-f]{1,8}$ ]] ||
        fail 'LOADED_BASE must be up to eight hex digits, optionally prefixed by 0x, or ?.'
    loadedBase=$((16#$hexText))
fi

temporaryDir=''
cleanup() {
    if [[ -n $temporaryDir ]]; then rm -rf -- "$temporaryDir"; fi
}
trap cleanup EXIT
trap 'exit 130' INT
trap 'exit 143' TERM

if [[ -n ${STADIUM_REPO:-} ]]; then
    symbolDir="${STADIUM_REPO%/}/linker_scripts/$version"
    [[ -d $symbolDir ]] || fail "Symbol directory not found: $symbolDir"
    symbolOrigin="local: $symbolDir"
else
    command -v curl >/dev/null || fail 'curl is required for upstream symbol downloads.'
    revision=${STADIUM_REF:-bd74c85a4185b73cb3bd1e5b1fe535cf34989b4d}
    [[ $revision =~ ^[A-Za-z0-9_./-]+$ ]] || fail 'Invalid STADIUM_REF.'
    temporaryDir=$(mktemp -d)
    symbolDir=$temporaryDir
    for filename in symbol_addrs.txt symbol_addrs_code.txt; do
        url="https://raw.githubusercontent.com/michiiik/pokestadium/$revision/linker_scripts/$version/$filename"
        curl --fail --silent --show-error --location --connect-timeout 10 --max-time 60 \
            "$url" --output "$symbolDir/$filename" ||
            fail "Could not download $url. Try STADIUM_REPO for local symbols."
    done
    symbolOrigin="upstream: michiiik/pokestadium @ $revision"
fi

shopt -s nullglob
symbolFiles=("$symbolDir"/symbol_addrs*.txt)
(( ${#symbolFiles[@]} > 0 )) || fail "No symbol_addrs*.txt files in $symbolDir"
for symbolFile in "${symbolFiles[@]}"; do
    IFS= read -r firstLine < "$symbolFile" || true
    [[ $firstLine != 'version https://git-lfs.github.com/spec/v1' ]] ||
        fail "Unhydrated Git LFS pointer: $symbolFile"
done

# Exact symbol matching, deduplicate identical definitions, reject conflicts.
lookupSymbol() {
    local wanted=$1 result
    result=$(awk -v wanted="$wanted" '
        $1 == wanted && $2 == "=" {
            address = $3
            sub(/;.*/, "", address)
            if (address ~ /^0[xX][0-9a-fA-F]+$/) {
                normalized = tolower(address)
                if (!(normalized in seen)) {
                    seen[normalized] = 1
                    print normalized
                }
            }
        }
    ' "${symbolFiles[@]}")
    [[ -n $result ]] || fail "Symbol '$wanted' not found for $version. Check spelling or use STADIUM_REPO."
    [[ $result != *$'\n'* ]] || fail "Conflicting addresses for '$wanted': $result"
    printf '%s' "$result"
}

nominalText=$(lookupSymbol "$functionName")
nominalAddress=$((nominalText))
printf 'Function:        %s\nVersion:         %s\nSymbols:         %s\n' \
    "$functionName" "$version" "$symbolOrigin"
printf 'Nominal address: 0x%08X\n' "$nominalAddress"

if (( nominalAddress < 0x81000000 || nominalAddress >= 0x90000000 )); then
    printf 'Not fragment-encoded; no fragment rebasing is needed.\n'
    printf 'Runtime address: 0x%08X\n' "$nominalAddress"
    exit 0
fi

fragmentIndex=$((((nominalAddress & 0x0FF00000) >> 20) - 0x10))
fragmentOffset=$((nominalAddress & 0x000FFFFF))
tableText=$(lookupSymbol gFragments)
tableAddress=$((tableText))
slotAddress=$((tableAddress + fragmentIndex * 8))
printf 'Fragment index:  %d (0x%X; zero-based table index)\n' "$fragmentIndex" "$fragmentIndex"
printf 'Fragment offset: 0x%X\n' "$fragmentOffset"
printf 'Read base at:    0x%08X (32-bit virtual-memory value)\n' "$slotAddress"
printf 'Read size at:    0x%08X (optional bounds check)\n' "$((slotAddress + 4))"

if [[ $loadedBaseText == '?' ]]; then
    printf '\nRead the base VALUE at the address above, then rerun with that value.\n'
    exit 0
fi
(( loadedBase != 0 )) || fail 'Base is zero: the fragment is not currently mapped.'
(( loadedBase != slotAddress )) ||
    fail 'You supplied the table-slot address. Supply the 32-bit VALUE stored there instead.'
(( (loadedBase >= 0x80000000 && loadedBase < 0x80800000) ||
   (loadedBase >= 0xA0000000 && loadedBase < 0xA0800000) )) ||
    fail 'Base is outside the expected N64 RDRAM virtual ranges; check the pointer and version.'
(( (loadedBase & 3) == 0 )) || fail 'Fragment base must be word-aligned.'

runtimeAddress=$((loadedBase + fragmentOffset))
(( (runtimeAddress & 0x1FFFFFFF) < 0x00800000 )) ||
    fail 'Calculated address exceeds the 8 MiB RDRAM range; check the base pointer.'
printf 'Loaded base:     0x%08X\n' "$loadedBase"
printf 'Calculation:     0x%08X + 0x%X\n' "$loadedBase" "$fragmentOffset"
printf 'Runtime address: 0x%08X\n' "$runtimeAddress"
printf '\nOpen %08X in Project64 Commands; double-click to set a PC breakpoint.\n' "$runtimeAddress"
printf 'Re-read the base after a fragment reload. This is an N64 address, not a host pointer.\n'
