#include <iostream>
using namespace std;

int n = 8;
int arr[8][8] = { 0 };

void show() {
	for (int i = 0; i < n; i++) {
		
		for (int j = 0; j < n; j++) {
			cout << (arr[i][j] ? "# " : "o ");
		}
		cout << endl;
	}
	cout << "--------------------" << endl;
}

int chek(int c, int r)   
{                      
	for (int i = 0; i < c; ++i)
	{
		// Проверка горизонтали
		if (arr[i][r]) return 0;
		// Проверка диагонали
		if ((r - c + i >= 0) && (arr[i][r - c + i])) return 0;
		if ((r + c - i < 8) && (arr[i][r + c - i])) return 0;
	}
	return 1;
}

int set(int line)
{
	if (line == 8)
	{
		show();
		return 1;
	}
	
	for (int j = 0; j < n; j++) {
		if (chek(line, j)) 
		{
			arr[line][j] = 1;
			//show();
			if (set(line + 1)) return 1;
			arr[line][j] = 0;
		}
	}
	return 0;
}

int main() {
	set(0);
	return 0;
}