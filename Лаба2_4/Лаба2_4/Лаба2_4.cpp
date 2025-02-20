#include <iostream>
#include <clocale>
using namespace std;
int n;   //это К

int main()
{
    setlocale(LC_ALL, "RU");
    const int S = 6;
    cin >> n;
    int a[S] = { 5,3,2,1, 9, 4 };
    int o[S + 3];
    int k = 0;

    
    for (int i = 0; i < S; i++) {
        cout << a[i] << " ";
    }  
    cout << "Изначальный массив" << endl;

    for (int i = n; i >= 0; i--) {
        
        cout << a[i] << " ";
        o[k] = a[i];
        k++;
    }

    for (int i = S-1; (i > n-1); i--) {

        cout << a[i] << " ";
        o[k] = a[i];
        k++;
    }
    cout << "Массив от К до К-1 (влево)";
    o[k] = a[0];
    k++;
    o[k] = a[S-1];
    k++;

    cout << endl;
    for (int i = 0; i < S + 3; i++) {
        cout << o[i] << " ";
    }

    cout << "Выведенный массив + первый и последний элементы" << endl;
    for (int i = n; i < S+3; i++) {

        cout << o[i] << " ";
       
    }
    for (int i = 0; i < n; i++) {

        cout << o[i] << " ";
    }
    cout << "Выведенный массив от К до К+1 (вправо)";
    return 0;
}

