#define TABLE_SIZE 90
#define _CRT_SECURE_NO_WARNINGS
//Метод открытой адресации

#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime> 
#include <clocale>
using namespace std;

int collisions = 0;
const double A = 0.6180339887;

struct Node
{
    string name;
    char data[256];
    string tele;
    bool isDeleted;
    bool isEmpty;
};

Node hashTable[TABLE_SIZE];

unsigned int hashFunction(const char* key)
{
    unsigned int k = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        k += (unsigned char)key[i];
    }

    double product = k * A;
    double fractional = product - (unsigned int)product;

    return (unsigned int)(TABLE_SIZE * fractional);
}

void initH()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i].isEmpty = true;
        hashTable[i].isDeleted = false;
    }
}

void insert(string key, const char* dat, string t)
{
    unsigned int index = hashFunction(dat);
    int originalIndex = index;
    bool inserted = false;
    int i = 0;

    while (i < TABLE_SIZE && !inserted)
    {
        int currentIndex = (index + i) % TABLE_SIZE;

        if (hashTable[currentIndex].isEmpty || hashTable[currentIndex].isDeleted)
        {
            strncpy_s(hashTable[currentIndex].data, dat, 255);
            hashTable[currentIndex].name = key;
            hashTable[currentIndex].tele = t;
            hashTable[currentIndex].isEmpty = false;
            hashTable[currentIndex].isDeleted = false;
            inserted = true;
        }
        else if (strcmp(hashTable[currentIndex].data, dat) == 0)
        {
            hashTable[currentIndex].name = key;
            hashTable[currentIndex].tele = t;
            inserted = true;
        }
        else
        {
            collisions++;
        }
        i++;
    }

    if (!inserted)
    {
        cout << "Хеш-таблица переполнена!" << endl;
    }
}

void generateRandomKey(char* key, int maxLength)
{
    const char chars[] = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int len = 5 + rand() % (maxLength - 6);

    for (int i = 0; i < len; i++)
    {
        key[i] = chars[rand() % (sizeof(chars) - 1)];
    }
    key[len] = '\0';
}

void generateT(char* key)
{
    const char chars[] = "1234567890";
    int len = 5 + rand() % 6;

    for (int i = 0; i < len; i++)
    {
        key[i] = chars[rand() % (sizeof(chars) - 1)];
    }
    key[len] = '\0';
}

void randomFill(int numItems)
{
    srand(time(NULL));
    string DATES[20] = { "27.01.1988","28.02.1967","29.04.1999","30.05.1867",
        "31.12.1999","01.06.1976","02.07.1980","03.08.1982","04.09.1955","05.10.1948",
        "04.08.2008", "30.06.1988","31.07.2013", "03.12.2021","11.03.1950","08.03.1950"
        ,"25.11.1987","11.01.2003","06.11.1965","06.10.1960" };

    for (int i = 0; i < numItems; i++)
    {
        char key[256];
        char tele[30];
        char data[11];
        generateRandomKey(key, 25);
        strcpy(data, DATES[rand() % 20].c_str());
        generateT(tele);

        insert(key, data, tele);
    }
}

void find(const char* key)
{
    unsigned int index = hashFunction(key);
    bool found = false;
    int i = 0;

    while (i < TABLE_SIZE && !found)
    {
        int currentIndex = (index + i) % TABLE_SIZE;

        if (hashTable[currentIndex].isEmpty && !hashTable[currentIndex].isDeleted)
        {
            i = TABLE_SIZE; // Прерываем цикл
        }
        else if (!hashTable[currentIndex].isEmpty && !hashTable[currentIndex].isDeleted &&
            strcmp(hashTable[currentIndex].data, key) == 0)
        {
            cout << "Index " << currentIndex << ":\n";
            cout << "  Key: '" << hashTable[currentIndex].name
                << "', Data: " << hashTable[currentIndex].data
                << "', Tele: " << hashTable[currentIndex].tele << "\n";
            found = true;
        }
        i++;
    }

    if (!found)
    {
        cout << "Не найдено" << "\n";
    }
}

void remov(const char* key)
{
    unsigned int index = hashFunction(key);
    bool removed = false;
    int i = 0;

    while (i < TABLE_SIZE && !removed)
    {
        int currentIndex = (index + i) % TABLE_SIZE;

        if (hashTable[currentIndex].isEmpty && !hashTable[currentIndex].isDeleted)
        {
            i = TABLE_SIZE; // Прерываем цикл
        }
        else if (!hashTable[currentIndex].isEmpty && !hashTable[currentIndex].isDeleted &&
            strcmp(hashTable[currentIndex].data, key) == 0)
        {
            hashTable[currentIndex].isDeleted = true;
            hashTable[currentIndex].isEmpty = true;
            cout << "Элемент удален\n";
            removed = true;
        }
        i++;
    }

    if (!removed)
    {
        cout << "Элемент для удаления не найден\n";
    }
}

void printH()
{
    cout << "--------------------\n";

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (!hashTable[i].isEmpty && !hashTable[i].isDeleted)
        {
            cout << "Index " << i << ":\n";
            cout << "  Key: '" << hashTable[i].name
                << "', Data: " << hashTable[i].data
                << "', Tele: " << hashTable[i].tele << "\n";
        }
    }
    cout << "--------------------\n";
}

void clear()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i].isEmpty = true;
        hashTable[i].isDeleted = false;
    }
    collisions = 0;
}

void saveH(const char* filename)
{
    FILE* file = fopen(filename, "wb");
    if (!file)
    {
        perror("Failed to open file for writing");
        return;
    }

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (!hashTable[i].isEmpty && !hashTable[i].isDeleted)
        {
            char name[256] = { 0 };
            char tele[256] = { 0 };
            strncpy(name, hashTable[i].name.c_str(), 255);
            strncpy(tele, hashTable[i].tele.c_str(), 255);

            fwrite(name, sizeof(char), 256, file);
            fwrite(hashTable[i].data, sizeof(char), 256, file);
            fwrite(tele, sizeof(char), 256, file);
        }
    }

    fclose(file);
}

void loadH(const char* filename)
{
    FILE* file = fopen(filename, "rb");
    if (!file)
    {
        perror("Failed to open file for reading");
        return;
    }
    clear();

    char name[256];
    char data[256];
    char tele[256];
    bool readSuccess = true;

    while (readSuccess)
    {
        size_t nameRead = fread(name, sizeof(char), 256, file);
        size_t dataRead = fread(data, sizeof(char), 256, file);
        size_t teleRead = fread(tele, sizeof(char), 256, file);

        readSuccess = (nameRead == 256) && (dataRead == 256) && (teleRead == 256);

        if (readSuccess)
        {
            insert(string(name), data, string(tele));
        }
    }

    fclose(file);
    cout << "Hash table loaded from " << filename << endl;
}

int main()
{
    setlocale(LC_ALL, "rus");
    const char file[] = "D:\\Копачи\\HeshTable\\d.txt";
    cout << "Метод открытой адресации\n";
    initH();

    insert("apple", "10.10.10", "88005553535");
    insert("banana", "20.20.20", "8843653535");
    insert("orange", "30.30.30", "98452553535");

    saveH(file);

    randomFill(100);

    printH();
    cout << "collisions: " << collisions << endl;

    char y;
    do
    {
        cout << "Хотите найти элемент? y/n:";
        cin >> y;
        if (y == 'y')
        {
            char g[256];
            cout << "Напишите дату искомого элемента:";
            cin >> g;
            find(g);
        }
    }
    while (y == 'y');

    clear();
    return 0;
}