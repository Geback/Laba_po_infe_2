
#include "Dialog.h"

Dialog::Dialog(void) :Vector()
{
	EndState = 0;
}

Dialog::~Dialog(void) {}

void Dialog::GetEvent(TEvent& event)
{
	string OpInt = "m+-szq";
	string s;
	cout << '>';
	if (!(cin >> s)) // Проверка на ошибку ввода
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		event.what = evNothing;
		return;}

	char code = s[0];
	if (OpInt.find(code) >= 0)
	{ 
		event.what = evMessage;
		switch (code)
		{
		case 'm': event.command = cmMake; break;
		case '+': event.command = cmAdd; break;
		case '-': event.command = cmDel; break; 
		case 's': event.command = cmShow; break;
		case 'z': event.command = cmGet; break;
		case 'q': event.command = cmQuit; break; 
		}
	}
	else event.what = evNothing;
}

void Dialog::Execute()
{
	TEvent event;
	do
	{
		EndState = 0;
		GetEvent(event);
		HandleEvent(event); 
	}
	while (Valid());
}

bool Dialog::Valid()
{
	return EndState == 0;
}

void Dialog::ClearEvent(TEvent& event)
{
	event.what = evNothing;
}

void Dialog::EndExec()
{
	EndState = 1;
}

void Dialog::HandleEvent(TEvent& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmMake:
		{
			cout << "Enter size: ";
			int new_size;
			while (!(cin >> new_size) || new_size <= 0)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid size! Enter positive number: ";
			}
			Clear();
			beg = new Object * [new_size];
			size = new_size;
			cur = 0;
			break;
		}
		case cmAdd:
			Add();
			break;
		case cmDel:
			Del();
			break;
		case cmShow:
			Show(); 
			break;
		case cmQuit:
			EndExec();
			break;
		case cmGet:
			Get_Name();

			break;
		};
	};
}