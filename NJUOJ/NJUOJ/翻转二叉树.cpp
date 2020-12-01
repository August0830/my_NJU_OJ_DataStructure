#include <iostream>
using namespace std;
int len1 = 0, len2 = 0;
bool Check(int ln, int rn, int* tree1, int* tree2);
int main()
{
	cin >> len1;
	int* tree1 = new int[len1];
	for (int i = 0; i < len1; ++i)
		cin >> tree1[i];
	cin >> len2;
	int* tree2 = new int[len2];
	for (int i = 0; i < len2; ++i)
		cin >> tree2[i];
	if (tree1[0]==tree2[0] && Check(0, 0, tree1, tree2))
		cout << "True";
	else
		cout << "False";
	return 0;
}
bool Check(int ln, int rn,int *tree1,int *tree2)
{
	if (((tree1[2 * ln + 1] == -1 || 2 * ln + 1 >= len1)
		&& (tree1[2 * ln + 2] == -1 || 2 * ln + 2 >= len1)
		&& ((tree2[2 * rn + 1] == -1 || 2 * rn + 1 >= len2)
			&& (tree2[2 * rn + 2] == -1 || 2 * rn + 2 >= len2))
		))
		return true;
	else if (tree1[2 * ln + 1] == tree2[2 * rn + 1] && tree1[2 * ln + 2] == tree2[2 * rn + 2])
		//未调转
	{
		return Check(2 * ln + 1, 2 * rn + 1, tree1, tree2) && Check(2 * ln + 2, 2 * rn + 2, tree1, tree2);
	}
	else if (tree1[2 * ln + 1] == tree2[2 * rn + 2] && tree1[2 * ln + 2] == tree2[2 * rn + 1])
		//有翻转
	{
		return Check(2 * ln + 1, 2 * rn + 2, tree1, tree2) && Check(2 * ln + 2, 2 * rn + 1, tree1, tree2);
	}
	else
		return false;
}