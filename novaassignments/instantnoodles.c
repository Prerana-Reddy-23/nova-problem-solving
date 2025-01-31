#include <stdio.h>
int maximum_num_of_customers(int x,int y);
int main() {
	// your code goes here
    int x,y;
    scanf("%d%d",&x,&y);
    printf("%d",maximum_num_of_customers(x,y));
}

int maximum_num_of_customers(int x,int y)
{
    return x*y;
}