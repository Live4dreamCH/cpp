/*
5、	第八章第一题
输入三个整数，按从小到大的顺序输出。
输入输出均用空格隔开
*/
#include<stdio.h>

void bubble(int *arr, int len, int SmallToBig)
{
    int i, j, t;
    for (i = 0; i < len - 1;i++)
    {
        for (j = len - 2; j >= i;j--)
        {
            if(SmallToBig)
            {
                if(arr[j]>arr[j+1])
                {
                    t = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = t;
                }
            }
            else
            {
                if(arr[j]<arr[j+1])
                {
                    t = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = t;
                }
            }
            
        }
    }
}

int main()
{
    int a[3], i;
    for (i = 0; i < 3; i++)
    {
        scanf("%d", &a[i]);
    }
    bubble(a, 3, 1);
    printf("%d", a[0]);
    for (i = 1; i < 3; i++)
    {
        printf(" %d", a[i]);
    }
    return 0;
}