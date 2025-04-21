//Person.cpp
#include <iostream>
#include "Person.h"
using namespace std;

Person::Person(string F, int S)
{
    name = F;
    age = S;
}
Person::Person()
{
    name = "";
    age = 0;
}
Person::Person(const Person& p)
{
    name = p.name;
    age = p.age;
}

void Person::set_F(string f)
{
    name = f;
}
void Person::set_S(int s)
{
    age = s;
}

Person& Person::operator=(const Person& other)
{
    if (this == &other) return *this;

    name = other.name;
    age = other.age;
    return *this;
}

istream& operator>>(istream& in, Person& p)
{
    cout << "\nName:"; in >> p.name;
    cout << "Age:"; in >> p.age;
    return in;
}
ostream& operator<<(ostream& out, const Person& p)
{
    out << "\nName: " << p.name << "\nAge: " << p.age;
    return out;
}

void Person::Show()
{
    cout<<"\nName:"<< name;
    cout<<"\nAge:"<< age;
}