#include <stdio.h>
float fahrenheit(float celsius);

int main() {
	// your code goes here
    float celsius;
    scanf("%f",&celsius);
    //printf("%f",celsius);
    float result = fahrenheit(celsius);
    printf("%f",result);

}

float fahrenheit(float celsius)
{
    float fah = (celsius*(9.0/5.0))+32;
    return fah;
}