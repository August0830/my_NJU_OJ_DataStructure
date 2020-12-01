#include <iostream>
using namespace std;
struct Node
{
	int val;
	int nodes;//subtree number
	Node* left;
	Node* right;
	Node* par;
};
template <class E>
class Queue
{
protected:
	int rear, front;
	E* elements;
	int maxSize;
public:
	Queue(int sz) :front(0), rear(0), maxSize(sz)
	{
		elements = new E[maxSize];
	}
	~Queue() { delete[] elements; };
	void makeEmpty() { front = rear = 0; }
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % maxSize == front; }
	bool En(E x);
	bool De(E& x);
};
Node* BuildTree();
void MidOrder(Node* tree);
void CountNodes(Node*& tree);
int main()
{
	Node* tree = BuildTree();
	CountNodes(tree);
	//MidOrder(tree);
	return 0;
}

void CountNodes(Node*& tree)
{
	if (!tree->left && !tree->right)
		tree->nodes = 0;
	else if (!tree->left && tree->right)
	{
		CountNodes(tree->right);
		tree->nodes = 1 + tree->right->nodes;
	}
	else if (tree->left && !tree->right)
	{
		CountNodes(tree->left);
		tree->nodes = 1 + tree->left->nodes;
	}
	else
	{
		CountNodes(tree->left);
		CountNodes(tree->right);
		tree->nodes = tree->right->nodes + tree->left->nodes + 2;
	}
}
Node* BuildTree()
{
	int n = 0;
	cin >> n;
	Queue<Node*> queue(1024);
	Node* root;
	int tmp = 0, cnt = 0;
	cin >> tmp; cnt++;
	if (tmp == -1)
		return NULL;
	root = new Node;
	root->val = tmp;
	//root->par = NULL;
	queue.En(root);
	while (cnt < n)//while (!q.isEmpty())
	{
		Node* node = new Node;
		queue.De(node);
		int ntmp;
		cin >> ntmp; cnt++;
		if (ntmp != -1)
		{
			node->left = new Node;
			node->left->val = ntmp;
			node->left->left = NULL;
			node->left->right = NULL;
			node->left->par = node;
			queue.En(node->left);
		}
		else
			node->left = NULL;
		if (cnt >= n)
			break;
		cin >> ntmp; cnt++;
		if (ntmp != -1)
		{
			node->right = new Node;
			node->right->val = ntmp;
			node->right->left = NULL;
			node->right->right = NULL;
			node->right->par = node;
			queue.En(node->right);
		}
		else
			node->right = NULL;
	}
	return root;
}
template <class E>
bool Queue<E>::En(E x)
{
	if (isFull())
		return false;
	elements[rear] = x;
	rear = (rear + 1) % maxSize;
	return true;
}
template <class E>
bool Queue<E>::De(E& x)
{
	if (isEmpty())
		return false;
	x = elements[front];
	front = (front + 1) % maxSize;
	return true;
}
void MidOrder(Node* tree)
{
	if (tree != NULL)
	{
		MidOrder(tree->left);
		cout << tree->val << " "<<tree->nodes<<" ";
		MidOrder(tree->right);
	}
}