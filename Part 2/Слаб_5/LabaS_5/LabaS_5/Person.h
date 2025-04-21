//Person.h
#pragma once
#include "Object.h"
#include <iostream>
using namespace std;

class Person:
    public Object{
protected:
    string name;
    int age;
public:
    Person(string F, int S);
    Person();
    Person(const Person& p);
    virtual ~Person() {}

    //селекторы
    string Get_F() { return name; }
    int Get_S() { return age; }
    //модификаторы
    void set_F(string f);
    void set_S(int s);

    Person& operator=(const Person& other);

    friend istream& operator>>(istream& in, Person& p);
    friend ostream& operator<<(ostream& out, const Person& p);
    void Show();
};

