#ifndef _2E110_H_
#define _2E110_H_

#include "global.h"

void Text_InitStringTables(void);
char** Text_GetStringTable(s32 file_number);
void Text_SetStringToken(u32 arg0, u32 arg1);
void Text_SetNumberToken(u32 arg0, u32 arg1);
void Text_SubstituteTokens(char* text, u32 text_length, s8* token);
char* Text_GetString(char* text, s32 text_length, char** string_array, u32 file_number);
s32 Text_CountLines(s8* arg0);

#endif // _2E110_H_
