/*
输入按照大小顺序排列的15个整数，另外输入一个数，用折半法找出是第几个数字。
输入格式为16个用空格隔开的整数。
如果找到，输出这个数的序号(从1开始)，否则，输出字符N。
*/
#include <stdio.h>

int findnum(int a[], int len, int num)
{
    int middle = len / 2, left = 0, right = len-1;
    if (num < a[left] || num > a[right])
        return -1;    
    while (left <= right)
    {
        if (a[middle] == num)
            return middle;
        else if (a[middle] > num)
        {
            right = middle-1;
            middle = (right + left) / 2;
        }
        else
        {
            left = middle+1;
            middle = (right + left) / 2;
        }
    }
    return -1;
}

int main()
{
    int a[20], num, i;
    for (i = 0; i < 15; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &num);
    i = findnum(a, 15, num)+1;
    if (!i)
        putchar('N');
    else
    {
        printf("%d", i);
    }
    return 0;
}