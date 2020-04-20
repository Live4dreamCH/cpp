// #include <stdio.h>
#include <stdlib.h>

void foo();

int main()
{
    foo();

    return 0;
}

void foo()
{
    int *p;

    while (1)
    {
        p = (int *)malloc(100000 * sizeof(int));
    }
}