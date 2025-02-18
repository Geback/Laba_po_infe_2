#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
	srand(time(NULL));
	const int n = 10;
	int m[n];

	for (int i = 0; i < n; i++)
	{
		m[i] = rand() % 1001 - 500;
	}
	for (int i = 0; i < n; i++)
	{
		cout << m[i] << " ";
	}

	for (int i = n - 1; i > 0; i--)
	{
		for (int j = n - 1; j >= n - i; j--)
		{
			if (m[j] < m[j - 1])
			{
				int r = m[j];
				m[j] = m[j - 1];
				m[j - 1] = r;
			}
		}
	}

	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << m[i] << " ";
	}
	return 0;
}