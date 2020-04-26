/*
例如：162中有1个6，3661中有2个6。
要求：
1、从键盘输入两个正整数和一个个位数，用英文空格隔开。
2、统计在这两个数的闭区间内给定的个位数出现的次数并输出。
3、定义一个函数，有两个形参，形参2为个位数，该函数返回值为形参1中形参2出现的次数。
例如：统计1到2000之间的正整数，数字6出现的次数，输入格式为：
1 2000 6
输出格式为：
600
*/
#include <stdio.h>

int get_times(int multi, int single)
{
    int i = 0;
    while (multi)
    {
        if (multi%10==single)
        {
            i++;
        }
        multi /= 10;
    }
    return i;
}

int main()
{
    int i, start, end, num, times = 0;
    scanf("%d%d%d", &start, &end, &num);
    for (i = start; i <= end;i++)
    {
        times += get_times(i, num);
    }
    printf("%d", times);
    return 0;
}