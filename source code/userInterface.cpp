#include "userInterface.h"
#include <Windows.h>

void UserInterface::addAbiturient()
{
	string surname, name, patronymic;
	double sum, certificate, exam;
	cout << "������� �������:\n";
	cin >> surname;
	cout << "������� ���:\n";
	cin >> name;
	cout << "������� ��������:\n";
	cin >> patronymic;
	cout << "������� ����� ����:\n";
	do
	{
		cin >> sum;
		if(sum <= 0)
			cout << "�������� ����! ����������, ��������� ����!\n";
	}while(sum <= 0);
	cout << "������� ���� ���������:\n";
	do
	{
		cin >> certificate;
		if(certificate <= 0)
			cout << "�������� ����! ����������, ��������� ����!\n";
	}while(certificate <= 0);
	cout << "������� ���� �� ��������:\n";
	do
	{
		cin >> exam;
		if(exam <= 0)
			cout << "�������� ����! ����������, ��������� ����!\n";
		else if(exam + certificate > sum && exam != 12345)
			cout << "�������� ����! ����� ���� ������, ��� ����� ����� ��������� � ����� �� �������!\n��������� ���� ��� ������� \"12345\" ��� ������ ����������!\n";
	}while(exam <= 0 || ((exam+certificate > sum) && exam!=12345));
	if(exam == 12345)
		return;
	list<Abiturient>::iterator ab = container.addAbiturient(surname, name, patronymic, sum, certificate, exam);
	cout << "���������!\n������ ����� ������ ��������� �� �����������?\n";
	cout << "1.��\n2.���\n";
	int selection;
	cin >> selection;
	if(selection<=0 || selection>2)
	{
		cerr << "�������� ����!\n";
		return;
	}
	else if(selection==2)
		return;
	cout << "�� ����� ����������� ������ ������?\n";
	this->printCourses();
	list<Course>::iterator iter = this->chooseCourse(container.coursesBegin(),container.coursesEnd());
	container.addStatement(ab,iter);
	cout << "�������� ������ �������!\n";
}
pair<multimap<string,list<Abiturient>::iterator>::iterator, multimap<string,list<Abiturient>::iterator>::iterator> UserInterface::findAbiturient()
{
	pair<multimap<string,list<Abiturient>::iterator>::iterator, multimap<string,list<Abiturient>::iterator>::iterator> it;
	if(container.abiturientsEmpty())
		cerr << "������ ������������ ����!\n";
	else
	{
		cout << "������� ������� �����������:\n";
		string surname;
		cin >> surname;
		it = container.findAbiturient(surname);
		if(it.first == it.second)
		{
			cout << "������ �� �������!\n";
			return it;
		}
		int counter = 1;
		cout << "#  ���" << setw(37) << "����� ����" << setw(12) << "��������" << setw(5) << "���\n";
		for(multimap<string,list<Abiturient>::iterator>::iterator i = it.first; i != it.second; i++)
		{
			cout << counter << ") ";
			i->second->Print();
			counter++;
		}
	}
	return it;
}
pair<multimap<double,list<Abiturient>::iterator>::iterator, multimap<double,list<Abiturient>::iterator>::iterator> UserInterface::findAbiturientByScore()
{
	if(container.abiturientsEmpty())
		cout << "������ ������������ ����!\n";
	else
	{
		cout << "������� �������� ������:\n��: ";
		double from, to;
		cin >> from;
		cout << "��: ";
		cin >> to;
		pair<multimap<double,list<Abiturient>::iterator>::iterator, multimap<double,list<Abiturient>::iterator>::iterator> it;
		it = container.findAbiturientByScore(from,to);
		if(it.first == it.second)
		{
			cout << "������ �� �������!\n";
			return it;
		}
		int counter = 1;
		cout << "#  ���" << setw(37) << "����� ����" << setw(12) << "��������" << setw(5) << "���\n";
		for(multimap<double,list<Abiturient>::iterator>::iterator i = it.first; i != it.second; i++)
		{
			cout << counter << ") ";
			i->second->Print();
			counter++;
		}
		return it;
	}
}

void UserInterface::addStatement()
{
	pair<multimap<string,list<Abiturient>::iterator>::iterator, multimap<string,list<Abiturient>::iterator>::iterator> it;
	it = this->findAbiturient();
	if(it.first == it.second)
		return;
	int counter, choice;
	bool flag = false;
	multimap<string,list<Abiturient>::iterator>::iterator ab;
	cout << "�������� �����������:\n";
	while(!flag)
	{
		counter = 1;
		cin >> choice;
		for(ab = it.first; ab != it.second; ab++)
		{
			if(counter == choice)
			{
				flag = true;
				break;
			}
			counter++;
		}
		if(!flag)
			cout << "������������ ����! ����������, ��������� ����!\n";
	}
	cout << "�������� �����������:\n";
	this->printCourses();
	list<Course>::iterator c = this->chooseCourse(container.coursesBegin(),container.coursesEnd());
	container.addStatement(ab->second,c);
	cout << "���������!\n";
}
void UserInterface::addCourse()
{
	cout << "�� �������, ��� ������ �������� ����� �����������?\n1.��\n2.���\n";
	int choice;
	cin >> choice;
	if(choice <=0 || choice > 2)
		cout << "������ �����!\n";
	else if(choice == 2)
		return;
	else
	{
		cout << "������� �������� ��� ������ �����������:\n";
		cin.ignore();
		string name;
		std::getline(cin, name);
		container.addCourse(name);
		cout << "���������!\n";
	}
}

void UserInterface::printAbiturients()
{
	if(container.abiturientsEmpty())
	{
		cerr << "������ ������������ ����!\n";
		return;
	}
	cout << "#  ���" << setw(37) << "����� ����" << setw(12) << "��������" << setw(5) << "���\n";
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)(15<<4 | 4) | FOREGROUND_INTENSITY);
	container.printAbiturients();
}
bool UserInterface::printCourses()
{
	if(container.coursesEmpty())
	{
		cerr << "������ ����������� ����!\n";
		return false;
	}
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)(15<<4 | 4) | FOREGROUND_INTENSITY);
	container.printCourses();
	return true;
}
void UserInterface::printCoursesOfAbiturient()
{
	pair<multimap<string,list<Abiturient>::iterator>::iterator, multimap<string,list<Abiturient>::iterator>::iterator> it;
	it = this->findAbiturient();
	if(it.first == it.second)
		return;
	cout << "�������� �����������:\n";
	list<Abiturient>::iterator ab = this->chooseAbiturient(it.first,it.second);
	cout << "����������:\n";
	cout << "  ���" << setw(37) << "����� ����" << setw(12) << "��������" << setw(5) << "  ���\n  ";
	ab->Print();
	cout << endl;
	cout << "��������� ����� ����������� ���� ������ ��...\n";
	if(container.printCoursesOfAbiturient(ab))
		return;
	else
		cout << "��������� ����� ����������� �� �������!\n";
}
void UserInterface::printAbiturientsOnCourse()
{
	cout << "�������� �����������:\n";
	if(!this->printCourses())
		return;
	list<Course>::iterator c = this->chooseCourse(container.coursesBegin(),container.coursesEnd());
	cout << "#  ���" << setw(37) << "����� ����" << setw(12) << "��������" << setw(5) << "���\n";
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)(15<<4 | 4) | FOREGROUND_INTENSITY);
	if(container.printAbiturientsOnCourse(c))
		return;
	else
		cout << "������ �� �������!\n";
}


void UserInterface::deleteAbiturient()
{
	pair<multimap<string,list<Abiturient>::iterator>::iterator, multimap<string,list<Abiturient>::iterator>::iterator> it;
	it = this->findAbiturient();
	if(it.first == it.second)
		return;
	cout << "��������, ���� �������:\n";
	list<Abiturient>::iterator ab = this->chooseAbiturient(it.first,it.second);
	container.deleteAbiturient(ab);
	cout << "�������!\n";
}
void UserInterface::deleteStatement()
{
	pair<multimap<string,list<Abiturient>::iterator>::iterator, multimap<string,list<Abiturient>::iterator>::iterator> it;
	it = this->findAbiturient();
	if(it.first == it.second)
		return;
	cout << "�������� �����������:\n";
	list<Abiturient>::iterator ab = this->chooseAbiturient(it.first,it.second);
	cout << "����������:\n";
	cout << "  ���" << setw(37) << "����� ����" << setw(12) << "��������" << setw(5) << "  ���\n  ";
	ab->Print();
	cout << endl;
	cout << "��������� ����� ����������� ���� ������ ��...\n";
	if(!container.printCoursesOfAbiturient(ab))
	{
		cout << "��������� ����� ����������� �� �������!\n";
		return;
	}
	cout << "�������� �����������:\n";
	this->printCourses();
	list<Course>::iterator c = this->chooseCourse(container.coursesBegin(),container.coursesEnd());
	if(container.deleteStatement(ab,c))
	{
		cout << "�������!\n";
		return;
	}
	else
		cout << "�������� ����!\n";
}


list<Course>::iterator UserInterface::chooseCourse(list<Course>::iterator begin, list<Course>::iterator end)
{
	int choice, counter;
	bool flag = false;
	cin >> choice;
	list<Course>::iterator it;
	do
	{
		counter = 1;
		for(it = begin; it != end; it++)
		{
			if(counter == choice)
			{
				flag = true;
				break;
			}
			counter++;
		}
		if(!flag)
			cout << "������ �����! ����������, ��������� ����!\n";
	}while(!flag);
	return it;
}

list<Abiturient>::iterator UserInterface::chooseAbiturient(list<Abiturient>::iterator begin, list<Abiturient>::iterator end)
{

	int counter, choice;
	bool flag = false;
	list<Abiturient>::iterator it;
	do
	{
		counter = 1;
		cin >> choice;
		for(it = begin; it != end; it++)
		{
			if(counter == choice)
			{
				flag = true;
				break;
			}
			counter++;
		}
		if(!flag)
			cout << "������������ ����! ����������, ��������� ����!\n";
	}while(!flag);
	return it;
}

list<Abiturient>::iterator UserInterface::chooseAbiturient(multimap<string,list<Abiturient>::iterator>::iterator begin, multimap<string,list<Abiturient>::iterator>::iterator end)
{
	int counter, choice;
	bool flag = false;
	multimap<string,list<Abiturient>::iterator>::iterator it;
	do
	{
		counter = 1;
		cin >> choice;
		for(it = begin; it != end; it++)
		{
			if(counter == choice)
			{
				flag = true;
				break;
			}
			counter++;
		}
		if(!flag)
			cout << "������������ ����! ����������, ��������� ����!\n";
	}while(!flag);
	return it->second;
}