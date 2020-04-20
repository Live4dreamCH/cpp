/*
输入两个字符串，输出较大的字符串。
*/
#include <stdio.h>
 
int strcmp(char a[],char b[])
{
    int i = 0;
    while(1)
    {
        if(a[i]==0&&b[i]==0)
            return 0;
        if(a[i]==0&&b[i]!=0)
            return -1;
        if(a[i]!=0&&b[i]==0)
            return 1;
        if(a[i]>b[i])
            return 1;
        if(a[i]<b[i])
            return -1;
        i++;
    }
    return 0;
}
 
int main()
{
    char a[1000], b[1000];
    int t;
    gets(a);
    gets(b);
    t = strcmp(a, b);
    if(t==1)
        puts(a);
    else if(t==-1)
        puts(b);
    else
        puts(a);
    return 0;
}
