#include <iostream>
#include <cmath>
#define freq len
using namespace std;
struct Node
{
	double x;
	double y;
	double z;
	double len;
};
class MinHeap
{
public:
	MinHeap(int sz) { heap = new Node * [sz]; maxSize = sz; };
	~MinHeap() { delete[] heap; };
	bool Insert(Node*& d);
	bool isEmpty() { return curSize == 0; }
	bool isFull() { return curSize == maxSize; }
	bool Remove(Node*& x);
	void Print();
	int curSize = 0;
	Node** heap;
private:
	int maxSize;
	void shiftUp(int end);
	void shiftDown(int start, int end);
};
int main()
{
	int m = 0;
	cin >> m;
	MinHeap minhp(10000000);
	for (int i = 0; i < m; ++i)
	{
		char tmp;
		cin >> tmp;
		if (tmp == 'A')
		{
			Node* ntmp = new Node;
			if (!ntmp)
			{
				cout << "error";
				break;
			}
			//double x = 0, y = 0, z = 0;
			scanf("%lf",&ntmp->x);
			scanf("%lf", &ntmp->y);
			scanf("%lf", &ntmp->z);
			//cin >> ntmp->x >> ntmp->y >> ntmp->z;
			//ntmp->x = x;
			//ntmp->y = y;
			//ntmp->z = z;
			ntmp->len = sqrt(ntmp->x * ntmp->x + ntmp->y * ntmp->y + ntmp->z * ntmp->z);
			minhp.Insert(ntmp);
		}
		else
		{
			int cnt = 0;
			cin >> cnt;
			double sum = 0;
			for (int j = 0; j < cnt; ++j)
			{
				Node* n;
				minhp.Remove(n);
				sum += n->len;
			}
			//c << sum / cnt << endl;
			printf("%.5f", sum / cnt);
			if (i != m - 1)
				printf("\n");
		}
	}
	return 0;
}
bool MinHeap::Insert(Node*& d)
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
void MinHeap::shiftUp(int end)//Êµ¼ÊµÄcurSize==
{
	int j = end, i = (j - 1) / 2;
	Node* temp = heap[j];
	while (j > 0)
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
	heap[0] = heap[curSize - 1];
	curSize--;
	shiftDown(0, curSize - 1);
	//for (int i = 0; i < curSize; ++i)
		//cout << heap[i]->freq << " " << heap[i]->ch << " ";
	//cout << endl;
	return true;
}
void MinHeap::Print()
{
	for(int i=0;i<=curSize;++i)
		printf("x=%.5f y=%.5f z=%.5f len=%.5f", heap[i]->x, heap[i]->y, heap[i]->z, heap[i]->len);
}