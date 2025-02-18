#include <iostream>
using namespace std;
int c;

void Pi(int n)
{
    while (n > 0)
    {
        cout << "*";
        n--;
    }
    cout << endl;
}

void Han(int n, int start, int point,int temp)
{
    if (n != 0)
    {
        Han(n - 1, start, temp, point);
        Pi(n);
        cout << start << "=>" << point << endl;
        Han(n - 1, temp, point, start);
    }
    return;
}


int main()
{
    cin >> c;
    cout << endl;
    while (c <= 0)
    {
        cout << "VVedi pologitelnoe chiclo:";
        cin >> c;
    }
    Han(c, 1, 3, 2);
    return 0;
}



