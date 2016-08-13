	.dw 0x80371240                ; initial PI_BSD_DOM1 register values
	.dw 0xF                       ; clock rate (default)
	.dw 0x80100400                ; entry point
	.dw 0x144C                    ; release
	.dw 0x03571182                ; checksum 1
	.dw 0x892FD06D                ; checksum 2
	.fill 8                       ; unknown
	.ascii "POKEMON STADIUM 2   " ; game name
	.fill 4                       ; unknown
	.dw "N"                       ; format (cartridge)
	.ascii "P3"                   ; game ID
	.ascii "E"                    ; region (North America)
	.db 0x00                      ; version
