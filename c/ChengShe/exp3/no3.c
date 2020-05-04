/*
课本第七章第十三题
用递归法求n阶让德多项式在x处的值。
n和x从键盘输入，用空格隔开。
输出保留两位小数。
*/
#include <stdio.h>

double lrdP(int n,double x)
{
    if(n==0)
        return 1;
    if(n==1)
        return x;
    return ((2 * n - 1) * x - lrdP(n - 1, x) - (n - 1) * lrdP(n - 2, x)) / n;
}

int main()
{
    int n;
    double x;
    scanf("%d%lf", &n, &x);
    printf("%.2f", lrdP(n, x));
    return 0;
}