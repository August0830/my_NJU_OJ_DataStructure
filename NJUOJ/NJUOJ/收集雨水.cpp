#include <iostream>
using namespace std;
int main()
{
	int n = 0, s = n + 1;
	long long sum = 0,tmpsum = 0;//e8
	int ptr = -1;
	long long secondmax = -1;
	cin >> n;
	long long* arr = new long long [n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] != 0)
		{
			s = i;
			break;
		}
	}
	while (s < n)
	{
		int i = s + 1;
		for (; i < n; ++i)
		{
			if (arr[i] >= arr[s])
				break;
			else
			{
				tmpsum += arr[s] - arr[i];
				if (arr[i] >= secondmax)
				{
					secondmax = arr[i];
					ptr = i;
				}
			}
		}
		if (i == n)
		{
			if (ptr == s + 1||ptr==-1)//ptr是次高的下标 没有次高即右侧均比左侧高或者次高在最高旁边
				s = s + 1;
			else
			{
				for (int j = s + 1; j < ptr; ++j)//可以直接减
					sum += secondmax - arr[j];
				s = ptr;
			}
			ptr = -1;
			secondmax = -1;
			tmpsum = 0;
		}
		else
		{
			s = i;
			sum += tmpsum;
			tmpsum = 0;
			ptr = -1;
			secondmax = -1;
		}
	}
	cout << sum << endl;
	return 0;
}
/*8
0 2 1 3 1 0 2 1*/
//尽量在一遍遍历中获得需要的信息 注意提交的版本和修改的版本要一致