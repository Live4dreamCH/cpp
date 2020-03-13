#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> a(80);
    a[0] = 100;
    a[1] = 3000;
    a.emplace_back(3);
    a.emplace_front(7);
    return 0;
}