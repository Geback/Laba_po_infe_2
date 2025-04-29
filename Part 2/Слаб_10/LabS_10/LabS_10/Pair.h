#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Pair
{
private:
    int first;
    double second;

public:

    Pair(int F, double S);//
    Pair();//
    Pair(const Pair& p);//

    ~Pair() {}//

    //селекторы
    int Get_F();//
    double Get_S();//
    //модификаторы
    void set_F(int f);//
    void set_S(double s);//

    Pair operator =(const Pair&);//
    bool operator <(const Pair&);//
    Pair operator -(const Pair& p);//
    Pair& operator +(const int X);//
    Pair& operator +(const double X);//
    friend istream& operator>>(istream& in, Pair& p);//
    friend ostream& operator<<(ostream& out, const Pair& p);//

    friend fstream& operator>>(fstream& fin, Pair& p);//
    friend fstream& operator<<(fstream& fout, const Pair& p);//
};
