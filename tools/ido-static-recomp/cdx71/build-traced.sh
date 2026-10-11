#!/usr/bin/env bash
# Rebuild build/7.1-traced/ from a stock `make VERSION=7.1 RELEASE=1` tree.
#   needs: python3, gcc, decomp-workbench (pipx/pip install of akratch/n64-decomp-workbench)
#   run from the ido-static-recomp root:  bash cdx71/build-traced.sh
#   DKWB_BIN / DKWB_PYTHON override the workbench CLI and the python that can import
#   decomp_workbench (macOS dev box: ~/.pyenv/versions/3.10.4/bin/{decomp-workbench,python3.10}).
# Host flags match the stock Makefile (gcc -std=c11 -Os -fno-strict-aliasing),
# so the fidelity gate compares like with like.
set -euo pipefail
DKWB_BIN="${DKWB_BIN:-decomp-workbench}"
DKWB_PYTHON="${DKWB_PYTHON:-python3}"
cd "$(dirname "$0")/.."
T=build/7.1-traced
CFLAGS="-std=c11 -Os -fno-strict-aliasing -I."
test -f build/7.1/uopt.c -a -f build/7.1/ugen.c || { echo "run: make setup && make VERSION=7.1 RELEASE=1"; exit 1; }
mkdir -p "$T/out"
cp -a build/7.1/out/. "$T/out/"

# --- ugen: workbench instrument-ugen + 7.1 addresses -------------------------
rm -f "$T/ugen.traced.c"
"$DKWB_BIN" instrument-ugen --emit-provenance build/7.1/ugen.c "$T/ugen.traced.c"
# workbench ships 5.3 addresses; 7.1 values derived from f_emit_rr / f_demit_ri
# (ibuffer base 0x10021234, forward cursor +4, backward cursor +0xC) and
# f_warning ("ugen: warning: line %d: %s" reads MEM_U32(0x10021220)).
sed -i.bak 's/0x10018e70u/0x10021238u/; s/0x10018e78u/0x10021240u/; s/0x10018e00u/0x10021220u/' "$T/ugen.traced.c"
rm -f "$T/ugen.traced.c.bak"
grep -q 0x10021238u "$T/ugen.traced.c"
# u-code injection hook (DKWB_UDUMP / UPATCH / UDELETE / UINSERT / UREPLACE)
python3 cdx71/patch_ugen71.py "$T/ugen.traced.c"

# --- uopt: staged CDX port ---------------------------------------------------
"$DKWB_PYTHON" cdx71/patch_uopt71.py build/7.1/uopt.c "$T"

# --- libc with ecvt/fcvt (only the traced uopt links it) ---------------------
gcc -c $CFLAGS -DIDO71 -Wno-deprecated-declarations -o "$T/libc_impl_cdx71.o" cdx71/libc_impl_cdx71.c

build() {  # build <source.c> <out-binary> <libc.o>
  gcc -c $CFLAGS -x c -o "$2.o" "$1"
  gcc -std=c11 -Os -o "$2" "$2.o" build/7.1/version_info.o "$3" -lm 2>/dev/null
  strip "$2"; rm -f "$2.o"
}
build "$T/ugen.traced.c" "$T/out/ugen" build/7.1/libc_impl_71.o &
build "$T/uopt.gc.c" "$T/out/uopt" "$T/libc_impl_cdx71.o" &
build "$T/uopt.gc.c.bak_nodes" "$T/out/uopt.bak_nodes" "$T/libc_impl_cdx71.o" &
wait
"$DKWB_BIN" check-drop-in "$T/out/uopt" "$T/out/ugen" || true
echo "built $T/out (ugen + uopt instrumented; everything else stock)"
