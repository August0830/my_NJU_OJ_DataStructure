#include <iostream>
using namespace std;
void MakeList(int ptr, int* list, int n);
int main()
{
	int n = 0,ptr=0,num=0;
	cin >> n;
	int* list = new int[n];
	for(int i=0;i<n;++i)
	{
		cin >> ptr>>num;
		list[ptr - 1] = num;
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		int j = 0;
		for(; j < n; ++j)
		{
			if (list[j] == cnt)
			{
				cout << j+1 << " ";
				break;
			}
		}
		cnt = j + 1;
	}
	/*for (int i = 0; i < n; ++i)
		cout << list[i] << " ";*/
	//MakeList(1, list, n);
	return 0;
}
void MakeList(int ptr, int* list, int n)
{
	if (list[ptr-1] != 0)
		MakeList(list[ptr - 1], list, n);
	cout << ptr << " ";
}