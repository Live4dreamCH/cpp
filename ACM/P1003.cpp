#include <iostream>
using namespace std;
struct ditan
{
    int a, b, g, k;
};

int main()
{
    int n, x, y, ans=-1;
    ditan ar[10005];
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        cin >> ar[i].a >> ar[i].b >> ar[i].g >> ar[i].k;
    }
    cin >> x >> y;
    for (int i = n-1; i >=0;i--)
    {
        if((x>=ar[i].a&&x<=ar[i].a+ar[i].g)&&(y>=ar[i].b&&y<=ar[i].b+ar[i].k))
        {
            ans = i + 1;
            break;
        }
    }
    cout << ans;
    return 0;
}