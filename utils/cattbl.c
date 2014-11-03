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
	int i, runsum, numptrs;
	uint32_t *ptrs, *runsums;
	FILE **f;
	uint8_t buf[8192];

	if (argc < 2) {
		errx(1, "Usage: cattbl file ...");
	}

	f = reallocarray(NULL, argc - 1, sizeof *f);
	ptrs = reallocarray(NULL, argc - 1, sizeof *ptrs);
	runsums = reallocarray(NULL, argc - 1, sizeof *runsums);
	numptrs = 0;

	putuint32BE(0, stdout);
	putuint32BE(0, stdout);

	runsum = 16 + 16 * (argc - 1);
	for (i = 1; i < argc; ++i) {
		f[i - 1] = fopen(argv[i], "rb");
		if (f[i - 1] == NULL) {
			err(1, "Could not open file '%s'", argv[i]);
		}
		fseek(f[i - 1], 0, SEEK_END);
		runsums[i - 1] = runsum;
		runsum += ftell(f[i - 1]);
		ptrs[i - 1] = ftell(f[i - 1]);
		fseek(f[i - 1], 0, SEEK_SET);
	}
	putuint32BE(runsum, stdout);
	putuint32BE(argc - 1, stdout);
	for (i = 0; i < argc - 1; ++i) {
		putuint32BE(runsums[i], stdout);
		putuint32BE(ptrs[i], stdout);
		putuint32BE(0, stdout);
		putuint32BE(0, stdout);
	}

	for (i = 0; i < argc - 1; ++i) {
		size_t n;

		while ((n = fread(buf, sizeof *buf, sizeof buf, f[i])) > 0)
			if (fwrite(buf, sizeof *buf, n, stdout) != n)
				;
	}
}
