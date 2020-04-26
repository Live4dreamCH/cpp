/*
输入一行字符(以*结尾)，分别统计出其中英文字母、空格、数字和其他字符(不统计*)的个数。
输入示例：
abc 100000 ,*
输出：
3 2 6 1
*/
#include <stdio.h>
 
int main()
{
    int i, cha = 0, spc = 0, num = 0, oth = 0;
    char t;
    for (i = 0; i < 100; i++)
    {
        t = getchar();
        if (t == '*')
            break;
        else if (('a' <= t && t <= 'z') || ('A' <= t && t <= 'Z'))
            cha++;
        else if (t == ' ')
            spc++;
        else if ('0' <= t && t <= '9')
            num++;
        else
            oth++;
    }
    printf("%d %d %d %d", cha, spc, num, oth);
    return 0;
}