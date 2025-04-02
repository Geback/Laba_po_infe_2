#include <iostream>
#include <clocale>
using namespace std;

int interSearch(int* arr, int t, int s)
{
    int left = 0;
    int right = s;

    while (left <= right && t >= arr[left] && t <= arr[right])
    {
        if (left == right){
            if (arr[left] == t) return left;
            return -1;
        }

        int pos = left + ((double)(right - left) / (arr[right] - arr[left])) * (t - arr[left]);

        if (arr[pos] == t) 
            return pos;

        if (arr[pos] < t){
            left = pos + 1;
        }
        else{
            right = pos - 1;
        }
    }
    return -1;
}

int main()
{
    setlocale(LC_ALL, "rus");
   
    int arr[] = {10, 13, 16, 18, 19, 20, 21, 22, 24, 33, 35, 42, 47};
    int size = sizeof(arr) / sizeof(arr[0]);

    int t;
    cout << "Введите число которое хотите найти: ";
    cin >> t;

    int ind = interSearch(arr, t, size - 1);

    if (ind != -1){
        cout << "Элемент " << t << " найден по индексу " << ind << endl;
    }else{
        cout << "Элемент " << t << " не найден" << endl;}
    return 0;
}