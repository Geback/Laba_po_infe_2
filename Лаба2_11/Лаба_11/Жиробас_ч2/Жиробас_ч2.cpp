#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <clocale>
#include <cstdio>
#include <cstring>
using namespace std;
int r, ele, kk;
char s;

struct Node
{
	char data;
	Node* prev = nullptr, * next = nullptr;

	void addData(char Data)
	{
		data = Data;
	}
};

struct List
{
	Node* head = nullptr, * tail = nullptr;

	void push_back(char data)  //Добавление в конец
	{
		Node* node = new Node;
		node->addData(data);
		node -> prev = tail;
		if (head == nullptr) head = node;
		if (tail != nullptr) tail->next = node;
		tail = node;
		r++;
	}

	void pop() //Удаление из начала списка (для erase)
	{
		if (head == nullptr) return;
		if (head == tail){
			delete tail;
			head = tail = nullptr;
			r--;
			return;
		}
		Node* node = head;
		head = node->next;
		head->prev = nullptr;

		delete node;
		r--;
	}

	Node* getAt(int k) //Возвращение адресса элемента по его индексу (для erase)
	{
		if (k < 0) return 0;
		Node* node = head;
		int n = 0;
		while (node && n != k && node->next)
		{
			node = node->next;
			n++;
		}
		if (n == k) { return node; }
		else { return nullptr; }

	}

	void erase(int k) //Удаление по индексу
	{
		if (k < 0) return;
		if (k == 0) { pop(); return; }
		Node* left = getAt(k - 1);

		Node* node = left->next;
		if (node == nullptr) return;
		Node* right = node->next;
		left->next = right;
		right->prev = left;

		if (node == tail) tail = left;
		delete node;
		--r;
	}

	void show() //Вывод списка в консоль
	{
		cout << endl << "Вывод из списка:";
		Node* current = head;
		if (r <= 0) { cout << "Список пуст"; return; }
		while (current != nullptr)
		{
			cout << current->data << " ";
			current = current->next;
		}
	}

	void addf() //Запись списка в файл
	{
		FILE* f1;
		Node* current = head;
		f1 = fopen("C:\\Копачи\\Лаба_11\\gg\\s.txt", "w");
		if (f1 == nullptr)
		{
			cout << "Ошибка открытия файла!" << endl;
			return;
		}

		current = head;
		while (current != nullptr)
		{
			fputc(current->data, f1);
			current = current->next;
		}
		fclose(f1);
	}

	void outputf() //Вывод списка из файла
	{
		cout << endl << "Вывод из файла:";
		FILE* f1;
		char s[255];
		f1 = fopen("C:\\Копачи\\Лаба_11\\gg\\s.txt", "r");
		if (f1 == nullptr)
		{
			cout << "Ошибка открытия файла!" << endl;
			return;
		}

		while (fgets(s, 255, f1))
			cout << s;
		fclose(f1);
	}

	void clear() //тотальная аннигиляция
	{
		Node* current = head;
		while (current != nullptr)
		{
			Node* next = current->next;
			delete current;
			current = next;
		}
		head = nullptr;
		tail = nullptr;
		r = 0;
	}

	void revival() //Возрождение из ничего
	{
		FILE* f1;
		f1 = fopen("C:\\Копачи\\Лаба_11\\gg\\s.txt", "r");
		if (f1 == nullptr){
			cout << "Ошибка открытия файла!" << endl;
			return;
		}

		char ch;
		while ((ch = fgetc(f1)) != EOF){
			push_back(ch);
		}
		fclose(f1);
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	List list;
	r = 0;

	list.push_back('R');
	//list.push_back('T');
	list.push_back('X');

	cout << "Добавить К элементов:";
	cin >> kk;
	while (kk != 0)
	{
		cout << "Введите символ:";
		cin >> s;
		list.push_back(s);
		kk--;
	}
	list.show();

	cout << endl << "Введите ключ элэмента:";
	cin >> ele;
	list.erase(ele - 1);

	list.show();

	list.addf();
	list.outputf();

	list.clear();
	list.show();

	list.revival();
	list.show();

	list.clear();
	return 0;
}
