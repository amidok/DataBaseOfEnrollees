#include "abiturient.h"

Abiturient::Abiturient()
{
	surname = "Kolomeyko";
	name = "Peter";
	patronymic = "Ivanovich";
	certificate = 200;
	exam = 600;
	sum = 820;
}
Abiturient::Abiturient(const Abiturient& s)
{
	surname = s.surname;
	name = s.name;
	patronymic = s.patronymic;
	certificate = s.certificate;
	exam = s.exam;
	sum = s.sum;
}
Abiturient::Abiturient(string surname, string name, string patronymic,double sum, double certificate, double exam)
{
	this->surname = surname;
	this->name = name;
	this->patronymic = patronymic;
	this->certificate = certificate;
	this->exam = exam;
	this->sum = sum;
}
void Abiturient::Print()
{
	cout << surname << " " <<  name << " " << patronymic;
	int size = surname.length() + name.length() + patronymic.length();
	if(size <= 25)
		cout << " \t\t" << sum  << "\t" << certificate << "\t" << exam << endl;
	else
		cout << " \t" << sum << "\t" << certificate << "\t" << exam << endl;
}

void Abiturient::set(string surname, string name, string patronymic,double sum, double certificate, double exam)
{
	this->surname = surname;
	this->name = name;
	this->patronymic = patronymic;
	this->certificate = certificate;
	this->exam = exam;
	this->sum = sum;
}
bool Abiturient::operator== (const Abiturient &b) const
{
	if((this->surname == b.surname) && (this->name == b.name) && (this->patronymic == b.patronymic))
		return true;
	else
		return false;
}
bool Abiturient::operator< (const Abiturient &b) const
{
	if((surname < b.surname) && (name < b.name) && (patronymic < b.patronymic))
		return true;
	else
		return false;
}

istream& operator>> (istream &s, Abiturient &ab)
{
	string name, surname, patronymic;
	double certificate, exam, sum;
	s >> surname;
	s >> name;
	s >> patronymic;
	s >> sum;
	s >> certificate;
	s >> exam;
	ab.set(surname,name,patronymic,sum,certificate,exam);
	return s;
}
ostream& operator<< (ostream &out, Abiturient &ab)
{
	out << ab.surname << " " <<  ab.name << " " << ab.patronymic << "\t" << ab.sum << "\t" << ab.certificate << "\t" << ab.exam;
	return out;
}