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
	long size, cursize;
	uint32_t *ptrs, *runsums;
	FILE *f;
	uint8_t buf[8192];
	char *ep;

	if (argc != 3) {
		errx(1, "Usage: padff size file");
	}

	size = strtol(argv[1], &ep, 0);
	if (argv[1][0] == '\0' || *ep != '\0') {
		errx(1, "invalid size '%s'", argv[1]);
	}
	if (errno == ERANGE && (size == LONG_MAX || size == LONG_MIN)) {
		errx(1, "invalid size '%s'", argv[1]);
	}

	f = fopen(argv[2], "rb");
	if (f == NULL) {
		err(1, "Could not open file '%s'", argv[2]);
	}

	fseek(f, 0, SEEK_END);
	cursize = ftell(f);

	if (cursize > size) {
		errx(1, "size %d is smaller than current filesize", size);
	}

	fseek(f, 0, SEEK_SET);
	for (i = 0; i < cursize; ++i) {
		fputc(fgetc(f), stdout);
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
