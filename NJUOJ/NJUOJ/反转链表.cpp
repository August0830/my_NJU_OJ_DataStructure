#include <stdio.h>
#include <iostream>
using namespace std;
struct Node
{
	int addr;
	int data;
	int next;
};
struct Link
{
	Node nod;
	Link* link;
};
Node Search(int next, Node* list,int n);
void PrintNode(Link* ptr);
int main()
{
	int n, start;
	scanf_s("%d %05d", &start, &n);
	Node* list = new Node[n];
	for (int i = 0; i < n; ++i)
	{
		Node *ntmp = new Node;
		ntmp->addr = 0; ntmp->data = 0; ntmp->next = 0;
		scanf_s("%05d %d %05d", &ntmp->addr, &ntmp->data, &ntmp->next);
		list[i] = *ntmp;
	}
	Link* ptr = new Link;
	Link* p = ptr;
	ptr->link = NULL;
	ptr->nod = Search(start, list, n);
	for (int i = 1; i < n; ++i)
	{
		p->link = new Link;
		p->link->link = NULL;
		p->link->nod = Search(p->nod.next,list,n);
		p = p->link;
	}
	//PrintNode(ptr);
	//cout << endl;//
	ptr->nod.next = -1;
	Link* nxt = ptr->link, * prev = ptr;
	ptr->link = NULL;
	while (nxt != NULL)
	{
		ptr = nxt;
		nxt = nxt->link;
		ptr->link = prev;
		ptr->nod.next = prev->nod.addr;
		prev = ptr;
	}
	ptr = prev;
	PrintNode(ptr);
	return 0;
}
Node Search(int next, Node* list,int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (list[i].addr == next)
			return list[i];
	}
}
void PrintNode(Link* ptr)
{
	while (ptr->link != NULL)
	{
		printf("%05d %d %05d\n", ptr->nod.addr, ptr->nod.data, ptr->nod.next);
		ptr = ptr->link;
	}
	printf("%05d %d %d\n", ptr->nod.addr, ptr->nod.data, ptr->nod.next);
}
//最后一个用例超时 怀疑是查找部分出问题