#pragma once
#include "Header.h"

void Show(priority_queue<Pair> q);

Pair SearchMidVal(priority_queue<Pair>& q);

void DelElem(priority_queue<Pair>& q);

void plusMinMax(priority_queue<Pair>& q);

void number_4()
{
	Pair temp;
	priority_queue<Pair> pq;
	int size;
	cout << "Введите кол-во эл в списке: "; cin >> size;
	for (int i = 0; i < size; i++)
		pq.push(temp.randomGener());
	cout << "Полученный список:" << endl;
	Show(pq);
	cout << "Добавим ср арифм значение списка в конец файла:" << endl;
	pq.push(SearchMidVal(pq));
	cout << "Полученный список:" << endl;
	Show(pq);
	cout << "Удалим эл по значению в заданном диапазоне:" << endl;
	DelElem(pq);
	cout << "Полученный список:" << endl;
	Show(pq);
	cout << "Добавим сумму min и max элементов к каждому эл:" << endl;
	plusMinMax(pq);
	cout << "Полученный список:" << endl;
	Show(pq);
	return;
}



void Show(priority_queue<Pair> q)
{
	int j = 0;
	//priority_queue<Pair> temp(q);
	while (!q.empty())
	{
		cout << j++ << ". " << q.top() << endl;
		q.pop();
	}
}


Pair SearchMidVal(priority_queue<Pair>& q)
{
	priority_queue<Pair> temp(q);
	Pair mid = 0;
	while (!temp.empty())
	{
		mid = mid + temp.top();
		temp.pop();
	}
	return mid / q.size();
}


void DelElem(priority_queue<Pair>& q)
{
	Pair key, k;
	priority_queue<Pair> temp;
	cout << "Введите ключ для поиска: "; cin >> key;
	while (!q.empty())
	{
		k = q.top();
		if (key == k)
			q.pop();
		else

		{
			temp.push(k);
			q.pop();
		}
	}
	q.swap(temp);
}

void plusMinMax(priority_queue<Pair>& q)
{
	Pair k;
	Pair loc_min = q.top(), loc_max = 0;
	priority_queue<Pair> temp(q);
	while (!temp.empty())
	{
		k = temp.top();
		if (loc_max < k)
		{
			loc_max = k;
			temp.pop();
		}
		else if (loc_min > k)
		{
			loc_min = k;
			temp.pop();
		}
		else temp.pop();
	}
	cout << "min element: " << loc_min << endl;
	cout << "max element: " << loc_max << endl;
	temp.swap(q);
	while (!temp.empty())
	{
		k = temp.top();
		q.push(k + loc_min + loc_max);
		temp.pop();
	}
}