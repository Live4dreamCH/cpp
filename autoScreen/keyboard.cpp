//此程序用于模拟鼠标和键盘操作。
#include <windows.h>
int main()
{
    Sleep(3000); //留3秒用于我们把鼠标移到文档上
    for (int i = 1; i < 567; i++)
    {
        //模拟右键按下弹起
        mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
        mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
        //模拟按下'E'键
        keybd_event('E', (BYTE)0, 0, 0);
        keybd_event('E', (BYTE)0, KEYEVENTF_KEYUP, 0);
        Sleep(50);
        //模拟按下回车，对应确定保存
        keybd_event(VK_RETURN, 0, 0, 0);
        keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
        Sleep(100); //等待保存
        //模拟按下ctrl+PageDown键，对应翻页
        keybd_event(VK_CONTROL, (BYTE)0, 0, 0);
        keybd_event(VK_NEXT, (BYTE)0, 0, 0);
        keybd_event(VK_NEXT, (BYTE)0, KEYEVENTF_KEYUP, 0);
        keybd_event(VK_CONTROL, (BYTE)0, KEYEVENTF_KEYUP, 0);
        Sleep(50); //等待翻页
    }
    return 0;
}
