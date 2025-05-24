#pragma once
#include "Header.h"

template <typename T>
void Show(list<T> lst);

template<class T>
T SearchMidVal(list<T>& lst);

template<class T>
void DelElem(list<T>& lst);

void number_1();

template<class T>
void plusMinMax(list<T>& lst);


void number_1()
{
	list<double> lst;
	int size;
	cout << "Введите кол-во эл в списке: "; cin >> size;
	for (int i = 0; i < size; i++)
		lst.push_back((double((rand() % 10000 - 5000)) / 100));
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

template<class T>
void plusMinMax(list<T>& lst)
{
	T loc_min = 0, loc_max = 0;
	for (auto& i : lst)
	{
		if (i < loc_min)
		{
			loc_min = i;
		}
		else if (i > loc_max)
		{
			loc_max = i;
		}
	}
	cout << "min element: " << loc_min << endl;
	cout << "max elem: " << loc_max << endl;
	for (auto& i : lst)
	{
		i = i + loc_min + loc_max;
	}
}

template<typename T>
void Show(list<T> lst)
{
	int j = 0;
	for (auto& i : lst)
		cout << j++ << ")\t" << i << endl;
}

template<class T>
T SearchMidVal(list<T>& lst)
{
	T mid = 0;
	for (auto& i : lst)
		mid = mid + i;
	return mid / lst.size();
}

template<class T>
void DelElem(list<T>& lst)
{
	T key;
	int start, end;
	auto it_start = lst.begin(), it_end = lst.begin();
	cout << "Введите ключ для поиска: "; cin >> key;
	cout << "Введите диапазон для поиска (индексы) (start end): "; cin >> start >> end;
	if (start > end) std::swap(start, end);
	std::advance(it_start, start);
	std::advance(it_end, end);
	do
	{
		if (*it_start == key) it_start = lst.erase(it_start);
		else ++it_start;
	}
	while (it_start != it_end);
}