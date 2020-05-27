#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int partions(int a[], int i, int j)
{
    int key = a[i];
    while (i < j)
    {
        while (a[i] <= key)
            i++;
        swap(&a[i], &a[j]);
        while (a[j] >= key)
            j--;
        swap(&a[i], &a[j]);
    }
    return i;
}

void sort(int a[], int low, int high)
{
    int k;
    if (low < high)
    {
        k = partions(a, low, high);
        sort(a, low, k - 1);
        sort(a, k + 1, high);
    }
}
int main()
{
    int *a, n, i;
    printf("请输入序列的长度:\n");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    printf("请输入待排序的序列:\n");
    for (i = 0; i <= n - 1; i++)
        scanf("%d", &a[i]);
    sort(a, 0, n - 1);
    printf("快速排序后的序列为:\n");
    for (i = 0; i <= n - 1; i++)
        printf("%d ", a[i]);
    return 0;
}
