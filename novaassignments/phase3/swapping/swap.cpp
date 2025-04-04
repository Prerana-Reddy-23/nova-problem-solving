#include "swap.h"


void swap_integers(int& a, int& b) {
   
    int temp = a;
    a = b;
    b = temp;
}