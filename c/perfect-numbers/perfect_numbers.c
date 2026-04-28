#include "perfect_numbers.h"

kind classify_number(int number) {
    if (number < 1)
        return ERROR;
    if (number == 1)
        return DEFICIENT_NUMBER;
    int sum = 1;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            sum += i;
            if (i != number / i)
                sum += number / i;
        }
    }
    if (number == sum)
        return PERFECT_NUMBER;
    return (sum > number) ? ABUNDANT_NUMBER : DEFICIENT_NUMBER;
}