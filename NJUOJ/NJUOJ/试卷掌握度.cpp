#include <iostream>
using namespace std;
struct Node
{
	int val;
	Node* left;
	Node* right;
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
Node* BuildTree();
double Count(Node* tree);
int main()
{
	Node* tree = BuildTree();
	//MidOrder(tree);
	//printf("t %5lf t-l %5lf t-r %5lf", Count(tree), Count(tree->lchild), Count(tree->rchild));
	double max = 0;
	Queue<Node*> q(5000);
	q.En(tree);
	while (!q.isEmpty())
	{
		double res = 0;
		Node* tmp=new Node;
		if (q.De(tmp))
			res = Count(tmp);
		if (tmp->left)
			q.En(tmp->left);
		if (tmp->right)
			q.En(tmp->right);
		max = (max > res) ? max : res;
	}
	printf("%0.5lf", max);
	return 0;
}//避免重复计算 可以用递归 返回总数 用全局变量记录出现的最大掌握度

double Count(Node* tree)
{
	double res = 0;
	if (!tree)
		return res;
	Queue<Node*> q(5000);
	q.En(tree);
	int cnt = 0;
	double sum = 0;
	while (!q.isEmpty())
	{
		Node* tmp;
		if(q.De(tmp))
			cnt++;
		if (tmp->left)
			q.En(tmp->left);
		if (tmp->right)
			q.En(tmp->right);
		sum += tmp->val;
	}
	res = sum / cnt;
	return res;
}

void MidOrder(Node* tree)
{
	if (tree)
	{
		MidOrder(tree->left);
		cout << tree->val << " ";
		MidOrder(tree->right);
	}
}
Node* BuildTree()
{
	Queue<Node*> queue(5000);
	Node* root;
	int tmp = 0, cnt = 0;
	cin >> tmp; 
	if (tmp == -1)
		return NULL;
	root = new Node;
	root->val = tmp;
	queue.En(root);
	while (!queue.isEmpty())
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
			queue.En(node->left);
		}
		else
			node->left = NULL;
		cin >> ntmp; 
		if (ntmp != -1)
		{
			node->right = new Node;
			node->right->val = ntmp;
			node->right->left = NULL;
			node->right->right = NULL;
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