#define TABLE_SIZE 90
#define _CRT_SECURE_NO_WARNINGS
//Метод цепочек
#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime> 
#include <clocale>
using namespace std;

int collisions = 0;
const double A = 0.6180339887;

struct Node {  //
    string name;
    char data[256];
    string tele;
    Node* next;
};

Node* hashTable[TABLE_SIZE];

unsigned int hashFunction(const char* key) {  ///
    unsigned int k = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        k += (unsigned char)key[i];
    }

    double product = k * A;
    double fractional = product - (unsigned int)product;

    return (unsigned int)(TABLE_SIZE * fractional);
}

// Инициализация таблицы ////
void initH() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = nullptr;
    }
}

// Вставка элемента ///
void insert(string key, const char* dat, string t) {
    unsigned int index = hashFunction(dat);

    Node* newNode = new Node;
    strncpy_s(newNode->data, dat, 255);
    newNode->name = key;
    newNode->tele = t;
    newNode->next = nullptr;

    if (hashTable[index] == nullptr) {
        hashTable[index] = newNode;
    }
    else {
        collisions++;
        Node* temp = hashTable[index];
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Генерация случайного ключа (латинские буквы) ///
void generateRandomKey(char* key, int maxLength) {
    const char chars[] = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int len = 5 + rand() % (maxLength - 6); // Длина от 5 до maxLength-1

    for (int i = 0; i < len; i++) {
        key[i] = chars[rand() % (sizeof(chars) - 1)];
    }
    key[len] = '\0';

}

void generateT(char* key) {   ////
    const char chars[] = "1234567890";
    int len = 5 + rand() % 6;

    for (int i = 0; i < len; i++) {
        key[i] = chars[rand() % (sizeof(chars) - 1)];
    }
    key[len] = '\0';
}

// Заполнение таблицы случайными данными   /////
void randomFill(int numItems) {
    srand(time(NULL)); // Инициализация генератора случайных чисел
    string* DATES = new string[20]{ "27.01.1988","28.02.1967","29.04.1999","30.05.1867",
        "31.12.1999","01.06.1976","02.07.1980","03.08.1982","04.09.1955","05.10.1948", 
        "04.08.2008", "30.06.1988","31.07.2013", "03.12.2021","11.03.1950","08.03.1950"
        ,"25.11.1987","11.01.2003","06.11.1965","06.10.1960" };

    for (int i = 0; i < numItems; i++) {
        char key[256];
        char tele[30];
        char data[11];
        generateRandomKey(key, 25);
        strcpy(data, DATES[rand() % 20].c_str());
        generateT(tele);

        insert(key, data, tele);
    }
    delete[] DATES;
}
 
// Поиск элемента   ////
void find(const char* key) {
    unsigned int index = hashFunction(key);
    bool found = false;
    Node* temp = hashTable[index];

    // Поиск элемента в цепочке
    while (temp != nullptr && !found){
        if (strcmp(temp->data, key) == 0){
            found = true;
            cout << "Bucket " << index << ":\n";
            cout << "  Key: '" << temp->name
                << "', Data: " << temp->data
                << "', Tele: " << temp->tele << "\n";
        }
        temp = temp->next;
    }

    if (!found) cout << "Не найдено" << "\n";
}

// Удаление элемента  ...
void remov(const char* key) {
    unsigned int index = hashFunction(key);
    Node* nodeD = hashTable[index];
    if (!nodeD) return;
    Node* prev = nullptr;

for (Node* temp = hashTable[index]; temp != nodeD; prev = temp, temp = temp->next) {}
    
    if (prev) {
        prev->next = nodeD->next;
    } else {
        hashTable[index] = nodeD->next;
    }
    
    delete nodeD;
}

// Функция вывода хеш-таблицы в консоль   ....
void printH() {
      cout << "--------------------\n";

    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = hashTable[i];
        if (current != nullptr) {
            cout << "Bucket " << i << ":\n";

            int itemCount = 1;
            while (current != nullptr) {
                cout << "  [" << itemCount << "] Key: '" << current->name
                    << "', Data: " << current->data << 
                    "', Tele: " << current->tele << "\n";
                current = current->next;
                itemCount++;
            }
        }
    }
    cout << "--------------------\n";
}
// Очистка таблицы ///
void clear() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* temp = hashTable[i];
        while (temp != nullptr) {
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
        hashTable[i] = nullptr;
    }
    collisions = 0;
}

// Функция записи хеш-таблицы в файл  ////
void saveH(const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Failed to open file for writing");
        return;
    }

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Node* current = hashTable[i];
        while (current != nullptr)
        {
            char name[256] = { 0 };
            char tele[256] = { 0 };
            strncpy(name, current->name.c_str(), 255);
            strncpy(tele, current->tele.c_str(), 255);

            fwrite(name, sizeof(char), 256, file);
            fwrite(current->data, sizeof(char), 256, file);
            fwrite(tele, sizeof(char), 256, file);

            current = current->next;
        }
    }

    fclose(file);
}

// Функция загрузки хеш-таблицы из файла
void loadH(const char* filename) {   ///
    FILE* file = fopen(filename, "rb");
    if (!file) {
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

int main() {
    setlocale(LC_ALL,"rus");
    const char file[] = "D:\\Копачи\\HeshTable\\d.txt";
    cout <<"Метод цепочек\n";
    initH();

    insert("apple", "10.10.10", "88005553535");
    insert("banana", "20.20.20", "8843653535");
    insert("orange", "30.30.30", "98452553535");
   
    saveH(file);

    randomFill(10);

    printH();
    cout << "collisions: " << collisions << endl;

    char y;
    do
    {

        cout << "Хотите найти элемент? y/n:";
        cin >> y;
        if (y == 'y')
        {
            char* g = new char[256];
            cout << "Напишите дату искомого элемента:";
            cin >> g;
            find(g);
        }

    }
    while (y == 'y');
    
    //loadH(file);
    //printH();

    clear();
    return 0;
}