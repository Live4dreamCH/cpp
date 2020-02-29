#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int n, i, t, z, s;
    long long f, l;
    vector<int> po, ne;
    multimap
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        cin >> t;
        if(t>0)
        {
            po.push_back(t);
        }
        else if(t<0)
        {
            ne.push_back(t);
        }
        else
        {
            z++;
        }
    }
    s = po.size();
    for (f = 1, l = 1 << s; f < l;f++)
    {
        int sum = 0, num = 0;
        for (i = 0; i < s;i++)
        {
            if((f>>i)&1)
            {
                sum += po[i];
                num++;
            }
        }
    }
}