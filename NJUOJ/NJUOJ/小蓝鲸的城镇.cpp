#include <iostream>
using namespace std;
void Union(int root1, int root2, int*& parent, int M);
int Count(int*& parent, int M);
int Find(int root, int* parent);
int main()
{
	int M=0, N;
	cin >> N;
	if (N == 0)
		cout << N;
	else
		cin >> M;
	int* parent = new int[N + 1];
	for (int i = 0; i <= N; ++i)
		parent[i] = -1;
	//for(int i=0;i<=N;)
	while (M != 0)
	{
		int root1, root2;
		cin >> root1 >> root2;
		Union(root1, root2, parent, N);
		M--;
	}
	int res = Count(parent, N);
	cout << res;
	return 0;
}
void Union(int root1, int root2,int*&parent,int M)
{
	int frt1 = Find(root1, parent); //cout << frt1 << " ";
	int frt2 = Find(root2, parent); //cout << frt2 << " ";
	if (frt1 != frt2)//压缩路径 否则深度太深
	{
		root1 = frt1;
		root2 = frt2;
		int tmp = parent[root1] + parent[root2];
		if (parent[root1] < parent[root2])//more nodes
		{
			parent[root2] = root1;
			parent[root1] = tmp;
		}
		else
		{
			parent[root1] = root2;
			parent[root2] = tmp;
		}
	}
	
}
int Find(int root,int*parent)
{
	while (parent[root] > 0)
		root = parent[root];
	return root;
}
int Count(int*& parent, int M)
{
	int res = 0;
	for (int i = 1; i <= M; ++i)
		if (parent[i] < 0)
			res++;
	return res - 1;
}