#pragma once
#include "Monom.h"
using namespace std;
#include <sstream>
class link{
	Monom A;
	link *n;
public:
	link(string str);
	link(Monom B);


	friend class Polinom;
};
class Polinom{
	link *h;
public:
	Polinom::Polinom();
	Polinom::Polinom(string str);
	void Polinom::makeunique();
	void Polinom::dellink(link* todel);
	void Polinom::push(string str);
	void pushl(Monom B);
	void Polinom::push(Monom B);
	string Polinom::createstringfrompol();

	void Polinom::testshow();
	double Polinom::count(double x, double y,double z);
	Polinom  Polinom::operator+(Polinom &right);
	Polinom  Polinom::operator-(Polinom &right);

	Polinom Polinom::operator*(Polinom &right);
};