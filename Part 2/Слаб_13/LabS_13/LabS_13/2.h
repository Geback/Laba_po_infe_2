#pragma once
#include "Header.h"

void Show(priority_queue<Pair> q);

Pair SearchMidVal(priority_queue<Pair>& q);

void DelElem(priority_queue<Pair>& q);

void plusMinMax(priority_queue<Pair>& q);

/*
У очереди с приоретами нет итераторов, а также с ней не могут взаимодействовать
функции из библиотеки algorithm, потому что они основаны на том, что они работают
с итераторами. Поэтому задачи, которые указаны в варианте номер 15 невозможно выполнить
методами, которые предложены. Даже какими-либо методами приоритетной очереди это тоже не
выполняются.
ЗДЕСЬ ПОМОГУТ ТОЛЬКО КОСТЫЛИ!!!
Поэтому выполнение данного задания из лабораторной работы номер 11 - то что нужно.
*/


void number2()			//Это я даже не буду объяснять. Если очень интересно, то идем в 11 лабу там это 4 задача
{						//просто ужас, как можно было такое составить
	Pair temp;			//неадекватное задание
	priority_queue<Pair> pq;	//у нее даже итераторв нет
	int size;
	cout << "Введите количество элементов в очереди: "; cin >> size;
	for (int i = 0; i < size; i++)
		pq.push(temp.randomGener());
	cout << "Полученная очередь:" << endl;
	Show(pq);
	cout << "Добавим среднее арифмитическое значение очереди:" << endl;
	pq.push(SearchMidVal(pq));
	cout << "Полученный очередь:" << endl;
	Show(pq);
	cout << "Удалим элемент по значению." << endl;
	DelElem(pq);
	cout << "Полученный очередь:" << endl;
	Show(pq);
	cout << "Добавим сумму min и max элементов к каждому элементу." << endl;
	plusMinMax(pq);
	cout << "Полученный очередь:" << endl;
	Show(pq);
	return;
}



void Show(priority_queue<Pair> q)
{
	int j = 0;
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