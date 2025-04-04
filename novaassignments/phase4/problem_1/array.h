#ifndef DYNAMIC_ARRAY_UTILS_H
#define DYNAMIC_ARRAY_UTILS_H

#include <cstddef> 

int* allocateArray(int size);
void fillArray(int* arr, int size);
void sortArray(int* arr, int size);
void printArray(const int* arr, int size);
void deleteArray(int*& arr);

#endif 