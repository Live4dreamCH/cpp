/*
求S=1!+2!+3!+...20!。
因为数据超出了int的表示范围，统一为long long int类型（8字节），
输出示例：
12345678
*/
#include <stdio.h>
// #include <math.h>
 
int main()
{
    unsigned long long r = 0, i, t = 1;
    for (i = 1; i < 21; i++)
    {
        t *= i;
        r += t;
    }
    printf("%llu", r);
    return 0;
}
