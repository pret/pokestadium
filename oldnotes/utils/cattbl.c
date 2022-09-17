/*
 * Copyright © 2014 IIMarckus <imarckus@gmail.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED “AS IS” AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <err.h>
#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
putuint32BE(uint32_t n, FILE *f)
{
	fputc(n >> 24, f);
	fputc(n >> 16, f);
	fputc(n >> 8, f);
	fputc(n, f);
}

int
main(int argc, char *argv[])
{
	bool efflag, sameptrflag;
	int i, runsum, numptrs;
	long size;
	uint32_t *ptrs, *runsums;
	FILE **f;
	uint8_t buf[8192];
	char *ep;

	if (argc < 3) {
		errx(1, "Usage: cattbl [-fx] size file ...");
	}

	if (strcmp(argv[1], "-f") == 0) {
		efflag = true;
		argv += 1;
		argc -= 1;
	} else {
		efflag = false;
	}

	if (strcmp(argv[1], "-x") == 0) {
		sameptrflag = true;
		argv += 1;
		argc -= 1;
	} else {
		sameptrflag = false;
	}

	if (strcmp(argv[1], "-fx") == 0) {
		sameptrflag = true;
		efflag = true;
	}

	size = strtol(argv[1], &ep, 0);
	if (argv[1][0] == '\0' || *ep != '\0') {
		errx(1, "invalid size '%s'", argv[1]);
	}
	if (errno == ERANGE && (size == LONG_MAX || size == LONG_MIN)) {
		errx(1, "invalid size '%s'", argv[1]);
	}

	argc -= 2;
	argv += 2;

	f = reallocarray(NULL, argc, sizeof *f);
	ptrs = reallocarray(NULL, argc, sizeof *ptrs);
	runsums = reallocarray(NULL, argc, sizeof *runsums);
	numptrs = 0;

	if (efflag) {
		putuint32BE(0xef, stdout);
	} else {
		putuint32BE(0, stdout);
	}
	putuint32BE(0, stdout);

	runsum = 16 + 16 * (argc);
	for (i = 0; i < argc; ++i) {
		if (sameptrflag && i > 0 && strcmp(argv[i], argv[i - 1]) == 0)
		    {
			runsums[i] = runsums[i - 1];
			ptrs[i] = ptrs[i - 1];
			continue;
		}
		f[i] = fopen(argv[i], "rb");
		if (f[i] == NULL) {
			err(1, "Could not open file '%s'", argv[i]);
		}
		fseek(f[i], 0, SEEK_END);
		runsums[i] = runsum;
		runsum += ftell(f[i]);
		while (runsum % 16) {
			++runsum;
		}
		ptrs[i] = ftell(f[i]);
		fseek(f[i], 0, SEEK_SET);
	}
	putuint32BE(runsum, stdout);
	putuint32BE(argc, stdout);
	for (i = 0; i < argc; ++i) {
		while (ptrs[i] % 16) {
			++ptrs[i];
		}
		putuint32BE(runsums[i], stdout);
		putuint32BE(ptrs[i], stdout);
		putuint32BE(0, stdout);
		putuint32BE(0, stdout);
	}

	for (i = 0; i < argc; ++i) {
		if (sameptrflag && i > 0 && strcmp(argv[i], argv[i - 1]) == 0)
		    {
			continue;
		}
		size_t n;

		while ((n = fread(buf, sizeof *buf, sizeof buf, f[i])) > 0)
			if (fwrite(buf, sizeof *buf, n, stdout) != n)
				;
		while (ftell(stdout) % 16) {
			fputc(0xff, stdout);
		}
	}

	int padspace;
	padspace = size - ftell(stdout);
	for (i = 0; i < sizeof buf; ++i) {
		buf[i] = 0xff;
	}
	while (padspace > sizeof buf) {
		fwrite(buf, sizeof *buf, sizeof buf, stdout);
		padspace -= sizeof buf;
	}
	fwrite(buf, sizeof *buf, padspace, stdout);

	return 0;
}
