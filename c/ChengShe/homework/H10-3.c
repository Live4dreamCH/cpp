/*
请注意在本机的换行是\n一个字符，在服务器是\r\n两个字符。
可以用
while( ( getcharegg ) != '\n )
;
试一下
有10个学生，每个学生的数据包括学号、姓名、三门课的成绩，从键盘输入学生数据，姓名可能有空格。
1、用结构体数组实现
2、编写input函数，输入一个学生的数据
3、编写output函数，输出一个学生的数据
4、输出三门课总平均成绩（所有学生所有成绩的平均值）
5、输出三门课总成绩最高的学生的信息
6、用重定向和键盘输入都尝试实现
输入格式为
2019001
Xue Sheng 1
88.5 88.0 88.5
2019002
Xue Sheng 2
88.0 92.0 86.0
2019003
Xue Sheng 3
86.5 91.5 93.5
2019004
Xue Sheng 4
90.5 95.0 87.0
2019005
Xue Sheng 5
93.5 89.0 94.0
2019006
Xue Sheng 6
83.0 91.5 92.5
2019007
Xue Sheng 7
88.0 84.5 92.0
2019008
Xue Sheng 8
81.5 92.5 87.5
2019009
Xue Sheng 9
86.5 93.5 82.0
2019010
Xue Sheng 10
92.5 90.0 88.0
输出格式保留两位小数为
The average score of all of the courses is 89.23
The information of the sutdent with the highest score is:
2019005,Xue Sheng 5,93.50,89.00,94.00
*/
#include <stdio.h>

struct Student
{
    char number[30];
    char name[20];
    double score[3];
};

char *my_gets(char *str)
{
    char c, *front = str;
    while ((c = getchar()) != '\r')
    {
        *str = c;
        str++;
    }
    *str = 0;
    getchar();
    return front;
}

void input(struct Student *s)
{
    my_gets(s->number);
    my_gets(s->name);
    scanf("%lf%lf%lf", &s->score[0], &s->score[1], &s->score[2]);
    getchar();
}

void output(struct Student *s)
{
    printf("%s,%s,%.2f,%.2f,%.2f", s->number, s->name, s->score[0], s->score[1], s->score[2]);
}

int main()
{
    struct Student s[10];
    int i, max_stu = -1;
    double average = 0, total[10], max_score = -1;
    for (i = 0; i < 10; i++)
    {
        input(&s[i]);
        total[i] = s[i].score[0] + s[i].score[1] + s[i].score[2];
        average += total[i];
    }
    printf("The average score of all of the courses is %.2f\nThe information of the sutdent with the highest score is:", average / 30);
    for (i = 0; i < 10; i++)
    {
        if (total[i] > max_score)
        {
            max_score = total[i];
            max_stu = i;
        }
    }
    output(&s[max_stu]);
    return 0;
}