#include <cmath>
#include <iostream>
#include <stack>
// #include <algorithm>
#include <map>
#include <string>
using namespace std;

void number(const char &p, stack<double> &num);
void operate(const char &p, stack<double> &num, stack<char> &op);
bool doing(stack<double> &num, stack<char> &op);

double cal(string &p)
{
    stack<double> num;
    stack<char> op;
    for (int i = 0; i <= p.length(); i++)
    {
        number(p[i], num);
        operate(p[i], num, op);
    }
    while (!op.empty())
    {
        doing(num, op);
    }
    if (num.size() == 1)
        return num.top();
    else
    {
        cout << "No result!" << endl;
        system("pause");
        exit(-1);
    }
}

//字符串中提取数字，支持整数、小数
void number(const char &c, stack<double> &num)
{
    static stack<int> interger; //整数栈
    static bool pre = false;    //前一位是否为数字，连续性
    static bool dec = false;    //此位是否为小数decimal
    static double n = 0;        //临时存完整数字
    static int b = 1;           //整数位数
    static double w = 0.1;      //小数位数
    if ('0' <= c && c <= '9')
    {
        if (!dec)
        {
            interger.push(c - '0');
            pre = true;
        }
        else
        {
            n += (c - '0') * w;
            w /= 10;
        }
    }
    else if (c == '.')
    {
        b = 1;
        while (!interger.empty())
        {
            n += interger.top() * b;
            interger.pop();
            b *= 10;
        }
        dec = true;
        pre = true;
        w = 0.1;
    }
    else if (c == ' ' || c == '\t')
        ;
    else
    {
        if (pre && !dec)
        {
            b = 1;
            while (!interger.empty())
            {
                n += interger.top() * b;
                interger.pop();
                b *= 10;
            }
            num.push(n);
            n = 0;
            pre = false;
        }
        else if (pre && dec)
        {
            num.push(n);
            n = 0;
            dec = false;
            pre = false;
        }
    }
}

void operate(const char &c, stack<double> &num, stack<char> &op)
{
    static map<char, int> od;
    static bool l;
    od[')'] = od['('] = -1;
    od['+'] = od['-'] = 1;
    od['*'] = od['/'] = 2;
    od['^'] = 3;
    if (c == '(')
        op.push(c);
    else if (od.find(c) != od.end())
    {
        if (op.empty())
            op.push(c);
        else if (od[c] > od[op.top()])
            op.push(c);
        else
        {
            while (od[c] <= od[op.top()])
            {
                l = doing(num, op);
                if (op.empty() || l)
                    break;
            }
            if (c != ')')
                op.push(c);
        }
    }
    else if ((c < '0' || c > '9') && c != ' ' && c != '\t' && c != '.' && c != '\0')
    {
        cout << "invalid syntax: " << c << endl;
        system("pause");
        exit(-1);
    }
}

bool doing(stack<double> &num, stack<char> &op)
{
    //完了，必须在一遍内从p中读num和op，num和op的位置才对的上   搞定了
    char sym = op.top();
    op.pop();
    if (sym == '(')
        return true;
    double n1, n2;
    n1 = num.top();
    num.pop();
    n2 = num.top();
    num.pop();
    if (sym == '+')
        num.push(n2 + n1);
    else if (sym == '-')
        num.push(n2 - n1);
    else if (sym == '*')
        num.push(n2 * n1);
    else if (sym == '/')
        num.push(n2 / n1);
    else if (sym == '^')
        num.push(pow(n2, n1));
    return false;
}

void print(const double &r)
{
    cout << r << endl;
}

// (010. + .0024) *15-(12.34+ 0420.0310 )=
int main()
{
    string p;
    while (true)
    {
        getline(cin, p);
        print(cal(p));
    }
    return 0;
}