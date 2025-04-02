
#include <iostream>
#include <clocale>
using namespace std;
int n;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;}

void Show(int arr[], int size){
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;}

int raz(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;

    while (true)
    {
        do{
            i++;}
        while (arr[i] < pivot);

        do{
            j--;}
        while (arr[j] > pivot);

        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
        Show(arr, n);
    }
}

void quickSort(int arr[], int low, int high){
    if (low < high){
        int pi = raz(arr, low, high);

        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}



int main()
{
    setlocale(LC_ALL,"rus");
    int arr[] = { 8, -23, -76, -7, -60, -1, 98, -46, 81, 58, 73, 67 };
    n = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив: "<<endl;
    Show(arr, n);
    cout<<"=====================================" << endl;
    quickSort(arr, 0, n - 1);
    cout<<"=====================================" << endl;

    cout << "Отсортированный массив: " << endl;
    Show(arr, n);

    return 0;
}