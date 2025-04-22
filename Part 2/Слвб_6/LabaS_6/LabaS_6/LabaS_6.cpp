//Laba_6.cpp
#include "Header.h"
#include <iostream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "rus");
    cout<<"Код добавляет элементы в начало списка!!\n";
    List list1, list2;
    cin >> list1;
    cin >> list2;

    cout << "list1: " << list1 << endl;
    cout << "list2: " << list2 << endl;

    List list3 = list1 * list2;
    cout << "list3 = list1 * list2: " << list3 << endl;

    cout << "Enter index for list1: ";
    int index;
    cin >> index;
    cout << "list1[" << index << "] = " << list1[index] << endl;

    cout << "Enter n for list2: ";
    int n;
    cin >> n;
    List::Iterator it = list2.begin() + n;
    if (it != list2.end()){
        cout << "list1[" << n << "] = " << *it << endl;
    }
    else{
        cout << "Invalid index\n";
    }
    return 0;
}
