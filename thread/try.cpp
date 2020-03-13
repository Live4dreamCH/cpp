#include <iostream>
#include <thread>
using namespace std;

void fun(int i)
{
    cout << i << endl;
}

int main()
{
    system("D:/documents/Sources/c++/build/CalculatingMachine.exe");
    for (int i = 0; i < 10;i++)
    {
        thread t(fun, i);
        cout << "进程" << t.get_id() << "启动" << endl;
        t.join();
        // cout << t.joinable();
    }
    return 0;
}