#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
#include <cctype>
using namespace std;
class Monom
{
private:
	double coef; //степени и коэфициент

	int hide; // свертка
public:
	Monom();
	Monom(std::string str);
	
	
	Monom  operator*(Monom &right);

	bool  operator==(const Monom &T)const;
		
		


	int getsign();
	double getcoef();
	int getx();
	int gety();
	int getz();
	int gethide();


	void show();
	friend class Polinom;
	friend class link;
	
};
