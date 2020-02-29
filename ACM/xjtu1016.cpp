#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int n, t;
    cin >> n;
    vector<int> a(n);
    priority_queue<int, vector<int>, greater<int>> odd, even;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        if (t % 2 == 0)
        {
            a[i] = 0;
            even.push(t);
        }
        else
        {
            a[i] = 1;
            odd.push(t);
        }
    }
    for (int i = 0; i < n;i++)
    {
        if(a[i])
        {
            a[i] = odd.top();
            odd.pop();
        }
        else
        {
            a[i] = even.top();
            even.pop();
        }
    }
    cout << a[0];
    for (int i = 1; i < n;i++)
        cout << ' ' << a[i];
    return 0;
}