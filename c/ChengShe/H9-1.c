/*
将计算第二天的日期的程序中的自定义函数全部改成用指针做形参。
输入格式为
2002 2 6
输出格式为
2002-2-7
*/
#include <stdio.h>

struct date
{
    int year;
    int month;
    int day;
};


int isLeapYear(int *year)
{
    if (*year % 4 == 0 && *year % 100 != 0)
        return 1;
    if (*year % 100 == 0 && *year % 400 == 0)
        return 1;
    return 0;
}

void nextDay(struct date *origin)
{
    int a[] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(isLeapYear(&origin->year))
        a[2] = 29;
    else
        a[2] = 28;
    if(origin->day!=a[origin->month])
        origin->day++;
    else
    {
        origin->day = 1;
        if (origin->month!=12)
        {
            origin->month++;
        }
        else
        {
            origin->month = 1;
            origin->year++;
        }
    }
}

// int getDay(int *month, int *date, int *leap)
    // {
    //     int a[] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, days = 0, i;
    //     if (*leap)
    //         a[2] = 29;
    //     else
    //         a[2] = 28;
    //     for (i = 1; i < *month; i++)
    //     {
    //         days += a[i];
    //     }
    //     days += *date;
    //     return days;
    // }

int main()
{
    // int input, year, month, date;
    // scanf("%d", &input);
    // year = input / 10000;
    // input %= 10000;
    // month = input / 100;
    // date = input % 100;
    // printf("%d", getDay(&month, &date, (isLeapYear(&year))));
    // return 0;
    struct date a;
    scanf("%d%d%d", &a.year, &a.month, &a.day);
    nextDay(&a);
    printf("%d-%d-%d", a.year, a.month, a.day);
    return 0;
}