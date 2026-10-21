#ifndef _FRAGMENT1_H_
#define _FRAGMENT1_H_

#include "global.h"
#include "src/gb_tower_audio.h"

// Yay0 files in fragment1_misc_yay0 (retail ROM 0xADC80), named by their retail ROM address.
// Offsets from the segment rather than fixed addresses, so they follow it when an earlier
// segment changes size.
#define D_F4130 (fragment1_misc_yay0_ROM_START + 0x464B0)
#define D_F4920 (fragment1_misc_yay0_ROM_START + 0x46CA0)
#define D_F5450 (fragment1_misc_yay0_ROM_START + 0x477D0)
#define D_FDE40 (fragment1_misc_yay0_ROM_START + 0x501C0)
#define D_102BA0 (fragment1_misc_yay0_ROM_START + 0x54F20)

// End of the D_FDE40 file, the same address as D_102BA0. A linker symbol (undefined_syms.ld)
// rather than a second macro: func_812033F4 uses both, and IDO computes one shared
// expression only once, which changes the function's code.
extern u8 D_102BA0_END[];

void GbEmu_Init(unk_D_800AA660*);
void GbEmu_RunFrame(unk_D_800AA660*);
void GbEmu_AudioVideoTick(unk_D_800AA664*);
void func_81209078();
void GbEmu_InitContext(unk_D_8122B2C0*);
s32 osGbSetNextBuffer(void*, s32);
void GbAudio_SetAlternateStreamId(s32);
u8 GbMem_ReadIoRegister(u16);
s32 GbCpu_Execute(unk_D_8122B2C0*, s32);
void GbCpu_InitOpcodeTables(unk_D_8122B2C0*, void*);
void func_81209374(s32, s16*);

#endif /* _FRAGMENT1_H_ */
