#include <iostream>
using namespace std;

int main()
{
    int n, a[105], i;
    cin >> n;
    for (i = n; i >= 0; i--)
    {
        cin >> a[i];
    }
    // cout << a[n];
    // if(n>1)
    // {
    //     cout << "x^" << n;
    // }
    // else if(n==1)
    // {
    //     cout << "x";
    // }
    for (i = n; i >= 1; i--)
    {
        if (a[i] == 0)
        {
            continue;
        }
        if (a[i] > 0 && i != n)
        {
            cout << '+';
        }
        if (a[i] == -1)
        {
            cout << "-";
        }
        else if (a[i] != 1)
        {
            cout << a[i];
        }
        cout << 'x';
        if (i > 1)
        {
            cout << '^' << i;
        }
    }
    if (n > 0)
    {
        if (a[0] > 0)
        {
            cout << '+';
        }
        if (a[0] != 0)
            cout << a[0];
    }
    else
    {
        cout << a[0];
    }
    return 0;
}