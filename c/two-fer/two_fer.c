#include "two_fer.h"

void two_fer(char *buffer, const char *name) {
    /*snprintf would be better here for buffer size safety, but the function's signature doesn't
     * include the buffer's size*/
    sprintf(buffer, "One for %s, one for me.", (name) ? name : "you");
}