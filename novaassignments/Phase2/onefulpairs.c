#include <stdio.h>

int main() {
    int input1, input2;
    scanf("%d %d", &input1, &input2);
    // Your code goes here (if needed)
    if((input1+input2+(input1*input2))==111)
    {
        printf("YES");
    }
    else
        printf("NO");
    return 0;
}
