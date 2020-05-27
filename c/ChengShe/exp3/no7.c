/*
请根据课本第九章三、四、五题为基本要求，自己设计并完善一个学生成绩管理系统，包含多个自定义函数。
本题无测评。
*/
#include <stdio.h>

struct Student
{
    char num[30];
    char name[30];
    double score[3];
};

char *my_getstr(char *dest)
{
    char *origin = dest;
    char c;
    c = getchar();
    while (c != '\r' && c != EOF)
    {
        *dest = c;
        dest++;
        c = getchar();
    }
    *dest = 0;
    if (c=='\r')
    {
        getchar();
    }
    return origin;
}

void input(struct Student *s)
{
    my_getstr(s->num);
    my_getstr(s->name);
    scanf("%lf%lf%lf", &s->score[0], &s->score[1], &s->score[2]);
    getchar();
}

void print(struct Student *s)
{
    printf("%s,%s,%.2f,%.2f,%.2f", s->num, s->name, s->score[0], s->score[1], s->score[2]);
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
    print(&s[max_stu]);
    return 0;
}