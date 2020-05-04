/*
性质1：一个n（n大于等于3）位整数，它的每一位数字的n次方的和等于这个整数。
键盘输入两个正整数，输出这两个数的闭区间上所有满足性质1的数。
要求用函数实现。
输入输出均用空格隔开，每隔五个数换行。
*/
#include <math.h>
#include <stdio.h>

int isArmstrongNumber(int num)
{
    int times = 0, originnum = num, result = 0;
    while (num)
    {
        num /= 10;
        times++;
    }
    num = originnum;
    while (num)
    {
        result += pow(num % 10, times);
        num /= 10;
    }
    if (result == originnum)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int start, end, i, format = 0;
    scanf("%d%d", &start, &end);
    for (i = start; i <= end; i++)
    {
        if (isArmstrongNumber(i))
        {
            if (format == 4)
            {
                printf("%d\n", i);
                format = 0;
            }
            else
            {
                printf("%d ", i);
                format++;
            }
        }
    }
    return 0;
}