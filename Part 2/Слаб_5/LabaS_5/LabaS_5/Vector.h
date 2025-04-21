//Vector.h
#pragma once
#include "Object.h"
#include <string>
#include <iostream>
using namespace std;

class Vector
{
private:
    Object** beg;//��������� �� ������ ������� �������
    int size;//������
    int cur;//������� �������
public:
    Vector();
    Vector(int);
    ~Vector();

    void add(Object*);//���������� �������� � ������
    friend ostream& operator<<(ostream& out, const Vector&);

};