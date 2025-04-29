#pragma once
#ifndef LIST_H
#define LIST_H
#include <clocale>
#include <iostream>
using namespace std;

struct Node
{
    Node* prev = nullptr;
    Node* next = nullptr;
    int data;
};

class List
{
public:
    int front() const; 
    int back() const;   
    void pushback(int data);
    void pushfront(int data);
    void popback();
    void popfront();
    bool empty() const;

    List& operator=(const List& a);
    int& operator[](int index);
    int operator()() const; 
    List operator*(List& a);
    friend ostream& operator<<(ostream&, const List&);
    friend istream& operator>>(istream&, List&);

    int& operator+(int n);

    List();
    List(int s);
    List(const List&);
    ~List();

protected:
    int size; 
    Node* head = nullptr;
    Node* tail = nullptr;
};
#endif
