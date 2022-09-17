#include <err.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <json_tokener.h>
#include <json_util.h>

#include "constants.h"

void printpokemon(struct json_object *);

void
required8int(struct json_object *k, struct json_object *l, const char *s)
{
	if (!json_object_object_get_ex(k, s, &l)) {
		errx(1, "Needs a '%s'!", s);
	}
	fputc(json_object_get_int(l), stdout);
}

void
required8id(struct json_object *k, struct json_object *l, const char *s,
    int (*f)(const char *))
{
	if (!json_object_object_get_ex(k, s, &l)) {
		errx(1, "Needs a '%s'!", s);
	}
	fputc(f(json_object_get_string(l)), stdout);
}

void
optional8id(struct json_object *k, struct json_object *l, const char *s,
    int (*f)(const char *))
{
	if (!json_object_object_get_ex(k, s, &l)) {
		fputc(0, stdout);
	} else {
		fputc(f(json_object_get_string(l)), stdout);
	}
}

void
optional8strint(struct json_object *k, struct json_object *l, const char *s)
{
	if (!json_object_object_get_ex(k, s, &l)) {
		fputc(0, stdout);
	} else {
		char *ep;
		unsigned long x;
		x = strtoul(json_object_get_string(l), &ep, 0);
		if (json_object_get_string(l)[0] == '\0' || *ep != '\0') {
			errx(1, "invalid number for '%s'", s);
		}
		if (errno == ERANGE && x == ULONG_MAX) {
			errx(1, "invalid number for '%s'", s);
		}
		fputc(x, stdout);
	}
}

void
required16strint(struct json_object *k, struct json_object *l, const char *s)
{
	if (!json_object_object_get_ex(k, s, &l)) {
		errx(1, "Needs a '%s'!", s);
	} else {
		char *ep;
		unsigned long x;
		x = strtoul(json_object_get_string(l), &ep, 0);
		if (json_object_get_string(l)[0] == '\0' || *ep != '\0') {
			errx(1, "invalid number for '%s'", s);
		}
		if (errno == ERANGE && x == ULONG_MAX) {
			errx(1, "invalid number for '%s'", s);
		}
		fputc(x >> 8, stdout);
		fputc(x & 0xff, stdout);
	}
}

int
main(int argc, char *argv[])
{
	struct json_object *j, *k, *l;
	int len, i;

	if (argc != 2) {
		errx(1, "usage: json2rostertbl file");
	}

	j = json_object_from_file(argv[1]);

	len = json_object_array_length(j);

	if (len > 50) {
		/* rentals */
		fputc(len, stdout);
		fputc(0, stdout);
		fputc(0, stdout);
		fputc(0, stdout);
		for (i = 0; i < len; ++i) {
			printpokemon(json_object_array_get_idx(j, i));
		}
	} else {
		/* rosters */
		fputc(len, stdout);
		fputc(0, stdout);
		fputc(0, stdout);
		fputc(0, stdout);
		for (i = 0; i < len; ++i) {
			k = json_object_array_get_idx(j, i);
			required8id(k, l, "group", strtogroup);
			required8id(k, l, "trainer", strtotrainer);
			optional8strint(k, l, "unknown1");
			required8id(k, l, "text", strtotext);

			if (!json_object_object_get_ex(k, "pokemon", &l)) {
				errx(1, "Needs a pokemon!");
			}
			fputc(json_object_array_length(l), stdout);

			struct json_object *m;
			optional8strint(k, m, "unknown3");
			optional8strint(k, m, "unknown4");
			optional8strint(k, m, "unknown5");

			int z;
			struct json_object *o;
			for (z = 0; z < json_object_array_length(l); ++z) {
				printpokemon(json_object_array_get_idx(l, z));
			}
			while (z++ < 6) {
				/*
				 * XXX should create a json string for generic
				 * pokemon, parse it here, and pass it to
				 * printpokemon()
				 */
				fputc(1, stdout);
				fputc(1, stdout);
				int A;
				for (A = 0; A < 7; ++A) {
					fputc(0, stdout);
				}
				fputc(0x7f, stdout);
				for (A = 0; A < 10; ++A) {
					fputc(0, stdout);
				}
				fputc(0x67, stdout);
				fputc(0x77, stdout);
				fputc(0, stdout);
				fputc(0, stdout);
			}
		}
	}

	return 0;
}

void
printpokemon(struct json_object *k)
{
	struct json_object *l;
	required8int(k, l, "level");
	required8id(k, l, "species", strtopokemon);
	optional8id(k, l, "item", strtoitem);
	optional8strint(k, l, "unknown1");
	required8id(k, l, "move1", strtomove);
	optional8id(k, l, "move2", strtomove);
	optional8id(k, l, "move3", strtomove);
	optional8id(k, l, "move4", strtomove);
	optional8strint(k, l, "unknown2");
	optional8strint(k, l, "happiness");
	required16strint(k, l, "hp exp");
	required16strint(k, l, "attack exp");
	required16strint(k, l, "defense exp");
	required16strint(k, l, "speed exp");
	required16strint(k, l, "special exp");
	required16strint(k, l, "dvs");
	optional8strint(k, l, "unknown4");
	optional8strint(k, l, "unknown5");
}
