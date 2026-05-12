#include "sieve.h"
#include <stdbool.h>
#include <stdlib.h>

#define SET_BIT(A, k) (A[(k) >> 3] |= 1U << ((k) & 7))
// these work since it's all bitwise. >> 3 is the same as / 8 and & 7 is the same as % 8
#define GET_BIT(A, k) (A[(k) >> 3] & 1U << ((k) & 7))

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes) {
    if (limit < 2 || max_primes == 0)
        return 0;
    uint8_t *marked = calloc((limit / 8 + 1), sizeof(uint8_t));
    if (!marked)
        return 0;
    size_t count = 1;
    primes[0] = 2;
    for (uint32_t i = 3; i <= limit; i += 2) {
        if (GET_BIT(marked, i))
            continue;
        primes[count] = i;
        count++;
        if (count == max_primes)
            break;
        if (i <= limit / i) {
            for (uint32_t mult = i * i; mult <= limit; mult += (i << 1))
                // can skip odd i values since odd + odd = even and we don't check evens
                SET_BIT(marked, mult);
        }
    }
    free(marked);
    return (uint32_t) count;
}
