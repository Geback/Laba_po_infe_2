#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <clocale>
#include <cstdio>
#include <cstring>
using namespace std;
int ele, kk;
char s;

struct Node
{
	char data;
	Node* next_ptr;
};

struct Stack
{
	Node* head = nullptr;
	int size;

	void setNode(Node* &temp, int data, Node* next_ptr)  // Создание узла
	{
		temp = new Node;
		temp->next_ptr = next_ptr;
		temp->data = data;
		return;
	}

	void setStack(Stack &MyStack)  //  Инициализация полей
	{
		MyStack.head = nullptr;
		MyStack.size = 0;
		return;
	}

	void push(Stack &MyStack, const char &data)  //Добавление в стек
	{
		Node* new_node;
		setNode(new_node, data, MyStack.head);
		MyStack.head = new_node;
		MyStack.size++;
		return;
	}

	void pop(Stack &MyStack) //Удаление из стека
	{
		if (MyStack.head != nullptr)
		{
			Node* del_el = MyStack.head;
			MyStack.head = MyStack.head->next_ptr;
			delete del_el;
			MyStack.size--;
		}
		return;
	}

	void show(Stack &MyStack) //Вывод стека в консоль
	{
		cout << endl << "Вывод из стека:";
		Node* temp = MyStack.head;
		if (MyStack.size <= 0) { cout << "Стек пуст"; return; }
		while (temp != nullptr){
			cout<<temp->data<<" ";
			temp = temp->next_ptr;
		}
		return;
	}

	void addf(Stack &MyStack) //Запись стека в файл
	{
		FILE* f1;
		Node* current = MyStack.head;
		f1 = fopen("C:\\Залупинск\\2\\Part 1\\Лаба2_11\\Лаба_11\\gg\\s.txt", "w");
		if (f1 == nullptr){
			cout << "Ошибка открытия файла!" << endl;
			return;
		}

		while (current != nullptr)
		{
			fputc(current->data, f1);
			current = current->next_ptr;
		}
		fclose(f1);
	}

	void outputf() //Вывод стека из файла
	{
		cout << endl << "Вывод из файла:";
		FILE* f1;
		char s[255];
		f1 = fopen("C:\\Залупинск\\2\\Part 1\\Лаба2_11\\Лаба_11\\gg\\s.txt", "r");
		if (f1 == nullptr){
			cout << "Ошибка открытия файла!" << endl;
			return;
		}

		while (fgets(s, 255, f1))
			cout << s;
		fclose(f1);
	}

	void clear(Stack &MyStack) //тотальная аннигиляция
	{
		
		while (MyStack.head != nullptr)
			pop(MyStack);
		return;
	}

	void revival(Stack& MyStack) //Возрождение из ничего
	{
		FILE* f1;
		f1 = fopen("C:\\Залупинск\\2\\Part 1\\Лаба2_11\\Лаба_11\\gg\\s.txt", "r");
		if (f1 == nullptr)
		{
			cout << "Ошибка открытия файла!" << endl;
			return;
		}

        char ss[255];
		int l = 0;
		char ch;
		while ((ch = fgetc(f1)) != EOF && l < 255)
		{
			ss[l] = ch;
			l++;
		}
		ss[l] = '\0';

		for (int i = l - 1; i >= 0; i--)
		{
			push(MyStack, ss[i]);
		}
		fclose(f1);
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	Stack myStack;
	myStack.setStack(myStack);

	// Записываем данные в стек
	myStack.push(myStack, 'A');
	myStack.push(myStack, 'B');

	cout << "Добавить К элементов:";
	cin >> kk;
	while (kk != 0)
	{
		cout << "Введите символ:";
		cin >> s;
		myStack.push(myStack, s);
		kk--;
	}
	myStack.show(myStack);

	cout << endl << "Введите количество удаляемых элэментов:";
	cin >> ele;
	while ( ele!= 0)
	{
		myStack.pop(myStack);
		ele--;
	}

	myStack.show(myStack);

	myStack.addf(myStack);
	myStack.outputf();

	myStack.clear(myStack);
	myStack.show(myStack);

	myStack.revival(myStack);
	myStack.show(myStack);

	myStack.clear(myStack);
	return 0;
}
