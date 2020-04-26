#include <math.h>
#include <stdio.h>

int bubblesort(int *a)
{
    int temp;
    int i, j;
    for (i = 0; i < 25 - 1; i++)
    {
        for (j = 0; j < 25 - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    return 0;
}

int main()
{
    int box[25];
    int i;
    for (i = 0; i < 25; i++)
    {
        scanf("%d", &box);
    }
    bubblesort(box);
    int p = 0;

    //第一行
    printf("%d ", box[0]);
    p++;
    while (p != 4)
    {
        printf("%d ", box[p]);
        p++;
    }
    printf("%d\n", box[1]);
    p++;

    //第二行
    while (p != 9)
    {
        printf("%d ", box[p]);
        p++;
    }
    printf("%d\n", box[p]);
    p++;

    //第三行
    while (p != 12)
    {
        printf("%d ", box[p]);
        p++;
    }
    printf("%d ", box[24]);
    p++;
    while (p != 14)
    {
        printf("%d ", box[p]);
        p++;
    }
    printf("%d\n", box[p]);
    p++;

    //第四行
    while (p != 19)
    {
        printf("%d ", box[p]);
        p++;
    }
    printf("%d\n", box[p]);
    p++;

    //第五行
    printf("%d ", box[2]);
    p++;
    while (p != 24)
    {
        printf("%d ", box[p]);
        p++;
    }
    printf("%d", box[3]);

    return 0;
}
