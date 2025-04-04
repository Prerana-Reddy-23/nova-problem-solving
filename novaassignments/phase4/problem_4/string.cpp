#include "string.h"
#include <cctype>  
#include <cstring>  
#include <algorithm> 

void toUpperCase(char* str) {
    if (!str) return;
    for (int i = 0; str[i] != '\0'; ++i) {
        str[i] = std::toupper(static_cast<unsigned char>(str[i]));
    }
}

bool isVowel(char c) {
    char lowerC = std::tolower(static_cast<unsigned char>(c));
    return (lowerC == 'a' || lowerC == 'e' || lowerC == 'i' || lowerC == 'o' || lowerC == 'u');
}

void removeVowels(char* str) {
    if (!str) return;
    int writeIndex = 0;
    for (int readIndex = 0; str[readIndex] != '\0'; ++readIndex) {
        if (!isVowel(str[readIndex])) {
            str[writeIndex++] = str[readIndex];
        }
    }
    str[writeIndex] = '\0'; 
}

void reverseString(char* str) {
     if (!str) return;
     int len = std::strlen(str);
     if (len < 2) return;
     int start = 0;
     int end = len - 1;
     while (start < end) {
         std::swap(str[start], str[end]);
        
         // char temp = str[start];
         // str[start] = str[end];
         // str[end] = temp;
         start++;
         end--;
     }
}