#include "darts.h"

uint8_t score(coordinate_t position) {
    float distance = position.x * position.x + position.y * position.y;

    if (distance > 100.0f)
        return 0;
    if (distance > 25.0f)
        return 1;
    return (distance > 1.0f) ? 5 : 10;
}