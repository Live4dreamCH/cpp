#include <stdio.h>
// #include <stdlib.h>
void swapint(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void swapaddr(int *a, int *b)
{
    int *t;
    t = a;
    a = b;
    b = t;
}

void swapaddraddr(int **a, int **b)
{
    int *t;
    t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    int x = 1, y = 2;
    int *a = &x, *b = &y;
    swapint(a, b);        //x<=>y, a<=>b
    swapaddr(a, b);       //nothing
    swapaddraddr(&a, &b); //a<=>b
    return 0;
}
