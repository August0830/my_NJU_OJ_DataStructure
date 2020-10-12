#include<iostream>
using namespace std;
struct Node
{
	int data;
	int index;
	Node* next;
};
bool push(Node*&top,int val, int pt)
{
	Node* tmp = new Node;
	if (tmp == NULL)
		return false;
	tmp->data = val;
	tmp->index = pt;
	tmp->next = NULL;
	if (top == NULL)
		top = tmp;
	else
	{
		tmp->next = top;
		top = tmp;
	}
	return true;
}
bool pop(Node*&top)
{
	if (top == NULL)
		return false;
	else
	{
		Node* tmp = top;
		top = top->next;
		delete tmp;
	}
	return true;
}
bool Print(Node* stack)
{
	if (stack == NULL)
		return false;
	Node* tmp = stack;
	while(tmp!=NULL)
	{
		cout << tmp->data << " " << tmp->index<<" ";
		tmp = tmp->next;
	}
	cout << endl;
	return true;
}
long long int Calculate(long long int* arr, int n);
int main()
{
	int T = 0;
	cin >> T;
	int n = 0;
	for (int i = 0; i < T; ++i)
	{
		cin >> n;
		long long int* arr = new long long int[n+1];
		for (int j = 0; j < n; ++j)
			cin >> arr[j];
		arr[n] = 0;//多置一位0保证全部弹出
		cout << Calculate(arr, n+1) << endl;;
	}
	/*Node* stack=NULL;
	for (int i = 0; i < 5; ++i)
	{
		push(stack,i,i+100);
	}
	Print(stack); 
	while(stack!=NULL)
	{
		cout << stack->data << " " << stack->index << endl;
		pop(stack);
		Print(stack);
	}错在哪？？*/
	return 0;
}
long long int Calculate(long long int* arr, int n)
{
	long long int sq = 0, finals = 0;
	Node* stack = NULL;
	for (int i = 0; i < n; ++i)
	{
		while (stack != NULL && stack->data > arr[i])
		{
				Node cur = *stack;//取地址和直接copy数据的区别 取地址会被释放
				cur.next = NULL;
				pop(stack);
				if (stack != NULL)
					sq = ((long long int)i - (long long int)stack->index - 1) * (long long int)cur.data;
				else
					sq = (long long int)i * (long long int)cur.data;
				if (sq > finals)
					finals = sq;
		}
		push(stack, arr[i], i);
	}
	return finals;
}
//不单独采用delta的时候会跳过一步不执行？？为什么？？ 
//比arr[start]小的不与其相邻 10 3 2 3 5 4 5 5 4 5 1 20
