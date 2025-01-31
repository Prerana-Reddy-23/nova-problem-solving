#include <stdio.h>
int number_of_courses(int number_of_languages);
int main() {
	// your code goes here
    int number_of_languages;
    scanf("%d",&number_of_languages);
    printf("%d",number_of_courses(number_of_languages));
}

int number_of_courses(int number_of_languages)
{
    return 2*number_of_languages;
}