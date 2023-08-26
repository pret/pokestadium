#include <ultra64.h>
#include <string.h>
#include "hal_libc.h"

/*
 * Strcpy implementation; copy the strings terminated by 0. Return the original dest
 * pointer.
 */
char* HAL_Strcpy(char* dest, char* src) {
    char *newDest = dest;
    while ((*(newDest++) = *(src++)) != '\0') {
    }
    return dest;
}

/*
 * Alternate strcpy implementation; return the post-increment altered dest pointer.
 */
char* HAL_Strcpy2(char *dest, char* src) {
    UNUSED size_t c = strlen(dest); // this is completely pointless. the strlen func called
                                    // doesnt alter the pointer.
    while ((*(dest++) = *(src++)) != '\0') {
    }
    return dest;
}

/*
 * Strcmp implementation. Compare two strings, terminated by 0. Return a 0 if success, return
 * a positive value if the 2nd string is "greater" than the 1st, and vice versa.
 */
size_t HAL_Strcmp(char* dest, char* src) {
    int c1 = *dest;
    int c2 = *src;
    // while the string values are the same...
    while (c1 == c2) {
        // ...once we hit a 0 terminator, we've reached the end of the strings.
        // Return a success.
        if (c1 == '\0') {
            return 0;
        }
        // Increment the strings and update the content values for comparison.
        c1 = *++dest;
        c2 = *++src;
    }
    // depending on where the mismatch occured, this subtraction operation
    // will result in the correctly expected sign for whichever string is
    // "greater".
    return c1-c2;
}

/*
 * Memset implementation. Given a value, set each byte in the given pointer to
 * this value for every byte across a given specified size. Return the original
 * pointer used.
 */
char* HAL_Memset(char* dest, s32 c, u32 nsize) {
    char* newDest = dest;

    // While the size is not 0, keep decrementing.
    while( nsize --> 0 ) {
        *newDest++ = c;
    }
    return dest;
}
