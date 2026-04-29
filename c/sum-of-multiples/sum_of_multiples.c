#include "sum_of_multiples.h"
#include <stdbool.h>
#include <stdlib.h>

unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit) {
    unsigned int sum_multiples = 0;
    bool *multiples = calloc(limit, sizeof(bool));
    if (!multiples)
        return 0;
    for (size_t i = 0; i < number_of_factors; i++) {
        if (factors[i] == 0)
            continue;
        for (unsigned int j = factors[i]; j < limit; j += factors[i]) {
            if (!multiples[j]) {
                sum_multiples += j;
                multiples[j] = true;
            }
        }
    }
    free(multiples);
    return sum_multiples;
}