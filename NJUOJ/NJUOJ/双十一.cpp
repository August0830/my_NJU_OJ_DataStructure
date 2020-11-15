#include <iostream>
using namespace std;
struct Tri
{
	int row, col;
	int val;
};
int Construct(int n, int t, Tri*& A);
void Print(Tri* A, int n, int t);
int main()
{
	int n = 0, t = 0, m = 0;
	cin >> n >> t >> m;
	Tri* A = new Tri[n * t];
	Tri* B = new Tri[t * m];
	int cntA=Construct(n, t, A);
	int cntB=Construct(t, m, B);
	int** C = new int* [n];
	for (int i = 0; i < n; ++i)
	{
		C[i] = new int[m];
		for (int j = 0; j < m; ++j)
			C[i][j] = 0;
	}
	for (int i = 0; i < cntA; ++i)
	{
		for (int j = 0; j < cntB; ++j)
		{
			if (A[i].col == B[j].row)//矩阵相乘的计算方法 注意是累加
				C[A[i].row][B[j].col] += A[i].val * B[j].val;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cout << C[i][j] << " ";
		cout << endl;
	}
	delete []A;
	delete []B;
	//Print(C, n, m);
	delete []C;
	//Print(A, n, t);
	return 0;
}
int Construct(int n, int t, Tri*& A)
{
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < t; ++j)
		{
			int tmp = 0;
			cin >> tmp;
			if (tmp != 0)
			{
				A[cnt].row = i;
				A[cnt].col = j;
				A[cnt].val = tmp;
				cnt++;
			}
		}
	}
	return cnt;
}
void Print(Tri* A,int n,int t)
{
	int ptr = 0;
	for (int i = 0; i < n; ++i)
	{
		if (i == A[ptr].row)
		{
			for (int j = 0; j < t; j++)
			{
				if (j == A[ptr].col)
				{
					cout << A[ptr].val << " ";
					ptr++;
				}
				else
					cout << "0 ";
			}
		}
		else
		{
			for (int j = 0; j < t; ++j)
				cout << "0 ";
		}
		cout << endl;
	}
}