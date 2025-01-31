#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    // Your code goes here (if needed)
    if((a+b+(a*b))==111)
    {
        printf("YES");
    }
    else
        printf("NO");
    return 0;
}
