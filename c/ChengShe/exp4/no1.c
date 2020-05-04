/*
请利用嵌套循环输出平行四边形，平行四边形行数为n，每行的“*”的数目也为n，n由键盘输入。
示例输入：
5
示例输出：
*****
 *****
  *****
   *****
    *****
*/
#include <stdio.h>

int main()
{
    int n, i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            putchar(' ');
        }
        for (j = 0; j < n; j++)
        {
            putchar('*');
        }
        putchar('\n');
    }
    return 0;
}