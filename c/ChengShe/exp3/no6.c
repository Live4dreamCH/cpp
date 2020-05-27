/*
课本第六章第一题修改
原题:用筛选法求100以内的素数
输入两个整数，输出闭区间内所有素数的和。
*/
#include <math.h>
#include <stdio.h>

int isPrime(int n)
{
    int i = 2;
    double s = sqrt(n);
    if (n == 2 || n == 3)
        return 1;
    if (n <= 1)
        return 0;
    if (n % 6 != 1 && n % 6 != 5)
    {
        return 0;
    }
    while (i <= s + 1)
    {
        if (n % i == 0)
            return 0;
        i++;
    }
    return 1;
}

int main()
{
    int start, end, i;
    long long int result = 0;
    scanf("%d%d", &start, &end);
    for (i = start; i <= end; i++)
    {
        if (isPrime(i))
        {
            result += i;
            // printf("%d\n", i);
        }
    }
    printf("%lld", result);
    return 0;
}