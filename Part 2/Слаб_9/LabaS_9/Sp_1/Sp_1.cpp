#include "List.h"
#include <iostream>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    try
    {
        List a(5);
        List b(6);
        cout << "a: " << a;
      //  cout << a[5]; // Попытка доступа к элементу с индексом, равным размеру списка
        cout << "b: " << b;
      //  List c = a * b; // Попытка умножения списков разной длины
        cout << "b + 6: " << b + 6 << endl;
        cout << b + 7; // Попытка доступа к элементу с индексом больше размера списка
    }
    catch (int ex)
    {
        if (ex == 1)
            cout << "Ошибка, не существует элемента с таким индексом!\n";
        if (ex == 2)
            cout << "Ошибка, у списков различные длины!\n";
        if (ex == 3)
            cout << "Ошибка, нельзя перейти к узлу с этим номером!\n";
    }
    catch (...)
    {
        cout << "Unknown exception occurred" << endl;
    }

    return 0;
}