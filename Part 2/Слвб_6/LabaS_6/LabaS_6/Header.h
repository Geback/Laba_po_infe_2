// Header.h
#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

class List
{
public:
	class Node
	{
	public:
		Node(int value, Node* next = nullptr) : value_(value), next_(next) {}
		int getValue() const { return value_; }
		Node* getNext() const { return next_; }
		void setNext(Node* next) { next_ = next; }
	private:
		int value_;
		Node* next_;
	};

protected:
	Node* head_;
public:
	List();
	List(const List& other);
	~List();

	void push_back(int value);

	List& operator=(const List& other);
	friend ostream& operator<<(ostream& os, const List& list);
	friend istream& operator>>(istream& is, List& list);

	int operator[](int index) const;
	int size() const;
	friend List operator*(const List& a, const List& b);

	class Iterator
	{
	public:
		Iterator(Node* node = nullptr) : node_(node) {}
		int operator*() const { return node_->getValue(); }
		Iterator operator+(int n) const;
		Iterator& operator++();
		bool operator==(const Iterator& other) const { return node_ == other.node_; }
		bool operator!=(const Iterator& other) const { return !(*this == other); }
	private:
		Node* node_;
	};

	Iterator begin() const { return Iterator(head_); }
	Iterator end() const { return Iterator(nullptr); }

	
};

#endif