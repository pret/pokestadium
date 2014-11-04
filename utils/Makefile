BINARIES = \
	extractstrtbltbl \
	extractrostertbltbl \
	txt2strtbl \
	cattbl \
	json2rostertbl \
	extractbin

all: ${BINARIES}

json2rostertbl: json2rostertbl.c constants.h
	cc `pkg-config --cflags --libs json-c` -o $@ json2rostertbl.c

clean:
	rm -f ${BINARIES}
