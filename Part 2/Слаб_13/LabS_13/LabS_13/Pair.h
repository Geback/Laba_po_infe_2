#pragma once
#include <iostream>
using namespace std;

class Pair
{
public:
	Pair();
	Pair(int first, double second);
	Pair(int val);
	Pair(const Pair& copy);
	~Pair() {}
	int GetFirst() const { return this->first; }
	double GetSecond() const { return this->second; }
	void SetFirst(int first) { this->first = first; }
	void SetSecond(double second) { this->second = second; }
	Pair& operator =(const Pair& other);
	Pair operator +(const Pair& other) const;
	Pair& operator ++();
	Pair operator ++(int);
	Pair operator -(const Pair& other);
	bool operator <(const Pair& other) const;
	bool operator >(const Pair& other) const;
	bool operator ==(const Pair& other);
	friend const Pair operator +(const Pair& left, const int& right);
	friend const Pair operator +(const int& left, const Pair& right);
	friend const Pair operator +(const Pair& left, const double& right);
	friend const Pair operator +(const double& left, const Pair& right);
	Pair operator /(const Pair& other);
	Pair operator /(const int other);
	friend ostream& operator <<(ostream& os, const Pair& str);
	friend istream& operator >> (istream& is, Pair& str);
	Pair randomGener();
private:
	int first;
	double second;
};