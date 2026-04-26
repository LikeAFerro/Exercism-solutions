#include "gigasecond.h"

void gigasecond(time_t input, char *output, size_t size) {
    time_t after = input + 1000000000;
    struct tm *time_after = gmtime(&after);
    strftime(output, size, "%Y-%m-%d %H:%M:%S", time_after);
}

/* MANUAL MATH WAY
// #include <stdint.h>
// #include <stdio.h>
bool leap_year(int year) { return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)); }

void gigasecond(time_t input, char *output, size_t size) {
    static const time_t seconds_in_day = 86400; // 60 * 60 * 24
    static const uint16_t days_in_months[2][12] = {
        {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334},
        {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335}};
    time_t after = input + 1000000000;
    time_t year = 1970;
    while (after >= seconds_in_day * 366) {
        after -= (leap_year(year)) ? 366 * seconds_in_day : 365 * seconds_in_day;
        year++;
    }
    if (after >= seconds_in_day * 365) {
        year++;
        after -= 365 * seconds_in_day;
    }
    time_t month = 1;
    while (after >= seconds_in_day * days_in_months[leap_year(year)][month]) {
        month++;
    }
    after -= seconds_in_day * days_in_months[leap_year(year)][month - 1];
    time_t day = after / 86400 + 1;
    after %= 86400;
    time_t hours = after / 3600;
    after %= 3600;
    time_t minutes = after / 60;
    time_t seconds = after % 60;

    snprintf(output, size, "%ld-%02ld-%02ld %02ld:%02ld:%02ld", (long) year, (long) month,
             (long) day, (long) hours, (long) minutes, (long) seconds);
}*/