/*
输入六位数的日期，输出是该年份的第几天。
除了main函数，要求编写判断闰年的函数和判断是第几天的函数。
输入格式：
20100205
输出：
35
 
20200302
 
20000802
*/
// #include <math.h>
#include <stdio.h>
 
int isLeapYear(int year)
{
    if(year%4==0&&year%100!=0)
        return 1;
    if(year%100==0&&year%400==0)
        return 1;
    return 0;
}
 
int getDay(int month, int date, int leap)
{
    int a[] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, days=0,i;
    if(leap)
        a[2] = 29;
    else
        a[2] = 28;
    for (i = 1; i < month;i++)
    {
        days += a[i];
    }
    days += date;
    return days;
}
 
int main()
{
    int input, year, month, date;
    scanf("%d", &input);
    year = input / 10000;
    input %= 10000;
    month = input / 100;
    date = input % 100;
    printf("%d", getDay(month, date, isLeapYear(year)));
    return 0;
}