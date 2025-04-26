#pragma once
#include <iostream>
using namespace std;

class SALARY
{
private:
    string name;
    double oklad;
    int prize;

public:

    SALARY(string Name, double Oklad, int Prize); 
    SALARY();
    SALARY(const SALARY& p);

    ~SALARY(){
        cout << "Деструктор для " << name << endl;
    }

    /*void Set_S(string Name, double Oklad, int Prize) {
        name = Name;
        oklad = Oklad;
        prize = Prize;
    }*/

    //селекторы
    string Get_N();
    double Get_O();
    int Get_P();

    //модификаторы
    void set_n(string n);
    void set_o(double o);
    void set_p(int p);

    void Print() const{
        cout << "Имя: " << name << ", Оклад: " << oklad << ", Премия (% от оклада): " << prize << endl;
    }
};
