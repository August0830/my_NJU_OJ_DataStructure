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
		if (line[i] == -1)//ͬѧ�Ѿ����ų� �����һ��ͬѧ�ĺ�����
			continue;
		int j = i + 1;
		while (j < len)
		{
			cnt_i = 0;
			while (cnt_i != line[i] && j < len)
			{
				if (line[j] != -1) cnt_i++;//ͬѧû���ų� ���Լ���
				j++;
			}//cnt_i��֤����ͬѧ��Ӧ�ĺ����� ����ʱj����Ҫ���ų���ͬѧ����һ��ͬѧ
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
		cout << line[tag - 1] << endl;;//�������line����ĵ�n-1��λ�ü�Ϊ��
		cin >> n;
	}
	return 0;
}