#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    bool found = false;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < n-1;i++)
    {
        int j = (n + i) / 2, l = i, r = n;
        while(l<j&&j<r)
        {
            if(a[i]+a[j] == k)
            {
                found = true;
                break;
            }
            else if(a[i]+a[j] < k)
            {
                l = j;
                j = (l + r) / 2;
            }
            else
            {
                r = j;
                j = (l + r) / 2;
            }
        }
        if(found)
            break;
    }
    if(found)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}