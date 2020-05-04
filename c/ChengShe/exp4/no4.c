/*
编写一个函数int sum(int *p, int n)计算一组数据的和，在main函数中输入5个int型数并放入数组，调用sum函数计算并输出该5个数的和。
示例输入
1 3 5 7 9
示例输出
25
*/
#include <stdio.h>

int sum(int *p, int n)
{
    int i, result=0;
    for (i = 0; i < n;i++)
    {
        result += p[i];
    }
    return result;
}

int main()
{
    int i, arr[10], re;
    for (i = 0; i < 5;i++)
    {
        scanf("%d", &arr[i]);
    }
    re = sum(arr, 5);
    printf("%d", re);
    return 0;
}