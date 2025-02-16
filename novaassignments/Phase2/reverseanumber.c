#include <stdio.h>
int main() {
    
    int input_number;
    scanf("%d",&input_number);
    int reverse_number=0;
    while(input_number!=0)
    {
        int remainder = input_number%10;
        reverse_number = reverse_number*10+remainder;
        input_number=input_number/10;
    }
    printf("%d",reverse_number);
    return 0;
}