#include <iostream>
#include <string>
using namespace std;
int alph[26] = {};
int sum = 0;
struct Node
{
	int freq;
	char ch;
	Node* left;
	Node* right;
};//better using the space?
//template<class E>
class MinHeap
{
public:
	MinHeap(int sz) { heap = new Node*[sz]; maxSize = sz; };
	~MinHeap() { delete[] heap; };
	bool Insert(Node*& d);
	bool isEmpty() { return curSize == 0; }
	bool isFull(){return curSize == maxSize;}
	bool Remove(Node*& x);
	int curSize = 0;
	Node** heap;
private:
	int maxSize;
	void shiftUp(int end);
	void shiftDown(int start, int end);
};
//template <class E>
Node* Huff( MinHeap& minh);
void Depth(Node* tree, int cnt);
void midorder(Node* tree);
void postorder(Node* tree);
int main()
{
	string str;
	cin >> str;
	int strlen = str.length();
	MinHeap minh(strlen);
	for (int i = 0; i < 26; ++i)
		alph[i] = 0;
	for (int i = 0; i < strlen; ++i)
		alph[str[i] - 'A']++;
	/*for (int i = 0; i < 26;++i)
	{
		if (alph[i] != 0)
		{
			Node* tmp = new Node;
			tmp->left = NULL;
			tmp->right = NULL;
			tmp->ch = (char)('A' + i);
			tmp->freq = alph[i];
			minh.Insert(tmp);
		}
	}//build minheap
	*/
	Node* tree = Huff(minh);
	//midorder(tree); cout << endl;
	//postorder(tree);
	Depth(tree, 0);
	cout << sum;
	return 0;
}
void postorder(Node* tree)
{
	if (tree)
	{
		postorder(tree->left);
		postorder(tree->right);
		cout << tree->ch << " " << tree->freq << " ";
	}
}
void midorder(Node* tree)
{
	if (tree)
	{
		midorder(tree->left);
		cout << tree->ch << " " << tree->freq<<" ";
		midorder(tree->right);
	}
}
void Depth(Node* tree,int cnt)
{
	if (tree != NULL)
	{
		if (tree->left == NULL && tree->right == NULL)//leaf
		{
			int index = (int)(tree->ch - 'A');
			sum += alph[index] * =;
		}
		else
		{
			Depth(tree->left, cnt + 1);
			Depth(tree->right, cnt + 1);
		}
	}
}
bool MinHeap :: Insert(Node*& d)
{
	if (isFull())
	{
		cout << "heap is full" << endl;
		return false;
	}
	heap[curSize] = d;
	shiftUp(curSize);
	curSize++;
	//for (int i = 0; i < curSize; ++i)
		//cout << heap[i]->freq << " " << heap[i]->ch << " ";
	//cout << endl;
	return true;
}
void MinHeap::shiftDown(int start, int end)
{
	int i = start, j = 2 * i + 1;
	Node* tmp = heap[i];
	while (j <= end)
	{
		if (j<end && heap[j]->freq>heap[j + 1]->freq) j++;
		if (tmp->freq <= heap[j]->freq)
			break;
		else
		{
			heap[i] = heap[j];
			i = j;
			j = 2 * j + 1;
		}
	}
	heap[i] = tmp;
}
void MinHeap:: shiftUp(int end)//Êµ¼ÊµÄcurSize==
{
	int j = end, i=(j-1)/2;
	Node*temp = heap[j];
	while (j >0)
	{
		if (heap[i]->freq <= temp->freq)
			break;
		else
		{
			heap[j] = heap[i];
			j = i;
			i = (j - 1) / 2;
		}
	}
	heap[j] = temp;
}
bool MinHeap::Remove(Node*& x)
{
	if (isEmpty())
	{
		cout << "heap is empty" << endl;
		return false;
	}
	x = heap[0];
	heap[0] = heap[curSize-1];
	curSize--;
	shiftDown(0,curSize-1);
	//for (int i = 0; i < curSize; ++i)
		//cout << heap[i]->freq << " " << heap[i]->ch << " ";
	//cout << endl;
	return true;
}
Node* Huff(MinHeap &minh)
{
	Node* parent=NULL, *first=NULL, *second=NULL;
	int cnt = 0;
	for (int i = 0; i < 26; ++i)
	{
		if (alph[i] != 0)
		{
			Node* ntmp = new Node;
			ntmp->freq = alph[i];
			ntmp->ch = (char)('A' + i);
			ntmp->left=NULL;
			ntmp->right = NULL;
			minh.Insert(ntmp);
			cnt++;
		}
	}
	for (int i = 0; i < cnt-1; ++i)
	{
		minh.Remove(first);
		minh.Remove(second);
		parent= new Node;
		parent->freq = first->freq + second->freq;
		parent->ch = 'a';
		parent->left= first;
		parent->right = second;
		minh.Insert(parent);
	}
	minh.Remove(parent);
	return parent;
}//AABBBBBBBBBBBCCCDDDDDFHHHHHHHHHHHHHJJJJJJJJJJJJK