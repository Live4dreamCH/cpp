#include <iostream>
// #include <queue>
// #include <utility>
using namespace std;

// class hugeint
// {
// public:
//     unsigned long long high, low;
//     hugeint() {}
//     hugeint(int x)
//     {
//         high = 0;
//         low = x;
//     }
//     hugeint operator+(const hugeint &ano)
//     {
//         hugeint t(0);
//         t.low = low + ano.low;
//         // 10000000000000000000;
//         // 00001000000000000000;
//         t.high = t.low / 10000000000000000;
//         t.low %= 10000000000000000;
//         t.high += high + ano.high;
//         return t;
//     }
//     hugeint operator*(int ano)
//     {
//         hugeint t(0);
//         t.low = low * ano;
//         t.high = t.low / 10000000000000000;
//         t.low %= 10000000000000000;
//         t.high += high * ano;
//         return t;
//     }
//     bool operator==(int ano)
//     {
//         return (high == 0 && low == ano);
//     }
//     bool operator==(const hugeint &ano)
//     {
//         return (high == ano.high && low == ano.low);
//     }
//     void print()
//     {
//         if (high == 0 && low == 0)
//         {
//             cout << '0';
//             return;
//         }
//         bool zeros = false;
//         int t;
//         if (high != 0)
//         {
//             zeros = true;
//             cout << high;
//         }
//         for (unsigned long long dig = 1000000000000000; dig > 0; dig /= 10)
//         {
//             t = low / dig;
//             if (t)
//             {
//                 zeros = true;
//                 cout << t;
//             }
//             else
//             {
//                 if (zeros)
//                     cout << '0';
//             }
//             low %= dig;
//         }
//     }
// };

long long memory[25][25];
int bx, by, horsex, horsey;
// pair<int, int> zb;
// queue<pair<int, int> > pre;

long long route(int currentx, int currenty)
{
    // zb.first = cx;
    // zb.second = cy;
    // pre.push(zb);
    if(memory[currentx][currenty] != 0)
        return memory[currentx][currenty];
    if ((currentx == horsex && currenty == horsey) || (currentx == horsex + 1 && currenty == horsey + 2) || (currentx == horsex + 2 && currenty == horsey + 1) || (currentx == horsex - 1 && currenty == horsey + 2) || (currentx == horsex - 2 && currenty == horsey + 1) || (currentx == horsex + 1 && currenty == horsey - 2) || (currentx == horsex + 2 && currenty == horsey - 1) || (currentx == horsex - 1 && currenty == horsey - 2) || (currentx == horsex - 2 && currenty == horsey - 1))
        memory[currentx][currenty] = 0;
    else if (currentx == bx && currenty == by)
    {
        // while(!pre.empty())
        // {
        //     cout << '(' << pre.front().first << ", "  << pre.front().second << ") ";
        //     pre.pop();
        // }
        // cout << endl;
        memory[currentx][currenty] = 1;
    }
    else if (currentx == bx)
    {
        memory[currentx][currenty] = route(currentx, currenty + 1);
    }
    else if (currenty == by)
    {
        memory[currentx][currenty] = route(currentx + 1, currenty);
    }
    else
        memory[currentx][currenty] = route(currentx + 1, currenty) + route(currentx, currenty + 1);
    return memory[currentx][currenty];
}

int main()
{
    cin >> bx >> by >> horsex >> horsey;
    for (int i = 0; i <= bx; i++)
    {
        for (int j = 0; j <= by; j++)
        {
            memory[i][j] = 0;
        }
    }
    cout << route(0, 0);
    return 0;
}