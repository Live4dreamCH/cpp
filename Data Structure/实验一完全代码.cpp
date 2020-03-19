/*
6 10
1 8 4 3 5 2
*/
#include <iostream>
using namespace std;

template<class T>
class stack	//由于此问题中，栈的最大长度即为物件数，故使用顺序栈
{
	int MaxSize;
	T* base;
	int top;
public:
	stack(int size)
	{
		if (size < 0)
		{
			cerr << "长度不能为负！";
			exit(0);
		}
		else
		{
			MaxSize = size;
			base = new T[MaxSize];
			if (base == NULL)
			{
				cerr << "创建失败！";
				exit(0);
			}
			else
			{
				top = 0;
				cout << "创建栈成功，长度为" << MaxSize << endl;
			}
		}
	}
	stack(const stack &a)
	{
		MaxSize = a.MaxSize;
		MaxSize;
		base=a.base;
		top=a.top;
	}
	~stack()	//摧毁栈
	{
		delete[]base;
	}
	bool IsEmpty()const
	{
		if (top == 0)
			return true;
		return false;
	}
	bool IsFull()const
	{
		if (top == MaxSize)
			return true;
		return false;
	}
	void clear()	//清空元素
	{
		top = 0;
	}
	int len()const	//求长度
	{
		return top;
	}
	void push(T &e)
	{
		if (IsFull())
			cout << "栈已满，无法插入！" << endl;
		else
			base[top++] = e;
	}
	T pop()			//返回并删除栈顶元素
	{
		if (IsEmpty())
			cout << "栈为空，无法弹出！" << endl;
		else
			return base[--top];
	}
	T GetTop()	//仅返回栈顶元素，但不删除
	{
		if (IsEmpty())
			cout << "栈为空，无法获取！" << endl;
		else
			return base[top - 1];
	}
	T add()			//对栈进行魔改233
	{
		T sum=0;
		for (int i = 0; i < top; i++)
		{
			sum += base[i];
		}
		return sum;
	}
	void print()	//测试用
	{
		/*for (int i = 0; i < top; i++)
		{
			cout << base[i] << ends;
		}
		cout << endl;*/

		cout << '{' << base[0];
		for (int i = 1; i < top; i++)
		{
			cout << ',' << base[i];
		}
		cout << '}' << endl;
	}
};

template<class T>
int search(T *l, T e, int n)		//在最大长度为n的数组l中查找元素e的下标
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (e == l[i])
			return i;
	}
	return -1;
}

template<class T>
void fullpack(T *t, int n, T v, stack<T> &pack)
{
	int curr = 0, prev = -1;
	if (n == 1)	//排除单元素情况，避免死循环
	{
		if (t[0] == v)
			cout << '{' << t[0] << '}' << endl;
		cout << "求解完毕！";
	}
	else
	{
		pack.push(t[0]);
		do
		{
			cout << "curr=" << curr << ends << "prev=" << prev << ends << "测试输出：";		//测试
			pack.print();		//测试
			if (pack.add() == v)		//满足条件就输出
				pack.print();
			if (curr < n - 1)		//没有触碰到最后元素时curr前移
			{
				if (pack.add() >= v)		//超过体积则抛出
				{
					pack.pop();
					curr++;
				}
				else
				{
					prev = curr;
					curr++;
				}
			}
			else if (curr == n - 1)	//触碰到最后一个元素，则将倒数第二个元素前移
			{
				pack.pop();
				if (!pack.IsEmpty())	//防最后一次循环的空栈
					pack.pop();
				curr = prev + 1;
				prev = pack.IsEmpty() ? curr : search(t, pack.GetTop(), n);		//防空栈
			}
			pack.push(t[curr]);
		} while (curr < n);
		cout << "求解完毕！" << endl;
	}
}

template<class T>
void bestpack(T *t, int n, T v, stack<T> &pack, float *vl)
{
	int curr = 0, prev = -1;
	stack<float> value(n);
	pack.clear();
	float max = 0;
	if (n == 1)	//排除单元素情况，避免死循环
	{
		if (t[0] <= v)
			cout << '{' << t[0] << '}' << "最大价值为：" << vl[0] << endl;
		cout << "求解完毕！";
	}
	else
	{
		pack.push(t[0]);
		value.push(vl[0]);
		do
		{
			cout << "curr=" << curr << ends << "prev=" << prev << ends << "价值为：" << max << ends << "测试输出：";		//测试
			pack.print();		//测试
			//if (pack.add() == v)		//满足条件就输出
				//pack.print();
			if (value.add() > max)
			{
				max = value.add();
				cout << "最大价值为：" << max << ends;
				pack.print();
			}
			if (curr < n - 1)		//没有触碰到最后元素时curr前移
			{
				if (pack.add() >= v)		//超过体积则抛出
				{
					pack.pop();
					value.pop();
					curr++;
				}
				else
				{
					prev = curr;
					curr++;
				}
			}
			else if (curr == n - 1)	//触碰到最后一个元素，则将倒数第二个元素前移
			{
				pack.pop();
				value.pop();
				if (!pack.IsEmpty())	//防最后一次循环的空栈
					pack.pop();
				if(!value.IsEmpty())
					value.pop();
				curr = prev + 1;
				prev = pack.IsEmpty() ? curr : search(t, pack.GetTop(), n);		//防空栈
			}
			pack.push(t[curr]);
			value.push(vl[curr]);
		} while (curr < n);
		cout << "求解完毕！" << endl;
	}
}

int main()
{
	int n, *t, i, v;		//n数量，t物品，v总体积，curr当前压入元素的下标，prev栈中前一个元素的下标（若无前一个元素，则为当前元素）
	cout << "请输入物品件数n和总体积V：（用空格或回车分割）" << endl;
	cin >> n >> v;
	if (n <= 0)	//健壮
	{
		cerr << "无物品，无需求解！";
		return 0;
	}
	t = new int[n];
	stack<int> pack(n);

	cout << "请输入各物体体积：（用空格或回车分割）" << endl;
	for (i = 0; i < n; i++)
	{
		cin >> t[i];
		if (t[i] <= 0)	//健壮
		{
			cerr << "物品体积有误！";
			return 0;
		}
	}
	//输入完成

	fullpack(t, n, v, pack);		//求解装满背包问题

	float *vl;	//每件物品的价值数组
	vl = new float[n];
	cout << "请输入各物体价值：（用空格或回车分割）" << endl;
	for (i = 0; i < n; i++)
	{
		cin >> vl[i];
		if (vl[i] <= 0)	//健壮
		{
			cerr << "物品价值有误！";
			return 0;
		}
	}
	bestpack(t, n, v, pack, vl);	//求解最优背包问题

	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
