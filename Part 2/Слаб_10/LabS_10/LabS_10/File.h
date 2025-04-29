#include "Pair.h"
#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std;

int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);
	if (!stream) return -1;
	int n;
	Pair p;
	cout << "Количество пар: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		stream << p << '\n';
	}
	stream.close();
	return n;
}

int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in);
	if (!stream)return -1;
	Pair p;
	int i = 0;
	while (stream >> p)
	{
		cout << p << " ";
		i++;
	}
	cout<<endl;
	stream.close();
	return i;
}

int del_file(const char* f_name, Pair t)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream)return -1;
	int i = 0;
	Pair p;
	while (stream >> p)
	{
		if (stream.eof()) break;
		i++;

		if (t < p) temp << p;
	}

	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}

int add_file(const char* f_name, int k, int count)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Pair p; int i = 0, l = 0;
	while (stream >> p)
	{
		if (stream.eof())break;
		i++;
		temp << p;
		if (i == k)
		{
			for (int j = 0; j < count; j++)
			{
				Pair new_Pair;
				cin >> new_Pair;
				temp << new_Pair;
				l++;
			}
		}
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;
}

int add_end(const char* f_name, int count)
{
	fstream stream(f_name, ios::app);
	if (!stream) return -1;
	for (int i = 0; i < count; i++)
	{
		Pair new_Pair;
		cin >> new_Pair;
		stream << new_Pair;
	}
	return 1;
}

int change_file(const char* f_name, double k)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Pair p; int l = 0;
	while (stream >> p)
	{
		if (stream.eof()) break;
		if (k == (int)k)
			p + (int)k;
		else
			p + k;
		temp << p;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;
}