#include <iostream>
#include "Header.h"
using namespace std;

Pair::Pair(int F, double S)
{
    cout << "Конструктор с параметрами" << endl;
    first = F;
    second = S;
}
Pair::Pair()
{
    cout << "Конструктор по умолчанию" << endl;
    first = 0;
    second = 0;
}
Pair::Pair(const Pair& p)
{
    cout << "Конструктор копирования для " << endl;
    first = p.first;
    second = p.second;
}

//селекторы
int Pair::Get_F()
{
    return first;
}
double Pair::Get_S()
{
    return second;
}


//модификаторы
void Pair::set_F(int f)
{
    first = f;
}
void Pair::set_S(double s)
{
    second = s;
}
