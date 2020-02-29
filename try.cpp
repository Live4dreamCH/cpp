#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> a;
    int t;
    for (int i = 0; i < 5; i++)
    {
        cin >> t;
        a.push(t);
    }
    for (int i = 0; i < 5; i++)
    {
        cout << a.top() << ' ';
        a.pop();
    }

    return 0;
}

// #include <string>
// string a;
// getline(cin, a); //可以接受空格、tab
// cout << a;
