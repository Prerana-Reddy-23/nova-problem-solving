#include <stdbool.h>
#include <stdio.h>

int main() {
    int input_number;
    scanf("%d",&input_number);
    int count = 0;
    if (input_number <= 1)
        printf("NO");
    else {
        for (int index = 1; index <= input_number; index++) {

            if (input_number % index == 0)
                count++;
        }
        if (count > 2)
            printf("NO");
        else
            printf("YES");
    }

    return 0;
}
