#include <iostream>
#include <string>
#include <cmath> 
using namespace std;

const int TABLE_SIZE = 10; 
const double A = 0.6180339887;

struct KeyValue
{
    string key;
    int value;
    bool isDeleted = false; // Нужно для корректного удаления
};

KeyValue hashTable[TABLE_SIZE]; // Сама таблица (массив структур)

int Hash(const string& key)
{
    unsigned int k = 0;
    for (char c : key)
    {
        k = k * 31 + c; // Простая хеш-функция для строки
    }

    double product = k * A;
    double intPart;
    double fractionalPart = modf(product, &intPart); // Берём дробную часть

    return static_cast<int>(TABLE_SIZE * fractionalPart);
}

// Вставка элемента (с линейным пробированием)
void insert(const std::string& key, int value)
{
    int index = Hash(key);
    int startIndex = index;

    do
    {
        // Если ячейка пуста или помечена как удалённая, вставляем
        if (hashTable[index].key.empty() || hashTable[index].isDeleted)
        {
            hashTable[index].key = key;
            hashTable[index].value = value;
            hashTable[index].isDeleted = false;
            return;
        }
        // Если ключ уже есть, обновляем значение
        else if (hashTable[index].key == key)
        {
            hashTable[index].value = value;
            return;
        }

        index = (index + 1) % TABLE_SIZE; // Линейное пробирование
    }
    while (index != startIndex); // Проверяем, не прошли ли всю таблицу

    std::cerr << "Хеш-таблица переполнена!\n";
}

// Поиск элемента
int* get(const std::string& key)
{
    int index = Hash(key);
    int startIndex = index;

    do
    {
        // Если нашли ключ и он не удалён
        if (!hashTable[index].key.empty() && !hashTable[index].isDeleted && hashTable[index].key == key)
        {
            return &hashTable[index].value;
        }
        // Если дошли до пустой ячейки, значит, ключа нет
        else if (hashTable[index].key.empty())
        {
            break;
        }

        index = (index + 1) % TABLE_SIZE;
    }
    while (index != startIndex);

    return nullptr; // Ключ не найден
}

// Удаление элемента (не физическое, а пометка isDeleted)
bool remove(const std::string& key)
{
    int index = Hash(key);
    int startIndex = index;

    do
    {
        if (!hashTable[index].key.empty() && !hashTable[index].isDeleted && hashTable[index].key == key)
        {
            hashTable[index].isDeleted = true; // Помечаем как удалённый
            return true;
        }
        else if (hashTable[index].key.empty())
        {
            break;
        }

        index = (index + 1) % TABLE_SIZE;
    }
    while (index != startIndex);

    return false; // Ключ не найден
}

// Вывод таблицы (для отладки)
void printTable()
{
    for (int i = 0; i < TABLE_SIZE; ++i)
    {
        if (!hashTable[i].key.empty() && !hashTable[i].isDeleted)
        {
            cout << "[" << i << "] " << hashTable[i].key << ": " << hashTable[i].value << "\n";
        }
        else if (hashTable[i].isDeleted)
        {
            cout << "[" << i << "] <deleted>\n";
        }
        else
        {
            cout << "[" << i << "] <empty>\n";
        }
    }
}

int main()
{
    insert("Alice", 25);
    insert("Bob", 30);
    insert("Charlie", 35);
    insert("Alice", 26); // Обновление Alice

    int* age = get("Bob");
    if (age)
    {
        cout << "Bob's age: " << *age << "\n";
    }

    remove("Charlie");
    printTable();

    return 0;
}