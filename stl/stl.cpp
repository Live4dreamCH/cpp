#include <algorithm>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

bool cmp(int a, int b);

int main()
{
    //vector:
    int size;
    vector<int> a(10); //length=10
    size = a.size();
    a.push_back(4);
    a[3] = 4;
    a;

    vector<int>::iterator p = a.begin();
    (*p == a[0]);
    p++;
    p += 1;
    p = p + 1;

    a.erase(p);
    a.erase(a.begin() + 2);
    a.erase(a.begin() + 3, a.begin() + 10);
    a.clear();
    a.resize(5);

    //stack
    stack<int> s;
    s.push(4);
    s.pop();
    s.top();
    s.empty();
    s.size();

    //queue
    queue<int> q;
    q.push(1);
    q.pop();
    q.front();
    q.empty();
    q.size();

    //priority_queue
    priority_queue<int> pq;                         //默认大顶堆
    priority_queue<int, vector<int>, less<int>> pq; //与上方等价
    pq.push(5);
    pq.pop();
    pq.top();
    pq.size();
    pq.empty();

    //set(集合)
    set<int> j;
    j.insert(1);
    j.insert(1); //元素具有唯一性
    j.count(1);  //1
    j.erase(1);

    set<int>::iterator jp = j.begin();
    jp != j.end();
    jp++; //only ++
    // jp += 1;     +=error
    // jp = jp + 1; +error

    multiset<int> mj; //可重复集合
    mj.insert(1);
    mj.insert(1); //可以添加
    mj.count(1);  //2

    //map(映射)
    map<string, int> m;
    m["apple"] = 1;
    m["banana"] = 2;
    m.find("cake"); //the iterator or m.end()

    //string
    string str;
    str = "Hello world!";
    string s1 = str;
    char c[100];
    strcpy(c, str.c_str());

    //pair in algorithm
    pair<int, int> pr(1, 10);
    pr.first;
    pr.second;

    //sort in algorithm
    int ab[100];
    sort(ab, ab + 100, cmp); //从小到大
    sort(a.begin(), a.end());
    return 0;
}

//从小到大
bool cmp(int a, int b)
{
    return a < b;
}