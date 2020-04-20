// #include <cstdlib>
// #include <iostream>
#include <windows.h>

void clickL(int x, int y)
{
    SetCursorPos(x, y);
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);  //按下左键
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);    //松开左键
}

void showWeMeeting()
{
    clickL(1535, 863);
    Sleep(500);
    clickL(37, 625);
    clickL(37, 625);
    Sleep(700);
    SetCursorPos(1510, 52);
    Sleep(300);
    clickL(1510, 52);
    Sleep(1000);
    clickL(1276, 432);
    SetCursorPos(1535, 170);
}

void hideWeMeeting()
{
    SetCursorPos(1511, 10);
    Sleep(300);
    clickL(1511, 10);
    Sleep(500);
}

void showChrome()
{
    // clickL(1535, 863);
    // Sleep(1000);
    clickL(372, 847);
    Sleep(300);
    SetCursorPos(998, 688);
    Sleep(500);
    clickL(998, 688);
    SetCursorPos(1535, 170);
}

void hideChrome()
{
    SetCursorPos(1516, 843);
    Sleep(500);
    clickL(1516, 843);
    Sleep(500);
}

void startLuBo(int t=4000)
{
    clickL(1535, 863);
    Sleep(1000);
    clickL(40, 425);
    clickL(40, 425);
    Sleep(t);
    clickL(1348, 763);
    Sleep(300);
}

void endLuBo()
{
    startLuBo(1000);
    Sleep(1000);
    clickL(1527,14);
    Sleep(500);
    clickL(719,480);
    Sleep(500);
    clickL(1535, 863);
}

void webSource()
{
    char n;
    POINT p;
    //获取鼠标位置
    // while ((n = getchar()) == '\n')
    // {
    //     GetCursorPos(&p);
    //     // system("cls"); //包含在cstdlib中
    //     std::cout << p.x << " " << p.y << std::endl;
    // }
    //1535 863右下角,40 425快捷方式,1348 763录播按钮,1527 14关闭,719 480确认关闭,372 847chrome,37 625腾讯会议
    SetCursorPos(100, 100);                         //移动到指定位置
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);  //按下左键
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);    //松开左键
    mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0); //按下右键
    mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);   //松开右键
}

// int main()
// {
//     startLuBo();
//     Sleep(10000);
//     endLuBo();
//     // webSource();
//     return 0;
// }