#ifndef _HAL_LIBC_
#define _HAL_LIBC_

char* HAL_Strcpy(char* dest, char* src);
char* HAL_Strcpy2(char *dest, char* src);
size_t HAL_Strcmp(char* dest, char* src);
char* HAL_Memset(char* dest, s32 c, s32 nsize);

#endif // _HAL_LIBC_
