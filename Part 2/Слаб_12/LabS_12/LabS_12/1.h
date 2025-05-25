#pragma once
#include"Header.h"


void plus_mid(multiset<double>& mlst)
{
	double midl = 0;
	for (auto& i : mlst)
		midl += i;
	mlst.insert(midl / mlst.size());
}

void searchAndDel(multiset<double>& mlst)
{
	double min, max;
	cout << "Введите диапазон для поиска:\n" << "min: "; cin >> min;
	cout << "max: "; cin >> max;
	auto left = mlst.lower_bound(min);
	auto right = mlst.upper_bound(max);
	mlst.erase(left, right);
}

void plusMinMax(multiset<double>& mlst)
{
	multiset<double> temp;
	double min = *mlst.begin(), max = *mlst.begin();
	for (auto& i : mlst)
	{
		if (i < min) min = i;
		if (i > max) max = i;
	}
	cout << "min element: " << min << endl;
	cout << "max element: " << max << endl;
	for (auto& i : mlst)
		temp.insert(i + min + max);
	mlst.swap(temp);
}

void number1()
{
	multiset<double> mlst;
	int n;
	cout << "Введите кол-во сгенерированных записей: "; cin >> n;
	for (int i = 0; i < n; i++)
		mlst.insert((double((rand() % 10000))) / 100 - 50);
	cout << endl << "Полученный multiset:" << endl; n = 0;
	for (auto& i : mlst)
		cout << ++n << ". " << i << endl;
	cout << endl << "Найдем среднее арифметическое значение и добавим его в контейнер:" << endl;
	plus_mid(mlst);
	cout << endl << "Полученный multiset:" << endl; n = 0;
	for (auto& i : mlst)
		cout << ++n << ". " << i << endl;
	cout << endl << "Зададим диапазон и удалим данные ищ контейнера в этом диапазоне:" << endl;
	searchAndDel(mlst);
	cout << endl << "Полученный multiset:" << endl; n = 0;
	for (auto& i : mlst)
		cout << ++n << ". " << i << endl;
	cout << endl << "К каждому эл контейнера добавить max и min эл контейнера:" << endl;
	plusMinMax(mlst);
	cout << endl << "Полученный multiset:" << endl; n = 0;
	for (auto& i : mlst)
		cout << ++n << ". " << i << endl;
}