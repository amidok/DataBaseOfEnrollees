#ifndef userInterface_h
#define userInterface_h
#include "container.h"
class UserInterface
{
private:
	Container container;
public:
	//конструктор, деструктор
	UserInterface(){cin >> container;}
	~UserInterface(){cout << container;}
	//функции просмотра
	void printAbiturients();
	bool printCourses();
	void printCoursesOfAbiturient();
	void printAbiturientsOnCourse();
	//функции добавления
	void addAbiturient();
	void addStatement();
	void addCourse();
	//функции поиска
	pair<multimap<string,list<Abiturient>::iterator>::iterator, multimap<string,list<Abiturient>::iterator>::iterator> findAbiturient();
	pair<multimap<double,list<Abiturient>::iterator>::iterator, multimap<double,list<Abiturient>::iterator>::iterator> findAbiturientByScore();
	//функции удаления
	void deleteAbiturient();
	void deleteStatement();
	//другие
	list<Course>::iterator chooseCourse(list<Course>::iterator begin, list<Course>::iterator end);
	list<Abiturient>::iterator chooseAbiturient(list<Abiturient>::iterator begin, list<Abiturient>::iterator end);
	list<Abiturient>::iterator chooseAbiturient(multimap<string,list<Abiturient>::iterator>::iterator begin, multimap<string,list<Abiturient>::iterator>::iterator end);
};
#endif