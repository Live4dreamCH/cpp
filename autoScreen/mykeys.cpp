#include<windows.h>

void in

int main()
{
    Sleep(10000);
    keybd_event(48,0,KEYEVENTF_EXTENDEDKEY,0);
    return 0;
}