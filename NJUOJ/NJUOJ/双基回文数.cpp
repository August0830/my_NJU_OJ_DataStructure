#include <iostream>
#include <string>
using namespace std;
string TurnBin(int num);
string TurnStr(int num);
bool Judge(string str);
int main()
{
	int num = 0;
	cin >> num;
	//cout << 
	//string res = TurnBin(num);
	/*if (Judge(res))
		cout << "Y";
	else
		cout << "N";*/
	int start = (num%2==0)?num+1:num+2;
	string res = TurnBin(start);
	string orig = TurnStr(start);
	bool flagB = Judge(res);
	bool flagD = Judge(orig);
	while (!flagB || !flagD)
	{
		start += 2;
		res = TurnBin(start);
		orig = TurnStr(start);
		flagB = Judge(res);
		flagD = Judge(orig);
	}
	//cout << start << " " << res;
	cout << start;
	return 0;
}
string TurnStr(int num)
{
	string tmp;
	while (num > 0)
	{
		tmp.push_back((char)('0' + num % 10));
		num = num / 10;
	}
	string res;
	int len = tmp.length();
	for(int i = len - 1; i > -1; --i)
		res.push_back(tmp[i]);
	return res;
}
string TurnBin(int num)
{
	string tmp;
	while (num > 0)
	{
		int bin = num % 2;
		tmp.push_back((char)('0' + bin));
		num = num >> 1;
		//cout << num << endl;
	}
	string res;
	int len = tmp.length();
	for (int i = len - 1; i > -1; --i)
		res.push_back(tmp[i]);
	return res;
}
bool Judge(string str)
{
	int len = str.length();
	for (int i = 0; i < len / 2; ++i)
	{
		if (str[i] != str[len - 1 - i])
			return false;
	}
	return true;
}