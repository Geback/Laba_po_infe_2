#include "List.h"
#include "Error.h"
#include <iostream>
#include <exception>
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
        cout << "dddr\n";
        cout <<"a[5]:"<< a[5] << endl;
        cout << "b: " << b;
        List c = a * b;
        cout << "b + 6: " << b + 6 << endl;
        cout << "b + 7: " << b + 7;
    }
    catch (Error& e)
    {
        e.what();
    }
    catch (...)
    {
        cout << "Unknown exception occurred" << endl;
    }
    return 0;
}