#include<string.h>
#include<stdio.h>
#include<stdbool.h>
bool isPalindrome(char* s);
int main()
{
    char s[1000];
    scanf("%[^\n]s",s);
    printf("%d",isPalindrome(s));
}
bool isPalindrome(char* s) {
    int i;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]>=65 && s[i]<=90)
        {
            s[i]=s[i]+32;
        }
    }
    //printf("%s",s);
    int l=0;
    int r=strlen(s)-1;
    while(l<r)
    {
        if(!((s[l]>=97 && s[l]<=122)||(s[l]>='0' && s[l]<='9')))
        {
            l++;
            continue;
        }
        if(!((s[r]>=97 && s[r]<=122)||(s[r]>='0' && s[r]<='9')))
        {
            r--;
            continue;
        }
        //printf("%c - %c\n",s[l],s[r]);
        if(s[l]==s[r])
        {
            l++;
            r--;
        }
        else
            return false;
    }
    return true;
}