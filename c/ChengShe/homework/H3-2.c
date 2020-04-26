/*
求S=a + aa + a...a(n个a)，其中a是一个数字，n表示a的位数。
（提示：数字可能很大，建议用long类型）
输入a和n示例：
3 6
输出
370368
*/
#include <stdio.h>
 
int main()
{
    long long a, n, r = 0, t = 1, i;
    scanf("%lld %lld", &a, &n);
    for (i = n; i > 0; i--)
    {
        r += i * a * t;
        t *= 10;
    }
    printf("%lld", r);
    return 0;
}