#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <cstddef>

const size_t MAX_STRING_SIZE = 256;

void readString(char* str, size_t maxSize);
void toUpperCase(char* str);
void removeVowels(char* str);
void reverseString(char* str);
bool isVowel(char c);

#endif 