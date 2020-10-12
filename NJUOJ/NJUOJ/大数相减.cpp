#include <iostream>
#include <string>
using namespace std;

bool NotSmaller(string minu, string sub);
int main()
{
	string minu, sub,result;
	bool tag = true;
	cin >> minu >> sub;
	if (!NotSmaller(minu, sub))
	{
		string str = minu;
		minu = sub;
		sub = str;
		tag = false;
	}
	int lenm = minu.length();
	int lens = sub.length();
	int cin = 0;
	for (int i = 0; i <lens; ++i)
	{
		int res = 0;
		int  minuc = (int)(minu[lenm-1-i] - '0');
		int subc = (int)(sub[lens-1-i] - '0');//注意是字符0
		if (minuc < subc)
		{
			res = 10 + minuc - subc+cin;
			cin = -1;
		}
		else
		{
			res = minuc - subc+cin;
			cin = 0;
		}
		if (res < 0)
		{
			res = res + 10;
			cin = -1;
		}
		result.push_back((char)(res+'0'));
	}
	for (int i = lens; i < lenm; ++i)
	{
		int  minuc = (int)(minu[lenm-1-i] - '0');
		int res = minuc+cin;
		if (res < 0)
		{
			res = res + 10;
			cin = -1;
		}
		else
			cin = 0;
		result.push_back((char)(res + '0'));
	}
	if (!tag)
		cout << '-';
	int rlen = result.length();
	int nonz = -1;
	for (int i = rlen-1; i >-1; --i)
	{
		if (result[i] != '0')
		{
			nonz = i;
			break;
		}
	}
	if (nonz!=-1)
	{
		for (int i = nonz; i > -1; --i)
		{
			cout << result[i];
		}
	}
	else
		cout << "0";
	//cout << minu << " " << sub;
	return 0;
}
bool NotSmaller(string minu, string sub)
{
	if (minu.length() > sub.length())
		return true;
	else if (minu.length() < sub.length())
		return false;
	int len = minu.length();
	for (int i = 0; i < len; ++i)
	{
		int minuc = (int)(minu[i] - '0');
		int subc = (int)(sub[i] - '0');
		if (minuc < subc)
			return false;
		else if (minuc > subc)
			return true;
	}
	return true;//始终相等 视为真
}