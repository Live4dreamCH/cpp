/*
2、	第七章第十六题
写一个函数，输入一个十六进制数，包含大小写字母，输出相应的十进制数。
输入：
1c
输出
28
*/
#include <stdio.h>

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
    if (c=='\r')
    {
        getchar();
    }
    return origin;
}

long long HexToDec(char hex[])
{
    int i, len, curr;
    long long result = 0, sixteens = 1;
    for (i = 0; hex[i] != 0; i++)
        ;
    len = i;
    for (i = len - 1; i >= 0; i--)
    {
        if ('0'<=hex[i]&&hex[i]<='9')
        {
            curr = (hex[i] - '0');
        }
        else if('a'<=hex[i]&&hex[i]<='f')
        {
            curr = hex[i] - 'a' + 10;
        }
        else
        {
            curr = hex[i] - 'A' + 10;
        }
        result += sixteens * curr;
        sixteens *= 16;
    }
    return result;
}

int main()
{
    char hex[100];
    long long result;
    my_getstr(hex); //my_getstr
    result = HexToDec(hex);
    printf("%lld", result);
    return 0;
}