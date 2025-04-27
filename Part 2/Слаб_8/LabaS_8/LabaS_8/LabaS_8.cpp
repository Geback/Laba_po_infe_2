// LabaS_8
#include <iostream>
#include <clocale>
using namespace std;
#include "Print.h"
#include "Magazin.h"
#include "Vector.h"
#include "Dialog.h"

int main()
{
	setlocale(LC_ALL,"rus");
	cout << "m: Создать новую группу\n";
	cout << "+: Добавить элемент\n";
	cout << "-: Удалить элемент\n";
	cout << "s: Информация о членах группы\n";
	cout << "z: Информация о названиях элементов группы\n";
	cout << "q: Конец работы\n";
	Dialog D;
	D.Execute();
	return 0;
}

