#pragma once
#include"Header.h"

void plus_mid2(multiset<Pair>& mlst)	//добавление в контейнер элемента со средним арифмитическим значением
{
	Pair midl = 0;
	for (auto& i : mlst)
		midl = midl + i;
	mlst.insert(midl / mlst.size());
}

void searchAndDel2(multiset<Pair>& mlst)	//поиск и удаление данных в заданном диапазоне
{
	Pair min, max;
	cout << "Введите диапазон для поиска (Pair):\n" << "min: "; cin >> min;
	cout << "max: "; cin >> max;
	auto left = mlst.lower_bound(min);
	auto right = mlst.upper_bound(max);
	mlst.erase(left, right);
}

void plusMinMax2(multiset<Pair>& mlst)		//добавлениек каждому элементу максимального и минимального элементов
{
	multiset<Pair> temp;
	Pair min = *mlst.begin(), max = *mlst.begin();
	for (auto& i : mlst)			//два раза проходим циклом
	{								//первый раз ищем минимум и максимум
		if (i < min) min = i;
		if (!(i < max)) max = i;
	}
	cout << "min element: " << min << endl;
	cout << "max element: " << max << endl;
	for (auto& i : mlst)			//второй раз составляем новый multiset
		temp.insert(i + min + max);
	mlst.swap(temp);			//меняем данные в multisetах
}

void number2()
{
	Pair pr;
	multiset<Pair> mlst;
	int n;
	cout << "Введите какое количество записей сгенерировать: "; cin >> n;
	for (int i = 0; i < n; i++)		//заполнение контейнера рандомнаыми данными
		mlst.insert(pr.randomGener());
	cout << endl << "Полученный multiset:" << endl; n = 0;
	for (auto& i : mlst)			//вывод 
		cout << ++n << ". " << i << endl;
	cout << endl << "Найдем среднее арифмитическое значение и добавим его в контейнер." << endl;
	plus_mid2(mlst);			//добавление элемента со средним арифметическим
	cout << endl << "Полученный multiset:" << endl; n = 0;
	for (auto& i : mlst)			//вывод 
		cout << ++n << ". " << i << endl;
	cout << endl << "Зададим диапазон и удалим данные из контейнера в данном диапазоне." << endl;
	searchAndDel2(mlst);			// поиск и удаление элементов в заданном диапазоне
	cout << endl << "Полученный multiset:" << endl; n = 0;
	for (auto& i : mlst)			//вывод 
		cout << ++n << ". " << i << endl;
	cout << endl << "К каждому элементу контейнера добавим max и min элемент контейнера." << endl;
	plusMinMax2(mlst);				//поиск максимального и минимального и добавление к каждому элементу
	cout << endl << "Полученный multiset:" << endl; n = 0;
	for (auto& i : mlst)			//вывод 
		cout << ++n << ". " << i << endl;
}