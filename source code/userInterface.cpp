#include "userInterface.h"
#include <Windows.h>

void UserInterface::addAbiturient()
{
	string surname, name, patronymic;
	double sum, certificate, exam;
	cout << "Введите фамилию:\n";
	cin >> surname;
	cout << "Введите имя:\n";
	cin >> name;
	cout << "Введите отчество:\n";
	cin >> patronymic;
	cout << "Введите общий балл:\n";
	do
	{
		cin >> sum;
		if(sum <= 0)
			cout << "Неверный ввод! Пожалуйста, повторите ввод!\n";
	}while(sum <= 0);
	cout << "Введите балл аттестата:\n";
	do
	{
		cin >> certificate;
		if(certificate <= 0)
			cout << "Неверный ввод! Пожалуйста, повторите ввод!\n";
	}while(certificate <= 0);
	cout << "Введите балл за экзамены:\n";
	do
	{
		cin >> exam;
		if(exam <= 0)
			cout << "Неверный ввод! Пожалуйста, повторите ввод!\n";
		else if(exam + certificate > sum && exam != 12345)
			cout << "Неверный ввод! Общий балл меньше, чем сумма балла аттестата и балла за экзамен!\nПовторите ввод или введите \"12345\" для отмены добавления!\n";
	}while(exam <= 0 || ((exam+certificate > sum) && exam!=12345));
	if(exam == 12345)
		return;
	list<Abiturient>::iterator ab = container.addAbiturient(surname, name, patronymic, sum, certificate, exam);
	cout << "Добавлено!\nХотите сразу подать заявление на направление?\n";
	cout << "1.Да\n2.Нет\n";
	int selection;
	cin >> selection;
	if(selection<=0 || selection>2)
	{
		cerr << "Неверный ввод!\n";
		return;
	}
	else if(selection==2)
		return;
	cout << "На какое направление хотите подать?\n";
	this->printCourses();
	list<Course>::iterator iter = this->chooseCourse(container.coursesBegin(),container.coursesEnd());
	container.addStatement(ab,iter);
	cout << "Операция прошла успешно!\n";
}
pair<multimap<string,list<Abiturient>::iterator>::iterator, multimap<string,list<Abiturient>::iterator>::iterator> UserInterface::findAbiturient()
{
	pair<multimap<string,list<Abiturient>::iterator>::iterator, multimap<string,list<Abiturient>::iterator>::iterator> it;
	if(container.abiturientsEmpty())
		cerr << "Список абитуриентов пуст!\n";
	else
	{
		cout << "Введите фамилию абитуриента:\n";
		string surname;
		cin >> surname;
		it = container.findAbiturient(surname);
		if(it.first == it.second)
		{
			cout << "Ничего не найдено!\n";
			return it;
		}
		int counter = 1;
		cout << "#  ФИО" << setw(37) << "Общий балл" << setw(12) << "Аттестат" << setw(5) << "ВНО\n";
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
		cout << "Список абитуриентов пуст!\n";
	else
	{
		cout << "Введите диапазон баллов:\nОт: ";
		double from, to;
		cin >> from;
		cout << "До: ";
		cin >> to;
		pair<multimap<double,list<Abiturient>::iterator>::iterator, multimap<double,list<Abiturient>::iterator>::iterator> it;
		it = container.findAbiturientByScore(from,to);
		if(it.first == it.second)
		{
			cout << "Ничего не найдено!\n";
			return it;
		}
		int counter = 1;
		cout << "#  ФИО" << setw(37) << "Общий балл" << setw(12) << "Аттестат" << setw(5) << "ВНО\n";
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
	cout << "Выберите абитуриента:\n";
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
			cout << "Неправильный ввод! Пожалуйста, повторите ввод!\n";
	}
	cout << "Выберите направление:\n";
	this->printCourses();
	list<Course>::iterator c = this->chooseCourse(container.coursesBegin(),container.coursesEnd());
	container.addStatement(ab->second,c);
	cout << "Добавлено!\n";
}
void UserInterface::addCourse()
{
	cout << "Вы уверены, что хотите добавить новое направление?\n1.Да\n2.Нет\n";
	int choice;
	cin >> choice;
	if(choice <=0 || choice > 2)
		cout << "Ошибка ввода!\n";
	else if(choice == 2)
		return;
	else
	{
		cout << "Введите название для нового направления:\n";
		cin.ignore();
		string name;
		std::getline(cin, name);
		container.addCourse(name);
		cout << "Добавлено!\n";
	}
}

void UserInterface::printAbiturients()
{
	if(container.abiturientsEmpty())
	{
		cerr << "Список абитуриентов пуст!\n";
		return;
	}
	cout << "#  ФИО" << setw(37) << "Общий балл" << setw(12) << "Аттестат" << setw(5) << "ВНО\n";
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)(15<<4 | 4) | FOREGROUND_INTENSITY);
	container.printAbiturients();
}
bool UserInterface::printCourses()
{
	if(container.coursesEmpty())
	{
		cerr << "Список направлений пуст!\n";
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
	cout << "Выберите абитуриента:\n";
	list<Abiturient>::iterator ab = this->chooseAbiturient(it.first,it.second);
	cout << "Абитуриент:\n";
	cout << "  ФИО" << setw(37) << "Общий балл" << setw(12) << "Аттестат" << setw(5) << "  ВНО\n  ";
	ab->Print();
	cout << endl;
	cout << "Заявления этого абитуриента были поданы на...\n";
	if(container.printCoursesOfAbiturient(ab))
		return;
	else
		cout << "Заявлений этого абитуриента не найдено!\n";
}
void UserInterface::printAbiturientsOnCourse()
{
	cout << "Выберите направление:\n";
	if(!this->printCourses())
		return;
	list<Course>::iterator c = this->chooseCourse(container.coursesBegin(),container.coursesEnd());
	cout << "#  ФИО" << setw(37) << "Общий балл" << setw(12) << "Аттестат" << setw(5) << "ВНО\n";
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)(15<<4 | 4) | FOREGROUND_INTENSITY);
	if(container.printAbiturientsOnCourse(c))
		return;
	else
		cout << "Ничего не найдено!\n";
}


void UserInterface::deleteAbiturient()
{
	pair<multimap<string,list<Abiturient>::iterator>::iterator, multimap<string,list<Abiturient>::iterator>::iterator> it;
	it = this->findAbiturient();
	if(it.first == it.second)
		return;
	cout << "Выберите, кого удалить:\n";
	list<Abiturient>::iterator ab = this->chooseAbiturient(it.first,it.second);
	container.deleteAbiturient(ab);
	cout << "Удалено!\n";
}
void UserInterface::deleteStatement()
{
	pair<multimap<string,list<Abiturient>::iterator>::iterator, multimap<string,list<Abiturient>::iterator>::iterator> it;
	it = this->findAbiturient();
	if(it.first == it.second)
		return;
	cout << "Выберите абитуриента:\n";
	list<Abiturient>::iterator ab = this->chooseAbiturient(it.first,it.second);
	cout << "Абитуриент:\n";
	cout << "  ФИО" << setw(37) << "Общий балл" << setw(12) << "Аттестат" << setw(5) << "  ВНО\n  ";
	ab->Print();
	cout << endl;
	cout << "Заявления этого абитуриента были поданы на...\n";
	if(!container.printCoursesOfAbiturient(ab))
	{
		cout << "Заявлений этого абитуриента не найдено!\n";
		return;
	}
	cout << "Выберите направление:\n";
	this->printCourses();
	list<Course>::iterator c = this->chooseCourse(container.coursesBegin(),container.coursesEnd());
	if(container.deleteStatement(ab,c))
	{
		cout << "Удалено!\n";
		return;
	}
	else
		cout << "Неверный ввод!\n";
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
			cout << "Ошибка ввода! Пожалуйста, повторите ввод!\n";
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
			cout << "Неправильный ввод! Пожалуйста, повторите ввод!\n";
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
			cout << "Неправильный ввод! Пожалуйста, повторите ввод!\n";
	}while(!flag);
	return it->second;
}