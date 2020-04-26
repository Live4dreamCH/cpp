/*
1、定义一个包含实部和虚部的结构体，实部和虚部都是double类型。
2、分别编写两个复数的加减乘除运算的函数，每个函数均有三个形参，且形参均为结构体指针。
3、从键盘输入两个复数，并选择进行哪种运算（加减乘除分别用a\b\c\d表示），输出其运算结果，结果都是float类型。
输入格式为：
3.21 -5.66 56.777 -62.112 a
输出格式保留三位小数
59.987-67.772i
*/
#include <stdio.h>

struct myComplex
{
    double real;
    double imag;
};

void add(struct myComplex *result, struct myComplex *a, struct myComplex *b)
{
    result->real = a->real + b->real;
    result->imag = a->imag + b->imag;
}
void subtract(struct myComplex *result, struct myComplex *a, struct myComplex *b)
{
    result->real = a->real - b->real;
    result->imag = a->imag - b->imag;
}
void multi(struct myComplex *result, struct myComplex *a, struct myComplex *b)
{
    result->real = a->real * b->real - a->imag * b->imag;
    result->imag = a->real * b->imag + a->imag * b->real;
}
void division(struct myComplex *result, struct myComplex *a, struct myComplex *b)
{
    b->imag *= -1;
    multi(result, a, b);
    b->imag *= -1;
    result->real /= (b->real * b->real + b->imag * b->imag);
    result->imag /= (b->real * b->real + b->imag * b->imag);
}

void input(struct myComplex *result)
{
    scanf("%lf%lf", &result->real, &result->imag);
}

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
    struct myComplex x, y,result;
    char c;
    input(&x);
    input(&y);
    while((c = getchar())==' ')
        ;
    if (c=='a')
    {
        add(&result, &x, &y);
    }
    else if (c=='b')
    {
        subtract(&result, &x, &y);
    }
    else if (c=='c')
    {
        multi(&result, &x, &y);
    }
    else
    {
        division(&result, &x, &y);
    }
    print(&result);
    return 0;
}