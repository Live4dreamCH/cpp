#include <iostream>
#include <windows.h>
// #include <cstdlib>

int main()
{
    char n;
    POINT p;
    //获取鼠标位置
    while ((n = getchar()) == '\n')
    {
        GetCursorPos(&p);
        // system("cls"); //包含在cstdlib中
        std::cout << p.x << ", " << p.y << std::endl;
    }
    //1535 863右下角,40 425快捷方式,1348 763录播按钮,1527 14关闭,719 480确认关闭,372 847chrome,37 625腾讯会议
    //1510, 52腾讯会议全屏键 | 1535, 170腾讯会议鼠标贴边 | 1511, 10腾讯会议退出全屏 | 1276, 432贴边隐藏名字
    //998, 688Chrome全屏键(需延迟) | 1516, 843Chrome退出全屏

    // SetCursorPos(100, 100);                         //移动到指定位置
    // mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);  //按下左键
    // mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);    //松开左键
    // mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0); //按下右键
    // mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);   //松开右键
    return 0;
}
