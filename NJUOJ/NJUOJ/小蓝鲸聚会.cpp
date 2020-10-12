#include <iostream>
using namespace std;
int main()
{
	int cnt = 0, cnt_i = 0, len = 100000;
	int line[100000];
	for (int i = 0; i < len; ++i)
		line[i] = i + 2;
	for (int i = 0; i < len && cnt < 3000; ++i)
	{
		if (line[i] == -1)//同学已经被排除 检查下一个同学的号码牌
			continue;
		int j = i + 1;
		while (j < len)
		{
			cnt_i = 0;
			while (cnt_i != line[i] && j < len)
			{
				if (line[j] != -1) cnt_i++;//同学没被排除 所以计入
				j++;
			}//cnt_i保证数够同学对应的号码牌 跳出时j是需要被排除的同学的下一个同学
			if (cnt_i == line[i])
				line[j - 1] = -1;
		}
		cnt++;
	}
	int n = -1;
	cin >> n;
	while (n != 0)
	{
		int cnt_res = 0, tag = 0;
		while (cnt_res < n)
		{
			if (line[tag] != -1)
				cnt_res++;
			tag++;
		}
		cout << line[tag - 1] << endl;;//整理过后line数组的第n-1个位置即为答案
		cin >> n;
	}
	return 0;
}