/*
输入两个字符串1和2，判定字符串2是否在1中出现，出现输出Y，没出现输出N。
例如字符串ree在字符串This is a tree!中出现了。
This is a tree!
ree

This0
Thi0

This0
his0

0
0

T0
0

0
T0

Th0
Thi0

abbbcde0
bbcd0

abbbcde0
bbcde0
*/
#include <stdio.h>

int main()
{
    char parent[1000], child[1000];
    int i = 0, j = 0, state = 0, start = 0;
    gets(parent);
    gets(child);
    if (child[0] == 0)
    {
        putchar('Y');
        return 0;
    }
    else if (parent[0] == 0)
    {
        putchar('N');
        return 0;
    }
    while (1)
    {
        if (parent[i] == child[j] && child[j] != 0) //?
        {
            if(!state)
            {
                state = 1;
                start = i;
            }
            i++;
            j++;
        }
        else if (child[i] == 0)
        {
            putchar('Y');
            break;
        }
        else if (parent[i] == 0)
        {
            putchar('N');
            break;
        }
        else
        {
            state = 0;
            i = start + 1;
            start++;
            j = 0;
        }
    }
    return 0;
}