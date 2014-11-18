BINARIES = \
	extractstrtbltbl \
	extractrostertbltbl \
	txt2strtbl \
	cattbl \
	json2rostertbl \
	extractbin \
	face2png \
	padff

all: ${BINARIES}

json2rostertbl: json2rostertbl.c constants.h
	cc `pkg-config --cflags --libs json-c` -o $@ json2rostertbl.c

face2png: face2png.c
	cc `pkg-config --cflags --libs libpng` -o $@ face2png.c

clean:
	rm -f ${BINARIES}
