//LabaS_4.cpp
#include <iostream>
#include <clocale>
#include "Person.h"
#include "Student.h"
using namespace std;

void f1(Person& c)
{
    c.set_F("Opel");
    cout << c;
}

Person f2()
{
    Student l("Kia", 1, "PE", 3);
    return l;
}
int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Лучше писать на англ.\n";
    Person a;
    cin >> a;
    cout<<"\nВывод:";
    cout << a;
    cout << endl;

    Person b("Ford", 4);
    cout << "\nВывод:";
    cout << b;
    a = b;
    cout << endl;
    cout << "\nВывод:";
    cout << a;

    Student c;
    cin >> c;
    cout << "\nВывод:";
    cout << c <<endl;
    static_cast<Student>(c).check();

    cout << "\nВывод: ";
    f1(c);
    cout << endl;
    a = f2();
    cout << "\nВывод: ";
    cout << endl;
    cout << a;

    return 0;
}


