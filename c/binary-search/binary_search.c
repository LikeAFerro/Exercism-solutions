#include "binary_search.h"
#include <stdio.h>

const int *binary_search(int value, const int *arr, size_t length) {
    if (!arr || length == 0)
        return NULL;
    size_t low = 0;
    size_t high = length - 1;
    while (low <= high) {
        size_t mid = low + (high - low) / 2;
        printf("%d\n", *(arr + mid));
        if (*(arr + mid) == value)
            return arr + mid;
        if (*(arr + mid) < value)
            low = mid + 1;
        else {
            if (mid == 0)
                break;
            high = mid - 1;
        }
    }
    return NULL;
}

/* RECURSIVE WAY
const int *binary_search(int value, const int *arr, size_t length) {
    if (length == 0)
        return NULL;
    const int *mid = arr + (int) (length / 2);
    printf("%d\n", *mid);
    if (*mid == value)
        return mid;
    if (length == 1)
        return NULL;
    return (*mid > value) ? binary_search(value, arr, mid - arr)
                          : binary_search(value, mid, length / 2 + length % 2);
}
*/