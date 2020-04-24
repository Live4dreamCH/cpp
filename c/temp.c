// #include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[200];
    char str2[200];
    gets(str1);
    gets(str2);
    int a = strlen(str1);
    int b = strlen(str2);
    int c = 1;
    for (int i = 0; i <= a - b; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (str1[i + j] != str2[j])
            {
                c = 0;
                break;
            }
        }
        if (c)
        {
            printf("Y");
            c = 0;
            break;
        }
        c = 1;
    }
    if (c)
        printf("N");

    return 0;
}