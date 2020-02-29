#include <iostream>
#include <string>
using namespace std;
//48 57 97 122 65 90
//0  9  a  z   A  Z
int main()
{
    int f0[15] = {0}, l, fa[30] = {0}, fA[30] = {0};
    string c;
    cin >> c;
    l = c.length();
    for (int i = 0; i < l; i++)
    {
        if ('0' <= c[i] && c[i] <= '9')
            f0[c[i] - '0']++;
        else if ('a' <= c[i] && c[i] <= 'z')
            fa[c[i] - 'a']++;
        else
            fA[c[i] - 'A']++;
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < f0[i]; j++)
            cout << i;
    }
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < fa[i]; j++)
            cout << (char)('a' + i);
    }
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < fA[i]; j++)
            cout << (char)('A' + i);
    }

    return 0;
}