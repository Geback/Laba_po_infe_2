#include <iostream>
#include <clocale>
#include "Header.h"
using namespace std;

void print_tovar(SALARY t)
{
    t.Print();
}
SALARY make_s()
{
    string s;
    int p;
    double o;
    cout << "Vvedite name: ";
    cin >> s;
    cout << "Vvedite oklad: ";
    cin >> o;
    cout << "Vvedite prise: ";
    cin >> p;
    SALARY t(s, o, p);
    return t;
}

int main()
{
    setlocale(LC_ALL, "rus");
    //конструктор без параметров
    SALARY t1;
    t1.Print();
    //коструктор с параметрами
    SALARY t2("Женек", 10.7, 15);
    t2.Print();

    //конструктор копирования 1
    SALARY t3 = t2;
    t3.set_n("Telephon23");
    t3.set_o(23.6);
    t3.set_p(25);
    //конструктор копирования 2
    print_tovar(t3);
    //конструктор копирования 3
    t1 = make_s();
    t1.Print();
    return 0;
}


