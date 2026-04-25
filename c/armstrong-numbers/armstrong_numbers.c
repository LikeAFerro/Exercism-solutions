#include "armstrong_numbers.h"
#include <stdint.h>

bool is_armstrong_number(int candidate) {
    if (candidate < 0) {
        return false;
    }
    int num = candidate;
    int digits = 1;
    while (num > 9) {
        digits++;
        num /= 10;
    }
    num = candidate;
    int64_t sum = 0;
    while (num > 0) {
        int digit = num % 10;
        int64_t power = 1;
        for (int i = 0; i < digits; i++) {
            power *= digit;
        }
        sum += power;
        if (sum > candidate)
            return false;
        num /= 10;
    }
    return sum == candidate;
}