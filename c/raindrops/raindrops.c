#include "raindrops.h"
#include <stdio.h>

void convert(char result[], int drops) {
    result[0] = '\0';
    char *ptr = result;
    // sprintf returns an integer containing the number of characters successfully written to the
    // buffer ('\0' excluded)
    if (drops % 3 == 0)
        ptr += sprintf(ptr, "Pling");
    if (drops % 5 == 0)
        ptr += sprintf(ptr, "Plang");
    if (drops % 7 == 0)
        ptr += sprintf(ptr, "Plong");
    if (ptr == result)
        sprintf(result, "%d", drops);
}