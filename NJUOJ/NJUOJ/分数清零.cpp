#include <iostream>
using namespace std;
struct Loc
{
	int row, col;
};
int main()
{
	int m, n;
	cin >> m >> n;
	int** ptr = new int* [m];
	int* rowlist = new int[m];
	int* collist = new int[m];
	int rcnt = 0, ccnt = 0;
	Loc* judge = new Loc[n * m];
	int cnt = 0;
	for (int i = 0; i < m; ++i)
		ptr[i] = new int[n];
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> ptr[i][j];
			if (ptr[i][j] == 0)//输入时就进行标记
			{
				bool repr = false, repc = false;
				for (int k = 0; k < rcnt; ++k)
				{
					if (rowlist[k] == i)
					{
						repr = true;
						break;
					}
				}
				if (!repr)
					rowlist[rcnt++] = i;
				for (int k = 0; k < ccnt; ++k)
				{
					if (collist[k] == j)
					{
						repc = true;
						break;
					}
				}
				if (!repc)
					collist[ccnt++] = j;
			}
		}
	}/*
	 for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> ptr[i][j];
			if (ptr[i][j] == 0)
			{
				judge[cnt].row = i;
				judge[cnt++].col = j;
			}
		}
	}
	for (int i = 0; i < cnt; ++i)
	{
		for (int j = 0; j < n; ++j)
			ptr[judge[i].row][j] = 0;
		for (int j = 0; j < m; ++j)
			ptr[j][judge[i].col] = 0;//直接记行列减少冗余
	}*/
	for (int i = 0; i < rcnt; ++i)//clear row
	{
		for (int j = 0; j < n; ++j)
			ptr[rowlist[i]][j] = 0;
	}
	for (int i = 0; i < ccnt; ++i)
	{
		for (int j = 0; j < m; ++j)
			ptr[j][collist[i]] = 0;
	}
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << ptr[i][j] << " ";
		cout << endl;
	}
	return 0;
}