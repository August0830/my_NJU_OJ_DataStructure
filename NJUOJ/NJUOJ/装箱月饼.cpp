#include <iostream>
#include <string>
#define INT_MAX 2147483647
using namespace std;
int main()
{
	string str;
	cin >> str;
	long long int len = str.length(), cur = 0, answer = 0;
	long long int loc[32] = {};
	for (int i = 1; i < 32; ++i)
		loc[i] = INT_MAX;
	loc[0] = -1;
	for (int i = 0; i < len; ++i)
	{
		switch (str[i])
		{
			case 'n': cur = cur ^ 1; break;
			case 'j': cur = cur ^ 2; break;
			case 'u':cur = cur ^ 4; break;
			case'c':cur = cur ^ 8; break;
			case 's':cur = cur ^ 16; break;
			default:break;
		}
		if (loc[cur] == INT_MAX)
			loc[cur] = i;
		else
			answer = (answer > i - loc[cur]) ? answer : i - loc[cur];//确保后者足够小
	}
	cout << answer << endl;
	return 0;
}