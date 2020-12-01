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
bool Check(Node* tree1, Node* tree2);
int main()
{
	Node* tree1 = BuildTree();
	Node* tree2 = BuildTree();
	//MidOrder(tree1);
	//MidOrder(tree2);
	if (Check(tree1, tree2))
		cout << "True";
	else
		cout << "False";
	return 0;
}
bool Check(Node* tree1, Node* tree2)
{
	if (tree1->val != tree2->val)
		return false;
	else if (!tree1 && !tree2)
		return true;
	else if(tree1 && tree2)
	{
		if (!tree1->left && !tree2->left && tree1->right && tree2->right)
			return Check(tree1->right, tree2->right);
		else if (!tree1->right && !tree2->right && tree1->left && tree2->left)
			return Check(tree1->left, tree2->left);
		else if (!tree1->left && !tree2->left && !tree1->right && !tree2->right)
			return true;
		else if (tree1->left && tree1->right &&
			tree2->left && tree2->right &&
			tree1->left->val == tree2->left->val && tree1->right->val == tree2->right->val)
			return Check(tree1->left, tree2->left) && Check(tree1->right, tree2->right);
		else if (tree1->left && tree1->right &&
			tree2->left && tree2->right && tree1->left->val == tree2->right->val && tree1->right->val == tree2->left->val)
			return Check(tree1->left, tree2->right) && Check(tree1->right, tree2->left);
		else if (!tree1->left && tree2->left && tree1->right && !tree2->right)
			return Check(tree1->right, tree2->left);
		else if (tree1->left && !tree2->left && !tree1->right && tree2->right)
			return Check(tree1->left, tree2->right);
		else
			return false;
	}
	else
		return false;
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
			//node->left->par = node;
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
		cout << tree->val << " ";
		MidOrder(tree->right);
	}
}