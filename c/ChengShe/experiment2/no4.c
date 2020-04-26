/*
./课本第五章第十题.jpg
修改版
输入一个数字n，
则输出前n项的和，保留两位小数。
*/
#include <stdio.h>



int main()
{
    double result;
    int fenzi=2, fenmu=1, i, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        result += (double)fenzi / fenmu;
        fenzi += fenmu;
        fenmu = fenzi - fenmu;
    }
    printf("%.2f", result);
    return 0;
}