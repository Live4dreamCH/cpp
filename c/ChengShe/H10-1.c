/*
请按字典顺序罗列前六个大写字母ABCDEF能构成的所有组合。
每个组合中每个字母出现且仅出现一次。
输出格式为每个组合单列一行。
*/
#include <stdio.h>
#include <string.h>

char charset[] = {'A', 'B', 'C', 'D', 'E', 'F', 0}; //字符集
int len = 6;                                        //字符数

//在字符数组arr里找比字符base大的最小字符,将它删除(置零)并返回;
//如果没有,就返回0
char pop_min(char arr[], char base)
{
    int i, exist = 0, pos;
    char min = 127;
    for (i = 0; i < len; i++)
    {
        if (arr[i] > base)
        {
            if (arr[i] < min)
            {
                min = arr[i];
                pos = i;
                exist = 1;
            }
        }
    }
    if (exist)
    {
        arr[pos] = 0;
        return min;
    }
    else
        return 0;
}

//用line的前pos个字符刷新not_used(target)集合
void refresh(char target[], char line[], int pos)
{
    int i;
    strcpy(target, charset);
    for (i = 0; i < pos; i++)
    {
        target[line[i] - charset[0]] = 0;
    }
}

int main()
{
    char result[800][10], not_used[10], curr;
    int pointer = 0, line = 0, i, brk = 0;
    strcpy(not_used, charset);
    while (pointer >= 0) //pointer前进循环
    {
        //在没用过的字符里找最小的,写入到当前位置
        //如果找不到字符了,就会返回0,这时刚好这一个字符串应当结束,需要写入一个0
        curr = pop_min(not_used, 0);
        result[line][pointer] = curr;
        if (curr == 0)
        {
            while (curr == 0) //pointer后撤循环
            {
                pointer--;
                if (pointer < 0) //最后一行pointer会后撤至-1,以此为依据退出整个循环
                {
                    brk = 1;
                    break;
                }
                refresh(not_used, result[line], pointer);
                curr = pop_min(not_used, result[line][pointer]); //当前位置是否有比现在更大的字符可以写入?如果有就在下一行的对应位置写入,并继续前进;如果没有就继续后撤,寻找合适的位置
            }
            if (brk)
                break;
            line++;                       //换行
            for (i = 0; i < pointer; i++) //从上一行复制当前位置之前的字符
            {
                result[line][i] = result[line - 1][i];
            }
            result[line][pointer] = curr; //写入当前位置
        }
        pointer++; //前进
    }
    for (i = 0; i < 720; i++) //输出
        printf("%s\n", result[i]);
    return 0;
}