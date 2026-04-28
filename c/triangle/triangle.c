#include "triangle.h"
#include <math.h>
#define EPSILON 1e-9

static bool sides_equal(double s1, double s2) { return fabs(s1 - s2) < EPSILON; }

// each side needs to be > 0 and < the sum of the other two sides
bool is_triangle(triangle_t triangle) {
    return triangle.a < triangle.b + triangle.c && triangle.b < triangle.a + triangle.c &&
           triangle.c < triangle.a + triangle.b && triangle.a > 0 && triangle.b > 0 &&
           triangle.c > 0;
}

bool is_equilateral(triangle_t triangle) {
    return is_triangle(triangle) && sides_equal(triangle.a, triangle.b) &&
           sides_equal(triangle.a, triangle.c);
}

bool is_isosceles(triangle_t triangle) {
    return is_triangle(triangle) &&
           (sides_equal(triangle.a, triangle.b) || sides_equal(triangle.a, triangle.c) ||
            sides_equal(triangle.b, triangle.c));
}

bool is_scalene(triangle_t triangle) { return is_triangle(triangle) && !is_isosceles(triangle); }