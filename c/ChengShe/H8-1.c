/*
输入一个字符串，内有数字和非数字字符，例如
a123xcv%66587?21tdd
将其中连续的数字作为一个整数，依次输出这些数字的两倍，用空格隔开。
*/
#include <stdio.h>
 
int main()
{
    char str[1000], num[1000];
    int i = 0, ni = 0, state = 1;
    long long t = 1, n = 0;
    gets(str);
    while (1)
    {
        if ('0' <= str[i] && str[i] <= '9')
        {
            num[ni] = str[i];
            ni++;
        }
        else
        {
            if (ni != 0)
            {
                for (ni--; ni >= 0; ni--)
                {
                    n += t * (num[ni] - '0');
                    t *= 10;
                }
                if(state)
                {
                    printf("%lld", 2 * n);
                    state = 0;
                }
                else
                {
                    printf(" %lld", 2 * n);
                }
                t = 1;
                n = 0;
                ni = 0;
            }
            if(str[i]==0)
                break;
        }
        i++;
    }
    return 0;
}