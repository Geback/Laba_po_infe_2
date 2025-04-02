#include <iostream>
using namespace std;
// 527 443 -56 924 869 -502 24 -395 946 254 708 242 -592 -242 263
// -972, 47, 569, 803, -291, 530, 45, -986, -154, 450, 825, 378, -937, 748, 543
//709, -51, -615, 565, -139, -105, 194, 969, 191, -648, 915, -642, 699, 960, 851

void counting(int* d, int s)
{
    int min = 99999;
    int max = -99999;

    for (int i = 0; i < s; i++){
        if (min > d[i]){
            min = d[i];}
        if (max < d[i]){
            max = d[i];}
    }

    int y = max - min + 1;
    int* vs = new int [y] { 0 };

    for (int j = 0; j < s; j++){
        vs[d[j] - min] += 1;
    }

    int g = 0;
    for (int i = 0; i < (max - min + 1); i++){
        while (vs[i] > 0){
            d[g] = i + min;
            vs[i] -= 1;
            g++;
        }
    }
    return;
}

int main()
{
    int d[15] = { -972, 47, 569, 803, -291, 530, 45, -986, -154, 450, 825, 378, -937, 748, 543 };

    cout << "оcnovnaya posled:";
    for (int i = 0; i < 15; i++){
        cout << d[i] << " ";
    }
    cout << endl;

    int min = 99;
    int max = -99;

    for (int i = 0; i < 15; i++){
        if (min > d[i] / 100){
            min = d[i] / 100;}
        if (max < d[i] / 100){
            max = d[i] / 100;}
    }

    int y = max - min + 1;
    int** b = new int* [y] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; //массив блоков
    int* co = new int[y] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; // подсчет

    for (int j = 0; j < 15; j++){
        co[(d[j] / 100) - min] += 1;
    }

    cout << "pamat' v blokah:";
    for (int i = 0; i < y; i++){
        cout << co[i] << " ";
    }
    cout << endl;
    cout << "blocks:" << endl;

    for (int i = 0; i < y; i++){
        int c = 0;
        if (co[i] > 0){
            b[i] = new int[co[i]];
            for (int h = 0; h < 15; h++){
                if (d[h] / 100 == i + min){
                    b[i][c] = d[h];
                    cout << b[i][c] << " ";
                    c++;
                }
            }
            cout << endl;
        }
    }

    for (int h = 0; h < y; h++){
        if (co[h] > 1){
            counting(b[h], co[h]);
        }
    }

    cout << endl << "otsort blocks:" << endl;    
    for (int i = 0; i < y; i++){
        int c = 0;
        
        if (co[i] > 0){
            for (int h = 0; h < 15; h++){
                if (d[h] / 100 == i + min){
                    cout << b[i][c] << " ";
                    c++;
                }
            }
            cout << endl;
        }
    }

    cout << "otsort posled: ";
    for (int i = 0; i < y; i++){
        if (co[i] > 0){
            for (int j = 0; j < co[i]; j++){
                cout << b[i][j] << " ";
            }
        }
    }
    cout << endl;

    for (int i = 0; i < y; i++){
        delete[] b[i];}

    delete[] b;
    delete[] co;

    return 0;
}
