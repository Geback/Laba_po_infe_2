#include <iostream>
#include <stdlib.h>
using namespace std;
int imax, imin, ki, ka;

int main() 
{
	const int n = 7;
	int m[n] = {0,0,0,0,0,0,0};
	for (int i = 0; (i < n); i++)
	{
		m[i] = rand() % 100;
		cout << m[i] << " ";

	}

	int max = m[0];
	imax = 0;
	ka = 1;
	ki = 1;
	int min = m[0];

	for (int i = 1; i < n; i++)
	{
		if (max < m[i])
		{
			max = m[i];
			imax = i;
			ka = 1;
		}
		else {

			if (max == m[i]) 
			{
				ka++;
			}
		}

		if (min > m[i])
		{
			min = m[i];
			imin = i;
			ki = 1;
		}
		else {

			if (min == m[i])
			{
				ki++;
			}
		}
	}
	cout << endl;
	cout << "Max=" << max << " imax=" << imax << " " << ka << endl;
	cout << "Min=" << min << " imin=" << imin << " " << ki << endl;
	return 0;
}