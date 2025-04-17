#pragma once
#include <iostream>
using namespace std;

class Pair
{
private:
    int first;
    double second;

public:

    Pair(int F, double S);
    Pair();
    Pair(const Pair& p);

    ~Pair(){}

    //селекторы
    int Get_F();
    double Get_S();
    //модификаторы
    void set_F(int f);
    void set_S(double s);

    Pair& operator=(const Pair& other)
    {
        if (this != &other)
        {
            first = other.first;
            second = other.second;
        }
        return *this;
    }

    Pair operator-(const Pair& other) const
    {
        return Pair(first - other.first, second - other.second);
    }
    Pair operator+(int value) const
    {
        return Pair(first + value, second);
    }
    Pair operator+(double value) const
    {
        return Pair(first, second + value);
    }

    friend istream& operator>>(istream& in, Pair& p){
        in >> p.first >> p.second;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Pair& p){
        out << p.first << ":" << p.second;
        return out;
    }
};
