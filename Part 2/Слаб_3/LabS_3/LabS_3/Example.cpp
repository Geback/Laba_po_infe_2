#include <iostream>
#include "Header.h"
using namespace std;

Pair::Pair(int F, double S)
{
    cout << "����������� � �����������" << endl;
    first = F;
    second = S;
}
Pair::Pair()
{
    cout << "����������� �� ���������" << endl;
    first = 0;
    second = 0;
}
Pair::Pair(const Pair& p)
{
    cout << "����������� ����������� ��� " << endl;
    first = p.first;
    second = p.second;
}

//���������
int Pair::Get_F()
{
    return first;
}
double Pair::Get_S()
{
    return second;
}


//������������
void Pair::set_F(int f)
{
    first = f;
}
void Pair::set_S(double s)
{
    second = s;
}
