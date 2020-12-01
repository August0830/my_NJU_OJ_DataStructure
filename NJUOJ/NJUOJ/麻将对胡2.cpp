#include <iostream>
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	int* list = new int[n];
	int* loc = new int[n];
	int index = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> index;
		list[i] = index;
		loc[index] = i;
	}
	index = 0;
	int cnt = 0;
	for (int i = 0; 2*i+1<n; i+=1)
	{
		int low = 2 * i;
		int high = 2 * i + 1;
		if (list[low] == list[high] + 1 ||
			list[low] + 1 == list[high])
			continue;
		index = list[low];
		int pair = 0;
		if (index % 2 == 0)
			pair = index + 1;
		else
			pair = index - 1;
		int locpair = loc[pair];
		int tmp = list[high];
		list[high] = pair;
		list[locpair] = tmp;
		loc[tmp] = locpair;
		loc[pair] = high;
		cnt++;
		/*for (int i = 0; i < n; ++i)
			cout << list[i] << " ";
		cout << endl;
		for (int i = 0; i < n; ++i)
			cout << loc[list[i]] << " ";
		cout << endl;*/
	}
	cout << cnt;
	return 0;
}