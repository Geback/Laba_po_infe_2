#include <iostream>
#include <clocale>
using namespace std;

void prepBadChar(char* oo, int pSize, int badChar[256]){
    for (int i = 0; i < 256; i++)
        badChar[i] = -1;

    for (int i = 0; i < pSize; i++)
        badChar[(int)oo[i]] = i;
}

void search(char* s, char* o, int sSize, int oSize)
{
    bool sheald = true;
    int badChar[256];
    prepBadChar(o, oSize, badChar);

    int shift = 0;
    while (shift <= (sSize - oSize))
    {
        int j = oSize - 1;

        while (j >= 0 && o[j] == s[shift + j])
            j--;

        if (j < 0){
            cout << "Образ начинается с " << shift << " индекса" << endl;
            sheald = false;
            shift += (shift + oSize < sSize) ? oSize - badChar[s[shift + oSize]] : 1;
        }else{
            if ((j - badChar[s[shift + j]]) > 1){
                shift += j - badChar[s[shift + j]];
            }else{
                shift += 1;
            }
        }
    }

    if (sheald){
        cout << "Образ не найден" << endl;
    }
}

int main(){
    setlocale(LC_ALL, "rus");
    char stroka[] = "abccbfdsadkacaabcd";
    char obraz[] = "aabc";

    int sSize = (sizeof(stroka) / sizeof(stroka[0])) - 1;
    int oSize = (sizeof(obraz) / sizeof(obraz[0])) - 1;
    search(stroka, obraz, sSize, oSize);

    return 0;
}
