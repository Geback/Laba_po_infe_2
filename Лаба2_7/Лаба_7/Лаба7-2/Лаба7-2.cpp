#include <iostream>
#include <cstdarg>
using namespace std;

int dateToDays(int day, int month, int year)
{
    int dayM[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    bool Year4 = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (Year4 && month > 2)
    {
        dayM[1] = 29;
    }

    int td = 0;
    for (int i = 0; i < month - 1; ++i)
    {
        td += dayM[i];
    }
    td += day;

    for (int y = 1970; y < year; ++y)
    {
        td += (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0) ? 366 : 365;
    }

    return td;
}

int findMin(int arr[], int size)
{
    int min = arr[0];
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int findMax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void days(int argc, ...)
{
    if (argc < 2)
    {
        cout << "Error: At least two dates must be specified." << endl;
        return;
    }

    int* dayArr = new int[argc / 3];
    int* monthArr = new int[argc / 3];
    int* yearArr = new int[argc / 3];

    va_list args;
    va_start(args, argc);

    for (int i = 0; i < argc / 3; ++i)
    {
        dayArr[i] = va_arg(args, int);
        monthArr[i] = va_arg(args, int);
        yearArr[i] = va_arg(args, int);
    }

    va_end(args);
    int* datesAsDays = new int[argc / 3];
    for (int i = 0; i < argc / 3; ++i)
    {
        datesAsDays[i] = dateToDays(dayArr[i], monthArr[i], yearArr[i]);
    }

    int minD = findMin(datesAsDays, argc / 3);
    int maxD = findMax(datesAsDays, argc / 3);

    cout << "Number of days between the earliest and latest dates: "
        << (maxD - minD) << endl;
}

int main()
{
    cout << "Call with 3 parameters:" << endl;
    days(9, 1, 1, 2022, 15, 6, 2024, 1, 1, 2025);

    cout << "\nCall with 5 parameters:" << endl;
    days(15, 1, 1, 2022, 15, 6, 2022, 31, 12, 2022, 10, 10, 2022, 25, 5, 2022);

    cout << "\nCall with 8 parameters:" << endl;
    days(24, 1, 1, 1999, 15, 6, 2022, 31, 12, 2022, 10, 10, 2024, 25, 5, 2022, 5, 3, 1962, 18, 7, 2022, 22, 11, 2022);

    return 0;
}