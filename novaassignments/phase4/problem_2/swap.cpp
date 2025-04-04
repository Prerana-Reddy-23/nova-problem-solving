#include "swap.h"

void swapIntegers(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}