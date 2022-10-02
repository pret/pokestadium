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

/*
 * Dump a table of files to individual binary files.
 */

#include <err.h>
#include <errno.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* 0x1708000 in Stadium GS */

uint32_t
getint32BE(FILE *f)
{
	uint32_t n;
	n  = fgetc(f) << 24;
	n |= fgetc(f) << 16;
	n |= fgetc(f) << 8;
	n |= fgetc(f);

	return n;
}

int
main(int argc, char *argv[])
{
	FILE *rom;
	FILE *outfile;
	uint32_t ntables, nentries;
	uint32_t *tableptrs, *sizes;
	int i, x, table, entry;
	char outfilename[16];
	char *ep;
	unsigned long long dataoff;

	if (argc != 3) {
		errx(1, "Usage: extractbin file offset");
	}

	rom = fopen(argv[1], "rb");
	if (rom == NULL) {
		err(1, "Error opening file '%s'", argv[1]);
	}

	dataoff = strtoull(argv[2], &ep, 0);
	if (argv[2][0] == '\0' || *ep != '\0') {
		err(1, "invalid offset '%s'", argv[2]);
	}
	if (errno == ERANGE && dataoff == ULLONG_MAX) {
		err(1, "invalid offset '%s'", argv[2]);
	}
	if (dataoff > 64 * 1024 * 1024) {
		err(1, "invalid offset '%s'", argv[2]);
	}

	fseek(rom, dataoff + 0xc, SEEK_SET);
	ntables = getint32BE(rom);
	tableptrs = reallocarray(NULL, ntables, sizeof(uint32_t));
	sizes = reallocarray(NULL, ntables, sizeof(uint32_t));
	if (tableptrs == NULL || sizes == NULL) {
		err(1, "Could not allocate memory for table table");
	}

	for (i = 0; i < ntables; ++i) {
		tableptrs[i] = getint32BE(rom);
		sizes[i] = getint32BE(rom);
		getint32BE(rom);
		getint32BE(rom);
	}
	printf("%d tables\n", ntables);

	for (table = 0; table < ntables; ++table) {
		for (i = 0; i < 16; ++i) {
			fseek(rom, dataoff + tableptrs[table] + sizes[table] - i - 1, SEEK_SET);
			if (fgetc(rom) != 0xff) {
				sizes[table] -= i;
				break;
			}
		}
		fseek(rom, dataoff + tableptrs[table], SEEK_SET);
		snprintf(outfilename, sizeof outfilename, "0x%x.bin", ftell(rom));
		outfile = fopen(outfilename, "wb");

		for (i = 0; i < sizes[table]; ++i) {
			fputc(fgetc(rom), outfile);
		}
		fclose(outfile);
	}
}
