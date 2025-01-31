#include <stdio.h>
float celsius(float fahrenheit);
int main() {
    float fahrenheit;
    // Complete the code
    scanf("%f",&fahrenheit);
    printf("%f",celsius(fahrenheit));
    return 0;
}

float celsius(float fahrenheit)
{
    return (fahrenheit-32)*(5.0/9.0);
}