#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a[5] = {3, 7, 2, 8, 1};//默认从小到大
    sort(a, (a + 5));
    cout << a[0] << endl;//1
    sort(a, (a + 5));
    cout << a[0] << endl;//1
    return 0;
}