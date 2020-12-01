#include <iostream>
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	int* list = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> list[i];
	int* check = new int[n];
	for (int i = 0; i < n; ++i)
		check[i] = -1;
	int cnt = 0;
	int match = 0;
	for (int i = 0; i < n; ++i)
	{
		int index = list[i];
		if (index % 2 == 0)
		{
			check[index] =cnt;
			if (index<n-1 && check[index + 1] == cnt)
				match++;
		}
		else
		{
			check[index] = cnt;
			if (check[index - 1] == cnt)
				match++;

		}
		if (2 * match == i+1)
			cnt++;
	}
	cout << n / 2 - cnt << endl;
	return 0;
}//循环群？n/2-循环群数 假设最乱的情况