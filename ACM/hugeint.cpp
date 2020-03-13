#include <iostream>
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
    bool operator==(int ano)
    {
        return (high == 0 && low == ano);
    }
    bool operator==(const hugeint &ano)
    {
        return (high == ano.high && low == ano.low);
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
