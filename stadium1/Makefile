all: text.tbl

TBLS = \
	text/0x783a50.bin \
	text/0x783e50.bin \
	text/0x784000.bin \
	text/0x784430.bin \
	text/0x7846b0.bin \
	text/0x7849b0.bin \
	text/0x785060.bin \
	text/0x7851a0.bin \
	text/0x7852f0.bin \
	text/0x7853b0.bin \
	text/pokedex.bin \
	text/movedescriptions.bin \
	text/itemdescriptions.bin \
	text/0x78f500.bin \
	text/0x78f680.bin \
	text/0x78fd40.bin \
	text/0x78fe60.bin \
	text/0x7901e0.bin \
	text/0x790210.bin \
	text/0x790380.bin \
	text/0x790560.bin \
	text/options.bin \
	text/0x790700.bin \
	text/map.bin \
	text/0x790a30.bin \
	text/gym.bin \
	text/0x790c60.bin \
	text/0x7912d0.bin \
	text/surfpikachu.bin \
	text/kidsclub.bin \
	text/0x792460.bin \
	text/0x793470.bin \
	text/0x793670.bin \
	text/tradeservice.bin \
	text/trainers1.bin \
	text/trainers2.bin \
	text/pokemon.bin \
	text/moves.bin \
	text/types.bin \
	text/items.bin \
	text/pokedex/theblankpokemon.bin \
	text/statuses.bin \
	text/0x797140.bin \
	text/0x797150.bin \
	text/0x797350.bin \
	text/credits.bin

.SUFFIXES: .txt .bin

.txt.bin:
	../utils/txt2strtbl $< > $@

# md5 of text.tbl: 6f77a5e30618d7ba211e321636fa7b25
text.tbl: ${TBLS}
	../utils/cattbl ${TBLS} > $@

clean:
	rm -f text.tbl ${TBLS}
