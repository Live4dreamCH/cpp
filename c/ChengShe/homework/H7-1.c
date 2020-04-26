/*
输入10个整数，将其中最小的数与第1个数对换，把最大的数与最后一个数对换。
写3个函数：①输入10个数；②进行处理；③输出10个数。
输入:
 
15 2 3 4 5 6 7 8 9 10
 
输出
 
2 10 3 4 5 6 7 8 9 15
*/
// #include <math.h>
#include <stdio.h>
#include <stdlib.h>
 
int *getint()
{
    int *a = (int *)calloc(10, sizeof(int)), i;
    for (i = 0; i < 10; i++)
    {
        scanf("%d", a + i);
    }
    return a;
}
 
void dealing(int *a)
{
    int i, max = 0, min = 0;
    for (i = 0; i < 10; i++)
    {
        if (a[i] < a[min])
            min = i;
        if (a[i] > a[max])
            max = i;
    }
    i = a[0];
    a[0] = a[min];
    a[min] = i;
    if(max==0)
        max = min;
    i = a[9];
    a[9] = a[max];
    a[max] = i;
}
 
void printint(int *a)
{
    int i;
    for (i = 0; i < 9; i++)
    {
        printf("%d ", a[i]);
    }
    printf("%d", a[9]);
}
 
int main()
{
    int *a;
    a = getint();
    dealing(a);
    printint(a);
    return 0;
}
