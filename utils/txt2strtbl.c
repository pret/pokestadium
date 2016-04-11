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

/*
 * string table format:
 * 32-bit pointers to each string, relative to the start of the table
 * strings
 * 0xff for padding to nearest 16-byte boundary
 */

void
putuint32BE(uint32_t n, FILE *f)
{
	fputc(n >> 24, f);
	fputc(n >> 16, f);
	fputc(n >> 8, f);
	fputc(n, f);
}

/* transform a blank line-delimited record into a null-terminated string. */
char *
getrecord(FILE *f)
{
	int x;
	char *s;
	int len;

	s = malloc(500);
	len = 0;

	for (;;) {
		x = fgetc(f);
		/*
		 * UTF-8 characters are mapped as follows:
		 *
		 *     ¥ → 0xa5
		 *     ♂ → 0xa9
		 *     ° → 0xba
		 *     · → 0xb7
		 *     ♀ → 0xbe
		 *     × → 0xd7
		 *     é → 0xe9
		 */
		if (x == -1) {
			return NULL;
		} else if (x == '@') {
			s[len++] = '\n';
		} else if (x == 0xe2) {
			x = fgetc(f);
			if (x != 0x99) {
				errx(1, "Bad input char 0x%x", x);
			}
			x = fgetc(f);
			if (x == 0x82) {
				s[len++] = '\xa9';
			} else if (x == 0x80) {
				s[len++] = '\xbe';
			} else {
				errx(1, "Bad input char 0x%x", x);
			}
		} else if (x == 0xc2) {
			x = fgetc(f);
			if (x == 0xa5) {
				s[len++] = '\xa5';
			} else if (x == 0xb7) {
				s[len++] = '\xb7';
			} else {
				errx(1, "Bad input char 0x%x", x);
			}
		} else if (x == 0xc3) {
			x = fgetc(f);
			if (x == 0xa9) {
				s[len++] = '\xe9';
			} else if (x == 0x97) {
				s[len++] = '\xd7';
			} else {
				errx(1, "Bad input char 0x%x", x);
			}
		} else if (x == '\n') {
			x = fgetc(f);
			if (x == '\n' || x == -1) {
				/* end of string */
				s[len++] = '\0';
				return s;
			} else {
				ungetc(x, f);
				s[len++] = '\n';
			}
		} else {
			s[len++] = x;
		}
	}
}

int
main(int argc, char *argv[])
{
	FILE *f;
	char **s;
	uint32_t *lengths;
	int i, x, count, arrcount, numstrings, runsum;
	uint8_t *arr;
	char *t;

	if (argc != 2) {
		errx(1, "Usage: txt2strtbl file");
	}

	f = fopen(argv[1], "rb");
	if (f == NULL) {
		err(1, "Error opening file '%s'", argv[1]);
	}

	/*
	 * 2500 is a decent enough default.
	 * There are no string tables that big.
	 */
	s = reallocarray(NULL, sizeof *s, 2500);
	lengths = reallocarray(NULL, sizeof *lengths, 2500);
	if (s == NULL || lengths == NULL) {
		err(1, "could not allocate memory");
	}

	numstrings = 0;
	while ((t = getrecord(f)) != NULL) {
		s[numstrings] = t;
		lengths[numstrings] = strlen(t);
		numstrings++;
	}

	putuint32BE(numstrings, stdout);
	runsum = 4 + sizeof(uint32_t) * numstrings;
	for (i = 0; i < numstrings; ++i) {
		putuint32BE(runsum, stdout);
		runsum += strlen(s[i]) + 1;
	}
	for (i = 0; i < numstrings; ++i) {
		printf("%s", s[i]);
		fputc('\0', stdout);
	}

	while (runsum++ % 16) {
		fputc(0xff, stdout);
	}
}
