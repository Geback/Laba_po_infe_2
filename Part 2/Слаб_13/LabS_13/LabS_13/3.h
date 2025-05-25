#include"Header.h"


static int shet = 0;		

void print(map<int, Pair>& mp)		
{
	cout << endl << "Полученный map:" << endl;
	for (auto& i : mp)
		cout << i.first << ". " << i.second << endl;
}

void plus_mid(map<int, Pair>& mp)	
{
	Pair midl(0, 0);				
	for (auto& i : mp)				
		midl = midl + i.second;		
	mp.emplace(++shet, midl / mp.size());	
}

void searchAndDel(map<int, Pair>& mp)		
{											
	int y;
	cout << "Введите ключ для удаления (int): "; cin >> y;
	mp.erase(y);
}

void plusMinMax(map<int, Pair>& mp)			
{
	Pair min = min_element(mp.begin(), mp.end())->second;		
	Pair max = max_element(mp.begin(), mp.end())->second;		
	cout << "min: " << min << endl << "max: " << max << endl;	
	for (auto& i : mp)
		i.second = i.second + max + min;			
}

void myfind(map<int, Pair>& mp)			
{
	int a;
	cout << "Введите ключ для поиска: "; cin >> a;
	auto it = mp.find(a);
	if (it != mp.end())
		cout << "Ключ: " << a << "   Значение:"  << it->second << endl;
	else cout << "Элемента с таким ключом нет в словаре." << endl;
}

void printsortup(map<int, Pair>& mp)		
{											
	int a = 0;
	map<Pair, int> temp;
	for (auto i = mp.begin(); i != mp.end(); ++i)
		temp.emplace(i->second, i->first);
	for (auto& i : temp)
		cout << ++a << ".\t" << i.first << "  \tКлюч: " << i.second << endl;
}

void printsortdown(map<int, Pair>& mp){		
	int a = 0;
	map<Pair, int> temp;
	for (auto i = mp.begin(); i != mp.end(); ++i)
		temp.emplace(i->second, i->first);
	for (auto i = temp.crbegin(); i != temp.crend(); i++)
		cout << ++a << ".\t" << i->first << "  \tКлюч: " << i->second << endl;



}

void number3()		
{					
	Pair p;			
	map<int, Pair> mp;
	int n;
	cout << "Введите какое количество записей сгенерировать: "; cin >> n;
	for (int i = 0; i < n; i++)
		mp.emplace(++shet, p.randomGener());
	cout << "Тип вывода:\nКлюч. Значение" << endl;
	print(mp);
	cout << endl << "Найдем среднее арифмитическое значение и добавим его в контейнер:" << endl;
	plus_mid(mp);
	print(mp);
	cout << endl << "Зададим диапазон и удалим данные из контейнера в данном диапазоне:" << endl;
	searchAndDel(mp);
	print(mp);
	cout << endl << "К каждому элементу контейнера добавим max и min элемент контейнера:" << endl;
	plusMinMax(mp);
	print(mp);
	cout << endl << "Найдем в данном контейнере элемент по его ключу:" << endl;
	myfind(mp);
	cout << endl << "Отсортируем контейнер по возрастанию" << endl;
	printsortup(mp);
	cout << endl << "Отсортируем контейнер по убыванию" << endl;
	printsortdown(mp);
}