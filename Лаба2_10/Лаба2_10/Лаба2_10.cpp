#include <iostream>
#include <string>
#include <clocale>
using namespace std;
// kdufbs fdshdbfus fsfd fksfbsifj fgdfthd

int main()
{
	setlocale(LC_ALL, "rus");
	int n = 5;
	cout << "Введите " <<n<<" строк:";

	string* mas = new string[n];
	for (int i = 0; i < n; ++i)
		cin >> mas[i];
	cout << endl;

	int shorts = 0;
	for (int i = 1; i < n; i++) {
		if ((mas[i].length()) < (mas[shorts].length())) {
			shorts = i;
		}
	}

	string* mass = new string[n-1];
	int j = 0;
	for (int i = 0; i < n; ++i) {
		if (i != shorts) {
			mass[j++] = mas[i];
		}
	}
	delete[] mas;
	mas = nullptr;
	
	for (int i = 0; i < n-1; i++){
		cout << mass[i] << " ";
	}
	delete[] mass;
	mass = nullptr;

	return 0;
}


