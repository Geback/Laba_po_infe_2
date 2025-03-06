#include<iostream>
#include<cmath>
using namespace std;
float a;
int b;

double ch_m(int min)
{
    cout << "hours:" << min / 60 << " minutes:" << min - (min / 60 * 60);
    return 0.0;
}

double ch_m(float ch)
{
    float c;
    float h = modf(ch, &c);
    cout << "minutes:" << c * 60 + h * 100;
    return 0.0;
}

int main()
{
    char r;
    cout << "hours and minutes => minutes y/n:";
    cin >> r;
    cout << endl;

    if (r == 'y'){
        cin >> a;
        if (a < 0)
        {
            cout<<">6(";
            return -1;
        }
        ch_m(a);
    }
    else{
        cin >> b;
        if (b < 0)
        {
            cout << ">9(";
            return -1;
        }
        ch_m(b);
    }

    return 0;
}