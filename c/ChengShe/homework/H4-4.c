/*从键盘输入一个自然数，求出这是几位数，按格式逆序和顺序输出每一位数字。
输入格式为
18960
输出
18960是5位数。
1*8*9*6*0
0*6*9*8*1
*/
#include <stdio.h>
 
int main()
{
    // char c = 0, a[10000];
    // int i = 0, l = 0;
    // while(1)
    // {
    //     c = getchar();
    //     if(c=='\n')
    //         break;
    //     a[i] = c;
    //     i++;
    // }
    // l = i;
    // for (i = 0; i < l;i++)
    // {
    //     printf("%c", a[i]);
    // }
    // printf("是%d位数。\n%c", l, a[0]);
    // for (i = 1; i < l;i++)
    // {
    //     printf("*%c", a[i]);
    // }
    // printf("\n%c", a[l - 1]);
    // for (i = l - 2; i >= 0;i--)
    // {
    //     printf("*%c", a[i]);
    // }
    int n, t;
    int a[30], i, l;
    scanf("%d", &n);
    t = n;
    for (i = 0;n>0;i++)
    {
        a[i] = n % 10;
        n /= 10;
    }
    l = i;
    printf("%d是%d位数。\n%d", t, l, a[l-1]);
    for (i = l - 2; i >= 0;i--)
    {
        printf("*%d", a[i]);
    }
    printf("\n%d", a[0]);
    for (i = 1; i < l;i++)
    {
        printf("*%d", a[i]);
    }
    return 0;
}