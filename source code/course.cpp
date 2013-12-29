#include "course.h"


ostream& operator<< (ostream& out, const Course& c)
{
	out << c.name;
	return out;
}
istream& operator>> (istream& s, Course& c)
{
	getline(s, c.name);
	return s;
}
bool Course::operator== (const Course &c) const
{
	if(name == c.name)
		return true;
	else 
		return false;
}
bool Course::operator< (const Course& c) const
{
	return name < c.name;
}
bool Course::operator> (const Course& c) const
{
	return name > c.name;
}