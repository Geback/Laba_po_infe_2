#include <iostream>
#include <clocale>
#include "Header.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    Pair p1, p2;
    cout << "Введите пару чисел (Целое и вещ.): ";
    cin >> p1;
    cout << "Введите пару чисел (Целое и вещ.): ";
    cin >> p2;
    cout <<"Para1:  " << p1 <<'\n';
    cout <<"Para2:  " << p2 << '\n';
    cout <<"p1-p2: " << p1 - p2<< endl;
    int v;
    double vv;
    cout <<"Entr int:";
    cin >> v;
    cout << "Entr double:";
    cin >> vv;
    cout << "Int p1 + v:"<< p1 + v << endl;
    cout << "Double p1 + vv:"<< p1 + vv << endl;

    return 0;
}


