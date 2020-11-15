#include <iostream>
using namespace std;
struct Node
{
	int val;
	Node* lf,*rt;
};
bool flag = false;
void PreOrder(Node* tree);
Node* BuildTree();
void CountPath(Node* tree, int n, int cnt);
int main()
{
	int n;
	cin >> n;
	Node* tree = BuildTree();
	//PreOrder(tree);
	CountPath(tree, n, 0);
	if (flag)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;
}
Node* BuildTree()
{
	int tmp = 0;
	cin >> tmp;
	if (tmp == -1)
		return NULL;//empty node
	else
	{
		Node* p = new Node;
		p->val = tmp;//set the node
		p->lf = BuildTree();//build its children
		p->rt = BuildTree();
		return p;
	}
	
}
void PreOrder(Node* tree)
{
	if (tree != NULL)
	{
		cout << tree->val << " ";
		PreOrder(tree->lf);
		PreOrder(tree->rt);
	}
}
void CountPath(Node* tree, int n,int cnt)
{
	if (tree != NULL)
	{
		cnt += tree->val;
		if (tree->lf != NULL)
			CountPath(tree->lf, n, cnt);
		if (tree->rt != NULL)
			CountPath(tree->rt, n, cnt);//cut leaves or 队列 压入目前的cnt 空间换时间
		if (!tree->lf && !tree->rt)
			if (cnt == n)
				flag = true;
	}
}