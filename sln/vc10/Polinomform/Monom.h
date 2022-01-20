#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
#include <cctype>
using namespace std;
class Monom
{
private:
	int degx, degy, degz, coef; //степени и коэфициент
	int sign; //знак
	int hide; // свертка
public:
	Monom();
	Monom(std::string str);


	Monom(Monom &m);
	Monom  operator*(Monom &right);

	bool  operator==(const Monom &T)const;

	int getsign();
	int getcoef();
	int getx();
	int gety();
	int getz();
	int gethide();



	void show();
	friend class Polinom;
	friend class link;

};
