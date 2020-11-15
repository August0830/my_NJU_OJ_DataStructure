#include <iostream>
using namespace std;
struct Node
{
	int val;
	Node* left, * right;
};
int mid[31] = {};
int post[31] = {};
Node stack[32] = {};//double direction stack(??)
int front = -1;
int rear = 32;
Node* BuildTree(int start, int end, int root);
void PostOrder(Node* tree);
void PreOrder(Node* tree);
void midOrder(Node* tree);
void Solution(Node* tree);
bool IsEmptyLeft();
bool IsEmptyRight();
void push(bool left, Node* ptr);
Node* pop(bool left);
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> mid[i];
	for (int i = 0; i < n; ++i)
		cin >> post[i];
	Node* tree = BuildTree(0, n - 1,n-1);
	/*PostOrder(tree); cout << endl;
	PreOrder(tree); cout << endl;
	midOrder(tree); cout << endl << endl;*/
	Solution(tree);
	return 0;
}
void Solution(Node* tree)
{
	bool left = true;//true->push or pop left side
	push(left, tree);
	while (!IsEmptyLeft() || !IsEmptyRight())
	{
		while (left && !IsEmptyLeft())
		{
			Node* tmp = pop(left);
			cout << tmp->val << " ";
			if (tmp->right != NULL)
				push(!left, tmp->right);
			if (tmp->left != NULL)
				push(!left, tmp->left);//push to the opposite side
		}
		while(!left && !IsEmptyRight())
		{
			Node* tmp = pop(left);
			cout << tmp->val << " ";
			if (tmp->left != NULL)
				push(!left, tmp->left);
			if (tmp->right != NULL)
				push(!left, tmp->right);
		}
		left = !left;
	}
}
bool IsEmptyLeft()
{
	return front == -1;
}
bool IsEmptyRight()
{
	return rear == 32;
}
Node* pop(bool left)
{
	Node* res = NULL;
	if (left && !IsEmptyLeft())
	{
		res = &stack[front--];
	}
	else if(!left && !IsEmptyRight())
	{
		res = &stack[rear++];
	}
	return res;
}
void push(bool left, Node* ptr)
{
	if (left)
	{
		stack[++front] = *ptr;
	}
	else
		stack[--rear] = *ptr;
}
Node* BuildTree(int start,int end,int root)
//root used in post;start and end used in mid
{
	Node* p = new Node;
	p->val = post[root];
	if (start == end)
	{
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		int i = start;
		for (; i <= end; ++i)
			if (mid[i] == p->val)
				break;
		int rightlen = end - i;
		int leftlen = i - start;
		if (leftlen > 0)
			p->left = BuildTree(start, start + leftlen-1, root - rightlen -1);
		else
			p->left = NULL;
		if (rightlen > 0)
			p->right = BuildTree(i+1, end, root - 1);
		else
			p->right = NULL;
	}
	return p;
}
void PostOrder(Node* tree)
{
	if (tree != NULL)
	{
		
		PostOrder(tree->left);
		PostOrder(tree->right);
		cout << tree->val<<" ";
	}
}
void PreOrder(Node* tree)
{
	if (tree != NULL)
	{
		cout << tree->val << " ";
		PreOrder(tree->left);
		PreOrder(tree->right);
	}
}
void midOrder(Node* tree)
{
	if (tree != NULL)
	{
		midOrder(tree->left);
		cout << tree->val << " ";
		midOrder(tree->right);
	}
}