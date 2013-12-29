#include <iostream>
#include <fstream>
#include <windows.h>
#include "abiturient.h"
#include "course.h"
#include "container.h"
#include "userInterface.h"
using namespace std;


typedef BOOL (WINAPI *SETCONSOLEFONT)(HANDLE, DWORD); 
 SETCONSOLEFONT SetConsoleFont;
 void readme()
 {
	 ofstream readme;
	 readme.open("README.txt");
	 readme << "Перед началом пользования программой, убедитесь, чтобы шрифт консоли был или \"Consolas\" или \"Lucida console\".\n"
            << "Изменить его можно зайдя в свойства консоли, для этого нужно кликнуть правой кнопкой мыши по окну консоли"
			<< "(просто кликните правой кнопкой мыши там, где написано название программы) и в появившемся меню выбрать пункт"
			<< " \"свойства\".\nПосле этого откроется окно, в котором, выберите шрифт или \"Consolas\" (если такой имеется), или \"Lucida console\".\n"
			<< "Нажмите \"ОК\", и, если не хотите повторять эту операцию каждый раз при новом запуске программы, "
			<< "в окне, которое появится после нажатия \"ОК\", выберите \"сохранить свойства для других окон с тем же именем\".\n"
			<< "Все, программа готова к использованию. Все данные хранятся в файлах \"enrollees.txt\", \"courses.txt\", \"relations.txt\".\n"
			<< "Чтобы загрузить существующие базы данных, всегда следите за тем, чтобы они были в одной папке с программой."
			<< "И пусть удача всегда будет с вами! :3\n©Database of enrollees\n";
	 readme.close();
 }
void help()
{
	cout << "Для выбора пункта меню используйте цифры 0-9.\nВсе данные хранятся в файлах \"enrollees.txt\", \"courses.txt\", \"relations.txt\".\n"
			<< "Чтобы загрузить существующие базы данных, всегда следите за тем, чтобы они были в одной папке с программой.\n"
			<< "И пусть удача всегда будет с вами! :3\n";
	wcout << (wchar_t)0xA9 << "Database of enrollees" <<  endl;
}
void settings()
{
	int selection=-1;
	while(selection != 0)
	{
		cout << "Если хотите поменять фон и цвет текста, выберите соответстующий вариант:\n Фон - цвет текста\n"
		 << "1.Белый - синий(стандартный)\n2.Черный - белый\n3.Черный - светло-белый\n4.Черный - зеленый\n5.Зеленый - черный\n"
		 << "6.Белый - красный\n0.Вернуться в предыдущее меню\n";
		cin >> selection;
		switch(selection)
		{
		case 1:
			system("color F1");
			system("cls");
			break;
		case 2:
			system("color 07");
			system("cls");
			break;
		case 3:
			system("color 0F");
			system("cls");
			break;
		case 4:
			system("color 02");
			system("cls");
			break;
		case 5:
			system("color 20");
			system("cls");
			break;
		case 6:
			system("color F4");
			system("cls");
			break;
		
		}
	}

}
void dialog()
{
	int selection = -1, sel;
	UserInterface menu;
	while(selection!=0)
	{
		cout << "Меню:\n1.Просмотр\n2.Добавление\n3.Поиск\n4.Удаление\n5.Помощь/настройки\n0.Выход\n";
		cin >> selection;
		switch(selection)
		{
		case 0:
			system("pause");
			break;
		case 1:
			cout << "1.Просмотр всех абитуриентов\n2.Просмотр всех направлений\n3.Просмотр заявлений абитуриента\n"
				<< "4.Просмотр абитуриентов на направлениях\n0.Вернуться в предыдущее меню\n";
			cin >> sel;
			switch(sel)
			{
			case 1:
				menu.printAbiturients();
				system("pause");
				system("cls");
				break;
			case 2:
				menu.printCourses();
				system("pause");
				system("cls");
				break;
			case 3:
				menu.printCoursesOfAbiturient();
				system("pause");
				system("cls");
				break;
			case 4:
				menu.printAbiturientsOnCourse();
				system("pause");
				system("cls");
				break;
			default:
				system("cls");
				break;
			}
			break;
		case 2:
			cout << "1.Добавить нового абитуриента в базу\n2.Добавить заявление абитуриента на направление\n3.Добавить новое направление\n0.Вернуться в предыдущее меню\n";
			cin >> sel;
			switch(sel)
			{
			case 1:
				menu.addAbiturient();
				system("pause");
				system("cls");
				break;
			case 2:
				menu.addStatement();
				system("pause");
				system("cls");
				break;
			case 3:
				menu.addCourse();
				system("pause");
				system("cls");
				break;
			default:
				system("cls");
				break;
			}
			break;
		case 3:
			cout << "Поиск абитуриента:\n1.По фамилии\n2.По диапазону общего балла\n0.Вернуться в предыдущее меню\n";
			cin >> sel;
			switch(sel)
			{
			case 1:
				menu.findAbiturient();
				system("pause");
				system("cls");
				break;
			case 2:
				menu.findAbiturientByScore();
				system("pause");
				system("cls");
				break;
			default:
				system("cls");
				break;
			}
			break;
		case 4:
			cout << "1.Удаление абитуриента\n2.Удаление заявления абитуриента на направление\n0.Вернуться в предыдущее меню\n";
			cin >> sel;
			switch(sel)
			{
			case 1:
				menu.deleteAbiturient();
				system("pause");
				system("cls");
				break;
			case 2:
				menu.deleteStatement();
				system("pause");
				system("cls");
				break;
			default:
				system("cls");
				break;
			}
			break;
		case 5:
			cout << "1.Помощь\n2.Настройки\n";
			cin >> sel;
			switch(sel)
			{
			case 1:
				help();
				system("pause");
				system("cls");
				break;
			case 2:
				settings();
				system("pause");
				system("cls");
				break;
			}
			break;
		default:
			system("cls");
			break;
		}
	}
}
int main()
{
	HMODULE hmod = GetModuleHandleA("KERNEL32.DLL"); 
	SetConsoleFont =(SETCONSOLEFONT) GetProcAddress(hmod, "SetConsoleFont"); 
	if (!SetConsoleFont) {cout<<"error\n" ; exit(1);} 
	SetConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE),10); 


	cout << "Please,read README.txt and change console font to \"lucida console\" or \"consolas\"\n";
	system("color F1");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	readme();
	dialog();
	return 0;
}
