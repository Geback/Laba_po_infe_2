#include <iostream>
#include <clocale>
using namespace std;


void razdelenie(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1; // levo part
    int n2 = right - mid;    // pravo part

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Слияние временных массивов обратно в arr
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1){ //levo
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2){  //pravo
        arr[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

void sliyanie(int arr[], int left, int right)
{
    if (left < right){
        int mid = left + (right - left) / 2;

        sliyanie(arr, left, mid);
        sliyanie(arr, mid + 1, right);
        razdelenie(arr, left, mid, right);
    }
}


void Show(int arr[], int size){
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int arr[] = { 2, 4, 7, -8, 5, 6, 4, 2, 1, 0, -6 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив: ";
    Show(arr, size);

    sliyanie(arr, 0, size - 1);

    cout << "Отсортированный массив: ";
    Show(arr, size);

    return 0;
}
