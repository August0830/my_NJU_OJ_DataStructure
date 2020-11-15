#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	bool diag = true,upper=true,lower=true;
	int** matrix = new int* [n];
	for (int i = 0; i < n; ++i)
		matrix[i] = new int[n];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> matrix[i][j];
			if (matrix[i][j] != 0)
			{
				if (i != j)
					diag = false;
				if (i > j)
					upper = false;
				if (i < j)
					lower = false;
			}
		}
			
	}
	if (diag)
		cout << "diagonal";
	if (!diag && lower)//如果是diag lower和upper的标记仍然为真 
		cout << "lower";
	if (!diag && upper)
		cout << "upper";
	if (!diag && !lower && !upper)
		cout << "none";
	return 0;
}