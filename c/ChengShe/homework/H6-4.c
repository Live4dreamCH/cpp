/*
输入两个数字，输出这两个数字闭区间上的素数。
编写函数判定是否是素数。
输入格式为
300 98651
输出格式为（最后一个数字之后不换行）：
3
5
7
*/
#include <math.h>
#include <stdio.h>
 
int isprime(int n)
{
    int i = 2;
    if (n % 6 != 1 && n % 6 != 5)
    {
        return 0;
    }
    while (i <= sqrt(n) + 1)
    {
        if (n % i == 0)
            return 0;
        i++;
    }
    return 1;
}
 
int main()
{
    int a, b, i, t = 0;
    scanf("%d%d", &a, &b);
    for (i = a; i <= b; i++)
    {
        if (isprime(i))
        {
            if (t)
                printf("%d\n", t);
            t = i;
        }
    }
    printf("%d", t);
    return 0;
}
