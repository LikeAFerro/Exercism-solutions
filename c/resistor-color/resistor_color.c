#include "resistor_color.h"

int color_code(resistor_band_t color) {
    // automatically converted to int, value matches order in enumeration
    return color;
}

resistor_band_t *colors(void) {
    // declaring a static array lets me return it, otherwise it would stop
    // existing when the function ends
    static resistor_band_t ret[] = {BLACK, BROWN, RED,    ORANGE, YELLOW,
                                    GREEN, BLUE,  VIOLET, GREY,   WHITE};
    return ret;
}