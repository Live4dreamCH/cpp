/*
输入一段英文，统计其中的数字字符、英文字母和英文单词的个数。
这段文字以*结尾(不统计*)。
输入格式为：
Oh! This is a tree abc! 256 56892!*
输出格式为：
8 16 5
*/
#include <stdio.h>
 
int main()
{
    int i, cha = 0, num = 0, words = 0;
    char t, pre;
    for (i = 0; i < 10000; i++)
    {
        t = getchar();
        if (('a' <= t && t <= 'z') || ('A' <= t && t <= 'Z'))
            cha++;
        else if ('0' <= t && t <= '9')
            num++;
        else
        {
            if(('a' <= pre && pre <= 'z') || ('A' <= pre && pre <= 'Z'))
                words++;
            if (t == '*')
                break;
        }
        pre = t;
    }
    printf("%d %d %d", num, cha, words);
    return 0;
}