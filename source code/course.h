#ifndef course_h
#define course_h
#include <iostream>
#include <string>
using namespace std;


class Course
{
private:
	string name;
public:
	Course(){name = "";}
	Course(string n):name(n){}
	string getName()const{return name;}
	void Print(){cout << name;}
	void set(string name){this->name = name;}
	friend ostream& operator<< (ostream& out, const Course& c);
	friend istream& operator>> (istream& s, Course& c);
	bool operator< (const Course& c)const;
	bool operator> (const Course& c)const;
	bool operator== (const Course& c)const;
};
#endif