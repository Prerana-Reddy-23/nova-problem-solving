#include <stdio.h>

int main() {
    int size;
    scanf("%d", &size);

    // Loop for each test case
    while (size--) {
        int input1, input2;
        scanf("%d %d", &input1, &input2);

        // Your code for each test case goes here 
        if(input1+input2<=6)
        {
            printf("NO\n");
        }
        else
            printf("YES\n");
    }
}
