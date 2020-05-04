/*
课本第五章第十四题
输出保留两位小数。
*/
#include <stdio.h>

int Xnext(double x)
{
    return x - (2 * x * x * x - 4 * x * x + 3 * x - 6) / (6 * x * x - 8 * x + 3);
}

int main()
{
    double Xcurr=1.5, Xpre=0;
    while (Xcurr-Xpre<-0.0001||0.0001<Xcurr-Xpre)
    {
        Xpre = Xcurr;
        Xcurr = Xnext(Xcurr);
    }
    printf("%.2f", Xcurr);
    return 0;
}