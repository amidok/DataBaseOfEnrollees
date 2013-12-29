#ifndef container_h
#define container_h
#include <iostream>
#include <iomanip>
#include <map>
#include <list>
#include <fstream>
#include <iterator>
#include <functional>
#include <algorithm>
#include "course.h"
#include "abiturient.h"
using namespace std;

class UserInterface;
class Container
{
private:
	list<Abiturient> abiturients;
	list<Course> courses;
	multimap<list<Abiturient>::iterator, list<Course>::iterator> relation;
	multimap<string, list<Abiturient>::iterator> find; //��� ������ ������������ �� �������
	multimap<double, list<Abiturient>::iterator> find_score;//��� ������ ������������ �� ��������� ������
public:
	Container(){}
	//������� ���������
	void printAbiturients();
	void printCourses();
	bool printAbiturientsOnCourse(list<Course>::iterator it);
	bool printCoursesOfAbiturient(list<Abiturient>::iterator it);
	//������� ����������
	list<Abiturient>::iterator addAbiturient(string surname, string name, string patronymic, double sum, double certificate, double exam);
	void addCourse(string name);
	void addStatement(list<Abiturient>::iterator abit, list<Course>::iterator c);
	//������� ������
	pair<multimap<string,list<Abiturient>::iterator>::iterator, multimap<string,list<Abiturient>::iterator>::iterator> findAbiturient(string surname);
	pair<multimap<double,list<Abiturient>::iterator>::iterator, multimap<double,list<Abiturient>::iterator>::iterator> findAbiturientByScore(double from, double to);
	//������� ��������
	void deleteAbiturient(list<Abiturient>::iterator it);
	bool deleteStatement(list<Abiturient>::iterator ab, list<Course>::iterator c);
	//������� �����-������
	friend istream& operator>> (istream &s, Container &m);
	friend ostream& operator<< (ostream &out, Container &m);
	//������� ���������
	friend bool operator< (list<Abiturient>::iterator i1, list<Abiturient>::iterator i2);
	friend bool operator< (list<Course>::iterator i1, list<Course>::iterator i2);
	friend bool operator== (list<Abiturient>::iterator i1, list<Abiturient>::iterator i2);
	friend bool operator== (list <Course>::iterator i1, list <Course>::iterator i2);
	//������
	bool abiturientsEmpty(){return abiturients.empty();}
	bool coursesEmpty(){return courses.empty();}
	list<Abiturient>::iterator abiturientsBegin(){return abiturients.begin();}
	list<Abiturient>::iterator abiturientsEnd(){return abiturients.end();}
	list<Course>::iterator coursesBegin(){return courses.begin();}
	list<Course>::iterator coursesEnd(){return courses.end();}
};
#endif