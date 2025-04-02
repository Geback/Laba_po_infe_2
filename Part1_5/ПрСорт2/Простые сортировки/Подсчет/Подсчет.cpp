#include <iostream>
using namespace std;

int main()
{
    int d[11] = { 2, 4, 7, -8, 5, 6, 4, 2, 1, 0, -6 };
    for (int i = 0; i < 11; i++)
    {
        cout << d[i] << " ";
    }

    int min = 99999;
    int max = -99999;

    for (int i = 0; i < 11; i++)
    {
        if (min > d[i])
        {
            min = d[i];
        }
        if (max < d[i])
        {
            max = d[i];
        }
    }

    cout << endl <<"min:" << min << "  " <<"max:" << max << endl;
    int y = max - min + 1;

    int* vs = new int [y] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    for (int j = 0; j < 11; j++)
    {
        vs[d[j] - min] += 1;
    }

    for (int i = 0; i < (max - min + 1); i++)
    {
        cout << vs[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < (max - min + 1); i++)
    {
        while (vs[i] > 0)
        {
            cout << i + min << " ";
            vs[i] -= 1;
        }
    }
    return 0;
}

