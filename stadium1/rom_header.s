	.dw 0x80371240                ; initial PI_BSD_DOM1 register values
	.dw 0xF                       ; clock rate (default)
	.dw 0x80100400                ; entry point
	.dw 0x1449                    ; release
	.dw 0x90F5D9B3                ; checksum 1
	.dw 0x9D0EDCF0                ; checksum 2
	.fill 8                       ; unknown
	.ascii "POKEMON STADIUM     " ; game name
	.fill 4                       ; unknown
	.dw "N"                       ; format (cartridge)
	.ascii "PO"                   ; game ID
	.ascii "E"                    ; region (North America)
	.db 0x00                      ; version
