#include <iostream>
#include <clocale>
using namespace std;


void Prefix(const char* o, int oSize, int* pi)
{
    pi[0] = 0;

    int k = 0;
    for (int q = 1; q < oSize; ++q){
        while (k > 0 && o[k] != o[q]){
            k = pi[k - 1];
        }

        if (o[k] == o[q]){
            k++;
        }
        pi[q] = k;
    }
}

int KMP(const char* text, int tSize, const char* o, int oSize)
{
    if (oSize == 0) return 0;

    int* pi = new int[oSize];
    Prefix(o, oSize, pi);

    int q = 0;

    for (int i = 0; i < tSize; ++i){
        while (q > 0 && o[q] != text[i]){
            q = pi[q - 1]; 
        }

        if (o[q] == text[i]){
            q++;
        }

        if (q == oSize){
            delete[] pi;
            return i - oSize + 1; 
        }
    }

    delete[] pi;
    return -1;
}

int main()
{
    setlocale(LC_ALL, "rus");
    const char* text = "ABABDABACDABABCABAB";
    const char* obraz = "ABABCABAB";

    int text_len = 0;
    while (text[text_len] != '\0') text_len++;

    int obraz_len = 0;
    while (obraz[obraz_len] != '\0') obraz_len++;

    int pos = KMP(text, text_len, obraz, obraz_len);

    if (pos != -1){
        cout << "Образ начинается с " << pos << " индекса" << endl;
    }
    else{
        cout << "Образ не найден" << endl;
    }

    return 0;
}