#include <iostream>
#include "Header.h"
#include <clocale>
using namespace std;

Arifm make_Arifm(double F, int S) {
    Arifm t;
    t.Init(F, S);
    return t;
}

int main()
{
    setlocale(LC_ALL, "rus");  
    Arifm A;
    A.Init(0, 0);
    A.Read();
    A.Show();

    double k = A.Element();
    if ( k == -1) {
        cout << "Error 404  A";
        return -1;}

    cout << "a0 * r^j = " << k << endl;   
    cout << "------------------------------------\n";

    double f;
    int s;
    cout << "first?:";  cin >> f;
    cout << "second?:";  cin >> s;
    Arifm d = make_Arifm(f, s);
    d.Show();

    k = d.Element();
    if (k == -1) {
        cout << "Error 404  d";
        return -1;
    }

    cout << "a0 * r^j = " << k << endl;
    return 0;
}

