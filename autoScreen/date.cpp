#include <ctime>
#include <iostream>
#include "mouse.cpp"

// struct tm {
//   int tm_sec;   // 秒，正常范围从 0 到 59，但允许至 61
//   int tm_min;   // 分，范围从 0 到 59
//   int tm_hour;  // 小时，范围从 0 到 23
//   int tm_mday;  // 一月中的第几天，范围从 1 到 31
//   int tm_mon;   // 月，范围从 0 到 11
//   int tm_year;  // 自 1900 年起的年数
//   int tm_wday;  // 一周中的第几天，范围从 0 到 6，从星期日算起
//   int tm_yday;  // 一年中的第几天，范围从 0 到 365，从 1 月 1 日算起
//   int tm_isdst; // 夏令时
// }

bool isAfterThisTime(int weekday, int hour, int minute, int second = 0)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    if(ltm->tm_wday==0)
        ltm->tm_wday = 7;

    if (ltm->tm_wday < weekday)
        return false;
    else if(ltm->tm_wday > weekday)
        return true;

    if (ltm->tm_hour < hour)
        return false;
    else if (ltm->tm_hour > hour)
        return true;

    if (ltm->tm_min < minute)
        return false;
    else if (ltm->tm_min > minute)
        return true;
        
    if(ltm->tm_sec<second)
        return false;
    return true;
}

void webTimeSourse()
{
    // 基于当前系统的当前日期/时间
    time_t now = time(0);

    std::cout << "1970 到目前经过秒数:" << now << std::endl;

    tm *ltm = localtime(&now);

    // 输出 tm 结构的各个组成部分
    std::cout << "年: " << 1900 + ltm->tm_year << std::endl;
    std::cout << "月: " << 1 + ltm->tm_mon << std::endl;
    std::cout << "日: " << ltm->tm_mday << std::endl;
    std::cout << "星期: " << ltm->tm_wday << std::endl;
    std::cout << "时间: " << ltm->tm_hour << ":";
    std::cout << ltm->tm_min << ":";
    std::cout << ltm->tm_sec << std::endl;
}

int main()
{
    // webTimeSourse();
    while (true)
    {
        if(isAfterThisTime(1, 11, 39))
            break;
        else
            Sleep(1000);
    }
    startLuBo();
    // showChrome();
    showWeMeeting();
    while (true)
    {
        if(isAfterThisTime(1, 11, 39, 20))
            break;
        else
            Sleep(1000);
    }
    // hideChrome();
    hideWeMeeting();
    endLuBo();
    return 0;
}