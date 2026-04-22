#include "grains.h"

uint64_t square(uint8_t index) {
    // Using the left-shift operator since the nth square contains 2^(n-1) grains 
    return (index >= 1 && index <= 64) ? 1ULL << (index - 1) : 0;
}

uint64_t total(void) {
    // A uint64_t contains 64 bits. The total grains is the sum of 2^0 through 2^63,
    // which results in all 64 bits being set to 1. ~0ULL flips all bits to 1.
    return ~0ULL;
}