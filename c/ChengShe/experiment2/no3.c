/*
./课本第五章第七题.jpg
保留六位小数
*/
#include <stdio.h>



int main()
{
    int k;
    double result = 0;
    for (k = 1; k <= 100;k++)
    {
        result += k;
    }
    for (k = 1; k <= 50;k++)
    {
        result += k * k;
    }
    for (k = 1; k <= 10;k++)
    {
        result += (double)1 / k;
    }
    printf("%.6f", result);
    return 0;
}