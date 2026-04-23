#include "eliuds_eggs.h"

unsigned int egg_count(int code) {
    unsigned int count = 0, n = (unsigned int) code;
    while (n > 0) {
        n &= (n - 1); // Extinguish the rightmost set bit
        count++;
    }
    return count;
}