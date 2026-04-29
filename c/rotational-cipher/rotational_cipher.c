#include "rotational_cipher.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char *rotate(const char *text, int shift_key) {
    shift_key = (shift_key % 26 + 26) % 26;
    size_t len = strlen(text);
    char *rotated = malloc(len + 1); // 1 char is exactly 1 byte, add 1 for the terminator
    if (!rotated)
        return NULL;
    for (size_t i = 0; i < len; i++) {
        if (isalpha(text[i]))
            rotated[i] = (isupper(text[i])) ? (text[i] - 'A' + shift_key) % 26 + 'A'
                                            : (text[i] - 'a' + shift_key) % 26 + 'a';
        else
            rotated[i] = text[i];
    }
    rotated[len] = '\0';
    return rotated;
}