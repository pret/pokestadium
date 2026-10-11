#!/usr/bin/env bash
# Make a disposable copy of the instrumented toolchain for scratchpad experiments,
# so forced-color probes never run against the tree a gate was recorded on.
#   usage: bash cdx71/make-scratch-copy.sh <dest>      (e.g. ../scratchpad/idot/run1)
# The pokestadium build itself keeps using tools/ido/<os>/7.1; never point the
# repo Makefile at this tree.
set -euo pipefail
src="$(cd "$(dirname "$0")/.." && pwd)/build/7.1-traced/out"
mkdir -p "$1"
cp -a "$src/." "$1/"
echo "scratch toolchain at $1 (cc, uopt=CDX, ugen=traced; uopt.bak_nodes is the stage-2 binary)"
