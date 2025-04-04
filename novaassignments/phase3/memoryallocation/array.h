#ifndef ARRAY_H
#define ARRAY_H


int* allocateIntArray(int size);


void populateIntArray(int* arr, int size);


void sortIntArray(int* arr, int size);


void printIntArray(const int* arr, int size);

void deallocateIntArray(int* arr);

#endif