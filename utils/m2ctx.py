#!/usr/bin/env python3
import argparse
import os
import shutil
import sys
import subprocess
from pathlib import Path

# Project-specific
# assuming that this is in tools
SCRIPT_DIR = os.path.dirname(os.path.realpath(__file__))
ROOT_DIR = os.path.abspath(os.path.join(SCRIPT_DIR, ".."))
CPP_FLAGS = [
    "-undef",
    "-D__sgi",
    "-D_LANGUAGE_C",
    "-DF3DEX_GBI_2",
    "-DNDEBUG",
    "-D_MIPS_SZLONG=32",
    "-DSCRIPT(...)={}"
    "-D__attribute__(...)=",
    "-D__asm__(...)=",
    "-DGLOBAL_ASM(...)=",
    "-ffreestanding",
    "-nostdinc",
    "-Iinclude",
    "-Iinclude/PR",
    "-Iinclude/audio",
    "-Isrc"
]

def import_c_file(in_file) -> str:
    in_file = os.path.relpath(in_file, ROOT_DIR)
    # Prefer clang as C preprocessor if installed on the system
    if shutil.which('clang') is not None:
        cpp = ['clang', '-E', '-P', '-x', 'c', '-Wno-trigraphs']
    else:
        cpp = ['gcc', '-E', '-P']
    
    cpp_getdefines = [*cpp, "-dM", *CPP_FLAGS, in_file]
    cpp_procfile = [*cpp, *CPP_FLAGS, in_file]

    out_text = ""
    try:
        out_text += subprocess.check_output(cpp_getdefines, cwd=ROOT_DIR, encoding="utf-8")
        out_text += subprocess.check_output(cpp_procfile, cwd=ROOT_DIR, encoding="utf-8")
    except subprocess.CalledProcessError:
        print(
            "Failed to preprocess input file, when running command:\n",
            cpp_getdefines,
            file=sys.stderr,
            )
        sys.exit(1)

    if not out_text:
        print("Output is empty - aborting")
        sys.exit(1)
    return out_text

def main():
    parser = argparse.ArgumentParser(
        description="Create a context file which can be used for m2c"
    )
    parser.add_argument(
        "c_file",
        help="File from which to create context",
    )
    parser.add_argument(
        "ctx_file",
        nargs='?',
        help="save context to file if present, otherwise print to stdout"
    )
    args = parser.parse_args()

    output = import_c_file(args.c_file)

    if args.ctx_file is not None:
        with open(os.path.join(ROOT_DIR, args.ctx_file), "w", encoding="UTF-8") as f:
            f.write(output)
    else:
        print(output)

if __name__ == "__main__":
    main()