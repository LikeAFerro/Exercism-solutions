#include "isogram.h"
#include <ctype.h>
#include <stddef.h>
#include <stdint.h>

bool is_isogram(const char phrase[]) {
    if (!phrase)
        return false;
    int32_t letters = 0;
    for (size_t i = 0; phrase[i] != '\0'; i++) {
        if (isalpha((unsigned char) phrase[i])) {
            int8_t index = toupper((unsigned char) phrase[i]) - 'A';
            if (letters & (1 << index))
                return false;
            letters |= 1 << index;
        } else if (phrase[i] != ' ' && phrase[i] != '-')
            return false;
    }
    return true;
}