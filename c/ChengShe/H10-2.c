/*
输入两个多项式格式如下，系数都是浮点数：
2 1.362 1 8.8 2 -5.02 0 30.3
3 6.6 0 0
表示多项式1是 1.362X2+8.8X-5.02X2+30.3 
多项式2是6.6X3 
最后一组数字必须输入并且表示0次幂，最高幂为16，
输入并不需要按照幂次高低顺序,同一幂次可多次输入（但是0次幂仅在每个多项式最后一组数字输入），
每个多项式总共不超过30项输入，输入系数为负数时，负号后没有空格。
乘法结果不为零。0次幂的系数为0时也必须出现在输入数据中。
输出格式：从最高幂开始依次降到0幂，系数为0不输出，输出保留两位小数：
-200X8+300X2-1X1+30
*/
#include <stdio.h>
int main()
{
    int times = -1, Amax = -1, Bmax = -1, i, j;
    double coefficientA[20] = {0}, coefficientB[20] = {0}, coefficientC[40] = {0}, curr;
    while (times != 0)
    {
        scanf("%d%lf", &times, &curr);
        if (times > Amax)
            Amax = times;
        coefficientA[times] += curr;
    }
    times = -1;
    while (times != 0)
    {
        scanf("%d%lf", &times, &curr);
        if (times > Bmax)
            Bmax = times;
        coefficientB[times] += curr;
    }
    for (i = 0; i <= Amax; i++)
    {
        for (j = 0; j <= Bmax; j++)
        {
            coefficientC[i + j] += coefficientA[i] * coefficientB[j];
        }
    }
    for (i = Amax + Bmax; i >= 0; i--)
    {
        if (coefficientC[i]>0)
        {
            if (i!=Amax+Bmax)
            {
                putchar('+');
            }
            if(i!=0)
                printf("%.2fX%d", coefficientC[i], i);
            else
                printf("%.2f", coefficientC[i]);
        }
        else if(coefficientC[i]<0)
        {
            if(i!=0)
                printf("%.2fX%d", coefficientC[i], i);
            else
                printf("%.2f", coefficientC[i]);
        }
    }
    return 0;
}