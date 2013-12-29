#include "container.h"
#include <Windows.h>

list<Abiturient>::iterator Container::addAbiturient(string surname, string name, string patronymic, double sum, double certificate, double exam)
{
	Abiturient ab;
	ab.set(surname, name, patronymic, sum, certificate, exam);
	list<Abiturient>::iterator it;
	bool flag = false;
	for(list<Abiturient>::iterator abit = abiturients.begin(); abit != abiturients.end(); abit++)
	{
		if(ab.getSum() > abit->getSum())
		{
			it = abiturients.insert(abit,ab);
			flag = true;
			break;
		}
	}
	if(!flag)
		it = abiturients.insert(abiturients.end(),ab);
	return it;
}
void Container::printCourses()
{
	int counter = 1;
	for(list<Course>::iterator it = courses.begin(); it != courses.end(); it++)
	{
		cout << counter << ") ";
		it->Print();
		cout << endl;
		counter++;
	}
}
pair<multimap<string,list<Abiturient>::iterator>::iterator, multimap<string,list<Abiturient>::iterator>::iterator> Container::findAbiturient(string surname)
{
	if(!find.empty())
		find.clear();
	for(list<Abiturient>::iterator i = abiturients.begin(); i!= abiturients.end(); i++)
		find.insert(pair<string, list<Abiturient>::iterator>(i->getSurname(),i));
	return find.equal_range(surname);
}
pair<multimap<double,list<Abiturient>::iterator>::iterator, multimap<double,list<Abiturient>::iterator>::iterator> Container::findAbiturientByScore(double from, double to)
{
	if(!find_score.empty())
		find_score.clear();
	for(list<Abiturient>::iterator i = abiturients.begin(); i!= abiturients.end(); i++)
		find_score.insert(pair<double, list<Abiturient>::iterator>(i->getSum(),i));
	multimap<double,list<Abiturient>::iterator>::iterator f = find_score.lower_bound(from);
	multimap<double,list<Abiturient>::iterator>::iterator t = find_score.upper_bound(to);
	return pair<multimap<double,list<Abiturient>::iterator>::iterator, multimap<double,list<Abiturient>::iterator>::iterator>(f,t);
}
void Container::addCourse(string name)
{
	Course c;
	c.set(name);
	courses.insert(courses.end(),c);
}
void Container::printAbiturients()
{
	int counter = 1;
	for(list<Abiturient>::iterator it = abiturients.begin(); it != abiturients.end(); it++)
	{
		cout << counter << ") ";
		it->Print();
		counter++;
	}
}
bool Container::printCoursesOfAbiturient(list<Abiturient>::iterator it)
{
	bool counter = false;
	int count = 1;
	for(multimap<list<Abiturient>::iterator, list<Course>::iterator>::iterator i = relation.begin(); i != relation.end(); i++)
	{
		if(i->first == it)
		{
			cout << count << ") ";
			i->second->Print();
			cout << endl;
			counter = true;
			count++;
		}
	}
	return counter;
}
bool Container::printAbiturientsOnCourse(list<Course>::iterator it)
{
	bool counter = false;
	int count = 1;
	for(multimap<list<Abiturient>::iterator, list<Course>::iterator>::iterator i = relation.begin(); i != relation.end(); i++)
	{
		if(i->second == it)
		{
			cout << count << ") ";
			i->first->Print();
			counter = true;
			count++;
		}
	}
	return counter;
}

void Container::addStatement(list<Abiturient>::iterator abit, list<Course>::iterator c)
{
	relation.insert(pair<list<Abiturient>::iterator, list<Course>::iterator>(abit,c));
}
void Container::deleteAbiturient(list<Abiturient>::iterator it)
{
	bool flag;
	do
	{
		flag = false;
		for(multimap<list<Abiturient>::iterator, list<Course>::iterator>::iterator i = relation.begin(); i!=relation.end(); i++)
		{
			if(it == i->first)
			{
				relation.erase(i);
				flag = true;
				break;
			}
		}
	}while(flag);
	abiturients.erase(it);
}
bool Container::deleteStatement(list<Abiturient>::iterator ab, list<Course>::iterator c)
{
	bool counter = false;
	for(multimap<list<Abiturient>::iterator, list<Course>::iterator>::iterator i = relation.begin(); i != relation.end(); i++)
	{
		if(ab == i->first && c == i->second)
		{
			relation.erase(i);
			counter = true;
			break;
		}
	}
	return counter;
}
istream& operator>> (istream &s, Container &m)
{
	ifstream cour, abitur, relat;
	cour.open("courses.txt");
	abitur.open("enrollees.txt");
	Course c;
	while(cour >> c)
		m.courses.push_back(c);
	cour.close();
	Abiturient ab;
	while (abitur >> ab)
	{
		m.abiturients.push_back(ab);
	}
	abitur.close();
	relat.open("relations.txt");//чтение из файла связей абитуриент-направление
	int counter1=1, count1, counter2=1, count2;
	while(relat >> count1 >> count2)
	{
		list<Abiturient>::iterator ab;
		for(ab = m.abiturients.begin(); ab!=m.abiturients.end(); ab++)
		{
			if(count1 == counter1)
				break;
			counter1++;
		}
		list<Course>::iterator c;
		for(c = m.courses.begin(); c!=m.courses.end(); c++)
		{
			if(count2 == counter2)
				break;
			counter2++;
		}
		m.relation.insert(pair<list<Abiturient>::iterator, list<Course>::iterator>(ab,c));
		counter1=1;
		counter2=1;
	}
	relat.close();
	return s;
}
ostream& operator<< (ostream &out, Container &m)
{
	ofstream cour, abitur, relat;
	cour.open("courses.txt");
	abitur.open("enrollees.txt");
	for(list<Course>::iterator i = m.courses.begin(); i!=m.courses.end();i++)
	{
		cour << *i << endl;
	}
	for(list<Abiturient>::iterator it = m.abiturients.begin(); it!=m.abiturients.end(); it++)
	{
		abitur << *it << endl;
	}
	cour.close();
	abitur.close();
	relat.open("relations.txt"); //сохранение связей абитуриент-направление
	int count1=1, count2=1;
	for(multimap<list<Abiturient>::iterator, list<Course>::iterator>::iterator it = m.relation.begin(); it != m.relation.end(); it++)
	{
		for(list<Abiturient>::iterator ab = m.abiturients.begin(); ab != m.abiturients.end(); ab++)
		{
			if(it->first == ab)
				break;
			count1++;
		}
		for(list<Course>::iterator c = m.courses.begin(); c != m.courses.end(); c++)
		{
			if(it->second == c)
				break;
			count2++;
		}
		relat << count1 << " " << count2 << endl;
		count1 = 1;
		count2 = 1;
	}
	relat.close();
	return out;
}
bool operator< (list<Abiturient>::iterator i1, list<Abiturient>::iterator i2)
{
	if((*i1) < (*i2))
		return true;
	else
		return false;
}
bool operator< (list<Course>::iterator i1, list<Course>::iterator i2)
{
	if(*i1 < *i2)
		return true;
	else
		return false;
}
bool operator== (list<Abiturient>::iterator i1, list<Abiturient>::iterator i2)
{
	if(*i1 == *i2)
		return true;
	else
		return false;
}
bool operator== (list <Course>::iterator i1, list <Course>::iterator i2)
{
	if(*i1 == *i2)
		return true;
	else
		return false;
}
