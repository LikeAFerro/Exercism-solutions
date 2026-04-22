#include "difference_of_squares.h"

unsigned long long sum_of_squares(unsigned int number) {
    // Formula: (n * (n + 1) * (2n + 1)) / 6
    return (unsigned long long) number * (number + 1) * (2 * number + 1) / 6;
}

unsigned long long square_of_sum(unsigned int number) {
    // Formula: (n * (n + 1) / 2)^2
    unsigned long long sum = (unsigned long long) number * (number + 1) / 2;
    return sum * sum;
}

unsigned long long difference_of_squares(unsigned int number) {
    return square_of_sum(number) - sum_of_squares(number);
}