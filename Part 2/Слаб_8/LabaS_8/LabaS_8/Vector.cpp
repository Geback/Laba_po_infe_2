
#include "Vector.h"
using namespace std;

Vector::Vector()
{
	beg = nullptr;
	size = 0;
	cur = 0;
}

Vector::~Vector(void)
{
	Clear();
}

Vector::Vector(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}

void Vector::Clear()
{
	for (int i = 0; i < cur; ++i)
	{
		delete beg[i];  
	}
	delete[] beg;       
	beg = nullptr;
	size = 0;
	cur = 0;
}

void Vector::Get_Name()
{
	if (cur == 0)
	{
		cout << "Empty" << endl;
		return;
	}

	Object** p = beg;
	for (int i = 0; i < cur; i++)
	{
		cout << (*p)->Get_name() << endl;
		p++;
	}
}

void Vector::Add()
{
	if (cur >= size)
	{
		cout << "Vector is full!" << endl;
		return;
	}

	int y;
	cout << "1.Print" << endl;
	cout << "2.Magazin" << endl;
	cout << "Select type: ";
	cin >> y;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	Object* p = nullptr;

	if (y == 1)
	{
		Print* a = new Print();
		a->Input();
		p = a;
	}
	else if (y == 2)
	{
		Magazin* b = new Magazin();
		b->Input();
		p = b;
	}
	else
	{
		cout << "Invalid selection! Please choose 1 or 2." << endl;
		return;
	}

	beg[cur++] = p;
}

void Vector::Show()
{
	if (cur == 0) {cout << "Empty" << endl; return;}
	Object** p = beg;
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();
		p++;
	}
}

int Vector::operator ()()
{
	return cur;
}

void Vector::Del()
{

	if (cur == 0) { cout << "Vector is empty!" << endl; return; }

	delete beg[--cur];
	beg[cur] = nullptr;
}