// #include "audio_clip.h"
#include "AudioClip.cpp"
int main()
{
    AudioClip ac;
    ac.load("E:/bgm.mp3");
    ac.play();
    system("pause");
}