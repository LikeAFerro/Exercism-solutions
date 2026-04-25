#include "resistor_color_trio.h"

resistor_value_t color_code(resistor_band_t *bands) {
    resistor_value_t result = {bands[0] * 10.0f + bands[1], OHMS};
    int exponent = bands[2];
    if (exponent > 9 || exponent < 0) {
        result.value = -1.0f;
        return result;
    }
    for (int i = 0; i < exponent; i++)
        result.value *= 10.0f;
    while (result.value >= 1000.0f) {
        result.value /= 1000.0f;
        result.unit++;
        exponent -= 3;
    }
    return result;
}