#include "luhn.h"
#include <ctype.h>
#include <string.h>

bool luhn(const char *num) {
    if (!num)
        return false;
    int len = strlen(num);
    int sum = 0, digits = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == ' ')
            continue;
        if (!isdigit(num[i]))
            return false;
        digits++;
        int digit = (num[i] - '0');
        if (digits % 2 == 0) {
            digit *= 2;
            if (digit > 9)
                digit -= 9;
        }
        sum += digit;
    }
    return sum % 10 == 0 && digits > 1;
}