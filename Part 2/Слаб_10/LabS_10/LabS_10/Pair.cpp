#include <iostream>
#include "Pair.h"
using namespace std;

Pair::Pair(int F, double S)
{
    first = F;
    second = S;
}
Pair::Pair()
{
    first = 0;
    second = 0;
}
Pair::Pair(const Pair& p)
{
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
Pair Pair::operator=(const Pair& other)
{
    if (this != &other)
    {
        first = other.first;
        second = other.second;
    }
    return *this;
}

Pair& Pair::operator +(const int X)
{
    first += X;
    return *this;
}

Pair& Pair::operator +(const double X)
{
    second += X;
    return *this;
}

Pair Pair::operator -(const Pair& p)
{
    Pair temp;
    temp.first = this->first - p.first;
    temp.second = this->second - p.second;
    return temp;
}

istream& operator>>(istream& in, Pair& p)
{
    cout << "int first = "; in >> p.first;
    cout << "double second = "; in >> p.second;
    return in;
}

ostream& operator<<(ostream& out, const Pair& p)
{
    out << p.first << ":" << p.second;
    return out;
}

fstream& operator>>(fstream& fin, Pair& p)
{
    fin >> p.first;
    fin >> p.second;
    return fin;
}

fstream& operator<<(fstream& fout, const Pair& p)
{
    fout << p.first << "\n" << p.second << "\n";
    return fout;
}

bool Pair::operator <(const Pair& p)
{
    double temp = p.first + p.second;
    double t = (*this).first + (*this).second;
    if (t < temp) return true;
    return false;
}
