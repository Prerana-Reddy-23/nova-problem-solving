#include<stdio.h>
#include<string.h>

int lengthOfLastWord(char *s);
int main()
{
    char s[1000];
    scanf("%[^\n]s",s);
    printf("%d",lengthOfLastWord(s));
}
int lengthOfLastWord(char* s) {
    int count=0;
    int len = strlen(s)-1;
    while(*(s+len)==' ')
    {
        len--;
    }
    for(int i=len;i>=0 && *(s+i)!='\0';i--)
    {
        if(*(s+i)!=' ')
        {
            count++;
        }
        else
        {
            break;
        }
    }
    return count;

}