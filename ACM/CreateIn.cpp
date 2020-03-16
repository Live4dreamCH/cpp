#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    for (int i = 0; i < 10;i++)
    {
        cout << '[';
        for (int j = 0; j < 10;j++)
        {
            cout << rand() % 20 + 1<<',';
        }
        cout << "]\n";
    }
    return 0;
}