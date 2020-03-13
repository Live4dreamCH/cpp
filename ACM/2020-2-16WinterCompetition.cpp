// (a+b)%p = (a%p + b%p) %p
// a = p*k + x
// b = p*n + y
// (a*b)%p
// =((p*k + x)*(p*n + y))%p
// =(p^2*k*n+...+x*y)%p
// =(x*y)%p
// =((a%p)*(b%p))%p

// 1,1 -1,2 1,3 -1,4 1,0 -1,1

// 5,6 6,5 5,1 1,0

// 5,3
// 3,2 (?%2 =1 && ?>2) => ?=2+1=3
// 2,1
// 1,0 0
// fib:0 1 2 3 4 5 6  7  ...
// vl: 0 1 2 3 5 8 13 21 ...
// rt: 1 3 5 8 13 ...

// 12345

// 又是好长时间没写cpp了，555
# include<iostream>
// # include<string>
// # include<cmath>
// # include<vector>
// # include<algorithm>
// # include<stack>
// # include<map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n<4)
        cout << "NO";
    else
    {
        if(n == 4)
            cout << "4*3*2*1";
        else if(n==5)
            cout << "(5-2-1)*4*3";
        else if(n%2==0)
        {
            for (int i = n; i > 4;i++)
            {
                
            }
        }
    }
    return 0;
}