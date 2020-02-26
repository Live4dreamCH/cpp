#include <iostream>
using namespace std;

struct stu
{
    char name[100];
    long long id;
    int grade[3];
    void cheat(int which)
    {
        grade[which] = 0;
    }
};

int main()
{
    struct stu lch = {"dl", 2190000000, 100, 100, 100};
    cout << lch.name << endl
         << lch.id << endl;
    for (int i = 0; i < 3; i++)
        cout << lch.grade[i] << ' ';
    lch.cheat(0);
    cout << lch.grade[0];
    return 0;
}