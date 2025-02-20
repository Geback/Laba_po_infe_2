#include <iostream>
using namespace std;
int k, min;

int main()
{
	const int n = 3;
	int arr[n][n] = { 7, 8, 2, 5, 9, 2 ,8, 4, 3 };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < n; i++)
	{
		int min = 999999999;
		for (int j = n - 1; j >= i; j--)
		{
			if (arr[1][j] < min)
			{
				k = j;
				min = arr[1][j];
			}

		}
		int r2 = arr[2][i];
		arr[2][i] = arr[2][k];
		arr[2][k] = r2;

		int r1 = arr[1][i];
		arr[1][i] = arr[1][k];
		arr[1][k] = r1;

		int r0 = arr[0][i];
		arr[0][i] = arr[0][k];
		arr[0][k] = r0;
	}

	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
