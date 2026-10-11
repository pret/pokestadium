/**
 * Function that prints version info. This file should be compiled with the following defined:
 * - PACKAGE_VERSION, e.g. with `-DPACKAGE_VERSION="\"$(LC_ALL=C git --git-dir .git describe --tags --dirty)\""`
 * - DATETIME, e.g. with `-DDATETIME="\"$(date +'%F %T UTC%z')\""`
 *
 * The code in this file is mostly taken from 
 * - CPython: https://github.com/python/cpython/, licensed under the PSF, available here: https://docs.python.org/3/license.html
 * - The Ocarina of Time practice rom, gz: https://github.com/glankk/gz/
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>

#if defined(IDO53)
#define IDO_VERSION "IDO 5.3"
#elif defined(IDO71)
#define IDO_VERSION "IDO 7.1"
#else
#define IDO_VERSION ""
#endif

#ifndef COMPILER

// Note the __clang__ conditional has to come before the __GNUC__ one because
// clang pretends to be GCC.
#if defined(__clang__)
#define COMPILER "Clang " __clang_version__
#elif defined(__GNUC__)
#define COMPILER "GCC " __VERSION__
// Generic fallbacks.
#elif defined(__cplusplus)
#define COMPILER "C++"
#else
#define COMPILER "C"
#endif

#endif /* !COMPILER */

/* git */
#ifndef PACKAGE_VERSION
#define PACKAGE_VERSION "Unknown version"
#endif

/* Date and time */
#ifndef DATETIME
#define DATETIME "Unknown date"
#endif

extern char* progname;

void print_version_info(void) {
    char* buf = malloc(strlen(progname) + 1);
    strcpy(buf, progname);
    char* name = basename(buf);

    printf("%s `%s` static recompilation, Decompals version\n", IDO_VERSION, name);
    printf("Source:     https://github.com/decompals/ido-static-recomp\n");
    printf("Version:    %s\n", PACKAGE_VERSION);
    printf("Build date: %s\n", DATETIME);
    printf("Compiler:   %s\n", COMPILER);

    free(buf);
}
