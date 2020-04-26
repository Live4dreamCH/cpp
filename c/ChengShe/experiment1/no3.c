/*
3、	第七章第七题
有一个字符串，写一个函数，将此字符串中从第m个字符开始的全部字符复制成另一个字符串。
输入
This is a tree!
6
输出
is a tree!
*/
#include <stdio.h>
#include <string.h>

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

char *my_strcpy(char *dest, char *source, int m)
{
    char *origin = dest;
    source += m - 1;
    while (*source!=0)
    {
        *dest = *source;
        dest++;
        source++;
    }
    *dest = 0;
    return origin;
}

int main()
{
    char a[1000], b[1000];
    int m;
    my_getstr(a); //my_getstr
    scanf("%d", &m);
    my_strcpy(b, a, m);
    puts(b);
    return 0;
}