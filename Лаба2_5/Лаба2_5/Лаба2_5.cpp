#include <iostream>
using namespace std;
int n = 5;
bool F = true;
//{5 52 46 73 47 43 74 1 54 61 17 81 12 8 29 76 2 79 84 55 20 7 83 13 58}
// 54 49 21 79 4 34 81 33 50 49 49 66 64 64 73 60 28 32 2 31 63 8 2 17 5
int main()
{
	int ki = 0;
	int** arr = new int* [n]; 

	for (int k = 0; k < n; k++) { 
		arr[k] = new int[n];
	}

	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
		
	}
	cout << endl;

	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	int pastm = -99;
	for (int j = 0;j<n;j++){
		
		/*for (int i = 0; i < n; i++) {  //Выводит столбцы 
			cout << arr[i][j] << " ";
		}
		cout << endl;*/

		int min = 999999;
		for (int i = 0; i < n; i++) {

			if ((min > arr[i][j]) && (pastm < arr[i][j])) {
				min = arr[i][j];
				ki = i;
				//cout << ".";
			}
		}
		if (pastm == 999999) {
			F = false;
		}

		//cout << "min:" << min << "   " << "kj:" << ki <<" << "<<pastm;
		//cout << endl;
		pastm = min;

		int b = arr[n - j-1][j];
		arr[n - j-1][j] = arr[ki][j];
		arr[ki][j] = b;
	}
	cout << endl;  

	if (F) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
	}
	else {
		cout << "Error!!! It's impossible to arrange elements on the secondary diagonal so that they increase.";
	}
	return 0;
}
