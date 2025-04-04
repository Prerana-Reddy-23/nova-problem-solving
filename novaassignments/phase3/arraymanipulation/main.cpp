#include <iostream>
#include "string.h" 
int main() {
  
    char userString[MAX_STRING_SIZE];

   
    std::cout << "Enter a string (max " << MAX_STRING_SIZE - 1 << " characters): ";
    readString(userString, MAX_STRING_SIZE);

    std::cout << "\nOriginal string: [" << userString << "]" << std::endl;

  
    toUpperCase(userString);
    std::cout << "After converting to uppercase: [" << userString << "]" << std::endl;

  
    removeVowels(userString);
    std::cout << "After removing vowels: [" << userString << "]" << std::endl;

   
    reverseString(userString);
    std::cout << "After reversing: [" << userString << "]" << std::endl;

   
    std::cout << "\nFinal modified string: [" << userString << "]" << std::endl;

    return 0; 
}