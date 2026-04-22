#include "hamming.h"
#include <string.h>

int compute(const char *lhs, const char *rhs) {
    if (!lhs || !rhs)
        return -1;
    int count = 0;
    size_t lenl = strlen(lhs);
    if (lenl != strlen(rhs))
        return -1;
    for (size_t i = 0; i < lenl; i++) {
        if (lhs[i] != rhs[i])
            count++;
    }
    return count;
}