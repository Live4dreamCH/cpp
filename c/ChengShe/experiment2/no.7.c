/*
从键盘输入24小时制时间
5 16 32 8 5 30
表示5点16分32秒和8点8分30秒（默认后面的时间晚于前面的时间）
输出
时间差是2小时51分钟58秒。
*/
#include <stdio.h>

int main()
{
    int h1, m1, s1, h2, m2, s2, ds1 = 0, ds2 = 0, ds, h, m, s;
    scanf("%d%d%d%d%d%d", &h1, &m1, &s1, &h2, &m2, &s2);
    ds1 = h1 * 3600 + m1 * 60 + s1;
    ds2 = h2 * 3600 + m2 * 60 + s2;
    ds = ds2 - ds1;
    if (ds<0)
    {
        ds += 24 * 3600;
    }
    h = ds / 3600;
    m = (ds % 3600) / 60;
    s = ds % 60;
    printf("时间差是%d小时%d分钟%d秒。", h, m, s);
    return 0;
}