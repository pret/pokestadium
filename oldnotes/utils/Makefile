BINARIES = \
	extractstrtbltbl \
	extractrostertbltbl \
	txt2strtbl \
	cattbl \
	json2rostertbl \
	extractbin \
	face2png \
	padff \
	presjpeg

all: ${BINARIES}

json2rostertbl: json2rostertbl.c constants.h
	cc `pkg-config --cflags --libs json-c` -o $@ json2rostertbl.c

face2png: face2png.c
	cc `pkg-config --cflags --libs libpng` -o $@ face2png.c

presjpeg: presjpeg.c
	cc -I/usr/local/include -L/usr/local/lib -ljpeg -o $@ presjpeg.c

clean:
	rm -f ${BINARIES}
