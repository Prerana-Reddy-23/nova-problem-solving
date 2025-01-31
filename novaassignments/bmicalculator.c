#include <stdio.h>
float bmi(float height,float weight);
int main() {
    float height = 1.82;
    float weight = 72.00;
    // Complete the code
    printf("%f",bmi(height,weight));
    return 0;
}
float bmi(float height,float weight)
{
    return (weight/(height*height));
}