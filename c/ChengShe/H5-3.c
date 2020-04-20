/*
找出一个4行5列的二维数组a的鞍点，即该位置上的元素在该行上最大，在该列上最小。
也可能没有鞍点。
输入示例，按行输入各元素，
1 2 3 4 5 
2 4 6 8 10 
3 6 9 12 15 
4 8 12 16 20
若有鞍点则输出
a[1][2]=6
若无鞍点，则输出
None
*/
#include <stdio.h>
 
int main()
{
    int a[4][5], i, j, t, max[4], min[5];
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    // for (i = 0; i < 4;i++)
    // {
    //     for (j = 0; j < 5;j++)
    //     {
    //         printf("%d ", a[i][j]);
    //     }
    //     printf("\n");
    // }
    for (i = 0; i < 4; i++)
    {
        t = 0;
        for (j = 0; j < 5; j++)
        {
            if (a[i][j] > a[i][t])
                t = j;
        }
        max[i] = t;
    }
    for (j = 0; j < 5; j++)
    {
        t = 0;
        for (i = 0; i < 4; i++)
        {
            if (a[i][j] < a[t][j])
                t = i;
        }
        min[j] = t;
    }
    t = 0;
    for (i = 0; i < 4; i++)
    {
        if (min[max[i]] == i)
        {
            printf("a[%d][%d]=%d", i, max[i], a[i][max[i]]);
            t = 1;
            break;
        }
    }
    if (!t)
    {
        printf("None");
    }
    return 0;
}