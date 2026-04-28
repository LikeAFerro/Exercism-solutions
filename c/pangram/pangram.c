#include "pangram.h"
#include <ctype.h>
#include <stdint.h>
#include <string.h>

bool is_pangram(const char *sentence) {
    if (!sentence)
        return false;
    int32_t alphabet = 0;
    for (size_t i = 0; sentence[i] != '\0'; i++) {
        if (isalpha((unsigned char) sentence[i])) {
            int index = tolower((unsigned char) sentence[i]) - 'a';
            // every bit represents a letter, Z to A (left to right). 3FFFFF is 26 1s (binary) in
            // HEX
            alphabet |= (1 << index);
            if (alphabet == 0x3FFFFFF)
                return true;
        }
    }
    return false;
}