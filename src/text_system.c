#include "text_system.h"
#include "src/jpeg_stream.h"
#include "src/memory.h"

#define D_800AF740_NUM_FILES 42

static BinArchive* gTextArchive;
static char** gTextTokenTable;

void Text_InitStringTables(void) {
    s32 i;

    gTextArchive = BinArchive_Open(textdata_ROM_START, NULL, 1, 0);
    gTextTokenTable = main_pool_alloc(D_800AF740_NUM_FILES * sizeof(char*), 0);

    for (i = 0; i < D_800AF740_NUM_FILES; i++) {
        gTextTokenTable[i] = NULL;
    }
}

char** Text_GetStringTable(s32 file_number) {
    return (char**)BinArchive_GetFile(gTextArchive, file_number);
}

void Text_SetStringToken(u32 arg0, u32 arg1) {
    if ((arg0 >= 0x14) && (arg0 < 0x2A)) {
        gTextTokenTable[arg0] = (char*)arg1;
    }
}

void Text_SetNumberToken(u32 arg0, u32 arg1) {
    if ((arg0 != 0) && (arg0 < 0xA)) {
        gTextTokenTable[arg0] = (char*)arg1;
    }
}

void Text_SubstituteTokens(char* text, u32 text_length, s8* token) {
    u32 i;
    s32 in_replace_mode;
    s32 current_char;
    char text_buffer[12];
    s8* replacement;
    char* sp54;
    u32 written_count;

    in_replace_mode = 0;
    written_count = 0;
    sp54 = replacement;
    replacement = sp54;
    i = 0;

    while (i < text_length - 1u) {
        switch (in_replace_mode) {
            case 0:
                current_char = *token++;
                if (current_char == '\x00') {
                    goto end;
                }

                if (current_char == '#') {
                    current_char = *token++;

                    current_char -= '0';
                    current_char = (*token++ + (current_char * 10)) - '0';
                    if ((current_char > 0) && (current_char < 10)) {
                        sprintf(text_buffer, "%d", gTextTokenTable[current_char]);
                        replacement = text_buffer;
                        in_replace_mode = 1;
                        continue;
                    }

                    if ((current_char >= 0x14) && (current_char < 0x2A)) {
                        if (gTextTokenTable[current_char] != NULL) {
                            replacement = gTextTokenTable[current_char];
                            in_replace_mode = 1;
                        }
                        continue;
                    }
                } else {
                    *text++ = current_char;
                    written_count++;
                    i++;
                }
                break;

            case 1:
                current_char = *replacement++;
                if (current_char == '\x00') {
                    in_replace_mode = 0;
                } else {
                    *text++ = current_char;
                    written_count++;
                    i++;
                }
                break;
        }
    }

end:
    *text++ = '\x00';
}

char* Text_GetString(char* text, s32 text_length, char** string_array, u32 file_number) {
    char* string;
    char* string_array_lookup = (u32)string_array + (u32)string_array[file_number + 1];

    if (text == NULL) {
        string = string_array_lookup;
    } else {
        string = text;
        Text_SubstituteTokens(text, text_length, string_array_lookup);
    }

    return string;
}

s32 Text_CountLines(s8* arg0) {
    s32 last_chr = 0;
    s32 line_count = 0;
    s32 chr = *arg0++;

    while (chr != 0) {
        last_chr = chr;
        if (chr == '\n') {
            line_count++;
        }
        chr = *arg0++;
    }

    if (last_chr != '\n') {
        line_count++;
    }

    return line_count;
}
