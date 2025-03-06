#include <iostream>
#include <clocale>
#include <cstring>
#include <fstream>
using namespace std;

struct CarOwner
{
    char fio[60];
    int num;
    long int tele;
    long int tran;
};

void wriht(const char* fail, CarOwner* states, int n)
{
    ofstream fale(fail, ios::binary);
    if (!fale.is_open())
    {
        cout << "Ошибка, файл не открыт." << endl;
        return;
    }
    fale.write(reinterpret_cast<char*>(states), sizeof(CarOwner) * n);
    fale.close();
}

void read(const char* fail)
{
    ifstream fale(fail, ios::binary);
    if (!fale.is_open())
    {
        cout << "Ошибка, файл не открыт." << endl;
        return;
    }
    CarOwner a;
    while (fale.read(reinterpret_cast<char*>(&a), sizeof(a)))
    {
        cout << "Фио: " << a.fio
            << ", Номер авто:" << a.num
            << ", Телефон:" << a.tele
            << ", Номер техпаспорта:" << a.tran << endl;
    }
    fale.close();
}
          
void deleteName(const char* fale, int* numName)
{
    ifstream fail(fale, ios::binary);
    if (!fail.is_open())
    {
        cout << "Ошибка, файл не открыт." << endl;
        return;
    }
    int k = 0;
    CarOwner a;
    CarOwner* Te = new CarOwner[100];
    while (fail.read(reinterpret_cast<char*>(&a), sizeof(a)))
    {
        if (a.num != *numName)
        {
            Te[k] = a;
            k++;
        }
    }
    fail.close();
    wriht(fale, Te, k);
    delete[] Te;
}

void newElement(const char* file, int n)
{
    ifstream fale(file, ios::binary);
    if (!fale.is_open())
    {
        cout << "Ошибка, файел не открыт" << endl;
        return;
    }

    CarOwner* old = new CarOwner[1000];
    CarOwner* re = new CarOwner[2];

    int k = 0;
    while ((fale.read(reinterpret_cast<char*>(&old[k]), sizeof(CarOwner))))
    {
        k++;
    }

    for (int i = 0; i < 2; i++)
    {
        cin.clear();
        cin.ignore();

        cout << "Фио:";
        cin.getline(re[i].fio, sizeof(re[i].fio));

        cout << "Номер авто:";
        cin >> re[i].num;

        cout << "Телефон:";
        re[i].tele = old[k + i].tele;
        cin >> re[i].tele;

        cout << "Номер техпаспорта:";
        re[i].tran = old[k + i].tran;
        cin >> re[i].tran;
    }

    CarOwner* newData = new CarOwner[1000 + 2];
    int newIndex = 0;

    for (int i = 0; i < n-1; ++i)
    {
        newData[newIndex++] = old[i];
    }

    for (int i = 0; i < 2; ++i)
    {
        newData[newIndex++] = re[i];
    }

    for (int i = n-1; i < k; ++i)
    {
        newData[newIndex++] = old[i];
    }

    fale.close();
    wriht(file, newData, k + 2);
    delete[] old;
    delete[] re;
    delete[] newData;
}

int main()
{
    setlocale(LC_ALL, "RU");
    int n;
    cout << "Введите число владельцев автомобиля: " << endl;
    cin >> n;

    CarOwner* states = new CarOwner[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Введите введение <entr>: " << endl;
        cin.clear();
        cin.ignore();
        cout << "Фио:";
        cin.getline(states[i].fio, sizeof(states[i].fio));
        cout << "Номер авто:";
        cin >> states[i].num;
        cout << "Телефон:";
        cin >> states[i].tele;
        cout << "Номер техпаспорта:";
        cin >> states[i].tran;
        cin.ignore();
    }
    wriht("C:\\Копачи\\Лаба_8\\666\\onemoretime.bin", states, n);
    cout << "\nСодержимое файла:" << endl;
    read("C:\\Копачи\\Лаба_8\\666\\onemoretime.bin");
    cin.ignore();
    int del;
    int ya;
    
    cout << "ВВедите номер авто для удаляния: " << endl;
    cin >> del;
    deleteName("C:\\Копачи\\Лаба_8\\666\\onemoretime.bin", &del);

    cout << "\nСодержимое файла после удаления:" << endl;
    read("C:\\Копачи\\Лаба_8\\666\\onemoretime.bin");

    cout << "ВВедите номер элемента для записи: " << endl;
    cin >> ya;

    cout << "Введите еще 2 владельцев: " << endl;
    newElement("C:\\Копачи\\Лаба_8\\666\\onemoretime.bin", ya);
    cout << "\nСодержимое файла после добавления:" << endl;
    read("C:\\Копачи\\Лаба_8\\666\\onemoretime.bin");
    
    delete[] states;
    return 0;
}
