/*
4、	第七章第十题
将一个5阶方阵中的最大元素放在中心，4个角分别放4个最小元素，顺序为从左到右、从上到下依次从小到大存放。
输入空格隔开的25个数字
输出5行5列的矩阵形式
*/
#include <stdio.h>
struct coordinate
{
    int x;
    int y;
};

void exchange(int a[7][7], int x1, int y1, int x2, int y2)
{
    int t;
    t = a[x1][y1];
    // a[x1][y1] = a[x2][y2];
    // a[x2][y2] = t;
    *(*(a + x1) + y1) = *(*(a + x2) + y2);
    *(*(a + x2) + y2) = t;
}

int in(int x, int y, struct coordinate b[], int len)
{
    int i;
    for (i = 0; i < len;i++)
    {
        if(x==b[i].x&&y==b[i].y)
            return 1;
    }
    return 0;
}

int main()
{
    // int input[30], arranged[30], output[7][7], i, j, t;
        // for (i = 0; i < 25;i++)
        // {
        //     scanf("%d", &input[i]);
        //     arranged[i] = input[i];
        // }
        // for (i = 0; i < 24;i++)
        // {
        //     for (j = 23; j >= i;j--)
        //     {
        //         if(arranged[j]>arranged[j+1])
        //         {
        //             t = arranged[j];
        //             arranged[j] = arranged[j + 1];
        //             arranged[j + 1] = t;
        //         }
        //     }
        // }
    int matrix[7][7], i, j, k;
    struct coordinate max = {0, 0}, min[4];
    for (k = 0; k < 4; k++)
    {
        min[k].x = 0;
        min[k].y = 0;
    }
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (matrix[i][j] > matrix[max.x][max.y])
            {
                max.x = i;
                max.y = j;
            }
            if (matrix[i][j] < matrix[min[0].x][min[0].y])
            {
                min[0].x = i;
                min[0].y = j;
            }
        }
    }
    for (k = 1; k < 4; k++)
    {
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 5; j++)
            {
                if (matrix[i][j] >= matrix[min[k - 1].x][min[k - 1].y])
                {
                    if (matrix[i][j] < matrix[min[k].x][min[k].y] && !in(i, j, min, k))
                    {
                        min[k].x = i;
                        min[k].y = j;
                    }
                }
            }
        }
    }

    // putchar('\n');
    // for (i = 0; i < 5;i++)
    // {
    //     printf("%d", matrix[i][0]);
    //     for (j = 1; j < 5;j++)
    //     {
    //         printf(" %d", matrix[i][j]);
    //     }
    //     putchar('\n');
    // }
    
    exchange(matrix, 2, 2, max.x, max.y);
    for (k = 0; k < 4;k++)
    {
        if(min[k].x==2&&min[k].y==2)
        {
            min[k].x = max.x;
            min[k].y = max.y;
            break;
        }
    }

    // putchar('\n');
    // for (i = 0; i < 5;i++)
    // {
    //     printf("%d", matrix[i][0]);
    //     for (j = 1; j < 5;j++)
    //     {
    //         printf(" %d", matrix[i][j]);
    //     }
    //     putchar('\n');
    // }
    
    exchange(matrix, 0, 0, min[0].x, min[0].y);
    for (k = 1; k < 4;k++)
    {
        if(min[k].x==0&&min[k].y==0)
        {
            min[k].x = min[0].x;
            min[k].y = min[0].y;
            break;
        }
    }

    // putchar('\n');
    // for (i = 0; i < 5;i++)
    // {
    //     printf("%d", matrix[i][0]);
    //     for (j = 1; j < 5;j++)
    //     {
    //         printf(" %d", matrix[i][j]);
    //     }
    //     putchar('\n');
    // }

    exchange(matrix, 0, 4, min[1].x, min[1].y);
    for (k = 2; k < 4;k++)
    {
        if(min[k].x==0&&min[k].y==4)
        {
            min[k].x = min[1].x;
            min[k].y = min[1].y;
            break;
        }
    }

    // putchar('\n');
    // for (i = 0; i < 5;i++)
    // {
    //     printf("%d", matrix[i][0]);
    //     for (j = 1; j < 5;j++)
    //     {
    //         printf(" %d", matrix[i][j]);
    //     }
    //     putchar('\n');
    // }

    exchange(matrix, 4, 0, min[2].x, min[2].y);
    for (k = 3; k < 4;k++)
    {
        if(min[k].x==4&&min[k].y==0)
        {
            min[k].x = min[2].x;
            min[k].y = min[2].y;
            break;
        }
    }

    // putchar('\n');
    // for (i = 0; i < 5;i++)
    // {
    //     printf("%d", matrix[i][0]);
    //     for (j = 1; j < 5;j++)
    //     {
    //         printf(" %d", matrix[i][j]);
    //     }
    //     putchar('\n');
    // }


    exchange(matrix, 4, 4, min[3].x, min[3].y);
    for (i = 0; i < 5;i++)
    {
        printf("%d", matrix[i][0]);
        for (j = 1; j < 5;j++)
        {
            printf(" %d", matrix[i][j]);
        }
        putchar('\n');
    }
    return 0;
}