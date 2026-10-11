#!/usr/bin/env bash
# Fidelity gate for build/7.1-traced: every cell must print IDENTICAL.
#   usage: bash cdx71/gate.sh <pokestadium-root> <tu.c> [<tu.c> ...]
# Compares stock build/7.1/out against the instrumented tree with
#   off      no switches set
#   baknodes out/uopt.bak_nodes swapped in (stage-2 backup binary)
#   on       every trace switch on (CDX_* and DKWB_UGEN_*)
#   cm       CDX_CMDUMP=1 (uopt's own -zdbug:3 listing)
#   cm7      CDX_CMDUMP=7 (numeric level: printtab after copy propagation)
#   uinj     DKWB_UDUMP=1 plus a DKWB_UREPLACE of record 5 with itself
#            (exercises the ugen injection queue; must be byte-identical)
# Section-scoped (.text .rodata .data .sdata .bss, relocations, symbols),
# per decomp-workbench docs/compiler-instrumentation.md "Required fidelity gates".
set -uo pipefail
R="$(cd "$(dirname "$0")/.." && pwd)/build"
P="$(cd "$1" && pwd)"; shift
if [ -z "${OBJDUMP_PREFIX:-}" ]; then
  if command -v mips-linux-gnu-objcopy >/dev/null 2>&1; then OBJDUMP_PREFIX=mips-linux-gnu-; else OBJDUMP_PREFIX=mips64-elf-; fi
fi
OD=$OBJDUMP_PREFIX
if command -v sha256sum >/dev/null 2>&1; then SHA="sha256sum"; else SHA="shasum -a 256"; fi
W=$(mktemp -d)
cc71() {  # cc71 <outdir> <src> <obj>
  (cd "$P" && "$1/cc" -c -G 0 -non_shared -Xcpluscomm -nostdinc -Wab,-r4300_mul \
    -Iinclude -Isrc -Isrc/libnaudio -Iassets/us -I. -Ibuild \
    -Ilib/ultralib/include -Ilib/ultralib/include/PR -Ilib/ultralib/include/ido -Iinclude/ \
    -woff 624,649,838,712,516,513,596,564,594 -mips2 -EB -D_MIPS_SZLONG=32 \
    -DNDEBUG -D_FINALROM -DN_MICRO -DF3DEX_GBI_2 -DBUILD_VERSION=VERSION_I_P \
    -DLANGUAGE_C -D_LANGUAGE_C -O2 -o "$3" "$2")
}
fp() {
  for s in .text .rodata .data .sdata .bss; do
    printf "%s " $s; ${OD}objcopy -O binary -j $s "$1" "$1.sec" 2>/dev/null; $SHA < "$1.sec" | cut -c1-16
  done
  printf "relocs "; ${OD}readelf -rW "$1" | $SHA | cut -c1-16
  printf "symtab "; ${OD}readelf -sW "$1" | $SHA | cut -c1-16
}
mkdir -p "$W/baknodes"; cp -a "$R/7.1/out/." "$W/baknodes/"; cp "$R/7.1-traced/out/uopt.bak_nodes" "$W/baknodes/uopt"
ALL="CDX_LOG=1 CDX_DETAIL_WEB=all CDX_SYMTAB=1 CDX_TEMPS=1 CDX_NODES=1 CDX_UCODE=1 CDX_LINEAGE_TABLES=all CDX_CP=1 CDX_CA=1 CDX_NEWBIT=1 CDX_WEBREPORT=1 DKWB_UGEN_TRACE=1 DKWB_UGEN_SCHED=1"
fail=0
for tu in "$@"; do
  # paths relative to the caller's cwd win; otherwise relative to pokestadium
  if [ -f "$tu" ]; then tu="$(cd "$(dirname "$tu")" && pwd)/$(basename "$tu")"; fi
  b=$(basename "$tu" .c)
  cc71 "$R/7.1/out" "$tu" "$W/$b.stock.o" 2>/dev/null
  cc71 "$R/7.1-traced/out" "$tu" "$W/$b.off.o" 2>/dev/null
  cc71 "$W/baknodes" "$tu" "$W/$b.baknodes.o" 2>/dev/null
  env $ALL CDX_OUT="$W/$b.cdx.log" bash -c "$(declare -f cc71); P='$P'; cc71 '$R/7.1-traced/out' '$tu' '$W/$b.on.o'" 2>"$W/$b.ugen.log"
  env CDX_CMDUMP=1 CDX_CMFILE="$W/$b.cm.txt" bash -c "$(declare -f cc71); P='$P'; cc71 '$R/7.1-traced/out' '$tu' '$W/$b.cm.o'" 2>/dev/null
  env CDX_CMDUMP=7 CDX_CMFILE="$W/$b.cm7.txt" bash -c "$(declare -f cc71); P='$P'; cc71 '$R/7.1-traced/out' '$tu' '$W/$b.cm7.o'" 2>/dev/null
  # identity replacement: record 5 replaced by its own words (taken from a dump run)
  w5=$(env DKWB_UDUMP=1 bash -c "$(declare -f cc71); P='$P'; cc71 '$R/7.1-traced/out' '$tu' '$W/$b.udump.o'" 2>&1 | grep -m1 '^\[U\] n=5 ' | sed 's/.* w=//; s/ /,0x/g; s/^/0x/')
  env DKWB_UDUMP=1 DKWB_UREPLACE="5:1:$w5" bash -c "$(declare -f cc71); P='$P'; cc71 '$R/7.1-traced/out' '$tu' '$W/$b.uinj.o'" 2>/dev/null
  if [ ! -s "$W/$b.stock.o" ]; then echo "$b: STOCK OBJECT MISSING (compile failed)"; fail=1; continue; fi
  fp "$W/$b.stock.o" > "$W/$b.stock.fp"
  for v in off baknodes on cm cm7 uinj; do
    if [ ! -s "$W/$b.$v.o" ]; then echo "$b stock-vs-$v: MISSING OBJECT"; fail=1; continue; fi
    fp "$W/$b.$v.o" > "$W/$b.$v.fp" 2>/dev/null
    if cmp -s "$W/$b.stock.fp" "$W/$b.$v.fp"; then r=IDENTICAL; else r=DIFF; fail=1; fi
    echo "$b stock-vs-$v: $r"
  done
  echo "  .text $(grep '^.text' "$W/$b.stock.fp" | cut -d' ' -f2)  cdx.log $(wc -l < "$W/$b.cdx.log") lines  ugen.log $(wc -l < "$W/$b.ugen.log") lines  cm.txt $(wc -l < "$W/$b.cm.txt" 2>/dev/null || echo 0) lines"
done
echo "work dir: $W"
exit $fail
