// List.cpp
#include "Header.h"
#include <iostream>
using namespace std;

List::List() : head_(nullptr) {}

List::List(const List& other) {
	if (other.head_ == nullptr) {
		head_ = nullptr;
	}
	else {
		head_ = new Node(other.head_->getValue());
		Node* thisNode = head_;
		Node* otherNode = other.head_->getNext();
		while (otherNode != nullptr) {
			thisNode->setNext(new Node(otherNode->getValue()));
			thisNode = thisNode->getNext();
			otherNode = otherNode->getNext();
		}
	}
}

List::~List() {
	while (head_ != nullptr) {
		Node* temp = head_;
		head_ = head_->getNext();
		delete temp;
	}
}

void List::push_back(int value){
	Node* newNode = new Node(value);

	if (head_ == nullptr){
		head_ = newNode;
	}else{ 
		Node* current = head_;
		while (current->getNext() != nullptr){ 
			current = current->getNext();
		}
		current->setNext(newNode);
	}
}

List& List::operator=(const List& other) {
	if (this != &other) {
		List temp(other);
		swap(head_, temp.head_);
	}
	return *this;
}

ostream& operator<<(ostream& os, const List& list) {
	List::Node* current = list.head_;
	while (current != nullptr) {
		os << current->getValue() << " ";
		current = current->getNext();
	}
	return os;
}

istream& operator>>(istream& is, List& list) {
	int size, i = 0;
	cout << "Enter size: "; cin >> size;
	int value;
	while (i++ < size) {
		is >> value;
		list.head_ = new List::Node(value, list.head_);
	}
	return is;
}

int List::operator[](int index) const {
	Node* current = head_;
	for (int i = 0; i < index; ++i) {
		current = current->getNext();
		if (current == nullptr) {
			return -1;
		}
	}
	return current->getValue();
}

int List::size() const {
	int count = 0;
	Node* current = head_;
	while (current != nullptr) {
		++count;
		current = current->getNext();
	}
	return count;
}

List operator*(const List& a, const List& b)
{
	List result;
	List::Iterator itA = a.begin();
	List::Iterator itB = b.begin();

	while (itA != a.end() && itB != b.end())
	{
		result.push_back(*itA * *itB);
		++itA;
		++itB;
	}

	return result;
}

List::Iterator List::Iterator::operator+(int n) const {
	Iterator result(node_);
	for (int i = 0; i < n; ++i) {
		++result;
	}
	return result;
}

List::Iterator& List::Iterator::operator++() {
	if (node_ != nullptr) {
		node_ = node_->getNext();
	}
	return *this;
}