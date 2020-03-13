#include <iostream>
// #include <cmath>
using namespace std;

class hugeint
{
public:
    unsigned long long high, low;
    hugeint() {}
    hugeint(int x)
    {
        high = 0;
        low = x;
    }
    hugeint operator+(const hugeint &ano)
    {
        hugeint t(0);
        t.low = low + ano.low;
        // 10000000000000000000;
        // 00001000000000000000;
        t.high = t.low / 10000000000000000;
        t.low %= 10000000000000000;
        t.high += high + ano.high;
        return t;
    }
    hugeint operator*(int ano)
    {
        hugeint t(0);
        t.low = low * ano;
        t.high = t.low / 10000000000000000;
        t.low %= 10000000000000000;
        t.high += high * ano;
        return t;
    }
    void print()
    {
        if (high == 0 && low == 0)
        {
            cout << '0';
            return;
        }
        bool zeros = false;
        int t;
        if (high != 0)
        {
            zeros = true;
            cout << high;
        }
        for (unsigned long long dig = 1000000000000000; dig > 0; dig /= 10)
        {
            t = low / dig;
            if (t)
            {
                zeros = true;
                cout << t;
            }
            else
            {
                if (zeros)
                    cout << '0';
            }
            low %= dig;
        }
    }
};

hugeint max(hugeint a, hugeint b)
{
    if (a.high > b.high)
        return a;
    if (a.high < b.high)
        return b;
    if (a.low > b.low)
        return a;
    return b;
}

hugeint memory[85][85];

hugeint dp(int ar[], hugeint two, int front, int end)
{
    if (front == end)
        return two * ar[front];
    if (memory[front][end].high == 0 && memory[front][end].low == 0)
        memory[front][end] = max(two * ar[front] + dp(ar, two * 2, front + 1, end), two * ar[end] + dp(ar, two * 2, front, end - 1));
    return memory[front][end];
}

int main()
{
    int n, m, a[85][85];
    hugeint sum = 0, two = 2;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        // front[i] = 0;
        // back[i] = m - 1;
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        two = 2;
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < m; k++)
            {
                memory[j][k] = 0;
            }
        }
        sum = sum + dp(a[i], two, 0, m - 1);
    }
    sum.print();
    return 0;
}

// dp{7 1 1 6 6 6}
// =max{7*2+dp{1 1 6 6 6},dp{7 1 1 6 6}+6*2}
// =max{14+max{1*4+dp{1 6 6 6},dp{1 1 6 6}+6*4},...}