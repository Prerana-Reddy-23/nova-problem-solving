#include<stdio.h>
int missingNumber(int nums[],int numsSize);
int main()
{
    int numsSize;
    scanf("%d",&numsSize);
    int nums[numsSize];
    for(int i=0;i<numsSize;i++)
    {
        scanf("%d",&nums[i]);
    }
    int result = missingNumber(nums,numsSize);
    printf("%d",result);
}
int missingNumber(int nums[], int numsSize) {
    int sum_of_n= (numsSize*(numsSize+1))/2;
    int sum=0;
    for(int i=0;i<numsSize;i++)
    {
        sum=sum+nums[i];
    }
    return sum_of_n - sum;
}