#ifndef userInterface_h
#define userInterface_h
#include "container.h"
class UserInterface
{
private:
	Container container;
public:
	//�����������, ����������
	UserInterface(){cin >> container;}
	~UserInterface(){cout << container;}
	//������� ���������
	void printAbiturients();
	bool printCourses();
	void printCoursesOfAbiturient();
	void printAbiturientsOnCourse();
	//������� ����������
	void addAbiturient();
	void addStatement();
	void addCourse();
	//������� ������
	pair<multimap<string,list<Abiturient>::iterator>::iterator, multimap<string,list<Abiturient>::iterator>::iterator> findAbiturient();
	pair<multimap<double,list<Abiturient>::iterator>::iterator, multimap<double,list<Abiturient>::iterator>::iterator> findAbiturientByScore();
	//������� ��������
	void deleteAbiturient();
	void deleteStatement();
	//������
	list<Course>::iterator chooseCourse(list<Course>::iterator begin, list<Course>::iterator end);
	list<Abiturient>::iterator chooseAbiturient(list<Abiturient>::iterator begin, list<Abiturient>::iterator end);
	list<Abiturient>::iterator chooseAbiturient(multimap<string,list<Abiturient>::iterator>::iterator begin, multimap<string,list<Abiturient>::iterator>::iterator end);
};
#endif