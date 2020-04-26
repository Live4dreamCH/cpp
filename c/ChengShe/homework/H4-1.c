/*一个球从100m高度自由落下，每次落地反跳回原高度的一半，再落下，再反弹。
求它在第10次落地时，共经过多少米，第10次反弹多高。（保留6位小数）
105.111111 0.333333*/
#include <stdio.h>
 
int main()
{
    int i = 0;
    double height = 100, pass = -100;
    for (; i < 10; i++)
    {
        pass += height * 2;
        height /= 2;
    }
    printf("%.6f %.6f", pass, height);
    return 0;
}
