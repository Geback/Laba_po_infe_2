//Student.h
#pragma once
#include "Person.h"

class Student :
    public Person
{
protected:
    string subject;
    int assessment;
public:
    Student(string F, int S, string FF, int SS);
    Student();
    Student(const Student& p);
    ~Student() {}

    //селекторы
    string Get_FF() { return subject; }
    int Get_SS() { return assessment; }
    //модификаторы
    void set_FF(string f);
    void set_SS(int s);
    void check();

    Student& operator=(const Student& other);

    friend istream& operator>>(istream& in, Student& p);
    friend ostream& operator<<(ostream& out, const Student& p);
    void Show();
};

