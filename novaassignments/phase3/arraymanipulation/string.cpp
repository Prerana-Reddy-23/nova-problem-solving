#include "string.h"
#include <iostream> 
#include <cctype>   
#include <cstring>  
#include <algorithm> 
#include <limits>  
void readString(char* str, size_t maxSize) {
    if (maxSize == 0 || str == nullptr) {
        std::cerr << "Error: Invalid buffer provided to readString." << std::endl;
        return;
    }
    
    std::cin.getline(str, maxSize);

   
    if (std::cin.fail() && !std::cin.eof()) {
         std::cerr << "Warning: Input exceeded buffer size (" << maxSize - 1
                   << " chars). Truncated." << std::endl;
         std::cin.clear(); 
         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}



bool isVowel(char c) {
    char lowerC = std::tolower(static_cast<unsigned char>(c)); 
    return (lowerC == 'a' || lowerC == 'e' || lowerC == 'i' || lowerC == 'o' || lowerC == 'u');
}


void toUpperCase(char* str) {
    if (str == nullptr) return;
    for (int i = 0; str[i] != '\0'; ++i) {
        str[i] = std::toupper(static_cast<unsigned char>(str[i]));
    }
}


void removeVowels(char* str) {
    if (str == nullptr) return;

    int writeIndex = 0; 
    for (int readIndex = 0; str[readIndex] != '\0'; ++readIndex) {
        
        if (!isVowel(str[readIndex])) {
            
            str[writeIndex] = str[readIndex];
          
            writeIndex++;
        }
        
    }
    
    str[writeIndex] = '\0';
}


void reverseString(char* str) {
     if (str == nullptr) return;
    size_t length = std::strlen(str);
    if (length <= 1) {
        return; 
    }

    size_t start = 0;
    size_t end = length - 1;

    while (start < end) {
        
        std::swap(str[start], str[end]);
        
        start++;
        end--;
    }
}