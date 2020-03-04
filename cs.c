#include <stdio.h>
 
int main()
{
    int c = 0;
    scanf("%c", &c);
    if (c == 'z')
        c = 'a';
    else if (c == 'Z')
        c = 'A';
    else
        c++;
    printf("%c的ASCII编码是%d。", c, c);
    return 0;
}