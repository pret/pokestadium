text/ is done.

rosters/ is done.

rentals/ is done.

backgrounds/ is done.

academygfx/ is done.

(but for all of the above, some files could use better names)

Todo:

0x1718000/:

* what is this?

0x1898000/:

* what is this?

0x1e40000/:

* this is references to logos and other texts. what is the format?

0x2000000/:

* what is this?
* answer: .pers.szp, containing yay0, containing FRAGMENT
* but what is it?

faces/:

* have been dumped to png
* need to write a converter from png

0x3fd5000/:

* contains .pers.szp files that in turn contain yay0-compressed data
* these have been decompressed into the .bin files. but what is their format?
* need to write a yay0/pers-szp compressor/decompressor

0x3fed000/:

* just one file
* looks like 253 entries, 16 bytes per entry
* 253 is awfully close to 251
* so it probably has something to do with pokémon species

There is a table at 0x04377d0 (contains .pers-szp containing yay0)

There is a table at 0x04494c0 (contains .pers-szp containing yay0)

There is a table at 0x1638000 (contains .pers-szp containing yay0)
