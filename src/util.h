#ifndef _UTIL_H_
#define _UTIL_H_

extern u32 gExpansionRAMStart;

uintptr_t Util_ConvertAddrToVirtAddr(uintptr_t addr);
void Util_Memcpy(u32* dest, u32* src, int size);
void Util_InitMainPools(void);
void* Util_Malloc(s32 size);
void Util_Free(void* ptr);
void Util_DrawRect(Gfx** dlist, s32 ulx, s32 lrx, u16 color);
void Util_DrawMemProfiler(Gfx** dlist);
void Util_Memclear(u64* dest, u32 size);
s32 Util_CheckStubMemArea(u64* ptr); // unused

#endif // _UTIL_H_
