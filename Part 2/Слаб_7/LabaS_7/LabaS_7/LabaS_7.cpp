//Laba_6.cpp
#include "List.h"
#include "Pair.h"
#include <iostream>
#include <clocale>
using namespace std;


int main()
{
	setlocale(LC_ALL,"rus");
	Pair p1(2, 2.5);
	List<Pair> a(3, p1);
	cout << a << endl;
	cout << "Вывод 1 эл из List a:\n" << a.front() << endl;
	cin >> a;
	cout <<"\nВывод из List a:\n" << a << endl;
	List<Pair> b(a);
	cout << "Вывод из List b:\n";
	cout << b << endl;
	List<Pair> c = a * b;
	cout << "a * b\n" << c << endl;
	Pair num;
	cout << "Ввод num:\n"; cin >> num;
	b.pushback(num);
	cout <<"Вывод из List b:\n" << b << endl;
	cout <<"Вывод из List a с помощью Iterator:\n";
	for (Iterator<Pair> iter = a.first(); iter != a.last(); ++iter)
		cout << *iter << '\n';
	return 0;
}
