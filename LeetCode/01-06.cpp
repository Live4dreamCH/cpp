#include <iostream>
#include <string>
using namespace std;

int main()
{
    string instr, new_str;
    cin >> instr;
    int l = instr.size(), times;
    char t;
    for (int i = 0; i < l;i++)
    {
        if(t==instr[i])
        {
            times++;
        }
        else
        {
            new_str.push_back(t);
            new_str.push_back()
            t = instr[i];
        }
        t = instr[i];

    }
        return 0;
}