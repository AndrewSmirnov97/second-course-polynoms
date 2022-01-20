#pragma once
#include "Monom.h"
using namespace std;
#include <sstream>

class link{
	Monom A;
	link *n;
public:
	link(std::string str);
	link(Monom B);

	friend class Polinom;
};
class Polinom{
	link *h;
public:
	Polinom();
	Polinom(std::string str);
	void makeunique();

		
	void dellink(link* todel);
	void push(std::string str);
	void push(Monom B);
	std::string createstringfrompol();

	void testshow();
	Polinom  operator+(Polinom &right);
	Polinom  operator-(Polinom &right);

	Polinom operator*(Polinom &right);

};