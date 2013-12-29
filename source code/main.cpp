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
	 readme << "����� ������� ����������� ����������, ���������, ����� ����� ������� ��� ��� \"Consolas\" ��� \"Lucida console\".\n"
            << "�������� ��� ����� ����� � �������� �������, ��� ����� ����� �������� ������ ������� ���� �� ���� �������"
			<< "(������ �������� ������ ������� ���� ���, ��� �������� �������� ���������) � � ����������� ���� ������� �����"
			<< " \"��������\".\n����� ����� ��������� ����, � �������, �������� ����� ��� \"Consolas\" (���� ����� �������), ��� \"Lucida console\".\n"
			<< "������� \"��\", �, ���� �� ������ ��������� ��� �������� ������ ��� ��� ����� ������� ���������, "
			<< "� ����, ������� �������� ����� ������� \"��\", �������� \"��������� �������� ��� ������ ���� � ��� �� ������\".\n"
			<< "���, ��������� ������ � �������������. ��� ������ �������� � ������ \"enrollees.txt\", \"courses.txt\", \"relations.txt\".\n"
			<< "����� ��������� ������������ ���� ������, ������ ������� �� ���, ����� ��� ���� � ����� ����� � ����������."
			<< "� ����� ����� ������ ����� � ����! :3\n�Database of enrollees\n";
	 readme.close();
 }
void help()
{
	cout << "��� ������ ������ ���� ����������� ����� 0-9.\n��� ������ �������� � ������ \"enrollees.txt\", \"courses.txt\", \"relations.txt\".\n"
			<< "����� ��������� ������������ ���� ������, ������ ������� �� ���, ����� ��� ���� � ����� ����� � ����������.\n"
			<< "� ����� ����� ������ ����� � ����! :3\n";
	wcout << (wchar_t)0xA9 << "Database of enrollees" <<  endl;
}
void settings()
{
	int selection=-1;
	while(selection != 0)
	{
		cout << "���� ������ �������� ��� � ���� ������, �������� �������������� �������:\n ��� - ���� ������\n"
		 << "1.����� - �����(�����������)\n2.������ - �����\n3.������ - ������-�����\n4.������ - �������\n5.������� - ������\n"
		 << "6.����� - �������\n0.��������� � ���������� ����\n";
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
		cout << "����:\n1.��������\n2.����������\n3.�����\n4.��������\n5.������/���������\n0.�����\n";
		cin >> selection;
		switch(selection)
		{
		case 0:
			system("pause");
			break;
		case 1:
			cout << "1.�������� ���� ������������\n2.�������� ���� �����������\n3.�������� ��������� �����������\n"
				<< "4.�������� ������������ �� ������������\n0.��������� � ���������� ����\n";
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
			cout << "1.�������� ������ ����������� � ����\n2.�������� ��������� ����������� �� �����������\n3.�������� ����� �����������\n0.��������� � ���������� ����\n";
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
			cout << "����� �����������:\n1.�� �������\n2.�� ��������� ������ �����\n0.��������� � ���������� ����\n";
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
			cout << "1.�������� �����������\n2.�������� ��������� ����������� �� �����������\n0.��������� � ���������� ����\n";
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
			cout << "1.������\n2.���������\n";
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
