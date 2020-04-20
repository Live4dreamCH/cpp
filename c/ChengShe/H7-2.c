/*
请回忆小学学习的手算整数除法的步骤。
本题所得的商小于1
先将被除数乘以10，得到一位商以后，将余数乘以10作为下一轮计算的被除数，可得任意精度的商。
输入的整数得到的商一定除不尽。
输入示例：123 567
输出示例：0.21693121693121693121693121693122
最多显示小数点后200位。
如果是循环小数，则输出
0.6T123456T
T之间为循环周期
如果超过200位还未找到循环节，则输出前200位。
提示：如果余数重复，则循环节出现。
*/
// #include <math.h>
#include <stdio.h>
#include <stdlib.h>
 
int search(int a[],int len,int num)
{
    int i;
    for (i = 0; i < len;i++)
    {
        if(a[i]==num)
            return i;
    }
    return -1;
}
 
int main()
{
    int memory[205]={0},answer[205]={0},dividend=0,divisor=0,i,fr=0,bk=0,t=0;
    scanf("%d%d", &dividend, &divisor);
    if(divisor==0)
        return 0;
    answer[0] = dividend / divisor;
    memory[0] = dividend % divisor;
    for (i = 1; i <= 200;i++)
    {
        answer[i] = memory[i-1] * 10 / divisor;
        memory[i] = memory[i-1] * 10 % divisor;
        t = search(memory, i, memory[i]);
        if(t!=-1)
        {
            fr = t;
            bk = i;
            break;
        }
    }
    for (i = 0; i <= 200;i++)
    {
        printf("%d", answer[i]);
        if(i==0)
            printf(".");
        if(fr!=bk)
        {
            if(i==fr)
                printf("T");
            if(i==bk)
            {
                printf("T");
                break;
            }
        }
    }
    return 0;
}