.n64
.open "baserom.n64","pokestadium.n64",0

; moves legality checker
.orga 0x2ecb38
	or v0, s4, r0
	lbu v1, 0x000a (v0) ; load starting move in v1
	addiu s0, s0, 1
	slti at, s0, 4 ; set at to 1 if four moves haven't been checked yet
	beq v1, r0, 0x2ecb64
	nop

.close
