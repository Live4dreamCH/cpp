/*从键盘输入一个浮点数a，用迭代法求其平方根x。
要求前后两次求出的x的差的绝对值小于0.001。
输入格式为：
25.00
输出保留两位小数：
5.00*/
#include <stdio.h>
 
int main()
{
    double a, x, pre=-1;
    scanf("%lf", &a);
    x = a;
    while((x-pre)>=0.001||(x-pre)<=-0.001)
    {
        pre = x;
        x = 0.5 * (x + a / x);
    }
    printf("%.2f", x);
    return 0;
}
