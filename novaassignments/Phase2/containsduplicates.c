#include<stdio.h>
#include<stdlib.h>
typedef int bool;
#define true 1
#define false 0
int compare(const void *a, const void *b);
bool containsDuplicate(int* nums, int nums_size);
int main()
{
    int nums_size;
    scanf("%d",&nums_size);
    int nums[nums_size];
    for(int i=0;i<nums_size;i++)
    {
        scanf("%d",&nums[i]);
    }
    int result = containsDuplicate(nums,nums_size);
    printf("%d",result);
}
int compare(const void *a, const void *b)
{
    return (*(int*)a-*(int*)b);
}
bool containsDuplicate(int* nums, int nums_size) {
    qsort(nums,nums_size,sizeof(int),compare);
    for(int i=0;i<nums_size-1;i++)
    {
        if(nums[i]==nums[i+1])
        {
            return true;
        }
    }
    return false;
}