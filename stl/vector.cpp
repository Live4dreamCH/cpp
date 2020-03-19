#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //初始化
    {
        vector<int> a(10);                       //length=10,且全为0
        vector<int> b(20, 3);                    //len=20,且全为3
        vector<int> c(b);                        //c复制b
        vector<int> d = c;                       //d复制c
        vector<int> e(d.begin(), d.begin() + 3); //e复制d的一部分
        int arr[7] = {1, 2, 3, 4, 5, 6, 7};
        vector<int> f(arr, arr + 5); //数组(的一部分)转换成向量
        vector<vector<int>> matrix;  //矩阵
        for (int i = 0; i < 10; i++)
        {
            vector<int> t(10, i);
            matrix.emplace_back(t);
        }
    }

    //赋值
    {
        vector<int> a(10);
        a.push_back(4); //增加长度1,添加4
        a[3] = 4, a[0] = 10086;
        a[11] = -10086;        //本地越界但不报错
        cout << a[11] << endl; //可输出
        a.resize(15, 6);       //用6填充新空间
        cout << a[11] << endl; //6
        a.resize(4, 6);        //比原来短,后边数据丢失,参数6没用
        cout << a[11] << endl; //越界,但本地还是6
        a = {3, 6, 9};         //长度直接从11变成3,慎用
    }

    //迭代器,类似指针
    {
        vector<int> a(10);
        vector<int>::iterator p = a.begin();
        cout << *p << endl;
        p++;
        p += 1;
        p = p + 1;
    }

    //方法
    {
        vector<int> a(10);
        vector<int> b(20, 3);
        vector<int>::iterator p(a.begin() + 3);
        for (int i = 0; i < a.size(); i++)
        {
            a[i] = i * 10;
        }
        a.assign(b.begin(), b.begin() + 6); //把b的一部分赋值给a(现在a的内容和b的这一部分一样)
        a.assign(10, 2);                    //a变成10个2
        a.erase(p);                         //a[3]
        a.erase(a.begin() + 2);             //a[2]
        // a.erase(a.begin() + 1, a.begin() + 100); //[1,100),报错:越界
        a.erase(a.begin() + 1, a.begin() + 3); //[1,3),不报错
        for (int i = 0; i < a.size(); i++)
        {
            a[i] = i * 10;
        }
        cout << a.front() << endl; //第一个,可写可读
        cout << a.back() << endl; //最后一个,可写可读
        a.back() = 369;
        cout << a.back() << endl; //最后一个,可写可读
        a.clear();                //a为空
        cout << a.front() << endl; //第一个,可写可读
        // cout << a.back() << endl; //乱码
        a.resize(5);
        a.resize(1000); //全为0
    }
    return 0;
}