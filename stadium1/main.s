.n64
.open "baserom.n64","pokestadium.n64",0

; retrieves value from count register
.orga 0x5c900
	mfc0 v0, count                  ; v0 = counter(cop0)
	jr ra
	nop
.close

; moves legality checker
.orga 0x2ecb38
	; starting moves
	or v0, s4, r0
	lbu v1, 0x000a (v0)             ; load starting move in v1
	addiu s0, s0, 1
	slti at, s0, 4                  ; set at to 1 if four moves haven't been checked yet
	beq v1, r0, 0x2ecb64
	nop
	lbu t0, 0x001f (s2)             ; load move known by the pokémon in t0
	addu t1, s3, s1
	bne v1, t0, 0x002ecb64          ; if starting move id ? known move id, branch to 0x2ecb64
	nop
	sb r0, 0x0715 (t1)
	bnez at, 0x002ecb3c             ; if the 4 starting moves have not been checked, branch to 0x2ecb3c
	addiu v0, v0, 0x0001            ; increase the starting moves pointer
	
	; level-up moves
	or s0, r0, r0
	lw v1, 0x0048 (sp)
	lbu v0, 0x0000 (v1)             ; load level-up move in v0
	addiu s0, s0, 0x0001
	beql v0, r0, 0x002ecbb0         ; if move id = 0, skip to the next move
	slti at, s0, 0x000a             ; set at to 1 if 10 moves haven't been checked yet
	lbu t2, 0x0026 (s5)
	slt at, t2, v0
	bnel at, r0, 0x002ecbb0
	slti at, s0, 0x000a             ; sets at to 1 if 10 have not been checked yet
	lbu t3, 0x000a (v1)             ; load level-up move in t3
	lbu t4, 0x001f (s2)             ; load move known by the pokémon in t4
	addu t5, s3, s1 
	bnel t3, t4, 0x002ecbb0         ; if level-up move id  known move id, skip to the next move
	slti at, s0, 0x000a
	sb r0, 0x0715 (t5)              ; set the move validity byte to 0
	slti at, s0, 0x000a
	bnez at, 0x002ecb74             ; if the 10 level-up moves have not been checked, branch to 0x2ecb74
	addiu v1, v1, 0x0001            ; increase the level-up moves pointer
	
	; 0x2ecbb8
	or s0, r0, r0
	lw v1, 0x004c (sp)
	lbu v0, 0x0000 (v1)
	addiu s0, s0, 0x0001
	beql v0, r0, 0x002ecbfc
	slti at, s0, 0x000a
	lbu t6, 0x0026 (s5)
	slt at, t6, v0
	bnel at, r0, 0x002ecbfc
	slti at, s0, 0x000a
	lbu t9, 0x001f (s2)
	addu t7, s3, s1
	bnel t8, t9, 0x002ecbfc
	slti at, s0, 0x000a
	sb r0, 0x0715 (t7)              ; set the move validity byte to 0
	slti at, s0, 0x000a
	bnez at, 0x002ecbc0
	addiu v1, v1, 0x0001
	or s0, r0, r0
	andi a0, s6, 0xffff
	or a1, s7, r0
	jal 0x04302194
.close

; PRNG
.orga 0x359fa8
	andi a0, v0, 0x0ff0             ; a0 = counter(cop0) & 0xff0
	srl a0, a0, 0x4			        ; a0 >> 4
	andi t6, a0, 0x00ff		        ; t6 = ((counter(cop0) & 0xff0) >> 4) & 0xff
	blez t6, 0x0035a01c		        ; if negative number, jump to 0x35a01c
	andi v1, a0, 0x00ff		        ; v1 = ((counter(cop0) & 0xff0) >> 4) & 0xff
	lui a3, 0x0001
	lui a2, 0x41c6
	lui a1, 0x8439
	lui a0, 0x8439
	addiu a0, a0, 0xae40		    ; a0 is a pointer to ram (0x801ae1a0)
	addiu a1, a1, 0xae3c		    ; a1 is a pointer to ram (0x801ae19c)
	ori a2, a2, 0x4e6d		        ; a2 = 0x41c64e6d
	ori a3, a3, 0x1020		        ; a3 = 0x11020
	lw t7, 0x0000 (a1)		        ; t7 = (0x801ae19c)
	lw v0, 0x0000 (a0)		        ; v0 = (0x801ae1a0)
	addiu v1, v1, 0xffff		    ; decrease v1
	multu t7, a2			        ; t7 × 0x41c64e6d
	andi t0, v0, 0x0001		        ; is v0 odd ?
	andi v1, v1, 0x00ff		        ; v1 & 0xff
	xor t1, v0, a3			        ; t1 = (0x801ae1a0) ^ 0x11020
	mflo t8				            ; t8 = t7 × 0x41c64e6d
	addiu t9, t8, 0x303b		    ; t9 = t8 + 0x303b
	beq t0, r0, 0x0035a010		    ; if v0 is even, jump to 0x35a010
	sw t9, 0x0000 (a1)		        ; store seed × 0x41c64e6d + 0x303b to (0x801ae19c)
	sw t1, 0x0000 (a0)		        ; store (0x801ae1a0) ^ 0x11020 to (0x801ae1a0)
	or v0, t1, r0			        ; v0 = (0x801ae1a0) ^ 0x11020
	srl t2, v0, 0x1			        ; t2 == v0 >> 1
	bgtz v1, 0x00359fdc		        ; as long as v1 > 0, loop to 0x359fdc
	sw t2, 0x0000 (a0)		        ; store v0 >> 1 to (0x801ae1a0)
	lui a0, 0x8439
	lui a1, 0x8439
	addiu a1, a1, 0xae3c		    ; a1 is a pointer to ram (0x801ae19c)
	addiu a0, a0, 0xae40		    ; a0 is a pointer to ram (0x801ae1a0)
	lw t4, 0x0000 (a0)		        ; load pseudo-random number 1 in t4
	lw t3, 0x0000 (a1)		        ; load pseudo-random number 2 in t3
	lw ra, 0x0014 (sp)
	addiu sp, sp, 0x0018
	xor v1, t3, t4			        ; v1 = prn1 ^ prn2
	jr ra
	andi v0, v1, 0x00ff		        ; v0 = (prn1 ^ prn2) & 0xff
.close
