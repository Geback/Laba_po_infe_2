#pragma once
#include "Pair.h"


template <typename T>
class Priority_queue{
private:
	priority_queue<T> q;
	T SearchMidVal();
	int _size;

public:
	Priority_queue() { _size = 0; }
	Priority_queue(int n);
	~Priority_queue() {};
	void Print();
	void PushMidVal();
	void DelElem();
	int size() { return this->_size; }
	void plusMinMax();
};

template<typename T>
Priority_queue<T>::Priority_queue(int n){
	T a;
	cout << "ÂВведите данные: " << endl;
	for (size_t i = 0; i < n; i++)
	{
		cout << i << ". ";
		cin >> a;
		q.push(a);
	}
	_size = n;}

template<typename T>
void Priority_queue<T>::Print(){
	int j = 0;
	priority_queue<Pair> temp(this->q);
	while (!temp.empty())
	{
		cout << j++ << ". " << temp.top() << endl;
		temp.pop();}}


template<typename T>
T Priority_queue<T>::SearchMidVal(){
	priority_queue<T> temp(q);
	T mid = 0;
	while (!temp.empty()){
		mid = mid + temp.top();
		temp.pop();}
	return mid / q.size();}

template<typename T>
void Priority_queue<T>::PushMidVal()
{
	q.push(SearchMidVal());
	this->_size = q.size();
}

template<typename T>
void Priority_queue<T>::DelElem()
{
	T key, k;
	priority_queue<T> temp;
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

template<typename T>
void Priority_queue<T>::plusMinMax()
{
	T k;
	T loc_min = q.top(), loc_max = 0;
	priority_queue<T> temp(q);
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

void number_5()
{
	int n;
	cout << "Введите кол-во эл в списке: "; cin >> n;
	Priority_queue<Pair> lst(n);
	cout << "Полученный список:" << endl;
	lst.Print();
	cout << "Добавим ср арифм значение списка в конец файла:" << endl;
	lst.PushMidVal();
	cout << "Полученный список:" << endl;
	lst.Print();
	cout << "Удалим эл по значению в заданном диапазоне:" << endl;
	lst.DelElem();
	cout << "Полученный список:" << endl;
	lst.Print();
	cout << "Добавим сумму min и max элементов к каждому эл:" << endl;
	lst.plusMinMax();
	cout << "Полученный список:" << endl;
	lst.Print();
}