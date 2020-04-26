/*
输入一个字符串和一个字符，删除该字符串中的这个字符。输出删除给定字符后的新字符串。
*/
#include <stdio.h>
 
int strcmp(char a[],char b[])
{
 
}
 
int main()
{
    char a[1000], b;
    int i, del;
    gets(a);
    b = getchar();
    i = 0;
    del = 0;
    while(a[i+del]!=0)
    {
        if(a[i+del]==b)
        {
            del++;
        }
        a[i] = a[i + del];
        i++;
    }
    a[i] = 0;
    puts(a);
    return 0;
}