/*从键盘输入一个大于等于1的奇数，输出图形；
例如输入3
输出
 *
***
 *
*/
#include <stdio.h>
 
int main()
{
    int n, i, j, start, end;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        if (i <= n / 2)
        {
            start = (n - 1) / 2 - i;
            end = (n + 1) / 2 + i;
        }
        else
        {
            start = (n - (2*n-1)) / 2 + i;
            end = (n + 2*n-1) / 2 - i;
        }
        for (j = 0; j < n; j++)
        {
            if (j < start)
            {
                printf(" ");
            }
            else if (j >= end)
            {
                printf(" ");
            }
            else
            {
                printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}
