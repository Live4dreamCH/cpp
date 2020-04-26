/*
1、	第七章第十题
写一个函数，输入一行字符串，将此字符串中最长的单词输出。
如果最长单词有多个，用空格隔开输出每个最长单词，
字符串长度不超过200，每个单词不超过20个字符，最长单词不超过5个。
输入：
This is another tree ttttttt hello efrtrer hello world!
输出：
another ttttttt efrtrer
*/
#include <stdio.h>
// #include <string.h>

char *my_getstr(char *dest)
{
    char *origin = dest;
    char c;
    c = getchar();
    while (c != '\r' && c != EOF)
    {
        *dest = c;
        dest++;
        c = getchar();
    }
    *dest = 0;
    if (c=='\r')
    {
        getchar();
    }
    return origin;
}

char *my_strcpy(char *dest, char *source, int len)
{
    char *origin = dest;
    int i = 0;
    while (*source != 0)
    {
        *dest = *source;
        dest++;
        source++;
        i++;
        if (i >= len)
        {
            break;
        }
    }
    *dest = 0;
    return origin;
}

void longest_word(char string[])
{
    int i = 0, max_length = -1, len = 0, num = 0;
    char words[10][25];
    while (1)
    {
        if (('a' <= string[i] && string[i] <= 'z') || ('A' <= string[i] && string[i] <= 'Z'))
        {
            len++;
        }
        else
        {
            if (max_length < len)
            {
                max_length = len;
                num = 1;
                my_strcpy(words[0], &string[i - len], len);
            }
            else if (max_length == len)
            {
                my_strcpy(words[num], &string[i - len], len);
                num++;
            }
            len = 0;
        }
        if (string[i] == 0)
        {
            break;
        }
        i++;
    }
    printf("%s", words[0]);
    for (i = 1; i < num; i++)
    {
        printf(" %s", words[i]);
    }
}

int main()
{
    char sentence[205];
    my_getstr(sentence); //交作业时改成my_getstr
    longest_word(sentence);
    return 0;
}