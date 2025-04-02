#include <iostream>
#include <clocale>
using namespace std;

int binarySearch(const int arr[], int size, int t)
{
    int left = 0;
    int right = size - 1;

    while (left <= right){
        int mid = left + (right - left) / 2;

        if (arr[mid] == t)
            return mid;

        if (arr[mid] < t){
            left = mid + 1;
        }else{
            right = mid - 1;}
    }
    return -1;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int arr[] = { -18, -17, -11, -10, -6, 5, 9, 12, 15, 32, 35, 49 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int t;
    cout << "Введите число которое хотите найти: ";
    cin >> t;
    int result = binarySearch(arr, size, t);

    if (result != -1){
        cout << "Элемент найден по индексу: " << result << endl;}
    else{
        cout << "Элемент не найден." << endl;}

    return 0;
}