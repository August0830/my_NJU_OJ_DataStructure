#include <iostream>
#include <stdio.h>
using namespace std;
struct Node
{
	int data;
	int next;
	int addr;
};
Node arr[99999];
void Print(int n, int start);
int main()
{
	int n, start;
	scanf_s("%d %05d", &start, &n);
	for (int i = 0; i < n; ++i)
	{
		int ptr;
		scanf_s("%d", &ptr);
		arr[ptr].addr = ptr;
		scanf_s("%d %05d", &arr[ptr].data, &arr[ptr].next);
	}
	Print(n, start);
	cout << endl;
	int reset = -1;
	int cur = start, pre = 0;
	//N cur = arr[start];
	//Node pre;
	for(int i=0;i<n;++i)
	{
		pre = cur;
		cur = arr[cur].next;//cur = arr[cur.next];
		arr[pre].next = reset;//pre.next = reset;
		reset = pre;//reset = pre.addr;
	}
	Print(n, reset);
	return 0;
}
void Print(int n, int start)
{
	for (int i = 0; i < n-1; ++i)
	{
		printf("%05d %d %05d\n", start, arr[start].data, arr[start].next);
		start = arr[start].next;
	}
	printf("%05d %d %d\n", start, arr[start].data, arr[start].next);
}