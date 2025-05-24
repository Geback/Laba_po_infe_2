#pragma once
#include "Header.h"

void number_2()
{
	list<Pair> lst;
	Pair temp;
	int size;
	cout << "Введите кол - во эл в списке : "; cin >> size;
	for (int i = 0; i < size; i++)
		lst.push_back(temp.randomGener());
	cout << "Полученный список:" << endl;
	Show(lst);
	cout << "Добавим ср арифм значение списка в конец файла:" << endl;
	lst.push_back(SearchMidVal(lst));
	cout << "Полученный список:" << endl;
	Show(lst);
	cout << "Удалим эл по значению в заданном диапазоне:" << endl;
	DelElem(lst);
	cout << "Полученный список:" << endl;
	Show(lst);
	cout << "Добавим сумму min и max элементов к каждому эл:" << endl;
	plusMinMax(lst);
	cout << "Полученный список:" << endl;
	Show(lst);
	return;
}