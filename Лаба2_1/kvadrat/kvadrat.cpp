#include <iostream>
#include <math.h>
using namespace std;

int main() 
{
	const int n = 5;
	int a[n][n];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (abs(i - j) == 2 or (i + j) == n + 1 or (i + j) == n - 3)
			{
				a[i][j] = 1;
			}
			else {
				a[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
