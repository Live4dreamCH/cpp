#include <stdlib.h>
#include <windows.h>
int main(int argc, char *argv[])
{
    PlaySoundW(L"C:\\WINDOWS\\Media\\Windows XP 启动.MP3", NULL, SND_FILENAME | SND_ASYNC);
    system("pause");
    return 0;
}