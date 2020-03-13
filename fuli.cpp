#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double base, interest, days, term;
    int c;
    cout << "本金：" << endl;
    cin >> base;
    cout << "1 利润 or 2 总额"<<endl;
    cin >> c >> interest;
    if (c == 2)
        interest -= base;
    cout << "持有时长" << endl;
    cin >> days;
    cout << "赎回时长：" << endl;
    cin >> term;

    double fuli;
    fuli = (pow(((interest / base) / days * term) + 1, 365 / term) - 1) * 100;
    cout << fuli << '%';
    system("pause");
    return 0;
}