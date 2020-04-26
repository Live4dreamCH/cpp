/*
从键盘输入一个整数，输出这么多行的杨辉三角。
例如输入6，则输出6行的杨辉三角。
输出格式为每行相邻两个数用空格隔开，每行最后一个数后无空格。
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
*/
#include <stdio.h>
#include <stdlib.h>
 
void PrintLine(int a[], int len)
{
    int i = 0;
    printf("1");
    for (i = 1; i < len; i++)
    {
        printf(" %d", a[i]);
    }
    printf("\n");
}
 
void GiveBirthTo(int *parent, int *child, int p_len)
{
    int i;
    for (i = 1; i < p_len; i++)
    {
        child[i] = parent[i] + parent[i - 1];
    }
    child[0] = 1;
    child[p_len] = 1;
}
 
int main()
{
    int n, *a, *b, i;
    scanf("%d", &n);
    a = (int *)calloc(n + 5, sizeof(int));
    b = (int *)calloc(n + 5, sizeof(int));
    a[0] = 1;
    b[0] = 1;
    for (i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            PrintLine(a, i);
            GiveBirthTo(a, b, i);
        }
        else
        {
            PrintLine(b, i);
            GiveBirthTo(b, a, i);
        }
    }
    return 0;
}
