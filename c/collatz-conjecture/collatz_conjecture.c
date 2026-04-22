#include "collatz_conjecture.h"

int steps(int start){
    int count = 0;
    if(start > 0){
        while(start != 1){
        start = (start % 2 == 0) ? start / 2 : start * 3 + 1;
        count++;
        }
    }
    else
        count = -1;
    return count;
}