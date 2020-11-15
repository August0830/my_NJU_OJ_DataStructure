#include <iostream>
using namespace std;
struct Node
{
	int val;
	Node* left, *right, *par;
};
template <class E>
class Queue
{protected:
	int rear, front;
	E* elements;
	int maxSize;
public:
	Queue(int sz) :front(0),rear(0), maxSize(sz)
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
void midorder(Node* tree);
Node* ppos, * qpos;
int p, q;
int main()
{
	cin >> p >> q;
	Node* tree = BuildTree();
	//midorder(tree);//
	int res = tree->val;
	Node* ip = ppos, * iq = qpos;
	bool find = false;
	while (ip!= NULL && !find)
	{
		while (iq!= NULL && !find)
		{
			if (ip->par == iq->par)
			{
				res = ip->par->val;
				find = true;
			}
			iq = iq->par;
		}
		ip = ip->par;
		iq = qpos;
	}
	cout << res;
	return 0;
}
Node* BuildTree()
{
	int n = 0;
	cin >> n;
	Queue<Node*> queue(1024);
	Node* root;
	int tmp = 0,cnt=0;
	cin >> tmp; cnt++;
	if (tmp == -1)
		return NULL;
	root = new Node;
	root->val = tmp;
	root->par = NULL;
	queue.En(root);
	while(cnt<n)//while (!q.isEmpty())
	{
		Node* node= new Node;
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
			if (ntmp == p)
				ppos = node->left;
			if (ntmp == q)
				qpos = node->left;
		}
		else
			node->left = NULL;
		cin >> ntmp; cnt++;
		if (ntmp != -1)
		{
			node->right = new Node;
			node->right->val = ntmp;
			node->right->left = NULL;
			node->right->right = NULL;
			node->right->par = node;
			queue.En(node->right);
			if (ntmp == p)
				ppos = node->right;
			if (ntmp == q)
				qpos = node->right;
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
void midorder(Node*tree)
{
	if (tree!=NULL)
	{
		midorder(tree->left);
		cout << tree->val << " ";
		midorder(tree->right);
	}
}
/*4
41
17
41 12 -1 44 22 36 20 24 4 11 38 27 35 52 49 43 54

*/