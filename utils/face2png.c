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

#include <png.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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

void
printpng(uint16_t **pixels, int height, int width)
{
	png_structp png_ptr;
	png_infop info_ptr;
	int x, y;
	png_byte **row_pointers;
	int pixel_size;
	int depth;

	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL,
	    NULL);
	if (png_ptr == NULL) {
		errx(1, "Could not create PNG write struct");
	}
    
	info_ptr = png_create_info_struct(png_ptr);
	if (info_ptr == NULL) {
		png_destroy_write_struct(&png_ptr, NULL);
		errx(1, "Could not create PNG info struct");
	}
    
	if (setjmp (png_jmpbuf (png_ptr))) {
		png_destroy_write_struct(&png_ptr, &info_ptr);
		errx(1, "Internal PNG error");
	}
    
	depth = 8;
	png_set_IHDR(png_ptr, info_ptr, width, height, depth,
	    PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE,
	     PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
    
	pixel_size = 3;
	row_pointers = png_malloc(png_ptr, height * sizeof (png_byte *));
	for (y = 0; y < height; ++y) {
		png_byte *row = png_malloc(png_ptr,
		    sizeof(uint8_t) * width * pixel_size);
		row_pointers[y] = row;
		for (x = 0; x < width; ++x) {
			*row++ = (pixels[x][y] >> 11) << 3;
			*row++ = ((pixels[x][y] >> 6) & 0x1f) << 3;
			*row++ = ((pixels[x][y] >> 1) & 0x1f) << 3;
		}
	}

	png_init_io(png_ptr, stdout);
	png_set_rows(png_ptr, info_ptr, row_pointers);
	png_write_png(png_ptr, info_ptr, PNG_TRANSFORM_IDENTITY, NULL);

	for (y = 0; y < height; y++) {
		png_free(png_ptr, row_pointers[y]);
	}

	png_free(png_ptr, row_pointers);
	png_destroy_write_struct(&png_ptr, &info_ptr);
}

int
main(int argc, char *argv[])
{
	FILE *f;
	int x, y;
	uint16_t **pixels;
	int height, width;
	uint32_t nfaces;
	uint32_t *offsets;

	if (argc != 2) {
		errx(1, "Usage: face2png file");
	}

	f = fopen(argv[1], "rb");
	if (f == NULL) {
		err(1, "Could not open file '%s'", argv[1]);
	}

	height = 64;
	width = 64;

	nfaces = getint32BE(f);
	offsets = reallocarray(NULL, nfaces, sizeof *offsets);

	for (y = 0; y < nfaces; ++y) {
		offsets[y] = getint32BE(f);
	}
	for (y = 0; y < nfaces; ++y) {
		getint32BE(f);
	}

	fseek(f, offsets[nfaces - 1], SEEK_SET);

	pixels = reallocarray(NULL, width, sizeof *pixels);
	if (pixels == NULL) {
		err(1, "Could not allocate memory");
	}
	for (x = 0; x < width; ++x) {
		pixels[x] = reallocarray(NULL, height, sizeof
		    *pixels[x]);
		if (pixels[x] == NULL) {
			err(1, "Could not allocate memory");
		}
	}

	/*
	 * In the original format, on every other line, every other pair of
	 * pixels is swapped. Here we transpose it into top-bottom left-right.
	 */
	uint16_t q[4];
	for (y = 0; y < height; ++y) {
		for (x = 0; x < width; ++x) {
			if (y % 2 == 0) {
				pixels[x][y] = fgetc(f) << 8;
				pixels[x][y] |= fgetc(f);
			} else {
				q[x % 4] = fgetc(f) << 8;
				q[x % 4] |= fgetc(f);
				if (x % 4 == 3) {
					pixels[x - 3][y] = q[2];
					pixels[x - 2][y] = q[3];
					pixels[x - 1][y] = q[0];
					pixels[x][y] = q[1];
				}
			}
		}
	}

	printpng(pixels, height, width);

	fclose(f);

	return 0;
}
