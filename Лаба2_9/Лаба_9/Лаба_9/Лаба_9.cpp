#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    FILE* f1; // Файл f
    FILE* f2; // Файл ff
    f1 = fopen("C:\\Копачи\\Лаба_9\\joke\\f.txt", "r");
    f2 = fopen("C:\\Копачи\\Лаба_9\\joke\\ff.txt", "w");

    const int MAXLINE = 255; //максимальная длина строки
    char s[MAXLINE];
    int k, g;
    while (fgets(s, MAXLINE, f1)){
        k = strlen(s) - 1;

        if ((s[0] == 'а' or s[0] == 'А') && 
            (s[k-1] == 'с' or s[k-1] == 'С')){ 
            fputs(s, f2);
        }
    }

    fclose(f1);
    fclose(f2);

    f2 = fopen("C:\\Копачи\\Лаба_9\\joke\\ff.txt", "r");
    while (fgets(s, MAXLINE, f2))
        cout<<s;
    fclose(f2);

    f2 = fopen("C:\\Копачи\\Лаба_9\\joke\\ff.txt", "r");
    g = 1;
    fgets(s, MAXLINE, f2);
    for (int i = 0; i < strlen(s); i++){

        if (s[i] == ' '){
            g++;
        }

    }
    cout<<"В 1 строке Файл2 " << g << " слов";
    fclose(f2);
    return 0;
}




