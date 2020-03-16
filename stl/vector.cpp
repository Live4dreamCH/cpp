#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int len;
    vector<int> a(10); //length=10,且全为0
    len = a.size();
    a.push_back(4); //增加长度,添加4
    a[3] = 4, a[0] = 10086;
    // a = {3, 6, 9}; //长度直接从11变成3,慎用

    vector<int>::iterator p = a.begin();
    cout << *p;
    p++;
    p += 1;
    p = p + 1;

    for (int i = 0; i < a.size(); i++)
    {
        a[i] = i * 10;
    }

    a.erase(p);
    a.erase(a.begin() + 2);
    a.erase(a.begin() + 3, a.begin() + 5); //[3,5)
    a.clear();
    a.resize(5);
    a.resize(1000); //全为0
    return 0;
}