#include<stdio.h>
int removeDuplicates(int *nums, int nums_size);

int main()
{
    int nums_size;
    scanf("%d",&nums_size);
    int nums[nums_size];
    for(int i=0;i<nums_size;i++)
    {
        scanf("%d",&nums[i]);
    }
    int result = removeDuplicates( nums, nums_size);
    printf("%d",result);
}

int removeDuplicates(int* nums, int nums_size) {
    if(nums_size == 0)
    {
     return nums_size;
    }
    int index=1;
     for(int i=0;i<nums_size-1;i++)
     {
         if(nums[i+1] != nums[i])
         {
             nums[index]=nums[i+1];
             index++;
         }
     }
     return index;
 }