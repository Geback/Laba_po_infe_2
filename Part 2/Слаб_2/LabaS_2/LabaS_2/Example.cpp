#include <iostream>
#include "Header.h"
using namespace std;

SALARY::SALARY(string Name, double Oklad, int Prize)
{
    cout << "����������� � ����������� ��� " << name << endl;
    name = Name;
    oklad = Oklad;
    prize = Prize;
}
SALARY::SALARY()
{
    cout << "����������� �� ���������" << endl;
    name = "";
    oklad = 0;
    prize = 0;
}
SALARY::SALARY(const SALARY& p)
{
    cout << "����������� ����������� ��� " << name << endl;
    name = p.name;
    oklad = p.oklad;
    prize = p.prize;
}

//���������
string SALARY::Get_N(){
    return name;
}
double SALARY::Get_O(){
    return oklad;
}
int SALARY:: Get_P(){
    return prize;
}

//������������
void SALARY::set_n(string n){
     name = n;
}
void SALARY::set_o(double o){
     oklad = o;
}
void SALARY::set_p(int p){
     prize = p;
}