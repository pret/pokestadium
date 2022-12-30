.section .text
glabel func_800025C4
/* 31C4 800025C4 27BDFFE0 */  addiu      $sp, $sp, -0x20
/* 31C8 800025C8 AFA40020 */  sw         $a0, 0x20($sp)
/* 31CC 800025CC AFBF0014 */  sw         $ra, 0x14($sp)
/* 31D0 800025D0 AFA50024 */  sw         $a1, 0x24($sp)
/* 31D4 800025D4 3C04800A */  lui        $a0, %hi(D_800A6074)
/* 31D8 800025D8 24846074 */  addiu      $a0, $a0, %lo(D_800A6074)
/* 31DC 800025DC 00002825 */  or         $a1, $zero, $zero
/* 31E0 800025E0 0C015AB4 */  jal        osRecvMesg
/* 31E4 800025E4 24060001 */   addiu     $a2, $zero, 0x1
/* 31E8 800025E8 8FA40020 */  lw         $a0, 0x20($sp)
/* 31EC 800025EC 0C0008E0 */  jal        func_80002380
/* 31F0 800025F0 8FA50024 */   lw        $a1, 0x24($sp)
/* 31F4 800025F4 3C04800A */  lui        $a0, %hi(D_800A6074)
/* 31F8 800025F8 AFA2001C */  sw         $v0, 0x1C($sp)
/* 31FC 800025FC 24846074 */  addiu      $a0, $a0, %lo(D_800A6074)
/* 3200 80002600 00002825 */  or         $a1, $zero, $zero
/* 3204 80002604 0C015A30 */  jal        osSendMesg
/* 3208 80002608 00003025 */   or        $a2, $zero, $zero
/* 320C 8000260C 8FBF0014 */  lw         $ra, 0x14($sp)
/* 3210 80002610 8FA2001C */  lw         $v0, 0x1C($sp)
/* 3214 80002614 27BD0020 */  addiu      $sp, $sp, 0x20
/* 3218 80002618 03E00008 */  jr         $ra
/* 321C 8000261C 00000000 */   nop

