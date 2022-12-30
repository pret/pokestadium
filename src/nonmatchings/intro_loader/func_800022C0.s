.section .text
glabel func_800022C0
/* 2EC0 800022C0 27BDFFE8 */  addiu      $sp, $sp, -0x18
/* 2EC4 800022C4 AFA5001C */  sw         $a1, 0x1C($sp)
/* 2EC8 800022C8 8FB9001C */  lw         $t9, 0x1C($sp)
/* 2ECC 800022CC 3C05800A */  lui        $a1, %hi(D_800A6070)
/* 2ED0 800022D0 24A56070 */  addiu      $a1, $a1, %lo(D_800A6070)
/* 2ED4 800022D4 2403FFF0 */  addiu      $v1, $zero, -0x10
/* 2ED8 800022D8 248E000F */  addiu      $t6, $a0, 0xF
/* 2EDC 800022DC 01C37824 */  and        $t7, $t6, $v1
/* 2EE0 800022E0 25F80010 */  addiu      $t8, $t7, 0x10
/* 2EE4 800022E4 03234024 */  and        $t0, $t9, $v1
/* 2EE8 800022E8 2509FFF0 */  addiu      $t1, $t0, -0x10
/* 2EEC 800022EC 01385823 */  subu       $t3, $t1, $t8
/* 2EF0 800022F0 270CFFF0 */  addiu      $t4, $t8, -0x10
/* 2EF4 800022F4 AFBF0014 */  sw         $ra, 0x14($sp)
/* 2EF8 800022F8 ACB80020 */  sw         $t8, 0x20($a1)
/* 2EFC 800022FC ACA90024 */  sw         $t1, 0x24($a1)
/* 2F00 80002300 ACAB001C */  sw         $t3, 0x1C($a1)
/* 2F04 80002304 ACA00030 */  sw         $zero, 0x30($a1)
/* 2F08 80002308 ACAC0028 */  sw         $t4, 0x28($a1)
/* 2F0C 8000230C AD800000 */  sw         $zero, 0x0($t4)
/* 2F10 80002310 8CAE0028 */  lw         $t6, 0x28($a1)
/* 2F14 80002314 3C04800A */  lui        $a0, %hi(D_800A6074)
/* 2F18 80002318 24846074 */  addiu      $a0, $a0, %lo(D_800A6074)
/* 2F1C 8000231C ADC00004 */  sw         $zero, 0x4($t6)
/* 2F20 80002320 8CAF0028 */  lw         $t7, 0x28($a1)
/* 2F24 80002324 24060001 */  addiu      $a2, $zero, 0x1
/* 2F28 80002328 ADE00008 */  sw         $zero, 0x8($t7)
/* 2F2C 8000232C 8CB80028 */  lw         $t8, 0x28($a1)
/* 2F30 80002330 AF00000C */  sw         $zero, 0xC($t8)
/* 2F34 80002334 8CB90024 */  lw         $t9, 0x24($a1)
/* 2F38 80002338 ACB9002C */  sw         $t9, 0x2C($a1)
/* 2F3C 8000233C AF200000 */  sw         $zero, 0x0($t9)
/* 2F40 80002340 8CA9002C */  lw         $t1, 0x2C($a1)
/* 2F44 80002344 AD200004 */  sw         $zero, 0x4($t1)
/* 2F48 80002348 8CAA0028 */  lw         $t2, 0x28($a1)
/* 2F4C 8000234C AD400008 */  sw         $zero, 0x8($t2)
/* 2F50 80002350 8CAB0028 */  lw         $t3, 0x28($a1)
/* 2F54 80002354 0C0178E8 */  jal        osCreateMesgQueue
/* 2F58 80002358 AD60000C */   sw        $zero, 0xC($t3)
/* 2F5C 8000235C 3C04800A */  lui        $a0, %hi(D_800A6074)
/* 2F60 80002360 24846074 */  addiu      $a0, $a0, %lo(D_800A6074)
/* 2F64 80002364 00002825 */  or         $a1, $zero, $zero
/* 2F68 80002368 0C015A30 */  jal        osSendMesg
/* 2F6C 8000236C 00003025 */   or        $a2, $zero, $zero
/* 2F70 80002370 8FBF0014 */  lw         $ra, 0x14($sp)
/* 2F74 80002374 27BD0018 */  addiu      $sp, $sp, 0x18
/* 2F78 80002378 03E00008 */  jr         $ra
/* 2F7C 8000237C 00000000 */   nop

