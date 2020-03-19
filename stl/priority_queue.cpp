#include <iostream>
#include <queue>
using namespace std;

bool myless(int a, int b)
{
    return a < b;
}

int main()
{
    priority_queue<int> original; //默认大顶堆,max heap
    original.push(1);
    original.push(2);
    original.push(3);
    cout << original.top() << endl; //3

    priority_queue<int, vector<int>, less<int>> complete; //和上面等价,大顶堆,max heap
    complete.push(1);
    complete.push(2);
    complete.push(3);
    cout << complete.top() << endl; //3

    priority_queue<int, vector<int>, greater<int>> min_heap;//小顶堆
    min_heap.push(1);
    min_heap.push(2);
    min_heap.push(3);
    cout << min_heap.top() << endl;//1

    priority_queue<int, vector<int>, myless> my_max_heap;
    return 0;
}