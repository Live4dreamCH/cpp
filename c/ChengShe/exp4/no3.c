/*
编写函数将整数k变换为一个字母串，规则如下：设0对应A，1对应B，......，25对应Z。
从左向右考察k的各位数字，若连续两位对应上面一种变换，则直接换掉两位数字，否则一位数字换成对应的字母。
变换结果存入res反馈给调用者。函数原型为：
    void  DigiTran( int k, char res[] );    
在主函数输入一些非负整数，最后输入-1代表结束，利用上面函数对每个数字变换后输出。

示例输入：(数字间空一格)
12 3925 0 -1
示例输出：(每个字符串后面空一格)
M DJZ A 
*/
#include <stdio.h>

void DigiTran(int k, char res[])
{
    //bit: 放置的k的每一位; i: bit数组的下标; j: res数组的下标; len: k的位数; temp: 用来存两位的值
    int bit[20], i = 0, len, j = 0, temp;
    //特殊情况
    if (k == 0)
    {
        res[0] = 'A';
        res[1] = 0;
        return;
    }
    while (k) //拆分k的每一位,个位数放在bit[0]
    {
        bit[i] = k % 10;
        k /= 10;
        i++;
    }
    len = i;
    for (i = len - 1; i > 0; i--) //从最高位移动,看各位数字,直到十位数
    {
        temp = bit[i] * 10 + bit[i - 1]; //这一位*10+下一位,
        if (9 < temp && temp < 26)       //如果是十位数,则填入对应字母,并且移动两位
        {
            res[j] = 'A' + temp;
            i--;
        }
        else //如果不是十位数,填入当前位对应字母,只移动一位
        {
            res[j] = 'A' + bit[i];
        }
        j++; //字符数组已经填入一个字母了,下标后移至下次填入的位置
    }
    //因为i=0时35行 "bit[i - 1]" 会越界,所以将i=0单独列出
    if (i == 0) //只有可能是个位数了
    {
        res[j] = 'A' + bit[i];
        j++;
    }
    res[j] = 0; //在字符串末尾加结束符
}

int main()
{
    int num[1005], i, len;
    char str[20];
    for (i = 0; i < 1000; i++)
    {
        scanf("%d", &num[i]);
        if (num[i] == -1)
        {
            num[i] = 0;
            break;
        }
    }
    len = i;
    for (i = 0; i < len; i++)
    {
        DigiTran(num[i], str);
        printf("%s ", str);
    }
    // putchar('.');
    return 0;
}