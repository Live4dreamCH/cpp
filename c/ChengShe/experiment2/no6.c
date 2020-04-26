/*
求一元二次方程的根。
输入格式为空格隔开的a，b，c的值。
输出保留三位小数，格式如下，i 为虚数符号
x1=2.362+1.235i x2=-3.167+6.160i
*/
#include <stdio.h>
#include <math.h>

struct myComplex
{
    double real;
    double imag;
};

void print(struct myComplex *result)
{
    printf("%.3f", result->real);
    if (result->imag>0)
    {
        putchar('+');
    }
    printf("%.3fi", result->imag);
}


int main()
{
    double a, b, c, delta;
    struct myComplex result;
    scanf("%lf%lf%lf", &a, &b, &c);
    delta = b * b - 4 * a * c;
    if(delta>=0)
    {
        printf("x1=%.3f x2=%.3f", (-b + sqrt(delta)) / 2 / a, (-b - sqrt(delta)) / 2 / a);
    }
    else
    {
        printf("x1=");
        result.real = -b / 2 / a;
        result.imag = sqrt(-delta) / 2 / a;
        print(&result);
        printf(" x2=");
        result.imag *= -1;
        print(&result);
    }
    
    return 0;
}