/*
选择法对10个整数从小到大排序。
输入输出格式为10个用空格隔开的整数。
*/
#include<stdio.h>

void selection_sort(int arr[], int len, int SmallToBig)
{
    int i,j, target,temp;
    for (i = 0; i < len - 1;i++)
    {
        target = i;
        for (j = i; j < len;j++)
        {
            if(SmallToBig)
            {
                if(arr[j]<arr[target])
                {
                    target = j;
                }
            }
            else
            {
                if(arr[j]>arr[target])
                {
                    target = j;
                }
            }
        }
        if(target!=i)
        {
            temp = arr[i];
            arr[i] = arr[target];
            arr[target] = temp;
        }
    }
}

int main()
{
    int i,a[20];
    for (i = 0; i < 15; i++)
    {
        scanf("%d", &a[i]);
    }
    selection_sort(a, 15, 1);
    printf("%d", a[0]);
    for (i = 1; i < 15; i++)
    {
        printf(" %d", a[i]);
    }
    return 0;
}