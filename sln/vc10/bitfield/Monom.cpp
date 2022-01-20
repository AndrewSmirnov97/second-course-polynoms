#include"Monom.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <cctype>
using namespace std;

	Monom::Monom(){

	}
	Monom::Monom(std::string str){  //моном из строки (строка вида (знак, коэфициент даже 1, три буквы со степенями через галочку


		//случай есть все три переменные указаны степени
		int i = 0;
		coef = 1;
		hide = 0;
		
		string c;
		string degx;
		string degy;
		string degz;
		c.resize(0);
		degx.resize(0);
		degy.resize(0);
		degz.resize(0);

		int len = str.length();
		while (1){
			if (str[i] != 'x'){
				c = c + str[i];
				i++;

			}
			else{
			/*	while (1){
					int i = 0;
					if (c[i] == '.'){
						i = i + 3;
						c.resize(i);
						break;
					}
					i++;
				}*/
				coef = stof(c);
				break;
			}
		}
		coef = round(coef * 10000) / 10000;
		i = i + 2;

		while (1){
			if (str[i] != 'y'){
				degx = degx + str[i];
				i++;

			}
			else{
				if (stoi(degx) >= 20)
					throw "deglimit";
				hide = hide + stoi(degx);
				break;
			}
		}
		i = i + 2;


		while (1){
			if (str[i] != 'z'){
				degy = degy + str[i];
				i++;

			}
			else
			{
				if (stoi(degy) >= 20)
					throw "deglimit";
				hide = hide + stoi(degy) * 20;
				break;
			}
		}
		i = i + 2;
		while (1){
			if (i != len ){
				
				degz = degz + str[i];
				i++;

			}
			else
			{
				if (stoi(degz) >= 20)
					throw "deglimit";
				hide = hide + stoi(degz) * 400;
				break;
			}

		}

		

	}



	Monom  Monom::operator*(Monom &right){
		Monom T(right);
		int xp;
		int yp;
		int zp;
		
		T.coef = T.coef*this->coef;
		xp=T.getx()+this->getx();
		 /*= T.getz()+this->getz();
		 = T.gety()+this->gety();*/
		if (xp >= 20){
			throw "limit degree";
		}
		 yp= (T.gety() + this->gety());
		 zp = (T.getz() + this->getz());
		 if (yp >= 20){
			 throw "limit degree";
		 }if (zp >= 20){
			 throw "limit degree";
		 }

		T.hide = xp + yp * 20 + zp * 400;
		//T.hide = T.getx() + T.gety() * 20 + T.getz() * 400;
		return T;
	}

	bool  Monom::operator==(const Monom &T)const{




		if (coef != T.coef){
			return false;
		}


		if (hide != T.hide){
			return false;
		}






		return true;
	}


	int Monom::getsign(){
		if (coef < 0)
			return -1;
		else
			return 1;
	}
	double Monom::getcoef(){
		return abs(coef);
	}
	int Monom::getx(){
		return (hide % 400) % 20; //неоднозначно
	}
	int Monom::gety(){
		return (hide % 400)/20;
	}
	int Monom::getz(){
		return hide / 400;
	}
	int Monom::gethide(){
		return hide;

	}



	void Monom::show(){


		cout << coef << endl;


		cout << hide << endl;

	}
	