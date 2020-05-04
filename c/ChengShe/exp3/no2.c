/*
课本第六章第五题
长度小于100的整型数组，输入空格隔开的一组整数，要求逆序存储并输出。
*/
#include <stdio.h>

void reverse(int a[], int len)
{
    int i;
    for (i = 0; i < len / 2; i++)
    {
        a[i] = a[i] ^ a[len - i - 1];
        a[len - i - 1] = a[i] ^ a[len - i - 1];
        a[i] = a[i] ^ a[len - i - 1];
    }
}

int main()
{
    int i, arr[105], len;
    for (i = 0; i < 100; i++)
    {
        scanf("%d", &arr[i]);
        if (getchar() != ' ')
        {
            break;
        }
    }
    len = i+1;
    reverse(arr, len);
    printf("%d", arr[0]);
    for (i = 1; i < len; i++)
    {
        printf(" %d", arr[i]);
    }
    return 0;
}