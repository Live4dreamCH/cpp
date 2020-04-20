// #include<iostream>
// using namespace std;
#include <stdio.h>

long long times = 0;

bool NFA(char *str, int state = 0, int i = 0)
{
    times++;
    char c = str[i];
    if (state == 0)
    {
        if (c == '1')
        {
            return NFA(str, 0, i + 1) || NFA(str, 1, i + 1);
        }
        else if(c=='0')
        {
            return NFA(str, 0, i + 1);
        }
    }
    else if (state == 1)
    {
        if (c == '0')
        {
            return NFA(str, 2, i + 1);
        }
        else if (c == '1')
        {
            return false;
        }
    }
    else if (state == 2)
    {
        if (c == '1')
        {
            return NFA(str, 3, i + 1);
        }
        else if (c == '0')
        {
            return false;
        }
    }
    else if (state == 3)
    {
        if (c == '\0')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

int main()
{
    char string[1000];
    gets(string);
    bool result = NFA(string);
    if (result)
        printf("Yes");
    else
        printf("No");
    printf("\n%lld", times);
    return 0;
}