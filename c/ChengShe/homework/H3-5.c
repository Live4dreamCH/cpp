/*一个数如果恰好等于它的因子之和，这个数就称为“完数”。
找出1000之内的所有完数并输出其因子。
输出格式为（每个数及其因子占一行，冒号后面有个英文空格）：
 
6: 1,2,3*/
 
#include <stdio.h>
 
int main()
{
    int i, sum, a[1000],j,p;
    for (i = 1; i < 1000;i++)
    {
        for (j = 1, sum = 0, p = 0; j < i; j++)
        {
            if(i%j==0)
            {
                sum += j;
                a[p] = j;
                p++;
            }
            if(sum>i)
                break;
        }
        if(sum==i)
        {
            printf("%d: 1", i);
            for (j = 1; j < p;j++)
            {
                printf(",%d", a[j]);
            }
            printf("\n");
        }
    }
        return 0;
}
