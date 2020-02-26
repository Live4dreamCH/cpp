# include <iostream>
# include <ctime>
# include <string>
// # include <vector>
using namespace std;

// n
// 1
// n
// nlogn

long long a = 0;
long long p[10000];

long long fib(int x)
{
    a++;
    if(x<=2)
        return 1;
    if(p[x]!=-1)
        return p[x];
    p[x] = fib(x - 1) - fib(x - 2);
    return fib(x - 1) - fib(x - 2);
}

int main()
{
    cout << "中文？" << endl;
    clock_t start, end;
    double sec;
    long long r;
    for (int i = 0; i < 10000;i++)
    {
        // for (int j = 0; j < 10000;j++)
        //     p[j] = -1;
        p[i] = -1;
        a = 0;
        start = clock();
        r = fib(i);
        end = clock();
        sec = (end - start) / double(CLOCKS_PER_SEC);
        cout << "所求位数：" << i << ' ' << "答案：" << r << ' ' << "递归次数：" << a << ' ' << "时间：" << sec << endl;
    }
}