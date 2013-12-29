#ifndef abiturient_h
#define abiturient_h

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


class Abiturient
{
private:
	string surname;
	string name;
	string patronymic;
	double certificate;//���� ���������
	double exam;//���� �� ��������
	double sum;//����� ������(����� ���� ������, ��� certificate+exam)
public:
	//������������
	Abiturient();
	Abiturient(const Abiturient& s);
	Abiturient(string surname, string name, string patronymic,double sum, double certificate, double exam);
	//Set-� � get-�
	string getSurname()const{return surname;}
	string getName()const{return name;}
	string getPatronymic()const{return patronymic;}
	double getCertificate()const{return certificate;}
	double getExam()const{return exam;}
	double getSum()const{return sum;}
	void set(string surname, string name, string patronymic,double sum, double certificate, double exam);
	//���� � �����
	void Print();
	friend istream& operator>> (istream &s, Abiturient &ab);
	friend ostream& operator<< (ostream &out, Abiturient &ab);
	//��������� ���������
	bool operator== (const Abiturient &b) const;
	bool operator< (const Abiturient &b) const;
};
#endif