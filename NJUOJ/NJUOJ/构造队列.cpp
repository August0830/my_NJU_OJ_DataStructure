# include <iostream>
using namespace std;
void Build(int*& ptr, int n);
int main()
{
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; ++i)
	{
		int n;
		cin >> n;
		int* ptr = new int[n];
		for (int j = 0; j < n; ++j)
			ptr[j] = 0;
		Build(ptr, n);
		for (int j = 0; j < n-1; ++j)
			cout << ptr[j] << " ";
		cout << ptr[n - 1] << endl;
		delete[] ptr;
	}
	return 0;
}
void Build(int*& ptr, int n)
{
	int s = -1;
	for (int i = 1; i <= n; ++i)
	{
		int j = 0;
		while (j < 2)
		{
			s = (s + 1) % n;
			if (ptr[s] == 0)
				j++;
		}
		ptr[s] = i;
	}
}