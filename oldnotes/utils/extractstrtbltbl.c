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
 * Dump a table of string tables to individual text files.
 * One table per text file.
 */

#include <err.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define TEXTBASE 0x783760

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
	uint32_t ntables, nstrings;
	uint32_t *tableptrs, *stringptrs;
	int i, x, table, string;
	char outfilename[11];

	if (argc != 2) {
		errx(1, "Usage: extractstrtbltbl file");
	}

	rom = fopen(argv[1], "rb");
	if (rom == NULL) {
		err(1, "Error opening file '%s'", argv[1]);
	}

	fseek(rom, TEXTBASE + 0xc, SEEK_SET);
	ntables = getint32BE(rom);
	tableptrs = reallocarray(NULL, ntables, sizeof(uint32_t));
	if (tableptrs == NULL) {
		err(1, "Could not allocate memory for table table");
	}

	for (i = 0; i < ntables; ++i) {
		tableptrs[i] = getint32BE(rom);
		getint32BE(rom);
		getint32BE(rom);
		getint32BE(rom);
	}
	printf("%d tables\n", ntables);

	for (table = 0; table < ntables; ++table) {
		fseek(rom, TEXTBASE + tableptrs[table], SEEK_SET);
		snprintf(outfilename, sizeof outfilename, "0x%x", ftell(rom));
		outfile = fopen(outfilename, "wb");
		nstrings = getint32BE(rom);

		printf("%d strings in table %d\n", nstrings, table);

		stringptrs = reallocarray(NULL, nstrings, sizeof(uint32_t));
		if (stringptrs == NULL) {
			err(1, "Could not allocate memory for string table");
		}

		for (i = 0; i < nstrings; ++i) {
			stringptrs[i] = getint32BE(rom);
		}
		for (i = 0; i < nstrings; ++i) {
			while ((x = fgetc(rom)) != '\0') {
				if (x == '\n') {
					int y;
					y = fgetc(rom);
					ungetc(y, rom);

					if (y == '\n' || y == '\0') {
						fputc('@', outfile);
					} else {
						fputc('\n', outfile);
					}
				} else if (x == 0xa5) {
					fprintf(outfile, "\xc2\xa5");
				} else if (x == 0xa9) {
					fprintf(outfile, "\xe2\x99\x82");
				} else if (x == 0xbe) {
					fprintf(outfile, "\xe2\x99\x80");
				} else if (x == 0xb7) {
					fprintf(outfile, "\xc2\xb7");
				} else if (x == 0xd7) {
					fprintf(outfile, "\xc3\x97");
				} else if (x == 0xe9) {
					fprintf(outfile, "\xc3\xa9");
				} else {
					fputc(x, outfile);
				}
			}

			fputc('\n', outfile);
			if (i < nstrings - 1) {
				fputc('\n', outfile);
			}
		}

		fclose(outfile);
	}
}
