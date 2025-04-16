#include <iostream>
#include <cmath>
#include "Header.h"
using namespace std;

void Arifm::Init(double F, int S) {
	first = F;
	second = S;

}
void Arifm::Read() {
	cout << "first?:";  cin >> first;
	cout << "second?:";  cin >> second;

}
void Arifm::Show() {
	cout << "\nfirst=" << first;
	cout << "\nsecond=" << second;
}

double Arifm::Element() {
	int j;
	cout << "\n¬ведите чило:";
	cin >> j;
	cout << endl;
	if (j < 0) return -1;
	double k = first * pow(second, j);
	return k;
}
