/*
在主函数中按行输入10个等长的字符串。用另一个函数对其排序，然后在主函数输出这10个已排好序的字符串。
每个字符串长度不超过100，字符串可能含有空格。
*/
#include <stdio.h>
#include <stdlib.h>

char *my_getstr(char *dest)
{
    char *origin = dest;
    char c;
    c = getchar();
    while (c != '\r' && c != EOF)
    {
        *dest = c;
        dest++;
        c = getchar();
    }
    *dest = 0;
    if (c == '\r')
    {
        getchar();
    }
    return origin;
}

int my_strcmp(char a[], char b[])
{
    int i = 0;
    while (1)
    {
        if (a[i] == 0 && b[i] == 0)
            return 0;
        if (a[i] == 0)
            return -1;
        if (b[i] == 0)
            return 1;
        if (a[i] > b[i])
            return 1;
        if (a[i] < b[i])
            return -1;
        i++;
    }
}

char *my_strcpy(char *dest, char *source, int len)
{
    char *origin = dest;
    int i = 0;
    while (*source != 0)
    {
        *dest = *source;
        dest++;
        source++;
        i++;
        if (i >= len)
        {
            break;
        }
    }
    *dest = 0;
    return origin;
}

void my_strswap(char a[], char b[], int len)
{
    char *temp=(char *)malloc(len*sizeof(char));
    my_strcpy(temp, a, len);
    my_strcpy(a, b, len);
    my_strcpy(b, temp, len);
}

int main()
{
    char strings[15][105];
    int i, j;
    for (i = 0; i < 10; i++)
    {
        my_getstr(strings[i]);//my_getstr
    }
    for (i = 0; i < 9; i++)
    {
        for (j = 8; j >= i; j--)
        {
            if (my_strcmp(strings[j], strings[j + 1]) == 1)
                my_strswap(strings[j], strings[j + 1],101);
        }
        puts(strings[i]);
    }
    puts(strings[i]);
    return 0;
}