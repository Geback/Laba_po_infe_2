#pragma once
#include"Header.h"

void number3()
{
	Pair pr;
	List<Pair> mlst;
	int n;
	cout << "Введите какое количество записей сгенерировать: "; cin >> n;		//заполнение списка рандомнаыми данными
	for (int i = 0; i < n; i++)
		mlst.add(pr.randomGener());
	cout << endl << "Полученный list:" << endl;
	mlst.print();	//вывод 
	cout << endl << "Найдем среднее арифмитическое значение и добавим его в контейнер." << endl;
	mlst.plus_mid();	//добавление элемента со средним арифметическим
	cout << endl << "Полученный list:" << endl;
	mlst.print();		//вывод
	cout << endl << "Зададим диапазон и удалим данные из контейнера в данном диапазоне." << endl;
	mlst.searchAndDel();	//поиск и удаление элементов в диапазоне
	cout << endl << "Полученный list:" << endl;
	mlst.print();		//вывод
	cout << endl << "К каждому элементу контейнера добавим max и min элемент контейнера." << endl;
	mlst.plusMinMax();	//поиск максимального и минимального, для добавление к каждому элементу
	cout << endl << "Полученный list:" << endl;
	mlst.print();		//вывод
}