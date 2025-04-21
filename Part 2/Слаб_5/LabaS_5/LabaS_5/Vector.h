//Vector.h
#pragma once
#include "Object.h"
#include <string>
#include <iostream>
using namespace std;

class Vector
{
private:
    Object** beg;//указатель на первый элемент вектора
    int size;//размер
    int cur;//текущая позиция
public:
    Vector();
    Vector(int);
    ~Vector();

    void add(Object*);//добавление элемента в вектор
    friend ostream& operator<<(ostream& out, const Vector&);

};