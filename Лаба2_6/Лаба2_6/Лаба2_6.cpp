#include <iostream>
#include <stdio.h>
#include <clocale>
using namespace std;
//The cat    saw the cat but another  cat also        saw the cat that    the cat    saw.
//The cat saw the cat but another  also saw the  that   saw.
 
// Функция для удаления множества пробелов
string preprocess(char str[]) {
    char output[1000]; // Буфер для результата
    output[0] = '\0';  // Инициализируем пустую строку

    // Указатель на начало строки
    const char* ptr = str;

    // Флаг для отслеживания первого слова
    bool firstWord = true;

    // Проходим по словам в строке
    while (*ptr != '\0') { //Пока не дойдем до конца строки
        // Пропускаем все пробелы
        while (*ptr == ' ') {
            ptr++;
        }

        // Находим начало и конец текущего слова
        const char* wordStart = ptr;
        while (*ptr != ' ' && *ptr != '\0') {
            ptr++;
        }
        const char* wordEnd = ptr;

        // Добавляем пробел перед словом, если это не первое слово
        if (!firstWord) {
            strcat_s(output, " ");
        }
        firstWord = false;

        // Копируем слово в выходную строку
        int wordLength = wordEnd - wordStart;
        strncat_s(output, wordStart, wordLength);
    }
    cout << "Результат: " << output << endl;
    return output;
}

// Функция для подсчета частоты слов
void findMostFrequentWord(char str[]) {
    int maxCount = 0;
    char mostFrequentWord[100]; // Буфер для хранения самого частого слова
    mostFrequentWord[0] = '\0';

    char currentWord[100]; // Буфер для текущего слова
    currentWord[0] = '\0';

    int wordCount[1000] = { 0 }; // Массив для хранения частоты каждого слова
    char wordsList[1000][100] = {}; // Список уникальных слов

    int wordIndex = 0; // Индекс для списка уникальных слов
    int wordLen = 0;   // Длина текущего слова

    // Проходим по строке и разбиваем её на слова
    for (int i = 0; str[i] != '\0'; ++i) {
        if ((str[i] != ' ') && (str[i] != '.')) {
            currentWord[wordLen++] = str[i];
        }
        else {
            currentWord[wordLen] = '\0'; // Завершаем текущее слово
            wordLen = 0;

            bool found = false;
            // Проверяем, встречалось ли это слово ранее
            for (int j = 0; j < wordIndex; ++j) {
                if ((strcmp(wordsList[j], currentWord) == 0) && (!found)) {
                    wordCount[j]++;
                    found = true;
                }
            }

            // Если слово новое, добавляем его в список
            if (!found) {
                strcpy_s(wordsList[wordIndex], currentWord);
                wordCount[wordIndex] = 1;
                wordIndex++;
            }

            currentWord[0] = '\0';
        }
    }

    // Находим наиболее часто встречающееся слово
    for (int i = 0; i < wordIndex; ++i) {
        if (wordCount[i] > maxCount) {
            maxCount = wordCount[i];
            strcpy_s(mostFrequentWord, wordsList[i]);
        }
    }

    cout << "Самое часто встречающееся слово: \"" 
        << mostFrequentWord << "\" (" << maxCount << " раз)" << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    char s[255]; // Буфер для хранения строки
    printf("Введите строку: ");
    fgets(s, sizeof(s), stdin); // Чтение строки
    printf("Вы ввели: %s\n", s);

    string ass = { preprocess(s) };
    strcpy_s(s, ass.c_str());
    findMostFrequentWord(s);

    return 0;
}