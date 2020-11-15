#include<iostream>
#include <string>
using namespace std;
template <class E>
struct StackNode
{
public:
	E data;
	StackNode<E>* link;
	StackNode(E d = 0, StackNode<E>* next = NULL) :data(d), link(next) {};
};
template <class E>
class LinkedStack
{
private:
	StackNode<E>* top;//栈顶指针
public:
	LinkedStack() :top(NULL) {};
	~LinkedStack() { makeEmpty(); };
	void Push(E x);
	bool Pop();
	bool getTop(E& x) const;
	bool IsEmpty() const { return top == NULL; }
	void makeEmpty();
};
string toSuffix(string inffix);
long long int Cal(string suffix);
int main()
{
	string inffix;
	cin >> inffix;
	string suffix = toSuffix(inffix);
	long long int res = Cal(suffix);
	cout << res << endl;
	return 0;
}
string toSuffix(string inffix)
{
	string res; res.clear();
	LinkedStack<char> stk;
	stk.Push(' ');
	char c;
	for (auto& c : inffix)
	{
		if (c >= '0' && c <= '9')
		{
			res.push_back(c);
			res.push_back(' ');
		}
		else
		{
			while (!stk.IsEmpty())
			{
				int isp = 0, icp = 0;
				switch (c)
				{
					case '(':icp = 6; break;
					case 'x':icp = 4; break;
					case '+':icp = 2; break;
					case '-' : icp = 2; break;
					case ')':icp = 1; break;
					case ' ':icp = 0; break;
				}
				char ctmp;
				stk.getTop(ctmp);
				switch (ctmp)
				{
					case '(':isp = 1; break;
					case 'x':isp = 5; break;
					case '+':isp = 3; break;
					case '-' : isp = 3; break;
					case ')':isp = 6; break;
					case ' ':isp = 0; break;
				}
				if (icp > isp)
				{
					stk.Push(c);
					break;
				}
				else if (icp < isp)
				{
					stk.Pop();
					res.push_back(ctmp);
					res.push_back(' ');
				}
				else
				{
					stk.Pop();
					if (ctmp == '(')
						break;
				}
			}
			
		}
	}
	while (!stk.IsEmpty())
	{
		char ctmp;
		stk.getTop(ctmp);
		res.push_back(ctmp);
		res.push_back(' ');
		stk.Pop();
	}
	//cout << res << endl;//
	return res;
}
long long int Cal(string suffix)
{
	long long int res = 0;
	LinkedStack<long long int> stk;
	char c;
	int len = suffix.length();
	for (int i=0;i<len;++i)
	{
		c = suffix[i];
		if (c == ' ')
			continue;
		long long int oper = -1;
		while (c >= '0' && c <= '9')
		{
			if (oper == -1)
				oper = 0;
			oper = oper * 10 + (long long int)(c - '0');
			c = suffix[++i];//结束循环时已经移动到空格
		}
		if(oper!=-1)
			stk.Push(oper);
		else//是符号
		{
			long long int op1 = 0, op2 = 0;
			stk.getTop(op2); stk.Pop();
			stk.getTop(op1); stk.Pop();
			long long int restmp = 0;
			switch(c)
			{
			case '+': restmp = op1 + op2; break;
			case '-': restmp = op1 - op2; break;
			case 'x':restmp = op1 * op2; break;
			}
			stk.Push(restmp);
		}
	}
	stk.getTop(res);
	return res;
}
template <class E>
void LinkedStack<E>::makeEmpty()
{
	StackNode<E>* p;
	while (top != NULL)
	{
		p = top;
		top = top->link;
		delete p;
	}
}
template <class E>
void LinkedStack<E>::Push(E x)
{
	top = new StackNode<E>(x, top);
}
template <class E>
bool LinkedStack<E>::Pop()
{
	if (IsEmpty())
		return false;
	StackNode<E>* p = top;
	top = top->link;
	delete p;
	return true;
}
template <class E>
bool LinkedStack<E>::getTop(E &x) const
{
	if (top == NULL)
		return false;
	x = top->data;
	return true;
}