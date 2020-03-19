/*
有一个分数序列
2/1，3/2，5/3，8/5，13/8
从键盘输入一个数n，输出该序列前n项之和，保留两位小数。
*/
#include <stdio.h>

int main()
{
    int num, den, i, n, t;
    double sum=0;
    scanf("%d", &n);
    num = 1;
    den = 1;
    for (i = 0; i < n;i++)
    {
        t = num;
        num += den;
        den = t;
        sum += (float)num / den;
    }
    printf("%.2f", sum);
    return 0;
}
