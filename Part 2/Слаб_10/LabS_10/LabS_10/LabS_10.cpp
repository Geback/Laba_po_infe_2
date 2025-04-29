#include "Pair.h"
#include "File.h"
#include <iostream> 
#include <fstream>
#include <string> 
using namespace std;

int main()
{
	setlocale(LC_ALL,"rus");
	Pair p, temp; int k, c, num, count; double plus; char file_name[30];
	do
	{
		system("pause"); system("cls");
		cout << "1.Создать список:";
		cout << "\n2. Вывести файл:";
		cout << "\n3. Удалить пары, меньшие заданного значения:";
		cout << "\n4. Добавить K записей после элемента с заданным номером:";
		cout << "\n5. Увеличить все записи с заданным значением на число L:";
		cout << "\n0. Выйти\n";
		cin >> c;
		switch (c)
		{
		case 1:
			cout << "Имя файла: "; cin >> file_name;
			k = make_file(file_name);
			if (k < 0) cout << "Невозможно создать файл\n";
			break;
		case 2:
			cout << "Имя файла: "; cin >> file_name; 
			k = print_file(file_name); 
			if (k == 0) cout << "Пустой файл\n"; 
			if (k < 0) cout << "Невозможно считать файлe\n"; 
			break;
		case 3:
			cout << "Имя файла: "; cin >> file_name;
			cin >> temp;
			k = del_file(file_name, temp);
			if (k < 0)cout << "Невозможно считать файл\n";
			break;
		case 4:
			cout << "Имя файла: "; cin >> file_name;
			cout << "После какого номера: "; cin >> num;
			cout << "количество: "; cin >> count;
			k = add_file(file_name, num, count);
			if (k < 0) cout << "Невозможно считать файл\n";
			if (k == 0) k = add_end(file_name, count);
			break;
		case 5:
			cout << "Имя файла: "; cin >> file_name;
			cout << "Введите число которое хотите добавить: ";
			cin >> plus;
			k = change_file(file_name, plus);
			if (k < 0) cout << "Невозможно считать файл\n";
			break;
		}
	}
	while (c != 0);
	return 0;
}