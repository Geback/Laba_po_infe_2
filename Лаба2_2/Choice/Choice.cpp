#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int k;

int main()
{
	srand(time(NULL));
	const int n = 10;
	int m[n];

	for (int i = 0; i < n; i++)
	{
		m[i] = rand() % 1001 - 500;
	}
	cout << "Begin:";
	for (int i = 0; i < n; i++)
	{
		cout << m[i] << " ";
	}

	
	for (int i = 0; i < n; i++)
	{
		int min = 999999999;
		for (int j = n - 1; j >= i; j--)
		{
			if (m[j] < min)
			{
				k = j;
				min = m[j];
			}
			
		}
		int r = m[i];
		m[i] = m[k];
		m[k] = r;

		cout << endl;
		for (int i = 0; i < n; i++)
		{
			cout << m[i] << " ";
		}
	}

	cout << endl << "End:";
	for (int i = 0; i < n; i++)
	{
		cout << m[i] << " ";
	}
	return 0;
}