//LabaS_5.cpp
#include "Object.h"
#include "Person.h"
#include "Student.h"
#include "Vector.h"

#include <string>
#include <iostream>
#include <clocale>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Лучше писать на англ.\n";
	Person a;
	cin >> a;
	Object* p = &a;
	Student b;
	cin >> b;
	static_cast<Student>(b).check();

	Vector v(5);

	v.add(new Person("Toy", 54)); // 1 эл в векторе

	v.add(p); // 2 эл
	Object* pt = &b;
	v.add(pt); // 3 эл
	cout <<"\n";
	cout << v;

	return 0;
}
