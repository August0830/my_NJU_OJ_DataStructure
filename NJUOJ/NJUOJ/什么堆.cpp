#include <iostream>
using namespace std;
int main()
{
	bool max = true, min = true;
	int N = 0;
	cin >> N;
	int* tree = new int[N];
	int* stack = new int[N];
	bool* check = new bool[N];
	for (int i = 0; i < N; ++i)
		check[i] = true;
	for (int i = 0; i < N; ++i)
		cin >> tree[i];
	int stk = 0;
	while (check[0])
	{
		int i = 0;
		int nxt = 2 * i + 2;
		while (nxt < N)
		{
			if (!check[nxt])
			{
				nxt = 2 * i + 1;
				if (!check[nxt] || nxt>=N)//
					check[i] = false;
			}
			if (!check[0])
				break;
			if (tree[i] < tree[nxt])
				max = false;
			if (tree[i] > tree[nxt])
				min = false;
			cout << tree[i] << " ";
			i = nxt;
			nxt = 2 * i + 2;
			if (nxt >= N || !check[nxt])//不能往下的两种情况 时刻调整
				nxt = 2 * i + 1;
		}
		if (!check[0])
			break;
		cout << tree[i] << " ";
		check[i] = false;//leaf is set
		int root = (i-1) / 2;
		while (root >= 0 && check[0])//回溯设置 att 0-1/2==0 
		{
			if ((2 * root + 1 >= N || !check[2 * root + 1]) && (2 * root + 2 >= N || !check[2 * root + 2]))
			{
				check[root] = false;
				root = (root - 1) / 2;
			}
			else
				break;
		}
		cout << endl;
	}
	if (max && !min)
		cout << "Max Heap";
	else if (min && !max)
		cout << "Min Heap";
	else
		cout << "Not Heap";
	return 0;
}
