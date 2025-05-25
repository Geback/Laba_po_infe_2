#include"Header.h"

void plus_mid(list<Pair>& lst)		
{
	Pair midl(0, 0);
	for_each(lst.begin(), lst.end(), [&midl](Pair this_el)	
		{
			midl = midl + this_el;
		});			
	lst.push_back(midl / lst.size());		
}

void searchAndDel(list<Pair>& lst)			
{
	Pair y;
	cout << "Введите данные для удаления: "; cin >> y;
	int min, max;
	cout << "Введите диапазон для поиска:\n" << "min: "; cin >> min;
	cout << "max: "; cin >> max;					
	auto left = lst.begin(); auto right = lst.begin();
	advance(left, min);			
	advance(right, max);
	lst.erase(remove_if(left, right, [&y](Pair& x)	
		{
			return x == y;
		}));		
}

void plusMinMax(list<Pair>& lst){		
	Pair min = *min_element(lst.begin(), lst.end());		
	Pair max = *max_element(lst.begin(), lst.end());
	cout << "min: " << min << endl << "max: " << max << endl;
	for_each(lst.begin(), lst.end(),		
		[&min, &max](Pair& this_el) { this_el = this_el + max + min; });		
}

void number1()		
{
	Pair p;
	list<Pair> lst;
	int n;
	cout << "Введите кол-во сгенерированных записей: "; cin >> n;
	for (int i = 0; i < n; i++)
		lst.push_back(p.randomGener());
	cout << endl << "Полученный list:" << endl; n = 0;
	for (auto& i : lst)
		cout << ++n << ". " << i << endl;
	cout << endl << "Найдем среднее арифметическое значение и добавим его в контейнер:" << endl;
	plus_mid(lst);
	cout << endl << "Полученный list:" << endl; n = 0;
	for (auto& i : lst)
		cout << ++n << ". " << i << endl;
	cout << endl << "Зададим диапазон и удалим данные из контейнера в этом диапазоне:" << endl;
	searchAndDel(lst);
	cout << endl << "Полученный list:" << endl; n = 0;
	for (auto& i : lst)
		cout << ++n << ". " << i << endl;
	cout << endl << "К каждому эл контейнера добавить max и min эл контейнера:" << endl;
	plusMinMax(lst);
	cout << endl << "Полученный list:" << endl; n = 0;
	for (auto& i : lst)
		cout << ++n << ". " << i << endl;
	cout << endl << "Найдем в данном контейнере эл и его индекс:" << endl;
	cout << "Введите эл для поиска: "; cin >> p;
	auto it = find(lst.begin(), lst.end(), p);
	if (it != lst.end())
		cout << "Номер элемента: " << distance(lst.begin(), it) + 1 << "\tЭлемент: " << p;
	else
		cout << "Элемент не найден:" << endl;
	cout << endl << "Отсортируем контейнер по возрастанию" << endl;
	lst.sort();								
	cout << endl << "Полученный list:" << endl; n = 0;
	for (auto& i : lst)
		cout << ++n << ". " << i << endl;
	cout << endl << "Отсортируем контейнер по убыванию" << endl;
	lst.sort(greater<Pair>());				
	cout << endl << "Полученный list:" << endl; n = 0;
	for (auto& i : lst)
		cout << ++n << ". " << i << endl;
}