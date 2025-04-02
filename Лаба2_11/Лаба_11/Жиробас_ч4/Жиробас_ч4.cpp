#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <clocale>
#include <cstdio>
#include <cstring>
using namespace std;
int kk, b;
char s, ele;

struct Node
{
	char data;
	Node* next_ptr;
};

struct Queue
{
	Node* head = nullptr;
	Node* tail = nullptr;
	int size = 0;

	void initq(Queue &q, char v)  //  Инициализация queue
	{
		Node* node = new Node;
		node->data = v;
		node->next_ptr = nullptr;
		q.head = node;
		q.tail = node;
		q.size = 1;
		return;
	}

	void push(Queue &q, const char &data)  //Добавление в queue
	{
		Node* new_node = new Node{data,nullptr};
		q.tail->next_ptr = new_node;
		q.tail = new_node;
		q.size++;
		return;
	}

	void create(Queue& q, int n) //Создание queue
	{
		char v;
		cout << "Введите символ:";
		cin >> v;
		
		initq(q,v);
		for (int i = 2; i <= n; i++)
		{
			cout << "Введите символ:";
			cin >> v;
			push(q,v);
		}
		return;
	}

	void pop(Queue &q) //Удаление из queue (для remove)
	{
		if (q.head != nullptr)
		{
			Node* del_el = q.head;
			q.head = q.head->next_ptr;
			delete del_el;
			q.size--;
		}
		return;
	}

	void remove(Queue& q, const char k)
	{
		int size = q.size;
		for (int i = 1; i <= size; i++){
			if (q.head->data == k){
				pop(q);
			}else{
				push(q, q.head->data);
				pop(q);
			}
		}
		return;
	}

	void show(Queue &q) //Вывод queue в консоль
	{
		cout << endl << "Вывод из queue:";
		Node* temp = q.head;
		if (q.size <= 0) { cout << "queue пуст"; return; }
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next_ptr;
		}
		return;
	}

	void addf(Queue &q) //Запись queue в файл
	{
		FILE* f1;
		Node* current = q.head;
		f1 = fopen("C:\\Копачи\\Лаба_11\\gg\\s.txt", "w");
		if (f1 == nullptr)
		{
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

	void outputf() //Вывод queue из файла
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

	void clear(Queue &q) //тотальная аннигиляция queue
	{

		while (q.head != nullptr)
		{
			pop(q);
		}
		return;
	}

	void revival(Queue &q) //Возрождение queue
	{
		FILE* f1;
		f1 = fopen("C:\\Копачи\\Лаба_11\\gg\\s.txt", "r");
		if (f1 == nullptr)
		{
			cout << "Ошибка открытия файла!" << endl;
			return;
		}

		char ch;
		bool isFirst = true;
		while ((ch = fgetc(f1)) != EOF){
			if (isFirst){
				initq(q, ch);
				isFirst = false;
			}else{
				push(q, ch);
			}
		}
		fclose(f1);
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	Queue myQ;
	cout << "Создать queue из N элементов:";
	cin >> b;
	myQ.create(myQ, b);

	cout << "Добавить К элементов:";
	cin >> kk;
	while (kk != 0)
	{
		cout << "Введите символ:";
		cin >> s;
		myQ.push(myQ, s);
		kk--;
	}
	myQ.show(myQ);

	cout << endl << "Введите ключ  удаляемого элeмента:";
	cin >> ele;
	
	myQ.remove(myQ, ele);

	myQ.show(myQ);

	myQ.addf(myQ);
	myQ.outputf();

	myQ.clear(myQ);
	myQ.show(myQ);

	myQ.revival(myQ);
	myQ.show(myQ);

	myQ.clear(myQ);
	return 0;
}
