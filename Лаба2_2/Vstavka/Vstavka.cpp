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
	cout << "Begin:";
	for (int i = 0; i < n; i++)
	{
		cout << m[i] << " ";
	}

	for (int i = 1; i < n; i++)
	{
		
		bool f = true;
		for (int j = i; (j >= 0) && f; j--)
		{
			if (m[j] < m[j - 1])
			{
				int r = m[j];
				m[j] = m[j - 1];
				m[j - 1] = r;
			}
			else {
				f = false;
			}

			
		}
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