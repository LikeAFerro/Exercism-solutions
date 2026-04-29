#include "clock.h"
#include <stdio.h>
#include <string.h>

static void clock_parse(char *text, int *hour, int *minute) { sscanf(text, "%d:%d", hour, minute); }

clock_t clock_create(int hour, int minute) {
    clock_t clock;

    int totmins = (hour * 60 + minute) % 1440;
    if (totmins < 0)
        totmins += 1440; // minutes in 24 hours
    snprintf(clock.text, MAX_STR_LEN, "%02d:%02d", totmins / 60, totmins % 60);

    return clock;
}

clock_t clock_add(clock_t clock, int minute_add) {
    int hour, minute;
    clock_parse(clock.text, &hour, &minute);
    return clock_create(hour, minute + minute_add);
}

clock_t clock_subtract(clock_t clock, int minute_subtract) {
    int hour, minute;
    clock_parse(clock.text, &hour, &minute);
    return clock_create(hour, minute - minute_subtract);
}

bool clock_is_equal(clock_t a, clock_t b) {
    int hour, minute;
    clock_parse(a.text, &hour, &minute);
    a = clock_create(hour, minute);
    clock_parse(b.text, &hour, &minute);
    b = clock_create(hour, minute);
    return strcmp(a.text, b.text) == 0;
}