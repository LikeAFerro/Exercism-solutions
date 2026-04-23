#include "binary.h"
#include <string.h>

int convert(const char *input) {
    if (!input || *input == '\0')
        return INVALID;
    int result = 0;
    while (*input) {
        if (*input != '1' && *input != '0')
            return INVALID;
        // shift one character to the left (multiply by 2) and bitwise or the last character (add 0
        // if 0, 1 if 1)
        result = (result << 1) | (*input - '0');
        input++;
    }
    return result;
}