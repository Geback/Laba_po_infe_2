//Vector.cpp
#include "Vector.h"
#include <iostream>

Vector::Vector(){
	beg = 0;
	size = 0;
	cur = 0;
}

Vector::~Vector()
{
	if (beg != 0) delete[] beg;
	beg = 0;

}

Vector::Vector(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}
//добавление объекта
void Vector::add(Object* p)
{
	if (p == nullptr) return;

	if (cur >= size)
	{
		size = size * 2;
	}
	beg[cur++] = p;
}


ostream& operator<<(ostream& out, const Vector& v)
{
	if (v.size == 0) out << "Empty" << endl;
	Object** p = v.beg;
	for (int i = 0; i < v.cur; i++)
	{
		(*p)->Show();
		out << '\n';
		p++;
	}
	return out;
}