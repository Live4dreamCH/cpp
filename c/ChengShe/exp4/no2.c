/*
输入一个3*5矩阵，求出每一行每一列的最小值，将这些最小值中的最大值输出。
（例如行和列的最小值为11 1 6 1 2 3 4 5，这8个最小值中11最大）
示例输入
11 12 13 14 15
1  2  3  4  5
7  8  9  6  10
示例输出
11
*/
#include <stdio.h>

int main()
{
    int i, j, matrix[10][10], max = -__INT_MAX__, temp;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (i = 0; i < 3; i++)
    {
        temp = matrix[i][0];
        for (j = 0; j < 5; j++)
        {
            if (matrix[i][j] < temp)
            {
                temp = matrix[i][j];
            }
        }
        if (temp > max)
        {
            max = temp;
        }
    }
    for (j = 0; j < 5; j++)
    {
        temp = matrix[0][j];
        for (i = 0; i < 3; i++)
        {
            if (matrix[i][j] < temp)
            {
                temp = matrix[i][j];
            }
        }
        if (temp > max)
        {
            max = temp;
        }
    }
    printf("%d", max);
    return 0;
}