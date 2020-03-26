#include <stdio.h>

int main()
{
    puts("attract the ^^ here");
    char t;
    t = getchar();
    while(t!=EOF)
    {
        if(t=='\r')
        {
            printf("\\r");
        }
        else if(t=='\n')
        {
            printf("\\n");
        }
        else
        {
            putchar(t);
        }
        t = getchar();
    }
    return 0;
}

// This is a tree!
// $
// Hello world!$


// /*
// 从键盘输入两个字符串，把后输入的字符串拼接到第一个字符串后，然后输出合并后的字符串。
// 每个字符串长度不超过50个字符。字符串可能包含空格。
// */
// #include <stdio.h>

// int main()
// {
//     char a[55], b[55], c[115];
//     int i=0, len_a=10086;
//     gets(a);
//     gets(b);
//     while(i<len_a)
//     {
//         if(a[i]==0)
//         {
//             len_a = i;
//             break;
//         }
//         c[i] = a[i];
//         i++;
//     }
//     i = 0;
//     while(b[i]!=0)
//     {
//         c[i + len_a] = b[i];
//         i++;
//     }
//     c[i + len_a] = 0;
//     // printf("%s", c);
//     puts(c);
//     return 0;
// }