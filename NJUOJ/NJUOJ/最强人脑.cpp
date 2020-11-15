#include <iostream>
#include <string>
using namespace std;//match string practise KMP-method
void Vector(string src,int*&next);
void Match(string target, string src);
int main()
{
	string target, src;
	cin >> target;
	cin >> src;
	Match(target, src);
	//int* next = Vector(src);//figure out vector
	/*for (int i = 0; i < src.length(); ++i)
		cout << next[i];*/
	return 0;
}
void Match(string target, string src)
{
	int i = 0,j=0;
	bool flag = false;
	int slen = src.length();
	int tlen = target.length();
	int* next = new int[slen];
	Vector(src,next);
	//for (int i = 0; i < src.length(); ++i)
		//cout << next[i];
	//next[0] = 0;
	while (i < tlen)
	{
		while (j < slen && i < tlen)
		{
			if (  j == -1 || target[i] == src[j])//avoid out of range
			{
				i++;
				j++;
			}
			else
				j = next[j];
		}
		if (j == src.length())
		{
			cout << i - slen << " ";
			flag = true;
			i = i - slen + 1;//repetition in string place in the right part
		}
		j = 0;

	}
	if (!flag)
		cout << "-1";
}
void Vector(string src,int*&next)
{
	int len = src.length();
	next[0] = -1;
	int s = -1, j = 0;
	while (j < len)
	{
		if (s == -1 || src[j] == src[s])
		{
			j++;
			s++;
			next[j] = s;
		}
		else
			s = next[s];
	}
}