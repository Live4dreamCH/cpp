#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long a;
    long long t = 2;
    cin >> a;
    cout << 1 << ' ';
    while (a)
    {
        if (a % t == 0)
        {
            a /= t;
            cout << t << ' ';
        }
        else if(t<a)
        {
            t++;
        }
        else
            break;
    }
    return 0;
}

// #include <string>
// string a;
// getline(cin, a); //可以接受空格、tab
// cout << a;
