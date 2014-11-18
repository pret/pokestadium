text/ is done.

rosters/ is done.

rentals/ is done.


Todo:

backgrounds/ and presjpeg/:

* write a presjpeg compressor/decompressor

0x1718000/:

* what is this?

0x1898000/:

* what is this?

0x1e40000/:

* this is references to logos and other texts. what is the format?

0x2000000/:

* what is this?

faces/:

* have been dumped to png
* need to write a converter from png

0x3fd5000/:

* contains .pers.szp files that in turn contain yay0-compressed data
* what is the decompressed data?
* need to write a yay0/pers-szp compressor/decompressor

0x3fed000/:

* just one file
* looks like 253 entries, 16 bytes per entry
* 253 is awfully close to 251
* so it probably has something to do with pokémon species
